/* datasniffer.c
Program:   datasniffer.c
Version:   1.0.4
Date:      07-JUN-2011
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2008 David Mathog and California Institute of Technology (Caltech)

Description:  
   Dump data out of binary files.
   Based on code from mdump and an older fortran program.
   This dumps data in a myriad of ways as it steps through the
   input file.  Primarily useful for reverse engineering data
   files whose format is not known.
   
   Compiles cleanly with:
   
   gcc -Wall -pedantic -std=c99 -lm -o datasniffer datasniffer.c
   
     
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

  1.0.4 07-JUN-2011, Fixed warning in gcc compile.
  1.0.3 17-DEC-2008, Change character formatting. Emit NP instead of * for nonprintable. Emit actual
                     value instead of 2a (hex for ascii *) for other modes.
  1.0.2 23-OCT-2006, changed license to GPL 2.
  1.0.1 11-JUL-2005, removed include of unistd.h, it was not needed.
  1.0.0 17-JUN-2005, first release

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>           /* for INT_MAX */
#include <math.h>             /* for ceil() and log() */
#include <ctype.h>            /* for toupper, tolower */

#define EXVERSTRING "1.0.4  07-JUN-2011"
#define COPYSTRING  "2011 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"

#define DT_NUM         10  /* number of supported data types */
#define DT_FORMS        6  /* number of supported data formattings */

/* data types as bit masks, also used for format type mask in format array
NOTE.  These MUST start at 1 and go up by factors of two!!! */
#define DT_C      0x00001  /* char               */
#define DT_S      0x00002  /* short int          */
#define DT_L      0x00004  /* int                */
#define DT_G      0x00008  /* long long          */
#define DT_F      0x00010  /* float              */
#define DT_D      0x00020  /* double             */
#define DT_UC     0x00040  /* unsigned char      */
#define DT_US     0x00080  /* unsigned short int */
#define DT_UL     0x00100  /* unsigned int       */
#define DT_UG     0x00200  /* unsigned long long */

/* position in format array for format for this data type */
#define DT_C_POS        0  /* c char               */
#define DT_S_POS        1  /* s short int          */
#define DT_L_POS        2  /* l int                */
#define DT_G_POS        3  /* g long long          */
#define DT_F_POS        4  /* f float              */
#define DT_D_POS        5  /* d double             */
#define DT_UC_POS       6  /* C unsigned char      */
#define DT_US_POS       7  /* S unsigned short int */
#define DT_UL_POS       8  /* L unsigned int       */
#define DT_UG_POS       9  /* G unsigned long long */

/* byte orders for all data types, both are possible */
#define DT_FOR  0x00001  /* forward   */
#define DT_REV  0x00002  /* reversed */

/* numbering options*/
#define DT_NOP_NON    0x00001  /*    no numbering                                  */
#define DT_NOP_REL    0x00002  /*    relative  position (number from offset) absolute if not set       */
#define DT_NOP_ST1    0x00004  /*    number from 1 (else from 0)                   */
#define DT_NOP_HEX    0x00008  /*    print position in hexadecimal                 */
#define DT_NOP_DEC    0x00010  /*    print position in decimal                     */
#define DT_NOP_OCT    0x00020  /*    print position in octal                       */

/* data formating bit masks,These MUST start at 1 and go up by factors of two!!! */
#define DF_C      0x00001  /* %c                 */
#define DF_D      0x00002  /* %d                 */
#define DF_X      0x00004  /* %x                 */
#define DF_O      0x00008  /* %o                 */
#define DF_F      0x00010  /* %f                 */
#define DF_E      0x00020  /* %e                 */
#define DF_L      0x00040  /* l modifier         */
#define DF_LL     0x00080  /* ll modifier        */

#define READ_BUF_SIZE    32    /*    size of a buffers to hold read values         */

/* prototypes */

int  lcl_strcasecmp(char *s1, char *s2);
void emit_ds(void);
void emit_header(int flip, int numbers, int headerbreaks, int columns);
void emit_help(void);
void emit_line(int offset, int count, int most_bytes,
 unsigned char *fordata, unsigned char *revdata,
 int flip, int numbers, int ccount, int columns);
int  find_most_bytes(void);
void format_scv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_ssv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_slv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_sgv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_sfv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_sdv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_ucv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_usv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_ulv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void format_ugv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes);
void init_dtsizes(void);
void insane(char *string);
void setinonnegnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label);
void setstring(char **val,int *numarg,int argc,char **argv,char * label);
void  process_command_line_args(int argc,char **argv,
  int *numbers, int *offset, int *multiple, int *flip,
  int *headers, int *headerbreaks, int *columns);
void store_value_in_arrays(int most_bytes, unsigned int inval,
   unsigned char *fordata, unsigned char *revdata, int flip);

/* globals */

FILE *lcl_stdin;
FILE *lcl_stdout;
/* a buffer used by all format functions to temporarily store a formatted result.
Note that some double values can use a huge number of positions if represented as a float, so
allocate 1000 characters to avoid writing off the end.  Ideally sprintf would restrict formatting
to "n" characters max but I don't see how to do that in C99. */
char fbuf[1024];

char *dt_fnames[DT_FORMS]={ 
  "%c",
  "%d",
  "%x",
  "%o",
  "%f",
  "%e"};

char *dt_snames[DT_NUM]={ 
  "c",
  "s",
  "l",
  "g",
  "f",
  "d",
  "C",
  "S",
  "L",
  "G"};

char *dt_lnames[DT_NUM]={
  "char",
  "short int",
  "int",
  "long long",
  "float",
  "double",
  "unsigned char",
  "unsigned short int",
  "unsigned int",
  "unsigned long long"};

int   dt_format[DT_NUM];          /* format options for each data type        */
int   dt_emit[DT_NUM];            /* emit (or not) setting for each data type */
int   dt_size[DT_NUM];            /* sizes, in bytes, of each data type       */
int   dt_fw[DT_NUM][DT_FORMS];    /* field width for each formatted type      */

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

void emit_ds(void){
int i;
   
    (void) fprintf(stderr,"Data sizes in bytes are:\n");
    for(i=0;i<DT_NUM;i++){
      if(dt_size[i] > 0){
        (void) fprintf(stderr,"%s %2d %s\n",
          dt_snames[i],dt_size[i],dt_lnames[i]);
      }
      else {
        (void) fprintf(stderr,"%s  * %s NOT IMPLEMENTED\n",
          dt_snames[i],dt_lnames[i]);
      }
    }
    exit(EXIT_SUCCESS);
}

void emit_help(void){
    (void) fprintf(stderr,"usage: datasniffer [options] (dump data from stdin/file to stdout/file)\n");
    (void) fprintf(stderr,"\noptions:\n");
    (void) fprintf(stderr,"   -in   file   file to dump. default = - = stdin \n");
    (void) fprintf(stderr,"   -out  file   write output to this file. default =  - = stdout\n");
    (void) fprintf(stderr,"   -o    N      offset in bytes to start of dumped data. default = 0\n");
    (void) fprintf(stderr,"   -l    N      number of bytes to dump. default = 0 = all\n");
    (void) fprintf(stderr,"   -c    N      number of byte columns per line. default = 1\n");
    (void) fprintf(stderr,"                (Clearest if used with a single data type and format.)\n");
    (void) fprintf(stderr,"   -n    [nar01xdo]  numbering options.  default = a0xd\n");
    (void) fprintf(stderr,"                  n no numbering, position: a=absolute,r=relative\n");
    (void) fprintf(stderr,"                  a absolute position  (number from start of file)\n");
    (void) fprintf(stderr,"                  r relative  position (number from offset)\n");
    (void) fprintf(stderr,"                  0 number from 0\n");
    (void) fprintf(stderr,"                  1 number from 1\n");
    (void) fprintf(stderr,"                  x print position in hexadecimal\n");
    (void) fprintf(stderr,"                  d print position in decimal\n");
    (void) fprintf(stderr,"                  o print position in octal\n");
    (void) fprintf(stderr,"   -d    t      datatypes to dump to output, default = CSL \n");
    (void) fprintf(stderr,"                  (signed) c=char, s=short, l=long, g=longlong, f=float, d=double\n");
    (void) fprintf(stderr,"                  (unsigned) C=char, S=short, L=long , G=longlong\n");
    (void) fprintf(stderr,"   -b  [fr]     Byte order to dump.  default = f\n");
    (void) fprintf(stderr,"                  f forward  (as read from data)\n");
    (void) fprintf(stderr,"                  r reversed (invert order of bytes in each data size)\n");
    (void) fprintf(stderr,"   -r  N        Header lines.  default = INT_MAX (one header at top of output)\n");
    (void) fprintf(stderr,"                0 no header lines.\n");
    (void) fprintf(stderr,"                N one header at top of output and every N output lines after that\n");
    (void) fprintf(stderr,"   -p           Emit a page break before every header except the first.\n");
    (void) fprintf(stderr,"   -ds          Emit data sizes before data dump\n");
    (void) fprintf(stderr,"   -h           print this help message (also -help --h --help -? --?)\n\n");
    (void) fprintf(stderr,"   FORMAT OPTIONS: ");
    (void) fprintf(stderr,"      c=char,d=decimal,x=hexadecimal,o=octal,f=float,e=exp\n");
    (void) fprintf(stderr,"   -fc [cdxo]   Emit c,C data types with formats specified. default = cx\n");
    (void) fprintf(stderr,"                 (If the character isn't printable c results in an NP)\n");
    (void) fprintf(stderr,"   -fs [dxo]    Emit s,S data types with formats specified. default = dx\n");
    (void) fprintf(stderr,"   -fl [dxo]    Emit l,L data types with formats specified. default = dx\n");
    (void) fprintf(stderr,"   -fg [dxo]    Emit g,G data types with formats specified. default = dx\n");
    (void) fprintf(stderr,"   -ff [fe]     Emit f   data type  with formats specified. default = f\n");
    (void) fprintf(stderr,"   -fd [fe]     Emit d   data type  with formats specified. default = f\n");
    (void) fprintf(stderr,"   -i           emit version, copyright, license and contact information\n\n");
    (void) fprintf(stderr,"\nexamples:\n");
    (void) fprintf(stderr," %% datasniffer -in somefile \n");
    (void) fprintf(stderr,"       Dump in hex format integer elements in blocks of 4 per line\n");
    (void) fprintf(stderr,"       and number the lines by data block.\n");
    (void) fprintf(stderr," %% echo ABCD | datasniffer -d c \n");
    (void) fprintf(stderr,"       Emits the octal values for the four characters ABCD.\n");
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]){
int   count,hcount;
int   numbers;           /* numbering control bits                   */
int   offset;            /* offset to first data emitted             */
int   multiple;          /* number of bytes of data to emit          */
int   flip;              /* data reordering options                  */
int   columns;           /* number of bytes to process per line      */
int   headers;           /* lines between headers (or no headers)    */
int   headerbreaks;      /* if true emit a page break before 2nd -> nth headers */

int                most_bytes;  /* the most bytes used for any of the storage types */
unsigned char      fordata[READ_BUF_SIZE];
unsigned char      revdata[READ_BUF_SIZE];
int                inval;
int                ccount;      /* byte column counter */

  
  init_dtsizes();
 
  process_command_line_args(argc,argv,
    &numbers, &offset, &multiple, &flip, &headers, &headerbreaks, &columns);

  most_bytes=find_most_bytes();
  
  /* clear the accumulators */
  memset(fordata,0,most_bytes);
  memset(revdata,0,most_bytes);

    
  count=-1;
  hcount=0;
  ccount=columns;
  while(1){
    count++;
    if(count>multiple)break;
    inval=fgetc(lcl_stdin);
    if(inval==EOF)break;
    if(count<offset)continue;
    if(headers){
      if(hcount==0){
        emit_header(flip,numbers,headerbreaks,columns);
        hcount=headers*columns;
      }
      hcount--;
    }
    store_value_in_arrays(most_bytes,(unsigned int) inval, fordata, revdata, flip);
    emit_line(offset,count,most_bytes, fordata, revdata, flip, numbers,ccount,columns);
    ccount--;
    if(!ccount)ccount=columns;
  }
  /* If the data didn't come out evenly in columns per line 
     appenda terminating EOL. */
  if(ccount!=columns){
    (void) fprintf(lcl_stdout,"\n");
  }
  exit(EXIT_SUCCESS);
}

void emit_header(int flip, int numbers, int headerbreaks, int columns){
int i,j,k,fw,ccount;
char string[32];
static int firstheader=1;

  if(firstheader){
    firstheader=0;
  }
  else {
    if(headerbreaks){
      (void) fprintf(lcl_stdout,"%c",12);
    }
  }

  if(!(numbers & DT_NOP_NON)){  /* Make space for numbers */
    if(numbers & DT_NOP_ST1){ (void) sprintf(string," P1");  }
    else {                    (void) sprintf(string," P0");  }
    if(numbers & DT_NOP_REL){ (void) sprintf(&string[3],"Rel");  }
    else {                    (void) sprintf(&string[3],"Abs");  } /* Abs is the default if nothing is specified */
    if(numbers & DT_NOP_DEC)  (void) fprintf(lcl_stdout,"%sDec",string); 
    if(numbers & DT_NOP_HEX)  (void) fprintf(lcl_stdout,"%sHex",string);
    if(numbers & DT_NOP_OCT)  (void) fprintf(lcl_stdout,"%sOct",string); 
    (void) fprintf(lcl_stdout," "); 
  }

  /* Formatted fields may be repeated columns times */
  for(ccount=columns;ccount>0;ccount--){
  
     /* field widths are 2*bytes+1 or 9, whichever is MORE.  Labels are all 9
        wide.  Want them left justified, so pad it if the fw is > 9 */
     for(i=0;i<DT_NUM;i++){
       if(dt_emit[i]>0){
         for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
           fw=dt_fw[i][j];
           if(fw<8)fw=8; /* minimum field width */
           if(dt_format[i] & k){
             if(flip & DT_FOR){
               (void) fprintf(lcl_stdout," %*s(+,%s) ",fw-7,dt_snames[i],dt_fnames[j]);
             }
             if(flip & DT_REV){
               (void) fprintf(lcl_stdout," %*s(-,%s) ",fw-7,dt_snames[i],dt_fnames[j]);
             }
           }
         }
       }
     }
  }
  (void) fprintf(lcl_stdout,"\n");
}

void store_value_in_arrays(int most_bytes, unsigned int inval,
   unsigned char *fordata, unsigned char *revdata, int flip){
   
int i;
   
   if(flip & DT_FOR){
     /* shift all data to the right and drop the new byte in at the front */
     for(i=most_bytes-1; i>0; i--){
       fordata[i]=fordata[i-1];
     }
     fordata[0]=inval;
   }
   
   if(flip & DT_REV){
     /* shift all to the left and drop the new byte in at the back */
     for(i=0; i<most_bytes-1; i++){
       revdata[i]=revdata[i+1];
     }
     revdata[most_bytes-1]=inval;
   }
}

void    emit_line(int offset, int count, int most_bytes,
 unsigned char *fordata, unsigned char *revdata,
 int flip, int numbers, int ccount, int columns){

int               pos;
int                 i;

  /* Numbers are only emitted before the first byte column in the line */
  if(ccount==columns){
    if(!(numbers & DT_NOP_NON)){  /* Make space for numbers */
      if(numbers & DT_NOP_REL){ pos = count - offset;         }
      else {                    pos = count;                   }
      if(numbers & DT_NOP_ST1){ pos++;                         }
      if(numbers & DT_NOP_DEC)  (void) fprintf(lcl_stdout,"%9d",pos); 
      if(numbers & DT_NOP_HEX)  (void) fprintf(lcl_stdout,"%9x",pos);
      if(numbers & DT_NOP_OCT)  (void) fprintf(lcl_stdout,"%9o",pos); 
    }
  }

  /* field widths are 2*bytes+1 or 9, whichever is MORE.  Labels are all 9
     wide.  Want them left justified, so pad it if the fw is > 9 */
  
  for(i=0;i<DT_NUM;i++){
    if(dt_emit[i]>0){
      switch (i) {
        case DT_C_POS:
          format_scv(fordata,revdata,i,flip,most_bytes); break;
        case DT_S_POS:
          format_ssv(fordata,revdata,i,flip,most_bytes); break;
        case DT_L_POS:
          format_slv(fordata,revdata,i,flip,most_bytes); break;
        case DT_G_POS:
          format_sgv(fordata,revdata,i,flip,most_bytes); break;
        case DT_F_POS:
          format_sfv(fordata,revdata,i,flip,most_bytes); break;
        case DT_D_POS:
          format_sdv(fordata,revdata,i,flip,most_bytes); break;
        case DT_UC_POS: 
          format_ucv(fordata,revdata,i,flip,most_bytes); break;
        case DT_US_POS:
          format_usv(fordata,revdata,i,flip,most_bytes); break;
        case DT_UL_POS:
          format_ulv(fordata,revdata,i,flip,most_bytes); break;
        case DT_UG_POS:
          format_ugv(fordata,revdata,i,flip,most_bytes); break;
        default:
          insane("datasniffer: fatal programming error: unknown data type");
      }
    }
  }
  
  /* EOL is only emitted after the last byte column on the line */
  if(ccount==1){
    (void) fprintf(lcl_stdout,"\n");
  }
}

void  process_command_line_args(int argc,char **argv,
  int *numbers, int *offset, int *multiple, int *flip,
  int *headers, int *headerbreaks, int *columns){

int numarg;
int dt_emitset=0;    /* use defaults if none are set */
char *string;
int  itemp;

  lcl_stdin=stdin;
  lcl_stdout=stdout;
  *numbers=-1;        /* use default */
  *offset=0;          /* start from first int */
  *multiple=0;        /* emit all data in file */
  *flip=-1;           /* use default */
  *headers=INT_MAX;   /* use default */
  *headerbreaks=0;    /* no breaks before headers */
  *columns=1;         /* 1 byte per output line */

  /* set the default formats for each type */

  dt_format[DT_C_POS]  = DF_C | DF_X         ;
  dt_format[DT_S_POS]  = DF_D | DF_X         ;
  dt_format[DT_L_POS]  = DF_D | DF_X | DF_L  ;
  dt_format[DT_G_POS]  = DF_D | DF_X | DF_LL ;
  dt_format[DT_F_POS]  = DF_F;
  dt_format[DT_D_POS]  = DF_F;
  dt_format[DT_UC_POS] = dt_format[DT_C_POS];
  dt_format[DT_US_POS] = dt_format[DT_S_POS];
  dt_format[DT_UL_POS] = dt_format[DT_L_POS];
  dt_format[DT_UG_POS] = dt_format[DT_G_POS];


  for(numarg=1;numarg<argc;numarg++){
    if(0==lcl_strcasecmp(argv[numarg], "-b")){
      setstring(&string,&numarg,argc,argv,"-b");
      itemp=0;
      for(;*string != '\0';string++){
        switch(tolower(*string)){
          case 'f':
            itemp |= DT_FOR; break;
          case 'r':
            itemp |= DT_REV; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -b");
        }
      }
      *flip=itemp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-n")){
      setstring(&string,&numarg,argc,argv,"-n");
      itemp=0;
      for(;*string != '\0';string++){
        switch(tolower(*string)){
          case 'n':
            itemp |= DT_NOP_NON; break;
          case 'a':
            break; /* This is the default */
          case 'r':
            itemp |= DT_NOP_REL; break;
          case '0': /*This is the default*/
            break;
          case '1':
            itemp |= DT_NOP_ST1; break;
          case 'x':
            itemp |= DT_NOP_HEX; break;
          case 'd':
            itemp |= DT_NOP_DEC; break;
          case 'o':
            itemp |= DT_NOP_OCT; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -n");
        }
      }
      *numbers=itemp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-c")){
      setiposnumeric(columns,&numarg,argc,argv,"-c");
    }
    else if(lcl_strcasecmp(argv[numarg], "-in")==0){
      lcl_stdin=fopen(argv[++numarg],"r");
      if(lcl_stdin==NULL)insane("datasniffer: fatal error: could not open input file");
      continue;
    }
    else if(lcl_strcasecmp(argv[numarg], "-out")==0){
      lcl_stdout=fopen(argv[++numarg],"w");
      if(lcl_stdout==NULL)insane("datasniffer: fatal error: could not open output file");
      continue;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-p")){
      *headerbreaks=1;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-r")){
      setinonnegnumeric(headers,&numarg,argc,argv,"-r");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-o")){
      setinonnegnumeric(offset,&numarg,argc,argv,"-o");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-offset")){
      setinonnegnumeric(offset,&numarg,argc,argv,"-offset");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-l")){
      setinonnegnumeric(multiple,&numarg,argc,argv,"-l");
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-d")){
      if(dt_emitset)insane("datasniffer: fatal error: multiple instances of -d");
      setstring(&string,&numarg,argc,argv,"-d");
      for(;*string!='\0';string++){
        dt_emitset=1;
        switch(*string){
          case 'c':
            dt_emit[DT_C_POS]=1; break;
          case 's':
            dt_emit[DT_S_POS]=1; break;
          case 'l':
            dt_emit[DT_L_POS]=1; break;
          case 'g':
            dt_emit[DT_G_POS]=1; break;
          case 'f':
            dt_emit[DT_F_POS]=1; break;
          case 'd':
            dt_emit[DT_D_POS]=1; break;
          case 'C':
            dt_emit[DT_UC_POS]=1; break;
          case 'S':
            dt_emit[DT_US_POS]=1; break;
          case 'L':
            dt_emit[DT_UL_POS]=1; break;
          case 'G':
            dt_emit[DT_UG_POS]=1; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -d");
        }
      }
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fc")){
      setstring(&string,&numarg,argc,argv,"-fc");
      itemp=0;
      for(;*string!='\0';string++){
        switch(tolower(*string)){
          case 'c':
            itemp |= DF_C; break;
          case 'd':
            itemp |= DF_D; break;
          case 'x':
            itemp |= DF_X; break;
          case 'o':
            itemp |= DF_O; break;
          case 'f':
            itemp |= DF_F; break;
          case 'e':
            itemp |= DF_E; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -fc");
        }
      }
      dt_format[DT_UC_POS]=itemp;
      dt_format[DT_C_POS]=itemp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fs")){
      setstring(&string,&numarg,argc,argv,"-fs");
      itemp=0;
      for(;*string!='\0';string++){
        switch(tolower(*string)){
          case 'd':
            itemp |= DF_D; break;
          case 'x':
            itemp |= DF_X; break;
          case 'o':
            itemp |= DF_O; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -fs");
        }
      }
      dt_format[DT_US_POS]=itemp;
      dt_format[DT_S_POS]=itemp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fl")){
      setstring(&string,&numarg,argc,argv,"-fl");
      itemp=DF_L;
      for(;*string!='\0';string++){
        switch(tolower(*string)){
          case 'd':
            itemp |= DF_D; break;
          case 'x':
            itemp |= DF_X; break;
          case 'o':
            itemp |= DF_O; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -fl");
        }
      }
      dt_format[DT_UL_POS]=itemp;
      dt_format[DT_L_POS]=itemp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fg")){
      setstring(&string,&numarg,argc,argv,"-fg");
      itemp=DF_LL;
      for(;*string!='\0';string++){
        switch(tolower(*string)){
          case 'd':
            itemp |= DF_D; break;
          case 'x':
            itemp |= DF_X; break;
          case 'o':
            itemp |= DF_O; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -fg");
        }
      }
      dt_format[DT_UG_POS]=itemp;
      dt_format[DT_G_POS]=itemp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-ff")){
      setstring(&string,&numarg,argc,argv,"-ff");
      itemp=0;
      for(;*string!='\0';string++){
        switch(tolower(*string)){
          case 'f':
            itemp |= DF_F; break;
          case 'e':
            itemp |= DF_E; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -ff");
        }
      }
      dt_format[DT_F_POS]=itemp;
    }
    else if(0==lcl_strcasecmp(argv[numarg], "-fd")){
      setstring(&string,&numarg,argc,argv,"-fd");
      itemp=0;
      for(;*string!='\0';string++){
        switch(tolower(*string)){
          case 'f':
            itemp |= DF_F; break;
          case 'e':
            itemp |= DF_E; break;
          default:
            insane("datasniffer: fatal error: illegal datatype specified in -fd");
        }
      }
      dt_format[DT_D_POS]=itemp;
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
      (void) fprintf(stderr,"datasniffer:fatal error:no such parameter [%s]\n",argv[numarg]);
      emit_help();
    }
  }
  /*sanity checking*/
  if(*numbers==-1){ *numbers  = DT_NOP_HEX | DT_NOP_DEC ; }  /* DT_NOP_ABS is an unset bit, also default */
  if(*headers==-1){ *headers  = INT_MAX;                               }
  if(*flip==-1){    *flip     = DT_FOR;                                }
  if(dt_emitset==0){
    dt_emit[DT_UC_POS]=1;
    dt_emit[DT_US_POS]=1;
    dt_emit[DT_UL_POS]=1;
  }
  if( ! (*numbers & (DT_NOP_HEX | DT_NOP_DEC | DT_NOP_OCT) )){
    insane("datasniffer: fatal error: -n requires at least one of {x,d,o}");
  }
  if(*multiple==0){ *multiple = INT_MAX; }  
  else {            *multiple = *multiple + *offset - 1; } /* make multiple absolute position*/
}

int find_most_bytes(void){
int i;
int most=0;

  for(i=0;i<DT_NUM;i++){
    if(dt_emit[i]){
      if(dt_size[i]>most)most=dt_size[i];
    }
  }
  return most;
}

void format_scv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
char thevar='^';
int  j,k,fw;
char string[32];

  for (j=0,k=1; j<DT_FORMS;  j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */
      /* construct a format string */
      if(dt_format[i] & DF_L){          sprintf(string," %%%cl%c",'*',dt_fnames[j][1]);    }
      else if(dt_format[i] & DF_LL){    sprintf(string," %%%cll%c",'*',dt_fnames[j][1]);   } 
      else {                            sprintf(string," %%%c%c",'*',dt_fnames[j][1]);     }

      /* the cast to (int) in isprint eliminates warnings in some
      compilers from the char type of thevar */
      if(flip & DT_FOR){       
        memcpy(&thevar,fordata,dt_size[i]);
        if(!isprint((int) thevar) && (k & DF_C)){  (void) fprintf(lcl_stdout," %*s",fw,"NP");      }
        else {                               (void) fprintf(lcl_stdout,string,  fw, thevar); }
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        if(!isprint((int) thevar) && (k & DF_C)){  (void) fprintf(lcl_stdout," %*s",fw,"NP");      }
        else {                               (void) fprintf(lcl_stdout,string,  fw, thevar); }
      }
    }
  }
}

void format_ssv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
short int thevar;
int  j,k,fw;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */

      /* construct a format string */
      if(dt_format[i] & DF_L){
        sprintf(string," %%%cl%c",'*',dt_fnames[j][1]);
      }
      else if(dt_format[i] & DF_LL){
        sprintf(string," %%%cll%c",'*',dt_fnames[j][1]);
      } 
      else {
        sprintf(string," %%%c%c",'*',dt_fnames[j][1]);
      }
      if(flip & DT_FOR){
        memcpy(&thevar,fordata,dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
    }
  }
}

void format_slv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
int thevar;
int  j,k,fw;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */

      /* construct a format string */
      if(dt_format[i] & DF_L){
        sprintf(string," %%%cl%c",'*',dt_fnames[j][1]);
      }
      else if(dt_format[i] & DF_LL){
        sprintf(string," %%%cll%c",'*',dt_fnames[j][1]);
      } 
      else {
        sprintf(string," %%%c%c",'*',dt_fnames[j][1]);
      }
      if(flip & DT_FOR){
        memcpy(&thevar,fordata,dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
    }
  }
}

void format_sgv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
long long thevar;
int  j,k,fw;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */

      /* construct a format string */
      if(dt_format[i] & DF_L){
        sprintf(string," %%%cl%c",'*',dt_fnames[j][1]);
      }
      else if(dt_format[i] & DF_LL){
        sprintf(string," %%%cll%c",'*',dt_fnames[j][1]);
      } 
      else {
        sprintf(string," %%%c%c",'*',dt_fnames[j][1]);
      }
      if(flip & DT_FOR){
        memcpy(&thevar,fordata,dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
    }
  }
}

void format_sfv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
float thevar;
int  j,k,fw,co;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */

      /* construct a format string */
      if(dt_format[i] & DF_L){
        sprintf(string,"%%%sl%c","*.*",dt_fnames[j][1]);
      }
      else if(dt_format[i] & DF_LL){
        sprintf(string,"%%%sll%c","*.*",dt_fnames[j][1]);
      } 
      else {
        sprintf(string,"%%%s%c","*.*",dt_fnames[j][1]);
      }
      if(flip & DT_FOR){
        memcpy(&thevar,fordata,dt_size[i]);
        co=sprintf(fbuf,string,  fw,fw-7, thevar);
        if(co<=fw){ (void) fprintf(lcl_stdout," %s",fbuf);    }
        else {      (void) fprintf(lcl_stdout," %*s",fw,"*"); }
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        co=sprintf(fbuf,string,  fw,fw-7, thevar);
        if(co<=fw){ (void) fprintf(lcl_stdout," %s",fbuf);    }
        else {      (void) fprintf(lcl_stdout," %*s",fw,"*"); }
      }
    }
  }
}

void format_sdv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
double thevar;
int  j,k,fw,co,first,dir;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */

      /* construct a format string */
      if(dt_format[i] & DF_L){
        sprintf(string,"%%%sl%c","*.*",dt_fnames[j][1]);
      }
      else if(dt_format[i] & DF_LL){
        sprintf(string,"%%%sll%c","*.*",dt_fnames[j][1]);
      } 
      else {
        sprintf(string,"%%%s%c","*.*",dt_fnames[j][1]);
      }
      
      for(dir=0;dir<=1;dir++){
        if(dir==0){
          if(flip & DT_FOR){ memcpy(&thevar,fordata,dt_size[i]); }
          else {             continue;                           }
        }
        else {
          if(flip & DT_REV){ memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]); }
          else {             continue;                           }
        }
        co=sprintf(fbuf,string,  fw,fw-8, thevar);
        if(co<=fw){
          /* handle implementations where e+55 is used instead of e+055, else
          the column will shift. */
          if(fbuf[fw-3]=='+' || fbuf[fw-3]=='-'){
            first=1;
            fbuf[fw+1] = '\0';
            fbuf[fw]   = fbuf[fw-1];
            fbuf[fw-1] = fbuf[fw-2];
            fbuf[fw-2] = '0';
          }
          else {
            first=0;
          }
          (void) fprintf(lcl_stdout," %s",&fbuf[first]);   
        }
        else {      (void) fprintf(lcl_stdout," %*s",fw,"*"); }
      }
    }
  }
}


void format_ucv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
unsigned char thevar;
int  j,k,fw;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */

      /* construct a format string */
      if(dt_format[i] & DF_L){        sprintf(string," %%%cl%c",'*',dt_fnames[j][1]);      }
      else if(dt_format[i] & DF_LL){  sprintf(string," %%%cll%c",'*',dt_fnames[j][1]);     }
      else {                          sprintf(string," %%%c%c",'*',dt_fnames[j][1]);       }

      /* the cast to (int) in isprint eliminates warnings in some
      compilers from the char type of thevar */
      if(flip & DT_FOR){       
        memcpy(&thevar,fordata,dt_size[i]);
        if(!isprint(thevar) && (k & DF_C)){  (void) fprintf(lcl_stdout," %*s",fw,"NP");      }
        else {                               (void) fprintf(lcl_stdout,string,  fw, thevar); }
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        if(!isprint(thevar) && (k & DF_C)){  (void) fprintf(lcl_stdout," %*s",fw,"NP");      }
        else {                               (void) fprintf(lcl_stdout,string,  fw, thevar); }
      }
    }
  }
}

void format_usv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
unsigned short int thevar;
int  j,k,fw;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */

      /* construct a format string */
      if(dt_format[i] & DF_L){
        sprintf(string," %%%cl%c",'*',dt_fnames[j][1]);
      }
      else if(dt_format[i] & DF_LL){
        sprintf(string," %%%cll%c",'*',dt_fnames[j][1]);
      } 
      else {
        sprintf(string," %%%c%c",'*',dt_fnames[j][1]);
      }
      if(flip & DT_FOR){
        memcpy(&thevar,fordata,dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
    }
  }
}

void format_ulv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
unsigned int thevar;
int  j,k,fw;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */

      /* construct a format string */
      if(dt_format[i] & DF_L){
        sprintf(string," %%%cl%c",'*',dt_fnames[j][1]);
      }
      else if(dt_format[i] & DF_LL){
        sprintf(string," %%%cll%c",'*',dt_fnames[j][1]);
      } 
      else {
        sprintf(string," %%%c%c",'*',dt_fnames[j][1]);
      }
      if(flip & DT_FOR){
        memcpy(&thevar,fordata,dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
    }
  }
}

void format_ugv(unsigned char *fordata, unsigned char *revdata, int i, int flip, int most_bytes){
unsigned long long thevar;
int  j,k,fw;
char string[32];

  for (j=0,k=1;j<DT_FORMS;j++, k<<=1){
    if(dt_format[i] & k){
      fw=dt_fw[i][j];
      if(fw<8)fw=8; /* minimum field width */
      /* construct a format string */
      if(dt_format[i] & DF_L){
        sprintf(string," %%%cl%c",'*',dt_fnames[j][1]);
      }
      else if(dt_format[i] & DF_LL){
        sprintf(string," %%%cll%c",'*',dt_fnames[j][1]);
      } 
      else {
        sprintf(string," %%%c%c",'*',dt_fnames[j][1]);
      }
      if(flip & DT_FOR){
        memcpy(&thevar,fordata,dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
      if(flip & DT_REV){
        memcpy(&thevar,&revdata[most_bytes-dt_size[i]],dt_size[i]);
        (void) fprintf(lcl_stdout,string,  fw, thevar);
      }
    }
  }
}

void init_dtsizes(void){
int i;

  /* initialize the dtlookup and dt_format arrays.
  If dt_format is still 0 after the command line args are
  processed it will be set with the default values. */

  for(i=0; i<DT_NUM; i++){
    dt_format[i]=0;
    dt_emit[i]=0;
  }

  /*initialize sizes for data types, these are in bytes */
  
  dt_size[DT_C_POS ] =   sizeof(char               );
  dt_size[DT_S_POS ] =   sizeof(short int          );
  dt_size[DT_L_POS ] =   sizeof(int                );
#ifdef datasniffer_NOLONGLONG                          
  dt_size[DT_G_POS ] =   0                          ;
  dt_size[DT_UG_POS] =   0                          ;
#else
  dt_size[DT_G_POS ] =   sizeof(long long          );
  dt_size[DT_UG_POS] =   sizeof(unsigned long long );
#endif
  dt_size[DT_F_POS ] =   sizeof(float              );
  dt_size[DT_D_POS ] =   sizeof(double             );
  dt_size[DT_UC_POS] =   sizeof(unsigned char      );
  dt_size[DT_US_POS] =   sizeof(unsigned short int );
  dt_size[DT_UL_POS] =   sizeof(unsigned int       );
  
  /*initialize field widths for each formatted data types, these are in
    characters.  Note that many of these are never used. d can be signed
    in some cases so allow one more space for that. f,e can also be signed
    but that is handled in the format_sfv function.*/
  
  for(i=0;i<DT_NUM;i++){
    dt_fw[i][0] = dt_size[i]*1;   /* %c */
    dt_fw[i][1] = 1 + ceil( (double) dt_size[i] * 2 * log(16.0) / log(10.0) );   /* %d */
    dt_fw[i][2] = dt_size[i]*2;   /* %x */
    dt_fw[i][3] = ceil( (double) dt_size[i] * 2 * log(16.0) / log(8.0)  );   /* %o */
    dt_fw[i][4] = dt_size[i]*3;   /* %f */
    dt_fw[i][5] = dt_size[i]*3;   /* %e */
  }
}

