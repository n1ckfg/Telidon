C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/11                        *
C  *    TEST TITLE : Appearance of bundled attributes      *
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
      INTEGER    PPOINT,     PPLUS,     PAST,     POMARK,    PXMARK
      PARAMETER (PPOINT = 1, PPLUS = 2, PAST = 3, POMARK =4, PXMARK =5)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)
C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER    IMPMAX
      PARAMETER (IMPMAX=600)

      INTEGER    PICSTR,TXCI, NUMMT,NUMMW, STDDX,REGDX,IMPDX
      INTEGER    THISMT, LAVSMT(5), LAVRMT(100), LAVIMT(IMPMAX)
      INTEGER    ITRIM,NUMDIS, CSIZ, SZCOLT, NUMPAS, SZBT
      INTEGER    MKCOL(20), IX, VISDX,VISCOL, RNDINT, PMCI, NUMCI
      INTEGER    MAXCOL, COLEL, UNDF(3), EXPLCT, PERM(10), RTANS(10)
      INTEGER    CDIM, NUMMAR

      REAL       THISMW, NOMMW,MINMW,MAXMW, YLOC,YINCR, XA(9),YA(9)
      REAL       XLOC, XINCR, MSCF
      PARAMETER (CSIZ = 6)
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ), LMSSF(7)
      REAL       TSTMW1,TSTMW2, MULT, RAD, CENTX,CENTY, PI

      CHARACTER  MDESCR(5)*14, PROMPT*200, MKTID*12, PFSW*1

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7
      REAL       RDUM1,RDUM2,RDUM3

      DATA  MDESCR / 'dot', 'plus', 'asterisk', 'circle', 'cross' /

      CALL INITGL ('04.02.02.02/11')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  set ASFs to BUNDLE
      CALL SETASF (PBUNDL)

C  use <inquire polymarker facilities> to determine:
C    nummt  = number of marker types
C    lavsmt = list of available standard marker types
C    lavrmt = list of available registered (non-mandatory) marker types
C    lavimt = list of available implementor-defined marker types
C             (may be derived directly from marker type value, if reported
C              number of marker types < 0)
C    nummw  = number of available marker-sizes
C    nommw  = nominal marker-size (DC)
C    minmw,maxmw = minimum,maximum marker-size (DC)
      CALL PQPMF (SPECWT,0, ERRIND, NUMMT,IDUM1,
     1            NUMMW,NOMMW,MINMW,MAXMW, IDUM2 )
      CALL CHKINQ ('pqpmf', ERRIND)
C  szbt = maximum size of bundle table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, SZBT, IDUM2, IDUM3,
     1            IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      STDDX = 0
      REGDX = 0
      IMPDX = 0
      DO 100 IX = 1,ABS(NUMMT)
         CALL PQPMF (SPECWT,IX, ERRIND, IDUM1, THISMT,
     1               IDUM2,RDUM1,RDUM2,RDUM3, IDUM3)
         CALL CHKINQ ('pqpmf', ERRIND)
         IF     (THISMT .GT. PXMARK) THEN
            REGDX = REGDX+1
            LAVRMT (REGDX) = THISMT
         ELSEIF (THISMT .GT. 0) THEN
            STDDX = STDDX+1
            LAVSMT (STDDX) = THISMT
         ELSE
            IF (IMPDX .LT. IMPMAX) THEN
               IF (NUMMT .LT. 0) THEN
C  build list from first IX negative integers
                  IMPDX = IMPDX+1
                  LAVIMT (IMPDX) = -IX
               ELSE
                  IMPDX = IMPDX+1
                  LAVIMT (IMPDX) = THISMT
               ENDIF
            ENDIF
         ENDIF
100   CONTINUE

C  *** *** ***   marker type

C  mark start of marker types
      CALL PLB (1)
      MSCF = 0.05 / (WCPDC*NOMMW)
C set polymarker bundle representation
      DO 150 IX = 1, STDDX
         CALL PSPMR (WKID, IX, LAVSMT(IX), MSCF, 1)
150   CONTINUE

C  Display in random order bundles 1 thru stddx
      CALL RNPERM (STDDX, PERM)
      XA(1) = 0.3
      YINCR = 0.8/STDDX
      YLOC  = 0.9
      CALL NUMLAB (STDDX, 0.1, YLOC,YINCR)

      DO 200 IX = 1,STDDX
         YA(1) = YLOC
         CALL PSPMI (LAVSMT(PERM(IX)))
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

C  mark end of marker types
      CALL PLB (2)

      CALL SETMSG ('3 4 5 6 35 36', 'The mandatory marker types ' //
     1             '(1-5) should be recognizable from their '     //
     2             'standard description.')

C  Operator must identify each marker type according to official
C  English description: 1-dot, 2-plus sign, 3-asterisk, 4-circle,
C                       5-diagonal cross
      PROMPT = 'MANDATORY MARKER TYPES: List, in order, numeric ' //
     1         'labels for marker types: ' // MDESCR(LAVSMT(1))
      RTANS(PERM(1)) = 1
      DO 300 IX = 2,STDDX
         PROMPT(ITRIM(PROMPT)+1:) = ', ' // MDESCR(LAVSMT(IX))
         RTANS(PERM(IX)) = IX
300   CONTINUE
      PROMPT(ITRIM(PROMPT)+1:) = '.'
      CALL DLSTPF (PROMPT, STDDX,RTANS, 'L')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  REGDX = size of lavrmt
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No non-mandatory registered marker types are ' //
     1               'supported.')
         GOTO 890
      ENDIF
C select at most 8 bundles with marker types from lavrmt
      NUMDIS = MIN(8, REGDX, SZBT)
      CALL RNSET (NUMDIS, REGDX, PERM)
C  and sort them
      CALL SRTIAR (NUMDIS, PERM)
      CALL SRTIAR (REGDX, LAVRMT)

C  set polymarker bundle representation
      DO 770 IX = 1,NUMDIS
         CALL PSPMR (WKID, IX, LAVRMT(PERM(IX)), MSCF, 1)
770   CONTINUE

C  Display and label bundles with (some) marker types from LAVRMT
      XA(1) = 0.5
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9

      DO 800 IX = 1,NUMDIS
         YA(1) = YLOC
         THISMT = LAVRMT(PERM(IX))
         WRITE (MKTID, '(A,I2,A)') 'Type#', THISMT, ':'
         CALL VISLAB (MKTID(1:8), 'R',
     1                .05,.45, YLOC-.3*YINCR, YLOC+.3*YINCR)
         CALL PSPMI (IX)
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
800   CONTINUE
      CALL SETMSG ('3 4 5 6 35 37', 'The registered non-mandatory ' //
     1             'marker types (> 5) should agree with their '    //
     2             'registered description.')
      CALL DYNPF ('NON-MANDATORY REGISTERED MARKER TYPES: Is each ' //
     1            'marker type depicted according to its numeric '  //
     2            'identifier''s specification in the ISO register?',
     3            'Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  neg_type:
890   CONTINUE
C  IMPDX = size of lavimt
      IF (IMPDX .LT. 1) THEN
         CALL INMSG ('No implementor-defined marker types are ' //
     1               'supported.')
         GOTO 990
      ENDIF
C select at most 8 bundles with marker types from lavimt
      NUMDIS = MIN(8, IMPDX, SZBT)
      CALL RNSET (NUMDIS, IMPDX, PERM)
C and sort them
      CALL SRTIAR (NUMDIS, PERM)
      CALL SRTIAR (IMPDX, LAVIMT)

C set polymarker bundle representation
      DO 870 IX = 1, NUMDIS
         CALL PSPMR (WKID, IX, LAVIMT(PERM(IX)), MSCF, 1)
870   CONTINUE

C  Display and label bundles with (some) marker types from LAVIMT
      XA(1) = 0.5
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9

      DO 900 IX = 1,NUMDIS
         YA(1) = YLOC
         THISMT = LAVIMT(PERM(IX))
         WRITE (MKTID, '(A,I5,A)') 'Type#', THISMT, ':'
         CALL VISLAB (MKTID(1:11), 'R',
     1                .05,.45, YLOC-.3*YINCR, YLOC+.3*YINCR)
         CALL PSPMI (IX)
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
900   CONTINUE

      CALL SETMSG ('3 4 5 6 35 38', 'Implementor-defined marker '    //
     1             'types (< 1) should agree with the descriptions ' //
     2             'supplied by the implementor.')

      CALL DYNPF ('IMPLEMENTOR DEFINED MARKER TYPES: Is each marker ' //
     1            'type depicted according to its numeric '           //
     2            'identifier''s specification in the implementor '   //
     3            'documentation?','Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)
C end_markertype:
990   CONTINUE

C  *** *** ***   marker size

C  Are there at least two visually distinguishable marker sizes?
      IF (NUMMW .EQ. 1          .OR.
     1    MAXMW .LE. 1.02*MINMW .OR.
     2    MAXMW-MINMW .LT. QVIS)    THEN
         TSTMW1 = MAXMW
         TSTMW2 = MAXMW
         MULT   = 2.0
      ELSE
         TSTMW1 = MINMW
         TSTMW2 = MAXMW
         IF (NUMMW .EQ. 0) THEN
C  continuous range of marker sizes available - take 4 geometric steps
            MULT = 0.9999 * ((TSTMW2/TSTMW1) ** 0.25)
         ELSE
C  discrete set of marker sizes available - test min/max only
            MULT = 0.9999 * (TSTMW2/TSTMW1)
         ENDIF
      ENDIF

C test scale sizes
C set up counter; numpas = number of tests passed so far
      NUMPAS = 0
      THISMW = TSTMW1
C  loop thru various marker sizes/next_Mw:
1000  CONTINUE

C  invoke SHPMBW subroutine to test bundle with
C     requested marker size = thismw
C     expected marker size = thismw
      CALL SHPMBW ('VARIOUS MARKER SIZE SCALE FACTORS', WKID,
     1              THISMW, THISMW, NOMMW, PFSW)

      IF (PFSW .EQ. 'A') THEN
         IF (NUMPAS .LT. 2) THEN
            CALL INMSG ('Skipping test case for various scale '      //
     1                  'factors because largest valid marker size ' //
     2                  'is greater than screen size.')
            GOTO 1110
         ELSE
            GOTO 1100
         ENDIF
      ELSEIF (PFSW .NE. 'P') THEN
         NUMPAS = 0
         GOTO 1100
      ENDIF
C  if PFSW = 'P', set up for next marker size to be tested:
      NUMPAS = NUMPAS+1
      THISMW = THISMW * MULT
      IF (THISMW .LE. TSTMW2) GOTO 1000

1100  CONTINUE
      CALL SETMSG ('3 4 5 6 42 43 44', 'Available marker size ' //
     1             'scale factors should control the realized ' //
     2             'size of a polymarker.')
      CALL IFPF (NUMPAS.GT.0)

C  min_max_coerce:
1110  CONTINUE
      CALL SETMSG ('3 4 5 6 42 43 45', 'A requested positive marker ' //
     1             'size scale factor below the minimum available '   //
     2             'should be realized as the minimum.')

      CALL SHPMBW ('POSITIVE MARKER SIZE BELOW MINIMUM', WKID,
     1              MINMW/2, MINMW, NOMMW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

      CALL SETMSG ('3 4 5 6 42 43 45', 'A requested negative marker ' //
     1             'size scale factor should be realized as the '     //
     2             'minimum.')

      CALL SHPMBW ('NEGATIVE MARKER SIZE', WKID,
     1             -MAXMW-100, MINMW, NOMMW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

C test marker size scale above maximum = maximum
      CALL SHPMBW ('POSITIVE MARKER SIZE ABOVE MAXIMUM', WKID,
     1              MAXMW*2, MAXMW, NOMMW, PFSW)
      IF (PFSW .EQ. 'A') THEN
         CALL INMSG ('Skipping test case for requested scale factor ' //
     1               'greater than maximum because largest valid '    //
     2               'marker size is greater than screen size.')
      ELSE
         CALL SETMSG ('3 4 5 6 42 43 45', 'A requested marker size '  //
     1                'scale factor above the maximum available '     //
     2                'should be realized as the maximum.')
         CALL IFPF (PFSW .EQ. 'P')
      ENDIF

C  *** *** ***   Marker type 1   *** *** *** ***

C lmssf =  list of marker sizes, contains:
      LMSSF(1) = MINMW/2
      LMSSF(2) = MAXMW * 2
      LMSSF(3) = - 2.76
      LMSSF(4) = (MINMW + MAXMW)/2
      LMSSF(5) = MINMW
      LMSSF(6) = MAXMW
      LMSSF(7) = NOMMW
C set up bundles 1-7
      DO 1150 IX = 1,7
         CALL PSPMR (WKID, IX, PPOINT, LMSSF(IX)/NOMMW, 1)
1150  CONTINUE

C nummar = number of markers to be drawn = random integer between 3-7
      NUMMAR = RNDINT (3,7)
      XINCR = .1
      XLOC  = XINCR
      XA(1) = XLOC
      YA(1) = .5

      CALL SETMSG ('3 4 5 6 42 43 46', 'Marker type 1 should be ' //
     1             'rendered as the smallest displayable dot, '   //
     2             'regardless of the marker size scale factor '  //
     3             'value.')

C draw reference marker and polyline separator
C  set ASFs to INDIVIDUAL
      CALL SETASF (PINDIV)
      CALL PSMK (PPOINT)
      CALL PSMKSC (1.0)
      CALL PPM (1,XA,YA)
C attributes for POLYLINE
      CALL PSLN (1)
      CALL PSLWSC (1.0)
      CALL PSPLCI (1)
      XLOC  = XINCR + XLOC
      XA(1) = XLOC
      XA(2) = XA(1)
      YA(1) = .45
      YA(2) = .55
      CALL PPL (2, XA, YA)

C  set ASFs to BUNDLE
      CALL SETASF (PBUNDL)
C draw markers with varying sizes
      YA(1) = .5
      DO 1200 IX = 1,NUMMAR
         XLOC = XLOC + XINCR
         XA(1) = XLOC
         CALL PSPMI (IX)
         CALL PPM (1, XA, YA)
1200  CONTINUE

      CALL DCHPFV ('MARKER SIZE OF MARKER TYPE 1: How many dots '    //
     1             'to the right of the vertical line are the same ' //
     2             'size as the dot to the left of the line?',
     3             12, NUMMAR)

1350  CONTINUE

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  *** *** ***  polymarker color index

      CALL SETMSG ('3 4 5 6 47 48 49', 'A defined polymarker color ' //
     1             'index should cause the addressed entry in the '  //
     2             'color table to be used when rendering a '        //
     3             'polymarker.')

      CALL PSCMD (WKID, PRGB)
C  bckcol = background color = realized color spec for entry #0
C  forcol = foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 0, CSIZ, PREALI, ERRIND, CDIM, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL PQCR (WKID, 1, CSIZ, PREALI, ERRIND, CDIM, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  szcomt = maximum size of color table (including entry #0)
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             SZCOLT, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)
C  how many markers to draw
      NUMDIS = MIN(8, SZCOLT, SZBT)
C  from values 2 to SZCOLT-1, pick NUMDIS-2 entries
      CALL RNBSET (NUMDIS-2, 2, SZCOLT-1, MKCOL)
C  add in 0 and 1
      MKCOL(NUMDIS-1) = 1
      MKCOL(NUMDIS)   = 0
      CALL RNPERM (NUMDIS, PERM)

C  from mkcol, randomly select entry #visdx, but not the one that
C  contains 0, since this may not be re-settable.
      VISDX  = RNDINT(1,NUMDIS-1)
      VISCOL = MKCOL(VISDX)

C  ensure dialogue visible
      DTXCI  = VISCOL
      CALL PSTXCI (VISCOL)
      YLOC  = 0.9
      YINCR = 0.8 / (NUMDIS-1)
      XA(1) = .2

      CALL NUMLAB (NUMDIS, .1, YLOC, YINCR)

C  for each color entry - set to background color
C                       - set bundle representation and draw marker
      DO 2100 IX = 1,NUMDIS
         PMCI = MKCOL(PERM(IX))
         CALL PSCR (WKID, PMCI, CDIM, BCKCOL)
C set entry mkcol(vis) to forcol
         CALL PSPMR (WKID, IX, 3, MSCF, PMCI)
         YA(1) = YLOC
         CALL PSPMI (IX)
         CALL PPM (1, XA,YA)
         YLOC  = YLOC-YINCR
2100  CONTINUE

C  set entry mkcol(vis) to forcol
      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)

      CALL DCHPF ('DEFINED POLYMARKER COLOR INDICES: Which marker ' //
     1            'is visible?', NUMDIS, VISDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 5 6 47 48 50', 'An undefined polymarker '    //
     1             'color index should cause entry number 1 in the ' //
     2             'color table to be used when rendering a '        //
     3             'polymarker.')

C  Try to set entry #1 opposite from BCKCOL
      DO 2150 IX = 1,3
         IF (BCKCOL(IX) .GT. 0.5) THEN
            NEWCOL(IX) = 0.0
         ELSE
            NEWCOL(IX) = 1.0
         ENDIF
2150  CONTINUE

C  set entry #1 different from FORCOL - make sure other default
C  is to current color-rep of #1, not just a predefined color.
      IF (FORCOL(3) .GT. 0.5) THEN
         NEWCOL(3) = 0.0
      ELSE
         NEWCOL(3) = 1.0
      ENDIF
      CALL PSCR  (WKID, 1, CDIM, NEWCOL)

      CALL PQECI (WKID, 0, ERRIND, NUMCI, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      MAXCOL = 0
      DO 2200 IX = 1,NUMCI
         CALL PQECI (WKID, IX, ERRIND, IDUM1, COLEL)
         CALL CHKINQ ('pqeci', ERRIND)
         MAXCOL = MAX(MAXCOL, COLEL)
2200  CONTINUE

C  undf1,undf2,undf3 = 3 undefined, positive color indices
      UNDF(1) = MAXCOL+1
      UNDF(2) = MAXCOL+10
      UNDF(3) = MAXCOL+90

C  explct = number of explicit markers of color #1 = random integer
C  from 0 to 4
      EXPLCT = RNDINT(0,4)
      NUMDIS = EXPLCT+3
      CALL RNPERM (NUMDIS, PERM)

C  draw star with individual attributes:linetype=1,width=1,col index=1
C  set ASFS to INDIVIDUAL
      CALL SETASF (PINDIV)
      CALL PSLN (1)
      CALL PSLWSC (1.0)
      CALL PSPLCI (1)
      RAD = .15
      CENTX = .5
      CENTY = .75
      PI = 3.14159265
      DO 2400 IX = 1,6
         YA(IX) = CENTY + RAD*COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD*SIN((4*PI*IX)/5)
2400  CONTINUE
      CALL PPL (6,XA,YA)

C  re-set ASFS to BUNDLE
      CALL SETASF (PBUNDL)
C  display interleaved:
C    three bundles with color u1,u2,u3,
C    explct bundles with color #1
      XINCR = 0.1
      XLOC  = XINCR
      YA(1) = .5
C  for each color entry - set to background color and draw line
      DO 2300 IX = 1,NUMDIS
         COLEL = PERM(IX)
         IF (COLEL .LE. 3) THEN
            CALL PSPMR (WKID, IX, 3, MSCF, UNDF(COLEL))
         ELSE
            CALL PSPMR (WKID, IX, 3, MSCF, 1)
         ENDIF
         XA(1) = XLOC
         CALL PSPMI (IX)
         CALL PPM (1, XA,YA)
         XLOC  = XLOC + XINCR
2300  CONTINUE

      CALL DCHPFV ('UNDEFINED POLYMARKER COLOR INDICES: How many ' //
     1             'markers are the same color as the star?',
     2             12, NUMDIS)

666   CONTINUE
C wrap it up
      CALL ENDIT
      END
