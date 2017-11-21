/* mbout.c
Program:   mbout.c
Version:   1.0.3
Date:      12-NOV-2012
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2012 David Mathog and California Institute of Technology (Caltech)
   
Description:  
   mbout == Multiple Buffer OUTput.
   With the companion program mbin buffers a data stream
   through a series of buffers, such that input/output
   runs at full speed until it stalls waiting for data or
   waiting for a buffer to open up.
   
   mbout merges the input stream back together from the
   2 buffer files.  These are typically
   located on separate spindles.  It takes all of the
   merge commands from lcl_stdin, which normally is
   stdin but can be changed to a file.
   
   The first set of commands are:
     blocksize  (an integer, in bytes)
     files      (an integer, currently mbin emits 2, some other program could use more)
     file1      (text, full path to the file)
     file2
     file1lock   (text lockfile associated with file1)
     file2lock
   These are followd by a series of commands:
     blocks whichfile   (two unsigned integers, number of blocks & which file to read it from)
     
   On receiving this type of command it checks for a lock file,
   which is "filename1_lock".  If that doesn't exist it aborts.
   It then reads the specified number of blocks of blocksize
   from the file and sends them to the output in blocksize chunks.
   When it's done it deletes the lock file and tries to read
   another one of these commands.
   
   The stream is terminated with
      DONE  totalblocks  padbytes
   or
      ABORT message
      
   In either case it attempts to clean up by deleting all of the
   files and all of the lock files.
   
   WARNING!  This really needs large file support to be of any use.  For gcc
   compile like this:
   
     gcc -Wall -Wextra -pedantic -D_LARGE_FILE_SOURCE -D_FILE_OFFSET_BITS=64 -o mbout mbout.c
   
    
License terms:   GNU General Public License 2.
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

  1.0.3 12-NOV-2012
        Fixed compiler warnings recent gcc, variables set but not used.
  1.0.2 07-JUN-2011, changed -in/-out to rb/wb respectively, so that
       this will work on nonUnix systems.  stdin/stdout will probably not
       work on such systems, as those streams will probably not be binary.
  1.0.1 01-AUG-2008, changed output from fwrite() to write().  There
       were issues with the former when writing through a pipe to
       a linux st driver connected tape drive, if the tape drive was
       set to a large fixed block size.
  1.0   19-OCT-2006, first release

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>           /* for unlink */
#include <ctype.h>            /* for toupper, tolower */

#define EXVERSTRING "1.0.3  12-NOV-2012"
#define COPYSTRING  "2012 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"

#define MAXMB 10               /* maximum number of buffer files, should never need more than 2*/
#define BOOM   1
#define NOBOOM 0
#define MAXBUF 1024           /* longest command through stdin */

/* prototypes */
 int  buffer_write (int fd, const unsigned char  *buffer, size_t remaining);
void  clean_up(int explode, char *message);
void  emit_help(void);
void  insane(char *string);
 int  lcl_strcasecmp(char *s1, char *s2);
FILE *next_buffer(char *lockname, char *filename);
void  process_command_line_args(int argc,char **argv, int *vt, int *vr, int *ve);
void  setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void  setstring(char **val,int *numarg,int argc,char **argv,char * label);

/* globals */

FILE          *lcl_stdin;
FILE          *lcl_stdout;
FILE          *lcl_stderr;
int            mbcount;
char         **mb_files=NULL;
char         **mb_lfiles=NULL;

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
    (void) fprintf(lcl_stderr,"usage: mbout [options]\n");
    (void) fprintf(lcl_stderr,"\nfunction:\n");
    (void) fprintf(lcl_stderr,"   (mbout = Multiple Buffer OUTput)\n");
    (void) fprintf(lcl_stderr,"   Reassemble a data stream which has been buffered\n");
    (void) fprintf(lcl_stderr,"   through multiple files\n");
    (void) fprintf(lcl_stderr,"\noptions:\n");
    (void) fprintf(lcl_stderr,"   -in   FILE   read commands from FILE,   default or - from stdin\n");
    (void) fprintf(lcl_stderr,"   -out  FILE   write data stream to FILE, default or - to stdout\n");
    (void) fprintf(lcl_stderr,"   -log  FILE   write messages to FILE,    default or - to stderr\n");
    (void) fprintf(lcl_stderr,"   -ve          echo every command to stderr or the log file\n");
    (void) fprintf(lcl_stderr,"   -vt          writes a status message when done even if no error\n");
    (void) fprintf(lcl_stderr,"   -vr      N   write a status message every N blocks \n");
    (void) fprintf(lcl_stderr,"   -h           print this help message (also -help --h --help -? --?)\n");
    (void) fprintf(lcl_stderr,"   -i           emit version, copyright, license and contact information\n\n");
    (void) fprintf(lcl_stderr,"\nexample:\n");
    (void) fprintf(lcl_stderr," %% (ssh remotemachine 'dump -f - filesystem') | mbin | mbout > /dev/tapedrive\n");
    exit(EXIT_FAILURE);
}

void  process_command_line_args(int argc,char **argv, int *vt, int *vr, int *ve){
  
int numarg;


  /* set all the default values */
  lcl_stdin=stdin;
  lcl_stdout=stdout;
  lcl_stderr=stderr;
  *vt=0;
  *vr=0;
  *ve=0;

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
        lcl_stdout=fopen(argv[numarg],"wb");
        if(lcl_stdout==NULL)insane("mbout: fatal error: could not open output file");
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
    else if(0==lcl_strcasecmp(argv[numarg], "-vt")){
      *vt=1;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-ve")){
      *ve=1;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-vr")){
      setiposnumeric(vr,&numarg,argc,argv,"-vr");
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
      (void) fprintf(lcl_stderr,"mbout:fatal error:no such parameter [%s]\n",argv[numarg]);
      emit_help();
    }
  }  
}


/* Try to clean up on a terrible error, but don't warn further if it
doesn't work. If explode is set it exits at this point, otherwise it returns. */
void clean_up(int explode, char *message){
int i;

  for(i=0;i<mbcount;i++){
    (void) unlink(mb_files[i]);
    (void) unlink(mb_lfiles[i]);
  }
  if(explode==BOOM)insane(message);
}

/* Send the whole buffer or die trying.  Returns 1 if success, 0 if failure.  Assumes syncrhonous IO  */
int  buffer_write (int fd, const unsigned char  *buffer, size_t remaining){
  ssize_t wrote;
  int status = 1;

  while(remaining) {
     wrote=write(fd, buffer, remaining);
     if(wrote > 0){
        buffer    += wrote;
        remaining -= wrote;
     }
     else if(wrote < 0){
        status=0;
        break;
     }
     else { /* This should never happen!  If it does, do the same thing dd does */
        status=0;
	break;
     }
  }

  return status;
}


int main(int argc, char *argv[]){
/* command line parameters*/
int            vt,vr,ve;

/* other variables */
char           *cbuffer; /* should be big enough for any reasonable name! */
unsigned char  *buffer;
int            ptr=0;
unsigned int   tblocks;
int            bblocks;
int            vblocks;
int            i,count;
unsigned int   bs;
FILE          *fin;
int            fd;

  cbuffer=malloc(sizeof(char) * MAXBUF);
  if(cbuffer==NULL)insane("mbout: fatal error: could not allocate space for command buffer");

  process_command_line_args(argc,argv, &vt, &vr, &ve);
  
  /* read and process the configuration information as described above */
 
  /* blocksize */
  if(NULL==fgets(cbuffer,MAXBUF,lcl_stdin) || strlen(cbuffer)==0){  /* This is a blocking read */
      insane("mbout: fatal error: could not read next command from the input stream");
  }
  if(ve)(void) fprintf(lcl_stderr,"mbout: echo command: %s",cbuffer); /* \n on end of cbuffer */
  count=sscanf(cbuffer,"%u\n",&bs);
  if(count!=1)insane("mbout: fatal error: first command was not blocksize");

  /* number of buffer files */
  if(NULL==fgets(cbuffer,MAXBUF,lcl_stdin) || strlen(cbuffer)==0){  /* This is a blocking read */
      insane("mbout: fatal error: could not read next command from the input stream");
  }
  if(ve)(void) fprintf(lcl_stderr,"mbout: echo command: %s",cbuffer); /* \n on end of cbuffer */
  count=sscanf(cbuffer,"%d\n",&mbcount);
  if(count!=1 || mbcount>MAXMB || mbcount<1)insane("mbout: fatal error: second command was not number of buffers or number was invalid");
  mb_files  = malloc(sizeof(char *) * mbcount);
  mb_lfiles = malloc(sizeof(char *) * mbcount);
  if(mb_files==NULL || mb_lfiles==NULL)insane("mbout: fatal error: could not allocate arrays for file or lock file names");

  /* all the buffer files */
  for(i=0;i<mbcount;i++){
    if(NULL==fgets(cbuffer,MAXBUF,lcl_stdin) || strlen(cbuffer)==0){  /* This is a blocking read */
      insane("mbout: fatal error: could not read a file name");
    }
    if(ve)(void) fprintf(lcl_stderr,"mbout: echo command: %s",cbuffer); /* \n on end of cbuffer */
    count=strlen(cbuffer);
    mb_files[i]=malloc(sizeof(char) * count);
    if(mb_files[i]==NULL)insane("mbout: fatal error: could not allocate space for a file name");
    cbuffer[--count]='\0'; /* remove the line terminator */
    (void) strcpy(mb_files[i],cbuffer);
  }

  /* all the buffer lock files */
  for(i=0;i<mbcount;i++){
    if(NULL==fgets(cbuffer,MAXBUF,lcl_stdin) || strlen(cbuffer)==0){  /* This is a blocking read */
      insane("mbout: fatal error: could not read a lock file name");
    }
    if(ve)(void) fprintf(lcl_stderr,"mbout: echo command: %s",cbuffer); /* \n on end of cbuffer */
    count=strlen(cbuffer);
    mb_lfiles[i]=malloc(sizeof(char) * count);
    if(mb_lfiles[i]==NULL)insane("mbout: fatal error: could not allocate space for a lock file name");
    cbuffer[--count]='\0'; /* remove the line terminator */
    (void) strcpy(mb_lfiles[i],cbuffer);
  }
 
    
  buffer=malloc(sizeof(unsigned char)*bs);
  if(buffer==NULL)insane("mbout: fatal error: could not allocate space for read buffer");

  /* the main loop */
  tblocks=0;
  bblocks=0;
  vblocks=0;
  
  fd=fileno(lcl_stdout);  /* convert from stream to file descriptor */

  while(1){
    if(NULL==fgets(cbuffer,MAXBUF,lcl_stdin) || strlen(cbuffer)==0){  /* This is a blocking read */
      clean_up(0,"mbout: fatal error: could not read next command from the input stream");
    }
    if(ve)(void) fprintf(lcl_stderr,"mbout: echo command: %s",cbuffer); 
    if(0==strncmp(cbuffer,"ABORT",5))clean_up(BOOM,&cbuffer[5]);
    if(0==strncmp(cbuffer,"DONE",4)){
       clean_up(NOBOOM,&cbuffer[4]);  /* echo the rest of the messge to stderr or the log file */
       break;
    }
    count=sscanf(cbuffer,"%d %d\n",&bblocks,&ptr);  
    if(count!=2){
      (void) fprintf(lcl_stderr,"mbout: fatal error: command is bad: %s\n",cbuffer);
      clean_up(BOOM,"mbout: fatal error: bad parameter count on a command");
    }
    ptr--;  /* external is in range 1->N, internally it is 0->N-1 */
    if(bblocks <=0 || ptr <0 || ptr >= mbcount)clean_up(BOOM,"mbout: fatal error: bad parameter values on a command");

    /* verify that the lock file is present */
    fin=fopen(mb_lfiles[ptr],"rb");
    if(fin==NULL){
      (void) fprintf(lcl_stderr,"mbout: fatal error: could not find lock file: >%s<\n",mb_lfiles[ptr]);
      clean_up(BOOM,"mbout: fatal error: lock file is missing");
    }
    (void)fclose(fin);
    
    /* transfer the data from the file, when done, delete the lockfile */
    fin=fopen(mb_files[ptr],"rb");
    if(fin==NULL)clean_up(BOOM,"mbout: fatal error: could not open a specified file");
    for (i=0;i<bblocks;i++){
       count=fread(buffer,bs,1,fin);
       if(count!=1)clean_up(BOOM,"mbout: fatal error: error while reading a file");
       /* Version 1.0.0 was

              count=fwrite(buffer,bs,1,lcl_stdout);
              if(count!=1)clean_up(BOOM,"mbout: fatal error: error while writing to the output");

           This had some issues writing to a tape drive after
              mt -f /dev/nst0 setblk 262144
          Even though blocksize here (bs) was also 262144, this could result in a message:
          kernel: st0: Write not multiple of tape block size. 
          According to Kai Makisara this was because the guts of fwrite() did not necessarily
            retain the block size for the actual writes it eventually made.
       */
       if(!buffer_write(fd,buffer,bs))clean_up(BOOM,"mbout: fatal error: error while writing to the output");
       vblocks++;
       tblocks++;
       if(vblocks==vr){
         vblocks=0;
         (void) fprintf(lcl_stderr,"mbout: message: copied block %d\n",tblocks);
       }
    }
    if(EOF==fclose(fin))clean_up(BOOM,"mbout: fatal error: error while closing a file");
    if(0!=unlink(mb_lfiles[ptr]))clean_up(BOOM,"mbout: fatal error: deleting a lock file");
  }
  if(vr)(void) fprintf(lcl_stderr,"\n");
  if(vt)(void) fprintf(lcl_stderr,"rout: message: copied %d blocks of %d bytes per block\n",tblocks,bs); 
  
  exit(EXIT_SUCCESS);
}
