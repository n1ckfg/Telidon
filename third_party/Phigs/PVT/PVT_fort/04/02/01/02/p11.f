C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/11                        *
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

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

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

      INTEGER    PICSTR,TXCI, NUMLT,NUMLW, STDDX,REGDX,IMPDX, LDX
      INTEGER    THISLT, LAVSLT(4), LAVRLT(100), LAVILT(IMPMAX)
      INTEGER    ITRIM,NUMDIS, CSIZ, CDIM, SZCOLT, NUMPAS, SZBT
      INTEGER    LNCOL(20), IX, VISDX,VISCOL, RNDINT, PLCI, NUMCI
      INTEGER    MAXCOL, COLEL, UNDF(3), EXPLCT, PERM(10), RTANS(10)

      REAL       THISLW, NOMLW,MINLW,MAXLW, YLOC,YINCR, XA(9),YA(9)
      PARAMETER (CSIZ = 6)
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ)
      REAL       TSTLW1,TSTLW2, MULT, RAD, CENTX,CENTY, PI

      CHARACTER  LDESCR(4)*14, PROMPT*200, LNTID*12, PFSW*1

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7
      REAL       RDUM1,RDUM2,RDUM3


      DATA  LDESCR / 'solid', 'dashed', 'dotted', 'dashed-dotted' /

      CALL INITGL ('04.02.01.02/11')

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

C  use <inquire polyline facilities> to determine:
C    numlt  = number of available linetypes
C    lavslt = list of available standard linetypes
C    lavrlt = list of available registered (non-mandatory) linetypes
C    lavilt = list of available implementor-defined linetypes
C             (may be derived directly from linetype value, if reported
C              number of linetypes < 0)
C    numlw  = number of available line-widths
C    nomlw  = nominal line-width (DC)
C    minlw,maxlw = minimum,maximum line-width (DC)
      CALL PQPLF (SPECWT,0, ERRIND, NUMLT,IDUM1,
     1            NUMLW,NOMLW,MINLW,MAXLW, IDUM2 )
      CALL CHKINQ ('pqplf', ERRIND)
C  szbt = maximum size of bundle table
      CALL PQWKSL (SPECWT, ERRIND, SZBT, IDUM1, IDUM2, IDUM3,
     1            IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      STDDX = 0
      REGDX = 0
      IMPDX = 0
      DO 100 LDX = 1,ABS(NUMLT)
         CALL PQPLF (SPECWT,LDX, ERRIND, IDUM1, THISLT,
     1               IDUM2,RDUM1,RDUM2,RDUM3, IDUM3)
         CALL CHKINQ ('pqplf', ERRIND)
         IF     (THISLT .GT. PLDASD) THEN
            REGDX = REGDX+1
            LAVRLT (REGDX) = THISLT
         ELSEIF (THISLT .GT. 0) THEN
            STDDX = STDDX+1
            LAVSLT (STDDX) = THISLT
         ELSE
            IF (IMPDX .LT. IMPMAX) THEN
               IF (NUMLT .LT. 0) THEN
C  build list from first LDX negative integers
                  IMPDX = IMPDX+1
                  LAVILT (IMPDX) = -LDX
               ELSE
                  IMPDX = IMPDX+1
                  LAVILT (IMPDX) = THISLT
               ENDIF
            ENDIF
         ENDIF
100   CONTINUE

C  *** *** ***   linetype

C  mark start of linetypes
      CALL PLB (1)

C set polyline bundle representation
      DO 150 IX = 1, STDDX
         CALL PSPLR (WKID, IX, LAVSLT(IX), 1.0, 1)
150   CONTINUE

C  Display in random order bundles 1 thru stddx
      CALL RNPERM (STDDX, PERM)
      XA(1) = 0.3
      XA(2) = 0.9
      YINCR = 0.8/STDDX
      YLOC  = 0.9
      CALL NUMLAB (STDDX, 0.2, YLOC, YINCR)

      DO 200 LDX = 1,STDDX
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PSPLI (LAVSLT(PERM(LDX)))
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

C  mark end of linetypes
      CALL PLB (2)

      CALL SETMSG ('3 4 5 6 35 36', 'The mandatory linetypes (1-4) ' //
     1             'should be recognizable from their standard '     //
     2             'description.')

C  Operator must identify each linetype according to official
C  English description: solid, dotted, dashed, dotted-dashed.
      PROMPT = 'MANDATORY LINETYPES: List, in order, the ' //
     1         'numeric labels for linetypes: ' // LDESCR(LAVSLT(1))
      RTANS(PERM(1)) = 1
      DO 300 LDX = 2,STDDX
         PROMPT(ITRIM(PROMPT)+1:) = ', ' // LDESCR(LAVSLT(LDX))
         RTANS(PERM(LDX)) = LDX
300   CONTINUE
      PROMPT(ITRIM(PROMPT)+1:) = '.'
      CALL DLSTPF (PROMPT, STDDX,RTANS, 'L')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  REGDX = size of lavrlt
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No non-mandatory registered linetypes are ' //
     1               'supported.')
         GOTO 890
      ENDIF

C select at most 8 linetypes in lavrlt
      NUMDIS = MIN(REGDX, 8, SZBT)
      CALL RNSET (NUMDIS, REGDX, PERM)
C  and sort them
      CALL SRTIAR (NUMDIS, PERM)
      CALL SRTIAR (REGDX, LAVRLT)

C  set polyline bundle representation
      DO 770 LDX = 1,NUMDIS
         CALL PSPLR (WKID, LDX, LAVRLT(PERM(LDX)), 1.0, 1)
770   CONTINUE

C  Display and label bundles with (some) linetypes from LAVRLT
      XA(1) = 0.5
      XA(2) = 0.9
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9

      DO 800 LDX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         THISLT = LAVRLT(PERM(LDX))
         WRITE (LNTID, '(A,I4,A)') 'Type#', THISLT, ':'
         CALL VISLAB (LNTID(1:10), 'R', 0.05,0.45,
     1                YLOC-0.3*YINCR, YLOC+0.3*YINCR)
         CALL PSPLI (LDX)
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
800   CONTINUE
      CALL SETMSG ('3 4 5 6 35 37', 'The registered non-mandatory ' //
     1             'linetypes (> 4) should agree with their '       //
     2             'registered description.')
      CALL DYNPF ('NON-MANDATORY REGISTERED LINETYPES: Is each '  //
     1            'linetype depicted according to its numeric '   //
     2            'identifier''s specification in the ISO register?',
     3            'Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  neg_type:
890   CONTINUE

C  IMPDX = size of lavilt
      IF (IMPDX .LT. 1) THEN
         CALL INMSG ('No implementor-defined linetypes are supported.')
         GOTO 990
      ENDIF
C select at most 8 bundles with linetypes from lavilt
      NUMDIS = MIN(IMPDX, 8, SZBT)
      CALL RNSET (NUMDIS, IMPDX, PERM)
C and sort them
      CALL SRTIAR (NUMDIS, PERM)
      CALL SRTIAR (IMPDX, LAVILT)

C set polyline bundle representation
      DO 870 LDX = 1, NUMDIS
         CALL PSPLR (WKID, LDX, LAVILT(PERM(LDX)), 1.0, 1)
870   CONTINUE

C  Display and label bundles with (some) linetypes from LAVILT
      XA(1) = 0.5
      XA(2) = 0.9
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9

      DO 900 LDX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         THISLT = LAVILT(PERM(LDX))
         WRITE (LNTID, '(A,I5,A)') 'Type#', THISLT, ':'
         CALL VISLAB (LNTID(1:11), 'R', 0.05,0.45,
     1                YLOC-0.3*YINCR, YLOC+0.3*YINCR)
         CALL PSPLI (LDX)
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
900   CONTINUE
      CALL SETMSG ('3 4 5 6 35 38', 'Implementor-defined linetypes ' //
     1             '(< 1) should agree with the descriptions '       //
     2             'supplied by the implementor.')
      CALL DYNPF ('IMPLEMENTOR DEFINED LINETYPES: Is each linetype ' //
     1            'depicted according to its numeric identifier''s ' //
     2            'specification in the implementor documentation?',
     3            'Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_linetype:
990   CONTINUE

C  *** *** ***   2. line-width

C  Are there at least two visually distinguishable line-widths?
      IF (NUMLW .EQ. 1          .OR.
     1    MAXLW .LE. 1.02*MINLW .OR.
     2    MAXLW-MINLW .LT. QVIS)    THEN
         TSTLW1 = MAXLW
         TSTLW2 = MAXLW
         MULT   = 2.0
      ELSE
         TSTLW1 = MINLW
         TSTLW2 = MAXLW
         IF (NUMLW .EQ. 0) THEN
C  continuous range of linewidths available - take 4 geometric steps
            MULT = 0.9999 * ((TSTLW2/TSTLW1) ** 0.25)
         ELSE
C  discrete set of linewidths available - test min/max only
            MULT = 0.9999 * (TSTLW2/TSTLW1)
         ENDIF
      ENDIF

C test scale sizes
C set up counter for number of sizes passed
      NUMPAS = 0
      THISLW = TSTLW1
C  loop thru various linewidths/next_lw:
1000  CONTINUE

C  invoke SHPLBW subroutine to test requested line width = thislw
C                                    expected line width = thislw
      CALL SHPLBW ('VARIOUS LINEWIDTH SCALE FACTORS', WKID,
     1              THISLW, THISLW, NOMLW, MINLW, PFSW)

      IF (PFSW .EQ. 'A') THEN
         IF (NUMPAS .LT. 2) THEN
            CALL INMSG ('Skipping test case for various scale '     //
     1                  'factors because largest valid line width ' //
     2                  'is greater than screen size.')
            GOTO 1110
         ELSE
            GOTO 1100
         ENDIF
      ELSEIF (PFSW .NE. 'P') THEN
         NUMPAS = 0
         GOTO 1100
      ENDIF
C  if PFSW = 'P', set up for next linewidth to be tested:
      NUMPAS = NUMPAS+1
      THISLW = THISLW * MULT
      IF (THISLW .LE. TSTLW2) GOTO 1000

1100  CONTINUE
      CALL SETMSG ('3 4 5 6 42 43 44', 'Available linewidth '   //
     1             'scale factors should control the realized ' //
     2             'thickness of a polyline.')
      CALL IFPF (NUMPAS.GT.0)

C  min_max_coerce:
1110  CONTINUE
      CALL SETMSG ('3 4 5 6 42 43 45', 'A requested positive ' //
     1             'linewidth scale factor below the minimum ' //
     2             'available should be realized as the minimum.')

      CALL SHPLBW ('POSITIVE LINEWIDTH BELOW MINIMUM', WKID,
     1              MINLW/2, MINLW, NOMLW, MINLW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

      CALL SETMSG ('3 4 5 6 42 43 45', 'A requested negative '     //
     1             'linewidth scale factor should be realized as ' //
     2             'the minimum.')
      CALL SHPLBW ('NEGATIVE LINEWIDTH', WKID,
     1             -MAXLW-100, MINLW, NOMLW, MINLW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

C test line width scale above maximum = maximum
      CALL SHPLBW ('POSITIVE LINEWIDTH ABOVE MAXIMUM', WKID,
     1              MAXLW*2, MAXLW, NOMLW, MINLW, PFSW)
      IF (PFSW .EQ. 'A') THEN
         CALL INMSG ('Skipping test case for requested scale factor ' //
     1               'greater than maximum because largest valid '    //
     2               'line width is greater than screen size.')
      ELSE
         CALL SETMSG ('3 4 5 6 42 43 45', 'A requested linewidth ' //
     1                'scale factor above the maximum available '  //
     2                'should be realized as the maximum.')
         CALL IFPF (PFSW .EQ. 'P')
      ENDIF

C  *** *** ***   3. polyline color index

      CALL SETMSG ('3 4 5 6 46 47 48', 'A defined polyline color '  //
     1             'index should cause the addressed entry in the ' //
     2             'color table to be used when rendering a polyline.')

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
C  how many lines to draw
      NUMDIS = MIN(SZCOLT, 8, SZBT)
C  from values 2 to SZCOLT-1, pick NUMDIS-2 entries
      CALL RNBSET (NUMDIS-2, 2, SZCOLT-1, LNCOL)
C  add in 0 and 1
      LNCOL(NUMDIS-1) = 1
      LNCOL(NUMDIS)   = 0
      CALL RNPERM (NUMDIS, PERM)

C  from lncol, randomly select entry #visdx, but not the one that
C    contains 0, since this may not be re-settable.
      VISDX  = RNDINT(1,NUMDIS-1)
      VISCOL = LNCOL(VISDX)

C  ensure dialogue visible
      DTXCI  = VISCOL
      CALL PSTXCI (VISCOL)
      YLOC  = 0.9
      YINCR = 0.8 / (NUMDIS-1)
      XA(1) = .2
      XA(2) = .9

      CALL NUMLAB (NUMDIS, .15, YLOC, YINCR)

C  for each color entry - set to background color
C                       - set bundle representation and draw line
      DO 2100 IX = 1,NUMDIS
         PLCI = LNCOL(PERM(IX))
         CALL PSCR (WKID, PLCI, CDIM, BCKCOL)
C  set entry lncol(vis) to forcol
         CALL PSPLR (WKID, IX, 1, 1.0, PLCI)
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PSPLI (IX)
         CALL PPL (2, XA,YA)
         YLOC  = YLOC-YINCR
2100  CONTINUE

C  set entry lncol(visdx) to forcol
      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)

      CALL DCHPF ('DEFINED POLYLINE COLOR INDICES: Which line ' //
     1            'is visible?', NUMDIS, VISDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 5 6 46 47 49', 'An undefined polyline '   //
     1             'color index should cause entry number 1 in '  //
     2             'the color table to be used when rendering a ' //
     3             'polyline.')

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

C  explct = number of explicit lines of color #1 = random integer
C  from 0 to 4, but don't overflow bundle table
      EXPLCT = RNDINT (0, MIN(4, SZBT-3))
      NUMDIS = EXPLCT+3
      CALL RNPERM (NUMDIS, PERM)

C  draw star with individual attributes:linetype=1, width=1, color index=1
C  set individual attributes
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

C  re-set to bundle attributes
      CALL SETASF (PBUNDL)
C  display interleaved:
C    three bundles with color u1,u2,u3,
C    explct bundles with color #1
      YLOC  = 0.5
      YINCR = 0.5 / 8
      XA(1) = .1
      XA(2) = .9
C  for each color entry - set to background color and draw line
      DO 2300 IX = 1,NUMDIS
         COLEL = PERM(IX)
         IF (COLEL .LE. 3) THEN
            CALL PSPLR (WKID, IX, 1, 1.0, UNDF(COLEL))
         ELSE
            CALL PSPLR (WKID, IX, 1, 1.0, 1)
         ENDIF
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PSPLI (IX)
         CALL PPL (2, XA,YA)
         YLOC  = YLOC-YINCR
2300  CONTINUE

      CALL DCHPFV ('UNDEFINED POLYLINE COLOR INDICES: How many '    //
     1             'of the horizontal lines are the same color as ' //
     2             'the star?', 12, NUMDIS)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
