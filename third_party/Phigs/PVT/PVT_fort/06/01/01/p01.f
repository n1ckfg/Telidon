C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.01/01                           *
C  *    TEST TITLE : Behavior of translations              *
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
 
      REAL      ACT4X4(4,4), EXP4X4(4,4), DX,DY,DZ
      REAL      ACT3X3(3,3), EXP3X3(3,3)
 
      LOGICAL   TRNSEQ
 
      CALL INITGL ('06.01.01/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL SETMSG ('1 2 3', '<Translate 3> should return a '        //
     1             'correct representation for the transformation ' //
     2             'to translate a 3D point, with non-zero '        //
     3             'parameters.')
 
      DX = -33.3
      DY =   0.0076
      DZ =   2.2
 
C  <Translate 3> with dx,dy,dz returns act4x4 = actual array
      CALL PTR3   (DX,DY,DZ, ERRIND, ACT4X4)
      CALL CHKINQ ('ptr3', ERRIND)
 
C  Compute exp4x4 = expected array
      CALL ETR3   (DX,DY,DZ, EXP4X4)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 3', '<Translate 3> should return a '        //
     1             'correct representation for the transformation ' //
     2             'to translate a 3D point, with zero parameters.')
 
      DX = 0.0
      DY = 0.0076
      DZ = 0.0
 
C  <Translate 3> with dx,dy,dz returns act4x4 = actual array
      CALL PTR3   (DX,DY,DZ, ERRIND, ACT4X4)
      CALL CHKINQ ('ptr3', ERRIND)
 
C  Compute exp4x4 = expected array
      CALL ETR3   (DX,DY,DZ, EXP4X4)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 4', '<Translate> should return a '          //
     1             'correct representation for the transformation ' //
     2             'to translate a 2D point, with non-zero '        //
     3             'parameters.')
 
      DX = -33.3
      DY =   0.0076
 
C  <Translate> with dx,dy returns act3x3 = actual array
      CALL PTR    (DX,DY, ERRIND, ACT3X3)
      CALL CHKINQ ('ptr', ERRIND)
 
C  Compute exp3x3 = expected array
      CALL ETR   (DX,DY, EXP3X3)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(3, ACT3X3, EXP3X3))
 
      CALL SETMSG ('1 2 4', '<Translate> should return a '          //
     1             'correct representation for the transformation ' //
     2             'to translate a 2D point, with zero parameters.')
 
      DX = 0.0
      DY = 0.0
 
C  <Translate> with dx,dy returns act3x3 = actual array
      CALL PTR    (DX,DY, ERRIND, ACT3X3)
      CALL CHKINQ ('ptr', ERRIND)
 
C  Compute exp3x3 = expected array
      CALL ETR   (DX,DY, EXP3X3)
 
C  pass if matrices represent same transformation
      CALL IFPF  (TRNSEQ(3, ACT3X3, EXP3X3))
 
      CALL ENDIT
      END
