drm_tools 1.1.18  JUN 25, 2013
Author:  David Mathog, mathog@caltech.edu

This is a collection of small tools that are 
sometimes helpful in specific instances.  Each
is provided as source code with a man page and an
html version of the man page.  Included programs are:

accudate:   An extended version of the unix "date" program.
            If supported by the compiler and OS it has subsecond
            accuracy and can easily be used to measure delta
            times in scripts.
            
binreplace: Command line utility that may be used in scripts to find
            or find/replace in binary files.  Initial release supports
            only fixed length binary sequences for FIND and REPLACE
            patterns.
            
columnadd:  Add columns of integers, decimals, and/or times.
            
datasniffer A utility for formatting binary data dumps.  Handy
            for reverse engineering binary data files if the
            contents are either already partially known or are
            expected to be intelligible upon careful examination.

dmath       Double precision interactive command line math calculator.
            (Same math functions as in extract.)

extract:    A utility that is designed to extract and
            emit data from text files based on character
            or token position.  In many instances it can
            replace tr, sed, or awk. 
          
execinput:  A utility that reads from stdin and executes
            each line as a command in a subprocess.
            
mdump:      A utility for formatting binary data.  Handy
            for decoding foreign binary data files.
            
msgqueue:   A command line interface to create message queues
            and send/receive messages.
            
mbin:       Multiple buffer in and out.  Used for buffering a lot
mbout:      of data between a slow device and a fast device.
            Mostly for buffering streaming tape drives for use
            with slower network connections, so that streaming
            is maintained as much as possible to minimize wear
            on the tape device.

pockmark:   Corrupt data streams - useful for testing error correction
            and data recovery.

tarsieve:   Filter, list, or split a tar file.
            
Other files:
sol8.h                     A few bits and pieces to work around missing things
                           in the Solaris 8 system libraries.  (Note, there
                           still minor incompatibilities, some NAN on other
                           systems are -INF here.)            
test_extract_increment.sh  Script for comparing incremental versions of extract.
test_extract_features.sh   Script for testing new features in 1.1.0 and up.  (Also
                           contains many scripting examples.) 
test_extract_features_mingw.sh
                           Script for testing new features in mingw.
test_dmath.sh              Script for testing dmath
test_dmath_mingw.sh        Script for testing dmath in mingw
test_tarsieve.sh           Script for testing tarsieve.
            
Build instructions:
Edit the build_(OSNAME) scripts as desired and run them.  Supported targets
are linux, solaris, and mingw.  The test scripts must use gnu diff which is
not the default on Solaris - edit that path before running.  There are 2 failures
in test_dmath.sh and test_extract_features.sh which are due to slight
differences in the math libraries.  There is also a 3rd failure in test_extract_features.sh
unless test_dmath is compiled with -DUSETOK.  That is not the default as that
is just a testing mode for some code only used in extract.

The mingw build will issue some warnings:

   warning: ISO C does not support the 'I64' ms_scanf length modifier [-Wformat]
   
which may be ignored.  These are the result of trying to use std=c99 with the MS supplied
scanf which uses a non-ISO C format instead of lld.


Dependenies:
The required libraries are most likely already installed in a Linux environment,
but some pieces may be missing on Solaris.  These are:

                            Install with
   libpcre                  pkg-get -i pcre
   libsigsegv               pkg-get -i libsigsegv
   libintl                  pkg-get -i libintl

   

Windows notes:
The mingw programs will run in a DOS window.  All are linked to a Microsoft
C RTL on the host system and consequently any \n in an output line will
actually emit \r\n, which is the default end of line marker on Windows.  
The -b switch will leave \n as \n, but only if the binary was built with
a C99 compatible compiler or -DMSCRTL was used (for instance, on mingw).

As of version 1.1.6 all of these programs are covered by the
GNU General Public License, Version 2.  A copy of the license
terms is found in the LICENSE file.

Program versions in this distribution:
accudate.c      1.0.9 14-NOV-2012
binreplace.c    1.0.3 14-NOV-2012
columnadd.c     1.0.3 12-NOV-2012
datasniffer.c   1.0.4 07-JUN-2011
execinput.c     1.0.1 19-OCT-2006
extract.c       1.1.9 13-JUN-2013
mbin.c          1.0.4 14-NOV-2012
mbout.c         1.0.3 12-NOV-2012
mdump.c         1.0.5 23-OCT-2006
msgqueue.c      1.0.2 23-OCT-2006
pockmark.c      1.0.2 02-SEP-2010
tarsieve.c      1.0.0 18-JUN-2013
test_math.c     0.0.8 12-DEC-2012


Distribution History
1.1.18 Added tarsieve.  Updated link to drm_tools download site in man
       and html pages which had not already been corrected.
1.1.17 Fixed a regression in extract which was affecting -fmt with consecutive
       [] clauses.  Modified documentation and test scripts.
       Modified documentation following suggestions by "Tanya".
1.1.16 Added bitwise operators and integer formats to  dmath and extract.
       Fixed some bugs in extract.  Updated documentation for dmath and extract.
1.1.15.2 Fixed minor bug in extract.
1.1.15.1 Changed all programs to use -DMSCRTL, some were using -DMSCLIB for 
       the same thing.
1.1.15 Document some solaris dependencies.   
       Slight changes to sol8.h.
       Fix compiler warnings on newer gcc.
       Changed build scripts, moved -l(lib) after name.c.
1.1.14 (Re)ported to mingw.  All run except msgqueue, which is too
       Unix specific.  Fixed a couple of minor bugs in various programs.
       Added binary output mode for extract (for systems other than Linux/Unix.)
1.1.13 fixed a couple of bugs in new version of extract.
1.1.12 major changes to extract (uses and requires PCRE, 
       added scripting and math capabilities). Added dmath.
1.1.11 added binreplace, two minor buf fixes to pockmark, slight change
       in build scripts to suppress a warning for mbout.
1.1.10 added pockmark
1.1.9  bug fixes in extract.
1.1.8  bug fixes in extract, datasniffer, mbin, and mbout. 
       Added sorts for multitoken fields to extract.
1.1.7  modified extract to support adding delimiters between single
       letter fields (expanded existing -bs function).
1.1.6  Added mbin/mbout.  Changed the license from proprietary to GPL 2
       on all programs.  Adjusted version numbers and documentation to
       reflect the new license and update copyrights.
1.1.5  Extract version 1.0.33, fixes one minor bug and one potential bug.
1.1.4.1 Removed unneeded unistd.h include in some programs.  No functional
       changes.
1.1.4  Added columnadd.  Slightly modified the other man and html pages.
1.1.3  Modified extract slightly to simplify iftermeol
1.1.1  Modified extract slightly so that it could also emit line lengths.
1.1.0  Added datasniffer.  Removed include of unistd.h from all but
       msgqueue.c.
1.0.0  Initial release

