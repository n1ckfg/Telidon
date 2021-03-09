C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/08                           *
C  *    TEST TITLE : Miscellaneous tests of modelling      *
C  *                 clipping                              *
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
 
C modelling clipping operator
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)
 
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
 
C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
      INTEGER   HSSIZ, ASIZ,  IPL, NDPMCV, NOPL, NAVMCO, IDUM1
 
      REAL      A1(3,3), P1(3,3), P9(3,3), S2(3,3), R1(4,4), IDM(3,3)
      REAL      HS(6,1), A,B,C,D, PX,PY,PZ, INPTX(1),INPTY(1),INPTZ(1)
      REAL      OUTPTX(1),OUTPTY(1),OUTPTZ(1), UX,UY,UZ, HS2D(4,1)
      REAL      PI, U, NSDIST, XA(20),YA(20), ANGINC, RADIUS, ANG
 
      LOGICAL    SPHDIS

      PARAMETER (PI = 3.14159265)
 
      CHARACTER  EXPELM*5
 
      CALL INITGL ('06.01.02/08')
      CALL XPOPPH (ERRFIL, MEMUN)
 
      IF (.NOT. SPHDIS(123)) THEN
         CALL INMSG ('Skipping test because implementation '     //
     1               'apparently uses non-Euclidean metric for ' //
     2               'search distance.')
         GOTO 666
      ENDIF

C  Throughout, use incremental spatial search (ISS) to test the
C  effects of modelling clipping.
 
C  Set up structure #101
      CALL POPST (101)
 
C  In WC, polyline segment from (3,2) to (1,2) is clipped at 2,2 by
C  the MCV set up in element #2.
 
C  S2 = matrix for transformation to scale by 2 in x-direction
      CALL ESC (2.0, 1.0, S2)
      CALL PSGMT (S2)
 
C  2D half-space
      CALL SETRVS ('2,0, 2,1', HS2D, HSSIZ)
      CALL PSMCV (PMCREP, 1, HS2D)
 
C  P1 = matrix for transformation to shift by 1 in x-direction
      CALL ETR (1.0, 0.0, P1)
      CALL PSGMT (P1)
 
C  polyline coordinates
      CALL SETRVS ('2,0,2,0,2,0', XA, ASIZ)
      CALL SETRVS ('1,1,2,2,3,3', YA, ASIZ)
      CALL PPL (ASIZ, XA,YA)
 
C  R1 = matrix for random transformation
      DATA R1 / 0.7061, -0.2336,  0.2953, -0.2673,
     1         -0.2344,  0.8280, -0.2632, -0.2501,
     2          0.2709,  0.0524,  0.6326,  0.1435,
     3          0.3407,  0.3902,  0.1875,  1.2520 /
      CALL PSGMT3 (R1)
 
C  hsmcpt = half-space point in MC  = -1,0,1
C  hsmcvc = half-space vector in MC =  2,3,4
      CALL SETRVS ('-1,0,1,  2,3,4', HS, HSSIZ)
      CALL PSMCV3 (PMCREP, 1, HS)
 
C  P9 = matrix for transformation to shift by 9 in x-direction
      CALL ETR (9.0, 0.0, P9)
      CALL PSGMT (P9)
 
C  a,b,c,d = coefficients for WC boundary plane when R1 is applied
C  to the MC half-space defined by hsmcpt and hsmcvc.
      CALL TRANHS (HS, R1, A,B,C,D)
 
C  px,py,pz = the WC point where the line
C    x = a*u
C    y = b*u
C    z = 5
C  intersects the a*x + b*y + c*z + d = 0 plane
      U = ((-5*C) - D) / (A*A + B*B)
      PX = A*U
      PY = B*U
      PZ = 5.0
 
C  nsdist = nominal search distance
      NSDIST = 0.1
 
C  ux,uy,uz = unit vector parallel to a,b,c
      CALL VEC1 (A,B,C, UX,UY,UZ)
 
C  inpt = WC point inside volume
      INPTX(1) = PX + NSDIST * UX
      INPTY(1) = PY + NSDIST * UY
      INPTZ(1) = PZ + NSDIST * UZ
 
C  outpt = WC point outside volume
      OUTPTX(1) = PX - NSDIST * UX
      OUTPTY(1) = PY - NSDIST * UY
      OUTPTZ(1) = PZ - NSDIST * UZ
 
      CALL PPM3 (1, OUTPTX, OUTPTY, OUTPTZ)
      CALL PPM3 (1,  INPTX,  INPTY,  INPTZ)
      CALL PCLST
 
      CALL SETMSG ('15 17 18 40 42 43 49 57', 'When traversal '       //
     1             'causes different current modelling '              //
     2             'transformations to be applied in the generation ' //
     3             'of a polyline and a current MCV, the clipping '   //
     4             'should be performed relative to WC space.')
 
C  perform ISS with srp = (2-nsdist,2), clipping ON, starting at 101,0,
C    and sdist just below and above nsdist
C  pass/fail depending on (found path = first empty and then = 101,4)
      CALL ISSAB (2.0-NSDIST,2.0,0.0, NSDIST,
     1            '101,0', PCLIP, 1, '101,4')
 
      CALL SETMSG ('15 17 40 42 43 57', 'When traversal causes a '    //
     1             'perspective current modelling transformation to ' //
     2             'be applied in the generation of a current MCV, '  //
     3             'and a different current modelling '               //
     4             'transformation to be applied in the generation '  //
     5             'of a polymarker, the clipping should be '         //
     6             'performed relative to WC space.')
 
C  perform ISS with srp = outpt, clipping ON, starting at 101,0
C    and sdist just below and above 2*nsdist
C  pass/fail depending on (found path = first empty and then = 101,9)
      CALL ISSAB (OUTPTX(1),OUTPTY(1),OUTPTZ(1), 2*NSDIST,
     1            '101,0', PCLIP, 1, '101,9')
 
C  To test several boundary planes, set up a sequence of polymarkers
C  all on the unit circle, and arrange each clipping plane so as to
C  eliminate just one of them, by slicing off the edge of the
C  circle.  There will be only one polymarker left unclipped, and
C  this is the one to be found.
C
C  <inquire modelling clipping facilities> returns
C     ndpmcv = number of distinct planes for modelling clipping volume
      CALL PQMCLF (0, ERRIND, NDPMCV, NAVMCO, IDUM1)
      CALL CHKINQ ('pqmclf', ERRIND)
 
C  number of planes to be tested
      NOPL = MIN (50, NDPMCV)
 
C  angle increment
      ANGINC = (2*PI) / (NOPL + 1)
 
C  distance from origin of boundary planes
      RADIUS = (1 + COS(ANGINC)) / 2
      CALL SETRVS ('0,0,-1,0', HS2D, HSSIZ)
      HS2D (1,1) = RADIUS
 
C  A1  = matrix for transformation to rotate by anginc
      CALL ERO (ANGINC, A1)
 
C  idm = identity matrix
      CALL IDMAT (3, IDM)
 
C  Set up structure #102
      CALL POPST (102)
C  set up MCV to clip away all points except 1,0,0
      DO 210 IPL = 1,NOPL
         CALL PSLMT (A1, PCPRE)
         CALL PSMCV (PMCINT, 1, HS2D)
210   CONTINUE
      CALL PSLMT (IDM, PCREPL)
 
      DO 220 IPL = 1, NOPL+1
         ANG = ANGINC*IPL
         XA(1) = COS(ANG)
         YA(1) = SIN(ANG)
         CALL PPM (1, XA,YA)
220   CONTINUE
 
C  close structure #102
      CALL PCLST
 
      CALL SETMSG ('8 17 18 35 40 42 43 49 57', 'During traversal, ' //
     1             'it should be possible to construct the current ' //
     2             'MCV from as many half-spaces as are reported '   //
     3             'available by <inquire modelling clipping '       //
     4             'facilities>.')
 
C  expected element
      WRITE (EXPELM, '(I5)') 3*NOPL + 2
 
C  perform ISS with srp = 0,0, clipping ON, starting at 102,0
C    and sdist just below and above 1.0
C  pass/fail depending on (found path = first empty and then = 102,expelm)
      CALL ISSAB (0.0,0.0,0.0, 1.0, '102,0', PCLIP, 1,
     1            '102,' // EXPELM)
 
666   CONTINUE
      CALL ENDIT
      END
