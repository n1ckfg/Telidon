/*
Program:   accudate.c
Version:   1.0.9
Date:      14-NOV-2012
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2012 David Mathog and California Institute of Technology (Caltech)

Description:

     "date" replacment which emits date and time down to milliseconds
     to stdout in format:

        2002-12-01:13:28:36.716
	
    or
    
        2002-12-01 13:28:36.716
 
	
Changes:

  1.0.9 14-NOV-2012, changed MSCLIB to MSCRTL for compatibility with other programs
  1.0.8 07-JUN-2011. Added -DMSCLIB to handle long long ssscanf's for mingw
     and other windows environments that still use old MS compilers.
  1.0.7 23-OCT-2006. Changed license to GPL 2
  1.0.6 11-JUL-2005. Removed unistd.h
  1.0.5 01-NOV-2004. Added offset in seconds for time emitted.  This
     lets the user emit previous times (negative seconds) or future
     times (positive seconds).
  1.0.4 20-JAN-2004, Bug in deltatime.  Was using time() for current
     seconds and gettimeofday() for initial.  This could (and did)
     often result in a random 1 second slew.  Use gettimeofday
     for all seconds/useconds now.
  1.0.3 15-JAN-2003, Added optional spaced format
  1.0.2 12-DEC-2002, Oops, removed a colon by accident going to 1.0.1
  1.0.1 10-DEC-2002, Added delta time capability.  -t0 switch
     emits current time to stdout as seconds microseconds. -df 
     switch followed by seconds microseconds emits delta time
     in ddd:hh:mm:ss.mmm and -dt emits it as seconds.mmm.  Note
     that seconds is converted to long long and then emitted,
     and microseconds to an int.  On 32 bit systems and above
     it should usually be possible to convert back and forth
     using this method.  long long isn't in older ANSI C though.
  1.0.0 06-DEC-2002, first release

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
    
    gcc -Wall -std=c99 -pedantic -o accudate accudate.c
    
    You may ignore the warnings about "long long" and "ll" not being
    supported - so long as _your_ compiler supports them.
    
    On mingw and any other windows environment that still uses old
    MS C rtl add -DMSCRTL so that sscanf will work for long long.  There
    will be a couple of warnings (ISO C does not support I64) when it
    compiles, but it will work.
    
    Since the program itself takes time to run the time point
    indicated by milliseconds is fairly arbitrary.  On our Sparc
    IIi machine a series of accudate commands emit times .01
    seconds apart, and on our Athlon 2200 RedHat machine the
    times are .002 seconds apart.  On future machines the run
    time should drop below 1 millisecond, at which point accudate
    will be accurate to the last decimal shown.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
 
/* definitions */
#define EXVERSTRING "1.0.9 14-JUN-2012"
#define COPYSTRING  "2012 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"
enum timemodes {NORMAL,SNORMAL,TZERO,DELTA,DELTASECONDS,TOUCH};

/* function prototypes */
void emit_help(void);
void insane(char *string);
int  lcl_strcasecmp(char *s1, char *s2);
void process_command_line_args(int argc,char **argv, enum timemodes *tmode,
   struct timeval *start_time, struct timeval *off_time);
void setzerotime(struct timeval *val,int *numarg,int argc,char **argv,char * label); 
void offsetzerotime(struct timeval *val,int *numarg,int argc,char **argv,char * label); 


/* functions */
void setzerotime(struct timeval *val,int *numarg,int argc,char **argv,char * label){
long long external_seconds;
int       external_microseconds;
      (*numarg)++;
      if( ( *numarg  >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing seconds\n",label);
        exit(EXIT_FAILURE);
      }
#ifdef MSCRTL
      if(sscanf(argv[*numarg],"%I64d",&external_seconds) != 1){
#else
      if(sscanf(argv[*numarg],"%lld",&external_seconds) != 1){
#endif
        (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      (*numarg)++;
      if( ( *numarg  >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing microseconds\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%d",&external_microseconds) != 1){
        (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(external_seconds < 0){
        (void) fprintf(stderr,"Illegal value for seconds [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(external_microseconds < 0){
        (void) fprintf(stderr,"Illegal value for microseconds [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      val->tv_sec  = external_seconds;
      val->tv_usec = external_microseconds;
}

void offsetzerotime(struct timeval *val,int *numarg,int argc,char **argv,char * label){
long long external_seconds;
      (*numarg)++;
      if( ( *numarg  >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing seconds\n",label);
        exit(EXIT_FAILURE);
      }
#ifdef MSCRTL
      if(sscanf(argv[*numarg],"%I64d",&external_seconds) != 1){
#else
      if(sscanf(argv[*numarg],"%lld",&external_seconds) != 1){
#endif
        (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      val->tv_sec  = external_seconds;
}

void emit_help(void){
(void) fprintf(stderr,"accudate command summary:\n\n");
(void) fprintf(stderr,"   [no args]       write time to stdout as YYYY-MM-DD:hh:mm:ss.lll\n");
(void) fprintf(stderr,"   -s              write time to stdout as YYYY-MM-DD hh:mm:ss.lll\n");
(void) fprintf(stderr,"   -touch          write time to stdout as YYYYMMDDhhmm.ss\n");
(void) fprintf(stderr,"   -t0             write time to stdout as \"seconds microseconds\" \n");
(void) fprintf(stderr,"   -toff seconds   add \"seconds\" (signed) to the current time before emitting.\n");
(void) fprintf(stderr,"                   hour=3600, day=86400, week=604800, 1year (365 days)=1536000\n");
(void) fprintf(stderr,"                   WARNING:  consider leap years, daylight savings, time zones, and so forth!\n");
(void) fprintf(stderr,"   -df seconds microseconds\n");
(void) fprintf(stderr,"                   write elapsed time as \"DDDD-hh:mm.ss.lll\" to stdout\n");
(void) fprintf(stderr,"   -ds seconds microseconds\n");
(void) fprintf(stderr,"                   write elapsed time as \"ssssss.lll\" to stdout\n");
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

void process_command_line_args(int argc,char **argv, enum timemodes *tmode,
   struct timeval *start_time, struct timeval *off_time){

 int numarg=0;

  off_time->tv_sec  = 0;
  off_time->tv_usec = 0;
  *tmode=NORMAL;

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
    else if(lcl_strcasecmp(argv[numarg], "-s")==0){
      if(*tmode != NORMAL)insane("accudate: fatal error: bad command line flags");
      *tmode=SNORMAL;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-touch")==0){
      if(*tmode != NORMAL)insane("accudate: fatal error: bad command line flags");
      *tmode=TOUCH;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-s")==0){
      if(*tmode != NORMAL)insane("accudate: fatal error: bad command line flags");
      *tmode=SNORMAL;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-ds")==0){
      if(*tmode != NORMAL)insane("accudate: fatal error: bad command line flags");
      setzerotime(start_time,&numarg,argc,argv,"-ds");
      *tmode=DELTASECONDS;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-df")==0){
      if(*tmode != NORMAL)insane("accudate: fatal error: bad command line flags");
      setzerotime(start_time,&numarg,argc,argv,"-df");
      *tmode=DELTA;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-toff")==0){
      if(*tmode != NORMAL && *tmode != TZERO && *tmode != TOUCH)insane("accudate: fatal error: bad command line flags");
      offsetzerotime(off_time,&numarg,argc,argv,"-toff");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-t0")==0){
      if(*tmode != NORMAL)insane("accudate: fatal error: bad command line flags");
      *tmode=TZERO;
      continue;
    }
    else
      (void) fprintf(stderr,"Unknown command line argument: %s\n",argv[numarg]);
      exit(EXIT_FAILURE);
      continue;
    }
}

int main(int argc, char *argv[]){

        struct  tm  *time_structure;
        time_t time_val;
	struct timeval start_time;
	struct timeval off_time;
	struct timeval thetv;
        struct timeval *tp=&thetv;
	int millisec;
	enum timemodes tmode;
	long long external_seconds;
	time_t    delta_s;
	int       external_microseconds,delta_us;
	int       days,hours,minutes,seconds;
        
        process_command_line_args(argc,argv, &tmode, &start_time, &off_time);
	
	
        (void) time(&time_val);
	time_val        += off_time.tv_sec;  /* if toff was used, offset the apparent time */
        time_structure   = localtime(&time_val);
        tp->tv_sec       = 0;
	tp->tv_usec      = 0;
        if (gettimeofday(tp,(struct timezone *)NULL) != 0) {
                (void) fprintf(stderr,"Error calling gettimeofday\n");
                exit(EXIT_FAILURE);
        }
	millisec = tp->tv_usec/1000;
	
	switch (tmode){
	  case NORMAL:
           (void) fprintf(stdout,"%.4d-%.2d-%.2d:%.2d:%.2d:%.2d.%.3d\n",
               1900+time_structure->tm_year,
               1+time_structure->tm_mon,
               time_structure->tm_mday,
               time_structure->tm_hour,
               time_structure->tm_min,
               time_structure->tm_sec,
               millisec);
	    break;
	  case SNORMAL:
           (void) fprintf(stdout,"%.4d-%.2d-%.2d %.2d:%.2d:%.2d.%.3d\n",
               1900+time_structure->tm_year,
               1+time_structure->tm_mon,
               time_structure->tm_mday,
               time_structure->tm_hour,
               time_structure->tm_min,
               time_structure->tm_sec,
               millisec);
	    break;
	  case TOUCH:
           (void) fprintf(stdout,"%.4d%.2d%.2d%.2d%.2d.%.2d\n",
               1900+time_structure->tm_year,
               1+time_structure->tm_mon,
               time_structure->tm_mday,
               time_structure->tm_hour,
               time_structure->tm_min,
               time_structure->tm_sec);
	    break;
	  case TZERO:
	   external_seconds = tp->tv_sec + off_time.tv_sec;   /* implicit conversion, usually safe */
	   external_microseconds= tp->tv_usec;                /* implicit conversion, usually safe */
           (void) fprintf(stdout,"%lld %8d\n",external_seconds,external_microseconds);
	    break;
	  case DELTA:
            if(start_time.tv_usec < tp->tv_usec){
              delta_us = tp->tv_usec - start_time.tv_usec;
            }
            else {
              delta_us = 1000000 + tp->tv_usec - start_time.tv_usec;
              tp->tv_sec--;
            }
	    millisec=delta_us/1000;
	    delta_s= tp->tv_sec - start_time.tv_sec;
	    external_seconds=delta_s;
	    days=external_seconds/(24*60*60);
	    if(days>0)external_seconds -= days*24*60*60;
	    hours=external_seconds/(60*60);
	    if(hours>0)external_seconds -= hours*60*60;
	    minutes=external_seconds/60;
	    if(minutes>0)external_seconds -= minutes*60;
	    seconds=external_seconds;
            (void) fprintf(stdout,"%.4d-%.2d:%.2d:%.2d.%.3d\n",days,hours,minutes,seconds,millisec);
	    break;
	  case DELTASECONDS:
            if(start_time.tv_usec < tp->tv_usec){
              delta_us = tp->tv_usec - start_time.tv_usec;
            }
            else {
              delta_us = 1000000 + tp->tv_usec - start_time.tv_usec;
              tp->tv_sec--;
            }
	    millisec=delta_us/1000;
	    delta_s= tp->tv_sec - start_time.tv_sec;
	    external_seconds=delta_s;
           (void) fprintf(stdout,"%7.7lld.%.3d\n",external_seconds,millisec);
	    break;
	}
        exit(EXIT_SUCCESS);
}                                                                       

