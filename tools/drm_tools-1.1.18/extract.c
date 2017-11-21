/*
Program:   extract.c
Version:   1.1.9
Date:      13-JUN-2013
Author:    David Mathog, Biology Division, Caltech
email:     mathog@caltech.edu
Copyright: 2013 David Mathog and California Institute of Technology (Caltech)

Description:

    Reads a text file from stdin and extracts a range of rows
    and columns (character positions) and sends them to lcl_stdout.
    Alternatively, acts on tokens.  Alternatively, removes the
    selected range instead of emitting it.
    
    "extract" is a lot simpler to use than awk or perl and sufficient for
    most column/row extraction tasks.  "extract" now has features for more 
    general pattern recognition and data extraction, which can be plenty complicated
    if you choose to employ them!

    See function emit_help for command line options.

    Compiles cleanly with:

     % gcc -Wall -pedantic -std=c99 -DMAXINFILE=20 -o extract extract.c -lm -lpcre
     
     change -DMAXINFILE=40  to increase the number of input
     files which may be processed.
     
     For solaris 8 there are some missing pieces in the system include files
     and libraries.  On that platform use:
     
     % gcc -DSOL8 -Wall -pedantic -std=c99 -DMAXINFILE=20 -o extract extract.c -lm -lpcre
     
     For debugging purposes, especially on new platforms, use -DCHKALN, which adds
     tests that Ints and Doubles are stored aligned in the alldata structure.  This
     seems not to matter on x86 platforms, but the Sparc was really unhappy trying to reference
     an int by pointer at an unaligned address.


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

  1.1.9 13-DEC-2012
         Introduced a bug with version 1.1.12 where an -mt -fmt like
         [1,3][4][5][6,] would only emit delimiters for ranges with > 1
         token.  Previously a series of concatenated ranges would all emit
         delimiters after the token  except for the very last delimiter.
         In other words, originally the condition was "emit all delimiters in
         consecutive tokens on the line except the last" and it became instead
         "emit all delimiters in consecutive tokens in a RANGE except the last".
  1.1.8 12-DEC-2012
         Fixed a bug, -rtds,-rtss,-rs etc. set on command line were not being applied
         as defaults in [] in an -op.
         Fixed a bug: -psN was not working in scripts in sections other than main.
         Fixed a bug: labels preceding a -psN in a script mangled the replacement field.
         Changed behavior of [5,-3] in an -op when the string was empty to match
         that of -fmt.  In a -fmt an empty string was appended (ie, nothing happened), but
         but in an -op [] it was a cleared variable error.  Now both do nothing.
         Added decimal, unsigned, hex, and octal formatted output modes.
         Added bitwise operators.  These take a double value (or values) convert it to 
         (u)int32_t, perform the operation, then convert back.
         Added =main label, so that scripts may be placed in any order - previously functions
         had to follow the "main" part, which was implicit. 
         Added more sanity checking on scripts - unreachable lines before first label are now an error.       
  1.1.7 21-NOV-2012.
         Fixed a bug caused by a patern line a[1]b\123c[1]d, which was
         truncating after the second [] because an attempt was made to
         correct for the length of the format string during parsing
         at the end of init_process_type after the escape sequence was
         processed.  However, this is no longer required because the format
         parsing keeps track of the chunks in their modified positions,and
         the overall length does not change.  (There may be some trailing
         nulls, which are harmless.)
  1.1.6 12-NOV-2012.
         Fixed compiler warnings recent gcc, variables set but not used.
  1.1.5 09-JUN-2011.
         Added method for controlling printing -0 as 0.  That becomes the
           default for engineering notation.
  1.1.4 07-JUN-2011.
         Fixed use of %lf in fprintf, not standard.  (Needed in scanf, but
         not appropriate in printf).
         Fixed bug in [rtds], was defaulting to var and not using immediate
           string in some cases.
         Modified "could not open" messages to show file names.
         Added -DCHKALN
         Added fix for Sol8 c89 log not testing like c99 log (no NAN).
  1.1.3 03-JUN-2011.
         Added solaris compatibility.  (There are some minor incompatibilities in the
           math libraries, mostly involving NANs that show up as -INF, that remain.)
         Fixed alignment problem (int off by 1 char) in fn_to_pal, caused segfault on Solaris.
         Fixed bug in MATH_CAT, MATH_INI, pulling an integer out as a byte, worked on Opteron
           but not Sparc.
  1.1.1 29-MAY-2011.
         Fixed problems in -ps.  It was doing the [] overrides but did not handle
           all of the other PATTERN/REPLACE options properly.  It also wasn't respecting
           ps-. -psN was OK, it was only -ps that was broken. 
         changed default multiple query match mode from FIRST to NEAREST.  First is
           a bit strange ie, search "1 3 1 2 3" with {1,2,3} and it finds 1,1,2,3,
           whereas nearest finds 1,2,3,1,2,3.  Farthest finds {2,3}, which is very
           counterintuititve (although perhaps useful in some instances).
  1.1.0 25-FEB-2011.  
         added -cmd (-eoc) FILE read more command line options from a file.
           Supports escapes and double quotes.  Lines beginning with # are
           comments, with _ (underscore) are read verbatim (one token on such a line,
           the leading underscore is stripped).
         added variable modes
         added PCRE support
         added pattern match support
         added minimal scripting support
         added multiple output streams
         added numeric variables and math operations
         moved parse options around.  There are now 10 (0->9) with 0 being the default
           one.
         added -rtsv (and associated rtsv modes in []).  Replacement string from
           variable (entire character string of variable, no token selection or ranges
           possible).
         Changed around realends to not use LOCINVALID anymore, but return a status instead.
         Changed STRINGNEXUS organization from start/send to start/slen.  This allowed
           easier representation of empty tokens as 0/0, especially in cases where
           tokens were being added onto the list.
         Changed postprocessing model.  Previously there was a big structure
           and for each piece the code would look at each option and then
           call the appropriate subroutine if set.  In the new model there
           is an "action list" where each entry consists of a structure
           with a pointer to the (casify, or whatever), and an offset
           into a common data storage structure, where the subroutine retrieves
           its data.  This way there are only as many tests as there are
           postprocessing options to apply.  If there is nothing special
           for a particular piece then the global action list is used instead.
         Fixed bug: \1345 (number too big) was inserting a random character
           before the number, instead of just eating the backslash.
         Fixed bug: [] was not defaulting to [1,-1].
         Fixed bug: -d- was not working, but [-d:] was.
         Fixed bug: -xc was not being checked in make_inp_tokens
         Changed: split -xe off from -xc
         Fixed bug: adjuststring for negative shift was reading to blen insted of clen.
           Too many operatioins and occasional access violations.
         Fixed bug: -unmerge had an access violation, 1 byte past the end of string
           (wasn't segfaulting as it seems to have fallen on other alloc'd memory.)
         Fixed bug: dqs was missing the case for 'foo "goo"', it was leaving the 
            double quotes on.  NOTE.  not well documented that -dq only works for
              [BOL|delimiter]"<string>"[EOL|delimiter
            [delim]ab"cd"[delim|EOL\ is ab"cd" even with -dq set, and
            ]delim]"cd"[NOT delim|EOL] is a fatal error.
d- was not working, but [-d:] was.
         Added: variables vA->vZ, -ifs condition, multiple -cols, conditional
            on -ifs.
         Modified - most references to -cols became references to -fmt
  1.0.39 12-APR-2010.  Fixed bugs:
         1. -fileeol was not active if -nr or -er terminates input before the 
             end of the file is reached.
         2. -merge emitted nothing when -sr/-er/-nr defined a single line.
         3. -merge emitted the last merged line twice if the input range ended
             on the last row of the input.
  1.0.38 24-JUL-2009.  Added -lt, emits token count per line
  1.0.37.1 24-JUL-2009.  Minor fix in the make_sort_map routine to prevent realloc error
         when sorted range has 0 tokens.
  1.0.37 22-JUL-2009.  Added sort options.  Only used in fields with ranges in -cols.
         sort[ad][csn], sort, Ascending/Descending, string(case/insensitive)/Numeric.  Sort occurs
         at the output stage before all other processing.  Numeric sort on anything that does not convert
         successfully to a DOUBLE is a fatal error.
         Changed processing of token delimiters so that for a string "a b c" the delimiter
           assigned to "c" is a space, the delimiter before it.  All other tokens still use the
           delimiter after. This tends to do the "right thing" when tokens are emitted in reversed order.
  1.0.36 09-JUL-2008.  Fixed a bug where long != int on 64 bit systems, caused problems with some
         calls to lstrol where an int was passed, and a long written, overwriting the adjacent int.
         Renamed fixupdelimit() to fixupescapes.Added \f (form feed) and \y  (vertical tab) support.
  1.0.35 03-JUL-2007.  Added -ba (add a backslash before EVERY character) and -b2
         (similar, except starting at the second character).  Added -ecc (change the
	 escape character, default is a backslash.)  Can be
         used in a pipe to create tab or comma
	 delimited output from single position values.
  1.0.34 23-OCT-2006.  Changed license to GPL 2.
  1.0.33 15-JUN-2006,
         In getnextline the handling of input=1,2,3 was broken if -eqlen wasn't
	 specified.  It would segfault on some platforms.  Of course, if -eqlen
	 isn't specified the columns move around unpredictably and the format of
	 the output lines is generally impossible to predict.  Added a warning
	 to stderr to emit shortest line info, but it keeps going.  Also crok 
	 wasn't being initialized to 1, but by pure luck it was always nonzero
	 so it never triggered the bug. Valgrind caught that.
  1.0.32 06-APR-2006,
         Removed unistd.h include, it was not needed.
  1.0.31 24-JAN-2006,
         Modified the behavior of -iftermeol.  If NEITHER -ifterm is
         present then, and ONLY then, the iftermeol string will be emitted at
         at the end of every if block (and the end of the file).  For files
         with simple syntaxes this provides an easier way to clean up line
         terminators than using iftermbol iftermeol with ifterm, which gets
         messy when if blocks start and end on the same line. 
         
         added -ifnorestart.  Previous behavior was 'restart' within if 
         blocks if a tag matched, this extended if blocks.  If this is set
         tags within an if block aren't tested for -if (but still for -ifterm
         if that was specified.)
  1.0.30 28-AUG-2005,
         Added -ll (emit line length)
  1.0.29 06-MAY-2005,
         Fixed bug in -template, uninitialized variable "remwidth"
  1.0.28 30-MAR-2005,
         Added -tr options (remove leading, trailing, both white space)
  1.0.27 15-MAR-2005,
         Fixed a bug in adjuststring affecting rtss, if it was longer than rtds
         the substitution was mangled.
         Changed the base IO model to use super_fgets() instead of fgets().  This
         allows better handling of embedded nulls in input streams.  
         Added 
           -hnr        (retain embedded nulls = DEFAULT)
           -hnd        (delete embedded nulls)
           -hns        (substitute embedded nulls)
           -hnsubs '|' (character to substitute for embedded NULL, defaults to 255)
           -hnsubs '\254'  (alternate form)
           -crok       (retain a CR before LF. Default is to delete it).
  1.0.26 22-SEP-2004,
         Added fileeol,filebol, a string emitted at the end of a file and at the beginning
	 of a file.
  1.0.25 03-JUN-2004,
         Fixed a bug in rtds, removing "-" from "a---b" -> "a-b", because it was removing
         every other one.  Similarly, -rtds '-' -rtss '.' on '---' went to '.-.'
  1.0.24 15-JAN-2004,
         Fixed access violation on linux.  Found with njamd - had not
         affected operation.  Made sure all string malloc() have +1
         to hold terminator.
  1.0.23 11-JAN-2004,
         -rs was broken.  It worked when the field was off the ends but
         not for "a,b,,d" and retrieve 3rd field, which came back as 
         an empty string.
  1.0.22 18-NOV-2003,
         -ifterm string    Terminates an -if state, use instead of an -ifn.
         -iftermeol -string Append this EOL string at termination of an
           -if state.
         -iftermbol -string emit this string immediately on -if block
            termination (before processed text).  This is primarily to
            handle the case where the start and end lines of the if
            blocks are the same.  Using it a new line or other characters
            may be injected between blocks.  Primarily useful when the
            if blocks are collapsing multiple rows of text into one.
         -bol string, -ifbol which are the beginning of line equivalents
            to -eol,-ifeol.
  1.0.21 21-MAY-2003,
         -unmerge N.  Opposite of -merge (sort of).  Reads an input line.  Tokenizes
         with -mdl (which defaults to -dl if not specified).  For each group of N
         tokens after the first it creates an  "input line" consisting of the
         first token + N tokens.  This is processed as any other input line.  N is stored
         as -N in the "merge" variable.
         -template N.  Consider two files containing lists, one complete,
         one partial, both in the same order (sorted, or whatever).  If an input file
         (or files) is read in with the complete list as a template any missing lines
         are replaces with -trs (or -rs, or just a blank line).  Not compatible with
         -eqlen.  N is the number of characters which are compared to determine if
         there is a match.  The first file in the -in list is the template.
         A blank line in either file terminates it.
  1.0.20 15-MAY-2003,
         Fixed bug.  pad and fw were not working if the 
           field was empty
         Added -rcdc (case insensitive version)
         Added -rtds STRING (replace text delete string)
         Added -rtss STRING (replace text substitute string)
            Either remove a matching string or replace it.
  1.0.19 08-MAY-2003,
         Added -merge N  (same prefix merge of consecutive lines)
         Added -mdl STRING (delimiter between merged consecutive lines)
         Added -rcds STRING (remove characters delete string)
         Added -rcss STRING (remove characters substitute string)
         Use -rcds and -rcss like unix "tr" command.  rcds alone to
           remove (or if it starts with !, keep) characters.  With rcss
           matching characters are substituted from that position in the
           rcss string.
         This made the input structure in main() very messy :-(.
         Note that order is:
           merge from multiple files
             merge from -merge prefix
              if actions
                output
         Added [start,end[,increment]] to ranges.  Increment is optional
           and can be negative or positive.  Note that when going backwards
           the delimiter comes from the token before.  That is, the delimiter
           between n and n+1 is shown for n,n+1 and n+1,n.
         Fixed bug (maybe added others?).  [\58] was accepted and came out as 8.
            modified strtok_variant so that \ does not act in first position of a token.
         Modified behavior so that a range like [3,-1] does not generate an error on
            a short line.  Instead it becomes [LOCINVALID,LOCINVALID] which will always
            be valid but out of range, yielding an empty token or an empty string.
            However, [4,2] and [-2,-4] are still errors, since those are never valid.
  1.0.18 06-MAY-2003,
         Fixed bug:  [-1] wasn't working, required [-1,-1].
  1.0.17 03-MAY-2003, Added multiple comma separated input files and merge
         functionality.
         Added -indl 'string' to indicate a string to be placed between each line.
         Added -eqlen to force input files to all be the same length.
         Added -n to emit the current line number.
         Added ability to detect empty string. CAREFUL! tag=NULL means
         no if, tag='\0' means empty string!!!
  1.0.16 25-APR-2003, Added -fp (floating precision) and [ff] (floating
         format).  fp sets the precision for floating point and
         ff in an [] expression indicates that the value is a floating
         point number subject to -fw and -fp.  ff can be used on
         the command line as well, in which case ALL [] are floating
         point.  Fixed potential bug [fw-1:] and [pd-1:] were allowed
         but didn't make sense, now these values must be >=0.
  1.0.15 24-APR-2003, Added -eol, replaces \n with eolstring on the
         ends of lines.  Fixed up input so that it can handle a 
         file which ends with an EOF but no EOL on the last line.
         Note that such a line will be emitted with an EOL unless
         -eol or -ifeol intervenes.
  1.0.14 16-APR-2003, Added fixupescapes processing to all plain text strings
         inside -cols, -rs strings, and -dv strings.  So now -dv '\n' emits a
         line feed between tokens and -cols '[1]\t[2]\n[3]' contains tabs and line feeds.
         Added -cf (first letter upper, rest lower). Unrecognized \xxx strings are
         not interpreted and do not throw errors.
  1.0.13 10-FEB-2003, added -ifeol.  If the logic is satisfied EOL
         is suppressed.  This allows the next line to be appended to if line,
         or whole series of if lines to be appended to each other.
  1.0.12 14-JAN-2003, added -ifonly.  Without this rows matching
        -if/-ifn are modified by -cols, but all lines are emitted.
        With -ifonly only lines matching -if/-ifn are emitted.
  1.0.11 14-NOV-2002, added -ifn, which extends the result of the
        -if test for N more lines.  Each line is also tested for the
        tag so that the extend can be reset.  This allows a "tag" to
        be recognized and that and the next 5 lines processed.
  1.0.10 05-JUL-2002, added -if, which provides a limited conditional
        capability.  The general idea is that a very simple pattern
        can be matched with -if, and otherwise, put another program
        upstream to introduce a unique "process this" mark.
  1.0.9 15-MAY-2002, added -bs, which adds unix escapes (back slashes) to a string.
        added code so that -dl ' :\t' makes tab a delimiter.  Because on many OS's could
        not enter tab on the command line directly).  
  1.0.8 31-MAR-2002, fixed bug where -mt -d- worked but -d- -mt didn't.
  1.0.7 05-MAR-2002, sanitized [s,e] syntax and removed TAIL prefix.  Meaning is now:
     e=0,s=0  error
     s>0  column to start in measured from 1
     s<0  column to start in measured from the END of the line (-1 = last column)
     e>0  column to end   in measured from 1
     e<0  column to start in measured from the END of the line (-1 = last column)
     Note that it's a VERY bad idea to do 10 columns from left for start and 10
     from right for end as depending upon the line length the range may be invalid!
     Changes sc storage to NOT have -1 offset.  Note also that [2,] may give
     a fatal error if the line has only 1 token.
     Cleaned up logic for when delim is emitted in cases like [1,3]foo[4,5]

  1.0.6 03-MAR-2002, added [TAIL,offset,N] mode.  This allows extraction of
    N characters/tokens offset from the end of a line.  Changed -cols parsing
    so that \ escapes may be used, for instance, to escape :[].  Enabled [tail,o,n]
    format.  Fixed some bugs.  Rearranged some code.
  1.0.5 28-FEB-2002, added -rs switches.
  1.0.4 25-FEB-2002, added generic text based -cols switch to allow column reordering,
          multiple gapped column selection, and text insertion.  Added -xc (max columns)
          for data structure to hold token pointers.  Renamed pad to pd and added fw to
          handle the absolute width case.  
  1.0.3 22-FEB-2002, use lcl_strcasecmp because strcasecmp wasn't ANSI standard (at least
          on older compilers.)  Add -in -out flags for OS's that don't have pipes.
  1.0.2 22-FEB-2002, added these flags
          -pad N      pad field with N trailing spaces, if negative, pad or truncate to width.
          -jl/-jr/-jc left/right/center justify, follows pad
                      if that too is specified
          -cu/-cl     upper case/lower case
          -is         in situ mode (extract/remove/in situ)
  1.0.1 20-FEB-2002, added -rm flag, which removes the indicated
          region instead of extracting it.  Can be used iteratively
          or in a pipe to to pull out several columns from a
          multicolumn input file.
  1.0   05-JAN-2002, first release


Miscellaneous:
    Credit to Pat Rankin for writing the VMS EXTRACT utility
    which inspired this program.


*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>            /* for toupper, tolower */
#include <limits.h>           /* for INT_MAX          */
#include <math.h>             /* for math constants   */
#include <pcre.h>             /* for PCRE regular expressions */
#include <float.h>            /* for math precision constants   */
#ifdef SOL8
#include <sys/inttypes.h>     /* because no stdint.h, needed for uintptr_t  */
#include "sol8.h"
#else
#include <stdint.h>           /* for uintptr_t        */
#endif
#ifdef MSCRTL
#include <fcntl.h>
#include <io.h>
#endif /* MSCRTL */


#define EXVERSTRING "1.1.9 13-JUN-2013"
#define COPYSTRING  "(extract) 2013 David Mathog and California Institute of Technology"
#define COPYSTRING2 "(PCRE)    1997-2010 University of Cambridge"
#define BUGSTRING   "mathog@caltech.edu"
#define LICSTRING   "GNU General Public License 2"
#define INSFTLERR      "extract: fatal error:"
#define INSFTLPRGERR   "extract: fatal programming error:"

/* Things that don't change during the program run */
#define MYMAXSTRING  16000     /* Hard limit on input line size, initial size for some other buffers */
#define MYMAXCMD      8192     /* longest input line from -cmd       */
#define ALLPTRINC      256     /* size increments for alldata, if it must be realloc'd*/
#define ALLDATAINC    8192     /* size increments for alldata, if it must be realloc'd*/
#define MYMAXARGS     1024     /* largest number of tokens from -cmd */
#define MYMAXPAL        16     /* largest number of pattern action list entries for gbl/lcl params */
#define MYPOSMAX        10     /* largest number of parse option groups that may be handled */
#define MYPSSMAX        10     /* largest number of -ps# specifications that may be handled (there may be 26 psV) */
#define MYSHORTSTRING  100
#define MYMAXDV          4     /* longest possible dv string, like '\123' */
#define MYMAXSTACK     256     /* pm[N],psN call/return stack depth.  Need more? Write in Perl or Python! */
#define EOVLIST        127     /* character that terminates a vlist string */
#define MAXOUTFILE      10
#ifndef MAXINFILE
#define MAXINFILE   (FOPEN_MAX-MAXOUTFILE-1)  /* reserve the others for -out or -cmd */
#endif  /* MAXINFILE */
#define MYMAXJUMPS     256     /* the most jmp/lbl that may be used. Need more? Write in Perl or Python! */
#define MYMAXACTIONS   256     /* The largest number of actions that may be stored in a single
                                  -pm construct, spread out over both the True and False paths. */
#define MYFMTSMAX       10     /* maximum number of -fmt structures, default is 1 */
#define MYVARSMAX       26     /* maximum number of SET + DEFINED variables, vA->vZ */
#define ACCUMINC      2048     /* size increments for accum, if it must be realloc'd*/
#define LBLINC         256     /* (re)allocation size for -lbl  */
#define PATINC          32     /* (re)allocation size for pattern related structures */
#define ALINC           64     /* (re)allocation size for automatic label generation*/
#define XCINC           64     /* (re)allocation size for FMTNEXUS toklist storage */
#define MATHINC        512     /* size increments for pre_run and rpn math stacks */

/* initial values for things that can be changed or realloc'd later */
#define MYINIFMT       128     /* maximum terms in a -fmt statement.  Static strings and [] descriptions. */
#define MYINIRANGES    128     /* default number of column/token ranges that may be parsed. */
#define MYOVECSIZE     120     /* This is supposed to be a multiple of three. the initial size of the ovector, may be dynamically increased as needed*/
#define MYDEFPRECISION   6     /* floating point precision */

#define OPERDELIM ';'          /* delimiter for operations */
#define OPERDELIMSTR ";"       /* delimiter string for operations */
#define DBLPREC(A,B) ((A) > (B) ? (A) : ((A) < -(B) ? (A) : (isnan(A) ? (A) : 0.0) ))
#define DBL2UINT32(A) (A>UINT32_MAX ? UINT32_MAX : ( A<0 ? 0 : (uint32_t) A ))
#define DBL2INT32(A)  (A>INT32_MAX ? INT32_MAX : ( A<INT32_MIN ? INT32_MIN : (int32_t) A ))
#define EXT_CALLOC(A,B,C,D)      A=calloc(B,C); if(!A)insane(INSFTLERR,D)
#define EXT_MALLOC(A,B,C)        A=malloc(B); if(!A)insane(INSFTLERR,C)
#define EXT_FREALLOC(A,B,C,D)    if(B<C){if(A)free(A); A=malloc(C); if(!A)insane(INSFTLERR,D);B=(C);}
#define EXT_REALLOC(A,B,C,D)     if(B<C){A=realloc(A,C); if(!A)insane(INSFTLERR,D);B=(C);}
/*for , 
  A is memory
  B is initial size (units)
  C is test size (units)
  D is new size (units)
  E is the number of bytes in a unit
  F is the error message if it fails  
*/
#define EXT_REALLOC2(A,B,C,D,E,F)  if(B<C){ A=realloc(A,(D*E)); if(!A)insane(INSFTLERR,F);B=(D);}
#define EXT_REALLOC3(A,B,C,D,E)  {A=realloc(A,(C*D)); if(!A)insane(INSFTLERR,E);B=(C);}

#define EXT_STRLEN(A) ( A ? strlen(A) : 0 )  /* gives strlen 0 for null pointers*/

#define BR_SET(A,B,C)   (A) &= ~(B); (A) |= (C)

#define ISVAROFF(A)     (A>=0 && A<MYVARSMAX  ? 1 : 0)
#define ISNOTVAROFF(A)  (A<0  || A>=MYVARSMAX ? 1 : 0)
#define TOVAROFF(A)     (A=='-'       ? MYVARSMAX : toupper(A) - 'A')
#define FROMVAROFF(A)   (A==MYVARSMAX ? '-'       : toupper(A) + 'A')
#define TOFMTOFF(A)     ((A) - '0')
#define TOPSOFF(A)      ((A) - '0')
#define TOPOOFF(A)      ((A) - '0')
#define VAR_MUST_BE_SET(A,B)  if(!(A[(int) *B]->dat_str->slen)){ insane_var(INSFTLERR," variable used before being set: ",*B); }


/* Utility functions for use with ESNEXUS structures */
#define NEXTINTREMAINDER(A)  (A % SOI ? SOI-(A % SOI): 0) 
#define NEXTDBLREMAINDER(A)  (A % SOD ? SOD-(A % SOD): 0) 
#define NEXTINTBOUNDARY(A)  A += (A % SOI ? SOI-(A % SOI): 0) 
#define NEXTDBLBOUNDARY(A)  A += (A % SOD ? SOD-(A % SOD): 0) 
#define ESP_CLEN(A)    (A->slen ? A->slen - 1 : 0 )/* strlen value for the ESNEXUS*               */
#define ESP_CPTR(A)    (A->string)                 /* Pointer to the first position ESNEXUS*      */
#define ESP_CADDR(A,B) (&A->string[B])             /* Pointer to position B in the ESNEXUS string */
#define ESP_LASTPTR(A) &(A->string[ESP_CLEN(A)])   /* Pointer to the final character in ESNEXUS*  */
#define ESP_LASTVAL(A) A->string[ESP_CLEN(A)]      /* value of   the final character in ESNEXUS*  */
#define ESP_INCLEN(A)  (A->slen++)                 /* increment length for the ESNEXUS*           */
#define ESP_ADDLEN(A,B)(A->slen += (B))            /* add to length for the ESNEXUS*              */
#define ESP_SETLEN(A,B)(A->slen = (B))             /* set length for the ESNEXUS*                 */
#define ESP_NEXTINTBOUNDARY(A)  NEXTINTBOUNDARY(A->slen) 
#define ESP_NEXTDBLBOUNDARY(A)  NEXTDBLBOUNDARY(A->slen) 
#define ESP_INT(A,B) (*(int *)  &(A->string[B])) 
                                                   /* offset to integer data         */
#define ESP_OFFINT(A,B) (*(int *)  &(A->string[*(int *)  &(A->string[B])])) 
                                                   /* offset to an offset to integer data         */
#define ESP_OFFCPTR(A,B) ((char *)  &(A->string[*(int *)  &(A->string[B])])) 
                                                   /* offset to an offset to a character pointer  */
#define ES_CLEN(A)     (A.slen ? A.slen - 1 : 0)   /* strlen value for the ESNEXUS                */
#define ES_LASTPTR(A)  &(A.string[ES_CLEN(A)])     /* Pointer to the final character in ESNEXUS   */
#define ES_LASTVAL(A)  A.string[ES_CLEN(A)]        /* value of   the final character in ESNEXUS   */
#define ES_INCLEN(A)   (A.slen++)                  /* increment length for the ESNEXUS            */
#define ES_ADDLEN(A,B)(A.slen += (B))              /* increment length for the ESNEXUS            */
#define ES_NEXTINTBOUNDARY(A) while(A.slen % SOI){A.slen++;} 

#define MEMOOPS " could not allocate memory"
#define SOP     sizeof(uintptr_t)
#define SOD     sizeof(double)
#define SOI     sizeof(int)
#define SOUI    sizeof(unsigned int)
#define SOC     sizeof(char)

#define NO            0
#define YES           1
#define MAYBE        -1
#define TO_END       -1  /* for cases like [1,] */
#define IFFOREVER    -1  /* extend an -if block until end of file or terminated */

/* both of these fields are stored in the params->ff integer */
#define FFNONE     0x000
#define FFFLOAT    0x001  /* format to %M.Nf */
#define FFEXP      0x002  /* format to %M.Ne */
#define FFUNS      0x004  /* integer format is unsigned */
#define FFHEX      0x008  /* format to %M.Nx */
#define FFDEC      0x010  /* format to %M.Nd or %M.Nu */
#define FFOCT      0x020  /* format to %M.No */
#define FFPDEFAULT 0x040
#define FFSDEFAULT 0x080
#define FFMASKEF   0x03F
#define FFMASK     0x0FF
#define NZNONE     0x000  /* -0 prints as 0, engineering notation only */
#define NZNZ       0x100  /* if set, -0 prints as -0, normally prints as 0, engineering notation only */
#define NZPDEFAULT 0x200
#define NZSDEFAULT 0x400
#define NZMASK     0x700

#define IF_NONE       0  /* nothing set                                  */
#define IF_START1     1  /* if satisfied, single line, no countdown      */
#define IF_STARTC     2  /* if satisfied, start a countdown using ifn    */
#define IF_STARTT     4  /* if satisfied, go forever until ifterm        */
#define IF_TERM       8  /* cancel either if state                       */
#define IF_NORESTART 16  /* prevents if[cp] from (re)starting within an if block */
#define IF_TAG       32  /* -if and/or -ifterm defined, -pm if statements forbidden */
#define IF_CLEAR    ~63  /* clears all but exists flag                   */
#define IF_EXISTS    64  /* -if and/or -ifterm defined, -pm if statements forbidden */
#define IF_ANY_START (IF_START1 | IF_STARTC | IF_STARTT) /* these cannot be used together */


/* source for characters is as follows.
  There are two structures which can hold strings:
    DAT holds input for -fmt and values for -v*
    DEF holds literals for -fmt and -v*

                                 MODES  ISS  What
*/
#define SRCVRANGE     0x2000  /*  If clear iss values for start,end,inc come from the fldlist.  If
                                  Set .iss denotes a numeric variable, .issend a position in that variable,
                                  which must be an array, and .issinc is ignored.  The values for
                                  fstart,fend,finc are pulled from the numeric variable starting
                                  at the indicated position.  This allows a fmt specifier like:
                                  [xxxx:$A,1]
                                  where the actual range is calculated and stored in positions 1,2,3
                                  in $A.  */
#define SRCSELF       0x1000  /*  C      DEF   used only for literals in -fmt -v strings 
                                  C      DAT   used for data in SET variables.  (This is how they
                                                 refer to themselves)
                                               Strings derived this way are not further modified.
                                               All the other SRC* options will be justified, etc.   */
#define SRCLINE       0x0000  /*  C,T    DAT   in current -fmt                              */
#define SRCVARS       0x0100  /*  C,T    DAT   in named variable(s) sequentially   vABC...  
                                               This is short hand for
                                                 mc [vA:range][VB:range] etc.
                                                 mt [vA:range]<mdl>[VB:range] etc. 
                                               with full postprocessing on each []. */
#define SRCVARI       0x0200  /*    T    DAT   in named variable(s) interleaved    =ABC...  */
#define SRCVARF       0x0400  /*    T    DAT   in named variable(s) interleaved,front/end fill @ABC...  */
#define SRCMASK       0x0700
#define ISSDAT        0x0010   /* characters from DAT                         */
#define ISSDEF        0x0020   /* characters from DEF                         */
#define ISSMASK       0x0030
#define MODENONE      0x0001   /* program default mode is MODENONE = MODECHAR */
#define MODECHAR      0x0001   /* applies to either DAT or DEF                */
#define MODETOK       0x0002   /* applies ONLY to DAT (string variables)      */
#define MODENUM       0x0004   /* applies ONLY to DAT (numeric variables)     */
#define MODEPDEFAULT  0x0010   /* these are used in gblparams, lclparams, but reduce to char or tok */
#define MODESDEFAULT  0x0020   /* when stored in the source variable          */
#define MODEMASK      0x0007

#define DASH_ALLOW    1
#define NO_DASH_ALLOW 0
#define SIGNED_ALLOW    1
#define NO_SIGNED_ALLOW 0

#define OPT_NONE       0 /* no tokens found yet              */
#define OPT_FOUND      1 /* token in a specified range found */
#define OPT_FOLLOWING  2 /* this is not the first token found */
#define OPT_EMPTY      4 /* token is empty (like -s with ,,, - they are found, but they are
                            empty. Key difference, EMPTY tokens have a delimiter from the input
                            line, but !OPT_FOUND do not */

enum swi_actions {
 SWI_BIT0,  /* shift and add 0                            */
 SWI_BIT1,  /* shift and add 1                            */
 SWI_MV,    /* set from omni->mv                          */
 SWI_MP,    /* set from first match if omni->rc>0, else 0 */
 SWI_MATH   /* set from RESULT (last math operation)      */
};

enum acc_modes {
  ESRCVARS,  /*  v VLIST, see SRCVARS for description */
  ESRCVARI,  /*  = VLIST,     SRCVARI                 */
  ESRCVARF   /*  @ VLIST,     SRCVARF                 */
};

#define MATCH_GLOBAL     0x00000001  /* for -pm, -ps run the match repeatedly keeping track of results */
#define MATCH_SUBS       0x00000002  /* this is a match/substitution                                   */
#define MATCH_OPER       0x00000004  /* this is a match/operation                                      */
#define MATCH_REMAINDER  0x00000008  /* start search after last match, do not clear ovector            */
#define MATCH_PCRE       0x00000010  /* pattern is a PCRE expression                                   */
#define MATCH_STRING     0x00000020  /* pattern is a simple string                                     */
#define MATCH_VLIST      0x00000040  /* pattern is a VLIST, match any dat_str for these variables      */
#define MATCH_TOKENS     0x00000080  /* pattern is a VLIST, match any token in any variables           */
#define MATCH_NVLIST     0x00000100  /* pattern is an int4,VLIST, match that token in any variables    */
                                    /* multiple search strings modes "STRINGS"                        */
#define MATCH_STRS       (MATCH_VLIST | MATCH_TOKENS | MATCH_NVLIST) 
#define MATCH_SEARCH     (MATCH_PCRE | MATCH_STRING | MATCH_STRS)
#define MATCH_EXISTS     0x00000200  /* existence tests                                                */
#define MATCH_TRUE       0x00000400  /* always true, no pattern is actually matched                    */
#define MATCH_MATH       0x00000800  /* math tests                                                     */
#define MATCH_FILE       0x00001000  /* file tests                                                     */

   /* these 4 bits are overloaded for different contexts.  Only one flag of 4 may be used */
#define MATCH_SEQUENTIAL 0x00002000  /* for strings, match all sequentially, near->far order, not with global */
#define MATCH_FIRST      0x00004000  /* for strings, first that matches                                */
#define MATCH_NEAR       0x00008000  /* for strings, test all, nearest is the match                    */
#define MATCH_FAR        0x00010000  /* for strings, test all, farthest is the match                   */

#define MATCH_NML        0x00002000  /* RESULT is normal (not inf or NAN                               */
#define MATCH_EQ         0x00004000  /* RESULT is == 0                                                 */
#define MATCH_LT         0x00008000  /* RESULT is  < 0                                                 */
#define MATCH_GT         0x00010000  /* RESULT is  > 0                                                 */

                                    /* method for multiple search strings                             */
#define MATCH_STRSMETHOD (MATCH_SEQUENTIAL | MATCH_FIRST | MATCH_NEAR | MATCH_FAR) 
#define MATCH_CASELESS   0x00020000  /* case insensitive search                                        */
#define MATCH_START      0x00040000  /* (first) match must start on the first character in the target  */
#define MATCH_END        0x00080000  /* (last) match must end on the last character in the target      */
#define MATCH_KEEPN      0x00100000  /* for PCRE match, on each pass, keep only the indicated substring */
#define MATCH_SSUBS      0x00200000  /* replace is a simple string                                     */
#define MATCH_VSUBS      0x00400000  /* replace is the dat_str of each var in VLIST (used sequentially, wraps)   */
#define MATCH_NVSUBS     0x00800000  /* replace is the nt token of each var in VLIST (used sequentially, wraps)   */
#define MATCH_TSUBS      0x01000000  /* replace with matching token number (ie 
                                        find tok 3 in pattern string, swap in tok 3 in replacement string */
#define MATCH_QSUBS      0x02000000  /* replace is the tokens of each var in VLIST (used sequentially)           */
 /* hits are stored in an ovector list.  Each pair of numbers is a start,end+1.  Coming out of the
    match_* routines these contain only Hits (the substrings found).  When assigned to tokens the
    implicit regions Before (any text before the first hit, or an empty string), Interior (between
    successive hits, or an empty string), and After (after the last hit, or an empty string)
    may be used.  Default is just H unless the >bhia operation is employed.  */
#define MATCH_B          0x04000000  /* use region Before   when assigning substrings to tokens */
#define MATCH_H          0x08000000  /* use region Hit      when assigning substrings to tokens */
#define MATCH_I          0x10000000  /* use region Interior when assigning substrings to tokens */
#define MATCH_A          0x20000000  /* use region After    when assigning substrings to tokens */
#define MATCH_BHIA       (MATCH_B | MATCH_H | MATCH_I | MATCH_A)
#define MATCH_TTOK       0x40000000  /* test tokens (instead of variables)                             */
#define MATCH_EMPTY      0x80000000  /* true if token/variable is defined but empty  (0 length)        */



#define IS_SUBS      0  /* for prematches, these are stored in ms */
#define IS_MATCH     1  
#define IS_OPER      2  
#define IS_SECT      3
#define SECT_COMMON  0
#define SECT_BEFORE  1  /* these are stored in pattern, no terminator */
#define SECT_MAIN    2
#define SECT_AFTER   3 

/* bits for selector test for postprocessing of selected strings */
#define DO_RS       0x001
#define DO_DESC     0x002
#define DO_RCD      0x004
#define DO_RTD      0x008
#define DO_PS       0x010
#define DO_SLASH    0x020
#define DO_FFF      0x040
#define DO_PAD      0x080
#define DO_TRIM     0x100
#define DO_JUST     0x200
#define DO_CASE     0x400

/* Values for match actions */
enum mactions {DO_LISTEND, DO_CLRV,    DO_MRGV,    DO_SETC,    DO_MATH,
               DO_VSETV,   DO_STRV,    DO_FMTV,    DO_VV,      DO_NVV,
               DO_SHOWV,   DO_SHOWNV,  DO_VEMIT,   DO_SEMIT,   DO_FEMIT,
               DO_READ,
               DO_IF,      DO_IFN,     DO_EOL,
               DO_AFMT,    DO_NFMT,
               DO_HIDE,    DO_SHOW,    DO_SKIP,    DO_CALL,
               DO_RET,     DO_BRK,     DO_EOF,     DO_EXIT,
               DO_FAIL,    DO_PO,      DO_BHIA,    DO_NPOPV,
               DO_SW,      DO_SWI}; 


#define DBGCOL         0x01
#define DBGVAR         0x02
#define DBGIFP         0x04
#define DBGM           0x08
#define DBGSTACK       0x10
#define DBGAL          0x20

#define JUSTNONE       0
#define JUSTLEFT       1
#define JUSTRIGHT      2
#define JUSTCENTER     3
#define JUSTPDEFAULT   4
#define JUSTSDEFAULT   5

#define TRIMNONE       0
#define TRIMLEFT       1
#define TRIMRIGHT      2
#define TRIMCOMPRESS   4
#define TRIMPDEFAULT   8
#define TRIMSDEFAULT  16

#define CASENONE       0
#define CASEUPPER      1
#define CASELOWER      2
#define CASEFIRST      3
#define CASEPDEFAULT   4
#define CASESDEFAULT   5

#define SLASHNONE      0
#define SLASHUNIX      1
#define SLASHALL       2
#define SLASHREST      3
#define SLASHPDEFAULT  4
#define SLASHSDEFAULT  5

#define ECCVAL         1
#define ECCPDEFAULT    2
#define ECCSDEFAULT    3

 /* parsing controls are INITIALLY in bit fields, when they are set from the command
   line.  The escape field values are defined but they are not currently used really,
   as PARSE_ESCAPE is always set later.  */

#define DQNONE              0x0  /* double quote parsing control */
#define DQ                  0x1
#define DQS                 0x2
#define DQPDEFAULT          0x4
#define DQSDEFAULT          0x8
#define DQMASK              0xF
                       
#define SDNONE             0x00  /* single delimiter parsing control */
#define SD                 0x10
#define SDPDEFAULT         0x20
#define SDSDEFAULT         0x40
#define SDMASK             0x70
                       
#define DELIMNONE         0x000 /* setting delimiter for parsing control */
#define DELIMTOK          0x100 /* not used in [set], is used in other [] operations */
#define DELIMVAL          0x200
#define DELIMPDEFAULT     0x400
#define DELIMSDEFAULT     0x800
#define DELIMMASK         0xF00

#define MDELIMNONE       0x0000/* setting merge/unmerge delimiter for parsing control */
#define MDELIMVAL        0x1000
#define MDELIMPDEFAULT   0x2000
#define MDELIMSDEFAULT   0x4000
#define MDELIMMASK       0x7000
                       
#define ESCAPESNONE     0x00000/* setting merge/unmerge delimiter for parsing control */
#define ESCAPES         0x10000
#define ESCAPESPDEFAULT 0x20000
#define ESCAPESSDEFAULT 0x40000
#define ESCAPESMASK     0x70000

/* Parse options for strtok_variant.  The command line bits are converted to these in
add_po.   Conservative means no change to input string. Destructive
means that changes may be made to that string. */
#define PARSE_ESCAPES      1 /* destructive,  \ escapes characters and is consumed, ie \: -> : */
#define PARSE_DBLQUOTES    2 /* conservative, double quotes may surround delimiters */
#define PARSE_STRIPDQUOTES 4 /* with PARSE_DBLQUOTES, returns tokens without the double quotes */
#define PARSE_SINGLEDEL    8 /* conservative, each delim defines a token (default, runs define one token) */




#define ACTEXTRACT     0
#define ACTREMOVE      1
#define ACTINSITU      2

#define PADNONE        0
#define PADPDEFAULT    1
#define PADSDEFAULT    2
#define PADFIELD       3

#define FPNONE         0
#define FPPDEFAULT     1
#define FPSDEFAULT     2
#define FPFIELD        3

#define RSNONE         0  /* replacement string - for missing fields */
#define RSPDEFAULT     1
#define RSSDEFAULT     2
#define RSVAL          3

/* the data for these is partially stored in subs and partially in alldata, the part
that is in alldata is in the order:
  byte 1: #  (0->9)
  byte 2:
        <MYVARSMAX  the number of a variable
        MYVARSMAX   use the default replace string
        >MYVARSMAX  use this string, starting with this variable */
#define PSNONE         0  /* patterns substitution states */ 
#define PSPDEFAULT     1                                     
#define PSSDEFAULT     2                                     
#define PSVAL          3  /* psN or ps, use the specified or default PS */

#define RCDNONE        0  /* remove character delete string */
#define RCDPDEFAULT    1
#define RCDSDEFAULT    2
#define RCDVAL         3  /* case sensitive match */
#define RCDVALC        4  /* case insensitive match */

#define RCSNONE        0  /* remove character substitute string */
#define RCSPDEFAULT    1
#define RCSSDEFAULT    2
#define RCSVAL         3

#define RTDNONE        0  /* replace text delete string */
#define RTDPDEFAULT    1
#define RTDSDEFAULT    2
#define RTDVAL         3  /* case sensitive match */
#define RTDVALC        4  /* case insensitive match */

#define RTSNONE        0  /* replace text substitute string */
#define RTSPDEFAULT    1
#define RTSSDEFAULT    2
#define RTSVAL         3  /* immediate string value */
#define RTSVAR         4  /* indirect, contents of variable */  

#define DESCNONE       0  /* run fixupescapes on string  */
#define DESCPDEFAULT   1
#define DESCSDEFAULT   2
#define DESCFIELD      3   


#define SORTNONE       0  /* program default mode is SORTNONE */
#define SORTAS         1
#define SORTDS         2
#define SORTAC         3
#define SORTDC         4
#define SORTAN         5
#define SORTDN         6
#define SORTPDEFAULT   7
#define SORTSDEFAULT   8

#define TAG_NONE       0  /* tag states, stored in ctag[0] */
#define TAG_ANYWHERE   1
#define TAG_FRONT      2
#define TAG_END        4
#define TAG_NOT        8
#define TAG_NORESTART 16  /* only used by -if, not by -ifterm */
#define TAG_MASK       7
                          /* options for handling NULL characters in text strings on input*/
#define HNULL_RETAIN  -1   /* retain them - default, fastest, but only works correctly if none are present */
#define HNULL_DELETE   0   /* delete all embedded NULL characters */
#define HNULL_SUBS   255   /* default substitution character for embedded null characters
                              Override with -hnsubs */


/* super_fgets() status bits */
#define SFG_EOF              1 /* input terminated by End of File              */
#define SFG_EOL              2 /* input terminated by End of line (\n)         */
#define SFG_CRLF             4 /* input terminated by CRLF (\r\n) \r remains!  */
#define SFG_EMBEDDED_NULL    8 /* embedded NULL characters were read           */
#define SFG_BUFFER_FULL     16 /* input buffer full                            */
#define SFG_READERROR       32 /* unrecoverable read error                     */


/* Math related definitions */
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
#define OUT_FMT_ENG  0x00
#define OUT_FMT_SCI  0x01
#define OUT_FMT_UNS  0x02  /* unsigned, for integer types only */
#define OUT_FMT_HEX  0x04
#define OUT_FMT_DEC  0x08
#define OUT_FMT_OCT  0x10

enum rpn_states {RPN_SCALAR,RPN_NVEC_SELF,RPN_NVEC_SCALAR,RPN_SCALAR_NVEC,
  RPN_NVEC_NVEC,RPN_NVEC_SVEC};

/* Values for math actions 
NMUL etc handle unary operations like * -func().
*/
enum math_ops {
  MATH_NOP,   MATH_NNONE,    MATH_NONE,   MATH_LD_STATE,
  MATH_LD_ELEM,  MATH_SV_ELEM, MATH_SV_ZERO,
  MATH_LD_TOKEN,
  MATH_ADD,   MATH_SUB,  MATH_MUL,    MATH_DIV,     MATH_MOD,  MATH_POW, MATH_CMP,
  MATH_LOG,   MATH_LN,   MATH_E10,    MATH_EE,
  MATH_CHS,   MATH_ABS,
  MATH_SIN,   MATH_COS,  MATH_TAN,    MATH_ASIN,    MATH_ACOS, MATH_ATAN, 
  MATH_SINH,  MATH_COSH, MATH_TANH, 
  MATH_D2R,   MATH_R2D,
  MATH_BITNOT,
  MATH_MAX,   MATH_MIN,
  MATH_BITAND,MATH_BITOR,MATH_BITXOR, MATH_BITSHL,  MATH_BITSHR,
  MATH_DLEN,  MATH_SUM,  MATH_SM2,    MATH_NML,     MATH_TLS,  MATH_SLS,
  MATH_INV,   MATH_DEL,  MATH_IDX,    MATH_SRT,     MATH_SIX,
  MATH_DIM,   
  MATH_CAT,   MATH_INI,   
  MATH_TIX,   MATH_TCX,
  MATH_TOK,   MATH_TLN,  MATH_SLN,
  MATH_MAP,   MATH_UNMAP,
  MATH_RND,   MATH_LID,   MATH_TRC};  
#define MATH_LAST MATH_TRC  /*  update this if math_ops changes */  

enum mstack_ops {MSTK_NONE, MSTK_DPUSH, 
  MSTK_VPUSH, MSTK_VAPUSH, 
  MSTK_TOKZEROPUSH, MSTK_SAPUSH, 
  MSTK_OPUSH,
  MSTK_PSH, MSTK_NPSH, MSTK_POP, MSTK_DONE}; 


typedef struct is_stv             STVNEXUS;
typedef struct is_omni            OMNINEXUS;
typedef struct is_premoplist      PMLNEXUS;
typedef struct is_premop          PREMOPNEXUS;
typedef struct is_palist          PALNEXUS;
typedef struct is_moplist         MLNEXUS;
typedef struct is_moperation      MOPNEXUS;
typedef struct is_estring         ESNEXUS;
typedef struct is_parse_options   PONEXUS;
typedef struct is_fmt             FMTNEXUS;
typedef struct is_field           FIELDNEXUS;
typedef struct is_field2          FIELD2NEXUS;
typedef struct is_string_struct   STRINGNEXUS;
typedef struct is_jump            JMPNEXUS;
typedef struct is_jump_list       JLNEXUS;
typedef struct is_auto            ANEXUS;
typedef struct is_auto_list       ALNEXUS;
typedef struct is_mstklist        MSLNEXUS;
typedef struct is_mstack          MASNEXUS;
typedef struct is_dval            DVNEXUS;

struct is_mstklist {
   MASNEXUS *list;
   int       slen;
   int       salloc;
  };
struct is_mstack {
   int    what;                   /* 0 = value, 1=addr, 2 = mop */
   double val;                    /* value          */
   enum   math_ops mop;           /* math operation */
   };
struct is_dval {
   double *val;                   /* value             */
   int     dlen;                  /* number of entries */
   int     dalloc;                /* number allocated  */
   };

/* structure used to make strtok_variant nestable */
struct is_stv {
  char *string;
  int  ftoken;
  int  etoken; 
  int  dqetoken;
  int  endstring;
  int  firstcase;
};

/* structure used for automatic labels */
struct is_auto {
  int   first;   /* number associated with { (this is static once created) */
  int   mid;     /* number associated with }{ (goes up as struture is added) */
  int   last;    /* number associated with } (this is static once created) */
};
struct is_auto_list {
  ANEXUS *list;
  int   length;  /* of list */
  int   alloc;   /* space allocated for list */
  int   counter; /* increments upward as automatic labels are generated */
  int   skip;    /* used to prevent multiple autolabel operations */
};
/* structure used for matching up jmp and label tags*/
struct is_jump {
  char *label;
  int   adpos;   /* position in all data where the address value must be inserted (jmp or &)*/
  int   mpos;    /* position in the matches list where the label was defined */
};
struct is_jump_list {
  JMPNEXUS *list;
  int   length;
  int   alloc;
  int   skip;    /* used to prevent multiple jmp/skip operations */
};

/* structure for passing the most common data structures down into functions, to
simplify the calling interfaces. All of these except rc and target are allocated and
the pointer value set in main().  These pointers are not used in main() though, they
are provided so that other functions can read/write this data.
 */
struct is_omni {
   FMTNEXUS  **fn;             /* fmt_array                               */
   FMTNEXUS  **vn;             /* var_array                               */
   DVNEXUS    *dvar;           /* numeric variable structs                */
   DVNEXUS    *stk;            /* RPN run stack                           */
   MSLNEXUS   *pstk;           /* prerun stack                            */
   ESNEXUS    *buf_common;     /* common read buffer, for DO_READ         */
   ESNEXUS    *alldata;        /* action lists and their data             */
   ESNEXUS    *noleaks;        /* place to keep ptrs for data that would be lost */
   ESNEXUS    *piece;          /* scratch area for string construction    */
   ESNEXUS    *piece2;         /* 2nd scratch area, when piece is also used */
   ESNEXUS    *accum;          /* accumulator for -fmt construction       */
   PONEXUS    *gbl_po;         /* global parse options                    */
   PONEXUS    *po;             /* 10 parse options, position 0 is the same as gbl_po */
   MLNEXUS    *subs;           /* subs                                    */
   MLNEXUS    *matches;        /* matches                                 */
   FIELDNEXUS *gblparams;      /* global -fmt parameters                  */
   double      result;         /* last result for a math expression       */
   int         dbg;            /* debug mask                              */
   unsigned int *smap;         /* sort map, for emit_output               */
   unsigned int  smsize;       /* size of sort map, for emit_output       */
   int        *ifn;            /* ifn                                     */
   int         ifstate;        /* ifstate                                 */
   int         pat_skip;       /* pat_skip                                */
   int        *force_eof;      /* force_eof                               */
   int        *show;           /* show                                    */
   int         curfmt;         /* curfmt                                  */
   int         nextfmt;        /* nextfmt                                 */
   int        *numpo;          /* number of defined PO groups             */
   int        *ovector;        /* ovector array                           */
   int         osize;          /* osize                                   */
   int         oguard;         /* set if BHIAapplied, cleared on new list */
   int        *tlist;          /* holds matching token #s from t: pattern */
   int         talloc;         /* allocated size of of tlist              */
   int         tlen;           /* length of tlist                         */
   int         rc;             /* number of results in ovector            */
   char       *target;         /* string referenced by ovector            */
   int         gblpal_off;     /* offset to global action list            */
   int         gblpal_count;   /* number of entries in global action list */
   int         lastpal_off;    /* offset to last action list              */
   int         lastpal_count;  /* number of entries in last action list   */
   int         sw_val;         /* integer 0->sw_range-1, for switches     */
   int         maketokens;     /* True if input must be tokenized         */
   int         mv;             /* For a t:N match holds 0 if no match
                                  else token number 1->N that matched     */
   int         handlenull;     /* nulls in input, for DO_READ             */
   int         crok;           /* CR in input, for DO_READ                */
   };

/* post processing structure for strings.  This is stored in alldata and is not really a C structure.
   it consists of:
   int selector;      bits signifying which operations to perform    
   int offset1;       offset in alldata to parameters for 1st function
   int offset2;       offset in alldata to parameters for 2nd function
   int offsetN;       offset in alldata to parameters for Nth function
   
   The number of entries in the offset list are stored in ppcount of the FIELD2NEXUS that called.
   However, it isn't actually needed, because this is retrieved from alldata as
   int selector and int *offset, where offset increments for each test that matches, so
   the count is never referenced where this is used.  It is referenced to see if there is
   any postprocessing to be done.
   
   
   */
struct is_palist {
   int *offset;       /* offset in alldata where the parameters for each function are located.
                         Each function has one parameter, an offset into alldata, which tells it
                         where to pick up its data */
   int selector;      /* bits signifying which operations to perform         */
   };

struct is_moperation {
   char      src;                 /* variable to match against, - (26) if input             */
   char     *pattern;             /* the match pattern                                      */
   char     *replace;             /* the replace string  (for -ps)
                                     holds operations for -pm                               */
   pcre     *re;                  /* the compiled regular expression                        */
   int       tn;                  /* token number, used in some access modes                */
   unsigned  char*     keepsub;   /* substring(s) to keep for PCRE with MATCH_KEEPN         */
   int       bits;                /* used for MATCH_* bits                                  */
   int       true;                /* offset in alldata where the actions start for a match  */
   int       false;               /* offset in alldata where the actions start for no match */
   };


struct is_premoplist {
   PREMOPNEXUS *list;             /* a list of raw pm[N],ps[N] operations               */
   int       pcount;              /* the number of list entries                         */
   int       palloc;              /* the number of entries allocated                    */
   };
struct is_premop {
   char ms;                       /* 1 for match, 0 for sub                             */
   char var;                      /* <MYVARSMAX this is p[ms]N, otherwise, is pm        */
   char *pattern;                 /* raw pattern string                                 */
   char *second;                  /* raw operations/replace string                      */
   };

struct is_moplist {
   MOPNEXUS *list;                /* the list of match operations                       */
   int       start;               /* the entry to start on (common stuff before this)   */
   int       pcount;              /* the number of list entries                         */
   int       palloc;              /* the number of entries allocated                    */
   };
 /* the next one is parsing options, these are associated with each -fmt* -v* struct.
    Setting these on the command line sets them in -cols/-fmt0, others must be turned on
    or off with [set:] syntax. */
struct is_parse_options {
   int   parse_options;           /* what to do with double quotes and so forth         */
   int   dllen;                   /* length of delimit not INCLUDING terminator         */
   int   mdllen;                  /* length of mdelemit not INCLUDING terminator        */
   char *delimit;                 /* delimiter string for tokenizing                    */
   char *mdelimit;                /* merge delimiter string for tokenizing              */
   };

/* This is a generic data holder, so string terminators are counted like all other
characters towards the length. If it only holds a single string then slen will be
1 more than strlen would report. */
struct is_estring {
   char *string;                  /* Buffer that holds string        */
   int   slen;                    /* Length of data in buffer        */
   int   start;                   /* position (0->N-1 coords) to start search, used with MATCH_REMAINDER    */
   int   salloc;                  /* Allocated size of the buffer    */
   };
struct is_fmt {
   FIELD2NEXUS  *fldlist;         /* list of parsed FIELDS (from -fmt or -v*). These point to ISS
                                    structures.  If these are from -fmt* or -v* then they are
                                    static strings (stable for the run) and are stored in def_str.
                                    If they refer to data ranges, either from the input or from 
                                    variables, they are stored instead in toklist.  The FIELD2NEXUS
                                    "source" parameter indicates which of these many locations contains
                                    the data for each fldlist entry. 
                                    
                                    The maximum number of entries is set by the variable xe
                                    ("maX Expressions")
                                    */
   int          fldcount;        /* number of parsed fields */

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
   ESNEXUS     *def_str;          /* Storage for the literals in the definition */
   };
struct is_string_struct { /* coordinates for start are 0->N-1.  slen of 0 is an empty string  */
   int  start;            /* start  of the substring in the buffer */
   int  slen;             /* length of the substring */
   char delimit;          /* 0 or the delimiter */
   };
struct is_field2{  /* new version of field info */
   char  *vlist;          /* holds the variable reference string, if there is one */
   int    iss;            /* first iss to emit 1->N or -N->-1*/
   int    issend;         /* last iss to emit  1->N or -N->-1*/
   int    issinc;         /* increment from first to last by this (default to 1)*/
   int    source;         /* SRCLINE, SRCSELF, SRCVARS, SRCVARI */
   int    sort;           /* SORTNONE,SORTAS, SORTAC, SORTAN,SORTDS,SORTDC, SORTDN */
   int    map;            /* 0, or 1 + the numeric variable that holds the map */
   int    ppoff;          /* offset in alldata to post processing action list */
   int    ppcount;        /* size of list, could be 0 */
   int    ldelim;         /* DELIMNONE,DELIMP/SDEFAULT,DELIMTOK (with value from token),DELIMVAL (with .delim value) */
   char   delim;          /* used sometimes, depending upon ldelim) */
   };
struct is_field {
   int    notglobal;      /* in lcl, set if any value differs from global */
   int    source;         /* SRCLINE, SRCSELF, SRCVARS, SRCVARI */
   int    ttype;          /* MODENONE=MODECHAR,MODETOK,MODEP/SDEFAULT */
   int    sort;           /* SORTNONE,SORTAS, SORTAC, SORTAN,SORTDS,SORTDC.SORTDN */
   int    map;            /* 0, or 1 + the numeric variable that holds the map */
   int    pad;            /* pad value, used if lpad==PADFIELD, also used for field width */
   int    lpad;           /* PADNONE,PADP/SDEFAULT,PADFIELD (with .pad value) */
   int    precision;      /* floating point precision value */
   int    lprecision;     /* FPNONE,FPP/FPDEAFULT,FPFIELD (with .precision value) */
   int    ff;             /* FFNONE,FFFLOAT,FFEXP,FFUNS,FFOCT,FFDEC,FFHEX,FFP/SDEFAULT, also NZ fields */
   int    justify;        /* JUSTNONE,JUSTLEFT,JUSTRIGHT,JUSTCENTER,JUSTP/SDEFAULT */
   int    trimify;        /* BIT FIELD! TRIMNONE,TRIMLEFT,TRIMRIGHT,TRIMCOMPRESS,TRIMP/SDEFAULT */
   int    casify;         /* CASENONE,CASEUPPER,CASEFIRST,CASELOWER,CASEP/SDEFAULT */
   int    slashify;       /* SLASHNONE,SLASHUNIX,SLASHALL,SLASHREST,SLASHP/SDEFAULT */
   int    descify;        /* DESCNONE,DESCFIELD,DESCP/SDEFAULT */
   int    eccwhich;       /* ECCPDEFAULT,ECCSDEFAULT, or ECCVAL */
   char   ecc;            /* escape character*/
   char   delim;          /* used sometimes, depending upon ldelim) */
   int    ldelim;         /* DELIMNONE,DELIMP/SDEFAULT,DELIMTOK (with value from token),DELIMVAL (with .delim value) */
   int    lrs;            /* RSNONE,RSP/SDEFAULT,RSVAL */
   int    lps;            /* PSNONE,PSP/SDEFAULT,PSVAL, PSVAR */
   int    lrcd;           /* RCDNONE,RCDP/SDEFAULT,RCDVAL,RCDVALC */
   int    lrcs;           /* RCSNONE,RCSP/SDEFAULT,RCSVAL */
   int    lrtd;           /* RTDNONE,RTDP/SDEFAULT,RTDVAL,RTDVALC */
   int    lrts;           /* RTSNONE,RTSP/SDEFAULT,RTSVAL ,RTSVAR*/
   char  *ersstring;      /* holds the RS string, if there is one */
   char  *rcd;            /* holds the rcd string, if there is one */
   char  *rcs;            /* holds the rcs string, if there is one */
   char  *rtd;            /* holds the rtd string, if there is one */
   char  *rts;            /* holds the rts string, if there is one */
   char   ps;             /* byte:0->9 (indicates the PS number) */
   char  *vlist;           /* holds the variable reference string, if there is one */
   };

/* function prototypes (except for math, see below) */
int         acc_mode_identify(char letter);
char        acc_mode_show(int mode);
int         add_action(MLNEXUS *matches, JLNEXUS *jumplist, ALNEXUS *autolist, OMNINEXUS *omni, int *actions, int count, 
               char *atoken, const char *operations, int length, int *negate);
void        add_matches(MLNEXUS *matches, JLNEXUS *jumplist, ALNEXUS *autolist, OMNINEXUS *omni, int src, 
               char *pattern, char *operations);
void        add_op(OMNINEXUS *omni,char *cmd, int start, int length,
               FIELD2NEXUS  *fldlist, int *fldcount,
               FIELDNEXUS *gblparams, int xe);
void        add_po(OMNINEXUS *omni, char *cmd, PONEXUS *lcl_po);
void        add_prematch_lbl_op(PMLNEXUS *prematches,ESNEXUS *label);
void        add_prematches(PMLNEXUS *prematches, char type, int src, int *numarg,
               int argc, char **argv, ESNEXUS *label);
void        add_subs(MLNEXUS *subs, int src, char *pattern, char *replace);
void        al_destroy(ALNEXUS **autolist);
void        caseit(OMNINEXUS *omni, int offset);
void        classify_op(char *cmd, int *sc, int *nc, int *inc, FIELDNEXUS  *lclparams);
void        classify_po(char *cmd,PONEXUS *lcl_po);
static int  compare_ac(const void *p1, const void *p2);
static int  compare_an(const void *p1, const void *p2);
static int  compare_and(const void *p1, const void *p2);
static int  compare_as(const void *p1, const void *p2);
static int  compare_dc(const void *p1, const void *p2);
static int  compare_dn(const void *p1, const void *p2);
static int  compare_dnd(const void *p1, const void *p2);
static int  compare_ds(const void *p1, const void *p2);
static int  compare_jmp(const void *p1, const void *p2);
unsigned int
           *map_to_smap(OMNINEXUS *omni, int nvar);
int         copy_single_mc(ESNEXUS *result, char *src, int start, int end, int slen);
char        copy_single_mt(ESNEXUS *result, FMTNEXUS *work, int tok);
void        descit(OMNINEXUS *omni, int offset);
void        do_mops(OMNINEXUS *omni, int offset);
void        dump_commands(OMNINEXUS *omni, FMTNEXUS *this);
void        dump_bhia(int bits);
int         dump_if(OMNINEXUS *omni, int offset);
void        dump_ml(OMNINEXUS *omni, MLNEXUS *matches, char *section);
void        dump_mop(OMNINEXUS *omni, MOPNEXUS *mn);
void        dump_nvar(OMNINEXUS *omni, DVNEXUS *var, int which);
void        dump_ovector_mop(OMNINEXUS *omni, MOPNEXUS *mspec, char *target, int start);
void        dump_ovector_only(OMNINEXUS *omni, int start);
void        dump_pal(OMNINEXUS *omni, int offset);
void        dump_po(PONEXUS *this, char *string);
void        dump_separator(void);
void        dump_var(OMNINEXUS *omni, FMTNEXUS *var, int which);
void        dump_vars(OMNINEXUS *omni);
char       *dup_str(char *string, int length);
char       *dup_up_str(char *string, int length);
void        emit_help(void);
void        emit_help_cmd(void);
void        emit_help_examples(void);
void        emit_help_fmt(void);
void        emit_help_math(void);
void        emit_help_pat(void);
void        emit_help_po(void);
void        emit_help_var(void);
void        emit_output(OMNINEXUS *omni, FMTNEXUS *this, ESNEXUS *accum, FMTNEXUS *src,
              int ifeol, int ifbol, char *eol, char *bol,
              int linenumber, int linecount, int linelength, int linetokens, FIELD2NEXUS *efield);
void        es_adjust(ESNEXUS *dst, int start, int shiftval, int allocok);
void        es_append_aidat(ESNEXUS *dst, char *src, int slen, int inc, char *fail);
void        es_append_addat(ESNEXUS *dst, char *src, int slen, int inc, char *fail);
void        es_append_dat(ESNEXUS *dst, char *src, int slen, int inc, char *fail);
void        es_append_cptr(ESNEXUS *dst, char *src, int inc, char *fail);
void        es_append_str(ESNEXUS *dst, char *src, int slen, int inc, char *fail);
void        es_clear(ESNEXUS *dst);
ESNEXUS    *es_create(int size, char *fail);
void        es_destroy(ESNEXUS **target);
void        es_insert(ESNEXUS *dst, int offset, char *src, int slen, int inc, char *fail);
void        es_strcat(ESNEXUS *dst, char *src, int slen, int inc, char *fail);
int         exists(OMNINEXUS *omni, MOPNEXUS *mspec);
int         fetch_commands(FILE *fp,char ***argv);
void        ffit(OMNINEXUS *omni, int offset, double *dval);
void        FIELDNEXUS_clean(FIELDNEXUS *lcl, FIELDNEXUS *gbl);
void        FIELDNEXUS_destroy(FIELDNEXUS **efld);
char        field_postprocess( ESNEXUS *accum, OMNINEXUS *omni, char pdelim,
                  char delim, FIELD2NEXUS *fld, int options, FMTNEXUS *var);
void        field_postprocess_num(ESNEXUS *accum, OMNINEXUS *omni, 
                  FIELD2NEXUS *fld,  int options, double *dval, FMTNEXUS *var);
void        fillhole(OMNINEXUS *omni, int offset);
int         findmatches(OMNINEXUS *omni, ESNEXUS *target, MOPNEXUS *mspec, int start, int end);
void        fixupescapes(char *string);
void        fixuptag(char *tag, int *tagstate);
FMTNEXUS   *FMTNEXUS_init(int xc, int xe, ESNEXUS *common,  char *define, int dlen);
void        FMTNEXUS_destroy(FMTNEXUS *fn, int shared);
void        fn_to_pal(OMNINEXUS *omni, FIELDNEXUS *fld);
int         getnextline(char *buffer,int maxwidth,FILE **lcl_stdin,int infiles,
              char *indl, int samelines, int template, int handlenull, int crok);
int         get_range(char *string, int length, int *sc, int *nc, int *inc);
void        init_process_type(OMNINEXUS *omni, FMTNEXUS *fn, FIELDNEXUS *gblparams, int xe);
void        insane(const char *pre, const char *string);
void        insane2(const char *pre, const char *s1, const char *s2);
void        insane_var(const char *pre, const char *mode, const char var);
void        insane2_var(const char *prefix, const char *s1, const char *s2, const char var);
void        jl_clear(JLNEXUS *jumplist);
void        jl_destroy(JLNEXUS **jumplist);
void        jump_add(JLNEXUS *jumplist, int adpos, int mpos, char *string, int length);
int         jump_resolve(JLNEXUS *jumplist, ESNEXUS *alldata);
void        justit(OMNINEXUS *omni, int offset);
int         keep_substring(unsigned char *klist, int *vector, int len);
int         lcl_strcasecmp(char *s1, char *s2);
int         lcl_strncasecmp(char *s1, char *s2,int len);
int         lcl_strcmprange(char *s1, char *s2, int start, int end, int usecase);
int         lstrcasecmp(char *s1, int len1, char *s2, int len2);
int         lstrtol(char *string,int length, long *ival);
void        make_inp_tokens(FMTNEXUS *fmt, PONEXUS *po, char *emptystring);
unsigned char 
           *make_keep_substring(char *str, int len);
void        make_one_token(FMTNEXUS *fmt);
void        make_matches(OMNINEXUS *omni, PMLNEXUS *prematches,
              MLNEXUS *b_matches, MLNEXUS *m_matches, MLNEXUS *a_matches, 
              int ifn, int tagstate, int tagtermstate, char *tag, char *tagterm);
unsigned int
           *make_sort_map(unsigned int *smap,unsigned int *smsize,int sort,
                STRINGNEXUS *toklist, char *src, int start, int end, int tcount);
unsigned int 
           *make_sort_map_num(unsigned int *smap,unsigned int *smsize,int sort,
                double *list, int start, int end, int tcount);
void        match_p(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end);
void        match_s(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end);
void        match_t(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end);
void        match_v(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end);
void        match_nv(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end);
int         math_tests(OMNINEXUS *omni, MOPNEXUS *mspec);
void        MLNEXUS_destroy(MLNEXUS **eml);
int         nextpartialbuffer(char *pbuffer, char **first, int *flen, char **string,
                int ntokens, PONEXUS *po);
int         nvar_max_size(char *list, DVNEXUS *dn);
int         op_bhia(OMNINEXUS *omni, int offset);
int         op_clrv(OMNINEXUS *omni, int offset);
int         op_eol(OMNINEXUS *omni, int offset);
int         op_femit(OMNINEXUS *omni, int offset);
int         op_mrgv(OMNINEXUS *omni, int offset);
int         op_npopv(OMNINEXUS *omni, int offset);
int         op_nvv(OMNINEXUS *omni, int offset);
int         op_po(OMNINEXUS *omni, int offset); 
int         op_read(OMNINEXUS *omni, int offset);
int         op_semit(OMNINEXUS *omni, int offset);
int         op_setc(OMNINEXUS *omni, int offset);
int         op_showv(OMNINEXUS *omni, int offset);
int         op_shownv(OMNINEXUS *omni, int offset);
int         op_vemit(OMNINEXUS *omni, int offset);
int         op_vv(OMNINEXUS *omni, int offset);
void        padit(OMNINEXUS *omni, int offset);
void        parse_num(int *itok, int *next, char *str, int signmode);
void        parse_operations(MLNEXUS *matches, JLNEXUS *jumplist, ALNEXUS *autolist, OMNINEXUS *omni, char *operations);
void        PONEXUS_destroy(PONEXUS *po);
void        process_command_line_args(int argc,char **argv,
                PONEXUS *gbl_po, 
                int *maxwidth,
                int *sc,int *ec,
                int *sr,int *er,
                int *rm,
                int *all,
                FIELDNEXUS  *gblparams,
                int *xc,
                int *xe,
                int *dbg,
                int *tagstate,
                int *tagtermstate,
                int *ifn,
                int *ifonly,
                int *ifeol,
                int *ifbol,
                char **eol,
                char **bol,
                char ***fmt,
                char ***var,
                char **po,
                char **tag,
                char **tagterm,
                char **iftermeol,
                char **iftermbol,
                char **iffileeol,
                char **iffilebol,
                char **indl,
                int  *samelines,
                int  *linenumber,
                int  *linelength,
                int  *linetokens,
                int  *merge,
                int  *template,
                int  *handlenull,
                int  *crok,
                MLNEXUS    *subs,
                PMLNEXUS   *prematches
                );
void        rcit(OMNINEXUS *omni, int offset);
int         realends(int *rstart, int *rend, int lstart, int lend, int length);
void        realends_oops(int lstart, int lend, int length);
void        pattern_logic(OMNINEXUS *omni, MLNEXUS *matches, int start,int end);
void        re_precompile(char *string, int options, pcre **re);
void        regular_to_fmt(ESNEXUS *dst, char *buffer, int sc,int ec, int rm);
char        *strtok_variant(char *instring, STVNEXUS *hold, const char *delim, 
              int parse_options, char *empty,
              char *thedelim, int *start, int *length);
void        rtit(OMNINEXUS *omni, int offset);
void        setinumeric(int *val,int *numarg,int argc,char **argv,char * label);
void        setiposnumeric(int *val,int *numarg,int argc,char **argv,char * label);
char       *set_pat_options(char *options, MOPNEXUS *mop);
char       *set_rep_options(char *options, MOPNEXUS *mop);
void        setstring(char **val,int *numarg,int argc,char **argv,char * label);
void        setuchar(unsigned char *val,int *numarg,int argc,char **argv,char * label);
void        show_mops(OMNINEXUS *omni, int offset);
void        slashit(OMNINEXUS *omni, int offset);
void        subs_s(OMNINEXUS *omni, MOPNEXUS *mop);
void        subs_t(OMNINEXUS *omni, MOPNEXUS *mop);
void        subs_q(OMNINEXUS *omni, MOPNEXUS *mop);
void        subs_v(OMNINEXUS *omni, MOPNEXUS *mop);
void        subs_nv(OMNINEXUS *omni, MOPNEXUS *mop);
int         super_fgets(char *string, size_t size, FILE *stream,
              size_t *cterm, int enchar);
char       *to_operations(int tagstate, char *src);
char       *to_pattern(int tagstate, char *src);
void        trimit(OMNINEXUS *omni, int offset);
int         var_max_tcount(char *list, FMTNEXUS **vn);
void        var_presets(FMTNEXUS **vn);
char       *vlist_dup(char *vlist); 
int         vlist_holds(const char *vlist, const char test);
int         vlist_len(const char *src);
int         vlist_longest(OMNINEXUS *omni, const char *vlist);
int         vlist_longest_token(OMNINEXUS *omni, const char *vlist, int tn, int single);
char       *vlist_set(char **dst, int length, const char *src, int allowdash);
void        vlist_set1(char **dst, const char src);
void        vlist_show(FILE *fp, char *string);
char       *wait_insane(const char *pre, const char *string);
char       *wait_insane2(const char *pre, const char *s1, const char *s2);

/* math related function prototypes */
double      numeric_input(const char *nptr, char **endptr);
char       *categorize_operands(MASNEXUS *pstk,int psptr, enum math_ops *emop,
             int *shift, int *scroll, int *from, enum rpn_states *state);
static int  compare_tcx(const void *p1, const void *p2);
static int  compare_tix(const void *p1, const void *p2);
int         mop_properties(enum math_ops *mop, int where, int upper, int lower,
              int *shift, int *scroll, int *from, enum rpn_states *state);
ESNEXUS    *compile_math(char *string, char **message);
char       *op_precedence(char *string, int *assign, char **message);
char       *pre_run_math(OMNINEXUS *omni, ESNEXUS *program, ESNEXUS *rpnprog);
int         realends(int *rstart, int *rend, int lstart, int lend, int length);
char       *run_math_rpn(OMNINEXUS *omni, char *program, double *result);
char       *show_math_op(enum math_ops mop);
char       *show_stk_op(enum mstack_ops sop);
char       *strtok_math(char *string, char *thedelim, int *start, int *length);


/* globals */

FILE *lcl_stdin[MAXINFILE];
FILE *lcl_stdout[MAXOUTFILE];
int   infiles=0;
int   outfiles=0;
STRINGNEXUS *smuggle=NULL;  /* used to smuggle a toklist into the qsort, so that it can be sorted indirectly */
char *smuggle_str=NULL;  /* used to smuggle a toklist into the qsort, so that it can be sorted indirectly */

/* functions */

void insane(const char *pre, const char *string){
 (void) fprintf(stderr,"%s%s\n",pre,string);
 exit(EXIT_FAILURE);
}
void insane2(const char *pre, const char *s1, const char *s2){
  (void) fprintf(stderr,"%s%s [%s]\n",pre,s1,s2);
  exit(EXIT_FAILURE);
}
void insane_var(const char *prefix, const char *mode, const char var){
  fprintf(stderr,"%s%s %c\n",prefix,mode,FROMVAROFF(var));
  exit(EXIT_FAILURE);
}
void insane2_var(const char *prefix, const char *s1, const char *s2, const char var){
  fprintf(stderr,"%s%s%s %c\n",prefix,s1,s2,FROMVAROFF(var));
  exit(EXIT_FAILURE);
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

void emit_help(void){
(void) fprintf(stdout,"extract command summary:\n\n");
(void) fprintf(stdout,"This program extracts data from lines of text, either:\n");
(void) fprintf(stdout,"  Method 1: blocks of text by character column ranges\n");
(void) fprintf(stdout,"  Method 2: specified text token(s), located by delimiters\n");
(void) fprintf(stdout,"  Method 3: specified text token(s), located by pattern matching\n");
(void) fprintf(stdout,"  Processing may be restricted to a range of text rows.\n");
(void) fprintf(stdout,"  Data is read/written from/to stdin/stdout or input/output files.\n\n");
(void) fprintf(stdout,"Command line options are:\n");
(void) fprintf(stdout,"\n[ Processing modes ]\n");
(void) fprintf(stdout,"  -mc        extract characters (Default mode)\n");
(void) fprintf(stdout,"  -mt        extract tokens  (Default = extract characters)\n");
(void) fprintf(stdout,"               With -mt -sc/-ec/-nc/etc. refer to token numbers\n");
(void) fprintf(stdout,"               Tokens may be generated either by parsing by delimiters [Default]\n");
(void) fprintf(stdout,"               or by pattern matching.\n");
(void) fprintf(stdout,"\n[ Input/Output (maximum open files of all types: %d]\n",FOPEN_MAX);
(void) fprintf(stdout,"  -in  file1[,file2,file3...]  input file(s) (Default = stdin)\n");
(void) fprintf(stdout,"             If more than one input file paste lines side by side\n");
(void) fprintf(stdout,"             Use \"-\" to read one stream from stdin.\n");
(void) fprintf(stdout,"  -out file0[,file1...]  (up to 10) output file(s) (Default = stdout)\n");
(void) fprintf(stdout,"             Use \"-\" to write one stream to stdout.\n");
(void) fprintf(stdout,"  -cmd file  read more command line options from a file after all command\n");
(void) fprintf(stdout,"             line arguments are processed. See -hcmd for more information\n");
(void) fprintf(stdout,"  -eoc       Terminate input from a -cmd file.\n");
(void) fprintf(stdout,"\n[ Unconditional row/column limits ]\n");
(void) fprintf(stdout,"  -sc  N     start column      (1 is first and default)\n");
(void) fprintf(stdout,"  -ec  N     end   column      (<=wl, Default = wl)\n");
(void) fprintf(stdout,"  -nc  N     number of columns (Specify -ec or -nc but not both!)\n");
(void) fprintf(stdout,"  -sr  N     start row         (1 is first and default)\n");
(void) fprintf(stdout,"  -er  N     end   row         (Default = last row of file)\n");
(void) fprintf(stdout,"  -nr  N     number of rows    (Specify -er or -nr but not both!)\n");
(void) fprintf(stdout,"  -all       emit lines beyond row limits.\n");
(void) fprintf(stdout,"                               (Default = do not emit)\n\n");
(void) fprintf(stdout,"  -rm        remove selected columns/tokens \n");
(void) fprintf(stdout,"                               (Default = emit selected)\n");
(void) fprintf(stdout,"  -is        modify selected columns/tokens and emit all \n");
(void) fprintf(stdout,"                               (Default = emit selected)\n");
(void) fprintf(stdout,"\n[ Unconditional begin/end strings ]\n");
(void) fprintf(stdout,"  -fileeol STR \n");
(void) fprintf(stdout,"             emit STR after the last line of a file (default = none)\n");
(void) fprintf(stdout,"  -filebol STR \n");
(void) fprintf(stdout,"             emit STR before the first line of a file (default = none)\n");
(void) fprintf(stdout,"  -eol  STR  terminate lines with string (Default = end with \\n)\n");
(void) fprintf(stdout,"  -bol  STR  prefix lines with string (Default = no prefix )\n");
(void) fprintf(stdout,"\n[ Options that affect input processing ]\n");
(void) fprintf(stdout,"  -merge N   merge consecutive rows starting with the same N characters, separated by -mdl STR\n");
(void) fprintf(stdout,"  -unmerge N opposite of merge, works only with tokens delimited by -mdl STR\n");
(void) fprintf(stdout,"               Emit lines: first token + N tokens until line is consumed.\n");
(void) fprintf(stdout,"  -template N  Fill in missing records in a file using a template file.\n");
(void) fprintf(stdout,"             For each row the first N characters are compared.  The rows in the two\n");
(void) fprintf(stdout,"              files must be in the same order.  Use \"-in template,file\".  Missing \n");
(void) fprintf(stdout,"             rows from file are replaced by the first N characters from template plus -indl STR.\n");
(void) fprintf(stdout,"             In this mode only a blank line is equivalent to an EOF.\n");
(void) fprintf(stdout,"  -indl STR  string to place between input from multiple input files  (Default=none)\n");
(void) fprintf(stdout,"  -mdl  STR  string to place between input from multiple merged rows  (Default=none)\n");
(void) fprintf(stdout,"  -eqlen     require multiple input files to have exactly the same number of lines\n");
(void) fprintf(stdout,"  -crok      retain a CR immediately before an EOL (Default, delete these)\n");
(void) fprintf(stdout,"  -hnr       retain     embedded null characters (Default, fatal if nulls are found)\n");
(void) fprintf(stdout,"  -hnd       delete     embedded null characters \n");
(void) fprintf(stdout,"  -hns       substitute embedded null characters with \"\\%d\" \n",HNULL_SUBS);
(void) fprintf(stdout,"  -hnsubs CHAR\n");
(void) fprintf(stdout,"             substitute embedded null characters with CHAR\n");
(void) fprintf(stdout,"\n[ Options that affect conditional output ]\n");
(void) fprintf(stdout,"  -if  tag\n");
(void) fprintf(stdout,"             Modify row in range using -fmt only if it contains the text tag.\n");
(void) fprintf(stdout,"             Formats: [!][^]tag[$], ! = not in, ^ = front, $ = end \n");
(void) fprintf(stdout,"  -ifnorestart  Do not restart (extend) -if blocks at each matching -if tag.\n");
(void) fprintf(stdout,"             Normally tags are tested within an -if block and will extend if they match.\n");
(void) fprintf(stdout,"  -ifn N        extend result of -if N more lines or until EOF.\n");
(void) fprintf(stdout,"  -ifterm tag   extend result of -if until -ifterm tag matches or EOF\n");
(void) fprintf(stdout,"  -iftermeol STR \n");
(void) fprintf(stdout,"             emit STR after the last line of an -if block\n");
(void) fprintf(stdout,"  -iftermbol STR \n");
(void) fprintf(stdout,"             emit STR before the last line of an -if block\n");
(void) fprintf(stdout,"  -ifonly    only lines in an -if block are emitted\n");
(void) fprintf(stdout,"  -ifeol     omit EOL on lines within an -if block (does not effect iftermeol)\n");
(void) fprintf(stdout,"  -ifbol     omit BOL on lines within an -if block (does not effect iftermbol)\n");
(void) fprintf(stdout,"\n[ Options that affect delimiter based parsing of input into tokens ]\n");
(void) fprintf(stdout,"  -dl   STR  token delimiters  (Default = space,colon,tab)\n");
(void) fprintf(stdout,"  -s         each delimiter emits a token\n");
(void) fprintf(stdout,"               Use -s with delimited data as from a spreadsheet.\n");
(void) fprintf(stdout,"                               (Default = delimiter runs emit one token.)\n");
(void) fprintf(stdout,"  -dq        ignore delimiters within a token that starts and ends \n");
(void) fprintf(stdout,"               with double quotes.\n");
(void) fprintf(stdout,"                               (Default = recognize all delimiters)\n");
(void) fprintf(stdout,"  -dqs       like -dq, but surrounding double quotes are stripped\n");
(void) fprintf(stdout,"                               (Default = recognize all delimiters)\n");
(void) fprintf(stdout,"  -esc       respect escapes (backslashes) when parsing into tokens.\n");
(void) fprintf(stdout,"                               (Default = backslash is not special\n");
(void) fprintf(stdout,"  -po[N] PARSEOPTIONS\n");
(void) fprintf(stdout,"             Create up to %d sets of parse options.  See -hpo for more information.\n",MYPOSMAX);
(void) fprintf(stdout,"\n[ Options that affect pattern based token generation and other more complex data\n");
(void) fprintf(stdout,"   extraction and manipulation.  See -hpat for more information ]\n");
(void) fprintf(stdout,"  -vN DEF    Variable definitions, N must be A->Z.  See -hvars.\n");
(void) fprintf(stdout,"  -sect  SECTION\n");
(void) fprintf(stdout,"           Organize pattern commands into COMMON, BEFORE, MAIN, and AFTER sections.\n");
(void) fprintf(stdout,"           Functions defined in COMMON appear before the start position in the other\n");
(void) fprintf(stdout,"           sections and will not execute until they are called.  BEFORE\n");
(void) fprintf(stdout,"           and AFTER execute once outside the main loop, MAIN executes once\n");
(void) fprintf(stdout,"           for every line read in the main loop.\n");
(void) fprintf(stdout,"  -pm[N] PATTERN OPERATIONS\n");
(void) fprintf(stdout,"           Examine input (no N), or variable N (with N), for PATTERN.\n");
(void) fprintf(stdout,"           If it matches execute the True branch of OPERATIONS, otherwise\n");
(void) fprintf(stdout,"           execute the False branch.  -pm may be specified multiple times.\n");
(void) fprintf(stdout,"  -op[N] OPERATIONS\n");
(void) fprintf(stdout,"           Unconditionally execute OPERATIONS, which must contain only\n");
(void) fprintf(stdout,"           a True branch.  If N is specified it is the TARGET, otherwise\n");
(void) fprintf(stdout,"           the input buffer is the TARGET. -op may be specified multiple times.\n");
(void) fprintf(stdout,"  -ps[#] PATTERN REPLACE\n");
(void) fprintf(stdout,"           Examine OUTPUT fields for PATTERN.\n");
(void) fprintf(stdout,"           If found substitute with REPLACE.\n");
(void) fprintf(stdout,"           Define up to 10 (# = 0-9) pattern substitutions.\n");
(void) fprintf(stdout,"           These must be numbered and entered sequentially, like:\n");
(void) fprintf(stdout,"           -ps (or -ps0) -ps1 -ps2 etc.\n");
(void) fprintf(stdout,"  -psN PATTERN REPLACE\n");
(void) fprintf(stdout,"           Examine Variable N (A-Z) for PATTERN.\n");
(void) fprintf(stdout,"           If found substitute with REPLACE.\n");
(void) fprintf(stdout,"           These are not numbered.\n");
(void) fprintf(stdout,"\n[ Output field processing options ]\n");
(void) fprintf(stdout,"  -fmt[N] FMT   fine control of field extraction and line formatting.\n");
(void) fprintf(stdout,"             Up to 10 may be defined as -fmtN, N=0->9.  (-fmt==-fmt0)\n");
(void) fprintf(stdout,"             Formats must be numbered consecutively from 0.  0 may be omitted.\n");
(void) fprintf(stdout,"             The default format is N==0. (-pm may select a different one.)\n");
(void) fprintf(stdout,"             For backwards compatibility -cols == -fmt/-fmt0.\n");
(void) fprintf(stdout,"             See -hfmt and -hexamples. (Default = use -sc etc. for format)\n");
(void) fprintf(stdout,"  -dt        emit all but last token with first delimit character (Default)\n");
(void) fprintf(stdout,"  -dv C      emit all but last token followed by delimit character C\n");
(void) fprintf(stdout,"                               (Default = use actual delimiter)\n");
(void) fprintf(stdout,"  -d-        emit tokens without delimit character.\n");
(void) fprintf(stdout,"                               (Default = emit with actual delimiter)\n");
(void) fprintf(stdout,"  -pd  N     append N spaces to column (Default = no pad)\n");
(void) fprintf(stdout,"  -fw  N     make field N spaces wide  (Default = original width)\n");
(void) fprintf(stdout,"  -fp  N     make floating point precision N spaces wide  (Default = 6)\n");
(void) fprintf(stdout,"  -fff/ffe/ffd/ffu/ffo/ffx\n");
(void) fprintf(stdout,"             format all (numeric) fields/numeric variables as (double precision float)\n");
(void) fprintf(stdout,"              float/exponent/ (integer) /signed/unsigned/octal/hexadecimal (Default = text fields)\n");
(void) fprintf(stdout,"  -nz        print numeric -0 as -0 in float format (Default = print as 0)\n");
(void) fprintf(stdout,"  -jl/jr/jc  left/right/center    justify   (Default = no justify)\n");
(void) fprintf(stdout,"  -trl/trr/trb/trc  trim off whitespace left side/right side/both sides/\n");
(void) fprintf(stdout,"               both sides and reduce internal whitespace one space (Default = no trim)\n");
(void) fprintf(stdout,"  -cu/cf/cl  upper case/first letter upper & rest lower/lower case (Default = case unchanged)\n");
(void) fprintf(stdout,"  -bs,ba,b2  place a back slash (unix escape) before special characters, all characters,\n");
(void) fprintf(stdout,"               or all but the first character\n");
(void) fprintf(stdout,"  -ecc CHAR  use CHAR instead of back slash with -bs,ba,b2\n");
(void) fprintf(stdout,"  -desc      process escapes, \\\\ to \\ and so forth\n");
(void) fprintf(stdout,"  [ Sort operators require -mt to generate the tokens.  Sorts are performed \n");
(void) fprintf(stdout,"    only within a [field] (see -hfmt), in the output stage before  \n");
(void) fprintf(stdout,"    all other formatting. (Default = no sort) ]\n");
(void) fprintf(stdout,"  -sortas    sort tokens (case sensitive,   ascending).\n");
(void) fprintf(stdout,"  -sortds    sort tokens (case sensitive,   descending).\n");
(void) fprintf(stdout,"  -sortac    sort tokens (case insensitive, ascending).\n");
(void) fprintf(stdout,"  -sortdc    sort tokens (case insensitive, descending).\n");
(void) fprintf(stdout,"  -sortan    sort tokens (numeric,          ascending).\n");
(void) fprintf(stdout,"  -sortdn    sort tokens (numeric,          descending).\n\n");
(void) fprintf(stdout,"  -rs   STR  replacement string emitted when a column field is empty\n");
(void) fprintf(stdout,"                               (Default = do not replace empty fields)\n");
(void) fprintf(stdout,"  -rcds STR  delete characters found in STR. (Keep if str is \"!characters\").\n");
(void) fprintf(stdout,"                               (Default = allow all characters)\n");
(void) fprintf(stdout,"  -rcdc STR  case insensitive variant of -rcds\n");
(void) fprintf(stdout,"  -rcss STR  if character j in -rcds STR matches replace it with character j from -rcss STR\n");
(void) fprintf(stdout,"                                (Default = no substitutions)\n");
(void) fprintf(stdout,"  -rtds STR  delete STR from text (case sensitive).(Default = no action)\n");
(void) fprintf(stdout,"  -rtdc STR  delete STR from text (case insensitive).(Default = no action)\n");
(void) fprintf(stdout,"  -rtss STR  replace text removed by -rtds with STR (Default = no substitutions)\n");
(void) fprintf(stdout,"  -rtsvN     replace text removed by -rtds with contents of variable N (Default = no substitutions)\n");
(void) fprintf(stdout,"\n[ Output line processing options ]\n");
(void) fprintf(stdout,"  -b         binary output - emit \\n verbatim.  Not supported on all platforms.\n");
(void) fprintf(stdout,"  -n         emit input_line_number: before each output line.\n");
(void) fprintf(stdout,"  -ll        emit input_line_length: before each output line.\n");
(void) fprintf(stdout,"  -lt        emit input_line_token_count: before each output line.\n");
(void) fprintf(stdout,"\n[ Data size allocations ]\n");
(void) fprintf(stdout,"  -xc  N     Initial maximum tokens in an input line (Default = %d, increases automatically)\n",MYINIRANGES);
(void) fprintf(stdout,"  -xe  N     Parsed descriptions in a -fmt* or -v* (Default = %d, increases automatically)\n",MYINIFMT);
(void) fprintf(stdout,"  -wl  N     widest line (Default = 16000 characters, static)\n");
(void) fprintf(stdout,"\n[ Debugging options ]\n");
(void) fprintf(stdout,"  -dbg       emit state and parsing information\n");
(void) fprintf(stdout,"  -dbgv      emit STRING variables information\n");
(void) fprintf(stdout,"  -dbgp      emit raw substrings on pattern matches\n");
(void) fprintf(stdout,"  -dbgm      emit pm/ps information\n");
(void) fprintf(stdout,"  -dbgs      emit call stack information\n");
(void) fprintf(stdout,"  -dbga      emit autolabel information\n");
(void) fprintf(stdout,"\n[ Help and information options ]\n");
(void) fprintf(stdout,"  -h         print this help message (also -help --h --help -? --?)\n");
(void) fprintf(stdout,"  -hfmt      show the (many) -fmt options\n");
(void) fprintf(stdout,"  -hmath     more information math expressions\n");
(void) fprintf(stdout,"  -hpat      more information on -op,-pm,-ps,-sect\n");
(void) fprintf(stdout,"  -hvar      more information on variables\n");
(void) fprintf(stdout,"  -hexamples show examples\n");
(void) fprintf(stdout,"  -i         emit version, copyright, license and contact information\n");
(void) fprintf(stdout,"\nSpecial characters in strings: \\t is tab, \\n is LF, \\r is CR,\\\\ is \\ \n");
(void) fprintf(stdout,"                               \\19 is the character with value 19 decimal.\n");
exit(EXIT_FAILURE);
}

void emit_help_fmt(void){
(void) fprintf(stdout,"extract -fmt options:\n\n");
(void) fprintf(stdout,"  -fmt FORMAT allows fine grained control over multiple\n");
(void) fprintf(stdout,"    columns.  It is composed of a series of STR and FIELD constructs.\n");
(void) fprintf(stdout,"    For instance: \"STR1[cu:1,5]STR2[mt:5]\"\n");
(void) fprintf(stdout,"  STR (text outside of []) may contain any character. Use \\[, \\] or\n");
(void) fprintf(stdout,"    [[, ]] for a square bracket as a string character instead of a field delimiter. \n");
(void) fprintf(stdout,"  FIELD (a pair of [] brackets and the text inside) contains an optional\n");
(void) fprintf(stdout,"     colon delimited set of Format modifiers followed by a mandatory\n");
(void) fprintf(stdout,"     Range specifier (see below).  A FIELD may contain escaped\n");
(void) fprintf(stdout,"     characters including escaped square brackets.  Range specifiers\n");
(void) fprintf(stdout,"     are independent in each FIELD, so data may be reordered, repeated\n");
(void) fprintf(stdout,"     or omitted. When one or more consecutive FIELDs operate in token mode\n");
(void) fprintf(stdout,"     delimiters are emitted (subject to dt,dV,etc.) after each token until\n");
(void) fprintf(stdout,"     interrupted by a STR, character or numeric FIELD, or the end of the line.\n");
(void) fprintf(stdout,"  Modifiers share this suffix set:\n");
(void) fprintf(stdout,"     + as_set  = match command line specifications\n");
(void) fprintf(stdout,"     p default = match program defaults\n");
(void) fprintf(stdout,"     - disable = disable option\n");
(void) fprintf(stdout,"  Each FIELD may contain one or more of the following.\n");
(void) fprintf(stdout,"  Format modifiers:\n");
(void) fprintf(stdout,"    -/+/p  in first position - set all fields to indicated state\n");
(void) fprintf(stdout,"    mt/mc/m-/mp/m+         modifies -mt -mc\n");
(void) fprintf(stdout,"                            token fields/character fields/disable/default/as_set\n");
(void) fprintf(stdout,"    jl/jr/jc/j-/jp/j+      modifies -j*\n");
(void) fprintf(stdout,"                            justify left/right/center/disable/default/as_set\n");
(void) fprintf(stdout,"    trl/trr/trb/trc/tr-/trp/tr+      modifies -tr*\n");
(void) fprintf(stdout,"                            trims left/right/both/both and compress/disable/default/as_set\n");
(void) fprintf(stdout,"    cu/cl/cf/c-/cp/c+      modifies -c*\n");
(void) fprintf(stdout,"                            case upper/lower/first upper/disable/default/as_set\n");
(void) fprintf(stdout,"    bs/ba/b2/b-/bp/b+      modifies -bs,-ba, -b2\n");
(void) fprintf(stdout,"                            back slash special/bs all/bs all but first/disable/default/as_set\n");
(void) fprintf(stdout,"    eccCHAR/eccp/ecc+      modifies -ecc\n");
(void) fprintf(stdout,"                            use as escape character CHAR from -ecc,default, as_set\n");
(void) fprintf(stdout,"    dt/dvN/d-/dp/d+        modifies -d*\n");
(void) fprintf(stdout,"                            emit delimit from token/with char N/disable/default/as_set\n");
(void) fprintf(stdout,"    de/de-/dep/de+         modifies -desc\n");
(void) fprintf(stdout,"                            process escapes/ disable/default/as_set\n");
(void) fprintf(stdout,"    pd###/pd-/pdp/pd+      modifies -pd/-fw\n");
(void) fprintf(stdout,"                            pad with ### spaces/disable/default/as_set\n");
(void) fprintf(stdout,"    fw###/fw-/fwp/fw+      modifies -fw/-pd\n");
(void) fprintf(stdout,"                             field width to ### spaces/disable/default/as_set\n");
(void) fprintf(stdout,"    fp###/fp-/fpp/fp+      modifies -fp\n");
(void) fprintf(stdout,"                             floating precision to ### spaces/disable/default/as_set\n");
(void) fprintf(stdout,"    fff/ffe/ffd/ffu/ffo/ffx/ff-/ffp/ff+    modifies -ff*\n");
(void) fprintf(stdout,"                             floating format float/exp/int/unsigned int/octal/hex/disable/default/as_set\n");
(void) fprintf(stdout,"    nz/nz-/nzp/nz+         modifies -nz*\n");
(void) fprintf(stdout,"                             print -0 as -0 enable/disable/default/as_set\n");
(void) fprintf(stdout,"    psP/ps-/psp/ps+        modifies -ps\n");
(void) fprintf(stdout,"                             P = predefined pattern {0-9}.   Example: ps3 uses -ps3\n");
(void) fprintf(stdout,"    rssSTR/rs-/rsp/rs+     modifies -rs\n");
(void) fprintf(stdout,"                             rs is STR/from -rs/disable/default/as_set\n");
(void) fprintf(stdout,"    rcdsSTR/rcdcSTR/rcd-/rcdp/rcd+   modifies -rcds/-rcdc\n");
(void) fprintf(stdout,"                             rcds is STR/case insensitive STR/from -rcds/disable/default/as_set\n");
(void) fprintf(stdout,"    rcssSTR/rcs-/rcsp/rcs+ modifies -rcss\n");
(void) fprintf(stdout,"                             rcss is STR/from -rcss/disable/default/as_set\n");
(void) fprintf(stdout,"    rtdsSTR/rtd-/rtdp/rtd+ modifies -rtds\n");
(void) fprintf(stdout,"                             rtds is STR/disable/default/as_set\n");
(void) fprintf(stdout,"    rtssSTR/rtsvN/rts-/rtsp/rts+ modifies -rtss/-rtsc\n");
(void) fprintf(stdout,"                             rtss is STR/variable N/disable/default/as_set\n");
(void) fprintf(stdout,"    sortas/sortds/sortac/sortac/sortan/sortdn/sort-/sortp/sort+ modifies -sortas etc.\n");
(void) fprintf(stdout,"                             sort .../disable/default/as_set\n");
(void) fprintf(stdout,"    map$M/ump$M            MAP,UnMaP input token positions to output positions.\n");
(void) fprintf(stdout,"                             Numeric variable $M holds a MAP. For map the token\n");
(void) fprintf(stdout,"                             at output position i is that from input position $M[i].\n");
(void) fprintf(stdout,"                             For ump the token at output position $M[i] is that\n");
(void) fprintf(stdout,"                             from input position i. There is no corresponding\n");
(void) fprintf(stdout,"                             command line option.  Overrides Range, setting it to\n");
(void) fprintf(stdout,"                             [1,N,1], where N is the MAP size.  A single field may\n");
(void) fprintf(stdout,"                             not combine map, ump and sort modifiers.\n");
(void) fprintf(stdout,"   Range Specifier formats are:\n");
(void) fprintf(stdout,"       [] [c] [s,e] [s,] [,e] [s,,i] [,e,i] [,,i] [Colunn/Start, End, Increment]. \n");
(void) fprintf(stdout,"          or\n");
(void) fprintf(stdout,"       [$V] [$V,idx] [NUMERIC VARIABLE, index]. \n");
(void) fprintf(stdout,"       (All of the preceding forms may be overridden by the map/ump modifiers.)\n");
(void) fprintf(stdout,"       Defaults for implied range values are: [First, Last, 1]. The \n");
(void) fprintf(stdout,"       range must be the final option in a field. Start and End values\n");
(void) fprintf(stdout,"       may be positive or negative. If positive, they are positions\n");
(void) fprintf(stdout,"       measured from the front of the line, where 1 is the first column.\n");
(void) fprintf(stdout,"       If negative, they are positions measured from the end of\n");
(void) fprintf(stdout,"       the line, where -1 is the last column.  Mixed modes may be empty for some \n");
(void) fprintf(stdout,"       line lengths, but this is not an error.  (Example: [3,-3] for lines <5\n");
(void) fprintf(stdout,"       characters long.) The increment value may be anything other than zero.\n");
(void) fprintf(stdout,"       Increments only function in token mode - in character mode they are ignored. The\n");
(void) fprintf(stdout,"       range [,,-1] emits all tokens in a line in reverse order.\n\n");
(void) fprintf(stdout,"       In the NUMERIC VARIABLE forms a c/s,e,i triplet is retrieved from\n");
(void) fprintf(stdout,"       the 3 elements starting at the index.  If the index is omitted retrieval\n");
(void) fprintf(stdout,"       starts at the first element.\n");
(void) fprintf(stdout,"   The default source is the input line, but variables may be used instead by\n");
(void) fprintf(stdout,"   specifying one of the following within the [] range specifier. :\n");
(void) fprintf(stdout,"    vABC..Z     Variable values, in the order listed. Character or token mode.\n");
(void) fprintf(stdout,"                A variable may appear more than once on the list.  The values are\n");
(void) fprintf(stdout,"                selected by the range value, the specified formatting applied,\n");
(void) fprintf(stdout,"                and then the values are concatenated.\n");
(void) fprintf(stdout,"    =ABC..Z     Variable token values interleaved, missing filled from -rs. MT only.\n");
(void) fprintf(stdout,"    @ABC..Z     Variable token values interleaved by token.  MT only.\n");
(void) fprintf(stdout,"                If a variable's Nth token does not exist it is replaced with\n");
(void) fprintf(stdout,"                by its first/last token for positive/negative range increments..\n");
(void) fprintf(stdout,"   Use v$VLIST,=$VLIST, or @$VLIST for numeric variables instead. Numeric and string.\n");
(void) fprintf(stdout,"   variables cannot be combined in a single [] field.\n");
exit(EXIT_FAILURE);
}
void emit_help_po(void){
(void) fprintf(stdout,"extract -po options:\n\n");
(void) fprintf(stdout,"   Up to %d sets of parse options may be defined using\n",MYPOSMAX);
(void) fprintf(stdout,"   -po.  The first is applied to the input line if tokens \n");
(void) fprintf(stdout,"   are needed.  All may be used to parse strings stored in\n");
(void) fprintf(stdout,"   variables by using the po#VLIST operation in an\n");
(void) fprintf(stdout,"   -op/-pm/-pmN/-psN statement (see -hpat).  The first one \n");
(void) fprintf(stdout,"   may be set with -dq/-dqs/-esc/-s/-dl/-mdl on the command\n");
(void) fprintf(stdout,"   line.  It may also be set using colon delimited specifiers.\n");
(void) fprintf(stdout,"   The other parse option groups must be using the specifier syntax:\n\n");
(void) fprintf(stdout,"   dq,dqs,dq-,dqp,dq+     modifies parsing of double quoted text (like -dq, -dqs):\n");
(void) fprintf(stdout,"                             respect, respect & strip, disable, default, as_set\n");
(void) fprintf(stdout,"   sd,sd-,sdp,sd+         modifies parsing of delimiter runs (like -s):\n");
(void) fprintf(stdout,"                             token for: each, run, default, as_set\n");
(void) fprintf(stdout,"   esc,esc-,escp,esc+     modifies parsing of escape sequences (like -esc):\n");
(void) fprintf(stdout,"                             process escapes: yes, no, default, as_set\n");
(void) fprintf(stdout,"   dlvSTR,dlp,dl+         sets delimiter string (like -dl):\n");
(void) fprintf(stdout,"                             becomes STR, default, as_set.  dl- is forbidden.\n");
(void) fprintf(stdout,"   mdlvSTR,mdlp,mdl+      sets merge delimiter string (like -mdl):\n");
(void) fprintf(stdout,"                             becomes STR, default, as_set.  mdl- is forbidden.\n\n");
(void) fprintf(stdout,"   Example: -po3 'dq:dlv\\t' \n");
(void) fprintf(stdout,"       Parse options for group 3 are: respect double quotes and \n");
(void) fprintf(stdout,"       the only delimiters are tabs.\n");
exit(EXIT_FAILURE);
}

void emit_help_pat(void){
(void) fprintf(stdout,"Pattern Mode Overview:\n");
(void) fprintf(stdout,"  Character and token modes allow the processing of data from rigidly\n");
(void) fprintf(stdout,"  formatted text. Pattern mode extends data extraction to any file which\n");
(void) fprintf(stdout,"  contains recognizable text patterns. Because processing such files usually\n");
(void) fprintf(stdout,"  requires a small amount of logic, this mode also supports limited scripting.\n\n");
(void) fprintf(stdout,"Command line arguments:\n");
(void) fprintf(stdout,"  -ps# PATTERN REPLACE\n");
(void) fprintf(stdout,"      Statements execute during OUTPUT.  This occurs either during the default\n");
(void) fprintf(stdout,"      construction of the output line or in any [] field.  Up to 10 of them may be defined.\n");
(void) fprintf(stdout,"      and they are numbered 0-9.  These must be numbered and entered sequentially,\n");
(void) fprintf(stdout,"      -ps0 may also be written as -ps. In -fmt and -vN definitions\n");
(void) fprintf(stdout,"      these may be used like '[psv8C:1,3]' = search with pattern 8 and substitute\n");
(void) fprintf(stdout,"      with the contents of variable C.  See -hfmt.\n");
(void) fprintf(stdout,"  -pm[N]   PATTERN OPERATIONS\n");
(void) fprintf(stdout,"  -op[N]           OPERATIONS\n");
(void) fprintf(stdout,"  -psN PATTERN REPLACE\n");
(void) fprintf(stdout,"      Statements execute before OUTPUT, and in the order they were\n");
(void) fprintf(stdout,"      entered into the program. These act on the specified variable N.\n");
(void) fprintf(stdout,"  -sect  SECTION\n");
(void) fprintf(stdout,"      Organize pattern commands into BEFORE, MAIN, and AFTER sections,\n");
(void) fprintf(stdout,"      where the section refers to the position with respect to the\n");
(void) fprintf(stdout,"      input loop.  BEFORE may be used to initialize, AFTER to clean up.\n");
(void) fprintf(stdout,"      If no -sect is specified all -pm/-op/-ps are placed in MAIN.\n");
(void) fprintf(stdout,"      BEFORE and AFTER must only reference variables as the input\n");
(void) fprintf(stdout,"      is not defined in these sections.\n\n");
(void) fprintf(stdout,"Definitions and examples:\n");
(void) fprintf(stdout,"  VLIST is a list of single letter variables, like 'ABC', it must have\n");
(void) fprintf(stdout,"      at least one entry. When noted below, it may include '-' to represent\n");
(void) fprintf(stdout,"      the input. \n\n");
(void) fprintf(stdout,"  TARGET is the input buffer for -op, -pm and -ps; variable N for\n");
(void) fprintf(stdout,"      -opN, -pmN and -psN; or an entry in VLIST.\n\n");
(void) fprintf(stdout,"  The SUBSTRING LIST holds the results of match operations.  There\n");
(void) fprintf(stdout,"      is only one such list.  Match operations may clear it or append to it.\n\n");
(void) fprintf(stdout,"  PATTERN is defined by a single match specifier.  The specifier indicates\n");
(void) fprintf(stdout,"     which string or regular expression in PCRE syntax is the query.\n");
(void) fprintf(stdout,"     (For PCRE information see http://www.pcre.org/pcre.txt)\n");
(void) fprintf(stdout,"     Specifiers have format [BASE][MODIFIERS]:[WHAT].\n\n");
(void) fprintf(stdout,"   BASE specifiers that (may) add create or add to the SUBSTRING LIST:\n");
(void) fprintf(stdout,"      [The part to the right of the colon may not be empty.  The results\n");
(void) fprintf(stdout,"       of these matches are placed on the SUBSTRING LIST and correspond \n");
(void) fprintf(stdout,"       to different parts of PATTERN.  For PCRE pattern '(too)l(box)' matching\n");
(void) fprintf(stdout,"       the string 'toolbox' would make the list: 'toolbox', 'toolbox',\n");
(void) fprintf(stdout,"       'too', and 'box', where the substrings are not strictly sequential.\n");
(void) fprintf(stdout,"       Results from other pattern types will always be sequential.]\n");
(void) fprintf(stdout,"     p:RE            (PCRE regular expression) RE\n");
(void) fprintf(stdout,"     s:STRING        (string) STRING\n");
(void) fprintf(stdout,"     v:VLIST         (string(s)) any of the listed variable(s)\n");
(void) fprintf(stdout,"     n#:VLIST        (string(s)) token # in any of the listed variable(s)\n");
(void) fprintf(stdout,"                     # of 0 uses RESULT for the stream number (see -hmath).\n");
(void) fprintf(stdout,"     t:VLIST         (string(s)) any token(s) in the variable\n");
(void) fprintf(stdout,"   BASE specifiers that do not create or modify the SUBSTRING LIST:\n");
(void) fprintf(stdout,"     m:              always true.  (Normally one would use -op instead of -pm 'm:')\n");
(void) fprintf(stdout,"     ?:VLIST         Test for existence and length of input, variables, or tokens.\n");
(void) fprintf(stdout,"                     A VLIST entry of - tests the input buffer.\n");
(void) fprintf(stdout,"     ?CMP:VLIST      Test the value or status of NUMERIC variables in VLIST.\n");
(void) fprintf(stdout,"                     A VLIST entry of - tests RESULT.\n");
(void) fprintf(stdout,"                     True if all CMP (see MODIFIERS below) comparisons are true.\n");
(void) fprintf(stdout,"     i#:             True if input stream # is open, False otherwise.\n");
(void) fprintf(stdout,"                     Streams are 1->N, N from the number of entries with -in.\n");
(void) fprintf(stdout,"                     # of 0 uses RESULT for the stream number (see -hmath).\n");
(void) fprintf(stdout,"                     These are equivalent: i: and i1:.\n");
(void) fprintf(stdout,"   Specifier MODIFIERS may precede or follow the BASE, but must precede the colon delimiter:\n");
(void) fprintf(stdout,"     c               case invariant\n");
(void) fprintf(stdout,"     g               global (repeated search).\n");
(void) fprintf(stdout,"     /#[/#...]       (PCRE only.) only keep the substring(s) indicated by the\n");
(void) fprintf(stdout,"                     number.  For -[v]ps and complex patterns /1 will often\n");
(void) fprintf(stdout,"                     be needed so that the outer expression is substituted.\n");
(void) fprintf(stdout,"                     Numbers must be in range 1-255 and be in increasing order.\n");
(void) fprintf(stdout,"     r               remainder (search resumes in same target after previous match)\n");
(void) fprintf(stdout,"     ^               (not for PCRE) starts at first character \n");
(void) fprintf(stdout,"     $               (not for PCRE) ends at last character \n");
(void) fprintf(stdout,"   Modifiers when there are multiple search strings:\n");
(void) fprintf(stdout,"     q               seQuential search. All strings must match\n");
(void) fprintf(stdout,"                        and must appear in the order specified.\n");
(void) fprintf(stdout,"     f               test until First string matches.\n");
(void) fprintf(stdout,"     <               test all, nearest to the start of the target matches [DEFAULT].\n");
(void) fprintf(stdout,"     >               test all, nearest to the end of the target matches.\n");
(void) fprintf(stdout,"   Modifiers for math tests, use only one\n");
(void) fprintf(stdout,"                     must be specified.\n");
(void) fprintf(stdout,"     ?               Value is normal (not NaN or +=inf)\n");
(void) fprintf(stdout,"     =               Value is zero.\n");
(void) fprintf(stdout,"     <               Value is < zero.\n");
(void) fprintf(stdout,"     >               Value is > zero.\n");
(void) fprintf(stdout,"     #               Element number to test.  If 0, RESULT specifies.\n");
(void) fprintf(stdout,"   Modifiers for Existence tests\n");
(void) fprintf(stdout,"     t               test tokens (instead of variables)\n");
(void) fprintf(stdout,"     #               Without t, minimum variable size. If 0, RESULT specifies.\n");
(void) fprintf(stdout,"                     With t, token number to test. If 0, RESULT specifies.\n");
(void) fprintf(stdout,"   PATTERN Examples:\n");
(void) fprintf(stdout,"     's:Fred'        Fred (anywhere in the string)\n");
(void) fprintf(stdout,"     'sc^$:Fred'     A string containing only Fred (or fred or FRED etc.)\n");
(void) fprintf(stdout,"     'v:ABC'         Matches ...<vA>.. or ..<vB>.. or ..<vC>..\n");
(void) fprintf(stdout,"     'vq:ABC'        Matches ...<vA>...<vB>...<vC>..\n");
(void) fprintf(stdout,"     'vqr:ABC'       Matches ...<PREVIOUSMATCH>...<vA>...<vB>...<vC>..\n");
(void) fprintf(stdout,"                     but not ...<vA>...<PREVIOUSMATCH>...<vB>...<vC>..\n");
(void) fprintf(stdout,"     'p:Fred'        Fred\n");
(void) fprintf(stdout,"     'p:(?i)Fred'    Fred, fred, FRED etc. (Better to use the 'c' modifier.)\n");
(void) fprintf(stdout,"     'p:^Fred$'      A line containing just Fred and no other characters\n");
(void) fprintf(stdout,"     'p:(?i)(Fred).*(Ginger)'  Matches: ... fred ... ginger ...\n");
(void) fprintf(stdout,"                     This creates a list of 3 matches, the whole pattern,\n");
(void) fprintf(stdout,"                     fred, and ginger, which may be assigned to variables\n");
(void) fprintf(stdout,"                     using OPERATIONS.\n");
(void) fprintf(stdout,"     '?:-'           Always True (input buffer always exists).\n");
(void) fprintf(stdout,"     '?e:-'          True if the input buffer is empty.\n");
(void) fprintf(stdout,"     '?t3:-'         True if -mt and >=3 tokens were parsed from the input buffer.\n");
(void) fprintf(stdout,"     '?:ABC'         True if A,B, and C are all defined (not cleared).\n");
(void) fprintf(stdout,"     '?t-4:ABC'      True if TOKEN NUMBER -4 exists in A,B,and C.\n");
(void) fprintf(stdout,"     '?te3:ABC'      True if TOKEN NUMBER 3 exists and is empty in A,B,and C.\n");
(void) fprintf(stdout,"     '?<:ABC'        True if all elements in NUMERIC variables A,B,C are negative.\n");
(void) fprintf(stdout,"     '?>3:ABC'       True if element 3 in NUMERIC variables A,B,C is positive.\n");
(void) fprintf(stdout,"     '??:ABC'        True if all elements in NUMERIC variables A,B,C are normal numbers.\n");
(void) fprintf(stdout,"     '?>:-'          True if RESULT is greater than zero.\n");
(void) fprintf(stdout,"                     [May be used to test for 'token 3 of A is at least 5 characters\n");
(void) fprintf(stdout,"                     long' by preceding with -op '? tln(a[3])-4'.  (see -hmath).]\n");
(void) fprintf(stdout,"  REPLACE is one or more text strings from one of several sources. \n");
(void) fprintf(stdout,"     these are used to replace pattern matches sequentially.  If\n");
(void) fprintf(stdout,"     all of the source strings are used it starts over again with the first.\n");
(void) fprintf(stdout,"     s:STRING        (string) STRING\n");
(void) fprintf(stdout,"     v:VLIST         (string(s)) from the variable(s)\n");
(void) fprintf(stdout,"     n#:VLIST        (string(s)) in token number # from the variable(s)\n");
(void) fprintf(stdout,"                     # of 0 uses RESULT for the token number (see -hmath).\n");
(void) fprintf(stdout,"     t:VAR           Only with PATTERN t:, where token i of PATTERN found in target\n");
(void) fprintf(stdout,"                     replace with token i from VAR\n");
(void) fprintf(stdout,"     q:VLIST         (string(s)) in all token(s) from the variable\n\n");
(void) fprintf(stdout,"  OPERATIONS is a semicolon separated list containing one or more \n");
(void) fprintf(stdout,"      of the elements listed below.  Elements may be preceded by spaces\n");
(void) fprintf(stdout,"      but must be immediately followed by a delimiter (';' or end of token).\n");
(void) fprintf(stdout,"      Whenever a -pm is executed its operations are run before the\n");
(void) fprintf(stdout,"      next pattern match is attempted.  OPERATIONS is written as a\n");
(void) fprintf(stdout,"      single list, but that list is logically divided into True and False\n");
(void) fprintf(stdout,"      sections by a '!' operator, with each part of the list executing\n");
(void) fprintf(stdout,"      conditionally on the match or test.  Unless otherwise specified \n");
(void) fprintf(stdout,"      in this section all variables are STRING variables.\n\n");
(void) fprintf(stdout,"   op        Description\n\n");
(void) fprintf(stdout,"  <logic control:>\n");
(void) fprintf(stdout,"   !         Elements in an operations list before this execute when the match or test\n");
(void) fprintf(stdout,"             is true, after it, when it is false. One or the other set may be empty,\n");
(void) fprintf(stdout,"             which means do nothing for that condition. \n\n");
(void) fprintf(stdout,"  <pattern match interpretation:>\n");
(void) fprintf(stdout,"   %%COND     COND is any combination of {BHIA}. These modify \n");
(void) fprintf(stdout,"             the SUBSTRING LIST and affect how the list entries \n");
(void) fprintf(stdout,"             are assigned to tokens by the '>' operator.\n");
(void) fprintf(stdout,"             Default is to assign the list as is.  By specifying Before(first hit),\n");
(void) fprintf(stdout,"             Hit, Interior (between hits),After (last hit) these other substrings\n");
(void) fprintf(stdout,"             are derived and added to the substring list. If a specified \n");
(void) fprintf(stdout,"             interpolated substring does not exist, for instance, no Before\n");
(void) fprintf(stdout,"             because the first hit is at the first character, an empty token is created.\n");
(void) fprintf(stdout,"             Use with care for PCRE matches, which may not be sequential!\n");
(void) fprintf(stdout,"             Should only be used once for each set of operations!\n");
(void) fprintf(stdout,"             ALL is equivalent to BHIA.  Defaults to H (use pattern matches as is).\n\n");
(void) fprintf(stdout,"  <variable and input/output (all except v must be applied to SET variables [see -hvar]):>\n");
(void) fprintf(stdout,"   xVLIST    Clear the listed Set variables (they may not be a TARGET again until set).\n");
(void) fprintf(stdout,"   x#VLIST   Remove from token number # to the last token.\n");
(void) fprintf(stdout,"             Token number at or before the first token clears all.\n");
(void) fprintf(stdout,"             Token number after the last token clears none.\n");
(void) fprintf(stdout,"             # of 0 uses RESULT for the token number (see -hmath).\n");
(void) fprintf(stdout,"             These are equivalent: -x1A and -xA. \n");
(void) fprintf(stdout,"   vVLIST    Apply the Defined variables' -vN definitions to the TARGET.\n");
(void) fprintf(stdout,"   vVLIST<N  Like the preceding, but default input is from vN. VLIST should not include vN.\n");
(void) fprintf(stdout,"             (These are equivalent:  -pmA 'm:' 'vB' and -pm 'm: 'vB<A'.)\n");
(void) fprintf(stdout,"   |VLIST    Append a new line (\\n) to any variables in VLIST that are not empty.\n");
(void) fprintf(stdout,"             Also change the last token's delimiter value to \\n.\n");
(void) fprintf(stdout,"   >VLIST    Append to one or more SET variables from the SUBSTRING LIST,\n");
(void) fprintf(stdout,"             using one SUBSTRING LIST entry for each variable in the VLIST.\n");
(void) fprintf(stdout,"             Variables are A->Z or -, - means ignore that part of the match.\n");
(void) fprintf(stdout,"             Variables are processed in the order listed.  If the number\n");
(void) fprintf(stdout,"             of substrings is longer than the list the list is processed again.\n");
(void) fprintf(stdout,"             The SUBSTRING LIST is not consumed.  Examples, for 7 entries:\n");
(void) fprintf(stdout,"               >ABC appends 1,4,7 to A, 2,5 to B, 3,6 to C.\n");
(void) fprintf(stdout,"               >A-A appends 1,3,4,6,7 to A.\n");
(void) fprintf(stdout,"               >A   appends 1,2,3,4,5,6,7 to A.\n");
(void) fprintf(stdout,"   +N        Append the entire TARGET to vN (extends the string, adds token[s]).\n");
(void) fprintf(stdout,"             corresponding to the extended region).\n");
(void) fprintf(stdout,"             For any of the append operations, if TARGET is the input line\n");
(void) fprintf(stdout,"             an -mt or [:mt:] is needed or no tokens will have been generated.\n");
(void) fprintf(stdout,"   +N<=STR   Append STR to vN (extends the string, adds one token).\n");
(void) fprintf(stdout,"             STR may include \\n and similar escape sequences.\n");
(void) fprintf(stdout,"   +N<[FMT]  Append [FMT] to vN (extends the string, adds tokens).\n");
(void) fprintf(stdout,"             See -hfmt for [] options. Example: +A<[mt:1,3] adds 3 tokens.\n");
(void) fprintf(stdout,"   +N<VLIST  Append all of each variable in VLIST to vN.\n");
(void) fprintf(stdout,"             A '-' in VLIST appends from the input.\n");
(void) fprintf(stdout,"             (These are equivalent:  -opA '+B' and -op '+B<A'.)\n");
(void) fprintf(stdout,"   +N<#      Append token number # from TARGET to vN. \n");
(void) fprintf(stdout,"             # of 0 uses RESULT for the token number (see -hmath).\n");
(void) fprintf(stdout,"   +N<#VLIST Like +N<# but TARGET is VLIST. A '-' for input is allowed in VLIST.\n");
(void) fprintf(stdout,"             (These are equivalent:  -opA '+B<1' and -op '+B<1A'.)\n");
(void) fprintf(stdout,"   ?EXPR     Run the math expression EXPR.  See -hmath for syntax.\n");
(void) fprintf(stdout,"   mVLIST    If a variable is SET, merge all tokens into one.  Otherwise, do nothing.\n");
(void) fprintf(stdout,"             (This is the inverse of the po operation, see below.)\n");
(void) fprintf(stdout,"   m#VLIST   If a variable is set, merge from token number # to the end.\n");
(void) fprintf(stdout,"             Token number at or before the first token merges all.\n");
(void) fprintf(stdout,"             Token number at or after the last token merges none.\n");
(void) fprintf(stdout,"             # of 0 uses RESULT for the token number (see -hmath).\n");
(void) fprintf(stdout,"             These are equivalent: -m1A and -mA. \n");
(void) fprintf(stdout,"   <#VLIST   Emit each variable in VLIST to the # output stream.\n");
(void) fprintf(stdout,"             Output streams match -out entries, counting from 0.\n");
(void) fprintf(stdout,"             The number may be omitted for the default (0) output stream.\n");
(void) fprintf(stdout,"             A '-' in VLIST emits the input.  Use <#[FMT] (see below) to\n");
(void) fprintf(stdout,"             to emit NUMERIC variables\n");
(void) fprintf(stdout,"   >#        Read the next line from input stream # into the input buffer. \n");
(void) fprintf(stdout,"             # is 1->N, where N is the number of files in the -in statement.\n");
(void) fprintf(stdout,"             # of 0 uses RESULT for the stream number (see -hmath).\n");
(void) fprintf(stdout,"             Safe in -sects Before and After, but not recommended for -sect Main, where\n");
(void) fprintf(stdout,"             there will be complex interactions with the built in read loop.\n");
(void) fprintf(stdout,"             These are equivalent: > and >1.\n");
(void) fprintf(stdout,"   <#=STR    Emit STR to the # output stream. # is 0->N-1, N set by -out statement.\n");
(void) fprintf(stdout,"             These are equivalent: < and <0.\n");
(void) fprintf(stdout,"   <#[FMT]   Emit FMT to the # output stream. See -hfmt for [] options.\n");
(void) fprintf(stdout,"   ~VLIST    Dump each STRING variable in VLIST to stderr (for debugging).\n");
(void) fprintf(stdout,"   ~$VLIST   Dump each NUMERIC variable in VLIST to stderr (for debugging).\n");
(void) fprintf(stdout,"   po#VLIST  Make tokens for each variable in VLIST using the parse option set\n");
(void) fprintf(stdout,"             # (0-9) created with -po.  poA is equivalent to po0A.\n\n");
(void) fprintf(stdout,"  <output control (These apply only in -sect Main):>\n");
(void) fprintf(stdout,"   [ -fmt is applied when -if is true, see also -ifonly ].\n");
(void) fprintf(stdout,"   if1       Equivalent to a true -if statement (without -ifn or -ifterm).\n");
(void) fprintf(stdout,"   ifc       Equivalent to a true -if statement (with -ifn).\n");
(void) fprintf(stdout,"   if+       Equivalent to a true -if statement (with -ifterm).\n");
(void) fprintf(stdout,"   if-       Equivalent to a true -ifterm statement,\n");
(void) fprintf(stdout,"   ifr       Equivalent to an -ifnorestart statement,\n");
(void) fprintf(stdout,"               if+- is allowed.  Also terminates ifc.\n");
(void) fprintf(stdout,"               if[c+]r is like -if -ifnorestart.\n");
(void) fprintf(stdout,"   n#        Equivalent to -ifN #.\n");
(void) fprintf(stdout,"   afmt#     Make -fmt# active for this input line.  # is 0->9.\n");
(void) fprintf(stdout,"   nfmt#     Make -fmt# active next, after completing the current input.\n");
(void) fprintf(stdout,"   hide      Suppress -fmt and default output (overrides -if logic).\n");
(void) fprintf(stdout,"   show      Allow -fmt and default output. (Accept -if logic, [Default])\n");
(void) fprintf(stdout,"             [hide and show 'stick' once set, affecting all subsequent output.]\n");
(void) fprintf(stdout,"   eof       Close the input. (No more input results in no more output.)\n\n");
(void) fprintf(stdout,"  <flow control (through the -op/pm/pmN/psN list):>\n");
(void) fprintf(stdout,"   [By default statements execute sequentially in the order entered.\n");
(void) fprintf(stdout,"   Other patterns may be achieved using these operations.  Automatic \n");
(void) fprintf(stdout,"   labels provide a way to specify jump targets without having to separately\n");
(void) fprintf(stdout,"   name each statement.  However, getting there still requires using an explicit\n");
(void) fprintf(stdout,"   jump operation: '^' or 'sw'.  Labels alone have no effect on flow control,\n");
(void) fprintf(stdout,"   use a ret or a brk to prevent flow from passing down to the next line.]\n\n");
(void) fprintf(stdout,"   =LBL      Label this -op/pm/pmN/psN command as LBL.  The label may\n");
(void) fprintf(stdout,"             appear anywhere in the OPERATIONS list.  However, the script\n");
(void) fprintf(stdout,"             is easiest to read if labels are first in the OPERATIONS list.\n");
(void) fprintf(stdout,"             LBL may not begin with digits, contain spaces or semicolons, or\n");
(void) fprintf(stdout,"             be a valid automatic label [ {,}{,},c,c#, or c#-# ]. Labels are \n");
(void) fprintf(stdout,"             not case sensitive.\n");
(void) fprintf(stdout,"             The special label MAIN may mark the script line where execution begins.\n");
(void) fprintf(stdout,"             If MAIN is not employed execution starts on the first line of the script.\n");
(void) fprintf(stdout,"   &LBL      Call function at LBL. Recursion is allowed, but note that all \n");
(void) fprintf(stdout,"             variables have global scope.  On returning from the call\n");
(void) fprintf(stdout,"             the remainder of the statement's operations are processed.\n");
(void) fprintf(stdout,"             Functions must be placed so that they do not execute unless called,\n");
(void) fprintf(stdout,"             for instance, after an exit or jump that passes over it.\n");
(void) fprintf(stdout,"   {, }{, }  Generate automatic nestable labels.  May be used to create\n");
(void) fprintf(stdout,"             if/then/else, if/ifelse/else, while and other logical structures\n");
(void) fprintf(stdout,"             without requiring explicit labels for each jump target  Braces must\n");
(void) fprintf(stdout,"             appear in an operation before any jumps that reference positions in this\n");
(void) fprintf(stdout,"             structure, else that jump will reference the enclosing structure.\n");
(void) fprintf(stdout,"             The only combination of braces that can share a statement is\n");
(void) fprintf(stdout,"             multiple closing braces. \n");
(void) fprintf(stdout,"             A '{' need not be a jump target, but all '}{' and '}' must be.\n");
(void) fprintf(stdout,"             Use -dbga to resolve related syntax issues.\n");
(void) fprintf(stdout,"   c, c#, c#-#\n");
(void) fprintf(stdout,"             Generate (automatic) nestable case labels for a switch statement.\n");
(void) fprintf(stdout,"             The number of case labels must match the switch specification, \n");
(void) fprintf(stdout,"             'swC', see below. If present, each # is an integer from 0 -> C-1.\n");
(void) fprintf(stdout,"             c25 is a single case, c2-5 is a range of 4 cases.  Without explicit\n");
(void) fprintf(stdout,"             numbering the 'c' labels are numbered sequentially from 0.  The \n");
(void) fprintf(stdout,"             numeric and nonnumeric forms may not be mixed in a single switch\n");
(void) fprintf(stdout,"             statement. Multiple case labels may be applied to the same statement.\n");
(void) fprintf(stdout,"             Case labels may be applied to -pm[N] statements.\n");
(void) fprintf(stdout,"   [The SWITCH INDEX is only used by sw statements, which clear it.]\n");
(void) fprintf(stdout,"   im        Set the SWITCH INDEX to the token number of the last 't:N' match\n");
(void) fprintf(stdout,"             (1->N).  If the last test failed, the SWITCH INDEX is set to 0.\n");
(void) fprintf(stdout,"   ip        Set the SWITCH INDEX by the character position of the first match\n");
(void) fprintf(stdout,"             (1->N).  If the last test failed, the SWITCH INDEX is set to 0.\n");
(void) fprintf(stdout,"   i#        Shift SWITCH INDEX 1 bit left and set (#=1) or clear (#=0) the low bit.\n");
(void) fprintf(stdout,"   ir        Set SWITCH INDEX with RESULT from last math operation.\n");
(void) fprintf(stdout,"   [The following terminate processing of a statement's OPERATIONS.]\n");
(void) fprintf(stdout,"   ^LBL      Jump to the -op/pm/pmN/psN with the corresponding label.\n");
(void) fprintf(stdout,"             Reserved labels are '{[{...]','}{', and '}[}...]', which \n");
(void) fprintf(stdout,"             jump to the corresponding automatic label in this or an\n");
(void) fprintf(stdout,"             enclosing structure. \n");
(void) fprintf(stdout,"   ^#        Skip forward # statements. ^0 is a one line loop, and\n");
(void) fprintf(stdout,"             ^1 is pointless, since the next line would execute next anyway.\n");
(void) fprintf(stdout,"   swC       Switch. Jump to the statement ([automatically] labeled as 'cX'), \n");
(void) fprintf(stdout,"             where X is the value of the SWITCH INDEX, then clear that index. \n");
(void) fprintf(stdout,"             The number of cases is set by C. The value of X must be in the\n");
(void) fprintf(stdout,"             range 0 -> C-1.\n");
(void) fprintf(stdout,"   ret       Return from a function call.\n");
(void) fprintf(stdout,"   brk       Skip the remainder of the -op/pm/pmN/psN statements.\n");
(void) fprintf(stdout,"   exit      Exit the program with SUCCESS status.\n");
(void) fprintf(stdout,"   fail      Exit the program with FAILURE status.\n");
(void) fprintf(stdout,"  OPERATIONS abbreviations:\n");
(void) fprintf(stdout,"      In a -cmd file (only) an abbreviated syntax may be used:\n");
(void) fprintf(stdout,"        Long  short\n");
(void) fprintf(stdout,"        -pm   m\n");
(void) fprintf(stdout,"        -pmN  mN\n");
(void) fprintf(stdout,"        -psN  sN\n");
(void) fprintf(stdout,"        -op   o\n");
(void) fprintf(stdout,"        -opN  oN\n\n");
(void) fprintf(stdout,"      Labels may be placed in a separate token at the beginning of the line - \n");
(void) fprintf(stdout,"      see the examples. It is legal to have some labels in\n");
(void) fprintf(stdout,"      separate tokens and others in the OPERATIONS string for the\n");
(void) fprintf(stdout,"      same statement.  One or more terminal '}'s may be used\n");
(void) fprintf(stdout,"      without a following argument. Because tokens are delimited by\n");
(void) fprintf(stdout,"      spaces and EOL \"c4 =Label c1;c3 (new line)c2\" is equivalent to\n");
(void) fprintf(stdout,"      \"c4;=Label;c1;c3;c2\".\n"); 
(void) fprintf(stdout,"      A '};' may appear on an otherwise blank line to close a\n");
(void) fprintf(stdout,"      set of braces. The semicolon prevents the label from joining \n");
(void) fprintf(stdout,"      with the next statement, which would be invalid if it resulted \n");
(void) fprintf(stdout,"      in '}' and '{' appearing together.  A trailing '}' at the\n");
(void) fprintf(stdout,"      end of a section does not require a semicolon, nor does one\n");
(void) fprintf(stdout,"      which precedes a statement with no brace labels.\n");
(void) fprintf(stdout,"  OPERATIONS Examples:\n");
(void) fprintf(stdout,"   -pm \"s:Match?\" \"+A; !;x1A\"\n");
(void) fprintf(stdout,"                 If match/test is true, append TARGET to vA. If\n");
(void) fprintf(stdout,"                 false, delete most recent token from vA\n");
(void) fprintf(stdout,"   -pm \"s:Match?\" \"+A;po1A;+B<3A\"\n");
(void) fprintf(stdout,"                 If match/test is true, append TARGET to vA,\n");
(void) fprintf(stdout,"                 make tokens using po1, append the 3rd token which\n");
(void) fprintf(stdout,"                 results to vB.  If false, do nothing.\n");
(void) fprintf(stdout,"   -pm \"s:Match?\" \"if+; !; brk\"\n");
(void) fprintf(stdout,"                 If match/test is true, set the IF state to 'true until terminated',\n");
(void) fprintf(stdout,"                 unless it is already true, in which case do nothing.\n");
(void) fprintf(stdout,"                 If false, stop processing -op/pm/pmN/psN logic for\n");
(void) fprintf(stdout,"                 this input line. \n");
(void) fprintf(stdout,"   -pm \"s:Match?\" \"=Label; &Func1;!;<= Some failure\\n;fail\"\n");
(void) fprintf(stdout,"                 Identify this line as 'Label'. If match/test is true\n");
(void) fprintf(stdout,"                 call Func1. If false emit a failure message and exit.\n");
(void) fprintf(stdout,"   -pm \"s:Match?\" \"{; !; ^}}\"\n");
(void) fprintf(stdout,"                 Generate an automatic label for this line.  If match/test\n");
(void) fprintf(stdout,"                 is true fall through, else jump to enclosing final brace.\n");
(void) fprintf(stdout,"   -pm \"s:Fred\"   \"i1; !;i0\"\n");
(void) fprintf(stdout,"   -pm \"s:Ginger\" \"i1; !;i0\"\n");
(void) fprintf(stdout,"   -pm \"s:Dance\"  \"i1; !;i0\"\n");
(void) fprintf(stdout,"                 Construct a switch index based on the results of three\n");
(void) fprintf(stdout,"                 match/tests.\n");
(void) fprintf(stdout,"   -op \"{;                       sw8\"\n");
(void) fprintf(stdout,"    -op  \"c;      <=some action\\n;  ^}\" ##case 0\n");
(void) fprintf(stdout,"    -op  \"c;c;c;  <=some action\\n;  ^}\" ##cases 1,2,3\n");
(void) fprintf(stdout,"    -op  \"c;      <=some action\\n;  ^}\" ##case 4\n");
(void) fprintf(stdout,"    -op  \"c;      <=some action\\n;  ^}\" ##case 5\n");
(void) fprintf(stdout,"    -op  \"c;c;    <=some action\\n;  ^}\" ##cases 6,7\n");
(void) fprintf(stdout,"   -op \"}\"\n");
(void) fprintf(stdout,"                 An 8 case switch construct with single line cases,\n");
(void) fprintf(stdout,"                 the labels are automatic but the cases are commented.\n");
(void) fprintf(stdout,"                 The (automatic) labels are on the left side, the\n");
(void) fprintf(stdout,"                 jumps (sw and ^) on the right.\n");
(void) fprintf(stdout,"   -op \"{;                       sw4\"\n");
(void) fprintf(stdout,"    -op  \"c0;c3;  <=some action for 0,3\\n;  ^}\"\n");
(void) fprintf(stdout,"    -op  \"c1;c2;  <=some action for 1,2\\n;  ^}\"\n");
(void) fprintf(stdout,"   -op \"}\"\n");
(void) fprintf(stdout,"                 A 4 case switch construct with single line cases,\n");
(void) fprintf(stdout,"                 the explicit case labels are not in sequential order.\n");
(void) fprintf(stdout,"    {\n");
(void) fprintf(stdout,"              o \"sw4\"\n");
(void) fprintf(stdout,"      c0;c3   o \"  <=some action for 0,3\\n;  ^}\"\n");
(void) fprintf(stdout,"      c1\n");
(void) fprintf(stdout,"      c2\n");
(void) fprintf(stdout,"            -op \"  <=some action for 1,2\\n;  ^}\"\n");
(void) fprintf(stdout,"    }; \n");
(void) fprintf(stdout,"                 The same 4 case switch construct (mostly) using\n");
(void) fprintf(stdout,"                 the abbreviated syntax.  Note the semicolon\n");
(void) fprintf(stdout,"                 following the close brace, which precludes collisions\n");
(void) fprintf(stdout,"                 with a following line - because a label like '};{;' is forbidden.\n");
(void) fprintf(stdout,"   \n");
exit(EXIT_FAILURE);
}

void emit_help_math(void){
(void) fprintf(stdout,"Math expression syntax:\n");
(void) fprintf(stdout,"  RESULT: is the final number calculated in an expression.  It may be tested\n");
(void) fprintf(stdout,"    with the -pm '?' operator.\n");
(void) fprintf(stdout,"    RESULT may be loaded as $-, but $- cannot be assigned.\n");
(void) fprintf(stdout,"  Variables: may either be NUMERIC ($A) or STRING (A,if holding\n");
(void) fprintf(stdout,"    purely numeric text like '12.34').\n");
(void) fprintf(stdout,"    Cells/Tokens may be indexed as 1->N (from start) or -1->-N (from end).\n");
(void) fprintf(stdout,"  Scalar and Array math:  Unless otherwise noted operators and functions will\n");
(void) fprintf(stdout,"    work with either scalar or array operands.  If array operands are used\n");
(void) fprintf(stdout,"    the result will also be an array, with intermediate values stored in the\n");
(void) fprintf(stdout,"    leftmost array at each operation.  In scalar math the RETURN\n");
(void) fprintf(stdout,"    value is meaningful, but it is not in array math. Except for a straight\n");
(void) fprintf(stdout,"    assignment only NUMERIC variables may be used in Array math.\n");
(void) fprintf(stdout,"  Operands:\n");
(void) fprintf(stdout,"    12e-1,120,0xF0,0o77,0b1010 \n");
(void) fprintf(stdout,"                         numbers in float, integer, hexadecimal, octal, or binary formats\n");
(void) fprintf(stdout,"    $A                   NUMERIC variable ($A is the same as $A[1])\n");
(void) fprintf(stdout,"    $A[12],$A[3,4],$A[]  One element, range of elements, all elements\n");
(void) fprintf(stdout,"    A                    All of STRING variable A\n");
(void) fprintf(stdout,"    A[2],A[3,4],A[]      One token, range of tokens, all tokens\n");
(void) fprintf(stdout,"  Assignment:\n");
(void) fprintf(stdout,"    $A[6]  = 1+$B[$C[3]] to an element\n");
(void) fprintf(stdout,"    $A[1,2]= $B[3,4]     to a range of elements (number must match)\n");
(void) fprintf(stdout,"    $A[]   = 3           to an entire array\n");
(void) fprintf(stdout,"    Only NUMERIC variables may appear to the left of an '=' operator.\n");
(void) fprintf(stdout,"    Expressions may contain 0 or 1 '=' assignments.\n");
(void) fprintf(stdout,"  Operators:  val1 OP val2\n");
(void) fprintf(stdout,"    +        addition\n");          
(void) fprintf(stdout,"    -        subtraction\n");          
(void) fprintf(stdout,"    *        multiplication\n");          
(void) fprintf(stdout,"    %%        remainder\n");          
(void) fprintf(stdout,"    ^        power (val1 ^ val2)\n");          
(void) fprintf(stdout,"    ?        compare (returns 1,0,-1 if val1 >,==,< val2) \n");    
(void) fprintf(stdout,"  Functions(val)\n");
(void) fprintf(stdout,"    log      base 10 log\n");         
(void) fprintf(stdout,"    ln       natural log\n");         
(void) fprintf(stdout,"    e10      10^val\n");         
(void) fprintf(stdout,"    ee       e^val \n");         
(void) fprintf(stdout,"    chs      change sign\n"); 
(void) fprintf(stdout,"    abs      absolute value\n"); 
(void) fprintf(stdout,"    rnd      round to nearest int\n"); 
(void) fprintf(stdout,"    lid      round away from zero to next integer\n"); 
(void) fprintf(stdout,"    trc      round towards zero to next integer\n"); 
(void) fprintf(stdout,"    sin,asin sine, arc sine (angle in radians)\n");              
(void) fprintf(stdout,"    cos,acos cosine, arc cosine\n");              
(void) fprintf(stdout,"    tan,atan tangent, arc tangent\n");              
(void) fprintf(stdout,"    d2r      degrees to radians\n");         
(void) fprintf(stdout,"    r2d      radians to degress\n");         
(void) fprintf(stdout,"    sinh,cosh,tanh    hyperbolic sine, cosine,tangent\n");              
(void) fprintf(stdout,"    not      bitwise not (unsigned integer)\n");              
(void) fprintf(stdout,"  Functions(val1,val2)\n");
(void) fprintf(stdout,"    max      maximum\n");              
(void) fprintf(stdout,"    min      minimum\n");              
(void) fprintf(stdout,"    and,or,xor   bitwise and, or, xor (unsigned integer).\n");              
(void) fprintf(stdout,"    shl,shr   bitwise shift left/right (unsigned integer).\n");              
(void) fprintf(stdout,"  Functions($A[range])  [scalar results only]\n");
(void) fprintf(stdout,"    len      number of cells\n");              
(void) fprintf(stdout,"    sum      sum of cells\n");              
(void) fprintf(stdout,"    sm2      sum of squares of cells\n");              
(void) fprintf(stdout,"    inv      invert order of cells in range,  Returns 0.\n");              
(void) fprintf(stdout,"    del      delete cells in range.  Returns elements remaining.\n");              
(void) fprintf(stdout,"             (If all deleted, variable is reset to one element with value zero.)\n");              
(void) fprintf(stdout,"    idx      replace elements with their array positions (1-N).  Returns 0.\n");              
(void) fprintf(stdout,"    srt      sort elements into ascending order.  Returns 0.\n");              
(void) fprintf(stdout,"    six      replace elements with the positions they would occupy\n");              
(void) fprintf(stdout,"             if sorted into ascending order.  Ie {5,10,-21} -> {2,3,1}. Returns 0.\n");              
(void) fprintf(stdout,"    nml      test for normal numbers. 0=all elements normal, 1=at least one\n");              
(void) fprintf(stdout,"             infinite, 2=at least one NaN, 3=some infinite and some NaN\n");              
(void) fprintf(stdout,"    tls      (re)dim the variable and store the token number list from the last t:\n");              
(void) fprintf(stdout,"             pattern match. Returns the size of the token number list.\n");              
(void) fprintf(stdout,"             The token number list is consumed.\n");              
(void) fprintf(stdout,"    sls      (re)dim the variable and store the substrings list (start/end pairs)\n");              
(void) fprintf(stdout,"             from the last pattern match.\n");
(void) fprintf(stdout,"             Returns the number of matches (1/2 the list size).\n");              
(void) fprintf(stdout,"             The substrings list is not altered.\n");              
(void) fprintf(stdout,"  Functions($A[],value)  [scalar results only] \n");
(void) fprintf(stdout,"    dim       (Re)size $A to value entries.  New elements = 0.0. Returns 0.\n");              
(void) fprintf(stdout,"  Functions($A[],val1,val2,...)  [scalar results only]\n");
(void) fprintf(stdout,"    cat       Add values as new elements to $A, returns new length.\n");              
(void) fprintf(stdout,"    ini       (Re)initialize $A with values as elements, returns (new) length.\n");              
(void) fprintf(stdout,"  Functions($A[],$B[])  [array results only]\n");
(void) fprintf(stdout,"    Rearrange array contents.  Value returned  is not meaningful.\n");
(void) fprintf(stdout,"    map      $A[i]    = $A[$B[i]] for all i in the range\n");              
(void) fprintf(stdout,"    ump      $A[$B[i]]= $A[i]     for all i in the range (unmap).\n");              
(void) fprintf(stdout,"  Functions(A[range])  [scalar results only]\n");
(void) fprintf(stdout,"    tok      the number of tokens.\n");              
(void) fprintf(stdout,"    tln      the sum of the token lengths in the range.\n");              
(void) fprintf(stdout,"    sln      the length of the entire string (range values are ignored).\n");              
(void) fprintf(stdout,"  Functions($A[range],B[range])  [scalar results only]\n");
(void) fprintf(stdout,"    tix      make a map in the indicated range in $A that corresponds\n");              
(void) fprintf(stdout,"             to the TOKENS in the indicated range in STRING variable B\n");              
(void) fprintf(stdout,"             sorted into ascending order. Case sensitive.  The resulting\n");              
(void) fprintf(stdout,"             map will have all positive values.  Returns 0.\n");              
(void) fprintf(stdout,"    tcx      case invariant form of tix.\n");              
(void) fprintf(stdout,"    \n");              
(void) fprintf(stdout,"  Operator Precedence:\n");
(void) fprintf(stdout,"    ^  >  */%%  >  +-  >  ? > (), > =\n\n");  
(void) fprintf(stdout,"  Examples:\n");
(void) fprintf(stdout,"    -op \"? (5/ee(5)) + $A[-1]\" \n");
(void) fprintf(stdout,"         RESULT=(5 divided by e^5) + contents of last element in array $A\n");
(void) fprintf(stdout,"    -op \"? $A = log(3+$B[6])\"\n");
(void) fprintf(stdout,"         RESULT=(expression), and is also stored in $A[1]\n");
(void) fprintf(stdout,"    -op \"? $A[-1] = A[-2]\"\n");
(void) fprintf(stdout,"         RESULT=(2nd to last token from A), also stored in the last cell of $A.\n");
(void) fprintf(stdout,"    -op \"? $A[] = -$-\"\n");
(void) fprintf(stdout,"         RESULT=(negative of previous result), also fill $A[] with that value.\n");
(void) fprintf(stdout,"    -op \"? dim($A[],5); ? idx($A[]); ? sum(log($A[]))\"\n");
(void) fprintf(stdout,"         RESULT=sum of the logs of 1->5. log(1)->log(5) are stored in\n");
(void) fprintf(stdout,"         $A elements 1->5.\n");
(void) fprintf(stdout,"    -op         \"? $B=1;     ? $A=10\"\n");
(void) fprintf(stdout,"    -pm  \"?>:A\" \"? $B=$B*$A; ? $A=$A-1; ^0;\"\n");
(void) fprintf(stdout,"         RESULT=10 factorial.  Also stored in $B.  Note the conditional\n");
(void) fprintf(stdout,"         single line loop, which jumps to itself (^0) while $A\n");
(void) fprintf(stdout,"         is greater than zero.\n");
(void) fprintf(stdout,"    -op \"?log(max($A[1,4]*2.1,$B[3,6]))\"\n");
(void) fprintf(stdout,"         RESULT=(not meaningful).  Multiply all elements in array $A[1,4]\n");
(void) fprintf(stdout,"         by 2.1 and store in place.  Take the maximum with the corresponding\n");
(void) fprintf(stdout,"         elements (1->3, 2->4..4->6) of $B and store back into $A,  Then take\n");
(void) fprintf(stdout,"         the log of each element in the range and store that in place too.\n");
(void) fprintf(stdout,"         Only elements 1->4 of $A are modified.\n");
(void) fprintf(stdout,"\n");
exit(EXIT_FAILURE);
}



void emit_help_cmd(void){
(void) fprintf(stdout,"cmd file syntax:\n");
(void) fprintf(stdout,"  Input is read until the end of the input or an -eoc.\n");
(void) fprintf(stdout,"  Use \"-cmd -\" to read commands from stdin,\n");
(void) fprintf(stdout,"    then after -eoc the following lines are treated as input.\n");
(void) fprintf(stdout,"  Options are delimited by spaces or tabs.\n");
(void) fprintf(stdout,"  Strings containing these characters may be double quoted.\n");
(void) fprintf(stdout,"  Single quotes have no special meaning.\n");
(void) fprintf(stdout,"  Special first characters in input line:\n");
(void) fprintf(stdout,"    _ (underscore) Remainder of line is the next option.\n");
(void) fprintf(stdout,"      It is read verbatim and so need not be quoted.\n");
(void) fprintf(stdout,"    # The line is a comment - it is ignored.\n");
(void) fprintf(stdout,"  Special first characters in a token:\n");
(void) fprintf(stdout,"    ## The rest of the line is a comment and is ignored.\n\n");
(void) fprintf(stdout,"Example:\n");
(void) fprintf(stdout,"-mt -dl \" \\t\"\n");
(void) fprintf(stdout,"# this is a comment and is ignored\n");
(void) fprintf(stdout,"## as is this\n");
(void) fprintf(stdout,"-fmt ##the text before this is script, but this comment is ignored\n");
(void) fprintf(stdout,"# The next line is full of double quotes and spaces\n");
(void) fprintf(stdout,"# but is pulled in verbatim because of the leading underscore.\n");
(void) fprintf(stdout,"_This would be a \"Mess\\34 to  quote [1,4]\n");
(void) fprintf(stdout,"-eoc\n");
exit(EXIT_FAILURE);
}

void emit_help_var(void){
(void) fprintf(stdout,"Variable overview:\n\n");
(void) fprintf(stdout,"  There are two types of variables: STRING and NUMERIC.\n");
(void) fprintf(stdout,"    There are 26 variables of each type, designated A<->Z\n");
(void) fprintf(stdout,"    (not case insensitive).\n");
(void) fprintf(stdout,"  NUMERIC variables are represented as $N and hold double \n");
(void) fprintf(stdout,"   precision numbers.  These are initially arrays\n");
(void) fprintf(stdout,"   with one cell, but may be (re)dimensioned to be larger.  Array\n");
(void) fprintf(stdout,"   cells are references as $A[M], M in the range 1<->MAX.\n");
(void) fprintf(stdout,"  STRING variables are represented as N and are of subtypes: DEFINED or SET.\n");
(void) fprintf(stdout,"  DEFINED string variables are created by a -vN command line statement\n");
(void) fprintf(stdout,"    like '-vN DEF'.  This defines one variable N as DEF.\n");
(void) fprintf(stdout,"    The string DEF has the same syntax as -fmt and contains\n");
(void) fprintf(stdout,"    at least one field (like [1,3]).\n");
(void) fprintf(stdout,"  SET string variables are all of those which are not DEFINED.\n"); 
(void) fprintf(stdout,"    These may be initialized with -vN DEF so long as DEF\n");
(void) fprintf(stdout,"    is not empty and contains no fields.  Otherwise,\n");
(void) fprintf(stdout,"    these are initially CLEAR (undefined).  If the contents\n");
(void) fprintf(stdout,"    are a zero length string the variable is EMPTY, otherwise\n");
(void) fprintf(stdout,"    is is SET. The variables move between these three states\n");
(void) fprintf(stdout,"    as a result of -pm[N]/-op operations (see -hpat).\n");
(void) fprintf(stdout,"  Both types of variables may be used in a -fmt or -vN definition \n");
(void) fprintf(stdout,"    or on the right side of a math expression via vN,=N, @N (or \n");
(void) fprintf(stdout,"    v$N,=$N,@$N) references.  Only NUMERIC variables may be used\n");
(void) fprintf(stdout,"    on the left side of a numeric expression.\n");
exit(EXIT_FAILURE);
}

void emit_help_examples(void){
(void) fprintf(stdout,"extract examples:\n\n");
(void) fprintf(stdout,"  %% extract                         (print help message)\n");
(void) fprintf(stdout,"  %% extract -h                      (print help message)\n");
(void) fprintf(stdout,"  %% extract -sc 50 <fin >fout       (extract characters 50 to end of row\n");
(void) fprintf(stdout,"                                      for every line in fin and write to fout)\n");
(void) fprintf(stdout,"  %% extract -sr 4 -sc 5 -ec 10 <fin >fout\n");
(void) fprintf(stdout,"                                     (extract characters 5-10 from rows 4\n");
(void) fprintf(stdout,"                                      to end of fin and write to fout)\n");
(void) fprintf(stdout,"  %% extract -sc 5 -nc 10 <fin       (echo characters 5-14 for all rows to stdout)\n");
(void) fprintf(stdout,"  %% extract -sc 2 -ec 3 -mt -dl ':,;' <fin\n");
(void) fprintf(stdout,"                                     (emit 2nd and 3rd tokens,use delimiters :,; )\n");
(void) fprintf(stdout,"  %% extract -fmt \"foo[tk:cu:lj:fw20:3,5]blah[10,30]\" <fin \n");
(void) fprintf(stdout,"                                     (emit \"foo\" followed by tokens 3,4,5 upper cased\n");
(void) fprintf(stdout,"                                     in a 20 character field, left justified, then \"blah\"\n");
(void) fprintf(stdout,"                                     then characters 10 through 30)\n");
(void) fprintf(stdout,"  %% extract -mt -dv '\\t' -fmt \"[1,5]\\n[6]\" <fin \n");
(void) fprintf(stdout,"                                     (emit the first 5 tokens tab separated and the\n");
(void) fprintf(stdout,"                                     sixth token on the next output line.\n");
(void) fprintf(stdout,"  %% extract  -fmt '[,,-1]' <fin\n");
(void) fprintf(stdout,"                                     Invert the order of the columns in the file.\n");
(void) fprintf(stdout,"  %% extract  -rcds '\\r\\12' <fin\n");
(void) fprintf(stdout,"                                     Remove all carriage returns and form feeds from the file.\n");
(void) fprintf(stdout,"  %% extract  -rtds 'Thomas' -rtss 'Tom' <fin\n");
(void) fprintf(stdout,"                                     Replace Thomas with Tom everywhere it occurs in the file.\n");
(void) fprintf(stdout,"  %% echo \"blah a b c d e\" | extract  -unmerge 3\n");
(void) fprintf(stdout,"                                     Emits \"blah a b c\" \"blah d e\" \n");
(void) fprintf(stdout,"  %% extract  -in template,file -indl ' MISS' -template 3 -out fout\n");
(void) fprintf(stdout,"                                     If template contains \"120\",\"121\",\"122\" and file\n");
(void) fprintf(stdout,"                                     contains \"120 fred\",\"122 mary\" write \n");
(void) fprintf(stdout,"                                     \"120 fred\",\"121 MISS\"\"122 mary\" to fout.\n");
(void) fprintf(stdout,"  %% extract -nr 1 -sc 3 -all -in unicode.txt -hnd\n");
(void) fprintf(stdout,"                                     Convert 16 bit unicode to regular ASCII text.\n");
(void) fprintf(stdout,"                                     Deletes Byte order mark = first two bytes of first line\n");
(void) fprintf(stdout,"                                     and all embedded null characters.\n");
(void) fprintf(stdout,"  %% extract -b2 -ecc ',' -in data.txt >delimited.txt\n");
(void) fprintf(stdout,"                                     Place a comma between every character in data.txt.\n");
(void) fprintf(stdout,"                                     The result may be read into a spreadsheet with one character\n");
(void) fprintf(stdout,"                                     per cell.\n");
(void) fprintf(stdout,"  %% echo \"z Y x 1 3e-1 -123.45\" | extract  -mt -fmt \'[sortac:1,3] [sortdn:4,]\'\n");
(void) fprintf(stdout,"                                     Emits \"x Y z 1 3e-1 -123.45\"\n");
(void) fprintf(stdout,"  %% echo \"z Y x 1 3e-1 -123.45\" | extract  -mt -fmt \'[1] [6]\'\n");
(void) fprintf(stdout,"                                     Emits \"z -123.45\" because neither field contains\n");
(void) fprintf(stdout,"                                     more than one token, so sort will occur.\n");
exit(EXIT_FAILURE);
}

int acc_mode_identify(char letter){
int status=-1;
  if(letter=='v' || letter=='V'){   status = ESRCVARS; }
  else if(letter == '='){           status = ESRCVARI; }
  else if(letter == '@'){           status = ESRCVARF; }
  return(status);
}

char acc_mode_show(int mode){
char letter;
  switch(mode){
    case ESRCVARS: letter='v'; break;
    case ESRCVARI: letter='='; break;
    case ESRCVARF: letter='@'; break;
    default:       letter='?'; break;
  }
  return(letter);
}


/* Math functions start here */

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
                   if(*(to-2)=='$'){ *(to-2)=']';}
                   else {            *(to-2)='}';}
                   /* fill the empty [] with the implicit full range [1,-1] */
                   strcpy(to,"(1,@1))"); to+=7; /* @is MATH_NNONE, acts like a left paren */
                                 var = 0;          ocount=0; from++; break; }
         
          else {
            /* rewrite the v or $ as a [, for the rest this is just like a '('
               so fall through into the next case. */
                   if(*(to-2)=='$'){ *(to-2)='[';}
                   else {            *(to-2)='{';}
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
          else if( ISVAROFF(TOVAROFF(*from)) && 
                 !(ISVAROFF(TOVAROFF(last))    || 
                   ISVAROFF(TOVAROFF(from[1])) ||
                   isdigit((int) last)               ||
                   isdigit((int) from[1])
                  )  /* string variable is an isolated single letter like a+, not d2r( though!*/
                 ){       var=1;
                    strncpy(to,S_SVAR,1);    to++;  *to='\0';
                  }
          else {         var=0; }
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
    if(length){
      if(! (act & MASK_OPERAND_OK)){
        *message=wait_insane2(INSFTLERR," variable, literal, or function out of order",string);
      }
      if(*atoken =='$'){  /* variable */
        act = IS_VVAR;
        itmp=TOVAROFF(atoken[1]);
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
        else if(!lstrcasecmp("tls",  3,atoken,length)){  mop = MATH_TLS; }
        else if(!lstrcasecmp("sls",  3,atoken,length)){  mop = MATH_SLS; }
        else if(!lstrcasecmp("dim",  3,atoken,length)){  mop = MATH_DIM; }
        else if(!lstrcasecmp("cat",  3,atoken,length)){  mop = MATH_CAT; }
        else if(!lstrcasecmp("ini",  3,atoken,length)){  mop = MATH_INI; }
        else if(!lstrcasecmp("tix",  3,atoken,length)){  mop = MATH_TIX; }
        else if(!lstrcasecmp("tcx",  3,atoken,length)){  mop = MATH_TCX; }
        else if(!lstrcasecmp("tok",  3,atoken,length)){  mop = MATH_TOK; }
        else if(!lstrcasecmp("tln",  3,atoken,length)){  mop = MATH_TLN; }
        else if(!lstrcasecmp("sln",  3,atoken,length)){  mop = MATH_SLN; }
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
    case MATH_LD_TOKEN: string="(load va[i])";      break;
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
    case MATH_TLS:      string="tls()";             break;
    case MATH_SLS:      string="sls()";             break;
    case MATH_INV:      string="inv()";             break;
    case MATH_DEL:      string="del()";             break;
    case MATH_IDX:      string="idx()";             break;
    case MATH_SRT:      string="srt()";             break;
    case MATH_SIX:      string="six()";             break;
    case MATH_DIM:      string="dim()";             break;
    case MATH_CAT:      string="cat()";             break;
    case MATH_INI:      string="ini()";             break;
    case MATH_TIX:      string="tix()";             break;
    case MATH_TCX:      string="tcx()";             break;
    case MATH_TOK:      string="tok()";             break;
    case MATH_TLN:      string="tln()";             break;
    case MATH_SLN:      string="sln()";             break;
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
    case MSTK_TOKZEROPUSH:  string="spush";  break;
    case MSTK_SAPUSH: string="sapush"; break;
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
       else if(upper == OPPAT_B && lower == OPPAT_C){
         *shift=4; *scroll=0; *state=RPN_NVEC_SVEC;    status=1;
       }
       break; 
     case  MATH_SV_ZERO:
       if(upper == OPPAT_H && lower == OPPAT_A){
         *shift=2; *scroll=0; *state=RPN_SCALAR;          status=1;
       }
       break;   
     case  MATH_LD_TOKEN:
       if(    upper == OPPAT_I && lower == OPPAT_A ){
         *shift=2; *scroll=0; *state=RPN_SCALAR;    status=1;
       }
       else if(upper == OPPAT_I && lower == OPPAT_E ){ /* leave sadd val val*/
         *shift=1; *scroll=2; *state=RPN_SCALAR;    status=1; *mop=MATH_NOP; *from=0;
       }
       break;       
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
     case  MATH_TLS:
     case  MATH_SLS:
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
    EXT_REALLOC2(omni->pstk->list,omni->pstk->salloc,omni->pstk->slen+1,
      omni->pstk->slen+MATHINC,sizeof(MASNEXUS),MEMOOPS);
    pstk=omni->pstk->list;

    ctmp = dat[offset++];
    sop=ctmp;
    switch(sop){
      case MSTK_DPUSH:
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

      case MSTK_TOKZEROPUSH:
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
      case MSTK_OPUSH:
        mop      = dat[offset++];
        psptr++;
        pstk[psptr].what = IS_MOP;
        pstk[psptr].mop = mop;
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
      message=categorize_operands(pstk,psptr,&mop,&shift,&scroll,&from,&type);
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
      if(mop > MATH_NONE){
         if(type!=RPN_SCALAR){ /* this goes BEFORE the operator, so that it can effect it */
            ctmp=MSTK_OPUSH;   es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
            ctmp=MATH_LD_STATE;es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
            ctmp=type;         es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
            lastsop=sop;
         }
         ctmp=MSTK_OPUSH;  es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
         ctmp=mop;         es_append_dat(rpnprog, &ctmp, 1 ,MATHINC,MEMOOPS);
         lastsop=sop;
      }
      /* this is only vaguely doing the operations, mostly it needs to keep track of
         pointers and what is and isn't (going to be) a variable/op.  All variable values
         are represent by 1 once an operator has been applied.   */
      switch(mop){
        case MATH_NOP: /* NO OP, do nothing */
          try=0; /* but don't keep trying either*/
          break;
        case MATH_NNONE:
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
        case MATH_LD_TOKEN:
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
        case MATH_TLS:
        case MATH_SLS:
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
        case MATH_TIX:
        case MATH_TCX:
        case MATH_TOK:
        case MATH_TLN:
        case MATH_SLN:
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
FMTNEXUS *vv;
STRINGNEXUS *tok;
char    scratch[256]; /* much bigger than the largest valid number to convert */
char   *to;
char   *message=NULL;
enum rpn_states rpnstate=RPN_SCALAR; /* the default */

  dat = program;
  stk = omni->stk->val;
  while(ok){
    ctmp = dat[offset++];
    sop=ctmp;
    switch(rpnstate){ 
      case  RPN_SCALAR: /*rpnstate*/
        switch(sop){
          case MSTK_DPUSH:
            NEXTDBLBOUNDARY(offset);
            dtmp        = *(double *)&(dat[offset]);
            offset     += SOD;
            stk[++sptr] = dtmp;
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
            break;
          case MSTK_VAPUSH:
            NEXTINTBOUNDARY(offset);
            itmp        = *(int *)&(dat[offset]);
            offset     += SOI;
            stk[++sptr] = itmp;
            break;

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
            break;
          case MSTK_OPUSH:
            mop      = dat[offset++];
            switch(mop){
              case MATH_NOP: /* NO OP, do nothing */
                break;
              case MATH_NNONE: 
              case MATH_NONE: 
                 insane(INSFTLPRGERR," MATH_[N]NONE found in run_math_rpn");
                 break;
              case MATH_LD_STATE: /* this comes out of the program NOT off the stack */
                 rpnstate = dat[offset]; offset++;
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
              case MATH_TLS: /* redim and fill variable with token list from a t: match*/
                /* Note, returns number of tokens in the list.  If 0, returns that and does nothing */
                sptr -= 2;
                itmp =  stk[sptr]; /* this could have been mangled */
                i2   =  omni->tlen;
                dv=&(omni->dvar[itmp]);
                if(i2){
                  if(ISNOTVAROFF(itmp)){ 
                    message=wait_insane(INSFTLERR," tls() is not operating on a variable");
                    ok=0;
                  }
                  else {
                    EXT_REALLOC3(dv->val,dv->dalloc,i2,sizeof(double),MEMOOPS);
                    dv->dlen=i2;
                    for(i=0;i<dv->dlen;i++){ dv->val[i] = omni->tlist[i]; }
                  }
                }
                else { /* clear (reduce to one cell holding zero) */
                  dv->dlen=1;
                  dv->val[0]=0.0;
                }
                stk[sptr]=i2; /* return number of tokens, may be 0*/
                omni->tlen=0; /* consume the token list, unsafe to leave it dangling */
                break;
              case MATH_SLS: /* redim and fill variable with substring list from a t: match*/
                /* Note, returns rc in the list.  If 0, returns that and clears array */
                sptr -= 2;
                itmp =  stk[sptr]; /* this could have been mangled */
                i2   =  omni->rc;
                dv=&(omni->dvar[itmp]);
                if(i2){
                  if(ISNOTVAROFF(itmp)){ 
                    message=wait_insane(INSFTLERR," sls() is not operating on a variable");
                    ok=0;
                  }
                  else {
                    dv->dlen=i2+i2; /* two entries for each position */
                    EXT_REALLOC3(dv->val,dv->dalloc,dv->dlen,sizeof(double),MEMOOPS);
                    for(i=0;i<dv->dlen;){
                       dv->val[i] = omni->ovector[i]+1;i++;  /* start position, external coords */
                       dv->val[i] = omni->ovector[i];  i++;  /* end position, external coords*/
                    }
                  }
                }
                else { /* clear (reduce to one cell holding zero) */
                  dv->dlen=1;
                  dv->val[0]=0.0;
                }
                stk[sptr]=i2; /* return rc */
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
          case MATH_LD_TOKEN:
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
          case MATH_TLS:
          case MATH_SLS:
          case MATH_NML:
          case MATH_INV:
          case MATH_DEL:
          case MATH_IDX:
          case MATH_SRT:
          case MATH_SIX:
          case MATH_DIM:
          case MATH_CAT:
          case MATH_INI:
          case MATH_TIX:
          case MATH_TCX:
          case MATH_TOK:
          case MATH_TLN:
          case MATH_SLN:
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
          case MATH_TLS:
          case MATH_SLS:
          case MATH_INV:
          case MATH_DEL:
          case MATH_IDX:
          case MATH_SRT:
          case MATH_SIX:
          case MATH_DIM:
          case MATH_CAT:
          case MATH_INI:
          case MATH_LD_TOKEN:
          case MATH_TIX:
          case MATH_TCX:
          case MATH_TOK:
          case MATH_TLN:
          case MATH_SLN:
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
          case MATH_TLS:
          case MATH_SLS:
          case MATH_INV:
          case MATH_DEL:
          case MATH_IDX:
          case MATH_SRT:
          case MATH_SIX:
          case MATH_DIM:
          case MATH_CAT:
          case MATH_INI:
          case MATH_LD_TOKEN:
          case MATH_TIX:
          case MATH_TCX:
          case MATH_TOK:
          case MATH_TLN:
          case MATH_SLN:
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
          case MATH_TLS:
          case MATH_SLS:
          case MATH_INV:
          case MATH_DEL:
          case MATH_IDX:
          case MATH_SRT:
          case MATH_SIX:
          case MATH_DIM:
          case MATH_CAT:
          case MATH_INI:
          case MATH_LD_TOKEN:
          case MATH_TIX:
          case MATH_TCX:
          case MATH_TOK:
          case MATH_TLN:
          case MATH_SLN:
          case MATH_RND:
          case MATH_LID:
          case MATH_TRC:
             insane(INSFTLPRGERR," invalid op for NVEC_NVEC");
             break;
          default:
            insane(INSFTLPRGERR," unknown math case in run_math_rpn");
        }
        break;
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
      default:
        insane(INSFTLPRGERR," invalid RPN context");
    }
  }
  *result=stk[0];
  return(message);
}

/* Math functions end here */


/* For all of the op_* functions if offset is < 0 then it retrieves its 
arguments and prints them as if read from the command line.  This is used for debugging */

/* Clear the variables in a vlist.
   Parameters at offset:  
     vlist (variable list string)
   Other parameters from omni
     vn   (address of var_array from main())
*/
int op_clrv(OMNINEXUS *omni,  int offset){
char *v2;
FMTNEXUS **vn      = omni->vn;
FMTNEXUS *var;
  if(offset>0){
    v2 = ESP_OFFCPTR(omni->alldata,offset);
    for( ; *v2!= EOVLIST; v2++){
      var=vn[(int) *v2];
      es_clear(var->dat_str);  /* clear these for either SET or DEFINE variable */
      var->tokcount=0;
      if(! (var->def_str->slen && *var->def_str->string)){ 
        /* there is no v* definition, clear the fldlist too, by setting its length to 0 */
        var->fldcount          = 0;
      }
    }
  }
  else {
    offset=-offset;
    v2 = ESP_OFFCPTR(omni->alldata,offset);
    fprintf(stderr,"x");
    vlist_show(stderr,v2);
  }
  offset+=SOI;
  return(offset);
}

/* Append an \n to the target.  EXCEPT: only do so if the current 
   string does not already end in \n, which it determines by checking
   for the delimiter value.
   Also change delimiter to \n.
   Parameters at offset:  
     vlist (variable list string)
   Other parameters from omni
     vn   (address of var_array from main())
*/
int op_eol(OMNINEXUS *omni,  int offset){
char *v2;
FMTNEXUS **vn      = omni->vn;
FMTNEXUS *var;
STRINGNEXUS *tok;

  if(offset>0){
    v2 = ESP_OFFCPTR(omni->alldata,offset);
    for( ; *v2!= EOVLIST; v2++){
      var=vn[(int) *v2];
      if(!var->tokcount){ /* clear variable, appending \n sets it */
        es_strcat(var->dat_str,"\n",1,1,MEMOOPS);
        var->tokcount             = 1;
        tok                       = &var->toklist[0];
        tok->start                = 0;
        tok->slen                 = 0;
        tok->delimit              = '\n'; /* must set it to something */
        if(!var->fldcount){
          var->fldcount           = 1;  /* SET variable it is either 0 (empty) or 1 (somethng in it)*/
          var->fldlist[0].iss     = 1;  /* SET variables only have one fldlist entry */
          var->fldlist[0].issend  = -1; /* just the terminator, but this works too */
          var->fldlist[0].issinc  = 1;  /* set it to something */
          var->fldlist[0].source  = SRCSELF| ISSDAT | MODECHAR;
        }
      }
      else if(var->toklist[var->tokcount-1].delimit!='\n'){
        es_strcat(var->dat_str,"\n",1,1,MEMOOPS);
        var->toklist[var->tokcount-1].delimit='\n';
      }
    }
  }
  else {
    offset=-offset;
    v2 = ESP_OFFCPTR(omni->alldata,offset);
    fprintf(stderr,"|");
    vlist_show(stderr,v2);
  }
  offset+=SOI;
  return(offset);
}

/* Append to the variables in a vlist from the ovector.
   Parameters at offset:  
     char *  vlist (variable list string)
   Other parameters from omni
     char *  ovector
     int  *  rc
     char *  target
     FMTNEXUS **vn
*/
int op_setc(OMNINEXUS *omni, int offset){
char      *v2;
char      *vhold;
FMTNEXUS **vn      = omni->vn;
FMTNEXUS  *var;
int       *ovector = omni->ovector;
int        rc      = omni->rc; 
char      *target  = omni->target;
STRINGNEXUS *tok;
char       this[2];
int        ht;
int        hl;
int        tokneeded;
int        slen;
int        start,end,i;
int        ok=0;  /* every VLIST entry must be set at least once or it is an error */

  if(offset>0){
    vhold = v2 = ESP_OFFCPTR(omni->alldata,offset);      /* vlist string from offset position */
    for(i=0; i<rc; v2++,i++){
      if(*v2 == EOVLIST){
         v2=vhold;  /* start over in the list*/
         ok=1;      /* good to go, every list entry has been set once */
      }
      if(*v2==MYVARSMAX)continue;  /* this is an - */
      var  = vn[(int) *v2];
      if(var->def_str->slen && *var->def_str->string){  /* there is a -v* definition, cannot be set, only set again */
        this[0]=FROMVAROFF(*v2);
        this[1]='\0';
        insane2(INSFTLERR," variable defined by -v statements may not be set from a substring",this);
      }
      else { /* there is no v* definition, append this substring */
        if(!var->fldcount){
          var->fldcount           = 1;  /* SET variable it is either 0 (empty) or 1 (somethng in it)*/
          var->fldlist[0].iss     = 1;  /* SET variables only have one fldlist entry */
          var->fldlist[0].issend  = -1;
          var->fldlist[0].issinc  = 1;  /* set it to something */
          var->fldlist[0].source  = SRCSELF| ISSDAT | MODECHAR;
        }
        ht   = var->tokcount;
        hl   = ESP_CLEN(var->dat_str);  /* empty starts from 0, full starts from overwritten terminator */
        start=ovector[i*2];
        end  =ovector[i*2 + 1]-1;
        slen =end-start+1;
        es_strcat(var->dat_str,&target[start],slen,slen,MEMOOPS);
        tokneeded = ht + 1;
        EXT_REALLOC2(var->toklist,var->tokalloc,tokneeded,tokneeded,sizeof(STRINGNEXUS),MEMOOPS);
        tok                     = &var->toklist[ht];
        tok->start              = hl;
        tok->slen               = slen;
        tok->delimit            = '\0'; /* must set it to something */
        var->tokcount++;
      }
    }
    if(!ok && *v2 != EOVLIST){
      insane(INSFTLERR," insufficient substrings to set all variables");
    }
  }
  else {
    offset = -offset;
    v2 = ESP_OFFCPTR(omni->alldata,offset);      /* vlist string from offset position */
    fprintf(stderr,">");
    vlist_show(stderr,v2);
  }
  offset+=SOI;
  return(offset);
}


/* rearrange the ovector list so that hits are converted to BHIA format (before, hit, interval,
after). */
int op_bhia(OMNINEXUS *omni, int offset){
int bits,rc,needed;
int to,from;
int *ovector;
int i;
  if(offset > 0){
    if(omni->oguard){ insane(INSFTLERR," %BHIA already applied to SUBSTRING LIST"); }
    omni->oguard = 1;
    bits         = *(int *)ESP_OFFCPTR(omni->alldata,offset);
    rc           = 0;
    needed       = 0;
    if(bits & MATCH_B){needed++;               }
    if(bits & MATCH_A){needed++;               }
    if(bits & MATCH_H){needed += omni->rc;     }
    if(bits & MATCH_I){needed += omni->rc - 1; }
    /* make enough space for this rearrangment. */
    EXT_REALLOC2(omni->ovector,omni->osize,(omni->rc + needed),(omni->rc + needed),2*SOI,MEMOOPS);
    from = (omni->rc > needed ? 2*omni->rc : 2*needed);
    memmove(&omni->ovector[from],omni->ovector ,SOI*2*omni->rc);
    ovector = omni->ovector;
    to=0;
    if(bits & MATCH_B){  /* this could be an empty string if the first hit starts on first character */
        ovector[to]   = 0;
        ovector[to+1] = ovector[from];
        to += 2;  rc++;
    }
    for(i=0; i< omni->rc; i++){
      if(bits & MATCH_I && i){  /* hits */
        ovector[to]   = ovector[from-1];
        ovector[to+1] = ovector[from];
        if(ovector[to+1]<ovector[to]){insane(INSFTLERR," PCRE substring + <I error");}
        to += 2;  rc++;
      }
      if(bits & MATCH_H){  /* hits */
        ovector[to]   = ovector[from];
        ovector[to+1] = ovector[from+1];
        if(ovector[to+1]<ovector[to]){insane(INSFTLERR," PCRE substring + <H error");}
        to += 2;  rc++;
      }
      from += 2;  /* only increment after both B and H tests */
    }
    if(bits & MATCH_A){  /* this could be an empty string if the last hit ends on last character */
        ovector[to]   = ovector[from-1];
        ovector[to+1] = strlen(omni->target);
        rc++;
    }
    omni->rc=rc;
    if(omni->dbg & DBGIFP){
      dump_separator();
      fprintf(stderr,"Applied filter <");
      dump_bhia(bits);
      fprintf(stderr,"\n\n");
      dump_ovector_only(omni,0);
    }
  }
  else {
    offset = -offset;
    bits   = *(int *)ESP_OFFCPTR(omni->alldata,offset);
    fprintf(stderr,"%%");
    if(bits & MATCH_BHIA){
      if(bits & MATCH_B){fprintf(stderr,"all");}
    }
    else {
      if(bits & MATCH_B){fprintf(stderr,"B");}
      if(bits & MATCH_A){fprintf(stderr,"A");}
      if(bits & MATCH_H){fprintf(stderr,"H");}
      if(bits & MATCH_I){fprintf(stderr,"I");}
    }
  }
  offset+=SOI;
  return(offset);
}


/* Set the variables in a vlist from their -v* definitions input from the specified source.
   Either a variable or the input line .
  (none of the counts are available, linecount and so forth )
   Parameters at offset:  
     vlist (variable list string)
   Other parameters from omni
     FMTNEXUS **vn
*/
int op_vsetv(OMNINEXUS *omni, int offset){
char         *v2;
FMTNEXUS     **vn = omni->vn;
FMTNEXUS     *fsrc;
FMTNEXUS     *var;
int           src;
char          this[2];

  if(offset>0){
    v2 = ESP_OFFCPTR(omni->alldata,offset);      /* vlist string from offset position */
    src = *v2++;
    
    if(src==MYVARSMAX){  fsrc=omni->fn[0];   }
    else {               fsrc=vn[src];       }
    for( ; *v2!= EOVLIST; v2++){
      var=vn[(int) *v2];
      es_clear(var->dat_str);
      if(!vn[(int) *v2]->def_str->slen || ! *vn[(int) *v2]->def_str->string){ /* there is no -v* definition, cannot be set  */
        this[0]=FROMVAROFF(*v2);
        this[1]='\0';
        insane2(INSFTLERR," variable cannot be reset with v* operation as it was not defined: ",this);
      }
      else { /* there is a v* definition, run it  */
        emit_output(omni, var, var->dat_str, fsrc, 1, 1, NULL, NULL, 0, 0, 0, 0, NULL);
        /* fldlist entries don't change, else it could never be set again, only dat_str
        is modified, as is token description */
        var->tokcount            = 1;
        var->toklist[0].start    = 0;
        var->toklist[0].slen     = ESP_CLEN(var->dat_str);
        var->toklist[0].delimit  = '\0';
      }
    }
  }
  else {
    offset = -offset;
    v2 = ESP_OFFCPTR(omni->alldata,offset);      /* vlist string from offset position */
    src = *v2++;
    fprintf(stderr,"v");
    vlist_show(stderr,v2);
    if(src!=MYVARSMAX){ fprintf(stderr,"<%c",FROMVAROFF(src)); }
  }
  offset+=SOI;
  return(offset);
}

/* Append variable(s) to one variable
   Parameters at offset:  
     dst variable to append TO (as a character in 0-25 range)
     src VLIST variables to append FROM
*/
int op_vv(OMNINEXUS *omni, int offset){
int ht;
int hl;
FMTNEXUS *var;
FMTNEXUS *src;
STRINGNEXUS *dtok;
STRINGNEXUS *stok;
int tokneeded;
int i,idst;
char *dat;

  if(offset>0){
    dat = ESP_OFFCPTR(omni->alldata,offset);
    idst=*dat++;
    var=omni->vn[idst];
    for(;*dat!=EOVLIST;dat++){
      if(*dat!=MYVARSMAX){ src=omni->vn[(int) *dat]; }
      else {               src=omni->fn[0];          } /* any of these will work */
      if(!src->dat_str->slen){
        insane_var(INSFTLERR,"+N<VLIST src variable is CLEARED: ",(int) *dat);
      }
      ht = var->tokcount;
      hl = ESP_CLEN(var->dat_str);
      es_strcat(var->dat_str,src->dat_str->string,ESP_CLEN(src->dat_str),ESP_CLEN(src->dat_str),MEMOOPS);
      tokneeded = ht + src->tokcount;
      EXT_REALLOC2(var->toklist,var->tokalloc,tokneeded,tokneeded,sizeof(STRINGNEXUS),MEMOOPS);
      var->tokcount += src->tokcount;
      for(dtok=&var->toklist[ht], stok=src->toklist, i=0; i<src->tokcount; i++, dtok++,stok++){
        dtok->start   = stok->start + hl;
        dtok->slen    = stok->slen;
        dtok->delimit = stok->delimit;
      }
    }
    if(!var->fldcount){
      var->fldcount           = 1;  /* SET variable it is either 0 (empty) or 1 (somethng in it)*/
      var->fldlist[0].iss     = 1;  /* SET variables only have one fldlist entry */
      var->fldlist[0].issend  = -1;
      var->fldlist[0].issinc  = 1;  /* set it to something */
      var->fldlist[0].source  = SRCSELF| ISSDAT | MODECHAR;
    }
  }
  else {
    offset = -offset;
    dat = ESP_OFFCPTR(omni->alldata,offset);
    idst=*dat++;
    var=omni->vn[idst];
    if(*dat==MYVARSMAX){
      fprintf(stderr,"+%c",FROMVAROFF(idst));
    }
    else {
      fprintf(stderr,"+%c<",FROMVAROFF(idst));
      vlist_show(stderr,dat);
    }
  }
  offset += SOI;
  return(offset);
}


/* Append token # of variable(s) to one variable.  Only the relevant part of the dat_str is appended.
   Parameters at offset:
     #   int   token numberm if 0, use RESULT 
     dst variable to append TO (as a character in 0-25 range)
     src VLIST variables to append FROM
*/
int op_nvv(OMNINEXUS *omni, int offset){
int hl;
FMTNEXUS *var;
FMTNEXUS *src;
STRINGNEXUS *dtok;
STRINGNEXUS *stok;
int tokneeded;
int status;
int itok;
char *dat;
int jstart,jend;

  if(offset>0){
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    itok = *(int *)dat; /* RELATIVE position 1->N if from front, -1->-N if from back */
    if(itok==0){ itok = omni->result; }
    dat += SOI;
    var  = omni->vn[(int) *dat++];
    tokneeded = var->tokcount + vlist_len(dat) - 1; /* vlist_len counts the EOVLIST character */
    EXT_REALLOC2(var->toklist,var->tokalloc,tokneeded,tokneeded,sizeof(STRINGNEXUS),MEMOOPS);
    dtok = &var->toklist[ var->tokcount];
    var->tokcount = tokneeded;
    for(;*dat!=EOVLIST;dat++,dtok++){
      if(*dat == MYVARSMAX){ src=omni->fn[0];          }
      else {                 src=omni->vn[(int) *dat]; }
      if(!src->dat_str->slen){ 
        insane_var(INSFTLERR,"+N<#VLIST source variable is cleared",*dat); 
      }
      status=realends(&jstart,&jend,itok,itok,src->tokcount);
      if(status<=0 || jstart >=src->tokcount){
        insane(INSFTLERR," +N<#VLIST TARGET does not have at least # tokens");
      }
      stok=&src->toklist[jstart];
      hl = ESP_CLEN(var->dat_str);
      es_strcat(var->dat_str, &src->dat_str->string[stok->start],stok->slen,ESP_CLEN(src->dat_str),MEMOOPS);
      dtok->start    = hl;
      dtok->slen     = stok->slen;
      dtok->delimit  = stok->delimit;
    }
    if(!var->fldcount){
      var->fldcount           = 1;  /* SET variable it is either 0 (empty) or 1 (somethng in it)*/
      var->fldlist[0].iss     = 1;  /* SET variables only have one fldlist entry */
      var->fldlist[0].issend  = -1;
      var->fldlist[0].issinc  = 1;  /* set it to something */
      var->fldlist[0].source  = SRCSELF| ISSDAT | MODECHAR;
    }
  }
  else {
    offset = -offset;
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    itok = *(int *)dat;
    dat += SOI;
    fprintf(stderr,"+%c<%d",FROMVAROFF(*dat++),itok);
    vlist_show(stderr,dat);
  }
  offset += SOI;
  return(offset);
}


/* Remove token(s) from a variable[s].  The corresponding parts of dat_str->string
   are also removed.  It is not an error to remove more tokens than are present,
   that just clears the variable. 
   Parameters at offset:  
     num int, token number of first token to remove (to last token).  May be negative.
              If 0 use RESULT (0 same as 1 here).
     dat VLIST to operate on.
*/
int op_npopv(OMNINEXUS *omni, int offset){
FMTNEXUS *var;
STRINGNEXUS *stok;
int slen;
int itok;
char *dat;

  if(offset>0){
    dat = ESP_OFFCPTR(omni->alldata,offset);
    itok=*(int *)dat;
    if(itok==0){ itok = omni->result; }
    dat += SOI;
    for(;*dat != EOVLIST;dat++){
      var=omni->vn[(int) *dat];
      if(itok<0){  itok = var->tokcount + itok + 1; } /* still external format*/
      if(itok<1){  itok = 1;                        } /* still external format*/
      var->tokcount = (itok-1 < var->tokcount ? itok-1 : var->tokcount);
      if(!var->tokcount){        /* probably these are already cleared, but do it again to be safe */
        es_clear(var->dat_str);  /* clear these for either SET or DEFINE variable */
        var->fldcount           = 0;  /* SET variable it is either 0 (empty) or 1 (somethng in it)*/
        if(! (var->def_str->slen && *var->def_str->string)){ 
          /* there is no v* definition, clear the fldlist too, by setting its length to 0 */
          var->fldcount          = 0;
        }
      }
      else {
        var->fldcount           = 1;    /* SET variable it is either 0 (empty) or 1 (somethng in it)*/
        stok                    = &var->toklist[var->tokcount-1];
        slen                    =stok->start + stok->slen;       /* length of entire string */
        var->dat_str->string[slen++] = '\0';  /* new terminator */
        var->dat_str->slen      = slen;       /* new length */
      }
    }
  }
  else {
    offset = -offset;
    dat = ESP_OFFCPTR(omni->alldata,offset);
    itok=*(int *)dat;
    dat += SOI;
    fprintf(stderr,"x%d",itok);
    vlist_show(stderr,dat);
  }
  offset += SOI;
  return(offset);
}

/* Merge some or all token(s) from a variable[s].  The corresponding parts of dat_str->string
   are not affected.  It is not an error to merge more tokens than are present,
   that just merges all of them. This may be applied to either SET or DEFINE variables.
   Parameters at offset:  
     num int, number of tokens to merge from end of list
     dst variable to operate on.
*/
int op_mrgv(OMNINEXUS *omni, int offset){
FMTNEXUS *var;
STRINGNEXUS *stok;
STRINGNEXUS *dtok;
int itok;
char *dat;

  if(offset>0){
    dat = ESP_OFFCPTR(omni->alldata,offset);
    itok=*(int *)dat;
    if(itok==0){ itok = omni->result; }
    dat += SOI;
    for(;*dat != EOVLIST;dat++){
      var=omni->vn[(int) *dat];
      if(var->fldcount && var->tokcount > 1){  /* something to do, cannot merge CLEAR (no tokens)  or a single token */
        stok = &var->toklist[var->tokcount-1];
        if(itok<0)itok=var->tokcount + itok + 1; /* still external format*/
        if(itok<1)itok=1;                        /* still external format */
        if(itok < var->tokcount){
          var->tokcount = itok;
          dtok          = &var->toklist[--itok];  /* use as internal format       */
          dtok->slen    = ESP_CLEN(var->dat_str) - dtok->start;  /* this assumes tokens are in order, they should be */
          dtok->delimit = stok->delimit;
        }
      }
    }
  }
  else {
    offset = -offset;
    dat = ESP_OFFCPTR(omni->alldata,offset);
    itok=*(int *)dat;
    dat += SOI;
    fprintf(stderr,"m%d",itok);
    vlist_show(stderr,dat);
  }
  offset += SOI;
  return(offset);
}

/* emit vlist with no formatting (must have already been formatted.  No \n is added, put one in if needed)
     int outstream  output stream to emit to
     src VLIST variables to emit FROM
*/
int op_vemit(OMNINEXUS *omni, int offset){
FMTNEXUS *src;
char *dat;
int  istrm=0;

  if(offset>0){
    dat    = ESP_OFFCPTR(omni->alldata,offset);
    istrm  = *(int *)dat;  /* checked for valid range when operations precompiled */
    if(istrm==0){ istrm=omni->result; }
    istrm--;  /* 1-N -> 0->N-1 */
    if(istrm<0 || istrm>outfiles){ insane(INSFTLERR," <VLIST to invalid output stream"); }
    dat   += SOI;
    for(;*dat!=EOVLIST;dat++){
      if(*dat == MYVARSMAX){  src=omni->fn[0];          }
      else {                  src=omni->vn[(int) *dat]; }
      /* Empty string is ignored, as it is for op_semit.  This can happen if a token range is out of bounds */
      if(src->dat_str->slen){ 
         fprintf(lcl_stdout[istrm],"%s",src->dat_str->string);
      }
    }
  }
  else {
    offset = -offset;
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    istrm  = *(int *)dat;
    dat   += SOI;
    if(istrm){ fprintf(stderr,"<%d",istrm); }
    else {     fprintf(stderr,"<");         }
    vlist_show(stderr,dat);
  }
  offset += SOI;
  return(offset);
}

/* emit string with no formatting (must have already been formatted.  
   No \n is added, put one in if needed
     src STRING to emit
*/
int op_semit(OMNINEXUS *omni, int offset){
char *dat;
int  istrm=0;

  if(offset>0){
    dat    = ESP_OFFCPTR(omni->alldata,offset);
    istrm  = *(int *)dat;  /* checked for valid range when operations precompiled */
    if(istrm==0){ istrm=omni->result; }
    istrm--;  /* 1-N -> 0->N-1 */
    if(istrm<0 || istrm>outfiles){ insane2(INSFTLERR," <= to invalid output stream, STR: ",dat); }
    dat   += SOI;
    fprintf(lcl_stdout[istrm],"%s",dat);
  }
  else {
    offset = -offset;
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    istrm  = *(int *)dat;  /* checked for valid range when operations precompiled */
    dat   += SOI;
    if(istrm){  fprintf(stderr,"<%d=",istrm); }
    else {      fprintf(stderr,"<=");         }
    fprintf(stderr,"%s",dat);
  }
  offset += SOI;
  return(offset);
}

/* emit field with no formatting (must have already been formatted.  
   No \n is added, put one in if needed
     src STRING to emit
*/
int op_femit(OMNINEXUS *omni, int offset){
char *dat;
FIELD2NEXUS *f2n;
FMTNEXUS    *var;
int  istrm=0;
int  src;

  if(offset>0){
    dat    = ESP_OFFCPTR(omni->alldata,offset);
    istrm  = *(int *)dat;
    if(istrm==0){ istrm=omni->result; }
    istrm--;  /* 1-N -> 0->N-1 */
    if(istrm<0 || istrm>outfiles){ insane(INSFTLERR," <[field] to invalid output stream"); }
    dat   += SOI;
    src    = *dat;  /* default input source for the [field] */
    dat   += SOI;   /* wasted 3 bytes of storage, need alignment here.*/
    f2n    = (FIELD2NEXUS *)dat;
    if(src==MYVARSMAX){      var = omni->fn[0]; }
    else if(src<MYVARSMAX){  var = omni->vn[src]; }
    else {
      insane_var(INSFTLPRGERR," <[field] and VAR is undefined", src);
    }
    es_clear(omni->accum); /* might be something in it, toss that if so */
    emit_output(omni,NULL, omni->accum, var, 1, 1, NULL, NULL, 0, 0, 0, 0, f2n);
    fprintf(lcl_stdout[istrm],"%s",ESP_CPTR(omni->accum));
    es_clear(omni->accum); /* try not to leave anything here */
  }
  else {
    offset = -offset;
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    istrm  = *(int *)dat;  /* checked for valid range when operations precompiled */
    dat   += SOI;
    src    = *dat;  /* default input source for the [field] */
    dat   += SOI - 1;  /* wasted 3 bytes of storage, need alignment here.*/
    if(istrm){  fprintf(stderr,"<%d[FIELD]",istrm); }
    else {      fprintf(stderr,"<[FIELD]");         }
  }
  offset += SOI;
  return(offset);
}

/* Read from the designated input stream into the input buffer.
     stream  STREAM to read from
      STRING to emit
*/
int op_read(OMNINEXUS *omni, int offset){
char *dat;
int   istrm;
size_t cterm;
unsigned int sfg_status;
ESNEXUS *buf=omni->buf_common;

  if(offset>0){
    dat    = ESP_OFFCPTR(omni->alldata,offset);
    istrm  = *(int *)dat;  /* checked for valid range when operations precompiled */
    if(istrm==0){ istrm=omni->result; }
    istrm--;  /* 1-N -> 0->N-1 */
    if(lcl_stdin[istrm]==NULL){ insane(INSFTLERR," > read on closed input file"); }
    else{
      sfg_status = super_fgets(buf->string, buf->salloc, lcl_stdin[istrm],
         &cterm, omni->handlenull);
      if(sfg_status != 0){
        if(sfg_status & SFG_READERROR){
          insane(INSFTLERR," fatal read error during processing");
        }
        if(sfg_status & SFG_BUFFER_FULL){
          insane(INSFTLERR," sinle input line was wider than -wl");
        }
        if(sfg_status & SFG_EMBEDDED_NULL && omni->handlenull < 0){
          insane(INSFTLERR," found embedded null characters.  Use -hnd, -hns, or -hnsubs");
        }
        if(sfg_status & SFG_EOF){
          fclose(lcl_stdin[istrm]);
          lcl_stdin[istrm]=NULL;
        }
        if(omni->crok && (sfg_status & SFG_CRLF)){
          /* silently nip off the \r character if present on a CRLF */
          cterm--;
          buf->string[cterm]='\0';
        }
      }
      buf->slen = cterm + 1;
    }
  }
  else {
    offset = -offset;
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    istrm  = *(int *)dat;  /* checked for valid range when operations precompiled */
    fprintf(stderr,"<%d",istrm);
  }
  offset += SOI;
  return(offset);
}


/* show each of the listed string variables.  
     src VLIST variables to emit FROM
*/
int op_showv(OMNINEXUS *omni, int offset){
FMTNEXUS *src;
char *dat;

  if(offset>0){
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    for(;*dat!=EOVLIST;dat++){
      if(*dat<MYVARSMAX){ src=omni->vn[(int) *dat]; }
      else {              src=omni->fn[0];          }
      dump_var(omni,src,(int) *dat);
    }
  }
  else {
    offset = -offset;
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    fprintf(stderr,"~");
    vlist_show(stderr,dat);
  }
  offset += SOI;
  return(offset);
}

/* show each of the listed numeric variables.  
     src VLIST variables to emit FROM
*/
int op_shownv(OMNINEXUS *omni, int offset){
DVNEXUS *src;
char *dat;

  if(offset>0){
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    for(;*dat!=EOVLIST;dat++){
      if(*dat==MYVARSMAX){ fprintf(stderr,"Result: %le\n",omni->result); }
      else if(*dat<MYVARSMAX){ 
        src=&omni->dvar[(int) *dat];
        dump_nvar(omni,src,(int) *dat);
      }
    }
  }
  else {
    offset = -offset;
    dat  = ESP_OFFCPTR(omni->alldata,offset);
    fprintf(stderr,"~$");
    vlist_show(stderr,dat);
  }
  offset += SOI;
  return(offset);
}
/* Append string to the variable.  The variable may be completely empty (cleared).
   Parameters at offset:  
     var   (as a character in 0-25 range)
     string (null terminated)
*/
int op_strv(OMNINEXUS *omni, int offset){
int          ht;
int          hl;
FMTNEXUS    *var;
char        *src;
STRINGNEXUS *tok;
int          tokneeded;
int          idst;
int          slen;
  if(offset>0){
    src  = ESP_OFFCPTR(omni->alldata,offset);
    idst = *src++;
    var  = omni->vn[idst];
    if(!var->fldcount){
      var->fldcount           = 1;  /* SET variable it is either 0 (empty) or 1 (somethng in it)*/
      var->fldlist[0].iss     = 1;
      var->fldlist[0].issend  = -1;
      var->fldlist[0].issinc  = 1;  /* set it to something */
      var->fldlist[0].source  = SRCSELF | ISSDAT | MODECHAR;
    }
    ht   = var->tokcount;
    hl   = var->dat_str->slen;
    if(hl)hl--; /* empty starts from 0, full starts from overwritten terminator */
    slen = strlen(src);
    es_strcat(var->dat_str,src,slen,slen, MEMOOPS);
    tokneeded = ht + 1;
    EXT_REALLOC2(var->toklist,var->tokalloc,tokneeded,tokneeded,sizeof(STRINGNEXUS),MEMOOPS);
    tok                     = &var->toklist[ht];
    tok->start              = hl;
    tok->slen               = slen;
    tok->delimit            = '\0'; /* must set it to something */
    var->tokcount++;
  }
  else {
    offset = -offset;
    src = ESP_OFFCPTR(omni->alldata,offset);
    idst = *src++;
    fprintf(stderr,"+%c%s",FROMVAROFF(idst),src);
  }
  offset += SOI;
  return(offset);
}

/* Append [fmt] to the variable.  The variable may be completely empty (cleared).
   Parameters at offset:  
     idst   (as a character in 0-25 range)
     isrc   (as a character in 0-26 range)
     (two empty characters)
     f2n    (field2nexus)
*/
int op_fmtv(OMNINEXUS *omni, int offset){
FMTNEXUS    *dst;
FMTNEXUS    *src;
int          isrc;
int          idst;
char        *dat;
FIELD2NEXUS *f2n;

  if(offset>0){
    dat    = ESP_OFFCPTR(omni->alldata,offset);
    idst   = *dat;
    isrc   = *(dat + 1);
    f2n    = (FIELD2NEXUS *)(dat + SOI);  /* but must stay aligned here.*/
    if(isrc == MYVARSMAX){      src = omni->fn[0];    }
    else if(isrc < MYVARSMAX){  src = omni->vn[isrc]; }
    else {
      insane(INSFTLPRGERR," +N<[field] and source for [field] is undefined");
    }
    if(idst< MYVARSMAX){  dst = omni->vn[idst]; }
    else {
      insane(INSFTLPRGERR," +N<[field] and N not a variable undefined");
    }
    /* append string, also makes more tokens */
    emit_output(omni, dst, dst->dat_str, src, 1, 1, NULL, NULL, 0, 0, 0, 0, f2n);
    if(!dst->fldcount){
      dst->fldcount           = 1;  /* SET dstiable it is either 0 (empty) or 1 (somethng in it)*/
      dst->fldlist[0].iss     = 1;
      dst->fldlist[0].issend  = -1;
      dst->fldlist[0].issinc  = 1;  /* set it to something */
      dst->fldlist[0].source  = SRCSELF | ISSDAT | MODECHAR;
    }
  }
  else {
    offset = -offset;
    dat    = ESP_OFFCPTR(omni->alldata,offset);
    idst   = *dat;
    isrc   = *(dat + 1);
    f2n    = (FIELD2NEXUS *)(dat + SOI);  /* but must stay aligned here.*/
    fprintf(stderr,"+%c<[FIELD]",FROMVAROFF(idst));
  }
  offset += SOI;
  return(offset);
}

/* Tokenize target variables.  Whatever previous token representation existed is lost.
   Fatal error if the variable is completely empty (cleared).
   Parameters at offset:  
     N       char number of the po to use 0->9
     VLIST   char targets to tokenize
*/
int op_po(OMNINEXUS *omni, int offset){
FMTNEXUS    *var;
char        *src;
char         po;
char        *v2;
  if(offset>0){
    src  = ESP_OFFCPTR(omni->alldata,offset);
    po   = *src++;
    for(v2=src;*v2!=EOVLIST;v2++){
      var=omni->vn[(int) *v2];
      if(var->dat_str->slen==0){
        insane_var(INSFTLERR, " attempt to make tokens within a cleared variable: ",(int) *v2);
      }
      make_inp_tokens(omni->vn[(int) *v2], &omni->po[(int) po], "");
    }
  }
  else {
    offset = -offset;
    src    = ESP_OFFCPTR(omni->alldata,offset); 
    po     = *src++;                            
    fprintf(stderr,"po%d",po);
    vlist_show(stderr,src);
  }
  offset += SOI;
  return(offset);
}

/* show bits in ifstate.  It is possible to screw up the logic in a script
   to set incompatible IF bits, that should be captured in the primary read loop
   in main.
   Parameters at offset:
     int  the IF bits to set
*/
int dump_if(OMNINEXUS *omni, int offset){
int tmp;
  tmp  = ESP_OFFINT(omni->alldata,offset);
  fprintf(stderr,"if");
  if(tmp & IF_START1){    fprintf(stderr,"1"); } 
  if(tmp & IF_STARTC){    fprintf(stderr,"c"); } 
  if(tmp & IF_STARTT){    fprintf(stderr,"+"); } 
  if(tmp & IF_TERM){      fprintf(stderr,"-"); } 
  if(tmp & IF_NORESTART){ fprintf(stderr,"r"); } 
  offset += SOI;
  return(offset);
}

int lcl_strcasecmp(char *s1, char *s2){
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

int lcl_strncasecmp(char *s1, char *s2,int len){
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

/* compare between start and end only. Have to be careful about
   sizes here because one or other or both could terminate before
   the comparison region 
   
   returns:
   1 if s1> s2
   0 if s1==s2
  -1 if s1< s2
  -2 if both terminated before comparison range
  
*/
int lcl_strcmprange(char *s1, char *s2, int start, int end, int usecase){
int c1,ok1;
int c2,ok2;
int i;
  if(end<0)return -2;
  if(start<0)return -2;
  if(end<start)return -2;
  ok1=ok2=1;
  for(i=0;i<=end ;s1++,s2++,i++){
    if(usecase == NO){
      c1=toupper(*s1);
      c2=toupper(*s2);
    }
    else {
      c1=*s1;
      c2=*s2;
    }
    if(ok1 && (c1 == 0))ok1=0;
    if(ok2 && (c2 == 0))ok2=0;
    if(ok1 && ok2){
      if((i>=start) && (i<=end)){
        if(c1 < c2)return -1;
        if(c1 > c2)return  1;
      }
    }
    else if(ok1){
      if(i>=start)return 1;   /*s2 terminated, s1 did not, s1 is bigger*/
    }
    else if(ok2){
      if(i>=start)return -1;  /*s1 terminated, s2 did not, s2 is bigger*/
    }
    else {
      if(i>=start)return 0;   /* both terminated within comparison region, equivalent */
      return -2;              /* both terminated before comparison, no comparison possible */
    }
  }
  return 0;  /* over range they are identical*/
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

/* tokenize dat_str in the specified fmt.  Store these into the 
toklist.  Note that ALL pointers are to buffer, with varying start/length.
*/

void make_inp_tokens(FMTNEXUS *fmt, PONEXUS *po, char *emptystring){
int tcount,length,start;
char *atoken;
char thedelim;
char lastdelim='\0';
char *delimit      = po->delimit; 
int  parse_options = po->parse_options;
STVNEXUS hold;
  if(!po->delimit){ insane(INSFTLERR," attempt to use -poX without first defining it");}
  tcount=0;
  atoken=strtok_variant(fmt->dat_str->string,&hold,delimit,parse_options,emptystring,&thedelim,&start,&length);
  while(atoken != NULL){
    EXT_REALLOC2(fmt->toklist,fmt->tokalloc,tcount+1,sizeof(STRINGNEXUS),
       (fmt->tokalloc + XCINC),MEMOOPS);
    if(length > 0){  
       fmt->toklist[tcount].start   = start;
       fmt->toklist[tcount].slen    = length;
    }
    else{ 
       /* nothing there, so make length 0 and start is still sequential.*/
       fmt->toklist[tcount].start   = start;
       fmt->toklist[tcount].slen    = 0;      
    }
    if(thedelim){
      fmt->toklist[tcount].delimit = thedelim;
      lastdelim = thedelim;
    }
    else {
      fmt->toklist[tcount].delimit = lastdelim;
    }
    tcount++;
    atoken=strtok_variant(NULL,&hold,delimit,parse_options,emptystring,&thedelim,&start,&length);
  }
  fmt->tokcount=tcount;
  
}/* make_inp_tokens */


/* This strtok implementation can act like the regular strtok() or it can perform certain other
processing modes.  These are defined by bits in the parse_options parameter.  If none are
set, it acts like strtok, otherwise:

PARSE_DBLQUOTES
   Treat "stringDELIMITstringDELIMIT"DELIMIT as one token including the end double quotes.
   (Internal delimiters are ignored.)
PARSE_SINGLEDEL
   Treat a series DELIMIT DELIMIT as DELIMIT EMPTYSTRING DELIMIT,
   the latter form is required for properly handling tab delimited
   data when data fields may be empty.
PARSE_ESCAPES
   \ escapes characters but is NOT  consumed, ie \: -> \:
   \ may escape a delimiter
   \ may not escape the final '\0', ie, \EOL is the same as EOL.
PARSE_STRIPDQUOTES
   When used with PARSE_DBLQUOTES causes the token to be returned without
   the surrounding double quotes.


It returns a pointer to the empty string.  This is modified from mpcf_strtok
in the miniproc program.  It lacks the single quote processing and the & processing.
Double quotes are returned here WITH the quotes attached in dquotes mode.

Also returns thedelim = the delimiter, or first delimiter in a run, that terminated a token.
Also returns start    = offset in buffer to first byte of token (ie, &buffer[start]==atoken)
Also returns length   = number of bytes in atoken.  Atoken is NOT a null terminated string!!!*/

char *strtok_variant(char *instring, STVNEXUS *hold, const char *delim, 
  int parse_options, char *empty,
  char *thedelim, int *start, int *length){
int cpnt;
enum sstates {NEXTDELIM,NEXTDQUOTE,NEXTDELIMDQ,NEXTREGULAR,ENDSEARCH};
enum sstates searchstate;
enum vdquote {ISVALID,ISINVALID};
enum vdquote validdquote;

  if(instring != NULL){  /* new string */
     hold->endstring  = strlen(instring) - 1;
     hold->string     = instring; /* write on the actual input string, not a copy */
     hold->ftoken     = 0;
     hold->etoken     = 0;
     hold->firstcase  = 1;
  }
  else{  /* look for next token in existing string */
     hold->etoken++;     /* last call would have left this on a delimiter */
     hold->ftoken     = hold->etoken; 
     hold->firstcase  = 0;
     if(hold->etoken > hold->endstring)return NULL;
  }
  /* this is the part that does the search
     an exit path is left from this loop to a return=NULL outside so that
     some compilers (DECC) won't complain about there not being a final
     return statement */

  for( searchstate = NEXTREGULAR; searchstate != ENDSEARCH ; hold->etoken++){

    if(searchstate != NEXTREGULAR){hold->firstcase=0;}
    
    
    /* escaping has highest priority.  Normally if a character is escaped everything
       starting with it and going right slides left one and all further processing
       is bypassed (to avoid interpreting the escaped character).  However, if the
       escape as the very last character that would escape the EOL character, so in
       that one instance processing continues as it would for an unescaped EOL */
    
    if(parse_options & PARSE_ESCAPES && hold->ftoken != hold->etoken){
      if(hold->string[hold->etoken]=='\\'){
        if(hold->etoken == hold->endstring)continue;  /* \EOL, so \ cannot escape anything */
        hold->etoken++;
        if(hold->etoken == hold->endstring)continue;  /* \XEOL, so X is last character and EOL terminates */
        hold->etoken++;
        /* \XEOLY...  , so Y or later could terminate token, fall through */
      }
    }
    if(hold->etoken > hold->endstring){  /* always check first to see if search has extended past string end */
       switch (searchstate){
          case ENDSEARCH: /* gcc wants ENDSEARCH case, but from for()logic case is never used */
          case NEXTREGULAR: /* hit end of string, no tokens found */
             searchstate=ENDSEARCH;
             break;
          case NEXTDELIM:   /* end of token is end of string */
             *thedelim='\0';
             *length=hold->etoken - hold->ftoken;
             *start=hold->ftoken;
             return &hold->string[hold->ftoken];
          case NEXTDELIMDQ:   /* handle double quote, the potential double 
                                 quoted string MUST be followed by a delimiter or an EOL */
             hold->etoken=hold->dqetoken;
             hold->etoken++;
             validdquote=ISINVALID;
             if(hold->etoken == hold->endstring + 1){ /* EOL case */
               validdquote=ISVALID;
             }
             else{
               for(cpnt=0; delim[cpnt] != '\0';cpnt++){
                 if(hold->string[hold->etoken] == delim[cpnt]){  /* NON-EOL case */
                   validdquote=ISVALID;
                   break;
                 }
               }
             }
             if(validdquote == ISVALID){
               if(parse_options & PARSE_STRIPDQUOTES){
                 *thedelim=hold->string[hold->etoken];
                 *length=hold->etoken - hold->ftoken-2;
                 *start=hold->ftoken+1;
                 return &hold->string[hold->ftoken+1];
               }
               else {
                 *thedelim=hold->string[hold->etoken];
                 *length=hold->etoken - hold->ftoken;
                 *start=hold->ftoken;
                 return &hold->string[hold->ftoken];
               }
             }
             else{
               insane(INSFTLERR," unmatched double quotes");
             }
          case NEXTDQUOTE:   /* unmatched double quotes - bad */
             insane(INSFTLERR," unmatched double quotes");
       }
    }
    else{
       switch (searchstate){
          case ENDSEARCH: /* gcc wants ENDSEARCH case, but from for()logic case is never used */
            break;
          case NEXTREGULAR:    /* is the current character NOT a delimiter? */
            switch(hold->string[hold->etoken]){
              case '"':            /* start of a double quote delimited token */
                if(parse_options & PARSE_DBLQUOTES){
                  searchstate = NEXTDQUOTE;
                  hold->ftoken = hold->etoken;  /* double quotes are part of the token */
                  break;
                } /* DO NOT SEPARATE the " case from default: or the noquotes logic breaks! */
              default:
                searchstate=NEXTDELIM;
                hold->ftoken = hold->etoken;
                for(cpnt=0; delim[cpnt] != '\0';cpnt++){
                  if(hold->string[hold->etoken] == delim[cpnt]){
                    searchstate=NEXTREGULAR;
                  }
                }
                if(searchstate!=NEXTDELIM){
                  if(parse_options & PARSE_SINGLEDEL){ /* 1 delimiter = full token delimit in this mode EACH is a delimit*/
                    hold->ftoken=hold->etoken;
                    *thedelim=hold->string[hold->etoken];
                    *length=0;
                    *start=hold->ftoken;
                    return empty;
                  }
                }
            }
            break;
          case NEXTDELIM: /* see if the current character is a delimiter */
            for(cpnt=0; delim[cpnt] != '\0';cpnt++){
              if(hold->string[hold->etoken] == delim[cpnt]){  /* a token has been found */
                 *thedelim=hold->string[hold->etoken];
                 *length=hold->etoken - hold->ftoken;
                 *start=hold->ftoken;
                 return &hold->string[hold->ftoken];
              }
            }
            break;
          case NEXTDELIMDQ: /* after a "foo foo", this must be a delimiter */
            for(cpnt=0; delim[cpnt] ;cpnt++){
              if(hold->string[hold->etoken] == delim[cpnt]){  /* a token has been found */
                 if(parse_options & PARSE_STRIPDQUOTES){
                   *thedelim=hold->string[hold->etoken];
                   *length=hold->etoken - hold->ftoken-2;
                   *start=hold->ftoken+1;
                   return &hold->string[hold->ftoken+1];
                 }
                 else {
                   *thedelim=hold->string[hold->etoken];
                   *length=hold->etoken - hold->ftoken;
                   *start=hold->ftoken;
                   return &hold->string[hold->ftoken];
                 }
              }
            }
            insane2(INSFTLERR," double quotes followed by more text - should be EOL or delimiter",hold->string);
            break;
          case NEXTDQUOTE:  /* see if the current character is a quote */
            if(hold->string[hold->etoken] == '"'){    /* a valid token has been found, may not be final one though */
               searchstate = NEXTDELIMDQ;     /* indicates that at least one valid token was found */
               hold->dqetoken = hold->etoken;
            }
            break;
       }
    } 
  } 
  *thedelim='\0';
  *length=0;
  *start=0;
  return NULL;
}


/* in buffer  move everything to the right of "cptr" by shiftval positions.
If shiftval is negative slide left. blen is the length of the buffer and
clen the length of whatever was right of cptr.  buffer and blen are passed in 
a structure and the storage space may be increased to fit a large shift right.
Still a fatal error if data is shifted below position 0. */
void  es_adjust(ESNEXUS *dst, int start, int shiftval, int allocok){
char *cend;
char *from,*to;
char *cptr;
  if(shiftval==0)return;
  if(dst==NULL)insane(INSFTLPRGERR,"  es_adjust called with NULL dst");
  
  if(shiftval>0){
    if(dst->slen + shiftval > dst->salloc){ /* resize it to fit */
       EXT_REALLOC(dst->string,dst->salloc,dst->salloc+shiftval+32,MEMOOPS);
       dst->slen += shiftval;
    }
    cptr=&(dst->string[start]);
    cend=cptr   + shiftval + strlen(cptr);
    to  =cend;              /* first character moved goes here*/
    from=to     - shiftval; /* first character moved from here */
    for(;from>=cptr;to--,from--){ *to=*from; }
  }
  else {  /* shiftval < 0 */
    cptr=&(dst->string[start]);
    cend=cptr + shiftval + strlen(cptr);
    to=cptr   + shiftval;
    from=cptr;
    if(to<dst->string)insane(INSFTLERR," string adjust ran off left side of buffer");
    for(;to<=cend;to++,from++){   *to=*from; }
  }
}


/* interprets \t as tab, etc.  (see below) , \\ as \, and \number as
the decimal representation of the delimiter character.  Unrecognized
escape sequences escape the next character, whatever it is. A \
as the very last character is itself (no escaping \0). */
void fixupescapes(char *string){
char *cptr;
char *optr;
char *holdptr;
int  temp;
  for(optr=cptr=string;*cptr!='\0';optr++,cptr++){
    if(*cptr == '\\'){
      cptr++;
      if(*cptr=='t'){           /* horizontal tab */
        *optr='\t';
      }
      else if(*cptr=='n'){      /* line feed */
        *optr='\n';
      }
      else if(*cptr=='r'){      /* carriage return */
        *optr='\r';
      }
      else if(*cptr=='f'){      /* form feed */
        *optr='\f';
      }
      else if(*cptr=='v'){      /* vertical tab */
        *optr='\v';
      }
      else if(isdigit((unsigned int) *cptr)){ /* Numeric next, could be \12 or similar */
        for(holdptr=cptr,temp=0;isdigit((unsigned int) *cptr);cptr++){
          temp= 10*temp + (*cptr - '0');
        }
        if(temp <= 255 && temp >= 0){ /* valid numeric escape*/
          *optr = temp;
           cptr--;  /*so that loop increment places it correctly */
        }
        else { /* invalid numeric escape, just escape the first number, which is harmless */
           cptr=holdptr;
          *optr = *cptr;
        }
      }
      else if(*cptr=='\0'){     /* trailing slash does NOT escape the terminating zero character! */
        *optr='\\';
        cptr--;  /* do not go past the end of the string!!! */
      }
      else {  /* generic escape, next character goes through no matter what it is */
        *optr=*cptr;
      }
    }
    else {
      *optr=*cptr;
    }
  }
  *optr='\0';
}

/* interprets leading ^ as front, trailing $ as end,
leading \^ as just ^ and trailing \$ as just $.  Interpret leading
! as "NOT".  */
void fixuptag(char *tag, int *tagstate){
char *cptr;
char *optr;
int  temp;
  for(optr=cptr=tag;*cptr!='\0';cptr++){
    if(*cptr == '\\'){
      cptr++;
      if(*cptr=='t'){
        *optr='\t';
      }
      else if(*cptr == '\\'  || *cptr == '^' || *cptr == '$' || *cptr == '!') {
        *optr=*cptr;
      }
      else { /* numeric */
        for(temp=0;isdigit((unsigned int) *cptr);cptr++){
          temp= 10*temp + (*cptr - '0');
        }
        if(temp > 255 || temp == 0){
          insane2(INSFTLERR," -if contains invalid escaped char value",tag);
        }
        *optr = temp;
        cptr--;  /*so that loop increment places it correctly */
      }
      optr++;
    }
    else {
      if(*cptr == '!'){
        if(optr != tag)insane(INSFTLERR," -if contains unescaped,out of order \"!\"");
        *tagstate |= TAG_NOT;
      }
      else if(*cptr == '^'){
        if(optr != tag)insane(INSFTLERR," -if contains unescaped,out of order \"^\"");
        *tagstate |= TAG_FRONT;
      }
      else if(*cptr == '$'){
        cptr++;
        if(*cptr != '\0')insane(INSFTLERR," -if contains unescaped,out of order \"$\"");
        *tagstate |= TAG_END;
        break;  /* force exit */
      }
      else {
        *optr = *cptr;
        optr++;
      }
    }
  }
  *optr='\0';
  if(optr==tag){ /* tag is an empty string, use for matching empty lines */
    *tag='\0';
  }
  if(! (*tagstate & TAG_MASK)){
    *tagstate |=TAG_ANYWHERE;
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

void setinumeric(int *val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(sscanf(argv[*numarg],"%d",val) != 1){
        (void) fprintf(stderr,"Bad integer argument/parameter [%s %s] \n",label,argv[*numarg]);
        exit(EXIT_FAILURE);
      }
}

/* Attempt to precompile PCRE regular expressions.  These may NOT reference vN variables!  */
void re_precompile(char *string, int options, pcre **re){
const char *error;
int erroffset;
#
  *re = pcre_compile(
    string,               /* the pattern */
    options,              /* default options */
    &error,               /* for error message */
    &erroffset,           /* for error offset */
    NULL);                /* use default character tables */
  if(!*re)insane2(INSFTLERR," failed to compile RE: ",string);
  if(error){
    fprintf(stderr,"%s PCRE compile error offset: %d, message: %s\n",
      INSFTLERR,erroffset,error);
    exit(EXIT_FAILURE);
  }
}


/*delete or substitute all instances of rstring in string.  If replace, replace with sstring*/
void rtit(OMNINEXUS *omni, int offset){
char *rstring=NULL;
char *sstring=NULL;
int rtdmode;
char *from,*to,*mptr,*cptr,*fptr,*tptr;
char oops[]=" ";
int match;
int shiftval;
ESNEXUS *dst     = omni->piece;
ESNEXUS *alldata = omni->alldata;

  /*retrieve parameters */
  rtdmode =  ESP_INT(alldata,offset);   offset += SOI;
  rstring =  ESP_CADDR(alldata,offset); offset += 1 + strlen(rstring);
  sstring =  ESP_CADDR(alldata,offset);
  if(*sstring == MYVARSMAX){ /* immediate string data follows */
    sstring++;
  }
  else { /* the string is in a variable, go get it */
    oops[0] =FROMVAROFF(*sstring);  /* just in case */
    sstring = omni->vn[(int) *sstring]->dat_str->string;
    if(!sstring){  insane2(INSFTLERR," rtsv references uninitialized variable: ",oops); }
  }
  /* now use them */
  if(dst){
    if(!*rstring)insane(INSFTLPRGERR," rtit called with empty rstring");
    if(*sstring){ /* substitute on match.  */
      shiftval=strlen(sstring) - strlen(rstring);
      for(to=from=dst->string;*from!='\0';from++,to++){
         for(match=1,mptr=from,cptr=rstring;;mptr++,cptr++){
           if(*cptr=='\0')break;
           if(  (rtdmode==RTDVAL  && *mptr!=*cptr) ||
                (rtdmode==RTDVALC && toupper(*mptr)!= toupper(*cptr)) ||
                *mptr=='\0'){
             match=0;
             break;
           }
         }
         if(match){
           es_adjust(dst,(mptr - dst->string),shiftval,0); /* if dst is relloc'd it trashes from,to, so do not allow */
           dst->slen += shiftval;
           for(fptr=sstring,tptr=to; *fptr!='\0';fptr++,tptr++){ *tptr = *fptr; }
           from=to+strlen(sstring)-1;
           to=from;
         }
         *to=*from;
         if(*from=='\0')break;
       }
    }
    else {  /* just delete if it matches */
      for(to=from=dst->string;;from++,to++){
         for(match=1,mptr=from,cptr=rstring;;mptr++,cptr++){
           if(*cptr=='\0')break;
           if(  (rtdmode==RTDVAL  && *mptr!=*cptr) ||
                (rtdmode==RTDVALC && toupper(*mptr)!= toupper(*cptr)) ||
                *mptr=='\0'){
             match=0;
             break;
           }
         }
         if(match){
          mptr--;
          from=mptr; 
          to--;
          dst->slen -= strlen(rstring);
          }
         else { *to=*from; }
         if(*from=='\0')break;
      }
    }
  }
  else {
    fprintf(stderr, "lrtd:%d ",rtdmode);
    fprintf(stderr,  "rtd:[%s] ",rstring);
    fprintf(stderr, " rts:[%s] ",sstring);
  }
}




/*remove or KEEP (!) all characters from string which are in rstring */
void rcit(OMNINEXUS *omni, int offset){
char *rstring;
char *sstring;
int rcdmode;
int  from,to;
int  j,ok;
char *string;
ESNEXUS *dst     = omni->piece;
ESNEXUS *alldata = omni->alldata;

  /*retrieve parameters */
  rcdmode =  ESP_INT(alldata,offset);   offset += SOI;
  rstring =  ESP_CADDR(alldata,offset); offset += 1 + strlen(rstring);
  sstring =  ESP_CADDR(alldata,offset);

  /* now use them */
  if(dst){
    string=dst->string;
    if(!*rstring)insane(INSFTLPRGERR," rcit called with empty rstring");
    if(*sstring){ /* substitute on match.   ! isn't special here  */
      for(from=0,to=0;;from++,to++){
        if(string[from]=='\0')break;
        if(rcdmode == RCDVAL){
          for(j=0; rstring[j]!='\0'; j++){
             if(string[from]==rstring[j]){ string[to]=sstring[j]; break; }
          }
        }
        else if(rcdmode == RCDVALC){
          for(j=0; rstring[j]!='\0'; j++){
             if(toupper(string[from])==toupper(rstring[j])){ string[to]=sstring[j]; break; }
          }
        }
      }
    }
    else if(*rstring=='!'){  /* keep ONLY those after !*/
      for(from=0,to=0;;from++){
        if(string[from]=='\0')break;
        if(rcdmode == RCDVAL){
          for(ok=0,j=1; rstring[j] != '\0'; j++){ if(string[from]==rstring[j]){ok = 1; break; } }
        }
        else {
          for(ok=0,j=1; rstring[j] != '\0'; j++){ if(toupper(string[from])==toupper(rstring[j])){ok = 1; break; } }
        }
        if(ok){
          string[to]=string[from];
          to++;
        }
      }
    }
    else { /* remove those in string */
      for(from=0,to=0;;from++){
        if(string[from]=='\0')break;
        if(rcdmode == RCDVAL){
          for(ok=1,j=0; rstring[j] != '\0';j++){ if(string[from]==rstring[j]){ok = 0; break; } }
        }
        else {
          for(ok=1,j=0; rstring[j] != '\0';j++){ if(toupper(string[from])==toupper(rstring[j])){ok = 0; break; } }
        }
        if(ok){
          string[to]=string[from];
          to++;
        }
      }
    }
    string[to]='\0';
    dst->slen = to+1;
  }
  else {
    fprintf(stderr, "lrvd:%d ",rcdmode);
    fprintf(stderr,  "rtd:[%s] ",rstring);
    fprintf(stderr, " rts:[%s] ",sstring);
  }
}

void fillhole(OMNINEXUS *omni, int offset){
ESNEXUS *target  = omni->piece;
ESNEXUS *alldata = omni->alldata;
char *str;

   str =  ESP_CADDR(alldata,offset);
   if(target){
     strcpy(target->string,str);
     target->slen=strlen(str)+1;
   }
   else {
     fprintf(stderr," ersstring:[%s] ",str);
   }
}

/* apply the substitutions to the string stored in piece */
void psit(OMNINEXUS *omni, int offset){
ESNEXUS    *piece   = omni->piece;
ESNEXUS    *alldata = omni->alldata;
MOPNEXUS   *mop=NULL;
char       *data;
char       oops[]=" ";

int theps;

  /* sstring is 1: from REPLACE in ps #, 2: from dat_str in var #, 3: a literal string */
  data=ESP_CADDR(alldata,offset);
  theps  = *data;
  if(theps < 10){
    if(theps>=omni->subs->pcount){
      oops[0]=theps + '0';
      insane2(INSFTLERR," undefined ps referenced: ",oops);
    }
    mop   = &omni->subs->list[theps];
  }
  else {
    insane(INSFTLPRGERR," pattern number in psit not 0-9");
  }
  if(piece){
    findmatches(omni, piece, mop,1,-1);
    if( omni->rc){  
      /* these are -ps, result is left in piece to avoid corrupting input buffer */
      /* the following need the data moved to piece2, because they also use piece */
      es_clear(omni->piece2);
      es_strcat(omni->piece2,omni->piece->string,ESP_CLEN(omni->piece),ESP_CLEN(omni->piece),MEMOOPS);
      if(     mop->bits & MATCH_SSUBS){  subs_s(omni,mop); }
      else if(mop->bits & MATCH_VSUBS){  subs_v(omni,mop); }
      else if(mop->bits & MATCH_NVSUBS){ subs_nv(omni,mop); }
      else if(mop->bits & MATCH_TSUBS){  subs_t(omni,mop); }
      else if(mop->bits & MATCH_QSUBS){  subs_q(omni,mop); }
      else {
        insane(INSFTLPRGERR," not valid MATCH_*SUBS in pattern_logic");
      }
    }
  }
  else {
    fprintf(stderr,      "ps:%d ",theps);
    fprintf(stderr,   "match:%s ",mop->pattern);
    fprintf(stderr, "replace:%s ",mop->replace);
  }
}


/* this finds all matches using whatever method was specified and returns them in
ovector/rc. Additionally, if the match is TRUE the return status is 1, else 0.
(rc>0 cannot be used because of MATCH_TRUE).  It is also used for various tests on
math values, existene, and so forth */
int findmatches(OMNINEXUS *omni, ESNEXUS *target, MOPNEXUS *mspec, int start, int end){
int      jstart,jend;
int      bits;
int      status=0;
int      rstatus;
int      istrm;
  bits=mspec->bits;
  if((bits & MATCH_SEARCH) && ESP_CLEN(target)){
    rstatus=realends(&jstart,&jend,start,end,ESP_CLEN(target));
    if(rstatus==0){return(0);}
    else if(rstatus<0){ realends_oops(start,end,ESP_CLEN(target)); }
    if(bits & MATCH_PCRE){
      match_p(omni,target,mspec,jstart,jend);
      if(omni->rc)status=1;
    }
    else {  /* these can only match if there is something in the string */
      if(     bits & MATCH_STRING){ match_s(omni,target,mspec,jstart,jend);  }
      else if(bits & MATCH_VLIST){  match_v(omni,target,mspec,jstart,jend);  }
      else if(bits & MATCH_TOKENS){ match_t(omni,target,mspec,jstart,jend);  }
      else if(bits & MATCH_NVLIST){ match_nv(omni,target,mspec,jstart,jend); }
      if(omni->rc)status=1;
    }
  }
  else {  /* these do not affect the SUBSTRING LIST (ovector/omni->rc) one way or the other*/
    if(bits & MATCH_TRUE){        status = 1;                    }
    else if(bits & MATCH_EXISTS){ status = exists(omni, mspec);  }
    else if(bits & MATCH_MATH){   status = math_tests(omni, mspec);  }
    else if(bits & MATCH_FILE){
      if(mspec->tn == 0){ istrm = omni->result; }
      else {              istrm = mspec->tn;    }
      istrm--;
      if(istrm < 0 || istrm >= MAXINFILE){
         insane(INSFTLERR," invalid input stream number in file_test() ");
      }
      if(lcl_stdin[istrm]){ status = 1; }
      else {                status = 0; }
    }
  }
  return(status);
}

/* floating point formatting */
void ffit(OMNINEXUS *omni, int offset, double *dval){
ESNEXUS *target  = omni->piece;
ESNEXUS *alldata = omni->alldata;
int      converted;
double   dtemp;
char     fstring[32];  /* big enough for any reasonable format string */
int      ff, width, precision;
uint32_t utmp;
int32_t  stmp;
static double dlim=0.0000005;    /* rounding point for default precision */
static int    lastprec=6;        /* default precision                    */

  /*retrieve parameters */
  ff        = ESP_INT(alldata,offset);  offset += SOI;
  width     = ESP_INT(alldata,offset);  offset += SOI;
  precision = ESP_INT(alldata,offset);  offset += SOI;

  /* now use them */
  if(target){
    if(dval){
      dtemp = *dval;
    }
    else {
      converted = sscanf(target->string,"%lf",&dtemp);
      if(converted != 1){  /* ugh, not a valid float, best to blow up here*/
        (void) fprintf(stderr,"%s  string is not a valid numeric value [%s]\n",INSFTLERR,target->string);
        exit(EXIT_FAILURE);
      }
    }
    if(width > 0)width += ESP_CLEN(target);  /*pad, bad idea, but supported */
    if(width < 0)width=-width;
    if(width > target->salloc-1)insane(INSFTLERR,"  numeric value width will not fit into the buffer");
    EXT_REALLOC(target->string, target->salloc, (width+1),MEMOOPS);
    if((ff & FFMASKEF) == FFFLOAT){
      (void)sprintf(fstring,"%%%d.%df",width,precision);
      if(lastprec != precision){ /* try to skip some pow calls, since precision mostly should be constant */
        dlim      = 5*pow(10.0,-(precision+1));
        lastprec  = precision;
      }
      if((dtemp==-0.0) && (ff & NZNZ)){  /* print -0 as -0 */
        target->slen = 1 + sprintf(target->string,fstring,-0.0);
      }
      else {  /* print -0 as 0 (DBLPREC will change -0.0 to 0.0) */
        target->slen = 1 + sprintf(target->string,fstring,DBLPREC(dtemp,dlim));
      }
    }
    else if((ff & FFMASKEF) == FFEXP){
      (void)sprintf(fstring,"%%%d.%de",width,precision);
      if((dtemp==-0.0) && !(ff & NZNZ)){  /* print -0 as 0 */
         target->slen = 1 + sprintf(target->string,fstring,0.0);
      }
      else {  /* print -0 as -0 */
         target->slen = 1 + sprintf(target->string,fstring,dtemp);
      }
    }
    else if(ff & FFUNS){ /* unsigned integer */
       utmp = DBL2UINT32(dtemp);
       if(     ff & FFOCT){ (void)sprintf(fstring,"%%%d.%do",width,precision); }
       else if(ff & FFDEC){ (void)sprintf(fstring,"%%%d.%du",width,precision); }
       else if(ff & FFHEX){ (void)sprintf(fstring,"%%%d.%dx",width,precision); }
       target->slen = 1 + sprintf(target->string,fstring,utmp);
    }
    else { /* signed integer */
       stmp = DBL2INT32(dtemp);
       if(ff & FFDEC){ (void)sprintf(fstring,"%%%d.%dd",width,precision);  }
       target->slen = 1 + sprintf(target->string,fstring,stmp);
    }
    
  }
  else {
     fprintf(stderr,  "ff:%d ",ff);
     fprintf(stderr, "pad:%d ",width);
     fprintf(stderr,"prec:%d ",precision);
  }
}

void padit(OMNINEXUS *omni, int offset){
ESNEXUS *target  = omni->piece;
ESNEXUS *alldata = omni->alldata;
int  tpad,slen;
int  pad;
  /*retrieve parameter */
  pad = ESP_INT(alldata,offset);

  /* now use it */
  if(target){
    slen = ESP_CLEN(target); /* onvert to C strlen, ignore terminator */
    if(pad > 0){
      tpad = pad;
    } 
    else {
      tpad = -pad;
      if(slen > tpad){
        target->string[tpad]='\0'; /* truncate it */
        target->slen = tpad + 1;
        return;
      }
      tpad -= slen; /* difference it must be padded out */
    }
    EXT_REALLOC(target->string, target->salloc, (target->slen + tpad),MEMOOPS);
    memset(ESP_LASTPTR(target),' ', tpad);
    target->slen += tpad;
    ESP_LASTVAL(target)='\0'; /* truncate it SAFE because slen must be > 0*/
  }
  else {
     fprintf(stderr,"pad:%d ",pad);
  }
}

void caseit(OMNINEXUS *omni, int offset){
ESNEXUS *target  = omni->piece;
ESNEXUS *alldata = omni->alldata;
char *cptr;
int casify;
char *string;
  /*retrieve parameter */
  casify = ESP_INT(alldata,offset);

  /* now use it */
  if(target){
    string=target->string;
    switch (casify) {
      case CASENONE:
        break;
      case CASEUPPER:
        for(cptr=string;*cptr!='\0';cptr++){
          *cptr = toupper(*cptr);
        }
        break;
      case CASELOWER:
        for(cptr=string;*cptr!='\0';cptr++){
          *cptr = tolower(*cptr);
        }
        break;
      case CASEFIRST:
        cptr=string;
        *cptr = toupper(*cptr);
        for(cptr++;*cptr!='\0';cptr++){
          *cptr = tolower(*cptr);
        }
        break;
      default:
        insane(INSFTLPRGERR," case not handled in function caseit()");
        break;
    }
  }
  else {
     fprintf(stderr,"casify:%d ",casify);
  }
}

void descit(OMNINEXUS *omni, int offset){
ESNEXUS *target  = omni->piece;
ESNEXUS *alldata = omni->alldata;
int descify;
char *string;
  /*retrieve parameter */
  descify = ESP_INT(alldata,offset);

  /* now use it */
  if(target && target->slen){
    string=target->string;
    fixupescapes(string);
    target->slen = 1 + strlen(string); /* count the terminator */
  }
  else {
     fprintf(stderr,"descify:%d ",descify);
  }
}


void slashit(OMNINEXUS *omni, int offset){
ESNEXUS *target  = omni->piece;
ESNEXUS *alldata = omni->alldata;
char *dst;
char *src;
int stop,padnum;
int padnum2=0;
int stop2=0;
int slashify;
char ecc;

  /*retrieve parameters */
  slashify =  ESP_INT(alldata,offset);   offset += SOI;
  ecc      = *ESP_CADDR(alldata,offset);

  /* now use them */
  if(target->slen < 2)return;  /* not defined or empty string, nothing to slash */
  if(target){
    switch (slashify) {
      case SLASHNONE:
        break;
      case SLASHREST: /* This INTENTIONALLY FALLS THROUGH TO SLASHALL*/
        padnum2=target->slen-2; /* one less than the length, not counting terminator */
        stop2=1;
      case SLASHALL:

        /* count characters to pad, here full length of string */
        padnum = (padnum2 ? padnum2 : target->slen-1);
        stop   = (stop2   ? stop2   : 0);
        if(padnum==0)break;

        /* expand by padnum characters */
        EXT_REALLOC(target->string, target->salloc, (target->slen + padnum),MEMOOPS);

        /* shift right and pad */
        src=ESP_LASTPTR(target); /* points to the terminator on the start string */
        dst=&src[padnum];
        *dst = *src;             /* where it will end up, but it is not escaped */
        target->slen += padnum;

        for(src--,dst--; src >= &(target->string[stop]); src--){
          *dst-- = *src;
          *dst-- =  ecc;
        }
        break;
      case SLASHUNIX:

        /* count characters to pad (everything but alnum and underscore */
        for(padnum=0,src=target->string; *src != '\0'; src++){
          if(! (isalnum((unsigned int) *src) || *src=='_' || *src=='.' || *src=='/')  )padnum++;
        }
        if(padnum==0)break;

        /* expand by padnum characters */
        EXT_REALLOC(target->string, target->salloc, (target->slen + padnum),MEMOOPS);

        /* shift right and pad */
        src=ESP_LASTPTR(target); /* if realloc'd cptr would have been invalid */
        dst=&src[padnum];
        *dst=*src;           /* move the terminator to its new home, it is not escaped */
        target->slen += padnum;
        for(src--,dst--;src >= target->string; src--){
          *dst-- = *src;
          if(! (isalnum((unsigned int) *src) || *src=='_' || *src=='.'|| *src=='/')){  /* escape this one */
            *dst-- = ecc;
            padnum--;
            if(padnum==0)break;  /* fully slashed out at this point */
          }
        }
        break;
      default:
        insane(INSFTLPRGERR," slash not handled in function slashit()");
        break;
    }
  }
  else {
     fprintf(stderr,"slashify:%d ",slashify);
     fprintf(stderr,"ecc:%2.2X ",ecc);
  }
}


/* Modified from miniproc's mpcf_string_justify()
*/

void justit(OMNINEXUS *omni, int offset){
ESNEXUS *target  = omni->piece;
ESNEXUS *alldata = omni->alldata;
int slen,count,lcount;
char *from;
char *to;
int justify;
char *string;

  /*retrieve parameter */
  justify =  ESP_INT(alldata,offset);   offset += SOI;

  /* now use it */
  if(target){
    string=target->string;
    switch (justify) {
      case JUSTNONE:
        break;
      case JUSTLEFT:
        for(from=string; ;from++){
          if(*from == '\0')return;  /* nothing to justify */
          if(*from != ' ')break;
        }
        for(to=string; ;to++,from++){
          if(*from == '\0')break;
          *to = *from;
        }
        for(  ;*to!='\0';to++){*to=' ';}
        break;
      case JUSTRIGHT:
        slen=strlen(string);
        for(from=&string[slen-1]; ;from--){
          if(from < string)return;  /* nothing to justify */
          if(*from != ' ')break;
        }
        for(to=&string[slen-1]; ;to--,from--){
          if(from < string)break;
          *to = *from;
        }
        for(  ;to >= string;to--){*to=' ';}
        break;
      case JUSTCENTER:
        for(count=0, from=string; ;from++){
          if(*from != ' ')break;
          count++;
        }
        lcount=count;
        slen=strlen(string);
        for(from=&string[slen-1]; ;from--){
          if(from < string || *from != ' ')break;
          count++;
        }
 
        count = lcount - count/2; /* amount to shift, left if positive */
 
        if(count==0)return; /* nothing to do */
        if(count > 0){ /* shift left by this much */
          for(to=string,from=&string[count] ; *from!='\0'; from++,to++){
            *to=*from;
          }
          for( ;*to!='\0'; to++){*to=' ';}
        }
        else{ /* shift right by this much */
          for(to=&string[slen-1],from=&string[slen-1+count] ; from >= string ; from--,to--){
            *to=*from;
          }
          for( ; to>=string ; to--){*to=' ';}
        }
        break;
     default:
        insane(INSFTLPRGERR," case not handled in function justit()");
    }
  }
  else {
     fprintf(stderr,"justify:%d ",justify);
  }
  return;
}

void trimit(OMNINEXUS *omni, int offset){
ESNEXUS *target  = omni->piece;
ESNEXUS *alldata = omni->alldata;
int trimify;
int trimmed;   /* keeping track that some trim operation executed */
int ws,slen;
int count=0;   /* number of characters removed */
char *from;
char *to;
char *string;

  /*retrieve parameter */
  trimify =  ESP_INT(alldata,offset);   offset += SOI;

  /* now use it */
  if(target){
    string=target->string;
    if(trimify == TRIMNONE)return;    /* do not trim     */
    if(*string == '\0')return;        /* nothing to trim */
    trimmed=0;
    if(trimify & TRIMRIGHT){
      trimmed++;
      slen=ESP_CLEN(target);
      for(from=&string[slen-1]; from>=string ;from--){
        if(*from == ' ' || *from == '\t'){   *from='\0'; count++; }
        else {                               break;      }
      }
    }
    if(trimify & TRIMLEFT){
      trimmed++;
      for(from=string; ;from++){
        if(*from == ' ' || *from == '\t'){  count++;  continue; }
        break;
      }
      /* from is on the first nonwhitespace character, it might be on a \0 though */
      for(to=string; ;to++,from++){
        *to = *from;
        if(*from == '\0')break;
      }
    }
    if(trimify & TRIMCOMPRESS){
    /* Replace runs of INTERNAL whitespace with a single space.  At this point there
       are no external whitespaces, these having already been trimmed off. */
      trimmed++;
      ws=0;
      for(from=to=string; ;from++){
        if(*from == ' ' || *from == '\t'){
          if(ws==0){    /* on the first char of whitespace write a space, skip the rest */
            *to=' ';
            ws=1;
            to++;
          }
          else { count++; }
        }
        else {
          ws=0;
          *to=*from;
          to++;
        }
        if(*from=='\0')break;
      }
    }
    if(trimmed==0)insane(INSFTLPRGERR," case not handled in function trimit()");
    target->slen -= count;
  }
  else {
     fprintf(stderr,"trimify:%d ",trimify);
  }
  return;
}



void setstring(char **val,int *numarg,int argc,char **argv,char * label){
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      *val = dup_str(argv[*numarg],strlen(argv[*numarg]));
}


void setuchar(unsigned char *val,int *numarg,int argc,char **argv,char * label){
char scratch[16];
      (*numarg)++;
      if( ( *numarg >= argc ) || (argv[*numarg] == NULL)){
        (void) fprintf( stderr, "%s: missing argument\n",label);
        exit(EXIT_FAILURE);
      }
      if(strlen(argv[*numarg])>15){
        (void) fprintf( stderr," %s%s excessively long argument\n", INSFTLERR,label);
        exit(EXIT_FAILURE);
      }
      (void) strcpy(scratch,argv[*numarg]);
      fixupescapes(scratch);
      if(scratch[1]!='\0'){
        (void) fprintf( stderr, "%s %s argument does not reduce to a single character\n",INSFTLERR,label);
        exit(EXIT_FAILURE);
      }
      *val=scratch[0];
}

/* parsing of REPLACE string in patterns and substitutions */
char *set_rep_options(char *options, MOPNEXUS *mop){
int   ok=1;
char *payload=options;  /* may be used if there is an error to show original string */
int   olen;  
int   tn=0;  /* token number,  this is the only invalid one since 1->N and -N->-1 are both valid */
int   sum;
int  *bits = &mop->bits;
int   next;
char *message=NULL;
  while(ok){
    switch (toupper(*options)){
      case 'S':  /* string           */
        *bits |= MATCH_SSUBS;     
        break;
      case 'V':  /* all dat_str from VLIST  */
        *bits |= MATCH_VSUBS;      
        break;
      case 'N':  /* Nth token from each entry in VLIST   */
        *bits |= MATCH_NVSUBS;
        if(tn){
           insane2(INSFTLERR," -[v]p[sm] repeat token number specification in REPLACE:",payload);
        }
        options++;
        parse_num(&tn,&next,options,SIGNED_ALLOW);
        if(!tn){
           insane2(INSFTLERR," -[v]p[sm] improper token number specification in REPLACE:",payload);
        }
        options += next-1; /* move to last character in number */
        mop->tn = tn;
        tn=1; /* prevent it from being set again*/
        break;
      case 'T':  /* matching tokens from VLIST (only first variable used) */
        *bits |= MATCH_TSUBS;     
        break;
      case 'Q':  /* all tokens from VLIST */
        *bits |= MATCH_QSUBS;     
        break;
      case ':':  /* end of options, payload follows */
        ok=0;
        break;
      case '\0':  
        insane2(INSFTLERR," -[v]p[sm] lacked ':' separating options in REPLACE: ",payload);    
      default:
        insane2(INSFTLERR," -[v]p[sm] REPLACE has unknown option or missing colon in ",payload);    
    }
    options++;
  }
  /* sanity checking */
  sum = (*bits & MATCH_SSUBS   ? 1 : 0 ) +
        (*bits & MATCH_VSUBS   ? 1 : 0 ) +
        (*bits & MATCH_TSUBS   ? 1 : 0 ) +
        (*bits & MATCH_QSUBS   ? 1 : 0 ) +
        (*bits & MATCH_NVSUBS  ? 1 : 0 );
  if(!sum){
    insane2(INSFTLERR," -[v]p[sm] specifies no REPLACE type:",payload);    
  }
  if(sum > 1){
    insane2(INSFTLERR," -[v]p[sm] specifies more than one REPLACE type:",payload);    
  }
  
  
  olen=strlen(options);
  if(!olen && (*bits & (MATCH_VSUBS | MATCH_TSUBS | MATCH_QSUBS | MATCH_NVSUBS))){
      insane2(INSFTLERR," -[v]p[sm] empty Variable List in REPLACE:",payload);    
  }
  if((olen!=1) && (*bits & MATCH_TSUBS)){
      insane2(INSFTLERR," -[v]p[sm] t: list contains more than one Variable List in REPLACE:",payload);    
  }
  /* empty string is ok for MATCH_SSUBS, it can be used to delete */
  
  /* fill the payload appropriately */
  if(*bits & (MATCH_SSUBS)){
    payload=dup_str(options,olen);
  }
  else if(*bits & ( MATCH_VSUBS | MATCH_NVSUBS |MATCH_TSUBS |MATCH_QSUBS)){
    if((message=vlist_set(&payload,olen,options,0))){
      fprintf(stderr,"%s%s%s\n",INSFTLERR,"  in REPLACE field: ",payload);
      insane("",message);
    }
  }
  return(payload);
}

char *set_pat_options(char *options, MOPNEXUS *mop){
int   ok=1;
char *payload=options;  /* may be used if there is an error to show original string */
int   olen;
int  *bits = &mop->bits;
int   tn,ks,next;
int   sum;
char *message=NULL;
  mop->tn = 0; /* token number,  this is the only invalid one since 1->N and -N->-1 are both valid */
  tn      = 0; /* flag for whether or not it was set */
  mop->keepsub = NULL; /* nothing in keep SUBSTRING LIST */
  ks = 0; /* invalid substring number, they start at 1 */
  while(ok){
    switch (toupper(*options)){
      case '^':  /* first match character must be first character of target     */
        *bits |= MATCH_START;      
        break;
      case '$':  /* last match character must be last character of target     */
        *bits |= MATCH_END;        
        break;
      case 'Q':  /* sequential       */
        *bits |= MATCH_SEQUENTIAL; 
        break;
      case 'F':  /* first string that matches, is the match       */
        *bits |= MATCH_FIRST; 
        break;
      case '<':  /* test all, nearest is the match                */
        *bits |= MATCH_NEAR; 
        break;
      case '>':  /* test all, farthest is the match               */
        *bits |= MATCH_FAR; 
        break;
      case 'R':  /* remainder        */
        *bits |= MATCH_REMAINDER;  
        break;
      case 'P':  /* pcre             */
        *bits |= MATCH_PCRE;       
        break;
      case 'S':  /* string           */
        *bits |= MATCH_STRING;     
        break;
      case 'V':  /* vlist            */
        *bits |= MATCH_VLIST;      
        break;
      case 'T':  /* tokens           */
        *bits |= MATCH_TOKENS;     
        break;
      case 'N':  /* n,tokens           */
        *bits |= MATCH_NVLIST;     
        break;
      case '?':  /* existence tests or math tests, n tokens or Nth element */
        switch( options[1]){
          case '?': *bits |= (MATCH_NML | MATCH_MATH); options++; break;
          case '<': *bits |= (MATCH_LT  | MATCH_MATH); options++; break;
          case '>': *bits |= (MATCH_GT  | MATCH_MATH); options++; break;
          case '=': *bits |= (MATCH_EQ  | MATCH_MATH); options++; break;
          default:  *bits |= MATCH_EXISTS;     
        }
        break;
      case 'I':  /* input files         */
        *bits |= MATCH_FILE;     
        break;
      case '/':  /* nth substring          */
        if(ks){
           insane2(INSFTLERR," -[v]p[sm] repeat substring specification in PATTERN:",payload);
        }
        ks=1;
        next=strspn(options,"/0123456789");
        mop->keepsub=make_keep_substring(options,next);
        options += next - 1 ; /* move to last character in number */
        *bits |= MATCH_KEEPN;        
        break;
      case 'M':  /* always true      */
        *bits |= MATCH_TRUE;        
        break;
      case 'C':  /* case insensitive */
        *bits |= MATCH_CASELESS;
        break;
      case 'E':  /* empty string */
        *bits |= MATCH_EMPTY;
        break;
      case 'G':  /* global */
        *bits |= MATCH_GLOBAL;
        break;
      case ':':  /* end of options, payload follows */
        ok=0;
        break;
      case '\0':  
        insane2(INSFTLERR," -[v]p[sm] lacked ':' separating options  in PATTERN",payload);    
      default:
        if(tn){
           insane2(INSFTLERR," -[v]p[sm] repeat token number specification in PATTERN:",payload);
        }
        parse_num(&tn,&next,options,SIGNED_ALLOW); /* all numbers are valid here */
        if(next==0){
          insane2(INSFTLERR," -[v]p[sm] PATTERN has unknown option or missing colon in ",payload);    
        }
        options += next - 1; /* move to last character in number */
        mop->tn = tn;
        tn = 1;  /* set flag, so that tn cannot be set again */
    }
    options++;
  }
  /* T can either be a modifier for match_exists, or it can be MATCH_TOKENS, so check for that*/
  if(*bits & MATCH_TOKENS && *bits & MATCH_EXISTS){
    *bits |= MATCH_TTOK;
    *bits &= ~MATCH_TOKENS;
  }
  /* sanity checking */
  olen=strlen(options);
  sum = (*bits & MATCH_PCRE    ? 1 : 0 ) +
        (*bits & MATCH_STRING  ? 1 : 0 ) +
        (*bits & MATCH_VLIST   ? 1 : 0 ) +
        (*bits & MATCH_TOKENS  ? 1 : 0 ) +
        (*bits & MATCH_NVLIST  ? 1 : 0 ) +
        (*bits & MATCH_TRUE    ? 1 : 0 ) +
        (*bits & MATCH_EXISTS  ? 1 : 0 ) +
        (*bits & MATCH_MATH    ? 1 : 0 ) +
        (*bits & MATCH_FILE    ? 1 : 0 );
  if(!sum){
    insane2(INSFTLERR," -[v]p[sm] does not specify a match condition in PATTERN:",payload);    
  }
  if(sum > 1){
    insane2(INSFTLERR," -[v]p[sm] specifies more than one match condition in PATTERN:",payload);    
  }
  sum = (*bits & MATCH_SEQUENTIAL    ? 1 : 0 ) +
        (*bits & MATCH_FIRST         ? 1 : 0 ) +
        (*bits & MATCH_NEAR          ? 1 : 0 ) +
        (*bits & MATCH_FAR           ? 1 : 0 );
  if(sum > 1){
    insane2(INSFTLERR," -[v]p[sm] more than one strings method (qf<>) is specified in PATTERN:",payload);
  }
  if(!(*bits & MATCH_MATH) && *bits & MATCH_STRSMETHOD && !(*bits & MATCH_STRS)){
    insane2(INSFTLERR," -[v]p[sm] multiple strings method (qf<>) specified for single string match:",payload);    
  }
  if((*bits & MATCH_EMPTY) && !(*bits & MATCH_EXISTS)){ 
    insane2(INSFTLERR," -[v]p[sm] empty string modifier (e) requires exists (?) test:",payload);    
  }
  if(*bits & MATCH_STRS && ! (*bits & MATCH_STRSMETHOD)){ 
    *bits |= MATCH_NEAR; /* no strings method was set, use the default */
  }
  if((*bits & MATCH_PCRE) && 
     (*bits & (MATCH_START   | MATCH_END   | MATCH_SEQUENTIAL ))){
    insane2(INSFTLERR," -[v]p[sm] PCRE used with incompatible option[s]:",payload);    
  }
  if(*bits & MATCH_NVLIST && !tn){
     insane2(INSFTLERR," -[v]p[sm] token number may not be 0 in N specification in PATTERN:",payload);
  }
  if(*bits & MATCH_FILE){
     if(!tn){ mop->tn=1; } /* if nothing specified default file is 1*/
     if(mop->tn > MAXINFILE || mop->tn<0){
       insane2(INSFTLERR," -[v]p[sm] input stream number out of range in PATTERN:",payload);
     }
  }
  if(*bits & (MATCH_MATH | MATCH_EXISTS)){ /* both of these, if no # specified, it means global */
    if(!tn){ *bits |= MATCH_GLOBAL; }
  }
  
  /* 's:' is allowed, it matches an empty string*/
  if(!olen){
     if(*bits & (MATCH_PCRE | MATCH_VLIST | MATCH_TOKENS | MATCH_NVLIST | MATCH_EXISTS)){
       insane2(INSFTLERR," -[v]p[sm] empty PATTERN:",payload);
     }  /* OK if olen is 0 for MATCH_TRUE, that never actually searches */   
  }
  else {
    if(*bits & MATCH_TRUE)insane2(INSFTLERR," -[v]p[sm] TRUE match PATTERN:",payload);
  }
  
  /* fill the payload appropriately */
  if(*bits & (MATCH_PCRE | MATCH_STRING)){
    payload=dup_str(options,strlen(options));
  }
  else if(*bits & ( MATCH_VLIST | MATCH_TOKENS | MATCH_NVLIST)){
    message=vlist_set(&payload,strlen(options),options,NO_DASH_ALLOW);
  }
  else if(*bits & (MATCH_EXISTS | MATCH_MATH)){
    message=vlist_set(&payload,strlen(options),options,DASH_ALLOW);
  }
  else { /* MATCH_TRUE, empty string for pattern */
    payload=dup_str("",0);
  }
  if(message){
      fprintf(stderr,"%s%s%s\n",INSFTLERR," in PATTERN field: ",payload);
      insane("",message);
  }
  return(payload);
}

/* the string contains /#/#/#/# where # are digits and the numbers count up, starting no lower
than 1. */
unsigned char *make_keep_substring(char *str, int len){
unsigned char *ct=NULL;
char *hs=str;
int   slen=0;
int   salloc=0;
int   last=0;
int   num=0;
int   i;
   for(i=0;i<len;i++,str++){
     if(*str == '/'){
       if(slen){
         if(num<1 || num > 255 || num <= last){
           insane2(INSFTLERR," keep substring specification is invalid: ",hs);
         }
         ct[slen-1]= num; /* this will fit, based on previous test */
         last      = num;
       }
       slen++;
       num=0;
       EXT_REALLOC2(ct,salloc,slen,salloc+16,1,MEMOOPS);
     }
     else if(isdigit((int) *str)){
       num = num*10 + *str - '0';
     }
     else {
       insane2(INSFTLERR," bad character in keep substring specification: ",hs);
     }
   }
   /* pick up the dangling one */
   if(num<1 || num > 255 || num <= last){
     insane2(INSFTLERR," keep substring specification is invalid: ",hs);
   }
   ct[slen-1]= num; /* this will fit, based on previous test */
   EXT_REALLOC2(ct,salloc,slen+1,salloc+16,1,MEMOOPS); /* the terminator might not though */
   ct[slen]='\0'; /* terminate it  */
   return(ct);
}

/* put together a -ps structure. */
void add_subs(MLNEXUS *subs, int src, char *pattern, char *replace){
MOPNEXUS *sop;
int pcre_options=0;
char *options;
  EXT_REALLOC2(subs->list,subs->palloc,
     subs->pcount+1,(subs->palloc + PATINC),(sizeof(MLNEXUS)),MEMOOPS);
  sop             = &(subs->list[subs->pcount]);
  sop->pattern    = dup_str(pattern,strlen(pattern));
  sop->replace    = dup_str(replace,strlen(replace));
  sop->src        = src;
  sop->bits       = MATCH_SUBS;  /* default, not global */
  sop->true       = 0;
  sop->false      = 0;
  sop->re         = NULL;

  options         = sop->pattern;
  sop->pattern    = set_pat_options(options,sop);  /* pattern with options removed, processed to VLIST if needed */
  if(sop->bits & MATCH_TRUE)insane(INSFTLERR," the 'm' option may not be used with -ps");
  free(options);

  options         = sop->replace;
  sop->replace    = set_rep_options(options,sop);  /* replace with options removed, processed to VLIST if needed */
  free(options);
  if((sop->bits & MATCH_TSUBS) && !(sop->bits & MATCH_TOKENS)){
    insane(INSFTLERR," in -psN the 't:' REPLACE option requires the 't:' PATTERN option");
  }

  if(sop->bits & MATCH_PCRE){
    if(sop->bits & MATCH_CASELESS)pcre_options = PCRE_CASELESS;
    re_precompile(sop->pattern,pcre_options, &(sop->re));
  } 
  subs->pcount++;
}

/* This routine inserts a null OP to be used solely as a target for a label.*/
void add_prematch_lbl_op(PMLNEXUS *prematches,ESNEXUS *label){
PREMOPNEXUS *pmop;
  
  EXT_REALLOC2(prematches->list,prematches->palloc,(prematches->pcount + 1),
    (PATINC + prematches->palloc),sizeof(PREMOPNEXUS),MEMOOPS);
  pmop          = &prematches->list[prematches->pcount++];
  pmop->ms      = IS_MATCH;       
  pmop->pattern = dup_str("m:",2);
  pmop->second  = dup_str(ESP_CPTR(label),ESP_CLEN(label));
  es_clear(label);
}


void add_prematches(PMLNEXUS *prematches, char type, int src, int *numarg, int argc,
  char **argv, ESNEXUS *label){
PREMOPNEXUS *pmop;
char c;
char *ct;
  
  /* + 2 in the next command because we might have to handle a dangling label */
  EXT_REALLOC2(prematches->list,prematches->palloc,(prematches->pcount + 2),
    (PATINC + prematches->palloc),sizeof(PREMOPNEXUS),MEMOOPS);
  if(ESP_CLEN(label) && ((type==IS_SECT) || (type==IS_SUBS))){
    /* There is a dangling label, and it is before -sect or -psN.  These cannot hold a label
       theselves, so insert an empty -op just to hold this label */
    add_prematch_lbl_op(prematches,label);
  }

  pmop = &prematches->list[prematches->pcount++];
  c         = src & 127;  /* will always fit */
  pmop->var = c;          /* if < MYVARSMAX then pmN,psN, else MYVARSMAX for pm*/

  switch(type){
     case IS_SUBS:
       pmop->ms  = IS_SUBS;
       setstring(&(pmop->pattern), numarg,argc,argv,argv[*numarg]);
       setstring(&(pmop->second),  numarg,argc,argv,argv[*numarg]);
       return;
     case IS_OPER: /* -op is just shorthand for -pm 'm:'  */
       pmop->ms      = IS_MATCH;       
       pmop->pattern = dup_str("m:",2);
       setstring(&(pmop->second),  numarg,argc,argv,argv[*numarg]);
       break;
     case IS_MATCH:
       pmop->ms  = IS_MATCH;
       setstring(&(pmop->pattern), numarg,argc,argv,argv[*numarg]);
       setstring(&(pmop->second),  numarg,argc,argv,argv[*numarg]);
       break;
     case IS_SECT:
       pmop->ms  = IS_SECT;       
       pmop->pattern = dup_str("",1); /* this will be used */
       pmop->second  = dup_str("",1); /* this will be ignored, but set it to an empty string */
       (*numarg)++;
       if(     0==lcl_strncasecmp(argv[*numarg],"common", 6)){ *pmop->pattern = SECT_COMMON; }
       else if(0==lcl_strncasecmp(argv[*numarg],"before", 6)){ *pmop->pattern = SECT_BEFORE; }
       else if(0==lcl_strncasecmp(argv[*numarg],"main",   4)){ *pmop->pattern = SECT_MAIN;   }
       else if(0==lcl_strncasecmp(argv[*numarg],"after",  5)){ *pmop->pattern = SECT_AFTER;  }
       else {
         insane2(INSFTLERR," unknown -sect ",argv[*numarg]);
       }
       return;
     default:
       insane(INSFTLPRGERR," add_prematches, unknown type");
  }
  if(ESP_CLEN(label)){
    /* dangling label that may be applied to -op or -pm[N], add to second param to make:  LABEL:OPERATIONS */
    ct           = pmop->second;
    pmop->second  = dup_str("",strlen(pmop->second)+ESP_CLEN(label)+1);
    sprintf(pmop->second,"%s%c%s",ESP_CPTR(label),OPERDELIM,ct);
    free(ct);
    es_clear(label);
  }
}

void add_matches(MLNEXUS *matches, JLNEXUS *jumplist, ALNEXUS *autolist, OMNINEXUS *omni,
   int src, char *pattern, char *operations){
MOPNEXUS *mop;
int pcre_options=0;
char *options;
  EXT_REALLOC2(matches->list,matches->palloc,
     matches->pcount+1,(matches->palloc + PATINC),(sizeof(MOPNEXUS)),MEMOOPS);
  mop=&(matches->list[matches->pcount]);
  mop->pattern    = dup_str(pattern,strlen(pattern));
  mop->replace    = dup_str(operations,strlen(operations));
  mop->src        = src;
  mop->true       = 0;
  mop->false      = 0;
  mop->re         = NULL;  
  mop->bits       = MATCH_OPER;  /* default, note match for global works differently than for subs */

  options         = mop->pattern;
  mop->pattern    = set_pat_options(options,mop);  /* pattern with options removed, processed to VLIST if needed */
  free(options);
  if(mop->bits & MATCH_PCRE){
    if(mop->bits & MATCH_CASELESS)pcre_options = PCRE_CASELESS;
    re_precompile(mop->pattern,pcre_options, &(mop->re));
  } 
  parse_operations(matches,jumplist,autolist,omni,operations); 
  matches->pcount++;
}

/* parse a number out of a string and figure out where it ends.  If signmode is set the
number may be negative, otherwise only >=0 */
void parse_num(int *itok, int *next, char *str, int signmode){
int itmp=0;
int sign=1;
   *next=0;
   for(;*str;str++){
     if(isdigit((int) *str)){
       itmp = 10*itmp + *str - '0';
     }
     else {
       if(signmode && *str=='-'){
         if(itmp){ /*trailing -, possible in -tok-, where the last one means input */
           break;;
         }
         else {
           sign=-1;
         }
       }
       else {
         break;
       }
     }
     (*next)++;
   }
   /* a single -, partially interpreted as a minus, but is really a dash
   because no numbers followed it. -0 is not allowed.*/
   if(sign==-1 && itmp==0)(*next)--;
   *itok=itmp*sign;
}

/* The recognized ops are:
  prefix         load
  !              none     separates the True and False set of actions.
  xVLIST         VLIST    DO_CLRV clear list of variables. variable - is an error
  x[#]VLIST      int,VLIST  DO_NPOPV remove token(s) from vN. If specified # is the first token, else 1
  m              int, VLIST    DO_MRGV, #=INT_MAX. merge all tokens in each variables. variable - is an error
  m[#]VLIST      int, VLIST    DO_MRGV, #>0, if # specified it is the token numbe, else 1. 
  %[bhia|all]    STR      DO_BHIA Set the interpretation of the SUBSTRING LIST when converting to tokens. b=before
                          h=hit, i=in between, a = after, all - bhia.  Affects = and @ actions.
  vVLIST         VLIST    DO_VSETV apply -vN definitions to src (either input line or a variable), - is an error
  vVLIST<M       VLIST    
                          DO_VSETV like v, but use vM for input instead of line input (vM is first in VLIST)

   IMPORTANT!  None of the +N operations can have the same variable as both dst and src.
   The main reason is that if a reallocation event occurs for dst it usually invalidates
   the pointer for the src.  The test for dst==src are all done in this routine.
  +N             VLIST   
                          DO_VV append default input (MYVARSMAX) to vN (vlist is vN then MYVARSMAX then EOVLIST)
  +N<VLIST       VLIST
                          DO_VV append VLIST to vN.  (vlist is vN then VLIST, then EOVLIST)
  +N<=STR        char,STR
                          DO_STRV append STR to vN
  +N<[FIELD]     char,char,STR
                          DO_FMTV run format field and append to vN
  +N<#VLIST      int,VLIST
                          DO_NVV append token # of VLIST to vN.  (vlist is vN, VLIST, then EOVLIST)
  ?EXPR          PROG     DO_MATH run the math expression
  <VLIST         VLIST    DO_VEMIT  emit variables from list verbatim
  <=STR          STR      DO_STR  emit STR
  <[FIELD]       FIELD    DO_FEMIT format and emit field
  |VLIST         VLIST    DO_EOL, put a \n on the end of the string, make it the delimiter, if the
                           there is already a last token.
  ~[$]VLIST      VLIST    DO_SHOWV or DO_SHOWNV  for debugging, show only these variables
  >              VLIST    DO_SETC append match results (substrings) sequentially to a list of variables,
                             - is allowed and means skip.  If VLIST is consumed and matches remain it
                             starts over at the beginning.
  >#                      DO_READ from stream #, sections BEFORE and AFTER only.
  po             char,VLIST DO_PO apply the PO in the char (0-9) to the vlist
  if[c+]r        int      DO_IF  -if logic  r is for norestart
  if-            int      DO_IF  -ifterm logic
  n              int      DO_IFN -ifn logic
  i0,i1          int      DO_SWVAL modify sw_* variables
  sw#            ints     DO_SW, load is array size (#), then array
  afmt           int      DO_AFMT make fmt active
  nfmt           int      DO_NFMT make fmt active next
  hide           none     DO_HIDE suppress output
  show           none     DO_SHOW allow output
  ^              none     indicate target for jump (meta operation, resolves to a skip)
  ^              INT      DO_SKIP jump to the statement at (positive) offset INT. 0 is a one line loop.
  =              none     label this structure (as target for jump) (meta operation, resolves to nothing)
  {,}{,}         none     autolabel this structure (as target for jump) (meta operation, resolves to nothing)
  c[#]           none     autolabel or label this switch (as target for jump) (meta operation, resolves to nothing)
  &              none     DO_CALL stores a value like a jump, but it is a function call.
  brk            none     DO_BRK  skip the remainder
  eof            none     DO_EOF  close the input (like an EOF)
  exit           none     DO_EXIT immediate exit with SUCCESS
  fail           none     DO_FAIL immediate exit with FAIL

NOTE.  Anything that adds something other than an INT with es_append_dat must call
  ESP_NEXTINTBOUNDARY(alldata);
to keep data aligned on boundaries!
  
  */

int add_action(MLNEXUS *matches, JLNEXUS *jumplist, ALNEXUS *autolist, OMNINEXUS *omni, 
  int *actions, int count, char *atoken, const char *operations, int length, int *negate){
int   i;
long  tlong;
int   dstart=0;
char *vlist=NULL;
char *ct=NULL;
int   itmp;
int   i2;
char  ctmp;
char  ctmp2;
char  alabel[16]; /* scratch space for autolabel */
int   next;
int   front;
char *message=NULL;
ESNEXUS  *mprog   = NULL;
ESNEXUS  *rpnprog = omni->piece;  /* OK to use piece for this, rpnprog fully contained in this call*/
ESNEXUS  *alldata = omni->alldata;
ESNEXUS  *noleaks = omni->noleaks;
MOPNEXUS *mn      = &(matches->list[matches->pcount]);
ANEXUS   *alist   = NULL;
FIELD2NEXUS *f2n  = NULL;

   while(*atoken==' '){ atoken++; length--; }  /* leading spaces on operation tokens is ignored */
   dstart=alldata->slen; /* in a few cases this is reassigned, but mostly this is used */
   front=1;
   if(      lstrcasecmp(atoken,length,"!",1)  == 0){
     if(*negate){
       message = wait_insane(INSFTLERR," match operation definition contains more than one !");
       goto oops;
     }
     if(count){
       if(jumplist->skip > 1){ /* only one unconditional jump for True, one for False, branches */
         message = wait_insane2(INSFTLERR," more than one ^, brk, or # operator:",operations);
         goto oops;
       }
       else { jumplist->skip = 0; }
       actions[count++] = DO_LISTEND;  /* No associated offset  */
       mn->true=alldata->slen;
       es_append_aidat(alldata,(char *)&actions[0],count*SOI,ALLDATAINC,MEMOOPS);
     }
     count   = 0;
     *negate = 1;
   }
   else if( lstrcasecmp(atoken,1,"x",1)  == 0){  /* DO_CLRV or DO_NPOPV*/
     if(atoken[front]=='-' || isdigit((int) atoken[front])){
       actions[count++] = DO_NPOPV;
       parse_num(&itmp,&next,&atoken[front],SIGNED_ALLOW);
       front+=next;
       es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     }
     else {
       actions[count++] = DO_CLRV;
     } 
     message=vlist_set(&vlist,    length-front, &(atoken[front]), NO_DASH_ALLOW);
     es_append_dat(alldata,vlist,vlist_len(vlist),ALLDATAINC,MEMOOPS);
     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,1,"m",1)  == 0){  /* DO_MRGV */
     if(atoken[front]=='-' || isdigit((int) atoken[front])){
       parse_num(&itmp,&next,&atoken[front],SIGNED_ALLOW);
       front+=next;
     }
     else {
       itmp=1;  /* this means merge all of them */
     } 
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     message=vlist_set(&vlist,    length-front, &(atoken[front]), NO_DASH_ALLOW);
     es_append_dat(alldata,vlist,vlist_len(vlist),ALLDATAINC,MEMOOPS);
     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = DO_MRGV;
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,1,"|",1)  == 0){
     dstart=alldata->slen; 
     message=vlist_set(&vlist,    length-1, &(atoken[1]), NO_DASH_ALLOW);
     es_append_dat(alldata,vlist,length,ALLDATAINC,MEMOOPS);
     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = DO_EOL;
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,1,">",1)  == 0){ /* DO_SETC or DO_READ */
     dstart=alldata->slen;
     parse_num(&itmp,&next,&atoken[front],NO_SIGNED_ALLOW);
     if(!next){ itmp=1;   } /* no stream specified, use default */
     if(next || length==1){ /* a plain ">" reads from stream 1 */
       if(itmp>infiles){
         message = wait_insane2(INSFTLERR," in ># clause, # is not a valid input stream: ",atoken);
       }
       es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
       actions[count++] = DO_READ;
     }
     else {
       message=vlist_set(&vlist,    length-1, &(atoken[1]), DASH_ALLOW);
       es_append_dat(alldata,vlist,length,ALLDATAINC,MEMOOPS);
       ESP_NEXTINTBOUNDARY(alldata);
       actions[count++] = DO_SETC;
     }
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,1,"?",1)  == 0){  /* compile and store a math expression */
     ct = dup_str(&atoken[front],length-front);
     mprog = compile_math(ct,&message); /* message set to NULL first thing in here */
     if(message)goto oops;
     message = pre_run_math(omni,mprog,rpnprog);
     if(message)goto oops;
     es_destroy(&mprog);
     ESP_NEXTDBLBOUNDARY(alldata); /* maintain alignment for doubles and ints */
     dstart = alldata->slen;
     es_append_dat(alldata,rpnprog->string,rpnprog->slen,ALLDATAINC,MEMOOPS);
     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = DO_MATH;
     actions[count++] = dstart;
   }  
   else if( lstrcasecmp(atoken,1,"+",1)  == 0){ /* DO_VV, DO_STRV, DO_FMTV, or DO_NVV*/
     itmp=TOVAROFF(atoken[1]); 
     if(itmp <0 || itmp>=MYVARSMAX){
       message = wait_insane2(INSFTLERR," in +N clause, N is not a variable A-Z: ",atoken);
       goto oops;
     }
     ctmp=itmp;
     front++; /* was 1, now 2*/
     if(front==length || atoken[front]==OPERDELIM){
       actions[count++] = DO_VV;
       es_append_dat(alldata,&ctmp,1,ALLDATAINC,MEMOOPS);  /* effectively this becomes part of the vlist */
       ctmp = mn->src; /* indicate from input */
       vlist_set1(&vlist,ctmp);
       es_append_dat(alldata,vlist,2,ALLDATAINC,MEMOOPS);
     }
     else if (atoken[front]=='<'){
       if (atoken[front+1]=='='){
         actions[count++] = DO_STRV;
         es_append_dat(alldata,&ctmp,1,ALLDATAINC,MEMOOPS);
         front+=2;
         ct = dup_str(&atoken[front],length-front);
         fixupescapes(ct);  /* this could reduce to an empty string.  That is OK */
         es_append_str(alldata,ct,strlen(ct),ALLDATAINC,MEMOOPS);
       }
       else if (atoken[front+1]=='['){
         actions[count++] = DO_FMTV;
         front++;
         ct = dup_str(&atoken[front],length-front);
         fixupescapes(ct);  /* this should not reduce to an empty string. */
         EXT_CALLOC(f2n,1,sizeof(FIELD2NEXUS),MEMOOPS);
         i2=0;  /* fldcount */
         add_op(omni, ct, 0, strlen(ct), f2n, &i2, omni->gblparams, 1);
         /* if f2n has a vlist that is floating around in memory who knows where
         and it won't be easy to release it.  So put a copy of this pointer in noleaks. */
         if(f2n->vlist){
           es_append_cptr(noleaks,f2n->vlist,ALLPTRINC,MEMOOPS);
         }
         /* add_op puts the processing list in alldata too.  Must wait until after that to
         store all the parameters. */
         dstart = alldata->slen; 
         if((MODENUM != (f2n->source & MODEMASK)) &&
            (ctmp == mn->src || (f2n->vlist && vlist_holds(f2n->vlist,ctmp)))
           ){  /* >A=[$a:] is OK */
           message = wait_insane2(INSFTLERR," invalid +N<[DEF] clause, same variable is src and dst:",atoken);
           goto oops;
         }
         es_append_dat(alldata,&ctmp,1,ALLDATAINC,MEMOOPS);     /* dst variable */
         es_append_dat(alldata,&mn->src,1,ALLDATAINC,MEMOOPS);  /* src variable */
         ESP_NEXTINTBOUNDARY(alldata);
         es_append_str(alldata,(char *)f2n,sizeof(FIELD2NEXUS),ALLDATAINC,MEMOOPS);
       }
       else if ((atoken[front+1]=='-' && isdigit((int) atoken[front + 2])) || isdigit((int) atoken[front + 1])){
         actions[count++] = DO_NVV;
         front += 1;
         parse_num(&itmp,&next,&atoken[front],SIGNED_ALLOW);
         front += next;
         if(length-front){ /* there is a literal VLIST */
           message=vlist_set(&vlist, length - front, &atoken[front], DASH_ALLOW);
           if(message){goto oops;};
         }
         else {
           ctmp2 = mn->src; /* src from -pmN or -pm */
           vlist_set1(&vlist,ctmp2);
         }
         if(vlist_holds(vlist,ctmp)){
           message = wait_insane2(INSFTLERR," invalid +N<#VLIST clause, N is contained in VLIST:",atoken);
           goto oops;
         }
         es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
         es_append_dat(alldata,&ctmp,1,ALLDATAINC,MEMOOPS);  /* effectively this becomes part of the vlist */
         es_append_dat(alldata,vlist,vlist_len(vlist),ALLDATAINC,MEMOOPS);
       }
       else {
         actions[count++] = DO_VV;
         front += 1;
         es_append_dat(alldata,&ctmp,1,ALLDATAINC,MEMOOPS);  /* effectively this becomes part of the vlist */
         message=vlist_set(&vlist, length-front, &atoken[front], DASH_ALLOW);
         if(message){goto oops;}
         if(vlist_holds(vlist,ctmp)){
           message = wait_insane2(INSFTLERR," invalid +N<VLIST clause, N is contained in VLIST:",atoken);
           goto oops;
         }
         es_append_dat(alldata, vlist,vlist_len(vlist),ALLDATAINC,MEMOOPS);
       }
     }
     else {
       message = wait_insane2(INSFTLERR," unrecognized match OPERATION starting at: ",operations);
       goto oops;
     }

     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,1,"<",1)  == 0){ /* DO_VEMIT, DO_FEMIT, DO_SEMIT*/
     parse_num(&itmp,&next,&atoken[front],NO_SIGNED_ALLOW);
     if(next){ front += next; }
     else {    itmp=1;        } /* no stream specified, use default */
     if(itmp > outfiles){
       message = wait_insane2(INSFTLERR," output stream in < clause greater than -out files:",operations);
       goto oops;
     }
     if(atoken[front]=='='){
       actions[count++] = DO_SEMIT;
       es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
       front+=1;
       ct = dup_str(&atoken[front],length-front);
       fixupescapes(ct);  /* this could reduce to an empty string.  That is OK */
       es_append_str(alldata,ct,strlen(ct),ALLDATAINC,MEMOOPS);
     }
     else if(atoken[front]=='['){
       actions[count++] = DO_FEMIT;
       ctmp = mn->src; /* indicate from input */
       vlist_set1(&vlist,ctmp);
       EXT_CALLOC(f2n,1,sizeof(FIELD2NEXUS),MEMOOPS);
       ct = dup_str(&atoken[front],length-front);
       fixupescapes(ct);  /* this could reduce to an empty string.  That is OK */
       i2=0;  /* fldcount */
       add_op(omni, ct, 0, strlen(ct), f2n, &i2, omni->gblparams, 1);
       /* if f2n has a vlist that is floating around in memory who knows where
       and it won't be easy to release it.  So put a copy of this pointer in noleaks. */
       if(f2n->vlist){
         es_append_cptr(noleaks, f2n->vlist,ALLPTRINC,MEMOOPS);
       }
       /* add_op puts the processing list in alldata too.  Must wait until after that to
       store all the parameters. */
       dstart = alldata->slen; /* dstart must be assigned again */
       es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
       es_append_dat(alldata,vlist,2,ALLDATAINC,MEMOOPS);
       ESP_NEXTINTBOUNDARY(alldata);
       es_append_str(alldata,(char *)f2n,sizeof(FIELD2NEXUS),ALLDATAINC,MEMOOPS);
     }
     else {
       actions[count++] = DO_VEMIT;
       es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
       message=vlist_set(&vlist, length-front, &atoken[front], DASH_ALLOW);
       if(message){goto oops; }
       es_append_dat(alldata,vlist,vlist_len(vlist),ALLDATAINC,MEMOOPS);
     }
     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,1,"~",1)  == 0){ /* DO_SHOWV or $DO_SHOWNV*/
     if(atoken[1]=='$'){ actions[count++] = DO_SHOWNV; front++; length--; }
     else {              actions[count++] = DO_SHOWV;                     }
     message=vlist_set(&vlist, length-1, &atoken[front], DASH_ALLOW); /* DASH is input for STRING, result for NUMERIC*/
     if(message){goto oops; }
     es_append_dat(alldata,vlist,vlist_len(vlist),ALLDATAINC,MEMOOPS);
     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,1,"%",1)  == 0){ 
     /*  this one may or may not end up in an action, If it is just HIT then do nothing,
     that's how the substrings are by default.  Otherwise, make it an action.  */
     atoken++;
     length--;
     if(lstrcasecmp(atoken,3,"all",3) == 0){ itmp = MATCH_BHIA; }
     else {
       itmp=0;
       while(length){
         switch(toupper(*atoken)){
           case 'A': itmp |= MATCH_A; break;
           case 'B': itmp |= MATCH_B; break;
           case 'H': itmp |= MATCH_H; break;
           case 'I': itmp |= MATCH_I; break;
           default:
            message=wait_insane2(INSFTLERR," invalid character in %BHIA clause in operations statement:",operations);
            goto oops;
         }
         atoken++;
         length--;
       }
     }
     if(itmp != MATCH_H){ /* have to actually do this, not just hits */
       es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
       actions[count++] = DO_BHIA;
       actions[count++] = dstart;
     }
   }
   else if( lstrcasecmp(atoken,1,"v",1)  == 0){ /* VSETV*/
     atoken++;
     ct  = dup_str("",length+2);/* big enough to hold vlist no matter what*/
     next=strcspn(atoken,"<");
     if(next + 1 >= length){ /* no < found */
       *ct = 'A';  /*any variable, it wll be overwritten*/
       memcpy(&ct[1],atoken,length-1);  /* the vlist is placed after it */
       ct[length]='\0';
       message=vlist_set(&vlist, length, ct, NO_DASH_ALLOW);
       if(message){goto oops; }
       *vlist = mn->src; /* N from pmN, or MYVARSMAX if pm (from input) */
     }
     else {  /* < found */
       if(next + 3 < length){
         insane2(INSFTLERR," command line extra characters after vVLIST<N: ",operations);
       }
       *ct=atoken[next+1]; /* the character after <, should be a variable letter */
       memcpy(&ct[1],atoken,next);  /* the vlist is placed after it */
       /* M is converted and passed in as the first position in the VLIST) */
       ct[next+1]='\0';
       message=vlist_set(&vlist, next+1, ct, NO_DASH_ALLOW);
       if(message){goto oops; }
       if(vlist_holds(&vlist[1],vlist[0])){
           insane2(INSFTLERR," invalid vVLIST<N clause, N is contained in VLIST:",atoken);
       }
     }
     es_append_dat(alldata,vlist,vlist_len(vlist),ALLDATAINC,MEMOOPS);
     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = DO_VSETV;
     actions[count++] = dstart;
   }
   else if( length<=4 &&lstrcasecmp(atoken,2,"if",2)  == 0){ 
     itmp  = 0; 
     if(omni->ifstate & IF_TAG){
       insane2(INSFTLERR," command line -if may not be combined with -[v]pm if[c+-] operations: ",operations);
     }
     omni->ifstate |= IF_EXISTS;  /* enables/disables if logic processing overall in main */
     for(i=2;i<length;i++){
       switch(atoken[i]){
         case '-':
           itmp |= IF_TERM;
           break;
         case '+':
           itmp |= IF_STARTT;
           break;
         case '1':
           itmp |= IF_START1;
           break;
         case 'c': 
         case 'C': 
           itmp |= IF_STARTC;
           break;
         case 'r': 
         case 'R': 
           itmp |= IF_NORESTART;
           break;
         default:
          message=wait_insane2(INSFTLERR," invalid if clause in operations statement:",operations);
          goto oops;
       }
     }
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     actions[count++] = DO_IF;
     actions[count++] = dstart;
   }
   else if(  length==5 && lstrcasecmp(atoken,4,"afmt",4)  == 0){
     itmp=TOFMTOFF(atoken[4]);
     if(itmp<0 || itmp >9){
          insane2(INSFTLERR," invalid afmt clause in operations statement:",operations);
     }
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     actions[count++] = DO_AFMT;
     actions[count++] = dstart;
   } 
   else if( length==5 && lstrcasecmp(atoken,4,"nfmt",4)  == 0){
     itmp=TOFMTOFF(atoken[4]);
     if(itmp<0 || itmp >9){
          insane2(INSFTLERR," invalid afmt clause in operations statement:",operations);
     }
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     actions[count++] = DO_NFMT;
     actions[count++] = dstart;
   } 
   else if(lstrcasecmp(atoken,2,"po",2)  == 0){
     itmp=TOVAROFF(atoken[2]);
     if(itmp>=0 && itmp < MYVARSMAX){ /* poN form */
       itmp = 0;
       i2   = 2;
     }
     else {
       itmp=TOPOOFF(atoken[2]);
       if(itmp<0 || itmp >9){
            insane2(INSFTLERR," invalid po clause in operations statement:",operations);
       }
       i2 = 3;
     }
     ctmp=itmp;
     es_append_dat(alldata,&ctmp,1,ALLDATAINC,MEMOOPS);  /* PO passed in a byte */
     message=vlist_set(&vlist,    length-i2, &(atoken[i2]), NO_DASH_ALLOW);
     es_append_dat(alldata,vlist,length-i2+1,ALLDATAINC,MEMOOPS);
     ESP_NEXTINTBOUNDARY(alldata);
     actions[count++] = DO_PO;
     actions[count++] = dstart;
   } 
   else if( lstrcasecmp(atoken,1,"n",1)  == 0){ /* this must follow the nfmt parse */
     if(! lstrtol(&atoken[1],length-1,&tlong)){
          insane2(INSFTLERR," invalid n clause in operations statement:",operations);
     }
     if(tlong<0){
          insane2(INSFTLERR," the number in an n operation must be nonnegative:",operations);
     }
     itmp=tlong; /* in case long != int */
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     actions[count++] = DO_IFN;
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,length,"brk",3)  == 0){
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     actions[count++] = DO_BRK;
     jumplist->skip++;
   }
   else if( lstrcasecmp(atoken,length,"hide",4)  == 0){
     actions[count++] = DO_HIDE; /* No associated offset  */
   } 
   else if( lstrcasecmp(atoken,length,"show",4)  == 0){
     actions[count++] = DO_SHOW; /* No associated offset  */
   } 
   else if( lstrcasecmp(atoken,length,"eof",3)  == 0){
     actions[count++] = DO_EOF;
   } 
   else if( lstrcasecmp(atoken,length,"exit",4)  == 0){
     actions[count++] = DO_EXIT;
   } 
   else if( lstrcasecmp(atoken,length,"fail",4)  == 0){
     actions[count++] = DO_FAIL;
   } 
   else if( lstrcasecmp(atoken,length,"ret",3)  == 0){
     actions[count++] = DO_RET;
   } 
   else if( lstrcasecmp(atoken,(length > 1 ? 1 : length),"^",1)  == 0){
     itmp=0; /* this is a placeholder until the label is resolved */
     if(               atoken[1] == '{'){ /*  jump to automatic label open brace */
       next = strspn(&atoken[1],"{");
       if(length - next - 1){
         insane2(INSFTLERR," invalid ^{ operation at:",operations);
       }
       i    = autolist->length - next + 1;
       if(i<=0){ insane2(INSFTLERR," jump to nonexistent enclosing '{' at:",operations); }
       alist = &autolist->list[i];
       sprintf(alabel,"ATOP%8.8d",alist->first);  
       if(omni->dbg & DBGAL){ 
         fprintf(stderr,"autoREF {  depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
       }
       jump_add(jumplist,dstart,matches->pcount,alabel,13);
     }
     else if( !strncmp(&atoken[1],"}{",2)){ /* jump to automatic label close/open brace */
       if(length - 3){
         insane2(INSFTLERR," invalid ^}{ operation at:",operations);
       }
       if(autolist->length <= 0){
         insane2(INSFTLERR," mismatched braces: no preceding { at:",operations);
       }
       alist = &autolist->list[autolist->length];
       sprintf(alabel,"AMID%8.8d",alist->mid);  
       if(omni->dbg & DBGAL){ 
         fprintf(stderr,"autoREF }{ depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
       }
       jump_add(jumplist,dstart,matches->pcount,alabel,13);
     }
     else if(          atoken[1] == '}'){ /* jump to automatic label close brace  */
       /* this elseif must follow the preceding one or it would take precedence */
       next = strspn(&atoken[1],"}");
       if(length - next - 1){
         insane2(INSFTLERR," invalid ^} operation at:",operations);
       }
       i    = autolist->length - next + 1;
       if(i<=0){ insane2(INSFTLERR," jump to nonexistent enclosing '}' at:",operations); }
       alist = &autolist->list[i];
       sprintf(alabel,"ABOT%8.8d",alist->last);  
       if(omni->dbg & DBGAL){ 
         fprintf(stderr,"autoREF }  depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
       }
       jump_add(jumplist,dstart,matches->pcount,alabel,13);
     }
     else{
       parse_num(&itmp,&next,&atoken[1],NO_SIGNED_ALLOW);
       if(next){ /* ^number, so a skip */
         if(itmp < 0 ){ insane2(INSFTLERR," ^ with negative value:",operations); }
         if(next != length - 1){ insane2(INSFTLERR," jump labels may not start with digits:",operations); }
         itmp=itmp + matches->pcount; /* Absolute position to skip to */
       }
       else { /* explicit label */
         jump_add(jumplist,dstart,matches->pcount,&atoken[1],length-1);
       }
     }
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     actions[count++] = DO_SKIP;
     actions[count++] = dstart;
     jumplist->skip++;
   } 
   else if( lstrcasecmp(atoken,(length > 2 ? 2 : length),"sw",2)  == 0){
     itmp=0; /* this is a placeholder until the label is resolved */
     if(autolist->skip != 1){ insane2(INSFTLERR," sw requires preceding { at:",operations); }
     front=2;
     parse_num(&itmp,&next,&atoken[front],NO_SIGNED_ALLOW);
     if(next){
       if(itmp < 2 ){
         insane2(INSFTLERR," invalid 'sw' clause in operations statement:",operations);
       }
     }
     else {
       insane2(INSFTLERR," invalid 'sw' clause at:",operations);
     }
     /* redo the autolist for a switch */
     if(autolist->length <= 0){
        insane2(INSFTLERR," sw requires preceding { at:",operations);
     }
     alist             = &autolist->list[autolist->length];
     alist->mid        = alist->first + 1;
     alist->last       = alist->first + itmp  + 1;
     autolist->counter = alist->last;
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS); /* table length */
     front=-1;
     for(itmp=alist->mid; itmp<alist->last; itmp++){
       sprintf(alabel,"AMID%8.8d",itmp);  
       if(omni->dbg & DBGAL){ 
         fprintf(stderr,"autoRSV c  depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
       }
       jump_add(jumplist,alldata->slen,matches->pcount,alabel,13);
       es_append_aidat(alldata,(char *)&front,SOI,ALLDATAINC,MEMOOPS); /* a jump table entry */
     }
     actions[count++] = DO_SW;
     actions[count++] = dstart;
     jumplist->skip++;
   } 
   else if( lstrcasecmp(atoken,(length > 1 ? 1 : length),"&",1)  == 0){
     itmp=0; /* this is a placeholder until the label is resolved  */
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     actions[count++] = DO_CALL;
     actions[count++] = dstart;
     jump_add(jumplist,dstart,matches->pcount,&atoken[1],length-1);
   } 
   else if( lstrcasecmp(atoken,(length > 1 ? 1 : length),"i",1)  == 0){
     atoken++;
     if(toupper(*atoken )== 'M'){
       itmp=SWI_MV;
     }
     else if(toupper(*atoken )== 'P'){
       itmp=SWI_MP;
     }
     else if(toupper(*atoken )== 'R'){
       itmp=SWI_MATH;
     }
     else {
       parse_num(&itmp,&next,atoken,NO_SIGNED_ALLOW);
       if(next){
         if(itmp > 1 || itmp <0){
           insane2(INSFTLERR," invalid 'i' clause in operations statement:",operations);
         }
         /* so 0 or 1, same thing as SWI_BIT0 or SWI_BIT1*/
       }
       else {
         insane2(INSFTLERR," invalid 'i' clause at:",operations);
       }
     }
     es_append_aidat(alldata,(char *)&itmp,SOI,ALLDATAINC,MEMOOPS);
     actions[count++] = DO_SWI;
     actions[count++] = dstart;
   }
   else if( lstrcasecmp(atoken,(length > 1 ? 1 : length),"c",1)  == 0){
     if(autolist->length <= 0){
       insane2(INSFTLERR," sw \"c\" label is not preceded by a { brace at:",operations);
     }
     alist = &autolist->list[autolist->length];
     atoken++;
     parse_num(&itmp,&next,atoken,NO_SIGNED_ALLOW);
     if(next){
       if(itmp > alist->last - alist->first - 2){
         insane2(INSFTLERR," invalid c# clause in operations statement:",operations);
       }
       parse_num(&i2,&next,&atoken[next],SIGNED_ALLOW);
       if(i2<0){ 
         i2 = -i2;
         if(i2<itmp || (i2 > alist->last - alist->first - 2)){
           insane2(INSFTLERR," invalid cSTART-END clause in operations statement:",operations);
         }
       }
       else { i2 = itmp; } /* no number, just do one */
       for(; itmp <= i2; itmp++){
         sprintf(alabel,"AMID%8.8d",alist->mid + itmp);  
         jump_add(jumplist,-1,matches->pcount,alabel,13);
         if(omni->dbg & DBGAL){ 
           fprintf(stderr,"autoLBL c  depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
         }
       }
     }
     else {
       if(!alist){
         insane2(INSFTLERR," stray 'c' label outside of switch at:",operations);
       }
       if(alist->mid >= alist->last){
         insane2(INSFTLERR," too many 'c' labels for this switch at:",operations);
       }
       sprintf(alabel,"AMID%8.8d",alist->mid++);  
       jump_add(jumplist,-1,matches->pcount,alabel,13);
       if(omni->dbg & DBGAL){ 
         fprintf(stderr,"autoLBL c  depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
       }
     }
   }
   else if( lstrcasecmp(atoken,(length > 1 ? 1 : length),"{",1)  == 0){
     if(autolist->skip){ insane2(INSFTLERR," multiple open braces in the same line:",operations); }
     autolist->skip = 1;
     EXT_REALLOC2(autolist->list,autolist->alloc,(1+autolist->length),ALINC,sizeof(ANEXUS),MEMOOPS);
     alist        = &autolist->list[++autolist->length];
     alist->first = ++(autolist->counter);   
     alist->mid   = ++(autolist->counter);
     alist->last  = ++(autolist->counter);
     sprintf(alabel,"ATOP%8.8d",alist->first);  
     if(omni->dbg & DBGAL){ 
       fprintf(stderr,"autoLBL {  depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
     }
     jump_add(jumplist,-1,matches->pcount,alabel,13);
   }
   else if( lstrcasecmp(atoken,(length > 2 ? 2 : length),"}{",2)  == 0){
     if(autolist->skip){ insane2(INSFTLERR," multiple braces in the same line:",operations); }
     autolist->skip = 2;
     if(autolist->length <= 0){
       insane2(INSFTLERR," mismatched braces }{ not preceded by a { brace at:",operations);
     }
     alist        = &autolist->list[autolist->length];
     sprintf(alabel,"AMID%8.8d",alist->mid);  
     if(omni->dbg & DBGAL){ 
       fprintf(stderr,"autoLBL }{ depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
     }
     jump_add(jumplist,-1,matches->pcount,alabel,13);
     alist->mid  = ++(autolist->counter);
   }
   else if( lstrcasecmp(atoken,(length > 1 ? 1 : length),"}",1)  == 0){
     /* having multiple pure close braces in one line is OK, but cannot reside with { or }{  */
     if(autolist->skip > 0){ insane2(INSFTLERR," multiple braces in the same line:",operations); }
     autolist->skip = -1;
     if(autolist->length <= 0){
       insane2(INSFTLERR," mismatched braces, too many } or no preceding { brace at:",operations);
     }
     alist        = &autolist->list[autolist->length];
     sprintf(alabel,"ABOT%8.8d",alist->last);  
     if(omni->dbg & DBGAL){ 
       fprintf(stderr,"autoLBL }  depth %d %s line %d at %s\n",autolist->length, alabel,matches->pcount,operations);
     }
     jump_add(jumplist,-1,matches->pcount,alabel,13);
     autolist->length--;
     if(autolist->length < 0){
       insane2(INSFTLERR," mismatched braces (too many }) at:",operations);
     }
   }
   else if( lstrcasecmp(atoken,(length > 1 ? 1 : length),"=",1)  == 0){
     jump_add(jumplist,-1,matches->pcount,&atoken[1],length-1);
   }
   else {
     message=wait_insane2(INSFTLERR," unrecognized match OPERATION starting at: ",atoken);
   }
oops:
   if(message){
     fprintf(stderr,"%s  Problem at -pm/-op expression %d\n",INSFTLERR,matches->pcount);
     insane("",message);
   }
   if(ct)free(ct);
   if(vlist)free(vlist);
   if(f2n)free(f2n);
   return(count);
}

/* keep track of labels.  if adpos is >=0 then it corresponds to the address field in a jmp or 
  & (function call) location. If adpos < 0 then it is a label declaration. */
void jump_add(JLNEXUS *jumplist, int adpos, int mpos, char *string, int length){
JMPNEXUS *jptr;
  EXT_REALLOC2(jumplist->list,jumplist->alloc,(jumplist->length + 1),
    (jumplist->alloc + PATINC),sizeof(JMPNEXUS),MEMOOPS);
  jptr           = &(jumplist->list[jumplist->length]);
  jptr->label    = dup_up_str(string,length);
  jptr->adpos    = adpos;             /* where the skip data field is located */
  jptr->mpos     = mpos;              /* where the jmp was called in the matches list */
  jumplist->length++;
}

/* For debugging, not compiled into final program */
void jump_dump(JLNEXUS *jumplist){
int       i;
JMPNEXUS *jptr;
   for(i=0,jptr=jumplist->list;i<jumplist->length;i++,jptr++){
      printf("%4d label:%s adpos:%d mpos:%d\n",i,jptr->label,jptr->adpos,jptr->mpos);
   }
   fflush(stdout);
}

/* resolve labels.  Sort the jumplist by label, then adpos.  if adpos is >=0 then it corresponds
  to the address field in a jmp or & (function call) location. If adpos < 0 then it is a label.
  declaration. When sorted into ascending order the declarations are seen before the references.
  Stray or mismatched top braces are ignored by this routine, since it is not required that anytning
  transfer control to them.  However, all named, "c", '}{' and '}' labels must be referenced
  somewhere.
  
  =main may be used ONCE.  It is not required.  Its position in the list is returned. */
int jump_resolve(JLNEXUS *jumplist, ESNEXUS *alldata){
int       i;
JMPNEXUS *jptr;
char     *label;
char     *firstlabel=NULL;
int       firstline=0;
int       found=1;
int       itmp;
int       mpos=0;
int       mainline=0;
  if(jumplist->length){
    for(i=0,jptr=jumplist->list;i<jumplist->length;i++,jptr++){
      if(jptr->adpos<0){
         firstline=jptr->mpos;
         firstlabel=jptr->label;
         break;
      }
    }
    /* jump_dump(jumplist);  DEBUG */
    qsort((void *)jumplist->list,jumplist->length,sizeof(JMPNEXUS),compare_jmp);
    /* jump_dump(jumplist);   DEBUG */
    itmp=0;
    label=(char *)&itmp; /* it must point at something for the first strcmp */

    /* now that they are in order ... */
    for(i=0,jptr=jumplist->list;i<jumplist->length;i++,jptr++){
      if(strcmp(label,jptr->label)!=0){ /* new label */
        if(!found){
          if(0==strncmp(label,"MAIN",4)){
             mainline = mpos;
             if(mainline && firstline){
                insane2(INSFTLERR," Unreachable script lines before first label:",firstlabel); 
             }
          }
          else if(strncmp(label,"ATOP",4)){
            insane2(INSFTLERR," label was declared but not referenced:",label); 
          }
        }
        label  = jptr->label;
        mpos   = jptr->mpos;
        if(jptr->adpos >= 0){
          insane2(INSFTLERR," label is referenced but not declared:",label); 
        }
        found  = 0;
      }
      else {
        found = 1;
        es_insert(alldata, jptr->adpos, (char *) &mpos, SOI, ALLDATAINC,
           " jump_resolve at es_insert");
      }
    }  
    if(!found && strncmp(label,"ATOP",4)){  insane2(INSFTLERR," label was declared but not referenced:",label); }
  }
  jl_clear(jumplist);  /* reset */
  return(mainline);
}

void al_destroy(ALNEXUS **autolist){
  free((*autolist)->list);
  free(*autolist);
  *autolist=NULL;
}

void jl_destroy(JLNEXUS **jumplist){
  jl_clear(*jumplist);
  free((*jumplist)->list);
  free(*jumplist);
  *jumplist=NULL;
}

void jl_clear(JLNEXUS *jumplist){
int       i;
JMPNEXUS *jptr;
  for(jptr=jumplist->list, i=0; i<jumplist->length; i++,jptr++){
    if(jptr->label){
      free(jptr->label);
      jptr->label=NULL;
    }
  }
  jumplist->length=0;
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

/* this duplicates vlists */
char *vlist_dup(char *vlist){
int length;
char *tmp;
     length = vlist_len(vlist);
     EXT_MALLOC(tmp,length,MEMOOPS);
     memcpy(tmp,vlist,length);
     return(tmp);
}

/* this duplicates strings even if they are not terminated, uppercases it too */
char *dup_up_str(char *string, int length){
char *tmp;
char *ptr;
int i;
     EXT_MALLOC(tmp,length+1,MEMOOPS);
     for(ptr=tmp, i=0; i<length; i++,ptr++,string++){
       *ptr=toupper(*string);
     }
     *ptr='\0';
     return(tmp);
}

/* parse operations string into tokens.  clauses are separated by colons */
void parse_operations(MLNEXUS *matches, JLNEXUS *jumplist, ALNEXUS *autolist, OMNINEXUS *omni, char *operations){
char *atoken;
char  thedelim;
int   start;
int   length;
int   negate=0;
int   count=0;
ESNEXUS *alldata = omni->alldata;
int   actions[MYMAXACTIONS]; /* store sequence of mactions followed by an option offset (into alldata) */
MOPNEXUS *mn = &(matches->list[matches->pcount]);
STVNEXUS hold;
   jumplist->skip=0;  /* trap redundant jmp, skip operations */
   autolist->skip=0;  /* trap overlapping { }{ operations */
   atoken=strtok_variant(operations,&hold,OPERDELIMSTR,PARSE_ESCAPES,"",&thedelim,&start,&length);
   while(atoken){
     if(count>= MYMAXACTIONS - 2){ /* no room for actions from this token */
       insane2(INSFTLERR," too many actions on one line at:",operations);
     }
     count = add_action(matches, jumplist, autolist, omni, &(actions[0]),count, atoken, operations, length, &negate);
     atoken=strtok_variant(NULL,&hold,OPERDELIMSTR,PARSE_ESCAPES,"",&thedelim,&start,&length);
   }
   if(count){
       if(negate){  mn->false = alldata->slen; }
       else {       mn->true  = alldata->slen; }
       actions[count++] = DO_LISTEND;  /* No associated offset  */
       ESP_NEXTINTBOUNDARY(alldata);
       es_append_aidat(alldata,(char *)&actions[0],count*SOI,ALLDATAINC,MEMOOPS);
       if(jumplist->skip > 1){
         fprintf(stderr,"%s  Problem at -pm/-op expression %d\n",INSFTLERR,matches->pcount);
         insane2(INSFTLERR," more than one ^,brk, or # (skip) operator:",operations);
       }
   }
   /* a bit of sanity checking for -op, there should not be a False branch */
   if(mn->bits & MATCH_TRUE && mn->false){
     fprintf(stderr,"%s  Problem at -pm/-op expression %d\n",INSFTLERR,matches->pcount);
     insane2(INSFTLERR," -op or -pm 'm:' has unreachable operations in the FALSE branch:",operations);
   }
}

char *to_operations(int tagstate, char *src){
char *string;
char *sptr;
int   slen;
   slen     = strlen(src); 
   EXT_MALLOC(string,slen + 5,MEMOOPS); /* more than enough extra room for modifiers */
   sptr     = string;
   if(tagstate & TAG_NOT){
     *sptr++ = '!';
     *sptr++ = OPERDELIM;
   }
   strcpy(sptr,src);
   sptr    += slen;
   if(tagstate & TAG_NORESTART){
     *sptr++ = 'r';
     *sptr++ = '\0';
   }
   
   return(string);
}

char *to_pattern(int tagstate, char *src){
char *string;
char *sptr;
int   slen;
   slen = strlen(src); 
   EXT_MALLOC(string,slen + 5,MEMOOPS); /* more than enough extra room for modifiers */
   sptr     =string;
   *sptr++ = 's';
   if(tagstate & TAG_FRONT){     *sptr++ = '^'; }
   if(tagstate & TAG_END){       *sptr++ = '$'; }
   *sptr++ = ':';
   strcpy(sptr,src);
   return(string);
}

void make_matches(OMNINEXUS *omni, PMLNEXUS *prematches,
    MLNEXUS *b_matches, MLNEXUS *m_matches, MLNEXUS *a_matches, 
    int ifn, int tagstate, int tagtermstate, char *tag, char *tagterm){
int           i,j;
PREMOPNEXUS  *pmop;
PREMOPNEXUS  *cmop;
JLNEXUS      *jumplist;
ALNEXUS      *autolist;
char         *pattern;
char         *operations;
int           comlines=0;

  EXT_CALLOC(jumplist,1,sizeof(JLNEXUS),MEMOOPS);
  EXT_CALLOC(autolist,1,sizeof(ALNEXUS),MEMOOPS);
  pmop=prematches->list;
  i=0;
  /* SECT_COMMON 
  this marks a part of prematches that is loaded into BEFORE, MAIN,and AFTER ahead of
  the section specific comments.  Provides a place to put subroutines and such. */
  if(pmop->ms == IS_SECT && *pmop->pattern == SECT_COMMON){
    for(pmop++, i++; i<prematches->pcount; i++,pmop++){
      if(pmop->ms == IS_SUBS && pmop->var >= MYVARSMAX){
        insane(INSFTLERR," -ps# may not be used in the COMMON section");
      }
      else if(pmop->ms == IS_SECT){
        if(*pmop->pattern == SECT_COMMON){
          insane(INSFTLERR," unexpected section, expected BEFORE, MAIN or AFTER, saw COMMON");
        }
        break;
      }
    }
    comlines=i-1;
  }
  
  /* SECT_BEFORE */
  if(pmop->ms == IS_SECT && *pmop->pattern == SECT_BEFORE){
    if(comlines){  /* load common stuff ahead of BEFORE */
      for(j=1, cmop=&prematches->list[j]; j<=comlines; j++,cmop++){
         add_matches(b_matches, jumplist, autolist, omni, (int) cmop->var, cmop->pattern,cmop->second);
      }
    }
    free(pmop->pattern);  /* these are on the IS_SECT */
    free(pmop->second);
    for(pmop++, i++; i<prematches->pcount; i++,pmop++){
       if(pmop->ms == IS_SUBS){
         if(pmop->var < MYVARSMAX){
            add_subs(b_matches, (int) pmop->var, pmop->pattern, pmop->second);
         }
         else {
            insane(INSFTLERR," -ps# may not be used in the BEFORE section");
         }
       }
       else if(pmop->ms == IS_MATCH){
         add_matches(b_matches, jumplist, autolist, omni, (int) pmop->var, pmop->pattern,pmop->second);
       }
       else if(pmop->ms == IS_SECT){
         if(*pmop->pattern == SECT_BEFORE){
           insane(INSFTLERR," unexpected section, expected MAIN or AFTER, saw BEFORE");
         }
         break;
       }
       free(pmop->pattern);
       free(pmop->second);
    }
    b_matches->start=comlines + jump_resolve(jumplist, omni->alldata); /* resets to 0 length at the end */
    autolist->length  = 0; /* reset the autolist for the next section */
    autolist->counter = 0;
  }

  /* SECT_MAIN */
  if((i < prematches->pcount && (pmop->ms != IS_SECT || *pmop->pattern == SECT_MAIN))
     && comlines){  /* load common stuff ahead of MAIN */
    for(j=1, cmop=&prematches->list[j]; j<=comlines; j++,cmop++){
       add_matches(m_matches, jumplist, autolist, omni, (int) cmop->var, cmop->pattern,cmop->second);
    }
  }
  /* -if ALWAYS goes into main, even if there isn't anything else */
  if(tag){ /* convert to -pm format, if any ifs show up later, it is a fatal error */
    if(tagterm){
      pattern    = to_pattern(tagstate,tag);
      operations = to_operations(tagstate,"if+"); /* if forever */
      add_matches(m_matches, jumplist, autolist, omni, MYVARSMAX, pattern, operations);
      free(operations);
      free(pattern);

      pattern    = to_pattern(tagtermstate,tagterm);
      operations = to_operations(tagtermstate,"if-"); /* terminator */
      add_matches(m_matches, jumplist, autolist, omni, MYVARSMAX, pattern, operations);
    }
    else {
      pattern    = to_pattern(tagstate,tag);
      if(ifn){ operations = to_operations(tagstate,"ifc");  } /* if counts down */
      else {   operations = to_operations(tagstate,"if1");  } /* single if      */
      add_matches(m_matches, jumplist, autolist, omni, MYVARSMAX, pattern,operations);  /* if counts down */
    }
    free(operations);
    free(pattern);
    omni->ifstate |= IF_TAG; /* used to block any if statements from -pm later */
  }
  if(i < prematches->pcount && (pmop->ms != IS_SECT || *pmop->pattern == SECT_MAIN)){
    if(pmop->ms == IS_SECT){
      free(pmop->pattern);  /* these are on the IS_SECT */
      free(pmop->second);
      pmop++;
      i++;
    }
    for(;i<prematches->pcount;i++,pmop++){
       if(pmop->ms == IS_SUBS){
         add_subs(m_matches, (int) pmop->var, pmop->pattern, pmop->second);
       }
       else if(pmop->ms == IS_MATCH){
         add_matches(m_matches, jumplist, autolist, omni, (int) pmop->var, pmop->pattern,pmop->second);
       }
       else if(pmop->ms == IS_SECT){
         if(*pmop->pattern != SECT_AFTER){
           insane(INSFTLERR," unexpected section, expected AFTER, saw BEFORE or MAIN");
         }
         break;
       }
       free(pmop->pattern);
       free(pmop->second);
    }
    m_matches->start=comlines + jump_resolve(jumplist, omni->alldata); /* resets to 0 length at the end */
  }
  /* SECT_AFTER */
  if(i < prematches->pcount){  /* must be IS_SECT, no other way to get here */
    if(comlines){
      for(j=1, cmop=&prematches->list[j]; j<=comlines; j++,cmop++){
         add_matches(a_matches, jumplist, autolist, omni, (int) cmop->var, cmop->pattern,cmop->second);
      }
    }
    free(pmop->pattern);  /* these are on the IS_SECT */
    free(pmop->second);
    for(pmop++, i++; i<prematches->pcount; i++,pmop++){
       if(pmop->ms == IS_SUBS){
         if(pmop->var < MYVARSMAX){
            add_subs(a_matches, (int) pmop->var, pmop->pattern, pmop->second);
         }
         else {
            insane(INSFTLERR," -ps# may not be used in the AFTER section");
         }
       }
       else if(pmop->ms == IS_MATCH){
         add_matches(a_matches, jumplist, autolist, omni, (int) pmop->var, pmop->pattern,pmop->second);
       }
       else if(pmop->ms == IS_SECT){
         insane(INSFTLERR," unexpected -sect in AFTER section");
       }
       free(pmop->pattern);
       free(pmop->second);
    }
    a_matches->start=comlines + jump_resolve(jumplist, omni->alldata); /* resets to 0 length at the end */
    autolist->length  = 0; /* reset the autolist for the next section */
    autolist->counter = 0;
  }
  if(comlines){  /* load common stuff ahead of AFTER, free memory at this point  */
    for(j=0, cmop=&prematches->list[j]; j<=comlines; j++,cmop++){
       free(cmop->pattern);
       free(cmop->second);
    }
  }
  free(prematches->list);
  free(prematches);
  jl_destroy(&jumplist);  /* release this memory */
  al_destroy(&autolist);  /* release this memory */
}

void process_command_line_args(int argc,char **argv, 
    PONEXUS *gbl_po,
    int *maxwidth,
    int *sc,int *ec,
    int *sr,int *er,
    int *rm,
    int *all,
    FIELDNEXUS  *gblparams,
    int *xc,
    int *xe,
    int *dbg,
    int *tagstate,
    int *tagtermstate,
    int *ifn,
    int *ifonly,
    int *ifeol,
    int *ifbol,
    char **eol,
    char **bol,
    char ***fmt,
    char ***var,
    char **po,
    char **tag,
    char **tagterm,
    char **iftermeol,
    char **iftermbol,
    char **fileeol,
    char **filebol,
    char **indl,
    int  *samelines,
    int  *linenumber,
    int  *linelength,
    int  *linetokens,
    int  *merge,
    int  *template,
    int  *handlenull,
    int  *crok,
    MLNEXUS    *subs,
    PMLNEXUS   *prematches){
    
int           numarg=0;
int           nc,nr;
int           scset=NO;
int           ncset=NO;
int           ecset=NO;
int           dset=NO;
int           fromstdin=0;
int           fromstdout=0;
char         *delimitv=NULL;
char         *file_string=NULL;
ESNEXUS      *label;  /* used by -lbl, -pm[N], -psN, -op*/
/* abbreviations on -cmd only allow these abbreviations, which
make for a more readable script:
  {,}{,}  for -lbl {,}{,}
  c*      for -lbl c*
  =*      for -lbl =*
  m[N]    for -pm[N]
  sN      for -psN
  o       for -op
*/
int           abbrev=0;  
unsigned char hnsubs;
int           hnset=NO;
char         *pctemp=NULL;
char         *ctmp=NULL;
int           numfmt=0;
int           it;
char        **largv;
FILE         *cmd=NULL;
int           pocount=0;  
int           pscount=0;
char         *p1;
char         *p2;
int           binary_output=0;

  if(argc <2){ /* no arguments */
    emit_help();
  }
  
  *maxwidth=MYMAXSTRING;
  *xc=MYINIRANGES;
  *xe=MYINIFMT;
  *rm=ACTEXTRACT;
  gbl_po->parse_options =  0;  /* always cleared, may be overwritten below */
  gbl_po->dllen         = -1;  /* so we can tell if it has been set or not */
  gbl_po->mdllen        = -1;  /* so we can tell if it has been set or not */
  gbl_po->delimit       = NULL;
  gbl_po->mdelimit      = NULL;
  *dbg=NO;
  *sc=1;
  gblparams->ttype       = MODENONE; /* ==MODECHAR = use characters */
  gblparams->sort        = SORTNONE;
  gblparams->pad         = 0;
  gblparams->lpad        = PADNONE;
  gblparams->precision   = MYDEFPRECISION;
  gblparams->lprecision  = FPNONE;
  gblparams->ff          = FFNONE | NZNONE;
  gblparams->justify     = JUSTNONE;
  gblparams->trimify     = TRIMNONE;
  gblparams->casify      = CASENONE;
  gblparams->slashify    = SLASHNONE;
  gblparams->descify     = DESCNONE;
   /* the next one is harmless for character mode and is the right default for MT.  It is set here
      because there might be -mc -fmt '[mt:1,4]'.  -mc would imply DELIMNONE, but the op mt in 
      -fmt demands something else for ldelim.  Cannot set it to something else at [mt]
      because  [d-:mt:1,4] is allowed .  So the default must be set here to take effect much later.
      Note that if -d- is set on the command line then every [mt] which is to be delimited must have
      that set locally.  */
  gblparams->ldelim      = DELIMTOK;
  gblparams->delim       =  ':';     /* will be replaced if DELIMVAL is specified below */
  gblparams->ecc         =  '\\';      /* will be replaced if ecc is specified below */
  gblparams->eccwhich    =  ECCPDEFAULT;
  gblparams->lrs         = RSNONE;
  gblparams->lrcd        = RCDNONE;
  gblparams->lrcs        = RCSNONE;
  gblparams->lrtd        = RTDNONE;
  gblparams->lrts        = RTSNONE;
  gblparams->lps         = PSNONE;
  gblparams->ersstring   = NULL;
  gblparams->rcd         = NULL;
  gblparams->rcs         = NULL;
  gblparams->rtd         = NULL;
  gblparams->rts         = NULL;
  gblparams->ps          = 0;
  gblparams->vlist       = NULL;
  *ec=TO_END;
   nc=MYMAXSTRING;
  *sr=1;
  *er=0;
   nr=0;
  *all=NO;  /* do not emit unchanged rows beyond row limits */
  *tag=NULL;
  *tagterm=NULL,
  *iftermeol=NULL;
  *iftermbol=NULL;
  *fileeol=NULL;
  *filebol=NULL;
  *tagstate=TAG_NONE;
  *tagtermstate=TAG_NONE;
  *ifn=0;
  *ifonly=NO;
  *ifeol=NO;
  *ifbol=NO;
  *indl=NULL;
  *merge=0;
  *samelines=NO;   /* do not require the same number of lines in each input file */
  *linenumber=NO;  /* do not emit line numbers before each line */
  *linelength=NO;  /* do not emit line length before each line */
  *linetokens=NO;  /* do not emit count of tokens before each line */
  EXT_MALLOC(*eol,2*SOC,MEMOOPS);
  (*eol)[0] = '\n';
  (*eol)[1] = '\0';
  EXT_MALLOC(*bol,SOC,MEMOOPS);
  (*bol)[0] = '\0';
  *template =0;
  *handlenull=HNULL_RETAIN;
  *handlenull=YES;
  *crok=YES;
  prematches->pcount=0;
  label=es_create(LBLINC,MEMOOPS);
  largv=argv;  /* first pass, all options from command line */

  while(1){  /* command line or command from file input */  
    while( ++numarg < argc){
      if( (lcl_strcasecmp(largv[numarg], "-h")==0)     ||
          (lcl_strcasecmp(largv[numarg], "--h")==0)    ||
          (lcl_strcasecmp(largv[numarg], "-?")==0)     ||
          (lcl_strcasecmp(largv[numarg], "--?")==0)    ||
          (lcl_strcasecmp(largv[numarg], "-help")==0)  ||
          (lcl_strcasecmp(largv[numarg], "--help")==0) ){
        emit_help();
      }
      else if( (lcl_strcasecmp(largv[numarg], "-hcols")==0) ||
               (lcl_strcasecmp(largv[numarg], "-hfmt")==0) ){
        emit_help_fmt();
      }
      else if(lcl_strcasecmp(largv[numarg], "-hmath")==0){
        emit_help_math();
      }
      else if(lcl_strcasecmp(largv[numarg], "-hpat")==0){
        emit_help_pat();
      }
      else if(lcl_strcasecmp(largv[numarg], "-hpo")==0){
        emit_help_po();
      }
      else if(lcl_strcasecmp(largv[numarg], "-hvar")==0){
        emit_help_var();
      }
      else if(lcl_strcasecmp(largv[numarg], "-hcmd")==0){
        emit_help_cmd();
      }
      else if( (lcl_strcasecmp(largv[numarg], "-hexamples")==0)){
        emit_help_examples();
      }
      else if(lcl_strcasecmp(largv[numarg], "-i")==0){
        (void)fprintf(stderr,"Version:   %s\n",EXVERSTRING);
        (void)fprintf(stderr,"bugs to:   %s\n",BUGSTRING);
        (void)fprintf(stderr,"Copyright: %s\n",COPYSTRING);
        (void)fprintf(stderr,"           %s\n",COPYSTRING2);
        (void)fprintf(stderr,"License:   %s\n",LICSTRING);
        exit(EXIT_SUCCESS);
      }
      else if(lcl_strcasecmp(largv[numarg], "-wl")==0){
        setiposnumeric(maxwidth,&numarg,argc,largv,"-wl");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dbg")==0){
        *dbg |= DBGCOL;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dbgv")==0){
        *dbg |= DBGVAR;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dbgp")==0){
        *dbg |= DBGIFP;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dbgm")==0){
        *dbg |= DBGM;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dbgs")==0){
        *dbg |= DBGSTACK;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dbga")==0){
        *dbg |= DBGAL;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-all")==0){
        *all=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-s")==0){
        gbl_po->parse_options |= SD;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dq")==0){
        gbl_po->parse_options |= DQ;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dqs")==0){
        gbl_po->parse_options |= DQ;
        gbl_po->parse_options |= DQS;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-esc")==0){
        gbl_po->parse_options |= ESCAPES;
        continue;
      }
      else if(lcl_strncasecmp(largv[numarg], "-po",3)==0){  /* must be numbered sequentially */
        if(pocount>MYPOSMAX)insane(INSFTLERR," too many -po statements");
        if(strlen(largv[numarg])>4 || (pocount && (strlen(largv[numarg])!=4)) ){
           insane2(INSFTLERR," unrecognized or out of order command line argument: ",largv[numarg]);
        }
        it=0; /* for po0 as po case */
        if(pocount==0){
          if(strlen(largv[numarg])==4){ it=TOPOOFF(largv[numarg][3]); }/* -po0  that's OK*/
        }
        else if(pocount>0){ 
          it=TOPOOFF(largv[numarg][3]);
        }
        if(it != pocount)insane(INSFTLERR," -po statements not numbered sequentially");
        numarg++;
        po[it]=dup_str(largv[numarg],strlen(largv[numarg]));
        pocount++;
        continue;
      }
      else if(lcl_strncasecmp(largv[numarg], "-ps",3)==0){ 
        if(strlen(largv[numarg]) == 4){  /* -psN ? */
          it=TOVAROFF(largv[numarg][3]);
          if(it>=0 && it <MYVARSMAX){
            add_prematches(prematches,IS_SUBS,it,&numarg,argc,largv,label);
            continue;
          }
        }
        if(pscount>MYPSSMAX)insane(INSFTLERR," too many -ps statements");
        if(strlen(largv[numarg])>4 || (pscount && (strlen(largv[numarg])!=4)) ){
           insane2(INSFTLERR," unrecognized or out of order command line argument: ",largv[numarg]);
        }
        it=0; /* for ps0 as ps case */
        if(pscount==0){
          if(strlen(largv[numarg])==4){ it=TOPSOFF(largv[numarg][3]); }/* -ps0  that's OK*/
        }
        else if(pscount>0){ 
          it=TOPSOFF(largv[numarg][3]);
        }
        if(it != pscount)insane(INSFTLERR," -ps statements not numbered sequentially");
        numarg++;
        p1=dup_str(largv[numarg],strlen(largv[numarg]));
        numarg++;
        p2=dup_str(largv[numarg],strlen(largv[numarg]));
        add_subs(subs,MYVARSMAX,p1,p2);
        free(p1);
        free(p2);
        pscount++;
        gblparams->lps = PSVAL;
        gblparams->ps  = 0; /* default, use PS 0*/
        continue;
      }
      else if(lcl_strncasecmp(largv[numarg], "-pm",3)==0){ 
        if(strlen(largv[numarg]) == 3){ it=MYVARSMAX; }
        else {
          it=TOVAROFF(largv[numarg][3]);
          if(it<0 || it >=MYVARSMAX)insane(INSFTLERR," N invalid in -pmN, only A-Z are allowed");
        }
        add_prematches(prematches,IS_MATCH,it,&numarg,argc,largv,label);
        continue;
      }
      else if(lcl_strncasecmp(largv[numarg], "-op",3)==0){ 
        if(strlen(largv[numarg]) == 3){ it=MYVARSMAX; }
        else {
          it=TOVAROFF(largv[numarg][3]);
          if(it<0 || it >=MYVARSMAX)insane(INSFTLERR," N invalid in -pmN, only A-Z are allowed");
        }
        add_prematches(prematches,IS_OPER,it,&numarg,argc,largv,label);
        continue;
      }
      else if(lcl_strncasecmp(largv[numarg], "-sect",5)==0){ 
        if(ESP_CLEN(label)){/* dangling label, add an -op for it */
          add_prematch_lbl_op(prematches,label);
        }
        add_prematches(prematches,IS_SECT,MYVARSMAX,&numarg,argc,largv,label);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-cmd")==0){
        numarg++;
        if(strcmp(largv[numarg],"-")==0){
          cmd=stdin;
        }
        else {
          cmd=fopen(largv[numarg],"r");
          if(cmd==NULL)insane2(INSFTLERR," could not open command file: ",largv[numarg]);
        }
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-in")==0){
        /* open as many input files as are present up to MAXINFILE */
        file_string=strtok(largv[++numarg],",");
        for(infiles=0; infiles<MAXINFILE; infiles++){
          if(file_string==NULL)break;
          if(strcmp(file_string,"-")==0){
            if(fromstdin)insane(INSFTLERR," only one input stream may come from stdin");
            lcl_stdin[infiles]=stdin;
            fromstdin=1;
          }
          else {
            lcl_stdin[infiles]=fopen(file_string,"r");
          }
          if(lcl_stdin[infiles]==NULL)insane2(INSFTLERR," could not open input file: ",file_string);
          file_string=strtok(NULL,",");
        }
        if(infiles==0)insane(INSFTLERR," no valid input files");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-out")==0){
        /* open as many output files as are present up to MAXINFILE */
        file_string=strtok(largv[++numarg],",");
        for(outfiles=0;outfiles<MAXOUTFILE;outfiles++){
          if(file_string==NULL)break;
          if(strcmp(file_string,"-")==0){
            if(fromstdout)insane(INSFTLERR," only one output stream may go to stdout");
            if(binary_output){
#ifdef MSCRTL
              lcl_stdout[outfiles++] = stdout;
              setmode(fileno(stdout),O_BINARY);   /* for windows environments with a cruddy C RTL, ie, most of them */
#else /* MSCRTL */
              lcl_stdout[outfiles++]=freopen(0,"wb",stdout);
              if(!lcl_stdout[outfiles-1])insane(INSFTLERR," this platform does not support -b on stdout");
#endif /* MSCRTL */
            }
            else {
              lcl_stdout[outfiles]=stdout;
            }
            fromstdout=1;
          }
          else {
            if(binary_output){
              lcl_stdout[outfiles]=fopen(file_string,"wb");
            }
            else {
              lcl_stdout[outfiles]=fopen(file_string,"w");
            }
          }
          if(lcl_stdout[outfiles]==NULL)insane2(INSFTLERR," could not open output file: ",file_string);
          file_string=strtok(NULL,",");
        }
        if(outfiles==0)insane(INSFTLERR," no valid output files");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-rm")==0){
        if(*rm!=ACTEXTRACT)insane(INSFTLERR," conflicting extract/remove/in situ commands");
        *rm=ACTREMOVE;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-is")==0){
        if(*rm!=ACTEXTRACT)insane(INSFTLERR," conflicting extract/remove/in situ commands");
        *rm=ACTINSITU;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-crok")==0){
        *crok=NO;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-cl")==0){
        if(gblparams->casify != CASENONE)insane(INSFTLERR," conflicting case commands");
        gblparams->casify=CASELOWER;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-cu")==0){
        if(gblparams->casify!=CASENONE)insane(INSFTLERR," conflicting case commands");
        gblparams->casify=CASEUPPER;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-cf")==0){
        if(gblparams->casify!=CASENONE)insane(INSFTLERR," conflicting case commands");
        gblparams->casify=CASEFIRST;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ba")==0){
        if(gblparams->slashify!=SLASHNONE)insane(INSFTLERR," conflicting backslash commands");
        gblparams->slashify=SLASHALL;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-b2")==0){
        if(gblparams->slashify!=SLASHNONE)insane(INSFTLERR," conflicting backslash commands");
        gblparams->slashify=SLASHREST;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-bs")==0){
        if(gblparams->slashify!=SLASHNONE)insane(INSFTLERR," conflicting backslash commands");
        gblparams->slashify=SLASHUNIX;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ecc")==0){
        setstring(&pctemp,&numarg,argc,largv,"-ecc");
        fixupescapes(pctemp);
        if(strlen(pctemp)>1)insane(INSFTLERR," escape must be a single character, not a string");
        gblparams->ecc=*pctemp;
        gblparams->eccwhich=ECCSDEFAULT;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-fff")==0){
        if((gblparams->ff & FFMASKEF) !=FFNONE)insane(INSFTLERR," conflicting ff commands");
        gblparams->ff |= FFFLOAT;      /* pad sets process increment, not ff */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ffe")==0){
        if((gblparams->ff & FFMASKEF) !=FFNONE)insane(INSFTLERR," conflicting ff commands");
        gblparams->ff |= FFEXP;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ffd")==0){
        if((gblparams->ff & FFMASKEF) !=FFNONE)insane(INSFTLERR," conflicting ff commands");
        gblparams->ff |= FFDEC;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ffu")==0){
        if((gblparams->ff & FFMASKEF) !=FFNONE)insane(INSFTLERR," conflicting ff commands");
        gblparams->ff |= FFDEC | FFUNS;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ffx")==0){
        if((gblparams->ff & FFMASKEF) !=FFNONE)insane(INSFTLERR," conflicting ff commands");
        gblparams->ff |= FFHEX | FFUNS;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ffo")==0){
        if((gblparams->ff & FFMASKEF) !=FFNONE)insane(INSFTLERR," conflicting ff commands");
        gblparams->ff |= FFOCT | FFUNS;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-nz")==0){
        gblparams->ff |= NZNZ;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-jl")==0){
        if(gblparams->justify!=JUSTNONE)insane(INSFTLERR," conflicting justify commands");
        gblparams->justify=JUSTLEFT;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-jr")==0){
        if(gblparams->justify!=JUSTNONE)insane(INSFTLERR," conflicting justify commands");
        gblparams->justify=JUSTRIGHT;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-jc")==0){
        if(gblparams->justify!=JUSTNONE)insane(INSFTLERR," conflicting justify commands");
        gblparams->justify=JUSTCENTER;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-trl")==0){
        if(gblparams->trimify!=TRIMNONE)insane(INSFTLERR," conflicting trim commands");
        gblparams->trimify=TRIMLEFT;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-trr")==0){
        if(gblparams->trimify!=TRIMNONE)insane(INSFTLERR," conflicting trim commands");
        gblparams->trimify=TRIMRIGHT;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-trb")==0){
        if(gblparams->trimify!=TRIMNONE)insane(INSFTLERR," conflicting trim commands");
        gblparams->trimify=TRIMLEFT | TRIMRIGHT ;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-trc")==0){
        if(gblparams->trimify!=TRIMNONE)insane(INSFTLERR," conflicting trim commands");
        gblparams->trimify=TRIMLEFT | TRIMRIGHT | TRIMCOMPRESS;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-mdl")==0){
        setstring(&(gbl_po->mdelimit),&numarg,argc,largv,"-mdl");
        fixupescapes(gbl_po->mdelimit);
        gbl_po->mdllen=strlen(gbl_po->mdelimit);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-indl")==0){
        setstring(indl,&numarg,argc,largv,"-indl");
        fixupescapes(*indl);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-d-")==0){
        if(dset==YES)insane(INSFTLERR," conflicting or repeated -d* commands");
        dset=YES;
        gblparams->ldelim=DELIMNONE;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dv")==0){
        if(dset==YES)insane(INSFTLERR," conflicting or repeated -d* commands");
        dset=YES;
        setstring(&delimitv,&numarg,argc,largv,"-dv");
        fixupescapes(delimitv);
        gblparams->delim=*delimitv;
        free(delimitv);
        gblparams->ldelim=DELIMVAL;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-dt")==0){
        if(dset==YES)insane(INSFTLERR," conflicting or repeated -d* commands");
        dset=YES;
        gblparams->ldelim=DELIMTOK;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-desc")==0){
        gblparams->descify=DESCFIELD;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-pd")==0){
        if(gblparams->lpad != PADNONE)insane(INSFTLERR," conflicting or repeated -pd and/or -fw commands");
        setiposnumeric(&(gblparams->pad),&numarg,argc,largv,"-pd");
        gblparams->lpad=PADFIELD;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-fw")==0){
        if(gblparams->lpad != PADNONE)insane(INSFTLERR," conflicting or repeated -pd and/or -fw commands");
        setiposnumeric(&(gblparams->pad),&numarg,argc,largv,"-fw");
        gblparams->pad = -gblparams->pad;
        gblparams->lpad=PADFIELD;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-fp")==0){
        if(gblparams->lprecision != FPNONE)insane(INSFTLERR," conflicting or repeated -fp commands");
        setinumeric(&(gblparams->precision),&numarg,argc,largv,"-fp");
        if(gblparams->precision < 0)insane(INSFTLERR," -fp value must be >= 0");
        gblparams->lprecision=FPFIELD;    /* process increments with ff  */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-n")==0){
        *linenumber=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ll")==0){
        *linelength=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-lt")==0){
        *linetokens=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-xc")==0){
        setiposnumeric(xc,&numarg,argc,largv,"-xc");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-xe")==0){
        setiposnumeric(xe,&numarg,argc,largv,"-xe");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-sc")==0){
        setinumeric(sc,&numarg,argc,largv,"-sc");
        scset=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ec")==0){
        setinumeric(ec,&numarg,argc,largv,"-ec");
        ecset=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-nc")==0){
        setiposnumeric(&nc,&numarg,argc,largv,"-nc");
        ncset=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-sr")==0){
        setiposnumeric(sr,&numarg,argc,largv,"-sr");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-er")==0){
        setiposnumeric(er,&numarg,argc,largv,"-er");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-nr")==0){
        setiposnumeric(&nr,&numarg,argc,largv,"-nr");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-merge")==0){
        if(*merge != 0)insane(INSFTLERR," only a single -merge or -unmerge may be used");
        setiposnumeric(merge,&numarg,argc,largv,"-merge");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-unmerge")==0){
        if(*merge != 0)insane(INSFTLERR," only a single -merge or -unmerge may be used");
        setiposnumeric(merge,&numarg,argc,largv,"-unmerge");
        *merge = -(*merge);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-template")==0){
        setiposnumeric(template,&numarg,argc,largv,"-template");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-mt")==0){
        /* for tokens there must be a post process action list because something must
           be done if the specified range exceeds the input data, which cannot be known
           until run time. */
        gblparams->ttype=MODETOK;
        if(dset==NO)gblparams->ldelim=DELIMTOK;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-mc")==0){
        gblparams->ttype=MODECHAR;  /* this does not go in the post process action list */
        gblparams->ldelim=DELIMNONE;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-sortas")==0){
        if(gblparams->sort != SORTNONE)insane(INSFTLERR," use only one -sortxx option");
        gblparams->sort=SORTAS;   /* this does not go in the post process action list */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-sortds")==0){
        if(gblparams->sort != SORTNONE)insane(INSFTLERR," use only one -sortxx option");
        gblparams->sort=SORTDS;   /* this does not go in the post process action list */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-sortac")==0){
        if(gblparams->sort != SORTNONE)insane(INSFTLERR," use only one -sortxx option");
        gblparams->sort=SORTAC;   /* this does not go in the post process action list */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-sortdc")==0){
        if(gblparams->sort != SORTNONE)insane(INSFTLERR," use only one -sortxx option");
        gblparams->sort=SORTDC;   /* this does not go in the post process action list */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-sortan")==0){
        if(gblparams->sort != SORTNONE)insane(INSFTLERR," use only one -sortxx option");
        gblparams->sort=SORTAN;   /* this does not go in the post process action list */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-sortdn")==0){
        if(gblparams->sort != SORTNONE)insane(INSFTLERR," use only one -sortxx option");
        gblparams->sort=SORTDN;   /* this does not go in the post process action list */
      }
      else if(lcl_strcasecmp(largv[numarg], "-dl")==0){
        setstring(&(gbl_po->delimit),&numarg,argc,largv,"-dl");
        fixupescapes(gbl_po->delimit);
        gbl_po->dllen=strlen(gbl_po->delimit);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-eoc")==0){
        insane(INSFTLERR," -eoc may only be used in a -cmd file");
      }
      else if(lcl_strcasecmp(largv[numarg], "-eqlen")==0){
        *samelines=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-hnr")==0){
        /*default value is HNULL_RETAIN, this line is just here to detect conflicting -hn params */
        if(hnset)insane(INSFTLERR," select only one of -hnr, -hnd, -hns, or -hnsubs");
        hnset=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-hnd")==0){
        if(hnset)insane(INSFTLERR," select only one of -hnr, -hnd, -hns, or -hnsubs");
        hnset=YES;
        *handlenull=HNULL_DELETE;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-hns")==0){
        if(hnset)insane(INSFTLERR," select only one of -hnr, -hnd, -hns, or -hnsubs");
        hnset=YES;
        *handlenull=HNULL_SUBS;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-hnsubs")==0){
        if(hnset)insane(INSFTLERR," select only one of -hnr, -hnd, -hns, or -hnsubs");
        hnset=YES;
        setuchar(&hnsubs,&numarg,argc,largv,"-hnsubs");
        if(hnsubs=='\0')insane(INSFTLERR," select -hnsubs may not reduce to the NULL character");
        *handlenull=hnsubs;  /* force this, so that -hns is not needed with -hnsubs */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-if")==0){
        setstring(tag,&numarg,argc,largv,"-if");
        fixuptag(*tag,tagstate);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ifnorestart")==0){
        *tagstate |= TAG_NORESTART;
        fixuptag(*tag,tagstate);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ifterm")==0){
        setstring(tagterm,&numarg,argc,largv,"-ifterm");
        fixuptag(*tagterm,tagtermstate);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-iftermeol")==0){
        setstring(iftermeol,&numarg,argc,largv,"-iftermeol");
        fixupescapes(*iftermeol);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-iftermbol")==0){
        setstring(iftermbol,&numarg,argc,largv,"-iftermbol");
        fixupescapes(*iftermbol);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-fileeol")==0){
        setstring(fileeol,&numarg,argc,largv,"-fileeol");
        fixupescapes(*fileeol);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-filebol")==0){
        setstring(filebol,&numarg,argc,largv,"-filebol");
        fixupescapes(*filebol);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ifn")==0){
        setiposnumeric(ifn,&numarg,argc,largv,"-ifn");
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ifonly")==0){
        *ifonly=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ifeol")==0){
        *ifeol=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-ifbol")==0){
        *ifbol=YES;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-eol")==0){
        setstring(eol,&numarg,argc,largv,"-eol");
        fixupescapes(*eol);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-bol")==0){
        setstring(bol,&numarg,argc,largv,"-bol");
        fixupescapes(*bol);
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-b")==0){
        binary_output=1;  /* this may or may not work on any given platform */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-rs")==0){
        setstring(&(gblparams->ersstring),&numarg,argc,largv,"-rs");
        fixupescapes(gblparams->ersstring); 
        gblparams->lrs=RSVAL;  /* delay incrementing process, only do so global mode is token */
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-rcds")==0){
        if(gblparams->lrcd!=RCDNONE)insane(INSFTLERR," multiple -rcds or -rcdc");
        setstring(&(gblparams->rcd),&numarg,argc,largv,"-rcds");
        fixupescapes(gblparams->rcd);
        gblparams->lrcd=RCDVAL;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-rcdc")==0){
        if(gblparams->lrcd!=RCDNONE)insane(INSFTLERR," multiple -rcds or -rcdc");
        setstring(&(gblparams->rcd),&numarg,argc,largv,"-rcdc");
        fixupescapes(gblparams->rcd);
        gblparams->lrcd=RCDVALC;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-rcss")==0){
        if(gblparams->lrcs!=RCSNONE)insane(INSFTLERR," multiple -rcss");
        setstring(&(gblparams->rcs),&numarg,argc,largv,"-rcss");
        fixupescapes(gblparams->rcs);
        gblparams->lrcs=RCSVAL;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-rtds")==0){
        if(gblparams->lrtd!=RTDNONE)insane(INSFTLERR," multiple -rtds or -rtdc");
        setstring(&(gblparams->rtd),&numarg,argc,largv,"-rtds");
        fixupescapes(gblparams->rtd);
        gblparams->lrtd=RTDVAL;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-rtdc")==0){
        if(gblparams->lrtd!=RTDNONE)insane(INSFTLERR," multiple -rtds or -rtdc");
        setstring(&(gblparams->rtd),&numarg,argc,largv,"-rtdc");
        fixupescapes(gblparams->rtd);
        gblparams->lrtd=RTDVALC;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-rtss")==0){
        if(gblparams->lrts!=RTSNONE)insane(INSFTLERR," multiple -rtss/-rtsv");
        setstring(&ctmp,&numarg,argc,largv,"-rtss");
        fixupescapes(ctmp);
        EXT_MALLOC(gblparams->rts, 2+strlen(ctmp), MEMOOPS);
        *gblparams->rts = MYVARSMAX; /* indicates an immediate string */
        strcpy(&gblparams->rts[1],ctmp);
        free(ctmp);
        gblparams->lrts=RTSVAL;
        continue;
      }
     else if(lcl_strncasecmp(largv[numarg], "-rtsv",5)==0){
        if(gblparams->lrts!=RTSNONE)insane(INSFTLERR," multiple -rtss/-rtsv");
        it=TOVAROFF(largv[numarg][5]);
        if(it<0 || it >MYVARSMAX-1)insane(INSFTLERR," X invalid in -v?, only A-Z are allowed");
        gblparams->rts  = dup_str("",1);
        *gblparams->rts = it;
        gblparams->lrts=RTSVAR;
        continue;
      }
      else if(lcl_strcasecmp(largv[numarg], "-cols")==0 ||
              lcl_strcasecmp(largv[numarg], "-fmt")==0){  /* pick up fmt0 with simple name*/
        if(*fmt[0])insane(INSFTLERR," -cols and/or -fmt/-fmt0 entered more than once");
        if(numfmt)insane(INSFTLERR," -cols and/or -fmt/-fmt0 must be declared before other -fmt");
        numfmt++;
        setstring(&((*fmt)[0]),&numarg,argc,largv,largv[numarg]);
        continue;
      }
      else if(lcl_strncasecmp(largv[numarg], "-fmt",4)==0){
        it=largv[numarg][4] -'0';
        if(it<0 || it >9)insane(INSFTLERR," X invalid in -fmtX, only 0-9 are allowed");
        if((*fmt)[it])insane(INSFTLERR," -fmtX entered more than once for some X");
        if(numfmt != it)insane(INSFTLERR," -fmtX must be entered sequentially");
        numfmt++;
        setstring(&((*fmt)[it]),&numarg,argc,largv,largv[numarg]);
        continue;
      }
      else if(lcl_strncasecmp(largv[numarg], "-v",2)==0){
        it=TOVAROFF(largv[numarg][2]);
        if(it<0 || it >MYVARSMAX-1)insane(INSFTLERR," X invalid in -v?, only A-Z are allowed");
        if((*var)[it])insane(INSFTLERR," -v? entered more than once for some ?");
        setstring(&((*var)[it]),&numarg,argc,largv,largv[numarg]);
        continue;
      }
      else {
         if(abbrev){
           switch(tolower(*largv[numarg])){
             case '{':
             case 'c':
             case '=':
               if(ESP_CLEN(label))es_strcat(label,OPERDELIMSTR,1,LBLINC,MEMOOPS);
               es_strcat(label,largv[numarg],strlen(largv[numarg]),LBLINC,MEMOOPS);
               break;
             case '}':
               if(ESP_CLEN(label))es_strcat(label,OPERDELIMSTR,1,LBLINC,MEMOOPS);
               es_strcat(label,largv[numarg],strlen(largv[numarg]),LBLINC,MEMOOPS);
               if(label->string[ESP_CLEN(label)-1]==';'){
                  /* }; generates an empty op to attach itself to, so that it doesn't run
                     into a following { on the next line, because  };{;whatever is invalid.*/
                 add_prematch_lbl_op(prematches,label);
               }
               break;
             case 'm':
               if(strlen(largv[numarg]) == 1){ it=MYVARSMAX; }
               else {
                 it=TOVAROFF(largv[numarg][1]);
                 if(it<0 || it >=MYVARSMAX)insane(INSFTLERR," N invalid in -pmN, only A-Z are allowed");
               }
               add_prematches(prematches,IS_MATCH,it,&numarg,argc,largv,label);
               break;
             case 's':
               it=TOVAROFF(largv[numarg][1]);
               if(it<0 || it >=MYVARSMAX)insane(INSFTLERR," N invalid in -psN, only A-Z are allowed");
               add_prematches(prematches,IS_SUBS,it,&numarg,argc,largv,label);
               break;
             case 'o':
               if(strlen(largv[numarg]) == 1){ it=MYVARSMAX; }
               else {
                 it=TOVAROFF(largv[numarg][1]);
                 if(it<0 || it >=MYVARSMAX)insane(INSFTLERR," N invalid in -pmN, only A-Z are allowed");
               }
               add_prematches(prematches,IS_OPER,it,&numarg,argc,largv,label);
               break;
             default:
           insane2(INSFTLERR," on command line.  Use the -h flag to list options. Not recognized ",largv[numarg]);
           }
         }
         else {
           insane2(INSFTLERR," on command line.  Use the -h flag to list options. Not recognized ",largv[numarg]);
         }
      }
    }

    if(argv!=largv){
      if(ESP_CLEN(label)){/* dangling label, add an -op for it */
        add_prematch_lbl_op(prematches,label);
      }
      /* release the largv memory */
      for(it=0;it<argc;it++){ free(largv[it]); }
      free(largv);
      
      break;  /* exit on second pass, after reading commands from a file */
    }
    else {
      if(cmd){ 
        argc=fetch_commands(cmd,&largv);
        if(cmd!=stdin)fclose(cmd);
        cmd=NULL;
        numarg=-1;  /* the new argv has args from 0, the original had the calling command there */
        abbrev=1;  /* abbreviations are OK */
       }  /* do a second pass using these args */
      else { break; }        /* exit on first pass if no -cmd */
    }
  }/* command line, file input */
    
  /* sanity checking */
  
  
  /* fmt implies no regular specification of columns */
  if(!infiles){  lcl_stdin[ infiles++]  = stdin; }
  if(!outfiles){
     if(binary_output){
#ifdef MSCRTL
       lcl_stdout[outfiles++] = stdout;
       setmode(fileno(stdout),O_BINARY);   /* for windows environments with a cruddy C RTL, ie, most of them */
#else /* MSCRTL */
       lcl_stdout[outfiles++]=freopen(0,"wb",stdout);
       if(!lcl_stdout[outfiles-1])insane(INSFTLERR," this platform does not support -b on stdout");
#endif /* MSCRTL */
     }
     else {
       lcl_stdout[outfiles++] = stdout;
     }
  }
  if(numfmt){
    if( ncset == YES)insane(INSFTLERR," both -fmt and -nc present on the command line");
    if( ecset == YES)insane(INSFTLERR," both -fmt and -ec present on the command line");
    if( scset == YES)insane(INSFTLERR," both -fmt and -sc present on the command line");
    if( *rm != ACTEXTRACT)insane(INSFTLERR," -fmt and -is or -rm present on the command line");
  }

  if(ncset == YES){
    if(ecset == YES){
       insane(INSFTLERR," both -ec and -nc present on the command line");
    }
    else {
       if(*sc>0){  *ec = *sc + nc - 1;  }
       else     {  *ec = nc;            }
    }
  } /* do sanity checking on sc/ec later */
  if(nr != 0){
    if(*er != 0){
       insane(INSFTLERR," both -er and -nr present on the command line");
    }
    else {
       *er = *sr + nr - 1;
    }
  }
  else{
    if(*er != 0 && *er < *sr)insane(INSFTLERR," ending row less than starting row");
  }
  if( *ec > *maxwidth)insane(INSFTLERR," last column specified by -ec, -sc, -nc is beyond -wl limit");
  
  if(gblparams->ttype==MODECHAR && numfmt==0){
    if(gbl_po->parse_options)insane(INSFTLERR," -po,-s,-esc,-dq, or -dqs specified in character/column mode");
    if(gbl_po->dllen > 0)insane(INSFTLERR," -dl specified in character/column mode");
  }
  if(*tag==NULL && *tagterm!=NULL)insane(INSFTLERR," -ifterm specified without -if");
  if(*ifn!=0    && *tagterm!=NULL)insane(INSFTLERR," both -ifn and -ifterm specified");
  /* no checks when ifeol ifbol iftermbol iftermbol for -if, these are applied also for
     if logic through pm[N] and that won't be known for a long time.  Worst case these
     are specified and never used. */
 
  /* default delimiters are space, column, tab if nothing else was specified */
  if(gbl_po->dllen == -1){
    gbl_po->delimit = dup_str(" :\t",3);
    gbl_po->dllen = strlen(gbl_po->delimit);
  }
  if(gbl_po->mdllen == -1){ 
     if(*merge < 0){ /* unmerge MUST have a nonzero delimiter, use -dl if -mdl not set */
       gbl_po->mdelimit = dup_str(gbl_po->delimit,strlen(gbl_po->delimit));
       gbl_po->mdllen = strlen(gbl_po->mdelimit);
     }
     else  {
       gbl_po->mdllen = 0;
     }
  } 

  if(gblparams->lrcs == RCSVAL){
    if(gblparams->lrcd != RCDVAL && gblparams->lrcd != RCDVALC)insane(INSFTLERR," -rcss specified without -rcds");
    if(strlen(gblparams->rcs) != strlen(gblparams->rcd))insane(INSFTLERR," length mismatch: -rcs -rcd");
    if(strlen(gblparams->rcs) == 0)insane(INSFTLERR,"  -rcs may not be an empty string");
  }
  if((gblparams->lrcd == RCDVAL || gblparams->lrcd == RCDVALC) && 
     strlen(gblparams->rcd) == 0)insane(INSFTLERR," -rcd may not be an empty string");

  if(gblparams->lrts == RTSVAL){
    if(gblparams->lrtd != RTDVAL && gblparams->lrtd != RTDVALC)insane(INSFTLERR," -rtss specified without -rtds");
    if(strlen(&gblparams->rts[1]) == 0)insane(INSFTLERR,"  -rtss may not be an empty string");
  }
  if((gblparams->lrtd == RTDVAL ||gblparams->lrtd == RTDVALC) && 
     strlen(gblparams->rtd) == 0)insane(INSFTLERR," -rtds may not be an empty string");
  
  if(*template>0){
     if(infiles!=2)insane(INSFTLERR," -template requires exactly two input files, the first being the template");
     if(*merge>0)insane(INSFTLERR," -template and -merge may not be used together");
  }
  es_destroy(&label);
}

/* read more command line options.
   The format is:
   -arg1[[ OPERAND [OPERAND]] -arg2 ] etc.
   No leading or trailing space.
   Operands are space or tab delimited and may use double quotes
     if they need to contain these characters.
   The argv memory allocated here is only released by the caller.
   If a line starts with _ the entire rest of the line is read verbatim
     in as a token.  This can be used to eliminate nasty quoting issues.
   Exits at the end of the file or on -eoc */
int fetch_commands(FILE *fp,char ***argv){
char **storage=NULL;
char  *rbuf=NULL;
int    argc=0;
size_t cterm=0;
int    sfg_status;
char  *atoken;
int    start,length;
char   thedelim;
int    ok=1;
STVNEXUS hold;

  
  EXT_MALLOC(storage,(MYMAXARGS*sizeof(char *)),MEMOOPS);
  EXT_MALLOC(rbuf,MYMAXCMD,MEMOOPS);
  while(ok){
    sfg_status = super_fgets(rbuf, MYMAXCMD, fp, &cterm, 0);
    if(sfg_status != 0){
      if(sfg_status & SFG_READERROR){
        insane(INSFTLERR," fatal read error during cmd processing");
      }
      if(sfg_status & SFG_BUFFER_FULL){
        insane(INSFTLERR," sum of input lines was wider than 8192");
      }
      if(sfg_status & SFG_EMBEDDED_NULL){
        insane(INSFTLERR," found embedded null characters in cmd input");
      }
      if(sfg_status & SFG_EOF){
        break;
      }
      if(sfg_status & SFG_CRLF){
        /* silently nip off the \r character if present on a CRLF */
        cterm--;
        rbuf[cterm]='\0';
      }
      cterm++; /* include the terminator */
      if(*rbuf=='_'){      storage[argc++]=dup_str(&rbuf[1],cterm-2); }
      else if(*rbuf=='#'){ continue;                                  }
      else {
        atoken=strtok_variant(rbuf,&hold," \t",PARSE_ESCAPES | PARSE_DBLQUOTES | PARSE_STRIPDQUOTES,"",&thedelim,&start,&length);
        while(atoken){
          if(lcl_strncasecmp(atoken, "-eoc",4)==0){
            ok=0;
            break;
          }
          if(lcl_strncasecmp(atoken, "##",2)==0)break; /* ignore rest of the line */
          if(lcl_strncasecmp(atoken, "-cmd",4)==0)insane(INSFTLERR," -cmd appeared inside a -cmd file");
          storage[argc++]=dup_str(&rbuf[start],length);
          atoken=strtok_variant(NULL,&hold," \t",PARSE_ESCAPES | PARSE_DBLQUOTES | PARSE_STRIPDQUOTES,"",&thedelim,&start,&length);
        }
      }
    }
  }
  *argv=storage;
  free(rbuf);     /* will never be used again */
  return(argc);
}


/* convert an lstr to LONG.  Returns 1 if success, 0 if failure.
Input string must be decimal and begin with +/-/ or digit.
No spaces are allowed before or after.
Assumes that overflow can be detected by a sign change.

WARNING, the ival which is passed must be long, do not do (long *) on an int variable, as this
will write over an adjoining variable, and valgrind will  NOT see it. */

int lstrtol(char *string,int length, long *ival){
long sum,lastsum;
int  i,thesign;

  thesign=1;
  for(sum=0,i=0; i<length; i++){
    lastsum=sum;
    sum=sum*10;
    if(sum < lastsum)return 0;
    switch (string[i]){
      case '+':
        if(i!=0)return 0;
        break;
      case '-':
        if(i!=0)return 0;
        thesign=-1;
        break;
      case '1':
        sum += 1;
        break;
      case '2':
        sum += 2;
        break;
      case '3':
        sum += 3;
        break;
      case '4':
        sum += 4;
        break;
      case '5':
        sum += 5;
        break;
      case '6':
        sum += 6;
        break;
      case '7':
        sum += 7;
        break;
      case '8':
        sum += 8;
        break;
      case '9':
        sum += 9;
        break;
      case '0':
        break;
      default:
        return 0;
    }
  }
  if(thesign != 1){  *ival = 0 - sum; }
  else            {  *ival = sum;     }
  return 1;
}


/* stores a series of Variable letters.  A->Z become 0->25, dash, if allowed,
is stored as 26.  EOL is EOVLIST.  (not \0 as in a normal string!!!!) This lets this
sort of string be used directly (almost) as an array index.  */
char *vlist_set(char **dst, int length, const char *src, int allowdash){
char *to;
const char *from;
int i;
char *message=NULL;

  if(length<1){
    message=wait_insane(INSFTLERR," empty Variable List");
  }
  else {
    EXT_MALLOC(*dst,length+1,MEMOOPS);
    for(to=*dst, from=src, i=0; i<length; i++,to++,from++){
      *to=TOVAROFF(*from);
      if(*to<0 || *to >= MYVARSMAX){
        if(*from=='-' && allowdash){ *to = MYVARSMAX; } /* convert */
        else {
          message=wait_insane2(INSFTLERR," variable reference not in allowed alphabet A-Z",src);
          break;
        }
      }
    }
    *to=EOVLIST;
  }
  return(message);
}
  
/* creates a variable list of length two and stores in it src and EOVLIST. */
void vlist_set1(char **dst, const char src){
char *to;
  EXT_MALLOC(to,2,MEMOOPS);
  *dst  = to;
  *to++ = src;
  *to   = EOVLIST;
}
        
/* Returns true if vlist contains the test character  */
int vlist_holds(const char *vlist, const char test){
int status=0;
  while(*vlist != EOVLIST){
    if(*vlist == test){ status=1; break; }
    vlist++;
  }
  return(status);
}
  
void vlist_show(FILE *fp, char *string){
  if(*string==EOVLIST){ fprintf(fp,"<EmptyVLIST>"); }
  else {
    for( ; *string != EOVLIST; string++){
      if(*string<MYVARSMAX){        fprintf(fp,"%c",FROMVAROFF(*string)); }
      else if(*string==MYVARSMAX){  fprintf(fp,"-");}
      else {
        insane(INSFTLPRGERR," corrupted vlist list in vlist_show");
      }
    }
  }
}          
int vlist_len(const char *src){  /* returns the length of a vlist, including the terminator */
int len;
  for(len=1; ; src++,len++){  if(*src==EOVLIST)break;  }
  return(len);
}

void classify_op(char *cmd, int *sc, int *nc, int *inc, FIELDNEXUS  *lclparams){

char *atoken;
char thedelim;
int  start,length,tcount;
char blah[]="+";
char dvtemp[MYMAXDV];
char ctemp[MYSHORTSTRING];
long ltemp;
int  use_ps;
int  where;
int  avar;
int  donerange=0;
int  make_vlist=0;
char *message=NULL;
STVNEXUS hold;

  *sc=0;
  *nc=0;
    
   /* default is to do an implicit '+:' at the beginning of the cmd string */

  atoken=blah;  /* This is a kludge to set all program defaults first*/
  thedelim=':';
  length=1;
  
  lclparams->source = SRCLINE; /* This is the default may be changed with v*** or =*** */
  /* must clear, as this is the only char pointer that the caller might test without
     it being set (otherwise) here.  */
  lclparams->vlist  = NULL;
  tcount=0;
  while(atoken != NULL){
    if(thedelim==':'){ /* modifier */
      if(     lstrcasecmp(atoken,length,"-",1)  == 0){
           if(tcount != 1)insane2(INSFTLERR," -fmt contains - out of order ",cmd);
           lclparams->ttype      = MODEPDEFAULT;
           lclparams->sort       = SORTPDEFAULT;
           lclparams->map        = 0;
           lclparams->justify    = JUSTNONE;
           lclparams->trimify    = TRIMNONE;
           lclparams->casify     = CASENONE;
           lclparams->slashify   = SLASHNONE;
           lclparams->descify    = DESCNONE;
           lclparams->eccwhich   = ECCPDEFAULT; /* anything, slashify none makes this irrelevant */
           lclparams->lpad       = PADNONE;
           lclparams->lprecision = FPNONE;
           lclparams->ff         = FFNONE | NZNONE;
           lclparams->ldelim     = DELIMNONE;
           lclparams->lrs        = RSNONE;
           lclparams->lps        = PSNONE;
           lclparams->lrcd       = RCDNONE;
           lclparams->lrcs       = RCSNONE;
           lclparams->lrtd       = RTDNONE;
           lclparams->lrts       = RTSNONE;
        } 
      else if(lstrcasecmp(atoken,length,"+",1)   == 0){
           if(tcount > 1)insane2(INSFTLERR," -fmt contains + out of order ",cmd);
           lclparams->ttype      = MODESDEFAULT;
           lclparams->sort       = SORTSDEFAULT;
           lclparams->map        = 0;
           lclparams->justify    = JUSTSDEFAULT;
           lclparams->trimify    = TRIMSDEFAULT;
           lclparams->casify     = CASESDEFAULT;
           lclparams->slashify   = SLASHSDEFAULT;
           lclparams->descify    = DESCSDEFAULT;
           lclparams->eccwhich   = ECCSDEFAULT;
           lclparams->lpad       = PADSDEFAULT;  /* default is to use any lpad from command line */
           lclparams->pad        = 0;
           lclparams->lprecision = FPSDEFAULT;
           lclparams->precision  = MYDEFPRECISION;
           lclparams->ff         = FFSDEFAULT;
           lclparams->ldelim     = DELIMSDEFAULT;
           lclparams->delim      = ':';
           lclparams->lrs        = PSSDEFAULT;
           lclparams->lps        = RSSDEFAULT;
           lclparams->lrcd       = RCDSDEFAULT;
           lclparams->lrcs       = RCSSDEFAULT;
           lclparams->lrtd       = RTDSDEFAULT;
           lclparams->lrts       = RTSSDEFAULT;
        } 
      else if(lstrcasecmp(atoken,length,"p",1)   == 0){
           if(tcount > 1)insane2(INSFTLERR," -fmt contains p out of order ",cmd);
           lclparams->ttype      = MODEPDEFAULT;
           lclparams->sort       = SORTPDEFAULT;
           lclparams->map        = 0;
           lclparams->justify    = JUSTPDEFAULT;
           lclparams->trimify    = TRIMPDEFAULT;
           lclparams->casify     = CASEPDEFAULT;
           lclparams->slashify   = SLASHPDEFAULT;
           lclparams->descify    = DESCPDEFAULT;
           lclparams->eccwhich   = ECCPDEFAULT;
           lclparams->lpad       = PADPDEFAULT;  /* default is to use any lpad from command line */
           lclparams->pad        = 0;
           lclparams->lprecision = FPPDEFAULT;
           lclparams->precision  = MYDEFPRECISION;
           lclparams->ff         = FFPDEFAULT;
           lclparams->ldelim     = DELIMPDEFAULT;
           lclparams->lrs        = RSPDEFAULT;
           lclparams->lps        = RSPDEFAULT;
           lclparams->lrcd       = RCDPDEFAULT;
           lclparams->lrcs       = RCSPDEFAULT;
           lclparams->lrtd       = RTDPDEFAULT;
           lclparams->lrts       = RTSPDEFAULT;
        } 
      else if(toupper(*atoken) == 'V'){   
          lclparams->source  = SRCVARS;
          make_vlist=1;
      }
      else if(*atoken == '='){
          lclparams->source  = SRCVARI;
          make_vlist=1;
      }
      else if(*atoken == '@'){
          lclparams->source  = SRCVARF;
          make_vlist=1;
      }

      else if(lstrcasecmp(atoken,length,"m-",2)  == 0){   lclparams->ttype   = MODENONE;      } /* same as mc */
      else if(lstrcasecmp(atoken,length,"mp",2)  == 0){   lclparams->ttype   = MODEPDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"m+",2)  == 0){   lclparams->ttype   = MODESDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"mt",2)  == 0){   lclparams->ttype   = MODETOK;       }
      else if(lstrcasecmp(atoken,length,"mc",2)  == 0){   lclparams->ttype   = MODECHAR;      }

      else if(lstrcasecmp(atoken,4,"map$",4)     == 0){
          if(length!=5)insane2(INSFTLERR," map$N invalid at: ",atoken);
          lclparams->map = TOVAROFF(atoken[4]);
          if(lclparams->map < 0 || lclparams->map >= MYVARSMAX){
            insane2(INSFTLERR," map$N invalid at: ",atoken);
          }
          lclparams->map++; /* offset by 1 away from zero */
      }
      else if(lstrcasecmp(atoken,4,"ump$",4)     == 0){
          if(length!=5)insane2(INSFTLERR," ump$N invalid at: ",atoken);
          lclparams->map = TOVAROFF(atoken[4]);
          if(lclparams->map < 0 || lclparams->map >= MYVARSMAX){
            insane2(INSFTLERR," ump$N invalid at: ",atoken);
          }
          lclparams->map = -1 -lclparams->map; /* change sign and offset by 1 away from zero */
      }

      else if(lstrcasecmp(atoken,length,"sort-",5)   == 0){   lclparams->sort  = SORTNONE;      }
      else if(lstrcasecmp(atoken,length,"sortp",5)   == 0){   lclparams->sort  = SORTPDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"sort+",5)   == 0){   lclparams->sort  = SORTSDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"sortas",6)  == 0){   lclparams->sort  = SORTAS;        }
      else if(lstrcasecmp(atoken,length,"sortac",6)  == 0){   lclparams->sort  = SORTAC;        }
      else if(lstrcasecmp(atoken,length,"sortan",6)  == 0){   lclparams->sort  = SORTAN;        }
      else if(lstrcasecmp(atoken,length,"sortds",6)  == 0){   lclparams->sort  = SORTDS;        }
      else if(lstrcasecmp(atoken,length,"sortdc",6)  == 0){   lclparams->sort  = SORTDC;        }
      else if(lstrcasecmp(atoken,length,"sortdn",6)  == 0){   lclparams->sort  = SORTDN;        }

      else if(lstrcasecmp(atoken,length,"c-",2)  == 0){   lclparams->casify  = CASENONE;      }
      else if(lstrcasecmp(atoken,length,"cp",2)  == 0){   lclparams->casify  = CASEPDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"c+",2)  == 0){   lclparams->casify  = CASESDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"cu",2)  == 0){   lclparams->casify  = CASEUPPER;     }
      else if(lstrcasecmp(atoken,length,"cl",2)  == 0){   lclparams->casify  = CASELOWER;     }
      else if(lstrcasecmp(atoken,length,"cf",2)  == 0){   lclparams->casify  = CASEFIRST;     }

      else if(lstrcasecmp(atoken,length,"b-",2)  == 0){   lclparams->slashify = SLASHNONE;      }
      else if(lstrcasecmp(atoken,length,"bp",2)  == 0){   lclparams->slashify = SLASHPDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"b+",2)  == 0){   lclparams->slashify = SLASHSDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"bs",2)  == 0){   lclparams->slashify = SLASHUNIX;      }
      else if(lstrcasecmp(atoken,length,"ba",2)  == 0){   lclparams->slashify = SLASHALL;       }
      else if(lstrcasecmp(atoken,length,"b2",2)  == 0){   lclparams->slashify = SLASHREST;      }

      else if(lstrcasecmp(atoken,length,"eccp",4)  == 0){ lclparams->eccwhich = ECCPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"ecc+",4)  == 0){ lclparams->eccwhich = ECCSDEFAULT;  }
      else if(lstrcasecmp(atoken,3,"ecc",3)       == 0){
          lclparams->eccwhich      = ECCVAL;
          if(length>10)insane(INSFTLERR," escape string too long");
          (void) strcpy(ctemp,&atoken[3]);
          fixupescapes(ctemp);
          lclparams->ecc=ctemp[0];
      }

      else if(lstrcasecmp(atoken,length,"j-",2)  == 0){   lclparams->justify = JUSTNONE;      }
      else if(lstrcasecmp(atoken,length,"jp",2)  == 0){   lclparams->justify = JUSTPDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"j+",2)  == 0){   lclparams->justify = JUSTSDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"jl",2)  == 0){   lclparams->justify = JUSTLEFT;      }
      else if(lstrcasecmp(atoken,length,"jr",2)  == 0){   lclparams->justify = JUSTRIGHT;     }
      else if(lstrcasecmp(atoken,length,"jc",2)  == 0){   lclparams->justify = JUSTCENTER;    }

      else if(lstrcasecmp(atoken,length,"tr-",3)  == 0){   lclparams->trimify = TRIMNONE;      }
      else if(lstrcasecmp(atoken,length,"trp",3)  == 0){   lclparams->trimify = TRIMPDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"tr+",3)  == 0){   lclparams->trimify = TRIMSDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"trl",3)  == 0){   lclparams->trimify = TRIMLEFT;      }
      else if(lstrcasecmp(atoken,length,"trr",3)  == 0){   lclparams->trimify = TRIMRIGHT;     }
      else if(lstrcasecmp(atoken,length,"trb",3)  == 0){   lclparams->trimify = TRIMLEFT | TRIMRIGHT;  }
      else if(lstrcasecmp(atoken,length,"trc",3)  == 0){   lclparams->trimify = TRIMLEFT | TRIMRIGHT | TRIMCOMPRESS;  }

      else if(lstrcasecmp(atoken,length,"ff-",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFNONE;         }
      else if(lstrcasecmp(atoken,length,"ffp",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFPDEFAULT;     }
      else if(lstrcasecmp(atoken,length,"ff+",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFSDEFAULT;     }
      else if(lstrcasecmp(atoken,length,"fff",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFFLOAT;        }
      else if(lstrcasecmp(atoken,length,"ffe",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFEXP;          }
      else if(lstrcasecmp(atoken,length,"ffd",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFDEC;          }
      else if(lstrcasecmp(atoken,length,"ffu",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFDEC | FFUNS ; }
      else if(lstrcasecmp(atoken,length,"ffx",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFHEX | FFUNS ; }
      else if(lstrcasecmp(atoken,length,"ffo",3) == 0){   lclparams->ff = (~FFMASK & lclparams->ff) | FFOCT | FFUNS ; }

      else if(lstrcasecmp(atoken,length,"nz-",3) == 0){   lclparams->ff = (~NZMASK & lclparams->ff) | NZNONE;    }
      else if(lstrcasecmp(atoken,length,"nzp",3) == 0){   lclparams->ff = (~NZMASK & lclparams->ff) | NZPDEFAULT;}
      else if(lstrcasecmp(atoken,length,"nz+",3) == 0){   lclparams->ff = (~NZMASK & lclparams->ff) | NZSDEFAULT;}
      else if(lstrcasecmp(atoken,length,"nz",2)  == 0){   lclparams->ff = (~NZMASK & lclparams->ff) | NZNZ;      }

      else if(lstrcasecmp(atoken,length,"d-",2)  == 0){   lclparams->ldelim  = DELIMNONE;     }
      else if(lstrcasecmp(atoken,length,"dp",2)  == 0){   lclparams->ldelim  = DELIMPDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"d+",2)  == 0){   lclparams->ldelim  = DELIMSDEFAULT;  }
      else if(lstrcasecmp(atoken,length,"dt",2)  == 0){   lclparams->ldelim  = DELIMTOK;      }
      else if(lstrcasecmp(atoken,2,"dv",2)       == 0){
          if(length-3 > MYMAXDV)insane2(INSFTLERR," invalid -dv value in -fmt [] expression = ",cmd);
          strncpy(dvtemp,&(atoken[2]),length-2);
          dvtemp[length-2]='\0';
          fixupescapes(dvtemp);
          length=strlen(dvtemp);
          lclparams->ldelim  = DELIMVAL;
          if(length!=1)insane2(INSFTLERR," invalid -dv value in -fmt [] expression = ",cmd);
          lclparams->delim=*dvtemp;
      }

      else if(lstrcasecmp(atoken,length,"rcd-",4)  == 0){  lclparams->lrcd     = RCDNONE;        }
      else if(lstrcasecmp(atoken,length,"rcdp",4)  == 0){  lclparams->lrcd     = RCDPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"rcd+",4)  == 0){  lclparams->lrcd     = RCDSDEFAULT;    }
      else if(lstrcasecmp(atoken,4,"rcds",4)  == 0){
          lclparams->lrcd      = RCDVAL;
          lclparams->rcd       = dup_str(&atoken[4],length-4);
          fixupescapes(lclparams->rcd);
      }
      else if(lstrcasecmp(atoken,4,"rcdc",4)  == 0){
          lclparams->lrcd      = RCDVALC;
          lclparams->rcd       = dup_str(&atoken[4],length-4);
          fixupescapes(lclparams->rcd);
      }

      else if(lstrcasecmp(atoken,length,"rcs-",4)  == 0){  lclparams->lrcs     = RCSNONE;        }
      else if(lstrcasecmp(atoken,length,"rcsp",4)  == 0){  lclparams->lrcs     = RCSPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"rcs+",4)  == 0){  lclparams->lrcs     = RCSSDEFAULT;    }
      else if(lstrcasecmp(atoken,4,"rcss",4)  == 0){
          lclparams->lrcs      = RCSVAL;
          lclparams->rcs       = dup_str(&atoken[4],length-4);
          fixupescapes(lclparams->rcs);
      }

      else if(lstrcasecmp(atoken,length,"rtd-",4)  == 0){  lclparams->lrtd     = RTDNONE;        }
      else if(lstrcasecmp(atoken,length,"rtdp",4)  == 0){  lclparams->lrtd     = RTDPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"rtd+",4)  == 0){  lclparams->lrtd     = RTDSDEFAULT;    }
      else if(lstrcasecmp(atoken,4,"rtds",4)  == 0){
          lclparams->lrtd      = RTDVAL;
          lclparams->rtd       = dup_str(&atoken[4],length-4);
          fixupescapes(lclparams->rtd);
      }
      else if(lstrcasecmp(atoken,4,"rtdc",4)  == 0){
          lclparams->lrtd      = RTDVALC;
          lclparams->rtd       = dup_str(&atoken[4],length-4);
          fixupescapes(lclparams->rtd);
      }

      else if(lstrcasecmp(atoken,length,"rts-",4)  == 0){  lclparams->lrts     = RTSNONE;        }
      else if(lstrcasecmp(atoken,length,"rtsp",4)  == 0){  lclparams->lrts     = RTSPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"rts+",4)  == 0){  lclparams->lrts     = RTSSDEFAULT;    }
      else if(lstrcasecmp(atoken,4,"rtss",4)  == 0){
          lclparams->lrts   = RTSVAL;
          EXT_MALLOC(lclparams->rts, length, MEMOOPS); /* a couple of bytes too big */
          lclparams->rts[0] = MYVARSMAX; /* indicates an immediate string */
          strncpy(&lclparams->rts[1],&atoken[4],length-4);
          lclparams->rts[length-3]='\0'; /* terminate string */
          fixupescapes(&lclparams->rts[1]);
      }
      else if(lstrcasecmp(atoken,4,"rtsv",4)  == 0){
          lclparams->lrts   = RTSVAR;
          EXT_MALLOC(lclparams->rts,SOC,MEMOOPS);
          *lclparams->rts=MYVARSMAX; /* indicate variable holds string */
      }

      else if(lstrcasecmp(atoken,length,"rs-",3)  == 0){  lclparams->lrs     = RSNONE;        }
      else if(lstrcasecmp(atoken,length,"rsp",3)  == 0){  lclparams->lrs     = RSPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"rs+",3)  == 0){  lclparams->lrs     = RSSDEFAULT;   }
      else if(lstrcasecmp(atoken,3,"rss",3)  == 0){
          lclparams->lrs          = RSVAL;
          lclparams->ersstring    = dup_str(&atoken[3],length-3);
          fixupescapes(lclparams->ersstring);
      }

      else if(lstrcasecmp(atoken,length,"ps-",3)  == 0){  lclparams->lps     = PSNONE;        }
      else if(lstrcasecmp(atoken,length,"psp",3)  == 0){  lclparams->lps     = PSPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"ps+",3)  == 0){  lclparams->lps     = PSSDEFAULT;    }
      else if(lstrcasecmp(atoken,2,"ps",2)  == 0){
          if(length < 2)insane2(INSFTLERR," invalid ps: ",atoken);
          avar=TOPSOFF(atoken[2]);
          lclparams->lps = PSVAL;
          if(avar >= 0 && avar <= 9){ /* a number, so it specifies a pattern */
            use_ps = avar; /* specified pattern */
            where = 3;
          }
          else {
            use_ps = 0; /* default pattern */
            where = 2;
          }
          lclparams->ps=use_ps;     /* the PS to use*/
          if(length - where != 0){
             insane2(INSFTLERR," invalid -ps value in -fmt [] expression = ",cmd);
          }
      }

      else if(lstrcasecmp(atoken,length,"de-",3) == 0){   lclparams->descify  = DESCNONE;        }
      else if(lstrcasecmp(atoken,length,"dep",3) == 0){   lclparams->descify  = DESCPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"de+",3) == 0){   lclparams->descify  = DESCSDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"de",2)  == 0){   lclparams->descify  = DESCFIELD;       }

      else if(lstrcasecmp(atoken,length,"pd-",3) == 0){   lclparams->lpad    = PADNONE;       }
      else if(lstrcasecmp(atoken,length,"pdp",3) == 0){   lclparams->lpad    = PADPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"pd+",3) == 0){   lclparams->lpad    = PADSDEFAULT;    }
      else if(lstrcasecmp(atoken,2,"pd",2)       == 0){
        if(! lstrtol(&atoken[2],length-2,&ltemp) || ( ltemp < 0 )){
          insane2(INSFTLERR," invalid -pd value in -fmt [] expression = ",cmd);
        }
        lclparams->pad=ltemp;  /* this will not overflow, it will be a small integer */
        lclparams->lpad=PADFIELD;
      }
      else if(lstrcasecmp(atoken,length,"fw-",3) == 0){   lclparams->lpad    = PADNONE;       }
      else if(lstrcasecmp(atoken,length,"fwp",3) == 0){   lclparams->lpad    = PADPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"fw+",3) == 0){   lclparams->lpad    = PADSDEFAULT;    }
      else if(lstrcasecmp(atoken,2,"fw",2)       == 0){
        if(! lstrtol(&atoken[2],length-2,&ltemp) || ( ltemp < 0 )){
          insane2(INSFTLERR," invalid -fw value in -fmt [] expression = ",cmd);
        }
        lclparams->pad = -ltemp;  /* this will not overflow, it will be a small integer */
        lclparams->lpad=PADFIELD;
      }
      else if(lstrcasecmp(atoken,length,"fp-",3) == 0){   lclparams->lprecision    = FPNONE;       }
      else if(lstrcasecmp(atoken,length,"fpp",3) == 0){   lclparams->lprecision    = FPPDEFAULT;    }
      else if(lstrcasecmp(atoken,length,"fp+",3) == 0){   lclparams->lprecision    = FPSDEFAULT;    }
      else if(lstrcasecmp(atoken,2,"fp",2)       == 0){
        if(! lstrtol(&atoken[2],length-2,&ltemp) || ( ltemp < 0 )){
          insane2(INSFTLERR," invalid -fp value in -fmt [] expression = ",cmd);
        }
        lclparams->precision = ltemp;  /* this will not overflow, it will be a small integer */
        lclparams->lprecision=FPFIELD;
      }
      else {
        insane2(INSFTLERR," invalid -fmt [] expression = ",cmd);
      }
      if(make_vlist){ /* implement v$VLIST, =$VLIST, @$VLIST */
        make_vlist=0;
        if(atoken[1]=='$'){
          lclparams->ttype   = MODENUM;  /* default to this, explicit mn not needed */
          message=vlist_set(&(lclparams->vlist),length-2,&(atoken[2]),DASH_ALLOW);
        }
        else { 
          message=vlist_set(&(lclparams->vlist),length-1,&(atoken[1]),NO_DASH_ALLOW);
        }
        if(message){
          insane2(INSFTLERR," invalid vlist in [field] v,=,@ addressing = ",cmd);
          insane("",message);
        }
      }
    }
    else { /* not :,  must be the range */
      if(get_range(atoken,length,sc,nc,inc)){ lclparams->source |= SRCVRANGE; }
      donerange=1;
    } /* test for : or range */
    if(tcount == 0){ atoken=strtok_variant(cmd,&hold,":",PARSE_ESCAPES,"",&thedelim,&start,&length);  }
    else           { atoken=strtok_variant(NULL,&hold,":",PARSE_ESCAPES,"",&thedelim,&start,&length); }
    tcount++;
  }
  if(!donerange){
     (void) get_range("",0,sc,nc,inc);
  }
}

void classify_po(char *cmd, PONEXUS *lcl_po){

char *atoken;
char thedelim;
int  start,length;
char ctemp[MYSHORTSTRING];
STVNEXUS hold;
    
  thedelim=':';
  length=1;
  
  atoken=strtok_variant(cmd,&hold,":",PARSE_ESCAPES,"",&thedelim,&start,&length);
  while(atoken != NULL){
    if(     lstrcasecmp(atoken,length,"dqs",3) == 0){ BR_SET(lcl_po->parse_options,DQMASK,DQS);        } 
    else if(lstrcasecmp(atoken,length,"dq-",3) == 0){ BR_SET(lcl_po->parse_options,DQMASK,DQNONE);     }
    else if(lstrcasecmp(atoken,length,"dq+",3) == 0){ BR_SET(lcl_po->parse_options,DQMASK,DQSDEFAULT); }
    else if(lstrcasecmp(atoken,length,"dqp",3) == 0){ BR_SET(lcl_po->parse_options,DQMASK,DQPDEFAULT); }
    else if(lstrcasecmp(atoken,length,"dq",2)  == 0){ BR_SET(lcl_po->parse_options,DQMASK,DQ);         }

    else if(lstrcasecmp(atoken,length,"sd-",3) == 0){ BR_SET(lcl_po->parse_options,SDMASK,SDNONE);     }
    else if(lstrcasecmp(atoken,length,"sd+",3) == 0){ BR_SET(lcl_po->parse_options,SDMASK,SDSDEFAULT); }
    else if(lstrcasecmp(atoken,length,"sdp",3) == 0){ BR_SET(lcl_po->parse_options,SDMASK,SDPDEFAULT); }
    else if(lstrcasecmp(atoken,length,"sd",2)  == 0){ BR_SET(lcl_po->parse_options,SDMASK,SD);         }

    else if(lstrcasecmp(atoken,length,"esc-",4) == 0){ BR_SET(lcl_po->parse_options,ESCAPESMASK,ESCAPESNONE);     }
    else if(lstrcasecmp(atoken,length,"esc+",4) == 0){ BR_SET(lcl_po->parse_options,ESCAPESMASK,ESCAPESSDEFAULT); }
    else if(lstrcasecmp(atoken,length,"escp",4) == 0){ BR_SET(lcl_po->parse_options,ESCAPESMASK,ESCAPESPDEFAULT); }
    else if(lstrcasecmp(atoken,length,"esc",3)  == 0){ BR_SET(lcl_po->parse_options,ESCAPESMASK,ESCAPES);         }

    else if(lstrcasecmp(atoken,3,"dlv",3) == 0){ BR_SET(lcl_po->parse_options,DELIMMASK,DELIMVAL);
      if(length-3 > MYSHORTSTRING)insane2(INSFTLERR," invalid dlv value in [set] expression = ",cmd);
      strncpy(ctemp,&(atoken[3]),length-3);
      ctemp[length-3]='\0';
      fixupescapes(ctemp);
      length=strlen(ctemp);
      if(!length)insane2(INSFTLERR," dlv value reduces to nothing in expression = ",cmd);
      lcl_po->dllen  = length;
      if(lcl_po->delimit)free(lcl_po->delimit);
      lcl_po->delimit=dup_str(ctemp,strlen(ctemp));
    }
    else if(lstrcasecmp(atoken,length,"dl-",3) == 0){ ;
       insane(INSFTLERR," dl- is not allowed, a delimiter string is required");
    }
    else if(lstrcasecmp(atoken,length,"dl+",3) == 0){ BR_SET(lcl_po->parse_options,DELIMMASK,DELIMSDEFAULT); }
    else if(lstrcasecmp(atoken,length,"dlp",3) == 0){ BR_SET(lcl_po->parse_options,DELIMMASK,DELIMPDEFAULT); }

    else if(lstrcasecmp(atoken,4,"mdlv",4) == 0){ BR_SET(lcl_po->parse_options,MDELIMMASK,MDELIMVAL);
      if(length-4 > MYSHORTSTRING)insane2(INSFTLERR," invalid mdlv value in [set] expression = ",cmd);
      strncpy(ctemp,&(atoken[4]),length-4);
      ctemp[length-4]='\0';
      fixupescapes(ctemp);
      length=strlen(ctemp);
      if(!length)insane2(INSFTLERR," mdlv value reduces to nothing in [set] expression = ",cmd);
      lcl_po->mdllen  = length;
      if(lcl_po->mdelimit)free(lcl_po->mdelimit);
      lcl_po->mdelimit=dup_str(ctemp,strlen(ctemp));
    }
    else if(lstrcasecmp(atoken,length,"mdl-",4) == 0){ ;
       insane(INSFTLERR," mdl- is not allowed, a delimiter string is required");
    }
    else if(lstrcasecmp(atoken,length,"mdl+",4) == 0){ BR_SET(lcl_po->parse_options,MDELIMMASK,MDELIMSDEFAULT); }
    else if(lstrcasecmp(atoken,length,"mdlp",4) == 0){ BR_SET(lcl_po->parse_options,MDELIMMASK,MDELIMPDEFAULT); }
    else {
      insane2(INSFTLERR," invalid [set] expression = ",cmd);
    }
    
    atoken=strtok_variant(NULL,&hold,":",PARSE_ESCAPES,"",&thedelim,&start,&length);
  }
}


/* Figure out the range field in an [] from a format or string variable.  
Returns 0 if it is a simple numeric range like [1,3,1], 1 if it is
[$A], [$A,5], [$A,-7] indicating a numeric variable range stored in $A, the first
form in positions 1,2,3,  the second in 5,6,7; the third in -7,-6,-5 */

int get_range(char *string, int length, int *sc, int *nc, int *inc){
int comma,comma2,ok;
long scl,ncl,incl;
int  status=0;
int  itmp=1000000; /* impossible value */

  incl= 1;
  scl = 1;
  ncl = TO_END;
  ok=0;
  if(*string=='$'){
     status=1;
     string++; length--; /* eat the leading $ */
     itmp=TOVAROFF(*string); /* store the variable */
     string++; length--;
     if(*string==','){ string++;length--; } /* eat the comma too, if there is one */
     /* now fall through and find scl using the same code as for a normal range */
  }
  for(comma=0 ; comma<length ; comma++){           if(string[comma]==',')break; }
  for(comma2=comma+1 ; comma2<length ; comma2++){  if(string[comma2]==',')break; }
  if(0 == length){ /* []   */
     ok=1;
  }
  else if(comma >= length){ /* [#] or [$N] */
    if(                lstrtol(string,            length,           &scl)  && scl  != 0){
      ncl=scl;
      ok=1;
    }
  }
  else if(comma == 0){ /* [,],[,#],[,,#],[,#,#], or [,#,]*/
    if(length == 1){   /*  [,] */
      ok=1;
    }
    else if(comma2 > length - 1 ){ /* [,#] */
      if(              lstrtol(&string[comma+1],  length-comma-1,   &ncl)  && ncl  != 0)ok=1;
    }
    else if(comma2 == length - 1){/* [,#,] */
      if(              lstrtol(&string[comma+1],  comma2-1,         &ncl)  && ncl  != 0)ok=1;
    }
    else { /* [,,#] or [,#,#] */
      if(comma2==1){ /* [,,#] */
        if(            lstrtol(&string[comma2+1], length-comma2-1,  &incl) && incl != 0)ok=1;
      }
      else { /* [,#,#] */
        if(            lstrtol(&string[comma+1],  comma2-comma-1,   &ncl)  && ncl  != 0 &&
                       lstrtol(&string[comma2+1], length-comma2-1,  &incl) && incl != 0)ok=1;
      }
    }
  }
  else if(comma ==length -1){ /* [#,] or [,]  */
    if(                lstrtol(string,            comma,            &scl)  && scl  != 0)ok=1;
  }
  else{ /* [#,#], [#,#,], [#,#,#], [#,,], [#,,#] */
    if(comma2 >= length-1){ /* [#,#,], [#,#], [#,,]*/
      if(comma2>comma+1){ /* [#,#,], [#,#]*/
        if(            lstrtol(string,            comma,            &scl)  && scl  != 0 &&
                       lstrtol(&string[comma+1],  comma2-comma-1,   &ncl)  && ncl  != 0)ok=1;
      }
      else{ /* [#,,] */
        if(            lstrtol(string,            comma,            &scl)  && scl  != 0)ok=1;
      }
    }  
    else { /* [#,#,#] [#,,#] */
      if(comma2>comma+1){ /* [#,#,#]*/
        if(            lstrtol(string,            comma,            &scl)  && scl  != 0 &&
                       lstrtol(&string[comma+1],  comma2-comma-1,   &ncl)  && ncl  != 0 && 
                       lstrtol(&string[comma2+1], length-comma2-1,  &incl) && incl != 0)ok=1;
      }
      else { /* [#,,#] */
        *nc=TO_END;
        if(            lstrtol(string,            comma,            &scl)  && scl  != 0 &&
                       lstrtol(&string[comma2+1], length-comma2-1,  &incl) && incl != 0 )ok=1;
      }
    }
  }
  if(itmp>=0 && itmp<MYVARSMAX){
    ncl=scl;   /* store the position in that array */
    scl=itmp;  /* store the variable offset, 0 for $A*/
  }
  *sc  = scl;
  *nc  = ncl;
  *inc = incl;
  if(!ok)insane2(INSFTLERR," invalid range in [] field: ",string);
  return(status);
}

/* add_op

 processes [] or regular string.  
 where a [] is processed like this:
 t   = token
 c   = character  (defaults to whatever -tok set on command line)
 +   = process (pad, etc)
 -   = noprocess   (defaults to process)
 #   = just the one column
 ,#  = first through this column
 #,  = this column through last
 #,# = column range
 
 
 xe is the limit on the number of defined fields (static strings or descriptors)
  
*/

void add_op(OMNINEXUS *omni, char *cmd, int start, int length,
   FIELD2NEXUS  *fldlist, int *fldcount,
   FIELDNEXUS *gblparams, int xe){
int  sc,nc,inc;
char holdc;
int  newlength;
FIELDNEXUS lclparams;

  if(length==0)return;
  if(*fldcount>=xe)insane(INSFTLERR," -fmt* or -v* has too many fields, increase -xe");
  if(cmd[start]=='['){ /* column field processing */
    lclparams.notglobal=0;
    start++; /* trim off the [] */
    length -= 2;
    holdc=cmd[start+length];
    cmd[start+length]='\0';
    classify_op(&cmd[start],&sc,&nc,&inc,&lclparams);
    cmd[start+length]=holdc;
        
    /* merge the global (command line) settings with the field settings
       so that when it comes time to emit only the field settings need
       to be checked.  S fields match settings, P match program defaults,
       and anything else uses the values returned in lclparams */
             
    if(lclparams.ttype==MODESDEFAULT){      lclparams.ttype  = gblparams->ttype;}
    else if(lclparams.ttype==MODEPDEFAULT){ lclparams.ttype  = MODENONE;        }/* same as MODECHAR */

    if(lclparams.sort==SORTSDEFAULT){       lclparams.sort  = gblparams->sort; }
    else if(lclparams.sort==SORTPDEFAULT){  lclparams.sort  = SORTNONE;        }
    
    /* there is no global map, so it cannot be merged */
    
    if      (lclparams.lpad == PADSDEFAULT  ){
      lclparams.lpad  = gblparams->lpad;
      lclparams.pad   = gblparams->pad; 
    }
    else if (lclparams.lpad == PADPDEFAULT  ){
      lclparams.lpad  = PADNONE;
      lclparams.pad   = 0; 
    }
    
    if      (lclparams.lprecision == FPSDEFAULT  ){
      lclparams.lprecision  = gblparams->lprecision;
      lclparams.precision   = gblparams->precision; 
    }
    else if (lclparams.lprecision == FPPDEFAULT  ){
      lclparams.lprecision  = FPNONE;
      lclparams.precision   = MYDEFPRECISION; 
    }
    
    if      (lclparams.justify == JUSTSDEFAULT){ lclparams.justify =  gblparams->justify; }
    else if (lclparams.justify == JUSTPDEFAULT){ lclparams.justify =  JUSTNONE;           }

    if      (lclparams.trimify == TRIMSDEFAULT){ lclparams.trimify =  gblparams->trimify; }
    else if (lclparams.trimify == TRIMPDEFAULT){ lclparams.trimify =  TRIMNONE;           }

    if      (lclparams.casify == CASESDEFAULT){  lclparams.casify  =  gblparams->casify;  }
    else if (lclparams.casify == CASEPDEFAULT){  lclparams.casify  =  CASENONE;           }
    
    if      ((FFMASK &lclparams.ff) == FFSDEFAULT){ lclparams.ff  =  (~FFMASK & lclparams.ff) | gblparams->ff; }
    else if ((FFMASK &lclparams.ff) == FFPDEFAULT){ lclparams.ff  =  (~FFMASK & lclparams.ff) | FFNONE;        }

    if      ((NZMASK &lclparams.ff) == NZSDEFAULT){ lclparams.ff  =  (~NZMASK & lclparams.ff) | gblparams->ff; }
    else if ((NZMASK &lclparams.ff) == NZPDEFAULT){ lclparams.ff  =  (~NZMASK & lclparams.ff) | NZNONE;        }

    if      (lclparams.slashify == SLASHSDEFAULT){ lclparams.slashify  =  gblparams->slashify; }
    else if (lclparams.slashify == SLASHPDEFAULT){ lclparams.slashify  =  SLASHNONE;           }
    
    if      (lclparams.descify == DESCSDEFAULT){ lclparams.descify  =  gblparams->descify; }
    else if (lclparams.descify == DESCPDEFAULT){ lclparams.descify  =  DESCNONE;           }
    
    if      (lclparams.eccwhich == ECCSDEFAULT){
      lclparams.eccwhich  =  ECCSDEFAULT;
      lclparams.ecc       =  gblparams->ecc;
    }
    else if (lclparams.eccwhich == ECCPDEFAULT){
      lclparams.eccwhich  =  ECCPDEFAULT;
      lclparams.ecc       =  '\\';
    }

    if      (lclparams.lrs  == RSSDEFAULT){
      lclparams.lrs        =  gblparams->lrs;
      lclparams.ersstring  =  gblparams->ersstring;
    }
    else if (lclparams.lrs  == RSPDEFAULT || lclparams.lrs  == RSNONE){
      lclparams.lrs        =  RSNONE;
      lclparams.ersstring  =  NULL;
    }

    if      (lclparams.lrcd  == RCDSDEFAULT){
      lclparams.lrcd       =  gblparams->lrcd;
      lclparams.rcd        =  gblparams->rcd;
    }
    else if (lclparams.lrcd  == RCDPDEFAULT || lclparams.lrcd  == RCDNONE){
      lclparams.lrcd       =  RCDNONE;
      lclparams.rcd        =  NULL;
    }

    if      (lclparams.lrcs  == RCSSDEFAULT){
      lclparams.lrcs       =  gblparams->lrcs;
      lclparams.rcs        =  gblparams->rcs;
    }
    else if (lclparams.lrcs  == RCSPDEFAULT || lclparams.lrcs  == RCSNONE){
      lclparams.lrcs       =  RCSNONE;
      lclparams.rcs        =  NULL;
    }

    if      (lclparams.lrtd  == RTDSDEFAULT){
      lclparams.lrtd       =  gblparams->lrtd;
      lclparams.rtd        =  gblparams->rtd;
    }
    else if (lclparams.lrtd  == RTDPDEFAULT || lclparams.lrtd  == RTDNONE){
      lclparams.lrtd       =  RTDNONE;
      lclparams.rtd        =  NULL;
    }

    if      (lclparams.lrts  == RTSSDEFAULT){
      lclparams.lrts       =  gblparams->lrts;
      lclparams.rts        =  gblparams->rts;
    }
    else if (lclparams.lrts  == RTSPDEFAULT || lclparams.lrts  == RTSNONE){
      lclparams.lrts       =  RTSNONE;
      lclparams.rts        =  NULL;
    }

    if      (lclparams.lps  == PSSDEFAULT){
      lclparams.lps        =  gblparams->lps;
      lclparams.ps         =  gblparams->ps;
    }
    else if (lclparams.lps  == PSPDEFAULT || lclparams.lps  == PSNONE){
      lclparams.lps        =  PSNONE;
      lclparams.ps         =  0;
    }

    /* sanity check rcds and rcss strings - prevent a mismatch in lengths or empty strings.
      It's OK for rcss to be set and rcds not be set because the latter overrides the former
      at output and nothing bad will happen.  */

    if(lclparams.lrcd == RCDVAL || lclparams.lrcd == RCDVALC){
      if(strlen(lclparams.rcd) == 0)insane(INSFTLERR," rcds may not be an empty string");
      if(lclparams.lrcs == RCSVAL){
        if(strlen(lclparams.rcs) != strlen(lclparams.rcd))insane(INSFTLERR," length mismatch: rcss rcds");
        if(strlen(lclparams.rcs) == 0)insane(INSFTLERR,"  rcss may not be an empty string");
      }
    }

    /* sanity check MODENUM, it must have a double format type set.  If none, use fff*/

    if((lclparams.ttype == MODENUM) && ((lclparams.ff & FFMASK)  == FFNONE)){
      lclparams.ff |= FFFLOAT;
    }

    /* Is a separate action list needed?  It is if anything differs from the global.
    However, the new list could be empty if the local turned everything off that was
    on in the global.  So for each option check if there is something to process or not.
    */

    if(lclparams.ttype     != gblparams->ttype){     lclparams.notglobal=1; }
    if(lclparams.rcd       != gblparams->rcd  ||
       lclparams.lrcd      != gblparams->lrcd ||
       lclparams.rcs       != gblparams->rcs){       lclparams.notglobal=1; }
    if(lclparams.rtd       != gblparams->rtd  ||
       lclparams.lrtd      != gblparams->lrtd ||
       lclparams.rts       != gblparams->rts){       lclparams.notglobal=1; }
    if(lclparams.lps       != gblparams->lps  ||
       lclparams.ps        != gblparams->ps){        lclparams.notglobal=1; }
    if(lclparams.descify   != gblparams->descify){   lclparams.notglobal=1; }
    if(lclparams.slashify  != gblparams->slashify ||
       lclparams.ecc       != gblparams->ecc){       lclparams.notglobal=1; }
    if(lclparams.ff        != gblparams->ff  ||
       lclparams.pad       != gblparams->pad ||
       lclparams.precision != gblparams->precision){ lclparams.notglobal=1; }
    if(lclparams.trimify   != gblparams->trimify){   lclparams.notglobal=1; }
    if(lclparams.justify   != gblparams->justify){   lclparams.notglobal=1; }
    if(lclparams.casify    != gblparams->casify){    lclparams.notglobal=1; }
    if(lclparams.lrs       != gblparams->lrs ||  
       lclparams.ersstring != gblparams->ersstring){ lclparams.notglobal=1; }

    /* If any of these are globally defined force a call to fn_to_pal, or the command line
       default strings will not be available in an [] in an -op */
    if(gblparams->ersstring ||
       gblparams->rcd       ||
       gblparams->rcs       ||
       gblparams->rtd       ||
       gblparams->rts){                              lclparams.notglobal=1; }

    /* Finally we know enough and can decide whether to use the global action list
       or to make a new one.
    */

    if(lclparams.notglobal){ /* make a new action list */
      fn_to_pal(omni, &lclparams);
      /* save the offset to this action list in ppoff*/
      fldlist[*fldcount].ppoff   = omni->lastpal_off;
      fldlist[*fldcount].ppcount = omni->lastpal_count;
    }
    else {  /* use the global post processing action list */
      fldlist[*fldcount].ppoff   = omni->gblpal_off;
      fldlist[*fldcount].ppcount = omni->gblpal_count;
    }
    FIELDNEXUS_clean(&lclparams,gblparams);

    /* move pieces from lclparams to fldlist, as appropriate, other than the
    action list */

    fldlist[*fldcount].iss     =  sc;     /* first token in the buffer */
    fldlist[*fldcount].issend  =  nc;     /* last  token to process */
    fldlist[*fldcount].source  =  lclparams.source | lclparams.ttype | ISSDAT; /* use toklist */
    fldlist[*fldcount].sort    =  lclparams.sort; /* pre-processing */
    fldlist[*fldcount].map     =  lclparams.map;  /* define a map   */
    if(lclparams.sort && lclparams.map){
      insane(INSFTLERR," field defines both a map/ump and a sort");
    }

    if      (lclparams.vlist  ){ fldlist[*fldcount].vlist  = 
      vlist_dup(lclparams.vlist);
      free(lclparams.vlist);
      lclparams.vlist       = NULL;
    }
    else {                       fldlist[*fldcount].vlist  = NULL;            }

    if(lclparams.ttype==MODETOK){
      fldlist[*fldcount].issinc  =  inc;    /* increment by  */
      if(!fldlist[*fldcount].vlist){  
        /* TARGET is not defined, so it is probably input, and we will need tokens.
        But this might be a waste of time if this is actually -opA and the like)*/
        omni->maketokens=YES;
      }
    }
    else if(lclparams.ttype==MODENUM){
      fldlist[*fldcount].issinc  =  inc;    /* increment by  */
    }
    else {
      if(lclparams.sort)insane(INSFTLERR," sorts require mt or mn");
      fldlist[*fldcount].issinc  =  1;       /* always 1, want all characters */
    }

    if      (lclparams.ldelim == DELIMSDEFAULT  ){
      fldlist[*fldcount].ldelim  = gblparams->ldelim;
      fldlist[*fldcount].delim   = gblparams->delim;
    }
    else if (lclparams.ldelim == DELIMPDEFAULT  ){
      fldlist[*fldcount].ldelim  = DELIMTOK;
      fldlist[*fldcount].delim   = ':'; /* will be overwritten when token is made */
    }
    else { /* DELIMNONE DELIMTOK or DELIMVAL */
      fldlist[*fldcount].ldelim  = lclparams.ldelim;
      fldlist[*fldcount].delim   = lclparams.delim; /* from a dlN construct */
    }

  }
  else {  
    /* static string processing - simplest, little processing required
      These are the literals from -fmt* or -v*  */
    holdc=cmd[start+length];
    cmd[start+length]='\0';
    fixupescapes(&(cmd[start]));                   /* handle \n \r \t \123 \[ \]*/
    newlength=strlen(&(cmd[start]));

    cmd[start+length]=holdc;
    fldlist[*fldcount].iss       =  start+1;           /* start of this string */
    fldlist[*fldcount].issend    =  start+newlength;   /* end of the string */
    fldlist[*fldcount].issinc    =  1;                 /* default to 1*/
    fldlist[*fldcount].source    =  SRCSELF | MODECHAR | ISSDEF;   /* descriptor source  */
    fldlist[*fldcount].map       =  0;           /* no map may be defined                     */
    fldlist[*fldcount].ppcount   =  0;           /* no post processing action list            */
    fldlist[*fldcount].ppoff     =  0;           /* should never be used but set to something */
    fldlist[*fldcount].delim     =  '\0';        /* should never be used but set to something */
    fldlist[*fldcount].sort      =  SORTNONE;    /* should never be used but set to something */
    fldlist[*fldcount].ldelim    =  DELIMNONE;   /* should never be used but set to something */
    fldlist[*fldcount].vlist     =  NULL;        /* should never be used but set to something */
  }
  (*fldcount)++;
  /* clear vlist (required for proper function) and all other strings (kill memory leaks) */
}

/* Avoid memory leaks in char * fields in FIELDNEXUS.
   delete local memory if allocated, always reset pointers to null
   vlist is handled elsewhere */
void FIELDNEXUS_clean(FIELDNEXUS *lcl, FIELDNEXUS *gbl){
  if(lcl->ersstring && (gbl->ersstring != lcl->ersstring))free(lcl->ersstring);
  if(lcl->rcd       && (gbl->rcd       != lcl->rcd      ))free(lcl->rcd      );
  if(lcl->rcs       && (gbl->rcs       != lcl->rcs      ))free(lcl->rcs      );
  if(lcl->rtd       && (gbl->rtd       != lcl->rtd      ))free(lcl->rtd      );
  if(lcl->rts       && (gbl->rts       != lcl->rts      ))free(lcl->rts      );
  lcl->ersstring   = NULL;
  lcl->rcd         = NULL;
  lcl->rcs         = NULL;
  lcl->rtd         = NULL;
  lcl->rts         = NULL;
  lcl->ps          = 0;
}

void FIELDNEXUS_destroy(FIELDNEXUS **efld){
FIELDNEXUS *fld = *efld;
  if(fld->ersstring)free(fld->ersstring);
  if(fld->rcd      )free(fld->rcd      );
  if(fld->rcs      )free(fld->rcs      );
  if(fld->rtd      )free(fld->rtd      );
  if(fld->rts      )free(fld->rts      );
  if(fld->vlist    )free(fld->vlist    );
  free(fld);
  *efld=NULL;
}


void add_po(OMNINEXUS *omni, char *cmd, PONEXUS *lcl_po){
int  repo;
PONEXUS   *gbl_po=omni->gbl_po;

    if(cmd)classify_po(cmd, lcl_po);  /* for global PO cmd will be NULL*/
    
    if(       (lcl_po->parse_options & DELIMMASK) == DELIMSDEFAULT){
      (void) strcpy(lcl_po->delimit,gbl_po->delimit);
      lcl_po->dllen=gbl_po->dllen;
    }
    else if ( (lcl_po->parse_options & DELIMMASK) == DELIMPDEFAULT){
      (void)strcpy(lcl_po->delimit," :\t");
      lcl_po->dllen = strlen(lcl_po->delimit);
    }
    if(       (lcl_po->parse_options & MDELIMMASK) == MDELIMSDEFAULT){
      (void) strcpy(lcl_po->mdelimit,gbl_po->mdelimit);
      lcl_po->mdllen=gbl_po->mdllen;
    }
    else if ( (lcl_po->parse_options & MDELIMMASK) == MDELIMPDEFAULT){
      (void)strcpy(lcl_po->mdelimit," :\t");
      lcl_po->mdllen = strlen(lcl_po->mdelimit);
    }

    repo=0;
    if      ((lcl_po->parse_options & DQMASK) == DQ  ){
      repo |= PARSE_DBLQUOTES;
    }
    else if ((lcl_po->parse_options & DQMASK) == DQS  ){
      repo |= PARSE_STRIPDQUOTES;
    }
    else if ((lcl_po->parse_options & DQMASK) == DQSDEFAULT  ){
      repo |= gbl_po->parse_options & (PARSE_DBLQUOTES | PARSE_STRIPDQUOTES);
    }
    else if ((lcl_po->parse_options & DQMASK) == DQPDEFAULT  ){\
      /* intentionally left blank, program default is neither DQ nor DQS*/
    }

    if      ((lcl_po->parse_options & SDMASK) == SD  ){
      repo |= PARSE_SINGLEDEL;
    }
    else if ((lcl_po->parse_options & SDMASK) == SDSDEFAULT  ){
      repo |= gbl_po->parse_options & PARSE_SINGLEDEL;
    }
    else if ((lcl_po->parse_options & SDMASK) == SDPDEFAULT  ){\
      /* intentionally left blank, program default is neither SD nor SDS*/
    }

    if      ((lcl_po->parse_options & ESCAPESMASK) == ESCAPES  ){
      repo |= PARSE_ESCAPES;
    }
    else if ((lcl_po->parse_options & ESCAPESMASK) == ESCAPESSDEFAULT  ){
      repo |= gbl_po->parse_options & PARSE_ESCAPES;
    }
    else if ((lcl_po->parse_options & ESCAPESMASK) == ESCAPESPDEFAULT  ){\
      /* intentionally left blank, program default is ! ESCAPES*/
    }

    lcl_po->parse_options=repo;
    
    return;
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

void realends_oops(int lstart, int lend, int length){
/* This would be better, but not backwards compatible  
  (void) fprintf(stderr,INSFTLERR," invalid range start %d, end %d, length %d\n",
  lstart,lend,length); */
  (void) fprintf(stderr,"%s column range invalid\n",INSFTLERR);
  exit(EXIT_FAILURE);
}

/* returns the largest token count for all of the variables in list.  Every character
in list must be from A<->Z. This is NOT checked. This is used by the interleave variable access modes, which
must create an array that is N (list length) by M (largest token count in any of the variables). */
int var_max_tcount(char *list, FMTNEXUS **vn){
int tcount=0;
FMTNEXUS *vptr;
  for( ;*list != EOVLIST; list++){
     vptr=vn[(int) *list];
     if(tcount < vptr->tokcount)tcount = vptr->tokcount;
  }
  return(tcount);
}

/* returns the largest array size for all of the numeric variables in list.
Similar to var_max_tcount. */
int nvar_max_size(char *list, DVNEXUS *dn){
int lmax=0;
DVNEXUS *dptr;
  for( ;*list != EOVLIST; list++){
     dptr=&dn[(int) *list];
     if(lmax < dptr->dlen)lmax = dptr->dlen;
  }
  return(lmax);
}

/* All of the post processing functions will emit info if called with a NULL
first argument. If called, there will always be at least one selected operation*/
void dump_pal(OMNINEXUS *omni, int poffset){
int *offset;
int  selector;
ESNEXUS *hold;

    selector = *(int *)&((omni->alldata->string[poffset]));
    offset   =  (int *)&((omni->alldata->string[poffset+SOI]));
    hold=omni->piece;
    omni->piece=NULL; /* causes these to show params instead of doing anything useful */
    
    if(selector & DO_RS   ){ fillhole(omni, *offset++); }
    if(selector & DO_DESC ){ descit(  omni, *offset++); }
    if(selector & DO_RCD  ){ rcit(    omni, *offset++); }
    if(selector & DO_RTD  ){ rtit(    omni, *offset++); }
    if(selector & DO_PS   ){ psit(    omni, *offset++); }
    if(selector & DO_SLASH){ slashit( omni, *offset++); }
    if(selector & DO_FFF  ){ ffit(    omni, *offset++,NULL); }
    if(selector & DO_PAD  ){ padit(   omni, *offset++); }
    if(selector & DO_TRIM ){ trimit(  omni, *offset++); }
    if(selector & DO_JUST ){ justit(  omni, *offset++); } 
    if(selector & DO_CASE ){ caseit(  omni, *offset++); } 
    omni->piece=hold;
}

void dump_ml(OMNINEXUS *omni, MLNEXUS *matches, char *section){
int i;
int start,end;
  if(section){
    fprintf(stderr,"Dump moplist section: %s, Actions: %d\n",
      section,matches->pcount - matches->start);fflush(stdout);
    start = matches->start;
    end   = matches->pcount;
  }
  else {
    fprintf(stderr,"Dump moplist section: Common, Actions: %d\n",matches->start);
    start = 0;
    end   = matches->start;
  }
  for(i=start;i<end;i++){
    fprintf(stderr,"%d ",i);
    dump_mop(omni,&(matches->list[i]));
  }
}

/* All of the post processing functions will emit info if called with a NULL
first argument. If called, there will always be at least one selected operation*/
void dump_mop(OMNINEXUS *omni, MOPNEXUS *mn){
  fprintf(stderr,"MOP examines:  ");
  if(mn->src==MYVARSMAX){ fprintf(stderr,"input\n");          }
  else {                  fprintf(stderr,"variable %c\n",FROMVAROFF(mn->src)); }
  fprintf(stderr,"  pattern: [");
  if (mn->bits & MATCH_PCRE){
    fprintf(stderr,"PCRE %s",mn->pattern);
  } 
  else if(mn->bits &MATCH_STRING){
    fprintf(stderr,"STRING %s",mn->pattern);
  } 
  else if (mn->bits & MATCH_TOKENS){
    fprintf(stderr,"All Tokens in VLIST ");
    vlist_show(stderr,mn->pattern);
  }
  else if (mn->bits & MATCH_VLIST){
    fprintf(stderr,"VLIST ");
    vlist_show(stderr,mn->pattern);
  } 
  else if (mn->bits & MATCH_NVLIST){ 
    fprintf(stderr,"Token %d in VLIST ",mn->tn);
    vlist_show(stderr,mn->pattern);
  } 
  else if (mn->bits & MATCH_TRUE){ 
    fprintf(stderr,"ALWAYS TRUE");
  } 
  else if (mn->bits & MATCH_EXISTS){ 
    fprintf(stderr,"?%d:",mn->tn);
    vlist_show(stderr,mn->pattern);
  } 
  else if (mn->bits & MATCH_MATH){ 
    fprintf(stderr,"?");
    if(     mn->bits == MATCH_NML){ fprintf(stderr,"?"); }
    else if(mn->bits == MATCH_EQ ){ fprintf(stderr,"="); }
    else if(mn->bits == MATCH_LT ){ fprintf(stderr,"<"); }
    else if(mn->bits == MATCH_GT ){ fprintf(stderr,">"); }
    fprintf(stderr,"%d:",mn->tn);
    vlist_show(stderr,mn->pattern);
  } 
  fprintf(stderr,"]\n");
  if(     mn->bits & MATCH_SUBS){
    if(mn->replace){ fprintf(stderr,"  replace: [%s]\n",mn->replace); }
    else {           fprintf(stderr,"  replace: [<none>]\n");}
  }
  
  fprintf(stderr,"  re(ptr): %p\n", (void *)mn->re);
  fprintf(stderr,"  bits:    %8.8X\n",mn->bits);
  if(mn->true){
    fprintf(stderr,"  TRUE:    ");
    show_mops(omni,mn->true);
    fprintf(stderr,"\n");
  }
  else {
    fprintf(stderr,"  TRUE:    (none)\n");
  }
  if(mn->false){
    fprintf(stderr,"  FALSE:   ");
    show_mops(omni,mn->false);
       fprintf(stderr,"\n");
  }
  else {
    fprintf(stderr,"  FALSE:   (none)\n");
  }
  fprintf(stderr,"\n");
}

void show_mops(OMNINEXUS *omni, int offset){
enum mactions selector;
int  notfirst=0;
int  *idat;
int  imax;
int  i;
enum swi_actions swact;
ESNEXUS *alldata = omni->alldata;
  while(1){
    if(notfirst){ fprintf(stderr,":"); }
    else {        notfirst = 1;        } 
    selector = *(int *)&((alldata->string[offset]));
    offset+=SOI; /* next offset or next operation */
    switch(selector){
     case DO_LISTEND:
       return;
     case DO_CLRV:
       offset = op_clrv(omni,-offset);
       break;
     case DO_MRGV:
       offset = op_mrgv(omni,-offset);
       break;
     case DO_SETC:
       offset = op_setc(omni,-offset);
       break;
     case DO_MATH:
       fprintf(stderr,"?(math expression)");
       offset+=SOI;
       break;
     case DO_VSETV:
       offset = op_vsetv(omni,-offset);
       break;
     case DO_STRV:
       offset = op_strv(omni,-offset);
       break;
     case DO_FMTV:
       offset = op_fmtv(omni,-offset);
       break;
     case DO_VV:
       offset = op_vv(omni,-offset);
       break;
     case DO_NVV:
       offset = op_nvv(omni,-offset);
       break;
     case DO_SHOWV:
       offset = op_showv(omni,-offset);
       break;
     case DO_SHOWNV:
       offset = op_shownv(omni,-offset);
       break;
     case DO_VEMIT:
       offset = op_vemit(omni,-offset);
       break;
     case DO_SEMIT:
       offset = op_semit(omni,-offset);
       break;
     case DO_FEMIT:
       offset = op_femit(omni,-offset);
       break;
     case DO_READ:
       offset = op_read(omni,-offset);
       break;
     case DO_IF:
       offset = dump_if(omni,offset); /* intentionally positive offset */
       break;
     case DO_IFN:
       fprintf(stderr,"n%d", ESP_OFFINT(omni->alldata,offset));
       offset += SOI;
       break;
     case DO_EOL:
       offset = op_eol(omni,-offset);
       break;
     case DO_AFMT:
       fprintf(stderr,"afmt%d", ESP_OFFINT(omni->alldata,offset));
       offset+=SOI;
       break;
     case DO_NFMT:
       fprintf(stderr,"nfmt%d", ESP_OFFINT(omni->alldata,offset));
       offset+=SOI;
       break;
     case DO_HIDE:
       fprintf(stderr,"hide");
       break;
     case DO_SHOW:
       fprintf(stderr,"show");
       break;
     case DO_SKIP:
       fprintf(stderr,"^%d",ESP_OFFINT(omni->alldata,offset));
       offset += SOI;
       break;
     case DO_CALL:
       fprintf(stderr,"&[to %d]",ESP_OFFINT(omni->alldata,offset));
       offset += SOI;
       break;
     case DO_RET:
       fprintf(stderr,"ret");
       break;
     case DO_BRK:
       fprintf(stderr,"brk");
       break;
     case DO_EOF:
       fprintf(stderr,"eof");
       break;
     case DO_EXIT:
       fprintf(stderr,"exit");
       break;
     case DO_FAIL:
       fprintf(stderr,"fail");
       break;
     case DO_PO:
       offset = op_po(omni,-offset);
       break;
     case DO_BHIA:
       offset = op_bhia(omni,-offset);
       break;
     case DO_NPOPV:
       offset = op_npopv(omni,-offset);
       break;
     case DO_SW:
       idat = (int *)ESP_OFFCPTR(omni->alldata,offset);
       imax = *idat;
       fprintf(stderr,"sw%d (",imax);
       for(i=1;i<=imax;i++){  fprintf(stderr," ^%d",idat[i]); }
       fprintf(stderr," )");
       offset += SOI;
       break;
     case DO_SWI:
       swact=ESP_OFFINT(omni->alldata,offset);
       switch(swact){
         case SWI_BIT0:
           fprintf(stderr,"i0"); break;
         case SWI_BIT1:
           fprintf(stderr,"i1"); break;
         case SWI_MV:
           fprintf(stderr,"im"); break;
         case SWI_MP:
           fprintf(stderr,"ip"); break;
         case SWI_MATH:
           fprintf(stderr,"ir"); break;
         default:
           insane(INSFTLPRGERR," impossible DO_SWI case in show_mops");
       }
       offset += SOI;
       break;
     default:
       insane(INSFTLPRGERR," unknown selector in show_mops");
    }; 
  }
}


/* Display slen characters from string, replacing any embedded \0 with rc
*/
void show_perforated_string(FILE *fp, char rc, int slen, char *string){
  int i;
  for(i=0;i<slen;i++,string++){
     if(*string){ fprintf(fp,"%c",*string); }
     else {       fprintf(fp,"%c",rc    );  }
  }
}



/* debugging routine, used mainly for program development but might also be useful for debugging
particularly tricky syntax.  This is very closely related to emit_output.  */
void  dump_commands(OMNINEXUS *omni, FMTNEXUS *fmt){
STRINGNEXUS  *toklist;
char         *srcstring;
int           i,j;
int           jssout;
int           jstart,jend;
int           fstart,fend,finc;
FIELD2NEXUS  *fldlist;
FMTNEXUS     *vptr;
DVNEXUS      *dptr;
FMTNEXUS     *src = fmt; /* to keep it similar to emit_output, here these are always the same */
double        dtmp;
char         *varlist;
char         *v2;
int           status;
int           source;
int           use_smap=0;
unsigned int *smap;
unsigned int  smsize;
FMTNEXUS    **vn;
DVNEXUS      *dn;
ESNEXUS      *piece;

  if(!fmt)insane(INSFTLPRGERR," dump_commands passed invalid fmt value");
  fldlist  =  fmt->fldlist;
  toklist  =  src->toklist;
  if(!omni)insane(INSFTLPRGERR," dump_commands passed invalid omni value");
  vn       =  omni->vn;
  dn       =  omni->dvar;
  piece    =  omni->piece;
  smap     =  omni->smap;
  smsize   =  omni->smsize;

  (void)fprintf(stderr,"toklist strings (from input): %d\n",src->tokcount);
  (void)fprintf(stderr,"  raw length: %d string:>%s<\n",src->dat_str->slen,src->dat_str->string);
  for(i=0;i<src->tokcount;i++){
    (void) fprintf(stderr,"%4d, start %5d, slen %5d, delimit %d string=[",
       i,
       toklist[i].start,
       toklist[i].slen,
       toklist[i].delimit);

       srcstring = src->dat_str->string;

       if(!toklist[i].slen){
         fprintf(stderr,"EMPTY]\n");
       }
       else {
         for(j=toklist[i].start; j<toklist[i].start + toklist[i].slen; j++){
           fprintf(stderr,"%c",srcstring[j]);
         }
         fprintf(stderr,"]\n");
       }
  }
  
  /* The def_str->string may contain embedded '\0' if it contained escape sequences.  
  For instance when "a\123b\0" is processed it becomes "a{b\03b\0".  The caller may swap the
  trailing \0 out but the introduced one will remain.  So use a special print function here
  that shows ~ instead of truncating. */
  
  (void)fprintf(stderr,"  literals: raw length: %d string:>",fmt->def_str->slen);
  show_perforated_string(stderr,'~',fmt->def_str->slen-1,fmt->def_str->string);
  (void)fprintf(stderr,"<\n");

  (void)fprintf(stderr,"fldlist (descriptors from definition -fmt*/-v*): %d\n",fmt->fldcount);
  for(i=0;i<fmt->fldcount;i++){
    source = fldlist[i].source;
    if(source & SRCVRANGE){
      j = fldlist[i].iss;
      if(j<0 || j>=MYVARSMAX){ insane(INSFTLPRGERR," invalid numeric variable for range in dump_commands");}
      dptr=&dn[(int) j];
      fend = fldlist[i].issend;
      status=realends(&j,&j,fend,fend,dptr->dlen); 
      if(status<0){realends_oops(fend,fend,dptr->dlen);}
      if(j>=dptr->dlen){insane(INSFTLERR," not enough elements for range from numeric variable in dump_commands");}
      fstart = dptr->val[j];
      fend   = dptr->val[j+1];
      finc   = dptr->val[j+2]; /* might not be used in some modes */
    }
    else {
      fstart = fldlist[i].iss;
      fend   = fldlist[i].issend;
      finc   = fldlist[i].issinc;  /* might not be used in some modes */
    }
    if(fldlist[i].map){
     /* map overrides the range, uses its size instead */
       dptr     = &omni->dvar[fldlist[i].map-1];
       fstart   = 1;
       fend     = dptr->dlen;
       finc     = 1;
       use_smap = 1;
    }
    (void) fprintf(stderr,          "%4d ", i);
    (void) fprintf(stderr,      "iss:%5d ",fstart);
    (void) fprintf(stderr,   "issend:%5d ",fend );
    (void) fprintf(stderr,   "issinc:%5d ",finc );
    (void) fprintf(stderr,   "source:%3.3x ",source );
    (void) fprintf(stderr,    "ldelim:%d ",fldlist[i].ldelim );
    (void) fprintf(stderr,     "delim:%2.2x ",fldlist[i].delim  );
    (void) fprintf(stderr,      "sort:%d ",fldlist[i].sort   );
    if(fldlist[i].map>0){
      (void) fprintf(stderr,    "map:$%c (range override) ",FROMVAROFF(fldlist[i].map-1));
    }
    else if(fldlist[i].map<0){
      (void) fprintf(stderr,    "ump:$%c (range override) ",FROMVAROFF(-1-fldlist[i].map));
    }
    else {
      (void) fprintf(stderr,    "map:NONE ");
    }
    if(fldlist[i].ppcount==0){
      (void) fprintf(stderr,    "PostProc:NONE ");
    }
    else {
      dump_pal(omni,fldlist[i].ppoff);
    }

    (void) fprintf(stderr,      "text:[");
    if(SRCSELF & source){
      if(source & ISSDEF){ /* these are fmt literals, also used in emit_output. */
        status=realends(&jstart,&jend,fstart,fend,ESP_CLEN(fmt->def_str));
        if(status>=0){
          (void) copy_single_mc(piece, fmt->def_str->string, jstart, jend, ESP_CLEN(fmt->def_str) );
        }
        else {
          realends_oops(jstart, jend, ESP_CLEN(fmt->def_str));
        }
        fprintf(stderr,"%s]\n",piece->string);
      }
      else if(source & ISSDAT){/* these are SET variables, this section only used in dump_commands */
        status=realends(&jstart,&jend,fstart,fend,ESP_CLEN(src->dat_str));
        if(status>=0){
          (void) copy_single_mc(piece, src->dat_str->string, jstart, jend, ESP_CLEN(src->dat_str) );
        }
        else {
          realends_oops(jstart, jend, ESP_CLEN(src->dat_str));
        }
        fprintf(stderr,"%s]\n",piece->string);
      }
      else {
        insane(INSFTLPRGERR," invalid SRC in dump_commands, not ISSDAT or ISSDEF");      
      }
      continue;
    }
    switch (source & SRCMASK){  /* dynamic strings, may be further processed later*/
      case  SRCLINE:
        switch (source & MODEMASK){
          case MODECHAR:
             status=realends(&jstart,&jend,fstart,fend,ESP_CLEN(src->dat_str));
             if(status>0){
               status = copy_single_mc(piece, src->dat_str->string, jstart,jend, ESP_CLEN(src->dat_str) );
               fprintf(stderr,"%s",piece->string);
             }
             else if (status==0){
               fprintf(stderr,"<EMPTY>");
             }
             else { realends_oops(jstart, jend, ESP_CLEN(src->dat_str));}
             break;
          case MODETOK:
             /* convert from relative to absolute token position */
             status=realends(&jstart,&jend,fstart,fend,src->tokcount);
             if(status<0){realends_oops(fstart,fend,src->tokcount);}
             /* If the field uses sorted tokens sort the indicated range and create or rewrite an
             array that maps it into the appropriate order.  */
             if(fldlist[i].sort){
                smap = omni->smap = make_sort_map(smap,&smsize,fldlist[i].sort,
                    src->toklist,src->dat_str->string,jstart,jend,src->tokcount);
                use_smap=1;
             }
             if(finc>0){ 
               for(j=jstart; j<=jend; j+=finc){
                 jssout  = ( use_smap ? smap[j] : j );
                 if(jssout>=0 && jssout < src->tokcount){
                   copy_single_mt(piece, src, jssout );
                   if(*piece->string){ fprintf(stderr,"<%s>",piece->string); }
                   else {              fprintf(stderr,"<EMPTY>");            }
                 }
                 else {
                   fprintf(stderr,"<?Tok %d>",jssout);
                 }
               }
             }
             else {
               for(j=jend; j>=jstart; j+=finc){
                 jssout  = ( use_smap ? smap[j] : j );
                 if(jssout>=0 && jssout < src->tokcount){
                   copy_single_mt(piece, src, jssout );
                   if(*piece->string){ fprintf(stderr,"<%s>",piece->string); }
                   else {              fprintf(stderr,"<EMPTY>");            }
                 }
                 else {
                   fprintf(stderr,"<?Tok %d>",jssout);
                 }
               }
             }
             break;
          case MODENUM:
            insane(INSFTLPRGERR," SRCLINE and MODENUM"); 
         }
         break;
      case  SRCVARS:
        if(fldlist[i].vlist==NULL)insane(INSFTLPRGERR," SRC VARS and no VARS list"); 
        varlist=fldlist[i].vlist;
        switch(source & MODEMASK){
          case MODECHAR:
            for(v2=varlist; *v2 != EOVLIST; v2++){
              vptr=vn[(int) *v2];
              if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARS", *v2);
              status=realends(&jstart,&jend,fstart,fend,ESP_CLEN(vptr->dat_str));
              if(status>0){
                status = copy_single_mc(piece, vptr->dat_str->string, jstart,jend, ESP_CLEN(vptr->dat_str));
                fprintf(stderr,"%s",piece->string);
              }
              else if(status==0){
                fprintf(stderr,"<EMPTY>");
              }
              else {  realends_oops(jstart, jend, ESP_CLEN(vptr->dat_str)); }
            }  
            break;
          case MODETOK:
            for(v2=varlist; *v2 != EOVLIST; v2++){
              vptr=vn[(int) *v2];
              VAR_MUST_BE_SET(vn,v2);
              status=realends(&jstart,&jend,fstart,fend,vptr->tokcount); 
              if(status<0){realends_oops(fstart,fend,vptr->tokcount);}
              /* If the field uses sorted tokens sort the indicated range and create or rewrite an
              array that maps it into the appropriate order.  */
              if(fldlist[i].sort){
                 smap = omni->smap = make_sort_map(smap,&smsize,fldlist[i].sort,
                     vptr->toklist,vptr->dat_str->string,jstart,jend,vptr->tokcount);
                 use_smap=1;
              }
              if(finc>0){                                                                             
                for(j=jstart; j<=jend; j+=finc){                                                      
                  jssout  = ( use_smap ? smap[j] : j );
                  if(jssout>=0 && jssout < vptr->tokcount){                                                    
                     copy_single_mt(piece, vptr, jssout );                                           
                     if(*piece->string){ fprintf(stderr,"<%s>",piece->string); }
                     else {              fprintf(stderr,"<EMPTY>");            }
                   }                                                                                  
                   else {                                                                             
                     fprintf(stderr,"<?Tok %d>",jssout);                                                   
                   }                                                                                  
                }                                                                                     
              }                                                                                       
              else {                                                                                  
                for(j=jend; j>=jstart; j+=finc){                                                      
                  jssout  = ( use_smap ? smap[j] : j );
                  if(jssout>=0 && jssout < vptr->tokcount){                                                     
                    copy_single_mt(piece, vptr, jssout );                                            
                    if(*piece->string){ fprintf(stderr,"<%s>",piece->string); }
                    else {              fprintf(stderr,"<EMPTY>");            }
                  }                                                                                   
                  else {                                                                              
                    fprintf(stderr,"<?Tok %d>",jssout);                                                    
                  }                                                                                   
                }                                                                                     
              }                                                                                       
            }
            break; 
          case MODENUM:
            for(v2=varlist; *v2 != EOVLIST; v2++){
              if(*v2==MYVARSMAX){ /* - , for numeric variable means omni->result */
                fprintf(stderr,"<%le>",omni->result);
                continue;
              }
              dptr=&dn[(int) *v2];
              status=realends(&jstart,&jend,fstart,fend,dptr->dlen); 
              if(status<0){realends_oops(fstart,fend,dptr->dlen);}
              /* If the field uses sorted numbers sort the indicated range and create or rewrite an
              array that maps it into the appropriate order.  */
              if(fldlist[i].sort){
                smap = omni->smap = make_sort_map_num(smap,&smsize,fldlist[i].sort,
                    dptr->val,jstart,jend,dptr->dlen);
                use_smap=1;
              }
              if(finc>0){                                                                             
                for(j=jstart; j<=jend; j+=finc){                                                      
                  jssout  = ( use_smap ? smap[j] : j );
                  if(jssout>=0 && jssout < dptr->dlen){                                                     
                    fprintf(stderr,"<%le>",dptr->val[j]);
                  }                                                                                   
                  else {                                                                              
                    fprintf(stderr,"<?Cell %d>",j);                                                    
                  }                                                                                   
                }                                                                                     
              }                                                                                       
              else {                                                                                  
                for(j=jend; j>=jstart; j+=finc){                                                      
                  jssout  = ( use_smap ? smap[j] : j );
                  if(jssout>=0 && jssout < dptr->dlen){                                                     
                    fprintf(stderr,"<%le>",dptr->val[j]);
                  }                                                                                   
                  else {                                                                              
                    fprintf(stderr,"<?Cell %d>",j);                                                    
                  }                                                                                   
                }                                                                                     
              }                                                                                       
            }
            break; 
        }
        break;
      case  SRCVARI:
        /* interleave. Token or Numeric mode only */
        switch(source & MODEMASK){
          case MODECHAR:
            insane(INSFTLERR," VARI access only with -mt, -mn"); 
            break;
          case MODETOK:
            varlist=fldlist[i].vlist;
            for(v2=varlist; *v2 != EOVLIST; v2++){ VAR_MUST_BE_SET(vn,v2); }
            status=realends(&jstart,&jend,fstart,fend,var_max_tcount(varlist,vn)); 
            if(status<0){realends_oops(fstart,fend,var_max_tcount(varlist,vn));}
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                jssout  = ( use_smap ? smap[j] : j );  /* map only, and map always has finc = 1*/
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  vptr=vn[(int) *v2 ];
                  if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARI", *v2);
                  if(jssout>=0 && jssout < vptr->tokcount){                                                     
                    copy_single_mt(piece, vptr, jssout );                                            
                    if(*piece->string){ fprintf(stderr,"<%s>",piece->string); }
                    else {              fprintf(stderr,"<EMPTY>");            }
                  }                                                                                   
                  else {                                                                              
                    fprintf(stderr,"<?Tok %d>",jssout);                                                    
                  }                                                                                   
                }     
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  vptr=vn[(int) *v2 ];
                  if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARI", *v2);
                  if(j>=0 && j < vptr->tokcount){                                                     
                    copy_single_mt(piece, vptr, j );                                            
                    if(*piece->string){ fprintf(stderr,"<%s>",piece->string); }
                    else {              fprintf(stderr,"<EMPTY>");            }
                  }                                                                                   
                  else {                                                                              
                    fprintf(stderr,"<?Tok %d>",j);                                                    
                  }                                                                                   
                }     
              }
            }
            break;
          case MODENUM:
            varlist=fldlist[i].vlist;
            status=realends(&jstart,&jend,fstart,fend,nvar_max_size(varlist,dn)); 
            if(status<0){realends_oops(fstart,fend,var_max_tcount(varlist,vn));}
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                jssout  = ( use_smap ? smap[j] : j );  /* map only, and map always has finc = 1*/
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  if(*v2==MYVARSMAX){  fprintf(stderr,"<%le>",omni->result); continue; }
                  dptr=&dn[(int) *v2 ];
                  if(jssout>=0 && jssout < dptr->dlen){
                         fprintf(stderr,"<%le>",dptr->val[j]); }                                                                                   
                  else { fprintf(stderr,"<?Cell %d>",j);       }                                                                                   
                }     
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  if(*v2==MYVARSMAX){  fprintf(stderr,"<%le>",omni->result); continue; }
                  dptr=&dn[(int) *v2 ];
                  if(j>=0 && j < dptr->dlen){ fprintf(stderr,"<%le>",dptr->val[j]); }                                                                                   
                  else {                      fprintf(stderr,"<?Cell %d>",j);       }                                                                                   
                }     
              }
            }
            break;
        }
        break;
      case  SRCVARF:
        /* interleave with default. Token or Numeric mode only */
        switch(source & MODEMASK){
          case MODECHAR:
            insane(INSFTLERR," VARF access only with -mt"); 
            break;
          case MODETOK:
            varlist=fldlist[i].vlist;
            for(v2=varlist; *v2 != EOVLIST; v2++){ VAR_MUST_BE_SET(vn,v2); }
            status=realends(&jstart,&jend,fstart,fend,var_max_tcount(varlist,vn)); 
            if(status<0){realends_oops(fstart,fend,var_max_tcount(varlist,vn));}
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                jssout  = ( use_smap ? smap[j] : j );  /* map only, and map always has finc = 1*/
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  vptr=vn[(int) *v2 ];
                  if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARF", *v2);
                  if(jssout>=0 && jssout < vptr->tokcount){                                                     
                    copy_single_mt(piece, vptr, jssout );                                            
                  }                                                                                   
                  else {                                                                              
                    copy_single_mt(piece, vptr, 0 );                                            
                  }                                                                                   
                  if(*piece->string){ fprintf(stderr,"<%s>",piece->string); }
                  else {              fprintf(stderr,"<EMPTY>");            }
                }     
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  vptr=vn[(int) *v2 ];
                  if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARF", *v2);
                  if(j>=0 && j < vptr->tokcount){                                                     
                    copy_single_mt(piece, vptr, j );                                            
                  }                                                                                   
                  else {                                                                              
                    copy_single_mt(piece, vptr, vptr->tokcount-1 );                                            
                  }                                                                                   
                  if(*piece->string){ fprintf(stderr,"<%s>",piece->string); }
                  else {              fprintf(stderr,"<EMPTY>");            }
                }     
              }
            }
            break;
          case MODENUM:
            varlist=fldlist[i].vlist;
            status=realends(&jstart,&jend,fstart,fend,nvar_max_size(varlist,dn)); 
            if(status<0){realends_oops(fstart,fend,var_max_tcount(varlist,vn));}
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                jssout  = ( use_smap ? smap[j] : j );  /* map only, and map always has finc = 1*/
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  if(*v2==MYVARSMAX){  fprintf(stderr,"<%le>",omni->result); continue; }
                  dptr=&dn[(int) *v2 ];
                  if(jssout>=0 && jssout < dptr->dlen){  dtmp = dptr->val[j]; }                                                                                   
                  else {                                 dtmp = dptr->val[0]; }                                                                                   
                  fprintf(stderr,"<%le>",dtmp);
                }     
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  if(*v2==MYVARSMAX){  fprintf(stderr,"<%le>",omni->result); continue; }
                  dptr=&dn[(int) *v2 ];
                  if(j>=0 && j < dptr->dlen){  dtmp = dptr->val[j]; }                                                                                   
                  else {                       dtmp = dptr->val[0]; }                                                                                   
                  fprintf(stderr,"<%le>",dtmp);
                }     
              }
            }
            break;
        }
        break;
      default:
        insane(INSFTLPRGERR," invalid SRC in dump_commands");      
    }
    (void) fprintf(stderr,"]\n");
  }
}


void dump_po(PONEXUS *po, char *string){
  (void)fprintf(stderr,"%s\n",string);
  (void)fprintf(stderr,"\n options:   %5.5X",po->parse_options);
     if(po->parse_options & PARSE_ESCAPES      )(void)fprintf(stderr," ESCAPES");
     if(po->parse_options & PARSE_DBLQUOTES    )(void)fprintf(stderr," DBLQUOTES");
     if(po->parse_options & PARSE_STRIPDQUOTES )(void)fprintf(stderr," STRIPDQUOTES");
     if(po->parse_options & PARSE_SINGLEDEL    )(void)fprintf(stderr," SINGLEDEL");
     (void)fprintf(stderr,"\n");
  (void)fprintf(stderr," delim len  %d val [%s]\n",po->dllen,po->delimit);
  (void)fprintf(stderr," mdelim len %d val [%s]\n",po->mdllen,po->mdelimit);
}

/* returns a single result.  Status is the length (does not include terminator, so may be 0)
or -1 if no matching token found. Start and end are relative positions (1->N).*/
int copy_single_mc(ESNEXUS *result, char *src, int start, int end, int slen){
int   status;

  if(!src){
    insane(INSFTLERR," undefined character input, most likely use of a variable before it is set");
  }
  /* This is messy because the characters can be referenced in either direction */
  if(start >= slen || end <0){
    *(result->string) = '\0';
    result->slen      = 1;
    return(0);  /* this happens on things like [mc:100,120] on a 5 character line */
  }
  if(start<0)start=0;          /* mc range outside of data must be ignored. */
  if(end>=slen)end=slen-1;
  EXT_REALLOC(result->string,result->salloc,end-start+2,MEMOOPS);
  strncpy(result->string,&(src[start]),end-start+1);
  status = end-start+1;
  result->slen=status+1;  /* includes terminator in length */
  if(status>0)result->string[status]='\0';
  return(status);
}

/* returns a single result.  Status is the length (does not include terminator, so may be 0)
or -1 if no matching token found. Tok must always refer to an existing token.  Tok
is an absolute position (0->Tokcount-1).  Returns the delimiter for this token. */
char copy_single_mt(ESNEXUS *result, FMTNEXUS *work, int tok){
  if(!(work->tokcount)){
    insane(INSFTLERR," undefined token input, most likely use of a variable before it is set");
  }
  if(!work->toklist[tok].slen){
    /* empty token.  This can happen when -s is used with ",,," or in some conversions of
    match_* results to tokens */
    *(result->string) = '\0';
    result->slen      = 1;
  }
  else {
    EXT_REALLOC(result->string,result->salloc,(work->toklist[tok].slen+1),MEMOOPS);
    strncpy(result->string,&(work->dat_str->string[work->toklist[tok].start]),
       work->toklist[tok].slen);
    result->string[work->toklist[tok].slen]='\0';
    result->slen=work->toklist[tok].slen + 1; /* includes terminator */
  }
  return(work->toklist[tok].delimit);
}


void dump_vars(OMNINEXUS *omni){
int i;
FMTNEXUS *var;
  for(i=0;i<MYVARSMAX;i++){
    var=omni->vn[i];
    dump_var(omni,var,i);
  }
}

void dump_var(OMNINEXUS *omni, FMTNEXUS *var, int which){
  if(var){
    fflush(lcl_stdout[0]);
    if(var->def_str->slen > 1){ 
      (void)fprintf(stderr,"Current var: %c type: Defined\n",FROMVAROFF(which)); 
      dump_commands(omni, var);
      (void)fprintf(stderr,"+++++++++++++++++++++++++++++++++++++++++\n");
    }
    else {
      (void)fprintf(stderr,"Current var: %c type: Set Status: ", FROMVAROFF(which));
      if(var->dat_str->slen > 0){
        (void)fprintf(stderr,"SET\n");
        dump_commands(omni, var);
        (void)fprintf(stderr,"+++++++++++++++++++++++++++++++++++++++++\n");
      }
      else {
        (void)fprintf(stderr,"CLEAR\n");
      }
    }
    fflush(stderr);
  }
}

void dump_nvar(OMNINEXUS *omni, DVNEXUS *var, int which){
int i;
  if(var){
    fflush(lcl_stdout[0]);
    (void)fprintf(stderr,"Numvar: %c, Elements: %d, Values: ",FROMVAROFF(which),var->dlen);
    fprintf(stderr,"1 %le",var->val[0]);
    if(var->dlen>1){
      for(i=1;i<var->dlen;i++){ fprintf(stderr,", %d %le",i+1,var->val[i]); }
    }
    fprintf(stderr,"\n");
    fflush(stderr);
  }
}

/* Arguments:
   fmt   format specifier OR if efield, the variable that is being appended to.  In the
         second case each append puts on a token.
   accum where the output goes
   src   default input for unqualified [] statements (no v* references)
   
   efield, if exists, do this one field, else, do all the fields in fmt.
      if efield is defined ifeol,ifbol,eol,bol,linenumber,linecount,linelength,linetokesn
      are all ignored
*/
void emit_output(OMNINEXUS *omni, FMTNEXUS *fmt, ESNEXUS *accum, FMTNEXUS *src,
   int ifeol, int ifbol, char *eol, char *bol,
   int linenumber, int linecount, int linelength, int linetokens, FIELD2NEXUS *efield){
int           i,j;
int           jssout;
int           jstart,jend;
int           fstart,fend,finc;
FIELD2NEXUS  *fldlist;
FMTNEXUS     *vptr;
DVNEXUS      *dptr;
int           fldcount;
char         *varlist;
char         *v2;
int           status;
int           linelen;
int           following=0;
int           tok_opt=0;
char          cdelim='\0';
char          pdelim='\0';
int           source;
int           use_smap=0;
double       *dval;
unsigned int *smap;
unsigned int  smsize;
FMTNEXUS    **fn;      
FMTNEXUS    **vn;      
DVNEXUS      *dn;
FMTNEXUS     *var;   
int           curfmt;
ESNEXUS      *piece;


  /* accum must be valid or boom! */
  if(!accum)insane(INSFTLPRGERR," emit_output passed invalid pointer values");
  if(!src)insane(INSFTLPRGERR," emit_output passed invalid pointer values");
  if(!omni)insane(INSFTLPRGERR," dump_commands passed invalid omni value");
  smap    =  omni->smap;
  smsize  =  omni->smsize;
  fn      =  omni->fn;
  vn      =  omni->vn;
  dn      =  omni->dvar;
  var     =  NULL;
  curfmt  =  omni->curfmt;
  piece   =  omni->piece;


  if(efield){
    fldlist  =  efield;
    fldcount =  1;
    if(fmt){  /* single field into a variable, do NOT empty the accumulator */
      accum    = fmt->dat_str;
      var      = fmt; 
    }
    else {    /* single field to output (accum passed in, empty it first ) */
      efield        = NULL;
      if(accum->string){ *(accum->string) = '\0';  } /* empty the accumulator */
      accum->slen   = 1;    /* empty the accumulator, count the terminator */
    }
  }
  else {
    if(!fmt)insane(INSFTLPRGERR," emit_output passed invalid pointer values");
    fldlist       = fmt->fldlist;
    fldcount      = fmt->fldcount; 
    if(accum->string){ *(accum->string) = '\0';  } /* empty the accumulator */
    accum->slen   = 0; /* empty the accumulator */
    linelen       =  ESP_CLEN(fn[curfmt]->dat_str); /* input line length, NOT variable length */
    /* no need to check string sizes at the beginning, accum will hold them */
    if(!ifbol){
    
      accum->slen += sprintf(&(accum->string[accum->slen]),"%s",bol);
    }
    if(linenumber==YES){  /* emit the line number */
      accum->slen += sprintf(&(accum->string[accum->slen]),"%8d:",linecount);
    }
    if(linelength==YES){  /* emit the length of the input line */
      accum->slen += sprintf(&(accum->string[accum->slen]),"%8d:",linelen);
    }
    if(linetokens==YES){  /* emit the tokens on the input line (even if source is a varible)*/
      accum->slen += sprintf(&(accum->string[accum->slen]),"%8d:",fn[curfmt]->tokcount);
    }
    if(accum->slen){ accum->slen++; } /* ES operations below count the terminatorm preceding did not */
  }

  for(i=0;i<fldcount;i++){
    source = fldlist[i].source;
    /* delimiters stay on for any series of token modes, but any intervening MODECHAR or MODENUM resets it  */
    if((source & MODEMASK) != MODETOK){
       following=0; 
       pdelim='\0';
    }
    if(source & SRCVRANGE){
      j = fldlist[i].iss;
      if(j<0 || j>=MYVARSMAX){ insane(INSFTLPRGERR," invalid numeric variable for range in dump_commands");}
      dptr=&dn[(int) j];
      fend = fldlist[i].issend;
      status=realends(&j,&j,fend,fend,dptr->dlen); 
      if(status<0){realends_oops(fend,fend,dptr->dlen);}
      if(j>=dptr->dlen){insane(INSFTLERR," not enough elements for range from numeric variable in dump_commands");}
      fstart = dptr->val[j];
      fend   = dptr->val[j+1];
      finc   = dptr->val[j+2]; /* might not be used in some modes */
    }
    else {
      fstart = fldlist[i].iss;
      fend   = fldlist[i].issend;
      finc   = fldlist[i].issinc;  /* might not be used in some modes */
    }
    if(SRCSELF & source){ /* literals, if this was emit, nothing further would be done */
      status=realends(&jstart,&jend,fstart,fend,ESP_CLEN(fmt->def_str));
      if(status>=0){
        (void) copy_single_mc(piece, fmt->def_str->string, jstart, jend, ESP_CLEN(fmt->def_str) );
      }
      else {
        realends_oops(jstart, jend, ESP_CLEN(fmt->def_str));
      }
      (void) field_postprocess(accum, omni, '\0', '\0', &fldlist[i], OPT_FOUND, NULL);
      continue;
    }
    if(fldlist[i].map){
     /* map overrides the range, uses its size instead */
       smap     = map_to_smap(omni,fldlist[i].map);
       dptr     = &omni->dvar[(fldlist[i].map > 0 ? fldlist[i].map - 1 : -1 -fldlist[i].map)];
       fstart   = 1;
       fend     = dptr->dlen;
       finc     = 1;
       use_smap = 1;
    }
    switch (source & SRCMASK){  /* dynamic strings, may be further processed later*/
     case  SRCLINE:
       switch (source & MODEMASK){
         case MODECHAR:
            status=realends(&jstart,&jend,fstart,fend,ESP_CLEN(src->dat_str));
            if(status>=0){
              (void) copy_single_mc(piece, src->dat_str->string, jstart, jend, ESP_CLEN(src->dat_str) );
              (void) field_postprocess(accum, omni, '\0', '\0', &fldlist[i], OPT_FOUND, var);
            }
            else { realends_oops(jstart, jend, ESP_CLEN(src->dat_str));  }
            break;
         case MODETOK:
            /* convert from relative to absolute token position */
            status=realends(&jstart,&jend,fstart,fend,src->tokcount);
            if(status<0){realends_oops(fstart,fend,src->tokcount);}
            /* If the field uses sorted tokens sort the indicated range and create or rewrite an
            array that maps it into the appropriate order.  */
            if(fldlist[i].sort){
               smap = omni->smap = make_sort_map(smap,&smsize,fldlist[i].sort,
                   src->toklist,src->dat_str->string,jstart,jend,src->tokcount);
               use_smap=1;
            }
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                tok_opt=OPT_NONE;
                jssout  = ( use_smap ? smap[j] : j );
                if(jssout>=0 && jssout < src->tokcount){
                  cdelim  = copy_single_mt(piece, src, jssout );
                  /* the position could exist but the token be empty, ie with -s and ,,, */
                  if(!*piece->string){ tok_opt |= OPT_EMPTY; }
                  tok_opt |= OPT_FOUND;
                }
                else {
                  es_clear(piece);                                                                              
                  cdelim  = '\0';
                }
                if(following){ tok_opt  |= OPT_FOLLOWING; }
                else {         following =1;              }
                pdelim = field_postprocess(accum, omni, pdelim, cdelim, &fldlist[i], tok_opt, var);
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                tok_opt=OPT_NONE;
                jssout  = ( use_smap ? smap[j] : j );
                if(jssout>=0 && jssout < src->tokcount){
                  cdelim  = copy_single_mt(piece, src, jssout );
                  if(!*piece->string){ tok_opt |= OPT_EMPTY; }
                  tok_opt |= OPT_FOUND;
                }
                else {
                  es_clear(piece);                                                                              
                  cdelim  = '\0';
                }
                if(following){ tok_opt  |= OPT_FOLLOWING; }
                else {         following =1;              }
                pdelim = field_postprocess(accum, omni, pdelim, cdelim, &fldlist[i], tok_opt, var);
              }
            }
            break;
        }
        break;
     case  SRCVARS:
       if(fldlist[i].vlist==NULL)insane(INSFTLPRGERR," SRC VARS and no VARS list"); 
       varlist=fldlist[i].vlist;
       switch(source & MODEMASK){
         case MODECHAR:
           for(v2=varlist; *v2 != EOVLIST; v2++){
             vptr=vn[(int) *v2 ];
             status=realends(&jstart,&jend,fstart,fend,ESP_CLEN(vptr->dat_str));
             if(status>=0){
               status = copy_single_mc(piece, vptr->dat_str->string, jstart,jend, ESP_CLEN(vptr->dat_str));
               (void) field_postprocess(accum, omni, '\0','\0', &fldlist[i], OPT_FOUND, var);
             }
             else {  realends_oops(jstart, jend, ESP_CLEN(vptr->dat_str)); }
           }  
           break;
         case MODETOK:
           for(v2=varlist; *v2 != EOVLIST; v2++){
             vptr=vn[(int) *v2 ];
             VAR_MUST_BE_SET(vn,v2);
             status=realends(&jstart,&jend,fstart,fend,vptr->tokcount); 
             if(status<0){realends_oops(fstart,fend,vptr->tokcount);}
             /* If the field uses sorted tokens sort the indicated range and create or rewrite an
             array that maps it into the appropriate order.  */
             if(fldlist[i].sort){
                smap = omni->smap = make_sort_map(smap,&smsize,fldlist[i].sort,
                    vptr->toklist,vptr->dat_str->string,jstart,jend,vptr->tokcount);
                use_smap=1;
             }
             if(finc>0){                                                                             
               for(j=jstart; j<=jend; j+=finc){                                                      
                 tok_opt=OPT_NONE;
                 jssout  = ( use_smap ? smap[j] : j );
                 if(jssout>=0 && jssout < vptr->tokcount){                                                     
                   cdelim  = copy_single_mt(piece, vptr, jssout );                                            
                   if(!*piece->string){ tok_opt |= OPT_EMPTY; }
                   tok_opt |= OPT_FOUND;
                 }                                                                                   
                 else {                                                                              
                   es_clear(piece);                                                                              
                   cdelim  = '\0';
                 }                                                                                   
                 if(following){ tok_opt  |= OPT_FOLLOWING; }
                 else {         following =1;              }
                 pdelim = field_postprocess(accum, omni, pdelim, cdelim, &fldlist[i], tok_opt, var);
               }                                                                                     
             }                                                                                       
             else {                                                                                  
               for(j=jend; j>=jstart; j+=finc){                                                      
                 tok_opt=OPT_NONE;
                 jssout  = ( use_smap ? smap[j] : j );
                 if(jssout>=0 && jssout < vptr->tokcount){                                                     
                   cdelim  = copy_single_mt(piece, vptr, jssout );                                            
                   if(!*piece->string){ tok_opt |= OPT_EMPTY; }
                   tok_opt |= OPT_FOUND;
                 }                                                                                   
                 else {
                   es_clear(piece);                                                                              
                   cdelim  = '\0';
                 }                                                                                   
                 if(following){ tok_opt  |= OPT_FOLLOWING; }
                 else {         following =1;              }
                 pdelim = field_postprocess(accum, omni, pdelim, cdelim, &fldlist[i], tok_opt, var);
               }                                                                                     
             }                                                                                       
           }
           break; 
         case MODENUM:
           for(v2=varlist; *v2 != EOVLIST; v2++){
             if(*v2==MYVARSMAX){  
               field_postprocess_num(accum, omni, &fldlist[i], tok_opt, &omni->result, var);
               following =1; continue;
             }
             dptr=&dn[(int) *v2 ];
             status=realends(&jstart,&jend,fstart,fend,dptr->dlen); 
             if(status<0){realends_oops(fstart,fend,dptr->dlen);}
             /* If the field uses sorted numbers sort the indicated range and create or rewrite an
             array that maps it into the appropriate order.  */
             if(fldlist[i].sort){
               smap = omni->smap = make_sort_map_num(smap,&smsize,fldlist[i].sort,
                   dptr->val,jstart,jend,dptr->dlen);
               use_smap=1;
             }
             if(finc>0){                                                                             
               for(j=jstart, tok_opt=OPT_NONE; j<=jend; j+=finc){                                                      
                 jssout  = ( use_smap ? smap[j] : j );
                 if(jssout>=0 && jssout < dptr->dlen){                                                     
                                     dval=&(dptr->val[jssout]); }                                                                 
                 else {              dval=NULL;                 }                                                                                   
                 if(following){      tok_opt  |= OPT_FOLLOWING; }
                 else {              following =1;              }
                 field_postprocess_num(accum, omni, &fldlist[i], tok_opt, dval, var);
               }                                                                                     
             }                                                                                       
             else {                                                                                  
               for(j=jend, tok_opt=OPT_NONE; j>=jstart; j+=finc){                                                      
                 tok_opt=OPT_NONE;
                 jssout  = ( use_smap ? smap[j] : j );
                 if(jssout>=0 && jssout < dptr->dlen){                                                     
                                     dval=&(dptr->val[jssout]); }                                                                                   
                 else {              dval=NULL;                 }                                                                                   
                 if(following){      tok_opt  |= OPT_FOLLOWING; }
                 else {              following =1;              }
                 field_postprocess_num(accum, omni, &fldlist[i], tok_opt, dval, var);
               }                                                                                     
             }                                                                                       
           }
           break; 
       }
       break;
     case  SRCVARI:
        /* interleave. Token or Numeric mode only */
        switch(source & MODEMASK){
          case MODECHAR:
            insane(INSFTLERR," VARI access only with -mt, -mn"); 
            break;
          case MODETOK:
            varlist=fldlist[i].vlist;
            for(v2=varlist; *v2 != EOVLIST; v2++){ VAR_MUST_BE_SET(vn,v2); }
            status=realends(&jstart,&jend,fstart,fend,var_max_tcount(varlist,vn)); 
            if(status<0){realends_oops(fstart,fend,var_max_tcount(varlist,vn));}
            tok_opt=OPT_NONE;
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                jssout  = ( use_smap ? smap[j] : j );  /* map only, and map always has finc = 1*/
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  vptr=vn[(int) *v2 ];
                  if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARI", *v2);
                  if(jssout>=0 && jssout < vptr->tokcount){                                                     
                    cdelim = copy_single_mt(piece, vptr, jssout );                                            
                    if(!*piece->string){ tok_opt |= OPT_EMPTY; }
                    tok_opt |= OPT_FOUND;
                  }                                                                                   
                  else {                                                                              
                    es_clear(piece);                                                                              
                    cdelim  = '\0';
                  }
                  if(following){ tok_opt  |= OPT_FOLLOWING; }
                  else {         following =1;              }
                  pdelim = field_postprocess(accum, omni, pdelim, cdelim, &fldlist[i], tok_opt, var);
                }
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  vptr=vn[(int) *v2 ];
                  if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARI", *v2);
                  if(j>=0 && j < vptr->tokcount){                                                     
                    cdelim  = copy_single_mt(piece, vptr, j );                                            
                    if(!*piece->string){ tok_opt |= OPT_EMPTY; }
                    tok_opt |= OPT_FOUND;
                  }                                                                                   
                  else {                                                                              
                    es_clear(piece);                                                                              
                    cdelim  = '\0';
                  }                                                                                   
                  if(following){ tok_opt  |= OPT_FOLLOWING; }
                  else {         following =1;              }
                  pdelim = field_postprocess(accum, omni, pdelim, cdelim, &fldlist[i], tok_opt, var);
                }
              }
            }
            break;
          case MODENUM:
            varlist=fldlist[i].vlist;
            status=realends(&jstart,&jend,fstart,fend,nvar_max_size(varlist,dn)); 
            if(status<0){realends_oops(fstart,fend,var_max_tcount(varlist,vn));}
            tok_opt=OPT_NONE;
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                jssout  = ( use_smap ? smap[j] : j );  /* map only, and map always has finc = 1*/
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  if(*v2==MYVARSMAX){  
                    field_postprocess_num(accum, omni, &fldlist[i], tok_opt, &omni->result, var);
                    following =1; continue;
                  }
                  dptr=&dn[(int) *v2 ];
                  if(jssout>=0 && jssout < dptr->dlen){ dval=&(dptr->val[jssout]); }                                                                                   
                  else {                                dval=NULL;                 }
                  if(following){                        tok_opt  |= OPT_FOLLOWING; }
                  else {                                following =1;              }
                  field_postprocess_num(accum, omni, &fldlist[i], tok_opt, dval, var);
                }
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  if(*v2==MYVARSMAX){  
                    field_postprocess_num(accum, omni, &fldlist[i], tok_opt, &omni->result, var);
                    following =1; continue;
                  }
                  dptr=&dn[(int) *v2 ];
                  if(j>=0 && j < dptr->dlen){   dval=&(dptr->val[j]);      }                                                                                   
                  else {                        dval=NULL;                 }
                  if(following){                tok_opt  |= OPT_FOLLOWING; }
                  else {                        following =1;              }
                  field_postprocess_num(accum, omni, &fldlist[i], tok_opt, dval, var);
                }
              }
            }
            break;
        }
       break;
     case  SRCVARF:
        /* interleave with fill . Token or Numeric mode only */
        switch(source & MODEMASK){
          case MODECHAR:
            insane(INSFTLERR," VARF access only with -mt -mn"); 
            break;
          case MODETOK:
            varlist=fldlist[i].vlist;
            for(v2=varlist; *v2 != EOVLIST; v2++){ VAR_MUST_BE_SET(vn,v2); }
            status=realends(&jstart,&jend,fstart,fend,var_max_tcount(varlist,vn)); 
            if(status<0){realends_oops(fstart,fend,var_max_tcount(varlist,vn));}
            tok_opt=OPT_NONE;
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                jssout  = ( use_smap ? smap[j] : j );  /* map only, and map always has finc = 1*/
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  vptr=vn[(int) *v2 ];
                  if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARF", *v2);
                  if(jssout>=0 && jssout < vptr->tokcount){   cdelim = copy_single_mt(piece, vptr, jssout ); }                                                                                   
                  else {                            cdelim = copy_single_mt(piece, vptr, 0 ); }                                                                                   
                  if(!*piece->string){ tok_opt |= OPT_EMPTY; }
                  tok_opt |= OPT_FOUND;
                  if(following){      tok_opt   |= OPT_FOLLOWING; }
                  else {              following  = 1;             }
                  pdelim = field_postprocess(accum, omni, pdelim, cdelim, &fldlist[i], tok_opt, var);
                }
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  vptr=vn[(int) *v2 ];
                  if(!vptr)insane2_var(INSFTLPRGERR," VAR is undefined, mode var = ","SRCVARF", *v2);
                  if(j>=0 && j < vptr->tokcount){   cdelim = copy_single_mt(piece, vptr, j );                  }                                                                                   
                  else {                            cdelim = copy_single_mt(piece, vptr, vptr->tokcount-1 );   }                                                                                   
                  if(!*piece->string){ tok_opt |= OPT_EMPTY; }
                  tok_opt |= OPT_FOUND;
                  if(following){      tok_opt   |= OPT_FOLLOWING; }
                  else {              following  = 1;             }
                  pdelim = field_postprocess(accum, omni, pdelim, cdelim, &fldlist[i], tok_opt, var);
                }
              }
            }
            break;
          case MODENUM:
            varlist=fldlist[i].vlist;
            status=realends(&jstart,&jend,fstart,fend,nvar_max_size(varlist,dn)); 
            if(status<0){realends_oops(fstart,fend,var_max_tcount(varlist,vn));}
            tok_opt=OPT_NONE;
            if(finc>0){ 
              for(j=jstart; j<=jend; j+=finc){
                jssout  = ( use_smap ? smap[j] : j );  /* map only, and map always has finc = 1*/
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  if(*v2==MYVARSMAX){  
                    field_postprocess_num(accum, omni, &fldlist[i], tok_opt, &omni->result, var);
                    following =1; continue;
                  }
                  dptr=&dn[(int) *v2 ];
                  if(jssout>=0 && jssout < dptr->dlen){   dval=&(dptr->val[jssout]);            }                                                                        
                  else {                        dval=&(dptr->val[0]);            }                                                                        
                  if(following){                tok_opt   |= OPT_FOLLOWING;      }
                  else {                        following  = 1;                  }
                  field_postprocess_num(accum, omni, &fldlist[i], tok_opt, dval, var);
                }
              }
            }
            else {
              for(j=jend; j>=jstart; j+=finc){
                for(v2=varlist; *v2 != EOVLIST; v2++){
                  if(*v2==MYVARSMAX){  
                    field_postprocess_num(accum, omni, &fldlist[i], tok_opt, &omni->result, var);
                    following =1; continue;
                  }
                  dptr=&dn[(int) *v2 ];
                  if(j>=0 && j < dptr->dlen){   dval=&(dptr->val[j]);            }                                                                                   
                  else {                        dval=&(dptr->val[dptr->dlen-1]); }                                                                                   
                  if(following){                tok_opt   |= OPT_FOLLOWING;      }
                  else {                        following  = 1;                  }
                  field_postprocess_num(accum, omni, &fldlist[i], tok_opt, dval, var);
                }
              }
            }
            break;
        }
        break;
     default:
       insane(INSFTLPRGERR," invalid SRC in emit_output");      
    }
  } /* all fields processed */
  if(!ifeol){
      es_strcat(accum,eol,strlen(eol),ACCUMINC,MEMOOPS);
  }
  if(accum->slen){ /* only if there is something in it, else, access before string! */
    ESP_LASTVAL(accum)='\0'; /* be sure that it is terminated */
  }
}

/* the various types of post processing of a field's string after it has been extracted.
If delim is not 0 then it is used (if a delimiter is required, else it uses the field delimiter value. 
This is used to pass in the mdelim for interleaved values. 
Options can be 0 or have the OPT_FOUND, OPT_FOLLOWING bits set.


Note that the token carries along the delimiter that ended it, and that is passed in via delim,
but what we need to put in front of a following token is the delimiter from the previous token,
so that is passed in as pdelim, and is returned by the function.  In other words
  tok1: foo has delimiter: ' '
  tok2: woo has delimiter: ','
  tok3: moo has delimiter: ';'
  
  should be output as <tok1> <tok2>,<tok3>, but when this routine is called with tok2 and its delimiter,
  it needs the previous delimiter since we don't know if this is a list until following tokens are seen.

if var is set we are adding to variable.  Keep track of tokens in that case.
 */
char field_postprocess(ESNEXUS *accum, OMNINEXUS *omni, char pdelim, char delim, 
  FIELD2NEXUS *fld,  int options, FMTNEXUS *var){
int cdelim;
int selector=0;
int *offset=NULL;
STRINGNEXUS *tok=NULL; /* this silences a gcc may be used uninitialized warning  */
ESNEXUS *alldata = omni->alldata;
ESNEXUS *piece   = omni->piece;
    cdelim=0;  /* assume no delimiter */
    if(var){
      EXT_REALLOC2(var->toklist,var->tokalloc,var->tokcount+1,var->tokcount+16,sizeof(STRINGNEXUS),MEMOOPS);
      tok        = &var->toklist[var->tokcount];
    }
    if(fld->ppcount){
      selector = *(int *)&((alldata->string[fld->ppoff]));
      offset   =  (int *)&((alldata->string[fld->ppoff+SOI]));
    }
    if(selector & DO_RS   ){ /* this must be consumed, one way or the other */
      if((options & OPT_EMPTY) || (!(options & OPT_FOUND))){fillhole(omni, *offset++); } 
      else { offset++; }
    }
    if(fld->ldelim == DELIMNONE){ pdelim = '\0'; }  /* none overrides everything else */
    if((options & OPT_FOLLOWING) && pdelim){        /* we are doing delimiters of some type*/
       es_strcat(accum,&pdelim,1,ACCUMINC,MEMOOPS);
    }
    if(var){ tok->start = ESP_CLEN(accum); }
 
    if(selector){
      if(selector & DO_DESC ){descit(  omni, *offset++); }
      if(selector & DO_RCD  ){rcit(    omni, *offset++); }
      if(selector & DO_RTD  ){rtit(    omni, *offset++); }
      if(selector & DO_PS   ){psit(    omni, *offset++); }
      if(selector & DO_SLASH){slashit( omni, *offset++); }
      if(selector & DO_FFF  ){ffit(    omni, *offset++, NULL); }
      if(selector & DO_PAD  ){padit(   omni, *offset++); }
      if(selector & DO_TRIM ){trimit(  omni, *offset++); }
      if(selector & DO_JUST ){justit(  omni, *offset++); }
      if(selector & DO_CASE ){caseit(  omni, *offset++); }
    }

    es_strcat(accum,piece->string,ESP_CLEN(piece),ACCUMINC,MEMOOPS);
         
    if(options & OPT_FOUND){  /* could have been OPT_EMPTY too, but it will have a delim value */
      switch (fld->ldelim){
        case DELIMTOK:  cdelim = delim;       break;
        case DELIMVAL:  cdelim = fld->delim;  break;
        case DELIMNONE: cdelim = '\0';        break;
        default: insane(INSFTLPRGERR," invalid delimiter oaction in field_postprocess");
      }
    }
    else {
      switch (fld->ldelim){
        case DELIMTOK:  /* there is not token, so no token delimiter, fail over to using the field value */
        case DELIMVAL:  cdelim = fld->delim;  break;
        case DELIMNONE: cdelim = '\0';        break;
        default: insane(INSFTLPRGERR," invalid delimiter oaction in field_postprocess");
      }
    }
    if(var){
      tok->delimit = cdelim; 
      tok->slen    = ESP_CLEN(accum) - tok->start;
      var->tokcount++;
    }
    return(cdelim);  /* pdelim for the next round */
} 

/* This ia a VERY cut down version of field_postprocess, which only applies the fields
appropriate for a double value formatting.  There is no delimiter in numeric variables
so if one is to be applied it comes from the fld structure.

if var is set we are adding to variable.  Keep track of tokens in that case.
 */
void field_postprocess_num(ESNEXUS *accum, OMNINEXUS *omni, 
  FIELD2NEXUS *fld,  int options, double *dval, FMTNEXUS *var){
char pdelim;
int selector=0;
int *offset=NULL;
STRINGNEXUS *tok=NULL; /* this silences a gcc may be used uninitialized warning  */
ESNEXUS *alldata = omni->alldata;
ESNEXUS *piece   = omni->piece;
    if(var){
      EXT_REALLOC2(var->toklist,var->tokalloc,var->tokcount+1,var->tokcount+16,sizeof(STRINGNEXUS),MEMOOPS);
      tok        = &var->toklist[var->tokcount];
    }
    if(fld->ppcount){
      selector = *(int *)&((alldata->string[fld->ppoff]));
      offset   =  (int *)&((alldata->string[fld->ppoff+SOI]));
    }
    if(fld->ldelim == DELIMNONE){ pdelim = '\0'; }  /* none overrides everything else */
    else {                        pdelim = fld->delim; }
    es_clear(omni->piece);                                                                              
    if((options & OPT_FOLLOWING) && pdelim){        /* we are doing delimiters of some type*/
       es_strcat(accum,&pdelim,1,ACCUMINC,MEMOOPS);
    }
    if(var){ tok->start = ESP_CLEN(accum); }
 
    if(selector & DO_RS   ){ /* this must be consumed, one way or the other */
      if(!dval){            fillhole(omni, *offset++); } 
      else {                                offset++;  }
    }
    /* these must be consumed if specified, but they do not do anything */
    if(selector & ( DO_DESC | DO_RCD | DO_RTD | DO_PS | DO_SLASH)){
       if(selector & DO_DESC ){             offset++;  }
       if(selector & DO_RCD  ){             offset++;  }
       if(selector & DO_RTD  ){             offset++;  }
       if(selector & DO_PS   ){             offset++;  }
       if(selector & DO_SLASH){             offset++;  }
    }
/* no need to test DO_FFF for ffit, if we are in this function it must be set */
    if(dval               ){ffit(    omni, *offset++, dval); } 
    if(selector & DO_PAD  ){padit(   omni, *offset++); }
    if(selector & DO_TRIM ){trimit(  omni, *offset++); }
    if(selector & DO_JUST ){justit(  omni, *offset++); }
    if(selector & DO_CASE ){caseit(  omni, *offset++); }

    es_strcat(accum,piece->string,ESP_CLEN(piece),ACCUMINC,MEMOOPS);
         
    if(var){
      tok->delimit = pdelim; 
      tok->slen    = ESP_CLEN(accum) - tok->start;
      var->tokcount++;
    }
} 


/* init_process_type reads cmd subject to gblparams produces from it:

 fldlist    (how to process those static strings as well as references to
               dynamic ones which may/will be set for each input line )
 fldcount   (number of ranges to process for each line from input file)
 
 syntax of cmd is "string[...]string[...][...]"
 passes strings and [] strings to add_op for further processing.
 
 The handling of most escape sequences is delayed until add_op, but
 \[ and \] are handled here so that \[blah\] can be a literal string.
*/

void init_process_type(OMNINEXUS *omni, FMTNEXUS *fn, FIELDNEXUS *gblparams, int xe){
int  cidx;
int  left;
int  ok;
enum sstates {FINDLEFT,FINDRIGHT};
enum sstates searchstate;
char        *cmd;
int         *fldcount;
FIELD2NEXUS *fldlist;

  if(!fn)insane(INSFTLPRGERR," init_process_type passed invalid fn value");
  cmd         = fn->def_str->string;
  fldlist     = fn->fldlist;
  fldcount    = &(fn->fldcount);
  
  *fldcount=0;
  cidx=0;
  left=0;
  searchstate=FINDLEFT;
  ok=1;
  while(ok){
    switch (cmd[cidx]) {
      case '\0':   /* end of command string */
        switch (searchstate){
          case FINDLEFT:
            add_op(omni,cmd,left,cidx-left,fldlist,fldcount,gblparams,xe);
            ok=0;
            break;
          case FINDRIGHT:
            insane(INSFTLERR," unterminated [ construct in -fmt");
            break;
          default:
            insane(INSFTLPRGERR," 100"); 
        }
        break;
      case '[':    /* hit a left bracket */
        switch (searchstate){
          case FINDLEFT:
            if(cmd[cidx+1]=='['){ /* case of [[, change to \[ */
              cmd[cidx]='\\';
              cidx++;
            }
            else {
              add_op(omni,cmd,left,cidx-left,fldlist,fldcount,gblparams,xe);
              searchstate=FINDRIGHT;
              left=cidx;
            }
            break;
          case FINDRIGHT:
            insane(INSFTLERR," [ out of order in -fmt");
            break;
          default:
            insane(INSFTLPRGERR," 101"); 
        }
        break;
      case ']':    /* hit a right bracket */
        switch (searchstate){
          case FINDLEFT:
            if(cmd[cidx+1]==']'){ /* case of ]], change to \] */
              cmd[cidx]='\\';
              cidx++;
            }
            else {
              insane(INSFTLERR," ] out of order in -fmt");
            }
            break;
          case FINDRIGHT:
            add_op(omni,cmd,left,cidx-left+1,fldlist,fldcount,gblparams,xe);
            searchstate=FINDLEFT;
            left=cidx+1;
            break;
          default:
            insane(INSFTLPRGERR," 102"); 
        }
        break;
      case '\\':    /* escape character, protect [ and ] only */
        if(cmd[cidx+1]==']' || cmd[cidx+1]=='[' )cidx++;
        break;
      default:     /* any other character */
        break;
    }
    cidx++;
  }
  /* in a few situations the effective length may have decreased due to escapes, however, there may
     also be embedded \0 characters for the same reason, so do NOT adjust fn->def_str->slen! */
}

/* variables set -with -vN having only a single deflist reference are actually
SET variables which have been preset.  Fix these here. */
void var_presets(FMTNEXUS **vn){
int       i;
ESNEXUS  *tmp;
FMTNEXUS *var;
  for(i=0; i<MYVARSMAX; i++){
    var=vn[i];
    if(var->def_str->slen > 0 && 
       var->fldcount==1       && 
       var->fldlist[0].source == (SRCSELF | ISSDEF | MODECHAR) ){ /* only literals */
       /* swap def_str and dat_str pointers, (dat is empty at this point, so no harm, no foul) */
       tmp                    = var->dat_str;
       var->dat_str           = var->def_str;
       var->def_str           = tmp;
       /* change the source, data is now in DAT */
       var->fldlist[0].source = (SRCSELF | ISSDAT | MODECHAR);
       /* fix up the toklist, one entry will have been allocated but not yet used.
          Fill it now. */
       var->toklist->start    = 0;
       var->toklist->slen     = ESP_CLEN(var->dat_str);
       var->toklist->delimit  = 0; /* no delimiter */
       var->tokcount          = 1;
    }
  }
}

/* sort first by label then by adpos */
static int  compare_jmp(const void *p1, const void *p2){
int result;
JMPNEXUS *j1 = (JMPNEXUS *)p1;
JMPNEXUS *j2 = (JMPNEXUS *)p2;
  result = strcmp(j1->label,j2->label);
  if( !result){
    result = j1->adpos - j2->adpos;
  }
  return(result);
}

/* for indirect comparison of two strings contained in the global smuggle.  Hopefully
the compiler will optimize most of this away, but it is easier to read this way. */
static int  compare_as(const void *p1, const void *p2){
int result;
unsigned int u1,u2,len1,len2,r1,r2;
STRINGNEXUS *sn1;
STRINGNEXUS *sn2;
char *str1;
char *str2;
  u1   = *((unsigned int*) p1);
  u2   = *((unsigned int*) p2);
  sn1  = &smuggle[u1];
  sn2  = &smuggle[u2];
  str1 = smuggle_str;
  str2 = smuggle_str;
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

/* like above, but opposite collating order. (Change sign just before return.) */
static int  compare_ds(const void *p1, const void *p2){
int result;
unsigned int u1,u2,len1,len2,r1,r2;
STRINGNEXUS *sn1;
STRINGNEXUS *sn2;
char *str1;
char *str2;
  u1   = *((unsigned int*) p1);
  u2   = *((unsigned int*) p2);
  sn1  = &smuggle[u1];
  sn2  = &smuggle[u2];
  str1 = smuggle_str;
  str2 = smuggle_str;
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
  return(-result);
}

/* for indirect case insensitive comparison of two strings contained in the global smuggle.  Hopefully
the compiler will optimize most of this away, but it is easier to read this way. */
static int  compare_ac(const void *p1, const void *p2){
int result;
unsigned int u1,u2,len1,len2,r1,r2;
STRINGNEXUS *sn1;
STRINGNEXUS *sn2;
char *str1;
char *str2;
  u1   = *((unsigned int*) p1);
  u2   = *((unsigned int*) p2);
  sn1  = &smuggle[u1];
  sn2  = &smuggle[u2];
  str1 = smuggle_str;
  str2 = smuggle_str;
  len1 = sn1->slen;
  len2 = sn2->slen;
  r1   = sn1->start;
  r2   = sn2->start;
  if(len1<len2){
    result = lcl_strncasecmp(&str1[r1], &str2[r2], len1);
    if(!result)result=-1;  /* shorter one collates before longer one */
  }
  else if(len1>len2){
    result = lcl_strncasecmp(&str1[r1], &str2[r2], len2);
    if(!result)result=1;  /* longer one collates after shorter one */
  }
  else {
    result = lcl_strncasecmp(&str1[r1], &str2[r2], len1);
  }
  return(result);
}

/* like above, but opposite collating order. (Change sign just before return.) */
static int  compare_dc(const void *p1, const void *p2){
int result;
unsigned int u1,u2,len1,len2,r1,r2;
STRINGNEXUS *sn1;
STRINGNEXUS *sn2;
char *str1;
char *str2;
  u1   = *((unsigned int*) p1);
  u2   = *((unsigned int*) p2);
  sn1  = &smuggle[u1];
  sn2  = &smuggle[u2];
  str1 = smuggle_str;
  str2 = smuggle_str;
  len1 = sn1->slen;
  len2 = sn2->slen;
  r1   = sn1->start;
  r2   = sn2->start;
  if(len1<len2){
    result = lcl_strncasecmp(&str1[r1], &str2[r2], len1);
    if(!result)result=-1;  /* shorter one collates before longer one */
  }
  else if(len1>len2){
    result = lcl_strncasecmp(&str1[r1], &str2[r2], len2);
    if(!result)result=1;  /* longer one collates after shorter one */
  }
  else {
    result = lcl_strncasecmp(&str1[r1], &str2[r2], len1);
  }
  return(-result);
}

/* ascending numeric */
static int  compare_an(const void *p1, const void *p2){
int result;
unsigned int u1,u2,r1,r2,e1,e2;
double d1,d2;
char save1,save2;
STRINGNEXUS *sn1;
STRINGNEXUS *sn2;
char *str1;
char *str2;
  u1    = *((unsigned int*) p1);     
  u2    = *((unsigned int*) p2);     
  sn1   = &smuggle[u1];              
  sn2   = &smuggle[u2];              
  str1  = smuggle_str;
  str2  = smuggle_str;
  r1    = sn1->start;     /* first char of the string */
  r2    = sn2->start;
  e1    = r1 + sn1->slen; /* one char PAST the string*/
  e2    = r2 + sn2->slen;
  save1 = str1[e1];
  save2 = str2[e2];
  str1[e1] = '\0';
  str2[e2] = '\0';
  if(sscanf(&str1[r1],"%lf",&d1) != 1)insane(INSFTLERR," numerical sort on nonnumerical data");
  if(sscanf(&str2[r2],"%lf",&d2) != 1)insane(INSFTLERR," numerical sort on nonnumerical data");
  if(d1<d2){ result = -1; }
  else if(d1>d2){ result =  1; }
  else {result = 0; }
  smuggle_str[e1] = save1;  /* restore these characters */
  smuggle_str[e2] = save2;
  return(result);
}

/* like above, but opposite collating order. (Change sign just before return.) */
static int  compare_dn(const void *p1, const void *p2){
int result;
unsigned int u1,u2,r1,r2,e1,e2;
double d1,d2;
char save1,save2;
STRINGNEXUS *sn1;
STRINGNEXUS *sn2;
char *str1;
char *str2;
  u1    = *((unsigned int*) p1);     
  u2    = *((unsigned int*) p2);     
  sn1   = &smuggle[u1];              
  sn2   = &smuggle[u2];              
  str1  = smuggle_str;
  str2  = smuggle_str;
  r1    = sn1->start;           /* first char of the string */
  r2    = sn2->start;
  e1    = r1 + sn1->slen;       /* one char PAST the string*/
  e2    = r2 + sn2->slen;
  save1 = str1[e1];
  save2 = str2[e2];
  str1[e1] = '\0';
  str2[e2] = '\0';
  if(sscanf(&str1[r1],"%lf",&d1) != 1)insane(INSFTLERR," numerical sort on nonnumerical data");
  if(sscanf(&str2[r2],"%lf",&d2) != 1)insane(INSFTLERR," numerical sort on nonnumerical data");
  if(d1<d2){ result = -1; }
  else if(d1>d2){ result =  1; }
  else {result = 0; }
  smuggle_str[e1] = save1;  /* restore these characters */
  smuggle_str[e2] = save2;
  return(-result);
}

/* ascending numeric on doubles*/
static int  compare_and(const void *p1, const void *p2){
int result;
unsigned int u1,u2;
double d1,d2;
  u1    = *((unsigned int*) p1);     
  u2    = *((unsigned int*) p2);     
  d1   = ((double *)smuggle_str)[u1];              
  d2   = ((double *)smuggle_str)[u2];              
  if(d1<d2){ result = -1; }
  else if(d1>d2){ result =  1; }
  else {result = 0; }
  return(result);
}

/* descending numeric on doubles (Change sign just before return.) */
static int  compare_dnd(const void *p1, const void *p2){
int result;
unsigned int u1,u2;
double d1,d2;
  u1    = *((unsigned int*) p1);     
  u2    = *((unsigned int*) p2);     
  d1   = ((double *)smuggle_str)[u1];              
  d2   = ((double *)smuggle_str)[u2];              
  if(d1<d2){ result = -1; }
  else if(d1>d2){ result =  1; }
  else {result = 0; }
  return(-result);
}

/* create a sort map.  Whatever the start/end are always make the size of smap = end + 1,
if it isn't already, and set all fields <start to -1.   */
unsigned int *make_sort_map(unsigned int *smap,unsigned int *smsize,int sort,
  STRINGNEXUS *list, char *src, int start, int end, int tcount){
int i;
  /* adjust so that only real tokens are sorted (the range may be set to more than the actual data */
  if(start<0)start=0;
  if(end<0)end=0;
  if(end>=tcount)end=tcount-1;
  EXT_REALLOC2(smap,(*smsize),(end+1),(end+128),SOUI,MEMOOPS);
  if(start>=tcount){ /* There is NOTHING to sort, fill it with -1 up to end */
    for(i=0;i<end;i++){    smap[i]=-1; }
  }
  else {
    /* initialize the map up to end */
    for(i=0;i<start;i++){      smap[i]=-1; }
    for(i=start; i<=end; i++){ smap[i]=i;  }
    smuggle     = list;     /* provides access inside qsort to the actual data indirectly */
    smuggle_str = src;      /* provides access inside qsort to the actual data indirectly */
    switch (sort) {
     case SORTAS: qsort((void *)&smap[start],end-start+1,SOUI,compare_as); break;
     case SORTDS: qsort((void *)&smap[start],end-start+1,SOUI,compare_ds); break;
     case SORTAC: qsort((void *)&smap[start],end-start+1,SOUI,compare_ac); break;
     case SORTDC: qsort((void *)&smap[start],end-start+1,SOUI,compare_dc); break;
     case SORTAN: qsort((void *)&smap[start],end-start+1,SOUI,compare_an); break;
     case SORTDN: qsort((void *)&smap[start],end-start+1,SOUI,compare_dn); break;
     default:     insane(INSFTLPRGERR," invalid (text) sort mode encountered");
    }
  }

  return(smap);
}

/* copy a MAP into a sort map.  The smap is made the same size as the MAP. 
smap's are 0->N-1, whereas MAPS are 1-N.  Make that conversion here.  If the nvar
is positive it is a map, if negative, it is an unmap. */
unsigned int *map_to_smap(OMNINEXUS *omni, int nvar){
int i;
int ump;
int itmp;
int i2;
DVNEXUS     *dv;
  if(nvar<0){ump=1; nvar=-1-nvar;}
  else {     ump=0; nvar-=1;     }
  if(nvar<0 || nvar >=MYVARSMAX){
    insane(INSFTLPRGERR," invalid numeric var specified for ump/map in map_to_smap");
  }
  dv = &omni->dvar[nvar];
  EXT_REALLOC2(omni->smap,omni->smsize,dv->dlen,(dv->dlen+128),SOUI,MEMOOPS);
  if(ump){
    for(i=0; i<dv->dlen; i++){ omni->smap[i] = i;  }  /* to detect many to one mapping */
    for(i=0; i<dv->dlen; i++){
      itmp = dv->val[i];
      if(1!=realends(&i2, &i2, itmp, itmp, dv->dlen)){ insane(INSFTLERR," MAP used in ump is invalid"); }
      if(omni->smap[i2]!=i2){
        insane(INSFTLERR," MAP used in ump is invalid, has many to one mapping (like {1,4,3,4})");
      }
      omni->smap[i2] = i; 
    }
  }
  else {
    for(i=0; i<dv->dlen; i++){
      itmp = dv->val[i];
      if(1!=realends(&i2, &i2, itmp, itmp, dv->dlen)){ insane(INSFTLERR," MAP used for map is invalid"); }
      omni->smap[i] = i2;
    }
  }
  return(omni->smap);
}

/* create a sort map for numeric data.  Whatever the start/end are always make the size of smap = end + 1,
if it isn't already, and set all fields <start to -1.   */
unsigned int *make_sort_map_num(unsigned int *smap,unsigned int *smsize,int sort,
  double *list, int start, int end, int tcount){
int i;
  /* adjust so that only real cells are sorted (the range may be set to more than the actual data */
  if(start<0)start=0;
  if(end<0)end=0;
  if(end>=tcount)end=tcount-1;
  EXT_REALLOC2(smap,(*smsize),(end+1),(end+128),SOUI,MEMOOPS);
  if(start>=tcount){ /* There is NOTHING to sort, fill it with -1 up to end */
    for(i=0;i<end;i++){    smap[i]=-1; }
  }
  else {
    /* initialize the map up to end */
    for(i=0;i<start;i++){      smap[i]=-1; }
    for(i=start; i<=end; i++){ smap[i]=i;  }
    smuggle_str  = (char *)list;     /* provides access inside qsort to the actual data indirectly */
    switch (sort) {
     case SORTAN: qsort((void *)&smap[start],end-start+1,SOUI,compare_and); break;
     case SORTDN: qsort((void *)&smap[start],end-start+1,SOUI,compare_dnd); break;
     default:     insane(INSFTLPRGERR," invalid (numeri) sort mode encountered");
    }
  }

  return(smap);
}


/* if user employs only -sc etc. this constructs a corresponding format statment */
 
void regular_to_fmt(ESNEXUS *dst, char *buffer,int sc,int ec, int rm){
    if(rm==ACTEXTRACT){ (void)sprintf(buffer,"[%d,%d]",sc,ec); }
    if(rm==ACTREMOVE){
      if(sc > 1 || sc < 1){ /* sc is a real column measured from the front */
        if    (ec == TO_END || ec == -1){ /* these are the same thing!!! */
                             (void)sprintf(buffer,"[-:m+:d+:1,%d]",sc-1);                 }
        else if(ec != 0) {   (void)sprintf(buffer,"[-:m+:d+:1,%d][-:m+:d+:%d,]",sc-1,ec+1);  }
      }
      else{ 
        if (ec != TO_END || ec == -1){
                             (void)sprintf(buffer,"[-:m+:d+:%d,]",ec+1); }
        else {               (void)sprintf(buffer,"[]");              }
      }
    }
    if(rm==ACTINSITU){
      if(sc > 1 || sc < 1){  
        if (ec != TO_END){ (void)sprintf(buffer,"[-:m+:d+:1,%d][%d,%d][-:m+:d+:%d,]",sc-1,sc,ec,ec+1); }
        else {             (void)sprintf(buffer,"[-:m+:d+:1,%d][%d,%d]",sc-1,sc,ec); }
      }
      else{
        if (ec != TO_END){ (void)sprintf(buffer,"[%d,%d][-:m+:d+:%d,]",sc,ec,ec+1); }
        else {             (void)sprintf(buffer,"[%d,%d]",sc,ec);                }
      }
    }
    dst->slen=0; /* should be that anyway, but just in case... */
    es_strcat(dst,buffer,strlen(buffer),ACCUMINC,MEMOOPS);
}



/* get next line from one or more files.  If any of them terminate,
all must terminate.  Also checks on some error conditions for the presence
of embedded nulls and distinguishes between that and a line that is
too long in the error message.  However, both conditions are fatal
unless null suppression is turned on, in which case input
lines with NULLs are converted as soon as they are read.  This
is not the default state because it slows things down. 

Note:  the terminal character on a normal fgets read on any OS is supposed
to be \n regardless of whether or not the OS encodes it as LF, CRLF, or something
else.  However since it is common to move files from windows to unix, and those
files read on linux really then did end in \r\n, the routine below was
considering the first \r or \n as the end of the line.  However that caused problems
when there were embedded single CR or LF in the file.  Consequently, the current
version now checks the last character to see if it is \n and then converts it
to a \0.  NO OTHER PROCESSING TAKES PLACE!  If it is desired to remove \r on files
transferred from a Windows -> Unix system use the rcds command.  */

int getnextline(char *buffer,int maxwidth,FILE **lcl_stdin,int infiles,
   char *indl, int samelines, int template, int handlenull,int crok){
   
char *cptr;
int i;
int terminated;
int firstchar;
int remwidth;
int status;
static char *hbuffer=NULL;
static int  dirty=0;
static int  warnonce=1;
size_t cterm;
unsigned int sfg_status;

  if(template > 0){
  
    if(hbuffer==NULL){
      hbuffer=malloc(SOC*(maxwidth+1));
      if(hbuffer==NULL)insane(INSFTLERR,MEMOOPS);
    }
    
    status = 1;
    
    /* Note that for the purpose of this template method ONLY a cterm=0 is sufficient
    to indicate an EOF.  If the file happens to end with: text<EOF> without an
    <EOL> that's ok, and cterm will not then be zero.  Also neither the template
    file nor the file it is compared to may contain empty lines.  */
    
    /* ALWAYS get a line from the template.  super_fgets does not leave a \n on the end */
    remwidth=maxwidth;
    sfg_status = super_fgets(buffer, remwidth, lcl_stdin[0],
         &cterm, handlenull);
    if(crok && (sfg_status & SFG_CRLF)){
      /* silently nip off the \r character if present on a CRLF */
      cterm--;
      buffer[cterm]='\0';
    }
    if(cterm  == 0){
      if(dirty)insane(INSFTLERR," input file contained a record not present in the template file");
      status=0;  /* no more templateable (word???) lines */
    }
    else if(sfg_status & SFG_READERROR){
      insane(INSFTLERR," fatal read error from template file.");
    }
    else if(sfg_status & SFG_EMBEDDED_NULL && handlenull < 0){
          insane(INSFTLERR," found embedded null characters in template file.  Use -hnd, -hns, or -hnsubs");
    }
    else {
      if(!dirty){ /* must load data into hbuffer */
        sfg_status = super_fgets(hbuffer, remwidth, lcl_stdin[1],
           &cterm, handlenull);
        if(crok && (sfg_status & SFG_CRLF)){
          /* silently nip off the \r character if present on a CRLF */
          cterm--;
          hbuffer[cterm]='\0';
          dirty=1;
        }
        if( cterm == 0){ /* empty line no more in input, remainder from template, leave dirty=0*/
           if(samelines==YES)insane2(INSFTLERR," present in template, missing in file: ",buffer);
           (void) strcat(buffer,indl);
        }
        else if(sfg_status & SFG_EMBEDDED_NULL && handlenull < 0){
          insane(INSFTLERR," found embedded null characters in file.  Use -hnd, -hns, or -hnsubs");
        }
        else if(sfg_status & SFG_READERROR){
          insane(INSFTLERR," fatal read error from file.");
        }
        else {
          dirty=1;
        }
      }
      if(dirty){
        if(strncmp(buffer,hbuffer,template)==0){ /* this is a match, return the one from hbuffer*/
           (void) strcpy(buffer,hbuffer);
           dirty=0;  /* force read next time */
        }
        else { /* no match */
           if(samelines==YES)insane2(INSFTLERR," present in template, missing in file: ",buffer);
           (void) strcat(buffer,indl);
        }
      }
    }
    return status;
  }
  
  terminated=0;
  firstchar=0;
  remwidth=maxwidth;
  for(i=0;i<infiles;i++){
    if(i>0 && indl != NULL){
      /* put on the line delimiter BEFORE the next line
         except on the FIRST input file and the LAST input file.
         Do this even if the preceding input file had no input line */
      for(cptr=indl;*cptr!='\0';){
        buffer[firstchar]=*cptr;
        cptr++;
        firstchar++;
        if(firstchar >= maxwidth){
           insane(INSFTLERR," sum of input lines was wider than -wl");
        }
      }
    }
    if(lcl_stdin[i]==NULL){ /* This input file already terminated */
      terminated++;
      cterm=0;  /* This wasn't here originally which caused problems because cterm might not be initialized */
    }
    else{
      sfg_status = super_fgets(&buffer[firstchar], remwidth, lcl_stdin[i],
         &cterm, handlenull);
      if(sfg_status != 0){
        if(sfg_status & SFG_READERROR){
          insane(INSFTLERR," fatal read error during processing");
        }
        if(sfg_status & SFG_BUFFER_FULL){
          insane(INSFTLERR," sum of input lines was wider than -wl");
        }
        if(sfg_status & SFG_EMBEDDED_NULL && handlenull < 0){
          insane(INSFTLERR," found embedded null characters.  Use -hnd, -hns, or -hnsubs");
        }
        if(sfg_status & SFG_EOF){
          fclose(lcl_stdin[i]);
          lcl_stdin[i]=NULL;
          terminated++;
          cterm=0;  /* This wasn't here originally which caused problems because cterm might not be initialized */
        }
        if(crok && (sfg_status & SFG_CRLF)){
          /* silently nip off the \r character if present on a CRLF */
          cterm--;
          buffer[firstchar+cterm]='\0';
        }
      }
    }
    remwidth  = maxwidth - cterm;
    firstchar = firstchar + cterm;
  }
  if((samelines==YES) && (terminated != 0) && (terminated != infiles))
     insane(INSFTLERR," input files are different lengths");
  if((terminated != 0) && (terminated != infiles)){
     if(samelines==YES){
       insane(INSFTLERR," input files are different lengths");
     }
     else if(warnonce){
       warnonce=0;
       (void) fprintf( stderr, "WARNING, input files are different lengths, use -nr to truncate to shortest or -eqlen to force exit\n");
     }
  }
  if(terminated == infiles){
    return 0;  /* everything has been read */
  }
  return 1;
}


/* create a partial buffer from the first token plus N tokens more.
If first is NULL it is calculated from the input string.  Returns the number
of tokens found this pass.   Sets *first to NULL if no more data can
be extracted from the line. */

int nextpartialbuffer(char *pbuffer, char **first, int *flen, char **string,
      int ntokens, PONEXUS *po){

int   start,tlen;  /* 1 start variables and a length variable*/
char  delimit;
char *atoken;
char *sstring;
char *hstring;
int   alen,i;
STVNEXUS hold;
  
  if(*string==NULL){
    *first=NULL; /* will need a new first token */
    return 0;    /* will need a new input buffer */
  }
  else if(**string=='\0'){
    *first=NULL;  /* will need a new first token */
    pbuffer[0]='\0';
    return 0;
  }
  hstring=sstring=*string;
  if(*first==NULL){
    *first=strtok_variant(sstring,&hold,po->mdelimit,po->parse_options,"",&delimit,&start,&tlen);
    if(first==NULL){ /* empty line */
      *pbuffer='\0';
      return 0; 
    }
    sstring=NULL;
    (void) strncpy(pbuffer,*first,tlen);
    *flen=alen=tlen;
  }
  else {
    (void) strncpy(pbuffer,*first,*flen);
    alen=*flen;
  }
  pbuffer[alen]='\0';
  for(i=1;i<=ntokens;i++){ /* NOTICE, i starts from 1 here!!! */
      atoken=strtok_variant(sstring,&hold,po->mdelimit,po->parse_options,"",&delimit,&start,&tlen);
      sstring=NULL;
      if(atoken==NULL){ /* No more tokens left */
        *first=NULL; /* will need a new first token */
        return 0;
      }
      else {
        pbuffer[alen]=*(po->mdelimit);
        alen++;
        strncpy(&(pbuffer[alen]),atoken,tlen);
        alen += tlen;
        pbuffer[alen]='\0';
        (*string) = &(hstring[start+tlen]); /* points at delimiter or \0*/
        if(**string == '\0'){  /* all used up */
          *first=NULL; /* will need a new first token */
          return i;
        }
        else { (*string)++; } /* more tokens available */
      }
  }
  return i;
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


FMTNEXUS *FMTNEXUS_init(int xc, int xe, ESNEXUS *common,  char *define, int dlen){
FMTNEXUS *fn=NULL;
  EXT_CALLOC(fn,1,sizeof(FMTNEXUS),MEMOOPS);
  EXT_CALLOC(fn->fldlist,xe,sizeof(FIELD2NEXUS),MEMOOPS);
  fn->fldcount=0;
  EXT_MALLOC(fn->toklist,(xc*sizeof(STRINGNEXUS)),MEMOOPS);
  fn->tokcount=0;
  fn->tokalloc=xc;
  EXT_MALLOC(fn->def_str,sizeof(ESNEXUS),MEMOOPS);
  /* set it to something small if not defined */
  fn->def_str->salloc = ( dlen ? dlen : 32);
  fn->def_str->slen =   ( dlen ? dlen : 0);
  EXT_MALLOC(fn->def_str->string,fn->def_str->salloc,MEMOOPS);
  if(dlen){ strcpy(fn->def_str->string,define); }

  if(common){  fn->dat_str=common; }  /* columns share this one area */
  else {      /* variables each have their own */
    EXT_CALLOC(fn->dat_str,1,sizeof(ESNEXUS),MEMOOPS);
    /* The calloc sets string to NULL and salloc/slen to 0.  If needed these are
    allocated later */
  }

  return fn;
}


void FMTNEXUS_destroy(FMTNEXUS *fn, int shared){
int i;
FIELD2NEXUS *fld;
  if(fn->def_str->string){ free(fn->def_str->string); }
  if(fn->def_str)free(fn->def_str);
  if(!shared){
    if(fn->dat_str->string)free(fn->dat_str->string);
    if(fn->dat_str)free(fn->dat_str);
  }
  if(fn->toklist)free(fn->toklist);
  if(fn->fldlist){
    for(i=0, fld=fn->fldlist; i < fn->fldcount; i++,fld++){
      if(fld->vlist)free(fld->vlist);
    }
    free(fn->fldlist);
  }
  free(fn);
}


void PONEXUS_destroy(PONEXUS *po){
  if(po->delimit)free(po->delimit);
  if(po->mdelimit)free(po->mdelimit);
}


void MLNEXUS_destroy(MLNEXUS **eml){
MLNEXUS *ml=*eml;
MOPNEXUS *mn;
int i;
   for(i=0;i<ml->pcount; i++){
     mn=&ml->list[i];
     if(mn->re)free(mn->re);
     if(mn->pattern)free(mn->pattern);
     if(mn->replace)free(mn->replace);
     if(mn->keepsub)free(mn->keepsub);
   }
   free(ml->list);
   free(ml);
   *eml=NULL;
}

/* subs_* all use omni->piece as a scratch area.  They take the ovector
information and substitute in each entry with the appropriate source.  When done
it is all copied back to the target.  The ovector is reset to 0 length by these
operations.  The dst variable is specified in mop->src and will always be <MYVARSMAX*/
void subs_s(OMNINEXUS *omni, MOPNEXUS *mop){
int       dst    = mop->src;
FMTNEXUS *var    = NULL;
int      *ovector= omni->ovector;
ESNEXUS  *tmp    = omni->piece;
ESNEXUS  *tgt;
int       last,slen,sslen,i;
  last      = 0;
  tmp->slen = 0;  /* clear out the scratch buffer */
  sslen     = strlen(mop->replace);
  if(dst==MYVARSMAX){ tgt    = omni->piece2;                      }
  else {              var    = omni->vn[dst]; tgt = var->dat_str; }
  for(i=0;i<2*omni->rc;i+=2){
    if(ovector[i] > last){  /* gap? copy the source over */
      slen = ovector[i] - last;
      if(slen<0){insane(INSFTLERR," invalid SUBSTRING LIST for -psN, probably PCRE subpatterns are still present");}
      es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS);
    }
    /* now the substitution */
    es_strcat(tmp,mop->replace,sslen,sslen,MEMOOPS);
    last = ovector[i+1];
  }
  /* dangling part */
  slen = ESP_CLEN(tgt) - last;
  if(slen > 0){  es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS); }
  
  /* Move this back to the variable.  If it was from input buffer, leave it in tmp (piece) */  
  if(dst!=MYVARSMAX){
    var->dat_str->slen      = 0;             
    slen                    = ESP_CLEN(tmp); 
    es_strcat(var->dat_str,ESP_CPTR(tmp),slen,slen,MEMOOPS);
    var->fldlist[0].source  = (SRCSELF | ISSDAT | MODECHAR);
    var->fldlist[0].iss     = 1;
    var->fldlist[0].issend  = -1;
    var->toklist->start     = 0;
    var->toklist->slen      = ESP_CLEN(var->dat_str);
    var->toklist->delimit   = 0; /* no delimiter */
    var->tokcount           = 1;
  
    /* empty the ovector, empty piece (just in case) */

    omni->rc  = 0;
    omni->tlen= 0;  /* it might not be set, but it must be cleared if it is */
    tmp->slen = 0;
  }
}

/* replace using up all the tokens in each variable, then moving on to the next variable.
Start over from the beginning if more are needed */
void subs_q(OMNINEXUS *omni, MOPNEXUS *mop){
int       dst    = mop->src;
int       tok    = 1;
int       jtok;
FMTNEXUS *var    = NULL;
FMTNEXUS *rvar;
int      *ovector= omni->ovector;
ESNEXUS  *tmp    = omni->piece;
ESNEXUS  *tgt;
char     *src;
char     *vlist  = mop->replace;
char     *v2;
int       last,slen,sslen,i;

  last      = 0;
  tmp->slen = 0;  /* clear out the scratch buffer */
  v2        = vlist;
  if(dst==MYVARSMAX){ tgt    = omni->piece2;                      }
  else {              var    = omni->vn[dst]; tgt = var->dat_str; }
  for(i=0;i<2*omni->rc;i+=2){
    rvar  = omni->vn[(int) *v2];   /* holds current replacement token */
    if(!rvar->dat_str->slen){
      insane2_var(INSFTLERR,"","replacement in -ps 't:VLIST' construct is CLEAR, variable:",*v2);
    }
    if(ovector[i] > last){  /* gap? copy the source over */
      slen = ovector[i] - last;
      if(slen<0){insane(INSFTLERR," invalid SUBSTRING LIST for -psN, probably PCRE subpatterns are still present");}
      es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS);
    }
    /* now the substitution */
    jtok  = tok - 1 ; /* convert from 1->N external form to 0->N-1 internal */
    src   = ESP_CADDR(rvar->dat_str,rvar->toklist[jtok].start);
    sslen = rvar->toklist[jtok].slen;
    es_strcat(tmp,src,sslen,sslen,MEMOOPS);
    last = ovector[i+1];
    tok++;
    if(tok > rvar->tokcount){
      tok=1;
      v2++;
      if(*v2==EOVLIST){ v2=vlist; }
    }
  }
  /* dangling part */
  slen = ESP_CLEN(tgt) - last;
  if(slen > 0){  es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS); }
  
  /* Move this back to the variable.  If it was from input buffer, leave it in tmp (piece) */  
  if(dst!=MYVARSMAX){
    var->dat_str->slen      = 0;             
    slen                    = ESP_CLEN(tmp); 
    es_strcat(var->dat_str,ESP_CPTR(tmp),slen,slen,MEMOOPS);
    var->fldlist[0].source  = (SRCSELF | ISSDAT | MODECHAR);
    var->fldlist[0].iss     = 1;
    var->fldlist[0].issend  = -1;
    var->toklist->start     = 0;
    var->toklist->slen      = ESP_CLEN(var->dat_str);
    var->toklist->delimit   = 0; /* no delimiter */
    var->tokcount           = 1;
  
    /* empty the ovector, empty piece (just in case) */

    omni->rc  = 0;
    omni->tlen= 0;  /* it might not be set, but it must be cleared if it is */
    tmp->slen = 0;
  }
}

/* replace using the designated tokens from a variable (in a single entry vlist).
Follows a t: pattern, which usually would have only one variable in its vlist, but
could have more.  Fatal error if a specified token does not exist in the source. */
void subs_t(OMNINEXUS *omni, MOPNEXUS *mop){
int       dst    = mop->src;
int      *tlist  = omni->tlist;
int       tlen   = omni->tlen;
int       jtok;
int       tn     = 0;
FMTNEXUS *var    = NULL;
FMTNEXUS *rvar;
int      *ovector= omni->ovector;
ESNEXUS  *tmp    = omni->piece;
ESNEXUS  *tgt;
char     *src;
char     *vlist  = mop->replace;
char     *v2;
int       last,slen,sslen,i;

  if(omni->oguard){insane(INSFTLERR," REPLACE with 't:V' cannot be applied after a %BHIA operation");}
  last      = 0;
  tmp->slen = 0;  /* clear out the scratch buffer */
  v2        = vlist;
  if(dst==MYVARSMAX){ tgt    = omni->piece2;                      }
  else {              var    = omni->vn[dst]; tgt = var->dat_str; }
  if(tlen==0)return; /* no tokens in the list, so no matches to replace */
  for(i=0;i<2*omni->rc;i+=2,tn++){
    rvar  = omni->vn[(int) *v2];   /* holds current replacement token */
    if(!rvar->dat_str->slen){
      insane2_var(INSFTLERR,"","replacement in -ps 'q:VLIST' construct is CLEAR, variable:",*v2);
    }
    if(ovector[i] > last){  /* gap? copy the source over */
      slen = ovector[i] - last;
      if(slen<0){insane(INSFTLERR," invalid SUBSTRING LIST for -psN, probably PCRE subpatterns are still present");}
      es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS);
    }
    /* now the substitution */
    if(tn>=tlen){insane(INSFTLPRGERR," invalid q:V replacement, rc length exceeds tlen length");}
    jtok  = tlist[tn]-1; /* is an internal address, 0->N-1 */
    if(jtok >= rvar->tokcount){insane(INSFTLERR," invalid q:V replacement in -psN, specified token does not exist in V");}
    src   = ESP_CADDR(rvar->dat_str,rvar->toklist[jtok].start);
    sslen = rvar->toklist[jtok].slen;
    es_strcat(tmp,src,sslen,sslen,MEMOOPS);
    last = ovector[i+1];
  }
  /* dangling part */
  slen = ESP_CLEN(tgt) - last;
  if(slen > 0){  es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS); }
  
  /* Move this back to the variable.  If it was from input buffer, leave it in tmp (piece) */  
  if(dst!=MYVARSMAX){
    var->dat_str->slen      = 0;             
    slen                    = ESP_CLEN(tmp); 
    es_strcat(var->dat_str,ESP_CPTR(tmp),slen,slen,MEMOOPS);
    var->fldlist[0].source  = (SRCSELF | ISSDAT | MODECHAR);
    var->fldlist[0].iss     = 1;
    var->fldlist[0].issend  = -1;
    var->toklist->start     = 0;
    var->toklist->slen      = ESP_CLEN(var->dat_str);
    var->toklist->delimit   = 0; /* no delimiter */
    var->tokcount           = 1;
  
    /* empty the ovector, empty piece (just in case) */

    omni->rc  = 0;
    omni->tlen= 0;  /* it might not be set, but it must be cleared if it is */
    tmp->slen = 0;
  }
}

/* substitute with variables in sequence, taking as many as needed and
wrapping if all consumed */
void subs_v(OMNINEXUS *omni, MOPNEXUS *mop){
int       dst    = mop->src;
FMTNEXUS *var    = NULL;
int      *ovector= omni->ovector;
ESNEXUS  *tmp    = omni->piece;
ESNEXUS  *src;
ESNEXUS  *tgt;
char     *vlist  = mop->replace;
char     *v2;
int       last,slen,sslen,i;

  last      = 0;
  tmp->slen = 0;  /* clear out the scratch buffer */
  v2        = vlist;
  if(dst==MYVARSMAX){ tgt    = omni->piece2;                      }
  else {              var    = omni->vn[dst]; tgt = var->dat_str; }
  for(i=0;i<2*omni->rc;i+=2){
    if(ovector[i] > last){  /* gap? copy the source over */
      slen = ovector[i] - last;
      if(slen<0){insane(INSFTLERR," invalid SUBSTRING LIST for -psN, probably PCRE subpatterns are still present");}
      es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS);
    }
    /* now the substitution */
    src   = omni->vn[(int) *v2]->dat_str;
    if(!src->slen){
      insane_var(INSFTLERR,"replacement in -ps 'v:VLIST' construct is CLEAR, variable:",*v2);
    }
    sslen = ESP_CLEN(src);
    es_strcat(tmp,ESP_CPTR(src),sslen,sslen,MEMOOPS);
    last = ovector[i+1];
    v2++;
    if(*v2==EOVLIST){ v2=vlist; }
  }
  /* dangling part */
  slen = ESP_CLEN(tgt) - last;
  if(slen > 0){  es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS); }
  
  /* Move this back to the variable.  If it was from input buffer, leave it in tmp (piece) */  
  if(dst!=MYVARSMAX){
    var->dat_str->slen      = 0;             
    slen                    = ESP_CLEN(tmp); 
    es_strcat(var->dat_str,ESP_CPTR(tmp),slen,slen,MEMOOPS);
    var->fldlist[0].source  = (SRCSELF | ISSDAT | MODECHAR);
    var->fldlist[0].iss     = 1;
    var->fldlist[0].issend  = -1;
    var->toklist->start     = 0;
    var->toklist->slen      = ESP_CLEN(var->dat_str);
    var->toklist->delimit   = 0; /* no delimiter */
    var->tokcount           = 1;
  
    /* empty the ovector, empty piece (just in case) */

    omni->rc  = 0;
    omni->tlen= 0;  /* it might not be set, but it must be cleared if it is */
    tmp->slen = 0;
  }
}

/* replace with token # from variable from variable list */
void subs_nv(OMNINEXUS *omni, MOPNEXUS *mop){
int       dst    = mop->src;
int       tok    = mop->tn;
int       jtok;
FMTNEXUS *var    = NULL;
FMTNEXUS *rvar;
int      *ovector= omni->ovector;
ESNEXUS  *tmp    = omni->piece;
ESNEXUS  *tgt;
char     *src;
char     *vlist  = mop->replace;
char     *v2;
int       last,slen,sslen,i;

  last      = 0;
  tmp->slen = 0;  /* clear out the scratch buffer */
  v2        = vlist;
  if(dst==MYVARSMAX){ tgt    = omni->piece2;                      }
  else {              var    = omni->vn[dst]; tgt = var->dat_str; }
  if(!tok){ tok = omni->result; } /* use RESULT for the token number*/
  for(i=0;i<2*omni->rc;i+=2){
    rvar  = omni->vn[(int) *v2];   /* holds current replacement token */
    if(!rvar->dat_str->slen){
      insane_var(INSFTLERR,"replacement in -ps 'n#:VLIST' construct is CLEAR, variable:",*v2);
    }
    if(ovector[i] > last){  /* gap? copy the source over */
      slen = ovector[i] - last;
      if(slen<0){insane(INSFTLERR," invalid SUBSTRING LIST for -psN, probably PCRE subpatterns are still present");}
      es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS);
    }
    /* now the substitution */
    if(tok > 0){ jtok = tok;                      }
    else {       jtok = rvar->tokcount + tok + 1; }  /* indexing from tail end is allowed */
    if(jtok <= 0 || jtok > rvar->tokcount){
      insane(INSFTLERR," subs with n# where token specified does not exist");
    }
    jtok--; /* convert from 1->N external form to 0->N-1 internal */
    src   = ESP_CADDR(rvar->dat_str,rvar->toklist[jtok].start);
    sslen = rvar->toklist[jtok].slen;
    es_strcat(tmp,src,sslen,sslen,MEMOOPS);
    last = ovector[i+1];
    v2++;
    if(*v2==EOVLIST){ v2=vlist; }
  }
  /* dangling part */
  slen = ESP_CLEN(tgt) - last;
  if(slen > 0){  es_strcat(tmp,ESP_CADDR(tgt,last),slen,slen,MEMOOPS); }
  
  /* Move this back to the variable.  If it was from input buffer, leave it in tmp (piece) */  
  if(dst!=MYVARSMAX){
    var->dat_str->slen      = 0;             
    slen                    = ESP_CLEN(tmp); 
    es_strcat(var->dat_str,ESP_CPTR(tmp),slen,slen,MEMOOPS);
    var->fldlist[0].source  = (SRCSELF | ISSDAT | MODECHAR);
    var->fldlist[0].iss     = 1;
    var->fldlist[0].issend  = -1;
    var->toklist->start     = 0;
    var->toklist->slen      = ESP_CLEN(var->dat_str);
    var->toklist->delimit   = 0; /* no delimiter */
    var->tokcount           = 1;
  
    /* empty the ovector, empty piece (just in case) */

    omni->rc  = 0;
    omni->tlen= 0;  /* it might not be set, but it must be cleared if it is */
    tmp->slen = 0;
  }
}

/* apply the match tests and operations/substitutions to the string stored in buf_common (bc) */
void pattern_logic(OMNINEXUS *omni, MLNEXUS *matches, int start,int end){
int              i,sum;
int              status;
FMTNEXUS       **vn      = omni->vn;
FMTNEXUS       **fn      = omni->fn;
MOPNEXUS        *mop     = NULL;
int              sptr    = 0; /* stack pointer */
ESNEXUS         *alldata = omni->alldata;
int              callstack[MYMAXSTACK];
int              offstack[MYMAXSTACK];
int              offset;
int             *idat;
char            *message;
enum swi_actions swact;
enum mactions    selector;

  if(!matches->pcount){ return; } /* nothing to do */
  omni->ifstate  &= IF_CLEAR;     /* bits within the mask may be set in do_mops below */
  omni->pat_skip  = 0;
  i               = matches->start;
  while(1){
outer_top:  /* used for function skip/^(jmp), call and only goto here*/
    mop=&matches->list[i];
    if(mop->src==MYVARSMAX){  /* work on the string in bc, shared by all fmt, just use fmt[0] */
      status=findmatches(omni,fn[0]->dat_str,mop,start,end);
    }
    else {  /* work on the variable indicated, note, it only changes the string */
      status=findmatches(omni,vn[(int)mop->src]->dat_str,mop,start,end);
    }
    if( omni->rc && mop->bits & MATCH_SUBS){  /* these are only -psN, the -ps are stored separately */
      if(     mop->bits & MATCH_SSUBS){  subs_s(omni,mop); }
      else if(mop->bits & MATCH_VSUBS){  subs_v(omni,mop); }
      else if(mop->bits & MATCH_NVSUBS){ subs_nv(omni,mop); }
      else if(mop->bits & MATCH_TSUBS){  subs_t(omni,mop); }
      else if(mop->bits & MATCH_QSUBS){  subs_q(omni,mop); }
      else {
        insane(INSFTLPRGERR," not valid MATCH_*SUBS in pattern_logic");
      }
    }
    else {
      omni->pat_skip = 0;             /* MUST be reset each time! */
        /* MANY side effects in do_mops: ifstate, pat_skip, force_eof, ifn, variables set/cleared...
           It is ok for a set of operations to be empty, it just means, "do nothing" */
      if(status){ offset = ( mop->true  ? mop->true:  0);  }
      else {      offset = ( mop->false ? mop->false: 0);  }
      /* run it... */

inner_top:  /* DO_RET jumps here */
      if(omni->dbg & DBGSTACK){ /* the flushes keep the lines in the right order */
         fflush(lcl_stdout[0]);
         fprintf(stderr,"Stack: %d Line: %d Offset: %d status: %d\n",sptr,i,offset,status);
         fflush(stderr);
      }
      while(offset){
        selector = *(int *)&((alldata->string[offset]));
        offset+=SOI; /* next offset or next operation */
        switch(selector){
         case DO_LISTEND:
           offset=0;
           break;;
         case DO_CLRV:
           offset = op_clrv(omni,offset);
           break;
         case DO_MRGV:
           offset = op_mrgv(omni,offset);
           break;
         case DO_SETC:
           offset = op_setc(omni,offset);
           break;
         case DO_MATH:
           message = run_math_rpn(omni,ESP_OFFCPTR(omni->alldata,offset),&omni->result);
           if(message)insane("",message);
           offset+=SOI;
           break;
         case DO_VSETV:
           offset = op_vsetv(omni,offset);
           break;
         case DO_STRV:
           offset = op_strv(omni,offset);
           break;
         case DO_FMTV:
           offset = op_fmtv(omni,offset);
           break;
         case DO_VV:
           offset = op_vv(omni,offset);
           break;
         case DO_NVV:
           offset = op_nvv(omni,offset);
           break;
         case DO_SHOWV:
           offset = op_showv(omni,offset);
           break;
         case DO_SHOWNV:
           offset = op_shownv(omni,offset);
           break;
         case DO_VEMIT:
           offset = op_vemit(omni,offset);
           break;
         case DO_SEMIT:
           offset = op_semit(omni,offset);
           break;
         case DO_FEMIT:
           offset = op_femit(omni,offset);
           break;
         case DO_READ:
           offset = op_read(omni,offset);
           break;
         case DO_IF:
           omni->ifstate |= ESP_OFFINT(omni->alldata,offset);
           offset += SOI;
           break;
         case DO_IFN:
           *(omni->ifn)= ESP_OFFINT(omni->alldata,offset);  /* meaning: this line + ifn more */
           offset += SOI;
           break;
         case DO_EOL:
           offset = op_eol(omni,offset);
           break;
         case DO_AFMT:
           /* Set curfmt in main() immediately
              Parameters at offset:  curfmt
           */
           omni->curfmt=  ESP_OFFINT(omni->alldata,offset);
           offset+=SOI;
           break;
         case DO_NFMT:
           /* Set nextfmt in main() at the bottom of the read loop (after this output, if any)
              Parameters at offset:  curfmt
           */
           omni->nextfmt=  ESP_OFFINT(omni->alldata,offset);
           offset+=SOI;
           break;
         case DO_HIDE:
           *(omni->show)=0;
           break;
         case DO_SHOW:
           *(omni->show)=1;
           break;
         case DO_SKIP:
           /* change the matchlist counter to  N and go there immediately*/
           i = ESP_OFFINT(omni->alldata,offset);
           goto outer_top;
         case DO_CALL:
           offstack[sptr] = offset + SOI; /* offset to next operation in this group.  Might be DO_LISTEND*/
           callstack[sptr]= i;
           sptr++;
           if(sptr > MYMAXSTACK){ insane(INSFTLERR," stack overflow, too many -pm & operations");}
           i = ESP_OFFINT(omni->alldata,offset);  /* call function at this matchlist position */
           goto outer_top;
         case DO_RET:
           sptr--;
           offset = offstack[sptr];
           i      = callstack[sptr];
           if(sptr < 0){ insane(INSFTLERR," stack underflow, too may -pm ret operations");}
           goto inner_top;
         case DO_BRK:
           /* jump completely out of all of the loops */
           goto done;
         case DO_EOF:
           /* Set FORCEEOF flag so that read loop will terminate.
              Parameters at offset:  none
           */
           *(omni->force_eof)=1;
           break;
         case DO_EXIT:
           exit(EXIT_SUCCESS);
           break;
         case DO_FAIL:
           exit(EXIT_FAILURE);
           break;
         case DO_PO:
           offset = op_po(omni,offset);
           break;
         case DO_BHIA:
           offset = op_bhia(omni,offset);
           break;
         case DO_NPOPV:
           offset = op_npopv(omni,offset);
           break;
         case DO_SW:
           idat         = (int *)ESP_OFFCPTR(omni->alldata,offset);
           if(omni->sw_val >= *idat){ insane(INSFTLERR," sw sees index larger than allowed range");}
           i            = idat[1 + omni->sw_val];
           omni->sw_val = 0; /* consumed! */
           offset      += SOI;
           goto outer_top;
         case DO_SWI:
           swact=ESP_OFFINT(omni->alldata,offset);
           switch(swact){
             case SWI_BIT0:
             case SWI_BIT1:
               omni->sw_val <<= 1;
               omni->sw_val |= ESP_OFFINT(omni->alldata,offset);
               break;
             case SWI_MV:
               omni->sw_val = omni->mv;
               break;
             case SWI_MP:
               if(omni->rc){ omni->sw_val = 1 + omni->ovector[0]; }
               else {        omni->sw_val = 0;                    }
               break;
             case SWI_MATH:
               if(isnormal(omni->result) && omni->result>=0){  /* note 0 fails isnormal */
                     omni->sw_val = omni->result;}
               else { omni->sw_val = 0;          }
               break;
             default:
               insane(INSFTLPRGERR," impossible DO_SWI case in pattern_logic");
           }
           offset       += SOI;
           break;
         default:
           insane(INSFTLPRGERR," unknown selector in pattern_logic");
        }; 
      }
    }
    i++;
    if(i >= matches->pcount)break;
  }
done:
  sum =  (omni->ifstate & IF_START1 ? 1 : 0) + 
         (omni->ifstate & IF_STARTC ? 1 : 0) +
         (omni->ifstate & IF_STARTT ? 1 : 0);
  if(sum > 1){
    insane(INSFTLERR," combination of if1, ifc, and ift were set - these if starts are not compatible");
  }
}

/* Tests for existence of input string, variables, or particular tokens.  Returns True if all tests
are true, otherwise returns false   */
int exists(OMNINEXUS *omni, MOPNEXUS *mspec){
int   status=1;
int   i,itmp;
int   start,end;
char *v2;
STRINGNEXUS *tok;
FMTNEXUS *var;

  for(v2=mspec->pattern; *v2 != EOVLIST; v2++){
    if(mspec->bits & MATCH_TTOK){ /* token tests */
      if(*v2==MYVARSMAX ){                var = omni->fn[0];         }
      else if(*v2>=0 || *v2>=MYVARSMAX){  var = omni->vn[(int) *v2]; }
      else { insane(INSFTLPRGERR," invalid variable in existence tests for tokens "); }
      if(mspec->bits & MATCH_GLOBAL){
        start=0; end=var->tokcount-1;
      }
      else {
        if(mspec->tn==0){ itmp = omni->result;}
        else {            itmp = mspec->tn;   }
        if(itmp>0){       start = itmp -1;              end=start; } /* internal */
        else if(itmp<0){  start = var->tokcount + itmp; end=start; } /* internal */
        else {            start=0;                      end=var->tokcount-1; } /* internal, RESULT was 0, so do global */
        if(start<0 || end >=var->tokcount){ status=0; break; } /* specified does not exist */
      }
      for(i=start;i<=end;i++){
        tok = &var->toklist[i];
        /* This is a logical exclusive or, but there is no ^^ in C  */
        if(mspec->bits & MATCH_EMPTY){
          if(tok->slen){  status=0; break;} /* failed empty test*/
        }
        else {
          if(!tok->slen){ status=0; break;} /* failed length test*/
        }
      }
      if(!status){break;}
    }
    else { /* variable tests */
      if(mspec->tn==0){ itmp = omni->result; }
      else {            itmp = mspec->tn;    }
      if(mspec->bits & MATCH_GLOBAL){ itmp = 0; } /* test for < than this, cannot fail on a length */
      else {
        if(itmp<=0){insane(INSFTLERR," value <=0 cannot be the minimum length of Variables");}
      }
      
      if(*v2 == MYVARSMAX){    /* input buffer test, check size */
        if(mspec->bits & MATCH_EMPTY){
          if(ESP_CLEN(omni->fn[0]->dat_str)){        status=0; break; } /* failed empty test*/
        }
        else {
          if(ESP_CLEN(omni->fn[0]->dat_str) < itmp){ status=0; break; }/* input buffer is not long enough */
        }
      }
      else if(*v2 <MYVARSMAX){ /* variable test, check size */
        var = omni->vn[(int) *v2];
        if(!var->dat_str->slen){           status=0; break; } /* variable is not set         */
        if(mspec->bits & MATCH_EMPTY){
          if(ESP_CLEN(var->dat_str)){     status=0; break; } /* failed empty test*/
        }
        else {
          if(ESP_CLEN(var->dat_str)<itmp){ status=0; break; } /* variable is not long enough */
        }
      }
      else { insane(INSFTLPRGERR," invalid VLIST entry in exists() "); }
    }
  }
  return(status);
}

/* Tests on math variables and/or math RESULT.
Returns True if all tests are true, otherwise returns false   */
int math_tests(OMNINEXUS *omni, MOPNEXUS *mspec){
int    status=1;
int    start,end,i;
char  *v2;
double dval;
DVNEXUS *dv = omni->dvar;

  for(v2=mspec->pattern; status && *v2 != EOVLIST; v2++){
    if(*v2 <MYVARSMAX){ /* variable test*/
      dv=&omni->dvar[(int) *v2];
      if(mspec->bits & MATCH_GLOBAL){
        start=0; end=dv->dlen-1;
      }
      else {
        if(mspec->tn > 0 ){     start = mspec->tn;                        } /* external coordinates */
        else if(mspec->tn < 0 ){start = mspec->tn;                        }
        else{                   start = omni->result;                     }
        if(start > 0 ){         start--;                end = start;      } /* internal coordinates */
        else if(start < 0 ){    start = dv->dlen+start; end = start;      }
        else{                   start = 0;              end = dv->dlen-1; }
        if(start<0 || end >=dv->dlen){ insane(INSFTLERR," invalid element for math test ");}
      }
      for(i=start;i<=end;i++){ 
        /* normal test must be true for zero too, but isnormal() is false for zero, so do the normal
           test this way */
        if(dv->val[i] != dv->val[i]){ /* NaN, fails all tests */
          status=0;  break;
        }
        else if(
             ( (mspec->bits & MATCH_NML) && isinf(dv->val[i])  ) || /* normal is !(inf or NaN)*/
             ( (mspec->bits & MATCH_EQ ) && (dv->val[i] != 0)  ) ||
             ( (mspec->bits & MATCH_LT ) && (dv->val[i] >= 0)  ) ||
             ( (mspec->bits & MATCH_GT ) && (dv->val[i] <= 0)  )
        ){  status=0;  break; }
      }
    }
    else if(*v2 ==MYVARSMAX){ /* RESULT test*/
      dval=omni->result;
      if(dval != dval){ /* NaN, fails all tests */
        status=0;  break;
      }
      else if(
         ( (mspec->bits & MATCH_NML) && isinf(dval)  ) || /* normal is !(inf or NaN)*/
         ( (mspec->bits & MATCH_EQ ) && (dval != 0)  ) ||
         ( (mspec->bits & MATCH_LT ) && (dval >= 0)  ) ||
         ( (mspec->bits & MATCH_GT ) && (dval <= 0)  )
      ){  status=0;  break; }
    }
    else {
      insane(INSFTLPRGERR," invalid VLIST entry in math_test() ");
    }
  }
  return(status);
}

/* Simple string match, restrict to range start/end.   */
void match_s(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end){
int      rc = 0;
int     *ovector = omni->ovector;
char    *from;  /* pointer for each position searched in the string we are searching */
char    *mptr;  /* pointer in the string we are searching, starting at "from"     */
char    *esptr; /* pointer to first (re)searchable character, modified in loops if MATCH_NEAR */
char    *emptr; /* pointer to one past the last searchable character */
char    *cptr;  /* pointer in the string we are searching for */
char    *qry  = mspec->pattern;
int      qlen = strlen(mspec->pattern);
char    *eqry = &mspec->pattern[qlen]; /* 1 past the end of the query */
int      where;


  if(!dst->slen)return;  /* (usually) cannot match an undefined target, rc is 0, so returns false */
  if(mspec->bits & MATCH_REMAINDER){
    if(omni->oguard){
      insane(INSFTLERR," STRING match cannot append to a match list following a %BHIA operation");
    }
    if(omni->target != dst->string){
      insane(INSFTLERR," STRING match with remainder on first search or different target on Nth search");
    }
  }
  else {
    omni->oguard = 0;
    omni->rc     = 0;
    dst->start   = start;
    omni->target = dst->string;
  }
  emptr   = &dst->string[end+1];
  while(1){
    where=dst->start;
    esptr   = &dst->string[where];
    if(dst->start + qlen - 1 > end ){  /* no way, it cannot fit */
      if(mspec->bits & MATCH_GLOBAL)break;  /* global with remainder, global takes precedence */
      if(mspec->bits & MATCH_REMAINDER){ omni->rc = 0; }
      break;
    }
    if(mspec->bits & MATCH_CASELESS){
      for(from=esptr; from <= emptr; from++, where++){
         for(rc=1,mptr=from,cptr=qry;;mptr++,cptr++){
           if(cptr >= eqry)break;
           if( (toupper(*mptr)!= toupper(*cptr)) || mptr>=emptr){  rc=0; break; }
         }
         if(rc)break;
      }
    }
    else {
      for(from=esptr; from <= emptr; from++, where++){
         for(rc=1,mptr=from,cptr=qry;;mptr++,cptr++){
           if(cptr >= eqry)break;
           if( *mptr!= *cptr || mptr>=emptr){  rc=0; break; }
         }
         if(rc)break;
      }
    }
    if(rc){ /* matched at "where" for a query with length qlen  */
      EXT_REALLOC2(omni->ovector,omni->osize,(omni->rc + 1),(2*omni->osize),(3*SOI),MEMOOPS);
      ovector[omni->rc * 2]     = where;             /* start of match */
      ovector[omni->rc * 2 + 1] = where + qlen;      /* one past end of match   */
      dst->start = where + qlen;                           /* new search position */
      omni->rc++;
    }
    else {
      if(mspec->bits & MATCH_GLOBAL)break;  /* global with remainder, global takes precedence */
      if(mspec->bits & MATCH_REMAINDER){ omni->rc = 0; }
      dst->start = 0;
      break;
    }
    if(!(mspec->bits & MATCH_GLOBAL))break;
  }
  /* positional constraints, 1st starts at 0 or last ends at last char */
  if( omni->rc &&
     ((mspec->bits & MATCH_END   && ovector[omni->rc * 2 - 1] != ESP_CLEN(dst)) ||
      (mspec->bits & MATCH_START && ovector[0]))){ 
     omni->rc = 0;
  }
  if(omni->dbg & DBGIFP)dump_ovector_mop(omni,mspec,dst->string,start);
}

/* Match dat_str from VLIST.  Match meaning defined by bits within MATCH_STRSMETHOD mask   */
void match_v(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end){
int     *ovector = omni->ovector;
char    *from;  /* pointer for each position searched in the string we are searching */
char    *mptr;  /* pointer in the string we are searching, starting at "from"     */
char    *esptr; /* pointer to first (re)searchable character, modified in loops if MATCH_NEAR */
char    *emptr; /* pointer to one past the last searchable character */
char    *cptr;  /* pointer in the string we are searching for */
char    *qry;
int      qlen;
int      qlong=0; /* longest token (query) */
int      mend2; /* temporary value       */
char    *eqry; /* 1 past the end of the query */
int      where =  0;
char    *v2;    /* vlist ptr*/
int      match;
int      mstart = 0; /*gcc -O3 gives may be used uninitialized without this */
int      mend   = 0; /* ditto */
int      rc     = 0; /* ditto */
int      ok;


  if(!dst->slen)return;  /* cannot match an undefined target, rc is 0, so returns false */
  qlen  = vlist_len(mspec->pattern);
  eqry  = &mspec->pattern[qlen]; /* 1 past the end of the query */
  if(mspec->bits & MATCH_REMAINDER){
    if(omni->oguard){
      insane(INSFTLERR," STRING match cannot append to a match list following a %BHIA operation");
    }
    if(omni->target != dst->string){
      insane(INSFTLERR," STRING match with remainder on first search or different target on Nth search");
    }
  }
  else {
    omni->oguard = 0;
    omni->rc     = 0;
    dst->start   = start;
    omni->target = dst->string;
  }
  if(mspec->bits & MATCH_NEAR){ /* need to find the length of the longest query */
    qlong = vlist_longest(omni, mspec->pattern);
  }
  v2    = mspec->pattern; /*  initialize for sequential, reinitialize below if others */
  match = 0;
  while(1){
    if(where > end)break;
    switch(mspec->bits & MATCH_STRSMETHOD){
      case MATCH_SEQUENTIAL:
        if(*v2==EOVLIST){ v2=mspec->pattern;} /* next position, loop below will only execute once */
        break;
      case MATCH_FIRST: 
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        break;
      case MATCH_NEAR:
        mstart = INT_MAX;
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        break;
      case MATCH_FAR:
        mend   = -1;
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        break;
      default:
        insane(INSFTLPRGERR," unknown multiple strings option in match_v");
    }
    ok      = 1;
    match   = 0;
    emptr   = &dst->string[end+1];
    esptr   = &dst->string[dst->start];
    while(ok){ /* multiple strings, loop in here as needed */
      if(*v2 == EOVLIST){ break; } /* all VLIST entries searched */
      where  = dst->start;
      qry    = ESP_CPTR(omni->vn[(int) *v2]->dat_str);
      qlen   = ESP_CLEN(omni->vn[(int) *v2]->dat_str);
      eqry   = &qry[qlen];   /* 1 past the end of the query */
      if(mspec->bits & MATCH_CASELESS){
        for(from=esptr; from <= emptr; from++, where++){
           for(rc=1,mptr=from,cptr=qry;;mptr++,cptr++){
             if(cptr >= eqry)break;
             if( (toupper(*mptr)!= toupper(*cptr)) || mptr>=emptr){  rc=0; break; }
           }
           if(rc)break;
        }
      }
      else {
        for(from=esptr; from <= emptr; from++, where++){
           for(rc=1,mptr=from,cptr=qry;;mptr++,cptr++){
             if(cptr >= eqry)break;
             if( *mptr!= *cptr || mptr>=emptr){  rc=0; break; }
           }
           if(rc)break;
        }
      }
      switch(mspec->bits & MATCH_STRSMETHOD){ /* note that v2 increments in all of these */
        case MATCH_SEQUENTIAL:/* only one pass no matter what  */
          if(rc){   ok=0; match=1; mstart=where; mend=where+qlen; }
          else {    ok=0; match=0;                                } 
          break;
        case MATCH_FIRST:
          if(rc){   ok=0; match=1; mstart=where; mend=where+qlen; }
          break;
        case MATCH_NEAR:
          if(rc && where < mstart) {
                          match=1; mstart=where; mend=where+qlen;
            mend2   = mend+qlong-qlen;  /* mend2/emptr minimize run time by not searching too much */
            emptr   = &dst->string[(end + 1 < mend2 ? end + 1 : mend2)];
          }
          break;
        case MATCH_FAR:
          if(rc && (where + qlen > mend))   {
                          match=1; mstart=where; mend=where+qlen;}
          break;
      }
      v2++;
    }
    if(match){ /* matched at "where" for a query with length qlen  */
      EXT_REALLOC2(omni->ovector,omni->osize,(omni->rc + 1),(2*omni->osize),(3*SOI),MEMOOPS);
      ovector[omni->rc * 2]     = mstart;    /* start of match */
      ovector[omni->rc * 2 + 1] = mend;      /* one past end of match   */
      dst->start = mend;                     /* new search position */
      omni->rc++;
      where = mend;  /* restore this, some search modes go to end */
    }
    else {
      if(mspec->bits & MATCH_SEQUENTIAL){
       /* OK to miss on 1st in vlist after a cycle completes, anywhere else wipes all the matches */
        if(v2 != mspec->pattern + 1 ){ 
          omni->rc   = 0;      
          dst->start = 0;
        }
        break;
      }
      if(mspec->bits & MATCH_GLOBAL)break;  /* global with remainder, global takes precedence */
      if(mspec->bits & MATCH_REMAINDER){ omni->rc = 0; }
      dst->start = 0;
      break;
    }
    if( !(mspec->bits & MATCH_GLOBAL) &&
        !(mspec->bits &  MATCH_SEQUENTIAL && *v2 != EOVLIST)
      )break; /* global always keeps going, sequential keeps going unless the list is exhausted */
  }
  /* positional constraints, 1st starts at 0 or last ends at last char */
  if( omni->rc &&
     ((mspec->bits & MATCH_END   && ovector[omni->rc * 2 - 1] != ESP_CLEN(dst)) ||
      (mspec->bits & MATCH_START && ovector[0]))){ 
     omni->rc = 0;
  }
  if(omni->dbg & DBGIFP)dump_ovector_mop(omni,mspec,dst->string,start);
}

/* Match nth token from each in VLIST.  If mspec->tn is zero, then use RESULT for
the token number.  */
void match_nv(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end){
int      *ovector = omni->ovector;
char     *from;  /* pointer for each position searched in the string we are searching */
char     *mptr;  /* pointer in the string we are searching, starting at "from"     */
char     *esptr; /* pointer to first (re)searchable character, modified in loops if MATCH_NEAR */
char     *emptr; /* pointer to one past the last searchable character */
char     *cptr;  /* pointer in the string we are searching for */
char     *qry;
int       qlen;
int       qlong=0; /* longest token (query) */
int       mend2; /* temporary value       */
char     *eqry;
int       status;
int       where = 0;
char     *v2;    /* vlist ptr*/
int       match;
int       mstart = 0; /*gcc -O3 gives may be used uninitialized without this */
int       mend   = 0; /* ditto */
int       rc     = 0; /* ditto */
int       ok;
FMTNEXUS *var;
int       jstart,jend;
int       tn;

  if(!dst->slen)return;  /* cannot match an undefined target, rc is 0, so returns false */
  qlen  = vlist_len(mspec->pattern);
  eqry  = &mspec->pattern[qlen]; /* 1 past the end of the query */
  if(mspec->tn){ tn = mspec->tn;    }
  else {         tn = omni->result; }
  if(mspec->bits & MATCH_REMAINDER){
    if(omni->oguard){
      insane(INSFTLERR," STRING match cannot append to a match list following a %BHIA operation");
    }
    if(omni->target != dst->string){
      insane(INSFTLERR," STRING match with remainder on first search or different target on Nth search");
    }
  }
  else {
    omni->oguard = 0;
    omni->rc     = 0;
    dst->start   = start;
    omni->target = dst->string;
  }
  if(mspec->bits & MATCH_NEAR){ /* need to find the length of the longest query */
    qlong = vlist_longest_token(omni, mspec->pattern, mspec->tn, 1);
  }
  v2    = mspec->pattern; /*  initialize for sequential, reinitialize below if others */
  match = 0;
  while(1){
    if(where > end)break;
    switch(mspec->bits & MATCH_STRSMETHOD){
      case MATCH_SEQUENTIAL:
        if(*v2==EOVLIST){ v2=mspec->pattern;} /* next position, loop below will only execute once */
        break;
      case MATCH_FIRST: 
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        break;
      case MATCH_NEAR:
        mstart = INT_MAX;
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        break;
      case MATCH_FAR:
        mend   = -1;
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        break;
      default:
        insane(INSFTLPRGERR," unknown multiple strings option in match_nv");
    }
    ok      = 1;
    match   = 0;
    emptr   = &dst->string[end+1];
    esptr   = &dst->string[dst->start];
    while(ok){ /* multiple strings, loop in here as needed */
      if(*v2 == EOVLIST){ break; } /* all VLIST entries searched */
      var=omni->vn[(int)*v2];
      where = dst->start;
      status=realends(&jstart,&jend,tn,tn,var->tokcount); /* jstart/jend set the same*/
      if(status<0){realends_oops(tn,tn,var->tokcount);}
      else if(status==0){
        insane(INSFTLERR," PATTERN n# token does not exist in at least one entry in VLIST");
      }
      qry   = &ESP_CPTR(var->dat_str)[var->toklist[jstart].start];
      qlen  = var->toklist[jstart].slen;
      eqry  = &qry[qlen];                   /* 1 past the end of the query */
      if(mspec->bits & MATCH_CASELESS){
        for(from=esptr; from <= emptr; from++, where++){
           for(rc=1,mptr=from,cptr=qry;;mptr++,cptr++){
             if(cptr >= eqry)break;
             if( (toupper(*mptr)!= toupper(*cptr)) || mptr>=emptr){  rc=0; break; }
           }
           if(rc)break;
        }
      }
      else {
        for(from=esptr; from <= emptr; from++, where++){
           for(rc=1,mptr=from,cptr=qry;;mptr++,cptr++){
             if(cptr >= eqry)break;
             if( *mptr!= *cptr || mptr>=emptr){  rc=0; break; }
           }
           if(rc)break;
        }
      }
      switch(mspec->bits & MATCH_STRSMETHOD){ /* note that v2 increments in all of these */
        case MATCH_SEQUENTIAL:/* only one pass no matter what  */
           
          if(rc){   ok=0; match=1; mstart=where; mend=where+qlen; }
          else {    ok=0; match=0;                                } 
          break;
        case MATCH_FIRST:
          if(rc){   ok=0; match=1; mstart=where; mend=where+qlen; }
          break;
        case MATCH_NEAR:
          if(rc && where < mstart) {
                          match=1; mstart=where; mend=where+qlen;
            mend2   = mend+qlong-qlen;  /* mend2/emptr minimize run time by not searching too much */
            emptr   = &dst->string[(end + 1 < mend2 ? end + 1 : mend2)];
          }
          break;
        case MATCH_FAR:
          if(rc && (where + qlen > mend))   {
                          match=1; mstart=where; mend=where+qlen;}
          break;
      }
      v2++;
    }
    if(match){ /* matched at "where" for a query with length qlen  */
      EXT_REALLOC2(omni->ovector,omni->osize,(omni->rc + 1),(2*omni->osize),(3*SOI),MEMOOPS);
      ovector[omni->rc * 2]     = mstart;    /* start of match */
      ovector[omni->rc * 2 + 1] = mend;      /* one past end of match   */
      dst->start = mend;                     /* new search position */
      omni->rc++;
      where = mend;  /* restore this, some search modes go to end */
    }
    else {
      if(mspec->bits & MATCH_SEQUENTIAL){
       /* OK to miss on 1st in vlist after a cycle completes, anywhere else wipes all the matches */
        if(v2 != mspec->pattern + 1 ){ 
          omni->rc   = 0;      
          dst->start = 0;
        }
        break;
      }
      if(mspec->bits & MATCH_GLOBAL)break;  /* global with remainder, global takes precedence */
      if(mspec->bits & MATCH_REMAINDER){ omni->rc = 0; }
      dst->start = 0;
      break;
    }
    if( !(mspec->bits & MATCH_GLOBAL) &&
        !(mspec->bits &  MATCH_SEQUENTIAL && *v2 != EOVLIST)
      )break; /* global always keeps going, sequential keeps going unless the list is exhausted */
  }
  /* positional constraints, 1st starts at 0 or last ends at last char */
  if( omni->rc &&
     ((mspec->bits & MATCH_END   && ovector[omni->rc * 2 - 1] != ESP_CLEN(dst)) ||
      (mspec->bits & MATCH_START && ovector[0]))){ 
     omni->rc = 0;
  }
  if(omni->dbg & DBGIFP)dump_ovector_mop(omni,mspec,dst->string,start);
}

/* Match all tokens from VLIST (usually this would just be one variable, and
all tokens in it, but make it general just in case).  */
void match_t(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end){
int      *ovector = omni->ovector;
char     *from;  /* pointer for each position searched in the string we are searching */
char     *mptr;  /* pointer in the string we are searching, starting at "from"     */
char     *esptr; /* pointer to first (re)searchable character, modified in loops if MATCH_NEAR */
char     *emptr; /* pointer to one past the last searchable character, modified in loops if MATCH_FAR  */
char     *cptr;  /* pointer in the string we are searching for */
char     *qry;
int       qlen;
int       qlong=0; /* longest token (query) */
int       mend2; /* temporary value       */
char     *eqry;
int       where = 0;
char     *v2;    /* vlist ptr*/
int       match;
int       mstart = 0; /*gcc -O3 gives may be used uninitialized without this */
int       mend   = 0; /* ditto */
int       rc     = 0; /* ditto */
int       ok;
int       mv=0;  /* will hold number of token that matched (1->N), 0 if no match */
FMTNEXUS *var;
int       tcount=0;

  if(!dst->slen)return;  /* cannot match an undefined target, rc is 0, so returns false */
  qlen  = vlist_len(mspec->pattern);
  eqry  = &mspec->pattern[qlen]; /* 1 past the end of the query */
  if(mspec->bits & MATCH_REMAINDER){
    if(omni->oguard){
      insane(INSFTLERR," STRING match cannot append to a match list following a %BHIA operation");
    }
    if(omni->target != dst->string){
      insane(INSFTLERR," STRING match with remainder on first search or different target on Nth search");
    }
  }
  else {
    omni->oguard = 0;
    omni->rc     = 0;
    omni->tlen   = 0;
    dst->start   = start;
    omni->target = dst->string;
  }
  if(mspec->bits & MATCH_NEAR){ /* need to find the length of the longest query */
    qlong = vlist_longest_token(omni, mspec->pattern,0,0);
  }
  v2    = mspec->pattern; /*  initialize for sequential, reinitialize below if others */
  match = 0;
  while(1){
    if(where > end)break;
    switch(mspec->bits & MATCH_STRSMETHOD){
      case MATCH_SEQUENTIAL:
        if(*v2==EOVLIST){ v2=mspec->pattern;} /* next position, loop below will only execute once */
        /* tcount NOT reset, or sequential wouldn't work */
        break;
      case MATCH_FIRST: 
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        tcount = 0;
        break;
      case MATCH_NEAR:
        mstart = INT_MAX;
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        tcount = 0;
        break;
      case MATCH_FAR:
        mend   = -1;
        v2     = mspec->pattern; /* start at the beginning, will run through in the loop below */
        tcount = 0;
        break;
      default:
        insane(INSFTLPRGERR," unknown multiple strings option in match_nv");
    }
    ok      = 1;
    match   = 0;
    emptr   = &dst->string[end+1];
    esptr   = &dst->string[dst->start];
    while(ok){ /* multiple strings, loop in here as needed */
      if(*v2 == EOVLIST){ break; } /* all VLIST entries searched */
      var=omni->vn[(int)*v2];
      where = dst->start;
      qry   = &ESP_CPTR(var->dat_str)[var->toklist[tcount].start];
      qlen  = var->toklist[tcount].slen;
      eqry  = &qry[qlen];                   /* 1 past the end of the query */
      if(mspec->bits & MATCH_CASELESS){
        for(from=esptr; from <= emptr; from++, where++){
           for(rc=1,mptr=from,cptr=qry;;mptr++,cptr++){
             if(cptr >= eqry)break;
             if( (toupper(*mptr)!= toupper(*cptr)) || mptr>=emptr){  rc=0; break; }
           }
           if(rc)break;
        }
      }
      else {
        for(from=esptr; from <= emptr; from++, where++){
           for(rc=1,mptr=from,cptr=qry;;mptr++,cptr++){
             if(cptr >= eqry)break;
             if( *mptr!= *cptr || mptr>=emptr){  rc=0; break; }
           }
           if(rc)break;
        }
      }
      switch(mspec->bits & MATCH_STRSMETHOD){ 
        case MATCH_SEQUENTIAL:/* only one pass no matter what  */
          if(rc){   ok=0; match=1; mstart=where; mend=where+qlen; mv = tcount+1;}
          else {    ok=0; match=0;                                } 
          break;
        case MATCH_FIRST:
          if(rc){   ok=0; match=1; mstart=where; mend=where+qlen; mv = tcount+1;}
          break;
        case MATCH_NEAR:
          if(rc && where < mstart) {
                          match=1; mstart=where; mend=where+qlen; mv = tcount+1;
            mend2   = mend+qlong-qlen;  /* mend2/emptr minimize run time by not searching too much */
            emptr   = &dst->string[(end + 1 < mend2 ? end + 1 : mend2)];
          }
          break;
        case MATCH_FAR:
          if(rc && (where + qlen > mend))   {
                          match=1; mstart=where; mend=where+qlen; mv = tcount+1;}
          break;
      }
      tcount++;
      if(tcount >= var->tokcount){
        v2++;
        tcount = 0;
      }
    }
    if(match){ /* matched at "where" for a query with length qlen  */
      EXT_REALLOC2(omni->tlist,omni->talloc,(omni->tlen + 1),(2*(omni->tlen+1)),SOI,MEMOOPS);
      omni->tlist[omni->tlen++]=mv;
      EXT_REALLOC2(omni->ovector,omni->osize,(omni->rc + 1),(2*omni->osize),(3*SOI),MEMOOPS);
      ovector[omni->rc * 2]     = mstart;    /* start of match */
      ovector[omni->rc * 2 + 1] = mend;      /* one past end of match   */
      dst->start = mend;                     /* new search position */
      omni->rc++;
      where = mend;  /* restore this, some search modes go to end */
    }
    else {
      if(mspec->bits & MATCH_SEQUENTIAL){
       /* OK to miss on 1st in vlist after a cycle completes, anywhere else wipes all the matches */
        if((v2 != mspec->pattern) || (tcount != 1) ){ 
          omni->rc   = 0;      
          dst->start = 0;
        }
        break;
      }
      if(mspec->bits & MATCH_GLOBAL)break;  /* global with remainder, global takes precedence */
      if(mspec->bits & MATCH_REMAINDER){ omni->rc = 0; }
      dst->start = 0;
      break;
    }
    if( !(mspec->bits & MATCH_GLOBAL) &&
        !(mspec->bits &  MATCH_SEQUENTIAL && *v2 != EOVLIST)
      )break; /* global always keeps going, sequential keeps going unless the list is exhausted */
  }
  /* positional constraints, 1st starts at 0 or last ends at last char */
  if( omni->rc &&
     ((mspec->bits & MATCH_END   && ovector[omni->rc * 2 - 1] != ESP_CLEN(dst)) ||
      (mspec->bits & MATCH_START && ovector[0]))){ 
     omni->rc = 0;
  }
  omni->mv = mv;  /* used to detect which token matched */
  if(omni->dbg & DBGIFP)dump_ovector_mop(omni,mspec,dst->string,start);
}

/* perform the RE match on dst that is described in mspec.  Restrict to
range start/end.    */
void match_p(OMNINEXUS *omni, ESNEXUS *dst, MOPNEXUS *mspec, int start, int end){
int      rc=0;
int     *ovector = omni->ovector;

  if(!dst->slen)return;  /* cannot match an undefined target, rc is 0, so returns false */
  if(mspec->bits & MATCH_REMAINDER){
    if(omni->oguard){
      insane(INSFTLERR," PCRE match cannot append to a match list following a %BHIA operation");
    }
    if(omni->target != dst->string){
      insane(INSFTLERR," PCRE match with remainder on first search or different target on Nth search");
    }
  }
  else {
    omni->oguard = 0;
    omni->rc     = 0;
    dst->start   = start;
    omni->target = dst->string;
  }
  rc             = omni->rc;
  if(mspec->re){
    while(1){
      if(dst->start>end){
        if(mspec->bits & MATCH_GLOBAL)break;  /* global with remainder, global takes precedence */
        if(mspec->bits & MATCH_REMAINDER){ omni->rc = 0; }
        break;
      }
      rc = pcre_exec(
        mspec->re,                /* the compiled pattern */
        NULL,                     /* no extra data - we didn't study the pattern */
        dst->string,              /* the subject string */
        dst->slen-1,              /* the length of the subject */
        dst->start,               /* start at offset 0 in the subject */
        0,                        /* default options (if any are set, they should be compiled into re already)*/
        &ovector[2*omni->rc],     /* output vector for substring information */
        omni->osize - 2*omni->rc); /* number of elements in the output vector */
      if(rc<0){  /* no match (on this cycle) */
        if(mspec->bits & MATCH_GLOBAL)break;  /* global with remainder, global takes precedence */
        if(mspec->bits & MATCH_REMAINDER){ omni->rc = 0; }
        break;        
      }
      if(rc==0){            /* ran out of space, resize ovector, double available space */
        EXT_REALLOC2(omni->ovector,omni->osize,0,(2*omni->osize),(3*SOI),MEMOOPS);
        continue;                 /* go around again */
      }
      if(mspec->bits & MATCH_KEEPN){
        rc = keep_substring(mspec->keepsub,&ovector[2*omni->rc],rc);
      }
      omni->rc += rc;
      dst->start = ovector[2 * omni->rc - 1];  /* new search position */
      if(!(mspec->bits & MATCH_GLOBAL))break;
    }
  }
  else {
    insane(INSFTLPRGERR," no RE in match_p");
  }
  if(omni->dbg & DBGIFP)dump_ovector_mop(omni,mspec,dst->string,start);
}

int vlist_longest_token(OMNINEXUS *omni, const char *vlist, int tn, int single){
const char *v2;
FMTNEXUS *var;
int tlong=0;
int i;
int status;
  v2 = vlist;
  if(single && tn==0){
    tn=omni->result;
    if(tn==0){ insane(INSFTLERR," match v0:, RESULT specifies invalid token number"); }
  }
  while(*v2 != EOVLIST){ /* all VLIST entries searched */
    var=omni->vn[(int)*v2];
    if(single){
        status=realends(&i,&i,tn,tn,var->tokcount);
        if(status<=0){
          insane(INSFTLERR," match vn:, specified token number which does not exist in one or more variables");
        }
        if(var->toklist[tn].slen > tlong){tlong = var->toklist[tn].slen; } 
    }
    else {
      for(i=0;i<var->tokcount;i++){ 
        if(var->toklist[i].slen > tlong){tlong = var->toklist[i].slen; } 
      }
    }
    v2++;
  }
  return(tlong);
}

int vlist_longest(OMNINEXUS *omni, const char *vlist){
const char *v2;
FMTNEXUS *var;
int tlong=0;
  v2 = vlist; 
  while(*v2 != EOVLIST){ /* all VLIST entries searched */
    var=omni->vn[(int)*v2];
    if(ESP_CLEN(var->dat_str) > tlong){ tlong = ESP_CLEN(var->dat_str); } 
    v2++;
  }
  return(tlong);
}

/* keep only some of the hits in the ovector and return the number remaining.
Note there are two entries in vector for each position.   */
int keep_substring(unsigned char *klist, int *vector, int len){
int newlen=0;
int from,to; /* 0->N-1, but klist is 1->N */
   for(from=to=0; *klist;from++){
     if(*klist>len){ insane(INSFTLERR," PCRE match did not create enough substrings to satisfy /#/# specification"); }
     if(*klist == from+1){
       memmove(&vector[2*to],&vector[2*from],2*SOI);
       to++;
       newlen++;
       klist++;
     }
   }
   return(newlen);
}


void dump_bhia(int bits){
  if(bits & MATCH_B){ fprintf(stderr,"B"); }
  if(bits & MATCH_H){ fprintf(stderr,"H"); }
  if(bits & MATCH_I){ fprintf(stderr,"I"); }
  if(bits & MATCH_A){ fprintf(stderr,"A"); }
}

void dump_separator(void){
  fprintf(stderr,"--------------------------------------\n");
}


void dump_ovector_mop(OMNINEXUS *omni, MOPNEXUS *mspec, char *target, int start){
  dump_separator();
  dump_mop(omni,mspec);
  dump_ovector_only(omni,start);
}

/* ovector is always in PCRE format.  It is supposed to be a multiple of 3 long,
but what is stored in it is pairs of:
  start (0->N-1)
  end+1 (character AFTER the end of the match)
*/

void dump_ovector_only(OMNINEXUS *omni, int start){
int i;
char *substring;
int   substart;
int   sublength;
char *target = omni->target;
  if(start){
    fprintf(stderr,"Target: %.*s^%.*s\n",start,target,strlen(target)-start,&(target[start]));
  }
  else {
    fprintf(stderr,"Target: %s\n",target);
  }
  fprintf(stderr,"##   Pos   Len  Substring  Entries=%d\n",omni->rc);
  for(i=0; i<omni->rc; i++){
    substart  = omni->ovector[2*i];
    substring = target + substart;
    sublength = omni->ovector[2*i+1] - omni->ovector[2*i];
    fprintf(stderr,"%2d: %4d  %4d  >%.*s<\n",
        i, substart, sublength, sublength, substring);
  }
}

ESNEXUS *es_create(int size, char *fail){
ESNEXUS *tmp;
  EXT_MALLOC(tmp,sizeof(ESNEXUS),fail);
  EXT_MALLOC(tmp->string,size,fail);
  tmp->string[0]='\0'; /* just in case */
  tmp->salloc=size;
  tmp->slen=0;
  return(tmp);
}

void es_destroy(ESNEXUS **etarget){
ESNEXUS *target=*etarget;
  free(target->string);
  free(target);
  *etarget=NULL;
}

void es_clear(ESNEXUS *dst){
  if(!dst)insane(INSFTLPRGERR," es_clear applied to NULL ESNEXUS pointer");
  if(dst->salloc){ *(dst->string)='\0'; }  /* just in case, not really needed if slen is 0*/
  dst->slen=0;
}
  
/*  There are five very similar function for ESNEXUS append, be sure
to use the right one!

  es_strcat       xxx\0 + yyy -> xxxyyy\0
  es_append_str   xxx\0 + yyy -> xxx\0yyy\0
  es_append_dat   xxx\0 + yyy -> xxx\0yyy
  es_append_aidat  xxx\0 + yyy -> xxx\0yyy  AND check that INT is stored aligned
  es_append_addat  xxx\0 + yyy -> xxx\0yyy  AND check that DBL is stored aligned

In all cases inc (increment memory storage if out of space) must be a multiple
of SOI.  If not, unaligned memory access can result.

Message if the realloc fails is in fail. 

*/  
  
/* See above for comparison of es_strcat, es_append_str, es_append_dat */
void es_strcat(ESNEXUS *dst, char *src, int slen, int inc, char *fail){
int islen; /* either slen or slen + 1, for existing or empty target */
int iinc;  /* amount to add to allocation */
  /* strcat a zero length string does nothing to an EXISTING string, but it will create an empty
     string in cleared variable (just the \0). */
  if(slen){
    islen = (dst->slen ? dst->slen + slen : slen + 1);
    iinc  = inc *( 1 + (islen / inc));  /* do NOT use modulo here, if inc is 1 iinc always inc! */
  }
  else if(!dst->slen){ /* just an empty string */
    islen = 1;
    iinc  = 1; 
  }
  else { return; }
  EXT_REALLOC2(dst->string, dst->salloc, islen,(dst->salloc + iinc),1,fail);
  if(dst->slen){  /* overwrite the terminal \0 */
    memcpy(&(dst->string[dst->slen -1]),src,slen);
    dst->slen += slen - 1;  /* lose one character since there was on overlap on the terminator */
  }
  else {  /* there is no terminal \0, start at the beginning, nothing is overwritten */
    memcpy(dst->string,src,slen);
    dst->slen += slen;
  }
  dst->string[dst->slen]='\0';  /* terminate     */
  dst->slen++;                  /* adjust length */
}  

/* See above for comparison of es_strcat, es_append_str, es_append_dat */
void es_append_str(ESNEXUS *dst, char *src, int slen, int inc, char *fail){
  if(slen){
     EXT_REALLOC2(dst->string, dst->salloc, (dst->slen + slen + 1),
      (dst->salloc + slen + inc + NEXTINTREMAINDER(slen + inc)),1,fail);
     memcpy(&(dst->string[dst->slen]),src,slen);
     dst->slen += slen;
     dst->string[dst->slen]='\0';
  }
  else {  /* appended an empty string, so one more terminator on the end */
     EXT_REALLOC2(dst->string, dst->salloc, (dst->slen + slen + 1),
      (dst->salloc + inc + NEXTINTREMAINDER(inc)),1,fail);
     dst->string[dst->slen]='\0';
  }
  dst->slen++;
}  

/* See above for comparison of es_strcat, es_append_str, es_append_dat */
void es_append_dat(ESNEXUS *dst, char *src, int slen, int inc, char *fail){
  EXT_REALLOC2(dst->string, dst->salloc, (dst->slen + slen),
   (dst->salloc + slen + inc + NEXTINTREMAINDER(slen + inc)),1,fail);
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

/* See above for comparison of es_strcat, es_append_str, es_append_dat */
void es_append_cptr(ESNEXUS *dst, char *src, int inc, char *fail){
uintptr_t tmp;
  tmp = (uintptr_t)(void*)src;
  es_append_dat(dst, (char *) &tmp, sizeof(uintptr_t), inc, fail);
}  

/* Insert a block of data into an ESNEXUS.  It is passed as a char but unlike es_append_str,
there is no terminator added. Insert must fit entirely within the already written memory.
fail is an error message.
*/
void es_insert(ESNEXUS *dst, int offset, char *src, int slen, int inc, char *fail){
  if(offset+slen > dst->slen)insane(INSFTLERR,fail);
  memcpy(&(dst->string[offset]),src,slen);
}  

/* convert fieldnexus post processing parameters to action list form. We already
know how many of these there are, which lets us skip over the space needed for the 
list itself and store parameters after it. */
void fn_to_pal(OMNINEXUS *omni, FIELDNEXUS *fld){
char fail1[]=" could not reallocate memory";
char fail2[]=" could not insert action list entry";
ESNEXUS *alldata = omni->alldata; 
int *offset;
int  offstore[MYMAXPAL];
int  count=0;
int  selector=0;
char blank_rts[]=""; /* empty replacement string */

  ESP_NEXTINTBOUNDARY(alldata);
  offset=&offstore[0];
  if(fld->descify != DESCNONE){
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->descify),SOI,ALLDATAINC,fail1);
    selector |= DO_DESC;
    count++;
  } 
  if(fld->ttype==MODETOK || fld->ttype==MODENUM){  /* MUST specify a string to fill with, even if it is just '\0' */
    *offset++=alldata->slen;
    es_append_str(alldata,fld->ersstring,EXT_STRLEN(fld->ersstring),ALLDATAINC,fail1);
    ESP_NEXTINTBOUNDARY(alldata);
    selector |= DO_RS;
    count++;
  }
  if(fld->rcd != RCDNONE){
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->lrcd),SOI,ALLDATAINC,fail1);
    es_append_str(alldata,fld->rcd,EXT_STRLEN(fld->rcd),ALLDATAINC,fail1);
    es_append_str(alldata,fld->rcs,EXT_STRLEN(fld->rcs),ALLDATAINC,fail1);
    ESP_NEXTINTBOUNDARY(alldata); 
    selector |= DO_RCD;
    count++;
  } 
  if(fld->rtd != RTDNONE){
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->lrtd),SOI,ALLDATAINC,fail1);
    es_append_str(alldata,fld->rtd,EXT_STRLEN(fld->rtd),ALLDATAINC,fail1);
    if(fld->rts){  /* replacement string specified */
      es_append_dat(alldata,fld->rts,1,ALLDATAINC,fail1); /* var or MYVARSMAX*/
      if(*fld->rts == MYVARSMAX){ /* immediate string, append the rest of it*/
        es_append_str(alldata,&fld->rts[1],strlen(&fld->rts[1]),ALLDATAINC,fail1);
      }
    }
    else {
      blank_rts[0]=MYVARSMAX;
      es_append_str(alldata,blank_rts,1,ALLDATAINC,fail1);
    }
    ESP_NEXTINTBOUNDARY(alldata); 
    selector |= DO_RTD;
    count++;
  } 
  if(fld->lps != PSNONE){
    *offset++=alldata->slen;
    es_append_dat(alldata,&fld->ps,1,ALLDATAINC,fail1);
    ESP_NEXTINTBOUNDARY(alldata); 
    selector |= DO_PS;
    count++;
  }
  if(fld->slashify != SLASHNONE){
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->slashify),SOI,ALLDATAINC,fail1);
    es_append_str(alldata,&(fld->ecc),1,ALLDATAINC,fail1);
    ESP_NEXTINTBOUNDARY(alldata); 
    selector |= DO_SLASH;
    count++;
  } 
  if(fld->ff != FFNONE){  /* This carries along the NZ bits too */
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->ff),       SOI,ALLDATAINC,fail1);
    es_append_aidat(alldata,(char *)&(fld->pad),      SOI,ALLDATAINC,fail1);
    es_append_aidat(alldata,(char *)&(fld->precision),SOI,ALLDATAINC,fail1);
    selector |= DO_FFF;
    count++;
  }
  else if(fld->pad != PADNONE){  /* this is the ONLY else if in this section !!! */
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->pad),      SOI,ALLDATAINC,fail1);
    selector |= DO_PAD;
    count++;
  } 
  if(fld->trimify != TRIMNONE){
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->trimify),  SOI,ALLDATAINC,fail1);
    selector |= DO_TRIM;
    count++;
  } 
  if(fld->justify != JUSTNONE){
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->justify),  SOI,ALLDATAINC,fail1);
    selector |= DO_JUST;
    count++;
  } 
  if(fld->casify != CASENONE){
    *offset++=alldata->slen;
    es_append_aidat(alldata,(char *)&(fld->casify),  SOI,ALLDATAINC,fail1);
    selector |= DO_CASE;
    count++;
  }
  ESP_NEXTINTBOUNDARY(alldata);
  omni->lastpal_off   = alldata->slen;
  omni->lastpal_count = count;
  if(count){  /* only store these if there is actually an action list */
    es_append_aidat(alldata,(char *)&selector,SOI,ALLDATAINC,fail2);  /* store action list */
    es_append_aidat(alldata,(char *)&(offstore[0]),count*SOI,ALLDATAINC,fail2);  /* store action list */
  }
}

/* make one token out of entire string */
void make_one_token(FMTNEXUS *fmt){
    fmt->tokcount = 1;
    fmt->toklist[0].start    = 0;
    fmt->toklist[0].slen     = ESP_CLEN(fmt->dat_str);
    fmt->toklist[0].delimit  = '\0';
}


int main(int argc, char *argv[]){
/* command line values */
int    maxwidth;
int    sc,ec;
int    sr,er;
int    all;
int    rm;
char  *tag=NULL;
char  *tagterm=NULL;
char  *iftermeol=NULL;
char  *iftermbol=NULL;
char  *fileeol=NULL;
char  *filebol=NULL;
char  *indl=NULL;
char  *eol=NULL;
char  *bol=NULL;
int    merge;
int    forcebuffer;
int    samelines;
int    template;
int    linenumber;                  /* flag, emit line number */
int    linelength;                  /* flag, emit line lengths */
int    linetokens;                  /* flag, emit line token number */
int    tagstate;                    /* if     */
int    tagtermstate;                /* ifterm */
int    ifn;
int    ifonly,ifeol,ifbol;
int    ifncount      = 0;
int    slblock       = 0;      /* used to detect the end of consecutive single line IF statements */
int    show          = 1;
int    force_eof     = 0;      /* option for pattern match, effectively forces an end of file on input */
int    emitteol      = 0;
                      /* buffer to hold lines is buf_common -> string */
char        *mbuffer=NULL;  /* buffer to hold 2nd line if merge is going on */
char        *ftoken=NULL;   /* pointer to first token in unmerge operations */
char        *obuffer=NULL;
int          xc;            /* max parsed tokens on a line, used for -fmt mode */
int          xe;            /* max format tokens in a -fmt or -v* */
int          linecount;
int          mlinecount;
int          linelen=0;
int          mlinelen=0;
int          flen;          /* first token length */
int          firstline=YES; /* first line special when -merge is active */
int          usembuf;       /* special case, when a merge terminates use mbuffer instead of buffer ONCE */
char       **rawfmts=NULL;
char       **rawvars=NULL;
char       **rawpos=NULL;
char        *mtoken=NULL;
int         *olinecount;
int          i;
int          numfmt=0;
int          numvar=0;
int          numpo=0;
int         *ovector=NULL;
int          osize=MYOVECSIZE;
OMNINEXUS   *omni;
FIELDNEXUS  *gblparams;
PONEXUS     *gbl_po;
PONEXUS     *po;
FMTNEXUS   **fmt_array;
FMTNEXUS   **var_array;
ESNEXUS     *buf_common;
ESNEXUS     *piece;   /* buffer to hold the current piece */
ESNEXUS     *piece2;   /* buffer to hold the current piece */
MLNEXUS     *subs;    /* -ps */
PMLNEXUS    *prematches; /* temporarily hold -pm[N],-psN strings */
MLNEXUS     *b_matches; /* -pm[N],-psN */
MLNEXUS     *m_matches; /* -pm[N],-psN */
MLNEXUS     *a_matches; /* -pm[N],-psN */
ESNEXUS     *alldata; /*stores action lists and data for post processing */
ESNEXUS     *accum;
DVNEXUS     *dv;

  lcl_stdout[0]=NULL;
  EXT_CALLOC(omni,              1,           sizeof(OMNINEXUS),   MEMOOPS);
  EXT_CALLOC(fmt_array,         MYFMTSMAX,   sizeof(FMTNEXUS *),  MEMOOPS);
  EXT_CALLOC(var_array,         MYVARSMAX,   sizeof(FMTNEXUS *),  MEMOOPS);
  EXT_CALLOC(rawfmts,           MYFMTSMAX,   sizeof(char *),      MEMOOPS);
  EXT_CALLOC(rawvars,           MYVARSMAX,   sizeof(char *),      MEMOOPS);
  EXT_CALLOC(rawpos,            MYPOSMAX,    sizeof(char *),      MEMOOPS);
  EXT_CALLOC(po,                MYPOSMAX,    sizeof(PONEXUS),     MEMOOPS);
  EXT_CALLOC(subs,              1,           sizeof(MLNEXUS),     MEMOOPS);
  EXT_CALLOC(b_matches,         1,           sizeof(MLNEXUS),     MEMOOPS);
  EXT_CALLOC(m_matches,         1,           sizeof(MLNEXUS),     MEMOOPS);
  EXT_CALLOC(a_matches,         1,           sizeof(MLNEXUS),     MEMOOPS);
  EXT_CALLOC(ovector,           MYOVECSIZE,  sizeof(int *),       MEMOOPS);
  EXT_CALLOC(prematches,        1,           sizeof(PMLNEXUS),    MEMOOPS);
  EXT_CALLOC(prematches->list,  PATINC,      sizeof(PREMOPNEXUS), MEMOOPS);
  EXT_CALLOC(gblparams,         1,           sizeof(FIELDNEXUS),  MEMOOPS);
  EXT_CALLOC(omni->dvar,        26,          sizeof(DVNEXUS),     MEMOOPS);
  /* initialize all math variables as single entry arrays */
  for(i=0;i<MYVARSMAX;i++){
    dv=&(omni->dvar[i]);
    EXT_CALLOC(dv->val,1,sizeof(double),MEMOOPS);
    dv->dlen=1;
    dv->dalloc=1;
  }
  EXT_CALLOC(omni->stk,1, sizeof(DVNEXUS),MEMOOPS);
  EXT_CALLOC(omni->pstk,1, sizeof(MSLNEXUS),MEMOOPS);
  prematches->palloc = PATINC;
  alldata=es_create(ALLDATAINC,MEMOOPS);
  gbl_po=po;  /* first entry in po list is the global one */
  /* put something in alldata, because 0 offset int true/false paths means empty, 
     so no real commands can be stored there */
  i = DO_LISTEND;
  es_append_aidat(alldata,(char *)&i,SOI,ALLDATAINC,MEMOOPS);


  process_command_line_args(argc,argv,gbl_po,
    &maxwidth,&sc,&ec,&sr,&er,&rm,
    &all,gblparams,&xc,&xe,&omni->dbg,&tagstate,&tagtermstate,&ifn,&ifonly,
    &ifeol,&ifbol,&eol,&bol,&rawfmts,&rawvars,rawpos,&tag,&tagterm,
    &iftermeol,&iftermbol,
    &fileeol,&filebol,
    &indl,&samelines,
    &linenumber,&linelength,&linetokens,
    &merge,&template,&omni->handlenull,&omni->crok, subs, prematches);

/*  dump_po(gbl_po,"Global Parsing Options"); */


  /* these allocations had to wait for maxwidth to be defined, the merge buffer is used both
     for merging multiple input files, and for variable operations, so always allocate it. */
  accum     = es_create(maxwidth+1, MEMOOPS);
  buf_common= es_create(maxwidth+1, MEMOOPS);
  piece     = es_create(maxwidth+1, MEMOOPS);
  piece2    = es_create(1, MEMOOPS); /* this may not be used, so make it small initially */
  EXT_MALLOC(mbuffer,(maxwidth+1),MEMOOPS);
  if(merge!=0){
    obuffer=mbuffer;
    olinecount=&mlinecount;
  }
  else{
    obuffer=buf_common->string;
    olinecount=&linecount;
  }

  /* save all the various pointers and such in the omni structure, rc and
     target are set after a pattern match. */
  omni->buf_common    = buf_common;
  omni->result        = 0.0;
  omni->ifn           = &ifn;       
  omni->alldata       = alldata;
  omni->noleaks       = es_create(SOP,MEMOOPS);;
  omni->ifstate       = 0;       
  omni->force_eof     = &force_eof;      
  omni->show          = &show;           
  omni->curfmt        = 0;         
  omni->nextfmt       = 0;        
  omni->ovector       = ovector;  
  omni->osize         = osize;          
  omni->rc            = 0;
  omni->po            = po;
  omni->gbl_po        = po;          
  omni->numpo         = &numpo;          
  omni->fn            = fmt_array;
  omni->vn            = var_array;
  omni->piece         = piece;
  omni->piece2        = piece2;
  omni->accum         = accum;
  omni->subs          = subs;
  omni->gblparams     = gblparams;
  omni->smap          = NULL;
  omni->smsize        = 0;
  /* omni->matches set separately for before, main, after sections */
  omni->gbl_po        = gbl_po;

  /* set up the -op, -pm[N], -psN matches structure.  Translate if,ifn,ifterm if only
     these are used.  Side effect, frees prematches. */
  make_matches(omni, prematches,  b_matches, m_matches, a_matches,
    ifn, tagstate, tagtermstate, tag, tagterm);

 /* convert params to action list */
  fn_to_pal(omni,gblparams);
  omni->gblpal_off   = omni->lastpal_off;
  omni->gblpal_count = omni->lastpal_count;
  
  if(omni->dbg & DBGM){
     /* dumps one copy of common region, even if empty */
    if(     b_matches->start){ dump_ml(omni,b_matches,NULL); }
    else if(m_matches->start){ dump_ml(omni,m_matches,NULL); }
    else{                      dump_ml(omni,a_matches,NULL); }
    dump_ml(omni,b_matches,"BEFORE");
    dump_ml(omni,m_matches,"MAIN");
    dump_ml(omni,a_matches,"AFTER");
  }

  for(i=0;i<MYFMTSMAX;i++){
    if(rawfmts[i]){
      numfmt++;
      fmt_array[i]=FMTNEXUS_init(xc,xe,buf_common,rawfmts[i],1+strlen(rawfmts[i]));
      init_process_type(omni, fmt_array[i], gblparams, xe);
    }
  }
  
  if(numfmt == 0){  /* regular command line processing, no -fmt was specified*/
    numfmt++;
    regular_to_fmt(piece,buf_common->string,sc,ec,rm);
    fmt_array[omni->curfmt]=FMTNEXUS_init(xc,xe,buf_common,piece->string,piece->slen);
    init_process_type(omni, fmt_array[omni->curfmt], gblparams, xe);
  }
  for(i=0;i<MYVARSMAX;i++){  /* vars restricted to xe tokens on input */
    numvar++;
    if(rawvars[i]){  /* These are DEFINED variables */
      var_array[i]=FMTNEXUS_init(1,xe,NULL,rawvars[i],1+strlen(rawvars[i]));
      init_process_type(omni, var_array[i], gblparams, xe);
    }
    else { /* These are SET variables.  Number of defined fields set to 1 for now */
      var_array[i]=FMTNEXUS_init(1,1,NULL,"",1);
      init_process_type(omni, var_array[i], NULL, xe);
    }
  }
  var_presets(var_array); /* fix up SET variables which have been preset */
  
  /* set up the PO array*/
  
  for(i=0;i<MYPOSMAX;i++){  /*  */
    numpo++;
    if(!rawpos[i]){
      if(!i)add_po(omni, NULL,&po[0]);  /* convert gbl_po to final format if no po0 was specified */
      break;
    }
    else {
      add_po(omni, rawpos[i],&po[i]);
    }
  }
  
  omni->matches = b_matches;
  pattern_logic(omni,b_matches,1,-1); /* BEFORE section*/
  omni->matches = m_matches;

  /**************************************************/
  /* preliminaries are complete, enter main loop    */
  /**************************************************/
 
  
  if(filebol!=NULL){ (void) fprintf(lcl_stdout[0],"%s",filebol); }

  linecount=0;
  usembuf=NO;
  forcebuffer=NO;
  mtoken=NULL;
  while( 1 ){
    if(force_eof)break;
    if(merge>0){
      if(usembuf == YES){
        usembuf=NO;
        strcpy(buf_common->string,mbuffer);
        linelen=mlinelen;
        mlinecount=linecount;
        if(er>0 && linecount>=er){
          forcebuffer=YES;
          linecount--;
        }
      }
      if(!getnextline(mbuffer,maxwidth,lcl_stdin,infiles,indl,samelines,template,
            omni->handlenull,omni->crok)){
        if(er>0 && linecount>=er)break;
        forcebuffer=YES;  /* buffer still holds data, force it out */
      }
      else {
        mlinelen=strlen(mbuffer);
        linecount++;
      }
    }
    else if(merge < 0){ /* unmerge operation */
      if(! nextpartialbuffer(buf_common->string,&ftoken,&flen,&mtoken,-merge,gbl_po)){
        if(!getnextline(mbuffer,maxwidth,lcl_stdin,infiles,indl,samelines,template
           ,omni->handlenull,omni->crok))break;
        linecount++;
        mlinecount=linecount;
        mlinelen=strlen(mbuffer);
        mtoken=mbuffer;
        (void) nextpartialbuffer(buf_common->string,&ftoken,&flen,&mtoken,-merge,gbl_po);
      }
      linelen=strlen(buf_common->string);
    }
    else {
      if(!getnextline(buf_common->string,maxwidth,lcl_stdin,infiles,indl,samelines,template,
        omni->handlenull,omni->crok))break;
      linelen=strlen(buf_common->string);
      linecount++;
    }
    buf_common->slen   =  linelen+1; /* include the terminator */
    buf_common->start  =  0;  /* always reset start whenever an ESNEXUS is set */
    if(ifncount>0)(ifncount)--;
    make_one_token(fmt_array[omni->curfmt]);  /* define it as one big token */


    if(linecount < sr){
      if(all && show){
         (void) fprintf(lcl_stdout[0],"%s",bol); 
         if(linenumber==YES)(void) fprintf(lcl_stdout[0],"%8d:",linecount);
         (void) fprintf(lcl_stdout[0],"%s%s",obuffer,eol); 
      }
    }
    else if(er == 0 || linecount <= er){  /* in row range as seen by linecount */
      if(merge>0){ /* merge in as many lines as are required up to -er */
        if(forcebuffer==NO){
          if(firstline==YES){
            firstline=NO;
            (void) strcpy(buf_common->string,mbuffer);
            linelen=mlinelen;
            mlinecount=linecount;
            if(linecount!=er)continue;  /* go back for more input lines */
          }
          else {
            if(0==lcl_strcmprange(mbuffer,buf_common->string,0,merge-1,NO)){
              if(mlinelen + linelen + gbl_po->mdllen - merge >= maxwidth)insane(INSFTLERR," input buffer overflow while merging lines");
              if(gbl_po->mdllen > 0){
                (void) strncpy(&(buf_common->string[linelen]),gbl_po->mdelimit,gbl_po->mdllen);
                linelen += gbl_po->mdllen;
              }
              if(mlinelen>merge){ 
                /* also copy delimiter, but do not count it in the length, so string is 
                always delimited, but next piece will overwrite this delimiter */
                (void) strncpy(&(buf_common->string[linelen]),&(mbuffer[merge]),mlinelen-merge+1);
                linelen += (mlinelen - merge);
              }
              if(er==0 || linecount<er )continue;  /* go back for more input lines to merge */
              /* if merge going on and hit er stop merging and emit mbuffer.
                 DO NOT set usembuf because this buffer was consumed (merged) into mbuffer */
            }
            else {
              usembuf=YES;
            }
          }
        }
      }
      
      /* get the input line tokens defined, if they ever will be */
      if(omni->maketokens)make_inp_tokens(fmt_array[omni->curfmt], gbl_po, "");
      /* -op, pm/pmA/psN logic. MANY side effects, clears variables and may reset ifstate */
      pattern_logic(omni,m_matches,sc,ec); /* MAIN section */

      /**************************************************/
      /* take care of the -if block processing (if any) */
      /**************************************************/
      
      if(omni->ifstate & IF_EXISTS){  /* skip all of this if no IF logic has been defined */
        /* this part handles the ending of an already open if block */
        if(ifncount==1 ||
           ((omni->ifstate & IF_TERM) && ifncount!=0 )){
          /* this is either the last line in an -ifn block (count down is completing)
             OR -ifn is not set and we just hit an if terminator, either -ifterm or 'if-' in an -mp
             statement in the pattern_logic. */
          ifncount=1; /* terminate the current -if block AFTER this line*/
          emitteol=1;
          if(iftermbol!=NULL && show){ (void) fprintf(lcl_stdout[0],"%s",iftermbol); }
        }
        else { emitteol=0; }

        if(slblock){
          slblock = 0;
          /* if NEITHER -ifn NOR -ifterm was specified THEN -if acts one line
          at a time and -if blocks may not overlap.  In that case iftermeol
          is written before the first line which fails to match the tag (fails
          the -if test), that is, ONCE following a run of single line if conditions */
          if(ifncount==0){
            if(iftermeol!=NULL && show){ (void) fprintf(lcl_stdout[0],"%s",iftermeol); }
          }
        }

        /* this part handles the starting (or continuation) of an if block */
        if(ifncount==0 || !(omni->ifstate & IF_NORESTART) ){
          /*we are outside an if block or ifncount cannot be restarted inside an if block */
          if(omni->ifstate & IF_ANY_START){
            if(ifncount>0)emitteol=0; /* cancel the end of block on a restart */
            if(omni->ifstate & IF_STARTT) {     ifncount = IFFOREVER; } /* until terminated */
            else if(omni->ifstate & IF_STARTC){ ifncount = 1+ifn;     } /* for N more lines */
            else{ /* IF_START1 */
              ifncount = 1; /* just this line   */
              slblock  = 1; /* mark block of single line ifs */
            }
          }
        }
      } /* test for IF_EXISTS */

      
      /* output */
      
      if((!(omni->ifstate & IF_EXISTS)) || ifncount>0 || ifncount == IFFOREVER ){
        if(omni->dbg & DBGCOL)dump_commands(omni, fmt_array[omni->curfmt]);        
        if(omni->dbg & DBGVAR)dump_vars(omni);
        if(show){ 
          /* if it won't be shown do not even calculate it, there might be undefined variables */
          emit_output(omni,fmt_array[omni->curfmt],accum,fmt_array[omni->curfmt],ifeol, ifbol, eol, bol,
            linenumber, *olinecount, linelength,linetokens, NULL);
          fprintf(lcl_stdout[0],"%s",accum->string);
        }
      }
      else {
        if(ifonly==NO && show){
          (void) fprintf(lcl_stdout[0],"%s",bol); 
          if(linenumber==YES)(void) fprintf(lcl_stdout[0],"%8d:",*olinecount);
          (void) fprintf(lcl_stdout[0],"%s%s",obuffer,eol);
        }
      }
      
      /* emit the if block termination string? */
      
      if( emitteol){
        if(iftermeol!=NULL && show){ (void) fprintf(lcl_stdout[0],"%s",iftermeol); }
        emitteol=0;
      }

    } /* linecount conditions */
    else { /* er !=0 and linecount >er, past the line restricted region */
      if(all && show){
        (void) fprintf(lcl_stdout[0],"%s",bol); 
        if(linenumber==YES)(void) fprintf(lcl_stdout[0],"%8d:",linecount);
        (void) fprintf(lcl_stdout[0],"%s%s",obuffer,eol);
      }
      else { /* no more lines will be processed, force an exit from the read loop */
        forcebuffer=YES;
      }
    }
    omni->curfmt = omni->nextfmt;
    if(forcebuffer==YES)break;
  }

  omni->matches = a_matches;
  pattern_logic(omni,a_matches,1,-1); /* AFTER section*/

  if((omni->ifstate & IF_EXISTS) && show && ((ifncount == IFFOREVER) || (ifncount >0)) ){
    if(iftermbol!=NULL)(void) fprintf(lcl_stdout[0],"%s",iftermbol);
    if(iftermeol!=NULL)(void) fprintf(lcl_stdout[0],"%s",iftermeol);
  }
  if(linecount < sr && !force_eof){
     insane(INSFTLERR," no input or start row is beyond the end of the input data");
  }
  if(fileeol!=NULL){ (void) fprintf(lcl_stdout[0],"%s",fileeol); }
  
  /* Code to free memory, this is not normally compiled in, but it is handy to use with valgrind for
     finding memory issues.  fmt_array all share buf_common, which is why there is 1 in FMTNEXUS_destroy
     for those, but a 0 for var_array, which each have their own data buffer.
  */  
uintptr_t    uiptr;
  free(eol);
  free(bol);
  free(mbuffer);
  free(ovector);
  es_destroy(&alldata);
  es_destroy(&piece);
  es_destroy(&piece2);
  es_destroy(&accum);
  es_destroy(&buf_common);
  for(i=0;i<10;i++){
    if(fmt_array[i]){  FMTNEXUS_destroy(fmt_array[i],1); }
  }
  free(fmt_array);
  for(i=0;i<MYVARSMAX;i++){
    if(var_array[i]){ FMTNEXUS_destroy(var_array[i],0); }
  }
  free(var_array);
  for(i=0;i<MYPOSMAX;i++){
    PONEXUS_destroy(&po[i]);
  }
  free(po);
  free(omni->pstk->list);
  free(omni->pstk);
  if(omni->tlist)free(omni->tlist);
  if(omni->stk->val)free(omni->stk->val);
  if(omni->stk)free(omni->stk);
  for(i=0;i<MYVARSMAX;i++){
    dv=&(omni->dvar[i]);
    free(dv->val);
  }
  free(omni->dvar);
  if(omni->smap)free(omni->smap);
  for(i=0; i < omni->noleaks->slen; i+=SOP){
    memcpy(&uiptr,&(omni->noleaks->string[i]),SOP);
    free((void *)uiptr);
  }
  es_destroy(&(omni->noleaks));
  free(omni);
  for(i=0;i<MYFMTSMAX;i++){
    if(rawfmts[i]){ free(rawfmts[i]); }
  }
  free(rawfmts);
  for(i=0;i<MYVARSMAX;i++){
    if(rawvars[i]){ free(rawvars[i]); }
  }
  free(rawvars);
  for(i=0;i<MYPOSMAX;i++){
    if(rawpos[i]){ free(rawpos[i]); }
  }
  free(rawpos);
  MLNEXUS_destroy(&subs);
  MLNEXUS_destroy(&b_matches);
  MLNEXUS_destroy(&m_matches);
  MLNEXUS_destroy(&a_matches);
  
  for(i=0;i<infiles;i++){
    if(lcl_stdin[i] && lcl_stdin[i] != stdin)fclose(lcl_stdin[i]);
  }
  for(i=0;i<outfiles;i++){
    if(lcl_stdout[i] && lcl_stdout[i] != stdout)fclose(lcl_stdout[i]);
  }
  FIELDNEXUS_destroy(&gblparams);
  if(tag)free(tag);
  if(tagterm)free(tagterm);
  exit(EXIT_SUCCESS);
}

