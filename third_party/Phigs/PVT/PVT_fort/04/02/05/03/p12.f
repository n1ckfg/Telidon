C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/12                        *
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
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C type of returned value
      INTEGER PSET, PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C linetype
      INTEGER    PLSOLI,    PLDASH,    PLDOT,   PLDASD
      PARAMETER (PLSOLI= 1, PLDASH=2 , PLDOT=3, PLDASD=4)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

      INTEGER    PEDT,     PEWSC,    PEDCI
      PARAMETER (PEDT=15,  PEWSC=16, PEDCI=17)

      INTEGER    IMPMAX, CSIZ, CDIM
      PARAMETER  (IMPMAX = 600, CSIZ = 6)

      INTEGER    PICSTR, TXCI, IX, LDX, NAREA
      INTEGER    NUMET, STDDX, REGDX, IMPDX, THISET, NUMEW
      INTEGER    PERM(20), SZBT, FILON, NUMDIS, NPTS(1)
      INTEGER    NUMPAS,SZCOLT,VISDX,NUMCI, MAXCOL, EXPLCT, UNDF(3)
      INTEGER    LAVSET(10), LAVIET(IMPMAX), LAVRET(10), RTANS(20)
      INTEGER    RNDINT, ITRIM, COLEL, EDCOL(20), VISCOL, PECI
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

      REAL       NOMEW, MINEW, MAXEW, TSTEW1, TSTEW2, MULT,THISEW
      REAL       XA(6), YA(6), YLOC, YINCR, RAD, CENTX, CENTY, PI
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ), MINLW
      REAL       RDUM1, RDUM2, RDUM3

      CHARACTER LDESCR(4)*14, PROMPT*200, PFSW*1

      DATA LDESCR /'solid','dashed','dotted','dashed-dotted'/

      CALL INITGL ('04.02.05.03/12')

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

C  set all ASFs to BUNDLED
      CALL SETASF (PBUNDL)
C  set interior style attribute ASFs to INDIVIDUAL
C     set interior style = EMPTY, interior color index = 1
      CALL PSIASF (PIS, PINDIV)
      CALL PSIASF (PICI, PINDIV)
      CALL PSIS (PISEMP)
      CALL PSICI (1)

C    numet  = number of available edgetypes
C    lavset = list of available standard edgetypes
C    lavret = list of available registered edgetypes
C    laviet = list of available implementor-defined edgetypes
C    numew  = number of available edge-widths
C    nomew  = nominal edge-width (DC)
C    minew,maxew = minimum,maximum edge-width (DC)

      CALL PQEDF (SPECWT, 0, ERRIND, NUMET, IDUM1,
     1            NUMEW, NOMEW, MINEW, MAXEW, IDUM2)
      CALL CHKINQ ('pqedf', ERRIND)

      STDDX = 0
      REGDX = 0
      IMPDX = 0

      DO 50 LDX=1, ABS(NUMET)
         CALL PQEDF (SPECWT, LDX, ERRIND, IDUM1, THISET, IDUM2, RDUM1,
     1               RDUM2, RDUM3, IDUM3)
         CALL CHKINQ ('pqedf', ERRIND)
         IF (THISET .GT. PLDASD) THEN
            REGDX = REGDX + 1
            LAVRET(REGDX) = THISET
         ELSEIF (THISET .GE. PLSOLI) THEN
            STDDX = STDDX + 1
            LAVSET(STDDX) = THISET
         ELSE
            IF (IMPDX .LT. IMPMAX) THEN
               IF (NUMET .LT. 0) THEN
                  IMPDX = IMPDX + 1
                  LAVIET (IMPDX) = -LDX
               ELSE
                  IMPDX = IMPDX + 1
                  LAVIET (IMPDX) = THISET
               ENDIF
            ENDIF
         ENDIF
50    CONTINUE

C     szbt = size of edge bundle table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             SZBT, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C  *** *** ***   edge flag indicator   *** *** ***

C  mark start of edge flag indicator
      CALL PLB (1)

C  filon  = number of areas to be drawn with edge flag ON
      NAREA = 8
      FILON = RNDINT (1, NAREA)

C  set edge representations 1--NAREA
      DO 60 IX = 1, NAREA
         IF (IX .LE. FILON) THEN
             CALL PSEDR (WKID, IX, PON,  PSOLID, 1.0, 1)
         ELSE
             CALL PSEDR (WKID, IX, POFF, PSOLID, 1.0, 1)
         ENDIF
60    CONTINUE

C  display in random order bundles 1-NAREA
      CALL RNPERM (NAREA, PERM)
      CALL DRBUED (NAREA, PERM)

C  mark end of edge flag indicator
      CALL PLB (2)
      CALL SETMSG ('3 4 5 6 30 31', 'The edge of a polygonal area '  //
     1             'should be visible when the edge flag is ON and ' //
     2             'not visible when the edge flag is OFF.')

      PROMPT = 'EDGE FLAG INDICATOR: which triangles have visible ' //
     1         'edges? '

      DO 70 IX = 1,NAREA
         RTANS(PERM(IX)) = IX
70    CONTINUE

      CALL DLSTPF (PROMPT, FILON,RTANS, 'S')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)
C
C  *** *** ***   edgetype   *** *** ***
C  stddx = size of lavset
C  set edge representation 1--stddx
      DO 150 IX = 1, STDDX
         CALL PSEDR (WKID, IX, PON, LAVSET(IX) , 1.0, 1)
150   CONTINUE

C  Display in random order bundles 1 thru stddx
      CALL RNPERM (STDDX, PERM)
      CALL DRBUED (STDDX, PERM)

      CALL SETMSG ('3 4 5 6 38 39', 'The standard edgetypes should ' //
     1             'be recognizable from their standard description.')

      PROMPT = 'STANDARD EDGETYPES: List, in order, the numeric ' //
     1         'labels for edgetypes: ' // LDESCR(LAVSET(1))
      RTANS(PERM(1)) = 1
      DO 170 LDX = 2, STDDX
         PROMPT(ITRIM(PROMPT)+1:) = ', ' // LDESCR(LAVSET(LDX))
         RTANS(PERM(LDX)) = LDX
170   CONTINUE
      PROMPT(ITRIM(PROMPT)+1:) = '.'
      CALL DLSTPF (PROMPT, STDDX,RTANS, 'L')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1, 2)

C  regdx = size of lavret
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No registered edgetypes are supported.')
         GOTO 290
      ENDIF

C  numdis = min(regdx, 8, szbt)
C  lindis = numdis entries, randomly chosen from lavret
      NUMDIS = MIN(REGDX, 8, SZBT)
      CALL RNSET (NUMDIS, REGDX, PERM)
      CALL SRTIAR (NUMDIS, PERM)
      CALL SRTIAR (REGDX, LAVRET)
      CALL LBEDTY (WKID, NUMDIS, PERM, LAVRET)

      CALL SETMSG ('3 4 5 6 38 40', 'The registered edgetypes (> 4) ' //
     1             'should agree with their registered description.')

      CALL DYNPF ('REGISTERED EDGETYPES: Is each edgetype depicted ' //
     1            'according to its numeric identifier''s '          //
     2            'specification in the ISO register? ', 'Y')
C
C  neg_type:
290   CONTINUE

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1, 2)

C  impdx = size of laviet
      IF (IMPDX .LT. 1) THEN
         CALL INMSG ('No implementor defined edge types are supported.')
         GOTO 390
      ENDIF

C  numdis = min(impdx, 8, szbt)
C  lindis = numdis entries, randomly chosen from laviet
      NUMDIS = MIN(IMPDX, 8, SZBT)
      CALL RNSET (NUMDIS, IMPDX, PERM)
      CALL SRTIAR (NUMDIS, PERM)
      CALL SRTIAR (IMPDX, LAVIET)
      CALL LBEDTY (WKID, NUMDIS, PERM, LAVIET)

      CALL SETMSG ('3 4 5 6 38 41', 'Implementor-defined edgetypes ' //
     1             '(< 1) should agree with the descriptions '       //
     2             'supplied by the implementor.')

      CALL DYNPF ('IMPLEMENTOR DEFINED EDGETYPES: Is each edgetype ' //
     1            'depicted according to its numeric identifier''s ' //
     2            'specification in the implementor documentation?','Y')

C  end_edgetype:
390   CONTINUE

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1, 2)

C  *** *** ***   edge-width   *** *** ***

C  Get minimum line width to allow simulation of edge width
      CALL PQPLF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, RDUM1,
     1            MINLW, RDUM2, IDUM4)
      CALL CHKINQ ('pqplf', ERRIND)

C  Are there at least two visually distinguishable edge-widths?
      IF ((NUMEW .EQ. 1) .OR. (MAXEW .LE. 1.02 * MINEW)
     1    .OR. (MAXEW-MINEW .LT.  QVIS))    THEN
         TSTEW1 = MAXEW
         TSTEW2 = TSTEW1
         MULT = 2.0
      ELSE
         TSTEW1 = MINEW
         TSTEW2 = MAXEW
         IF (NUMEW .EQ. 0) THEN
C   continuous range of edgewidths available - take 4 geometric steps
             MULT = 0.9999 * ((TSTEW2/TSTEW1) ** 0.25)
         ELSE
C   discrete set of edgewidths available - test min/max only
             MULT = 0.9999 * (TSTEW2/TSTEW1)
         ENDIF
      ENDIF

C  initialize numpas and thisew
      NUMPAS = 0
      THISEW = TSTEW1

C  loop thru various edgewidths
1000  CONTINUE

C  test bundle with both requested & expected edge width = thisew
      CALL SHEDBW ('VARIOUS EDGEWIDTH SCALE FACTORS', WKID, THISEW,
     1             THISEW, NOMEW, MINLW, PFSW)

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

      NUMPAS = NUMPAS + 1
      THISEW = THISEW * MULT
      IF (THISEW .LE. TSTEW2) GOTO 1000

1100  CONTINUE

C  do_test_msg:
      CALL SETMSG ('3 4 5 6 45 46 47', 'Available edgewidth scale ' //
     1             'factors should control the realized thickness ' //
     2             'of a edge.')
      CALL IFPF (NUMPAS.GT.0)

1110  CONTINUE

C  min_max_coerce:
      CALL SETMSG ('3 4 5 6 45 46 48', 'A requested positive ' //
     1             'edgewidth scale factor below the minimum ' //
     2             'available should be realized as the minimum.')

C  test bundle with requested edge width = minew/2
C                         expected edge width = minew
      CALL SHEDBW ('POSITIVE EDGEWIDTH BELOW MINIMUM', WKID,
     1              MINEW/2, MINEW, NOMEW, MINLW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

      CALL SETMSG ('3 4 5 6 45 46 48', 'A requested negative '     //
     1             'edgewidth scale factor should be realized as ' //
     2             'the minimum.')
      CALL SHEDBW ('NEGATIVE EDGEWIDTH', WKID, -MAXEW-100,
     1              MINEW, NOMEW, MINLW, PFSW)
      CALL IFPF (PFSW .EQ. 'P')

C  to test requested edge width = maxew*2
C  expected edge width = maxew
      CALL SHEDBW ('POSITIVE EDGEWIDTH ABOVE MAXIMUM', WKID,
     1              MAXEW*2, MAXEW, NOMEW, MINLW, PFSW)

      IF (PFSW.EQ.'A') THEN
         CALL INMSG ('Skipping test case for requested scale factor ' //
     1               'greater than maximum because largest valid '    //
     2               'edge width is greater than screen size.')
      ELSE
         CALL SETMSG ('3 4 5 6 45 46 48', 'A requested edgewidth ' //
     1                'scale factor above the maximum available '  //
     2                'should be realized as the maximum.')
         CALL IFPF (PFSW .EQ. 'P')
      ENDIF

C  *** *** ***   edge color index   *** *** ***
C
      CALL SETMSG ('3 4 5 6 49 50 51', 'A defined edge color index ' //
     1             'should cause the addressed entry in the color '  //
     2             'table to be used when rendering a edge.')
      CALL PSCMD (WKID, PRGB)

C  bckcol = background color = realized color spec for entry #0
C  forcol = foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 0, CSIZ, PREALI, ERRIND, CDIM, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL PQCR (WKID, 1, CSIZ, PREALI, ERRIND, CDIM, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  szcolt = maximum size of color table (including entry #0)
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5,
     1             IDUM6, SZCOLT, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C  numdis = number of edges to be drawn
      NUMDIS = MIN (8, SZCOLT, SZBT)

C  edcol  = random permutation of #0,#1, and numdis-2 random choices
C           from entries #2 to #szcolt-1
      CALL RNBSET (NUMDIS-2, 2, SZCOLT-1, EDCOL)
      EDCOL(NUMDIS-1) = 1
      EDCOL(NUMDIS) = 0
      CALL RNPERM (NUMDIS, PERM)

C  visdx = randomly select an entry from edcol to be made visible
      VISDX = RNDINT (1, NUMDIS-1)
      VISCOL = EDCOL(VISDX)

C  ensure dialogue visible
      DTXCI = VISCOL
      CALL PSIASF (PTXCI, PINDIV)
      CALL PSTXCI (VISCOL)

      YLOC  = 0.9
      YINCR = 0.8/(NUMDIS-1)
      XA(1) = 0.3
      XA(2) = 0.7
      XA(3) = 0.5
      CALL NUMLAB (NUMDIS, .25, YLOC+0.3*YINCR, YINCR)
      NPTS(1) = 3

C  for each color entry, set to background color and draw edges
      DO 2110 IX = 1,NUMDIS
         CALL PSEDI (IX)
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + 0.6*YINCR
         CALL PFAS (1,NPTS, XA, YA)

         PECI = EDCOL(PERM(IX))
         CALL PSCR (WKID, PECI, CDIM, BCKCOL)
         CALL PSEDR (WKID, IX, PON, 1, 1.0, PECI)
         YLOC = YLOC - YINCR
2110  CONTINUE
      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)

      CALL DCHPF ('DEFINED EDGE COLOR INDICES: which triangle is ' //
     1            'visible? ', NUMDIS, VISDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)
C
C  end_def_col:
C
      CALL SETMSG ('3 4 5 6 49 50 52', 'An undefined edge color '    //
     1             'index should cause entry number 1 in the color ' //
     2             'table to be used when rendering an edge.')

C  set entry #1 in color table opposite from BCKCOL
      DO 2300 IX = 1, 3
         IF (BCKCOL(IX) .GT. 0.5) THEN
            NEWCOL(IX) = 0.0
         ELSE
            NEWCOL(IX) = 1.0
         ENDIF
2300  CONTINUE

C  set entry #1 different from FORCOL - make sure undefined default
C  to *current* color-rep of #1, not just a predefined color.
      IF (FORCOL(3) .GT. 0.5) THEN
         NEWCOL(3) = 0.0
      ELSE
         NEWCOL(3) = 1.0
      ENDIF
      CALL PSCR (WKID, 1, CDIM, NEWCOL)
      CALL PQECI (WKID, 0, ERRIND, NUMCI, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)

      MAXCOL = 0
      DO 2400 IX = 1, NUMCI
         CALL PQECI (WKID, IX, ERRIND, IDUM1, COLEL)
         CALL CHKINQ ('pqeci',ERRIND)
         MAXCOL = MAX(MAXCOL, COLEL)
2400  CONTINUE

C  explct = number of explicit edges of color #1 = random integer
C  from 0 to min(4, szbt-3)
      EXPLCT = RNDINT (0, MIN(4, SZBT-3))
C  display in random order bundles #1 thru explct+3
      NUMDIS = EXPLCT + 3
      CALL RNPERM (NUMDIS, PERM)

C  u1,u2,u3 = 3 undefined, positive color indices
      UNDF(1) = MAXCOL + 1
      UNDF(2) = MAXCOL + 10
      UNDF(3) = MAXCOL + 90

C  draw star with color #1
      CALL PSIASF (PEDCI, PINDIV)
      CALL PSEDCI (1)
      RAD = .15
      CENTX = .5
      CENTY = .75
      PI = 3.14159265
      DO 2500 IX = 1,6
         YA(IX) = CENTY + RAD * COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD * SIN((4*PI*IX)/5)
2500  CONTINUE
      NPTS(1) = 6
      CALL PFAS (1, NPTS, XA, YA)

C  set up bundles 1 thru 3 with undf, 4 thru (explct+3) with #1
      CALL SETASF (PBUNDL)
      CALL PSIASF (PIS, PINDIV)
      CALL PSIASF (PICI, PINDIV)
      CALL PSIS (PISEMP)
      CALL PSICI (1)
      DO 2600 IX = 1, 3
         CALL PSEDR (WKID, IX, PON, 1, 1.0, UNDF(IX))
2600  CONTINUE
      DO 2610 IX = 4, EXPLCT+3
         CALL PSEDR (WKID, IX, PON, 1, 1.0, 1)
2610  CONTINUE

      XA(1) = 0.3
      XA(2) = 0.7
      XA(3) = 0.7
      XA(4) = 0.3
      YLOC  = 0.5
      YINCR = 0.5 / (NUMDIS+1)
      NPTS(1) = 4
      DO 2700 IX = 1, NUMDIS
         CALL PSEDI (PERM(IX))
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC - 0.5*YINCR
         YA(4) = YA(3)
         CALL PFAS (1, NPTS, XA, YA)
         YLOC = YLOC - YINCR
2700  CONTINUE

      CALL DCHPFV ('UNDEFINED EDGE COLOR INDICES: how many '      //
     1             'rectangles have edges the same color as the ' //
     2             'star?', 12, NUMDIS)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
