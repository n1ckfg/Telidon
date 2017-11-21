/* 
Program:   columnadd.c
Version:   1.0.3
Date:      12-NOV-2012
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2006 David Mathog and California Institute of Technology (Caltech)

Description:

 Simple program that adds digits in columns in text files.  Ported
 from a much older Fortran implementation.  This version can also
 add times in some formats, and can handle negative numbers (or times)
 in the columns.  It cannot handle scientific notation.  Note that -nn
 still sums into the negative bins but then ignores those numbers later.
 
Method carries to one column left at multiples of 10 unless:
  A.) One column left is a ".", in which case it carries two columns left
        if that case is also numeric or a space.  If it is neither it does not
        carry.
  B.) Times: Left most # in :##. or :##:, in which case carry at 60
        to the other side of the :
  C.) Times: Bracketed by DDD<space>HH:, in which case carry at 24 on
        the hours to the DDD on the other side of the space

	
Changes:

  1.0.3 12-NOV-2012, fixed some compiler warnings with recent gcc caused
     by set but unused variables.
  1.0.2 23-OCT-2006, changed license to GPL 2.
  1.0.1 06-APR-2006, removed unneeded unistd.h include.
  1.0.0 28-MAR-2006, first release

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

Miscellaneous:
    This should be relatively portable on Unix systems.  Compiles
    and builds on RedHat 7.3 and Solaris 8 with
    
    gcc -Wall -ansi -pedantic -o columnadd columnadd.c
    
    

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  /* for strcmp()  */
#include <ctype.h>   /* for toupper() */

/* definitions */
#define EXVERSTRING "1.0.3 12-NOV-2012"
#define COPYSTRING  "2012 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"
#ifndef DEFLW
#define DEFLW 16384
#endif
/*characterization of columns */
#define COL_INIT    0  /* initial value, state not known yet                   */
#define COL_NODIGIT 1  /* definitely not a digit, cannot change                */
#define COL_D10     2  /* a digit with 10 carry, can change to NODIGIT,D6,D24  */
#define COL_D6      3  /* a digit with  6  carry, can change to NODIGIT        */
#define COL_D24L    4  /* a left digit of pair with 24 carry, can change to NODIGIT         */
#define COL_D24R    5  /* a right digit of with 24 carry, can change to NODIGIT         */
#define COL_PERIOD  6  /* a period, can change to NODIGIT                      */
#define COL_COLON   7  /* a colon (if time is enabled), can change to NODIGIT  */
#define COL_SPACE   8  /* a space, can change to D* or NODIGIT              */
#define COL_BLANK   9  /* a space that is carried over and cannot become DIGIT */
#define COL_MINUS  10  /* used only on output to signal a negative sign */
/* super_fgets() status bits */
#define SFG_EOF              1 /* input terminated by End of File              */
#define SFG_EOL              2 /* input terminated by End of line (\n)         */
#define SFG_CRLF             4 /* input terminated by CRLF (\r\n) \r remains!  */
#define SFG_EMBEDDED_NULL    8 /* embedded NULL characters were read           */
#define SFG_BUFFER_FULL     16 /* input buffer full                            */
#define SFG_READERROR       32 /* unrecoverable read error                     */

typedef struct is_opt_struct   OPTNODE;
typedef struct is_sum_struct   SUMNODE;
struct is_opt_struct {
   int  lw;      /* maximum line length                               */
   int  nt;      /* disable time sums, syntax: [hh:]mm:ss[.lll]       */
   int  nb;      /* do not emit sums and reset at blank lines         */
   int  nz;      /* do not zero a column on a nonnumeric character    */
   int  nn;      /* no negative, ignores negative numbers             */
   int  np;      /* no positive, ignores positive numbers             */
   int  echo;    /* echo input lines OTHER than blanks                */
   int  sr;      /* shift input right offset spaces                   */
   char *prefix; /* prefix to emit at front of each sum line          */
   FILE *in;     /* read from file, default and "-" are from stdin    */
   FILE *out;    /* write to  file, default and "-" are to   stdout   */
};
struct is_sum_struct {
   unsigned int  pos;      /* for adding positive values  */
   unsigned int  neg;      /* for adding negative values  */
};

/* function prototypes */
void add_pos_neg(SUMNODE *sums, char *tags, int len);
void complement_and_add(SUMNODE *sums, char *tags, int len, 
       int first, int last, int sign);
void do_carries(SUMNODE *sums, char *tags, int len);
void do_pn_carries(SUMNODE *sums, char *tags, int len);
void dump_info(SUMNODE *sums, char *tags, int len); /* for debugging */
void emit_and_clear(char *buf, SUMNODE *sums, char *tags,
        OPTNODE *options, size_t *maxterm);
void emit_help(void);
void insane(char *string);
int  lcl_strcasecmp(char *s1, char *s2);
void process_command_line_args(int argc,char **argv, OPTNODE *options);
void setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void sum_col(char *buf, SUMNODE *sums, char *tags, OPTNODE *options, size_t cterm, size_t *maxterm);
int  super_fgets(char *string, size_t size, FILE *stream,
        size_t *cterm, int enchar);

/* functions */
void emit_help(void){
(void) fprintf(stderr,"columnadd:\n");
(void) fprintf(stderr,"  Adds columns of [signed] integers and/or [signed] times.\n\n");
(void) fprintf(stderr,"    There must be enough space columns between value columns\n");
(void) fprintf(stderr,"    such that the absolute value of the sum of the positive\n");
(void) fprintf(stderr,"    terms and the absolute value of the sum of the negative\n");
(void) fprintf(stderr,"    terms do not overflow into adjacent columns or off the front\n");
(void) fprintf(stderr,"    of the line.  Numeric precision is limited only by the line length.\n\n");
(void) fprintf(stderr,"  Accepts numeric formats: \n");
(void) fprintf(stderr,"      [-]digits[.digits]\n");
(void) fprintf(stderr,"     [-][digits].digits\n\n");
(void) fprintf(stderr,"  Accepts time formats: (2 digits only for h,m,s; unlimited digits for d,c)\n");
(void) fprintf(stderr,"     [-]dd hh:mm[:[ss[.cc]]]\n");
(void) fprintf(stderr,"        [-]hh:mm[:[ss[.cc]]]\n");
(void) fprintf(stderr,"           [-]mm:[ss[.[cc]]]\n");
(void) fprintf(stderr,"          [-]:mm:[ss[.[cc]]]\n\n");
(void) fprintf(stderr,"command summary:\n\n");
(void) fprintf(stderr,"   [no args]       sum numeric values in columns, read from stdin, write to stdout\n");
(void) fprintf(stderr,"   -nt             disable time sums\n");
(void) fprintf(stderr,"   -nb             do not emit or zero sums at blank lines  (sum entire input)\n");
(void) fprintf(stderr,"   -nz             do not zero a column on a nondigit or space character\n");
(void) fprintf(stderr,"   -nn             no negatives, parse but do not sum negative numbers (not with -np)\n");
(void) fprintf(stderr,"   -np             no positives, parse but do not sum positive numbers (not with -nn)\n");
(void) fprintf(stderr,"   -lw N           maximum line width, default is: %d\n",DEFLW);
(void) fprintf(stderr,"   -echo           echo input lines, other than blanks\n");
(void) fprintf(stderr,"   -sr N           shift input right N spaces, default is 0\n");
(void) fprintf(stderr,"   -pre STRING     prefix sum lines with STRING\n");
(void) fprintf(stderr,"   -in  file       read from file, default and \"-\" are from stdin\n");
(void) fprintf(stderr,"   -out filename   write to  file, default and \"-\" are to   stdout\n");
(void) fprintf(stderr,"   -append file    append to file, default is -out \n");
(void) fprintf(stderr,"   -h              print this help message (also -help --h --help -? --?)\n");
(void) fprintf(stderr,"   -i              emit version, copyright, license and contact information\n\n");
exit(EXIT_FAILURE);
}

void insane(char *string){
 (void) fprintf(stderr,"%s\n",string);
 exit(EXIT_FAILURE);
}

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
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%d",val) != 1){
        (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(*val <= 0){
        (void) fprintf(stderr,"Illegal nonpositive integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}

void process_command_line_args(int argc,char **argv,OPTNODE *options){

int numarg=0;

 options->nt     = 0;
 options->nb     = 0;
 options->nz     = 0;
 options->nn     = 0;
 options->np     = 0;
 options->echo   = 0;
 options->sr     = 0;
 options->lw     = DEFLW;
 options->in     = stdin;
 options->out    = stdout;
 options->prefix = NULL;


 while( ++numarg < argc){
    if( (lcl_strcasecmp(argv[numarg], "-h")==0)     ||
        (lcl_strcasecmp(argv[numarg], "--h")==0)    ||
        (lcl_strcasecmp(argv[numarg], "-?")==0)     ||
        (lcl_strcasecmp(argv[numarg], "--?")==0)    ||
        (lcl_strcasecmp(argv[numarg], "-help")==0)  ||
        (lcl_strcasecmp(argv[numarg], "--help")==0) ){
      emit_help();
    }
    else if(lcl_strcasecmp(argv[numarg], "-i")==0){
      (void)fprintf(stderr,"Version:   %s\n",EXVERSTRING);
      (void)fprintf(stderr,"bugs to:   %s\n",BUGSTRING);
      (void)fprintf(stderr,"Copyright: %s\n",COPYSTRING);
      (void)fprintf(stderr,"License:   %s\n",LICSTRING);
      exit(EXIT_SUCCESS);
    }
    else if(lcl_strcasecmp(argv[numarg], "-append")==0){
      numarg++;
      if(0==strcmp(argv[numarg],"-"))continue;
      options->out=fopen(argv[numarg],"a");
      if(options->out==NULL)insane("Could not open the specified output file for append");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-echo")==0){
      options->echo=1;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-in")==0){
      numarg++;
      if(0==strcmp(argv[numarg],"-"))continue;
      options->in=fopen(argv[numarg],"r");
      if(options->in==NULL)insane("Could not open the specified input file");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-lw")==0){
      setiposnumeric(&(options->lw),&numarg,argc,argv,"-lw");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-nb")==0){
      options->nb=1;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-nn")==0){
      options->nn=1;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-np")==0){
      options->np=1;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-nt")==0){
      options->nt=1;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-nz")==0){
      options->nz=1;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-sr")==0){
      setiposnumeric(&(options->sr),&numarg,argc,argv,"-sr");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-out")==0){
      numarg++;
      if(0==strcmp(argv[numarg],"-"))continue;
      options->out=fopen(argv[numarg],"w");
      if(options->out==NULL)insane("Could not open the specified output file");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-pre")==0){
      numarg++;
      options->prefix=argv[numarg];
      continue;
    }
    else {
      (void) fprintf(stderr,"Unknown command line argument: %s\n",argv[numarg]);
      exit(EXIT_FAILURE);
      continue;
    }
  }
  if(options->nn && options->np)insane("illegal options: both -nn and -np specified");
}

/* super_fgets is a wrapper around getc.  It does the following:

  A:  (like fgets) reads from a stream 
  B:  (like fgets) accepts a preallocated buffer 
  C:  (like fgets) accepts the size of that preallocated buffer 
  D:  (unlike fgets) terminates the characters read with a '\0' in
      all cases. 
  E:  (unlike fgets) returns the position of the terminating null =
      number of characters in the buffer (size_t).
  F:  (unlike fgets) sets a status integer where the bits are as
      defined in the table far above (SFG_*).  Status of 0 is a normal
      read.
  G:  (unlike fgets) either ignores, deletes, or replaces 
      embedded NULL characters depending on the value of enchar:
        <0:  leave   the embedded null characters in the string
         0:  delete  the embedded null characters
        >0:  replace the embedded null characters with enchar
      
  Limitations: Not a drop in fgets() replacement!
               Cannot process arbitrary binary data from a pipe
                 on Windows and probably some other platforms.  It will
                 usually do so if the data is read from a file opened
                 "rb" - but in that case the EOL characters will show up
                 explicitly here.
*/

int super_fgets(char *string, size_t size, FILE *stream,
  size_t *cterm, int enchar){
  
size_t       lastslot;      /* the last character cell in the buffer */
size_t       icterm;        /* internal cterm value */
int          status;        /* status value */
int          readthis;      /* the character which was read */

icterm   = 0;
status   = 0;
lastslot = size-1;

  while(1){
  
     /* Buffer full? 
          Signal this and exit the read loop. */
     if(icterm == lastslot){
       status |= SFG_BUFFER_FULL;
       break;
     }
     
     /* get the next character from the input stream */
     
     readthis=getc(stream);
     
     /* EOF or read error? 
          Figure out which and exit the read loop. */
     
     if(readthis == EOF){
       if(feof(stream)){  status |= SFG_EOF;        }
       else {             status |= SFG_READERROR;  }
       break;
     }
     
     /* Line terminator?  
         Signal EOL. 
         Return characters read so far, but NOT the terminator.
         Check for and signal \r<EOL>.  If found, leave the \r.
         Exit the read loop. */
     
     if(readthis == '\n'){
       status |= SFG_EOL;
       if( (icterm > 0) && (string[icterm-1]=='\r')) status |= SFG_CRLF;
       break;
     }


     /* Normal characters or Embedded null characters?
          Normal:  
            Store as is.
          Embedded Null:
            These are utterly toxic to most C string routines.
            Handle them here as instructed by enchar.
            Signal an embedded null was read from the input.*/

     if(readthis != '\0'){
       string[icterm] = readthis;
     }
     else {
       status |= SFG_EMBEDDED_NULL;  /* warn about embedded null characters */
       if (enchar == 0) {      continue;                  }  /* delete  null char */
       else if(enchar > 0){    string[icterm] = enchar;   }  /* replace null char */
       else {                  string[icterm] = '\0';     }  /* store   null char */
       /* enchar < 0 instructs that it be stored as a regular character */
     }
     icterm++;

  }
  
  string[icterm]='\0';  /* terminate the string!!!! */
  *cterm  = icterm;     /* location of the terminator = length of string without terminator */
  return status;
  
}

/* Note, at this point no carries are done, just sum in each column where digits are found,
Note that "-" only means negative like this: -12.3
Not: --1 or - 1
*/
void sum_col(char *buf, SUMNODE *sums, char *tags, OPTNODE *options, size_t cterm, size_t *maxterm){
int  i;
char convert[2];
int  negative;
int  period;

  convert[1] = '\0';
  negative   = 0;
  period     = 0;
  if(cterm > *maxterm)*maxterm=cterm;
  for(i=0;i<cterm;i++){
    switch (tags[i]) {
      case COL_INIT:
        if(isdigit((int) buf[i])){
          tags[i]   = COL_D10;
        }
        else if(buf[i]==' '){
          tags[i]   = COL_SPACE;
          /* have to look right here to try to determine if this space will later be
          a blank, so that the negative should carry over it.
          -dShh:  or -dSSh: or -dSSS:
           */
          if(!(
                 (i+3 < cterm && buf[i+3]==':') ||
                 (i+2 < cterm && buf[i+2]==':') ||
                 (i+1 < cterm && buf[i+1]==':')
              )
            ){ negative  = 0; }
          period    = 0;
        }
        else if(buf[i]=='.'){
          if(period>0)negative=0;
          tags[i]   = COL_PERIOD;
          period   += 1;
          if(!options->nt && i>=4){ 
            /* seconds to the left of period? */
            if((tags[i-4]==COL_D10 || tags[i-4]==COL_SPACE) &&
                tags[i-3]==COL_COLON && 
                tags[i-2]==COL_D10 && tags[i-1]==COL_D10){
              tags[i-2]=COL_D6;
            }
          }
        }
        else if(buf[i]==':'){
          if(options->nt){
            tags[i]   = COL_NODIGIT;  
            negative  = 0;
            period    = 0;
          }
          else {
            if(period>0)negative=0;
            tags[i]   = COL_COLON;  
            period    = 0;
            /* minutes to the left of colon?  Must have one of these syntaxes:
                      V we are at this position
               D HH:MM:SS[.CC]
                  H:MM:SS[.CC]
                    MM:SS[.CC]
                     M:SS[.CC]
                   ^^^^  only this part is examined
                Note that this can INITIALLY cause the left most H to be labeled as D6, which
                is corrected by the code below for i>=7.
             */
            if( (i>=4)                                         && 
                (tags[i-3]==COL_COLON || tags[i-3]==COL_SPACE) &&
                (tags[i-2]==COL_D10   || tags[i-2]==COL_SPACE) &&
                 tags[i-1]==COL_D10){
              tags[i-2]=COL_D6;
            }
            /* days and hours to the left of colon?  Must have EXACTLY this syntax:
                       V we are at this position
              ..D HH:MM:SS
              Hours and Minutes should have already converted to D6 by the section that precedes this.
            */
            if( (i>=7)                                          && 
                (tags[i-7]==COL_D10   || tags[i-7]==COL_SPACE)  &&
                 tags[i-6]==COL_SPACE                           && 
                (tags[i-5]==COL_D6    || tags[i-5]==COL_D10 || tags[i-5]==COL_SPACE)   &&
                 tags[i-4]==COL_D10                             &&
                 tags[i-3]==COL_COLON                           &&
                 tags[i-2]==COL_D6                              &&
                 tags[i-1]==COL_D10 ){
                tags[i-6]=COL_BLANK;
                tags[i-5]=COL_D24L;
                tags[i-4]=COL_D24R;
            }
          }
        }
        else if(buf[i]=='-'){
          tags[i]   = COL_SPACE;
          negative += 1;
          period    = 0;
        }
        else {
          tags[i]=COL_NODIGIT;
          negative  = 0;
          period    = 0;
        }
        break;
      case COL_NODIGIT:  /* black hole, once a nondigit, always a nondigit */
        negative = 0;
        period   = 0;
        break;
      case COL_D10:  /* All of these just add in the column, their differences */
      case COL_D6:   /* don't kick in until the final carry/add stage across columns.*/
      case COL_D24L:
      case COL_D24R:
        if(isdigit((int) buf[i])){ 
        }
        else {
          if(buf[i]=='-'){
            negative    += 1;
            period       = 0;
          }
          else if(buf[i]=='+'){
            negative     = 0;
            period       = 0;
          }
          /* a space is ok, nothing else ever is, not even a colon or period, unless
             nozero is set  */
          else if(buf[i]!=' ' && !options->nz){
            tags[i]      = COL_NODIGIT;
            sums[i].pos  = 0;
            sums[i].neg  = 0;
            negative     = 0;
            period       = 0;
          }
        }
        break;
      case COL_PERIOD:
        if(buf[i] == '.'){
          if(period)negative=0;  /* only one period allowed in a negative number */
          period    += 1;
          /* seconds to the left of period?\ Must have EXACTLY this syntax:
                         V we are at this position
                  X:MM:SS.    or
                  X  M:SS.    or
                  X   :SS.    or
                  X MM:SS.    where X is any character
          */
          if(!options->nt && i>=4){ 
            /* seconds to the left of period? */
            if((tags[i-4]==COL_D10 || tags[i-4]==COL_SPACE) &&
                tags[i-3]==COL_COLON && 
                tags[i-2]==COL_D10 && tags[i-1]==COL_D10){
              tags[i-2]=COL_D6;
            }
          }
        }
        /* a space is ok, nothing else ever is, not even a digit, colon, or - */
        else if( buf[i] != ' '){
          tags[i]    = COL_NODIGIT;
          period     = 0;
        }
        break;
      case COL_COLON:
        if(buf[i] == ':'){ /* cannot determine yet what to do about negative */
          period     = 0;
          if(!options->nt){
            /* minutes to the left of colon?  Must have one of these syntaxes:
                      V we are at this position
               D HH:MM:SS[.CC]
                  H:MM:SS[.CC]
                    MM:SS[.CC]
                     M:SS[.CC]
                   ^^^^  only this part is examined
                Note that this can INITIALLY cause the left most H to be labeled as D6, which
                is corrected by the code below for i>=7.
             */
            if( (i>=4)                                         && 
                (tags[i-3]==COL_COLON || tags[i-3]==COL_SPACE) &&
                (tags[i-2]==COL_D10   || tags[i-2]==COL_SPACE) &&
                 tags[i-1]==COL_D10){
              tags[i-2]=COL_D6;
            }
            /* days and hours to the left of colon?  Must have EXACTLY this syntax:
                       V we are at this position
              ..D HH:MM:SS
              Hours and Minutes should have already converted to D6 by the section that precedes this.
            */
            if( (i>=7)                                          && 
                (tags[i-7]==COL_D10   || tags[i-7]==COL_SPACE)  &&
                 tags[i-6]==COL_SPACE                           && 
                (tags[i-5]==COL_D6    || tags[i-5]==COL_D10 || tags[i-5]==COL_SPACE)   &&
                 tags[i-4]==COL_D10                             &&
                 tags[i-3]==COL_COLON                           &&
                 tags[i-2]==COL_D6                              &&
                 tags[i-1]==COL_D10 ){
                tags[i-6]=COL_BLANK;
                tags[i-5]=COL_D24L;
                tags[i-4]=COL_D24R;
            }
          }
        }
        /* a space is ok, nothing else ever is, not even a digit, -,  or period */
        else if(buf[i] != ' ' && !options->nz){
          if(i>1 && ( tags[i-2]==COL_D24L || tags[i-2]==COL_D6)){
            insane("Conflicting types in a column previously holding a time related colon character");
          }
          else {
            tags[i]    = COL_NODIGIT;
            period     = 0;
            negative   = 0;
          }
        }
        break;
      case COL_BLANK: /* The space between hours and days, cannot convert to anything else */
        if(buf[i]==' '){
          period     = 0;
        }
        else if(buf[i]=='-'){
          negative += 1;
          period    = 0;
        }
        else if(buf[i]=='+'){
          negative  = 0;
          period    = 0;
        }
        else {
            insane("Conflicting types in a column previously holding the space between days and hours");
        }
        break;
      case COL_SPACE:
        if(buf[i]==' '){ 
            negative  = 0;
            period    = 0;
        }
        else if(buf[i]=='.'){
          tags[i]     = COL_PERIOD;  
          negative    = 0;
          period      = 1;
        }
        else if(buf[i]==':'){
          if(options->nt){ /* no times, so colon is just a nondigit */
            tags[i]   = COL_NODIGIT;  
            negative  = 0;
            period    = 0;
          }
          else {
            if(period>0)negative=0;
            tags[i]   = COL_COLON;  
            period    = 0;
          }
        }
        else if(buf[i]=='-'){
          negative += 1;
          period    = 0;
        }
        else if(isdigit((int) buf[i])){
          tags[i]     = COL_D10;
        }
        else if(buf[i] != ' '){
          tags[i]     = COL_NODIGIT;
          negative    = 0;
          period      = 0;
        }
        break;
      default:
        insane("Programming error in sum_col()");  
    }
    if(period>1)insane("Invalid number encountered with 2 or more periods");
    if( isdigit((int) buf[i]) && (
          (tags[i]==COL_D10) || 
          (tags[i]==COL_D6)  || 
          (tags[i]==COL_D24L)||
          (tags[i]==COL_D24R) )){
      convert[0] = buf[i];
      if(negative==1){  sums[i].neg += atol(convert); }
      else{             sums[i].pos += atol(convert); }
    }
  }
}

void do_carries(SUMNODE *sums, char *tags, int len){
int          i,col_over;
unsigned int pcarry,ncarry;
unsigned int temp;

  pcarry    = 0;
  ncarry    = 0;
  col_over  = COL_INIT;

  /* do all the carries, for positive and negative sums. */

  for(i=len-1;i>=0;i--){
    switch(tags[i]){
      case COL_NODIGIT:
        /* there should be no carry, do nothing here */
        break;
      case COL_D10:
        sums[i].pos += pcarry;
        sums[i].neg += ncarry;

        pcarry       = sums[i].pos / 10;
        sums[i].pos  = sums[i].pos % 10;

        ncarry       = sums[i].neg / 10;
        sums[i].neg  = sums[i].neg % 10;

        if(pcarry || ncarry){
          /* upgrade a space to a D10 if a carry is required, either one space over
             or across a period.  HOWEVER, do not do this for situations like these:

                V       V    spaces that do NOT upgrade to D10
             123 45  0.1 .9
              +3 65   .2 .3

             As it will merge two numeric columns and make a mess. The user really should
             try to spread out the columns to avoid problems like these.
          */

          if(i>0 && tags[i-1]==COL_SPACE){ 
            if(i>1 && tags[i-2]==COL_D10){
              col_over=COL_D10;
            }
            else {
              tags[i-1]=COL_D10;
            }
          }  
          if(i>1 && tags[i-1]==COL_PERIOD && tags[i-2]==COL_SPACE){
            if(i>2 && tags[i-3]==COL_D10){
              col_over=COL_D10;
            }
            else {
              tags[i-2]=COL_D10;
            }
          }
          /* even with upgrades, is there a place to carry to? */
          if(  i==0                                  ||
               (i>0 &&   tags[i-1]!=COL_D10     &&
                         tags[i-1]!=COL_D6      &&
                         tags[i-1]!=COL_PERIOD)      ||
               (i>1 &&   tags[i-1]==COL_PERIOD && tags[i-2]!=COL_D10)
          ){
            col_over=COL_D10;
          }
        }
        break;
      case COL_D24R:
        sums[i].pos += pcarry;
        sums[i].neg += ncarry;

        pcarry       = sums[i].pos / 10;
        sums[i].pos  = sums[i].pos % 10;

        ncarry       = sums[i].neg / 10;
        sums[i].neg  = sums[i].neg % 10;
        if(pcarry || ncarry){
           if(i>0 && tags[i-1]==COL_SPACE)tags[i-1]=COL_D24L;
           if(i==0)col_over=COL_D24R;
        }
        break;
      case COL_D6:
        sums[i].pos += pcarry;
        sums[i].neg += ncarry;

        pcarry       = sums[i].pos / 6;
        sums[i].pos  = sums[i].pos % 6;

        ncarry       = sums[i].neg / 6;
        sums[i].neg  = sums[i].neg % 6;

        /* ok to carry? */
        if(pcarry || ncarry){
          /* upgrade a space to a colon, if required, also a space to a D10 or D24R */
         if(i>0 && tags[i-1]==COL_SPACE)tags[i-1]=COL_COLON;
         if(i>1 && tags[i-1]==COL_COLON && tags[i-2]==COL_SPACE){
           if(tags[i+2]==COL_COLON){  tags[i-2]=COL_D24R; }
           else {                     tags[i-2]=COL_D10;  }
         }
         if( (i<2)                       || 
             (tags[i-1]!=COL_COLON)      || 
             (tags[i-2]!=COL_D24R && tags[i-2]!=COL_D10)
           )col_over=COL_D6;
        }
        break;
      case COL_D24L:
        sums[i].pos += pcarry;
        sums[i].neg += ncarry;
        temp         = 10*sums[i].pos + sums[i+1].pos;
        pcarry       = temp / 24;
        sums[i].pos  = (temp % 24 ) / 10;
        sums[i+1].pos= (temp % 24 ) % 10;
        
        temp         = 10*sums[i].neg + sums[i+1].neg;
        ncarry       = temp / 24;
        sums[i].neg  = (temp % 24 ) / 10;
        sums[i+1].neg= (temp % 24 ) % 10;
        if(pcarry || ncarry){
          /* if there is a carry for hours -> days change COL_SPACE as needed */
          if(i>0 && tags[i-1]==COL_SPACE)tags[i-1]=COL_BLANK;
          if(i>1 && tags[i-1]==COL_BLANK && tags[i-2]==COL_SPACE)tags[i-2]=COL_D10;
          if(i<2 || tags[i-1]!=COL_BLANK || tags[i-2]!=COL_D10 )col_over=COL_D24L;
        }
        break;
      case COL_PERIOD:
      case COL_COLON:
      case COL_BLANK: /* the special space between days and hours*/
        /* do nothing, just carry over this position */
        if(i==0)col_over=COL_PERIOD;  /* oops, carried off the end of the line */
        break;
      case COL_SPACE:
        if(pcarry || ncarry)insane("Programming error in do_carries(), carried into a space");
        break;
      default:
        insane("Programming error in do_carries()");
        break;
    }
    if(col_over != COL_INIT){
      (void) fprintf(stderr,"FATAL ERROR at column:%d type:%d\n",i,col_over);
      insane("column sums overflow into each other, non-numeric areas, or off front of line");
    }
  }
}

void do_pn_carries(SUMNODE *sums, char *tags, int len){
int          i;
unsigned int carry;
unsigned int temp;

  carry    = 0;

  /* add pos and neg and carry.  Throw out the last carry since the
  neg value will have been complemented */

  for(i=len-1;i>=0;i--){
    switch(tags[i]){
      case COL_D10:
      case COL_D24R:
        sums[i].pos += sums[i].neg + carry;
        carry        = sums[i].pos / 10;
        sums[i].pos  = sums[i].pos % 10;
        break;
      case COL_D6:
        sums[i].pos += sums[i].neg + carry;
        carry        = sums[i].pos / 6;
        sums[i].pos  = sums[i].pos % 6;
        break;
      case COL_D24L:
        sums[i].pos += sums[i].neg + carry;
        temp         = 10*sums[i].pos + sums[i+1].pos;
        carry        = temp / 24;
        sums[i].pos  = (temp % 24 ) / 10;
        sums[i+1].pos= (temp % 24 ) % 10;
        break;
      case COL_PERIOD:
      case COL_COLON:
      case COL_BLANK: /* the special space between days and hours*/
        /* do nothing, just carry over this position */
        break;
      case COL_SPACE:
      case COL_NODIGIT:
      default:
        insane("Programming error in do_pn_carries()");
        break;
    }
  }
}

/*for debugging */
void dump_info(SUMNODE *sums, char *tags, int len){
int i;
  for(i=0;i<len;i++){
    (void) fprintf(stdout,"dump:  i:%2d sump:%4d sumn:%4d  tags:%4d\n",i,sums[i].pos,sums[i].neg,tags[i]);
  }
}


void complement_and_add(SUMNODE *sums, char *tags, int len, 
  int first, int last, int sign){

int i,mspot,lastdig;
unsigned int swap;

  if(sign<0){
    /* first swap pos <->neg digit values */
    for(i=first;i<=last;i++){
      swap        = sums[i].pos;
      sums[i].pos = sums[i].neg;
      sums[i].neg = swap;
    }
  }

  /* complement sums[].neg digits based on D tag values */
  lastdig=0;
  for(i=first;i<=last;i++){
    switch(tags[i]){
      case COL_D10:
        sums[i].neg   = 9 - sums[i].neg;
        lastdig       = i;
        break;
      case COL_D6:
        sums[i].neg   = 5 - sums[i].neg;
        lastdig       = i;
        break;
      case COL_D24L: /* 24R is one to the right, always */
        swap          = 10*sums[i].neg+sums[i+1].neg;
        swap          = 23 - swap;
        sums[i].neg   = swap/10;
        sums[i+1].neg = swap % 10;
        i++;
        lastdig       = i;
        break;
    }
  }
  sums[lastdig].neg += 1;     /* last digit is 1 more than complement N-1 complement */
  
  /* sum right to left */
  do_pn_carries(&sums[first], &tags[first], last-first+1);
  
  /* find a place to put the sign if it is negative */
  if(sign<0){
    if(sums[first].pos !=0 || tags[first]==COL_COLON || tags[first]==COL_PERIOD){
      if(first==0 || tags[first-1] !=COL_SPACE){
        insane("sign overflowed into a numeric or non-numeric area, or off front of line");
      }
      tags[first-1]=COL_MINUS;
    }
    else {
      mspot=first;
      for(i=first+1;i<=last;i++){
        switch(tags[i]){
           case COL_D10:
           case COL_D6:
           case COL_D24L:
           case COL_D24R:
             if(sums[i].pos == 0){
               mspot=i;
             }
             else {
               tags[mspot]=COL_MINUS;
               i=last+1;
             }
             break;
           case COL_PERIOD: /* cannot put a negative sign here */
           case COL_COLON:
             break;
           case COL_BLANK:  /* can put one here though */
             mspot=i;
             break;
           case COL_INIT:
           case COL_NODIGIT:
           case COL_SPACE:
           case COL_MINUS:
           default:
             insane("programming error");
        }
      }
    }
  }
}
  
void add_pos_neg(SUMNODE *sums, char *tags, int len){
int  first,last;
int  i,j;
int  sign; /* 0 undetermined, 1 pos, -1 neg */

  /* Method.  
  1.  Locate a block of numbers (D values and colon, period, blank) 
  2.  Figure out which is greater (absolute) pos or neg.  If neg
       set the sign and swap sum values.
  3.  Complement the neg sums.  Time complementation is as one
      might expect a little odd.
  4.  Add pos and neg summing into pos.   Toss the last carry
      off the left side.
  5.  If the sign bit is set place it as a COL_MINUS.
  repeat
  */
  first     = -1;
  last      = -2;
  sign      = 0;
  tags[len] = COL_NODIGIT; /* simplifies processing slightly */
  for(i=0;i<=len;i++){
    switch(tags[i]){
      case COL_PERIOD: /* unambiguously in a time or number */
      case COL_COLON:
      case COL_BLANK:
      case COL_D10:
      case COL_D6:
      case COL_D24L:
      case COL_D24R:
        if(first<0){
          first=i;
        }
        if(sign==0){
          if(       sums[i].pos > sums[i].neg){  sign=1;  }
          else if(  sums[i].pos < sums[i].neg){  sign=-1; }
        }
        break;
      case COL_NODIGIT:
      case COL_SPACE:
        if(first>=0) last=i-1; /* safe even if first was zero */
        break;
      case COL_INIT:  /* should never happen */
      case COL_MINUS: /* should never happen */
      default:
        insane("programming error");
    }
    if(last>=first){
      if(sign==0){
        /*adds to zero, this one is easy, just set all sums[i].pos to zero*/
        for(j=first;j<=last;j++){  sums[j].pos=0; }
      }
      else {
        complement_and_add(sums,tags,len,first,last,sign); 
      }
      first = -1;
      last  = -2;
      sign  =  0;
    }
  }
}

void emit_and_clear(char *buf, SUMNODE *sums, char *tags,
   OPTNODE *options, size_t *maxterm){
int  i;
char convert[2];
int  lzero;

  convert[1]        = '\0';
  buf[*maxterm]     = ' ';
  buf[*maxterm + 1] = ' ';
  lzero             = 1;
  
  do_carries(sums,tags,*maxterm);
  
  if(options->np){
    for(i=0;i<=*maxterm;i++){ sums[i].pos=0; }
  }
  if(!options->nn){
    add_pos_neg(sums,tags,*maxterm);
  }
  
  /* store characters to emit into tags */
  for(i=0;i<*maxterm;i++){
    switch(tags[i]){
      case COL_D10:
      case COL_D6:
      case COL_D24L:
      case COL_D24R:
        if(sums[i].pos==0 && lzero){
          tags[i]= ' ';
        }
        else {
          (void) sprintf(convert,"%1d",sums[i].pos);
          tags[i] = convert[0];
          lzero   = 0;
        }
        break;
      case COL_PERIOD:
        tags[i] = '.';
        lzero   = 0;
        break;
      case COL_COLON:
        tags[i] = ':';
        lzero   = 0;
        break;
      case COL_INIT:    /* This should never happen*/
      case COL_NODIGIT:
      case COL_SPACE:
        tags[i] = ' ';
        lzero   = 1;
        break;
      case COL_BLANK:
        tags[i] = ' ';
        lzero   = 0;
        break;
      case COL_MINUS:
        if(sums[i+1].pos == 0){
          tags[i]   = ' ';
          tags[i+1] = COL_MINUS;
        }
        else {
          tags[i] = '-';
          lzero   = 0;
        }
        break;
    }
  }
  tags[*maxterm]='\0';
  if(options->prefix!=NULL)(void) fprintf(options->out,"%s",options->prefix);
  (void) fprintf(options->out,"%s\n",tags);

  for(i=0;i<*maxterm;i++){
    sums[i].pos = 0;
    sums[i].neg = 0;
    tags[i]     = COL_INIT;
  }
  *maxterm=0;
}


int main(int argc, char *argv[]){


OPTNODE  *options;   /* command line values */
char     *buf;
size_t    cterm;
SUMNODE  *sums;
char     *tags;  /* do not need a full int */
int       sfg_status;
size_t    data_maxterm=0;
size_t    *maxterm=&data_maxterm;  /* the largest column with numeric data */
int       i;

  options=malloc(sizeof(OPTNODE));
  if(options==NULL)insane("Could not allocate memory for options");
  
  process_command_line_args(argc,argv,options);
  
  buf=malloc(options->lw * sizeof(char));
  if(buf==NULL)insane("Could not allocate memory for input line buffer");
  
  sums=malloc(options->lw * sizeof(SUMNODE));
  if(sums==NULL)insane("Could not allocate memory for sums buffer");

  tags=malloc(options->lw * sizeof(char));
  if(tags==NULL)insane("Could not allocate memory for tags buffer");

  for(i=0;i<options->lw;i++){
     sums[i].pos = 0;
     sums[i].neg = 0;
     tags[i]     = COL_INIT;
     buf[i]      = '\0';
  }
  /* This does nothing bad if sr isn't set */
  for(i=0;i<options->sr;i++){
    buf[i]=' ';
  }
  
  while(1){
    if(sfg_status & SFG_EOF)break;
    sfg_status = super_fgets(&buf[options->sr], options->lw, options->in, &cterm, ' ');
    if(sfg_status & SFG_CRLF){
      /* silently nip off the \r character if present on a CRLF. This should only happen
      for windows files moved to Unix */
      cterm--;
      buf[cterm]='\0';
    }
    if(cterm  == 0 && !options->nb){ /* blank line */
      emit_and_clear(buf,sums,tags,options,maxterm);
      *maxterm=0;
      continue;
    }
    else if(sfg_status & SFG_READERROR){
      insane("extract: fatal error: fatal read error from input file.");
    }
    else if(sfg_status & SFG_BUFFER_FULL){
      insane("extract: fatal error: input long too long for input buffer, use a larger -lw.");
    }
    else {
      if(options->echo)(void) fprintf(options->out,"%s\n",&buf[options->sr]);
      sum_col(buf,sums,tags,options,cterm + options->sr,maxterm);
    }
  }
  
  if(*maxterm>0){
    buf[0]=' '; /* restore (most of) previous line by rem,oving first terminator */
    emit_and_clear(buf,sums,tags,options,maxterm);
  }
  
  exit(EXIT_SUCCESS);
}
