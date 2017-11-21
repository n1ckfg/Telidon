/* 
Program:   execinput.c
Version:   1.0.0
Date:      05-MAR-2002
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2002 David Mathog and California Institute of Technology (Caltech)

Description:

    Reads input and executes each line via a system() call as long
    as the line is >= 1 character long.  Sometimes handy for putting
    at the end of a long pipe or text file processing stream.  For instance,
    on unix:
    
    find . | grep \/ | extract -cols "mv [1,] [1,-2][cu:-1,]" -dl \/ -mt | execinput
    
    would change all files to upper case.

    Compiles cleanly with:

     % gcc -Wall -pedantic -ansi -o execinput execinput.c
     
    This code will probably compile with any modern C compiler.
    
Changes:

  1.0.0 07-MAR-2002, initial coding.

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


*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>            /* for toupper, tolower */

#define EXVERSTRING "1.0.1  19-OCT-2006"
#define COPYSTRING  "2002,2006 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"
#define MYMAXSTRING 16000
#define NO    0
#define YES   1

/* function prototypes */

void emit_help(void);
int  lcl_strcasecmp(char *s1, char *s2);
void insane(char *string);
void process_command_line_args(int argc,char **argv,int *maxwidth, int *bail);
void setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label);

/* globals */
FILE *lcl_stdin;
FILE *lcl_log;
char *comments;

/* functions */

void insane(char *string){
 (void) fprintf(stderr,"%s\n",string);
 exit(EXIT_FAILURE);
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

void emit_help(void){
(void) fprintf(stderr,"execinput command summary:\n\n");
(void) fprintf(stderr,"This program reads one line at a time from stdin or a file\n");
(void) fprintf(stderr,"  and executes it in a subprocess.\n\n");
(void) fprintf(stderr,"  Command line options are.\n");
(void) fprintf(stderr,"   -in   file    input file            (Default = stdin)\n");
(void) fprintf(stderr,"   -logf file    log to file           (Default = no logging)\n");
(void) fprintf(stderr,"   -loge         log to stderr         (Default = no logging)\n");
(void) fprintf(stderr,"   -wl   N       longest command       (Default = %d)\n",MYMAXSTRING);
(void) fprintf(stderr,"   -ef           exit on first failure (Default = continue to end of input)\n");
(void) fprintf(stderr,"   -c    string  lines starting with a character in string are\n");
(void) fprintf(stderr,"                 comments and are not executed. (Default = do all lines)\n");
(void) fprintf(stderr,"   -h            print this help message (also -help --h --help -? --?)\n");
(void) fprintf(stderr,"   -i            emit version, copyright, license and contact information\n\n");
(void) fprintf(stderr,"  Examples (unix):\n\n");
(void) fprintf(stderr,"  %% echo 'mv foo Foo' | execinput\n");
(void) fprintf(stderr,"  %% generate_commands > thecmds ; execinput -in thecmds \n");
exit(EXIT_FAILURE);
}

void  process_command_line_args(int argc,char **argv, 
    int *maxwidth, int *bail){

int  numarg=0;

  
  *maxwidth=MYMAXSTRING;
  *bail=NO;
  lcl_log=NULL;
  lcl_stdin=stdin;
  comments=NULL;
  
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
    else if(lcl_strcasecmp(argv[numarg], "-c")==0){
      comments=argv[++numarg];
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-wl")==0){
      setiposnumeric(maxwidth,&numarg,argc,argv,"-wl");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-in")==0){
      lcl_stdin=fopen(argv[++numarg],"r");
      if(lcl_stdin==NULL)insane("execinput: fatal error: could not open input file");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-logf")==0){
      lcl_log=fopen(argv[++numarg],"w");
      if(lcl_log==NULL)insane("execinput: fatal error: could not open log file");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-loge")==0){
      lcl_log=stderr;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-ef")==0){
      *bail=YES;
      continue;
    }
    else {
       (void) fprintf(stderr,"execinput: fatal error: on command line [%s] is not recognized.  Use the -h flag to list options.\n",argv[numarg]);
       exit(EXIT_FAILURE);
    }
  }

  /* sanity checking */
   
}


int main(int argc, char *argv[]){
/* command line values */

int maxwidth,bail;

/* other values */
int outstat;
char *buffer;   /* buffer to hold lines */
char *newline;  /* used to point to newline in buffer */

  process_command_line_args(argc,argv,&maxwidth,&bail);
    
  buffer=malloc(sizeof(char)*(maxwidth+1));
  if(buffer == NULL){
      insane("execinput: fatal error: icould not allocate character buffer\n");
  }
  while( fgets(buffer,maxwidth,lcl_stdin) != NULL){
    newline=strstr(buffer,"\n");
    if(newline == NULL){   /* string truncated, this is fatal in this program */
      (void) fprintf(stderr,"execinput: fatal error: input line was longer than %d\n",maxwidth);
      exit(EXIT_FAILURE);
    }
    *newline='\0';                        /* replace the \n with a terminator */
    if(comments==NULL || strchr(comments,buffer[0]) == NULL){
      outstat=system(buffer);
      if(outstat==EXIT_SUCCESS){
        if(lcl_log != NULL)(void) fprintf(lcl_log,"success:%8.8x: %s\n",outstat,buffer);
      }
      else {
        if(lcl_log != NULL)(void) fprintf(lcl_log,"failed: %8.8x: %s\n",outstat,buffer);
        if(bail==YES)exit(EXIT_FAILURE);
      }
    }
    else {
        if(lcl_log != NULL)(void) fprintf(lcl_log,"comment: 00000000: %s\n",buffer);
    }
  }
  exit(EXIT_SUCCESS);
}
