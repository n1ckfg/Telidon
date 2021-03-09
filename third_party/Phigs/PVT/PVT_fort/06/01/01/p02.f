C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.01/02                           *
C  *    TEST TITLE : Behavior of scaling                   *
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
 
      REAL      ACT4X4(4,4), EXP4X4(4,4), FX,FY,FZ
      REAL      ACT3X3(3,3), EXP3X3(3,3)
      LOGICAL   TRNSEQ
 
      CALL INITGL ('06.01.01/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL SETMSG ('1 2 5', '<Scale 3> should return a correct ' //
     1             'representation for the transformation to '   //
     2             'scale a 3D point, with non-zero parameters.')
 
      FX = -33.3
      FY =   0.0076
      FZ =   2.2
 
C  <Scale 3> with fx,fy,fz returns act4x4 = actual array
      CALL PSC3   (FX,FY,FZ, ERRIND, ACT4X4)
      CALL CHKINQ ('psc3', ERRIND)
 
C  Compute exp4x4 = expected array
      CALL ESC3   (FX,FY,FZ, EXP4X4)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 5', '<Scale 3> should return a correct ' //
     1             'representation for the transformation to '   //
     2             'scale a 3D point, with zero parameters.')
 
      FX = 0.0
      FY = 0.0076
      FZ = 0.0
 
C  <Scale 3> with fx,fy,fz returns act4x4 = actual array
      CALL PSC3   (FX,FY,FZ, ERRIND, ACT4X4)
      CALL CHKINQ ('psc3', ERRIND)
 
C  Compute exp4x4 = expected array
      CALL ESC3   (FX,FY,FZ, EXP4X4)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 6', '<Scale> should return a correct '  //
     1             'representation for the transformation to '  //
     2             'scale a 2D point, with non-zero parameters.')
 
      FX = -33.3
      FY =   0.0076
 
C  <Scale> with fx,fy returns act3x3 = actual array
      CALL PSC    (FX,FY, ERRIND, ACT3X3)
      CALL CHKINQ ('psc', ERRIND)
 
C  Compute exp3x3 = expected array
      CALL ESC   (FX,FY, EXP3X3)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(3, ACT3X3, EXP3X3))
 
      CALL SETMSG ('1 2 6', '<Scale> should return a correct ' //
     1             'representation for the transformation to ' //
     2             'scale a 2D point, with zero parameters.')
 
      FX = 0.0
      FY = 0.0
 
C  <Scale> with fx,fy returns act3x3 = actual array
      CALL PSC    (FX,FY, ERRIND, ACT3X3)
      CALL CHKINQ ('psc', ERRIND)
 
C  Compute exp3x3 = expected array
      CALL ESC   (FX,FY, EXP3X3)
 
C  pass if matrices represent same transformation
      CALL IFPF  (TRNSEQ(3, ACT3X3, EXP3X3))
 
      CALL ENDIT
      END
