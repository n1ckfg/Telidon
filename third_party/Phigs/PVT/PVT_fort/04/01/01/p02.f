C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.01/02                           *
C  *    TEST TITLE : Appearance of polylines               *
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

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      REAL       Z,       H,       U,       PI
      PARAMETER (Z = 0.0, H = 0.5, U = 1.0, PI = 3.14159265)

      INTEGER    PICSTR, TXCI, IX, JX, RAN6(6), THIS
      INTEGER    TRUSIZ,TRULIS(6), NGSQ, RNDINT, OPENSD, NPTS
      INTEGER    XPERM(10), YPERM(10), ZPERM(10), T1,T2, NUMEMP
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4

      REAL       XSIZ,YSIZ, XWINLO(6), YWINLO(6), NOMMS,MSCF, IDM(4,4)
      REAL       XA(10),YA(10),ZA(10), RNDRL, SIDER(6,3), XF(4,4)
      REAL       XB(10),YB(10),ZB(10), XMID,YMID, RAD, ANG1,ANG2, OPX
      REAL       XFA(4,4), XFB(4,4)
      REAL       RDUM1,RDUM2

      LOGICAL    T1SAME,T2SAME

C  sider = rotation amount for sides:
C    front,back,left,right,top,bottom

      DATA SIDER / 18*Z /

      CALL INITGL ('04.01.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  default attributes
      CALL PSLWSC (0.0)
C  adjust polymarker size
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
C  set marker size WC
      MSCF = .02 / (NOMMS*WCPDC)
      CALL PSMKSC (MSCF)
      CALL PSMK   (POMARK)
      CALL PSPMCI (3)

C  Divide screen up into 6 square labelled areas for all test cases
      CALL PEXST (106)
      CALL PEXST (102)
      CALL PCLST

C  set up rotations for viewing from 6 sides
C  back - Y-axis
      SIDER(2,2) = PI
C  left - Y-axis
      SIDER(3,2) = 0.5*PI
C  right - Y-axis
      SIDER(4,2) = 1.5*PI
C  top - X-axis
      SIDER(5,1) = 0.5*PI
C  bottom - X-axis
      SIDER(6,1) = 1.5*PI

C  set up structure 106 to label 6 windows
      CALL WIN6 (106, 2, XSIZ,YSIZ, XWINLO, YWINLO)
      CALL POPST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'A <polyline> or <polyline 3> primitive ' //
     1             'with fewer than two points should have no '       //
     2             'visual effect.')

C  random order for 1-6
      CALL RNPERM (6, RAN6)
C  number of empty squares
      NUMEMP = RNDINT(2,4)
      TRUSIZ = 0
      DO 100 IX = 1,6
         XA(1) = XWINLO(IX) + XSIZ * RNDRL(0.2,0.8)
         YA(1) = YWINLO(IX) + YSIZ * RNDRL(0.2,0.8)
         THIS = RAN6(IX)

         IF (THIS .GT. NUMEMP+1) THEN
C  draw a single dot polymarker in area #ix
            CALL PSMK (PPOINT)
            CALL PPM  (1, XA,YA)
         ELSEIF (THIS .EQ. NUMEMP+1) THEN
C  draw a single cross polymarker in area #ix
            CALL PSMK (PXMARK)
            CALL PPM  (1, XA,YA)
         ELSEIF (THIS .EQ. NUMEMP) THEN
C  draw a single point 2D polyline in area #ix
            CALL PPL (1, XA,YA)
            TRUSIZ = TRUSIZ+1
            TRULIS(TRUSIZ) = IX
         ELSE
C  draw a single point 3D polyline in area #ix
            ZA(1) = 0.5
            CALL PPL3 (1, XA,YA,ZA)
            TRUSIZ = TRUSIZ+1
            TRULIS(TRUSIZ) = IX
         ENDIF
C  next ix
100   CONTINUE

      CALL DLSTPF ('DEGENERATE POLYLINES: List all the empty '     //
     1             'squares (caution: some squares may contain a ' //
     2             'dot-polymarker).', TRUSIZ,TRULIS, 'S')
      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'A <polyline> or <polyline 3> primitive ' //
     1             'with two points should be rendered as a single '  //
     2             'straight line segment connecting those points.')

C  which square will be marked wrong?
      NGSQ = RNDINT(1,6)
      CALL IDMAT (4,IDM)

      DO 200 IX = 1,6
C  rotate to view from side(ix) and move to window#ix
         CALL EBLTM3 (H,H,H, XWINLO(IX) + XSIZ/2 - H,
     1                       YWINLO(IX) + YSIZ/2 - H, Z,
     1        SIDER(IX,1), SIDER(IX,2), SIDER(IX,3), XSIZ,XSIZ,XSIZ, XF)
         CALL PSLMT3 (XF, PCREPL)

C  get some distinct endpoints
         DO 210 JX = 1,2
            XA(JX) = 0.5*JX - RNDRL(0.1,0.4)
            YA(JX) = 0.5*JX - RNDRL(0.1,0.4)
            ZA(JX) = 0.5*JX - RNDRL(0.1,0.4)
210      CONTINUE

         IF (IX .LE. 2) THEN
C  draw two-point 2D polyline in square #ix - will stay in cube,
C  even though drawn in plane z=0.
            CALL PPL (2, XA,YA)
         ELSE
C  draw two-point 3D polyline in square #ix
            CALL PPL3 (2, XA,YA,ZA)
         ENDIF

C  reset to identity
         CALL PSLMT3 (IDM, PCREPL)
C  expected endpoints
         CALL ETP3 (XA(1),YA(1),ZA(1), XF,  XB(1),YB(1),ZB(1))
         CALL ETP3 (XA(2),YA(2),ZA(2), XF,  XB(2),YB(2),ZB(2))
         IF (IX .EQ. NGSQ) THEN
C  mark expected vertices inaccurately
            XB(1) = 0.9*XB(1) + 0.1*XB(2)
            YB(1) = 0.9*YB(1) + 0.1*YB(2)
         ENDIF
         CALL PPM (2, XB,YB)
C  next ix
200   CONTINUE

      CALL DCHPFV ('TWO-POINT POLYLINES: Which square contains ' //
     1             'something other than a single line segment ' //
     2             'with two circled endpoints?', 6, NGSQ)
      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'A <polyline> or <polyline 3> primitive ' //
     1             'with a list of more than two points should be '   //
     2             'rendered by connecting each pair of adjacent '    //
     3             'points by a single straight line segment.')

C  side of pentagon to leave open
      OPENSD = RNDINT(1,5)
C  random order for 1-6
      CALL RNPERM (6,RAN6)
      RAD = 0.3 * XSIZ

      DO 300 IX = 1,6
         THIS = RAN6(IX)
         XMID = XWINLO(IX) + XSIZ/2
         YMID = YWINLO(IX) + YSIZ/2
         IF (THIS .LE. 2) THEN
C  draw 2D pentagon with open side = opensd, using one
C  polyline for each segment
            ANG1 = 0.4*PI*OPENSD
            XA(1) = XMID + RAD * SIN(ANG1)
            YA(1) = YMID + RAD * COS(ANG1)
            DO 310 JX = OPENSD+1, OPENSD+4
               ANG2 = 0.4*PI*JX
               XA(2) = XMID + RAD * SIN(ANG2)
               YA(2) = YMID + RAD * COS(ANG2)
               CALL PPL (2,XA,YA)
               ANG1 = ANG2
               XA(1) = XA(2)
               YA(1) = YA(2)
310         CONTINUE
         ELSE
C  draw 3D pentagon with open side = opensd, using one
C  polyline for whole figure
            OPX = OPENSD
C  if ix=6, draw pentagon with open side not= opensd
            IF (THIS .EQ. 6) OPX = OPX+1
            DO 320 JX = 0,4
               ANG1 = 0.4*PI* (JX+OPX)
               XA(JX+1) = XMID + RAD * SIN(ANG1)
               YA(JX+1) = YMID + RAD * COS(ANG1)
               ZA(JX+1) = RNDRL(0.1,0.9)
320         CONTINUE
            CALL PPL3 (5,XA,YA,ZA)
         ENDIF

C  next ix
300   CONTINUE

      CALL DCHPF ('MULTI-POINT POLYLINES: Which pentagon is open ' //
     1            'on a different side?', 6,6, RAN6)
      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'The appearance of a <polyline 3> '      //
     1             'primitive should reflect its 3D geometry after ' //
     2             'being transformed.')

C  which square will be marked wrong?
      NGSQ = RNDINT(1,6)
      CALL IDMAT (4,IDM)

C  generate 3D list of points distinct from any side for 3D polyline
      NPTS = 7
      CALL RNPERM (NPTS, XPERM)
      CALL RNPERM (NPTS, YPERM)
      CALL RNPERM (NPTS, ZPERM)
      DO 410 IX = 1,NPTS
         XA(IX) = (XPERM(IX)-0.5) / NPTS
         YA(IX) = (YPERM(IX)-0.5) / NPTS
         ZA(IX) = (ZPERM(IX)-0.5) / NPTS
410   CONTINUE

      DO 400 IX = 1,6
C  rotate to view from side(ix) and move to window#ix
         CALL EBLTM3 (H,H,H, XWINLO(IX) + XSIZ/2 - H,
     1                       YWINLO(IX) + YSIZ/2 - H, Z,
     1        SIDER(IX,1), SIDER(IX,2), SIDER(IX,3), XSIZ,XSIZ,XSIZ, XF)
         CALL PSLMT3 (XF, PCREPL)

C  display the 3D polyline in square #ix
         CALL PPL3 (NPTS, XA,YA,ZA)

C  reset to identity
         CALL PSLMT3 (IDM, PCREPL)
C  expected endpoints
         DO 420 JX = 1,NPTS
            CALL ETP3 (XA(JX),YA(JX),ZA(JX), XF, XB(JX),YB(JX),ZB(JX))
420      CONTINUE

         IF (IX .EQ. NGSQ) THEN
C  distort expected vertices - skip one
            JX = RNDINT(2, NPTS-1)
            XB(JX) = XB(NPTS)
            YB(JX) = YB(1)
         ENDIF
C  use 2D circle polymarker to mark expected vertices
         CALL PPM (NPTS, XB,YB)

C  next ix
400   CONTINUE

      CALL DCHPFV ('GEOMETRY OF 3D POLYLINES: Which polyline does ' //
     1             'NOT have all its vertices circled?', 6, NGSQ)
      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'The appearance of a <polyline> '  //
     1             'primitive should reflect its 2D geometry ' //
     2             'after being transformed.')

C  which square will be marked wrong?
      NGSQ = RNDINT(1,6)
      CALL IDMAT (4,IDM)

C  generate 2D list of points distinct from any side for 2D polyline
      NPTS = 4
550   CONTINUE
      CALL RNPERM (NPTS, XPERM)
      CALL RNPERM (NPTS, YPERM)
C  avoid linearity ...
      T1 = XPERM(1) + YPERM(1)
      T2 = XPERM(1) - YPERM(1)
      T1SAME = .TRUE.
      T2SAME = .TRUE.
      DO 540 IX = 2,NPTS
         IF (T1 .NE. XPERM(IX) + YPERM(IX)) T1SAME = .FALSE.
         IF (T2 .NE. XPERM(IX) - YPERM(IX)) T2SAME = .FALSE.
540   CONTINUE
      IF (T1SAME .OR. T2SAME) GOTO 550

      DO 510 IX = 1,NPTS
         XA(IX) = (XPERM(IX)-0.5) / NPTS
         YA(IX) = (YPERM(IX)-0.5) / NPTS
         ZA(IX) = Z
510   CONTINUE

      DO 500 IX = 1,6
C  rotate 45 degrees around x and y axis into unit cube to show
C  z-values, then rotate to view from side(ix)
C  45 degrees:
         CALL EBLTM3 (H,H,Z, Z,Z,H, PI/4,PI/4,Z, U,U,U, XFA)
C  rotate to view from side(ix) and move to window#ix
         CALL EBLTM3 (H,H,H, XWINLO(IX) + XSIZ/2 - H,
     1                       YWINLO(IX) + YSIZ/2 - H, Z,
     1        SIDER(IX,1),SIDER(IX,2),SIDER(IX,3), XSIZ,XSIZ,XSIZ, XFB)
         CALL ECOM3 (XFB,XFA, XF)
         CALL PSLMT3 (XF, PCREPL)

C  display the 2D polyline in square #ix
         CALL PPL (NPTS, XA,YA)

C  reset to identity
         CALL PSLMT3 (IDM, PCREPL)
C  expected endpoints
         DO 520 JX = 1,NPTS
            CALL ETP3 (XA(JX),YA(JX),ZA(JX), XF, XB(JX),YB(JX),ZB(JX))
520      CONTINUE

         IF (IX .EQ. NGSQ) THEN
C  distort expected vertices
            JX = RNDINT(2, NPTS-1)
            XB(JX) = XB(NPTS)
            YB(JX) = YB(1)
         ENDIF
C  use 2D circle polymarker to mark expected vertices
         CALL PPM (NPTS, XB,YB)

C  next ix
500   CONTINUE

      CALL DCHPFV ('GEOMETRY OF 2D POLYLINES: Which polyline does ' //
     1             'NOT have all its vertices circled?', 6, NGSQ)
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
