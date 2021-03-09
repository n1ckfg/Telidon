C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.01/05                           *
C  *    TEST TITLE : Behavior of transformation of points  *
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
 
      REAL      A4(4,4), A3(3,3), PX,PY,PZ, ACTTPX,ACTTPY,ACTTPZ
      REAL      EXPTPX,EXPTPY,EXPTPZ, ABSERR, RELERR
      LOGICAL   APPEQ
 
      CALL INITGL ('06.01.01/05')
 
C open PHIGS
      CALL XPOPPH  (ERRFIL, MEMUN)
 
C set up tolerance: absolute/relative error
      ABSERR = 1.0E-7
      RELERR = 1.0E-5
 
      CALL SETMSG ('1 2 13', '<Transform point 3> should return ' //
     1             'the 3D point resulting from applying the '    //
     2             'specified transformation matrix to the '      //
     3             'specified point.')
 
C set up transform
      A4(1,1) = -2.2
      A4(1,2) = 3.3
      A4(1,3) = 4.4
      A4(1,4) = 5.5
      A4(2,1) = 0.0023
      A4(2,2) = -727.12
      A4(2,3) = 2.09
      A4(2,4) = 33.33
      A4(3,1) = 0
      A4(3,2) = 34
      A4(3,3) = 54.1
      A4(3,4) = -0.045
      A4(4,1) = 7
      A4(4,2) = 6
      A4(4,3) = 5
      A4(4,4) = 4
 
C initialize point to be transformed
      PX = -262.27
      PY = 0.02525
      PZ = 53.838
 
C compute actual transformed point
      CALL PTP3  (PX,PY,PZ, A4, ERRIND, ACTTPX,ACTTPY,ACTTPZ)
      CALL CHKINQ ('ptp3', ERRIND)
 
C  Compute expected point
      CALL ETP3  (PX,PY,PZ, A4, EXPTPX,EXPTPY,EXPTPZ)
 
C Pass iff points are approximately equal
      CALL IFPF ( APPEQ(ACTTPX, EXPTPX, ABSERR, RELERR) .AND.
     1            APPEQ(ACTTPY, EXPTPY, ABSERR, RELERR) .AND.
     2            APPEQ(ACTTPZ, EXPTPZ, ABSERR, RELERR) )
 
      CALL SETMSG ('1 2 14', '<Transform point> should return the '  //
     1             '2D point resulting from applying the specified ' //
     2             'transformation matrix to the specified point.')
 
      A3(1,1) = -2.2
      A3(1,2) = 3.3
      A3(1,3) = 5.5
      A3(2,1) = 0.0023
      A3(2,2) = -727.12
      A3(2,3) = 33.33
      A3(3,1) = 0
      A3(3,2) = 34
      A3(3,3) = -0.045
 
C initialize point to be transformed
      PX = -262.27
      PY = 53.838
 
C compute actual transformed point
      CALL PTP  (PX,PY, A3, ERRIND, ACTTPX,ACTTPY)
      CALL CHKINQ ('ptp', ERRIND)
 
C  Compute expected point
      CALL ETP  (PX,PY, A3, EXPTPX,EXPTPY)
 
C Pass iff points are approximately equal
      CALL IFPF ( APPEQ(ACTTPX, EXPTPX, ABSERR, RELERR) .AND.
     1            APPEQ(ACTTPY, EXPTPY, ABSERR, RELERR) )
 
      CALL ENDIT
      END
