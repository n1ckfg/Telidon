 
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.01/06                           *
C  *    TEST TITLE : Building transformations              *
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
 
      REAL      ACT4X4(4,4), ACT3X3(3,3), EXP4X4(4,4), EXP3X3(3,3)
      REAL      X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ
      LOGICAL   TRNSEQ
 
      CALL INITGL ('06.01.01/06')
 
C open PHIGS
      CALL XPOPPH  (ERRFIL, MEMUN)
 
      CALL SETMSG ('1 2 15', '<Build transformation matrix 3> ' //
     1             'should generate a matrix to perform the '   //
     2             'specified 3D transformation.')
 
C Set up parameters:
C   set fixed point
      X0 = -1.12
      Y0 = 2.23
      Z0 = 3.34
C   set shift vector
      DX = 6.7
      DY = 8.9
      DZ = 10.11
C   set rotation angle
      PHIX = 7.6
      PHIY = -5.4
      PHIZ = 3.2
C   set scale factors
      FX = 0.0023
      FY = -636.34
      FZ = 2.2
 
C <Build transformation matrix 3> returns act4x4 = actual array
      CALL PBLTM3 (X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ,
     1             ERRIND, ACT4X4)
      CALL CHKINQ ('pbltm3', ERRIND)
 
C Compute exp4x4 = expected array
      CALL EBLTM3 (X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ,
     1             EXP4X4)
      CALL IFPF ( TRNSEQ (4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 16', '<Build transformation matrix> ' //
     1             'should generate a matrix to perform the ' //
     2             'specified 2D transformation.')
 
C Set up parameters:
C   set fixed point
      X0 = -1.12
      Y0 = 2.23
C   set shift vector
      DX = 6.7
      DY = 10.11
C   set rotation angle
      PHIZ = -5.4
C   set scale factors
      FX = 0.0023
      FY = -636.34
 
C <Build transformation matrix> returns act3x3 = actual array
      CALL PBLTM (X0,Y0, DX,DY, PHIZ, FX,FY, ERRIND, ACT3X3)
      CALL CHKINQ ('pbltm', ERRIND)
 
C Compute exp3x3 = expected array
      CALL EBLTM (X0,Y0, DX,DY, PHIZ, FX,FY, EXP3X3)
      CALL IFPF ( TRNSEQ (3, ACT3X3, EXP3X3))
 
      CALL ENDIT
      END
