      SUBROUTINE PMATTR (TSTYPE)

C  PMATTR tests polymarker attributes, either individually, using the
C  default values for the other attributes, or in combination, using
C  non-default values for the others.

C  Input parameter:
C    TSTYPE : 'i' for individual, 'c' for combination

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

C polyline type
      INTEGER    PSOLI
      PARAMETER  (PSOLI = 1)
C marker type
      INTEGER    PPOINT,     PPLUS,     PAST,     POMARK,    PXMARK
      PARAMETER (PPOINT = 1, PPLUS = 2, PAST = 3, POMARK =4, PXMARK =5)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

      INTEGER    IMPMAX
      PARAMETER (IMPMAX = 600)

      INTEGER    PICSTR,TXCI, NUMMT,NUMMW, STDDX,REGDX,IMPDX, MDX
      INTEGER    THISMT, LAVSMT(5), LAVRMT(100), LAVIMT(IMPMAX)
      INTEGER    ITRIM, MINIMT,MAXIMT, UNSUDX,LUNSUP(10), NUMDIS
      INTEGER    MARDIS(20), CDIM,CSIZ, SZCOMT, NUMMAR, NUMPAS
      INTEGER    MKCOL(20), IX, VISDX,VISCOL, RNDINT, PMCI, NUMCI
      INTEGER    MAXCOL, COLEL, UNDF(3), EXPLCT, PERM(10), RTANS(10)
      INTEGER    NDISCT, NDMKST, PMCOL, RANMKT

      PARAMETER (CSIZ = 6)

      REAL       THISMW, NOMMW,MINMW,MAXMW, YLOC,YINCR, XA(9),YA(9)
      REAL       XLOC, XINCR,BCKCOL(CSIZ),FORCOL(CSIZ),NEWCOL(CSIZ)
      REAL       TSTMW1,TSTMW2, MULT, RAD, CENTX,CENTY, PI,LMSSF(7)

      CHARACTER  MDESCR(5)*14, PROMPT*200, MKTID*12
      CHARACTER  PFSW*1, MSG*2600, TSTYPE*1, SUFFIX*70

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7
      REAL       RDUM1,RDUM2,RDUM3

      LOGICAL    NOZERO

      DATA  MDESCR / 'dot', 'plus', 'asterisk', 'circle', 'cross' /

      IF (TSTYPE .EQ. 'i' .OR. TSTYPE .EQ. 'c') THEN
C        tstype valid
      ELSE
         CALL UNMSG ('PMATTR called with TSTYPE = ' // TSTYPE)
      ENDIF

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
      STDDX = 0
      REGDX = 0
      IMPDX = 0
      DO 100 MDX = 1,ABS(NUMMT)
         CALL PQPMF (SPECWT,MDX, ERRIND, IDUM1, THISMT,
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
C  build list from first MDX negative integers
                  IMPDX = IMPDX+1
                  LAVIMT (IMPDX) = -MDX
               ELSE
                  IMPDX = IMPDX+1
                  LAVIMT (IMPDX) = THISMT
               ENDIF
            ENDIF
         ENDIF
100   CONTINUE

      IF (TSTYPE .EQ. 'c') THEN
C  NDISCT = number of distinct foreground colors set in color table.
         CALL DISCOL (8, WKID, NDISCT)
      ENDIF

C  *** *** ***   1. marker type

C  mark start of marker types
      CALL PLB (1)

C  Display in random order all marker types in lavsmt
      CALL RNPERM (STDDX, PERM)
      XA(1) = 0.3
      YINCR = 0.8/STDDX
      YLOC    = 0.9
      IF (TSTYPE .EQ. 'c') THEN
         CALL NDMW (YINCR/2, NOMMW)
      ELSE
         CALL PSMKSC ((YINCR/2) /(NOMMW * WCPDC))
      ENDIF
      CALL NUMLAB (STDDX, 0.1, YLOC,YINCR)

      DO 200 MDX = 1,STDDX
         YA(1) = YLOC
         IF (TSTYPE .EQ. 'c') THEN
            CALL PSPMCI (RNDINT (1, NDISCT))
         ENDIF
         CALL PSMK (LAVSMT(PERM(MDX)))
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

C  mark end of marker types
      CALL PLB (2)

      IF (TSTYPE .EQ. 'c') THEN
         SUFFIX = ', even when a non-default marker size or color ' //
     1            'is used.'
      ELSE
         SUFFIX = '.'
      ENDIF

      CALL SETMSG ('3 4 5 6 8', 'The mandatory marker types (1-5) ' //
     1             'should be recognizable from their standard '    //
     2             'description' // SUFFIX)

C  Operator must identify each marker type according to official
C  English description: 1-dot, 2-plus sign, 3-asterisk, 4-circle,
C                       5-diagonal cross
      PROMPT = 'MANDATORY MARKER TYPES: List, in order, numeric ' //
     1         'labels for marker types: ' // MDESCR(LAVSMT(1))
      RTANS(PERM(1)) = 1
      DO 300 MDX = 2,STDDX
         PROMPT(ITRIM(PROMPT)+1:) = ', ' // MDESCR(LAVSMT(MDX))
         RTANS(PERM(MDX)) = MDX
300   CONTINUE
      PROMPT(ITRIM(PROMPT)+1:) = '.'
      CALL DLSTPF (PROMPT, STDDX,RTANS, 'L')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C look for unsupported negative marker type
      IF (NUMMT .GT. 0) THEN
C  find negative marker type *not* in LAVIMT and whether zero
C  is supported.
         NOZERO = .TRUE.
         MINIMT = 0
         DO 400 MDX = 1,IMPDX
            IF (LAVIMT(MDX) .EQ. 0) THEN
               NOZERO = .FALSE.
            ENDIF
            IF (LAVIMT(MDX) .LT. MINIMT) THEN
               MINIMT = LAVIMT(MDX)
            ENDIF
400      CONTINUE
C  LUNSUP is list of unsupported marker types, indexed by UNSUDX
         IF (NOZERO) THEN
            UNSUDX = 1
            LUNSUP (UNSUDX) = 0
         ELSE
            UNSUDX = 0
         ENDIF
C  since this value is less than minimum of LAVIMT, it's unsupported
         UNSUDX = UNSUDX+1
         LUNSUP (UNSUDX) = MINIMT - 1
      ELSE
C  all non-positive marker types supported - derived directly from
C  marker type value
         UNSUDX = 0
      ENDIF

C now look for unsupported positive marker type
      MAXIMT = 6
      DO 500 MDX = 1,REGDX
         IF (LAVRMT(MDX) .GT. MAXIMT) THEN
            MAXIMT = LAVRMT(MDX)
         ENDIF
500   CONTINUE
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = MAXIMT + 1

C  now add to end of LUNSUP entry #3 and a non-asterisk marker type
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = 3

C  other = another available non-asterisk marker type: 2, 4, or 5
      DO 600 MDX = 1,STDDX
         IF (LAVSMT(MDX) .EQ. 2 .OR.
     1       LAVSMT(MDX) .EQ. 4 .OR.
     2       LAVSMT(MDX) .EQ. 5) THEN
C  this is the only one that should appear as non-asterisk
            UNSUDX = UNSUDX+1
            LUNSUP (UNSUDX) = LAVSMT(MDX)
            GOTO 610
         ENDIF
600   CONTINUE
C  no other available  - goto end_asterisk
      GOTO 690

610   CONTINUE

C  Display in random order marker types in LUNSUP
      CALL RNPERM (UNSUDX, PERM)
      XA(1) = 0.3
      YINCR = 0.8/UNSUDX
      YLOC  = 0.9
      IF (TSTYPE .EQ. 'c') THEN
         CALL NDMW (YINCR/2, NOMMW)
      ELSE
         CALL PSMKSC ((YINCR/2) / (NOMMW * WCPDC))
      ENDIF
      CALL NUMLAB (UNSUDX, 0.1, YLOC,YINCR)

      DO 700 MDX = 1,UNSUDX
         YA(1) = YLOC
         IF (TSTYPE .EQ. 'c') THEN
            CALL PSPMCI (RNDINT (1, NDISCT))
         ENDIF
         CALL PSMK (LUNSUP(PERM(MDX)))
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
700   CONTINUE

      CALL SETMSG ('3 4 5 6 7 8', 'Unavailable marker types should ' //
     1             'be displayed as marker type number 3' // SUFFIX)
      CALL DCHPF ('UNSUPPORTED MARKER TYPES: Which marker is NOT ' //
     1             'an asterisk?', UNSUDX, UNSUDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_asterisk:
690   CONTINUE

C  REGDX = size of lavrmt
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No non-mandatory registered marker types are ' //
     1               'supported.')
         GOTO 890
      ENDIF
C display and label at most 8 marker types in lavrmt
      NUMDIS = MIN(8, REGDX)
      CALL RNSET (NUMDIS, REGDX, PERM)

C  build list of marker types to be displayed
      DO 770 MDX = 1,NUMDIS
         MARDIS(MDX) = LAVRMT(PERM(MDX))
770   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, MARDIS)

C  Display in order (some) marker types in LAVRMT
      XA(1) = 0.5
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9
      IF (TSTYPE .EQ. 'c') THEN
         CALL NDMW (YINCR/2, NOMMW)
      ELSE
         CALL PSMKSC ((YINCR/2) / (NOMMW * WCPDC))
      ENDIF

      DO 800 MDX = 1,NUMDIS
         YA(1) = YLOC
         THISMT = MARDIS(MDX)
         WRITE (MKTID, '(A,I2,A)') 'Type#', THISMT, ':'
         CALL VISLAB (MKTID(1:8), 'R',
     1                .05, .4, YLOC-.3*YINCR, YLOC+.3*YINCR)
         IF (TSTYPE .EQ. 'c') THEN
            CALL PSPMCI (RNDINT (1, NDISCT))
         ENDIF
         CALL PSMK (THISMT)
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
800   CONTINUE
      CALL SETMSG ('3 4 5 6 9', 'The registered non-mandatory '  //
     1             'marker types (> 5) should agree with their ' //
     2             'registered description' // SUFFIX)

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
C display and label at most 8 marker types in lavimt
      NUMDIS = MIN(8, IMPDX)
      CALL RNSET (NUMDIS, IMPDX, PERM)

C  build list of marker types to be displayed
      DO 870 MDX = 1,NUMDIS
         MARDIS(MDX) = LAVIMT(PERM(MDX))
870   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, MARDIS)

C  Display (some) marker types in LAVIMT
      XA(1) = 0.5
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9
      IF (TSTYPE .EQ. 'c') THEN
         CALL NDMW (YINCR/2, NOMMW)
      ELSE
         CALL PSMKSC ((YINCR/2) / (NOMMW * WCPDC))
      ENDIF

      DO 900 MDX = 1,NUMDIS
         YA(1) = YLOC
         THISMT = MARDIS(MDX)
         WRITE (MKTID, '(A,I5,A)') 'Type#', THISMT, ':'
         CALL VISLAB (MKTID(1:11), 'R',
     1                .05,.4, YLOC-.3*YINCR, YLOC+.3*YINCR)
         IF (TSTYPE .EQ. 'c') THEN
            CALL PSPMCI (RNDINT (1, NDISCT))
         ENDIF
         CALL PSMK (THISMT)
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
900   CONTINUE

      CALL SETMSG ('3 4 5 6 10', 'Implementor-defined marker types ' //
     1             '(< 1) should agree with the descriptions '       //
     2             'supplied by the implementor' // SUFFIX)

      CALL DYNPF ('IMPLEMENTOR DEFINED MARKER TYPES: Is each marker ' //
     1            'type depicted according to its numeric '           //
     2            'identifier''s specification in the implementor '   //
     3            'documentation?','Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  Check if all implementor marker types already shown or
C  marker type appearance derived directly from value - if so, skip test
      IF (IMPDX .LE. 8 .OR. NUMMT .LT. 0) GOTO 990

      IF (TSTYPE .EQ. 'c') GOTO 990

      CALL SETMSG ('10', 'All reported implementor-defined marker ' //
     1             'types available for a given workstation type '  //
     2             'should be documented by the implementor.')
C sort first
      CALL SRTIAR (IMPDX, LAVIMT)
      WRITE (MSG, '(500I5)') (LAVIMT(MDX), MDX=1,IMPDX)
      CALL DYNPF ('COMPLETE DOCUMENTATION FOR IMPLEMENTOR MARKER '    //
     1            'TYPES: Are all these reportedly available marker ' //
     2            'types documented by the implementor?' // MSG, 'Y')

C  end_marker type:
990   CONTINUE

C  *** *** ***   2. marker size

      IF (TSTYPE .EQ. 'c') THEN
         SUFFIX = ', even when a non-default marker type ' //
     3            'or color is used.'
      ELSE
         SUFFIX = '.'
         NDMKST = PPLUS
         PMCOL  = 1
      ENDIF

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

      IF (TSTYPE .EQ. 'c') THEN
C  random marker type and color:
         NDMKST = RNDINT(2,4)
         PMCOL  = RNDINT (1, NDISCT)
      ENDIF
C  invoke SHOWMW subroutine to test requested marker size = thismw
C                                    expected marker size = thismw
      CALL SHOWMW ('VARIOUS MARKER SIZE SCALE FACTORS', NDMKST, PMCOL,
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
      CALL SETMSG ('3 13 14 15', 'Available marker size scale '  //
     1             'factors should control the realized size '   //
     2             'of a polymarker' // SUFFIX)
      CALL IFPF (NUMPAS.GT.0)

C  min_max_coerce:
1110  CONTINUE
      CALL SETMSG ('3 13 14 16', 'A requested positive marker size '  //
     1             'scale factor below the minimum available should ' //
     2             'be realized as the minimum' // SUFFIX)

      IF (TSTYPE .EQ. 'c') THEN
C  random marker type and color:
         NDMKST = RNDINT(2,4)
         PMCOL  = RNDINT (1, NDISCT)
      ENDIF
      CALL SHOWMW ('POSITIVE MARKER SIZE BELOW MINIMUM', NDMKST, PMCOL,
     1              MINMW/2, MINMW, NOMMW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

      CALL SETMSG ('3 13 14 16', 'A requested negative marker size ' //
     1             'scale factor should be realized as the minimum'  //
     2             SUFFIX)
      IF (TSTYPE .EQ. 'c') THEN
C  random marker type and color:
         NDMKST = RNDINT(2,4)
         PMCOL  = RNDINT (1, NDISCT)
      ENDIF
      CALL SHOWMW ('NEGATIVE MARKER SIZE', NDMKST, PMCOL,
     1             -MAXMW-100, MINMW, NOMMW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

C test marker size scale above maximum = maximum
      IF (TSTYPE .EQ. 'c') THEN
C  random marker type and color:
         NDMKST = RNDINT(2,4)
         PMCOL  = RNDINT (1, NDISCT)
      ENDIF
      CALL SHOWMW ('POSITIVE MARKER SIZE ABOVE MAXIMUM', NDMKST, PMCOL,
     1              MAXMW*2, MAXMW, NOMMW, PFSW)
      IF (PFSW .EQ. 'A') THEN
         CALL INMSG ('Skipping test case for requested scale factor ' //
     1               'greater than maximum because largest valid '    //
     2               'marker size is greater than screen size.')
      ELSE
         CALL SETMSG ('3 13 14 16', 'A requested marker size scale '  //
     1                'factor above the maximum available should be ' //
     2                'realized as the maximum' // SUFFIX)
         CALL IFPF (PFSW .EQ. 'P')
      ENDIF

C  *** *** ***   Marker type 1   *** *** *** ***

      IF (TSTYPE .EQ. 'c') GOTO 1350

C set marker type = DOT
      CALL PSMK (PPOINT)
C lmssf =  list of marker sizes, contains:
      LMSSF(1) = MINMW/2
      LMSSF(2) = MAXMW * 2
      LMSSF(3) = - 2.76
      LMSSF(4) = (MINMW + MAXMW)/2
      LMSSF(5) = MINMW
      LMSSF(6) = MAXMW
      LMSSF(7) = NOMMW

C nummar = number of markers to be drawn = random integer between 3-7
      NUMMAR = RNDINT (3,7)
C attributes for POLYLINE
      CALL PSLN (PSOLI)

      XINCR = .1
      XLOC  = XINCR
      XA(1) = XLOC
      YA(1) = .5

      CALL SETMSG ('3 4 5 13 14 17', 'Marker type 1 should be '  //
     1             'rendered as the smallest displayable dot, '  //
     2             'regardless of the marker size scale factor ' //
     3             'value.')

C draw reference marker and polyline separator
      CALL PSMKSC (1.0)
      CALL PPM (1,XA,YA)
      XLOC  = XINCR + XLOC
      XA(1) = XLOC
      XA(2) = XA(1)
      YA(1) = .45
      YA(2) = .55
      CALL PPL (2, XA, YA)

C set up and draw markers with varying sizes
      YA(1) = .5
      DO 1200 IX = 1,NUMMAR
         CALL PSMKSC (LMSSF(IX) / NOMMW)
         XLOC = XLOC + XINCR
         XA(1) = XLOC
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

C  *** *** ***   3. polymarker color index

      IF (TSTYPE .EQ. 'c') THEN
         SUFFIX = ', even when a non-default marker type ' //
     3            'or marker size is used.'
      ELSE
         SUFFIX = '.'
      ENDIF

      CALL SETMSG ('3 20 21 22', 'A defined polymarker color index ' //
     1             'should cause the addressed entry in the color '  //
     2             'table to be used when rendering a polymarker'    //
     3             SUFFIX)

      CALL PSCMD (WKID, PRGB)
C  bckcol = background color = realized color spec for entry #0
C  forcol = foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 0, CSIZ, PREALI, ERRIND, CDIM, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL PQCR (WKID, 1, CSIZ, PREALI, ERRIND, CDIM, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  szcomt = maximum size of color table (including entry #0)
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             SZCOMT, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)
C  how many markers to draw
      NUMMAR = MIN(8, SZCOMT)
C  from values 2 to SZCOMT-1, pick NUMMAR-2 entries
      CALL RNBSET (NUMMAR-2, 2, SZCOMT-1, MKCOL)
C  add in 0 and 1
      MKCOL(NUMMAR-1) = 1
      MKCOL(NUMMAR)   = 0
      CALL RNPERM (NUMMAR, PERM)

C  from mkcol, randomly select entry #visdx, but not the one that
C  contains 0, since this may not be re-settable.
      VISDX  = RNDINT(1,NUMMAR-1)
      VISCOL = MKCOL(VISDX)

C  ensure dialogue visible
      DTXCI  = VISCOL
      CALL PSTXCI (VISCOL)
      YLOC  = 0.9
      YINCR = 0.8 / (NUMMAR-1)
      XA(1) = .2

      IF (TSTYPE .EQ. 'c') THEN
C  non-default marker size
         CALL NDMW (YINCR/2, NOMMW)
      ELSE
         CALL PSMKSC ((YINCR/2) / (NOMMW * WCPDC))
      ENDIF
      CALL NUMLAB (NUMMAR, .1, YLOC, YINCR)

C  for each color entry - set to background color and draw marker
      DO 2100 IX = 1,NUMMAR
         PMCI = MKCOL(PERM(IX))
         CALL PSCR (WKID, PMCI, CDIM, BCKCOL)
         CALL PSPMCI (PMCI)
         IF (TSTYPE .EQ. 'c') THEN
C  random marker type
            CALL PSMK (RANMKT(STDDX,LAVSMT, REGDX,LAVRMT, IMPDX,LAVIMT))
         ELSE
            CALL PSMK (PAST)
         ENDIF
         YA(1) = YLOC
         CALL PPM (1, XA,YA)
         YLOC  = YLOC-YINCR
2100  CONTINUE

C  set entry mkcol(vis) to forcol
      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)

      CALL DCHPF ('DEFINED POLYMARKER COLOR INDICES: Which marker ' //
     1            'is visible?', NUMMAR, VISDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 20 21 23', 'An undefined polymarker color '    //
     1             'index should cause entry number 1 in the color ' //
     2             'table to be used when rendering a polymarker'    //
     3             SUFFIX)

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
      NUMMAR = EXPLCT+3
      CALL RNPERM (NUMMAR, PERM)

C  draw star with color #1
      RAD = .15
      CENTX = .5
      CENTY = .75
      PI = 3.14159265
      DO 2400 IX = 1,6
         YA(IX) = CENTY + RAD*COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD*SIN((4*PI*IX)/5)
2400  CONTINUE
      CALL PSPLCI (1)
      CALL PPL (6,XA,YA)

C  display interleaved:
C    three markers of color u1,u2,u3,
C    explct markers of color #1
      XINCR = 0.1
      XLOC  = XINCR
      YA(1) = .5

      IF (TSTYPE .EQ. 'c') THEN
C  non-default marker size
         CALL NDMW (XINCR/2, NOMMW)
      ELSE
         CALL PSMKSC ((XINCR/2) / (NOMMW * WCPDC))
      ENDIF

C  for each color entry - set to undefined color or #1 and draw marker
      DO 2300 IX = 1,NUMMAR
         COLEL = PERM(IX)
         IF (COLEL .LE. 3) THEN
            CALL PSPMCI (UNDF(COLEL))
         ELSE
            CALL PSPMCI (1)
         ENDIF
         IF (TSTYPE .EQ. 'c') THEN
C  random marker type
            CALL PSMK (RANMKT(STDDX,LAVSMT,REGDX,LAVRMT,IMPDX,LAVIMT))
         ELSE
            CALL PSMK (PAST)
         ENDIF
         XA(1) = XLOC
         CALL PPM (1, XA,YA)
         XLOC  = XLOC + XINCR
2300  CONTINUE

      CALL DCHPFV ('UNDEFINED POLYMARKER COLOR INDICES: How many ' //
     1             'markers are the same color as the star?',
     2             12, NUMMAR)

666   CONTINUE
      END
