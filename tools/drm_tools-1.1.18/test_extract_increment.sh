#!/bin/bash
#
#  test script for comparing behavior of current production version with that
#  of experimental version.
#  This script uses accudate, from drm_tools, available from:
#    http://sourceforge.net/projects/drmtools/
#
##
OLDPROG=/usr/local/bin/extract
NEWPROG=./extract
TMPDIR=/tmp
ADATE=/usr/local/bin/accudate
TESTED=0
PASSED=0
RM=/bin/rm
EXTRACT=$OLDPROG
DIFF=/usr/bin/diff #must be Gnu diff

#
# use this if the program is supposed to run without error
#
dotest ()
{
 hold=`$ADATE -t0`
 eval $NEWPROG  $TESTARGS >$TMPDIR/new.txt
 ntime=`$ADATE -ds $hold`
 hold=`$ADATE -t0`
 eval $OLDPROG  $TESTARGS >$TMPDIR/old.txt
 otime=`$ADATE -ds $hold`
 let TESTED+=1
 $DIFF -q $TMPDIR/new.txt $TMPDIR/old.txt >/dev/null
 if [ $? -eq 0 ]
 then
   echo -n " $TESTED Pass $ntime $otime "
   let PASSED+=1
 else 
   echo -n " $TESTED Fail $ntime $otime "
   $DIFF $TMPDIR/new.txt $TMPDIR/old.txt >/dev/null
 fi
}

#
# use this if the program is supposed to throw an error and exit.
# it compares the error messages,if the syntax changes, the test will fail.
#
dofail ()
{
 let TESTED+=1
 hold=`$ADATE -t0`
 eval $NEWPROG $TESTARGS >/dev/null 2>$TMPDIR/new.txt
 ntime=`$ADATE -ds $hold`
 hold=`$ADATE -t0`
 eval $OLDPROG $TESTARGS >/dev/null 2>$TMPDIR/old.txt
 otime=`$ADATE -ds $hold`
 $DIFF -q $TMPDIR/new.txt $TMPDIR/old.txt >/dev/null
 if [ $? -eq 0 ]
 then
   echo -n " $TESTED Pass $ntime $otime "
   let PASSED+=1
 else 
   echo -n " $TESTED Fail $ntime $otime "
 fi
}

echo " Test Ntime       Otime       Test (#CSE = catch syntax error?)"
cat >$TMPDIR/input1.txt <<EOD
1234
1235
1236
1247
header,1,2,3,4,5 FOR UNMERGE TESTING
test delimiters in double quotes "blah gah,foo, bar"
This line has f o o after this foo and this foo and this foo!
   Line     for testing     trim (note 4 trailing spaces)    
This is TAG1
  this is text after t ag1
  more text
  yet more text
This is TAG2
  this is text after t ag2
  more text
  line before end of fil

after blank1

after blank2
EOD
cat >$TMPDIR/input2.txt <<EOD
1,2,3,4
12,34,56,79,10000
EOD
cat >$TMPDIR/input3.txt <<EOD
10.1 123.1 456.8 -1234.67
EOD
cat >$TMPDIR/input4.txt <<EOD
this
is
a
file
with
no holes in
it
EOD
cat >$TMPDIR/input5.txt <<EOD
this is a different file after the first 4 characters
file and it has lots of holes in it
no holes in
EOD
TESTARGS="-in $TMPDIR/input1.txt";                         dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt,$TMPDIR/input1.txt";      dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt,$TMPDIR/input1.txt -eqlen";      dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt,$TMPDIR/input2.txt -eqlen";      dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt,$TMPDIR/input1.txt -indl '|'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input4.txt,$TMPDIR/input4.txt -indl 'MISSING' -template 4";      dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sc 13 -ec 10";           dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -sc 13 -nc -10";           dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -sr 13 -er 10";           dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -sr 13 -nr -10";           dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -wl 4";                   dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -mt -xc 4";               dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -sc 3 -ec 10";            dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sc 3 -nc 8";             dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sc 3 -ec 10";            dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sc 3 -ec 10 -n -ll -lt -s -mt"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sc 3 -ec 10 -n -ll -lt -s -rs '?' -mt"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sc 3 -ec 10 -rm";        dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 3 -er 10";            dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 3 -nr 8";             dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 3 -er 10 -all";       dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 3 -nr 8 -sc 3 -ec 10"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[2,4]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[2,4]' -dt"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[2,4]' -dv '!'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[dt:2,4]' -dv '!'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[dv?:2,4]' -dv '!'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[d-:2,4]' -dv '!'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[dp:2,4]' -dv '!'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[d+:2,4]' -dv '!'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[mt:2,4]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[mc:2,4]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[m-:2,4]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[mp:2,4]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[m+:2,4]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cols [2,4]"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cols [4,2]"; dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -cols [-4,-2]"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cols [2,4,2]"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cols [2,4,-2]"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cols [-4,-2,2]"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cols [-4,-2,-2]"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -if TAG  -ifonly"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -if TAG  -ifn 4 -ifonly"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -if TAG  -ifn 4 -ifonly -ifnorestart"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -if TAG  -ifeol -ifbol -bol 'PRE' -eol 'POST\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -if TAG1 -ifonly"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -if TAG1 -ifonly -ifn 3   -cols 'tag:[1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -if TAG1 -ifonly -ifterm TAG2 -cols 'tag:[1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt  -if TAG1 -ifterm TAG2 -iftermbol '\nPRE' -iftermeol 'POST\n' -ifeol"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt  -if TAG1 -ifterm TAG2 -iftermbol '\nPRE' -iftermeol 'POST\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -merge 3"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -merge 3 -mdl ','"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -unmerge 1 -mdl ','"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sortas -mt -dl ','"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sortds -mt -dl ','"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sortac -mt -dl ','"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sortdc -mt -dl ','"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sortan -mt -dl ','"; dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input2.txt -sortan -mt -dl ','"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input2.txt -sortdn -mt -dl ','"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sortas:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sortds:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sortac:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sortdc:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sortan:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sortdn:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sort-:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sortp:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -sortas -mt -dl ' ' -cols '[sort+:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rcds  'AEIOU'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rcdc  'AEIOU'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rcds '!AEIOU'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rcdc '!AEIOU'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rcdc  'AEIOU' -rcss '01234'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rcdc  'AEIOU' -rcss '012345'"; dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -rtds 'this'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rtds 'this' -rtss 'THIS'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rtdc 'this'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rtdc 'this' -rtss 'A'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -rcds  'aeiou' -is -sr 3 -er 10 -sc 3 -ec 10 -all"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -cols '>[fw20:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -cols '>[fw-:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -cols '>[fwp:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -cols '>[fw+:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -pd 10 -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -pd 10 -cols '>[pd20:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -pd 10 -cols '>[pd-:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -pd 10 -cols '>[pdp:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -pd 10 -cols '>[pd+:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jr -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jl -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jc -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jr -cols '>[jl:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jr -cols '>[jr:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jr -cols '>[jc:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jr -cols '>[j-:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jr -cols '>[jp:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -jr -cols '>[j+:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trr -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trl -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trb -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trc -cols '>[1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trr -cols '>[trl:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trr -cols '>[trr:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trr -cols '>[trb:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trr -cols '>[trc:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trr -cols '>[tr-:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trr -cols '>[trp:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -fw 10 -trr -cols '>[tr+:1]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cu"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cl"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cf"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cu -cols '[cu:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cu -cols '[cl:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cu -cols '[cf:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cu -cols '[c-:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cu -cols '[cp:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cu -cols '[c+:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dq"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -ba"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -bs"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -cols '[ba:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -cols '[bs:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -cols '[b2:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -cols '[b-:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -cols '[bp:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -cols '[b+:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -ecc '?'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -ecc '?'  -cols '[ecc^:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -ecc '?'  -cols '[ecc+:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -ecc '?'  -cols '[eccp:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -b2 -ecc '?'  -cols '[ecc-:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -cols '[1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -cols '[fff:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -cols '[ffe:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -cols '[ff-:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -cols '[ffp:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -cols '[ff+:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -fp 5 -cols '[1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -ffe -cols '[1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -ffe -fp 5 -cols '[1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -fp 5 -cols '[fp4:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -fp 5 -cols '[fp-:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -fp 5 -cols '[fpp:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input3.txt -mt -fw 15 -fff -fp 5 -cols '[fp+:1,]'"; dotest; echo $TESTARGS
echo "Passed: $PASSED/$TESTED"
echo "bug fixes or message changes, expect most or all of the following to fail"
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols '[2,4]' -d-"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -mt -dqs"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sc 3 -ec 10 -n -ll -lt -s"; dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -cols '[]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cols '[,]'"; dotest; echo $TESTARGS
# old version wasn't pulling out 3 blanks, new one does 
TESTARGS="-in $TMPDIR/input1.txt -mt -dl ' ' -cols [-4,-2]"; dotest; echo $TESTARGS

echo "Passed: $PASSED/$TESTED"

/bin/rm $TMPDIR/input1.txt
/bin/rm $TMPDIR/input2.txt
/bin/rm $TMPDIR/input3.txt
/bin/rm $TMPDIR/input4.txt
/bin/rm $TMPDIR/input5.txt
