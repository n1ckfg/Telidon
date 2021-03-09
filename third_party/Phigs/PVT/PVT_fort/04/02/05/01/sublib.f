C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.01/showew                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SHOWEW (HDING, REQEW, EXPEW, NOMEW,
     1                   MINLW, PFSW)

C  SHOWEW tests the rendering of a given edgewidth, and returns the
C  pass/fail result, or an abort signal if the requested edge is
C  too wide to be tested.

C
C  Input parameters:
C    HDING : Title for this test
C    REQEW : The edgewidth (in DC) to be requested.
C    EXPEW : The expected edgewidth (in DC) - the one which should
C            be realized in order to pass.
C    NOMEW : The nominal edgewidth
C    MINLW : The minimum linewidth (used for simulation)
C  Output parameters:
C    PFSW  : Result of the test - P:pass, F:fail, A:abort.

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C edge-, line-type
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C edge flag indicator
      INTEGER    POFF,    PON
      PARAMETER (POFF=0, PON=1)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    IX, NUMALT, ANS, PERM(20)
      INTEGER    NPTS(1)

      REAL       REQEW, EXPEW, NOMEW, MINLW, XA(5),YA(5),ZA(5)
      REAL       XLOC,YBASE, XINCR, FSIZE, XMARG,XLEN,XGAP,  ALT(10)

      CHARACTER  PFSW*1, HDING*(*), MSG*300, DIGIT*1

      YBASE = 0.2
C  can we fit in top of picture area? - if not, quit
      IF (EXPEW * WCPDC .GT. 1-YBASE) THEN
         PFSW = 'A'
         RETURN
      ENDIF

C  get list of alternate sizes
      CALL ALTSIZ (EXPEW, QVIS, (1.0-YBASE) / WCPDC, 4, NUMALT,ALT)
      CALL RNPERM (NUMALT, PERM)

C  draw actual and simulated edges of various widths

C  first simulated
      CALL PSLN (PLSOLI)
      CALL PSPLCI (1)
      CALL PSLWSC (0.0)
      XINCR = 1.0 / NUMALT
      XLOC  = 0.0
      XGAP  = XINCR/25
      XMARG = 3*XGAP
      XLEN  = (XINCR - XGAP - 2*XMARG) / 2
      YA(2) = YBASE + MINLW * WCPDC / 2
      YA(3) = YA(2)
      DO 500 IX = 1,NUMALT
C  size of linewidth to be simulated - allow for thickness
C  of simulating edge by subtracting minimum edgewidth.
         FSIZE = (ALT(PERM(IX))-MINLW) * WCPDC
         YA(1) = YA(2) + FSIZE
         YA(4) = YA(1)
         YA(5) = YA(1)
         XA(1) = XLOC + XMARG
         XA(2) = XA(1)
         XA(5) = XA(1)
         XA(3) = XA(1) + XLEN
         XA(4) = XA(3)
         CALL PPL (5, XA,YA)
         XLOC = XLOC + XINCR
500   CONTINUE
C  now actual
      CALL PSEWSC (REQEW/NOMEW)
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH  (0.05)
      XLOC = 0.0
      ZA(1) = 0.5
      ZA(2) = 0.9
      ZA(3) = ZA(2)
      ZA(4) = ZA(1)
      YA(1) = YBASE + EXPEW * WCPDC/2
      YA(2) = YA(1)
      YA(3) = YA(1)
      YA(4) = YA(1)
      NPTS(1) = 4

      DO 600 IX = 1,NUMALT
C  offset 2nd and 4th point slightly so that Z-oriented edges (1-2 and
C  3-4) project to a short horizontal line, rather than to a point.
         XA(1) = XLOC + XMARG + XGAP + XLEN
         XA(2) = XA(1) + XLEN/100
         XA(3) = XA(1) + XLEN
         XA(4) = XA(3) - XLEN/100
         CALL PFAS3 (1, NPTS, XA,YA,ZA)
         WRITE (DIGIT, '(I1)') IX
         CALL PTX (XLOC + XINCR/2, YBASE - 0.05, DIGIT)
         XLOC = XLOC + XINCR
600   CONTINUE

      MSG = HDING // ': Which pair has the same vertical thickness?'

      CALL DCHOIC (MSG, 0,NUMALT, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPCOFL
         PFSW = 'F'
      ELSEIF (PERM(ANS) .EQ. 1) THEN
         PFSW = 'P'
      ELSE
         PFSW = 'F'
      ENDIF

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.01/parpt                       *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PARPT (RCX,RCY, PARITY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y,
     1                  XA,YA, X,Y, STEP1,STEP2)

C  PARPT accepts a reference point and 2 vectors and computes a
C  corner of the smallest parallelogram containing a specified
C  rectangle. The corner is found in the direction specified by
C  parity.

C  Input parameters
C    RCX,RCY       : reference point within rectangle
C    PARITY        : +1 to search in direction of vectors, -1 to
C                    search in opposite direction
C    PRVC1X,PRVC1Y : first vector to increment reference point
C    PRVC2X,PRVC2Y : second vector to increment reference point
C    XA,YA         : 4 corners of rectangle to be contained
C  Output parameters
C    X,Y           : corner of parallelogram
C    STEP1,STEP2   : number of steps taken from reference point in
C                    direction of 1st,2nd vector

      INTEGER  PARITY, STEP1, STEP2

      REAL     RCX,RCY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y, XA(4),YA(4), X,Y
      REAL     A1,B1,C1, A2,B2,C2

C  find first, second boundary lines
      CALL PARLIN (RCX,RCY, PARITY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y,
     1             XA,YA, A1,B1,C1, STEP1)
      CALL PARLIN (RCX,RCY, PARITY, PRVC2X,PRVC2Y, PRVC1X,PRVC1Y,
     1             XA,YA, A2,B2,C2, STEP2)
C  intersection of lines is corner
      CALL LINTPT (A1,B1,C1, A2,B2,C2, X,Y)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.01/parlin                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PARLIN (RCX,RCY, PARITY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y,
     1                   XA,YA, A,B,C, STEP)

C  PARLIN accepts a reference point and 2 vectors and computes a
C  side of the smallest parallelogram containing a specified
C  rectangle.  The side is found in the direction specified by
C  parity.

C  Input parameters
C    RCX,RCY       : reference point within rectangle
C    PARITY        : +1 to search in direction of 1st vector, -1 to
C                    search in opposite direction
C    PRVC1X,PRVC1Y : first vector: used to increment/decrement reference point
C    PRVC2X,PRVC2Y : second vector: indicate direction (slope) of side
C    XA,YA         : 4 corners of rectangle to be contained
C  Output parameters
C    A,B,C         : coefficients of side
C    STEP          : number of steps taken from reference point

      INTEGER  PARITY, IX, STEP

      REAL     RCX,RCY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y, XA(4),YA(4), A,B,C
      REAL     CURX,CURY, CHK

      CURX = RCX
      CURY = RCY
      STEP = 0

100   CONTINUE
      STEP = STEP+1
      CURX = CURX + PARITY*PRVC1X
      CURY = CURY + PARITY*PRVC1Y
C  candidate line coefficients
      CALL PARCOF (CURX,CURY, PRVC2X,PRVC2Y, A,B,C)
      CHK = A*XA(1) + B*YA(1) + C
C  check if all on same side
      DO 200 IX = 2,4
C  if not on same side, go back and take another step
         IF (CHK * (A*XA(IX) + B*YA(IX) + C) .LE. 0) GOTO 100
200   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.01/cldiag                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CLDIAG (X1,Y1, X2,Y2, A,B,C,D, XL,YL, XF)

C  CLDIAG accepts the x-y coordinates of 2 MC points, the
C  coefficients of a fill area plane, and a transformation from MC
C  to WC, and draws the resulting (slightly shrunken) 3D line segment.
C
C  Input parameters:
C    X1,Y1, X2,Y2 : MC coordinates of 1st,2nd point
C    A,B,C,D      : fill area plane is: a*x + b*y + c*z + d = 0
C    XL,YL        : border of fill area in MC - an aligned rectanlge
C    XF           : transformation from MC to WC

      REAL   X1,Y1, X2,Y2, XW1,YW1, XW2,YW2, A,B,C,D, XF(4,4), SHRINK
      REAL   XL(4), YL(4), XLO,XHI,YLO,YHI, XA(2),YA(2),ZA(2), ZT

      XLO = XL(1)
      XHI = XL(3)
      YLO = YL(3)
      YHI = YL(1)

      SHRINK = .80
      XW1 = SHRINK*X1 + (1-SHRINK)*X2
      XW2 = SHRINK*X2 + (1-SHRINK)*X1
      YW1 = SHRINK*Y1 + (1-SHRINK)*Y2
      YW2 = SHRINK*Y2 + (1-SHRINK)*Y1

      IF ((XW1.LT.XLO .OR. XW1.GT.XHI .OR. 
     1     YW1.LT.YLO .OR. YW1.GT.YHI) .OR.
     2    (XW2.LT.XLO .OR. XW2.GT.XHI .OR. 
     3     YW2.LT.YLO .OR. YW2.GT.YHI))  THEN
         RETURN
      ENDIF

      ZT = -(A*XW1 + B*YW1 + D) / C
      CALL ETP3 (XW1,YW1,ZT, XF, XA(1),YA(1),ZA(1))
      ZT = -(A*XW2 + B*YW2 + D) / C
      CALL ETP3 (XW2,YW2,ZT, XF, XA(2),YA(2),ZA(2))

C  since simulated projection is flat, put in z=0.999 plane
      ZA(1) = 0.999
      ZA(2) = 0.999
      CALL PPL3 (2, XA,YA,ZA)

      END
