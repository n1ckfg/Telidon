C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.01/03                           *
C  *    TEST TITLE : Behavior of rotations                 *
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
 
      REAL      ACT4X4(4,4), EXP4X4(4,4), ROTANG
      REAL      ACT3X3(3,3), EXP3X3(3,3)
      LOGICAL   TRNSEQ
 
      CALL INITGL ('06.01.01/03')
 
C open PHIGS
      CALL XPOPPH  (ERRFIL, MEMUN)
      CALL SETMSG ('1 2 7', '<Rotate x> should return a correct '   //
     1             'representation for the transformation to '      //
     2             'rotate a 3D point counterclockwise around the ' //
     3             'x-axis by the specified number of radians.')
 
      ROTANG = 5.678
 
C  <Rotate x> with rotang returns act4x4 = actual array
      CALL PROX   (ROTANG, ERRIND, ACT4X4)
      CALL CHKINQ ('prox', ERRIND)
 
C  Compute exp4x4 = expected array
      CALL EROX   (ROTANG, EXP4X4)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 8', '<Rotate y> should return a correct '   //
     1             'representation for the transformation to '      //
     2             'rotate a 3D point counterclockwise around the ' //
     3             'y-axis by the specified number of radians.')
 
      ROTANG = -0.007373
 
C  <Rotate y> with rotang returns act4x4 = actual array
      CALL PROY   (ROTANG, ERRIND, ACT4X4)
      CALL CHKINQ ('proy', ERRIND)
 
C  Compute exp4x4 = expected array
      CALL EROY   (ROTANG, EXP4X4)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 9', '<Rotate z> should return a correct '   //
     1             'representation for the transformation to '      //
     2             'rotate a 3D point counterclockwise around the ' //
     3             'z-axis by the specified number of radians.')
 
      ROTANG = 8.52525
 
C  <Rotate z> with rotang returns act4x4 = actual array
      CALL PROZ   (ROTANG, ERRIND, ACT4X4)
      CALL CHKINQ ('proz', ERRIND)
 
C  Compute exp4x4 = expected array
      CALL EROZ   (ROTANG, EXP4X4)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(4, ACT4X4, EXP4X4))
 
      CALL SETMSG ('1 2 10', '<Rotate> should return a correct '    //
     1             'representation for the transformation to '      //
     2             'rotate a 2D point counterclockwise around the ' //
     3             'origin by the specified number of radians.')
 
      ROTANG = -11.1111
 
C  <Rotate> with rotang returns act3x3 = actual array
      CALL PRO    (ROTANG, ERRIND, ACT3X3)
      CALL CHKINQ ('pro', ERRIND)
 
C  Compute exp3x3 = expected array
      CALL ERO   (ROTANG, EXP3X3)
 
C  pass if matrices represent same transformation
      CALL IFPF   (TRNSEQ(3, ACT3X3, EXP3X3))
 
      CALL ENDIT
      END
