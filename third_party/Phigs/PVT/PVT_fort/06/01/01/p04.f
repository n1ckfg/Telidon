C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.01/04                           *
C  *    TEST TITLE : Behavior of matrix composition        *
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
 
      REAL      ACT4X4(4,4), EXP4X4(4,4), AIN4X4(4,4), BIN4X4(4,4)
      REAL      ACT3X3(3,3), EXP3X3(3,3), AIN3X3(3,3), BIN3X3(3,3)
      REAL      INC
      INTEGER   I,J
      LOGICAL   TRNSEQ
 
      CALL INITGL ('06.01.01/04')
 
C open PHIGS
      CALL XPOPPH  (ERRFIL, MEMUN)
      CALL SETMSG ('1 2 11', 'The matrix returned by <compose ' //
     1             'matrix 3> should perform the same 3D '      //
     2             'transformation as that resulting from the ' //
     3             'multiplication of the two specified matrices.')
 
      AIN4X4(1,1) = -2.2
      AIN4X4(1,2) = 3.3
      AIN4X4(1,3) = 4.4
      AIN4X4(1,4) = 5.5
      AIN4X4(2,1) = 0.0023
      AIN4X4(2,2) = -727.12
      AIN4X4(2,3) = 2.09
      AIN4X4(2,4) = 33.33
      AIN4X4(3,1) = 0
      AIN4X4(3,2) = 34
      AIN4X4(3,3) = 54.1
      AIN4X4(3,4) = -0.045
      AIN4X4(4,1) = 7
      AIN4X4(4,2) = 6
      AIN4X4(4,3) = 5
      AIN4X4(4,4) = 4
 
      INC = 0.0
      DO 401 I = 1,4
      DO 402 J = 1,4
        BIN4X4(I,J) = TAN(-1.56 + INC)
        INC = INC + 3.0/16.0
402   CONTINUE
401   CONTINUE
 
      CALL PCOM3  (AIN4X4, BIN4X4, ERRIND, ACT4X4)
      CALL CHKINQ ('pcom3', ERRIND)
 
C  Compute exp4x4 = expected array
      CALL ECOM3  (AIN4X4, BIN4X4, EXP4X4)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 12', 'The matrix returned by <compose ' //
     1             'matrix> should perform the same 2D '        //
     2             'transformation as that resulting from the ' //
     3             'multiplication of the two specified matrices.')
 
      AIN3X3(1,1) = -2.2
      AIN3X3(1,2) = 3.3
      AIN3X3(1,3) = 5.5
      AIN3X3(2,1) = 0.0023
      AIN3X3(2,2) = -727.12
      AIN3X3(2,3) = 33.33
      AIN3X3(3,1) = 0
      AIN3X3(3,2) = 34
      AIN3X3(3,3) = -0.045
 
      INC = 0.0
      DO 301 I = 1,3
      DO 302 J = 1,3
        BIN3X3(I,J) = TAN(-1.56 + INC)
        INC = INC + 3.0/9.0
302   CONTINUE
301   CONTINUE
 
      CALL PCOM  (AIN3X3, BIN3X3, ERRIND, ACT3X3)
      CALL CHKINQ ('pcom', ERRIND)
 
C  Compute exp3x3 = expected array
      CALL ECOM  (AIN3X3, BIN3X3, EXP3X3)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(3, ACT3X3, EXP3X3))
 
      CALL ENDIT
      END
