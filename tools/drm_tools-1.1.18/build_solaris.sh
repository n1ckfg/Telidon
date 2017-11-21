#!/bin/sh
# build_solaris.sh
#
# This does NO error checking.  Make sure the TARG directories
# exist before running it!
#
# Options:
#   extract:   MAXINFILE (maximum number of input files)
#   mdump:    -DMDUMP_NOLONGLONG if the compiler has no long long
#   msgqueue:  The method for seeing how many bytes are queued is
#              not portable.  This works for Solaris but not for Linux.
#
# Set up the target directories.  Uncomment the HTML
# entries if you have a place for the HTML formatted
# man pages.
#
BINTARG=/usr/local/bin
MANTARG=/usr/local/man/man1
###HTMLTARG=/usr/local/doc/html
export BINTARG MANTARG
###export HTMLTARG
#
echo "Compiling"
gcc -Wall -std=c99 -pedantic -o accudate                   accudate.c
gcc -Wall -ansi    -pedantic -o columnadd                  columnadd.c
gcc -Wall -std=c99 -pedantic \
                             -o datasniffer                datasniffer.c \
                             -lm
gcc -Wall -std=c99 -pedantic -O3  -DSOL8 \
                             -o dmath                      test_math.c \
                             -lm
gcc -Wall -std=c99 -pedantic -O3  -DSOL8 -DMAXINFILE=20 \
                             -o extract                    extract.c \
                             -lm -lpcre
gcc -Wall -ansi    -pedantic -o execinput                  execinput.c
gcc -Wall -std=c99 -pedantic -o mdump                      mdump.c
gcc -Wall -ansi    -pedantic  -DHASMSG_CBYTE  -D_XOPEN_SOURCE \
                             -o msgqueue                   msgqueue.c
gcc -Wall -ansi    -pedantic -D_LARGE_FILE_SOURCE -D_FILE_OFFSET_BITS=64 \
                              -o mbin                      mbin.c
gcc -Wall -ansi    -pedantic -D_LARGE_FILE_SOURCE -D_FILE_OFFSET_BITS=64 -D_POSIX_SOURCE \
                              -o mbout                     mbout.c
gcc -Wall -ansi    -pedantic -o pockmark                   pockmark.c
gcc -Wall -std=c99 -pedantic -o tarsieve                   tarsieve.c \
                             -lpcre 
gcc -Wall -std=c99 -pedantic -O3 -DSOL8 \
                             -o binreplace                 binreplace.c
#
echo "Installing"
cp accudate binreplace columnadd datasniffer dmath extract execinput mdump msgqueue mbin mbout pockmark tarsieve $BINTARG
cp accudate.1 binreplace.1 columnadd.1 datasniffer.1 dmath.1 extract.1 execinput.1 mdump.1 msgqueue.1 mbin.1 mbout.1 pockmark.1 tarsieve.1 $MANTARG
###cp accudate.html binreplace.html columnadd.html datasniffer.html dmath.html extract.html execinput.html mdump.html msgqueue.html mbin.html mbout.html pockmark.html tarsieve.html $HTMLTARG
#
echo "Done"
