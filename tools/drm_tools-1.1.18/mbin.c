/* mbin.c
Program:   mbin.c
Version:   1.0.3
Date:      14-NOV-2012
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2011 David Mathog and California Institute of Technology (Caltech)
   
Description:  
   mbin == Multiple Buffer INput
   With the companion program mbout buffers a data stream
   through a series of buffers, such that input/output
   runs at full speed until it stalls waiting for data or
   waiting for a buffer to open up.
   
   mbin splits an input stream sequentially
   between 2 buffer files.  These are typically
   located on separate spindles.  When it begins writing
   one it sets a lock file (lock_filename) and when it
   completes writing that one it writes "blocksize filename"
   to stdout.  The companion program mbout (Multiple Buffer OUTput)
   reads this information, and then copies the fragments
   back into a single stream. 
   
   WARNING!  This really needs large file support to be of any use.  For gcc
   compile like this:
   
     gcc -Wall -pedantic -ansi  -D_LARGE_FILE_SOURCE -D_FILE_OFFSET_BITS=64  -o mbin mbin.c
     
   Add -MSCRTL for windows platforms that use an MS C RTL which does not have sleep, but
   does have Sleep.
    
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

  1.0.3 14-NOV-2012, changed MSCLIB to MSCRTL for compatibility with other programs
  1.0.2 07-JUN-2011, added workaround for sleep() missing in MS C RTL on windows.
  1.0.1 04-AUG-2008, padbytes was passed to output uninitialized if the
           input was an exact multiple of the block size.
  1.0   19-OCT-2006, first release

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef MSCRTL
#include <windows.h>           /* for Sleep */
#else /* MSCRTL */
#include <unistd.h>           /* for sleep */
#endif /* MSCRTL */
#include <ctype.h>            /* for toupper, tolower */

#define EXVERSTRING "1.0.4  14-NOV-2012"
#define COPYSTRING  "2012 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"

#define DEFBLOCKSIZE 10240
#define DEFBLOCKS    1572864
#define DEFmbbufSIZE "15 Gb"
#define DEFmbbufNAME "mbbuf"
#define MAXMB        10      /* cannot imagine why more would be needed... */
#define DEFMB        2       /* currently only two buffers are implemented */
#define FIRSTPASS    1
#define NOTFIRSTPASS 0

/* prototypes */
int  lcl_strcasecmp(char *s1, char *s2);
void emit_help(void);
void insane(char *string);
FILE *next_buffer(char *lockname, char *filename, int first);
void  process_command_line_args(int argc,char **argv, int *bs);
void setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setstring(char **val,int *numarg,int argc,char **argv,char * label);

/* globals */

FILE *lcl_stdin;
FILE *lcl_stdout;
FILE *lcl_stderr;
int   mbcount;
char *mb_files[MAXMB];
char *mb_lfiles[MAXMB];
int   mb_size[MAXMB];
 
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
  (void) fprintf(lcl_stderr,"%s\n",string);
  (void) fprintf(lcl_stdout,"ABORT %s\n",string);
  (void) fflush(NULL);
  exit(EXIT_FAILURE);
}



void setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( lcl_stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%d",val) != 1){
        (void) fprintf(lcl_stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(*val <= 0){
        (void) fprintf(lcl_stderr,"Illegal zero or negative integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}

void setstring(char **val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( lcl_stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      *val = argv[*numarg];
}


void emit_help(void){
    (void) fprintf(lcl_stderr,"usage: mbin [options]\n");
    (void) fprintf(lcl_stderr,"\nfunction:\n");
    (void) fprintf(lcl_stderr,"   (mbin = Multiple Buffer INput)\n");
    (void) fprintf(lcl_stderr,"   Buffer a data stream through multiple files\n");
    (void) fprintf(lcl_stderr,"\noptions:\n");
    (void) fprintf(lcl_stderr,"   -in   FILE   read input from FILE,     default or - from stdin\n");
    (void) fprintf(lcl_stderr,"   -out  FILE   output commands to FILE,  default or - to stdout\n");
    (void) fprintf(lcl_stderr,"   -log  FILE   write messages to FILE,   default or - to stderr\n");
    (void) fprintf(lcl_stderr,"   -bs      N   blocksize in bytes, default %d\n",DEFBLOCKSIZE);
    (void) fprintf(lcl_stderr,"   -nb      N   number of buffer files, default %d, min 1, max %d\n",DEFMB,MAXMB);
    (void) fprintf(lcl_stderr,"   -fN   name   name of Nth buffer file, 1<=N<=10, default \"%s1\"\n",DEFmbbufNAME);
    (void) fprintf(lcl_stderr,"   -s   blocks  default size in blocks of all buffers, default %d  (%s)\n",DEFBLOCKS,DEFmbbufSIZE);
    (void) fprintf(lcl_stderr,"   -sN  blocks  size in blocks of Nth buffer, 1<=N<=10,  default %d  (%s)\n",DEFBLOCKS,DEFmbbufSIZE);
    (void) fprintf(lcl_stderr,"   -h           print this help message (also -help --h --help -? --?)\n");
    (void) fprintf(lcl_stderr,"   -i           emit version, copyright, license and contact information\n\n");
    (void) fprintf(lcl_stderr,"\nexample:\n");
    (void) fprintf(lcl_stderr," %% (ssh remotemachine 'dump -f - filesystem') | mbin | mbout > /dev/tapedrive\n");
    exit(EXIT_FAILURE);
}

void  process_command_line_args(int argc,char **argv, int *bs){
  
int numarg,i;
static char *buffer;
int mbdefsize=DEFBLOCKS;

  /* set all the default values */
  lcl_stdin=stdin;
  lcl_stdout=stdout;
  lcl_stderr=stderr;
  *bs=DEFBLOCKSIZE;
  mbcount=DEFMB;
  mbdefsize=DEFBLOCKS;

  for(i=0;i<MAXMB;i++){
    mb_size[i]=0;
    mb_files[i]=NULL;
  }

  for(numarg=1;numarg<argc;numarg++){
    if(lcl_strcasecmp(argv[numarg], "-in")==0){
      numarg++;
      if(lcl_strcasecmp(argv[numarg], "-")!=0){
        lcl_stdin=fopen(argv[numarg],"rb");
        if(lcl_stdin==NULL)insane("mbin: fatal error: could not open input file");
      }
    }
    else if(lcl_strcasecmp(argv[numarg], "-out")==0){
      numarg++;
      if(lcl_strcasecmp(argv[numarg], "-")!=0){
        lcl_stdout=fopen(argv[numarg],"w");
        if(lcl_stdout==NULL)insane("mbin: fatal error: could not open output file");
      }
    }
    else if(lcl_strcasecmp(argv[numarg], "-log")==0){
      numarg++;
      if(lcl_strcasecmp(argv[numarg], "-")!=0){
        lcl_stderr=fopen(argv[numarg],"w");
        if(lcl_stderr==NULL){ 
           lcl_stderr=stderr;  /* better set it back to the original value */
           insane("mbin: fatal error: could not open output file");
        }
      }
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-bs")){
      setiposnumeric(bs,&numarg,argc,argv,"-bs");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-nb")){
      setiposnumeric(&mbcount,&numarg,argc,argv,"-nb");
      if(mbcount<1 || mbcount >MAXMB)insane("mbin: fatal error: the number of rr files specified is out of range"); 
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s")){
      setiposnumeric(&mbdefsize,&numarg,argc,argv,"-s");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s1")){
      setiposnumeric(&mb_size[0],&numarg,argc,argv,"-s1");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s2")){
      setiposnumeric(&mb_size[1],&numarg,argc,argv,"-s2");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s3")){
      setiposnumeric(&mb_size[2],&numarg,argc,argv,"-s3");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s4")){
      setiposnumeric(&mb_size[3],&numarg,argc,argv,"-s4");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s5")){
      setiposnumeric(&mb_size[4],&numarg,argc,argv,"-s5");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s6")){
      setiposnumeric(&mb_size[5],&numarg,argc,argv,"-s6");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s7")){
      setiposnumeric(&mb_size[6],&numarg,argc,argv,"-s7");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s8")){
      setiposnumeric(&mb_size[7],&numarg,argc,argv,"-s8");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s9")){
      setiposnumeric(&mb_size[8],&numarg,argc,argv,"-s9");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-s10")){
      setiposnumeric(&mb_size[9],&numarg,argc,argv,"-s10");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f1")){
      setstring(&mb_files[0],&numarg,argc,argv,"-f1");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f2")){
      setstring(&mb_files[1],&numarg,argc,argv,"-f2");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f3")){
      setstring(&mb_files[2],&numarg,argc,argv,"-f3");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f4")){
      setstring(&mb_files[3],&numarg,argc,argv,"-f4");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f5")){
      setstring(&mb_files[4],&numarg,argc,argv,"-f5");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f6")){
      setstring(&mb_files[5],&numarg,argc,argv,"-f6");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f7")){
      setstring(&mb_files[6],&numarg,argc,argv,"-f7");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f8")){
      setstring(&mb_files[7],&numarg,argc,argv,"-f8");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f9")){
      setstring(&mb_files[8],&numarg,argc,argv,"-f9");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-f10")){
      setstring(&mb_files[9],&numarg,argc,argv,"-f10");
    }
    else if(lcl_strcasecmp(argv[numarg], "-i")==0){
      (void)fprintf(lcl_stderr,"Version:      %s\n",EXVERSTRING);
      (void)fprintf(lcl_stderr,"bugs to:      %s\n",BUGSTRING);
      (void)fprintf(lcl_stderr,"Copyright:    %s\n",COPYSTRING);
      (void)fprintf(lcl_stderr,"License:      %s\n",LICSTRING);
/* This works on Linux, must be modified for other OS's */
#ifdef _LARGE_FILE_SOURCE
      (void)fprintf(lcl_stderr,"Large Files:  Supported\n");
#else
      (void)fprintf(lcl_stderr,"Large Files:  Not Supported\n");
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
      (void) fprintf(lcl_stderr,"mbin:fatal error:no such parameter [%s]\n",argv[numarg]);
      emit_help();
    }
  }

  /* Set up the rr file names, the lock file names, and their sizes.  Unless specified
     above these take the default values.
  */

  for(i=0;i<mbcount;i++){
    if(mb_size[i]==0)mb_size[i]=mbdefsize;
    if(mb_files[i]==NULL || *(mb_files[i])=='\0'){  /* not defined or defined as an empty string */
      buffer=malloc(sizeof(char)*(strlen(DEFmbbufNAME)+2));
      if(buffer==NULL)insane("mbin: fatal error: could not allocate space for a buffer filename");
      mb_files[i]=buffer;
      (void) sprintf(mb_files[i],"%s%d",DEFmbbufNAME,i+1);
    }
    buffer=malloc(sizeof(char)*(strlen(mb_files[i])+6));
    if(buffer==NULL)insane("mbin: fatal error: could not allocate space for a lock filename");
    mb_lfiles[i]=buffer;
    (void) sprintf(mb_lfiles[i],"%s_lock",mb_files[i]);
  }
}


FILE *next_buffer(char *lockname, char *filename, int first){
FILE *flock;
FILE *fout;
  /* wait for lock file to go away, then create a new lock file */
  while(1){
    flock=fopen(lockname,"r");
    if(flock!=NULL){  /* lock file still around, mbout hasn't removed it yet */
      (void) fclose(flock);
      if(first==FIRSTPASS){
         insane("mbin: fatal error: first lock file already exists");
      }
      else {
#ifdef MSCRTL
        Sleep(1000);
#else /* MSCRTL */
        sleep(1);
#endif /* MSCRTL */
      }
    }
    else {
      flock=fopen(lockname,"w");
      if(flock==NULL)insane("mbin: fatal error: could not create a lock file");
      (void) fclose(flock);  /* close the lock file, nothing will be written to it*/
      break;
    }
  }
  /* open the next output buffer */
  fout=fopen(filename,"wb");  /* (re)create the output file */
  if(fout==NULL)insane("mbin: fatal error: could not open a buffer for write");
  return fout;
}     


int main(int argc, char *argv[]){
/* command line parameters*/
int   bs;

/* other variables */
unsigned char  *buffer;
int            ptr;
unsigned int   tblocks;
unsigned int   bblocks;
int            i,count,ok;
int            padbytes=0;
FILE *fout;

  process_command_line_args(argc,argv, &bs);
  
    
  buffer=malloc(sizeof(unsigned char)*bs);
  if(buffer==NULL)insane("mbin: fatal error: could not allocate space for read buffer");
  
  /* tell the downstream program (mbout or whatever) the block size, the number of
  buffer files, the buffer files, and the buffer lock files */
  (void) fprintf(lcl_stdout,"%d\n",bs);     /* tell mbout the block size */
  (void) fprintf(lcl_stdout,"%d\n",mbcount);  /* tell mbout the number of files and lock files */
  for(i=0;i<mbcount;i++){
     (void) fprintf(lcl_stdout,"%s\n",mb_files[i]); 
  }
  for(i=0;i<mbcount;i++){
     (void) fprintf(lcl_stdout,"%s\n",mb_lfiles[i]); 
  }
  (void) fflush(lcl_stdout);

  /* the main loop */
  tblocks=0;
  bblocks=0;
  ptr=0;
  ok=1;
  fout=next_buffer(mb_lfiles[ptr],mb_files[ptr],FIRSTPASS);  /* set lock file and open output file */

  while(ok){
    /* output buffer is full? */
    if(bblocks >= mb_size[ptr]){
      if(EOF==fclose(fout))insane("mbin: fatal error: could not close a buffer");
      (void) fprintf(lcl_stdout,"%d %d\n",bblocks,ptr+1); /* tell mbout it's ready */
      (void) fflush(NULL);
      ptr++;
      if(ptr>=mbcount)ptr=0;
      bblocks=0;
      fout=next_buffer(mb_lfiles[ptr],mb_files[ptr],NOTFIRSTPASS);  /* set up the next buffer */
    }

    /* output buffer is ready to go, read one block */

    count=fread(buffer,1,bs,lcl_stdin);
    if(count!=bs){
      if(feof(lcl_stdin)){
        /* it's ok, it's just the end of the data.  Tell mbout after loop exit */
        if(count>0){ /* pad out the rest of the buffer to a full block */
          (void) fprintf(lcl_stderr,"mbin:  warning: partial buffer on last block\n");
          for(i=count;i<bs;i++){buffer[i]=0;}
          padbytes=bs-count;
        }
        ok=0;
      }
      else {
        insane("mbin: fatal error: input error while reading data");
      }
    }

    /* have read in one block, whole or partial (then padded) */

    if(count){
      if(fwrite(buffer,bs,1,fout)){
        bblocks++;
        tblocks++;
      }
      else {
        /* This is a problem.  The output write to a buffer failed.  
        Probably ran out of disk space - no recovery is possible. 
        The next call exits and may leave buffer and lock files
        around if mbout cannot clean up the mess. */
        insane("mbin: fatal error: output error while writing to a buffer");
      };
    }
  }
  (void) fclose(fout);
  if(bblocks>0)(void) fprintf(lcl_stdout,"%d %d\n",bblocks,ptr+1);
  (void) fprintf(lcl_stdout,"DONE %d %d\n",tblocks,padbytes);
  
  exit(EXIT_SUCCESS);
}
