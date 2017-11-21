/* tarsieve.c
Program:   tarsieve.c
Version:   1.0.0
Date:      18-JUN-2013
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2013 David Mathog and California Institute of Technology (Caltech)
   
Description:  
   tarsieve ==  filter and/or split a tar data stream
   
   (Not "tarfilter" because it sounds like it has something to do with 
   cigarettes.)

   This program may be used to extract subsets of files and data from
   tar files, or tar data streams, without having to break the files out
   into separate files first.  It may also be used to split files out into
   multiple data streams, which is an application that comes up sometimes 
   in contexts where large numbers of data files are stored in a tar file.
   
   compile with:
   
   gcc -Wall -pedantic -std=c99 -o tarsieve tarsieve.c -lpcre 
   
   on solaris 8 or 9 with
    
   gcc -Wall -pedantic -std=c99 -DSOL8 -o tarsieve tarsieve.c -lpcre 
    
    
License:  GNU General Public License 2
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

Changes:

  1.0.0 18-JUN-2013, initial coding

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef SOL8
#include "sol8.h"
#else
#include <stdint.h>
#endif
#include <stddef.h>
#include <ctype.h>            /* for toupper, tolower */
#include <time.h>
#include <pcre.h>

#define EXVERSTRING "1.0.0  18-JUN-2013"
#define COPYSTRING  "(tarsieve) 2013 David Mathog and California Institute of Technology"
#define COPYSTRING2 "(PCRE)     1997-2010 University of Cambridge"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"
#define MAXOUTFILES 100

/* tar structure definitions, from gnu tar.h */

typedef struct {
   char    name[100];           /* NUL-terminated if NUL fits     */
   char    mode[8];             /* file protection mask bits      */
   char    uid[8];              /*                                */
   char    gid[8];              /*                                */
   char    size[12];            /*                                */
   char    mtime[12];           /*                                */
   char    chksum[8];           /*                                */
   uint8_t typeflag;            /*  see below                     */
   char    linkname[100];       /*  NUL-terminated if NUL fits    */
   char    magic[6];            /*  must be TMAGIC (NUL term.)    */
   char    version[2];          /*  must be TVERSION              */
   char    uname[32];           /*  NUL-terminated                */
   char    gname[32];           /*  NUL-terminated                */
   char    devmajor[8];         /*                                */
   char    devminor[8];         /*                                */
   char    prefix[155];         /*  NUL-terminated if NUL fits    */
   char    unused[12];          /*  unused space in header        */
} TARHEAD;

/* The bits in mode: */
#define TSUID    04000
#define TSGID    02000
#define TSVTX    01000
#define TUREAD   00400
#define TUWRITE  00200
#define TUEXEC   00100
#define TGREAD   00040
#define TGWRITE  00020
#define TGEXEC   00010
#define TOREAD   00004
#define TOWRITE  00002
#define TOEXEC   00001

/* The values for typeflag:
   Values 'A'-'Z' are reserved for custom implementations.
   All other values are reserved for future POSIX.1 revisions.  */

#define REGTYPE    '0'      /* Regular file (preferred code).  */
#define AREGTYPE   '\0'     /* Regular file (alternate code).  */
#define LNKTYPE    '1'      /* Hard link.  */
#define SYMTYPE    '2'      /* Symbolic link (hard if not supported).  */
#define CHRTYPE    '3'      /* Character special.  */
#define BLKTYPE    '4'      /* Block special.  */
#define DIRTYPE    '5'      /* Directory.  */
#define FIFOTYPE   '6'      /* Named pipe.  */
#define CONTTYPE   '7'      /* Contiguous file */
#define OTHER      '8'      /* all other types */
#define TYPE_MAX   9

/* bitmap of tar record types */
#define BIT_REGTYPE  0x0001      /* Regular file */
#define BIT_LNKTYPE  0x0002      /* Hard link.  */
#define BIT_SYMTYPE  0x0004      /* Symbolic link (hard if not supported).  */
#define BIT_CHRTYPE  0x0008      /* Character special.  */
#define BIT_BLKTYPE  0x0010      /* Block special.  */
#define BIT_DIRTYPE  0x0020      /* Directory.  */
#define BIT_FIFOTYPE 0x0040      /* Named pipe.  */
#define BIT_CONTTYPE 0x0080      /* Contiguous file */
#define BIT_OTHER    0x0100      /* all other types */
#define BIT_ALL      0x01FF

char *recnames[10]={
   "all",
   "reg","lnk","sym","chr",
   "blk","dir","fifo","cont",
   "other"};


/* Contents of magic field and its length.  */
#define TMAGIC      "ustar"
#define TMAGLEN      6

/* Contents of the version field and its length.  */
#define TVERSION      "00"
#define TVERSLEN      2

/* numbers to represent field names */
#define LIST_NAM  1
#define LIST_MOD  2
#define LIST_UID  3
#define LIST_GID  4
#define LIST_SIZ  5
#define LIST_MTM  6
#define LIST_CSM  7
#define LIST_TYP  8
#define LIST_LNM  9
#define LIST_UNM 10
#define LIST_GNM 11
#define LIST_DMJ 12
#define LIST_DMN 13
#define LIST_PRE 14
#define LIST_MAX 14

/* text for field names */
char *listnames[15]={
   "all",
   "nam","mod","uid","gid",
   "siz","mtm","csm","typ",
   "lnm","unm","gnm","dmj",
   "dmn","pre"};

typedef struct {
  int count;        /* number of fields to list */
  int field[100];   /* fields to list, in order, limit should never be reached*/   
} LISTFIELD;

typedef struct {
  char     *infile;    /* input file                      */
  int       outstms;   /* output streams                  */
  int       phases;    /* phases                          */
  int       epp;       /* emitted per phase               */
  int       list;      /* list contents                   */
  int       nodata;    /* list contents and no data out   */
  LISTFIELD lf;        /* list fields                     */
  time_t   *fnle;      /* rnum <= , NULL if no test       */
  time_t   *fnge;      /* rnum >= , NULL if no test       */
  time_t   *fdle;      /* date <= , NULL if no test       */
  time_t   *fdge;      /* date >= , NULL if no test       */
  uint32_t *fsle;      /* size <= , NULL if no test       */
  uint32_t *fsge;      /* size >= , NULL if no test       */
  uint32_t *fgeq;      /* gid == GID                      */
  uint32_t *fueq;      /* uid == UID                      */
  char     *fgrp;      /* gname == GROUP                  */
  char     *fown;      /* uname == OWNER                  */
  uint32_t  frec;      /* bitmap of tar record types      */
  int       zero;      /* zero file sizes                 */
  char     *fregexp;   /* file name regular expression    */
  char     *dregexp;   /* dir name regular expression     */
  int       nopath;    /* remove the path from filename   */
} PARAMS;

/* prototypes */
int  lcl_strcasecmp(char *s1, char *s2);
uint32_t depath(char *string);
void emit_help(void);
void emit_type(FILE *fout, int type, char *LongName);
void emit_field(FILE *fout, TARHEAD *th, int field, char *longname);
int  iszeroblock(uint8_t *buffer, size_t size);
int  match_field(char *test);
int  match_rec(char *test);
int  match_regexp(pcre *re, char *string, int mlen);
uint32_t new_checksum(TARHEAD *th);
pcre *compile_regexp(char *regexp);
void process_command_line_args(int argc,char **argv, PARAMS *prms);
void setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setinonnegnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setlistfield(LISTFIELD *val,int *numarg,int argc,char **argv,char * label);
void setrecfield(uint32_t *val,int *numarg,int argc,char **argv,char * label);
void setoctnumeric(unsigned int *val,int *numarg,int argc,char **argv,char * label);
void setstring(char **val,int *numarg,int argc,char **argv,char * label);
void settimeval(time_t **date, int *numarg, int argc, char **argv, char *label);
 
/* functions and main */

/* Only used when debugging issues
void dumprange(char *label, char *loc, int size){
  fprintf(stderr,"%s",label);
  for(;size>0;size--,loc++){
     fprintf(stderr,"[%c %2.2x] ",*loc,*loc);
  }
  fprintf(stderr,"\n");
}
*/

int  lcl_strcasecmp(char *s1, char *s2){
int c1;
int c2;
  for(; ;s1++,s2++){
    c1=toupper(*s1);
    c2=toupper(*s2);
    if(c1 < c2)return -1;
    if(c1 > c2)return  1;
    if(c1 == 0)return  0;  /*c2 also is 0 in this case */
  }
}

void setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "tarsieve: fatal error: %s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%d",val) != 1){
        (void) fprintf(stderr,"tarsieve: fatal error: Bad integer argument/parameter [%s %s]\n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(*val <= 0){
        (void) fprintf(stderr,"tarsieve: fatal error: Illegal zero or negative integer argument/parameter [%s %s]\n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}

void setinonnegnumeric(int *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "tarsieve: fatal error: %s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%d",val) != 1){
        (void) fprintf(stderr,"tarsieve: fatal error: Bad integer argument/parameter [%s %s]\n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(*val < 0){
        (void) fprintf(stderr,"tarsieve: fatal error: Illegal negative integer argument/parameter [%s %s]\n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}
void setoctnumeric(unsigned int *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "tarsieve: fatal error: %s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%o",val) != 1){
        (void) fprintf(stderr,"tarsieve: fatal error: Bad octal argument/parameter [%s %s]\n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}


void setstring(char **val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "tarsieve: fatal error: %s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      *val = argv[*numarg];
}

/* parse the time structure, must be in the form "YYYY-MM-DD HH:MM:SS"
   fields may be omitted starting from the right, the YYYY field is mandatory

*/
void settimeval(time_t **date, int *numarg, int argc, char **argv, char *label){
int fields;
struct tm tv;

      (*numarg)++;
      memset(&tv,0,sizeof(struct tm));
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "tarsieve: fatal error: %s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      fields = sscanf(argv[*numarg],"%4d-%2d-%2d %2d:%2d:%2d",
              &tv.tm_year,&tv.tm_mon,&tv.tm_mday,&tv.tm_hour,&tv.tm_min,&tv.tm_sec);
      if(fields < 1){
        (void) fprintf( stderr, "tarsieve: fatal error: %s: date format is YYYY-MM-DD HH:MM:SS, not:%s\n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      tv.tm_year -= 1900;
      tv.tm_mon  -= 1;
      *date=malloc(sizeof(time_t));
      **date= mktime(&tv);
}

int match_field(char *test){
int i;
int status = -1;
  for(i=0; i<=LIST_MAX; i++){
     if(0 == lcl_strcasecmp(test, listnames[i])){
       status = i;
       break;
     }
  }
  return(status);
}

int match_rec(char *test){
int i;
int status = -1;
  for(i=0; i<=TYPE_MAX; i++){
     if(0 == lcl_strcasecmp(test, recnames[i])){
       status = i;
       break;
     }
  }
  return(status);
}


void setlistfield(LISTFIELD *val,int *numarg,int argc,char **argv,char * label){
char *tok;
int   field;
int   i;
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "tarsieve: fatal error: %s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      val->count=0;
      /* comma delimited list */
      tok=strtok(argv[*numarg]," ,");
      while(tok){
         field=match_field(tok);
         if(field<0){ /* error */
           (void) fprintf( stderr, "tarsieve: fatal error: %s: unrecognized field name: %s\n",label,tok);
           exit(EXIT_FAILURE);
         }
         else if(field>0){
           if(val->count >=100){
             (void) fprintf( stderr, "tarsieve: fatal error: %s: too many fields, max is 100\n",label);
             exit(EXIT_FAILURE);
           }
           val->field[val->count++]=field;
         }
         else { /* all */
           for(i=1;i<=LIST_MAX;i++){
              if(val->count >=100){
                (void) fprintf( stderr, "tarsieve: fatal error: %s: too many fields, max is 100\n",label);
                exit(EXIT_FAILURE);
              }
              val->field[val->count++]=i;
           }
         }
         tok=strtok(NULL," ,");
      }
}

void setrecfield(uint32_t *val,int *numarg,int argc,char **argv,char * label){
char *tok;
int   type;
      (*numarg)++;
      *val = 0; /* default has all of the bits already set */
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "tarsieve: fatal error: %s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      /* comma delimited list */
      tok=strtok(argv[*numarg]," ,");
      while(tok){
         type=match_rec(tok);
         if(type < 0){ /* error */
           (void) fprintf( stderr, "tarsieve: fatal error: %s: unrecognized type name: %s\n",label,tok);
           exit(EXIT_FAILURE);
         }
         else if(type>0){
           *val |= 1<<(type-1);
         }
         else { /* all */
           *val = BIT_ALL;
         }
         tok=strtok(NULL," ,");
      }
}



void emit_help(void){
    (void) fprintf(stdout,"usage: tarsieve [options]\n");
    (void) fprintf(stdout,"\nfunction:\n");
    (void) fprintf(stdout,"   Filter, list, or split a tar file.\n\n");
    (void) fprintf(stdout,"Filtering options:  (Apply tests in order shown, drop records that fail any test)\n");
    (void) fprintf(stdout,"   -fnge, -fdle RECNUM\n");
    (void) fprintf(stdout,"                   record number [>= , <=] RECNUM (records are numbered 1 to N)\n");
    (void) fprintf(stdout,"   -fdge, -fdle DATE\n");
    (void) fprintf(stdout,"                   date [>= , <=] DATE (YYYY-MM-DD hh:mm:ss)\n");
    (void) fprintf(stdout,"   -fsge, -fsle SIZE\n");
    (void) fprintf(stdout,"                   size [>= , <=] SIZE (decimal size in bytes)\n");
    (void) fprintf(stdout,"   -fgeq GID       gid == GID (octal value)\n");
    (void) fprintf(stdout,"   -fueq UID       uid == UID (octal value)\n");
    (void) fprintf(stdout,"   -fgrp GROUP     gname == GROUP (string like \"users\")\n");
    (void) fprintf(stdout,"   -fown OWNER     uname == OWNER (string like \"John\")\n");
    (void) fprintf(stdout,"   -frec TYPE      record type == TYPE\n");
    (void) fprintf(stdout,"                   TYPE is a comma dilimited list of tar record types:\n");
    (void) fprintf(stdout,"                      all   All of the following\n");
    (void) fprintf(stdout,"                      reg   Regular file\n");
    (void) fprintf(stdout,"                      lnk   Hard link\n");
    (void) fprintf(stdout,"                      sym   Symbolic link\n");
    (void) fprintf(stdout,"                      chr   Character special\n");
    (void) fprintf(stdout,"                      blk   Block special\n");
    (void) fprintf(stdout,"                      dir   Directory\n");
    (void) fprintf(stdout,"                      fifo  Named pipe\n");
    (void) fprintf(stdout,"                      cont  Contiguous file\n");
    (void) fprintf(stdout,"                      other all other types\n");
    (void) fprintf(stdout,"   -ffre  REGEXP   file name matches PCRE regular expression\n");
    (void) fprintf(stdout,"   -fdre  REGEXP   directory name matches PCRE regular expression\n");
    (void) fprintf(stdout,"                   The tar record \"name\" field actually holds both the file name\n");
    (void) fprintf(stdout,"                   and the directory name.  Two filters are provided so that one may\n");
    (void) fprintf(stdout,"                   separately target each part of the name.\n\n");
    (void) fprintf(stdout,"Splitting options:\n");
    (void) fprintf(stdout,"   -n    STREAMS   number of tar streams to produce, N must be >0\n");
    (void) fprintf(stdout,"   -p    PHASES    0 or omitted, emit N streams to N files\n");
    (void) fprintf(stdout,"                   1-N, only emit contents of Pth stream to stdout\n");
    (void) fprintf(stdout,"   -c    COUNT     Emit COUNT tar records for each PHASE to each stream [Default=1]\n\n");
    (void) fprintf(stdout,"   The value of the environmental symbol TARSIEVETEMPLATE overrides the \n");
    (void) fprintf(stdout,"   default output file name template of \"frag%%.3d.tar\". \n\n");
    (void) fprintf(stdout,"   Examples: (input has 20 tar records)\n\n");
    (void) fprintf(stdout,"     -n 4 -p 0 -c 5:\n");
    (void) fprintf(stdout,"        records 1-5 to file1, 6-10 to file2, 11-15 to file3, 16-20 to file4\n");
    (void) fprintf(stdout,"     -n 4 -p 2 -c 3:\n");
    (void) fprintf(stdout,"        records 4-6,16-17 to stdout\n\n");
    (void) fprintf(stdout,"Listing options:\n");
    (void) fprintf(stdout,"   -l              Emit listing information to stderr.\n");
    (void) fprintf(stdout,"   -lx             Like -l, but also block all other output.\n");
    (void) fprintf(stdout,"   -lf   FIELDS    FIELDS is a comma delimited list of fields to\n");
    (void) fprintf(stdout,"                   show in the listing.  Fields are:\n");
    (void) fprintf(stdout,"                      all  all fields\n");
    (void) fprintf(stdout,"                      nam  file name\n");
    (void) fprintf(stdout,"                      mod  file protection mask\n");
    (void) fprintf(stdout,"                      uid  user id\n");
    (void) fprintf(stdout,"                      gid  group id\n");
    (void) fprintf(stdout,"                      siz  file size\n");
    (void) fprintf(stdout,"                      mtm  mtime\n");
    (void) fprintf(stdout,"                      csm  chksum\n");
    (void) fprintf(stdout,"                      typ  record type\n");
    (void) fprintf(stdout,"                      lnm  linkname\n");
    (void) fprintf(stdout,"                      unm  uname\n");
    (void) fprintf(stdout,"                      gnm  gname\n");
    (void) fprintf(stdout,"                      dmj  devmajor\n");
    (void) fprintf(stdout,"                      dmn  devminor\n");
    (void) fprintf(stdout,"                      pre  prefix\n");
    (void) fprintf(stdout,"                   The default FIELDS value is: \"siz,typ,nam\"\n");
    (void) fprintf(stdout,"Other options: \n");
    (void) fprintf(stdout,"   -in   FILE      read input from FILE, from stdin if default or -\n");
    (void) fprintf(stdout,"   -z              Zero record size (drops file contents).\n");
    (void) fprintf(stdout,"   -np             No Path.  Remove the path from the  record name.\n");
    (void) fprintf(stdout,"                   If nothing remains, drop the record.\n");
    (void) fprintf(stdout,"   -h              print this help message (also -help --h --help -? --?)\n");
    (void) fprintf(stdout,"   -i              emit version, copyright, license and contact information\n\n");
    (void) fprintf(stdout,"Other information: \n");
    (void) fprintf(stdout,"   Incoming null (terminator) blocks are always dropped and new\n");
    (void) fprintf(stdout,"   ones are always generated at the end of the file.  This allows\n");
    (void) fprintf(stdout,"   tar files to be concatenated like this: \n");
    (void) fprintf(stdout,"   cat 1.tar 2.tar 3.tar | tarsieve -n 1 -p 1 >123.tar \n\n");
    (void) fprintf(stdout,"   GNU long name blocks are always read, stored, and not counted.\n");
    (void) fprintf(stdout,"   They are emitted only if the subsequent block whose name\n");
    (void) fprintf(stdout,"   they hold is emitted.\n");
    exit(EXIT_FAILURE);
}

void  process_command_line_args(int argc,char **argv, PARAMS *prms){
int numarg;
int itmp;
unsigned int otmp;

  /* set defaults */
  prms->infile      = NULL;
  prms->outstms     = 1;   /* output streams    */
  prms->phases      = 1;   /* phases            */
  prms->epp         = 1;   /* emitted per phase */
  prms->list        = 0;   /* list contents     */
  prms->nodata      = 0;   /* drop output when listing contents */
  prms->lf.count    = 3;   /* 3 fields to list (if a list is enabled) */
  prms->lf.field[0] = 5;   /* size */
  prms->lf.field[1] = 8;   /* type */
  prms->lf.field[2] = 1;   /* name */
  prms->fnle        = NULL;
  prms->fnge        = NULL;
  prms->fdle        = NULL;
  prms->fdge        = NULL;
  prms->fsle        = NULL;
  prms->fsge        = NULL;
  prms->fgeq        = NULL;
  prms->fueq        = NULL;
  prms->fgrp        = NULL;
  prms->fown        = NULL;
  prms->frec        = BIT_ALL;    /* match all tar record types      */
  prms->zero        = 0;  /* do not drop file contents */
  prms->fregexp     = NULL;
  prms->dregexp     = NULL;
  prms->nopath      = 0;

  for(numarg=1;numarg<argc;numarg++){
    if(0==lcl_strcasecmp(argv[numarg], "-c")){
      setiposnumeric(&(prms->epp),&numarg,argc,argv,"-c");
    }
    else if(lcl_strcasecmp(argv[numarg], "-in")==0){
      setstring(&(prms->infile),&numarg,argc,argv,"-in");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fdge")){
      settimeval(&(prms->fdge),&numarg,argc,argv,"-fdge");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fdle")){
      settimeval(&(prms->fdle),&numarg,argc,argv,"-fdle");
    }
    else if(lcl_strcasecmp(argv[numarg], "-fdre")==0){
      setstring(&(prms->dregexp),&numarg,argc,argv,"-fdre");
    }
    else if(lcl_strcasecmp(argv[numarg], "-ffre")==0){
      setstring(&(prms->fregexp),&numarg,argc,argv,"-ffre");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fgeq")){
      setoctnumeric(&otmp,&numarg,argc,argv,"-fgeq");
      prms->fgeq=malloc(4);
      *(prms->fgeq) = otmp;
    }
    else if(lcl_strcasecmp(argv[numarg], "-fgrp")==0){
      setstring(&(prms->fgrp),&numarg,argc,argv,"-fgrp");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fnge")){
      setiposnumeric(&itmp,&numarg,argc,argv,"-fnge");
      prms->fnge=malloc(4);
      *(prms->fnge) = itmp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fnle")){
      setiposnumeric(&itmp,&numarg,argc,argv,"-fnle");
      prms->fnle=malloc(4);
      *(prms->fnle) = itmp;
    }
    else if(lcl_strcasecmp(argv[numarg], "-fown")==0){
      setstring(&(prms->fown),&numarg,argc,argv,"-fown");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fueq")){
      setoctnumeric(&otmp,&numarg,argc,argv,"-fueq");
      prms->fueq=malloc(4);
      *(prms->fueq) = otmp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fsge")){
      setiposnumeric(&itmp,&numarg,argc,argv,"-fsge");
      prms->fsge=malloc(4);
      *(prms->fsge) = itmp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fsle")){
      setiposnumeric(&itmp,&numarg,argc,argv,"-fsle");
      prms->fsle=malloc(4);
      *(prms->fsle) = itmp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-frec")){
      setrecfield(&(prms->frec),&numarg,argc,argv,"-frec");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-n")){
      setiposnumeric(&(prms->outstms),&numarg,argc,argv,"-n");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-p")){
      setinonnegnumeric(&(prms->phases),&numarg,argc,argv,"-p");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-lf")){ /* must precede -l */
      setlistfield(&(prms->lf),&numarg,argc,argv,"-lf");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-lx")){ /* must precede -l */
      prms->list = 1;
      prms->nodata = 1;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-l")){
      prms->list = 1;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-np")){
      prms->nopath = 1;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-z")){
      prms->zero = 1;
    }
    else if(lcl_strcasecmp(argv[numarg], "-i")==0){
      (void)fprintf(stderr,"Version:      %s\n",EXVERSTRING);
      (void)fprintf(stderr,"bugs to:      %s\n",BUGSTRING);
      (void)fprintf(stderr,"Copyright:    %s\n",COPYSTRING);
      (void)fprintf(stderr,"              %s\n",COPYSTRING2);
      (void)fprintf(stderr,"License:      %s\n",LICSTRING);
/* This works on Linux, must be modified for other OS's */
#ifdef _LARGE_FILE_SOURCE
      (void)fprintf(stderr,"Large Files:  Supported\n");
#else
      (void)fprintf(stderr,"Large Files:  Not Supported\n");
#endif
      exit(EXIT_SUCCESS);
    }
    else if( (lcl_strcasecmp(argv[numarg], "-h")==0)     ||
             (lcl_strcasecmp(argv[numarg], "--h")==0)    ||
             (lcl_strcasecmp(argv[numarg], "-?")==0)     ||
             (lcl_strcasecmp(argv[numarg], "--?")==0)    ||
             (lcl_strcasecmp(argv[numarg], "-help")==0)  ||
             (lcl_strcasecmp(argv[numarg], "--help")==0) ){
       emit_help();
    }
    else{
      (void) fprintf(stderr,"tarsieve: fatal error: no such parameter [%s]\n",argv[numarg]);
      emit_help();
    }
  }
}

int iszeroblock(uint8_t *buffer, size_t size){
int i;
   for(i=0; i<size; i++,buffer++){
      if(*buffer)return(0);
   }
   return(1);
}

void emit_type(FILE *fout, int type, char *LongName){
  switch(type){
     case  REGTYPE:
     case  0:         fprintf(fout,"Regular file");  break;
     case  LNKTYPE:   fprintf(fout,"Hard link");     break;
     case  SYMTYPE:   fprintf(fout,"Symbolic link"); break;
     case  CHRTYPE:   fprintf(fout,"Char. special"); break;
     case  BLKTYPE:   fprintf(fout,"Block special"); break;
     case  DIRTYPE:   fprintf(fout,"Directory");     break;
     case  FIFOTYPE:  fprintf(fout,"Named pipe");    break;
     case  CONTTYPE:  fprintf(fout,"Contig. file");  break;
     default:
       if(LongName){ fprintf(fout,"GNU Longname"); }
       else {         fprintf(fout,"Other");        }
       break;
  }
}

/* emit as text a header field */
void emit_field(FILE *fout, TARHEAD *th, int field, char *LongName){
int dsize;
struct  tm  *time_structure;
time_t time_val;
uint32_t utv;
   fprintf(fout,"%s=",listnames[field]);
   switch(field){
     case LIST_NAM:
        if(LongName){ fprintf(fout,"%s",LongName); }
        else {         fprintf(fout,"%s",th->name);  }
        break;
     case LIST_MOD:
        fprintf(fout,"%s",th->mode);
        break;
     case LIST_UID:
        fprintf(fout,"%s",th->uid);
        break;
     case LIST_GID:
        fprintf(fout,"%s",th->gid);
        break;
     case LIST_SIZ:
        sscanf(th->size,"%o",(unsigned int *)&dsize); /* yes, the size is stored as an octal number*/
        fprintf(fout,"%d",dsize);
        break;
     case LIST_MTM:
       
        sscanf(th->mtime,"%o",(unsigned int *)&utv); /* yes, the time is stored as an octal number*/
        time_val = utv;  /* Hopefully this will work when is >4 bytes, as it is on some platforms */
        time_structure   = localtime(&time_val);
        fprintf(fout,"%.4d-%.2d-%.2d %.2d:%.2d:%.2d",
               1900+time_structure->tm_year,
               1+time_structure->tm_mon,
               time_structure->tm_mday,
               time_structure->tm_hour,
               time_structure->tm_min,
               time_structure->tm_sec);
        break;
     case LIST_CSM:
        fprintf(fout,"%s",th->chksum);
        break;
     case LIST_TYP:
        emit_type(fout,th->typeflag,LongName);
        break;
     case LIST_LNM:
        fprintf(fout,"%s",th->linkname);
        break;
     case LIST_UNM:
        fprintf(fout,"%s",th->uname);
        break;
     case LIST_GNM:
        fprintf(fout,"%s",th->gname);
        break;
     case LIST_DMJ:
        fprintf(fout,"%s",th->devmajor);
        break;
     case LIST_DMN:
        fprintf(fout,"%s",th->devminor);
        break;
     case LIST_PRE:
        fprintf(fout,"%s",th->prefix);
        break;
   }
}

/* (re) calculate the checksum, needed when files are truncated to zero
  The value is the sum of the (unsigned) bytes of the header assuming the checksum bytes
  themselves are all ASCII spaces.
*/
uint32_t new_checksum(TARHEAD *th){
  int i;
  uint32_t sum = 0;
  uint8_t *sptr = (uint8_t *)th;
  for(i=0; i < offsetof(TARHEAD,chksum);     i++,sptr++){ sum += *sptr; }
  for(   ; i < offsetof(TARHEAD,chksum) + 8; i++,sptr++){ sum += ' ';   }
  for(   ; i < 512;                          i++,sptr++){ sum += *sptr; }
  return(sum);
}

pcre *compile_regexp(char *regexp){
pcre *re = NULL;
const char *error;
int         erroffset;
   if(regexp){
     re = pcre_compile(
     regexp,               /* the pattern */
     0,                    /* default options */
     &error,               /* for error message */
     &erroffset,           /* for error offset */
     NULL);                /* use default character tables */

     /* Compilation failed: print the error message and exit */

     if (!re){
       (void) fprintf(stderr,"tarsieve: fatal error: PCRE compilation failed at offset %d: %s\n", erroffset, error);
       exit(0);
     }
  }
  return(re);
}

/* 1 on match, 0 on no match*/
int match_regexp(pcre *re, char *string, int mlen){
int ovector[20]; /* number of entries is arbitrary, we will not look at results */
int slen = (strlen(string) > mlen ? mlen : strlen(string));
int status;
  if(pcre_exec(re,NULL,string,slen,0,0,ovector,20) < 0){ status = 0; }
  else {status = 1; }
  return(status);
}

/* chop off the path, shift the filename left, fill everything to the right 
with '\0', return the length of the filename. If the name is entirely path, it returns
0 and erases the string. */
uint32_t depath(char *string){
int   flen;
int   slen  = strlen(string);
char *slash = string + slen - 1;
  for(flen=0; slash >= string; slash--,flen++){
    if(*slash == '/')break;
  }
  if(flen != slen){
    memmove(string, string+slen-flen, flen);
    memset(string+flen,0,slen-flen);
  }
  return(flen);
}

int main(int argc, char *argv[]){
char        outname[200];
int         rec_btype;
int         recnum = 0;
uint8_t    *buffer;    /* tar files are composed of 512 byte blocks */
uint8_t    *lnbuffer;  /* header for a longname record  */
int         cyccount,i;
int         StmCount = 0;
FILE       *fin;
FILE       *fout[MAXOUTFILES];
char       *outfname_template;
char       *save_template = NULL; /* this pointer is set if preceding template was malloc'd*/
TARHEAD    *th;
int         status;
int         dsize;
int         termblocks = 0;
int         dropped;
PARAMS      prms;
time_t      time_val;
int         itmp;
pcre       *ref;
pcre       *red;
int         cleanin = 0;
uint32_t    utv;
char       *LongName = NULL;
char       *lnptr = NULL;
int         load_LongName = 0;
uint32_t    lnlen = 0;

  process_command_line_args(argc, argv, &prms);

  /* Sanity checking */
  if((prms.outstms < 1) || (prms.outstms > MAXOUTFILES)){
    (void) fprintf(stderr,"tarsieve: fatal error: The number of files must be between 1 and %d\n",MAXOUTFILES);
    exit(0);
  }

  if(prms.phases==0){
     (void) fprintf(stderr,"tarsieve: Processing %s with n=%d p=%d c=%d\n",
        prms.infile, prms.outstms, prms.phases, prms.epp);
  }
  
  if(!prms.infile){
     prms.infile=malloc(2);
     strcpy(prms.infile,"-");
     cleanin = 1;
  }
  if(lcl_strcasecmp(prms.infile,"-") == 0 || lcl_strcasecmp(prms.infile,"stdin") == 0){
    fin=stdin;
  }
  else {
    fin=fopen(prms.infile,"r");
  }
  if(fin==NULL){
   (void) fprintf(stderr,"tarsieve: Could not open input file %s\n",prms.infile);
    exit(0);
  }
  
  /* if there are PCRE patterns, build them now */

  ref = compile_regexp(prms.fregexp);
  red = compile_regexp(prms.dregexp);

  /* see if template is to use default or from a symbol */
  
  outfname_template=getenv("TARSIEVETEMPLATE");
  if(outfname_template==NULL){
     outfname_template=getenv("tarsievetemplate");
     if(outfname_template==NULL){
       save_template=outfname_template=malloc(30);
       (void) strcpy(outfname_template,"frag%.3d.tar");
    }
  }
  if(prms.phases==0)(void) fprintf(stderr,"tarsieve: Using template: %s\n",outfname_template);

  buffer=malloc(512);
  lnbuffer=malloc(512);

  /* open all the output files - if there will be any */

  if(!prms.nodata){
    for(StmCount=0; StmCount<prms.outstms; StmCount++){
       (void) sprintf(outname,outfname_template,StmCount+1);
       if(prms.phases==0){
         fout[StmCount] = fopen(outname,"w");
         if(fout[StmCount]==NULL){
            (void) fprintf(stderr,"tarsieve: fatal error: Could not open output file %s\n",outname);
            exit(EXIT_FAILURE);
         }
       }
       else if(prms.phases==StmCount+1){
         fout[StmCount] = stdout;
       }
    }
  }

  /* now send files to each one */

  StmCount   = 0;
  cyccount    = 0;
  while(1){
    status = fread(buffer,512,1,fin);
    if(!status){
       if(ferror(fin)){ fprintf(stderr,"tarsieve: fatal error: Bad read, exiting\n"); }
       break;
    }
    th = (TARHEAD *)buffer;
    recnum++;
    th->name[99]='\0'; /* maybe nick off one character */
    dsize   = 0;
    dropped = 0;
    sscanf(th->size,"%o",(unsigned int *)&dsize); /* yes, the size is stored as an octal number*/
    if(th->typeflag)termblocks=0;
    switch(th->typeflag){
      case 0:
        if(iszeroblock(buffer,512)){
           termblocks = 1;
           dropped    = 1; /* these are always dropped and new ones created for the end. */
           break;
        }
        /* fall through, regular file using alternate type encoding*/
      case  REGTYPE:
        rec_btype = BIT_REGTYPE;
        break;
      case  LNKTYPE:
        rec_btype = BIT_LNKTYPE;
        break;
      case  SYMTYPE:
        rec_btype = BIT_SYMTYPE;
        break;
      case  CHRTYPE:
        rec_btype = BIT_CHRTYPE;
        break;
      case  BLKTYPE:
        rec_btype = BIT_BLKTYPE;
        break;
      case  DIRTYPE:
        rec_btype = BIT_DIRTYPE;
        break;
      case  FIFOTYPE:
        rec_btype = BIT_FIFOTYPE;
        break;
      case  CONTTYPE:
        rec_btype = BIT_CONTTYPE;
        break;
      default:
        rec_btype = BIT_OTHER;
        if(0==strcmp(th->name,"././@LongLink")){
           lnlen = dsize;
           load_LongName = 1;
           lnptr = LongName = malloc(512*(1 + dsize/512));
        }
        /* check for longlink and hang onto it if found.  This is the 
        "real" name for the next record in gnu tar. */
        break;
    }
    
    /* apply filters */

    sscanf(th->mtime,"%o",&utv);
    time_val = utv;
    if(prms.fnge && (recnum   < *(prms.fnge)))dropped = 1;
    if(prms.fnle && (recnum   > *(prms.fnle)))dropped = 1;
    if(prms.fdge && (time_val < *(prms.fdge)))dropped = 1;
    if(prms.fdle && (time_val > *(prms.fdle)))dropped = 1;
    if(prms.fsge && (dsize    < *(prms.fsge)))dropped = 1;
    if(prms.fsle && (dsize    > *(prms.fsle)))dropped = 1;
    if(prms.fgeq){
       sscanf(th->gid,"%o",(unsigned int *)&itmp);
       if(itmp != *(prms.fgeq))dropped = 1;
    }
    if(prms.fueq){
       sscanf(th->uid,"%o",(unsigned int *)&itmp);
       if(itmp != *(prms.fueq))dropped = 1;
    }
    if(prms.fgrp && strcmp(th->gname,prms.fgrp))dropped = 1;
    if(prms.fown && strcmp(th->uname,prms.fown))dropped = 1;
    if(!(rec_btype & prms.frec))dropped = 1;
    if(red && !match_regexp(red,th->name,99))dropped = 1;
    if(ref && !match_regexp(ref,th->name,99))dropped = 1;
    
    if(prms.zero && (rec_btype == BIT_REGTYPE)){ /* zero the file - drop its contents and set size to 0 */
       strcpy(th->size,"00000000000");       
       sprintf(th->chksum,"%6.6o",new_checksum(th));
    }
    
    /* this is a little messy.  There are several cases:
       1.  LongName defined and shortened form fits into the usual space. 
           Drop the entire  LongName record and use form as name in the next record.
       2.  LongName defined and shortened form does NOT fit into the usual space.  
           Modify the LongName header to reflect the new length.  Store the shortened name
           as the data in the record.  Next record is not modified.
       3.  LongName defined and shortens to nothing.  Drop both the LongName and the next record.
       4.  LongName is not defined AND this is not a GNU longname record.
           Shorten the name, store it in the header.      
    */
    if(prms.nopath){
       if(LongName){
          if(!lnlen){ /* case 3 */
            dropped = 1;
          }
          else if (lnlen < 100){ /* case 1 */
            memset(th->name,0,100);
            strcpy(th->name,LongName);
            lnlen = 0;
          }
          else {
           /* a separate long name record must be emitted */
          }
          if(!lnlen){
            free(LongName);
            LongName=NULL;
          }
       }
       else if(!load_LongName) { /* case 4 */
          status = depath(th->name);
          if(!status)dropped = 1;
       }
       sprintf(th->chksum,"%6.6o",new_checksum(th)); /* harmless if case 2 */
    }

    /* LongName records are always processed, always dropped, and not counted.  They are conditionally
       emitted if the NEXT record is not dropped.*/
    if(load_LongName){ /* may need to recalculate the header, so order must be different than general case, below */                                          
       lnlen = dsize; /* the length of the stored name of the LongName */
       while(dsize>0){ /* contents of LongName */
          status = fread(buffer,512,1,fin);
          memcpy(lnptr,buffer,512); 
          lnptr += 512;
          dsize = (dsize > 512 ? dsize - 512 : 0);
       }
       if(prms.nopath){ lnlen = depath(LongName); }
       if(lnlen >= 100){  /* it will not fit in normal header, save this header (we already have the data) */
         sprintf(th->size,"%11.11o",lnlen);       
         sprintf(th->chksum,"%6.6o",new_checksum(th));
         memcpy(lnbuffer,buffer,512);
       }
       else {
         /* it will fit in a normal header.  That is processed in the next loop */
       }
    }
    else { /* not a LongName record */
       if(!dropped){
          cyccount++;
          if(cyccount > prms.epp){
            cyccount=1;
            StmCount++;
            if(StmCount >= prms.outstms)StmCount=0;
          }

          if(prms.phases==0 || prms.phases==StmCount+1){
            if(prms.list & !termblocks){
              for(i=0; i<prms.lf.count; i++){
                 if(i)fprintf(stderr,", ");
                 emit_field(stderr, th, prms.lf.field[i], LongName);
              }
              fprintf(stderr,"\n");
              /* done with LongName (from PREVIOUS record) */ 
            }

            /* in some instances write out the longname record which was stored previously
               its data must be written, whether or not nodata is set. */
            if(LongName && lnlen){
               status = fwrite(lnbuffer,512,1,fout[StmCount]); /* stored record header */
               lnptr = LongName;
               while(lnlen >0){ /* data for this record */
                  status = fwrite(lnptr,512,1,fout[StmCount]);
                  lnlen = (lnlen > 512 ? lnlen - 512 : 0);
                  lnptr += 512;
               }
               load_LongName = 0;
               free(LongName);
               LongName=NULL;
            }

            /* read and conditionally emit the current record.
               EXCEPTION, longname record has already been read and its emit is delayed */
            if(!load_LongName){
               if(!prms.nodata){ status = fwrite(buffer,512,1,fout[StmCount]); } /* record header */
               while(dsize>0){ /* data for this record */
                  status = fread(buffer,512,1,fin);
                  if( !(prms.nodata || prms.zero) ){ status = fwrite(buffer,512,1,fout[StmCount]); }
                  dsize = (dsize > 512 ? dsize - 512 : 0);
               }
            }
          }
       }
       else { /* dropped, still have to read the data for the record to reach the next one */
         if(LongName){
            free(LongName);
            LongName=NULL;
         }
         while(dsize>0){
            status = fread(buffer,512,1,fin);
            dsize = (dsize > 512 ? dsize - 512 : 0);
         }
       }    
    } /* end of condition on LongName record */
    load_LongName = 0;
  }
  /* send terminators to all of the streams */
  if(!prms.nodata){
    memset(buffer,0,512);
    for(StmCount=0; StmCount < prms.outstms ; StmCount++){
      (void) fwrite(buffer,512,1,fout[StmCount]);
      (void) fwrite(buffer,512,1,fout[StmCount]);
      if(fout[StmCount] != stdout)fclose(fout[StmCount]);
    }
  }
  free(buffer);
  free(lnbuffer);
  if(save_template)free(outfname_template);
  if(fin != stdin)fclose(fin);
  if(prms.fnge)free(prms.fnge);
  if(prms.fnle)free(prms.fnle);
  if(prms.fdge)free(prms.fdge);
  if(prms.fdle)free(prms.fdle);
  if(prms.fsge)free(prms.fsge);
  if(prms.fsle)free(prms.fsle);
  if(prms.fgeq)free(prms.fgeq);
  if(prms.fueq)free(prms.fueq);
  /*
    do not free prms.dregexp or prms.fregexp, as, if set, they are pointers to argv
  */
  if(ref)free(ref);
  if(red)free(red);
  if(cleanin)free(prms.infile);

  exit(EXIT_SUCCESS);
}
