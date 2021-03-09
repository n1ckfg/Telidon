 
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.03/07                           *
C  *    TEST TITLE : ISS and filters                       *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)
 
      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20
 
      INTEGER     NAMLEN, NAMSET(10), MXNTST,MXITST, INVAL,N
      INTEGER     IDUM1,IDUM2,IDUM3,IDUM4,IDUM5, MXNFL,MXIFL
      INTEGER     NPTR,IPTR
 
      REAL        XP(5),YP(5),ZP(5)
 
      CHARACTER   NFIL*900, IFIL*900, DIGCH(9)*1
 
      DATA  DIGCH / '1','2','3','4','5','6','7','8','9' /
 
      CALL INITGL ('02.03.03/07')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  Structure #101:
C  1. add names to set: 3,4,5
C  2. execute structure 102
      CALL POPST (101)
      CALL SETVS ('3,4,5', NAMSET, NAMLEN)
      CALL PADS  (NAMLEN, NAMSET)
      CALL PEXST (102)
      CALL PCLST
 
C  Structure #102:
C  1. polymarker at 1,2,3
      XP(1) = 1.0
      YP(1) = 2.0
      ZP(1) = 3.0
 
      CALL POPST (102)
      CALL PPM3  (1, XP,YP,ZP)
      CALL PCLST
 
C  Throughout, keep fixed for ISS:
C  SRP = 1,2,3
C  search distance = 0.1
C  search ceiling = 1
C  clipping flag = OFF
C
C  *** *** *** ***   One normal and inverted filter   *** *** *** ***
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '    //
     1             'should be found if its non-null nameset is '      //
     2             'accepted by a single non-null normal filter and ' //
     3             'rejected by a single non-null inverted filter.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   incl: 5,6,7; excl: 8,9
C    inverted filter = incl: 1,2;   excl: 8,9
C
C  pass/fail depending on (found path = 101,2, 102,1)
 
      CALL ISSFLT ('101,1', '5,6,7 / 8,9 /', '1,2 / 8,9 /',
     1             '101,2, 102,1')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '    //
     1             'should not be found if its non-null nameset is '  //
     2             'rejected by a single non-null normal filter and ' //
     3             'also by a single non-null inverted filter.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   incl: 5,6,7; excl: 3,8,9
C    inverted filter = incl: 1,2;   excl: 8,9
C
C  pass/fail depending on (found path = empty)
 
      CALL ISSFLT ('101,1', '5,6,7 / 3,8,9 /', '1,2 / 8,9 /', ' ')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '    //
     1             'should not be found if its non-null nameset is '  //
     2             'accepted by a single non-null normal filter but ' //
     3             'also by a single non-null inverted filter.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   incl: 4,6,7; excl: 9,1
C    inverted filter = incl: 3;     excl: 8,9
C
C  pass/fail depending on (found path = empty)
 
      CALL ISSFLT ('101,1', '4,6,7 / 9,1 /', '3 / 8,9 /', ' ')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '    //
     1             'should not be found if its non-null nameset is '  //
     2             'rejected by a single non-null normal filter and ' //
     3             'accepted by a single non-null inverted filter.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   incl: 6,7;  excl: 9,1,3
C    inverted filter = incl: 11,3; excl: 8,9
C
C  pass/fail depending on (found path = empty)
 
      CALL ISSFLT ('101,1', '6,7 / 9,1,3 /', '11,3 / 8,9 /', ' ')
 
C  *** *** ***   One normal or inverted filter, but not both   *** *** ***
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '    //
     1             'should be found if its non-null nameset is '      //
     2             'accepted by a single non-null normal filter and ' //
     3             'there are no inverted filters.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   incl: 5,6,7; excl: 8,9
C    inverted filter = none
C
C  pass/fail depending on (found path = 101,2, 102,1)
 
      CALL ISSFLT ('101,1', '5,6,7 / 8,9 /', ' ', '101,2, 102,1')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '    //
     1             'should not be found if its non-null nameset is '  //
     2             'rejected by a single non-null normal filter and ' //
     3             'there are no inverted filters.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   incl: 2,6,7; excl: 8,9
C    inverted filter = none
C
C  pass/fail depending on (found path = empty)
 
      CALL ISSFLT ('101,1', '2,6,7 / 8,9 /', ' ', ' ')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '   //
     1             'should not be found if its non-null nameset is ' //
     2             'accepted by a single non-null inverted filter '  //
     3             'and there are no normal filters.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   none
C    inverted filter = incl: 2,6,4,7; excl: 8,9
C
C  pass/fail depending on (found path = empty)
 
      CALL ISSFLT ('101,1', ' ', '2,6,4,7 / 8,9 /', ' ')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '  //
     1             'should be found if its non-null nameset is '    //
     2             'rejected by a single non-null inverted filter ' //
     3             'and there are no normal filters.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   none
C    inverted filter = incl: empty; excl: 8,9
C
C  pass/fail depending on (found path = 101,2, 102,1)
 
      CALL ISSFLT ('101,1', ' ', '  / 8,9 /', '101,2, 102,1')
 
C  *** *** ***   No filters   *** *** ***
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '   //
     1             'should be found if its nameset is non-null and ' //
     2             'there is no normal or inverted filter.')
 
C  ISS with
C    starting path =   101,1
C    normal filter =   none
C    inverted filter = none
C
C  pass/fail depending on (found path = 101,2, 102,1)
 
      CALL ISSFLT ('101,1', ' ', ' ', '101,2, 102,1')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive ' //
     1             'should be found if its nameset is null and '   //
     2             'there is no normal or inverted filter.')
 
C  ISS with
C    starting path =   102,0
C    normal filter =   none
C    inverted filter = none
C
C  pass/fail depending on (found path = 102,1)
 
      CALL ISSFLT ('102,0', ' ', ' ', '102,1')
 
C  *** *** *** ***   Null nameset   *** *** *** ***
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '   //
     1             'should not be found if its nameset is null and ' //
     2             'there is at least one normal filter.')
 
C  ISS with
C    starting path =   102,0
C    normal filter =   incl: empty; excl: 1,2
C    inverted filter = incl: 11,3;  excl: 8,9,4
C
C  pass/fail depending on (found path = empty)
 
      CALL ISSFLT ('102,0', '  / 1,2 /', '11,3 / 8,9,4 /', ' ')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive ' //
     1             'should be found if its nameset is null and '   //
     2             'there is no normal filter.')
 
C  ISS with
C    starting path =   102,0
C    normal filter =   none
C    inverted filter = incl: empty; excl: 8,9
C
C  pass/fail depending on (found path = 102,1)
 
      CALL ISSFLT ('102,0', ' ', '  / 8,9 /', '102,1')
 
C  *** *** *** ***   Maximum number of filters   *** *** *** ***
C
C  <inquire phigs facilities> to determine:
C    mxnfl = maximum length of normal filter list
C    mxifl = maximum length of inverted filter list
 
      CALL PQPHF (1, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5, MXNFL,MXIFL)
      CALL CHKINQ ('pqphf', ERRIND)
 
      CALL SETMSG ('21', '<Inquire phigs facilities> should report ' //
     1             'the maximum lengths of both the normal and '     //
     2             'inverted filter lists to be at least 1.')
      CALL IFPF (MXNFL .GT. 0 .AND. MXIFL .GT. 0)
 
      IF (MXNFL .LT. 2 .OR. MXIFL .LT. 2) THEN
         CALL INMSG ('Skipping tests of multiple filters.')
         GOTO 666
      ENDIF
 
      MXNTST = MIN (MXNFL, 50)
      MXITST = MIN (MXIFL, 50)
 
      CALL SETMSG ('21 22', 'ISS should be able to specify as many ' //
     1             'filters in a list as the maximum reported by '   //
     2             '<inquire phigs facilities>.')
 
      NPTR = 1
      INVAL = 3
      DO 100 N = 1, MXNTST
         IF (INVAL .GT. 4) THEN
            INVAL = 3
         ELSE
            INVAL = INVAL+1
         ENDIF
C  set up nth normal filter inclusion set as 1,inval
         NFIL (NPTR:) = '1,' // DIGCH(INVAL) // '/'
         NPTR = NPTR + 4
C  set up nth normal filter exclusion set as 8,9
         NFIL (NPTR:) = '8,9/'
         NPTR = NPTR + 4
100   CONTINUE
 
      IPTR = 1
      INVAL = 5
      DO 200 N = 1, MXITST
         IF (INVAL .GT. 4) THEN
            INVAL = 2
         ELSE
            INVAL = INVAL+1
         ENDIF
C  set up nth inverted filter inclusion set as 1,inval
         IFIL (IPTR:) = '1,' // DIGCH(INVAL) // '/'
         IPTR = IPTR + 4
C  set up nth inverted filter exclusion set as inval,8
         IFIL (IPTR:) = DIGCH(INVAL) // ',8/'
         IPTR = IPTR + 4
200   CONTINUE
 
C  ISS with
C    starting path =   101,1
C    normal filter =   as set up
C    inverted filter = as set up
C
C  pass/fail depending on
C     (no error from ISS and found path = 101,2, 102,1)
 
      CALL ISSFLT ('101,1', NFIL(1:NPTR), IFIL(1:IPTR), '101,2, 102,1')
 
C  *** *** *** ***   Multiple filters   *** *** *** ***
C
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '   //
     1             'should be found if its nameset is accepted all ' //
     2             'the normal filters and rejected by all the '     //
     3             'inverted filters.')
 
C  ISS with
C    starting path =    101,1
C    normal filters =   incl: 5,3,6,7; excl: 8,9
C                       incl: 3;       excl: empty
C    inverted filters = incl: 1,2;     excl: 8,9
C                       incl: 3,1,2;   excl: 4,8,9
C
C  pass/fail depending on (found path = 101,2, 102,1)
 
      CALL ISSFLT ('101,1', '5,3,6,7 / 8,9 / 3 /   /',
     1             '1,2 / 8,9 / 3,1,2 / 4,8,9 / ', '101,2, 102,1')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '   //
     1             'should not be found if its nameset is rejected ' //
     2             'by at least one normal filter.')
 
C  ISS with
C    starting path =    101,1
C    normal filters =   incl: 5,3,6,7; excl: 8,9
C                       incl: 3;       excl: 3
C    inverted filters = incl: 1,2;     excl: 8,9
C                       incl: 3,1,2;   excl: 4,8,9
C
C  pass/fail depending on (found path = empty)
 
      CALL ISSFLT ('101,1', '5,3,6,7 / 8,9 / 3 / 3 / ',
     1             '1,2 / 8,9 / 3,1,2 / 4,8,9 / ', ' ')
 
      CALL SETMSG ('3 4 5 6 10 18 19 20', 'An eligible primitive '   //
     1             'should not be found if its nameset is accepted ' //
     2             'by at least one inverted filter.')
 
C  ISS with
C    starting path =    101,1
C    normal filters =   incl: 5,3,6,7; excl: 8,9
C                       incl: 3;       excl: 2,1
C    inverted filters = incl: 4,1,2;   excl: 8,9
C                       incl: 3,1,2;   excl: 4,8,9
C
C  pass/fail depending on (found path = empty)
 
      CALL ISSFLT ('101,1', '5,3,6,7 / 8,9 / 3 / 2,1 / ',
     1             '4,1,2 / 8,9 / 3,1,2 / 4,8,9 / ', ' ')
 
C  end_mult_filter:
 
666   CONTINUE
      CALL ENDIT
      END
