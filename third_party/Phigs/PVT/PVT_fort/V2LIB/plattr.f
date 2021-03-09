      SUBROUTINE PLATTR (TSTYPE)

C  PLATTR tests polyline attributes, either individually, using the
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

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

      INTEGER    IMPMAX
      PARAMETER (IMPMAX = 600)

      INTEGER    PICSTR,TXCI, NUMLT,NUMLW, STDDX,REGDX,IMPDX, LDX
      INTEGER    THISLT, LAVSLT(4), LAVRLT(100), LAVILT(IMPMAX)
      INTEGER    ITRIM, MINILT,MAXILT, UNSUDX,LUNSUP(10), NUMDIS
      INTEGER    LINDIS(20), CDIM,CSIZ, SZCOLT, NUMLIN, NUMPAS
      INTEGER    LNCOL(20), IX, VISDX,VISCOL, RNDINT, PLCI, NUMCI
      INTEGER    MAXCOL, COLEL, UNDF(3), EXPLCT, PERM(10), RTANS(10)
      INTEGER    NDISCT, NDLNST, PLCOL, RANLST

      REAL       THISLW, NOMLW,MINLW,MAXLW, YLOC,YINCR, XA(9),YA(9)
      PARAMETER (CSIZ = 6)
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ)
      REAL       TSTLW1,TSTLW2, MULT, RAD, CENTX,CENTY, PI

      CHARACTER  LDESCR(4)*14, PROMPT*200, LNTID*12
      CHARACTER  PFSW*1, MSG*2600, TSTYPE*1, SUFFIX*70

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7
      REAL       RDUM1,RDUM2,RDUM3

      LOGICAL    NOZERO

      DATA  LDESCR / 'solid', 'dashed', 'dotted', 'dashed-dotted' /

      IF (TSTYPE .EQ. 'i' .OR. TSTYPE .EQ. 'c') THEN
C        tstype valid
      ELSE
         CALL UNMSG ('PLATTR called with TSTYPE = ' // TSTYPE)
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

C  use <inquire polyline facilities> to determine:
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

      IF (TSTYPE .EQ. 'c') THEN
C  ndisct = number of distinct foreground colors in color table.
         CALL DISCOL (8, WKID, NDISCT)
      ENDIF

C  *** *** ***   1. linetype

C  mark start of linetypes
      CALL PLB (1)

C  Display in random order all linetypes in lavslt
      CALL RNPERM (STDDX, PERM)
      XA(1) = 0.3
      XA(2) = 0.9
      YINCR = 0.8/STDDX
      YLOC  = 0.9
      IF (TSTYPE .EQ. 'c') THEN
         CALL NDLW (YINCR/2, NOMLW,MINLW)
      ENDIF
      CALL NUMLAB (STDDX, 0.2, YLOC, YINCR)

      DO 200 LDX = 1,STDDX
         YA(1) = YLOC
         YA(2) = YLOC
         IF (TSTYPE .EQ. 'c') THEN
            CALL PSPLCI (RNDINT (1, NDISCT))
         ENDIF
         CALL PSLN (LAVSLT(PERM(LDX)))
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

C  mark end of linetypes
      CALL PLB (2)

      IF (TSTYPE .EQ. 'c') THEN
         SUFFIX = ', even when a non-default linewidth or color ' //
     1            'is used.'
      ELSE
         SUFFIX = '.'
      ENDIF

      CALL SETMSG ('3 4 5 6 8', 'The mandatory linetypes (1-4) ' //
     1             'should be recognizable from their standard ' //
     2             'description' // SUFFIX)

C  Operator must identify each linetype according to official
C  English description: solid, dotted, dashed, dotted-dashed.
      PROMPT = 'MANDATORY LINETYPES: List, in order, the numeric ' //
     1         'labels for linetypes: ' // LDESCR(LAVSLT(1))
      RTANS(PERM(1)) = 1
      DO 300 LDX = 2,STDDX
         PROMPT(ITRIM(PROMPT)+1:) = ', ' // LDESCR(LAVSLT(LDX))
         RTANS(PERM(LDX)) = LDX
300   CONTINUE
      PROMPT(ITRIM(PROMPT)+1:) = '.'

      CALL DLSTPF (PROMPT, STDDX, RTANS, 'L')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C look for unsupported negative linetype
      IF (NUMLT .GT. 0) THEN
C  find negative linetype *not* in LAVILT and whether zero
C  is supported.
         NOZERO = .TRUE.
         MINILT = 0
         DO 400 LDX = 1,IMPDX
            IF (LAVILT(LDX) .EQ. 0) THEN
               NOZERO = .FALSE.
            ENDIF
            IF (LAVILT(LDX) .LT. MINILT) THEN
               MINILT = LAVILT(LDX)
            ENDIF
400      CONTINUE
C  LUNSUP is list of unsupported linetypes, indexed by UNSUDX
         IF (NOZERO) THEN
            UNSUDX = 1
            LUNSUP (UNSUDX) = 0
         ELSE
            UNSUDX = 0
         ENDIF
C  since this value is less than minimum of LAVILT, it's unsupported
         UNSUDX = UNSUDX+1
         LUNSUP (UNSUDX) = MINILT - 1
      ELSE
C  all non-positive linetypes supported - derived directly from linetype value
         UNSUDX = 0
      ENDIF

C now look for unsupported positive linetype
      MAXILT = 5
      DO 500 LDX = 1,REGDX
         IF (LAVRLT(LDX) .GT. MAXILT) THEN
            MAXILT = LAVRLT(LDX)
         ENDIF
500   CONTINUE
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = MAXILT + 1

C  now add to end of LUNSUP entry #1 and a non-solid linetype
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = 1

C  other = another available non-solid linetype: 2,3, or 4
      DO 600 LDX = 1,STDDX
         IF (LAVSLT(LDX) .GT. 1) THEN
C  this is the only one that should appear as non-solid
            UNSUDX = UNSUDX+1
            LUNSUP (UNSUDX) = LAVSLT(LDX)
            GOTO 610
         ENDIF
600   CONTINUE
C  no other available  - goto end_solid
      GOTO 690

610   CONTINUE

C  Display in random order linetypes in LUNSUP
      CALL RNPERM (UNSUDX, PERM)
      XA(1) = 0.3
      XA(2) = 0.9
      YINCR = 0.8/UNSUDX
      YLOC  = 0.9
      IF (TSTYPE .EQ. 'c') THEN
         CALL NDLW (YINCR/2, NOMLW,MINLW)
      ENDIF
      CALL NUMLAB (UNSUDX, 0.2, YLOC,YINCR)

      DO 700 LDX = 1,UNSUDX
         YA(1) = YLOC
         YA(2) = YLOC
         IF (TSTYPE .EQ. 'c') THEN
            CALL PSPLCI (RNDINT (1, NDISCT))
         ENDIF
         CALL PSLN (LUNSUP(PERM(LDX)))
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
700   CONTINUE

      CALL SETMSG ('3 4 5 6 7 8', 'Unavailable linetypes should be ' //
     1             'displayed as linetype number 1' // SUFFIX)
      CALL DCHPF ('UNSUPPORTED LINETYPES: Which line is NOT solid?',
     1             UNSUDX, UNSUDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_solid:
690   CONTINUE

C  REGDX = size of lavrlt
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No non-mandatory registered linetypes are ' //
     1               'supported.')
         GOTO 890
      ENDIF
C display and label at most 8 linetypes in lavrlt
      NUMDIS = MIN(8, REGDX)
      CALL RNSET (NUMDIS, REGDX, PERM)

C  build list of linetypes to be displayed
      DO 770 LDX = 1,NUMDIS
         LINDIS(LDX) = LAVRLT(PERM(LDX))
770   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, LINDIS)

C  Display in order (some) linetypes in LAVRLT
      XA(1) = 0.5
      XA(2) = 0.9
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9
      IF (TSTYPE .EQ. 'c') THEN
         CALL NDLW (YINCR/2, NOMLW,MINLW)
      ENDIF

      DO 800 LDX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         THISLT = LINDIS(LDX)
         WRITE (LNTID, '(A,I2,A)') 'Type#', THISLT, ':'
         CALL VISLAB (LNTID(1:8), 'R', 0.05,0.45,
     1                YLOC-0.3*YINCR, YLOC+0.3*YINCR)
         IF (TSTYPE .EQ. 'c') THEN
            CALL PSPLCI (RNDINT (1, NDISCT))
         ENDIF
         CALL PSLN (THISLT)
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
800   CONTINUE
      CALL SETMSG ('3 4 5 6 9', 'The registered non-mandatory '       //
     1             'linetypes (> 4) should agree with their '         //
     2             'registered description' // SUFFIX)
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
C display and label at most 8 linetypes in lavilt
      NUMDIS = MIN(8, IMPDX)
      CALL RNSET (NUMDIS, IMPDX, PERM)

C  build list of linetypes to be displayed
      DO 870 LDX = 1,NUMDIS
         LINDIS(LDX) = LAVILT(PERM(LDX))
870   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, LINDIS)

C  Display (some) linetypes in LAVILT
      XA(1) = 0.5
      XA(2) = 0.9
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9
      IF (TSTYPE .EQ. 'c') THEN
         CALL NDLW (YINCR/2, NOMLW,MINLW)
      ENDIF

      DO 900 LDX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         THISLT = LINDIS(LDX)
         WRITE (LNTID, '(A,I5,A)') 'Type#', THISLT, ':'
         CALL VISLAB (LNTID(1:11), 'R', 0.05,0.45,
     1                YLOC-0.3*YINCR, YLOC+0.3*YINCR)
         IF (TSTYPE .EQ. 'c') THEN
            CALL PSPLCI (RNDINT (1, NDISCT))
         ENDIF
         CALL PSLN (THISLT)
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
900   CONTINUE
      CALL SETMSG ('3 4 5 6 10', 'Implementor-defined linetypes (< ' //
     1             '1) should agree with the descriptions supplied ' //
     2             'by the implementor' // SUFFIX)
      CALL DYNPF ('IMPLEMENTOR DEFINED LINETYPES: Is each linetype ' //
     1            'depicted according to its numeric identifier''s ' //
     2            'specification in the implementor documentation?',
     3            'Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  Check if all implementor linetypes already shown or
C  linetype appearance derived directly from value - if so, skip test
      IF (IMPDX .LE. 8 .OR. NUMLT .LT. 0) GOTO 990
      IF (TSTYPE .EQ. 'c') GOTO 990

      CALL SETMSG ('10', 'All reported implementor-defined '      //
     1             'linetypes available for a given workstation ' //
     2             'type should be documented by the implementor.')

      CALL SRTIAR (IMPDX, LAVILT)
      WRITE (MSG, '(500I5)') (LAVILT(LDX), LDX=1,IMPDX)
      CALL DYNPF ('COMPLETE DOCUMENTATION FOR IMPLEMENTOR LINETYPES: '//
     1            'Are all these reportedly available linetypes '     //
     2            'documented by the implementor?' // MSG, 'Y')

C  end_linetype:
990   CONTINUE

C  *** *** ***   2. line-width

      IF (TSTYPE .EQ. 'c') THEN
         SUFFIX = ', even when a non-default linetype ' //
     3            'or color is used.'
      ELSE
         SUFFIX = '.'
         NDLNST = 1
         PLCOL  = 1
      ENDIF

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

      IF (TSTYPE .EQ. 'c') THEN
C  random linetype and color:
         NDLNST = RANLST (STDDX,LAVSLT, REGDX,LAVRLT, IMPDX,LAVILT)
         PLCOL  = RNDINT (1, NDISCT)
      ENDIF
C  invoke SHOWLW subroutine to test requested line width = thislw
C                                    expected line width = thislw
      CALL SHOWLW ('VARIOUS LINEWIDTH SCALE FACTORS', NDLNST, PLCOL,
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
      CALL SETMSG ('3 13 14 15', 'Available linewidth scale '       //
     1             'factors should control the realized thickness ' //
     2             'of a polyline' // SUFFIX)
      CALL IFPF (NUMPAS.GT.0)

C  min_max_coerce:
1110  CONTINUE
      CALL SETMSG ('3 13 14 16', 'A requested positive linewidth '    //
     1             'scale factor below the minimum available should ' //
     2             'be realized as the minimum' // SUFFIX)

      IF (TSTYPE .EQ. 'c') THEN
C  random linetype and color:
         NDLNST = RANLST (STDDX,LAVSLT, REGDX,LAVRLT, IMPDX,LAVILT)
         PLCOL  = RNDINT (1, NDISCT)
      ENDIF
      CALL SHOWLW ('POSITIVE LINEWIDTH BELOW MINIMUM', NDLNST, PLCOL,
     1              MINLW/2, MINLW, NOMLW, MINLW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

      CALL SETMSG ('3 13 14 16', 'A requested negative linewidth '  //
     1             'scale factor should be realized as the minimum' //
     2             SUFFIX)
      IF (TSTYPE .EQ. 'c') THEN
C  random linetype and color:
         NDLNST = RANLST (STDDX,LAVSLT, REGDX,LAVRLT, IMPDX,LAVILT)
         PLCOL  = RNDINT (1, NDISCT)
      ENDIF
      CALL SHOWLW ('NEGATIVE LINEWIDTH', NDLNST, PLCOL,
     1             -MAXLW-100, MINLW, NOMLW, MINLW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

C test line width scale above maximum = maximum
      IF (TSTYPE .EQ. 'c') THEN
C  random linetype and color:
         NDLNST = RANLST (STDDX,LAVSLT, REGDX,LAVRLT, IMPDX,LAVILT)
         PLCOL  = RNDINT (1, NDISCT)
      ENDIF
      CALL SHOWLW ('POSITIVE LINEWIDTH ABOVE MAXIMUM', NDLNST, PLCOL,
     1              MAXLW*2, MAXLW, NOMLW, MINLW, PFSW)
      IF (PFSW .EQ. 'A') THEN
         CALL INMSG ('Skipping test case for requested scale factor ' //
     1               'greater than maximum because largest valid '    //
     2               'line width is greater than screen size.')
      ELSE
         CALL SETMSG ('3 13 14 16', 'A requested linewidth scale '    //
     1                'factor above the maximum available should be ' //
     2                'realized as the maximum' // SUFFIX)
         CALL IFPF (PFSW .EQ. 'P')
      ENDIF

C  *** *** ***   3. polyline color index

      IF (TSTYPE .EQ. 'c') THEN
         SUFFIX = ', even when a non-default linetype ' //
     3            'or linewidth is used.'
      ELSE
         SUFFIX = '.'
      ENDIF

      CALL SETMSG ('3 19 20 21', 'A defined polyline color index '  //
     1             'should cause the addressed entry in the color ' //
     2             'table to be used when rendering a polyline'     //
     3             SUFFIX)

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
      NUMLIN = MIN(8, SZCOLT)
C  from values 2 to SZCOLT-1, pick NUMLIN-2 entries
      CALL RNBSET (NUMLIN-2, 2, SZCOLT-1, LNCOL)
C  add in 0 and 1
      LNCOL(NUMLIN-1) = 1
      LNCOL(NUMLIN)   = 0
      CALL RNPERM (NUMLIN, PERM)

C  from lncol, randomly select entry #visdx, but not the one that
C    contains 0, since this may not be re-settable.
      VISDX  = RNDINT(1,NUMLIN-1)
      VISCOL = LNCOL(VISDX)

C  ensure dialogue visible
      DTXCI  = VISCOL
      CALL PSTXCI (VISCOL)
      YLOC  = 0.9
      YINCR = 0.8 / (NUMLIN-1)
      XA(1) = .2
      XA(2) = .9

      IF (TSTYPE .EQ. 'c') THEN
C  non-default linewidth
         CALL NDLW (YINCR/2, NOMLW,MINLW)
      ENDIF
      CALL NUMLAB (NUMLIN, .15, YLOC, YINCR)

C  for each color entry - set to background color and draw line
      DO 2100 IX = 1,NUMLIN
         PLCI = LNCOL(PERM(IX))
         CALL PSCR (WKID, PLCI, CDIM, BCKCOL)
         CALL PSPLCI (PLCI)
         IF (TSTYPE .EQ. 'c') THEN
C  random linetype
            CALL PSLN (RANLST(STDDX,LAVSLT, REGDX,LAVRLT, IMPDX,LAVILT))
         ENDIF
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL (2, XA,YA)
         YLOC  = YLOC-YINCR
2100  CONTINUE

C  set entry lncol(visdx) to forcol
      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)

      CALL DCHPF ('DEFINED POLYLINE COLOR INDICES: Which line ' //
     1            'is visible?', NUMLIN, VISDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 19 20 22 ', 'An undefined polyline color '     //
     1             'index should cause entry number 1 in the color ' //
     2             'table to be used when rendering a polyline'      //
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

C  explct = number of explicit lines of color #1 = random integer
C  from 0 to 4
      EXPLCT = RNDINT(0,4)
      NUMLIN = EXPLCT+3
      CALL RNPERM (NUMLIN, PERM)

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
C    three lines of color u1,u2,u3,
C    explct lines of color #1
      YLOC  = 0.5
      YINCR = 0.5 / 8
      XA(1) = .1
      XA(2) = .9

      IF (TSTYPE .EQ. 'c') THEN
C  non-default linewidth
         CALL NDLW (YINCR/2, NOMLW,MINLW)
      ENDIF

C  for each color entry - set to background color and draw line
      DO 2300 IX = 1,NUMLIN
         COLEL = PERM(IX)
         IF (COLEL .LE. 3) THEN
            CALL PSPLCI (UNDF(COLEL))
         ELSE
            CALL PSPLCI (1)
         ENDIF
         IF (TSTYPE .EQ. 'c') THEN
C  random linetype
            CALL PSLN (RANLST(STDDX,LAVSLT, REGDX,LAVRLT, IMPDX,LAVILT))
         ENDIF
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL (2, XA,YA)
         YLOC  = YLOC-YINCR
2300  CONTINUE

      CALL DCHPFV ('UNDEFINED POLYLINE COLOR INDICES: How many '    //
     1             'of the horizontal lines are the same color as ' //
     2             'the star?', 12, NUMLIN)

666   CONTINUE
C  wrap it up.
      END
