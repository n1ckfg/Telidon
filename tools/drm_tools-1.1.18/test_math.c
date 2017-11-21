/* 
Program:   test_math.c
Version:   0.0.8
Date:      12-DEC-2012
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2012 David Mathog and California Institute of Technology (Caltech)

This is primarily a testbed for working out the math sections for extract.c,
but it also compiles to a standalone program with:

  gcc -Wall -std=c99 -pedantic -DUSETOK -O3 -o dmath test_math.c -lm 

The binary dmath is a calculator.  The parts specific for testing
extract compatibility require -DUSETOK at compile time.  The string variable
syntax and functions are not exposed in the help screens either way.  This
definition should be left off if dmath is to be installed on a system for general use.

  $a[1]=vb[1]    convert text to double and store
  tok(vA[])      number of tokens in vA
  $a[]=va[]      convert all text tokens to double and store
  

History:
0.0.8  Added hex and octal output modes.
       Added hex, octan, and binary input modes.
       Added bitwise operators (double ->uint32_t -> operate -> double)
0.0.7  Fixed compiler warning from recent gcc, variable set but not used.
0.0.6  Added nnz,pnz: turns on/off the formatting of double
       -0.  If off (pnz, default) these print as zero.  However, they are
       still stored numerically as -0.
0.0.5  bugfix, was using %lf/%le, which worked most places but should have
       been just %f/%e.
       Added -DCHKALN, to look for alignment issues.
0.0.4  Added solaris workarounds.  Fixed memory access problems in
       a couple of places that showed up on Solaris, silent on Opteron.
0.0.3  fixed bug in build, a few pieces on the wrong side of ifdef USETOK.
0.0.2  changed string constant form from vN to just N.  This is compatible
       with the syntax elsewhere in extract, so that the math section isn't
       the only place with the vN syntax.
0.0.1  first code

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>            /* for toupper, tolower */
#include <limits.h>           /* for INT_MAX          */
#include <math.h>             /* for math constants   */
#include <float.h>            /* for math precision constants   */
#ifdef SOL8
#include "sol8.h"
#else
#include <stdint.h>           /* for uint32_t, int32_t */
#endif

#define EXVERSTRING "0.0.8 12-DEC-2012"
#define COPYSTRING  "2012 David Mathog and California Institute of Technology"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"

#define INSFTLERR      "dmath: fatal error:"
#define INSFTLPRGERR   "dmath: fatal programming error:"


#define MEMOOPS " could not allocate memory"
#define SOD     sizeof(double)
#define SOI     sizeof(int)
#define TOVAROFF(A)     (A=='-'       ? MYVARSMAX : toupper(A) - 'A')
#define FROMVAROFF(A)   (A==MYVARSMAX ? '-'       : toupper(A) + 'A')
#define MYVARSMAX       26     /* maximum number of SET + DEFINED variables, vA->vZ */
#define ISVAROFF(A)     (A>=0 && A<MYVARSMAX  ? 1 : 0)
#define ISNOTVAROFF(A)  (A<0  || A>=MYVARSMAX ? 1 : 0)
#define DBLPREC(A,B) ((A) > (B) ? (A) : ((A) < -(B) ? (A) : (isnan(A) ? (A) : 0.0) ))
#define DBL2UINT32(A) (A>UINT32_MAX ? UINT32_MAX : ( A<0 ? 0 : (uint32_t) A ))
#define DBL2INT32(A)  (A>INT32_MAX ? INT32_MAX : ( A<INT32_MIN ? INT32_MIN : (int32_t) A ))

#define EXT_MALLOC(A,B,C)        A=malloc(B); if(!A)insane(INSFTLERR,C)
#define EXT_CALLOC(A,B,C,D)      A=calloc(B,C); if(!A)insane(INSFTLERR,D)
#define EXT_REALLOC(A,B,C,D)     if(B<C){A=realloc(A,C); if(!A)insane(INSFTLERR,D);B=(C);}
#define EXT_REALLOC2(A,B,C,D,E,F)  if(B<C){A=realloc(A,(D*E)); if(!A)insane(INSFTLERR,F);B=(D);}
#define EXT_REALLOC3(A,B,C,D,E)  {A=realloc(A,(C*D)); if(!A)insane(INSFTLERR,E);B=(C);}

#define ESP_CLEN(A)    (A->slen ? A->slen - 1 : 0 )/* strlen value for the ESNEXUS*               */
#define ESP_CPTR(A)    (A->string)                 /* Pointer to the first position ESNEXUS*      */
#define ESP_CADDR(A,B) (&A->string[B])             /* Pointer to position B in the ESNEXUS string */
#define ESP_LASTPTR(A) &(A->string[ESP_CLEN(A)])   /* Pointer to the final character in ESNEXUS*  */
#define ESP_LASTVAL(A) A->string[ESP_CLEN(A)]      /* value of   the final character in ESNEXUS*  */
#define ESP_INCLEN(A)  (A->slen++)                 /* increment length for the ESNEXUS*           */
#define ESP_ADDLEN(A,B)(A->slen += (B))            /* add to length for the ESNEXUS*              */
#define ESP_SETLEN(A,B)(A->slen = (B))             /* set length for the ESNEXUS*                 */
#define ESP_INT(A,B) (*(int *)  &(A->string[B])) 
                                                   /* offset to integer data         */
#define ESP_OFFINT(A,B) (*(int *)  &(A->string[*(int *)  &(A->string[B])])) 
                                                   /* offset to an offset to integer data         */
#define ESP_OFFCPTR(A,B) ((char *)  &(A->string[*(int *)  &(A->string[B])])) 
                                                   /* offset to an offset to a character pointer  */

/* above from extract, below new, for these routines */

#define NEXTINTREMAINDER(A)  (A % SOI ? SOI-(A % SOI): 0) 
#define NEXTDBLREMAINDER(A)  (A % SOD ? SOD-(A % SOD): 0) 
#define NEXTINTBOUNDARY(A)  A += (A % SOI ? SOI-(A % SOI): 0) 
#define NEXTDBLBOUNDARY(A)  A += (A % SOD ? SOD-(A % SOD): 0) 
#define ESP_NEXTINTBOUNDARY(A)  NEXTINTBOUNDARY(A->slen) 
#define ESP_NEXTDBLBOUNDARY(A)  NEXTDBLBOUNDARY(A->slen) 
#define MATHINC       512      /* size increments for pre_run and rpn math stacks */
#define A_UNARY_NEG     1
#define S_U_NEG       "\1"
#define A_STRINGVAR     2
#define S_SVAR        "\2"
#define IS_OP_TRUE    0x001  /* any normal operator */
#define IS_OP_PL      0x002  /* left paren          */
#define IS_OP_NPL     0x004  /* negating left paren */
#define IS_OP_PR      0x008  /* right paren         */
#define IS_OP_CMA     0x010  /* comma                */
#define IS_OP_DONE    0x020  /* done                */
#define IS_OP_START   0x040  /* used for syntax checking    */
#define IS_VVAR       0x080  /* variable operand    */
#define IS_VLIT       0x100  /* literal operand     */
#define IS_VFUNC      0x200  /* function operator (acts more like a variable) */
#define IS_VARRAY     0x400  /* array variable operand    */
 /* these are used to catch syntax errors, they characterize preceding token/delimiter
     operands and func must follow an operator,  (, Comma, START.  Values can follow unary 
     operators must follow an operand or a )
     ( may follow an operator, array, func, (, Comma, or START
     ) may follow an operand or another )
     Comma may follow an operand or a )
 */
#define MASK_OPERAND_OK  (IS_OP_START | IS_OP_PL | IS_OP_NPL | IS_OP_TRUE | IS_OP_CMA) 
#define MASK_OPERATOR_OK (IS_OP_PR | IS_VVAR | IS_VLIT) 
#define MASK_PL_OK       (IS_OP_START | IS_OP_PL | IS_OP_NPL |IS_OP_TRUE | IS_OP_CMA | IS_VFUNC| IS_VARRAY) 
#define MASK_PR_OK       (IS_OP_PR | IS_VVAR | IS_VLIT | IS_VARRAY) 
#define MASK_CMA_OK      (IS_OP_PR | IS_VVAR | IS_VLIT) 

#define IS_VALUE    0
#define IS_NUM_ADDR 1
#define IS_STR_ADDR 2
#define IS_MOP      3

/* val 1, numaddr 2 straddr 4 , pattern is 6 octal positions wide with leading 0s*/
#define OPPAT_VAL   1
#define OPPAT_NAD   2
#define OPPAT_SAD   4
#define OPPAT_NONE  0
/* valid operand patterns */
#define OPPAT_A  0000001 /*                      val */
#define OPPAT_B  0000211 /*              nad val val */
#define OPPAT_C  0000411 /*              sad val val */
#define OPPAT_D  0002111 /*          nad val val val */
#define OPPAT_E  0000011 /*                  val val */
#define OPPAT_F  0211211 /*  nad val val nad val val */
#define OPPAT_G  0021111 /*      nad val val val val */
#define OPPAT_H  0000002 /*                      nad */
#define OPPAT_I  0000004 /*                      sad */
#define OPPAT_J  0000021 /*                  nad val */
#define OPPAT_K  0000041 /*                  sad val */
#define OPPAT_L  0001211 /*          val nad val val */
#define OPPAT_M  0211111 /*  nad val val val val val */
#define OPPAT_N  0211411 /*  nad val val sad val val */

/* output formatting modes */
#define OUT_FMT_ENG  0x01
#define OUT_FMT_SCI  0x02
#define OUT_FMT_UNS  0x04  /* unsigned, for integer types only */
#define OUT_FMT_HEX  0x08
#define OUT_FMT_DEC  0x10
#define OUT_FMT_OCT  0x20

enum rpn_states {RPN_SCALAR,RPN_NVEC_SELF,RPN_NVEC_SCALAR,RPN_SCALAR_NVEC,
  RPN_NVEC_NVEC
#ifdef USETOK
  ,RPN_NVEC_SVEC
#endif /* USETOK */
};

/* Values for math actions 
NMUL etc handle unary operations like * -func().
*/
enum math_ops {
  MATH_NOP,   MATH_NNONE,    MATH_NONE,   MATH_LD_STATE,
  MATH_LD_ELEM,  MATH_SV_ELEM, MATH_SV_ZERO,
#ifdef USETOK
  MATH_LD_TOKEN,
#endif /* USETOK */
  MATH_ADD,   MATH_SUB,  MATH_MUL,    MATH_DIV,     MATH_MOD,  MATH_POW, MATH_CMP,
  MATH_LOG,   MATH_LN,   MATH_E10,    MATH_EE,
  MATH_CHS,   MATH_ABS,
  MATH_SIN,   MATH_COS,  MATH_TAN,    MATH_ASIN,    MATH_ACOS, MATH_ATAN, 
  MATH_SINH,  MATH_COSH, MATH_TANH, 
  MATH_D2R,   MATH_R2D,
  MATH_BITNOT,
  MATH_MAX,   MATH_MIN,
  MATH_BITAND,MATH_BITOR,MATH_BITXOR, MATH_BITSHL,  MATH_BITSHR,
  MATH_DLEN,  MATH_SUM,  MATH_SM2,    MATH_NML,
  MATH_INV,   MATH_DEL,  MATH_IDX,    MATH_SRT,     MATH_SIX,
  MATH_DIM,   
  MATH_CAT,   MATH_INI,   
#ifdef USETOK
  MATH_TIX,   MATH_TCX,
  MATH_TOK,   MATH_TLN,  MATH_SLN,
#endif /* USETOK */
  MATH_MAP,   MATH_UNMAP,
  MATH_RND,   MATH_LID,   MATH_TRC};  
#define MATH_LAST MATH_TRC  /*  update this if math_ops changes */  

enum mstack_ops {MSTK_NONE, MSTK_DPUSH, 
  MSTK_VPUSH, MSTK_VAPUSH, 
#ifdef USETOK
  MSTK_TOKZEROPUSH, MSTK_SAPUSH, 
#endif /* USETOK */
  MSTK_OPUSH,
  MSTK_PSH, MSTK_NPSH, MSTK_POP, MSTK_DONE}; 


typedef struct is_mstklist        MSLNEXUS;
typedef struct is_mstack          MASNEXUS;
typedef struct is_dval            DVNEXUS;
typedef struct is_stored_prog     SPNEXUS;
typedef struct is_sp_list         SPLNEXUS;
typedef struct is_estring         ESNEXUS;
typedef struct is_omni            OMNINEXUS;    /* DIFFERENT ONE THAN EXTRACT !*/
typedef struct is_string_struct   STRINGNEXUS;
struct is_string_struct { /* coordinates for start are 0->N-1.  slen of 0 is an empty string  */
   int  start;            /* start  of the substring in the buffer */
   int  slen;             /* length of the substring */
   char delimit;          /* 0 or the delimiter */
   };
#ifdef USETOK
typedef struct is_fmt             FMTNEXUS;    /* DIFFERENT ONE THAN EXTRACT !*/
struct is_fmt {
   int          fldcount;         /* here, 1 if it exists, 0 if not */
   STRINGNEXUS *toklist;          /* list of ISS entries (from input), these are dynamic
                                       and (usually) change with each line read.  If these
                                       are from -fmt or -v then the corresponding po (see below)
                                       determines how the input is parsed.  If they are in
                                       a SET variable then it is determined by assigning
                                       matched substrings. */
   int          tokcount;         /* number of iss entries in list (tokens) */
   int          tokalloc;         /* The initial number of entries in toklist.  For
                                     -fmt this is determined by the variable xc
                                    ("maX Columns", columns and tokens are synonymous in this
                                    context) and never changes.  For variables it starts at
                                    1 and is increased as needed. */
   ESNEXUS     *dat_str;          /* parsed -fmt string (still) holds dynamic strings fldlist
                                       references.  
                                       If this is -fmt it holds the current input string.
                                         All -fmt point to the same def_str storage area
                                         which they share.  This is the input buffer
                                       If this is -v* it holds RESULT of the definition of
                                         the variable, which is (optionally) parsed into tokens. 
                                         Each variable has its OWN def_str area.
                                  */
                                  /* length of the string INCLUDING terminator */
                                  /* size of the storage area (static for -fmt, dynamic for -v*)*/
   };
#endif /* USETOK */
struct is_stored_prog {
   char *name;                    /* name of program.       */
   char *prog;                    /* program                */
   char *rpnprog;                 /* rpn program            */
   int   slen;                    /* number of bytes in program (some may be 0, so not a regular string */
   };
struct is_sp_list {
   SPNEXUS *list;                 /* list of SPNEXUS entries       */
   int      slen;                 /* number in list                */
   int      salloc;               /* number allocated (not bytes!) */
   };
struct is_estring {
   char *string;                  /* Buffer that holds string        */
   int   slen;                    /* Length of data in buffer        */
   int   start;                   /* position (0->N-1 coords) to start search, used with MATCH_REMAINDER    */
   int   salloc;                  /* Allocated size of the buffer    */
   };
struct is_omni {
   DVNEXUS   *dvar;               /* Buffer that holds numeric variable structs      */
   DVNEXUS   *stk;                /* run stack */
   MSLNEXUS  *pstk;               /* prerun stack */
   double     result;             /* last result for a math expression       */
#ifdef USETOK
   FMTNEXUS **vn;                 /* var_array                               */
#endif /* USETOK */
   };
struct is_mstack {
   int    what;                   /* 0 = value, 1=addr, 2 = mop */
   double val;                    /* value          */
   enum   math_ops mop;           /* math operation */
   };
struct is_mstklist {
   MASNEXUS *list;
   int       slen;
   int       salloc;
  };
struct is_dval {
   double *val;                   /* value             */
   int     dlen;                  /* number of entries */
   int     dalloc;                /* number allocated  */
   };



/* function prototypes */
void        fmt_numeric_output(FILE *fp, int nz, int digits, int scieng, double value, double dlim);
void        fmt_numeric_output_array(FILE *fp, int nz, 
               int digits, int scieng, int idx, double value, double dlim);
double      numeric_input(const char *nptr, char **endptr);
static int  compare_da(const void *p1, const void *p2);
void        insane(const char *pre, const char *string);
void        insane2(const char *pre, const char *s1, const char *s2);
void        es_append_aidat(ESNEXUS *dst, char *src, int slen, int inc, char *fail);
void        es_append_addat(ESNEXUS *dst, char *src, int slen, int inc, char *fail);
void        es_append_dat(ESNEXUS *dst, char *src, int slen, int inc, char *fail);
void        es_clear(ESNEXUS *dst);
char       *dup_str(char *string, int length);
int         lstrcasecmp(char *s1, int len1, char *s2, int len2);

char       *categorize_operands(MASNEXUS *pstk,int psptr, enum math_ops *emop,
             int *shift, int *scroll, int *from, enum rpn_states *state);
int         mop_properties(enum math_ops *mop, int where, int upper, int lower,
              int *shift, int *scroll, int *from, enum rpn_states *state);
ESNEXUS    *compile_math(char *string, char **message);
char       *op_precedence(char *string, int *assign, char **message);
char       *pre_run_math(OMNINEXUS *omni, ESNEXUS *program, ESNEXUS *rpnprog);
int         realends(int *rstart, int *rend, int lstart, int lend, int length);
char       *run_math_rpn(OMNINEXUS *omni, char *program, double *result);
void        show_help(void);
void        show_hexp(void);
char       *show_math_op(enum math_ops mop);
char       *show_stk_op(enum mstack_ops sop);
char       *strtok_math(char *string, char *thedelim, int *start, int *length);
char       *wait_insane(const char *pre, const char *string);
char       *wait_insane2(const char *pre, const char *s1, const char *s2);
#ifdef USETOK
static int  compare_tcx(const void *p1, const void *p2);
static int  compare_tix(const void *p1, const void *p2);
#endif /* USETOK */
/* globals */
STRINGNEXUS *smuggle=NULL;  /* used to smuggle a toklist into the qsort, so that it can be sorted indirectly */
char *smuggle_str=NULL;  /* used to smuggle data into qsort for compare_dax, for indirect sort */

/* functions */
void es_clear(ESNEXUS *dst){
  if(!dst)insane(INSFTLPRGERR," es_clear applied to NULL ESNEXUS pointer");
  if(dst->salloc){ *(dst->string)='\0'; }  /* just in case, not really needed if slen is 0*/
  dst->slen=0;
}

/* case insensitive comparison for lstr, which
   are strings consisting of a pointer and a length
   but no 0 terminator.  For a match the lengths
   must be equal as well. If prefixes are identical
   the shorter string is lexically smaller than the longer. */
   
int lstrcasecmp(char *s1, int len1, char *s2, int len2){
int c1,c2;
int idx;
  for(idx=1; ;idx++){
    if(idx > len1){
      if(idx > len2){
        return  0;  /* identical, idx went past both at the same time */
      }
      else {
        return -1;  /* identical prefix but s1 is longer */
      }
    }
    else {
      if(idx > len2){
        return  1; /* identical prefix but s2 is longer */
      }
      else {
        c1=toupper(s1[idx-1]);
        c2=toupper(s2[idx-1]);
        if(c1 < c2)return -1;
        if(c1 > c2)return  1;
      }
    }
  }
}



void insane(const char *pre, const char *string){
 (void) fprintf(stderr,"%s%s\n",pre,string);
 exit(EXIT_FAILURE);
}

void insane2(const char *pre, const char *s1, const char *s2){
  (void) fprintf(stderr,"%s%s [%s]\n",pre,s1,s2);
  exit(EXIT_FAILURE);
}

/* Output in different numeric formats.  If the scieng value is unknown nothing happens. */
void fmt_numeric_output(FILE *fp, int nz, int digits, int scieng, double value, double dlim){
    uint32_t utmp;
    int32_t  stmp;
    if(scieng == OUT_FMT_SCI){
      if(value == -0.0 && !nz)
          { fprintf(stdout,"%.*e\n",digits,0.0);                 }
      else{ fprintf(stdout,"%.*e\n",digits,value);               }
    }
    else if(scieng == OUT_FMT_ENG){       
      if(value == -0.0 && !nz)
          { fprintf(stdout,"%.*f\n",digits,DBLPREC(value,dlim)); }
      else{ fprintf(stdout,"%.*f\n",digits,value);               }
    }
    else if(scieng & OUT_FMT_UNS){
       utmp = DBL2UINT32(value);
       if(     scieng & OUT_FMT_OCT){ fprintf(stdout,"%.*o\n",digits,utmp); }
       else if(scieng & OUT_FMT_DEC){ fprintf(stdout,"%.*u\n",digits,utmp); }
       else if(scieng & OUT_FMT_HEX){ fprintf(stdout,"%.*x\n",digits,utmp); }
    }
    else {
       stmp = DBL2INT32(value);
       if(scieng & OUT_FMT_DEC){ fprintf(stdout,"%.*d\n",digits,stmp); }
    }
}

/* Output array values in different numeric formats.  If the scieng value is unknown nothing happens. */
void fmt_numeric_output_array(FILE *fp, int nz, int digits, int scieng, int idx, double value, double dlim){
    uint32_t utmp;
    int32_t  stmp;
    if(scieng == OUT_FMT_SCI){  fprintf(stdout,"%4d %.*e\n",idx,digits,value); }
    else if(scieng == OUT_FMT_ENG){       
      if(nz){    fprintf(stdout,"%4d %.*f\n",idx,digits,value);               }
      else{      fprintf(stdout,"%4d %.*f\n",idx,digits,DBLPREC(value,dlim)); }
    }
    else if(scieng & OUT_FMT_UNS){
       utmp = DBL2UINT32(value);
       if(     scieng & OUT_FMT_OCT){ fprintf(stdout,"%4d %.*o\n",idx,digits,utmp); }
       else if(scieng & OUT_FMT_DEC){ fprintf(stdout,"%4d %.*u\n",idx,digits,utmp); }
       else if(scieng & OUT_FMT_HEX){ fprintf(stdout,"%4d %.*x\n",idx,digits,utmp); }
    }
    else {
       stmp = DBL2INT32(value);
       if(scieng & OUT_FMT_DEC){ fprintf(stdout,"%4d %.*d\n",idx,digits,stmp); }
    }
}

/* See above for comparison of es_strcat, es_append_str, es_append_dat */
void es_append_dat(ESNEXUS *dst, char *src, int slen, int inc, char *fail){
  EXT_REALLOC2(dst->string, dst->salloc, (dst->slen + slen),
   (dst->salloc + (inc*(1+((slen - 1) % inc)))),1,fail);
  memcpy(&(dst->string[dst->slen]),src,slen);
  dst->slen += slen;
}  
/* See above for comparison of es_strcat, es_append_str, es_append_dat */
void es_append_aidat(ESNEXUS *dst, char *src, int slen, int inc, char *fail){
#ifdef CHKALN
  if(!slen){
    insane(INSFTLPRGERR," es_append_aidat, zero size storage");
  }
  if(dst->slen % SOI){
    insane(INSFTLPRGERR," es_append_aidat, unaligned data storage");
  }
#endif /* CHKALN*/
  EXT_REALLOC2(dst->string, dst->salloc, (dst->slen + slen),
   (dst->salloc + slen + inc + NEXTINTREMAINDER(slen + inc)),1,fail);
  memcpy(&(dst->string[dst->slen]),src,slen);
  dst->slen += slen;
}

/* See above for comparison of es_strcat, es_append_str, es_append_dat */
void es_append_addat(ESNEXUS *dst, char *src, int slen, int inc, char *fail){
#ifdef CHKALN
  if(!slen){
    insane(INSFTLPRGERR," es_append_aidat, zero size storage");
  }
  if(dst->slen % SOD){
    insane(INSFTLPRGERR," es_append_aidat, unaligned data storage");
  }
#endif /* CHKALN*/
  EXT_REALLOC2(dst->string, dst->salloc, (dst->slen + slen),
   (dst->salloc + slen + inc + NEXTDBLREMAINDER(slen + inc)),1,fail);
  memcpy(&(dst->string[dst->slen]),src,slen);
  dst->slen += slen;
}


/* this duplicates strings even if they are not terminated.
It can also be used to place a smaller string into a larger buffer by
specifing a length longer than 1+strlen(stirng) */
char *dup_str(char *string, int length){
char *tmp;
char *ptr;
int i;
     EXT_MALLOC(tmp,length+1,MEMOOPS);
     for(ptr=tmp, i=0; *string && i<length; i++,ptr++,string++){
       *ptr=*string;
     }
     *ptr='\0';
     return(tmp);
}

/* realends() converts from relative [lstart,lend] format to C offset (starting at 0)
rstart,rend format.  This routine traps only one kind of error - start or lend = 0
Returns the number of cells in the range. 

Return status:

 >0 specifies a range that fits entirely in 0<->Length - 1.  The number is the number
    of items in the range.
  0 specifies a range that extends outside of 0<->Length-1 or is empty (that is,
      references tokens that do not exist).  Examples [4,-4],[100,104],[-50,-40] on a short array,
      This includes empty input strings, which by necessity "miss" on all ranges.
 -1 invalid range, like [5,3] or [*,0], [0,*]
*/


int realends(int *rstart, int *rend, int lstart, int lend, int length){
int status;

  if(lend == 0 || lstart == 0){
    status = -1;
  }
  else {
    *rend=0;
    *rstart=0;
    if(length > 0){
      if(lend>0){                                   /* absolute column, from front  */
        *rend = lend - 1;                           /* 1->0, now in C offset format */
      }
      else if(lend <0){                             /* relative column from end     */
        *rend = length + lend;                      /* 1->0, now in C offset format */
      }
      if(lstart>0){                                 /* absolute column, from front  */
        *rstart = lstart - 1;                       /* 1->0, now in C offset format */
      }
      else if(lstart < 0){                          /* relative column, from end    */
        *rstart = length + lstart;                  /* 1->0, now in C offset format */
      }
      status=*rend - *rstart + 1;
      if(status<0){
        if(lstart>0 && lend>0){      status=-1; }/* [3,2] always bogus */
        else if(lstart<0 && lend<0){ status=-1; } /* [-3,-4] always bogus */
        else {                       status=0;  }  /* [3,-1] should not be an error on short lines */
      }
      if(*rend > length -1 || *rstart<0){status = 0; }
    }
    else {  
      /* try to handle this, if at all possible.  Indices are meaningless on an empty string.  However,
         some of the external programs may want to fill in with "No value".  So if it is possible to
         figure out the size of the range convert it to (start-start,end-start) and set an error status.
         Also catch those ranges that could never be valid.  Punt on cases where it isn't possible to figure
         out the range size.
      */
      if(lstart > 0 && lend > 0){      *rstart = 0; *rend = lend - lstart; }
      else if(lstart < 0 && lend < 0){ *rstart = 0; *rend = lend - lstart; }
      else {                           *rstart = 0; *rend = 0;             } /* hopeless, set both to 0*/
      status=*rend - *rstart + 1;
      if(status < 0){
        if(lstart>0 && lend>0){      status=-1; } /* [3,2] always bogus */
        else if(lstart<0 && lend<0){ status=-1; } /* [-3,-4] always bogus */
        else {                       status=0;  } /* well, [3,-1] should not be an error on short lines */
      }
      else { status = 0; }
    }
  }
  return(status);
}

char *wait_insane(const char *pre, const char *string){
char *message;
  EXT_MALLOC(message,strlen(pre)+strlen(string)+1,MEMOOPS);
  (void) sprintf(message,"%s%s",pre,string);
  return(message);
}
char *wait_insane2(const char *pre, const char *s1, const char *s2){
char *message;
  EXT_MALLOC(message,strlen(pre)+strlen(s1)+strlen(s2)+4,MEMOOPS);
  (void) sprintf(message,"%s%s [%s]",pre,s1,s2);
  return(message);
}

/* convert a string to a double.  Handles the following syntaxes:
   123.4
   124.4e-01
   0x12  (hex)
   0o15  (octal)
   0b0101(binary)
   The hex,octal, and binary values are unsigned 32 bit ints.
*/
double numeric_input(const char *nptr, char **endptr){
  uint32_t utmp;
  double   dtmp;
  char     base;
  if(nptr[0]=='0'){
    base = toupper(nptr[1]);
    if(base=='X'){      utmp = strtol(&nptr[2],endptr,16); dtmp=utmp; }
    else if(base=='O'){ utmp = strtol(&nptr[2],endptr,8);  dtmp=utmp; }
    else if(base=='B'){ utmp = strtol(&nptr[2],endptr,2);  dtmp=utmp; }
    else {              dtmp = strtod(nptr,endptr);        }
  }
  else {                dtmp = strtod(nptr,endptr);        }
  return(dtmp);
}

/* conventional ascending numeric on doubles*/
static int  compare_da(const void *p1, const void *p2){
int result;
double d1,d2;
  d1    = *((double*) p1);     
  d2    = *((double*) p2);     
  if(d1<d2){ result = -1; }
  else if(d1>d2){ result =  1; }
  else {result = 0; }
  return(result);
}

/* ascending numeric on doubles, indirect, keeping indices in array being sorted */
static int  compare_dax(const void *p1, const void *p2){
int result;
unsigned int u1,u2;
double d1,d2;
  u1    = *((double*) p1);     
  u2    = *((double*) p2);     
  d1   = ((double *)smuggle_str)[u1];              
  d2   = ((double *)smuggle_str)[u2];              
  if(d1<d2){ result = -1; }
  else if(d1>d2){ result =  1; }
  else {result = 0; }
  return(result);
}

#ifdef USETOK
/* Sort tokens in a string variable indirectly.  The positions are what is actually sorted, in a double
array.  Hopefully the compiler will optimize most of this away, but it is easier to read this way. */
static int  compare_tix(const void *p1, const void *p2){
int result;
unsigned int u1,u2,len1,len2,r1,r2;
STRINGNEXUS *sn1;
STRINGNEXUS *sn2;
char *str1;
char *str2;
  u1    = *((double*) p1);     
  u2    = *((double*) p2);     
  sn1  = &smuggle[u1];
  sn2  = &smuggle[u2];
  str1 = ((ESNEXUS *)smuggle_str)->string;
  str2 = ((ESNEXUS *)smuggle_str)->string;
  len1 = sn1->slen;
  len2 = sn2->slen;
  r1   = sn1->start;
  r2   = sn2->start;
  if(len1<len2){
    result = strncmp(&str1[r1], &str2[r2], len1);
    if(!result)result=-1;  /* shorter one collates before longer one */
  }
  else if(len1>len2){
    result = strncmp(&str1[r1], &str2[r2], len2);
    if(!result)result=1;  /* longer one collates after shorter one */
  }
  else {
    result = strncmp(&str1[r1], &str2[r2], len1);
  }
  return(result);
}

/* Sort tokens in a string variable indirectly, case invariant.  The positions are what is actually sorted, in a double
array.  Hopefully the compiler will optimize most of this away, but it is easier to read this way. */
static int  compare_tcx(const void *p1, const void *p2){
int result;
unsigned int u1,u2,len1,len2,r1,r2;
STRINGNEXUS *sn1;
STRINGNEXUS *sn2;
char *str1;
char *str2;
  u1    = *((double*) p1);     
  u2    = *((double*) p2);     
  sn1  = &smuggle[u1];
  sn2  = &smuggle[u2];
  str1 = ((ESNEXUS *)smuggle_str)->string;
  str2 = ((ESNEXUS *)smuggle_str)->string;
  len1 = sn1->slen;
  len2 = sn2->slen;
  r1   = sn1->start;
  r2   = sn2->start;
  if(len1<len2){
    result = lstrcasecmp(&str1[r1], len1, &str2[r2], len1);
    if(!result)result=-1;  /* shorter one collates before longer one */
  }
  else if(len1>len2){
    result = lstrcasecmp(&str1[r1], len2, &str2[r2], len2);
    if(!result)result=1;  /* longer one collates after shorter one */
  }
  else {
    result = lstrcasecmp(&str1[r1], len1, &str2[r2], len1);
  }
  return(result);
}
#endif /* USETOK */


/* strtok replacement specifically for this calculator/math parsing.  Delimits
conditionally on +-* /%^().  Detects unary - and restores the "-" symbol, but does
not use that as a token delimiter. Detects +- used in exponents and does NOT consider that a delimiter.
Detects $e+/- as a variable and does delimit there.  Start is updated
before return so that next call starts after the present token (must be set to 0
at start).  Does NOT use NULL for string in repeat calls.  length is the token
length. negate is set if a delimiter is followed by @, indicating that the
negative form of the operator should be used */
char  *strtok_math(char *string, char *thedelim, int *start, int *length){
int   from = *start;
int   ok   = 1;
int   spec = 0;
char  *result=NULL;
   while(ok){
     switch (string[from]){
       case '\0':
          result   = NULL; 
         *thedelim = '\0';
         *length   = 0;
         *start    = from; /* leave *start on the terminator */
         ok=0;
         break;
       case '+':
       case '-':
         if(spec)break; /* in an exponent probably, so NOT a delimiter */
         /* falls through intentionally! */
       case '=':
       case '*':
       case '/':
       case '^':
       case '%':
       case '?':
       case '@':
       case '(':
       case ')':
       case ',':
          result   = &string[*start];
         *thedelim = string[from];
         *length   = from - *start;
         *start    = from+1;
         ok = 0;
         break;
       case 'e':
       case 'E':
         if(spec) { spec=0; } /* $e */
         else {     spec=1; } /* exponent? e+/-### ? */
         break;
       case '$':  /* numeric variable */
         from++;  /* mask the next character because $- is valid but - is normally a delimiter*/
         break;
       case A_UNARY_NEG:
         string[from]='-';
         break;
       default:
         spec = 0;
     }
     from++;
   }
   return(result);
}

/* remove all spaces and then add parentheses to implement operator precedence.
This also replaces unary negative with \1, delete unary +, so there is no confusion
with respect to regular sub and add.  In other unary cases like (/+-*%^?)-5 the first 
( following the operator is replaced by a @, which is basically "-(".

If there is an assignment (=) tell the caller, because the meaning of 
$letter and $(letter)[] 
differ on one side or the other.

on error message holds a pointer to the error message, otherwise null

precedence table (precedence == number of parens on each side):
  op     precedence  symmetric?
  START  8           N (all open parens)
  value  0           - (no parens added)
  ^      1           Y
  /%*    2           Y
  +-     3           Y
  ?      4           Y
  ,      5           Y
  []()   6           N (parens added one side only)
  =      7           Y
  END    8           N (all close parens)
*/

char *op_precedence(char *string, int *assign, char **message){
char *from;
char *to;
char *result;
int   nu;
int   var=0;
char  last=' '; /* space is safe, it cannot match because all are stripped */
int   ocount=0;

  *message=NULL;

  /* strip all white spaces */
  for(from=to=string; ; from++){
    if(*from==' ')continue;
    if(*from=='\n')continue;
    if(*from=='\t')continue;
    *to = *from;
    to++;
    if(!*from)break;
  }
  if(!strlen(string)){
    *message=wait_insane(INSFTLERR," empty operation string - nothing to do");
    return(NULL);
  } 

  /* ADJUST THIS IF PRECEDENCES CHANGE!!!! worst case memory requirement */
  EXT_MALLOC(result,strlen(string)*19,MEMOOPS);

  /* insert parenthesis */
  *assign=0;
  to   = result;
  from = string;
                    strcpy(to,"((((((((");     to+=8;
  if(*from=='-' && !strchr("0123456789.",*(from+2))){ 
     /* unary negative on a variable,function, or left paren at the very
        start of the program.  Handle it here. */
                    strcpy(--to,"@");        to+=1;           from++;}
  for(; *from && !*message; from++){
    if(*(from+1) == '-'){ nu = 1; }
    else {                nu = 0; }
    switch(*from){
        /* listed in order of high -> low precedence */                                  
        case '^': 
          if(nu){   strcpy(to,")^@");       to+=3; ocount++; from++; break; }
          else{     strcpy(to,")^(");       to+=3; ocount++;         break; }
        case '%': 
          if(nu){   strcpy(to,"))%@(");     to+=5; ocount++; from++; break; }
          else{     strcpy(to,"))%((");     to+=5; ocount++;         break; }
        case '*': 
          if(nu){   strcpy(to,"))*@(");     to+=5; ocount++; from++; break; }
          else{     strcpy(to,"))*((");     to+=5; ocount++;         break; }
        case '/': 
          if(nu){   strcpy(to,"))/@(");     to+=5; ocount++; from++; break; }
          else{     strcpy(to,"))/((");     to+=5; ocount++;         break; }
        case '+':                                      
          if(!var && last=='E'){  /* unary + as part of an exponent, ignore it */
            var=0;                     last=' ';   ocount=0;      continue; }
          if(        strchr(",([",last)){  /* unary + following ([ or comma ignore it */
                                       last=' ';   ocount=0;      continue; }
          else if(ocount==1) {         last=' ';   ocount++;      continue; }/* unary + following another operator, ignore it */
          else if(from==string) {      last=' ';   ocount++;      continue; }/* unary + at start, ignore it */
          else {
            if(nu){ strcpy(to,")))+@((");   to+=7; ocount++;  from++; }                       
            else{   strcpy(to,")))+(((");   to+=7; ocount++;          }
          }                      
          break;                                  
        case '-':
          if(last=='$'){ /* $-, pseudo variable, last result */
            var=1;
                    strncpy(to,from,1);      to+=1; *to='\0'; ocount=0; nu=0; 
          }
          else if((!var && last=='E') || (from==string)){  
             var=0; strcpy(to,S_U_NEG);     to+=1; ocount=10;}                              
          else if(   (strchr(",([",last) || from==string)){  
                    strcpy(to,S_U_NEG);     to+=1; ocount=10;}                              
          else{
            if(nu){ strcpy(to,")))-@((");   to+=7; ocount++;  from++; }                       
            else{   strcpy(to,")))-(((");   to+=7; ocount++;          }
          }                       
          break;                                  
        case '?': 
          if(nu){   strcpy(to,"))))?@((("); to+=9; ocount++; from++; break; }
          else{     strcpy(to,"))))?(((("); to+=9; ocount++;         break; }
        case ',':
          nu=0; 
          if(ocount==10){ 
            *message=wait_insane2(INSFTLERR," no unary operations on ,:",string);
          }
          else {
            if(*(from+1)=='-' && !strchr("0123456789.",*(from+2))){ 
              /* another unary negative on a variable,function, or left paren. Handle it here. */
                      strcpy(to,"))))),@");   to+=7; ocount=0; from++;}
            else{     strcpy(to,"))))),(");   to+=7; ocount=0;        }
          }
          /* now the remainder of the left parens */
                    strcpy(to,"((((");      to+=4;                   break;
        case '[':
          if(!var){                                ocount=2;         break; }
          else if(*(from+1)==']'){  /* $N[], this is the address of array N */
            /* rewrite the v or $ as a ] and eat the [] characters. */
#ifdef USETOK
                   if(*(to-2)=='$'){ *(to-2)=']';}
                   else {            *(to-2)='}';}
#else  /* USETOK */
                   *(to-2)=']';
#endif /* USETOK */
                   /* fill the empty [] with the implicit full range [1,-1] */
                   strcpy(to,"(1,@1))"); to+=7; /* @is MATH_NNONE, acts like a left paren */
                                 var = 0;          ocount=0; from++; break; }
         
          else {
            /* rewrite the v or $ as a [, for the rest this is just like a '('
               so fall through into the next case. */
#ifdef USETOK
                   if(*(to-2)=='$'){ *(to-2)='[';}
                   else {            *(to-2)='{';}
#else  /* USETOK */
                   *(to-2)='[';
#endif /* USETOK */
                                                   ocount=0;
          }
        case '(':
          nu=0; 
          if(ocount==10 && (*(to-1)==A_UNARY_NEG)){
                    to--; /* backtrack and overwrite the preceding unary negative */
                    strcpy(to,"@");         to+=1; ocount=0;}
          else {    strcpy(to,"(");         to+=1; ocount=0;}
          if(*(from+1)=='-' && !strchr("0123456789.",*(from+2))){ 
            /* another unary negative on a variable,function, or left paren. Handle it here. */
                    strcpy(to,"@");         to+=1;           from++;}
          else {    strcpy(to,"(");         to+=1;                  }
          /* now the remainder of the left parens */
                    strcpy(to,"((((");      to+=4;                   break;
        case ']':
        case ')':
          nu=0; 
          if(ocount==10){ 
              *message=wait_insane2(INSFTLERR," no unary operations on ():",string);
          }
          else {                
                    strcpy(to,"))))))");    to+=6; ocount=0;
          }
          break;
        case '=': /* assignment*/
          if(*assign){
            *message=wait_insane2(INSFTLERR," invalid math syntax, multiple = symbols:",string);
          }
          else {
            (*assign)=1;
             
            if(nu){ strcpy(to,")))))))=@(((((("); to+=15; ocount=0; from++; }                       
            else{   strcpy(to,")))))))=((((((("); to+=15; ocount=0;         }
          }
          break;
        default:    
          if(last=='$'){  var=1; }
#ifdef USETOK
          else if( ISVAROFF(TOVAROFF(*from)) && 
                 !(ISVAROFF(TOVAROFF(last))    || 
                   ISVAROFF(TOVAROFF(from[1])) ||
                   isdigit((int)last)               ||
                   isdigit((int)from[1])
                  )  /* string variable is an isolated single letter like a+, not d2r( though!*/
                 ){       var=1;
                    strncpy(to,S_SVAR,1);    to++;  *to='\0';
                  }
#endif /* USETOK */
          else {          var=0; }
                    strncpy(to,from,1);      to+=1; *to='\0'; ocount=0; nu=0; 
    }
    if(ocount ==2 ){
      *message=wait_insane2(INSFTLERR," invalid math syntax, multiple operators?:",string);
    }
    last = toupper(*from);                                                 
  }
                     strcpy(to,"))))))))");    to+=8;
  *to='\0';
  return(result);
}

ESNEXUS *compile_math(char *string, char **message){
char    *atoken;
char     thedelim;
char    *to;
char    *string2;
int      start,length;
int      itmp;
double   dtmp;
char     mop;
char     sop='\0';
int      act=IS_OP_START; 
int      tact=0;
ESNEXUS *program;
int      pcount=0;
char    *ct;
int      assign;
int      eqtype=0; /* = can translate into more than one kind of operator */

  *message=NULL;

  EXT_CALLOC(program,sizeof(ESNEXUS),1,MEMOOPS);

  /* add (more) parens for operator precedence, this is essentially from the wikipedia
     article on operator precedence.  Also strips spaces and EOL (if present).
  */
  string2 = op_precedence(string,&assign,message);
  if(*message){
    if(string2)free(string2);
    return(program);
  }
  
  /* parse the math operations */
  start = 0;
  atoken=strtok_math(string2, &thedelim, &start, &length);
  while(atoken && !*message){
//fprintf(stdout,"DEBUG pc %d atoken <%s> atoken delim <%c> length %d\n",pcount,atoken,thedelim,length);fflush(stdout);
    if(length){
      if(! (act & MASK_OPERAND_OK)){
        *message=wait_insane2(INSFTLERR," variable, literal, or function out of order",string);
      }
      if(*atoken =='$'){  /* variable */
        act = IS_VVAR;
//fprintf(stdout,"DEBUG var part %d %c\n",atoken[1],atoken[1]);
        itmp=TOVAROFF(atoken[1]);
//fprintf(stdout,"DEBUG itmp %d\n",itmp);
        if(length !=2 || itmp < 0 || itmp > MYVARSMAX){
          *message=wait_insane2(INSFTLERR," invalid variable syntax in math expression:",string);
        }
        else {
          if(assign){ 
            if(itmp==MYVARSMAX){
             *message=wait_insane2(INSFTLERR," cannot use $- to the left of an assignment (=):",string);
            }
            else {
              assign = 0; /* subsequent uses ok, like $a[$i] */
              eqtype = MATH_SV_ZERO; /* hold this until the "=" shows up */
              sop=MSTK_VAPUSH;
            }
          }
          else {
            sop=MSTK_VPUSH;
          }
          es_append_dat(program, (char *) &sop,sizeof(sop),MATHINC,MEMOOPS);
          ESP_NEXTINTBOUNDARY(program);
          es_append_aidat(program, (char *) &itmp,SOI,MATHINC,MEMOOPS);
        }
      }
      else if(*atoken =='['){  /* numeric variable[], push variable address (0-26) */
        act = IS_VARRAY;
        itmp=TOVAROFF(atoken[1]);
        if(length !=2 || ISNOTVAROFF(itmp)){
          *message=wait_insane2(INSFTLERR," invalid variable syntax in math expression:",string);
        }
        else {
          sop=MSTK_VAPUSH;
          es_append_dat(program, (char *) &sop,sizeof(sop),MATHINC,MEMOOPS);
          ESP_NEXTINTBOUNDARY(program);
          es_append_aidat(program, (char *) &itmp,SOI,MATHINC,MEMOOPS);
          if(assign){
            assign = 0;
            eqtype = MATH_SV_ELEM; /* hold this until the "=" shows up */
          }
          else {     
            /* load, so follow it immediately with MATH_LD_ELEM */
            sop = MSTK_OPUSH;
            mop = MATH_LD_ELEM; 
            es_append_dat(program, &sop, 1,MATHINC,MEMOOPS);
            es_append_dat(program, &mop, 1,MATHINC,MEMOOPS);
          }
        }
      }
      else if(*atoken ==']'){  /* numeric variable[], push variable address (0-26) only*/
        act = IS_VARRAY;
        itmp=TOVAROFF(atoken[1]);
        if(length !=2 || ISNOTVAROFF(itmp)){
          *message=wait_insane2(INSFTLERR," invalid variable syntax in math expression:",string);
        }
        else {
          if(assign){
            assign = 0;
            eqtype = MATH_SV_ELEM; /* hold this until the "=" shows up */
          }
          sop=MSTK_VAPUSH;
          es_append_dat(program, (char *) &sop,sizeof(sop),MATHINC,MEMOOPS);
          ESP_NEXTINTBOUNDARY(program);
          es_append_aidat(program, (char *) &itmp,SOI,MATHINC,MEMOOPS);
        }
      }
#ifdef USETOK
      else if(*atoken ==A_STRINGVAR){  /* string variable */
        act = IS_VVAR;
        itmp=TOVAROFF(atoken[1]);
        if(length !=2 || ISNOTVAROFF(itmp)){
          *message=wait_insane2(INSFTLERR," invalid variable syntax in math expression:",string);
        }
        else {
          if(assign){  
            *message=wait_insane2(INSFTLERR," illegal to assign to string variable in math expression:",string);
          }
          else {
            sop=MSTK_TOKZEROPUSH;
            es_append_dat(program, (char *) &sop,sizeof(sop),MATHINC,MEMOOPS);
            ESP_NEXTINTBOUNDARY(program);
            es_append_aidat(program, (char *) &itmp,SOI,MATHINC,MEMOOPS);
          }
        }
      }
      else if(*atoken =='{'){  /* string variable[], push variable address (0-26) */
        act = IS_VARRAY;
        itmp=TOVAROFF(atoken[1]);
        if(length !=2 || ISNOTVAROFF(itmp)){
          *message=wait_insane2(INSFTLERR," invalid variable syntax in math expression:",string);
        }
        else {
          sop=MSTK_SAPUSH;
          es_append_dat(program, (char *) &sop,sizeof(sop),MATHINC,MEMOOPS);
          ESP_NEXTINTBOUNDARY(program);
          es_append_aidat(program, (char *) &itmp,SOI,MATHINC,MEMOOPS);
          if(assign){
            *message=wait_insane2(INSFTLERR," invalid variable syntax in math expression:",string);
          }
          else {     
            /* load, so follow it immediately with MATH_LD_TOKEN */
            sop = MSTK_OPUSH;
            mop = MATH_LD_TOKEN; 
            es_append_dat(program, &sop, 1,MATHINC,MEMOOPS);
            es_append_dat(program, &mop, 1,MATHINC,MEMOOPS);
          }
        }
      }
      else if(*atoken =='}'){  /* string variable[], push variable address (0-26) only*/
        act = IS_VARRAY;
        itmp=TOVAROFF(atoken[1]);
        if(length !=2 || ISNOTVAROFF(itmp)){
          *message=wait_insane2(INSFTLERR," invalid variable syntax in math expression:",string);
        }
        else {
          if(assign){
            *message=wait_insane2(INSFTLERR," invalid variable syntax in math expression:",string);
          }
          else{
            sop=MSTK_SAPUSH;
            es_append_dat(program, (char *) &sop,sizeof(sop),MATHINC,MEMOOPS);
            ESP_NEXTINTBOUNDARY(program);
            es_append_aidat(program, (char *) &itmp,SOI,MATHINC,MEMOOPS);
          }
        }
      }
#endif /* USETOK */
      else if(strchr("0123456789.-+",*atoken)){ /* number*/
        act = IS_VLIT;
        ct = dup_str(atoken,length);
        dtmp=numeric_input(ct,&to);
        if(!to || *to != '\0'){
          *message=wait_insane2(INSFTLERR," incorrect number syntax",atoken);\
        }
        else {
          sop=MSTK_DPUSH;
          es_append_dat(program, &sop, 1, MATHINC,MEMOOPS);
          ESP_NEXTDBLBOUNDARY(program);
          es_append_addat(program, (char *) &dtmp, SOD,MATHINC,MEMOOPS);
        }
        free(ct);
      }
      else { /* functions go here*/
        act = IS_VFUNC;
        sop = MSTK_OPUSH;
        if(     !lstrcasecmp("log",  3,atoken,length)){  mop = MATH_LOG; }
        else if(!lstrcasecmp("ln",   2,atoken,length)){  mop = MATH_LN;  }
        else if(!lstrcasecmp("e10",  3,atoken,length)){  mop = MATH_E10; }
        else if(!lstrcasecmp("ee",   2,atoken,length)){  mop = MATH_EE;  }
        else if(!lstrcasecmp("chs",  3,atoken,length)){  mop = MATH_CHS; }
        else if(!lstrcasecmp("abs",  3,atoken,length)){  mop = MATH_ABS; }
        else if(!lstrcasecmp("sin",  3,atoken,length)){  mop = MATH_SIN; }
        else if(!lstrcasecmp("cos",  3,atoken,length)){  mop = MATH_COS; }
        else if(!lstrcasecmp("tan",  3,atoken,length)){  mop = MATH_TAN; }
        else if(!lstrcasecmp("asin", 4,atoken,length)){  mop = MATH_ASIN;}
        else if(!lstrcasecmp("acos", 4,atoken,length)){  mop = MATH_ACOS;}
        else if(!lstrcasecmp("atan", 4,atoken,length)){  mop = MATH_ATAN;}
        else if(!lstrcasecmp("sinh", 4,atoken,length)){  mop = MATH_SINH;}
        else if(!lstrcasecmp("cosh", 4,atoken,length)){  mop = MATH_COSH;}
        else if(!lstrcasecmp("tanh", 4,atoken,length)){  mop = MATH_TANH;}
        else if(!lstrcasecmp("d2r",  3,atoken,length)){  mop = MATH_D2R; }
        else if(!lstrcasecmp("r2d",  3,atoken,length)){  mop = MATH_R2D; }
        else if(!lstrcasecmp("not",  3,atoken,length)){  mop = MATH_BITNOT; }
        else if(!lstrcasecmp("max",  3,atoken,length)){  mop = MATH_MAX;    }
        else if(!lstrcasecmp("min",  3,atoken,length)){  mop = MATH_MIN;    }
        else if(!lstrcasecmp("and",  3,atoken,length)){  mop = MATH_BITAND; }
        else if(!lstrcasecmp("or",   2,atoken,length)){  mop = MATH_BITOR;  }
        else if(!lstrcasecmp("xor",  3,atoken,length)){  mop = MATH_BITXOR; }
        else if(!lstrcasecmp("shl",  3,atoken,length)){  mop = MATH_BITSHL; }
        else if(!lstrcasecmp("shr",  3,atoken,length)){  mop = MATH_BITSHR; }
        else if(!lstrcasecmp("len",  3,atoken,length)){  mop = MATH_DLEN; }
        else if(!lstrcasecmp("sum",  3,atoken,length)){  mop = MATH_SUM; }
        else if(!lstrcasecmp("inv",  3,atoken,length)){  mop = MATH_INV; }
        else if(!lstrcasecmp("del",  3,atoken,length)){  mop = MATH_DEL; }
        else if(!lstrcasecmp("idx",  3,atoken,length)){  mop = MATH_IDX; }
        else if(!lstrcasecmp("srt",  3,atoken,length)){  mop = MATH_SRT; }
        else if(!lstrcasecmp("six",  3,atoken,length)){  mop = MATH_SIX; }
        else if(!lstrcasecmp("sm2",  3,atoken,length)){  mop = MATH_SM2; }
        else if(!lstrcasecmp("nml",  3,atoken,length)){  mop = MATH_NML; }
        else if(!lstrcasecmp("dim",  3,atoken,length)){  mop = MATH_DIM; }
        else if(!lstrcasecmp("cat",  3,atoken,length)){  mop = MATH_CAT; }
        else if(!lstrcasecmp("ini",  3,atoken,length)){  mop = MATH_INI; }
#ifdef USETOK
        else if(!lstrcasecmp("tix",  3,atoken,length)){  mop = MATH_TIX; }
        else if(!lstrcasecmp("tcx",  3,atoken,length)){  mop = MATH_TCX; }
        else if(!lstrcasecmp("tok",  3,atoken,length)){  mop = MATH_TOK; }
        else if(!lstrcasecmp("tln",  3,atoken,length)){  mop = MATH_TLN; }
        else if(!lstrcasecmp("sln",  3,atoken,length)){  mop = MATH_SLN; }
#endif /* USETOK */
        else if(!lstrcasecmp("map",  3,atoken,length)){  mop = MATH_MAP; }
        else if(!lstrcasecmp("ump",  3,atoken,length)){  mop = MATH_UNMAP; }
        else if(!lstrcasecmp("rnd",  3,atoken,length)){  mop = MATH_RND; }
        else if(!lstrcasecmp("lid",  3,atoken,length)){  mop = MATH_LID; }
        else if(!lstrcasecmp("trc",  3,atoken,length)){  mop = MATH_TRC; }
        else {
          *message=wait_insane2(INSFTLERR," unknown math function in:",string);
        }
        if(thedelim != '('){
          *message=wait_insane2(INSFTLERR," math function not followed by parenthesis: ",atoken);\
        }
        else {
          es_append_dat(program, &sop, 1,MATHINC,MEMOOPS);
          es_append_dat(program, &mop, 1,MATHINC,MEMOOPS);
        }
      }
    }
    else { 
      /* nested parens and such, do nothing */
    }
    tact = 0;
    switch(thedelim){
        case '=':
          if(!eqtype){
            *message=wait_insane2(INSFTLERR," nothing left of = that may be assigned to: ",atoken);\
          }  
          else {
            tact   = IS_OP_TRUE; 
            mop    = eqtype;
            assign = 0 ; /* right of the assignment, there can only be one */
          }
          break;     
        case '+':  tact=IS_OP_TRUE; mop=MATH_ADD; break;     
        case '-':  tact=IS_OP_TRUE; mop=MATH_SUB; break;  
        case '*':  tact=IS_OP_TRUE; mop=MATH_MUL; break;  
        case '/':  tact=IS_OP_TRUE; mop=MATH_DIV; break;  
        case '%':  tact=IS_OP_TRUE; mop=MATH_MOD; break;  
        case '^':  tact=IS_OP_TRUE; mop=MATH_POW; break;  
        case '?':  tact=IS_OP_TRUE; mop=MATH_CMP; break;  
        case '(':  tact=IS_OP_PL;   pcount++;     break; 
        case '@':  tact=IS_OP_NPL;  pcount++;     break; 
        case ')':  tact=IS_OP_PR;   pcount--;     break; 
        case ',':  tact=IS_OP_CMA;                break; 
        case '\0': tact=IS_OP_DONE;               break;      
        default:
          *message=wait_insane2(INSFTLERR," incorrect operator syntax",string);
    }
    if(*message)break;
    if(tact & IS_OP_TRUE){
      if(! (act & MASK_OPERATOR_OK)){
        *message=wait_insane2(INSFTLERR," operator out of order",string);
      }
      else {
        sop  = MSTK_OPUSH;
        es_append_dat(program, &sop, 1, MATHINC,MEMOOPS);         
        es_append_dat(program, &mop, 1, MATHINC,MEMOOPS);         
      }
    }
    else if(tact & IS_OP_PL) {
      if(! (act & MASK_PL_OK)){
        *message=wait_insane2(INSFTLERR," illegal unary operator on function or ( parenthesis out of order",string);
      }
      else {
        sop=MSTK_PSH;
        es_append_dat(program, &sop, 1 ,MATHINC,MEMOOPS);
      }
    }
    else if(tact & IS_OP_NPL) {
      if(! (act & MASK_PL_OK)){
        *message=wait_insane2(INSFTLERR," illegal unary operator on function or illegal syntax",string);
      }
      else {
        sop=MSTK_NPSH;
        es_append_dat(program, &sop, 1 ,MATHINC,MEMOOPS);
      }
    }
    else if(tact & IS_OP_PR) {
      if(! (act & MASK_PR_OK)){
        *message=wait_insane2(INSFTLERR," illegal syntax",string);
      }
      else {
        sop=MSTK_POP;
        es_append_dat(program, &sop, 1, MATHINC,MEMOOPS);
      }
    }
    else if(tact & IS_OP_CMA) {  /* commas are just spacers, they do not turn into operators */
      if(! (act & MASK_CMA_OK)){
        *message=wait_insane2(INSFTLERR," comma out of order",string);
      }
    }
    else if(tact & IS_OP_DONE) { /* if program ends with variable or constant loop exits here */
      break;
    }
    if(tact){ act  = tact; }

    atoken=strtok_math(string2, &thedelim, &start, &length);
  }
  sop=MSTK_DONE;
  es_append_dat(program, &sop, 1, MATHINC,MEMOOPS);
  if(!*message && pcount){ 
    *message=wait_insane2(INSFTLERR," mismatched parentheses:", string);
  }
  free(string2);
  return(program);
}

/* used for debugging only */
char *show_math_op(enum math_ops mop){
char *string;
  switch(mop){
    case MATH_NOP:      string="NOP";               break;
    case MATH_NNONE:    string="Negate";            break;
    case MATH_NONE:     string="NONE";              break;
    case MATH_LD_STATE: string="(set RPN state)";   break;
    case MATH_LD_ELEM:  string="(load $a[i])";      break;
    case MATH_SV_ELEM:  string="(store $a[i[,j]])"; break;
    case MATH_SV_ZERO:  string="(store $a[0])";     break;
#ifdef USETOK
    case MATH_LD_TOKEN: string="(load va[i])";      break;
#endif /* USETOK */
    case MATH_ADD:      string="+";                 break;
    case MATH_SUB:      string="-";                 break;
    case MATH_MUL:      string="*";                 break;
    case MATH_DIV:      string="/";                 break;
    case MATH_MOD:      string="%";                 break;
    case MATH_POW:      string="^";                 break;
    case MATH_CMP:      string="?";                 break;
    case MATH_LOG:      string="log()";             break;
    case MATH_LN:       string="ln()";              break;
    case MATH_E10:      string="e10()";             break;
    case MATH_EE:       string="ee()";              break;
    case MATH_CHS:      string="chs()";             break;
    case MATH_ABS:      string="abs()";             break;
    case MATH_SIN:      string="sin()";             break;
    case MATH_COS:      string="cos()";             break;
    case MATH_TAN:      string="tan()";             break;
    case MATH_ASIN:     string="asin()";            break;
    case MATH_ACOS:     string="acos()";            break;
    case MATH_ATAN:     string="atan()";            break;
    case MATH_SINH:     string="sinh()";            break;
    case MATH_COSH:     string="cosh()";            break;
    case MATH_TANH:     string="tanh()";            break;
    case MATH_D2R:      string="d2r()";             break;
    case MATH_R2D:      string="r2d()";             break;
    case MATH_BITNOT:   string="not()";             break;
    case MATH_MAX:      string="max()";             break;
    case MATH_MIN:      string="min()";             break;
    case MATH_BITAND:   string="and()";             break;
    case MATH_BITOR:    string="or()";              break;
    case MATH_BITXOR:   string="xor()";             break;
    case MATH_BITSHL:   string="shl()";             break;
    case MATH_BITSHR:   string="shr()";             break;
    case MATH_DLEN:     string="len()";             break;
    case MATH_SUM:      string="sum()";             break;
    case MATH_SM2:      string="sm2()";             break;
    case MATH_NML:      string="nml()";             break;
    case MATH_INV:      string="inv()";             break;
    case MATH_DEL:      string="del()";             break;
    case MATH_IDX:      string="idx()";             break;
    case MATH_SRT:      string="srt()";             break;
    case MATH_SIX:      string="six()";             break;
    case MATH_DIM:      string="dim()";             break;
    case MATH_CAT:      string="cat()";             break;
    case MATH_INI:      string="ini()";             break;
#ifdef USETOK
    case MATH_TIX:      string="tix()";             break;
    case MATH_TCX:      string="tcx()";             break;
    case MATH_TOK:      string="tok()";             break;
    case MATH_TLN:      string="tln()";             break;
    case MATH_SLN:      string="sln()";             break;
#endif /* USETOK */
    case MATH_MAP:      string="map()";             break;
    case MATH_UNMAP:    string="ump()";             break;
    case MATH_RND:      string="rnd()";             break;
    case MATH_LID:      string="lid()";             break;
    case MATH_TRC:      string="trc()";             break;
    default:
      insane(INSFTLPRGERR," unknown case in show_math_op");
  }
  return(string);
}


char *show_stk_op(enum mstack_ops sop){
char *string;
  switch(sop){
    case MSTK_NONE:   string="NONE";   break;
    case MSTK_DPUSH:  string="dpush";  break;
    case MSTK_VPUSH:  string="vpush";  break;
    case MSTK_VAPUSH: string="vapush"; break;
#ifdef USETOK
    case MSTK_TOKZEROPUSH:  string="spush";  break;
    case MSTK_SAPUSH: string="sapush"; break;
#endif /* USETOK */
    case MSTK_OPUSH:  string="opush";  break;
    case MSTK_PSH:    string="psh";    break;
    case MSTK_NPSH:   string="npsh";   break;
    case MSTK_POP:    string="pop";    break;
    case MSTK_DONE:   string="done";   break;
    default:
      insane(INSFTLPRGERR," unknown case in show_stk_op");
  }
  return(string);
}

void dump_pstack(MASNEXUS *stk, int sptr){
int i;
enum math_ops mop;
  fprintf(stdout,"STACK:\n");fflush(stdout);
  for(i=0;i<=sptr;i++){
    if(stk[i].what== IS_MOP){
       mop=stk[i].mop;
       fprintf(stdout," %d OP   %s\n",i,show_math_op(mop));
       fflush(stdout);
    }
    else if(stk[i].what== IS_NUM_ADDR){
       fprintf(stdout," %d Address of dvar %c\n",i,FROMVAROFF((int)stk[i].val));
       fflush(stdout);
    }
    else if(stk[i].what== IS_STR_ADDR){
       fprintf(stdout," %d Address of svar %c\n",i,FROMVAROFF((int)stk[i].val));
       fflush(stdout);
    }
    else if(stk[i].what== IS_VALUE){
       fprintf(stdout," %d Value %f\n",i,stk[i].val);
       fflush(stdout);
    }
  }
}
void dump_rstack(double *stk, int sptr){
int i;
  fprintf(stdout,"STACK:\n");fflush(stdout);
  for(i=0;i<=sptr;i++){  fprintf(stdout," %d  %f\n",i,stk[i]); fflush(stdout); }
}

/* Returns true if the mop can be classified, otherwise false.  If it can be, shift,
  scroll, what, and state are set.  Also returns true with a MATH_NOP and no shift/scroll
  for operations with incomplete operands.  For instance ( */
int mop_properties(enum math_ops *mop, int where, int upper, int lower,
   int *shift, int *scroll, int *from, enum rpn_states *state){
int status=0;
int i,j;
//fprintf(stdout,"DEBUG PROPERTIES %s upper %o lower %o where %d\n",show_math_op(*mop),upper,lower,where);
   switch (*mop) {
     case  MATH_NOP:
       insane(INSFTLPRGERR," see NOP in mop properties");
     case  MATH_NNONE: /* this is ALMOST like MATH_NONE, but the only thing that can be negated
       is single val, anything else is a syntax error  */
       if(    lower == OPPAT_A){
         *shift=1; *scroll=where; *state=RPN_SCALAR;    status=1; *from=0;
       }
       else if(lower == OPPAT_B){
         *shift=1; *scroll=where; *state=RPN_NVEC_SELF;    status=1; *from=0;
       }
       break;
     case  MATH_NONE:
       for(i=1,j=7;;i++,j<<=3){ if(0==(lower & j)){break;} }   
       *shift=1; *scroll=where; *state=RPN_SCALAR;    status=1; *from=0;
       break;       
     case  MATH_LD_STATE:
      /* used to set for next cycle IS_NVEC_SCALAR,etc. defaults to IS_SCALAR.  It is generated
         by the results of the call to this routine, so it should never appear on the input */ 
       insane(INSFTLPRGERR," see LD_STATE in mop properties");
     case  MATH_LD_ELEM:    
       if(    upper == OPPAT_H && lower == OPPAT_A ){
         *shift=2; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       else if(upper == OPPAT_H && lower == OPPAT_E ){ /* leave nadd val val*/
         *shift=1; *scroll=2; *state=RPN_SCALAR;    status=1; *mop=MATH_NOP; *from=0; 
       }
       break;       
     case  MATH_SV_ELEM:
       if(     upper == OPPAT_A && lower == OPPAT_A){
         *shift=2; *scroll=0; *state=RPN_SCALAR;          status=1;
       }
       else if(upper == OPPAT_J && lower == OPPAT_A){
         *shift=3; *scroll=0; *state=RPN_SCALAR;          status=1;
       }
       else if(upper == OPPAT_B && lower == OPPAT_A){
         *shift=2; *scroll=0; *state=RPN_NVEC_SCALAR;     status=1;
       }
       else if(upper == OPPAT_B && lower == OPPAT_B){
         *shift=4; *scroll=0; *state=RPN_NVEC_NVEC;    status=1;
       }
#ifdef USETOK
       else if(upper == OPPAT_B && lower == OPPAT_C){
         *shift=4; *scroll=0; *state=RPN_NVEC_SVEC;    status=1;
       }
#endif /* USETOK */
       break; 
     case  MATH_SV_ZERO:
       if(upper == OPPAT_H && lower == OPPAT_A){
         *shift=2; *scroll=0; *state=RPN_SCALAR;          status=1;
       }
       break;   
#ifdef USETOK
     case  MATH_LD_TOKEN:
       if(    upper == OPPAT_I && lower == OPPAT_A ){
         *shift=2; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       else if(upper == OPPAT_I && lower == OPPAT_E ){ /* leave sadd val val*/
         *shift=1; *scroll=2; *state=RPN_SCALAR;    status=1; *mop=MATH_NOP; *from=0;
       }
       break;       
#endif /* USETOK */
     case  MATH_ADD:
     case  MATH_SUB:
     case  MATH_MUL:
     case  MATH_DIV:
     case  MATH_MOD:
     case  MATH_POW:
     case  MATH_CMP:
       if(     upper == OPPAT_A && lower == OPPAT_A){
         *shift=2; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       else if(upper == OPPAT_B && lower == OPPAT_B){
         *shift=4; *scroll=0; *state=RPN_NVEC_NVEC; status=1;
       }
       else if(upper == OPPAT_B && lower == OPPAT_A){
         *shift=2; *scroll=0; *state=RPN_NVEC_SCALAR; status=1;
       }
       else if(upper == OPPAT_A && lower == OPPAT_B){
         *shift=2; *scroll=3; *state=RPN_SCALAR_NVEC; status=1; *from=0;
       }
       break;       
     case  MATH_LOG:
     case  MATH_LN:
     case  MATH_E10:
     case  MATH_EE:
     case  MATH_CHS:
     case  MATH_ABS:
     case  MATH_SIN:
     case  MATH_COS:
     case  MATH_TAN:
     case  MATH_ASIN: 
     case  MATH_ACOS:
     case  MATH_ATAN: 
     case  MATH_SINH:
     case  MATH_COSH:
     case  MATH_TANH:
     case  MATH_D2R:
     case  MATH_R2D:
     case  MATH_BITNOT:
       if(    lower == OPPAT_A){
         *shift=1; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       else if(lower == OPPAT_B){
         *shift=1; *scroll=3; *state=RPN_NVEC_SELF; status=1; *from=0;
       }
       break;
     case  MATH_MAX:
     case  MATH_MIN:
     case  MATH_BITAND:
     case  MATH_BITOR:
     case  MATH_BITXOR:
     case  MATH_BITSHL:
     case  MATH_BITSHR:
       if(lower == OPPAT_E){
         *shift=2; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       else if(lower == OPPAT_F){
         *shift=4; *scroll=3; *state=RPN_NVEC_NVEC; status=1; *from=3;
       }
       else if(lower == OPPAT_D){
         *shift=2; *scroll=3; *state=RPN_NVEC_SCALAR; status=1; *from=1;
       }
       else if(lower == OPPAT_L){
         *shift=2; *scroll=3; *state=RPN_SCALAR_NVEC; status=1; *from=0;
       }
       break;       
     case  MATH_DLEN:
     case  MATH_SUM:
     case  MATH_SM2:
     case  MATH_NML:
     case  MATH_INV:
     case  MATH_DEL:
     case  MATH_IDX:
     case  MATH_SRT:
     case  MATH_SIX:
       if(lower == OPPAT_B){
         *shift=3; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       break;       
     case  MATH_CAT:
     case  MATH_INI:
       if(lower == OPPAT_D || lower == OPPAT_G || lower == OPPAT_M){
         *shift=where; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       break;
     case  MATH_DIM:
       if(lower == OPPAT_D){
         *shift=4; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       break;
#ifdef USETOK
     case  MATH_TIX:
     case  MATH_TCX:
       if(lower == OPPAT_N){
         *shift=6; *scroll=0; *state=RPN_NVEC_SVEC; status=1;
       }
       break;       
     case  MATH_TOK:
     case  MATH_TLN:
     case  MATH_SLN:
       if(lower == OPPAT_C){
         *shift=3; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       break;       
#endif /* USETOK */
     case  MATH_MAP:
     case  MATH_UNMAP:
       if(lower == OPPAT_F){
         *shift=4; *scroll=3; *state=RPN_NVEC_NVEC;    status=1; *from=3;
       }
       break;       
     case  MATH_RND:
     case  MATH_LID:
     case  MATH_TRC:
       if(lower == OPPAT_A){
         *shift=2; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       else if(lower == OPPAT_B){
         *shift=1; *scroll=3; *state=RPN_NVEC_SELF; status=1; *from=0;
       }
       break;
   };
   return(status);  
}

/* calculate operands up to next op or top of stack.  If operands is 0 the other returned
values are meaningless.  shift is the offset to the op, if one is found, and mop is its value.
Operands accumulate only up to the first 6 positions, after that the only valid form is
nad val... val for ini() and cat() */
void next_mop(MASNEXUS *pstk,int psptr, enum math_ops *mop, int *shift, int *eoperands){
int i,j,k;
int type=-1;
int operands = 0;

  if(mop){ *mop=MATH_NOP; } /* if nothing is found */
  for(i=0,j=1,k=psptr; i<=psptr; i++,k--){
    type=-1;
    switch(pstk[k].what){
      case IS_MOP:
        if(shift){*shift = i;}
        if(mop){*mop   = pstk[k].mop;}
        type  = 0;  /* for a short stack this might get added on after switch */
        i     = psptr+1; /* force loop exit */
        break;
      case IS_VALUE:      type = OPPAT_VAL;  break;
      case IS_NUM_ADDR:   type = OPPAT_NAD;  break;
      case IS_STR_ADDR:   type = OPPAT_SAD;  break;
    }
    if(type==-1){insane(INSFTLPRGERR," invalid type seen in pre stack"); }
    if(i<5){            operands += type * j; j<<=3;}
    else if(i==5){      operands += type * j;       }
    else if(i<=psptr){  operands>>=3;
                        operands += type * j;       }
  }
  *eoperands=operands;
}

/* find the operator and categorize the operand pattern.  This is used during
the conversion to RPN.  If it fails return an error message 
There are only a few patterns expected (see in the constants at the
beginning of this file) anything else is an error 
Only these two forms are allowed:
  upper op lower    AND op lower
  
mop     the operation found
shift.  amount to subtract from the ptr
scroll. number of positions to copy, maps from -> new ptr
from.   where to begin copying stack values from
state.  which RPN mode will be used 

*/


char *categorize_operands(MASNEXUS *pstk,int psptr, enum math_ops *mop,
   int *shift, int *scroll, int *from, enum rpn_states *state){
int lower=0;
int upper=0;
int where=0;
char *message=NULL;

  next_mop(pstk,psptr,      mop, &where,&lower);
  if(*mop != MATH_NOP && lower){
    if(where>0){ next_mop(pstk,psptr-where-1,NULL, NULL,  &upper); }
    else {       upper = 0; }
    if(!mop_properties(mop, where, upper, lower, shift, scroll, from, state)){
dump_pstack(pstk,psptr); 
      message=wait_insane(INSFTLERR," math expression syntax error"); 
    }
  }
  else { 
    /* no operator, this can happen when (1 op_pre_clow 2 op_prec_high 3)
    The outer parens reduce, then 2 combines with 3, then 1 combines
    with that result, and the try loop in pre_run will look one more time,
    but there are no operators left. */
    *scroll=0;
    *shift=0;
  }
  return(message);
} 
  
/* "runs"  the program, converting it to RPN and figuring out the
stack size needed to do the run.  Resizes the stack if needed. 
On normal exit returns NULL, if problem, a pointer to an error message string.
The program is constructed in and returned in rpnprog
 */
char *pre_run_math(OMNINEXUS *omni, ESNEXUS *program, ESNEXUS *rpnprog){
enum math_ops   mop;
enum mstack_ops sop=MSTK_NONE;
enum mstack_ops lastsop=MSTK_NONE;
char      ctmp;
char     *dat;
int       offset=0;
double    dtmp;
int       itmp,i;
int       ok=1;
MASNEXUS  *pstk;
int       psptr=-1;
int       try=0;
int       trynone=0;
int       from,to;
MASNEXUS *sn;
int       psptr_max=1;
int       shift;  /* adjustment to stack ptr.  */
int       scroll; /* Number of entries to rotate up by one, lowest lands on shift position*/
char     *message=NULL;
enum rpn_states type;

  dat = program->string;
  es_clear(rpnprog);
  while(ok){ 
//fprintf(stdout,"DEBUG PRERUN while()  offset %d\n",offset);
//dump_pstack(pstk,psptr);
    EXT_REALLOC2(omni->pstk->list,omni->pstk->salloc,omni->pstk->slen+1,
      omni->pstk->slen+MATHINC,sizeof(MASNEXUS),MEMOOPS);
    pstk=omni->pstk->list;

    ctmp = dat[offset++];
    sop=ctmp;
//fprintf(stdout,"DEBUG PRERUN sop %s offset %d\n",show_stk_op(sop),offset);
    switch(sop){
      case MSTK_DPUSH:
//fprintf(stdout,"DEBUG ->RPN DPUSH\n");
        es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
        ESP_NEXTDBLBOUNDARY(rpnprog); NEXTDBLBOUNDARY(offset);
        es_append_addat(rpnprog, (char *)&dat[offset],SOD ,MATHINC,MEMOOPS);
        lastsop=sop;
        dtmp     = *(double *)&(dat[offset]);
        offset+=SOD;
        psptr++;
        pstk[psptr].what = IS_VALUE;
        pstk[psptr].val  = dtmp;
        break;
      case MSTK_VPUSH:
//fprintf(stdout,"DEBUG ->RPN VPUSH\n");
        es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
        ESP_NEXTINTBOUNDARY(rpnprog); NEXTINTBOUNDARY(offset);
        es_append_aidat(rpnprog, (char *) &dat[offset],SOI ,MATHINC,MEMOOPS);
        lastsop=sop;
        itmp     = *(int *)&(dat[offset]);
        offset  += SOI;
        psptr++;
        pstk[psptr].what = IS_VALUE;
        if(ISVAROFF(itmp)){       pstk[psptr].val  = omni->dvar[itmp].val[0]; }
        else if(itmp==MYVARSMAX){ pstk[psptr].val  = omni->result;            }
        else {
          insane(INSFTLPRGERR," VPUSH of invalid variable in pre_run_math");
        }
        break;
     case MSTK_VAPUSH:
//fprintf(stdout,"DEBUG ->RPN VAPUSH\n");
        es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
        ESP_NEXTINTBOUNDARY(rpnprog); NEXTINTBOUNDARY(offset);
        es_append_aidat(rpnprog, (char *) &dat[offset],SOI ,MATHINC,MEMOOPS);
        lastsop=sop;
        itmp     = *(int *)&(dat[offset]);
        offset  += SOI;
        psptr++;
        pstk[psptr].what = IS_NUM_ADDR;
        pstk[psptr].val  = itmp;
        break;

#ifdef USETOK
      case MSTK_TOKZEROPUSH:
//fprintf(stdout,"DEBUG ->RPN SPUSH\n");
        es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
        ESP_NEXTINTBOUNDARY(rpnprog); NEXTINTBOUNDARY(offset);
        es_append_aidat(rpnprog, (char *) &dat[offset],SOI ,MATHINC,MEMOOPS);
        itmp     = *(int *)&(dat[offset]);
        offset  += SOI;
        psptr++;
        pstk[psptr].what = IS_VALUE;
        pstk[psptr].val  = 1000.0 + itmp;
        break;
     case MSTK_SAPUSH:
//fprintf(stdout,"DEBUG ->RPN SAPUSH\n");
        es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
        ESP_NEXTINTBOUNDARY(rpnprog); NEXTINTBOUNDARY(offset);
        es_append_aidat(rpnprog, (char *) &dat[offset],SOI ,MATHINC,MEMOOPS);
        lastsop=sop;
        itmp     = *(int *)&(dat[offset]);
        offset  += SOI;
        psptr++;
        pstk[psptr].what = IS_STR_ADDR;
        pstk[psptr].val  = itmp;
        break;
#endif /* USETOK */
      case MSTK_OPUSH:
        mop      = dat[offset++];
        psptr++;
        pstk[psptr].what = IS_MOP;
        pstk[psptr].mop = mop;
//fprintf(stdout,"DEBUG pre push mop %s\n",show_math_op(mop));
        break;
      case MSTK_PSH:
        psptr++;
        pstk[psptr].what = IS_MOP;
        pstk[psptr].mop  = MATH_NONE;
        break;
      case MSTK_NPSH:  /* special case for handling unary negatives */
        psptr++;
        pstk[psptr].what = IS_MOP;
        pstk[psptr].mop  = MATH_NNONE;
        break;
      case MSTK_POP:
        try      = 1;
        trynone  = 1;  /* have not yet consumed our one MATH_NONE or MATH_NNONE */
        break;
      case MSTK_DONE:
        es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
        lastsop=sop;
        ok=0;try=0;
        break;
      default: 
        insane(INSFTLPRGERR," unknown stack case in pre_run_math");
    }
    if(psptr > psptr_max){ psptr_max=psptr; }
    while(try){
//fprintf(stdout,"DEBUG TRY before stack adjust, trynone %d\n",trynone); dump_pstack(pstk,psptr);
      message=categorize_operands(pstk,psptr,&mop,&shift,&scroll,&from,&type);
//fprintf(stdout,"DEBUG found operator %s shift %d scroll %d type %d\n",show_math_op(mop),shift,scroll,type);
      if(message){ok=0; break; }
      if(mop<=MATH_NONE && !trynone){  /* consumed one NONE and possibly other operators */
        try=0;
        break;
      }
      if(scroll){
        from  = psptr-from-scroll+1;
        psptr-=shift;
        to    = psptr-scroll+1;
        sn    = &pstk[to];
        for(i=0;i<scroll;i++,from++,to++){
//fprintf(stdout,"DEBUG from %d to %d\n",from,to);
          pstk[to].val  = pstk[from].val;
          pstk[to].what = pstk[from].what;
        }
      }
      else { /* all of the cases where the stack is truncated end in a value */
        psptr-=shift;
        sn  = &pstk[psptr];
        sn->val=1.0;
        sn->what=IS_VALUE;
      }
//fprintf(stdout,"DEBUG try after  stack adjust\n"); dump_pstack(pstk,psptr);
      if(mop > MATH_NONE){
         if(type!=RPN_SCALAR){ /* this goes BEFORE the operator, so that it can effect it */
//fprintf(stdout,"DEBUG ->RPN OPUSH c LD_STATE %d\n",type);
            ctmp=MSTK_OPUSH;   es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
            ctmp=MATH_LD_STATE;es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
            ctmp=type;         es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
            lastsop=sop;
         }
//fprintf(stdout,"DEBUG ->RPN OPUSH A operator %s\n",show_math_op(mop));
         ctmp=MSTK_OPUSH;  es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
         ctmp=mop;         es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
         lastsop=sop;
      }
//fprintf(stdout,"DEBUG  pre try mop %s\n",show_math_op(mop));
      /* this is only vaguely doing the operations, mostly it needs to keep track of
         pointers and what is and isn't (going to be) a variable/op.  All variable values
         are represent by 1 once an operator has been applied.   */
      switch(mop){
        case MATH_NOP: /* NO OP, do nothing */
          try=0; /* but don't keep trying either*/
          break;
        case MATH_NNONE:
//fprintf(stdout,"DEBUG ->RPN  OPUSH B operator %s\n",show_math_op(MATH_CHS));
          if(lastsop==MSTK_DPUSH){ 
            /* if a constant was the last thing loaded, change its sign
               in the rpnprog so that CHS needn't be run on each pass */
            rpnprog->slen-=SOD;
            dtmp=*(double *)ESP_CADDR(rpnprog,rpnprog->slen);
            dtmp=-dtmp;
            ESP_NEXTDBLBOUNDARY(rpnprog);
            es_append_addat(rpnprog, (char *)&dtmp, SOD ,MATHINC,MEMOOPS);            
          }
          else { /* otherwise, force in a CHS */
            if(scroll!=1){ /* shift to RPN_NVEC_SELF, this is "nad val val" */
              ctmp=MSTK_OPUSH;   es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
              ctmp=MATH_LD_STATE;es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
              ctmp=RPN_NVEC_SELF;es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
            }
            ctmp=MSTK_OPUSH;  es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
            ctmp=MATH_CHS;    es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
          }
          lastsop=sop;
          /* intentionally falls through */
        case MATH_NONE:    /* consume only 1 push per pop, so set try back to 0 */ 
          trynone = 0;                                 break;
        case MATH_LD_STATE:
          insane(INSFTLPRGERR," hit LD_STATE in pre_run_math");
          break;
        case MATH_LD_ELEM:
#ifdef USETOK
        case MATH_LD_TOKEN:
#endif /* USETOK */
        case MATH_SV_ELEM:
        case MATH_SV_ZERO: 
        case MATH_ADD:                                    
        case MATH_SUB:                        
        case MATH_MUL:                        
        case MATH_DIV:                        
        case MATH_MOD:
        case MATH_POW:  
        case MATH_CMP:  
        case MATH_LOG:
        case MATH_LN:  
        case MATH_E10: 
        case MATH_EE:  
        case MATH_CHS:  
        case MATH_ABS:  
        case MATH_SIN:  
        case MATH_COS:  
        case MATH_TAN:  
        case MATH_ASIN:  
        case MATH_ACOS:  
        case MATH_ATAN:  
        case MATH_SINH:  
        case MATH_COSH:  
        case MATH_TANH:  
        case MATH_D2R:  
        case MATH_R2D:  
        case MATH_BITNOT:
        case MATH_MAX:
        case MATH_MIN:
        case MATH_BITAND:
        case MATH_BITOR:
        case MATH_BITXOR:
        case MATH_BITSHL:
        case MATH_BITSHR:
        case MATH_DLEN:
        case MATH_SUM:
        case MATH_SM2:
        case MATH_NML:
        case MATH_INV:
        case MATH_DEL:
        case MATH_IDX:
        case MATH_SRT:
        case MATH_SIX:
        case MATH_DIM:
          break;
        case MATH_CAT:
        case MATH_INI:
          /* Use an extended instruction instead of pushing the length onto
             the stack as a double and then retrieving it again */
          shift-=1; /* offset to nad when it is on RPN stack */
          ESP_NEXTINTBOUNDARY(rpnprog); /* must be int aligned*/
          es_append_aidat(rpnprog, (char *) &shift, SOI ,MATHINC,MEMOOPS);
          break;
#ifdef USETOK
        case MATH_TIX:
        case MATH_TCX:
        case MATH_TOK:
        case MATH_TLN:
        case MATH_SLN:
#endif /* USETOK */
        case MATH_MAP:
        case MATH_UNMAP:
        case MATH_RND:
        case MATH_LID:  
        case MATH_TRC:  
          break;
        default:
          insane(INSFTLPRGERR," unknown math case in run_math");
      }
    }
  }
  /* resize the run stack if this program means it needs more space */
  EXT_REALLOC2(omni->stk->val,omni->stk->dalloc,psptr_max,psptr_max,sizeof(double),MEMOOPS);
  return(message);
}

/*actually run the rpn program.  This is more efficient since it knows
at this point exactly what order to use for load data/var and operation. 

Returns NULL if there is no error, points to message if there was a problem.
Last value is in result  */
char *run_math_rpn(OMNINEXUS *omni, char *program, double *result){
enum    math_ops mop;
enum    mstack_ops sop;
char    ctmp;
char   *dat;
int     offset=0;
double  dtmp;
double  dtmp2;
int     itmp;
int     i2;
int     ok=1;
int     move;
int     i,j;
int     sptr=-1;
int     sstart,send;  /* real range, after conversion from 1->N to 0->N-1*/
int     dstart,dend;  /* real range, after conversion from 1->N to 0->N-1*/
double  Euler=2.7182818284590452354;
double  Pi   =3.14159265358979323846;
double *stk;
DVNEXUS *dv;
DVNEXUS *dv2;
#ifdef USETOK
FMTNEXUS *vv;
STRINGNEXUS *tok;
char    scratch[256]; /* much bigger than the largest valid number to convert */
char   *to;
#endif /* USETOK */
char   *message=NULL;
enum rpn_states rpnstate=RPN_SCALAR; /* the default */

  dat = program;
  stk = omni->stk->val;
  while(ok){
    ctmp = dat[offset++];
    sop=ctmp;
//fprintf(stdout,"DEBUG rpn sop %s from offset %d in state %d\n",show_stk_op(sop),offset-1,rpnstate);
    switch(rpnstate){ 
      case  RPN_SCALAR: /*rpnstate*/
        switch(sop){
          case MSTK_DPUSH:
            NEXTDBLBOUNDARY(offset);
            dtmp        = *(double *)&(dat[offset]);
            offset     += SOD;
            stk[++sptr] = dtmp;
//fprintf(stdout,"DEBUG rpn pushed constant value %f\n",dtmp);
            break;
          case MSTK_VPUSH:
            NEXTINTBOUNDARY(offset);
            itmp        = *(int *)&(dat[offset]);
            offset     += SOI;
            if(ISVAROFF(itmp)){       stk[++sptr] = omni->dvar[itmp].val[0]; }
            else if(itmp==MYVARSMAX){ stk[++sptr] = omni->result;            }
            else {
              insane(INSFTLPRGERR," VPUSH of invalid variable in rpn_math");
            }
//fprintf(stdout,"DEBUG rpn pushed variable [0] value %f\n",omni->dvar[itmp].val[0]);
            break;
          case MSTK_VAPUSH:
            NEXTINTBOUNDARY(offset);
            itmp        = *(int *)&(dat[offset]);
            offset     += SOI;
            stk[++sptr] = itmp;
//fprintf(stdout,"DEBUG rpn pushed variable address %d\n",itmp);
            break;

#ifdef USETOK
          case MSTK_TOKZEROPUSH:
            NEXTINTBOUNDARY(offset);
            itmp        = *(int *)&(dat[offset]);
            offset     += SOI;
            vv=omni->vn[itmp];
            if(!vv->fldcount){
              message=wait_insane(INSFTLERR," string variable not defined");
              ok=0; break;
            }
            tok=&(vv->toklist[0]);
            if(tok->slen >= 255){
              message=wait_insane(INSFTLERR," string variable too large, cannot be a number");
              ok=0;  break;
            }
            (void)strncpy(scratch,&(vv->dat_str->string[tok->start]),tok->slen);
            scratch[tok->slen]='\0';
            dtmp=numeric_input(scratch,&to);
            /* set NaN and go on.  That way extract can test for success.  If we throw an error
               it would be fatal there, so no way to recover in a script. */
            if(!to || *to != '\0'){ dtmp=NAN; }
            stk[++sptr] = dtmp;
            break;
          case MSTK_SAPUSH:
            NEXTINTBOUNDARY(offset);
            itmp        = *(int *)&(dat[offset]);
            offset     += SOI;
            stk[++sptr] = itmp;
//fprintf(stdout,"DEBUG rpn pushed string variable address %d\n",itmp);
            break;
#endif /* USETOK */
          case MSTK_OPUSH:
            mop      = dat[offset++];
//fprintf(stdout,"DEBUG rpn mop %s\n",show_math_op(mop));
            switch(mop){
              case MATH_NOP: /* NO OP, do nothing */
                break;
              case MATH_NNONE: 
              case MATH_NONE: 
                 insane(INSFTLPRGERR," MATH_[N]NONE found in run_math_rpn");
                 break;
              case MATH_LD_STATE: /* this comes out of the program NOT off the stack */
                 rpnstate = dat[offset]; offset++;
//fprintf(stdout,"DEBUG rpn rpnstate set to %d\n",rpnstate);
                 break;
              case MATH_LD_ELEM:
                 itmp=stk[sptr-1]; /* this should always be in range, RPN cannot alter the value */
                 dv=&(omni->dvar[itmp]);
                 i2=stk[sptr];  
                 /* i2 this could ___easily__ be wrong. Like token indices, these are 1->N
                 or -1->-N (from last position).  Converted to 0->N-1 before actually
                 indexing the array.  */
                 if(     i2>0 && i2<=dv->dlen){  stk[sptr-1] = dv->val[i2-1];        }
                 else if(i2<0 && i2>=-dv->dlen){ stk[sptr-1] = dv->val[dv->dlen+i2]; }
                 else { 
                   ok=0;
                   message=wait_insane(INSFTLERR," array access out of bounds");
                 }
                                                                                  sptr--; break;
              case MATH_SV_ELEM:
                 itmp=stk[sptr-2]; /* this should always be in range, RPN cannot alter the value */
                 dv=&(omni->dvar[itmp]);
                 i2=stk[sptr-1];  
                 /* i2 this could ___easily__ be wrong. Like token indices, these are 1->N
                 or -1->-N (from last position).  Converted to 0->N-1 before actually
                 indexing the array.  */
                 if(     i2>0 && i2<=dv->dlen){  dv->val[i2-1]        = stk[sptr]; }
                 else if(i2<0 && i2>=-dv->dlen){ dv->val[dv->dlen+i2] = stk[sptr]; }
                 else { 
                   ok=0;
                   message=wait_insane(INSFTLERR," array access out of bounds");
                 }
                 /* What should the stack value be?  Might as well be the same as
                 the stored value. */
                              stk[sptr-2] =  stk[sptr];                           sptr-=2; break;
              case MATH_SV_ZERO:
                 itmp=stk[sptr-1]; /* this should always be in range, RPN cannot alter the value */
                 dv=&(omni->dvar[itmp]);
                 dv->val[0]= stk[sptr];
                 /* What should the stack value be?  Might as well be the same as
                 the stored value. */
                              stk[sptr-1] =  stk[sptr];                           sptr--; break;
#ifdef USETOK
              case MATH_LD_TOKEN:
                 itmp=stk[sptr-1]; /* this should always be in range, RPN cannot alter the value */
                 vv=omni->vn[itmp];
                 if(!vv->fldcount){
                   message=wait_insane(INSFTLERR," string variable not defined");
                   ok=0; break;
                 }
                 i2=stk[sptr];  
                 /* i2 this could ___easily__ be wrong. Like token indices, these are 1->N
                 or -1->-N (from last position).  Converted to 0->N-1 before actually
                 indexing the array.  */
                 if(     i2>0 && i2<=vv->tokcount){  i2--;              }
                 else if(i2<0 && i2>=-vv->tokcount){ i2+=vv->tokcount;  }
                 else { 
                   message=wait_insane(INSFTLERR," string variable undefined or array access out of bounds");
                   ok=0; break;
                 }
                 tok=&(vv->toklist[i2]);
                 if(tok->slen >= 255){
                   message=wait_insane(INSFTLERR," string variable too large, cannot be a number");
                   ok=0;  break;
                 }
                 (void)strncpy(scratch,&(vv->dat_str->string[tok->start]),tok->slen);
                 scratch[tok->slen]='\0';
                 dtmp=numeric_input(scratch,&to);
                 if(!to || *to != '\0'){ dtmp=NAN; }
                 stk[sptr-1] = dtmp;                                              sptr--; break;
#endif /* USETOK */
              case MATH_ADD:  stk[sptr-1] = stk[sptr-1] + stk[sptr];              sptr--; break;                                     
              case MATH_SUB:  stk[sptr-1] = stk[sptr-1] - stk[sptr];              sptr--; break;                         
              case MATH_MUL:  stk[sptr-1] = stk[sptr-1] * stk[sptr];              sptr--; break;                         
              case MATH_DIV:  stk[sptr-1] = stk[sptr-1] / stk[sptr];              sptr--; break;                         
              case MATH_MOD:  stk[sptr-1] = modf((stk[sptr-1]/stk[sptr]),&dtmp);  sptr--; break;
              case MATH_POW:  stk[sptr-1] = pow(stk[sptr-1],stk[sptr]);           sptr--; break;
              case MATH_CMP:  stk[sptr-1] = ( stk[sptr-1] > stk[sptr] ?  1.0 :
                                             (stk[sptr-1] < stk[sptr] ? -1.0 : 0 )
                                            );                                    sptr--; break;                                     
              case MATH_LOG:  stk[sptr]   = log(stk[sptr])/log(10.0);                     break;
              case MATH_LN:   stk[sptr]   = log(stk[sptr]);                               break;
              case MATH_E10:  stk[sptr]   = pow(10.0,stk[sptr]);                          break;
              case MATH_EE:   stk[sptr]   = pow(Euler,stk[sptr]);                         break;
              case MATH_CHS:  stk[sptr]   = -stk[sptr];                                   break;
              case MATH_ABS:  stk[sptr]   = (stk[sptr]<0 ? -stk[sptr] : stk[sptr]);       break;
              case MATH_SIN:  stk[sptr]   = sin(  stk[sptr]);                             break;
              case MATH_COS:  stk[sptr]   = cos(  stk[sptr]);                             break;
              case MATH_TAN:  stk[sptr]   = tan(  stk[sptr]);                             break;
              case MATH_ASIN: stk[sptr]   = asin( stk[sptr]);                             break;
              case MATH_ACOS: stk[sptr]   = acos( stk[sptr]);                             break;
              case MATH_ATAN: stk[sptr]   = atan( stk[sptr]);                             break;
              case MATH_SINH: stk[sptr]   = sinh(  stk[sptr]);                            break;
              case MATH_COSH: stk[sptr]   = cosh(  stk[sptr]);                            break;
              case MATH_TANH: stk[sptr]   = tanh(  stk[sptr]);                            break;
              case MATH_D2R:  stk[sptr]   = 2.0*Pi*stk[sptr]/360.0;                       break;
              case MATH_R2D:  stk[sptr]   = 360.0*stk[sptr]/(2.0*Pi);                     break;
              case MATH_BITNOT:  stk[sptr]   = ~DBL2UINT32(stk[sptr]);                                    break;
              case MATH_MAX:     stk[sptr-1] = fmax(stk[sptr-1],stk[sptr]);                       sptr--; break;
              case MATH_MIN:     stk[sptr-1] = fmin(stk[sptr-1],stk[sptr]);                       sptr--; break;
              case MATH_BITAND:  stk[sptr-1] = DBL2UINT32(stk[sptr-1]) &  DBL2UINT32(stk[sptr]);  sptr--; break;
              case MATH_BITOR:   stk[sptr-1] = DBL2UINT32(stk[sptr-1]) |  DBL2UINT32(stk[sptr]);  sptr--; break;
              case MATH_BITXOR:  stk[sptr-1] = DBL2UINT32(stk[sptr-1]) ^  DBL2UINT32(stk[sptr]);  sptr--; break;
              case MATH_BITSHL:  stk[sptr-1] = DBL2UINT32(stk[sptr-1]) << DBL2UINT32(stk[sptr]);  sptr--; break;
              case MATH_BITSHR:  stk[sptr-1] = DBL2UINT32(stk[sptr-1]) >> DBL2UINT32(stk[sptr]);  sptr--; break;
              case MATH_DLEN:
                 sptr-=2;  /* eat the range part, not used here */
                 itmp=stk[sptr]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){
                  ok=0;
                  message=wait_insane(INSFTLERR," len() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   stk[sptr] = dv->dlen;   
                }
                break;
              case MATH_SUM:
                 itmp=stk[sptr-2]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){
                   ok=0;
                   message=wait_insane(INSFTLERR," sum() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   if(0 >= realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv->dlen)){
                     message=wait_insane(INSFTLERR," [range] is empty or not fully contained on variable");
                   }
                   else {
                     for(dtmp=0.,i=sstart;i<=send;i++){dtmp+=dv->val[i];}
                     sptr-=2;
                     stk[sptr] = dtmp;
                   }
                 }
                 break;
              case MATH_SM2:
                 itmp=stk[sptr-2]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){ 
                   ok=0;
                   message=wait_insane(INSFTLERR," sm2() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   if(0 >= realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv->dlen)){
                     message=wait_insane(INSFTLERR," [range] is empty or not fully contained on variable");
                   }
                   else {
                     for(dtmp=0.,i=sstart;i<=send;i++){dtmp += dv->val[i]*dv->val[i];}
                     sptr-=2;
                     stk[sptr] = dtmp;
                   }
                 }
                 break;
              case MATH_NML: /**/
                 itmp=stk[sptr-2]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){ 
                   ok=0;
                   message=wait_insane(INSFTLERR," nml() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   if(0 >= realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv->dlen)){
                     message=wait_insane(INSFTLERR," [range] is empty or not fully contained on variable");
                   }
                   else {
                     itmp=0;
                     for(i=sstart;i<=send;i++){
                       switch(fpclassify(dv->val[i])){
                         case FP_NAN: itmp|=2; break;
                         case FP_INFINITE: itmp|=1; break;
                         default: break;
                       }
                     }
                     sptr-=2;
                     stk[sptr] = itmp;
                   }
                 }
                 break;
              case MATH_INV:
                 itmp=stk[sptr-2]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){ 
                   ok=0;
                   message=wait_insane(INSFTLERR," inv() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   if(0 >= realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv->dlen)){
                     message=wait_insane(INSFTLERR," [range] is empty or not fully contained on variable");
                   }
                   else {
                     for(i=sstart,j=send;i<j;i++,j--){
                       dtmp       = dv->val[i];
                       dv->val[i] = dv->val[j];
                       dv->val[j] = dtmp;
                     }
                     sptr-=2;
                     stk[sptr] = 0;
                   }
                 }
                 break;
              case MATH_DEL:  /* delete the specified range */
                 itmp=stk[sptr-2]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){ 
                   ok=0;
                   message=wait_insane(INSFTLERR," del() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   if(0 >= realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv->dlen)){
                     message=wait_insane(INSFTLERR," [range] is empty or not fully contained on variable");
                   }
                   else {
                     if(sstart==0 && send==dv->dlen-1){ /* empty, which actually leaves it with one zero value */
                         dv->dlen=1; dv->val[0]=0.0;
                     }
                     else { /* truncate */
                       for(j=sstart,i=send+1;i<dv->dlen;i++,j++){ dv->val[j]=dv->val[i];}
                       dv->dlen = j;
                     }
                     sptr-=2;
                     stk[sptr] = dv->dlen;
                   }
                 }
                 break;
              case MATH_IDX:  /* set the specified range's values to their positive positions */
                 itmp=stk[sptr-2]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){ 
                   ok=0;
                   message=wait_insane(INSFTLERR," idx() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   if(0 >= realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv->dlen)){
                     message=wait_insane(INSFTLERR," [range] is empty or not fully contained on variable");
                   }
                   else {
                     for(j=sstart;j<=send;j++){ dv->val[j]=j+1;}
                     sptr-=2;
                     stk[sptr] = 0.0;
                   }
                 }
                 break;
              case MATH_SRT:
                 itmp=stk[sptr-2]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){ 
                   ok=0;
                   message=wait_insane(INSFTLERR," idx() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   if(0 >= realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv->dlen)){
                     message=wait_insane(INSFTLERR," [range] is empty or not fully contained on variable");
                   }
                   else {
                     qsort((void *)&dv->val[sstart],send-sstart+1,SOD,compare_da);
                     sptr-=2;
                     stk[sptr] = 0.0;
                   }
                 }
                 break;
              case MATH_SIX:
                 itmp=stk[sptr-2]; /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){ 
                   ok=0;
                   message=wait_insane(INSFTLERR," idx() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   if(0 >= realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv->dlen)){
                     message=wait_insane(INSFTLERR," [range] is empty or not fully contained on variable");
                   }
                   else {
                     EXT_REALLOC2(dv->val,dv->dalloc,2*(dv->dlen),(2*(dv->dlen)+MATHINC),sizeof(double),MEMOOPS);
                     memcpy(&dv->val[dv->dlen],dv->val,SOD*dv->dlen);  /* keep a copy */
                     smuggle_str  = (char *)&dv->val[dv->dlen]; /* provides access inside qsort to the data (indirectly */
                     for(j=sstart;j<=send;j++){ dv->val[j]=j;} /* preset the positions, note 0 offset! */
                     qsort((void *)&dv->val[sstart],send-sstart+1,SOD,compare_dax);
                     for(j=sstart;j<=send;j++){ dv->val[j]++;} /* change to array indices, 1->N */
                     sptr-=2;
                     stk[sptr] = 0.0;
                   }
                 }
                 break;
              case MATH_DIM:
                /* Note, returns 0 */
                itmp=stk[sptr-3]; /* this could have been mangled */
                if(ISNOTVAROFF(itmp)){ 
                  message=wait_insane(INSFTLERR," dim() is not operating on a variable");
                  ok=0;
                }
                else {
                  dv=&(omni->dvar[itmp]);
                  i2=stk[sptr];
                  if(i2<=0){
                    ok=0;
                    message=wait_insane(INSFTLERR," dim() needs a positive size value");
                  } /* this could have been mangled */
                  else {
                    if(i2<dv->dlen){dv->dlen=i2;}
                    EXT_REALLOC3(dv->val,dv->dalloc,i2,sizeof(double),MEMOOPS);
                    if(dv->dalloc > dv->dlen){
                      for(i=dv->dlen;i<dv->dalloc;i++){ dv->val[i]=0.0; }
                    }
                    dv->dlen=dv->dalloc;
                    sptr-=3;
                    stk[sptr]=0.0;
                  }
                }
                break;
              case MATH_CAT:
                 /* Note, returns number of entries after addition */
                 NEXTINTBOUNDARY(offset);
                 i2=*(int *)&(dat[offset++]); /* retrieve the position of the nad */
                 NEXTINTBOUNDARY(offset);     /* adjust the pointer, one past this data */
                 itmp=stk[sptr-i2];           /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){
                   ok=0;
                   message=wait_insane(INSFTLERR," cat() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   i2-=3; /* data terms present */
                   EXT_REALLOC2(dv->val,dv->dalloc,dv->dlen+i2+1,(dv->dlen+MATHINC),sizeof(double),MEMOOPS);
                   for(i=i2;i>=0;i--,dv->dlen++){ dv->val[dv->dlen]=stk[sptr-i]; }
                   sptr-=3+i2;
                   stk[sptr]=dv->dlen;
                 }
                 break;
              case MATH_INI:
                 /* Note, returns number of entries after initialization */
                 NEXTINTBOUNDARY(offset);
                 i2=*(int *)&(dat[offset++]); /* retrieve the position of the nad */
                 NEXTINTBOUNDARY(offset);     /* adjust the pointer, one past this data */
                 itmp=stk[sptr-i2];           /* this could have been mangled */
                 if(ISNOTVAROFF(itmp)){
                   ok=0;
                   message=wait_insane(INSFTLERR," cat() is not operating on a variable");
                 }
                 else {
                   dv=&(omni->dvar[itmp]);
                   i2-=3; /* data terms present */
                   EXT_REALLOC2(dv->val,dv->dalloc,i2+1,(i2+1+MATHINC),sizeof(double),MEMOOPS);
                   for(dv->dlen=0,i=i2;i>=0;i--,dv->dlen++){ dv->val[dv->dlen]=stk[sptr-i]; }
                   sptr-=3+i2;
                   stk[sptr]=dv->dlen;
                 }
                 break;
#ifdef USETOK
              case MATH_TIX:
              case MATH_TCX:
                break;
              case MATH_TOK:
                sptr-=2;  /* ignore the range */
                itmp=stk[sptr]; /* this could have been mangled */
                if(ISNOTVAROFF(itmp)){
                 ok=0;
                 message=wait_insane(INSFTLERR," tok() is not operating on a variable");
                }
                else {
                  vv=omni->vn[itmp];
                  stk[sptr] = vv->tokcount;   
                }
                break;
              case MATH_TLN:  /* sum of lengths of a range of tokens, not counting delims or terminators */
                itmp=stk[sptr-2]; /* this could have been mangled */
                if(ISNOTVAROFF(itmp)){ 
                  message=wait_insane(INSFTLERR," tln() is not operating on a variable");
                  ok=0;
                }
                else {
                  vv=omni->vn[itmp];
                  move = realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], vv->tokcount);
                  if(move<=0){
                    ok=0;
                    message=wait_insane(INSFTLERR," tln() range is invalid");
                  }
                  else {
                    for(itmp=0,i=sstart;i<=send;i++){ itmp += vv->toklist[i].slen;}
                    sptr-=2;
                    stk[sptr] = itmp;   
                  }
                }
                break;
              case MATH_SLN:
                sptr-=2;  /* ignore the range */
                itmp=stk[sptr]; /* this could have been mangled */
                if(ISNOTVAROFF(itmp)){
                 ok=0;
                 message=wait_insane(INSFTLERR," sln() is not operating on a variable");
                }
                else {
                  vv=omni->vn[itmp];
                  stk[sptr] = ESP_CLEN(vv->dat_str);   
                }
                break;
#endif /* USETOK */
              case  MATH_MAP:
              case  MATH_UNMAP:
                insane(INSFTLPRGERR," MAP/UNMAP in RPN_SCALAR");
                break;
              case MATH_RND:  stk[sptr]   = round(stk[sptr]);                             break;
              case MATH_LID:  stk[sptr]   = 
                 (stk[sptr] >= 0. ? ceil(stk[sptr]) : floor(stk[sptr]));                  break;
              case MATH_TRC:  dtmp        = modf(stk[sptr],&stk[sptr]);                   break;
              default:
                insane(INSFTLPRGERR," unknown math case in run_math_rpn");
            }
            break;
          case MSTK_PSH:
          case MSTK_POP:
          case MSTK_NPSH:
            insane(INSFTLPRGERR," PSH/POP/NPSH found in run_math_rpn");
            break;
          case MSTK_DONE:
            ok=0;
            break;
          default: 
//fprintf(stdout,"DEBUG rpn unknown sop %s\n",show_stk_op(sop));
            insane(INSFTLPRGERR," unknown stack case in run_math_rpn");
        }
        break;
      case  RPN_NVEC_SELF:  /*rpnstate*/
        /* Since these act in situ on an array(range), the sptr is not adjusted */
        rpnstate = RPN_SCALAR; /* always reset */
        itmp=stk[sptr-2]; /* this should always be in range, RPN cannot alter the value */
        dv=&(omni->dvar[itmp]);
        move = realends(&dstart,&dend, (int) stk[sptr-1], (int) stk[sptr], dv->dlen);
        if(move <= 0){
          message=wait_insane(INSFTLERR," dst range is empty or not fully contained on variable");
          ok=0; break;
        }
        mop = dat[offset++]; /* only OPUSH in this context */
//fprintf(stdout,"DEBUG rpn mop %s NVEC_SELF\n",show_math_op(mop));
        switch(mop){
          case MATH_LOG:  
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = log(dv->val[dstart])/log(10.0);}
            break;
          case MATH_LN:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = log(dv->val[dstart]);}
            break;
          case MATH_E10:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = pow(10.0,(dv->val[dstart]));}
            break;
          case MATH_EE:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = pow(Euler,(dv->val[dstart]));}
            break;
          case MATH_CHS:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = -(dv->val[dstart]);}
            break;
          case MATH_ABS:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = 
              (dv->val[dstart] < 0 ? -dv->val[dstart] : dv->val[dstart]); }
            break;
          case MATH_SIN:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = sin(dv->val[dstart]);}
            break;
          case MATH_COS:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = cos(dv->val[dstart]);}
            break;
          case MATH_TAN:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = tan(dv->val[dstart]);}
            break;
          case MATH_ASIN:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = asin(dv->val[dstart]);}
            break;
          case MATH_ACOS:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = acos(dv->val[dstart]);}
            break;
          case MATH_ATAN:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = atan(dv->val[dstart]);}
            break;
          case MATH_SINH:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = sinh(dv->val[dstart]);}
            break;
          case MATH_COSH:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = cosh(dv->val[dstart]);}
            break;
          case MATH_TANH:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = tanh(dv->val[dstart]);}
            break;
          case MATH_D2R:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = 2.0*Pi*dv->val[dstart]/360.0; }
            break;
          case MATH_R2D:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = 360.0*dv->val[dstart]/(2.0*Pi);}
            break;
          case MATH_BITNOT:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = ~DBL2UINT32(dv->val[dstart]);}
            break;
          case MATH_RND:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = round(dv->val[dstart]);}
            break;
          case MATH_LID:
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = 
               (dv->val[dstart] >= 0. ? ceil(dv->val[dstart]) : floor(dv->val[dstart])); }
            break;
          case MATH_TRC:
            for(i2=0;i2<move;i2++,dstart++){ dtmp = modf(dv->val[dstart],&dv->val[dstart]);}
            break;
          case MATH_NOP: /* NO OP, do nothing */
          case MATH_NNONE: 
          case MATH_NONE: 
          case MATH_LD_STATE:
          case MATH_LD_ELEM:
          case MATH_SV_ELEM:
          case MATH_SV_ZERO:
#ifdef USETOK
          case MATH_LD_TOKEN:
#endif /* USETOK */
          case MATH_ADD:                                   
          case MATH_SUB:                       
          case MATH_MUL:                       
          case MATH_DIV:                       
          case MATH_MOD:
          case MATH_POW:
          case MATH_CMP:
          case MATH_MAX:
          case MATH_MIN:
          case MATH_BITAND:
          case MATH_BITOR:
          case MATH_BITXOR:
          case MATH_BITSHL:
          case MATH_BITSHR:
          case MATH_DLEN:
          case MATH_SUM:
          case MATH_SM2:
          case MATH_NML:
          case MATH_INV:
          case MATH_DEL:
          case MATH_IDX:
          case MATH_SRT:
          case MATH_SIX:
          case MATH_DIM:
          case MATH_CAT:
          case MATH_INI:
#ifdef USETOK
          case MATH_TIX:
          case MATH_TCX:
          case MATH_TOK:
          case MATH_TLN:
          case MATH_SLN:
#endif /* USETOK */
          case MATH_MAP:
          case MATH_UNMAP:
            insane(INSFTLPRGERR," operator invalid in RPN NVEC_SELF context");
            break;
          default:
            insane(INSFTLPRGERR," unknown math case in run_math_rpn");
        }
        
        
        
        break;
      case  RPN_NVEC_SCALAR:  /*rpnstate*/
        rpnstate = RPN_SCALAR; /* always reset */
        itmp=stk[sptr-3]; /* this should always be in range, RPN cannot alter the value */
        dv=&(omni->dvar[itmp]);
        dtmp=stk[sptr];
        move = realends(&dstart,&dend, (int) stk[sptr-2], (int) stk[sptr-1], dv->dlen);
        if(move <= 0){
          message=wait_insane(INSFTLERR," dst range is empty or not fully contained on variable");
          ok=0; break;
        }
        sptr-=1;
        /* only OPUSH is ever used here , so don't test sop */
        mop      = dat[offset]; offset++;
//fprintf(stdout,"DEBUG rpn mop %s NVEC_SCALAR\n",show_math_op(mop));
        switch(mop){
          case MATH_SV_ELEM:   /* store constant into each element */
            for(i2=0;i2<move;i2++,dstart++){ dv->val[dstart] = dtmp; }
            sptr-=2;  /* reduces to a single value */
            stk[sptr] = move;
            break;
          case MATH_ADD:  
            for(;move;move--,dstart++,sstart++){dv->val[dstart] += dtmp; }
            break;                                     
          case MATH_SUB:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] -= dtmp; }
            break;                                     
          case MATH_MUL:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] *= dtmp; }
            break;                                     
          case MATH_DIV:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] /= dtmp; }
            break;                                     
          case MATH_MOD:
            for(;move;move--,dstart++,sstart++){
              dv->val[dstart] = modf(dv->val[dstart]/dtmp,&dtmp2);
            }
            break;                                     
          case MATH_POW:
            for(;move;move--,dstart++,sstart++){  dv->val[dstart] = 
              pow(dv->val[dstart],dtmp);
            }
            break;                                     
          case MATH_CMP:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dv->val[dstart] > dtmp ?  1.0 :
                 (dv->val[dstart] < dtmp ? -1.0 : 0 ) ); 
            }         
            break;                                     
          case MATH_MAX: 
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dv->val[dstart] > dtmp ?  dv->val[dstart] : dtmp );
            }         
            break;                                     
          case MATH_MIN: 
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dv->val[dstart] < dtmp ?  dv->val[dstart] : dtmp );
            }         
            break;                                     
          case MATH_BITAND:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) &  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_BITOR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) |  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_BITXOR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) ^  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_BITSHL:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) <<  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_BITSHR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) >>  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_NOP: /* NO OP, do nothing */
          case MATH_NNONE: 
          case MATH_NONE: 
          case MATH_LD_STATE:
          case MATH_LD_ELEM:
          case MATH_SV_ZERO:
          case MATH_LOG: 
          case MATH_LN:  
          case MATH_E10: 
          case MATH_EE:  
          case MATH_CHS: 
          case MATH_ABS: 
          case MATH_SIN: 
          case MATH_COS: 
          case MATH_TAN: 
          case MATH_ASIN:
          case MATH_ACOS:
          case MATH_ATAN:
          case MATH_SINH: 
          case MATH_COSH: 
          case MATH_TANH: 
          case MATH_D2R: 
          case MATH_R2D: 
          case MATH_BITNOT:
          case MATH_DLEN:
          case MATH_SUM:
          case MATH_SM2:
          case MATH_NML:
          case MATH_INV:
          case MATH_DEL:
          case MATH_IDX:
          case MATH_SRT:
          case MATH_SIX:
          case MATH_DIM:
          case MATH_CAT:
          case MATH_INI:
#ifdef USETOK
          case MATH_LD_TOKEN:
          case MATH_TIX:
          case MATH_TCX:
          case MATH_TOK:
          case MATH_TLN:
          case MATH_SLN:
#endif /* USETOK */
          case MATH_MAP:
          case MATH_UNMAP:
          case MATH_RND:
          case MATH_LID:
          case MATH_TRC:
            insane(INSFTLPRGERR," invalid op for NVEC_SCALAR");
            break;
          default:
            insane(INSFTLPRGERR," unknown math case in run_math_rpn");
        }
        break;
      case  RPN_SCALAR_NVEC:  /*rpnstate*/
        rpnstate = RPN_SCALAR; /* always reset */
        itmp=stk[sptr-2]; /* this should always be in range, RPN cannot alter the value */
        dv=&(omni->dvar[itmp]);
        dtmp=stk[sptr-3];
        move = realends(&dstart,&dend, (int) stk[sptr-1], (int) stk[sptr-0], dv->dlen);
        if(move <= 0){
          message=wait_insane(INSFTLERR," dst range is empty or not fully contained on variable");
          ok=0; break;
        }
        /* put the array where it is supposed to be and address the stack pointer */
        stk[sptr-3]=stk[sptr-2];
        stk[sptr-2]=stk[sptr-1];
        stk[sptr-1]=stk[sptr-0];
        sptr-=1;
        /* only OPUSH is ever used here , so don't test sop */
        mop      = dat[offset]; offset++;
//fprintf(stdout,"DEBUG rpn mop %s NVEC_SCALAR_NVEC\n",show_math_op(mop));
        switch(mop){
          case MATH_ADD:  
            for(;move;move--,dstart++,sstart++){dv->val[dstart] += dtmp; }
            break;                                     
          case MATH_SUB:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] = dtmp - dv->val[dstart]; }
            break;                                     
          case MATH_MUL:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] *= dtmp; }
            break;                                     
          case MATH_DIV:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] = dtmp / dv->val[dstart]; }
            break;                                     
          case MATH_MOD:
            for(;move;move--,dstart++,sstart++){
              dv->val[dstart] = modf(dtmp/dv->val[dstart],&dtmp2);
            }
            break;                                     
          case MATH_POW:
            for(;move;move--,dstart++,sstart++){  dv->val[dstart] = 
              pow(dtmp,dv->val[dstart]);
            }
            break;                                     
          case MATH_CMP:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dtmp > dv->val[dstart] ?  1.0 :
                 (dtmp < dv->val[dstart] ? -1.0 : 0 ) ); 
            }         
            break;                                     
          case MATH_MAX: 
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dv->val[dstart] > dtmp ?  dv->val[dstart] : dtmp );
            }         
            break;                                     
          case MATH_MIN: 
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dv->val[dstart] < dtmp ?  dv->val[dstart] : dtmp );
            }         
            break;                                     
          case MATH_BITAND:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) &  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_BITOR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) |  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_BITXOR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) ^  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_BITSHL:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) <<  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_BITSHR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) >>  DBL2UINT32(dtmp);
            }         
            break;                                     
          case MATH_NOP: /* NO OP, do nothing */
          case MATH_NNONE: 
          case MATH_NONE: 
          case MATH_LD_STATE:
          case MATH_LD_ELEM:
          case MATH_SV_ZERO:
          case MATH_SV_ELEM:
          case MATH_LOG: 
          case MATH_LN:  
          case MATH_E10: 
          case MATH_EE:  
          case MATH_CHS: 
          case MATH_ABS: 
          case MATH_SIN: 
          case MATH_COS: 
          case MATH_TAN: 
          case MATH_ASIN:
          case MATH_ACOS:
          case MATH_ATAN:
          case MATH_SINH: 
          case MATH_COSH: 
          case MATH_TANH: 
          case MATH_D2R: 
          case MATH_R2D: 
          case MATH_BITNOT:
          case MATH_DLEN:
          case MATH_SUM:
          case MATH_SM2:
          case MATH_NML:
          case MATH_INV:
          case MATH_DEL:
          case MATH_IDX:
          case MATH_SRT:
          case MATH_SIX:
          case MATH_DIM:
          case MATH_CAT:
          case MATH_INI:
#ifdef USETOK
          case MATH_LD_TOKEN:
          case MATH_TIX:
          case MATH_TCX:
          case MATH_TOK:
          case MATH_TLN:
          case MATH_SLN:
#endif /* USETOK */
          case MATH_MAP:
          case MATH_UNMAP:
          case MATH_RND:
          case MATH_LID:
          case MATH_TRC:
             insane(INSFTLPRGERR," invalid op for SCALAR_NVEC");
             break;
          default:
            insane(INSFTLPRGERR," unknown math case in run_math_rpn");
        }
        break;
      case  RPN_NVEC_NVEC:  /*rpnstate*/
        rpnstate = RPN_SCALAR; /* always reset */
        itmp=stk[sptr-5]; /* this should always be in range, RPN cannot alter the value */
        i2=stk[sptr-2];   /* this should always be in range, RPN cannot alter the value */
        dv=&(omni->dvar[itmp]);
        dv2=&(omni->dvar[i2]);
        move = realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], dv2->dlen);
        if(move <= 0){
          message=wait_insane(INSFTLERR," src range is empty or not fully contained on variable");
          ok=0; break;
        }
        if(move != realends(&dstart, &dend, (int) stk[sptr-4], (int) stk[sptr-3], dv->dlen)){
          message=wait_insane(INSFTLERR," dst range is wrong size, empty, or not fully contained on variable");
          ok=0; break;
        }
        if(i2==itmp && (dstart > sstart && dstart <=send)){
          message=wait_insane(INSFTLERR," offset and overlapping self->self src->dst ranges will corrupt data");
          ok=0; break;
        }
        /* only OPUSH is ever used here , so don't test sop */
        sptr-=3;
        mop      = dat[offset]; offset++;
//fprintf(stdout,"DEBUG rpn mop %s NVEC_NVEC\n",show_math_op(mop));
        switch(mop){
          case MATH_SV_ELEM:   /* range from one vector to another.  Sizes must match */
             memmove(&dv->val[dstart],&dv2->val[sstart],SOD * move);
             /* What should the stack value be?  Number of terms copied */
             sptr-=2; stk[sptr] = move;                                break;
          case MATH_ADD:  
            for(;move;move--,dstart++,sstart++){dv->val[dstart] += dv2->val[sstart]; }
            break;                                     
          case MATH_SUB:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] -= dv2->val[sstart]; }
            break;                                     
          case MATH_MUL:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] *= dv2->val[sstart]; }
            break;                                     
          case MATH_DIV:                        
            for(;move;move--,dstart++,sstart++){dv->val[dstart] /= dv2->val[sstart]; }
            break;                                     
          case MATH_MOD:
            for(;move;move--,dstart++,sstart++){
              dv->val[dstart] = modf(dv->val[dstart]/dv2->val[sstart],&dtmp);
            }
            break;                                     
          case MATH_POW:
            for(;move;move--,dstart++,sstart++){  dv->val[dstart] = 
              pow(dv->val[dstart],dv2->val[sstart]);
            }
            break;                                     
          case MATH_CMP:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dv->val[dstart] > dv2->val[sstart] ?  1.0 :
                 (dv->val[dstart] < dv2->val[sstart] ? -1.0 : 0 ) ); 
            }         
            break;                                     
          case MATH_MAX: 
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dv->val[dstart] > dv2->val[sstart] ?  dv->val[dstart] : dv2->val[sstart] );
            }         
            break;                                     
          case MATH_MIN: 
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                ( dv->val[dstart] < dv2->val[sstart] ?  dv->val[dstart] : dv2->val[sstart] );
            }         
            break;                                     
          case MATH_BITAND:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) &  DBL2UINT32(dv2->val[sstart]);
            }         
            break;                                     
          case MATH_BITOR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) |  DBL2UINT32(dv2->val[sstart]);
            }         
            break;                                     
          case MATH_BITXOR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) ^  DBL2UINT32(dv2->val[sstart]);
            }         
            break;                                     
          case MATH_BITSHL:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) <<  DBL2UINT32(dv2->val[sstart]);
            }         
            break;                                     
          case MATH_BITSHR:
            for(;move;move--,dstart++,sstart++){ dv->val[dstart] = 
                DBL2UINT32(dv->val[dstart]) >>  DBL2UINT32(dv2->val[sstart]);
            }         
            break;                                     
          case  MATH_MAP: /* a[i] = a[b[i]] */
            EXT_REALLOC2(dv->val,dv->dalloc,2*(dv->dlen),(2*(dv->dlen)+MATHINC),sizeof(double),MEMOOPS);
            memcpy(&dv->val[dv->dlen],dv->val,SOD*dv->dlen);  /* keep a copy */
            for(;move;move--,dstart++,sstart++){
              itmp= dv2->val[sstart];
              if(1!=realends(&i2, &i2, itmp, itmp, dv->dlen)){
                 message=wait_insane(
                  INSFTLERR," map() range is not fully contained in dst variable");
                 move=ok=0; break;
              }
              dv->val[dstart] =  dv->val[i2 + dv->dlen]; /* pull from the copy */
            }         
            break;                                     
          case  MATH_UNMAP: /* a[b[i]]  = a[i] */
            EXT_REALLOC2(dv->val,dv->dalloc,2*(dv->dlen),(2*(dv->dlen)+MATHINC),sizeof(double),MEMOOPS);
            memcpy(&dv->val[dv->dlen],dv->val,SOD*dv->dlen);  /* keep a copy */
            for(;move;move--,dstart++,sstart++){
              itmp= dv2->val[sstart];
              if(1!=realends(&i2, &i2, itmp, itmp, dv->dlen)){
                 message=wait_insane(
                  INSFTLERR," ump() range is not fully contained in dst variable");
                 move=ok=0; break;
              }
              dv->val[i2] =  dv->val[sstart+dv->dlen]; /* pull from the copy */
            }         
            break;                                                   
          case MATH_NOP: /* NO OP, do nothing */
          case MATH_NNONE: 
          case MATH_NONE: 
          case MATH_LD_STATE:
          case MATH_LD_ELEM:
          case MATH_SV_ZERO:
          case MATH_LOG: 
          case MATH_LN:  
          case MATH_E10: 
          case MATH_EE:  
          case MATH_CHS: 
          case MATH_ABS: 
          case MATH_SIN: 
          case MATH_COS: 
          case MATH_TAN: 
          case MATH_ASIN:
          case MATH_ACOS:
          case MATH_ATAN:
          case MATH_SINH: 
          case MATH_COSH: 
          case MATH_TANH: 
          case MATH_D2R: 
          case MATH_R2D: 
          case MATH_BITNOT:
          case MATH_DLEN:
          case MATH_SUM:
          case MATH_SM2:
          case MATH_NML:
          case MATH_INV:
          case MATH_DEL:
          case MATH_IDX:
          case MATH_SRT:
          case MATH_SIX:
          case MATH_DIM:
          case MATH_CAT:
          case MATH_INI:
#ifdef USETOK
          case MATH_LD_TOKEN:
          case MATH_TIX:
          case MATH_TCX:
          case MATH_TOK:
          case MATH_TLN:
          case MATH_SLN:
#endif /* USETOK */
          case MATH_RND:
          case MATH_LID:
          case MATH_TRC:
             insane(INSFTLPRGERR," invalid op for NVEC_NVEC");
             break;
          default:
            insane(INSFTLPRGERR," unknown math case in run_math_rpn");
        }
        break;
#ifdef USETOK
      case  RPN_NVEC_SVEC: /*rpnstate*/
        rpnstate = RPN_SCALAR; /* always reset */
        itmp=stk[sptr-5]; /* this should always be in range, RPN cannot alter the value */
        i2=stk[sptr-2];   /* this should always be in range, RPN cannot alter the value */
        dv=&(omni->dvar[itmp]);
        vv=omni->vn[i2];
        move = realends(&sstart,&send, (int) stk[sptr-1], (int) stk[sptr], vv->tokcount);
        if(move <= 0){
          message=wait_insane(INSFTLERR," src range is empty or not fully contained on variable");
          ok=0; break;
        }
        if(move != realends(&dstart, &dend, (int) stk[sptr-4], (int) stk[sptr-3], dv->dlen)){
          message=wait_insane(INSFTLERR," dst range is wrong size, empty, or not fully contained on variable");
          ok=0; break;
        }
        /* only OPUSH is ever used here , so don't test sop */
        mop      = dat[offset]; offset++;
//fprintf(stdout,"DEBUG rpn mop %s NVEC_SVEC\n",show_math_op(mop));
        switch(mop){
          case MATH_SV_ELEM:
            for(itmp=dstart,i2=sstart;i2<=send;i2++,itmp++){
              tok=&(vv->toklist[i2]);
              if(tok->slen >= 255){
                message=wait_insane(INSFTLERR," string variable too large, cannot be a number");
                ok=0; break;
              }
              (void)strncpy(scratch,&(vv->dat_str->string[tok->start]),tok->slen);
              scratch[tok->slen]='\0';
              dtmp=numeric_input(scratch,&to);
              if(!to || *to != '\0'){ dtmp=NAN; }
              dv->val[itmp]=dtmp;
            }
            /* What should the stack value be?  Number of terms converted */
            stk[sptr-5] = move;                                sptr-=5; break;
          case MATH_TIX:  /* sort text ascending, case sensitive, store destinations in numeric */
            for(i=sstart,j=dstart;j<=dend;j++,i++){ dv->val[j]=i;} /* preset the positions, note 0 offset! */
            smuggle     = vv->toklist; /* provides access inside qsort to the token data, indirectly */
            smuggle_str = (char *)vv->dat_str; /* provides access inside qsort to the basis string, indirectly */
            qsort((void *)&dv->val[dstart],dend-dstart+1,SOD,compare_tix);
            for(j=dstart;j<=dend;j++){ dv->val[j]++;} /* change to array indices, 1->N */
            sptr-=5;
            stk[sptr] = 0.0;  /* returns zero */
            break;
          case MATH_TCX:  /* sort text ascending, case sensitive, store destinations in numeric */
            for(i=sstart,j=dstart;j<=dend;j++,i++){ dv->val[j]=i;} /* preset the positions, note 0 offset! */
            smuggle     = vv->toklist; /* provides access inside qsort to the token data, indirectly */
            smuggle_str = (char *)vv->dat_str; /* provides access inside qsort to the basis string, indirectly */
            qsort((void *)&dv->val[dstart],dend-dstart+1,SOD,compare_tcx);
            for(j=dstart;j<=dend;j++){ dv->val[j]++;} /* change to array indices, 1->N */
            sptr-=5;
            stk[sptr] = 0.0;  /* returns zero */
            break;
          default:
            message=wait_insane(INSFTLERR," invalid RPN op in NVEC_SVEC context");
            ok=0;
        }
        break;
#endif /* USETOK */
      default:
        insane(INSFTLPRGERR," invalid RPN context");
    }
//dump_rstack(stk,sptr); /* DEBUG */
  }
  *result=stk[0];
  return(message);
}

void show_help(void){
  fprintf(stdout,"Simple calculator.  Commands are:\n");
  fprintf(stdout,"  help,h,?   show this message\n");
  fprintf(stdout,"  hexp       show syntax for math expressions\n");
  fprintf(stdout,"  =A         store last result in variable A (range A-Z)\n");
  fprintf(stdout,"  >A         add an element to array A and store last result in it\n");
  fprintf(stdout,"  <A         list all values in A\n");
  fprintf(stdout,"  >>Name     store the last operation as 'Name'\n");
  fprintf(stdout,"  <<Name     run stored operation 'Name'\n");
  fprintf(stdout,"  xxName     delete stored operation 'Name'\n");
  fprintf(stdout,"  ??         list the stored operations\n");
  fprintf(stdout,"  [no]echo   echo input to output (instead of just results)\n");
  fprintf(stdout,"  digits #   number of required digits for integer output types\n");
  fprintf(stdout,"             number of digits after the decimal (default is 6) for floating point types\n");
  fprintf(stdout,"  sci,eng    output in scientific/engineering floating point notation\n");
  fprintf(stdout,"  sint,uint,oint,xint\n");
  fprintf(stdout,"             output in integer notation. Signed decimal, unsigned decimal, octal, hex\n");
  fprintf(stdout,"  pnz,nnz    print -0 as 0/-0 in scientific/engineering notation\n");
  fprintf(stdout,"  expression (enter hexp for syntax. Example: 1+5^3)\n");
  fprintf(stdout,"  info       show version and copyright information\n");
  fprintf(stdout,"  exit,quit  exit program\n");
  fprintf(stdout,"\n");
}

/* string functions are not documented, even if compiled in */
void show_hexp(void){
  fprintf(stdout,"Math expression syntax:\n");
  fprintf(stdout,"  The previous result may be loaded as $-, but $- cannot be assigned.\n");
  fprintf(stdout,"  Variables: $A-$Z, case insensitive, hold 1 or many values.\n");
  fprintf(stdout,"    If used as an array 1->N index from start, -1->-N from end.\n");
  fprintf(stdout,"  Scalar and Array math:  Unless otherwise noted operators and functions will\n");
  fprintf(stdout,"    work with either scalar or array operands.  If array operands are used\n");
  fprintf(stdout,"    the result will also be an array, with intermediate values stored in the\n");
  fprintf(stdout,"    leftmost array at each operation.  In scalar math the result\n");
  fprintf(stdout,"    value is meaningful, but it is not in array math. \n");
  fprintf(stdout,"  Operands:\n");
  fprintf(stdout,"    12e-1,120,0xF0,0o77,0b1010 \n");
  fprintf(stdout,"                         numbers in float, integer, hexadecimal, octal, or binary formats\n");
  fprintf(stdout,"    $A                   variable ($A is the same as $A[1])\n");
  fprintf(stdout,"    $A[12],$A[3,4],$A[]  One element, range of elements, all elements\n");
  fprintf(stdout,"  Assignment:\n");
  fprintf(stdout,"    $A[6] = 1+$B[$C[3]]  to an element\n");
  fprintf(stdout,"    $A[1,2]=$B[3,4]      to a range of elements (number must match)\n");
  fprintf(stdout,"    $A[]=3               to an entire array\n");
  fprintf(stdout,"  Operators: $A OP $B\n");
  fprintf(stdout,"    +,-,*,/              addition,subtraction,multiplication,division\n");          
  fprintf(stdout,"    %%                    remainder\n");          
  fprintf(stdout,"    ^                    power\n");          
  fprintf(stdout,"    ?                    compare (1,0,-1 if $A <,==,> $B) \n");       
  fprintf(stdout,"  Functions($A)\n");
  fprintf(stdout,"    log,ln               base 10 and natural logs\n");         
  fprintf(stdout,"    e10,ee               10^x and e^x\n");         
  fprintf(stdout,"    chs                  change sign\n"); 
  fprintf(stdout,"    abs                  absolute value\n"); 
  fprintf(stdout,"    rnd                  round to nearest integer\n"); 
  fprintf(stdout,"    lid                  round away from zero to next integer\n");
  fprintf(stdout,"    trc                  round towards zero to next integer\n");
  fprintf(stdout,"    d2r,r2d              degrees <->radians\n");              
  fprintf(stdout,"    sin,cos,tan,asin,acos,atan   Standard Trig. Functions\n");              
  fprintf(stdout,"    sinh,cosh,tanh               Hyperbolic Functions\n");              
  fprintf(stdout,"    not                  bitwise not (unsigned integer)\n");              
  fprintf(stdout,"  Functions($A,$B)\n");
  fprintf(stdout,"    max,min   maximum,minimum of operands.\n");              
  fprintf(stdout,"    and,or,xor   bitwise and, or, xor (unsigned integer).\n");              
  fprintf(stdout,"    shl,shr   bitwise shift left/right (unsigned integer).\n");              
  fprintf(stdout,"  Functions($A,$B)  [array results only]\n");
  fprintf(stdout,"    map       $A[i]    = $A[$B[i] for all i in the range\n");              
  fprintf(stdout,"    ump       $A[$B[i]]= $A[i]    for all i in the range (unmap)] \n");              
  fprintf(stdout,"  Functions($A[])  [scalar results only]\n");
  fprintf(stdout,"    len       Length of array (number of elements)\n");              
  fprintf(stdout,"    sum       Sum of array elements\n");              
  fprintf(stdout,"    sm2       Sum of array elements squared\n");              
  fprintf(stdout,"    inv       Invert order of terms in range,  Returns 0.\n");              
  fprintf(stdout,"    del       Delete terms in range.  returns elements remaining.\n");              
  fprintf(stdout,"              (If all, variable is reset to one element with value zero.)\n");              
  fprintf(stdout,"    idx       Replace elements with their array positions (1-N).  Returns 0.\n");              
  fprintf(stdout,"    srt       Sort elements into ascending order.  Returns 0.\n");              
  fprintf(stdout,"    six       Replace elements with the positions they would occupy\n");              
  fprintf(stdout,"              if sorted into ascending order.  Ie {5,10,-21} -> {2,3,1}. Returns 0.\n");              
  fprintf(stdout,"    nml       Test for normal numbers. 0=all elements normal, 1=at least one\n");              
  fprintf(stdout,"              infinite, 2=at least one NaN, 3=some infinite and some NaN\n");              
  fprintf(stdout,"  Functions($A[],value)  [scalar results only]\n");
  fprintf(stdout,"    dim       (Re)size $A to value entries.  New elements = 0.0. Returns 0.\n");              
  fprintf(stdout,"  Functions($A[],val1,val2,...)  [scalar results only]\n");
  fprintf(stdout,"    cat       Add values as new elements to $A, returns new length.\n");              
  fprintf(stdout,"    ini       (Re)initialize $A with values as elements, returns (new) length.\n");              
  fprintf(stdout,"  Operator Precedence:\n");
  fprintf(stdout,"    ^  >  */%%  >  +-  >  ? > , > () > =\n");  
  fprintf(stdout,"  Examples:\n");
  fprintf(stdout,"  (5/ee(5)) + $A[-1] \n");
  fprintf(stdout,"         RESULT=(5 divided by e^5) + contents of last element in array $A\n");
  fprintf(stdout,"  $A = log(3+$B[6])\n");
  fprintf(stdout,"         RESULT=(expression), and is also stored in $A[1]\n");
  fprintf(stdout,"  $A[] = -$-\n");
  fprintf(stdout,"         RESULT=(negative of previous result), also fill $A[] with that value.\n");
  fprintf(stdout,"  dim($A[],5)+idx($A[])+sum(log($A[]))\n");
  fprintf(stdout,"         RESULT=sum of the logs of 1->5. log(1)->log(5) are stored in\n");
  fprintf(stdout,"         $A elements 1->5.  (This works because dim and idx return 0.0\n");
  fprintf(stdout,"         and the addition operands are processed left to right.)\n");
  fprintf(stdout,"  log(max($A[1,4]*2.1,$B[3,6]))\n");
  fprintf(stdout,"         RESULT=(not meaningful).  Multiply all elements in array $A[1,4]\n");
  fprintf(stdout,"         by 2.1 and store in place.  Take the maximum with the corresponding\n");
  fprintf(stdout,"         elements (1->3, 2->4..4->6) of $B and store back into $A,  Then take\n");
  fprintf(stdout,"         the log of each element in the range and store that in place too.\n");
  fprintf(stdout,"         Only elements 1->4 of $A are modified.\n");
  fprintf(stdout,"\n");
}

/* remove all spaces from a string, return the final C length */
int despace(char *string){
char *from;
char *to;
int i;
  for(to=from=string,i=0; ;from++){
    *to=*from;
    if(*from != ' '){ to++; i++; }
    if(!*from){ i--; break; }
  }
  return(i);
}

/* find the name and first available slot.  Returns position if name
was found, -1 otherwise.  Returns position of hole if one was wound, otherwise
-1. */
int find_stored(SPLNEXUS *stored_progs, char *name, int slen, int *hole){
int      i;
int      status=-1;
SPNEXUS *sp;

  *hole=-1;
  slen=despace(name);
  for(i=0;i<stored_progs->slen;i++){
    sp=&stored_progs->list[i];
    if(sp->name){
      if((strlen(sp->name) == slen) &&
         !lstrcasecmp(sp->name,slen,name,slen)){
         status=i;
         break;
      }
    }
    else {
      if(*hole==-1){ *hole=i; }
    }
  }
  return(status);
}

#ifdef USETOK
void setup_vn(OMNINEXUS *omni){
FMTNEXUS  *vv;
int        i,j,k;
  /* For testing purposes make up 5 string variables (a,b,c) with 3 tokens each, being
     "1  ,2  ,3  "
     "11 ,22 ,33 "
     "111,222,333"
     D, the 4th is for testing odd numeric conditions
     "foo, inf, +inf, -in, nan"
     E, the 5th, is for testing string sort to map
     "ab,cdef,abc,bcd,CDEE,def"
  */
  EXT_CALLOC(omni->vn, MYVARSMAX, sizeof(FMTNEXUS *),MEMOOPS);
  for(i=0;i<MYVARSMAX;i++){  /* allocate and clear all 26 */
    EXT_CALLOC(omni->vn[i],1, sizeof(FMTNEXUS),MEMOOPS);
  }
  for(j=1,i=0;i<3;i++){  /* the first 3 are defined as valid numbers */
    vv=omni->vn[i];
    vv->tokcount=3;
    EXT_CALLOC(vv->dat_str,1,sizeof(ESNEXUS),MEMOOPS);
    EXT_CALLOC(vv->dat_str->string,1,15,MEMOOPS);
    EXT_CALLOC(vv->toklist,3,sizeof(STRINGNEXUS),MEMOOPS);
    vv->dat_str->slen=12;
    vv->dat_str->salloc=15;
    vv->tokcount=3;
    vv->fldcount=1;
    sprintf(vv->dat_str->string,"%-3d,%-3d,%-3d",j,2*j,3*j);
    for(k=0;k<3;k++){
      vv->toklist[k].start=k*4;
      vv->toklist[k].slen=i+1;
    }
    j=10*j+1;
  }

  /* the fourth is a combination of odd numeric cases*/
  vv=omni->vn[3];
  vv->tokcount=3;
  EXT_CALLOC(vv->dat_str,1,sizeof(ESNEXUS),MEMOOPS);
  vv->dat_str->string=dup_str("fooinf+inf-infnan",32);
  vv->dat_str->slen=strlen(vv->dat_str->string)+1;
  vv->dat_str->salloc=32;
  vv->tokcount=5;
  EXT_CALLOC(vv->toklist,vv->tokcount,sizeof(STRINGNEXUS),MEMOOPS);
  vv->fldcount=1;
  vv->toklist[0].start=0; /* foo, a string which is in no sense a number */
  vv->toklist[0].slen=3;
  vv->toklist[1].start=3; /* inf,  is a valid double */
  vv->toklist[1].slen=3;
  vv->toklist[2].start=6; /* +inf, should be a valid double */
  vv->toklist[2].slen=4;
  vv->toklist[3].start=10; /* -inf, should be a valid double */
  vv->toklist[3].slen=4;
  vv->toklist[4].start=14; /* nan, sort of a valid double */
  vv->toklist[4].slen=3;

  /* the fifth are an assortment of nonnumeric strings*/
  vv=omni->vn[4];
  vv->tokcount=4;
  EXT_CALLOC(vv->dat_str,1,sizeof(ESNEXUS),MEMOOPS);
  vv->dat_str->string=dup_str("ab,cdef,abc,bcd,CDEE,def",32);
  vv->dat_str->slen=strlen(vv->dat_str->string)+1;
  vv->dat_str->salloc=32;
  vv->tokcount=6;
  EXT_CALLOC(vv->toklist,vv->tokcount,sizeof(STRINGNEXUS),MEMOOPS);
  vv->fldcount=1;
  vv->toklist[0].start=0; /* ab */
  vv->toklist[0].slen=2;
  vv->toklist[1].start=3; /* cdef */
  vv->toklist[1].slen=4;
  vv->toklist[2].start=8; /* abc */
  vv->toklist[2].slen=3;
  vv->toklist[3].start=12; /* bcd */
  vv->toklist[3].slen=3;
  vv->toklist[4].start=16; /* CDEE */
  vv->toklist[4].slen=4;
  vv->toklist[5].start=21; /* def */
  vv->toklist[5].slen=3;
}
#endif /* USETOK */

#define MAXCOMLEN 4096
int main(int argc, char *argv[]){
ESNEXUS   *mprog=NULL;
ESNEXUS   *rpnprog=NULL;
OMNINEXUS *omni;
DVNEXUS   *dv;
SPLNEXUS  *stored_progs;
SPNEXUS   *one_sp;
int        i;
char      *sprog=NULL;
int        sprog_len;
char      *last_sprog=NULL;
//double    *stk=NULL;
//int        stk_alloc=0;
int        ok=1;
int        hole;
int        itmp;
double     result;
char      *message;
int        digits=6;            /* default # of digits after the decimal */
int        scieng=OUT_FMT_ENG;  /* (see OUT_FMT_* above for meanings  */
int        echo=0;              /* if set, echo input to output          */
int        nz=0;                /* format negative zero as 0, if set, as -0 */
double     dlim=5*pow(10.0,-(digits+1));
;

  EXT_CALLOC(sprog,1,MAXCOMLEN,MEMOOPS);
  EXT_CALLOC(rpnprog,1,sizeof(ESNEXUS),MEMOOPS);
  EXT_CALLOC(omni,1, sizeof(OMNINEXUS),MEMOOPS);
  EXT_CALLOC(omni->dvar,26,sizeof(DVNEXUS),MEMOOPS);
  /* initialize the lot of them as single entry arrays */
  for(i=0;i<MYVARSMAX;i++){
    dv=&(omni->dvar[i]);
    EXT_CALLOC(dv->val,1,sizeof(double),MEMOOPS);
    dv->dlen=1;
    dv->dalloc=1;
  }
  EXT_CALLOC(omni->stk,1, sizeof(DVNEXUS),MEMOOPS);
  EXT_CALLOC(omni->pstk,1, sizeof(MSLNEXUS),MEMOOPS);
  EXT_CALLOC(stored_progs,1, sizeof(SPLNEXUS),MEMOOPS);
#ifdef USETOK
  setup_vn(omni);
#endif /* USETOK */
  
  while(ok){
    if(!fgets(sprog, MAXCOMLEN, stdin)){insane(INSFTLERR," bad input read");}
      sprog_len=strlen(sprog);  /* is 1 for an empty line, holds EOL */
      sprog[--sprog_len]='\0';  /* eat the EOL */
      if(echo){ (void) fprintf(stdout,"%s",sprog); }
      if(!lstrcasecmp("note",4,sprog,4)){  fprintf(stdout,"# %s",&sprog[4]); }
      sprog_len=despace(sprog);

           if(!lstrcasecmp("help",  4,sprog,4)){  show_help(); }
      else if(!lstrcasecmp("hexp",  4,sprog,4)){  show_hexp(); }
      else if(!lstrcasecmp("h",     1,sprog,1)){  show_help(); }
      else if(!lstrcasecmp("nnz",   3,sprog,3)){  nz=1; dlim=5*pow(10.0,-(digits+1));   }
      else if(!lstrcasecmp("pnz",   3,sprog,3)){  nz=0;    }
      else if(!lstrcasecmp("sci",   3,sprog,3)){  scieng=OUT_FMT_SCI;               }
      else if(!lstrcasecmp("eng",   3,sprog,3)){  scieng=OUT_FMT_ENG;               }
      else if(!lstrcasecmp("sint",  4,sprog,4)){  scieng=OUT_FMT_DEC;               }
      else if(!lstrcasecmp("uint",  4,sprog,4)){  scieng=OUT_FMT_DEC | OUT_FMT_UNS; }
      else if(!lstrcasecmp("oint",  4,sprog,4)){  scieng=OUT_FMT_OCT | OUT_FMT_UNS; }
      else if(!lstrcasecmp("xint",  4,sprog,4)){  scieng=OUT_FMT_HEX | OUT_FMT_UNS; }
      else if(!lstrcasecmp("echo",  4,sprog,4)){  echo=1;      }
      else if(!lstrcasecmp("noecho",6,sprog,6)){  echo=0;      }
      else if(!lstrcasecmp("note",  4,sprog,4)){  fprintf(stdout,"# %s",&sprog[4]); }
      else if(!lstrcasecmp("#",     1,sprog,1)){  continue;    }
      else if(!lstrcasecmp(">>",2,sprog,2)){ 
        /* store the current RPN program.  If the name is already in use it is an error */
        i=find_stored(stored_progs,&sprog[2],sprog_len-2,&hole);
        if(i>=0){
          fprintf(stderr,"ERROR: program name already in use: %s\n",&sprog[2]); fflush(stderr);
        }
        else {
          if(hole<0){
            hole=stored_progs->slen;
            stored_progs->slen++;
            EXT_REALLOC2(stored_progs->list,stored_progs->salloc,
              stored_progs->slen,stored_progs->slen+MATHINC,sizeof(SPNEXUS),MEMOOPS);
          }
          one_sp=&stored_progs->list[hole];
          one_sp->name=dup_str(&sprog[2],sprog_len-2);
          one_sp->prog=dup_str(last_sprog, strlen(last_sprog)+1);
          EXT_MALLOC(one_sp->rpnprog,rpnprog->slen,MEMOOPS);
          memcpy(one_sp->rpnprog,rpnprog->string,rpnprog->slen);
          one_sp->slen=rpnprog->slen;
        }
      }
      else if(!lstrcasecmp("xx",2,sprog,2)){ 
        /* erase the specified program.*/
        i=find_stored(stored_progs,&sprog[2],sprog_len-2,&hole);
        if(i<0){
          fprintf(stderr,"ERROR: program not found %s\n",&sprog[2]); fflush(stderr);
        }
        else {
          one_sp=&stored_progs->list[i];
          free(one_sp->name);
          free(one_sp->prog);
          free(one_sp->rpnprog);
          one_sp->name = one_sp->prog = one_sp->rpnprog = NULL;
          /* slide the remainder, if any, down to fill the hole */
          if(i<stored_progs->slen-1){
           memmove(&stored_progs->list[i],&stored_progs->list[i+1],
             sizeof(SPNEXUS)*(stored_progs->slen-i));
          }
          stored_progs->slen--;
        }
      }
      else if(!lstrcasecmp("??",2,sprog,2)){ 
        /* list the programs (cannot show them).*/
        fprintf(stdout,"Stored programs: %d\n",stored_progs->slen);
        for(i=0;i<stored_progs->slen;i++){
          one_sp=&stored_progs->list[i];
          if(one_sp->name){fprintf(stdout,"%s: %s\n",one_sp->name,one_sp->prog);}
        }
      }
      else if(!lstrcasecmp("<<",2,sprog,2)){ 
        /* recall and run a stored rpn program */
        i=find_stored(stored_progs,&sprog[2],sprog_len-2,&hole);
        if(i>=0){
          one_sp=&stored_progs->list[i];
          memcpy(rpnprog->string,one_sp->rpnprog,one_sp->slen); /* will fit, rpnprog once held it */
          rpnprog->slen=one_sp->slen;
          message = run_math_rpn(omni,rpnprog->string,&result);
          if(message){
            fprintf(stderr,"ERROR: %s\n",message); free(message); fflush(stderr);
          }
          else {
            if(result != result){  fprintf(stdout,"ERROR\n");}/* must be NAN */
            else {                 fmt_numeric_output(stdout,nz,digits,scieng,result,dlim); }
            fflush(stdout);
            omni->result=omni->stk->val[0];
          }
        }
        else {
          fprintf(stderr,"ERROR: program not defined: %s\n",&sprog[2]); fflush(stderr);
        }
      }
      else if(!lstrcasecmp("info",4,sprog,4)){
        (void)fprintf(stderr,"Version:        %s\n",EXVERSTRING);
        (void)fprintf(stderr,"bugs to:        %s\n",BUGSTRING);
        (void)fprintf(stderr,"Copyright:      %s\n",COPYSTRING);
        (void)fprintf(stderr,"License:        %s\n",LICSTRING);
        (void)fprintf(stderr,"Number limits:\n");
        (void)fprintf(stderr,"  Sig. digits:  %d\n",DBL_DIG);
        (void)fprintf(stderr,"  Largest:      %le\n",DBL_MAX);
        (void)fprintf(stderr,"  Smallest:     %le\n",DBL_MIN);
        (void)fprintf(stderr,"Settings:\n");
        if(      scieng & OUT_FMT_ENG){ (void)fprintf(stderr,"  Notation:     Engineering\n");      }
        else if( scieng & OUT_FMT_SCI){ (void)fprintf(stderr,"  Notation:     Scientific\n");       }
        else if( scieng & OUT_FMT_HEX){ (void)fprintf(stderr,"  Notation:     Hexadecimal\n");      }
        else if( scieng & OUT_FMT_OCT){ (void)fprintf(stderr,"  Notation:     Octal\n");            }
        else if( scieng & OUT_FMT_UNS){ (void)fprintf(stderr,"  Notation:     Unsigned Integer\n"); }
        else                          { (void)fprintf(stderr,"  Notation:     Signed Integer\n");   }
        if(scieng & (OUT_FMT_ENG | OUT_FMT_SCI)){
           if(nz){   (void)fprintf(stderr,"  Show:         -0 as -0\n");    }
           else {    (void)fprintf(stderr,"  Show:         -0 as  0\n");    }
           (void)fprintf(stderr,"  Precision:    %d\n",digits);
        }
        else {
           (void)fprintf(stderr,"  Digits:       %d\n",digits);
        }
      }
      else if(!lstrcasecmp("digits",5,sprog,5)){
        if(1 != sscanf(&sprog[6],"%d",&itmp) || itmp < 0){
          fprintf(stderr,"ERROR: invalid digits command\n"); fflush(stderr);
        }
        else { digits = itmp; }
        dlim=5*pow(10.0,-(digits+1));
      }
      else if(!lstrcasecmp("?",1,sprog,1)){          show_help(); }
      else if(sprog[0] == '='){
        itmp=TOVAROFF(sprog[1]);
        if(ISNOTVAROFF(itmp)){
          fprintf(stdout,"dmath: warning: no such variable as $%c\n",sprog[1]);
        }
        else {
          omni->dvar[itmp].val[0]=result;
        }
      }
      else if(sprog[0] == '>' ){
        itmp=TOVAROFF(sprog[1]);
        if(ISNOTVAROFF(itmp)){
          fprintf(stdout,"dmath: warning: no such variable as $%c\n",sprog[1]);
        }
        else {
          dv=&(omni->dvar[itmp]);
          EXT_REALLOC2(dv->val,dv->dalloc,(dv->dlen+1),(dv->dlen+32),sizeof(double),MEMOOPS);
          dv->val[dv->dlen]=result;
          dv->dlen++;
        }
      }
      else if(sprog[0] == '<' ){
        itmp=TOVAROFF(sprog[1]);
        if(ISNOTVAROFF(itmp)){
          fprintf(stdout,"dmath: warning: no such variable as $%c\n",sprog[1]);
        }
        else {
          dv=&(omni->dvar[itmp]);
          for(i=0;i<dv->dlen;i++){
              fmt_numeric_output_array(stdout,nz,digits,scieng,i+1,dv->val[i],dlim);
          }
        }
      }
      else if(!lstrcasecmp("exit",4,sprog,4)){ ok = 0; }
      else if(!lstrcasecmp("quit",4,sprog,4)){ ok = 0; }
      else {
        if(last_sprog){ free(last_sprog); }
        last_sprog=dup_str(sprog,sprog_len+1);
        mprog = compile_math(sprog,&message); /* message set to NULL first thing in here */
        if(message){
          fprintf(stderr,"ERROR: %s\n",message); free(message); fflush(stderr);
        }
        else {
          message = pre_run_math(omni,mprog,rpnprog);
          if(message){
            fprintf(stderr,"ERROR: %s\n",message); free(message); fflush(stderr);
          }
          else {
            message = run_math_rpn(omni,rpnprog->string,&result);
            if(message){
              fprintf(stderr,"ERROR: %s\n",message); free(message); fflush(stderr);
            }
            else {
              if(result != result){  fprintf(stdout,"ERROR\n");}/* must be NAN */
              else {                 fmt_numeric_output(stdout,nz,digits,scieng,result,dlim); }
              fflush(stdout);
              omni->result=omni->stk->val[0];
            }
          }
        }
        if(mprog){ free(mprog->string); free(mprog); }
      }
      fflush(stdout); /* If not present in mingw then "help" emits nothing, unclear why */
  }
  if(last_sprog){ free(last_sprog); }
  if(omni->stk->val)free(omni->stk->val);
  if(omni->stk)free(omni->stk);
  for(i=0;i<MYVARSMAX;i++){
    dv=&(omni->dvar[i]);
    free(dv->val);
  }
#ifdef USETOK
  for(i=0;i<=4;i++){
    free(omni->vn[i]->dat_str->string);
    free(omni->vn[i]->dat_str);
    free(omni->vn[i]->toklist);
  }
  for(i=0;i<MYVARSMAX;i++){  free(omni->vn[i]); }
  free(omni->vn);
#endif /* USETOK */
  if(rpnprog->string)free(rpnprog->string);
  if(rpnprog)free(rpnprog);
  for(i=0;i<stored_progs->slen;i++){
    one_sp=&stored_progs->list[i];
    if(one_sp->name){
      free(one_sp->name);
      free(one_sp->prog);
      free(one_sp->rpnprog);
    }
  }
  if(stored_progs->list)free(stored_progs->list);
  free(stored_progs);
  free(omni->dvar);
  free(omni->pstk->list);
  free(omni->pstk);
  free(omni);
  free(sprog);
  
  exit(EXIT_SUCCESS);
}

