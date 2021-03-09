C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/05                           *
C  *    TEST TITLE : Effect of local and global            *
C  *                 transformations in a structure        *
C  *                 network                               *
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
     3        DUMINT(20)
      REAL    DUMRL(20)
 
      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20
 
C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
      REAL       A1(4,4), A2(4,4), A3(4,4), A4(4,4), A5(4,4)
      REAL       PPMX(1), PPMY(1), PPMZ(1)
      REAL       EX1COM(4,4), EX2COM(4,4)

      LOGICAL    SPHDIS
 
C  Set up arbitrary matrices:
 
      DATA A1 / 0.6400,  -0.2158,  -0.3232,  -0.1398,
     1         -0.3405,   0.9041,  -0.1562,   0.2284,
     2         -0.3458,  -0.1908,   0.6289,  -0.2234,
     3         -0.2107,   0.2571,  -0.1183,   1.3633  /
 
      DATA A2 / 0.7066,   0.2092,  -0.0416,  -0.3792,
     1         -0.0907,   0.7405,  -0.1633,  -0.2249,
     2         -0.3822,   0.1112,   0.6808,   0.0086,
     3         -0.1183,  -0.1777,   0.0448,   0.9750  /
 
      DATA A3 / 0.7061,  -0.2336,  -0.2953,  -0.2673,
     1         -0.2344,   0.8280,  -0.2632,  -0.2501,
     2          0.2709,   0.0524,   0.6326,  -0.1435,
     3          0.3407,   0.3902,   0.1875,   1.2520  /
 
      DATA A4 / 0.8168,  -0.2033,  -0.3886,  -0.2358,
     1          0.1839,   1.1356,  -0.3802,  -0.3262,
     2          0.1461,   0.0644,   0.7139,   0.2245,
     3          0.0835,  -0.1778,  -0.3036,   0.8549  /
 
      DATA A5 / 0.6428,   0.3743,   0.1195,   0.0006,
     1         -0.2039,   1.3347,  -0.0378,   0.1513,
     2          0.3480,  -0.2931,   1.3423,   0.2051,
     3         -0.2744,  -0.2590,   0.0819,   1.2317  /
 
      CALL INITGL ('06.01.02/05')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      IF (.NOT. SPHDIS(123)) THEN
         CALL INMSG ('Skipping test because implementation '     //
     1               'apparently uses non-Euclidean metric for ' //
     2               'search distance.')
         GOTO 666
      ENDIF

C  Throughout, use incremental spatial search (ISS) to test the
C  effects of the current global and local modelling
C  transformations.  The search reference point (SRP) is based on
C  an MC location of (3,4,5), adjusted to account for the expected
C  transformation.
      DATA  PPMX / 3.0 /, PPMY / 4.0 /, PPMZ / 5.0 /
 
C  Set up structure #101:
      CALL POPST  (101)
      CALL PEXST  (104)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSGMT3 (A1)
      CALL PSLMT3 (A2, PCPRE)
      CALL PEXST  (102)
      CALL PSLMT3 (A3, PCPOST)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSGMT3 (A4)
      CALL PEXST  (103)
      CALL PCLST
 
C  Set up structure #102:
      CALL POPST  (102)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSGMT3 (A5)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSGMT3 (A3)
      CALL PEXST  (103)
      CALL PSLMT3 (A4, PCPRE)
      CALL PEXST  (104)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PCLST
 
C  Set up structure #103:
      CALL POPST  (103)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSLMT3 (A1, PCPRE)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PCLST
 
C  Set up structure #104:
      CALL POPST  (104)
      CALL PSGMT3 (A1)
      CALL PSLMT3 (A2, PCREPL)
      CALL PCLST
 
      CALL SETMSG ('16 17 19 20', 'If no transformations have been '  //
     1             'set since the onset of traversal, the composite ' //
     2             'modelling transformation should be restored to '  //
     3             'the identity matrix after invocation of a '       //
     4             'structure network.')
C  expected composite transformation = identity matrix
      CALL IDMAT  (4, EX1COM)
      CALL COMTOK (EX1COM, '101,2')
 
      CALL SETMSG ('16 17 21 22', 'At the start of a sub-traversal ' //
     1             'caused by <execute structure>, the new '         //
     2             'composite modelling transformation should be '   //
     3             'unchanged from that of the invoking structure.')
C  expected composite transformation = A1 x A2
      CALL ECOM3  (A1, A2, EX1COM)
      CALL COMTOK (EX1COM, '101,5, 102,1')
 
      CALL SETMSG ('16 17 21 22', 'Replacing the global modelling ' //
     1             'transformation within a sub-traversal without ' //
     2             'altering the local modelling transformation '   //
     3             'should replace the composite transformation.')
C  expected composite transformation = A5
      CALL COMTOK (A5, '101,5, 102,3')
 
      CALL SETMSG ('16 17 21 22', 'At the start of a sub-traversal '  //
     1             'several levels deep, the composite modelling '    //
     2             'transformation should be unchanged from that of ' //
     3             'the immediately invoking structure.')
C  expected composite transformation = A3
      CALL COMTOK (A3, '101,5, 102,5, 103,1')
 
      CALL SETMSG ('16 17 21 22', 'Replacing the local modelling '   //
     1             'transformation within a sub-traversal without '  //
     2             'altering the global modelling transformation '   //
     3             'should postconcatenate the specified matrix to ' //
     4             'the old value of the composite transformation.')
C  expected composite transformation = A3 x A1
      CALL ECOM3  (A3, A1, EX1COM)
      CALL COMTOK (EX1COM, '101,5, 102,5, 103,3')
 
      CALL SETMSG ('16 17 20', 'Upon returning from a '               //
     1             'sub-traversal, the global and local modelling '   //
     2             'transformations should be restored to the value ' //
     3             'they had just before the sub-traversal.')
C  expected composite transformation = A3 x A4
      CALL ECOM3  (A3, A4, EX1COM)
      CALL COMTOK (EX1COM, '101,5, 102,8')
 
      CALL SETMSG ('16 17 20', 'Upon returning several levels from '  //
     1             'a sub-traversal, the global and local modelling ' //
     2             'transformations should be restored to the value ' //
     3             'they had just before the sub-traversal.')
C  expected composite transformation = A1 x A3 x A2
      CALL ECOM3  (A3, A2, EX1COM)
      CALL ECOM3  (A1, EX1COM, EX2COM)
      CALL COMTOK (EX2COM, '101,7')
 
      CALL SETMSG ('16 17 21 22', 'At the start of a sub-traversal ' //
     1             'the new composite modelling transformation '     //
     2             'should be unchanged from that of the invoking '  //
     3             'structure, even if the invoked structure has '   //
     4             'been executed previously in the traversal.')
C  expected composite transformation = A4 x A3 x A2
      CALL ECOM3  (A4, EX1COM, EX2COM)
      CALL COMTOK (EX2COM, '101,9, 103,1')
 
      CALL SETMSG ('16 17 21 22', 'Replacing the local modelling '    //
     1             'transformation within a sub-traversal without '   //
     2             'altering the global modelling transformation '    //
     3             'should postconcatenate the specified matrix to '  //
     4             'the old value of the composite transformation, '  //
     5             'even if the invoked structure has been executed ' //
     6             'previously in the traversal.')
C  expected composite transformation = A4 x A3 x A2 x A1
      CALL ECOM3  (EX2COM, A1, EX1COM)
      CALL COMTOK (EX1COM, '101,9, 103,3')
 
666   CONTINUE
      CALL ENDIT
      END
