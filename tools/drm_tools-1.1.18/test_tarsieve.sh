#!/bin/bash
#
#  test script for tarsieve features.
#
#  Note the <<'EOD', the quoted input delimiter disables substitution within that input
#
#  Note, tests that use exit or fail will not clear out memory at the end, and so will
#    look like they have memory leaks under valgrind .
#
##
#
# version 1.0 JUN-21-2013
##
EXTRACT=`which extract` # must be drm_tools extract
NEWPROG=./tarsieve
TMPDIR=/tmp
TESTED=0
PASSED=0

#
# try to figure out the OS, fail over to linux if it isn't Solaris
#

if [ SunOS = `uname` ]  #solaris 8,9
then
RM=/usr/bin/rm
DIFF=/usr/local/bin/diff  #must be Gnu diff
TAR=/usr/local/bin/tar    #must be Gnu tar
else  #linux
RM=/bin/rm
DIFF=/usr/bin/diff
TAR=/bin/tar
fi


if [ ! -x $DIFF ]
then
  echo "Program \"diff\" was not found, test cannot be run"
  exit
fi

if [ ! -x $TAR ]
then
  echo "Program \"tar\" was not found, test cannot be run"
  exit
fi

if [ ! -x $RM ]
then
  echo "Program \"rm\" was not found, test cannot be run"
  exit
fi

if [ ! -x $EXTRACT ]
then
  echo "Program \"extract\" was not found, test 3 will fail"
fi

#
# use this if the program is supposed to run without error
#
dotest ()
{
 cat > $TMPDIR/new.txt <<'EOD'
EOD
# eval valgrind --leak-check=full  --show-reachable=yes $NEWPROG  $TESTARGS >$TMPDIR/new.txt
# eval valgrind $NEWPROG  $TESTARGS >$TMPDIR/new.txt
 eval $NEWPROG  $TESTARGS 2>$TMPDIR/new.txt >/dev/null
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
 let TESTED+=1
 $DIFF -q $1 $2
 if [ $? -eq 0 ]
 then
   echo -n " $TESTED Pass "
   let PASSED+=1
 else 
   echo -n " $TESTED Fail "
 fi
}


#
# use this if the program is supposed to throw an error and exit.
# it compares the error messages,if the syntax changes, the test will fail.
#
dofail ()
{
 cat > $TMPDIR/new.txt <<'EOD'
EOD
 let TESTED+=1
 eval  $NEWPROG $TESTARGS >/dev/null 2>$TMPDIR/new.txt
 if [ $? -eq 0 ]
 then
   echo -n " $TESTED Fail "
 else 
   echo -n " $TESTED Pass "
   let PASSED+=1
 fi
}

echo " Test Args (#CSE = catch syntax error?)"
#
# DO NOT EDIT THESE LINES.  OK to add onto the end.
#
mkdir $TMPDIR/foodir
mkdir $TMPDIR/foodir/foosubdir
cat >$TMPDIR/foodir/foo <<'EOD'
Contents of foo
EOD
touch $TMPDIR/foodir/foo2
ln -s $TMPDIR/foodir/foo $TMPDIR/foodir/foo3
mkfifo $TMPDIR/foodir/foo4
mknod $TMPDIR/foodir/foosubdir/foo5 b 1 2
mknod $TMPDIR/foodir/foosubdir/foo6 c 2 3
mknod $TMPDIR/foodir/foosubdir/foo7 c 3 4
touch $TMPDIR/foodir/foosubdir/foo10
touch $TMPDIR/foodir/foosubdir/foo11
touch $TMPDIR/foodir/foosubdir/foo12
touch $TMPDIR/foodir/foosubdir/foo13
touch $TMPDIR/foodir/foosubdir/foo14
touch $TMPDIR/foodir/foosubdir/foo15
touch $TMPDIR/foodir/foosubdir/foo16
touch $TMPDIR/foodir/foosubdir/foo17
touch $TMPDIR/foodir/foosubdir/foo18
touch $TMPDIR/foodir/foosubdir/foo19
#
# set timestamps on all the files
#
touch -t 201201010000.00 -a -m $TMPDIR/foodir/foo
touch -t 201206010000.00 -a -m $TMPDIR/foodir/foo $TMPDIR/foodir/foo2
touch -t 201208010000.00 -a -m $TMPDIR/foodir/foo3 $TMPDIR/foodir/foo4
touch -t 201101010000.00 -a -m $TMPDIR/foodir/foosubdir/*
touch -t 201101010000.00 -a -m $TMPDIR/foodir/foosubdir
touch -t 201101010000.00 -a -m $TMPDIR/foodir

#
# this was the order on an ext3 file system, might not be on some other file system
#
cat >$TMPDIR/fileorder <<'EOD'
foodir/
foodir/foo4
foodir/foo
foodir/foosubdir/
foodir/foosubdir/foo12
foodir/foosubdir/foo14
foodir/foosubdir/foo18
foodir/foosubdir/foo5
foodir/foosubdir/foo16
foodir/foosubdir/foo11
foodir/foosubdir/foo17
foodir/foosubdir/foo10
foodir/foosubdir/foo7
foodir/foosubdir/foo15
foodir/foosubdir/foo6
foodir/foosubdir/foo13
foodir/foosubdir/foo19
foodir/foo3
foodir/foo2
EOD

(cd $TMPDIR; $TAR  -T fileorder --no-recursion -cf - > foo.tar)
rm -rf $TMPDIR/foodir
rm -f $TMPDIR/fileorder

# Long name tests
mkdir $TMPDIR/foodir0001
touch $TMPDIR/foodir0001/longname__1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890
mkdir $TMPDIR/foodir0001/foodir0002
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010
mkdir $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011
touch $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo1
touch $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo2
touch $TMPDIR/foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo3

cat >$TMPDIR/fileorder <<'EOD'
foodir0001
foodir0001/longname__1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890
foodir0001/foodir0002
foodir0001/foodir0002/foodir0003
foodir0001/foodir0002/foodir0003/foodir0004
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo1
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo2
foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo3
EOD

(cd $TMPDIR; $TAR  -T fileorder --no-recursion -cf - > fool.tar)
rm -rf $TMPDIR/foodir0001
rm -f $TMPDIR/fileorder

#
# get username, groupname, gid, uid from the file
#
HOLD_UNAME=`ls -al $TMPDIR/foo.tar | $EXTRACT -mt -fmt '[3]'`
HOLD_GNAME=`ls -al $TMPDIR/foo.tar | $EXTRACT -mt -fmt '[4]'`
HOLD_DUID=`ls -an $TMPDIR/foo.tar | $EXTRACT -mt -fmt '[3]'`
HOLD_DGID=`ls -an $TMPDIR/foo.tar | $EXTRACT -mt -fmt '[4]'`
HOLD_UID=`printf %o $HOLD_DUID`
HOLD_GID=`printf %o $HOLD_DGID`

echo
echo "testing general operations "
echo


cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Directory, nam=foodir/
siz=0, typ=Named pipe, nam=foodir/foo4
siz=16, typ=Regular file, nam=foodir/foo
siz=0, typ=Directory, nam=foodir/foosubdir/
siz=0, typ=Regular file, nam=foodir/foosubdir/foo12
siz=0, typ=Regular file, nam=foodir/foosubdir/foo14
siz=0, typ=Regular file, nam=foodir/foosubdir/foo18
siz=0, typ=Block special, nam=foodir/foosubdir/foo5
siz=0, typ=Regular file, nam=foodir/foosubdir/foo16
siz=0, typ=Regular file, nam=foodir/foosubdir/foo11
siz=0, typ=Regular file, nam=foodir/foosubdir/foo17
siz=0, typ=Regular file, nam=foodir/foosubdir/foo10
siz=0, typ=Char. special, nam=foodir/foosubdir/foo7
siz=0, typ=Regular file, nam=foodir/foosubdir/foo15
siz=0, typ=Char. special, nam=foodir/foosubdir/foo6
siz=0, typ=Regular file, nam=foodir/foosubdir/foo13
siz=0, typ=Regular file, nam=foodir/foosubdir/foo19
siz=0, typ=Symbolic link, nam=foodir/foo3
siz=0, typ=Regular file, nam=foodir/foo2
EOD
TESTARGS="-in $TMPDIR/foo.tar -lx"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/foo.tar -l "; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/foo.tar -l -fgeq $HOLD_GID -fueq $HOLD_UID -fown $HOLD_UNAME -fgrp $HOLD_GNAME"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Directory, nam=foodir/foosubdir/
siz=0, typ=Regular file, nam=foodir/foosubdir/foo12
siz=0, typ=Regular file, nam=foodir/foosubdir/foo14
siz=0, typ=Regular file, nam=foodir/foosubdir/foo18
siz=0, typ=Block special, nam=foodir/foosubdir/foo5
siz=0, typ=Regular file, nam=foodir/foosubdir/foo16
siz=0, typ=Regular file, nam=foodir/foosubdir/foo11
siz=0, typ=Regular file, nam=foodir/foosubdir/foo17
siz=0, typ=Regular file, nam=foodir/foosubdir/foo10
siz=0, typ=Char. special, nam=foodir/foosubdir/foo7
siz=0, typ=Regular file, nam=foodir/foosubdir/foo15
siz=0, typ=Char. special, nam=foodir/foosubdir/foo6
siz=0, typ=Regular file, nam=foodir/foosubdir/foo13
siz=0, typ=Regular file, nam=foodir/foosubdir/foo19
EOD

TESTARGS="-in $TMPDIR/foo.tar -l -fnge 4 -fnle 17"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Named pipe, nam=foodir/foo4
siz=16, typ=Regular file, nam=foodir/foo
siz=0, typ=Symbolic link, nam=foodir/foo3
siz=0, typ=Regular file, nam=foodir/foo2
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -fdge 2012-01-01  -fnle 2012-11-31"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
siz=16, typ=Regular file, nam=foodir/foo
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -fsge 15"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/foo.tar -l -fsge 16  -fsle 16"; dotest; echo $TESTARGS
cat >$TMPDIR/old.txt <<'EOD'
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -fsge 17"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/foo.tar -l -fgeq 1${HOLD_GID}"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/foo.tar -l -fueq 1${HOLD_UID}"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/foo.tar -l -fown NOT_${HOLD_UNAME}"; dotest; echo $TESTARGS
TESTARGS="-in $TMPDIR/foo.tar -l -fgrp NOT_${HOLD_GNAME}"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
nam=foodir/, typ=Directory
nam=foodir/foo4, typ=Named pipe
nam=foodir/foo, typ=Regular file
nam=foodir/foosubdir/, typ=Directory
nam=foodir/foosubdir/foo12, typ=Regular file
nam=foodir/foosubdir/foo14, typ=Regular file
nam=foodir/foosubdir/foo18, typ=Regular file
nam=foodir/foosubdir/foo5, typ=Block special
nam=foodir/foosubdir/foo16, typ=Regular file
nam=foodir/foosubdir/foo11, typ=Regular file
nam=foodir/foosubdir/foo17, typ=Regular file
nam=foodir/foosubdir/foo10, typ=Regular file
nam=foodir/foosubdir/foo7, typ=Char. special
nam=foodir/foosubdir/foo15, typ=Regular file
nam=foodir/foosubdir/foo6, typ=Char. special
nam=foodir/foosubdir/foo13, typ=Regular file
nam=foodir/foosubdir/foo19, typ=Regular file
nam=foodir/foo3, typ=Symbolic link
nam=foodir/foo2, typ=Regular file
EOD

TESTARGS="-in $TMPDIR/foo.tar -l   -lf nam,typ"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
nam=foodir/, typ=Directory
nam=foodir/foo4, typ=Named pipe
nam=foodir/foosubdir/, typ=Directory
nam=foodir/foosubdir/foo5, typ=Block special
nam=foodir/foo3, typ=Symbolic link
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -lf nam,typ -frec dir,blk,fifo,sym"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
nam=foodir/foo, typ=Regular file
nam=foodir/foosubdir/foo12, typ=Regular file
nam=foodir/foosubdir/foo14, typ=Regular file
nam=foodir/foosubdir/foo18, typ=Regular file
nam=foodir/foosubdir/foo16, typ=Regular file
nam=foodir/foosubdir/foo11, typ=Regular file
nam=foodir/foosubdir/foo17, typ=Regular file
nam=foodir/foosubdir/foo10, typ=Regular file
nam=foodir/foosubdir/foo7, typ=Char. special
nam=foodir/foosubdir/foo15, typ=Regular file
nam=foodir/foosubdir/foo6, typ=Char. special
nam=foodir/foosubdir/foo13, typ=Regular file
nam=foodir/foosubdir/foo19, typ=Regular file
nam=foodir/foo2, typ=Regular file
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -lf nam,typ -frec chr,reg"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Named pipe, nam=foo4
siz=16, typ=Regular file, nam=foo
siz=0, typ=Regular file, nam=foo12
siz=0, typ=Regular file, nam=foo14
siz=0, typ=Regular file, nam=foo18
siz=0, typ=Block special, nam=foo5
siz=0, typ=Regular file, nam=foo16
siz=0, typ=Regular file, nam=foo11
siz=0, typ=Regular file, nam=foo17
siz=0, typ=Regular file, nam=foo10
siz=0, typ=Char. special, nam=foo7
siz=0, typ=Regular file, nam=foo15
siz=0, typ=Char. special, nam=foo6
siz=0, typ=Regular file, nam=foo13
siz=0, typ=Regular file, nam=foo19
siz=0, typ=Symbolic link, nam=foo3
siz=0, typ=Regular file, nam=foo2
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -np"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Regular file, nam=foodir/foosubdir/foo12
siz=0, typ=Regular file, nam=foodir/foosubdir/foo14
siz=0, typ=Regular file, nam=foodir/foosubdir/foo18
siz=0, typ=Block special, nam=foodir/foosubdir/foo5
siz=0, typ=Regular file, nam=foodir/foosubdir/foo16
siz=0, typ=Regular file, nam=foodir/foosubdir/foo11
siz=0, typ=Regular file, nam=foodir/foosubdir/foo17
siz=0, typ=Regular file, nam=foodir/foosubdir/foo10
siz=0, typ=Char. special, nam=foodir/foosubdir/foo7
siz=0, typ=Regular file, nam=foodir/foosubdir/foo15
siz=0, typ=Char. special, nam=foodir/foosubdir/foo6
siz=0, typ=Regular file, nam=foodir/foosubdir/foo13
siz=0, typ=Regular file, nam=foodir/foosubdir/foo19
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -fdre 'foosubdir/.'"; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Block special, nam=foodir/foosubdir/foo5
siz=0, typ=Regular file, nam=foodir/foosubdir/foo15
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -fdre 'foosubdir/.' -ffre '5$' "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Named pipe, nam=foodir/foo4
siz=0, typ=Regular file, nam=foodir/foosubdir/foo14
EOD
TESTARGS="-in $TMPDIR/foo.tar -l -ffre '4$' "; dotest; echo $TESTARGS

echo
echo "Testing syntax checking"
echo

cat >$TMPDIR/old.txt <<'EOD'
tarsieve: fatal error: Bad integer argument/parameter [-n notanumber]
EOD
TESTARGS="-in $TMPDIR/foo.tar -n notanumber"; dotest; echo $TESTARGS "#CSE"

cat >$TMPDIR/old.txt <<'EOD'
tarsieve: fatal error: Illegal zero or negative integer argument/parameter [-n 0]
EOD
TESTARGS="-in $TMPDIR/foo.tar -n 0 "; dotest; echo $TESTARGS "#CSE"

cat >$TMPDIR/old.txt <<'EOD'
tarsieve: fatal error: Illegal zero or negative integer argument/parameter [-n 0]
EOD
TESTARGS="-in $TMPDIR/foo.tar -n 0 "; dotest; echo $TESTARGS "#CSE"

cat >$TMPDIR/old.txt <<'EOD'
tarsieve: fatal error: Bad octal argument/parameter [-fgeq fred]
EOD
TESTARGS="-in $TMPDIR/foo.tar -fgeq fred "; dotest; echo $TESTARGS "#CSE"

cat >$TMPDIR/old.txt <<'EOD'
tarsieve: fatal error: -fgeq: missing argument
EOD
TESTARGS="-in $TMPDIR/foo.tar -fgeq "; dotest; echo $TESTARGS "#CSE"

echo
echo "Testing fragmentation followed by concatenation"
echo

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Directory, nam=foodir/
siz=0, typ=Directory, nam=foodir/foosubdir/
siz=0, typ=Regular file, nam=foodir/foosubdir/foo18
siz=0, typ=Regular file, nam=foodir/foosubdir/foo11
siz=0, typ=Char. special, nam=foodir/foosubdir/foo7
siz=0, typ=Regular file, nam=foodir/foosubdir/foo13
siz=0, typ=Regular file, nam=foodir/foo2
siz=0, typ=Named pipe, nam=foodir/foo4
siz=0, typ=Regular file, nam=foodir/foosubdir/foo12
siz=0, typ=Block special, nam=foodir/foosubdir/foo5
siz=0, typ=Regular file, nam=foodir/foosubdir/foo17
siz=0, typ=Regular file, nam=foodir/foosubdir/foo15
siz=0, typ=Regular file, nam=foodir/foosubdir/foo19
siz=16, typ=Regular file, nam=foodir/foo
siz=0, typ=Regular file, nam=foodir/foosubdir/foo14
siz=0, typ=Regular file, nam=foodir/foosubdir/foo16
siz=0, typ=Regular file, nam=foodir/foosubdir/foo10
siz=0, typ=Char. special, nam=foodir/foosubdir/foo6
siz=0, typ=Symbolic link, nam=foodir/foo3
EOD
export TARSIEVETEMPLATE="$TMPDIR/frag%.3d.tar"
$NEWPROG -in $TMPDIR/foo.tar -n 3 -p 0 2>/dev/null
cat $TMPDIR/frag001.tar $TMPDIR/frag002.tar $TMPDIR/frag003.tar | $NEWPROG > $TMPDIR/foo2.tar
TESTARGS="-in $TMPDIR/foo2.tar -l "; dotest; echo $TESTARGS

echo
echo "Testing long name handling"
echo

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Directory, nam=foodir0001/
siz=0, typ=Regular file, nam=foodir0001/longname__1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890
siz=0, typ=Directory, nam=foodir0001/foodir0002/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/foodir0004/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/
siz=0, typ=Directory, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/
siz=0, typ=Regular file, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo1
siz=0, typ=Regular file, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo2
siz=0, typ=Regular file, nam=foodir0001/foodir0002/foodir0003/foodir0004/foodir0005/foodir0006/foodir0007/foodir0008/foodir0009/foodir0010/foodir0011/foo3
EOD

TESTARGS="-in $TMPDIR/fool.tar -l "; dotest; echo $TESTARGS

cat >$TMPDIR/old.txt <<'EOD'
siz=0, typ=Regular file, nam=longname__1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890_1234567890
siz=0, typ=Regular file, nam=foo1
siz=0, typ=Regular file, nam=foo2
siz=0, typ=Regular file, nam=foo3
EOD
TESTARGS="-in $TMPDIR/fool.tar -l -np"; dotest; echo $TESTARGS

####################### clean up  #######################

rm -f $TMPDIR/new.txt $TMPDIR/old.txt
rm -f $TMPDIR/foo.tar
rm -f $TMPDIR/fool.tar
rm -f $TMPDIR/foo2.tar
rm -f $TMPDIR/frag001.tar $TMPDIR/frag002.tar $TMPDIR/frag003.tar
echo "---------------------------------------------"
echo "Passed: $PASSED/$TESTED"
