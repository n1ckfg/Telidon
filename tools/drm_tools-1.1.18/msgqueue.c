/* 
Program:   msgqueue.c
Version:   1.0.0
Date:      18-DEC-2002
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2002 David Mathog and California Institute of Technology (Caltech)

Description:

     Command line program to create/send/receive messages
     from message queues.
	
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

  1.0.1 31-DEC-2002, added targeted mode, changed name of msgbuf structure def
  1.0.0 18-DEC-2002, first release

Miscellaneous:
    This should be relatively portable on Unix systems.  
    Compiles and builds on RedHat 7.3 and Solaris 8 with
    
    gcc -Wall -ansi -pedantic -o msgqueue msgqueue.c
    
    Seeing how many bytes are queued is not portable. 
    Linux:    add -DHAS__MSG_CBYTES
    Solaris:  add -DHASMSG_CBYTES

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* definitions */
#define EXVERSTRING "1.0.2 23-OCT-2006"
#define COPYSTRING  "2002,2006 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"
#define MSGBUFMAX 32768
enum msgmodes {MSGUNDEF,TEST,CREATE,GET,SEND,GUIDED,REMOVE,SET,MAXMESSAGE};
enum matchmodes {MATCHUNDEF,MATCH,NEXT,EXCEPT};
struct lcl_msgbuf {
     long mtype;             /* message type, must be > 0 */
     char mtext[MSGBUFMAX];  /* message data */
};

/* function prototypes */
void emit_help(void);
void guidedmessage(struct lcl_msgbuf *thismsgbuf, int *key);
void insane(char *string);
int  lcl_strcasecmp(char *s1, char *s2);
char *messagefromstdin(void);
void process_command_line_args(int argc,char **argv, 
  int *key, enum msgmodes *mmode, int *lock, int *flags,
  int *mtype, int *gettype, char **message);
void sethexnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setoctalnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setstring(char **val,int *numarg,int argc,char **argv,char * label);


/* functions */
void setoctalnumeric(int *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%o",(unsigned int*) val) != 1){
        (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(*val < 0){
        (void) fprintf(stderr,"Illegal  negative integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}
void sethexnumeric(int *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%x",(unsigned int*) val) != 1){
        (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
      if(*val < 0){
        (void) fprintf(stderr,"Illegal  negative integer argument/parameter [%s %s] \n",label,argv[*numarg]);
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
        (void) fprintf(stderr,"Illegal zero or negative integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}

void emit_help(void){
(void) fprintf(stderr,"msgqueue [flags]:\n\n");
(void) fprintf(stderr,"   -c,-create	create the queue\n");
(void) fprintf(stderr,"   -r,-remove	remove the queue\n");
(void) fprintf(stderr,"   -s,-send 	send a message to the queue from stdin\n");
(void) fprintf(stderr,"     -t,-text MSG   send MSG instead of stdin\n");
(void) fprintf(stderr,"     -d,-guided     \\n terminates lines, formatted: KEY TYPE MSG. \n");
(void) fprintf(stderr,"                    Locks waiting for input.  Exits on EOF.\n");
(void) fprintf(stderr,"   -g,-get  	get a message from the queue and write it to stdout\n");
(void) fprintf(stderr,"     -match	next message which matches the type\n");
(void) fprintf(stderr,"     -except	next message which does not match the type\n");
(void) fprintf(stderr,"     -next	next message without regard to type, Default\n");
(void) fprintf(stderr,"   -modify  N	modify the queue.  Maximum bytes=N, mask as specified with -m (superuser only)\n");
(void) fprintf(stderr,"   -n,-info 	if the queue exists write information about it to stdout\n");
(void) fprintf(stderr,"   -y,-type  N	set the message type for queue operations, N>0, default = 1\n");
(void) fprintf(stderr,"   -m,-mask  660	specify the access mask, octal, for -c or -z modes\n");
(void) fprintf(stderr,"   -mm,-maxm 	find the platform specific largest message - specify an empty queue\n");
(void) fprintf(stderr,"   -k[x],-key[x] KEYVAL\n");
(void) fprintf(stderr,"                 Indicate the queue to act on by ([hexa]decimal) KEYVAL\n");
(void) fprintf(stderr,"   -l,-lock		lock waiting for get or send operation. default - do not lock\n");
(void) fprintf(stderr,"   -h            print this help message (also -help --h --help -? --?)\n");
(void) fprintf(stderr,"   -i            emit version, copyright, license and contact information\n\n");
(void) fprintf(stderr,"limits:          This program's maximum message length is %d characters\n",MSGBUFMAX);
exit(EXIT_FAILURE);
}

void insane(char *string){
 (void) fprintf(stderr,"%s\n",string);
 exit(EXIT_FAILURE);
}


/* read up to MSGBUFMAX characters from stdin */
char *messagefromstdin(void){
char *buffer;
char cin;
int  count;
   buffer=malloc(sizeof(char) * MSGBUFMAX);
   if(buffer==NULL)insane("msgqueue:fatal error: could not make space for message from stdin");

   count=0;
   while(1){
     cin=fgetc(stdin);
     if(cin==EOF){
       if(count==0)insane("msgqueue:fatal error: no input was read from stdin");
       buffer[count]='\0';  /* terminate the string */
       /* nip off the terminal \n, if one is present */
       if(count-- >= 0 && buffer[count]=='\n')buffer[count]='\0';
       return buffer;
     }
     buffer[count]=cin;
     count++;
     if(count >= MSGBUFMAX)insane("msgqueue:fatal error: too much data from stdin");
   }
}
/* read up to MSGBUFMAX characters from stdin */

void guidedmessage(struct lcl_msgbuf *thismsgbuf, int *key){
char *newline;
char *token;
char buffer[MSGBUFMAX];
int  mtype,parsed;
    /* this is called over and over, so assume that an empty input is the intended EOF, not an error*/
    if(fgets(buffer,MSGBUFMAX,stdin) == NULL)exit(EXIT_SUCCESS);
    newline=strstr(buffer,"\n");
    if(newline == NULL){   /* string truncated, this is fatal in this mode */
      insane("msgqueue: fatal error: input line was truncated");
    }
    *newline='\0';      /* replace the \n with a terminator */
    token=strtok(buffer," ");
    if(token == NULL)insane("msgqueue: fatal error: -guided input did not contain a queue key");
    parsed=sscanf(token,"%d",key);
    if(parsed != 1 || *key <= 0 )insane("msgqueue: fatal error: -guided input contained an invalid queue key");
    token=strtok(NULL," ");
    if(token == NULL)insane("msgqueue: fatal error: -guided input did not contain a message type");
    parsed=sscanf(token,"%d",&mtype);
    if(parsed != 1 || mtype <= 0 )insane("msgqueue: fatal error: -guided input contained an invalid message type");
    token=strtok(NULL,"");  /* returns rest of string, if any */
    (void) strcpy(thismsgbuf->mtext,token);
    if(token == NULL)insane("msgqueue: fatal error: -guided input did not contain a message type");
    thismsgbuf->mtype=mtype;
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

void process_command_line_args(int argc,char **argv, 
  int *key, enum msgmodes *mmode, int *lock, int *flags,
  int *mtype, int *gettype, char **message){

 int numarg=0;
 enum matchmodes typematch;
 int setsize;
 
 *flags=0666;    /* octal 666 */
 *key=-1;        /* may not be a valid message queue ID! */
 *mmode=MSGUNDEF;
 *message=NULL;
 *lock=0;
 *mtype=1;
 typematch=MATCHUNDEF;
 *gettype=0;
 

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
    else if( (lcl_strcasecmp(argv[numarg], "-k")==0) ||
             (lcl_strcasecmp(argv[numarg], "-key")==0)){
      setiposnumeric(key,&numarg,argc,argv,"-k,-key");
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-kx")==0) ||
             (lcl_strcasecmp(argv[numarg], "-keyx")==0)){
      sethexnumeric(key,&numarg,argc,argv,"-kx,-keyx");
      continue;
    }
     else if( (lcl_strcasecmp(argv[numarg], "-y")==0) ||
              (lcl_strcasecmp(argv[numarg], "-type")==0)){
      setiposnumeric(mtype,&numarg,argc,argv,"-y,-type");
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-s")==0) ||
              (lcl_strcasecmp(argv[numarg], "-send")==0)){
      if(*mmode != MSGUNDEF)insane("msgqueue: fatal error: conflicting modes specified");
      *mmode=SEND;
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-d")==0) ||
              (lcl_strcasecmp(argv[numarg], "-guided")==0)){
      if(*mmode != SEND)insane("msgqueue: fatal error: -d,-guided must follow -send");
      *mmode=GUIDED;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-modify")==0){
      if(*mmode != MSGUNDEF)insane("msgqueue: fatal error: conflicting modes specified");
      *mmode=SET;
      setiposnumeric(&setsize,&numarg,argc,argv,"-modify");
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-m")==0) ||
             (lcl_strcasecmp(argv[numarg], "-mask")==0)){
      setoctalnumeric(flags,&numarg,argc,argv,"-m,-mask");
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-t")==0) ||
             (lcl_strcasecmp(argv[numarg], "-text")==0)){
      if(*mmode != SEND)insane("msgqueue: fatal error: -t,-text must follow -send");
      setstring(message,&numarg,argc,argv,"-t,-text");
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-g")==0) ||
             (lcl_strcasecmp(argv[numarg], "-get")==0)){
      if(*mmode != MSGUNDEF)insane("msgqueue: fatal error: conflicting modes specified");
      *mmode=GET;
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-c")==0) || 
             (lcl_strcasecmp(argv[numarg], "-create")==0)){
      if(*mmode != MSGUNDEF)insane("msgqueue: fatal error: conflicting modes specified");
      *mmode=CREATE;
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-l")==0) ||
             (lcl_strcasecmp(argv[numarg], "-lock")==0)){
      *lock=1;
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-mm")==0) ||
             (lcl_strcasecmp(argv[numarg], "-maxm")==0)){
      *mmode=MAXMESSAGE;
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-n")==0) ||
             (lcl_strcasecmp(argv[numarg], "-info")==0)){
      if(*mmode != MSGUNDEF)insane("msgqueue: fatal error: conflicting modes specified");
      *mmode=TEST;
      continue;
    }
    else if( (lcl_strcasecmp(argv[numarg], "-r")==0) ||
             (lcl_strcasecmp(argv[numarg], "-remove")==0)){
      if(*mmode != MSGUNDEF)insane("msgqueue: fatal error: conflicting modes specified");
      *mmode=REMOVE;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-match")==0){
      if(typematch!=MATCHUNDEF)insane("msgqueue: fatal error: multiple get modes specified");
      typematch=MATCH;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-except")==0){
      if(typematch!=MATCHUNDEF)insane("msgqueue: fatal error: multiple get modes specified");
      typematch=EXCEPT;
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-next")==0){
      if(typematch!=MATCHUNDEF)insane("msgqueue: fatal error: multiple get modes specified");
      typematch=NEXT;
      continue;
    }
    else
      (void) fprintf(stderr,"Unknown command line argument: %s\n",argv[numarg]);
      exit(EXIT_FAILURE);
      continue;
    }
    
    /* Sanity checking */
    
    if( *key < 0)insane("msgqueue: fatal error: specify the message queue with -k, -kx, -key, or -keyx");
    if(*mmode==GET){
      switch (typematch){
        case MATCHUNDEF:
	case NEXT:
	  *gettype=0;
	  break;
	case MATCH:
	  *gettype=*mtype;
	  break;
	case EXCEPT:
	  *gettype=-*mtype;
	  break;
      }
    }
    if(*mmode==SET){  /* smuggle it out even if type was also set */
      *mtype=setsize;
    }
    if( (*mmode==SEND) && (*message==NULL))*message=messagefromstdin();
}

int main(int argc, char *argv[]){

int   key,lock,flags,mtype,gettype;
int   sendlen;
char  *message;
enum  msgmodes mmode;
int   msgqid;
int   result,blockflag;
struct msqid_ds msgstatbuf;


struct lcl_msgbuf thismsgbuf;
        
        process_command_line_args(argc,argv,&key,&mmode,&lock,&flags,&mtype,&gettype,&message);
	if(lock){
	  blockflag=0;
	}
	else {
	  blockflag=IPC_NOWAIT;
	}
        switch (mmode){
	  case SET:
	  case TEST:
	    msgqid = msgget((key_t)key,0);
	    if(msgqid == -1)exit(EXIT_FAILURE);
            result = msgctl(msgqid, IPC_STAT, &msgstatbuf);
	    if(result == -1)exit(EXIT_FAILURE);
	    if(mmode==SET){ /* modify only the qbytes and mode fields */
	      msgstatbuf.msg_qbytes=mtype;
	      msgstatbuf.msg_perm.mode=flags;
              result = msgctl(msgqid, IPC_SET, &msgstatbuf);
	      if(result == -1)exit(EXIT_FAILURE);
	      break;
	    }
	    /* These fields exist on both Linux and Solaris */
	    (void) fprintf(stdout,"last send:        %s",ctime(&msgstatbuf.msg_stime));
	    (void) fprintf(stdout,"last recv:        %s",ctime(&msgstatbuf.msg_rtime));
	    (void) fprintf(stdout,"last change:      %s",ctime(&msgstatbuf.msg_ctime));
	    flags = 0777 & msgstatbuf.msg_perm.mode;
	    (void) fprintf(stdout,"mask:             %o\n",flags);
	    (void) fprintf(stdout,"messages:         %d\n",(int)msgstatbuf.msg_qnum);
#ifdef HAS__MSG_CBYTES  /* linux and ??? */
	    (void) fprintf(stdout,"bytes in queue:   %d\n",(int)msgstatbuf.__msg_cbytes);
#endif
#ifdef HASMSG_CBYTES   /* solaris and ??? */
	    (void) fprintf(stdout,"bytes in queue:   %d\n",(int)msgstatbuf.msg_cbytes);
#endif
	    (void) fprintf(stdout,"max bytes(total): %d\n",(int)msgstatbuf.msg_qbytes);
	    (void) fprintf(stdout,"pid of last send: %d\n",(int)msgstatbuf.msg_lspid);
	    (void) fprintf(stdout,"pid of last recv: %d\n",(int)msgstatbuf.msg_lrpid);
	    break;
	  case CREATE:
	    msgqid = msgget((key_t)key,flags | IPC_CREAT);
	    if(msgqid == -1)exit(EXIT_FAILURE);
	    break;
	  case REMOVE:
	    msgqid = msgget((key_t)key,0);
	    if(msgqid == -1)exit(EXIT_FAILURE);
            result = msgctl(msgqid, IPC_RMID, &msgstatbuf);
	    if(result == -1)exit(EXIT_FAILURE);
	    break;
	  case GUIDED:
	    while(1){
	      guidedmessage(&thismsgbuf,&key); /* exits if there is a problem or EOF*/
	      msgqid = msgget((key_t)key,flags);
	      if(msgqid == -1)exit(EXIT_FAILURE);
	      sendlen=strlen(thismsgbuf.mtext);
 	      result = msgsnd(msgqid, (void *) &thismsgbuf, sendlen , blockflag);
	      if(result==-1)exit(EXIT_FAILURE);
	    }

	    break;
	  case SEND:
	    msgqid = msgget((key_t)key,flags);
	    if(msgqid == -1)exit(EXIT_FAILURE);
	    sendlen=strlen(message);
	    if(sendlen>MSGBUFMAX-1)insane("msgqueue: fatal error: input message too long for queue");
	    (void) strcpy(thismsgbuf.mtext,message);
	    thismsgbuf.mtype=mtype;
            result = msgsnd(msgqid, (void *) &thismsgbuf, sendlen , blockflag);
	    if(result==-1){
	       exit(EXIT_FAILURE);
	    }
	    break;
	  case MAXMESSAGE:
	    /* Apparently there is no standard way to do this with header files.
	       Find value experimentally by writing ever larger buffers
	       until it fails.  Do it all with NOWAIT or it might lock.
	    */
	    msgqid = msgget((key_t)key,flags);
	    if(msgqid == -1)exit(EXIT_FAILURE);
	    thismsgbuf.mtype=mtype;
	    for(sendlen=4;sendlen<=MSGBUFMAX;sendlen += 4){
              result = msgsnd(msgqid, (void *) &thismsgbuf, sendlen , IPC_NOWAIT);
	      if(result==-1)(void) fprintf(stdout,"%d\n",sendlen-4);
              result = msgrcv(msgqid, (void *) &thismsgbuf, MSGBUFMAX, 0, IPC_NOWAIT);
	      if(result==-1)exit(EXIT_FAILURE);
	    }
	    break;
	  case GET:
	    msgqid = msgget((key_t)key,flags);
	    if(msgqid == -1)exit(EXIT_FAILURE);
	    thismsgbuf.mtype=mtype;
            result = msgrcv(msgqid, (void *) &thismsgbuf, MSGBUFMAX, gettype, blockflag);
	    if(result==-1)exit(EXIT_FAILURE);
	    (void) fprintf(stdout,"%s\n",thismsgbuf.mtext);
	    break;
	  default:
	    insane("msgqueue: fatal error: incorrect parsing of command line arguments");
	}
        exit(EXIT_SUCCESS);
}                                                                       

