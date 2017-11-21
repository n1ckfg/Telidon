#!/bin/bash
#
#  test script for new features.
#  This script uses accudate, from drm_tools, available from:
#    http://sourceforge.net/projects/drmtools/
#
#  Note the <<'EOD', the quoted input delimiter disables substitution within that input
#
#  Note, tests that use exit or fail will not clear out memory at the end, and so will
#    look like they have memory leaks under valgrind .  These are marked by "with exit".
#    To test that mode do:
#       ./test_features >foo 2>&1
#       cat >pieces.txt <<'EOD'
#       -sect Before
#       o "hide;+F<=pass;+F<=fail"
#       -sect Main
#       m "s:reachable:" "xA;+A"
#       {  m "?:A"       "!; ^}"
#          m "tc:F"      "!; ^}"
#          m "sc:with"   "xA; ^}; !; <=Problem; <A; xA; <-; <=\n"
#       }
#       -eoc
#       EOD
#       ./extract -in foo -cmd pieces.txt
#
#    egrep -i 'reachable:|testing|pass|fail' foo | more
#    and look for 
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
 cat > $TMPDIR/new.txt <<'EOD'
EOD
# eval valgrind --leak-check=full  --show-reachable=yes $NEWPROG  $TESTARGS >$TMPDIR/new.txt
# eval valgrind $NEWPROG  $TESTARGS >$TMPDIR/new.txt
 eval $NEWPROG  $TESTARGS >$TMPDIR/new.txt
 ntime=`$ADATE -ds $hold`
 let TESTED+=1
 $DIFF -q $TMPDIR/new.txt $TMPDIR/old.txt
 if [ $? -eq 0 ]
 then
   echo -n " $TESTED Pass $ntime "
   let PASSED+=1
 else 
   echo -n " $TESTED Fail $ntime "
   $DIFF $TMPDIR/new.txt $TMPDIR/old.txt
 fi
}

docomp ()
{
 hold=`$ADATE -t0`
 ntime=`$ADATE -ds $hold`
 let TESTED+=1
 $DIFF -q $1 $2
 if [ $? -eq 0 ]
 then
   echo -n " $TESTED Pass $ntime "
   let PASSED+=1
 else 
   echo -n " $TESTED Fail $ntime "
 fi
}


#
# use this if the program is supposed to throw an error and exit.
# it compares the error messages,if the syntax changes, the test will fail.
#
dofail ()
{
 hold=`$ADATE -t0`
 cat > $TMPDIR/new.txt <<'EOD'
EOD
 ntime=`$ADATE -ds $hold`
 let TESTED+=1
 eval  $NEWPROG $TESTARGS >/dev/null 2>$TMPDIR/new.txt
 if [ $? -eq 0 ]
 then
   echo -n " $TESTED Fail $ntime "
 else 
   echo -n " $TESTED Pass $ntime "
   let PASSED+=1
 fi
}

echo " Test Ntime       Otime       Test (#CSE = catch syntax error?)"
#
# DO NOT EDIT THESE LINES.  OK to add onto the end.
#
cat >$TMPDIR/input1.txt <<'EOD'
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
  line before end of file
S one two three boo one two three woo blah blah one E
S one two three boo one two three woo blah blah E
f\o\o\bar\ two\\three\65\256\
EOD
cat >$TMPDIR/input2.txt <<'EOD'
0001 a01 b01 c01
0002 a02 b02 c02
0003 a03 b03 c03
0004 a04 b04 c04
0005 a05 b05 c05
0006 a06 b06 c06
0007 a07 b07 c07
0008 a08 b08 c08
0009 a09 b09 c09
0010 a10 b10 c10
0011 a11 b11 c11
0012 a12 b12 c12
0013 a13 b13 c13
0014 a14 b14 c14
0015 a15 b15 c15
0016 a16 b16 c16
0017 a17 b17 c17
0018 a18 b18 c18
0019 a19 b19 c19
0020 a20 b20 c20
EOD
cat >$TMPDIR/pieces.txt <<'EOD'
-vA "one two three"
-vB 
_alpha,baker,,charlie,,,
-vC 
_wash\tthe\tdog
-vD "input<[1,]> vA<[mt:vA:dv?:1,3,-1]> vB<[mt:vB:dv?:1,3]> vC<[mt:vC:dv?:1]>"
-vE ==
-po0 "dq-:sd-:dlv :mdlv|"
-po1 "dq:sd+:dlv,:mdlv|"
-po2 "dq:sd+:dlv\t:mdlv|"
-eoc
EOD

echo
echo "testing basic -fmt STR CLAUSE operations "
echo

cat >$TMPDIR/old.txt <<'EOD'
1,2,3,3,4BANG1,2,3,3,4 1,2 3 3,4
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 5 -nr 1 -mt -dl ',' -fmt '[2,3][4][-3,-2]BANG[2,3][4][-3,-2] [2,3] [4] [-3,-2]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 2 3,3 4BANG123,3,4 12 3 34
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 5 -nr 1 -mt -dl ',' -fmt '[dV :2,3][4][dV :-3,-2]BANG[d-:2,3][4][-3,-2] [d-:2,3] [4] [d-:-3,-2]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
one1234three
EOD

echo
echo "testing -xe "
echo

TESTARGS="-in $TMPDIR/input1.txt -er 1 -mt -xe 2 -cols 'one[1,2]three'"; dofail; echo $TESTARGS  "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -er 1 -mt -xe 3 -cols 'one[1,2]three'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -er 1 -mt -xe 4 -cols 'one[1,2]three'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
a1
b234c
d
EOD

echo
echo "testing -fmt [(with escapes)]"
echo

TESTARGS="-in $TMPDIR/input1.txt -er 1 -fmt 'a[1]\nb[2,4]c\nd'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -er 1 -fmt 'a[1]\010b[2,4]c\010d'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
one two three
EOD

echo
echo "testing -fmt [vA:], [@ABC:], and [=ABC]"
echo

TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -fmt '[mc:va:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -fmt '[mt:va:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
one&alpha&wash&two&baker&the&three&charlie&dog&&&
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A;po1B;po2C' -fmt '[mt:=ABC:dv&:1,4]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
two&baker&the&==&three&charlie&dog&==&one&alpha&wash&==&one&alpha&wash&==
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A;po1B;po2C' -fmt '[mt:@ABCE:dv&:2,5]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
three&charlie&dog&==&one&alpha&wash&==&three&charlie&dog&==
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A;po1B;po2C' -fmt '[mt:@ABCE:dv&:-5,-1,-2]'"; dotest; echo $TESTARGS

echo
echo "testing -pm '' 'po#A' "
echo

cat >$TMPDIR/old.txt <<'EOD'
one two three
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po1A' -fmt '[mt:dv?:va:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po2A' -fmt '[mt:dv?:va:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
one?two?three
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A' -fmt '[mt:dv?:va:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'poA' -fmt '[mt:dv?:va:1,]'"; dotest; echo $TESTARGS
cat >$TMPDIR/old.txt <<'EOD'
alpha?baker?charlie???
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A;po1B;po2C' -fmt '[mt:dv?:vB:1,6]'"; dotest; echo $TESTARGS


echo
echo "testing -pm '' 'vN' "
echo

cat >$TMPDIR/old.txt <<'EOD'
input<1234> vA<three?two?one> vB<alpha?baker?charlie> vC<wash>
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A;po1B;po2C;vD' -fmt '[vd:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
input<1234>^vA<three?two?one>^vB<alpha?baker?charlie>^vC<wash>
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A;po1B;po2C;vD;poD' -fmt '[mt:dv^:vd:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
input<==ONE TWO THREE> vA<three?two?one> vB<alpha?baker?charlie> vC<wash>
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A;po1B;po2C;+E<=ONE TWO THREE;vD<E' -fmt '[vd:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
input<==ONE^TWO^THREE>^vA<three?two?one>^vB<alpha?baker?charlie>^vC<wash>
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -er 1 -pm 'm:' 'po0A;po1B;po2C;+E<=ONE TWO THREE;vD<E;poD' -fmt '[mt:dv^:vd:1,]'"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '+A' operations"
echo

cat >$TMPDIR/pieces2.txt <<'EOD'
-sect COMMON
=doit
 o  "<[mt:vC:dv,:1,]; <=\n; xC;ret"
-sect BEFORE
 o  "+A<=1;  +A<=2;  +A<=3"
 o  "+B<=one;+B<=two;+B<=three"
 oA "+C;      &doit"
 o  "+C<A;    &doit"
 o  "+C<ABA;  &doit"
 oA "+C<1;    &doit"
 o  "+C<1A;   &doit"
 o  "+C<1ABA; &doit"
 o  "? 1;"  ##set RESULT to 1
 oA "+C<0;    &doit"
 o  "+C<0A;   &doit"
 o  "+C<0ABA; &doit"
 o  "? 3; +C<0ABA; ? 2; +C<0ABA; ? 1; +C<0ABA; &doit"
# note that using 4 would be an error, since there is no 4th token in the source variables
 o  "eof"
-eoc
EOD

cat >$TMPDIR/old.txt <<'EOD'
1,2,3
1,2,3
1,2,3,one,two,three,1,2,3
1
1
1,one,1
1
1
1,one,1
3,three,3,2,two,2,1,one,1
EOD
TESTARGS="-cmd $TMPDIR/pieces2.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm '' 'mA' operations"
echo

cat >$TMPDIR/pieces2.txt <<'EOD'
-sect COMMON
=doit
 o "<[mt:vB:dv,:1,]; <=\n; xB; +B<A; ret"
-sect BEFORE
 o "+A<=1;+A<=2;+A<=3;+A<=4; xB; +B<A"
 o "mB;   &doit"
 o "m-2B; &doit"
 o "m-3B; &doit"
 o "m-4B; &doit"
 o "m-5B; &doit"
 o "?  1; m0B; &doit"
 o "? -2; m0B; &doit"
 o "? -3; m0B; &doit"
 o "? -4; m0B; &doit"
 o "? -5; m0B; &doit"
 o "eof"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
1234
1,2,34
1,234
1234
1234
1234
1,2,34
1,234
1234
1234
EOD

TESTARGS="-cmd $TMPDIR/pieces2.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '|A' operations"
echo
cat >$TMPDIR/old.txt <<'EOD'
vAmc:
1234 vAmt:^1234
vAmc:
1234
1235 vAmt:^1234^1235
vAmc:
1234
1235
1236 vAmt:^1234^1235^1236
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 3 -pm 'm:' '|A;+A' -fmt 'vAmc:[mc:vA:1,] vAmt:[mt:dv^:vA:1,]'"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '>A' operations, also % substring list modifiers"
echo

cat >$TMPDIR/old.txt <<'EOD'
Test H: >fo^bo^wo<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -pm 'm:' '+B<=Sfoo boo wooE' -pmB 'gp:.o' '>A' -fmt 'Test H: >[mt:dv^:vA:1,]<'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
Test I: >o ^o <
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -pm 'm:' '+B<=Sfoo boo wooE' -pmB 'gp:.o' '%I;>A' -fmt 'Test I: >[mt:dv^:vA:1,]<'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
Test B: >S<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -pm 'm:' '+B<=Sfoo boo wooE' -pmB 'gp:.o' '%B;>A' -fmt 'Test B: >[mt:dv^:vA:1,]<'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
Test A: >oE<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -pm 'm:' '+B<=Sfoo boo wooE' -pmB 'gp:.o' '%A;>A' -fmt 'Test A: >[mt:dv^:vA:1,]<'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
Test HI: >fo^o ^bo^o ^wo<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -pm 'm:' '+B<=Sfoo boo wooE' -pmB 'gp:.o' '%HI;>A' -fmt 'Test HI: >[mt:dv^:vA:1,]<'"; dotest; echo $TESTARGS


cat >$TMPDIR/old.txt <<'EOD'
Test BHIA: >S^fo^o ^bo^o ^wo^oE<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -pm 'm:' '+B<=Sfoo boo wooE' -pmB 'gp:.o' '%all;>A' -fmt 'Test BHIA: >[mt:dv^:vA:1,]<'"; dotest; echo $TESTARGS


echo
echo "testing -pm '' 'xA' operations (clear variable, remove tokens)"
echo

cat >$TMPDIR/pieces2.txt <<'EOD'
-sect COMMON
=doit
 m   "?:B" "<[mt:vB:dv,:1,]; <=\n; !; <=Cleared\n"
 o   "xB; +B<A; ret"
-sect BEFORE
 o "+A<=1;+A<=2;+A<=3;+A<=4; xB; +B<A"
 o "      &doit"
 o "x-1B; &doit"
 o "x-2B; &doit"
 o "x-3B; &doit"
 o "x-4B; &doit"
 o "x-5B; &doit"
 o "x-6B; &doit"
 o "x1B;  &doit"
 o "x2B;  &doit"
 o "x3B;  &doit"
 o "x4B;  &doit"
 o "x5B;  &doit"
 o "x6B;  &doit"
 o "? -1; x0B; &doit"
 o "? -2; x0B; &doit"
 o "? -3; x0B; &doit"
 o "? -4; x0B; &doit"
 o "? -5; x0B; &doit"
 o "? -6; x0B; &doit"
 o "?  1; x0B; &doit"
 o "?  2; x0B; &doit"
 o "?  3; x0B; &doit"
 o "?  4; x0B; &doit"
 o "?  5; x0B; &doit"
 o "?  6; x0B; &doit"
 o "eof"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
1,2,3,4
1,2,3
1,2
1
Cleared
Cleared
Cleared
Cleared
1
1,2
1,2,3
1,2,3,4
1,2,3,4
1,2,3
1,2
1
Cleared
Cleared
Cleared
Cleared
1
1,2
1,2,3
1,2,3,4
1,2,3,4
EOD

TESTARGS="-cmd $TMPDIR/pieces2.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '?'  operations (math)"
echo

#
#  these are mostly from test_dmath.sh, just cut and paste in here, eliminate the
#  dmath =,<,> parts
#

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "? 1      ;    &result"
  o "? 1+3    ;    &result"
  o "? 1-3    ;    &result"
  o "? 1*3    ;    &result"
  o "? 1/3    ;    &result"
  o "? $A=10  ;    &result"
  o "? $B=20  ;    &result"
  o "? $C=30  ;    &result"
  o "? $A     ;    &result"
  o "? $A+3   ;    &result"
  o "? $A-3   ;    &result"
  o "? $A*3   ;    &result"
  o "? $A/3   ;    &result"
  o "? ($A)   ;    &result"
  o "? ($A+3) ;    &result"
  o "? ($A-3) ;    &result"
  o "? ($A*3) ;    &result"
  o "? ($A/3) ;    &result"
  o "? +($A)  ;    &result"
  o "? +($A+3);    &result"
  o "? +($A-3);    &result"
  o "? +($A*3);    &result"
  o "? +($A/3);    &result"
  o "? +$A    ;    &result"
  o "? +$A+3  ;    &result"
  o "? +$A-3  ;    &result"
  o "? +$A*3  ;    &result"
  o "? +$A/3  ;    &result"
  o "? -$A    ;    &result"
  o "? -$A+3  ;    &result"
  o "? -$A-3  ;    &result"
  o "? -$A*3  ;    &result"
  o "? -$A/3  ;    &result"
  o "? -($A)  ;    &result"
  o "? -($A+3);    &result"
  o "? -($A-3);    &result"
  o "? -($A*3);    &result"
  o "? -($A/3);    &result"
  o "? 2%3    ;    &result"
  o "? trc(1.1) ;  &result"
  o "? trc(-1.1);  &result"
  o "? lid(1.1) ;  &result"
  o "? lid(-1.1);  &result"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
1.000000
4.000000
-2.000000
3.000000
0.333333
10.000000
20.000000
30.000000
10.000000
13.000000
7.000000
30.000000
3.333333
10.000000
13.000000
7.000000
30.000000
3.333333
10.000000
13.000000
7.000000
30.000000
3.333333
10.000000
13.000000
7.000000
30.000000
3.333333
-10.000000
-7.000000
-13.000000
-30.000000
-3.333333
-10.000000
-13.000000
-7.000000
-30.000000
-3.333333
0.666667
1.000000
-1.000000
2.000000
-2.000000
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS  "#General"

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "? sin(0)                 ;    &result"
  o "? cos(0)                 ;    &result"
  o "? tan(0)                 ;    &result"
  o "? asin(sin(0))           ;    &result"
  o "? acos(cos(0))           ;    &result"
  o "? atan(tan(0))           ;    &result"
  o "? sin(d2r(90))           ;    &result"
  o "? cos(d2r(90))           ;    &result"
  o "? tan(d2r(90))           ;    &result"
  o "? r2d(asin(sin(d2r(90))));    &result"
  o "? r2d(acos(cos(d2r(90))));    &result"
  o "? r2d(atan(tan(d2r(90))));    &result"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
0.000000
1.000000
0.000000
0.000000
0.000000
0.000000
1.000000
0.000000
16331778728383844.000000
90.000000
90.000000
90.000000
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "#Trig functions"

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
=resultx
  o "<[fp0:ffx:v$-:]; <=\n; ret"
-sect BEFORE
  o "? 2^3              ;    &result"
  o "? 2^-3             ;    &result"
  o "? -2^3             ;    &result"
  o "? -2^-3            ;    &result"
  o "? log(0)           ;    &result"
  o "? ln(0)            ;    &result"
  o "? log(-1)          ;    &result"
  o "? ln(-1)           ;    &result"
  o "? e10(log(10))     ;    &result"
  o "? ee(ln(10))       ;    &result"
  o "? log(e10(10))     ;    &result"
  o "? ln(ee(10))       ;    &result"
  o "? $Z=log(10)       ;    &result"
  o "? e10(-$Z)         ;    &result"
  o "? sinh(0)          ;    &result"
  o "? sinh(1)          ;    &result"
  o "? sinh(10)         ;    &result"
  o "? cosh(0)          ;    &result"
  o "? cosh(1)          ;    &result"
  o "? cosh(10)         ;    &result"
  o "? tanh(0)          ;    &result"
  o "? tanh(1)          ;    &result"
  o "? tanh(10)         ;    &result"
  o "? not(0xFF)        ;    &resultx"
  o "? not(not(0xFF))   ;    &resultx"
  o "? and(0xFF,0x18)   ;    &resultx"
  o "? or(0x81,0x18)    ;    &resultx"
  o "? xor(0xFF,0x18)   ;    &resultx"
  o "? shl(0x10,4)      ;    &resultx"
  o "? shr(0x10,4)      ;    &resultx"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
8.000000
0.125000
-8.000000
-0.125000
-inf
-inf
nan
nan
10.000000
10.000000
10.000000
10.000000
1.000000
0.100000
0.000000
1.175201
11013.232875
1.000000
1.543081
11013.232920
0.000000
0.761594
1.000000
ffffff00
ff
18
99
e7
100
1
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "#Logs, exponents, hyperbolic functions, bitwise"

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "? 2++3                    ;    &result"
  o "? 2+-3                    ;    &result"
  o "? 2-+3                    ;    &result"
  o "? 2--3                    ;    &result"
  o "? 2*+3                    ;    &result"
  o "? 2*-3                    ;    &result"
  o "? 5/+3                    ;    &result"
  o "? 5/-3                    ;    &result"
  o "? 5%+3                    ;    &result"
  o "? 5%-3                    ;    &result"
  o "? 2^+3                    ;    &result"
  o "? 2^-3                    ;    &result"
  o "? +2++3                   ;    &result"
  o "? +2+-3                   ;    &result"
  o "? +2-+3                   ;    &result"
  o "? +2--3                   ;    &result"
  o "? +2*+3                   ;    &result"
  o "? +2*-3                   ;    &result"
  o "? +5/+3                   ;    &result"
  o "? +5/-3                   ;    &result"
  o "? +5%+3                   ;    &result"
  o "? +5%-3                   ;    &result"
  o "? +2^+3                   ;    &result"
  o "? +2^-3                   ;    &result"
  o "? -2++3                   ;    &result"
  o "? -2+-3                   ;    &result"
  o "? -2-+3                   ;    &result"
  o "? -2--3                   ;    &result"
  o "? -2*+3                   ;    &result"
  o "? -2*-3                   ;    &result"
  o "? -5/+3                   ;    &result"
  o "? -5/-3                   ;    &result"
  o "? -5%+3                   ;    &result"
  o "? -5%-3                   ;    &result"
  o "? -2^+3                   ;    &result"
  o "? -2^-3                   ;    &result"
  o "? (+2++3)                 ;    &result"
  o "? (+2+-3)                 ;    &result"
  o "? (+2-+3)                 ;    &result"
  o "? (+2--3)                 ;    &result"
  o "? (+2*+3)                 ;    &result"
  o "? (+2*-3)                 ;    &result"
  o "? (+5/+3)                 ;    &result"
  o "? (+5/-3)                 ;    &result"
  o "? (+5%+3)                 ;    &result"
  o "? (+5%-3)                 ;    &result"
  o "? (+2^+3)                 ;    &result"
  o "? (+2^-3)                 ;    &result"
  o "? (-2++3)                 ;    &result"
  o "? (-2+-3)                 ;    &result"
  o "? (-2-+3)                 ;    &result"
  o "? (-2--3)                 ;    &result"
  o "? (-2*+3)                 ;    &result"
  o "? (-2*-3)                 ;    &result"
  o "? (-5/+3)                 ;    &result"
  o "? (-5/-3)                 ;    &result"
  o "? (-5%+3)                 ;    &result"
  o "? (-5%-3)                 ;    &result"
  o "? (-2^+3)                 ;    &result"
  o "? (-2^-3)                 ;    &result"
  o "? +log(10)                ;    &result"
  o "? -log(10)                ;    &result"
  o "? max(-max(1,2),+max(3,4));    &result"
  o "? max(+max(1,2),-max(3,4));    &result"
  o "? $A=5                    ;    &result"
  o "? -$A                     ;    &result"
  o "? +$A                     ;    &result"
  o "? max($A,$A)              ;    &result"
  o "? max(-$A,-$A)            ;    &result"
  o "? max($A,-$A)             ;    &result"
  o "? max(-$A,$A)             ;    &result"
  o "? max(+$A,+$A)            ;    &result"
  o "? max($A,+$A)             ;    &result"
  o "? max(+$A,$A)             ;    &result"
  o "? max(($A),$A)            ;    &result"
  o "? max((-$A),-$A)          ;    &result"
  o "? max(($A),-$A)           ;    &result"
  o "? max((-$A),$A)           ;    &result"
  o "? max((+$A),+$A)          ;    &result"
  o "? max(($A),+$A)           ;    &result"
  o "? max((+$A),$A)           ;    &result"
  o "? max($A,($A))            ;    &result"
  o "? max(-$A,(-$A))          ;    &result"
  o "? max($A,(-$A))           ;    &result"
  o "? max(-$A,($A))           ;    &result"
  o "? max(+$A,(+$A))          ;    &result"
  o "? max($A,(+$A))           ;    &result"
  o "? max(+$A,($A))           ;    &result"
  o "? max(($A),($A))          ;    &result"
  o "? max((-$A),(-$A))        ;    &result"
  o "? max(($A),(-$A))         ;    &result"
  o "? max((-$A),($A))         ;    &result"
  o "? max((+$A),(+$A))        ;    &result"
  o "? max(($A),(+$A))         ;    &result"
  o "? max((+$A),($A))         ;    &result"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
5.000000
-1.000000
-1.000000
5.000000
6.000000
-6.000000
1.666667
-1.666667
0.666667
-0.666667
8.000000
0.125000
5.000000
-1.000000
-1.000000
5.000000
6.000000
-6.000000
1.666667
-1.666667
0.666667
-0.666667
8.000000
0.125000
1.000000
-5.000000
-5.000000
1.000000
-6.000000
6.000000
-1.666667
1.666667
-0.666667
0.666667
-8.000000
-0.125000
5.000000
-1.000000
-1.000000
5.000000
6.000000
-6.000000
1.666667
-1.666667
0.666667
-0.666667
8.000000
0.125000
1.000000
-5.000000
-5.000000
1.000000
-6.000000
6.000000
-1.666667
1.666667
-0.666667
0.666667
-8.000000
-0.125000
1.000000
-1.000000
4.000000
2.000000
5.000000
-5.000000
5.000000
5.000000
-5.000000
5.000000
5.000000
5.000000
5.000000
5.000000
5.000000
-5.000000
5.000000
5.000000
5.000000
5.000000
5.000000
5.000000
-5.000000
5.000000
5.000000
5.000000
5.000000
5.000000
5.000000
-5.000000
5.000000
5.000000
5.000000
5.000000
5.000000
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "#Unary"

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "? 1 - 6 - 7   ;    &result"
  o "? 1000 / 10 / 10;  &result"
  o "? 1 + 3 * 2   ;    &result"
  o "? 3 * 2 + 1   ;    &result"
  o "? 1 - 3 * 2   ;    &result"
  o "? 3 * 2 - 1   ;    &result"
  o "? 1 + 4 / 2   ;    &result"
  o "? 4 / 2 + 1   ;    &result"
  o "? 1 - 4 / 2   ;    &result"
  o "? 4 / 2 - 1   ;    &result"
  o "? 1 + 4 ^ 2   ;    &result"
  o "? 4 ^ 2 + 1   ;    &result"
  o "? 1 - 4 ^ 2   ;    &result"
  o "? 4 ^ 2 - 1   ;    &result"
  o "? 1 + 4 % 2   ;    &result"
  o "? 4 % 2 + 1   ;    &result"
  o "? 1 - 4 % 2   ;    &result"
  o "? 4 % 2 - 1   ;    &result"
  o "? 1 * 4 % 2   ;    &result"
  o "? 4 % 2 * 1   ;    &result"
  o "? 1 / 5 % 2   ;    &result"
  o "? 5 % 2 / 1   ;    &result"
  o "? 2 +  3 ? 4  ;    &result"
  o "? 4 ?  2 + 3  ;    &result"
  o "? 9 -  3 ? 4  ;    &result"
  o "? 4 ?  9 - 3  ;    &result"
  o "? 3 *  3 ? 4  ;    &result"
  o "? 4 ?  3 * 3  ;    &result"
  o "? 15 / 3 ? 4  ;    &result"
  o "? 4 ?  3 / 0.2;    &result"
  o "? (2 +  3) ? 4;    &result"
  o "? 4 ?  (2 + 3);    &result"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
-12.000000
10.000000
7.000000
7.000000
-5.000000
5.000000
3.000000
3.000000
-1.000000
1.000000
17.000000
17.000000
-15.000000
15.000000
1.000000
1.000000
1.000000
-1.000000
0.000000
0.000000
0.100000
0.500000
1.000000
-1.000000
1.000000
-1.000000
1.000000
-1.000000
1.000000
-1.000000
1.000000
-1.000000
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "#Precedence"

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "? $A=1+dim($A[],4)       ;    &result"
  o "? $A[2]=2                ;    &result"
  o "? $A[3]=3                ;    &result"
  o "? $A[4]=4                ;    &result"
  o "? $A[1]                  ;    &result"
  o "? $A[2]                  ;    &result"
  o "? $A[3]                  ;    &result"
  o "? $A[4]                  ;    &result"
  o "? $A[-1]                 ;    &result"
  o "? $A[-2]                 ;    &result"
  o "? $A[-3]                 ;    &result"
  o "? $A[-4]                 ;    &result"
  o "? $A[min(max(-4,-20),-1)];    &result"
  o "? $A[min(max(-4,-3),-1)] ;    &result"
  o "? $A[min(max(-4,2),-1)]  ;    &result"
  o "? len($A[])              ;    &result"
  o "? sum($A[])              ;    &result"
  o "? sm2($A[])              ;    &result"
  o "? 5+dim($A[],10)         ;    &result"
  o "? $A[]=10                ;    &result"
  o "? len($A[])              ;    &result"
  o "? sum($A[])              ;    &result"
  o "? sm2($A[])              ;    &result"
  o "? cat($D[],2)            ;    &result"
  o "? cat($D[],3)            ;    &result"
  o "? $D[1]                  ;    &result"
  o "? $D[2]                  ;    &result"
  o "? $D[3]                  ;    &result"
  o "? $A[3]=6                ;    &result"
  o "? $A[4]=7                ;    &result"
  o "? $D[1,2]=$A[3,4]        ;    &result"
  o "? $D[1]                  ;    &result"
  o "? $D[2]                  ;    &result"
  o "? len($A[3,4])           ;    &result"
  o "? sum($A[3,4])           ;    &result"
  o "? sm2($A[3,4])           ;    &result"
  o "? sum($A[-8,-7])         ;    &result"
  o "? sm2($A[-8,-7])         ;    &result"
  o "? idx($A[1,3])           ;    &result"
  o "? $A[1]                  ;    &result"
  o "? $A[2]                  ;    &result"
  o "? $A[3]                  ;    &result"
  o "? dim($A[],3)            ;    &result"
  o "? dim($B[],3)            ;    &result"
  o "? $B[]=$A[1,3]           ;    &result"
  o "? $B[]*3                 ;    &result"
  o "<[dv,:v$B:];<=\n;"
  o "? inv($A[])              ;    &result"
  o "? map($B[],$A[])         ;    &result"
  o "<[dv,:v$B:];<=\n;"
  o "? ump($B[],$A[])         ;    &result"
  o "<[dv,:v$B:];<=\n;"
  o "? dim($A[],6)+dim($B[],6);    &result"
  o "? $B[1]=324              ;    &result"
  o "? $B[2]=982              ;    &result"
  o "? $B[3]=-2398            ;    &result"
  o "? $B[4]=-24              ;    &result"
  o "? $B[5]=935              ;    &result"
  o "? $B[6]=2398             ;    &result"
  o "? $A[]=$B[]              ;    &result"
  o "? srt($A[])              ;    &result"
  o "<[dv,:v$A:];<=\n;"
  o "? $A[]=$B[]              ;    &result"
  o "? srt($A[2,4])           ;    &result"
  o "<[dv,:v$A:];<=\n;"
  o "? $A[]=$B[]              ;    &result"
  o "? six($A[2,4])           ;    &result"
  o "<[dv,:v$A:];<=\n;"
  o "? $A[]=$B[]              ;    &result"
  o "? six($A[])              ;    &result"
  o "? map($B[],$A[])         ;    &result"
  o "<[dv,:v$B:];<=\n;"
  o "? ini($A[],1,2,3,4,5,6,7,8);    &result"
  o "? sum($A[])              ;    &result"
  o "? cat($A[],9,10)         ;    &result"
  o "? sum($A[])              ;    &result"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
1.000000
2.000000
3.000000
4.000000
1.000000
2.000000
3.000000
4.000000
4.000000
3.000000
2.000000
1.000000
1.000000
2.000000
4.000000
4.000000
10.000000
30.000000
5.000000
10.000000
10.000000
100.000000
1000.000000
2.000000
3.000000
0.000000
2.000000
3.000000
6.000000
7.000000
2.000000
6.000000
7.000000
10.000000
13.000000
85.000000
13.000000
85.000000
0.000000
1.000000
2.000000
3.000000
0.000000
0.000000
3.000000
1.000000
3.000000,6.000000,9.000000
0.000000
1.000000
9.000000,6.000000,3.000000
1.000000
3.000000,6.000000,9.000000
0.000000
324.000000
982.000000
-2398.000000
-24.000000
935.000000
2398.000000
6.000000
0.000000
-2398.000000,-24.000000,324.000000,935.000000,982.000000,2398.000000
6.000000
0.000000
324.000000,-2398.000000,-24.000000,982.000000,935.000000,2398.000000
6.000000
0.000000
324.000000,3.000000,4.000000,2.000000,935.000000,2398.000000
6.000000
0.000000
1.000000
-2398.000000,-24.000000,324.000000,935.000000,982.000000,2398.000000
8.000000
36.000000
10.000000
55.000000
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "#Arrays"


cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "? dim($a[],4)                  ;    &result"
  o "? dim($b[],4)                  ;    &result"
  o "? $A=1                         ;    &result"
  o "? $A[2]=2                      ;    &result"
  o "? $A[3]=3                      ;    &result"
  o "? $A[4]=4                      ;    &result"
  o "? $A[-1]                       ;    &result"
  o "? $A[-2]                       ;    &result"
  o "? $A[-3]                       ;    &result"
  o "? $A[-4]                       ;    &result"
  o "? $A[1+(4-3)]=$A[1+(4-3)]      ;    &result"
  o "? $A[1+(4-3)]=$A[1+$A[1]*(4-3)];    &result"
  o "? $B[]=$A[]                    ;    &result"
  o "? $B[1]                        ;    &result"
  o "? $B[2]                        ;    &result"
  o "? $B[3]                        ;    &result"
  o "? $B[4]                        ;    &result"
  o "? inv($A[])                    ;    &result"
  o "? $A[1]                        ;    &result"
  o "? $A[2]                        ;    &result"
  o "? $A[3]                        ;    &result"
  o "? $A[4]                        ;    &result"
  o "? inv($A[])                    ;    &result"
  o "? inv($A[2,4])                 ;    &result"
  o "? $A[2]                        ;    &result"
  o "? $A[3]                        ;    &result"
  o "? $A[4]                        ;    &result"
  o "? $A[]=$B[]                    ;    &result"
  o "? del($A[])                    ;    &result"
  o "? len($A[])                    ;    &result"
  o "? $A[1]                        ;    &result"
  o "? dim($a[],4)                  ;    &result"
  o "? $A[]=$B[]                    ;    &result"
  o "? del($A[2,3])                 ;    &result"
  o "? $A[1]                        ;    &result"
  o "? $A[2]                        ;    &result"
  o "? dim($a[],4)                  ;    &result"
  o "? $A[]=$B[]                    ;    &result"
  o "? del($A[1,2])                 ;    &result"
  o "? $A[1]                        ;    &result"
  o "? $A[2]                        ;    &result"
  o "? dim($a[],4)                  ;    &result"
  o "? $A[]=$B[]                    ;    &result"
  o "? del($A[3,4])                 ;    &result"
  o "? $A[1]                        ;    &result"
  o "? $A[2]                        ;    &result"
  o "? del($A[1,1])                 ;    &result"
  o "? $A[1]                        ;    &result"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
0.000000
0.000000
1.000000
2.000000
3.000000
4.000000
4.000000
3.000000
2.000000
1.000000
2.000000
2.000000
4.000000
1.000000
2.000000
3.000000
4.000000
0.000000
4.000000
3.000000
2.000000
1.000000
0.000000
0.000000
4.000000
3.000000
2.000000
4.000000
1.000000
1.000000
0.000000
0.000000
4.000000
2.000000
1.000000
4.000000
0.000000
4.000000
2.000000
3.000000
4.000000
0.000000
4.000000
2.000000
1.000000
2.000000
1.000000
2.000000
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "#Assignment"

cat >$TMPDIR/pieces.txt <<'EOD'
-sect BEFORE
  o "? -0"
  o "<[fp3:v$-:];<=\n;"
  o "<[fp3:nz:v$-:];<=\n;"
  o "<[fp3:ffe:nz:v$-:];<=\n;"
  o "<[fp6:v$-:];<=\n;"
  o "<[fp6:nz:v$-:];<=\n;"
  o "<[fp9:v$-:];<=\n;"
  o "<[fp9:nz:v$-:];<=\n;"
  o "? 1"
  o "<[fp0:v$-:];<=\n;"
  o "<[fp9:v$-:];<=\n;"
  o "<[fp0:ffe:v$-:];<=\n;"
  o "<[fp6:ffe:v$-:];<=\n;"
  o "? 3"
  o "<[fp9:ffd:v$-:];<=\n;"
  o "? -3"
  o "<[fp9:ffd:v$-:];<=\n;"
  o "? 0b11"
  o "<[fp0:ffd:v$-:];<=\n;"
  o "? 10"
  o "<[fp0:ffu:v$-:];<=\n;"
  o "? 0o20"
  o "<[fp0:ffu:v$-:];<=\n;"
  o "? 10"
  o "<[fp0:ffx:v$-:];<=\n;"
  o "? 0x10"
  o "<[fp0:ffx:v$-:];<=\n;"
  o "? 10"
  o "<[fp0:ffo:v$-:];<=\n;"
  o "? 64"
  o "<[fp0:ffo:v$-:];<=\n;"
  o "? 10"
  o "<[fp4:ffo:v$-:];<=\n;"
  o "<[fp4:ffx:v$-:];<=\n;"
  o "? 10"
  o "<[fp4:ffd:v$-:];<=\n;"
  o "? -10"
  o "<[fp4:ffd:v$-:];<=\n;"
  o "? 123.4"
  o "<[fp4:ffd:v$-:];<=\n;"
  o "? -123.4"
  o "<[fp4:ffd:v$-:];<=\n;"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
0.000
-0.000
-0.000e+00
0.000000
-0.000000
0.000000000
-0.000000000
1
1.000000000
1e+00
1.000000e+00
000000003
-000000003
3
10
16
a
10
12
100
0012
000a
0010
-0010
0123
-0123
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS '#Notation/Precision'

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "+A<=1;   +A<=2;    +A<=3"
  o "+B<=11;  +B<=22;   +B<=33"
  o "+C<=111; +C<=222;  +C<=333"
  o "+D<=foo; +D<=inf;  +D<=+inf; +D<=-inf; +D<=nan"
  o "+E<=ab;  +E<=cdef; +E<=abc;  +E<=bcd;  +E<=CDEE; +E<=def"
  o "? dim($a[],tok(a[]));    &result"
  o "? $a[]=a[]          ;    &result"
  o "? 4+a[1]            ;    &result"
  o "? 4+b[2]            ;    &result"
  o "? 4+c[3]            ;    &result"
  o "? 4+a[a[1]]         ;    &result"
  o "? $a=c[3]           ;    &result"
  o "? $a[1,2]=a[2,3]    ;    &result"
  o "? $a[1]             ;    &result"
  o "? $a[2]             ;    &result"
  o "? sln(a[])          ;    &result"
  o "? sln(a[1,2])       ;    &result"
  o "? tln(a[])          ;    &result"
  o "? tln(a[1,2])       ;    &result"
  o "? tln(b[])          ;    &result"
  o "? tln(b[1,2])       ;    &result"
  o "? tln(c[])          ;    &result"
  o "? tln(c[1,2])       ;    &result"
  o "? tln(c[-2,-1])     ;    &result"
  o "? dim($A[],tok(d[]));    &result"
  o "? $A[]=d[]          ;    &result"
  o "<[dv,:fp0:v$A:];<=\n"
  o "? dim($a[],tok(e[]));    &result"
  o "? tix($a[],e[])     ;    &result"
  o "<[dv,:fp0:v$A:];<=\n"
  o "? tcx($a[],e[])     ;    &result"
  o "<[dv,:fp0:v$A:];<=\n"
  o "? tix($a[2,6],e[1,5]);    &result"
  o "<[dv,:fp0:v$A:];<=\n"
  o "? tcx($a[1,5],e[1,5]);    &result"
  o "<[dv,:fp0:v$A:];<=\n"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
0.000000
3.000000
5.000000
26.000000
337.000000
5.000000
333.000000
2.000000
2.000000
3.000000
3.000000
3.000000
3.000000
2.000000
6.000000
4.000000
9.000000
6.000000
6.000000
0.000000
5.000000
nan,inf,inf,-inf,nan
0.000000
0.000000
5,1,3,4,2,6
0.000000
1,3,4,5,2,6
0.000000
1,5,1,3,4,2
0.000000
1,3,4,5,2,2
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS '#Tokens'

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "? dim($A[],3)         ;    &result"
  o "? dim($B[],3)         ;    &result"
  o "? dim($C[],3)         ;    &result"
  o "? $C[1]=11            ;    &result"
  o "? $C[2]=22            ;    &result"
  o "? $C[3]=33            ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? e10(log($A[]))      ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? ee(ln($A[]))        ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]+1              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? 1+$A[]              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]-1              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? 1-$A[]              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]*-1             ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? 2*$A[]              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]/2              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? 66/$A[]             ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]%4              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? 11%$A[]             ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]^2              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? 2^$A[]              ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? $A[]?22             ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? 22?$A[]             ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? max($A[]*0+$C[],22) ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? max(0*$A[]+$C[],22) ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? min(0*$A[]+$C[],22) ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $C[1]=d2r(30)       ;    &result"
  o "? $C[2]=d2r(45)       ;    &result"
  o "? $C[3]=d2r(60)       ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? sin($A[])+1         ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? 1+cos($A[])         ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? 1+tan($A[])         ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? r2d(atan(tan($A[])));    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? r2d(asin(sin($A[])));    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? r2d(acos(cos($A[])));    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $C[1]=1.234         ;    &result"
  o "? $C[2]=-1.234        ;    &result"
  o "? $C[3]=1.501         ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? 1+abs($A[])         ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? 1+chs($A[])         ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? 1+trc($A[])         ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? lid($A[])           ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? 1+rnd($A[])         ;    &result"
  o "? $A[1]               ;    &result"
  o "? $A[2]               ;    &result"
  o "? $A[3]               ;    &result"
  o "? $C[1]=0             ;    &result"
  o "? $C[2]=1             ;    &result"
  o "? $C[3]=10            ;    &result"
  o "? $A[]=$C[]           ;    &result"
  o "? sinh($A[])          ;    &result"
  o "<[dv,:v$A:];<=\n;"
  o "? $A[]=$C[]           ;    &result"
  o "? cosh($A[])          ;    &result"
  o "<[dv,:v$A:];<=\n;"
  o "? $A[]=$C[]           ;    &result"
  o "? tanh($A[])          ;    &result"
  o "<[dv,:v$A:];<=\n;"
#
# note for unary minus on an array like below the array on
# the right is changed, whereas in most languages it wouldn't be.
#
  o "? $A[]=-$C[]          ;    &result"
  o "<[dv,:v$A:];<=\n;"
  o "? $A[]=-rnd($C[])     ;    &result"
  o "<[dv,:v$A:];<=\n;"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
0.000000
0.000000
0.000000
11.000000
22.000000
33.000000
3.000000
0.000000
11.000000
22.000000
33.000000
3.000000
0.000000
11.000000
22.000000
33.000000
3.000000
11.000000
22.000000
33.000000
0.000000
12.000000
23.000000
34.000000
0.000000
13.000000
24.000000
35.000000
0.000000
12.000000
23.000000
34.000000
0.000000
-11.000000
-22.000000
-33.000000
0.000000
11.000000
22.000000
33.000000
0.000000
22.000000
44.000000
66.000000
0.000000
11.000000
22.000000
33.000000
0.000000
6.000000
3.000000
2.000000
0.000000
0.500000
0.750000
0.500000
3.000000
0.000000
0.000000
0.500000
0.333333
0.000000
0.000000
0.250000
0.111111
0.000000
1.000000
1.189207
1.080060
3.000000
0.000000
-1.000000
0.000000
1.000000
3.000000
0.000000
1.000000
0.000000
-1.000000
0.000000
22.000000
22.000000
33.000000
3.000000
0.000000
22.000000
22.000000
33.000000
3.000000
0.000000
11.000000
22.000000
22.000000
0.523599
0.785398
1.047198
3.000000
0.000000
1.500000
1.707107
1.866025
3.000000
0.000000
1.866025
1.707107
1.500000
3.000000
0.000000
1.577350
2.000000
2.732051
3.000000
0.000000
30.000000
45.000000
60.000000
3.000000
0.000000
30.000000
45.000000
60.000000
3.000000
0.000000
30.000000
45.000000
60.000000
1.234000
-1.234000
1.501000
3.000000
0.000000
2.234000
2.234000
0.000000
-1.234000
-1.234000
3.000000
0.000000
2.000000
0.000000
2.000000
3.000000
0.000000
2.000000
-2.000000
2.000000
3.000000
0.000000
2.000000
0.000000
3.000000
0.000000
1.000000
10.000000
3.000000
0.000000
0.000000,1.175201,11013.232875
3.000000
0.000000
1.000000,1.543081,11013.232920
3.000000
0.000000
0.000000,0.761594,1.000000
3.000000
0.000000,-1.000000,-10.000000
3.000000
0.000000,1.000000,10.000000
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS '#Array math'

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=result
  o "<[v$-:]; <=\n; ret"
-sect BEFORE
  o "? dim($A[],3)    ;    &result"
  o "? $-             ;    &result"
  o "? 2              ;    &result"
  o "? $A[]=$-        ;    &result"
  o "<[dv,:v$A:];<=\n"
  o "? 2              ;    &result"
  o "? $A[$-,3]=-$-*10;    &result"
  o "<[dv,:v$A:];<=\n"
  o "? 10             ;    &result"
  o "? -4-$--6        ;    &result"
  o "? 2              ;    &result"
  o "? e10(-$-)       ;    &result"
  o "eof"
-eoc
EOD

#
#
cat >$TMPDIR/old.txt <<'EOD'
0.000000
0.000000
2.000000
3.000000
2.000000,2.000000,2.000000
2.000000
2.000000
2.000000,-20.000000,-20.000000
10.000000
-20.000000
2.000000
0.010000
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS '#Previous results'

echo
echo "testing -pm '' 'eof', 'exit' and 'fail' operations"
echo
cat >$TMPDIR/old.txt <<'EOD'
1234
1235
1236
1247
header,1,2,3,4,5 FOR UNMERGE TESTING
EOD
TESTARGS="-in $TMPDIR/input1.txt -pm 's:UNMERGE' 'eof'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1234
1235
1236
1247
EOD
TESTARGS="-in $TMPDIR/input1.txt -pm 's:UNMERGE' 'exit'"; dotest; echo $TESTARGS "with EXIT"
TESTARGS="-in $TMPDIR/input1.txt -pm 's:UNMERGE' 'fail'"; dotest; echo $TESTARGS "with FAIL"


echo
echo "testing -pm '' n#, if1,ifc,if+,if- operations"
echo

cat >$TMPDIR/old.txt <<'EOD'
0004 a04 b04 c04
EOD
TESTARGS="-in $TMPDIR/input2.txt -pm 's^:0004' 'if1' -ifonly "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
0004 a04 b04 c04
0005 a05 b05 c05
0006 a06 b06 c06
EOD
TESTARGS="-in $TMPDIR/input2.txt -pm 's^:0004' 'ifc;n2' -ifonly "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
0004 a04 b04 c04
0005 a05 b05 c05
0006 a06 b06 c06
0014 a14 b14 c14
0015 a15 b15 c15
0016 a16 b16 c16
EOD
TESTARGS="-in $TMPDIR/input2.txt -pm 's:4 a' 'if+' -pm 's:6 a' 'if-' -ifonly "; dotest; echo $TESTARGS

echo
echo "testing -pm '' 'sw' with 'im'"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
# T holds 4 values.  Search it with the first token of each input
# line and show which one matches.  (The 3rd value will never match,
# the 2nd one only with alternative delimiter set in 2nd test),
#
-sect BEFORE
  o "hide; +T<=1234; +T<=header; +T<=never; +T<=this"
-sect MAIN
  o "xA;+A<[mt:1,1]"
  mA "tc^$:T" "im"
{     o "sw5"
  c   o "<=0; ^}"
  c   o "<=1; ^}"
  c   o "<=2; ^}"
  c   o "<=3; ^}"
  c   o "<=4; ^}"  
}
-sect AFTER
  o "<=\n"
-eoc
EOD

#
# nr -18 so that if more stuff is added to input1.txt this doesn't break
#
cat >$TMPDIR/old.txt <<'EOD'
100000404400440000
EOD
TESTARGS="-in $TMPDIR/input1.txt -nr 18 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS
cat >$TMPDIR/old.txt <<'EOD'
100020404400440000
EOD
TESTARGS="-in $TMPDIR/input1.txt -nr 18 -mt -dl ' ,' -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm '' 'sw' with 'ip'"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect BEFORE
  o "hide; +A<=abcdefghijklmnopqrstuvwxyz1234567890"
-sect MAIN
  o "xB;+B<[mc:1]"    ## put the first character in B
  mA "vc:B" ""        ## find B in A
{        o "ip; sw37"    ## mark the position and switch
  c0     o "<=*; ^}"
  c1-26  o "<=A; ^}"
  c27-36 o "<=9; ^}"
}
-sect AFTER
  o "<=\n"
-eoc
EOD

#
# nr -18 so that if more stuff is added to input1.txt this doesn't break
#
cat >$TMPDIR/old.txt <<'EOD'
9999AAA*A***A***AA
EOD
TESTARGS="-in $TMPDIR/input1.txt -nr 18 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm '' 'sw' with 'ir'"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
# Classify the first letter of the input as A (a-z), 9 (number), or * (something else)
#
-sect COMMON
=showit; {     ## function "showit"
      o "ir; sw3" 
  c0  o "<=case 0\n; ^}"
  c1  o "<=case 1\n; ^}"
  c2  o "<=case 2\n; ^}"
}     o "ret"  ## end of function
-sect BEFORE
  o "? 0; <=RESULT = 0\n; &showit"
  o "? 1; <=RESULT = 1\n; &showit"
  o "? 2; <=RESULT = 2\n; &showit"
  o "eof"
-eoc
EOD

#
# nr -18 so that if more stuff is added to input1.txt this doesn't break
#
cat >$TMPDIR/old.txt <<'EOD'
RESULT = 0
case 0
RESULT = 1
case 1
RESULT = 2
case 2
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm 's:STR' with ^$r modifiers and xA,show,hide,afmt,nfmt "
echo

cat >$TMPDIR/old.txt <<'EOD'
This line has f o o after this foo and this foo and this foo!
This is TAG1
This is TAG2
EOD
TESTARGS="-in $TMPDIR/input1.txt -pm 's^:This' 'xA;+A;show;!;xA;+A<=empty;hide' -fmt '[vA:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
This line has f o o after this foo and this foo and this foo!
EOD
TESTARGS="-in $TMPDIR/input1.txt -pm 's^:This' '' -pm 'sr$:o!' 'xA;+A;show;!;xA;+A<=empty;hide' -fmt '[vA:1,]'"; dotest; echo $TESTARGS

# This  next one is an empty file, it isn't supposed to match anything 
cat >$TMPDIR/old.txt <<'EOD'
EOD
TESTARGS="-in $TMPDIR/input1.txt -pm 's^:his' 'xA;>A;show;!;xA;+A<=empty;hide' -fmt '[vA:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -pm 's^:This' '' -pm 'sr$:o' 'xA;>A;show;!;xA;+A<=empty;hide' -fmt '[vA:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
MISS: test delimiters in double quotes "blah gah,foo, bar"
HIT: This line has f o o after this foo and this foo and this foo!
MISS:    Line     for testing     trim (note 4 trailing spaces)    
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 6 -nr 3 -pm 's^:This' '' -pm 'sr$:o!' 'afmt0;!;afmt1' -fmt0 'HIT:  [1,]' -fmt1 'MISS: [1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 6 -nr 3 -pm 's^:This' '!;brk' -pm 'sr$:o!' 'afmt1;!;afmt0;nfmt1' -fmt0 'MISS: [1,]' -fmt1 'HIT: [1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
MISS: This line has f o o after this foo and this foo and this foo!
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 7 -nr 1 -pm 'scg:tHis' '' -pm 'src:line' 'afmt0;!;afmt1' -fmt0 'HIT:  [1,]' -fmt1 'MISS: [1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
HIT: This line has f o o after this foo and this foo and this foo!
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 7 -nr 1 -pm 'scg:line' '' -pm 'src:tHis' 'afmt0;!;afmt1' -fmt0 'HIT:  [1,]' -fmt1 'MISS: [1,]'"; dotest; echo $TESTARGS

echo
echo "testing -pm 'v:ABC' with [gfq<>] modifiers"
echo

cat >$TMPDIR/old.txt <<'EOD'
test vfg one^one^one
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -pm 'm:' '+A<=one;+B<=two;+C<=three' -pm 'vfg:ABC' '>Z' -fmt 'test vfg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test v<g one^two^three^one^two^three^one
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -pm 'm:' '+A<=one;+B<=two;+C<=three' -pm 'v<g:ABC' '>Z' -fmt 'test v<g [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test v>g three^three^one
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -pm 'm:' '+A<=one;+B<=two;+C<=three' -pm 'v>g:ABC' '>Z' -fmt 'test v>g [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test vqg MISS
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -pm 'm:' '+A<=one;+B<=two;+C<=three' -pm 'vqg:ABC' '>Z;!;+Z<=MISS' -fmt 'test vqg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test vqg one^two^three^one^two^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -pm 'm:' '+A<=one;+B<=two;+C<=three' -pm 'vqg:ABC' '>Z;!;+Z<=MISS' -fmt 'test vqg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test vq one^two^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -pm 'm:' '+A<=one;+B<=two;+C<=three' -pm 'vq:ABC' '>Z;!;+Z<=MISS' -fmt 'test vq [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test vqr SKIP1^one^two^three^two^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -pm 'm:' '+A<=one;+B<=two;+C<=three' -pm 'vq:ABC' '+Z<=SKIP1;!;+Z<=MISS1' -pm 'vqr:BC' '>Z;!;+Z<=MISS2' -fmt 'test vqr [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

echo
echo "testing -pm 'n#:ABC'  with [gfq<>] modifiers"
echo

cat >$TMPDIR/old.txt <<'EOD'
test n1fg one^one^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -vB 'three two one' -pm 'm:' 'poAB' -pm 'n1fg:AB' '>Z;!;+Z<=MISS' -fmt 'test n1fg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test n3fg three^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -vB 'three two one' -pm 'm:' 'poAB' -pm 'n3fg:AB' '>Z;!;+Z<=MISS' -fmt 'test n3fg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test n3<g one^three^one^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -vB 'three two one' -pm 'm:' 'poAB' -pm 'n3<g:AB' '>Z;!;+Z<=MISS' -fmt 'test n3<g [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test n3>g three^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -vB 'three two one' -pm 'm:' 'poAB' -pm 'n3>g:AB' '>Z;!;+Z<=MISS' -fmt 'test n3>g [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test n3qg MISS
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -vB 'three two one' -pm 'm:' 'poAB' -pm 'n3qg:AB' '>Z;!;+Z<=MISS' -fmt 'test n3qg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test n1qg one^three^one^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -vB 'three two one' -pm 'm:' 'poAB' -pm 'n1qg:AB' '>Z;!;+Z<=MISS' -fmt 'test n1qg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

echo
echo "testing -pm 't:ABC'  with [gfq<>] modifiers"
echo

cat >$TMPDIR/old.txt <<'EOD'
test tf one
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -pm 'm:' 'poA' -pm 'tf:A' '>Z;!;+Z<=MISS' -fmt 'test tf [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test tfg one^one^two^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -pm 'm:' 'poA' -pm 'tfg:A' '>Z;!;+Z<=MISS' -fmt 'test tfg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test t<g one^two^three^one^two^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -pm 'm:' 'poA' -pm 't<g:A' '>Z;!;+Z<=MISS' -fmt 'test t<g [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test t>g three^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -pm 'm:' 'poA' -pm 't>g:A' '>Z;!;+Z<=MISS' -fmt 'test t>g [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test tq one^two^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -pm 'm:' 'poA' -pm 'tq:A' '>Z;!;+Z<=MISS' -fmt 'test tq [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test tqg one^two^three^one^two^three
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -pm 'm:' 'poA' -pm 'tqg:A' '>Z;!;+Z<=MISS' -fmt 'test tqg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -pm 'm:' 'poA' -pm 'tqg:AA' '>Z;!;+Z<=MISS' -fmt 'test tqg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
test tqg MISS
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 18 -nr 1 -vA 'one two three' -pm 'm:' 'poA' -pm 'tqg:AAA' '>Z;!;+Z<=MISS' -fmt 'test tqg [vZ:mt:dv^:1,]' "; dotest; echo $TESTARGS


echo
echo "testing -pm 'm:' "
echo

cat >$TMPDIR/old.txt <<'EOD'
True
EOD
TESTARGS="-in $TMPDIR/input1.txt -nr 1 -pm 'm:' '+B<=True' -fmt '[vB:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -nr 1 -pm 'm:' '+B<=True;!' -fmt '[vB:1,]'"; dotest; echo $TESTARGS

echo
echo "testing -pm '?#:VLIST' "
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
# this must run in main so that - input buffer will be used
-sect main
  o "hide; eof"
  o "+A<=1; +A<=; +A<=23;" ##A has 3 tokens, one empty
                           ##B is CLEAR
  o "+C<=;"                ##defined, but contains only one empty token
  m "?:A-"   "<=True\n; !; <=False\n" ## True  A and input buffer both defined
  m "?1:A-"  "<=True\n; !; <=False\n" ## True  A and input buffer have >=1 chars
  m "?2:A-"  "<=True\n; !; <=False\n" ## True  A and input buffer have >=2 chars
  m "?3:A-"  "<=True\n; !; <=False\n" ## True  A and input buffer have >=3 chars
  m "?4:A-"  "<=True\n; !; <=False\n" ## False A has <4 characters
  m "?:B"    "<=True\n; !; <=False\n" ## False B is not defined
  m "?:AB"   "<=True\n; !; <=False\n" ## False B is not defined
  m "?1:AB"  "<=True\n; !; <=False\n" ## False B is not defined
  m "?:C"    "<=True\n; !; <=False\n" ## True  C is defined
  m "?e:C"   "<=True\n; !; <=False\n" ## True  C is empty
  m "?1:C"   "<=True\n; !; <=False\n" ## False C is not 1 character long
  m "?te:C"  "<=True\n; !; <=False\n" ## True  (All tokens) are empty
  m "?te1:C" "<=True\n; !; <=False\n" ## True  1st token exists and is empty
  m "?te2:C" "<=True\n; !; <=False\n" ## False because C has no 2nd token
  m "?t:A"   "<=True\n; !; <=False\n" ## False because A's 2nd token is empty
   o "? 1"                         
  m "?0:A-"  "<=True\n; !; <=False\n" ## True  A and input buffer have >=1 chars
  o "? 2"                         
  m "?0:A-"  "<=True\n; !; <=False\n" ## True  A and input buffer have >=2 chars
  o "? 3"                         
  m "?0:A-"  "<=True\n; !; <=False\n" ## True  A and input buffer have >=3 chars
  o "? 4"                         
  m "?0:A-"  "<=True\n; !; <=False\n" ## False A has <4 characters
  m "?te:A"  "<=True\n; !; <=False\n" ## False, not All tokens are empty
  m "?e:AC"  "<=True\n; !; <=False\n" ## False, A is not empty
  m "?e:BC"  "<=True\n; !; <=False\n" ## False, B is cleared.
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
True
True
True
True
False
False
False
False
True
True
False
True
True
False
False
True
True
True
False
False
False
False
EOD
TESTARGS="-in $TMPDIR/input1.txt -cmd $TMPDIR/pieces.txt -nr 1"; dotest; echo $TESTARGS

echo
echo "testing -pm '?CMP#:VLIST'"
echo
cat >$TMPDIR/pieces.txt <<'EOD'
#
# Math "pattern" tests
#
-sect BEFORE
  o "eof"
  o "? dim($A[],3)+dim($B[],3)+dim($C[],3);"
  o "? $A=1; ? $B=0; ? $C=-1; ? $D=1/0; ? $E=log(-1)"
  m "??1:A"  "<=T;!;<=F"
  m "?=1:A"  "<=T;!;<=F"
  m "?<1:A"  "<=T;!;<=F"
  m "?>1:A"  "<=T;!;<=F"
  o "<=\n"
  m "??1:B"  "<=T;!;<=F"
  m "?=1:B"  "<=T;!;<=F"
  m "?<1:B"  "<=T;!;<=F"
  m "?>1:B"  "<=T;!;<=F"
  o "<=\n"
  m "??1:C"  "<=T;!;<=F"
  m "?=1:C"  "<=T;!;<=F"
  m "?<1:C"  "<=T;!;<=F"
  m "?>1:C"  "<=T;!;<=F"
  o "<=\n"
  m "??1:D"  "<=T;!;<=F"
  m "?=1:D"  "<=T;!;<=F"
  m "?<1:D"  "<=T;!;<=F"
  m "?>1:D"  "<=T;!;<=F"
  o "<=\n"
  m "??1:E"  "<=T;!;<=F"
  m "?=1:E"  "<=T;!;<=F"
  m "?<1:E"  "<=T;!;<=F"
  m "?>1:E"  "<=T;!;<=F"
  o "<=\n"
  m "??1:AB" "<=T;!;<=F"
  m "?=1:AB" "<=T;!;<=F"
  m "?<1:AB" "<=T;!;<=F"
  m "?>1:AB" "<=T;!;<=F"
  o "<=\n"
  o "? 1" ## repeat preceding, use RESULT to choose element number
  m "??0:A"  "<=T;!;<=F"
  m "?=0:A"  "<=T;!;<=F"
  m "?<0:A"  "<=T;!;<=F"
  m "?>0:A"  "<=T;!;<=F"
  o "<=\n"
  m "??0:B"  "<=T;!;<=F"
  m "?=0:B"  "<=T;!;<=F"
  m "?<0:B"  "<=T;!;<=F"
  m "?>0:B"  "<=T;!;<=F"
  o "<=\n"
  m "??0:C"  "<=T;!;<=F"
  m "?=0:C"  "<=T;!;<=F"
  m "?<0:C"  "<=T;!;<=F"
  m "?>0:C"  "<=T;!;<=F"
  o "<=\n"
  m "??0:D"  "<=T;!;<=F"
  m "?=0:D"  "<=T;!;<=F"
  m "?<0:D"  "<=T;!;<=F"
  m "?>0:D"  "<=T;!;<=F"
  o "<=\n"
  m "??0:E"  "<=T;!;<=F"
  m "?=0:E"  "<=T;!;<=F"
  m "?<0:E"  "<=T;!;<=F"
  m "?>0:E"  "<=T;!;<=F"
  o "<=\n"
  m "??0:AB" "<=T;!;<=F"
  m "?=0:AB" "<=T;!;<=F"
  m "?<0:AB" "<=T;!;<=F"
  m "?>0:AB" "<=T;!;<=F"
  o "<=\n"
  m "??:BB"  "<=T;!;<=F"
  m "?=:BB"  "<=T;!;<=F"
  m "?<:BB"  "<=T;!;<=F"
  m "?>:BB"  "<=T;!;<=F"
  o "<=\n"
  o "? 1"
  m "??:-"  "<=T;!;<=F"
  m "?=:-"  "<=T;!;<=F"
  m "?<:-"  "<=T;!;<=F"
  m "?>:-"  "<=T;!;<=F"
  o "<=\n"
  o "? 0"
  m "??:-"  "<=T;!;<=F"
  m "?=:-"  "<=T;!;<=F"
  m "?<:-"  "<=T;!;<=F"
  m "?>:-"  "<=T;!;<=F"
  o "<=\n"
  o "? -1"
  m "??:-"  "<=T;!;<=F"
  m "?=:-"  "<=T;!;<=F"
  m "?<:-"  "<=T;!;<=F"
  m "?>:-"  "<=T;!;<=F"
  o "<=\n"
  o "? 1/0"
  m "??:-"  "<=T;!;<=F"
  m "?=:-"  "<=T;!;<=F"
  m "?<:-"  "<=T;!;<=F"
  m "?>:-"  "<=T;!;<=F"
  o "<=\n"
  o "? log(-1)"
  m "??:-"  "<=T;!;<=F"
  m "?=:-"  "<=T;!;<=F"
  m "?<:-"  "<=T;!;<=F"
  m "?>:-"  "<=T;!;<=F"
  o "<=\n"
-eoc
EOD

#
# nr -18 so that if more stuff is added to input1.txt this doesn't break
#
cat >$TMPDIR/old.txt <<'EOD'
TFFT
TTFF
TFTF
FFFT
FFFF
TFFF
TFFT
TTFF
TFTF
FFFT
FFFF
TFFF
TTFF
TFFT
TTFF
TFTF
FFFT
FFFF
EOD
TESTARGS=" -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing -op "
echo

cat >$TMPDIR/old.txt <<'EOD'
wombat
koala
EOD
TESTARGS="-in $TMPDIR/input1.txt  -er 1 -op 'hide;<=wombat\n' -op '<=koala\n'" ; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt  -er 1 -op 'hide;+A<=wombat\nkoala\n' -opA '+B;<B'" ; dotest; echo $TESTARGS


echo
echo "testing -ps "
echo

cat >$TMPDIR/old.txt <<'EOD'
T11 TAG1,Th9 is TAG1,T1^is^TAG1,Th9^9^TAG1
T11 TAG2,Th9 is TAG2,T1^is^TAG2,Th9^9^TAG2
EOD
TESTARGS="-in $TMPDIR/input1.txt  -if 'TAG' -ifonly -ps 'gp:.is' 's:1'  -ps1 's:is' 's:9' -fmt '[ps0:1,],[ps1:1,],[mt:ps0:dv^:1,],[mt:ps1:dv^:1,]'"; dotest; echo $TESTARGS
cat >$TMPDIR/old.txt <<'EOD'
8 9 TAG1,8^9^TAG1
8 9 TAG2,8^9^TAG2
EOD
TESTARGS="-in $TMPDIR/input1.txt -sect before -op '+A<=This;+A<=is;+B<=8;+B<=9'  -if 'TAG' -ifonly -ps 'tg:A' 't:B' -fmt '[ps0:1,],[mt:ps0:dv^:1,]'"; dotest; echo $TESTARGS
cat >$TMPDIR/old.txt <<'EOD'
8 9 TAG1
8 9 TAG2
EOD
TESTARGS="-in $TMPDIR/input1.txt -sect before -op '+A<=This;+A<=is;+B<=8;+B<=9'  -if 'TAG' -ifonly -ps 'tg:A' 't:B' "; dotest; echo $TESTARGS
cat >$TMPDIR/old.txt <<'EOD'
8^9^TAG1
8^9^TAG2
EOD
TESTARGS="-in $TMPDIR/input1.txt -mt -dv '^' -sect before -op '+A<=This;+A<=is;+B<=8;+B<=9'  -if 'TAG' -ifonly -ps 'tg:A' 't:B' "; dotest; echo $TESTARGS

echo
echo "testing -ps '' 's:' "
echo

cat >$TMPDIR/old.txt <<'EOD'
mt >Bf345678 b12 w12E< mc >Bf345678 b12 w12E<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -vA 'Bfoo boo wooE' -psA 'pg:oo' 's:12' -psA 'p:12' 's:345678' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
mt >Bf b12 w12E< mc >Bf b12 w12E<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -vA 'Bfoo boo wooE' -psA 'pg:oo' 's:12' -psA 'p:12' 's:' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dotest; echo $TESTARGS

echo
echo "testing -ps '' 'v:' "
echo

cat >$TMPDIR/old.txt <<'EOD'
mt >Bf1 b2345 w1E< mc >Bf1 b2345 w1E<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1 -vA 'Bfoo boo wooE' -vB '1' -vC '2345' -psA 'pg:oo' 'v:BC'  -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -er 1 -vA 'Bfoo boo wooE' -vB '1' -vC '2345' -psA 'pg:oo' 'v:Z'  -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dofail; echo $TESTARGS "#CSE"

echo
echo "testing -ps '' 'n#:' "
echo

cat >$TMPDIR/old.txt <<'EOD'
mt >Bf1 b34 w1E< mc >Bf1 b34 w1E<
EOD
TESTARGS="-in $TMPDIR/input1.txt -er 1  -vA 'Bfoo boo wooE' -vB '1 2' -vC '34 56' -pm 'm:' 'poBC' -psA 'pg:oo' 'n1:BC' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -er 1  -vA 'Bfoo boo wooE' -vB '1 2' -vC '34 56' -pm 'm:' 'poBC' -psA 'pg:oo' 'n-2:BC' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -er 1  -vA 'Bfoo boo wooE' -vB '1 2' -vC '34 56' -pm 'm:' 'poBC' -psA 'pg:oo' 'n3:BC' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dofail; echo $TESTARGS "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -er 1  -vA 'Bfoo boo wooE' -vB '1 2' -vC '34 56' -pm 'm:' 'poBC' -psA 'pg:oo' 'n-3:BC' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dofail; echo $TESTARGS "#CSE"
TESTARGS="-in $TMPDIR/input1.txt -er 1  -vA 'Bfoo boo wooE' -vB '1 2' -vC '34 56' -pm 'm:' 'poBC' -psA 'pg:oo' 'n1:Z' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dofail; echo $TESTARGS "#CSE"

echo
echo "testing -ps '' 'q:' "
echo

cat >$TMPDIR/old.txt <<'EOD'
mt >B123 4ab c12E< mc >B123 4ab c12E<
EOD
TESTARGS="-in $TMPDIR/input1.txt  -er 1 -vA 'Bfoo boo wooE' -vB '1 2 3 4' -vC 'a b c' -pm 'm:' 'poBC' -psA 'pg:[fbwo]' 'q:BC' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt  -er 1 -vA 'Bfoo boo wooE' -vB '1 2 3 4' -vC 'a b c' -pm 'm:' 'poBC' -psA 'pg:[fbwo]' 'q:BCZ' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dofail; echo $TESTARGS "#CSE"

echo
echo "testing -ps '' 't:' "
echo

cat >$TMPDIR/old.txt <<'EOD'
mt >BMa_Nb__Oc___Pd____Qa_Rb__Sc___Td____E< mc >BMa_Nb__Oc___Pd____Qa_Rb__Sc___Td____E<
EOD
TESTARGS="-in $TMPDIR/input1.txt  -er 1 -vA 'BM1---N2--O3-P4Q1---R2--S3-T4E' -vB '1--- 2-- 3- 4' -vC 'a_ b__ c___ d____' -pm 'm:' 'poBC' -psA 't<g:B' 't:C' -fmt 'mt >[mt:dv^:vA:1,]< mc >[mc:vA:1,]<'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1234
1235
1236
1247
header,1,2,3,4,5 FOR UNMERGE TESTING
test delimiters in double quotes "blah gah,foo, bar"
sub1 line has f o o after sub1 foo and sub1 foo and sub1 foo!
   Line     for testing     trim (note 4 trailing spaces)    
sub1 is TAG1
  sub1 is text after t ag1
  more text
  yet more text
sub1 is TAG2
  sub1 is text after t ag2
  more text
  line before end of file
S one two sub2 sub3 one two sub2 woo blah blah one E
S one two sub2 sub3 one two sub2 woo blah blah E
EOD
TESTARGS="-in $TMPDIR/input1.txt  -nr 18 -vA 'this three boo' -vB 'sub1 sub2 sub3' -op 'poAB' -ps 't<cg:A' 't:B' -fmt '[ps:]'"; dotest; echo $TESTARGS

echo
echo "testing scripting flow control logic  with -sect, op,-pm[N],-ps etc."
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
#  this is a little script
#  Note how vA and vB are cleared, else
#  they would just append onto the previous line
#
-fmt0 "[vB:1,]"
-pm   "m:"      "xAB;+A;po0A"
-pmA  "s^:0004" "^Block1"
-pmA  "s^:0008" "^Block2"
-pmA  "s^:0012" "^Block3"
-pmA  "s^:0016" "^Block4"
-pm   "m:"      "+B<=***;brk"
-op             "=Block1;  +B<1A;  brk"
-op             "+B<= you should never see this 1"
-op             "=Block2;  +B<2A;  brk"
-op             "+B<= you should never see this 2"
-op             "=Block3;  +B<3A;  brk"
-op             "+B<= you should never see this 3"
-op             "=Block4;  +B<4A;  brk"
-op             "+B<= you should never see this 4"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
***
***
***
0004
***
***
***
a08
***
***
***
b12
***
***
***
c16
***
***
***
***
EOD
TESTARGS="-in $TMPDIR/input2.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
#  same as preceding but use skip to offset lines instead of ^ (jmp)
#
-fmt0 "[vB:1,]"
-pm   "m:"      "xAB;+A;po0A"
-pmA  "s^:0004" "^5"
-pmA  "s^:0008" "^6"
-pmA  "s^:0012" "^7"
-pmA  "s^:0016" "^8"
-op             "+B<=***;brk"
-op             "+B<1A;  brk"
-op             "+B<= you should never see this 1\n"
-op             "+B<2A;  brk"
-op             "+B<= you should never see this 2\n"
-op             "+B<3A;  brk"
-op             "+B<= you should never see this 3\n"
-op             "+B<4A;  brk"
-op             "+B<= you should never see this 4\n"
-eoc
EOD
TESTARGS="-in $TMPDIR/input2.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
-fmt0 "[vB:1,]"
-op             "xBC;+C;poC;+A<C"
-pm   "?70:A"   "show;+B<A;xA;!;hide"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
0001 a01 b01 c010002 a02 b02 c020003 a03 b03 c030004 a04 b04 c040005 a05 b05 c05
0006 a06 b06 c060007 a07 b07 c070008 a08 b08 c080009 a09 b09 c090010 a10 b10 c10
0011 a11 b11 c110012 a12 b12 c120013 a13 b13 c130014 a14 b14 c140015 a15 b15 c15
0016 a16 b16 c160017 a17 b17 c170018 a18 b18 c180019 a19 b19 c190020 a20 b20 c20
EOD
TESTARGS="-in $TMPDIR/input2.txt -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
#
-sect Before
-vA   "<one>A<two>B<three>C</three></two></one><four>D<five>E</five><six>F</six></four>"
-vC   ""
-vE   "[mc:vF:1,-2]"
-vI   "tags:[mt:dv^:vB:1,] loads:[mt:dv^:vG:1,]\n"
  o             "hide;eof;xBCDGZ"
  o             "&sub1"
=sub1
#
#  The PCRE pattern finds <(tag)>(load)</tag>(remainder)
#
  mA "p/2/3/5:<([^\>]+)>(.*)(</\1>(.*))" 
                "xC;>BCD;%b;xF;>F;vE;!;+G<C;ret"
  m  "?1:E"     "+G<E"
  m  "?te-1:D"  "x-1D" ## strip off empty token (possibly) added to D
  m  "?1:C"     "xA;+A<C;&sub1"
  o             "vI;<I;xBG"
  m  "?t-1:D"   "xA;+A<-1D;x-1D;&sub1"
  o             "brk"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
tags:one^two^three loads:A^B^C
tags:four^five loads:D^E
tags:six loads:F
EOD
TESTARGS="-in $TMPDIR/input2.txt -er 1 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
# simple loop
# A active buffer
# B depth marker, three spaces for each <>
# C tag contents
# D / or empty
# E tag contents from LAST cycle
# T tag name
# R remainder
# emits indented tags like:
#   <tag1>load1
#   </tag1>
#
-vA "<one>A<two>B<three>C</three></two></one><four>D<five>E</five><six>F</six></four>"
-pm   "m:"       "+B<=;hide"
-pm   "?1:C"      "=Sub1"
#     find the tag or end tag
-pmA  "p/2/3/4:<(/){0,1}([^\>]+)>(.*)"   "xDTR;>DTR"
#     find load (from the preceding tag, not for the current tag)
-pmA  "p/1:<(/){0,1}([^\>]+)>(.*)"       "%b;xC;>C"
-pm   "?1:C"      "<C;<=\n"
-pm   "?1:D"      "x-1B"
-pm   "m:"       "<B;<=<;<DT;<=>"
-pm   "?1:D"      "<=\n;!;+B<=   "
-pm   "?1:R"      "xA;+A<R;!;brk"
-pm   "m:"       "^Sub1"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
<one>A
   <two>B
      <three>C
      </three>
   </two>
</one>
<four>D
   <five>E
   </five>
   <six>F
   </six>
</four>
EOD

TESTARGS="-in $TMPDIR/input2.txt  -er 1 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS
cat >$TMPDIR/pieces.txt <<'EOD'
#
# simple loop
# A active buffer
# B depth marker, three spaces for each <>
# C tag contents
# D / or empty
# E tag contents from LAST cycle
# T tag name
# R remainder
# emits indented tags like:
#   <tag1>load1
#   </tag1>
#
-sect BEFORE
-op   "+A<=<one>A<two>B<three>C</three></two></one><four>D<five>E</five><six>F</six></four>"
-sect MAIN
-pm   "m:"       "+B<=;hide"
-pm   "?1:C"      "=Sub1"
#     find the tag or end tag
-pmA  "p/2/3/4:<(/){0,1}([^\>]+)>(.*)"   "xDTR;>DTR"
#     find load (from the preceding tag, not for the current tag)
-pmA  "p/1:<(/){0,1}([^\>]+)>(.*)"       "%b;xC;>C"
-pm   "?1:C"      "<C;<=\n"
-pm   "?1:D"      "x-1B"
-pm   "m:"       "<B;<=<;<DT;<=>"
-pm   "?1:D"      "<=\n;!;+B<=   "
-pm   "?1:R"      "xA;+A<R;!;brk"
-pm   "m:"       "^Sub1"
-sect AFTER
-op              "<=Processing completed\n"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
<one>A
   <two>B
      <three>C
      </three>
   </two>
</one>
<four>D
   <five>E
   </five>
   <six>F
   </six>
</four>
Processing completed
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
# simple loop
# A active buffer
# C tag contents
# D / or empty
# T tag name
# R remainder
# Z tag accumulator
# Y load accumulator
# emits accumulated tags like:
#   {tag1}{load1}
#   {tag1,tag2}{load1,load2}
#   {tag1,tag3}{load1,load3}
#
-vX   "{[mt:vZ:dv,:2,-1]}{[mt:vY:dv,:2,-1]}\n"
-sect BEFORE
#load for five intentionally omitted
-op   "+A<=<one>A<two>B<three>C</three></two>A2</one><four>D<five></five><six>E</six>D2</four>"
#make the tag accumulator zero length strings to start with, saves some tests
-op   "+Z<=;+Y<="
-sect MAIN
-pm   "m:"       "+B<=;hide"
-pm   "?1:C"      "=Sub1"
#     find the tag or end tag
-pmA  "p/2/3/4/5:<(/){0,1}([^\>]+)>([^\<]*)(.*)"   "xDTCR;>DTCR;!;brk"
-pm   "?1:D"      "^2"
-pm   "?1:C"      "+Y<C;!;+Y<=*"
-pm   "?1:T"      "!;<=Fatal parsing error, no terminal <> tag\n;fail"
-pm   "?1:D"      "x-1Z;x-1Y;!;+Z<T;vX;<X"
-op              "xA;+A<R;^Sub1"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
{one}{A}
{one,two}{A,B}
{one,two,three}{A,B,C}
{four}{D}
{four,five}{D,*}
{four,six}{D,E}
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
# simple loop
# A active buffer
# C tag contents
# D / or empty
# T tag name
# R remainder
# Z tag accumulator
# Y load accumulator
# emits accumulated tags like:
#   {tag1}{load1}
#   {tag1,tag2}{load1,load2}
#   {tag1,tag3}{load1,load3}
# when a load is split into many pieces, they show up as load|load|load.
# Only lines that are meaningful are emitted.
#
-vX   "{[mt:vZ:dv,:2,-1]}{[mt:vY:dv,:2,-1]}\n"
-sect BEFORE
#load for five intentionally omitted
-op   "+A<=<one>A1<two>B<three>C</three></two>A2<ten>X</ten>A3</one><four>D1<five></five><six>E</six>D2</four>"
#make the tag accumulator zero length strings to start with, saves some tests
-op   "+Z<=;+Y<="
-sect MAIN
-pm   "m:"       "+B<=;hide"
-pm   "?1:C"      "=Sub1"
#     find the tag or end tag
-pmA  "p/2/3/4/5:<(/){0,1}([^\>]+)>([^\<]*)(.*)"
                            "xDTCR;>DTCR;!;brk"
-pm   "?1:T"                 "!;<=Fatal parsing error, no terminal <> tag\n;fail"
-pm   "?1:D"                 "^DTrue"
-pm   "?1:C"                 "+Y<C;!;+Y<=*"
-op                         "+Z<T;^Zexists"
-op              "=DTrue;    x-1ZY"
-pm   "?1:C"                 "+Y<=|;+Y<C;m-3Y;!;^Bottom"
-pm   "?1:Z"      "=Zexists;  vX;<X"
-op              "=Bottom;   xA;+A<R;^Sub1"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
{one}{A1}
{one,two}{A1,B}
{one,two,three}{A1,B,C}
{one}{A1|A2}
{one,ten}{A1|A2,X}
{one}{A1|A2|A3}
{four}{D1}
{four,five}{D1,*}
{four,six}{D1,E}
{four}{D1|D2}
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing output directing with <#"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
-er 1
-sect BEFORE
-op     "hide;  +A<=a value;  +B<=b value"
-sect MAIN
-op      "<A;   <= 1\n"
-op      "<2B; <2= 1\n"
-op      "<1A; <1= 2\n"
-op      "<2B; <2= 2\n"
-op      "<A;   <= 3\n"
-op      "<2B; <2= 3\n"
-op      "<1A; <1= 4\n"
-op      "<2B; <2= 4\n"
-op      "? 1; <0A; <0= 1\n"
-op      "? 2; <0B; <0= 1\n"
-op      "? 1; <0A; <0= 2\n"
-op      "? 2; <0B; <0= 2\n"
-op      "? 1; <0A; <0= 3\n"
-op      "? 2; <0B; <0= 3\n"
-op      "? 1; <0A; <0= 4\n"
-op      "? 2; <0B; <0= 4\n"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
a value 1
a value 2
a value 3
a value 4
a value 1
a value 2
a value 3
a value 4
EOD
TESTARGS="-in $TMPDIR/input2.txt -out $TMPDIR/new.txt,/dev/null -cmd $TMPDIR/pieces.txt";
eval $NEWPROG  $TESTARGS
docomp $TMPDIR/new.txt $TMPDIR/old.txt
echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
b value 1
b value 2
b value 3
b value 4
b value 1
b value 2
b value 3
b value 4
EOD
TESTARGS="-in $TMPDIR/input2.txt -out /dev/null,$TMPDIR/new.txt -cmd $TMPDIR/pieces.txt";
eval $NEWPROG  $TESTARGS
docomp $TMPDIR/new.txt $TMPDIR/old.txt
echo $TESTARGS

echo
echo "testing scripting flow control logic with autolabels {, }{, }"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
#nested if/else if structure.  True on B breaks out to very bottom intentionally
#
-sect BEFORE
-op                         "hide"
-sect MAIN
-pmA  "s:1"               "{; <=1 T,;      !; <=1 F,;^}{"
-pmA  "s:A"                   "{;  <=A T,;^};  !; <=A F,;^}{"
-pmA  "s:B"                   "}{; <=B T,;^}}; !; <=B F,;^}{"
-pmA  "s:C"                   "}{; <=C T,;^};  !; <=C F,;^}"
-op                           "};<=inner,;^}"
-pmA  "s:2"               "}{;<=2 T,;^};   !; <=2 F,;^}{"
-pmA  "s:3"               "}{;<=3 T,;^};   !; <=3 F,;^}"
-op                       "};<=outer\n"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
1 T,A F,B F,C F,inner,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 1 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS
cat >$TMPDIR/old.txt <<'EOD'
1 T,A T,inner,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 1A -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 T,A F,B T,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 1B -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 T,A F,B F,C T,inner,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 1C -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 F,2 T,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 23 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 F,2 F,3 T,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 3 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
#nested loops. 
#
-sect BEFORE
-op              "hide;poA"
-sect MAIN
-op              "{"
-pm      "?:A"     "<=vA ;<A;<=\n;             !; ^}"              
-op                "xB;+B<A;x-1A"
-op                "{"
-pm      "?:B"     "<= vB ;<B;<=\n;x-1B;  ^{; !; ^}"              
-op                "}"
-op                                        "^{"
-op              "}"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
vA 1 2 3 4
 vB 1 2 3 4
 vB 1 2 3
 vB 1 2
 vB 1
vA 1 2 3
 vB 1 2 3
 vB 1 2
 vB 1
vA 1 2
 vB 1 2
 vB 1
vA 1
 vB 1
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA '1 2 3 4' -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
#nested loops with test integrated with the top.  The close brace must be
#on a separate line because if it precedes the ^{ then that refers to the outer
#loop, and it cannot follow ^{, because that is an unconditional jump. 
#
-sect BEFORE
-op              "hide;poA"
-sect MAIN
-pm      "?:A"   "{; <=vA ;<A;<=\n;            !; ^}"              
-op                "xB;+B<A;x-1A"
-pm      "?:B"     "{;<= vB ;<B;<=\n;x-1B;  ^{; !; ^}"              
-op                "}"
-op                "                       ^{"
-op              "}"
-eoc
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA '1 2 3 4' -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing flow control logic with sw,c[#],i[#]"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
# switch structures.
#
-sect BEFORE
-op         "hide"
-sect MAIN
-pmA  "s:1" "i1;!;i0"
-pmA  "s:2" "i1;!;i0"
-op         "{;                  sw4"
-op         "c;      <=none;      ^}"
-op         "c;c;    <=1 or 2;    ^}"
-op         "c;      <=12"
-pmA  "s:A"   "i1;!;i0"
-pmA  "s:B"   "i1;!;i0"
-op           "&func;             ^}"
-op         "};"
-op         "        <=\n;exit"
-op         "{;=Func;            sw4"
-op         "c0;c1;  <=B?;        ^}"
-op         "c2;     <=A;         ^}"
-op         "c3;     <=AB;        ^}"
-op         "};                  ret"
-eoc
EOD

echo 12AB >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12B? >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12B -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12B? >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12A >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12A -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 1 or 2 >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 1AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 1 or 2 >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 2AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo none >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"

cat >$TMPDIR/pieces.txt <<'EOD'
#
#nested switch structures.
#
-sect BEFORE
-op         "hide"
-sect MAIN
-pmA  "s:1" "i1;!;i0"
-pmA  "s:2" "i1;!;i0"
-op         "{;                  sw4"
-op         "c;      <=none;      ^}"
-op         "c;c;    <=1 or 2;    ^}"
-op         "c;      <=12"
-pmA  "s:A"   "i1;!;i0"        
-pmA  "s:B"   "i1;!;i0"        
-op            "{;                  sw4"
-op            "c0;c1;    <=B?;      ^}"
-op            "c2;       <=A;       ^}"
-op            "c3;       <=AB;      ^}"
-op            "};"
-op                              "^}"
-op         "};"
-op         "        <=\n;exit"
-eoc
EOD

echo 12AB >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12B? >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12B -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12B? >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12A >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12A -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 1 or 2 >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 1AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 1 or 2 >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 2AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo none >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"

echo
echo "testing flow control logic with sw,c[#],i[#] and abbrev"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
# switch structures using abbreviations, and non abbreviated, mixed
#
-sect BEFORE
o         "hide"
-sect MAIN
-pmA  "s:1" "i1;!;i0"
mA    "s:2" "i1;!;i0"
{
       o "sw4"
  c    o "<=none;      ^}"
  c;c  o "<=1 or 2;    ^}"
  c    o "<=12"
    mA  "s:A"   "i1;!;i0"
   -pmA  "s:B"   "i1;!;i0"
  {        -op  "sw4"
    c0;c1  -op  "<=B?; ^}"
    c2     -op  "<=A;  ^}"
    c3     -op  "<=AB; ^}"
  }
};
o         "<=\n;exit"
-eoc
EOD
echo 12AB >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12B? >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12B -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12B? >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 12A >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 12A -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 1 or 2 >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 1AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo 1 or 2 >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA 2AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"
echo none >$TMPDIR/old.txt
TESTARGS="-in $TMPDIR/input1.txt -vA AB -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS "with EXIT"

echo
echo "testing scripting flow control logic with autolabels {, }{, } and abbrev"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
#nested if/else if structure.  True on B breaks out to very bottom intentionally
#
-sect BEFORE
  o "hide"
-sect MAIN
{    mA    "s:1"    "<=1 T,;      !; <=1 F,;   ^}{"
  {  -pmA  "s:A"    "<=A T,;^};   !; <=A F,;   ^}{"
  }{ mA    "s:B"    "<=B T,;^}};  !; <=B F,;   ^}{"
  }{ mA    "s:C"    "<=C T,;^};   !; <=C F,;   ^}"
  }  o              "<=inner,;^}"
}{   mA    "s:2"    "<=2 T,;^};   !; <=2 F,;   ^}{"
}{ -pmA    "s:3"    "<=3 T,;^};   !; <=3 F,;   ^}"
}   -op    "<=outer\n"
-eoc
EOD

cat >$TMPDIR/old.txt <<'EOD'
1 T,A F,B F,C F,inner,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 1 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 T,A T,inner,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 1A -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 T,A F,B T,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 1B -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 T,A F,B F,C T,inner,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 1C -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 F,2 T,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 23 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
1 F,2 F,3 T,outer
EOD
TESTARGS="-in $TMPDIR/input2.txt  -er 1 -vA 3 -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing -esc -desc"
echo
cat >$TMPDIR/old.txt <<'EOD'
f\o\o\bar\^two\\three\65\256\
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -mt -fmt '[dv^:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
f\o\o\bar\ two\\three\65\256\
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -mt -esc -fmt '[dv^:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
foobar\^two\threeA256\
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -mt -desc -fmt '[dv^:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
foobar two\threeA256\
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -mt -esc -desc -fmt '[dv^:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
foobar two\threeA256\
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -desc -fmt '[1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -fmt '[de:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -desc -fmt '[de+:1,]'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
f\o\o\bar\ two\\three\65\256\
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -desc -fmt '[de-:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -fmt '[de+:1,]'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 19 -nr 1 -fmt '[dep:1,]'"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '<[FLD]' and '+N<[FLD]' "
echo

cat >$TMPDIR/old.txt <<'EOD'
TWO^THREE^BOO^ONE^TWO^THREE^WOO^BLAH^BLAH^ONE^E^^^
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide; <[cu:dv^:3,16];<=\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide;+A; <[vA:cu:dv^:3,16];<=\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide;+B<[cu:dv^:3,16];<B;<=\n'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
TWO^ONE^WOO^ONE^
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide; <[cu:dv^:3,16,3];<=\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide;+A; <[vA:cu:dv^:3,16,3];<=\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide;+B<[cu:dv^:3,16,3];<B;<=\n'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
TWO^ONE^WOO^ONE^
EOD
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide;<[cu:dv^:3,16,3];<=\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide;+A; <[vA:cu:dv^:3,16,3];<=\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt -sr 17 -nr 1 -mt  -op 'hide;+B<[cu:dv^:3,16,3];<B;<=\n'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
    E     ^   blah   ^   two    ^  three   ^    S     |
EOD
TESTARGS="-in $TMPDIR/input1.txt  -sr 17 -nr 1 -mt -op 'hide; <[fw10:jc:dv^:1,-1,-3];<=|\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt  -sr 17 -nr 1 -mt -op 'hide;+A; <[vA:fw10:jc:dv^:1,-1,-3];<=|\n'"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/input1.txt  -sr 17 -nr 1 -mt -op 'hide;+B<[fw10:jc:dv^:1,-1,-3];<B;<=|\n'"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '<[FLD]' with numeric variables, numeric variable indexing"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
-sect BEFORE
  o "? dim($A[],6)+dim($B[],6)+dim($C[],3);"
  o "? $A[1]=1; ? $A[2]=3; ? $A[3]=1"
  o "? $A[4]=2; ? $A[5]=4; ? $A[6]=-1" ## {1,3,1,2,4,-1}
  o "? idx($B[]); ? $B[]*-1"
  o "? idx($C[])"
  o "<[dv,:fp0:v$A:];          <=\n"
  o "<[dv,:fp0:v$B:];          <=\n"
  o "<[dv,:fp0:v$C:];          <=\n"
  o "<[dv,:fp0:v$ABC:];        <=\n"
  o "<[dv,:fp0:=$ABC:];        <=\n"
  o "<[dv,:fp0:@$ABC:];        <=\n"
  o "<[dv,:fp0:v$ABC:,,-1];    <=\n"
  o "<[dv,:fp0:=$ABC:,,-1];    <=\n"
  o "<[dv,:fp0:@$ABC:,,-1];    <=\n"
  o "<[dv,:fp0:v$B:$A];        <=\n" ## determine indices indirectly from $A contents
  o "<[dv,:fp0:v$B:$A,1];      <=\n"
  o "<[dv,:fp0:v$B:$A,4];      <=\n"
  o "<[dv,:fp0:sortan:v$A:];   <=\n"
  o "<[dv,:fp0:sortdn:v$A:];   <=\n"
  o "<[dv,:fp0:sortan:v$ABC:];   <=\n"
  o "eof"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
1,3,1,2,4,-1
-1,-2,-3,-4,-5,-6
1,2,3
1,3,1,2,4,-1,-1,-2,-3,-4,-5,-6,1,2,3
1,-1,1,3,-2,2,1,-3,3,2,-4,NA,4,-5,NA,-1,-6,NA
1,-1,1,3,-2,2,1,-3,3,2,-4,1,4,-5,1,-1,-6,1
-1,4,2,1,3,1,-6,-5,-4,-3,-2,-1,3,2,1
-1,-6,NA,4,-5,NA,2,-4,NA,1,-3,3,3,-2,2,1,-1,1
-1,-6,3,4,-5,3,2,-4,3,1,-3,3,3,-2,2,1,-1,1
-1,-2,-3
-1,-2,-3
-4,-3,-2
-1,1,1,2,3,4
4,3,2,1,1,-1
-1,1,1,2,3,4,-6,-5,-4,-3,-2,-1,1,2,3
EOD
TESTARGS=" -rs NA -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '>#' and -pm 'i#:' "
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
-sect BEFORE
       o        "<=NOTE, if input1.txt is made longer the 19 in this test will change!!!\n"
       o        ">1;  <-; <=\n"
       o        ">2; >2; >2; <-; <=\n"
       m "i: "  "<=T\n; !; <=F\n" ## default, is 1
       o        "? 1"             ## set RESULT to 1
       m "i0:"  "<=T\n; !; <=F\n" ## 0->RESULT->1
       o        "? 4"             ## set RESULT to 4
       m "i0:"  "<=T\n; !; <=F\n" ## 0->RESULT->4
       m "i1:"  "<=T\n; !; <=F\n"
       m "i2:"  "<=T\n; !; <=F\n"
       m "i3:"  "<=T\n; !; <=F\n"
       m "i4:"  "<=T\n; !; <=F\n"
       o        "? $A=1;"

{      o        ">1"
       m "i:"   "? $A=$A+1; ^{; !; <=Lines from stream 1: ; <[v$A:fp0:]; <=\n; ? $A=3; ^}"
       o        ""
};
{      o        ">2"
       m "i2:"  "? $A=$A+1; ^{; !; <=Lines from stream 2: ; <[v$A:fp0:]; <=\n; ^}"
};
       o "eof"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
NOTE, if input1.txt is made longer the 19 in this test will change!!!
1234
1236
T
T
F
T
T
T
F
Lines from stream 1: 19
Lines from stream 2: 19
EOD
TESTARGS=" -in $TMPDIR/input1.txt,$TMPDIR/input1.txt,- -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS


echo
echo "testing -pm '' '+A<[map$Z:]'"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
-mt
-sect COMMON
=testem  ## function to run all tests
  o "<[map$Z:vE:dv,:];   <=\n"  ## tokens from E, v mode
  o "<[map$Z:vEF:dv,:];  <=\n"  ## tokens from EF
  o "<[map$Z:vEFG:dv,:]; <=\n"  ## tokens from EFG
  o "<[map$Z:=E:dv,:];   <=\n"  ## tokens from E, = mode
  o "<[map$Z:=EF:dv,:];  <=\n"  ## tokens from EF
  o "<[map$Z:=EFG:dv,:]; <=\n"  ## tokens from EFG
  o "<[map$Z:@E:dv,:];   <=\n"  ## tokens from E, @ mode
  o "<[map$Z:@EF:dv,:];  <=\n"  ## tokens from EF
  o "<[map$Z:@EFG:dv,:]; <=\n"  ## tokens from EFG
  o "<=\n; ret"
-sect BEFORE
  o "+E<=ab;   +E<=cdef;  +E<=abc;   +E<=bcd;   +E<=CDEE;  +E<=def"
  o "+F<=1A;   +F<=2A;    +F<=3A;    +F<=4A;    +F<=5A;    +F<=6A"
  o "+G<=1B;   +G<=2B;    +G<=3B;    +G<=4B;    +G<=5B;    +G<=6B"
  o "? dim($Z[],tok(e[]));"
  o "? tix($Z[],E[]); &testem"                     ## A case sensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "? tcx($Z[],E[]); &testem"                     ## A case INsensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "x-1F; x-2G"                                   ## Make two of the string variables shorter, repeat.
  o "? tix($Z[],E[]); &testem"                     ## A case sensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "? tcx($Z[],E[]); &testem"                     ## A case INsensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "? idx($Z[]); ? tix($Z[1,4],E[3,-1]); &testem" ## A case sensitive map of PART of E sorted, onto part of Z
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "eof"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
CDEE,ab,abc,bcd,cdef,def
CDEE,ab,abc,bcd,cdef,def,5A,1A,3A,4A,2A,6A
CDEE,ab,abc,bcd,cdef,def,5A,1A,3A,4A,2A,6A,5B,1B,3B,4B,2B,6B
CDEE,ab,abc,bcd,cdef,def
CDEE,5A,ab,1A,abc,3A,bcd,4A,cdef,2A,def,6A
CDEE,5A,5B,ab,1A,1B,abc,3A,3B,bcd,4A,4B,cdef,2A,2B,def,6A,6B
CDEE,ab,abc,bcd,cdef,def
CDEE,5A,ab,1A,abc,3A,bcd,4A,cdef,2A,def,6A
CDEE,5A,5B,ab,1A,1B,abc,3A,3B,bcd,4A,4B,cdef,2A,2B,def,6A,6B

CDEE,ab,abc,bcd,cdef,def
CDEE,ab,abc,bcd,cdef,def,5A,1A,3A,4A,2A,6A
CDEE,ab,abc,bcd,cdef,def,5A,1A,3A,4A,2A,6A,5B,1B,3B,4B,2B,6B
CDEE,ab,abc,bcd,cdef,def
CDEE,5A,ab,1A,abc,3A,bcd,4A,cdef,2A,def,6A
CDEE,5A,5B,ab,1A,1B,abc,3A,3B,bcd,4A,4B,cdef,2A,2B,def,6A,6B
CDEE,ab,abc,bcd,cdef,def
CDEE,5A,ab,1A,abc,3A,bcd,4A,cdef,2A,def,6A
CDEE,5A,5B,ab,1A,1B,abc,3A,3B,bcd,4A,4B,cdef,2A,2B,def,6A,6B

ab,abc,bcd,CDEE,cdef,def
ab,abc,bcd,CDEE,cdef,def,1A,3A,4A,5A,2A,6A
ab,abc,bcd,CDEE,cdef,def,1A,3A,4A,5A,2A,6A,1B,3B,4B,5B,2B,6B
ab,abc,bcd,CDEE,cdef,def
ab,1A,abc,3A,bcd,4A,CDEE,5A,cdef,2A,def,6A
ab,1A,1B,abc,3A,3B,bcd,4A,4B,CDEE,5A,5B,cdef,2A,2B,def,6A,6B
ab,abc,bcd,CDEE,cdef,def
ab,1A,abc,3A,bcd,4A,CDEE,5A,cdef,2A,def,6A
ab,1A,1B,abc,3A,3B,bcd,4A,4B,CDEE,5A,5B,cdef,2A,2B,def,6A,6B

ab,abc,bcd,CDEE,cdef,def
ab,abc,bcd,CDEE,cdef,def,1A,3A,4A,5A,2A,6A
ab,abc,bcd,CDEE,cdef,def,1A,3A,4A,5A,2A,6A,1B,3B,4B,5B,2B,6B
ab,abc,bcd,CDEE,cdef,def
ab,1A,abc,3A,bcd,4A,CDEE,5A,cdef,2A,def,6A
ab,1A,1B,abc,3A,3B,bcd,4A,4B,CDEE,5A,5B,cdef,2A,2B,def,6A,6B
ab,abc,bcd,CDEE,cdef,def
ab,1A,abc,3A,bcd,4A,CDEE,5A,cdef,2A,def,6A
ab,1A,1B,abc,3A,3B,bcd,4A,4B,CDEE,5A,5B,cdef,2A,2B,def,6A,6B

CDEE,ab,abc,bcd,cdef,def
CDEE,ab,abc,bcd,cdef,def,5A,1A,3A,4A,2A,
CDEE,ab,abc,bcd,cdef,def,5A,1A,3A,4A,2A,,,1B,3B,4B,2B,
CDEE,ab,abc,bcd,cdef,def
CDEE,5A,ab,1A,abc,3A,bcd,4A,cdef,2A,def,
CDEE,5A,,ab,1A,1B,abc,3A,3B,bcd,4A,4B,cdef,2A,2B,def,,
CDEE,ab,abc,bcd,cdef,def
CDEE,5A,ab,1A,abc,3A,bcd,4A,cdef,2A,def,1A
CDEE,5A,1B,ab,1A,1B,abc,3A,3B,bcd,4A,4B,cdef,2A,2B,def,1A,1B

CDEE,ab,abc,bcd,cdef,def
CDEE,ab,abc,bcd,cdef,def,5A,1A,3A,4A,2A,
CDEE,ab,abc,bcd,cdef,def,5A,1A,3A,4A,2A,,,1B,3B,4B,2B,
CDEE,ab,abc,bcd,cdef,def
CDEE,5A,ab,1A,abc,3A,bcd,4A,cdef,2A,def,
CDEE,5A,,ab,1A,1B,abc,3A,3B,bcd,4A,4B,cdef,2A,2B,def,,
CDEE,ab,abc,bcd,cdef,def
CDEE,5A,ab,1A,abc,3A,bcd,4A,cdef,2A,def,1A
CDEE,5A,1B,ab,1A,1B,abc,3A,3B,bcd,4A,4B,cdef,2A,2B,def,1A,1B

ab,abc,bcd,CDEE,cdef,def
ab,abc,bcd,CDEE,cdef,def,1A,3A,4A,5A,2A,
ab,abc,bcd,CDEE,cdef,def,1A,3A,4A,5A,2A,,1B,3B,4B,,2B,
ab,abc,bcd,CDEE,cdef,def
ab,1A,abc,3A,bcd,4A,CDEE,5A,cdef,2A,def,
ab,1A,1B,abc,3A,3B,bcd,4A,4B,CDEE,5A,,cdef,2A,2B,def,,
ab,abc,bcd,CDEE,cdef,def
ab,1A,abc,3A,bcd,4A,CDEE,5A,cdef,2A,def,1A
ab,1A,1B,abc,3A,3B,bcd,4A,4B,CDEE,5A,1B,cdef,2A,2B,def,1A,1B

ab,abc,bcd,CDEE,cdef,def
ab,abc,bcd,CDEE,cdef,def,1A,3A,4A,5A,2A,
ab,abc,bcd,CDEE,cdef,def,1A,3A,4A,5A,2A,,1B,3B,4B,,2B,
ab,abc,bcd,CDEE,cdef,def
ab,1A,abc,3A,bcd,4A,CDEE,5A,cdef,2A,def,
ab,1A,1B,abc,3A,3B,bcd,4A,4B,CDEE,5A,,cdef,2A,2B,def,,
ab,abc,bcd,CDEE,cdef,def
ab,1A,abc,3A,bcd,4A,CDEE,5A,cdef,2A,def,1A
ab,1A,1B,abc,3A,3B,bcd,4A,4B,CDEE,5A,1B,cdef,2A,2B,def,1A,1B

CDEE,abc,bcd,def,CDEE,def
CDEE,abc,bcd,def,CDEE,def,5A,3A,4A,,5A,
CDEE,abc,bcd,def,CDEE,def,5A,3A,4A,,5A,,,3B,4B,,,
CDEE,abc,bcd,def,CDEE,def
CDEE,5A,abc,3A,bcd,4A,def,,CDEE,5A,def,
CDEE,5A,,abc,3A,3B,bcd,4A,4B,def,,,CDEE,5A,,def,,
CDEE,abc,bcd,def,CDEE,def
CDEE,5A,abc,3A,bcd,4A,def,1A,CDEE,5A,def,1A
CDEE,5A,1B,abc,3A,3B,bcd,4A,4B,def,1A,1B,CDEE,5A,1B,def,1A,1B

CDEE,abc,bcd,def,CDEE,def
CDEE,abc,bcd,def,CDEE,def,5A,3A,4A,,5A,
CDEE,abc,bcd,def,CDEE,def,5A,3A,4A,,5A,,,3B,4B,,,
CDEE,abc,bcd,def,CDEE,def
CDEE,5A,abc,3A,bcd,4A,def,,CDEE,5A,def,
CDEE,5A,,abc,3A,3B,bcd,4A,4B,def,,,CDEE,5A,,def,,
CDEE,abc,bcd,def,CDEE,def
CDEE,5A,abc,3A,bcd,4A,def,1A,CDEE,5A,def,1A
CDEE,5A,1B,abc,3A,3B,bcd,4A,4B,def,1A,1B,CDEE,5A,1B,def,1A,1B

EOD
TESTARGS=" -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '+A<[ump$Z:]'  and =MAIN label"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
-mt
-sect BEFORE
=testem  ## function to run all tests
  o "<[ump$Z:vE:dv,:];   <=\n"  ## tokens from E, v mode
  o "<[ump$Z:vEF:dv,:];  <=\n"  ## tokens from EF
  o "<[ump$Z:vEFG:dv,:]; <=\n"  ## tokens from EFG
  o "<[ump$Z:=E:dv,:];   <=\n"  ## tokens from E, = mode
  o "<[ump$Z:=EF:dv,:];  <=\n"  ## tokens from EF
  o "<[ump$Z:=EFG:dv,:]; <=\n"  ## tokens from EFG
  o "<[ump$Z:@E:dv,:];   <=\n"  ## tokens from E, @ mode
  o "<[ump$Z:@EF:dv,:];  <=\n"  ## tokens from EF
  o "<[ump$Z:@EFG:dv,:]; <=\n"  ## tokens from EFG
  o "<=\n; ret"
=main
  o "+E<=ab;   +E<=cdef;  +E<=abc;   +E<=bcd;   +E<=CDEE;  +E<=def"
  o "+F<=1A;   +F<=2A;    +F<=3A;    +F<=4A;    +F<=5A;    +F<=6A"
  o "+G<=1B;   +G<=2B;    +G<=3B;    +G<=4B;    +G<=5B;    +G<=6B"
  o "? dim($Z[],tok(e[]));"
  o "? tix($Z[],E[]); &testem"                     ## A case sensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "? tcx($Z[],E[]); &testem"                     ## A case INsensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "x-1F; x-2G"                                   ## Make two of the string variables shorter, repeat.
  o "? tix($Z[],E[]); &testem"                     ## A case sensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "? tcx($Z[],E[]); &testem"                     ## A case INsensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "eof; brk"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
cdef,CDEE,abc,bcd,ab,def
cdef,CDEE,abc,bcd,ab,def,2A,5A,3A,4A,1A,6A
cdef,CDEE,abc,bcd,ab,def,2A,5A,3A,4A,1A,6A,2B,5B,3B,4B,1B,6B
cdef,CDEE,abc,bcd,ab,def
cdef,2A,CDEE,5A,abc,3A,bcd,4A,ab,1A,def,6A
cdef,2A,2B,CDEE,5A,5B,abc,3A,3B,bcd,4A,4B,ab,1A,1B,def,6A,6B
cdef,CDEE,abc,bcd,ab,def
cdef,2A,CDEE,5A,abc,3A,bcd,4A,ab,1A,def,6A
cdef,2A,2B,CDEE,5A,5B,abc,3A,3B,bcd,4A,4B,ab,1A,1B,def,6A,6B

cdef,CDEE,abc,bcd,ab,def
cdef,CDEE,abc,bcd,ab,def,2A,5A,3A,4A,1A,6A
cdef,CDEE,abc,bcd,ab,def,2A,5A,3A,4A,1A,6A,2B,5B,3B,4B,1B,6B
cdef,CDEE,abc,bcd,ab,def
cdef,2A,CDEE,5A,abc,3A,bcd,4A,ab,1A,def,6A
cdef,2A,2B,CDEE,5A,5B,abc,3A,3B,bcd,4A,4B,ab,1A,1B,def,6A,6B
cdef,CDEE,abc,bcd,ab,def
cdef,2A,CDEE,5A,abc,3A,bcd,4A,ab,1A,def,6A
cdef,2A,2B,CDEE,5A,5B,abc,3A,3B,bcd,4A,4B,ab,1A,1B,def,6A,6B

ab,CDEE,cdef,abc,bcd,def
ab,CDEE,cdef,abc,bcd,def,1A,5A,2A,3A,4A,6A
ab,CDEE,cdef,abc,bcd,def,1A,5A,2A,3A,4A,6A,1B,5B,2B,3B,4B,6B
ab,CDEE,cdef,abc,bcd,def
ab,1A,CDEE,5A,cdef,2A,abc,3A,bcd,4A,def,6A
ab,1A,1B,CDEE,5A,5B,cdef,2A,2B,abc,3A,3B,bcd,4A,4B,def,6A,6B
ab,CDEE,cdef,abc,bcd,def
ab,1A,CDEE,5A,cdef,2A,abc,3A,bcd,4A,def,6A
ab,1A,1B,CDEE,5A,5B,cdef,2A,2B,abc,3A,3B,bcd,4A,4B,def,6A,6B

ab,CDEE,cdef,abc,bcd,def
ab,CDEE,cdef,abc,bcd,def,1A,5A,2A,3A,4A,6A
ab,CDEE,cdef,abc,bcd,def,1A,5A,2A,3A,4A,6A,1B,5B,2B,3B,4B,6B
ab,CDEE,cdef,abc,bcd,def
ab,1A,CDEE,5A,cdef,2A,abc,3A,bcd,4A,def,6A
ab,1A,1B,CDEE,5A,5B,cdef,2A,2B,abc,3A,3B,bcd,4A,4B,def,6A,6B
ab,CDEE,cdef,abc,bcd,def
ab,1A,CDEE,5A,cdef,2A,abc,3A,bcd,4A,def,6A
ab,1A,1B,CDEE,5A,5B,cdef,2A,2B,abc,3A,3B,bcd,4A,4B,def,6A,6B

cdef,CDEE,abc,bcd,ab,def
cdef,CDEE,abc,bcd,ab,def,2A,5A,3A,4A,1A,
cdef,CDEE,abc,bcd,ab,def,2A,5A,3A,4A,1A,,2B,,3B,4B,1B,
cdef,CDEE,abc,bcd,ab,def
cdef,2A,CDEE,5A,abc,3A,bcd,4A,ab,1A,def,
cdef,2A,2B,CDEE,5A,,abc,3A,3B,bcd,4A,4B,ab,1A,1B,def,,
cdef,CDEE,abc,bcd,ab,def
cdef,2A,CDEE,5A,abc,3A,bcd,4A,ab,1A,def,1A
cdef,2A,2B,CDEE,5A,1B,abc,3A,3B,bcd,4A,4B,ab,1A,1B,def,1A,1B

cdef,CDEE,abc,bcd,ab,def
cdef,CDEE,abc,bcd,ab,def,2A,5A,3A,4A,1A,
cdef,CDEE,abc,bcd,ab,def,2A,5A,3A,4A,1A,,2B,,3B,4B,1B,
cdef,CDEE,abc,bcd,ab,def
cdef,2A,CDEE,5A,abc,3A,bcd,4A,ab,1A,def,
cdef,2A,2B,CDEE,5A,,abc,3A,3B,bcd,4A,4B,ab,1A,1B,def,,
cdef,CDEE,abc,bcd,ab,def
cdef,2A,CDEE,5A,abc,3A,bcd,4A,ab,1A,def,1A
cdef,2A,2B,CDEE,5A,1B,abc,3A,3B,bcd,4A,4B,ab,1A,1B,def,1A,1B

ab,CDEE,cdef,abc,bcd,def
ab,CDEE,cdef,abc,bcd,def,1A,5A,2A,3A,4A,
ab,CDEE,cdef,abc,bcd,def,1A,5A,2A,3A,4A,,1B,,2B,3B,4B,
ab,CDEE,cdef,abc,bcd,def
ab,1A,CDEE,5A,cdef,2A,abc,3A,bcd,4A,def,
ab,1A,1B,CDEE,5A,,cdef,2A,2B,abc,3A,3B,bcd,4A,4B,def,,
ab,CDEE,cdef,abc,bcd,def
ab,1A,CDEE,5A,cdef,2A,abc,3A,bcd,4A,def,1A
ab,1A,1B,CDEE,5A,1B,cdef,2A,2B,abc,3A,3B,bcd,4A,4B,def,1A,1B

ab,CDEE,cdef,abc,bcd,def
ab,CDEE,cdef,abc,bcd,def,1A,5A,2A,3A,4A,
ab,CDEE,cdef,abc,bcd,def,1A,5A,2A,3A,4A,,1B,,2B,3B,4B,
ab,CDEE,cdef,abc,bcd,def
ab,1A,CDEE,5A,cdef,2A,abc,3A,bcd,4A,def,
ab,1A,1B,CDEE,5A,,cdef,2A,2B,abc,3A,3B,bcd,4A,4B,def,,
ab,CDEE,cdef,abc,bcd,def
ab,1A,CDEE,5A,cdef,2A,abc,3A,bcd,4A,def,1A
ab,1A,1B,CDEE,5A,1B,cdef,2A,2B,abc,3A,3B,bcd,4A,4B,def,1A,1B

EOD
TESTARGS=" -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

cat >$TMPDIR/pieces.txt <<'EOD'
#
-mt
-sect BEFORE
=main
  o "+E<=ab;   +E<=cdef;  +E<=abc;   +E<=bcd;   +E<=CDEE;  +E<=def"
  o "+F<=1A;   +F<=2A;    +F<=3A;    +F<=4A;    +F<=5A;    +F<=6A"
  o "+G<=1B;   +G<=2B;    +G<=3B;    +G<=4B;    +G<=5B;    +G<=6B"
  o "? dim($Z[],tok(e[]));"
  o "? tix($Z[],E[]); &testem"                     ## A case sensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "? tcx($Z[],E[]); &testem"                     ## A case INsensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "x-1F; x-2G"                                   ## Make two of the string variables shorter, repeat.
  o "? tix($Z[],E[]); &testem"                     ## A case sensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "? tcx($Z[],E[]); &testem"                     ## A case INsensitive map of E sorted
  o "? $Z[]-(1+len($Z[])); &testem"                  ## Same, using negative token numbers
  o "eof; brk"
=testem  ## function to run all tests
  o "<[ump$Z:vE:dv,:];   <=\n"  ## tokens from E, v mode
  o "<[ump$Z:vEF:dv,:];  <=\n"  ## tokens from EF
  o "<[ump$Z:vEFG:dv,:]; <=\n"  ## tokens from EFG
  o "<[ump$Z:=E:dv,:];   <=\n"  ## tokens from E, = mode
  o "<[ump$Z:=EF:dv,:];  <=\n"  ## tokens from EF
  o "<[ump$Z:=EFG:dv,:]; <=\n"  ## tokens from EFG
  o "<[ump$Z:@E:dv,:];   <=\n"  ## tokens from E, @ mode
  o "<[ump$Z:@EF:dv,:];  <=\n"  ## tokens from EF
  o "<[ump$Z:@EFG:dv,:]; <=\n"  ## tokens from EFG
  o "<=\n; ret"
-eoc
EOD

TESTARGS=" -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS

echo
echo "testing -pm '' '? tls AND sls'"
echo

cat >$TMPDIR/pieces.txt <<'EOD'
#
-mt
-fp 0
-sect COMMON
=tlssls ##function that runs tls once,sls twice (better testing)
  o          "? $C=tls($T[]); <=Result of tls: ; <[v$C:]; ? $D=$C"
  o          "<= TokenNumbers: ; ? ini($I[],0,0,1)"
  ma "?>:C"  "? $I[1,2]=$I[1,2]+1;    ? $C=$C-1; <= ; <[dv\ :v$T:$I];           ^0; !; <=\n" 

  o          "<=Result of tls: ; <[v$D:]; ? $C=$D"
  o          "<= QueryToken:   ; ? ini($I[],1,1,1)"
  mA "?>:C"  "? $I[1,2]=$T[-$C];      ? $C=$C-1; <= ; <[vB:$I];                 ^0; !; <=\n"

  o          "? $C=sls($T[]); <=Result of sls: ; <[v$C:]; ? $D=$C"           
  o          "<= Ranges:       ; ? ini($I[],-1,0,1); ? $C=2*$D"
  mA "?>:C"  "? $I[1,2]=$I[1,2]+2;    ? $C=$C-2; <= (; <[dv,:v$T:$I];   <=);    ^0; !; <=\n"

  o          "                <=Result of sls: ; <[v$D:]"
  o          "<= Matched:      ; ? $C=2*$D;"
  mA "?>:C"  "? $I[1,2]=$T[-$C,1-$C]; ? $C=$C-2; <= ;  <[mc:dv,:vA:$I];         ^0; !; <=\n\n"
  o          "ret"
-sect BEFORE
  o          "+A<=miss miss two one miss three Two" ## A Variable to search
  o          "+B<=one two three; poB"               ## B holds search tokens
                                                    ## $C will hold the count of tokens/ranges
                                                    ## $D will hold the count of ranges
                                                    ## $I will index into $T
                                                    ## $T will hold the token numbers/search positions 
    
  mA "tg:B"  "&tlssls; !; <=OOPS!\n; fail"   ## three hits                
  mA "tcg:B" "&tlssls; !; <=OOPS!\n; fail"   ## four hits                
  o          "xB; +B<=three not in here; poB"
  mA "tg:B"  "&tlssls; !; <=OOPS!\n; fail"   ## one hit                
  o          "xB; +B<=not in here; poB"      ## no hits, swap the logic
  mA "tg:B"  "<=OOPS!\n; fail; !; &tlssls"                   
  o          "eof"
-eoc
EOD
cat >$TMPDIR/old.txt <<'EOD'
Result of tls: 3 TokenNumbers:  2 1 3
Result of tls: 3 QueryToken:    two one three
Result of sls: 3 Ranges:        (11,13) (15,17) (24,28)
Result of sls: 3 Matched:       two one three

Result of tls: 4 TokenNumbers:  2 1 3 2
Result of tls: 4 QueryToken:    two one three two
Result of sls: 4 Ranges:        (11,13) (15,17) (24,28) (30,32)
Result of sls: 4 Matched:       two one three Two

Result of tls: 1 TokenNumbers:  1
Result of tls: 1 QueryToken:    three
Result of sls: 1 Ranges:        (24,28)
Result of sls: 1 Matched:       three

Result of tls: 0 TokenNumbers: 
Result of tls: 0 QueryToken:   
Result of sls: 0 Ranges:       
Result of sls: 0 Matched:      

EOD
TESTARGS=" -cmd $TMPDIR/pieces.txt"; dotest; echo $TESTARGS


echo "---------------------------------------------"
echo "Passed: $PASSED/$TESTED"

#/bin/rm $TMPDIR/input1.txt
#/bin/rm $TMPDIR/input2.txt
#/bin/rm $TMPDIR/pieces.txt
