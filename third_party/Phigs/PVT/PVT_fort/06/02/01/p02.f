C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.01/02                           *
C  *    TEST TITLE : Behavior of 3D mapping                *
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
 
C  Declare program-specific variables
      REAL       VWWNLM(4), PJVPLM(6), VWMPMT(4,4)
      REAL       PRP(3), VPD,BPD,FPD, VWCENT(3)
      INTEGER    PJTYPE
 
C viewtype
      INTEGER    PPARL,     PPERS
      PARAMETER (PPARL = 0, PPERS = 1)
 
      CALL INITGL ('06.02.01/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  Set 3D mapping parameters for PARALLEL projection:
      VWWNLM(1) = -462.27
      VWWNLM(2) = -80.95
      VWWNLM(3) = -4891.85
      VWWNLM(4) = -94.78
 
      PJVPLM(1) = 0.2640
      PJVPLM(2) = 0.4082
      PJVPLM(3) = 0.01339
      PJVPLM(4) = 0.7457
      PJVPLM(5) = 0.1395
      PJVPLM(6) = 0.30036
 
      PJTYPE = PPARL
 
      PRP(1) = -15.044
      PRP(2) = 1.318
      PRP(3) = 34.873
      VPD = -1.213
      BPD = -3.311
      FPD = 15.332
 
      CALL SETMSG ('1 2 7 8 9', '<Evaluate view mapping matrix 3> '   //
     1             'should map the corners of the view volume to '    //
     2             'the corresponding corners of the projection '     //
     3             'viewport for a PARALLEL projection.')
C subroutine TSTCOR performs pass/fail test
      CALL TSTCOR  (VWWNLM, PJVPLM, PJTYPE, PRP, VPD,BPD,FPD,
     1              VWMPMT, VWCENT)
 
      CALL SETMSG ('1 2 10', '<Evaluate view mapping matrix 3> '      //
     1             'should map any two points on a given projector '  //
     2             'to the same x and y values in NPC space for a '   //
     3             'PARALLEL projection.')
C subroutine TSTPRJ performs pass/fail test
      CALL TSTPRJ (PRP, VWMPMT, VWCENT)
 
C  Set 3D mapping parameters for PERSPECTIVE projection:
      VWWNLM(1) = -62.2236
      VWWNLM(2) = -11.39577
      VWWNLM(3) = -60.530
      VWWNLM(4) =  24.255
 
      PJVPLM(1) = 0.10639
      PJVPLM(2) = 0.22243
      PJVPLM(3) = 0.10012
      PJVPLM(4) = 0.15392
      PJVPLM(5) = 0.24695
      PJVPLM(6) = 0.88262
 
      PJTYPE = PPERS
 
      PRP(1) = -3.6054E-02
      PRP(2) = 2.1181E-03
      PRP(3) = 3.0569
 
      VPD = 0.16487
      BPD = -5.2858E-03
      FPD = 3.0531
 
      CALL SETMSG ('1 2 7 8 9', '<Evaluate view mapping matrix 3> '   //
     1             'should map the corners of the view volume to '    //
     2             'the corresponding corners of the projection '     //
     3             'viewport for a PERSPECTIVE projection.')
C subroutine TSTCOR performs pass/fail test
      CALL TSTCOR  (VWWNLM, PJVPLM, PJTYPE, PRP, VPD,BPD,FPD,
     1              VWMPMT, VWCENT)
 
      CALL SETMSG ('1 2 10', '<Evaluate view mapping matrix 3> '      //
     1             'should map any two points on a given projector '  //
     2             'to the same x and y values in NPC space for a '   //
     3             'PERSPECTIVE projection.')
C subroutine TSTPRJ performs pass/fail test
      CALL TSTPRJ (PRP, VWMPMT, VWCENT)
 
 
C  Set 3D mapping parameters for PARALLEL projection, with flat
C  viewport (ZMIN = ZMAX):
      VWWNLM(1) = -2.6073
      VWWNLM(2) = 231.673
      VWWNLM(3) = 830.654
      VWWNLM(4) = 4.74075E+4
 
      PJVPLM(1) = 0.30322
      PJVPLM(2) = 0.54641
      PJVPLM(3) = 0.28099
      PJVPLM(4) = 0.68383
      PJVPLM(5) = 6.0076E-03
      PJVPLM(6) = 6.0076E-03
 
      PJTYPE = PPARL
 
      PRP(1) = 3.8497
      PRP(2) = 72.490
      PRP(3) = -111.363
      VPD = -0.38069
      BPD = -0.46296
      FPD = -4.25281E-02
 
      CALL SETMSG ('1 2 7 8 9', '<Evaluate view mapping matrix 3> '   //
     1             'should map the corners of the view volume to '    //
     2             'the corresponding corners of a flat projection '  //
     3             'viewport for a PARALLEL projection.')
C subroutine TSTCOR performs pass/fail test
      CALL TSTCOR  (VWWNLM, PJVPLM, PJTYPE, PRP, VPD,BPD,FPD,
     1              VWMPMT, VWCENT)
 
      CALL SETMSG ('1 2 10', '<Evaluate view mapping matrix 3> '      //
     1             'should map any two points on a given projector '  //
     2             'to the same x and y values in NPC space for a '   //
     3             'flat projection viewport and a PARALLEL '         //
     4             'projection.')
C subroutine TSTPRJ performs pass/fail test
      CALL TSTPRJ (PRP, VWMPMT, VWCENT)
 
C  Set 3D mapping parameters for PERSPECTIVE projection, with a flat
C  viewport (ZMIN = ZMAX) and view volume (BPD = FPD):
      VWWNLM(1) = -13.7
      VWWNLM(2) =  71.55
      VWWNLM(3) = -51.5509
      VWWNLM(4) =  79.861
 
      PJVPLM(1) = 0.15580
      PJVPLM(2) = 0.537
      PJVPLM(3) = 1.7186E-03
      PJVPLM(4) = 0.3148
      PJVPLM(5) = 0.73940
      PJVPLM(6) = 0.73940
 
      PJTYPE = PPERS
 
      PRP(1) = -1.8005
      PRP(2) = -4.19006E-02
      PRP(3) =  6.3462
 
      VPD = 0.831
      BPD = -2.1753
      FPD = -2.1753
 
      CALL SETMSG ('1 2 7 8 9', '<Evaluate view mapping matrix 3> '   //
     1             'should map the corners of a flat view volume to ' //
     2             'the corresponding corners of a flat projection '  //
     3             'viewport for a PERSPECTIVE projection.')
C subroutine TSTCOR performs pass/fail test
      CALL TSTCOR  (VWWNLM, PJVPLM, PJTYPE, PRP, VPD,BPD,FPD,
     1              VWMPMT, VWCENT)
 
      CALL SETMSG ('1 2 10', '<Evaluate view mapping matrix 3> '      //
     1             'should map any two points on a given projector '  //
     2             'to the same x and y values in NPC space for a '   //
     3             'flat view volume, a flat projection viewport, '   //
     4             'and a PERSPECTIVE projection.')
C subroutine TSTPRJ performs pass/fail test
      CALL TSTPRJ (PRP, VWMPMT, VWCENT)
 
666   CONTINUE
      CALL ENDIT
      END
