C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.04.01/03                        *
C  *    TEST TITLE : Current nameset during conceptual     *
C  *                 traversal                             *
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

      INTEGER    MAXNAM, NANAMS, IDUM1,IDUM2,IDUM3,IDUM4,IDUM6
      INTEGER    NAMSET(20), NAMSIZ, MXNOFL

      REAL       XA(2), YA(2), ZA(2)

      DATA       XA / 1.0,1.0 /, YA / 1.0,1.0 /, ZA / 1.0,1.0 /

      CALL INITGL ('04.03.04.01/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  Throughout, incremental spatial search (ISS) is used to probe the
C  behavior of the current nameset.  It always searches for a
C  primitive at location 1,1,1.  Its filters are set to accept only
C  the expected nameset.

C  <inquire PHIGS facilities> to determine
C    nanams = number of available names in namesets
C    mxnofl = maximum length of normal filter length
      CALL PQPHF (1, ERRIND, IDUM1, IDUM2, NANAMS, IDUM3, IDUM4,
     1            MXNOFL, IDUM6)
      CALL CHKINQ ('pqphf', ERRIND)

C  maxnam is used by ISS to generate the correct filters
      MAXNAM = MIN (NANAMS, 100)

C  Set up structure #101:
C  1. add names to set: 3,4,5,9
C  2. execute structure 102
C  3. remove names from set: 4,6
C  4. execute structure 102
      CALL POPST (101)                      
      CALL SETVS ('3,5,4,9', NAMSET, NAMSIZ)
      CALL PADS (NAMSIZ, NAMSET)
      CALL PEXST (102)
      CALL SETVS ('4,6', NAMSET, NAMSIZ)
      CALL PRES (NAMSIZ, NAMSET)
      CALL PEXST (102)
      CALL PCLST

C  Set up structure #102:
C  1. polymarker at 1,1,1
C  2. remove names from set: 5,6,7,8
C  3. add names to set: 1,2,8,9
C  4. polymarker at 1,1,1
      CALL POPST (102)
      CALL PPM3  (1, XA,YA,ZA)
      CALL SETVS ('8,7,6,5', NAMSET, NAMSIZ)
      CALL PRES (NAMSIZ, NAMSET)
      CALL SETVS ('1,2,8,9', NAMSET, NAMSIZ)
      CALL PADS (NAMSIZ, NAMSET)
      CALL PPM3  (1, XA,YA,ZA)
      CALL PCLST

      CALL SETMSG ('1 4 11 15', 'The current name set should be ' //
     1             'initialized to the null set at the start of ' //
     2             'traversal.')
      CALL CURNMS (MXNOFL, MAXNAM, '102,0', '102,1', ' ')

      CALL SETMSG ('1 4 11 12 13 15', 'The current name set should ' //
     1             'be augmented by <add names to set> and reduced ' //
     2             'by <remove names from set> during traversal '    //
     3             'within a structure.')
      CALL CURNMS (MXNOFL, MAXNAM, '102,0', '102,4', '1,2,8,9')

      CALL SETMSG ('1 4 11 12 13 15', 'The current name set should ' //
     1             'be inherited unchanged from an invoking '        //
     2             'structure during traversal.')
      CALL CURNMS (MXNOFL, MAXNAM, '101,0', '101,2, 102,1', '3,4,5,9')

      CALL SETMSG ('1 4 11 12 13 15', 'The current name set should ' //
     1             'be inherited unchanged from an invoking '        //
     2             'structure during traversal and then modified '   //
     3             'by <add names to set> and <remove names from '   //
     4             'set> within the structure.')
      CALL CURNMS (MXNOFL,MAXNAM, '101,0','101,2, 102,4', '1,2,3,4,8,9')

      CALL SETMSG ('1 4 11 12 13 14 15', 'After sub-traversal of '  //
     1             'the network specified by <execute structure>, ' //
     2             'the current name set should be restored to the '//
     3             'value it had just prior to the sub-traversal.')
      CALL CURNMS (MXNOFL, MAXNAM, '101,0', '101,4, 102,1', '3,5,9')

      CALL SETMSG ('1 4 11 12 13 14 15', 'The current nameset '     //
     1             'should reflect all the effects of traversal: '  //
     2             'inheritance, restoration after sub-traversal, ' //
     3             'and additions and removals within the current ' //
     4             'structure.')
      CALL CURNMS (MXNOFL, MAXNAM, '101,0', '101,4, 102,4', '1,2,3,8,9')

C  Set up structure #103:
C  1. add names to set: 0, 1, max+1, -1
C  2. polymarker at 1,1,1
C  3. remove names from set: 1, max+11, -10
C  4. polymarker at 1,1,1
      CALL POPST (103)   
      CALL SETVS ('3,2,1,0', NAMSET, NAMSIZ)
      NAMSET(1) = NANAMS
      NAMSET(2) = -1
      CALL PADS (NAMSIZ, NAMSET)
      CALL PPM3  (1, XA,YA,ZA)
                                          
      CALL SETVS ('3,2,1', NAMSET, NAMSIZ)
      NAMSET(1) = NANAMS+10
      NAMSET(2) = -10
      CALL PRES (NAMSIZ, NAMSET)
      CALL PPM3  (1, XA,YA,ZA)
      CALL PCLST

      CALL SETMSG ('1 10 11 12 15 16', 'The current name set should ' //
     1             'be augmented by the valid names specified by '    //
     2             '<add names to set> during traversal within a '    //
     3             'structure, and invalid names should be ignored.')
      CALL CURNMS (MXNOFL, MAXNAM, '103,0', '103,2', '0,1')

      CALL SETMSG ('4 10 11 13 15 16', 'The current name set should ' //
     1             'be reduced by the valid names specified by '      //
     2             '<remove names from set> during traversal within ' //
     3             'a structure, and invalid names should be ignored.')
      CALL CURNMS (MXNOFL, MAXNAM, '103,0', '103,4', '0')

666   CONTINUE
C wrap it up
      CALL ENDIT
      END

