C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.01/01                           *
C  *    TEST TITLE : Behavior of orientation utilities     *
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
 
      REAL       VWRX, VWRY, VWRZ, VPNX, VPNY, VPNZ, VUPX, VUPY, VUPZ
      REAL       ACT4X4(4,4), EXP4X4(4,4), ACT3X3(3,3), EXP3X3(3,3)
 
      LOGICAL    TRNSEQ
 
      CHARACTER  MSG*300
 
      CALL INITGL ('06.02.01/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('1 2 3 4', '<Evaluate view orientation matrix 3> ' //
     1             'should return a correct representation for the '  //
     2             'transformation to change 3D WC coordinates to '   //
     3             '3D VRC coordinates.')
 
C  Set 3D orientation parameters (all WC x-y-z):
C    VRP (view reference point) :  -3.24, 37.727,  11.2
C    VPN (view plane normal)    :  62.21, 45.67,  -25.98
C    VUP (view up vector)       : -23.32,  6.868,  -2.22
      VWRX = -3.24
      VWRY = 37.727
      VWRZ = 11.2
      VPNX = 62.21
      VPNY = 45.67
      VPNZ = -25.98
      VUPX = -23.32
      VUPY =  6.868
      VUPZ = -2.22
 
C  <Evaluate view orientation matrix 3> returns act4x4 = actual array
      CALL PEVOM3 (VWRX,VWRY,VWRZ, VPNX,VPNY,VPNZ, VUPX,VUPY,VUPZ,
     1             ERRIND, ACT4X4)
      IF (ERRIND .EQ. 0) THEN
C  Compute exp4x4 = expected array
         CALL EEVOM3 (VWRX,VWRY,VWRZ, VPNX,VPNY,VPNZ, VUPX,VUPY,VUPZ,
     1                EXP4X4)
         CALL IFPF (TRNSEQ (4, ACT4X4, EXP4X4))
      ELSE
         CALL FAIL
         WRITE (MSG,'(A,I5)') 'PEVOM3 failed with error code = ', ERRIND
         CALL INMSG (MSG)
      ENDIF
 
      CALL SETMSG ('1 2 5 6', '<Evaluate view orientation matrix> '   //
     1             'should return a correct representation for the '  //
     2             'transformation to change 2D WC coordinates to '   //
     3             '2D VRC coordinates.')
 
C  Set 2D orientation parameters (all WC x-y):
C    VRP (view reference point) :  -3.24, 37.727
C    VUP (view up vector)       : -23.32,  0.041
      VWRX = -3.24
      VWRY = 37.727
      VUPX = -23.32
      VUPY = 0.041
 
C  <Evaluate view orientation matrix> returns act3x3 = actual array
      CALL PEVOM (VWRX,VWRY, VUPX,VUPY, ERRIND, ACT3X3)
      IF (ERRIND .EQ. 0) THEN
C  Compute exp3x3 = expected array
         CALL EEVOM (VWRX,VWRY, VUPX,VUPY, EXP3X3)
         CALL IFPF (TRNSEQ (3, ACT3X3, EXP3X3))
      ELSE
         CALL FAIL
         WRITE (MSG,'(A,I5)') 'PEVOM failed with error code = ', ERRIND
         CALL INMSG (MSG)
      ENDIF
 
666   CONTINUE
      CALL ENDIT
      END
