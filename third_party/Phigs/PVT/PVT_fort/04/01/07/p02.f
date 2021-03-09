C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.07/02                           *
C  *    TEST TITLE : Appearance of cell arrays             *
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
 
C Aspect source
C                BUNDLED     INDIVIDUAL
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
 
C Marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)
 
C Composition type
C                PRECONCATENATE  POSTCONCATENATE  REPLACE
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
C Regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)
 
C Colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
 
C Type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)
 
      INTEGER XDIM, YDIM, CSIZ
      PARAMETER(XDIM = 5, YDIM = 5, CSIZ = 3)
 
      REAL       Z,       H,       U,      PI
      PARAMETER (Z = 0.0, H = 0.5, U = 1.0, PI = 3.14159265)
 
      INTEGER    PICSTR, TXCI, IY, IX, IDUM1, IDUM2, IDUM3, IDUM4
      INTEGER    COLIA(XDIM, YDIM), NGCA, DX, DY, NUMCI, IARFND
      INTEGER    NOCOLS, ARRLEN(XDIM),RNDINT, NCOLOR, NGCOL, CORCOL
      INTEGER    NCLS, LSIZ, LCOLS(5), OFFSET, TESID
      INTEGER    THIS, PERM(6), UNDF(3), LINECL, MARKCL, COLLOC
      INTEGER    IROW,ICOL, X1,Y1, CELX,CELY
 
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ)
      REAL       XSIZ, YSIZ, XWINLO(6), YWINLO(6), NOMMS, MSCF
      REAL       XPTS(4), YPTS(4), ZPTS(4), RNDRL
      REAL       XA(4),YA(4),XF(3,3), XF3D(4,4)
      REAL       PX,QX, ANG, QANG, RANG, PY, QY, RNDNUM, DIAGSZ
      REAL       ROWX,ROWY, COLX,COLY, CENTX,CENTY
      REAL       RADCIR, XDIAG(2), YDIAG(2), ZDIAG(2)
      REAL       RDUM1, RDUM2
 
      LOGICAL    DYN, SOLIDC
 
      DATA TESID / 102 /
 
      CALL INITGL ('04.01.07/02')
 
      CALL XPOPPH (ERRFIL, MEMUN)
C Set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      SOLIDC = DYN ('Are the cells of a cell array on this '       //
     1              'workstation displayed using the color index ' //
     2              'from the specified array?')
 
      CALL POPST (PICSTR)
C  By convention, view #1 is for picture
      CALL PSVWI (1)
C  Use individual attributes
      CALL SETASF (PINDIV)
 
C  Default attributes
      LINECL = 1
      MARKCL = 2
 
C  Adjust polymarker size
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
 
C  Set marker size and color
      MSCF = .02 / (NOMMS*WCPDC)
      CALL PSMKSC (MSCF)
      CALL PSMK   (POMARK)
      CALL PSPMCI (MARKCL)
 
C  Adjust polyline width
      CALL PQPLF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqplf', ERRIND)
 
C  Set line size and color
      MSCF = .01 / (NOMMS*WCPDC)
      CALL PSLWSC (MSCF)
      CALL PSPLCI (LINECL)
 
C  Divide screen up into 6 square labelled areas for all test cases
      CALL PEXST (106)
      CALL PEXST (TESID)
      CALL PCLST
 
C  Set up structure 106 to label 6 windows
      CALL WIN6 (106, 2, XSIZ,YSIZ, XWINLO, YWINLO)
 
C  *** *** *** *** ***   CELL ARRAY 3D    *** *** *** *** ***
 
      CALL SETMSG ('4 14', 'A <cell array 3> should be rendered as '  //
     1             'a parallelogram with the specified points P, Q, ' //
     2             'and R as vertices.')
 
C  NGCA = no-good cell array: random integer from 1 to 6
      NGCA = RNDINT (1,6)
 
C  Radius of circle for cell array corners
      RADCIR = 0.3
 
C  5x5 checkerboard 2d array, using 1 and 0 only
 
      CALL SET2D ('1,0,1,0,1/' //
     1            '0,1,0,1,0/' //
     2            '1,0,1,0,1/' //
     3            '0,1,0,1,0/' //
     4            '1,0,1,0,1/',
     5            XDIM, NOCOLS, ARRLEN, COLIA)
 
C  Open test structure
      CALL POPST (TESID)
 
      DO 10 IX = 1,6
 
C  Scale 0:1,0:1 into window #ix
         CALL EBLTM (Z,Z, XWINLO(IX), YWINLO(IX), Z, XSIZ,YSIZ, XF)
         CALL PSLMT (XF, PCREPL)
 
C  find random points on circle for P,Q,R of cell array
         ANG = RNDRL (0., 360.0) * (2*PI/360)
 
         XPTS(1) = 0.5 + RADCIR * COS(ANG)
         YPTS(1) = 0.5 + RADCIR * SIN(ANG)
 
         OFFSET = 2 * RNDINT(0,1) - 1
         QANG    = ANG + OFFSET * ( RNDRL(75.0 ,105.0 ) * (2*PI/360))
         RANG    = ANG - OFFSET * ( RNDRL(75.0 ,105.0 ) * (2*PI/360))
         XPTS(2) = 0.5 + RADCIR * COS(QANG)
         YPTS(2) = 0.5 + RADCIR * SIN(QANG)
         XPTS(3) = 0.5 + RADCIR * COS(RANG)
         YPTS(3) = 0.5 + RADCIR * SIN(RANG)
 
20       CONTINUE
         ZPTS(1) = RNDRL( 0.0, 1.0)
         ZPTS(2) = RNDRL( 0.0, 1.0)
         ZPTS(3) = RNDRL( 0.0, 1.0)
         IF ( ( ZPTS(2) + ZPTS(3) - ZPTS(1) .LT. 0)    .OR.
     1        ( ZPTS(2) + ZPTS(3) - ZPTS(1) .GT. 1) )  GOTO 20
 
C   Draw cell array 3, using
C      P,Q,R = (PX,PY,PZ), (QX,QY,QZ), (RX,RY,RZ) ,COLIA(1:DX, 1:DY)
         CALL PCA3 (XPTS,YPTS,ZPTS, XDIM,YDIM, 1,1, 5,5, COLIA)
 
         DO 30 IY = 1,3
            XA(IY) = XPTS(IY)
            YA(IY) = YPTS(IY)
30       CONTINUE
 
C Mark vertices
         IF (IX .EQ. NGCA) THEN
C compute incorrect location
            XA(4) = XA(1) + 1.1 * (XA(2) + XA(3) - 2*XA(1))
            YA(4) = YA(1) + 1.1 * (YA(2) + YA(3) - 2*YA(1))
         ELSE
            XA(4) =  XA(2) + XA(3) - XA(1)
            YA(4) =  YA(2) + YA(3) - YA(1)
         ENDIF
 
C Mark vertices with a circle
         CALL PPM (4, XA, YA)
10    CONTINUE
 
      CALL DCHPFV ('MINIMAL SIMULATION OF 3D CELL ARRAYS: For ' //
     1             'which cell array are the vertices NOT '     //
     1             'accurately marked by a circle?', 6, NGCA)
 
      CALL PEMST(TESID)
 
C  *** *** *** *** ***   CELL ARRAY 2D    *** *** *** *** ***
 
      CALL SETMSG ('9 14', 'A <cell array> should be rendered as a ' //
     1             'rectangle (in MC) with the specified points P ' //
     2             'and Q as opposite vertices.')
 
C  NGCA = No-good cell array: random integer from 1 to 6
      NGCA = RNDINT(1,6)
 
      DO 50 IX = 1,6
 
C  rotate 30 degrees around x and y and then shift to z=0.5 plane
         CALL EBLTM3 (H,H,Z, Z,Z,H, PI/6,PI/6,Z, U,U,U, XF3D)
         CALL PSLMT3 (XF3D, PCREPL)
 
C  Scale 0:1,0:1 into window #ix
         CALL EBLTM (Z,Z, XWINLO(IX), YWINLO(IX), Z, XSIZ,YSIZ, XF)
         CALL PSLMT (XF, PCPOST)
 
         RNDNUM = RNDRL (-1.,1.)
         IF (RNDNUM .GE. 0) THEN
            PX = 0.15
            QX = 0.85
         ELSE
            PX = 0.75
            QX = 0.25
         ENDIF
 
         RNDNUM = RNDRL (-5.,5.)
         IF (RNDNUM .GE. 0) THEN
            PY = 0.25
            QY = 0.85
         ELSE
            PY = 0.75
            QY = 0.15
         ENDIF
 
C Draw cell array using p,q = (px,py) (qx,qy) colia(1:dx, 1:dy)
         CALL PCA (PX,PY, QX,QY, XDIM,YDIM, 1,1, 5,5, COLIA)
 
         XA(1) = PX
         YA(1) = PY
         XA(2) = QX
         YA(2) = PY
         XA(3) = PX
         YA(3) = QY
 
C  mark vertices
         IF (IX .EQ. NGCA) THEN
C  compute incorrect vertices
            XA(4) = PX + 1.1 * (QX - PX)
            YA(4) = PY + 1.1 * (QY - PY)
         ELSE
            XA(4) =  QX
            YA(4) =  QY
         ENDIF
 
C Mark vertices with circles
         CALL PPM (4, XA, YA)
50    CONTINUE
 
      CALL DCHPFV ('MINIMAL SIMULATION OF 2D CELL ARRAYS: For ' //
     1             'which cell array are the vertices NOT '     //
     1             'accurately marked by a circle?', 6, NGCA)
 
      CALL PEMST (TESID)
 
C  *** *** *** *** ***   COLOR TEST SETUP   *** *** *** *** ***
 
      IF (.NOT. SOLIDC) THEN
         CALL INMSG ('Skipping tests of color index arrays, since ' //
     1               'this workstation does not support control '   //
     2               'of cell coloring by the array.')
         GOTO 666
      ENDIF
 
C  Request 5 distinct colors
      CALL DISCOL (5, WKID, NCLS)
 
      IF (NCLS .LE. 2) GOTO 85
 
C  Fill colia(ix,iy) avoiding same colors in adjacent cells
      DO 70 IX = 1,5
      DO 80 IY = 1,5
C set up list of random colors
         CALL RNPERM (NCLS, LCOLS)
         LSIZ = NCLS
 
         IF (IX .GT. 1) THEN
C  strike color of previous row from list
            COLLOC = IARFND (COLIA(IX-1,IY), LSIZ, LCOLS)
            IF (COLLOC .GT. 0) THEN
               LCOLS (COLLOC) = LCOLS(LSIZ)
               LSIZ = LSIZ-1
            ENDIF
         ENDIF
 
         IF (IY .GT. 1) THEN
C  strike color of previous column from list
            COLLOC = IARFND (COLIA(IX,IY-1), LSIZ, LCOLS)
            IF (COLLOC .GT. 0) THEN
               LCOLS (COLLOC) = LCOLS(LSIZ)
               LSIZ = LSIZ-1
            ENDIF
         ENDIF
 
         IF (LSIZ .GE. 1) THEN
            COLIA(IX,IY) = LCOLS(RNDINT(1,LSIZ))
         ELSE
            COLIA(IX,IY) = RNDINT(0,NCLS)
         ENDIF
 
80    CONTINUE
70    CONTINUE
85    CONTINUE
 
C  *** *** *** *** ***  CELL COLOR TEST  *** *** *** *** ***
 
      CALL SETMSG ('4 5 9 10 11 12', 'The color index of the cells ' //
     1             'of a <cell array 3> and <cell array> should be ' //
     2             'determined by the corresponding element of the ' //
     3             'specified color index array.')
 
C  NGCA = no-good cell array: random integer from 1 to 6
      NGCA = RNDINT (1,6)
 
      DO 140 IX = 1,6
C  number of cells
         DX = RNDINT (2,4)
         DY = RNDINT (2,4)
C  starting position for color array
         X1 = 6-DX
         Y1 = 6-DY
 
C  Scale 0:1,0:1 into window #ix
         CALL EBLTM (Z,Z, XWINLO(IX), YWINLO(IX), Z, XSIZ,YSIZ, XF)
         CALL PSLMT (XF, PCREPL)
 
         IF (IX .GT. 3) THEN
C We are in 3-D
            ANG = RNDRL (0., 360.0) * (2*PI/360)
 
            XPTS(1) = 0.5 + RADCIR * COS(ANG)
            YPTS(1) = 0.5 + RADCIR * SIN(ANG)
 
            OFFSET = 2 * RNDINT(0,1) - 1
            QANG    = ANG + OFFSET * ( RNDRL(75.0 ,105.0 ) * (2*PI/360))
            RANG    = ANG - OFFSET * ( RNDRL(75.0 ,105.0 ) * (2*PI/360))
            XPTS(2) = 0.5 + RADCIR * COS(QANG)
            YPTS(2) = 0.5 + RADCIR * SIN(QANG)
            XPTS(3) = 0.5 + RADCIR * COS(RANG)
            YPTS(3) = 0.5 + RADCIR * SIN(RANG)
            XPTS(4) = XPTS(2) + XPTS(3) - XPTS(1)
            YPTS(4) = YPTS(2) + YPTS(3) - YPTS(1)
 
C  put z-values between 0.2 and 0.5 - behind diagonals to be drawn
            ZPTS(1) = RNDRL( 0.3, 0.4)
            ZPTS(2) = RNDRL( 0.3, 0.4)
            ZPTS(3) = RNDRL( 0.3, 0.4)
            ZPTS(4) = ZPTS(2) + ZPTS(3) - ZPTS(1)
 
C   Draw cell array 3
            CALL PCA3 (XPTS,YPTS,ZPTS, XDIM,YDIM, X1,Y1, DX,DY, COLIA)
         ELSE
C  2-D cell array
            RNDNUM = RNDRL (-1.,1.)
            IF (RNDNUM .GE. 0) THEN
               PX = 0.15
               QX = 0.85
            ELSE
               PX = 0.75
               QX = 0.25
            ENDIF
 
            RNDNUM = RNDRL (-5.,5.)
            IF (RNDNUM .GE. 0) THEN
               PY = 0.25
               QY = 0.85
            ELSE
               PY = 0.75
               QY = 0.15
            ENDIF
 
C  Draw cell array using p,q = (px,py) (qx,qy) colia(1:dx, 1:dy)
            CALL PCA (PX,PY, QX,QY, XDIM,YDIM, X1,Y1, DX,DY, COLIA)
 
            XPTS(1) = PX
            YPTS(1) = PY
            XPTS(2) = QX
            YPTS(2) = PY
            XPTS(3) = PX
            YPTS(3) = QY
            XPTS(4) = QX
            YPTS(4) = QY
         ENDIF
 
C Compute cell boundaries and draw diagonals in correct color
         ZDIAG(1) = 0.999
         ZDIAG(2) = 0.999
C vectors for incrementing row and column:
         ROWX = (XPTS(2) - XPTS(1)) / DX
         ROWY = (YPTS(2) - YPTS(1)) / DX
         COLX = (XPTS(3) - XPTS(1)) / DY
         COLY = (YPTS(3) - YPTS(1)) / DY
 
C  control size of diagonal
         DIAGSZ = 0.3
         DO 170 IROW = 1,DX
         DO 180 ICOL = 1,DY
C  get correct color
            CELX = X1+IROW-1
            CELY = Y1+ICOL-1
            CORCOL = COLIA(CELX, CELY)
            IF (IX.EQ.NGCA .AND. IROW.EQ.2 .AND. ICOL.EQ.2) THEN
C  use an incorrect color
               NGCOL = COLIA(CELX-1, CELY)
               IF (NGCOL .NE. CORCOL) GOTO 510
               NGCOL = COLIA(CELX+1, CELY)
               IF (NGCOL .NE. CORCOL) GOTO 510
               NGCOL = COLIA(CELX, CELY-1)
               IF (NGCOL .NE. CORCOL) GOTO 510
               NGCOL = COLIA(CELX, CELY+1)
               IF (NGCOL .NE. CORCOL) GOTO 510
               CALL UNMSG ('Aborting test: cannot find distinct ' //
     1                     'color for cell to be colored incorrectly.')
 
510            CONTINUE
               CALL PSPLCI (NGCOL)
            ELSE
C  use correct color
               CALL PSPLCI (CORCOL)
            ENDIF
 
C  center of this cell:
            CENTX = XPTS(1) + (IROW - 0.5) * ROWX
     1                      + (ICOL - 0.5) * COLX
            CENTY = YPTS(1) + (IROW - 0.5) * ROWY
     1                      + (ICOL - 0.5) * COLY
C  first diagonal
            XDIAG(1) = CENTX + DIAGSZ * (ROWX + COLX)
            YDIAG(1) = CENTY + DIAGSZ * (ROWY + COLY)
            XDIAG(2) = CENTX - DIAGSZ * (ROWX + COLX)
            YDIAG(2) = CENTY - DIAGSZ * (ROWY + COLY)
            CALL PPL3 (2, XDIAG,YDIAG,ZDIAG)
C  second diagonal
            XDIAG(1) = CENTX + DIAGSZ*ROWX - DIAGSZ*COLX
            YDIAG(1) = CENTY + DIAGSZ*ROWY - DIAGSZ*COLY
            XDIAG(2) = CENTX - DIAGSZ*ROWX + DIAGSZ*COLX
            YDIAG(2) = CENTY - DIAGSZ*ROWY + DIAGSZ*COLY
            CALL PPL3 (2, XDIAG,YDIAG,ZDIAG)
C  next cell
180      CONTINUE
170      CONTINUE
 
C  next cell array
140   CONTINUE
 
      CALL DCHPFV ('CELL ARRAY COLORING: For which cell array do ' //
     1             'the cell diagonals NOT match the cell color?',
     2             6, NGCA)
      CALL PEMST (TESID)
 
C  *** *** ***  UNDEFINED CELL COLOR INDICES  *** *** ***
 
      CALL SETMSG ('12 13', 'An index which is undefined in the '    //
     1             'color table should cause entry number 1 to be '  //
     2             'used as the color of a cell which is specified ' //
     3             'by that index.')
 
C  Set colors so that they are not the background
C  Or the foreground color
      CALL PSCMD (WKID, PRGB)
 
C  BCKCOL = background color = realized color spec for entry #0
      CALL PQCR (WKID, 0, 3, PREALI, ERRIND, NCOLOR, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
 
C  FORCOL = Foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NCOLOR, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)
 
C  Try to set entry #1 opposite from bckcol
      DO 2150 IX = 1,3
         IF (BCKCOL(IX) .GT. 0.5) THEN
            NEWCOL(IX) = 0.0
         ELSE
            NEWCOL(IX) = 1.0
         ENDIF
2150  CONTINUE
 
C  Set entry #1 different from forcol - make sure other default
C  is to current color-rep of #1, not just a predefined color.
      IF (FORCOL(3) .GT. 0.5) THEN
         NEWCOL(3) = 0.0
      ELSE
         NEWCOL(3) = 1.0
      ENDIF
 
      CALL PSCR (WKID, 1, 3, NEWCOL)
 
      CALL PQECI (WKID, 0, ERRIND, NUMCI, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
 
C  UNDF1,UNDF2,UNDF3 = 3 undefined, positive color indices
      UNDF(1) = NUMCI + 1
      UNDF(2) = -1
      UNDF(3) = NUMCI + 90
 
      CALL RNPERM (6, PERM)
 
      DX = 3
      DY = 3
 
C  set up 3D cell array coordinates
      XPTS(1) = 0.2
      YPTS(1) = 0.2
      XPTS(2) = 0.8
      YPTS(2) = 0.2
      XPTS(3) = 0.2
      YPTS(3) = 0.8
      XPTS(4) = XPTS(2) + XPTS(3) - XPTS(1)
      YPTS(4) = YPTS(2) + YPTS(3) - YPTS(1)
      ZPTS(1) = 0.5
      ZPTS(2) = 0.5
      ZPTS(3) = 0.5
      ZPTS(4) = ZPTS(2) + ZPTS(3) - ZPTS(1)
 
C  set up 2D cell array coordinates
      PX = 0.2
      PY = 0.2
      QX = 0.8
      QY = 0.8
 
      DO 220 IX = 1,6
C  Scale 0:1,0:1 into window #ix
         CALL EBLTM (Z,Z, XWINLO(IX), YWINLO(IX), Z, XSIZ,YSIZ, XF)
         CALL PSLMT (XF, PCREPL)
 
C  3x3 checkerboard 2d array, using 1 and 0 only
         CALL SET2D ('1,0,1,0,0/' //
     1               '0,1,0,0,0/' //
     2               '1,0,1,0,0/' //
     3               '0,0,0,0,0/' //
     4               '0,0,0,0,0/',
     5               XDIM, NOCOLS, ARRLEN, COLIA)
 
         THIS = PERM(IX)
         IF (THIS .GE. 2) COLIA(1,1) = UNDF(1)
         IF (THIS .GE. 3) COLIA(3,3) = UNDF(2)
         IF (THIS .GE. 4) COLIA(1,3) = UNDF(3)
         IF (THIS .GE. 5) COLIA(2,2) = UNDF(1)
         IF (THIS .GE. 6) THEN
            COLIA(3,1) = 0
            NGCA = IX
         ENDIF
 
         IF (IX .GT. 3) THEN
C  3D cell array
            CALL PCA3 (XPTS,YPTS,ZPTS, XDIM,YDIM, 1,1, DX,DY, COLIA)
         ELSE
C  2D cell array
            CALL PCA (PX,PY, QX,QY, XDIM,YDIM, 1,1, DX,DY, COLIA)
         ENDIF
 
220   CONTINUE
 
      CALL DCHPFV ('UNDEFINED CELL COLOUR INDICES: Which cell ' //
     1             'array is different?', 6, NGCA)
      CALL PEMST (TESID)
 
C  Wrap it up.
666   CONTINUE
      CALL ENDIT
 
      END
