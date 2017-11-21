/*
Program:   binreplace.c
Version:   1.0.3
Date:      14-NOV-2012
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2010 David Mathog and California Institute of Technology (Caltech)

Description:

    Reads a binary stream from stdin and performs one of a few types of
    operations on it, either detecting strings or detecting and replacing.

     % gcc -Wall -pedantic -std=c99  -o binreplace binreplace.c
     
    This code will probably compile with any modern C compiler.  On windows with
    mingw and others using old MS C RTL add -DMSCRTL.  There will be a couple
    of compiler warnings about C99 not supporting I64, but it will work.

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

  1.0.3    14-NOV-2012, changed MSCLIB to MSCRTL for compatibility with
           other programs
  1.0.2    07-JUN-2011, added -DMSCLIB work around for build environments
           on windows that use old MS CRTL that doesn't do %lld.
           Added isblan() for Solaris.
  1.0.1    01-SEP-2010, fixed signed/unsigned problem in hex output.
           fixed very old bug in range method (emitted "too low" for both errors).
           Added \repeat\ syntax for all formats.  So that "\123\FF" in hex mode
           is 123 consecutive hex 'FF' bytes.  In string mode \123\x is 123 x's. 
           Now \ must be escaped in strings.
	   Also added -maxpattern, since we cannot easily determine length with repeats in place.
  1.0.0    30-AUG-2010, first release

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>            /* for toupper, tolower */

#ifdef SOL8                   /* missing C99 function  used here*/
#define isblank(x)  ( (x)==' ' || (x)== '\t' ? 1 : 0 );
#endif

#define EXVERSTRING "1.0.3 14-NOV-2012"
#define COPYSTRING  "2012 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"

#define LOGPOSFINDS   1
#define LOGSIZECHANGE 2
#define LOGSHOWFINDSH 4
#define LOGSHOWFINDST 8
#define LOGSHOWPATS  16
#define LOGMAX       31

#define NOCASE      1
#define BIT8        0
#define BIT16       2
#define HEXDEC      4
#define DECIMAL     6
#define FORMATMAX   7

#define IS_FSTRING  0
#define ISALNUM     2
#define ISALPHA     4
#define ISBLANK     6
#define ISCNTRL     8
#define ISDIGIT    10
#define ISGRAPH    12
#define ISPRINT    14
#define ISLOWER    16
#define ISUPPER    18
#define ISEITHER   20
#define ISPUNCT    22
#define ISSPACE    24
#define ISXDIGIT   26
#define ISNOT       1
#define ISWILDCARD 28
#define MASKMAX     ISWILDCARD
#define DENOT    0xFE  /* used to erase ISNOT, if present */


/* structs */
typedef struct is_hex_string HS_NEXUS;
struct is_hex_string{
  unsigned char *buffer;
  int           len;
};

/* function prototypes */
void emit_help(void);
int  findrepeat(char **string);
void insane(char *string);
void hexdump_line(unsigned char *string, int count);
int  lcl_strcasecmp(char *s1, char *s2);
int  lcl_strncasecmp(char *s1, char *s2,int len);
int  lcl_strcmprange(char *s1, char *s2, int start, int end, int usecase);
int  lstrcasecmp(char *s1, int len1, char *s2, int len2);
int  lstrtol(char *string,int length, long *ival);
void process_command_line_args(int argc,char **argv);
void setirangenumeric(int *val,int *numarg, int lower, int upper, int argc,char **argv,char * label);
void setstring(char **val,int *numarg,int argc,char **argv,char * label);
void setllrangenumeric(long long *val, int *numarg, long long lower,
         long long upper, int argc, char **argv,char * label);
void show_hexpats(HS_NEXUS *hfstring, HS_NEXUS *hmask, HS_NEXUS *hrstring);
HS_NEXUS *string_format(char *string, int format);

/* globals (values set in process_command_line_args)  */
char     *fstring;
char     *fmask;
char     *rstring;
int       verbose;
int       fformat;
int       rformat;
int       mformat;
int       maxpattern;
long long first;
long long length;

/* functions */

void insane(char *string){
  (void) fprintf(stderr,"%s\n",string);
  exit(EXIT_FAILURE);
}

void emit_hexamples(void){
  (void) fprintf(stdout,"Typical usage:\n");
  (void) fprintf(stdout,"  cat source_binary | binreplace [args] > destination_binary\n");
  (void) fprintf(stdout,"\n");
  (void) fprintf(stdout,"\n");
  (void) fprintf(stdout,"echo 'F123 abc' | binreplace -find '23 ' -verbose 15\n");
  (void) fprintf(stdout,"2 [ 32 33 20] [23 ]\n");
  (void) fprintf(stdout,"  (Find an exactly matching string, show position, hex, and ascii.)\n\n");
  (void) fprintf(stdout,"echo 'F123 abc' | binreplace -find '23 ' -verbose 0 -replace '09'\n");
  (void) fprintf(stdout,"F109abc\n");
  (void) fprintf(stdout,"  (Find and replace a string in the data stream.)\n\n");
  (void) fprintf(stdout,"echo 'F123 abc' | binreplace -find 'xxx' -verbose 15 -mask  '10 24 16'\n");
  (void) fprintf(stdout,"3 [ 33 20 61] [3 a]\n");
  (void) fprintf(stdout,"  (Find a property pattern: number, white space, lower case.)\n\n");
  (void) fprintf(stdout,"echo 'F123 abc' | binreplace -find 'xx' -verbose 15 -mask  '10 10'\n");
  (void) fprintf(stdout,"1 [ 31 32] [12]\n");
  (void) fprintf(stdout,"  (Only the first of overlapping matches is emitted or replaced.)\n\n");
  (void) fprintf(stdout,"echo 'F123 abc' | binreplace -find 'x' -verbose 15 -mask  '11'\n");
  (void) fprintf(stdout,"0 [ 46] [F]\n");
  (void) fprintf(stdout,"4 [ 20] [ ]\n");
  (void) fprintf(stdout,"5 [ 61] [a]\n");
  (void) fprintf(stdout,"6 [ 62] [b]\n");
  (void) fprintf(stdout,"7 [ 63] [c]\n");
  (void) fprintf(stdout,"8 [  A] [~]\n");
  (void) fprintf(stdout,"  (Find by NOT digits.)\n\n");
  (void) fprintf(stdout,"echo 'F123 abc' | binreplace -find 'xxxAB' -verbose 15 -mask  '28 28 28 0 0' -fformat 1\n");
  (void) fprintf(stdout,"2 [ 32 33 20 61 62] [23 ab]\n");
  (void) fprintf(stdout,"  (Retrieve data next to a known case insensitive tag.)\n\n");
  (void) fprintf(stdout,"echo 'F123 abc' |\\\n binreplace -find 'Fxxxxxxx' -verbose 0 -mask  '0 10 10 10 24 16 16 16' -replace 'G789 new'\n");
  (void) fprintf(stdout,"G789 new\n");
  (void) fprintf(stdout,"  (Replace a complex pattern.)\n\n");
  (void) fprintf(stdout,"(echo 'F123 abc'; echo 'second') |\\\n  binreplace -find '0000000A' -fformat 4  -verbose 15 -replace '7071720A' -mask '28 28 28 0'\n");
  (void) fprintf(stdout,"5 [ 61 62 63 0A] [abc~] \n");
  (void) fprintf(stdout,"F123 pqr                \n");
  (void) fprintf(stdout,"12 [ 6F 6E 64 0A] [ond~]\n");
  (void) fprintf(stdout,"secpqr                  \n");
  (void) fprintf(stdout,"  (Use hexadecimal find and replace strings combined with mask pattern.)\n\n");
  (void) fprintf(stdout,"echo 'F123 abc' |\\ \n");
  (void) fprintf(stdout,"   binreplace -find 'xx' -mask '28,28' -verbose 15 -replace 'XY'  -first 2 -length 4\n");
  (void) fprintf(stdout,"2 [ 32 33] [23]\n");
  (void) fprintf(stdout,"4 [ 20 61] [ a]\n");
  (void) fprintf(stdout,"F1XYXYbc       \n");
  (void) fprintf(stdout,"  (Replace in a restricted area, here positions 2 through 5.)\n\n");
  (void) fprintf(stdout,"echo 'F123 abc' |  binreplace -find '\\6\\xc' -mask '\\6\\28 0' -verbose 31 \n");
  (void) fprintf(stdout,"FIND PATTERN:  78 78 78 78 78 78 33\n");
  (void) fprintf(stdout,"MASK PATTERN:  1C 1C 1C 1C 1C 1C 00\n");
  (void) fprintf(stdout,"1 [ 31 32 33 20 61 62 63] [123 abc]\n");
  (void) fprintf(stdout,"  (Use repeat counts in binary sequence specifications.)\n\n");
  exit(EXIT_FAILURE);
}
 
 


void emit_help(void){
  (void) fprintf(stdout,"binreplace: search or search/replace a binary data stream.\n");
  (void) fprintf(stdout,"   Reads from stdin, writes to stdout.\n");
  (void) fprintf(stdout,"   Exit status:  SUCCESS if any matches are found, FAILURE otherwise.\n");
  (void) fprintf(stdout,"   Usage:  cat binary_source | binreplace [options] >binary_destination\n\n");
  (void) fprintf(stdout,"Command line options are:\n");
  (void) fprintf(stdout," -find    FIND\n");
  (void) fprintf(stdout,"            Locate binary sequence FIND in the data stream.\n");
  (void) fprintf(stdout," -replace REPLACE\n");
  (void) fprintf(stdout,"            Replace each FIND match with binary sequence REPLACE\n");
  (void) fprintf(stdout," -mask    MASK\n");
  (void) fprintf(stdout,"            Optional processing for each position in FIND.\n");
  (void) fprintf(stdout,"            The number of bytes in the binary sequences FIND\n");
  (void) fprintf(stdout,"            and MASK must be the same. [Default - no MASK]\n");
  (void) fprintf(stdout,"             0  Is the corresponding character in FIND\n");
  (void) fprintf(stdout,"             2  Is alphanumeric\n");
  (void) fprintf(stdout,"             4  Is alphabetic\n");
  (void) fprintf(stdout,"             6  Is blank\n");
  (void) fprintf(stdout,"             8  Is control\n");
  (void) fprintf(stdout,"            10  Is digit\n");
  (void) fprintf(stdout,"            12  Is printable, but not space\n");
  (void) fprintf(stdout,"            14  Is printable, includes space\n");
  (void) fprintf(stdout,"            16  Is lower case\n");
  (void) fprintf(stdout,"            18  Is upper case\n");
  (void) fprintf(stdout,"            20  Is either case\n");
  (void) fprintf(stdout,"            22  Is punctuation\n");
  (void) fprintf(stdout,"            24  Is white space\n");
  (void) fprintf(stdout,"            26  Is hexadecimal digit\n");
  (void) fprintf(stdout,"            28  Is any value (wildcard)\n");
  (void) fprintf(stdout,"             1  NOT, modifies all of the above, example: 7 = NOT blank\n");
  (void) fprintf(stdout," -verbose VALUE\n");
  (void) fprintf(stdout,"            Control messages sent to stderr during processing.\n");
  (void) fprintf(stdout,"            [ Bit mask, if none are set only fatal error messages are emitted.]\n"); 
  (void) fprintf(stdout,"            1  Emit FIND positions [Default]\n");
  (void) fprintf(stdout,"            2  Warn if file size might change [Default]\n");
  (void) fprintf(stdout,"            4  Emit FIND matches (as hex)\n");
  (void) fprintf(stdout,"            8  Emit FIND matches (as text)\n");
  (void) fprintf(stdout,"           16  Emit expanded binary sequences for FIND, REPLACE, and MASK\n");
  (void) fprintf(stdout," -first  FIRST\n");
  (void) fprintf(stdout,"            First byte in the data stream that -find may match.\n");
  (void) fprintf(stdout,"            Numbered from 0.  [Default 0].\n");
  (void) fprintf(stdout," -length LENGTH\n");
  (void) fprintf(stdout,"            Last byte in the data stream, counting from FIRST,\n");
  (void) fprintf(stdout,"            that -find may match.  [Default %lld]\n",LLONG_MAX);
  (void) fprintf(stdout," -fformat  FFORMAT\n");
  (void) fprintf(stdout,"            Format of FIND string:\n");
  (void) fprintf(stdout,"            0   8 bit text: '09Af'  -> bytes'30 39 41 66' [Default]\n");
  (void) fprintf(stdout,"            1   8 bit text, case INSENSITIVE\n");
  (void) fprintf(stdout,"            2  16 bit text: '09Af'  -> bytes'30 00 39 00 41 00 66 00'\n");
  (void) fprintf(stdout,"            3  16 bit text, case INSENSITIVE\n");
  (void) fprintf(stdout,"            4  Hexadecimal: '09Af'  -> bytes'09 AF'\n");
  (void) fprintf(stdout,"            5  Hexadecimal, case INSENSITIVE\n");
  (void) fprintf(stdout,"            6  Decimal:     '9,175' -> bytes'09 AF'\n");
  (void) fprintf(stdout,"            7  Decimal, case INSENSITIVE\n");
  (void) fprintf(stdout,"               [Commas or spaces delimit decimal sequences.]\n");
  (void) fprintf(stdout,"               [\\Decimal Repeat\\value repeats the next value Repeat times.]\n");
  (void) fprintf(stdout,"               [\\\\ is a single escaped backslash in text input formats.]\n");
  (void) fprintf(stdout," -rformat  RFORMAT\n");
  (void) fprintf(stdout,"            Format of REPLACE string, same list as for FFORMAT, \n");
  (void) fprintf(stdout,"            but the case sensitivity bit is ignored. [Default, same as FFORMAT]\n");
  (void) fprintf(stdout," -mformat  MFORMAT\n");
  (void) fprintf(stdout,"            Format of MASK string, like RFORMAT. [Default 6]\n");
  (void) fprintf(stdout," -maxpattern  N\n");
  (void) fprintf(stdout,"            Size to allocate for each binary sequence buffer. [Default 1024]\n");
  (void) fprintf(stdout," -h         print this help message (also -help --h --help -? --?)\n");
  (void) fprintf(stdout," -hexamples print examples\n");
  (void) fprintf(stdout," -i         emit version, copyright, license and contact information\n");
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

void setstring(char **val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      *val = argv[*numarg];
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
void setllrangenumeric(long long *val, int *numarg, long long lower, long long upper, int argc,char **argv,char * label){
  (*numarg)++;
  if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
    (void) fprintf( stderr, "%s: missing argument\n",label);
    exit(EXIT_FAILURE);
  }
#ifdef MSCRTL
  if(sscanf(argv[*numarg],"%I64d",val) != 1){
#else /* MSCRTL */
  if(sscanf(argv[*numarg],"%lld",val) != 1){
#endif /* MSCRTL */
    (void) fprintf(stderr,"Bad long long integer argument/parameter [%s %s] \n",label,argv[*numarg]);
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

/* parse \ usage. 
  '\12\'X  returns 12 and the pointer set on X
  '\\'     returns 1 and the pointer set on the second back slash
  '\(not a decimal number)[\ or end of string]` returns 0 (an error) 
*/
int findrepeat(char **string){
char *lstring;
char *rstring=NULL;
int status;
int repeat;
  if(!string)insane("binreplace: fatal programming error: findrepeat sees null argument");
  lstring = *string;
  if(*lstring != '\\')insane("binreplace: fatal programming error: findrepeat sees non backslash first character");
  if(lstring[1] == '\\'){
    (*string)++;
    repeat=1;
  }
  else {
    lstring++;
    rstring = strchr(lstring,'\\');
    if(rstring==NULL)return(0); /* no trailing backslash */
    *rstring='\0';
    rstring++;
    if(!*rstring)return(0);     /* repeat goes to the end of the line */
    *string=rstring;
    status=sscanf(lstring,"%d",&repeat);
    if(status != 1)return(0);
    if(!rstring)return(0);
  }
  return(repeat);
}
 
/* Created the formatted string structure, fill it, and return it.  The structure can be empty if the
string was replace, but should not be if it was find! */
HS_NEXUS *string_format(char *string, int format){
int            blen=0;
HS_NEXUS      *fs=NULL;
unsigned char *buf;
char           fromhex[3];
int            status;
unsigned int   temp;
char          *token;
int            repeat;

   fs=malloc(sizeof(HS_NEXUS));
   if(!fs)insane("binreplace: fatal error: could not allocate memory for formatted string structure");

   fs->buffer=malloc(maxpattern);
   if(!fs->buffer)insane("binreplace: fatal error: could not allocate memory for formatted string buffer");
   buf = fs->buffer;
   
   if(     format == HEXDEC  || format == HEXDEC + NOCASE){
     fromhex[2]='\0';
     while(*string){
       if(*string=='\\'){
         repeat = findrepeat(&string); 
         if(!repeat)insane("binreplace: fatal error: repeat syntax error, must be: \\Decimal repeat number\\HEX");
       }
       else {repeat = 1; }
       for(;repeat;repeat--){
         if(blen > maxpattern - 1)insane("binreplace: fatal error: expanded binary  is larger than -maxpattern");
         fromhex[0]=string[0];
         fromhex[1]=string[1];
         status=sscanf(fromhex,"%2X",&temp);
         if(status!=1)insane("binreplace: fatal error: hexadecimal input string contains non-Hex characters");
         *buf++=temp;  /* This will always fit */
         blen++;
       }
       string+=2;
     }
   }
  else if(format == DECIMAL || format == DECIMAL + NOCASE){
    token=strtok(string,", ");
    blen=0;  /* need to see how long this string actually is */
    while(token){
      if(*token=='\\'){  
        repeat = findrepeat(&token);
        if(!repeat)insane("binreplace: fatal error: syntax error, repeat must be: \\Decimal repeat number\\Decimal number");
      }
      else { repeat = 1; }
      status=sscanf(token,"%ud",&temp);
      if(status!=1)insane("binreplace: fatal error: decimal input string contains nondecimal characters");
      if(temp<0 || temp>255)insane("binreplace: fatal error: decimal input value out of range (should be 0<->255)");
      for(;repeat;repeat--){
        if(blen > maxpattern - 1)insane("binreplace: fatal error: expanded binary  is larger than -maxpattern");
        *buf++=temp;  /* This will always fit */
        blen++;
      }
      token=strtok(NULL,", ");
    }
  } 
  else if(format == BIT16   || format == BIT16 + NOCASE){
     while(*string){
       if(*string=='\\'){
         repeat = findrepeat(&string);
         if(!repeat)insane("binreplace: fatal error: syntax error, repeat must be: \\Decimal repeat number\\text");
       }
       else { repeat = 1; }
       for(;repeat;repeat--){
         if(blen > maxpattern - 2)insane("binreplace: fatal error: expanded binary  is larger than -maxpattern");
         *buf++ = *string;
         *buf++ = 0;
         blen+=2;
       }
       string++;
     }
  }
  else {    /* BIT8 */
    while(*string){
       if(*string=='\\'){  
         repeat = findrepeat(&string);
         if(!repeat)insane("binreplace: fatal error: syntax error, repeat must be: \\Decimal repeat number\\text");
       }
       else { repeat = 1; }
       for(;repeat;repeat--){
         *buf++ = *string;
         blen++;
       }
       string++;
    }
  }
  fs->len=blen;
  return(fs);
}

void hexdump_line(unsigned char *string, int count){
int i;
  if(count == 0){
    fprintf(stderr,"EMPTY\n");
  }
  else {
    for (i=0;i<count;i++){
      fprintf(stderr," %2.2X",*string++);
    }
    fprintf(stderr," \n");
  }
}

void  process_command_line_args(int argc,char **argv){
    
int  numarg=0;

  /* initialize the global variables */
  fstring    = NULL;
  rstring    = NULL;
  fmask      = NULL;   
  verbose    = LOGPOSFINDS | LOGSIZECHANGE; 
  fformat    = 0;      
  rformat    = -1;     
  mformat    = 6;     
  first      = 0;
  maxpattern = 1024;
  length     = LLONG_MAX;

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
    else if(lcl_strcasecmp(argv[numarg], "-hexamples")==0){
      emit_hexamples();
    }
    else if(lcl_strcasecmp(argv[numarg], "-find")==0){
      setstring(&fstring,&numarg,argc,argv,"-find");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-mask")==0){
      setstring(&fmask,&numarg,argc,argv,"-mask");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-replace")==0){
      setstring(&rstring,&numarg,argc,argv,"-replace");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-verbose")==0){
      setirangenumeric(&verbose,&numarg,0,LOGMAX,argc,argv,"-verbose");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-maxpattern")==0){
      setirangenumeric(&maxpattern,&numarg,0,INT_MAX,argc,argv,"-maxpattern");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-fformat")==0){
      setirangenumeric(&fformat,&numarg,0,FORMATMAX,argc,argv,"-fformat");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-mformat")==0){
      setirangenumeric(&mformat,&numarg,0,FORMATMAX,argc,argv,"-mformat");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-rformat")==0){
      setirangenumeric(&rformat,&numarg,0,FORMATMAX,argc,argv,"-rformat");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-first")==0){
      setllrangenumeric(&first,&numarg,0,LLONG_MAX,argc,argv,"-first");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-length")==0){
      setllrangenumeric(&length,&numarg,0,LLONG_MAX,argc,argv,"-length");
      continue;
    }
    else {
       (void) fprintf(stderr,"binreplace: fatal error: on command line [%s] is not recognized.  Use the -h flag to list options.\n",argv[numarg]);
       exit(EXIT_FAILURE);
    }
  }
  
  /* sanity checking and defaults */
  if(!fstring)insane("binreplace: fatal error: no -find value specified");
  if(rformat==-1)rformat=fformat;
}

void show_hexpats(HS_NEXUS *hfstring, HS_NEXUS *hmask, HS_NEXUS *hrstring){
  if(hfstring){ 
    (void) fprintf(stderr,"FIND PATTERN: ");
    hexdump_line(hfstring->buffer,hfstring->len);
  }
  if(hmask){ 
    (void) fprintf(stderr,"MASK PATTERN: ");
    hexdump_line(hmask->buffer,hmask->len);
  }
  if(hrstring){ 
    (void) fprintf(stderr,"REPLACE PATTERN: ");
    hexdump_line(hrstring->buffer,hrstring->len);
  }
} 

int main(int argc, char *argv[]){
int            c,c2;
HS_NEXUS      *hmask=NULL;
HS_NEXUS      *hfstring=NULL;
HS_NEXUS      *hrstring=NULL;
unsigned char *uc=NULL;
unsigned char *lc=NULL;
unsigned char *find=NULL;
unsigned char *lfind=NULL;
unsigned char *ufind=NULL;
unsigned char *ringbuffer=NULL;
int            ringlen=0;
int            cached=0;
long long      count=0;
long long      found=0;
int            status;
int            start=0;
int            restart;
int            i;
int            result;
int            delayed_exit=0;

  process_command_line_args(argc,argv);
  hfstring=string_format(fstring,fformat);
  if(fformat & NOCASE){
    uc = malloc(hfstring->len);
    lc = malloc(hfstring->len);
    if(!uc || !lc)insane("binreplace:fatal error: unable to allocate replace buffers");
    for(i=0; i<hfstring->len; i++){
      uc[i] = toupper(hfstring->buffer[i]);
      lc[i] = tolower(hfstring->buffer[i]);
    }
  }
  
  if(fmask){
    hmask=string_format(fmask,mformat);
    if(hmask->len != hfstring->len){
      insane("binreplace:fatal error: FMASK and FSTRING are different lengths");
    }
  }
  
  if(rstring){
   hrstring=string_format(rstring,rformat);
   if((hrstring->len != hfstring->len) && (verbose & LOGSIZECHANGE)){
     fprintf(stderr,"binreplace: warning: edit will alter file size\n");
   }
  }
  
  if(verbose & LOGSHOWPATS){ show_hexpats(hfstring,hmask,hrstring); }
  
  ringlen = hfstring->len;
  ringbuffer=malloc(ringlen);
  if(!ringbuffer)insane("binreplace:fatal error: unable to allocate the search buffer");
  
  while(1){
    
    c = getc(stdin);
    count++;

    if(c==EOF){
      if(feof(stdin)){
        if(cached == ringlen){ /* have to test before leaving the read loop */
          delayed_exit=1;
        }
        else {  /* no test possible, exit the read loop immediately */
          break;
        }
      }
      else {
        insane("binreplace: fatal read error");
      }
    }
    
    /* one character is waiting to go into the ring buffer */    
    if(cached == ringlen){  /* ring buffer is full, OK to test */
      if(!hmask){
        if(fformat & NOCASE){
          for(restart=start, lfind=lc, ufind=uc, i=0; i<ringlen; i++){
            if( (ringbuffer[restart] != *lfind) && 
                (ringbuffer[restart] != *ufind)    )break;
            restart++;
            lfind++; 
            ufind++;
            if(restart==ringlen)restart=0;
          }
        }
        else {
          for(restart=start,find=hfstring->buffer,i=0;i<ringlen;i++){
            if(ringbuffer[restart++] != *find++)break; 
            if(restart==ringlen)restart=0;
          }
        }
      }
      else {
        for(restart=start, find=hfstring->buffer, i=0; i<ringlen; find++,i++){
          c2=ringbuffer[restart++];
          if(restart==ringlen)restart=0;
          switch(hmask->buffer[i] & DENOT) {
            case IS_FSTRING:
              if(fformat & NOCASE){
                if(c2 == lc[i] || c2 == uc[i]){ result = 1; }
                else {                          result = 0; }
              }
              else {
                if(c2 == *find){                result = 1; }
                else {                          result = 0; }
              }
              break;
            case ISALNUM: 
              result=isalnum(c2);
              break;
            case ISALPHA: 
              result=isalpha(c2);
              break;
            case ISBLANK: 
              result=isblank(c2);
              break;
            case ISCNTRL: 
              result=iscntrl(c2);
              break;
            case ISDIGIT: 
              result=isdigit(c2);
              break;
            case ISGRAPH: 
              result=isgraph(c2);
              break;
            case ISPRINT: 
              result=isprint(c2);
              break;
            case ISLOWER: 
              result=islower(c2);
              break;
            case ISUPPER: 
              result=isupper(c2);
              break;
            case ISEITHER: 
              result=islower(c2) || isupper(c2);
              break;
            case ISPUNCT: 
              result=ispunct(c2);
              break;
            case ISSPACE: 
              result=isspace(c2);
              break;
            case ISXDIGIT: 
              result=isxdigit(c2);
              break;
            case ISWILDCARD:
              result=1;
              break;
            default:
              insane("binreplace: fatal error: -mask contains a value which is out of range");
          }
          if(hmask->buffer[i] & ISNOT){ 
            result = (result ? 0 : 1);
          }
          if(!result)break;
        }
      }
      if( i==ringlen && 
          (count  >= first + ringlen + 1 && count -first - 1 <= length)
        ){
        /* Found one AND -find fits entirely within the allowed search region */
        if(verbose & LOGPOSFINDS){
          (void)fprintf(stderr,"%lld",count - ringlen - 1);
        }
        if(verbose & LOGSHOWFINDSH){
          (void)fprintf(stderr," [");
          for(restart=start, i=0; i<ringlen; i++){
            (void)fprintf(stderr," %2.2X",ringbuffer[restart]);
            restart++;
            if(restart==ringlen)restart=0;
          }
          (void)fprintf(stderr,"]");
        }
        if(verbose & LOGSHOWFINDST){
          (void)fprintf(stderr," [");
          for(restart=start, i=0; i<ringlen; i++){
            if(isprint(ringbuffer[restart])){
              (void)fprintf(stderr,"%c",ringbuffer[restart]);
            }
            else {
              (void)fprintf(stderr,"~");
            }
            restart++;
            if(restart==ringlen)restart=0;
          }
          (void)fprintf(stderr,"]");
        }
        if(verbose & (LOGPOSFINDS | LOGSHOWFINDSH | LOGSHOWFINDST))(void)fprintf(stderr,"\n");
        found++;
        if(hrstring && hrstring->len){
          status=fwrite(hrstring->buffer,1,hrstring->len,stdout);
          if(status != hrstring->len)insane("binreplace: fatal write error");
        }
        /* empty the ring buffer and store the pending character */
        ringbuffer[0]=c;
        start=0;
        cached=1;
      }
      else {
        /* Mismatch or outside allowed region.
           If replacing emit the character at start, 
           store the waiting character.
           The number cached is unchanged  */ 
        if(hrstring){
          if(EOF==putc(ringbuffer[start],stdout))insane("binreplace: fatal write error");
        }
        ringbuffer[start++]=c;
        if(start == ringlen)start=0;
      }
    }
    else { /* fill the ringbuffer, this always starts from start = 0 */
      ringbuffer[cached++]=c;
    }
    if(delayed_exit){
      cached--;
      break;
    }
  }
  
  /* if replacing there may be some left in the ring buffer, emit it */
  
  if(hrstring){
    for(;cached;cached--){
      if(EOF==putc(ringbuffer[start++],stdout))insane("binreplace: fatal write error");
      if(start==ringlen)start=0;
    }
  }

  /* free all allocated memory.  Mostly this is here to help find memory leaks */
  if(hrstring){
    free(hrstring->buffer);
    free(hrstring);
  }
  if(hfstring){
    free(hfstring->buffer);
    free(hfstring);
  }
  if(hmask){
    free(hmask->buffer);
    free(hmask);
  }
  if(uc)free(uc);
  if(lc)free(lc);
  if(ringbuffer)free(ringbuffer);
  /* fstring and rstring cannot be freed, they are on the call stack */
  
  if(found){
     exit(EXIT_SUCCESS);
  }
  else {
     exit(EXIT_FAILURE);
  }
}


