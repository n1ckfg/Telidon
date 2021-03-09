C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.02.02/hueang                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE HUEANG (R,G,B, ANG, DIST)

C  This program calculates a characteristic angle for a hue from the
C  RGB color cube.  It does so by rotating the cube 45 deg around the
C  y-axis and atan(sqrt(2)) around the z-axis (assuming xyz = RGB).
C  This lines up the black-white cube diagonal (0,0,0 to 1,1,1) along
C  the y-axis.  Now, transformed points along the color-saturated
C  vertices are such that their angle in the x-z plane is a measure
C  of hue; so atan2 is used to compute the hue of any RGB point.

C  BTW, somewhat surprisingly, the points which are transformed into
C  the x=0 plane are all those in the old plane described by:
C  x -2y + z = 0 (this plane contains the points (0,0,0), (1,1,1),
C  and (0,.5,1), all of which can be "seen" to be rotated into x=0
C  plane).  This plane is such that it is satisfied by any points of
C  the form: (q, q+c, q+2c), so that sample points like (3,4,5) will
C  always transform into the x=0 plane.

C  Hueang also returns the distance of the RGB point from the
C  neutral (black-white) axis.

      REAL TMAT(4,4), R,G,B, XO,YO,ZO, PI,A45, ZZ,U, ANG, DIST

      ZZ = 0.0
      U = 1.0
      PI = 3.14159265
      A45 = PI/4.0

      CALL EBLTM3 (ZZ,ZZ,ZZ, ZZ,ZZ,ZZ, ZZ,A45,ATAN(SQRT(2.0)),
     1             U,U,U, TMAT)

10    CONTINUE

      CALL ETP3 (R,G,B, TMAT,  XO,YO,ZO)

      DIST = SQRT(XO*XO + ZO*ZO)

      IF (DIST .EQ. ZZ) THEN
         ANG = -666.0
      ELSE
C  Normalize to 0..1
         ANG = ATAN2(XO,ZO) / (2*PI)
         IF (ANG .LT. 0.0) ANG = ANG + 1
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION 04.03.02.02/modsep                   *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION MODSEP (PERIOD, A, B)

C  Given a period and two values, a and b, modsep calculates the
C  absolute value of the smallest "distance" between the values,
C  treating them as points on a circle with circumference of size =
C  period.  For example, if period=360, as for degree-measure,
C  modsep of 5 and 15 would of course be 10, but so would modsep of
C  5 and 355, or 0 and 710, or 0 and 730.

      REAL PERIOD, A, B, AM,BM, ABDIF

      IF (PERIOD .EQ. 0.0) THEN
         MODSEP = 0.0
         RETURN
      ENDIF

C get normalized mod-values - correct for loopy way Fortran
C mods negative numbers.
      AM = MOD (A,PERIOD)
      IF (A.LT.0) AM = AM+PERIOD
      BM = MOD (B,PERIOD)
      IF (B.LT.0) BM = BM+PERIOD
C now:   0 .le. am,bm  .lt. period

      ABDIF = ABS(AM-BM)
      MODSEP = MIN (ABDIF, PERIOD-ABDIF)

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 04.03.02.02/undcmd                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION UNDCMD (NUMMOD,MODLIS,HICOL,PROMPT)

C  UNDCMD tests the list of color models passed in by requesting
C  dimensions and drawing color patches using those dimensions.
C  The operator is asked if the displayed color matches the
C  randomly chosen color coordinates.

C  Input parameters:
C    NUMMOD :  Size of list of color models 
C    MODLIS :  Entire list of color models which may be tested
C    HICOL  :  Highest color index to be used
C    PROMPT :  String for prompt, indicating documentation to
C              be used for reference

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C  interior style 
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C     type of returned values set, realized
      INTEGER    PSET,   PREALI
      PARAMETER (PSET=0, PREALI=1)

      INTEGER   CMDIM, NUMCM, COLIX, NUMCL, RANLIS(8), NUMTST
      INTEGER   CM, ICM, II, IX, ITRIM, POS1, NUMMOD, MODLIS(*), HICOL

      REAL      LO(8), HI(8), ACTCOL(8), COLARY(8)
      REAL      YLO,YHI, YTOP, YINCR, RNDRL

      CHARACTER CVAL*5, MSG*200, PROMPT*(*), RVALS*80

      LOGICAL   DYN, FILMOD, INTSTY, LOMAG

C  Determine how to fill in rectangles, use solid style
C  if it is available, otherwise use dense polyline cross-hatch
      FILMOD = INTSTY(SPECWT, PSOLID)
C  number of models to test
      NUMTST = MIN(8, NUMMOD)
C  Test a random subset of the models if > 8
      CALL RNSET (NUMTST,NUMMOD,RANLIS)

      DO 140 ICM = 1,NUMTST
         CALL PEMST (102)
C  Set Color Model
         CM = MODLIS(RANLIS(ICM))
         CALL PSCMD (WKID, CM)

         WRITE (CVAL, '(I5)') CM
         CALL DCHOIC ('DIMENSION OF COLOUR MODEL: How many '   //
     1                'dimensions are there for colour model ' // 
     2                CVAL // '?', 0,100, CMDIM)

         IF (CMDIM .EQ. 0) THEN
            CALL INMSG ('Operator reported zero dimensions for a ' //
     1                  'color model.')
            UNDCMD = .FALSE.
            RETURN
         ENDIF

C  determine format for displaying color coordinates
         LOMAG = .TRUE.
         DO 100 IX = 1, CMDIM
            WRITE(CVAL, '(I5)') IX
            CALL DRLVAL('DIMENSION BOUNDS: Enter the LOWER limit ' //
     1                  'for valid values for dimension # '        //
     2                  CVAL, LO(IX))
            CALL DRLVAL('DIMENSION BOUNDS: Enter the UPPER limit ' //
     1                  'for valid values for dimension # '        //
     2                  CVAL, HI(IX))
            IF (ABS (LO(IX)) .GE. 10.0) LOMAG = .FALSE.
            IF (ABS (HI(IX)) .GE. 10.0) LOMAG = .FALSE.
100      CONTINUE

C  Draw color patches down left side of screen:
         NUMCM = HICOL - 1
         YINCR = 1.0 / (NUMCM + 1.0)
         YTOP  = 1 - YINCR
         YLO   = YTOP - 0.25*YINCR
         YHI   = YTOP + 0.25*YINCR
         CALL NUMLAB (NUMCM, 0.15, YTOP, YINCR)

         DO 130, COLIX = 2, HICOL
            DO 110 IX = 1, CMDIM
               COLARY(IX) = RNDRL(LO(IX),HI(IX))
110         CONTINUE

            CALL PSCR (WKID, COLIX, CMDIM, COLARY)
C  determine actual colval
            CALL PQCR (WKID,COLIX, CMDIM, PREALI, ERRIND, NUMCL,ACTCOL)
            CALL CHKINQ ('pqcr', ERRIND)

            IF (NUMCL .NE. CMDIM) THEN
               WRITE (MSG, '(A,I5,A,I5,A,I5,A)') 'Reported ' //
     1                'dimensionality for color model #', CM, ' is ', 
     2                NUMCL, '; does not match value specified by ' //
     3                'operator = ', CMDIM, '.'
               CALL INMSG (MSG)
               UNDCMD = .FALSE.
               RETURN               
            ENDIF

            CALL COLPCH (FILMOD, COLIX, 0.2, YLO, 0.5, YHI)
C  format color coordinates for printing
            RVALS = ' '
            DO 120 II = 1, NUMCL
               IF (LOMAG) THEN
                  POS1 = 6*II - 5
                  WRITE (RVALS(POS1:POS1+5), '(A,F5.2)') ',', ACTCOL(II)
               ELSE
                  POS1 = 10*II - 9
                  WRITE (RVALS(POS1:POS1+9), '(A,E9.2)') ',', ACTCOL(II)
               ENDIF
120         CONTINUE
            CALL VISLAB (RVALS(2:ITRIM(RVALS)), 'L', 0.55,0.95, YLO,YHI)

            YLO = YLO-YINCR
            YHI = YHI-YINCR

C  next random color within color model
130      CONTINUE

         WRITE (MSG, '(A,I5,A,A,A)') 'ACCURACY OF COLOUR MODEL: '  //
     1          'Are the colours of the rectangles compatible '    //
     2          'with the corresponding colour coordinate values ' //
     3          'within colour model #', CM, ', according to the ', 
     4          PROMPT, '?'

         IF (DYN (MSG)) THEN
C           OK so far
         ELSE
            WRITE (CVAL, '(I5)') CM
            CALL INMSG ('Color Model #' // CVAL // ' caused failure.')
            UNDCMD = .FALSE.
            RETURN
         ENDIF
C  next color model
140   CONTINUE
      UNDCMD = .TRUE.

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.02.02/colpch                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE COLPCH (FILMOD, CLOR, XLO,YLO,XHI,YHI)

C  COLPCH will generate a rectangular color patch with the specified
C  diagonal vertices.  It will use solid interior fill area or
C  polylines based on the specified filling mode.

C  Input parameters:
C    FILMOD          : use fill area if true, otherwise polyline
C    CLOR            : color index to use
C    XLO,YLO,XHI,YHI : extent of the rectangle

      INTEGER    CLOR

      REAL       FILX(4), FILY(4), YINC, XLO,XHI,YLO,YHI, YVAL

      LOGICAL    FILMOD

C  interior style hollow, solid,    pattern,  hatch,    empty
      INTEGER   PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER(PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)
C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

      FILX(1) = XLO
      FILX(2) = XHI
      FILX(3) = XHI
      FILX(4) = XLO

      IF (FILMOD) THEN
         FILY(1) = YLO
         FILY(2) = YLO
         FILY(3) = YHI
         FILY(4) = YHI

         CALL PSIS  (PSOLID)
         CALL PSICI (CLOR)
         CALL PFA   (4, FILX,FILY)
      ELSE
         CALL PSLN   (PLSOLI)
         CALL PSPLCI (CLOR)
C  paint lines at the rate of about 400/screen
         YINC = 1.0/400
         DO 100 YVAL = YLO, YHI, YINC
           FILY(1) = YVAL
           FILY(2) = YVAL
           CALL PPL (2, FILX,FILY)
  100    CONTINUE
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.02.02/coltrn                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE COLTRN (WKID, COLABL, FROMCC, FROMMD, TOCC, TOMD, SRS)

C  COLTRN tests the ability to translate color from one model to
C  another and issues pass or fail as a result.

C  Input parameters:
C    WKID   : workstation identifier
C    COLABL : labels (names) of colors to be tested
C    FROMCC : color coordinates to translate from
C    FROMMD : color model to translate from
C    TOCC   : color coordinates to translate to (expected result)
C    TOMD   : color model to translate to
C    SRS    : SR identifiers for test case

C colour model
      INTEGER    PRGB,   PCIE,   PHSV,   PHLS
      PARAMETER (PRGB=1, PCIE=2, PHSV=3, PHLS=4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER    WKID, FROMMD, TOMD, IX,IY, NUMRET, ERRIND, PASSCT

      REAL       FROMCC(3,9), TOCC(3,9), CSPEC(3),ACTCOL(3),EXPCOL(3)
      REAL       RNDRL

      LOGICAL    COLEQL

      CHARACTER  MSG*300, SRS*(*), MODNAM(PRGB:PHLS)*3, COLABL(9)*8

      DATA  MODNAM  / 'RGB', 'CIE', 'HSV', 'HLS' /

      PASSCT = 0
      DO 100 IX = 1,9
C <set colour model> 
         CALL PSCMD (WKID, FROMMD)
C  <set colour representation> index #1, entry #ix, change -1 to
C     random value between 0 and 1
         DO 110 IY = 1,3
            IF (FROMCC(IY,IX) .EQ. -1) THEN
               CSPEC(IY) = RNDRL (0., 1.)
            ELSE
               CSPEC(IY) = FROMCC(IY,IX)
            ENDIF
            EXPCOL(IY) = TOCC(IY,IX)
110      CONTINUE
         CALL PSCR (WKID, 1, 3, CSPEC)
         CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)
C  attempt to convert only realizable colors
         IF (.NOT. COLEQL (3, ACTCOL, CSPEC, 0.02, 0.0)) GOTO 100

C  <re-set colour model>
         CALL PSCMD (WKID, TOMD)
C  <inquire colour representation> as SET, to determine cspec
         CALL PQCR (WKID, 1, 3, PSET, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)

         IF (NUMRET.EQ.3 .AND.
     1       COLEQL (3, ACTCOL, EXPCOL, 0.1, 0.0)) THEN
C  OK so far
            PASSCT = PASSCT+1
         ELSE
            PASSCT = -666
            WRITE (MSG, '(A)') 'Fail to change colour model from ' //
     1             MODNAM(FROMMD) // ' to ' // MODNAM(TOMD) // 
     2             ' for colour = ' // COLABL(IX) // '.'
            CALL INMSG (MSG)
         ENDIF
100   CONTINUE

      IF (PASSCT .EQ. 0) THEN
         CALL INMSG ('No realizable ' // MODNAM(FROMMD) // 
     1               ' colors for ' // MODNAM(FROMMD) // ' to ' // 
     2               MODNAM(TOMD) // ' conversion test.')
      ELSE
         CALL SETMSG (SRS, 'Changing the colour model from '   //
     1                MODNAM(FROMMD) // ' to ' // MODNAM(TOMD) // 
     2                ' should not affect the colours in the ' //
     3                'colour table.')
         CALL IFPF (PASSCT .GT. 0)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.02.02/sethue                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETHUE (WKID,COLMOD,MAXFG,PALTTE,CC, NUMSET,LSCOLI)

C  SETHUE tries to set as many hues as possible in the color table
C  and reports back the order in which they were set and how many.
C
C  Input parameters
C    WKID   : workstation identifier
C    COLMOD : Color model to set up under
C    MAXFG  : Maximum number of available foreground entries in
C             color table, starting with #2
C    PALTTE : Number of colors to be displayed if possible
C    CC     : Color coordinates to be set in color table
C
C  Output parameters
C    NUMSET : Number of entries successfully set
C    LSCOLI : List of which entries in CC (palette) were set

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)
C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

      INTEGER   COLMOD, MAXFG, PALTTE, NUMSET, LSCOLI(*)
      INTEGER   RNCOL(20), IX, IY, ERRIND, CCSIZ, WKID, NUMDSP, PALIX

      REAL      CC(3,PALTTE), THISCC(3), REALCC(3), RNDRL

      LOGICAL   COLEQL, COLOK

      CALL PSCMD (WKID, COLMOD)

C  max number to be displayed
      NUMDSP = MIN(MAXFG, PALTTE)
      CALL RNSET (NUMDSP, PALTTE, RNCOL)

C  how many set so far?
      NUMSET = 0
      DO 100 IX = 1,NUMDSP
C  which color in palette to try
         PALIX = RNCOL(IX)
         DO 110 IY = 1,3
            THISCC(IY) = CC(IY, PALIX)
C  treat -1 as a "don't care" value
            IF (THISCC(IY) .EQ. -1) THISCC(IY) = RNDRL (0.,1.)
110      CONTINUE
         CALL PSCR (WKID, NUMSET+2, 3, THISCC)
         CALL PQCR (WKID, NUMSET+2, 3, PREALI, ERRIND, CCSIZ, REALCC)
         CALL CHKINQ ('pqcr', ERRIND)
         IF (CCSIZ .NE. 3) GOTO 100
C  is realized hue close enough ??
         IF (COLMOD .EQ. PCIE) THEN
            COLOK = COLEQL(2, REALCC,    THISCC,    0.01, 0.0) .AND.
     1              COLEQL(1, REALCC(3), THISCC(3), 0.1,  0.0)
         ELSE
            COLOK = COLEQL(3, REALCC, THISCC, 0.05, 0.0)
         ENDIF

         IF (COLOK) THEN
C  add to list
            NUMSET = NUMSET+1
            LSCOLI(NUMSET) = PALIX
         ELSE
C           not set
         ENDIF
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION 04.03.02.02/tsthue                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      INTEGER FUNCTION TSTHUE (PRMPT, FILMOD, NUMSET, LSCOLI)

C  TSTHUE displays NUMSET colors, starting with #2, using LSCOLI as
C  color indices.  It then asks the operator to identify these and
C  issues 1 (pass), -1 (fail), or -2 (fail with comment), as a result. 
C
C  Input parameters:
C    PRMPT  : prompt for the operator
C    FILMOD : fill mode for rectangle; true for solid fill area,
C             false for polylines
C    NUMSET : number of colored rectangles to be drawn
C    LSCOLI : list of identifiers from color palette

      INTEGER   NUMSET, LSCOLI(*), IX, ANSSIZ, ANSLIS(20)

      REAL      YTOP, YINCR, YVAL

      LOGICAL   FILMOD, IAREQL

      CHARACTER PRMPT*(*)

      YINCR = 1.0 /(NUMSET+1)
      YTOP  = 1-YINCR
      YVAL  = YTOP - 0.25*YINCR

      DO 120 IX = 1,NUMSET
         CALL COLPCH (FILMOD, IX+1, .25,YVAL, .75,YVAL + 0.5*YINCR)
         CALL PSPLCI (1)
         CALL DRWREC (.25,.75, YVAL,YVAL + 0.5*YINCR)
         YVAL = YVAL-YINCR
120   CONTINUE

      CALL DILIST (PRMPT, ANSSIZ, ANSLIS)
      IF (ANSSIZ.EQ.1 .AND. ANSLIS(1).EQ.0) THEN
         TSTHUE = -2
      ELSEIF (IAREQL (ANSSIZ,ANSLIS, NUMSET,LSCOLI)) THEN
         TSTHUE = 1
      ELSE
         TSTHUE = -1
      ENDIF

      CALL PEMST (102)

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 04.03.02.02/coleql                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION COLEQL (SIZE, ACT,EXP, ABSERR,RELERR)

C  Special purpose routine for testing approximate equality of
C  all three color components, unless one is -1.

C  Input parameters:
C    SIZE    : Number of elements to be compared
C    ACT     : actual values
C    EXP     : expected values
C    ABSERR  : absolute tolerance
C    RELERR  : relative tolerance

      INTEGER  SIZE, IX
      REAL     ACT(SIZE), EXP(SIZE), ABSERR, RELERR
      LOGICAL  APPEQ

      DO 100 IX = 1,SIZE
         IF (ACT(IX) .EQ. -1 .OR. EXP(IX) .EQ. -1) THEN
C OK so far
         ELSEIF (APPEQ (ACT(IX), EXP(IX), ABSERR, RELERR)) THEN
C OK so far
         ELSE
            COLEQL = .FALSE.
            RETURN
         ENDIF
100   CONTINUE
      COLEQL = .TRUE.

      END
