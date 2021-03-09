C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/04                           *
C  *    TEST TITLE : Effect of local and global            *
C  *                 transformations in a single structure *
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
 
C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
      REAL       A1(4,4), A2(4,4), A3(4,4), A4(4,4), A5(4,4)
      REAL       A6(3,3), A7(3,3), PPMX(1), PPMY(1), PPMZ(1)
      REAL       EX1COM(4,4), EX2COM(4,4), TMPMAT(4,4)

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
 
      DATA A6 / 0.9153,   0.3884,   0.3859,
     1          0.0327,   1.3789,  -0.3846,
     2          0.3814,   0.0693,   0.9099  /
 
      DATA A7 / 0.9528,   0.1134,  -0.3495,
     1          0.3002,   1.2937,   0.1857,
     2         -0.2830,   0.3916,   0.8847  /
 
C  Throughout, use incremental spatial search (ISS) to test the
C  effects of the current global and local modelling
C  transformations.  The search reference point (SRP) is based on
C  an MC location of (3,4,5), adjusted to account for the expected
C  transformation.
      DATA  PPMX / 3.0 /, PPMY / 4.0 /, PPMZ / 5.0 /
 
      CALL INITGL ('06.01.02/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      IF (.NOT. SPHDIS(123)) THEN
         CALL INMSG ('Skipping test because implementation '     //
     1               'apparently uses non-Euclidean metric for ' //
     2               'search distance.')
         GOTO 666
      ENDIF

C  Set up structure #101:
      CALL POPST  (101)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSLMT3 (A1, PCREPL)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSLMT3 (A2, PCPOST)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSLMT3 (A3, PCPRE)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSGMT3 (A4)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSLMT3 (A5, PCREPL)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSGMT  (A6)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PSLMT  (A7, PCPOST)
      CALL PPM3   (1, PPMX,PPMY,PPMZ)
      CALL PCLST
 
      CALL SETMSG ('16 17 19', 'At the start of a traversal, the ' //
     1             'current global and local modelling '           //
     2             'transformations should both be set to the '    //
     3             'identity matrix.')
C   expected composite transformation = identity matrix
      CALL IDMAT  (4, EX1COM)
      CALL COMTOK (EX1COM, '101,1')
 
      CALL SETMSG ('8 16 17', '<Set local transformation 3>, with ' //
     1             'REPLACE, should replace the current local '     //
     2             'modelling transformation with the specified '   //
     3             'matrix.')
C   expected composite transformation = A1
      CALL ECOM3  (EX1COM, A1, EX2COM)
      CALL COMTOK (EX2COM, '101,3')
 
      CALL SETMSG ('8 16 17', '<Set local transformation 3>, with '   //
     1             'POSTCONCATENATE, should replace the current '     //
     2             'local modelling transformation with the product ' //
     3             'of the specified matrix and its former value.')
C   expected composite transformation = A2 x A1
      CALL ECOM3  (A2, EX2COM, EX1COM)
      CALL COMTOK (EX1COM, '101,5')
 
      CALL SETMSG ('8 16 17', '<Set local transformation 3>, with '   //
     1             'PRECONCATENATE, should replace the current '      //
     2             'local modelling transformation with the product ' //
     3             'of its former value and the specified matrix.')
C   expected composite transformation = A2 x A1 x A3
      CALL ECOM3  (EX1COM, A3, EX2COM)
      CALL COMTOK (EX2COM, '101,7')
 
      CALL SETMSG ('15 16 17', '<Set global transformation 3> '   //
     1             'should replace the current global modelling ' //
     2             'transformation with the specified matrix.')
C   expected composite transformation = A4 x A2 x A1 x A3
      CALL ECOM3  (A4, EX2COM, EX1COM)
      CALL COMTOK (EX1COM, '101,9')
 
      CALL SETMSG ('8 16 17', '<Set local transformation 3>, with '  //
     1             'REPLACE, should be able to replace the current ' //
     2             'local modelling transformation with the '        //
     3             'specified matrix several times in one structure.')
C   expected composite transformation = A4 x A5
      CALL ECOM3  (A4, A5, EX1COM)
      CALL COMTOK (EX1COM, '101,11')
 
      CALL SETMSG ('15 16 17 18', '<Set global transformation> '  //
     1             'should replace the current global modelling ' //
     2             'transformation with the suitably expanded '   //
     3             'version of the specified matrix.')
C   expected composite transformation = expanded-A6 x A5
      CALL EXP34  (A6, TMPMAT)
      CALL ECOM3  (TMPMAT, A5, EX1COM)
      CALL COMTOK (EX1COM, '101,13')
 
      CALL SETMSG ('8 16 17 18', '<Set local transformation>, with '  //
     1             'POSTCONCATENATE, should replace the current '     //
     2             'local modelling transformation with the product ' //
     3             'of the suitably expanded version of the '         //
     4             'specified matrix and its former value.')
C   expected composite transformation = expanded-A6 x expanded-A7 x A5
      CALL EXP34  (A7, EX1COM)
      CALL ECOM3  (TMPMAT, EX1COM, EX2COM)
      CALL ECOM3  (EX2COM, A5, EX1COM)
      CALL COMTOK (EX1COM, '101,15')
 
666   CONTINUE
      CALL ENDIT
      END
