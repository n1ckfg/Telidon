C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.01/03                        *
C  *    TEST TITLE : Appearance of individual edge         *
C  *                 attributes                            *
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

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C edge flag indicator
      INTEGER    POFF,   PON
      PARAMETER (POFF=0, PON=1)

C edgetype  (linetype)
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

      INTEGER    PICSTR,TXCI, NUMET, COLA
      INTEGER    NUMEW, STDDX,REGDX,IMPDX, EDX, NPTS(1), FILON
      INTEGER    THISET, LAVSET(4), LAVRET(100), LAVIET(IMPMAX)
      INTEGER    ITRIM, MINIET,MAXIET, UNSUDX,LUNSUP(10), NUMDIS
      INTEGER    LINDIS(20), CDIM,CSIZ, SZCOLT, NUMFIL, NUMPAS
      INTEGER    IX, VISDX,VISCOL, RNDINT, EDCI, NUMCI, SIZ
      INTEGER    MAXCOL, COLEL, UNDF(3), EXPLCT, PERM(10), RTANS(10)
      INTEGER    NFASET, FASCOL(20)

      REAL       THISEW, NOMEW,MINEW,MAXEW, YLOC,YINCR, XA(9),YA(9)
      PARAMETER (CSIZ = 6)
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ),CC(9)
      REAL       TSTEW1,TSTEW2, MULT, RAD, CENTX,CENTY, PI, MINLW
      PARAMETER (PI = 3.14159265)

      CHARACTER  LDESCR(4)*14, PROMPT*200, LNTID*12
      CHARACTER  PFSW*1, MSG*2600
      CHARACTER  LDESIS(PHOLLO:PISEMP)*14

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7
      REAL       RDUM1,RDUM2,RDUM3

      LOGICAL    NOZERO

      DATA  LDESIS / 'hollow','solid','pattern','hatch','empty' /
      DATA  LDESCR / 'solid', 'dashed', 'dotted', 'dashed-dotted' /

      CALL INITGL ('04.02.05.01/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  set interior style EMPTY and edge flag ON as default
      CALL PSIS (PISEMP)
      CALL PSEDFG (PON)

C  use <inquire edge facilities> to determine:
C    numet  = number of available edgetypes
C    lavset = list of available standard edgetypes
C    lavret = list of available registered (>4) edgetypes
C    laviet = list of available implementor-defined edgetypes
C             (may be derived directly from edgetype value, if
C              reported number of edgetypes <0)
C    numew  = number of available edge-widths
C    nomew  = nominal edge-width (DC)
C    minew,maxew = minimum,maximum edge-width (DC)
      CALL PQEDF (SPECWT,0,ERRIND, NUMET,IDUM1,NUMEW,
     1            NOMEW, MINEW, MAXEW, IDUM2)
      CALL CHKINQ ('pqedf',ERRIND)
      STDDX = 0
      REGDX = 0
      IMPDX = 0
      DO 150 EDX = 1,ABS(NUMET)
         CALL PQEDF (SPECWT,EDX, ERRIND, IDUM1, THISET,
     1               IDUM2,RDUM1,RDUM2,RDUM3, IDUM3)
         CALL CHKINQ ('pqedf', ERRIND)
         IF  (THISET .GT. PLDASD) THEN
            REGDX = REGDX+1
            LAVRET (REGDX) = THISET
         ELSEIF (THISET .GT. 0) THEN
            STDDX = STDDX +1
            LAVSET (STDDX) = THISET
         ELSE
            IF (IMPDX .LT. IMPMAX) THEN
               IMPDX = IMPDX+1
               IF (NUMET .LT. 0) THEN
C  build list from first EDX negative integers
                  LAVIET (IMPDX) = -EDX
               ELSE
                  LAVIET (IMPDX) = THISET
               ENDIF
            ENDIF
         ENDIF
150   CONTINUE

C  *** *** *** edge flag indicator

C  mark start of edge flag
      CALL PLB (1)

C filon = number of rectangles to be drawn with edge flag ON =
C         random number 1 - 8
C and 8-filon rectangles to be drawn with edge flag OFF
      FILON = RNDINT (1,8)
      CALL RNPERM (8, PERM)
      CALL SETRVS ('0.3,0.9,0.9,0.3', XA, SIZ)
      YINCR = 0.8/8
      YLOC  = 0.85
      CALL NUMLAB (8, 0.2, YLOC, YINCR)

      NPTS(1) = 4
      DO 40 EDX = 1, 8
         YA(1) = YLOC - 0.3*YINCR
         YA(2) = YLOC - 0.3*YINCR
         YA(3) = YLOC + 0.3*YINCR
         YA(4) = YLOC + 0.3*YINCR
         RTANS(PERM(EDX)) = EDX
         IF (PERM(EDX) .LE. FILON) THEN
            CALL PSEDFG (PON)
         ELSE
            CALL PSEDFG (POFF)
         ENDIF
         CALL PFAS (1, NPTS, XA, YA)
         YLOC = YLOC - YINCR
40    CONTINUE

C  mark end of edge flag
      CALL PLB (2)

      CALL SETMSG ('4 32 33 34 35 36', 'The edge of a polygonal '  //
     1             'area should be visible when the edge flag is ' //
     2             'on and not visible when the edge flag is off.')

C Operator must identify the rectangles with visible edges.
      PROMPT = 'EDGE FLAG INDICATOR: List the numeric labels for ' //
     1         'all rectangles with visible edges.'

      CALL DLSTPF (PROMPT, FILON, RTANS, 'S')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C edge vs boundary test
C <inquire color facilities>, if monochrome skip tests
      CALL PQCF (SPECWT, ERRIND, IDUM1, COLA, IDUM2, CC)
      CALL CHKINQ ('pqcf', ERRIND)
C  szcolt = maximum size of color table (including entry #0)
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             SZCOLT, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (COLA .EQ. PMONOC .OR. SZCOLT .LE. 2) THEN
         CALL INMSG ('This workstation does not support more than ' //
     1               'one foreground color; skipping test because ' //
     2               'edge cannot be distinguished from boundary.')
         GOTO 95
      ENDIF

      CALL SETMSG ('4 10 32 34 35 36 37', 'The edges of fill area ' //
     1             'sets should be drawn on top of the interior.')

C  bckcol = background color = realized color spec for entry #0
C  forcol = foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 0, CSIZ, PREALI, ERRIND, CDIM, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL PQCR (WKID, 1, CSIZ, PREALI, ERRIND, CDIM, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  set entry #2 different from BCKCOL and FORCOL
      DO 80 IX = 1,3
         IF (BCKCOL(IX) .GT. 0.5) THEN
            NEWCOL(IX) = 0.0
         ELSE
            NEWCOL(IX) = 1.0
         ENDIF
80    CONTINUE
      IF (FORCOL(3) .GT. 0.5) THEN
         NEWCOL(3) = 0.0
      ELSE
         NEWCOL(3) = 1.0
      ENDIF
      CALL PSCR  (WKID, 2, CDIM, NEWCOL)

C set interior style HOLLOW
      CALL PSIS (PHOLLO)
C set edge flag on
      CALL PSEDFG (PON)
C set interior color index = #1
      CALL PSICI (1)
C set edge color index = #2
      CALL PSEDCI (2)

C  draw star with color #2
      RAD = .15
      CENTX = .5
      CENTY = .75
      DO 60 IX = 1,6
         YA(IX) = CENTY + RAD*COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD*SIN((4*PI*IX)/5)
60    CONTINUE
      CALL PSPLCI (2)
      CALL PPL (6,XA,YA)

C nfaset = number of fill area sets = random number 1-5
C display interleaved: nfaset fill area sets, 6-nfaset fill areas
      NFASET = RNDINT (1,5)
      CALL RNPERM (6, PERM)
      CALL SETRVS ('0.2,0.8,0.8,0.2', XA, SIZ)
      YINCR = 0.5 / 7
      YLOC  = 0.5
      CALL NUMLAB (6, 0.12, YLOC, YINCR)

      NPTS(1) = 4
      DO 70 IX = 1, 6
         YA(1) = YLOC - 0.3*YINCR
         YA(2) = YLOC - 0.3*YINCR
         YA(3) = YLOC + 0.3*YINCR
         YA(4) = YLOC + 0.3*YINCR
         RTANS(PERM(IX)) = IX
         IF (PERM(IX) .LE. NFASET) THEN
            CALL PFAS (1, NPTS, XA, YA)
         ELSE
            CALL PFA (NPTS(1), XA, YA)
         ENDIF
         YLOC = YLOC - YINCR
70    CONTINUE

      CALL DLSTPF ('EDGE OVERLAYS INTERIOR: List the numeric labels ' //
     1             'for all rectangles whose outermost edges are '    //
     2             'the same color as the star.', NFASET,RTANS, 'S')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

95    CONTINUE

C  *** *** ***   edgetype

C  Display in random order all edgetypes in lavset
      CALL RNPERM (STDDX, PERM)
      CALL SETRVS ('0.3,0.7,0.5', XA, SIZ)
      YINCR = 0.8/STDDX
      YLOC  = 0.85
      CALL NUMLAB (STDDX, 0.2, YLOC+.05, YINCR)
      NPTS(1) = 3

      DO 200 EDX = 1,STDDX
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + 0.6*YINCR
         CALL PSEDT (LAVSET(PERM(EDX)))
         CALL PFAS (1, NPTS,  XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

      CALL SETMSG ('4 36 40 41 42 44', 'The edgetypes (1-4) '    //
     1             'should be recognizable from their standard ' //
     2             'description.' )

C  Operator must identify each edgetype according to official
C  English description: solid, dotted, dashed, dotted-dashed.
      PROMPT = 'STANDARD EDGETYPES: List, in order, the numeric ' //
     1         'labels for edgetypes: ' // LDESCR(LAVSET(1))
      RTANS(PERM(1)) = 1
      DO 300 EDX = 2,STDDX
         PROMPT(ITRIM(PROMPT)+1:) = ', ' // LDESCR(LAVSET(EDX))
         RTANS(PERM(EDX)) = EDX
300   CONTINUE
      PROMPT(ITRIM(PROMPT)+1:) = '.'
      CALL DLSTPF (PROMPT, STDDX,RTANS, 'L')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C look for unsupported negative edgetype
      IF (NUMET .GT. 0) THEN
C  find negative edgetype *not* in LAVIET and whether zero
C  is supported.
         NOZERO = .TRUE.
         MINIET = 0
         DO 400 EDX = 1,IMPDX
            IF (LAVIET(EDX) .EQ. 0) THEN
               NOZERO = .FALSE.
            ENDIF
            MINIET = MIN(MINIET, LAVIET(EDX))
400      CONTINUE
C  LUNSUP is list of unsupported edgetypes, indexed by UNSUDX
         IF (NOZERO) THEN
            UNSUDX = 1
            LUNSUP (UNSUDX) = 0
         ELSE
            UNSUDX = 0
         ENDIF
C  since this value is less than minimum of LAVIET, it's unsupported
         UNSUDX = UNSUDX+1
         LUNSUP (UNSUDX) = MINIET - 1
      ELSE
C  all non-positive edgetypes supported - derived directly from edgetype value
         UNSUDX = 0
      ENDIF

C now look for unsupported positive edgetype
      MAXIET = STDDX+1
      DO 500 EDX = 1,REGDX
         MAXIET = MAX(MAXIET, LAVRET(EDX))
500   CONTINUE
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = MAXIET + 1

C  now add to end of LUNSUP entry #1 and a simulated edgetype
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = 1
C  other = simulate using polylines and linetype PLDOT
C  this is the only one that should appear as non-solid
      UNSUDX = UNSUDX+1

C  Display in random order edgetypes in LUNSUP
      CALL RNPERM (UNSUDX, PERM)
      CALL SETRVS ('0.3,0.9,0.9,0.3', XA, SIZ)
      YINCR = 0.8/UNSUDX
      YLOC  = 0.85
      CALL NUMLAB (UNSUDX, 0.2, YLOC+.05,YINCR)
      NPTS(1) = 4

      DO 700 EDX = 1,UNSUDX
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         YA(4) = YLOC + YINCR/2
         IF (PERM(EDX) .EQ. UNSUDX) THEN
C simulate rectangle with PLDOT
            CALL PSLN (PLDOT)
            CALL DRWREC (.3, .9, YLOC, YLOC + YINCR/2)
         ELSE
            CALL PSEDT (LUNSUP(PERM(EDX)))
            CALL PFAS  (1, NPTS, XA,YA)
         ENDIF
         YLOC  = YLOC-YINCR
700   CONTINUE

      CALL SETMSG ('4 36 40 41 42 43 44', 'Unavailable edgetypes ' //
     1             'should be displayed as edgetype number 1.')
      CALL DCHPF ('UNSUPPORTED EDGETYPES: Which rectangle has ' //
     1            'a non-solid edge?', UNSUDX, UNSUDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_solid:

C  REGDX = size of lavrlt
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No registered edgetypes beyond those defined ' //
     1               'in the standard (1-4) are supported.')
         GOTO 890
      ENDIF
C display and label at most 8 edgetypes in lavrlt
      NUMDIS = MIN(8, REGDX)
      CALL RNSET (NUMDIS, REGDX, PERM)

C  build list of edgetypes to be displayed
      DO 770 EDX = 1,NUMDIS
         LINDIS(EDX) = LAVRET(PERM(EDX))
770   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, LINDIS)

C  Display in order (some) edgetypes in LAVRET
      CALL SETRVS ('0.5,0.9,0.7', XA, SIZ)
      YINCR = 0.8/NUMDIS
      YLOC  = 0.85
      NPTS(1) = 3

      DO 800 EDX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + 0.6*YINCR
         THISET = LINDIS(EDX)
         WRITE (LNTID, '(A,I2,A)') 'Type#', THISET, ':'
         CALL VISLAB (LNTID(1:8), 'R', 0.05,0.45,
     1                YLOC, YLOC+0.6*YINCR)
         CALL PSEDT (THISET)
         CALL PFAS  (1, NPTS, XA,YA)
         YLOC  = YLOC-YINCR
800   CONTINUE
      CALL SETMSG ('4 36 40 41 42 45', 'The appearance of the '    //
     1             'registered edgetypes (> 4) should agree with ' //
     2             'their registered description.')
      CALL DYNPF ('REGISTERED EDGETYPES: Is each edgetype depicted ' //
     1            'according to its numeric identifier''s '          //
     2            'specification in the ISO register?', 'Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  neg_type:
890   CONTINUE

C  IMPDX = size of laviet
      IF (IMPDX .LT. 1) THEN
         CALL INMSG ('No implementor-defined edgetypes are supported.')
         GOTO 990
      ENDIF
C display and label at most 8 edgetypes in laviet
      NUMDIS = MIN(8, IMPDX)
      CALL RNSET (NUMDIS, IMPDX, PERM)

C  build list of edgetypes to be displayed
      DO 870 EDX = 1,NUMDIS
         LINDIS(EDX) = LAVIET(PERM(EDX))
870   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, LINDIS)

C  Display (some) edgetypes in LAVIET
      CALL SETRVS ('0.5,0.9,0.7', XA, SIZ)
      YINCR = 0.8/NUMDIS
      YLOC  = 0.85
      NPTS(1) = 3
      DO 900 EDX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + 0.6*YINCR
         THISET = LINDIS(EDX)
         WRITE (LNTID, '(A,I5,A)') 'Type#', THISET, ':'
         CALL VISLAB (LNTID(1:11), 'R', 0.05,0.45,
     1                YLOC, YLOC+0.6*YINCR)
         CALL PSEDT (THISET)
         CALL PFAS  (1, NPTS, XA,YA)
         YLOC  = YLOC-YINCR
900   CONTINUE

      CALL SETMSG ('4 36 40 41 42 46', 'The appearance of the '   //
     1             'implementor defined edgetypes (< 1) should '  //
     2             'agree with the descriptions supplied by the ' //
     3             'implementor.')
      CALL DYNPF ('IMPLEMENTOR DEFINED EDGETYPES: Is each edgetype ' //
     1            'depicted according to its numeric identifier''s ' //
     2            'specification in the implementor documentation?',
     3            'Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  Check if all implementor edgetypes already shown or
C  edgetype appearance derived directly from value - if so, skip test
      IF (IMPDX .LE. 8 .OR. NUMET .LT. 0) GOTO 990

      CALL SETMSG ('46', 'All reported implementor-defined '      //
     1             'edgetypes available for a given workstation ' //
     2             'type should be documented by the implementor.')

      CALL SRTIAR (IMPDX, LAVIET)
      WRITE (MSG, '(500I5)') (LAVIET(EDX), EDX=1,IMPDX)
      CALL DYNPF ('COMPLETE DOCUMENTATION FOR IMPLEMENTOR EDGETYPES: '//
     1            'Are all these reportedly available edgetypes '     //
     2            'documented by the implementor?' // MSG, 'Y')

C  end_edgetype:
990   CONTINUE

C  *** *** ***   edgewidth

C  need MINLW to let SHOWEW simulate edge
      CALL PQPLF (SPECWT,0, ERRIND, IDUM1,IDUM2,IDUM3,RDUM1,MINLW,
     1            RDUM2,IDUM4)
      CALL CHKINQ ('pqplf', ERRIND)

C  Are there at least two visually distinguishable line-widths?
      IF (NUMEW .EQ. 1          .OR.
     1    MAXEW .LE. 1.02*MINEW .OR.
     2    MAXEW-MINEW .LT. QVIS)    THEN
         TSTEW1 = MAXEW
         TSTEW2 = MAXEW
         MULT   = 2.0
      ELSE
         TSTEW1 = MINEW
         TSTEW2 = MAXEW
         IF (NUMEW .EQ. 0) THEN
C  continuous range of edgewidths available - take 4 geometric steps
            MULT = 0.9999 * ((TSTEW2/TSTEW1) ** 0.25)
         ELSE
C  discrete set of edgewidths available - test min/max only
            MULT = 0.9999 * (TSTEW2/TSTEW1)
         ENDIF
      ENDIF

C test scale sizes
C set up counter for number of sizes passed
      NUMPAS = 0
      THISEW = TSTEW1
C  loop thru various edgewidths/next_ew:
1000  CONTINUE

C  invoke SHOWEW subroutine to test requested edge width = thisew
C                                    expected edge width = thisew
      CALL SHOWEW ('VARIOUS EDGEWIDTH SCALE FACTORS',
     1              THISEW, THISEW, NOMEW, MINLW, PFSW)

      IF (PFSW .EQ. 'A') THEN
         IF (NUMPAS .LT. 2) THEN
            CALL INMSG ('Skipping test case for various scale '     //
     1                  'factors because largest valid edge width ' //
     2                  'is greater than screen size.')
            GOTO 1110
         ELSE
            GOTO 1100
         ENDIF
      ELSEIF (PFSW .NE. 'P') THEN
         NUMPAS = 0
         GOTO 1100
      ENDIF
C  if PFSW = 'P', set up for next edgewidth to be tested:
      NUMPAS = NUMPAS+1
      THISEW = THISEW * MULT
      IF (THISEW .LE. TSTEW2) GOTO 1000

1100  CONTINUE
      CALL SETMSG ('4 36 49 50 51', 'Available edgewidth scale '    //
     1             'factors should control the realized thickness ' //
     2             'of an edge.')
      CALL IFPF (NUMPAS.GT.0)

C  min_max_coerce:
1110  CONTINUE
      CALL SETMSG ('4 36 49 50 52', 'A requested positive edgewidth ' //
     1             'scale factor below the minimum available should ' //
     2             'be realized as the minimum.')
      CALL SHOWEW ('POSITIVE EDGEWIDTH BELOW MINIMUM',
     1              MINEW/2, MINEW, NOMEW, MINLW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

      CALL SETMSG ('4 36 49 50 52', 'A requested negative edgewidth ' //
     1             'scale factor should be realized as the minimum.')
      CALL SHOWEW ('NEGATIVE EDGEWIDTH',
     1             -MAXEW-100, MINEW, NOMEW, MINLW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

C test edge width scale above maximum = maximum
      CALL SHOWEW ('POSITIVE EDGEWIDTH ABOVE MAXIMUM',
     1              MAXEW*2, MAXEW, NOMEW, MINLW, PFSW)
      IF (PFSW .EQ. 'A') THEN
         CALL INMSG ('Skipping test case for requested scale factor ' //
     1               'greater than maximum because largest valid '    //
     2               'edge width is greater than screen size.')
      ELSE
         CALL SETMSG ('4 36 49 50 52', 'A requested edgewidth scale ' //
     1                'factor above the maximum available should be ' //
     2                'realized as the maximum.')
         CALL IFPF (PFSW .EQ. 'P')
      ENDIF

C  *** *** ***   edge color index

      CALL SETMSG ('4 36 55 56 57', 'A defined edge color index '   //
     1             'should cause the addressed entry in the color ' //
     2             'table to be used when rendering the edge of a ' //
     3             'polygonal area.')

C  bckcol = background color = realized color spec for entry #0
C  forcol = foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 0, CSIZ, PREALI, ERRIND, CDIM, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL PQCR (WKID, 1, CSIZ, PREALI, ERRIND, CDIM, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  how many fill areas to draw
      NUMFIL  = MIN(8, SZCOLT)
C  from values 2 to SZCOLT-1, pick NUMFIL-2 entries
      CALL RNBSET (NUMFIL-2, 2, SZCOLT-1, FASCOL)
C  add in 0 and 1
      FASCOL(NUMFIL-1) = 1
      FASCOL(NUMFIL)   = 0
      CALL RNPERM (NUMFIL, PERM)

C  from fascol, randomly select entry #visdx, but not the one that
C    contains 0, since this may not be re-settable.
      VISDX  = RNDINT(1,NUMFIL-1)
      VISCOL = FASCOL(VISDX)

C  ensure dialogue visible
      DTXCI  = VISCOL
      CALL PSTXCI (VISCOL)
      YLOC  = 0.9
      YINCR = 0.8 / (NUMFIL-1)
      CALL SETRVS ('0.3,0.7,0.5', XA, SIZ)
      CALL NUMLAB (NUMFIL, .25, YLOC + 0.3*YINCR, YINCR)
      NPTS(1) = 3

C  for each color entry - set to background color and draw line
      DO 2100 IX = 1,NUMFIL
         EDCI = FASCOL(PERM(IX))
         CALL PSCR (WKID, EDCI, CDIM, BCKCOL)
         CALL PSEDCI (EDCI)
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + 0.6*YINCR
         CALL PFAS (1, NPTS, XA,YA)
         YLOC  = YLOC-YINCR
2100  CONTINUE

      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)

      CALL DCHPF ('DEFINED EDGE COLOR INDICES: Which triangle ' //
     1            'is visible?', NUMFIL, VISDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('4 36 55 56 58', 'An undefined edge color index ' //
     1             'should cause entry number 1 in the color table ' //
     2             'to be used when rendering the edge of a '        //
     3             'polygonal area.')

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

C  explct = number of explicit fill area sets of color #1 = random integer
C  from 0 to 4
      EXPLCT = RNDINT(0,4)
      NUMFIL = EXPLCT+3
      CALL RNPERM (NUMFIL, PERM)

C  draw star with color #1
      RAD = .15
      CENTX = .5
      CENTY = .75
      DO 2400 IX = 1,6
         YA(IX) = CENTY + RAD*COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD*SIN((4*PI*IX)/5)
2400  CONTINUE
      CALL PSPLCI (1)
      CALL PPL (6,XA,YA)

C  display interleaved:
C    three fill area sets of color u1,u2,u3,
C    explct fill area sets of color #1
      YLOC  = 0.5
      YINCR = 0.5 / 8
      CALL SETRVS ('0.3,0.7,0.7,0.3', XA, SIZ)
      NPTS(1) = 4

C  for each color entry - set to background color and draw fill area set
      DO 2300 IX = 1,NUMFIL
         COLEL = PERM(IX)
         IF (COLEL .LE. 3) THEN
            CALL PSEDCI (UNDF(COLEL))
         ELSE
            CALL PSEDCI (1)
         ENDIF
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/3
         YA(4) = YLOC + YINCR/3
         CALL PFAS (1, NPTS, XA,YA)
         YLOC  = YLOC-YINCR
2300  CONTINUE

      CALL DCHPFV ('UNDEFINED EDGE COLOR INDICES: How many ' //
     1             'rectangles are the same color as the star?',
     2             12, NUMFIL)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
