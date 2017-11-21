/* mdump.c
Program:   mdump.c
Version:   1.0.5
Date:      23-OCT-2006
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2002, 2005 David Mathog and California Institute of Technology (Caltech)
   
Description:  
   Dump data out of binary files.
   Useful among other things for extracting NCBI
   gi values from the .[pn]nd blast database file and
   extracts from it the gi numbers present in that file.
   If the byte order is reversed use -flip to turn them over.
   
   Note that long long (type s) is not always available.  If it isn't
   compile with -D MDUMP_NOLONGLONG.
   
   Note that many older compilers do not support long long or do
   not use lld,llu etc.   gcc supports all of these and is available
   for most platforms.
     
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

  1.0.4 11-JUL-2005, Mathog, removed include of unistd.h, wasn't required.
  1.0.3 04-MAY-2005, Mathog, fixed bug, -ds wasn't invoking emit_ds.
  1.0.2 29-JUL-2002, Mathog, fixed bugs MDUMP_NOLONGLONG
  1.0.1 30-APR-2002, Mathog, fixed bugs in -show and -offset
  1.0   21-APR-2002, first release

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>            /* for toupper, tolower */

#define EXVERSTRING "1.0.5  23-OCT-2006"
#define COPYSTRING  "2002,2005,2006 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"

/* prototypes */
int  lcl_strcasecmp(char *s1, char *s2);
void emit_ds(void);
void emit_help(void);
void flipit(char *carray, int size);
void insane(char *string);
void  process_command_line_args(int argc,char **argv,
  char *dtype, int *offset, int *interval, int *multiple,
  int *blocks, int *usesign, int *flip, int *show,  char **format);
void setinonnegnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setstring(char **val,int *numarg,int argc,char **argv,char * label);
void setchar(char *val,int *numarg,int argc,char **argv,char * label);

/* globals */

FILE *lcl_stdin;
FILE *lcl_stdout;

/* functions and main */

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

void insane(char *string){
 (void) fprintf(stderr,"%s\n",string);
 exit(EXIT_FAILURE);
}

/* flipit inverts the byte order in an array of characters 
   where size is 2,4,8 or larger (and even) */

void flipit(char *carray, int size){
char ctemp;
int i;
    for(i=0; i<size/2; i++){
      ctemp            =  carray[i];
      carray[i]        =  carray[size-i-1];
      carray[size-i-1] =  ctemp;
    }
}



void setinonnegnumeric(int *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%d",val) != 1){
        (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(*val < 0){
        (void) fprintf(stderr,"Illegal negative integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}

void setstring(char **val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      *val = argv[*numarg];
}

void setchar(char *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      *val = *(argv[*numarg]);
}

void emit_ds(void){
    (void) fprintf(stderr,"Data sizes in bytes are:\n");
    (void) fprintf(stderr,"c    %d\n",sizeof(char));
    (void) fprintf(stderr,"w    %d\n",sizeof(short int));
    (void) fprintf(stderr,"l    %d\n",sizeof(int));
#ifdef MDUMP_NOLONGLONG
    (void) fprintf(stderr,"s    unavailable\n");
#else
    (void) fprintf(stderr,"s    %d\n",sizeof(long long));
#endif
    (void) fprintf(stderr,"f    %d\n",sizeof(float));
    (void) fprintf(stderr,"d    %d\n",sizeof(double));
    exit(EXIT_SUCCESS);
}

void emit_help(void){
    (void) fprintf(stderr,"usage: mdump [options] (dump data from stdin/file to stdout/file)\n");
    (void) fprintf(stderr,"\noptions:\n");
    (void) fprintf(stderr,"   -in   file   file to dump, if not specified, from stdin\n");
    (void) fprintf(stderr,"   -out  file   write output to this file, if not specified, to stdout\n");
    (void) fprintf(stderr,"   -dtype    t  c=char, s=short, l=long (default), g=longlong, f=float, d=double\n");
    (void) fprintf(stderr,"   -offset   N  begin this many data elements into file, 0=default\n");
    (void) fprintf(stderr,"   -interval N  number of data elements in each repeat block, 1=default\n");
    (void) fprintf(stderr,"   -multiple N  number of data elements to dump from each block (all to one line)\n");
    (void) fprintf(stderr,"                default is interval value\n");
    (void) fprintf(stderr,"   -blocks   N  number of blocks to dump, 0=all=default\n");
    (void) fprintf(stderr,"   -signed      default is unsigned.  Applies to c,s,l,g data types.\n");
    (void) fprintf(stderr,"                (For g type also change format to lld)\n");
    (void) fprintf(stderr,"   -show     t  show offset to data positions in file (relative to -offset)\n");
    (void) fprintf(stderr,"                as:  (hex) 1: bytes, 2: data elements, 3: blocks\n");
    (void) fprintf(stderr,"                   (octal) 4: bytes, 5: data elements, 6: blocks\n");
    (void) fprintf(stderr,"                 (decimal) 7: bytes, 8: data elements, 9: blocks\n");
    (void) fprintf(stderr,"                anything else = do not show position = default\n");
    (void) fprintf(stderr,"   -format 'string'   C format string for output. ' %%width.precisionType' :\n");
    (void) fprintf(stderr,"                c:   c[har],d[ecimal],o[ctal],[he]x default: ' %%c'\n");
    (void) fprintf(stderr,"                s,l: d,o,x                          default: ' %%9d'\n");
    (void) fprintf(stderr,"                g:   ll(d,u[nsigned],o,x)           default: ' %%20llu'\n");
    (void) fprintf(stderr,"                f,d: f[loat],e[xponent]             default: ' %%9e'\n");
    (void) fprintf(stderr,"   -flip     N  invert byte order, as is=default\n");
    (void) fprintf(stderr,"                Ignored for type c.\n");
    (void) fprintf(stderr,"   -ds          Emit data sizes\n");
    (void) fprintf(stderr,"   -h           print this help message (also -help --h --help -? --?)\n");
    (void) fprintf(stderr,"   -i           emit version, copyright, license and contact information\n\n");
    (void) fprintf(stderr,"\nexamples:\n");
    (void) fprintf(stderr," %% mdump -in somefile -dtype l -format ' %%8.8x' -interval 4 -show 2\n");
    (void) fprintf(stderr,"       Dump in hex format integer elements in blocks of 4 per line\n");
    (void) fprintf(stderr,"       and number the lines by data block.\n");
    (void) fprintf(stderr," %% echo ABCD | mdump -dtype c -format ' %%3.3o' -interval 4 -blocks 1\n");
    (void) fprintf(stderr,"       Emits the octal values for the four characters ABCD.\n");
    exit(EXIT_FAILURE);
}

void  process_command_line_args(int argc,char **argv,
  char *dtype, int *offset, int *interval, int *multiple,
  int *blocks, int *usesign, int *flip, int *show,  char **format){
  
int numarg;
int multset=0;

lcl_stdin=stdin;
lcl_stdout=stdout;
*dtype='l';     /* int4 */
*offset=0;      /* start from first int */
*interval=1;    /* emit in blocks of one */
*multiple=1;    /* emit all in the interval = 1 */
*blocks=0;      /* emit all blocks */
*usesign=0;     /* unsigned int */
*flip=0;        /* do not flip bytes */
*show=0;        /* do not show data offsets */
**format='\0';   /* nothing in format, initially */

  for(numarg=1;numarg<argc;numarg++){
    if(0==lcl_strcasecmp(argv[numarg], "-flip")){
      *flip=1;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-signed")){
      *usesign=1;
    }
    else if(lcl_strcasecmp(argv[numarg], "-in")==0){
      lcl_stdin=fopen(argv[++numarg],"r");
      if(lcl_stdin==NULL)insane("mdump: fatal error: could not open input file");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-out")==0){
      lcl_stdout=fopen(argv[++numarg],"w");
      if(lcl_stdout==NULL)insane("mdump: fatal error: could not open output file");
      continue;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-show")){
      setinonnegnumeric(show,&numarg,argc,argv,"-show");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-dtype")){
      setchar(dtype,&numarg,argc,argv,"-dtype");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-offset")){
      setinonnegnumeric(offset,&numarg,argc,argv,"-offset");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-interval")){
      setinonnegnumeric(interval,&numarg,argc,argv,"-interval");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-multiple")){
      setinonnegnumeric(multiple,&numarg,argc,argv,"-multiple");
      multset=1;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-blocks")){
      setinonnegnumeric(blocks,&numarg,argc,argv,"-blocks");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-format")){
      setstring(format,&numarg,argc,argv,"-format");
    }
    else if(lcl_strcasecmp(argv[numarg], "-ds")==0){
      emit_ds();
      exit(EXIT_SUCCESS);
    }
    else if(lcl_strcasecmp(argv[numarg], "-i")==0){
      (void)fprintf(stderr,"Version:   %s\n",EXVERSTRING);
      (void)fprintf(stderr,"bugs to:   %s\n",BUGSTRING);
      (void)fprintf(stderr,"Copyright: %s\n",COPYSTRING);
      (void)fprintf(stderr,"License:   %s\n",LICSTRING);
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
      (void) fprintf(stderr,"mdump:fatal error:no such parameter [%s]\n",argv[numarg]);
      emit_help();
    }
  }
  if(multset==0)*multiple=*interval;
}

int main(int argc, char *argv[]){
int   count,repcount,mcount,bcount,dangle;
int   offset, interval, multiple;
int   blocks, usesign, flip,show;
int   dsize,dformat;
char  dtype;
char  *carray;
char  cformat[100];
char *format=&cformat[0];

char      cv;
short int sv;
int       lv;
#ifdef MDUMP_NOLONGLONG
/* long long not supported on this platform */
#else
long long gv;
#endif
float     fv;
double    dv;

  process_command_line_args(argc,argv,
     &dtype, &offset, &interval, &multiple,
     &blocks, &usesign, &flip, &show, &format);
    
  dangle=0;
  count=0;
  repcount=0;
  mcount=0;
  bcount=0;
  switch (dtype) {
    case 'c':
    case 'C':
      dsize=sizeof(char);
      dformat=0;
      carray = &cv;
      if(*format=='\0')(void) strcpy(format," %c");
      break;
    case 's':
    case 'S':
      dsize=sizeof(short int);
      dformat=2;
      carray = (char *) &sv;
      if(*format=='\0')(void) strcpy(format," %9d");
      break;
    case 'l':
    case 'L':
      dsize=sizeof(int);
      dformat=4;
      carray = (char *) &lv;
      if(*format=='\0')(void) strcpy(format," %9d");
      break;
    case 'f':
    case 'F':
      dsize=sizeof(float);
      dformat=6;
      carray = (char *) &fv;
      if(*format=='\0')(void) strcpy(format," %9e");
      break;
    case 'd':
    case 'D':
      dsize=sizeof(double);
      dformat=8;
      carray = (char *) &dv;
      if(*format=='\0')(void) strcpy(format," %9e");
      break;
    case 'g':
    case 'G':
#ifdef MDUMP_NOLONGLONG
      (void) fprintf(stderr,"mdump, fatal error: type s is not supported on this platform\n");
      exit(EXIT_FAILURE);
#else /* MDUMP_NOLONGLONG */
      dsize=sizeof(long long);
      dformat=10;
      carray = (char *) &gv;
      if(*format=='\0')(void) strcpy(format," %20llu");
      break;
#endif /* MDUMP_NOLONGLONG */
    default:
      (void)fprintf(stderr,"mtype, fatal error, unknown data type %c\n",dtype);
      exit(EXIT_FAILURE);
  }
  if(usesign)dformat++;
  
  while(fread(carray,dsize,1,lcl_stdin)>0){
  

    count++;
    if(count<offset+1)continue;
    if(mcount < multiple){
       if(mcount==0){
         switch(show){
           case 1:   /* byte offsets, hex */
             (void) fprintf(lcl_stdout,"%8.8x ",(count-offset-1)*dsize);
             break;
           case 2:   /* data element offsets, hex */
             (void) fprintf(lcl_stdout,"%8.8x ",(count-offset-1));
             break;
           case 3:   /* block offsets, hex */
             (void) fprintf(lcl_stdout,"%8.8x ",(count-offset-1)/interval);
             break;
           case 4:   /* byte offsets, octal */
             (void) fprintf(lcl_stdout,"%11.11o ",(count-offset-1)*dsize);
             break;
           case 5:   /* data element offsets, octal */
             (void) fprintf(lcl_stdout,"%11.11o ",(count-offset-1));
             break;
           case 6:   /* block offsets, octal */
             (void) fprintf(lcl_stdout,"%11.11o ",(count-offset-1)/interval);
             break;
           case 7:   /* byte offsets, decimal */
             (void) fprintf(lcl_stdout,"%9d ",(count-offset-1)*dsize);
             break;
           case 8:   /* data element offsets, decimal */
             (void) fprintf(lcl_stdout,"%9d ",(count-offset-1));
             break;
           case 9:   /* block offsets, decimal */
             (void) fprintf(lcl_stdout,"%9d ",(count-offset-1)/interval);
             break;
         }         
       }
       if(flip){ flipit(carray,dsize); }
       switch (dformat) {
          case 0: 
            (void) fprintf(lcl_stdout,format,(unsigned char) cv);
            break;
          case 1:
            (void) fprintf(lcl_stdout,format,(char) cv);
            break;
          case 2: 
            (void) fprintf(lcl_stdout,format,(unsigned short int) sv);
            break;
          case 3:
            (void) fprintf(lcl_stdout,format, sv);
            break;
          case 4: 
            (void) fprintf(lcl_stdout,format, (unsigned int) lv);
            break;
          case 5:
            (void) fprintf(lcl_stdout,format, lv);
            break;
          case 6: /* no unsigned for float */ 
          case 7:
            (void) fprintf(lcl_stdout,format, fv);
            break;
          case 8: /* no unsigned for double */
          case 9:
            (void) fprintf(lcl_stdout,format, dv);
            break;
          case 10: 
#ifndef  MDUMP_NOLONGLONG
           (void) fprintf(lcl_stdout,format, (unsigned long long) gv);
#endif
            break;
          case 11:
#ifndef  MDUMP_NOLONGLONG
            (void) fprintf(lcl_stdout,format, gv);
#endif
            break;
       }
       dangle=1;
    }
    repcount++;
    mcount++;
    if(repcount>=interval){
       repcount=0;
       mcount=0;
       bcount++;
       (void) fprintf(lcl_stdout,"\n");
       dangle=0;
       if(blocks != 0 && bcount >= blocks)break;
    }
  }
  
  if(dangle)(void) fprintf(lcl_stdout,"\n");
  exit(EXIT_SUCCESS);
}
