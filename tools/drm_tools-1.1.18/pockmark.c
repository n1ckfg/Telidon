/* 
Program:   pockmark.c
Version:   1.0.2
Date:      2-SEP-2010
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2010 David Mathog and California Institute of Technology (Caltech)

Description:

    Reads a binary stream from stdin and "pockmarks" it by randomly 
    changing data.  Corruption methods are fill (overwrite), insert (with
    the same fill character), and delete.  Only one method at a time may be used,
    but the three may be used together in a pipe.

     % gcc -Wall -pedantic -ansi  -o pockmark pockmark.c
     
     change -DMAXINFILE=40  to increase the number of input
     files which may be processed.

    This code will probably compile with any modern C compiler.
    
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

  1.0.2  02-SEP-2010, fixed typo in integer range message (too low should
    have been too high).  Removed unused variable.
  1.0.1  22-JUN-2010, added bs, so that it can do block style corruption
  1.0    08-JUN-2010, first release

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>            /* for toupper, tolower */
#include <time.h>

#define EXVERSTRING "1.0.2 02-SEP-2010"
#define COPYSTRING  "2010 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"


/* function prototypes */
void emit_help(void);
void insane(char *string);
int  lcl_strcasecmp(char *s1, char *s2);
int  lcl_strncasecmp(char *s1, char *s2,int len);
int  lcl_strcmprange(char *s1, char *s2, int start, int end, int usecase);
int  lstrcasecmp(char *s1, int len1, char *s2, int len2);
int  lstrtol(char *string,int length, long *ival);
void process_command_line_args(int argc,char **argv);
void setirangenumeric(int *val,int *numarg, int lower, int upper, int argc,char **argv,char * label);

/* globals */

int          maxgap = 64000;
int          maxrun = 1024;
int          method = 0;
int          fill   = 0;
int          bs     = 1;
unsigned int seed   = 0;

/* functions */

void insane(char *string){
  (void) fprintf(stderr,"%s\n",string);
  exit(EXIT_FAILURE);
}

void emit_help(void){
  (void) fprintf(stdout,"pockmark: corrupt a data stream. Reads from stdin, writes to stdout.\n");
  (void) fprintf(stdout,"Command line options are:\n\n");
  (void) fprintf(stdout," -maxgap N   longest number of blocks between corruptions [range 1-%d, default %d]\n",INT_MAX,maxgap);
  (void) fprintf(stdout," -maxrun N   longest run of blocks corrupted [range 1-%d, default %d]\n",INT_MAX,maxrun);
  (void) fprintf(stdout," -method N   corruption method: 0 overwrite, 1 insert, 2 delete [default 0]\n");
  (void) fprintf(stdout," -fill   N   integer inserted or overwritten at corrupted locations [range 0-255, default 0]\n");
  (void) fprintf(stdout," -seed   N   large integer seed for the random number generator [default is time in seconds]\n");
  (void) fprintf(stdout," -bs     N   block size [default 1, act on bytes]\n");
  (void) fprintf(stdout," -h          print this help message (also -help --h --help -? --?)\n");
  (void) fprintf(stdout," -i          emit version, copyright, license and contact information\n");
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

int  lcl_strncasecmp(char *s1, char *s2,int len){
int c1;
int c2;
  for(;len>0 ;s1++,s2++,len--){
    c1=toupper(*s1);
    c2=toupper(*s2);
    if(c1 < c2)return -1;
    if(c1 > c2)return  1;
    if(c1 == 0)return  0;  /*c2 also is 0 in this case */
  }
  return 0; /* identical for the first len characters */
}

void setirangenumeric(int *val,int *numarg, int lower, int upper, int argc,char **argv,char * label){
  (*numarg)++;
  if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
    (void) fprintf( stderr, "%s: missing argument\n",label);
    exit(EXIT_FAILURE);
  }
  if(sscanf(argv[*numarg],"%d",val) != 1){
    (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
    exit(EXIT_FAILURE);
  }
  if(*val < lower){
    (void) fprintf(stderr,"Illegal (too low) integer argument/parameter [%s %s] \n",label,argv[*numarg]);
    exit(EXIT_FAILURE);
  }
  if(*val > upper){
    (void) fprintf(stderr,"Illegal (too high) integer argument/parameter [%s %s] \n",label,argv[*numarg]);
    exit(EXIT_FAILURE);
  }
}

void setiunsignednumeric(unsigned int *val,int *numarg, int argc,char **argv,char * label){
  (*numarg)++;
  if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
    (void) fprintf( stderr, "%s: missing argument\n",label);
    exit(EXIT_FAILURE);
  }
  if(sscanf(argv[*numarg],"%u",val) != 1){
    (void) fprintf(stderr,"Bad unsigned integer argument/parameter [%s %s] \n",label,argv[*numarg]);
    exit(EXIT_FAILURE);
  }
}


void  process_command_line_args(int argc,char **argv){
    
int  numarg=0;

  if(argc <2){ /* no arguments */
    emit_help();
  }
      
  
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
    else if(lcl_strcasecmp(argv[numarg], "-maxgap")==0){
      setirangenumeric(&maxgap,&numarg,1,INT_MAX,argc,argv,"-maxgap");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-maxrun")==0){
      setirangenumeric(&maxrun,&numarg,1,INT_MAX,argc,argv,"-maxrun");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-method")==0){
      setirangenumeric(&method,&numarg,0,2,argc,argv,"-method");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-fill")==0){
      setirangenumeric(&fill,&numarg,0,255,argc,argv,"-fill");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-seed")==0){
      setiunsignednumeric(&seed,&numarg,argc,argv,"-seed");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-bs")==0){
      setirangenumeric(&bs,&numarg,1,INT_MAX,argc,argv,"-bs");
      continue;
    }
    else {
       (void) fprintf(stderr,"pockmark: fatal error: on command line [%s] is not recognized.  Use the -h flag to list options.\n",argv[numarg]);
       exit(EXIT_FAILURE);
    }
  }
  if(!seed)seed = time(NULL);  /* have to put something into the seed */
}

#define INGAP 0
#define INRUN 1
int main(int argc, char *argv[]){
long int gap,run;
int c,c2;
int state=INGAP;

  process_command_line_args(argc,argv);
  srand(seed);
  gap = bs * ( 1 + (rand() / (RAND_MAX / maxgap)));
  run = 0;
  while(1){
    c2 = c = getc(stdin);

    if(c==EOF){
      if(feof(stdin))break;
      insane("pockmark: fatal read error");
    }
    if(gap){
      gap--;
    }
    else if(run){
      c2=fill;
    }
    else {
      if(state == INRUN){
        state =  INGAP;
        gap   =  bs * ( 1 + (rand() / (RAND_MAX / maxgap))) - 1;
      }
      else {
        state =  INRUN;
        run   =  bs * ( 1 + (rand() / (RAND_MAX / maxrun)));
        c2=fill;
      }
    }
    switch(method){
      case 0:  /* overwrite */
        if(run)run--;
        if(EOF==putc(c2,stdout)){
          insane("pockmark: fatal write error");   
        }
        break;
      case 1:  /* insert   - do them all at once */
        c2=fill;
        while(run){
          run--;
          if(EOF==putc(c2,stdout)){
            insane("pockmark: fatal write error");   
          }
        }
        if(EOF==putc(c,stdout)){
          insane("pockmark: fatal write error");   
        }
        break;
      case 2:  /* delete    */
        if(run){
          run--;
        }
        else {
          if(EOF==putc(c,stdout)){
            insane("pockmark: fatal write error");   
          }
        }
        break;
      default:
        insane("pockmark: fatal programming error");
    }
  }
  exit(EXIT_SUCCESS);
}


