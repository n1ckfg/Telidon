C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.06/02                           *
C  *    TEST TITLE : Appearance of fill area sets          *
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

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      REAL       Z,       H,       U,       PI
      PARAMETER (Z = 0.0, H = 0.5, U = 1.0, PI = 3.14159265)

      INTEGER    PICSTR, TXCI, IX, JX, RAN6(6), THIS
      INTEGER    NGSQ, RNDINT, NPTS, NSIZ, NUMEMP, TRUSIZ, TRULIS(6)
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,ENDPTS(10)

      REAL       XSIZ,YSIZ, XWINLO(6), YWINLO(6), NOMMS,MSCF, IDM(4,4)
      REAL       XA(10),YA(10),ZA(10), SIDER(6,3), XF(4,4)
      REAL       XB(10),YB(10),ZB(10), XMID,YMID, RAD, RNDRL
      REAL       XFA(4,4), XFB(4,4), XR(10), YR(10), ZR(10)
      REAL       RDUM1,RDUM2

C  sider = rotation amount for sides:
C    front,back,left,right,top,bottom
      DATA SIDER / 18*Z /

      CALL INITGL ('04.01.06/02')

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
C  use interior style HOLLOW throughout
      CALL PSIS (PHOLLO)

C  Divide screen up into 6 square labelled areas for all test cases
      CALL PEXST (106)
      CALL PEXST (102)
      CALL PCLST

C  set up structure 106 to label 6 windows
      CALL WIN6 (106, 2, XSIZ,YSIZ, XWINLO, YWINLO)
      CALL POPST (102)

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
 
C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
 
      CALL SETMSG ('1 4 7', 'A <fill area set> or <fill area set 3> ' //
     1             'subarea with fewer than three points should '     //
     2             'have no visual effect.')
 
C  random order for 1-6
      CALL RNPERM (6, RAN6)
C  number of empty squares
      NUMEMP = RNDINT(2,4)
      TRUSIZ = 0

      DO 100 IX = 1,6
         THIS = RAN6(IX)

C  set up points for fill areas and polymarkers
         DO 110 JX = 1,4
            XA(JX) = XWINLO(IX) + XSIZ * RNDRL(0.2,0.8)
            YA(JX) = YWINLO(IX) + YSIZ * RNDRL(0.2,0.8)
            ZA(JX) = RNDRL(0.0,1.0)
110      CONTINUE

         IF (THIS .GT. NUMEMP+1) THEN
C  draw a single dot polymarker in area #ix
            CALL PSMK (PPOINT)
            CALL PPM  (1, XA,YA)
         ELSEIF (THIS .EQ. NUMEMP+1) THEN
C  draw a single line segment in area #ix
            CALL PPL (2, XA,YA)
         ELSEIF (THIS .EQ. NUMEMP) THEN
C  draw a 2D fill area set with 0, 1, and 2 point subareas
            CALL SETVS ('1,1,3', ENDPTS, NSIZ)
            CALL PFAS  (NSIZ, ENDPTS, XA,YA)
         ELSEIF (THIS .EQ. NUMEMP-1) THEN
C  draw a two point 3D fill area set
            CALL SETVS ('2', ENDPTS, NSIZ)
            CALL PFAS3 (NSIZ, ENDPTS, XA,YA,ZA)
         ELSE
C  draw a 3D fill area set with 0, 1, and 2 point subareas
            CALL SETVS ('0,2,3', ENDPTS, NSIZ)
            CALL PFAS3 (NSIZ, ENDPTS, XA,YA,ZA)
         ENDIF
 
         IF (THIS .LE. NUMEMP) THEN
C  add to list of empty squares
            TRUSIZ = TRUSIZ+1
            TRULIS(TRUSIZ) = IX
         ENDIF
 
C  next ix
100   CONTINUE
 
      CALL DLSTPF ('DEGENERATE FILL AREA SETS: List all the empty ' //
     1             'squares (caution: some squares may contain a '  //
     2             'dot-polymarker).', TRUSIZ,TRULIS, 'S')
      CALL PEMST (102) 

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'A <fill area set> or <fill area set 3> '//
     1             'primitive with multiple vertices should be '     //
     2             'rendered as a collection of subareas.  Each '    //
     3             'subarea should be rendered by connecting the '   //
     4             'points in the order that the points are given '  //
     5             'in the point list.')

C  random order for 1-6
      CALL RNPERM (6,RAN6)
      RAD = 0.2 * XSIZ
      ENDPTS(1) = 5
      ENDPTS(2) = 9

      DO 200 IX = 1,6
         THIS = RAN6(IX)
         XMID = XWINLO(IX) + XSIZ/2
         YMID = YWINLO(IX) + YSIZ*2/3
C  coordinates for rectangle
         XR(1) = XMID - RAD
         YR(1) = YWINLO(IX) + YSIZ * 0.1
         XR(2) = XMID + RAD
         YR(2) = YR(1)
         XR(3) = XR(2)
         YR(3) = YWINLO(IX) + YSIZ * 0.3
         XR(4) = XR(1)
         YR(4) = YR(3)
         XR(5) = XR(1)
         YR(5) = YR(1)
         DO 205 JX=1,5
            ZR(JX) = 0.5*XR(JX) + 0.5*YR(JX)
205      CONTINUE

         DO 210 JX = 1,4
            XA(JX+5) = XR(JX)
            YA(JX+5) = YR(JX)
            ZA(JX+5) = ZR(JX)
210      CONTINUE

         IF (THIS .EQ. 1) THEN
C  use polylines to draw a 5 point star and a rectangle
            CALL ARCPTS (6, XMID,YMID,RAD, PI/2, 4*PI/5, XA,YA,ZA)
            CALL PPL (6, XA,YA)
            CALL PPL (5, XR,YR)
            NGSQ = IX
         ELSEIF (THIS .EQ. 2) THEN
C  draw 2D rectangle and pentagon, clockwise
            CALL ARCPTS (5, XMID,YMID,RAD, PI/2, -2*PI/5, XA,YA,ZA)
            CALL PFAS (2, ENDPTS, XA, YA)
         ELSEIF (THIS .EQ. 3) THEN
C  draw 2D rectangle and pentagon, counterclockwise
            CALL ARCPTS (5, XMID,YMID,RAD, PI/2,  2*PI/5, XA,YA,ZA)
            CALL PFAS (2, ENDPTS, XA, YA)
         ELSEIF (THIS .EQ. 4) THEN
C  draw 3D rectangle and pentagon, clockwise
            CALL ARCPTS (5, XMID,YMID,RAD, PI/2, -2*PI/5, XA,YA,ZA)
            CALL PFAS3 (2, ENDPTS, XA, YA, ZA)
         ELSE
C  draw 3D rectangle and pentagon, counterclockwise
            CALL ARCPTS (5, XMID,YMID,RAD, PI/2,  2*PI/5, XA,YA,ZA)
            CALL PFAS3 (2, ENDPTS, XA, YA, ZA)
         ENDIF

C  next ix
200   CONTINUE

      CALL DCHPFV ('ORDER OF VERTICES: Which square does NOT ' //
     1             'contain a closed rectangle and pentagon?', 6, NGSQ)
      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'The subareas with a list of more than ' //
     1             'two points in a <fill area set> or <fill area '  //
     2             'set 3> primitive should be rendered as closed '  //
     3             'polygonal areas.')

C  random order for 1-6
      CALL RNPERM (6,RAN6)
      RAD = 0.3 * XSIZ

      DO 300 IX = 1,6
         THIS = RAN6(IX)
         XMID = XWINLO(IX) + XSIZ/2
         YMID = YWINLO(IX) + YSIZ/2
         CALL ARCPTS (5, XMID,YMID,RAD, PI/2, 2*PI/5, XA,YA,ZA)
         XA(6) = XA(1)
         YA(6) = YA(1)
         ZA(6) = ZA(1)

         IF (THIS .EQ. 1) THEN
C  draw a pentagon with polylines and leave one side open
            CALL PPL (5, XA,YA)
            NGSQ = IX
         ELSEIF (THIS .EQ. 2) THEN
C  draw 3D pentagon with 6 points (explicit close, last=first point)
            ENDPTS(1) = 6
            CALL PFAS3 (1, ENDPTS, XA,YA,ZA)
         ELSEIF (THIS .EQ. 3) THEN
C  draw 2D pentagon with 6 points (explicit close, last=first point)
            ENDPTS(1) = 6
            CALL PFAS (1, ENDPTS, XA,YA)
         ELSEIF (THIS .EQ. 4) THEN
C  draw 2D pentagon with 5 points (implicit close)
            ENDPTS(1) = 5
            CALL PFAS (1, ENDPTS, XA,YA)
         ELSE
C  draw 3D pentagon with 5 points (implicit close)
            ENDPTS(1) = 5
            CALL PFAS3 (1, ENDPTS, XA,YA,ZA)
         ENDIF
C  next ix
300   CONTINUE

      CALL DCHPFV ('FILL AREA SET CLOSURE: Which pentagon is open?',
     1             6, NGSQ)
      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'The appearance of a <fill area set 3> ' //
     1             'primitive should reflect its 3D geometry after ' //
     2             'being transformed.')

C  which square will be marked wrong?
      NGSQ = RNDINT(1,6)
      CALL IDMAT (4,IDM)

C  set up fill area set with a triangle and a pentagon as subareas
C  with z = .5x + .5y
      XA(1) = 0.5
      YA(1) = 0.25
      XA(2) = 0.2
      YA(2) = 0.1
      XA(3) = 0.8
      YA(3) = 0.1

      NPTS = 5
      CALL ARCPTS (NPTS, H,0.65,0.3, PI/2, 2*PI/NPTS, XB,YB,ZB)

      DO 410 IX = 1,NPTS
         XA(IX+3) = XB(IX)
         YA(IX+3) = YB(IX)
410   CONTINUE

      DO 420 IX = 1,NPTS+3
         ZA(IX) = 0.5*XA(IX) + 0.5*YA(IX)
420   CONTINUE

      ENDPTS(1) = 3
      ENDPTS(2) = NPTS+3

      DO 400 IX = 1,6
C  rotate to view from side(ix) and move to window#ix
         CALL EBLTM3 (H,H,H, XWINLO(IX) + XSIZ/2 - H,
     1                       YWINLO(IX) + YSIZ/2 - H, Z,
     1        SIDER(IX,1), SIDER(IX,2), SIDER(IX,3), XSIZ,XSIZ,XSIZ, XF)
         CALL PSLMT3 (XF, PCREPL)
C  display the 3D fill area in square #ix
         CALL PFAS3 (2, ENDPTS, XA,YA,ZA)

C  reset to identity
         CALL PSLMT3 (IDM, PCREPL)
C  expected endpoints
         DO 430 JX = 1,NPTS+3
            CALL ETP3 (XA(JX),YA(JX),ZA(JX), XF, XB(JX),YB(JX),ZB(JX))
430      CONTINUE

         IF (IX .EQ. NGSQ) THEN
C  distort expected vertices - skip one
            JX = RNDINT(2, NPTS+2)
            XB(JX) = XB(NPTS+3)
            YB(JX) = YB(1)
         ENDIF
C  use 2D circle polymarker to mark expected vertices
         CALL PPM (NPTS+3, XB,YB)

C  next ix
400   CONTINUE

      CALL DCHPFV ('GEOMETRY OF 3D FILL AREA SETS: Which fill area '//
     1             'set does NOT have all its vertices circled?', 6,
     2             NGSQ)
      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 7', 'The appearance of a <fill area set> '   //
     1             'primitive should reflect its 2D geometry after ' //
     2             'being transformed.')

C  which square will be marked wrong?
      NGSQ = RNDINT(1,6)
      CALL IDMAT (4,IDM)

C  use same points for 2D
      DO 510 IX = 1,NPTS+3
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

C  display the 2D fill area in square #ix
         CALL PFAS (2, ENDPTS, XA,YA)
C  reset to identity
         CALL PSLMT3 (IDM, PCREPL)
C  expected endpoints
         DO 520 JX = 1,NPTS+3
            CALL ETP3 (XA(JX),YA(JX),ZA(JX), XF, XB(JX),YB(JX),ZB(JX))
520      CONTINUE

         IF (IX .EQ. NGSQ) THEN
C  distort expected vertices
            JX = RNDINT(2, NPTS+2)
            XB(JX) = XB(NPTS+3)
            YB(JX) = YB(1)
         ENDIF
C  use 2D circle polymarker to mark expected vertices
         CALL PPM (NPTS+3, XB,YB)

C  next ix
500   CONTINUE

      CALL DCHPFV ('GEOMETRY OF 2D FILL AREA SETS: Which fill area ' //
     1             'does NOT have all its vertices circled?', 6, NGSQ)
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
