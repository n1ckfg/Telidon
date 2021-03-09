C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/12                        *
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

C aspect identifier
      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C linetype  (edgetype)
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)

      INTEGER    IMPMAX
      PARAMETER (IMPMAX = 600)

      INTEGER    PICSTR,TXCI, LAVIS(5), NALIS, NUMHS, THISIS
      INTEGER    NOSEG, SIZ, SZBT, INTCST(0:2), CSTSIZ
      INTEGER    REGDX,IMPDX, ISI, MAXRHS, MINIHS, ENDPTS(3)
      INTEGER    THISHS, LAVRHS(100), LAVIHS(IMPMAX)
      INTEGER    ITRIM, UNSUDX,LUNSUP(10), MDI,NPI, UNDPI
      INTEGER    CDIM,CSIZ, SZCOLT, NUMDIS, RNDINT
      INTEGER    FACOL(20), IX, HDX, VISDX,VISCOL, ISCI, NUMCI
      INTEGER    MAXCOL, COLEL, UNDF(3), EXPLCT, PERM(10), RTANS(10)

      REAL       YLOC,YINCR, XA(40),YA(40)
      PARAMETER (CSIZ = 6)
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ)
      REAL       RAD, CENTX,CENTY, PI, ANG
      PARAMETER (PI = 3.14159265)

C set up pattern array index values
      INTEGER    DIMX, DIMY, PAI, DIFFI
      PARAMETER (DIMX = 50, DIMY = 50)
      INTEGER    PCIA(DIMX, DIMY)

      CHARACTER  PROMPT*200, HATID*12
      CHARACTER  LDESIS(PHOLLO:PISEMP)*14

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5, IDUM6, IDUM7

      LOGICAL    NOZERO, NOAVAL(PHOLLO:PISEMP)

      DATA  LDESIS / 'hollow','solid','pattern','hatch','empty' /
C  interior styles affected by interior color

      CALL INITGL ('04.02.05.02/12')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use bundle attributes
      CALL SETASF (PBUNDL)
C  set edge flag off, (pedfg=14)
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (POFF)
C set up pattern size
      CALL PSPA (.1,.1)

C  use <inquire interior style facilities> to determine:
C    nalis  = number of available & legal interior styles (hollow:empty)
C    lavis  = list of available interior styles
C    numhs  = number of available hatch styles
C    lavrhs = list of available registered (non-mandatory) hatch styles
C    lavihs = list of available implementor-defined hatch styles
C             (may be derived directly from hatch style value, if
C              reported number of hatch styles< 0)
C    noaval = boolean table of interior styles not available

      NALIS = 0
      CSTSIZ = 0
      DO 10 ISI = PHOLLO, PISEMP
         NOAVAL(ISI) = .TRUE.
10    CONTINUE

      CALL PQIF (SPECWT,0,0,ERRIND, SIZ, IDUM1,
     1            NUMHS,IDUM2,IDUM3)
      CALL CHKINQ ('pqif', ERRIND)
C get interior styles
      DO 50 ISI = 1, SIZ
         CALL PQIF (SPECWT, ISI,0,ERRIND, IDUM1, THISIS,
     1              IDUM2, IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS .GE. PHOLLO .AND. THISIS .LE. PISEMP) THEN
            NALIS = NALIS + 1
            LAVIS(NALIS) = THISIS
C mark which interior styles are available
            NOAVAL(THISIS) = .FALSE.
         ENDIF

C  build list of styles sensitive to interior color
         IF (THISIS.EQ.PHOLLO .OR. THISIS.EQ.PSOLID .OR.
     1       THISIS.EQ.PHATCH) THEN
            INTCST(CSTSIZ) = THISIS
            CSTSIZ = CSTSIZ+1
         ENDIF
50    CONTINUE

C get hatch styles
      REGDX = 0
      IMPDX = 0
      DO 100 HDX = 1,ABS(NUMHS)
         CALL PQIF (SPECWT,0,HDX, ERRIND, IDUM1, IDUM2,IDUM3,
     1              THISHS,IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISHS .GT. 0) THEN
            REGDX = REGDX+1
            LAVRHS (REGDX) = THISHS
         ELSE
            IF (IMPDX .LT. IMPMAX) THEN
               IMPDX = IMPDX+1
               IF (NUMHS .LE. 0) THEN
C  build list from first HDX negative integers
                  LAVIHS (IMPDX) = -HDX
               ELSE
                  LAVIHS (IMPDX) = THISHS
               ENDIF
            ENDIF
         ENDIF
100   CONTINUE
C  sort them
      IF (REGDX .GT. 1) CALL SRTIAR (REGDX, LAVRHS)
      IF (IMPDX .GT. 1) CALL SRTIAR (IMPDX, LAVIHS)

C  szbt = maximum size of interior bundle table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, SZBT,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C *** *** ***  interior style   *** *** ***

C  mark start of interior styles
      CALL PLB (1)
C  set interior bundle representation
      DO 150  IX=1, NALIS
         CALL PSIR (WKID, IX, LAVIS(IX), 1, 1)
150   CONTINUE

C  Display in random order with FILL AREA bundles 1 thru nalis
      CALL RNPERM (NALIS,PERM)
      YINCR = 0.8/NALIS
      YLOC  = 0.85
      CALL NUMLAB (NALIS, 0.2, YLOC, YINCR)
      NOSEG = 7
      RAD = 0.33 * YINCR
      CENTX = 0.5

      DO 200 ISI = 1,NALIS
         DO 202 SIZ = 1, NOSEG
            ANG = SIZ * 2 * PI /NOSEG
            XA(SIZ) = CENTX + 2 * RAD*SIN(ANG)
            YA(SIZ) = YLOC  +     RAD*COS(ANG)
202      CONTINUE
         CALL PSII (PERM(ISI))
         CALL PFA  (NOSEG, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

C  mark end of interior styles
      CALL PLB (2)

      CALL SETMSG ('3 5 6 7 35 36', 'The available interior '  //
     1             'styles should be recognizable from their ' //
     3             'standard description.')

C  Operator must identify each interior style according to official
C  English description: 0-hollow,1-solid, 2-pattern,3-hatch, 4-empty.
      PROMPT = 'INTERIOR STYLES: List, in order, the numeric ' //
     1         'labels for interior styles: '
      DO 300 ISI = 1,NALIS
         PROMPT(ITRIM(PROMPT)+1:) = ', ' // LDESIS(LAVIS(ISI))
         RTANS(PERM(ISI)) = ISI
300   CONTINUE
      PROMPT(ITRIM(PROMPT)+1:) = '.'
      CALL DLSTPF (PROMPT, NALIS,RTANS, 'L')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C *** *** *** interior style index - hatch   *** *** ***

C use noaval to check if hatch available
      IF (NOAVAL(PHATCH)) THEN
         CALL INMSG ('Hatch interior style not supported, skip ' //
     1               'hatch index tests.')
         GOTO 990
      ENDIF

C  REGDX = size of lavrhs
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No registered hatch styles are supported.')
         GOTO 890
      ENDIF

C  select at most 8 hatch styles in lavrhs
      NUMDIS = MIN(8, REGDX, SZBT)
      CALL RNSET (NUMDIS, REGDX, PERM)
C  and sort them
      CALL SRTIAR (NUMDIS, PERM)

C  set interior bundle representation
      DO 400 IX = 1, NUMDIS
         CALL PSIR (WKID, IX, PHATCH, LAVRHS(PERM(IX)), 1)
400   CONTINUE

C  Display and label bundles with (some) hatch styles in LAVRHS
      CALL SETRVS ('0.5,0.9,0.9,0.5', XA, SIZ)
      YINCR = 0.8/NUMDIS
      YLOC  = 0.85

      DO 500 IX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         YA(4) = YLOC + YINCR/2
         THISHS = LAVRHS(PERM(IX))
         WRITE (HATID, '(A,I5,A)') 'Style#', THISHS, ':'
         CALL VISLAB (HATID(1:12), 'R', 0.05,0.45,
     1                YLOC, YLOC+0.6*YINCR)
         CALL PSII (IX)
         CALL PFA  (4, XA,YA)
         YLOC  = YLOC-YINCR
500   CONTINUE
      CALL SETMSG ('3 5 6 7 35 39 40 47 48', 'The registered '   //
     1             'hatch styles (> 0) should agree with their ' //
     2             'registered description.')
      CALL DYNPF ('REGISTERED HATCH STYLES: Is each hatch style '    //
     1            'depicted according to its numeric identifier''s ' //
     2            'specification in the ISO register?', 'Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  neg_type:
890   CONTINUE


C  IMPDX = size of lavihs
      IF (IMPDX .LT. 1) THEN
         CALL INMSG ('No implementor-defined hatch styles are ' //
     1               'supported.')
         GOTO 903
      ENDIF
C select at most 8 bundles with hatch styles in lavihs
      NUMDIS = MIN(8, IMPDX, SZBT)
      CALL RNSET (NUMDIS, IMPDX, PERM)
C  and sort them
      CALL SRTIAR (NUMDIS, PERM)

C  set interior bundle representation
      DO 600 IX = 1, NUMDIS
         CALL PSIR (WKID, IX, PHATCH, LAVIHS(PERM(IX)), 1)
600   CONTINUE

C  Display AND LABEL BUNDLES WITH (some) hatch styles in LAVIHS
      CALL SETRVS ('0.5,0.9,0.9,0.5', XA, SIZ)
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9

      DO 700 IX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         YA(4) = YLOC + YINCR/2
         THISHS = LAVIHS(PERM(IX))
         WRITE (HATID, '(A,I5,A)') 'Style#', THISHS, ':'
         CALL VISLAB (HATID(1:12), 'R', 0.05,0.45,
     1                YLOC, YLOC+0.6*YINCR)
         CALL PSII (IX)
         CALL PFA  (4, XA,YA)
         YLOC  = YLOC-YINCR
700   CONTINUE
      CALL SETMSG ('3 5 6 7 35 39 40 47 49', 'Implementor-defined ' //
     1             'hatch styles (< 1) should agree with the '      //
     2             'descriptions supplied by the implementor.')
      CALL DYNPF ('IMPLEMENTOR DEFINED HATCH STYLES: Is each hatch ' //
     1            'style depicted according to its numeric '         //
     2            'identifier''s specification in the implementor '  //
     3            'documentation?','Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C end_hatch_style:
903   CONTINUE

C  check for hatch style 1 - OK to check only 1st position,
C  because list is sorted
      IF (LAVRHS(1) .NE. 1) THEN
         CALL INMSG ('No hatch style #1, skip test of unsupported ' //
     1               'hatch style.')
         GOTO 990
      ENDIF

C look for unsupported negative hatch style
      IF (NUMHS .GT. 0) THEN
C  find negative hatch style *not* in LAVIHS and whether zero
C  is supported.
         NOZERO = .TRUE.
         MINIHS = 0
         DO 910 HDX = 1,IMPDX
            IF (LAVIHS(HDX) .EQ. 0) THEN
               NOZERO = .FALSE.
            ENDIF
            MINIHS = MIN(MINIHS, LAVIHS(HDX))
910      CONTINUE
C  LUNSUP is list of unsupported hatch styles, indexed by UNSUDX
         IF (NOZERO) THEN
            UNSUDX = 1
            LUNSUP (UNSUDX) = 0
         ELSE
            UNSUDX = 0
         ENDIF
C  since this value is less than minimum of LAVIHS, it's unsupported
         UNSUDX = UNSUDX+1
         LUNSUP (UNSUDX) = MINIHS - 1
      ELSE
C  all non-positive hatch styles supported - derived directly from
C  interior style index value
         UNSUDX = 0
      ENDIF

C now look for unsupported positive hatch style
      MAXRHS = 2
      DO 920 HDX = 1,REGDX
         MAXRHS = MAX(MAXRHS, LAVRHS(HDX))
920   CONTINUE
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = MAXRHS + 1

C  now add to end of LUNSUP entry #1 and a non-horizontal hatch style
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = 1
C  other = another available non-horizontal hatch style
C  get positive hatch style, if not, get negative style
C  this is the only one that should appear as non-horizontal style #1
      UNSUDX = UNSUDX+1
      IF (REGDX .GT. 1) THEN
         LUNSUP(UNSUDX) = LAVRHS(2)
      ELSE
         LUNSUP(UNSUDX) = LAVIHS(1)
      ENDIF

C  set interior bundles with mostly unsupported hatch styles
      DO 750 IX = 1, UNSUDX
         CALL PSIR (WKID, IX, PHATCH, LUNSUP(IX), 1)
750   CONTINUE

C  Display in random order bundles 1 thru unsudx
      CALL RNPERM (UNSUDX, PERM)
      XA(1) = 0.3
      XA(2) = 0.9
      XA(3) = 0.6
      YINCR = 0.8/UNSUDX
      YLOC  = 0.85
      CALL NUMLAB (UNSUDX, 0.2, YLOC+.05,YINCR)

      DO 970 IX = 1,UNSUDX
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         CALL PSII (PERM(IX))
         CALL PFA  (3, XA,YA)
         YLOC  = YLOC-YINCR
970   CONTINUE

      CALL SETMSG ('3 5 6 7 35 39 41', 'Unavailable hatch ' //
     1             'styles should be displayed as hatch style 1.')
      CALL DCHPF ('UNSUPPORTED HATCH STYLES: Which hatch style is ' //
     1            'not the horizontal hatch style of index #1?',
     2             UNSUDX, UNSUDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_hatch:
990   CONTINUE

C *** *** ***   interior style index - pattern   *** *** ***

C use noavail to check if pattern available
      IF (NOAVAL(PPATTR)) THEN
         CALL INMSG ('Pattern interior style not supported, skip ' //
     1               'pattern index tests.')
         GOTO 1900
      ENDIF

      CALL SETMSG ('3 4 5 6 7 35 39 40', 'A defined pattern '       //
     1             'index should cause the addressed entry in the ' //
     2             'pattern table to be used when rendering an '    //
     3             'interior filled with pattern interior style.')

C set 5 patterns (index 1-5): 4 identical and one different
      PCIA(5,5) = 1
      PCIA(6,5) = 0
      PCIA(7,5) = 2
      PCIA(5,6) = 0
      PCIA(6,6) = 1
      PCIA(7,6) = 2
      DO 1100 IX = 1, 5
         CALL PSPAR (WKID, IX, DIMX, DIMY, 5,5, 3,2, PCIA)
C  and set up interior bundles
         CALL PSIR  (WKID, IX, PPATTR, IX, 1)
1100  CONTINUE

C now randomly set the different pattern
      DIFFI = RNDINT(1,5)
      PCIA (1,1) = 0
      PCIA (2,1) = 1
      PCIA (1,2) = 1
      PCIA (2,2) = 0
      CALL PSPAR (WKID, DIFFI, DIMX, DIMY, 1,1, 2,2, PCIA)

      CALL SETRVS ('0.3,0.7,0.7,0.3', XA, NOSEG)
      ENDPTS(1) = NOSEG
      YLOC   = 0.9
      YINCR  = 0.8 / 5
      CALL NUMLAB (5, .15, YLOC, YINCR)

      DO 1350 IX = 1,5
         YA(1) = YLOC - 0.25*YINCR
         YA(2) = YLOC - 0.25*YINCR
         YA(3) = YLOC + 0.25*YINCR
         YA(4) = YLOC + 0.25*YINCR
         CALL PSII (IX)
C alternate between PFA and PFAS
         IF (MOD(IX,2) .EQ. 1) THEN
            CALL PFA (NOSEG, XA,YA)
         ELSE
            CALL PFAS (1, ENDPTS, XA, YA)
         ENDIF
         YLOC = YLOC - YINCR
1350  CONTINUE

      CALL DCHPFV ('DEFINED PATTERNS: Which pattern is different?',
     1             5, DIFFI)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C look for 3 undefined pattern indices
C loop thru pattern table to determine mdi = the maximum defined index
C npi = number of pattern indices

      CALL PQEPAI (WKID,0, ERRIND, NPI,IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)
      MDI =  -9999
      DO 1400 IX = 1,NPI
         CALL PQEPAI (WKID, IX, ERRIND, IDUM1, PAI)
         CALL CHKINQ ('pqepai', ERRIND)
         IF (MDI .LT. PAI) MDI = PAI
1400  CONTINUE

C set up 5 patterns: 3 undefined, index #1, and another
      UNSUDX = 5
C undpi = undefined pattern index
      UNDPI = MDI + 1

C lunsup = list of (mostly) unsupported pattern indices
      LUNSUP(1) = UNDPI
      LUNSUP(2) = UNDPI + 1
      LUNSUP(3) = UNDPI + 2
C reset pattern for index #1 to checkerboard
      PCIA (1,1) = 1
      PCIA (2,1) = 0
      PCIA (1,2) = 0
      PCIA (2,2) = 1
      CALL PSPAR (WKID, 1, DIMX, DIMY, 1,1, 2,2, PCIA)
      LUNSUP(4) = 1

C set pattern for index #5 (because we know 1-5 defined above, so this
C won't define an undefined index)
      PCIA (1,1) = 1
      PCIA (2,1) = 1
      PCIA (1,2) = 1
      PCIA (2,2) = 0
      CALL PSPAR (WKID, 5, DIMX, DIMY, 1,1, 2,2, PCIA)
      LUNSUP(5) = 5

C  set interior bundles with mostly unsupported patterns
      DO 1750 IX = 1, UNSUDX
         CALL PSIR (WKID, IX, PPATTR, LUNSUP(IX), 1)
1750  CONTINUE

C  Display in random order bundles 1 thru 5
      CALL RNPERM (UNSUDX, PERM)
      CALL SETRVS ('0.3,0.9,0.9,0.3', XA, NOSEG)
      YINCR = 0.8/UNSUDX
      YLOC  = 0.85
      CALL NUMLAB (UNSUDX, 0.2, YLOC+.05, YINCR)

      DO 1500 PAI = 1,UNSUDX
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         YA(4) = YLOC + YINCR/2
         CALL PSII (PERM(PAI))
         CALL PFA (4, XA, YA)
         YLOC  = YLOC - YINCR
1500  CONTINUE

      CALL SETMSG ('3 5 6 7 35 39 41', 'Unavailable patterns ' //
     1             'should be displayed as pattern 1.')
      CALL DCHPF ('UNDEFINED PATTERNS: Which pattern is different?',
     1             UNSUDX, UNSUDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C end_pattern:
1900  CONTINUE

C  *** *** ***   interior color index   *** *** ***

      CALL SETMSG ('3 4 5 6 7 50 51 52', 'A defined interior color ' //
     1             'index should cause the addressed entry in the '  //
     2             'color table to be used when rendering an '       //
     3             'interior.')

      CALL PSCMD (WKID, PRGB)
C  bckcol = background color = realized color spec for entry #0
C  forcol = foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 0, CSIZ, PREALI, ERRIND, CDIM, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL PQCR (WKID, 1, CSIZ, PREALI, ERRIND, CDIM, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  szcolt = maximum size of color table (including entry #0)
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             SZCOLT, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)
C  how many interiors to draw
      NUMDIS = MIN(8, SZCOLT)
C  from values 2 to SZCOLT-1, pick NUMDIS-2 entries
      CALL RNBSET (NUMDIS-2, 2, SZCOLT-1, FACOL)
C  add in 0 and 1
      FACOL(NUMDIS-1) = 1
      FACOL(NUMDIS)   = 0
      CALL RNPERM (NUMDIS, PERM)

C  from facol, randomly select entry #visdx, but not the one that
C    contains 0, since this may not be re-settable.
      VISDX  = RNDINT(1,NUMDIS-1)
      VISCOL = FACOL(VISDX)

C  ensure dialogue visible
      DTXCI  = VISCOL
      CALL PSTXCI (VISCOL)
      YLOC  = 0.9
      YINCR = 0.8 / NUMDIS
      RAD = 0.3 * YINCR
      CENTX = .25 + RAD
      CENTY = YLOC
      CALL NUMLAB (NUMDIS, .15, YLOC, YINCR)

      NOSEG = 11
      ENDPTS(1) = NOSEG

C  for each color entry - set to background color
C                       - set bundle representation and draw interior
      DO 2100 IX = 1,NUMDIS
         ISCI = FACOL(PERM(IX))
         CALL PSCR (WKID, ISCI, CDIM, BCKCOL)
C  set bundle represention
C  rotate among available styles: [HOLLOW, SOLID, HATCH]
         CALL PSIR (WKID, IX, INTCST(MOD(IX,CSTSIZ)), 1, ISCI)
         DO 2050 SIZ = 1, NOSEG
            ANG = SIZ * 2 * PI /NOSEG
            XA(SIZ) = CENTX + RAD*COS(ANG)
            YA(SIZ) = CENTY + RAD*SIN(ANG)
2050     CONTINUE
         CALL PSII (IX)
C alternate between PFA and PFAS
         IF (MOD(IX,2) .EQ. 0) THEN
            CALL PFA (ENDPTS(1), XA,YA)
         ELSE
            CALL PFAS (1,ENDPTS, XA,YA)
         ENDIF
         YLOC  = YLOC-YINCR
         CENTY = YLOC
2100  CONTINUE

C  set entry facol(visdx) to forcol
      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)
      CALL DCHPF ('DEFINED INTERIOR COLOR INDICES: Which ' //
     1            'circle is visible?', NUMDIS, VISDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 5 6 7 50 51 53', 'An undefined interior '    //
     1             'color index should cause entry number 1 in the ' //
     2             'color table to be used when rendering an '       //
     3             'interior.')

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

C  explct = number of explicit interiors of color #1 =
C  random integer from 0 to 4
      EXPLCT = RNDINT(0,4)
      NUMDIS = EXPLCT+3
      CALL RNPERM (NUMDIS, PERM)

C  draw star with individual attributes: linetype=1,width=1,color=#1
C  set individual attributes
      CALL SETASF (PINDIV)
      CALL PSLN (1)
      CALL PSLWSC (1.0)
      CALL PSPLCI (1)
      RAD = .15
      CENTX = .5
      CENTY = .75
      DO 2400 IX = 1,6
         YA(IX) = CENTY + RAD*COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD*SIN((4*PI*IX)/5)
2400  CONTINUE
      CALL PPL (6,XA,YA)

C  re-set to bundle attributes
      CALL SETASF (PBUNDL)
C  set edge flag = OFF
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (POFF)

C  display interleaved:
C    three interiors of color u1,u2,u3,
C    explct interiors of color #1
      YLOC  = 0.5
      YINCR = 0.5 / 8
      XA(1) = .3
      XA(2) = .7
      XA(3) = .5
      ENDPTS(1) = 3

C  for each color entry - set to background color and draw interior
      DO 2300 IX = 1,NUMDIS
         COLEL = PERM(IX)
         IF (COLEL .LE. 3) THEN
            CALL PSIR (WKID, IX, PSOLID, 1, (UNDF(COLEL)))
         ELSE
            CALL PSIR (WKID, IX, PSOLID, 1, 1)
         ENDIF

         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         CALL PSII (IX)
C alternate between PFA and PFAS
         IF (MOD(IX,2) .EQ. 0)THEN
            CALL PFA (3, XA,YA)
         ELSE
            CALL PFAS (1,ENDPTS, XA,YA)
         ENDIF
         YLOC  = YLOC-YINCR
2300  CONTINUE

      CALL DCHPFV ('UNDEFINED INTERIOR COLOR INDICES: How many ' //
     1             'triangles are the same color as the star?',
     2             12, NUMDIS)

666   CONTINUE
      CALL ENDIT
      END
