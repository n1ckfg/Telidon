C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/07                        *
C  *    TEST TITLE : Hue recognition for colour models     *
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

C colour available
      INTEGER    PMONOC,     PCOLOR
      PARAMETER (PMONOC = 0, PCOLOR = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

      INTEGER    LSCOLI(20), HUEDX, SIZPAL, COLA, NPCI, MCOLI
      INTEGER    CMOD, PICSTR, TXCI, IX, IY, IZ, MAXFG, I
      INTEGER    NMOD, NUMSET, RESULT, TSTHUE, HUEENT(6)
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

      REAL       CC(9), RGBCC(3,9), HSVCC(3,9), HLSCC(3,9), SHADCC(3,4)
      REAL       CIEBAS(3,10), CIEGR1(3,6), CIEGR2(3,6)

      REAL       Z,       H,       U
      PARAMETER (Z = 0.0, H = 0.5, U = 1.0)

      LOGICAL    DIDTST, FILMOD, INTSTY, CMODEL(PRGB:PHLS)

      CHARACTER  PRMPT1*77, PRMBAS*139, PRMINT*236, COLIST(9)*7
      CHARACTER  CIEPR1*87, CIEPR2*103, CIEPR3*101

      DATA CMODEL / 4 * .FALSE. /

C  identify hue entries
      DATA HUEENT / 2,3,5,6,7,9 /

C  Alphabetical order of hues (except CIE):
      DATA COLIST / 'black', 'blue',   'cyan', 'gray', 'green',
     1              'magenta',  'red', 'white',  'yellow' /
      DATA RGBCC /   Z,Z,Z,   Z,Z,U,    Z,U,U,  H,H,H,  Z,U,Z,
     1               U,Z,U,      U,Z,Z, U,U,U,    U,U,Z /
      DATA HSVCC /  -1,-1,Z, .6667,U,U, H,U,U,  -1,Z,H, .3333,U,U,
     1              .8333,U,U,   Z,U,U, -1,Z,U,  .1667,U,U /
      DATA HLSCC /  -1,Z,-1, .6667,H,U, H,H,U,  -1,H,Z, .3333,H,U,
     1              .8333,H,U,   Z,H,U, -1,1,-1, .1667,H,U /

C  CIE coordinates for basic hues and neutrals:
C                    black,   blue,             gray
      DATA  CIEBAS / -1,-1,0, .11689,.20283,1., .19366,.46435,0.5,
C           green,            orange,           pink
     1      .00733,.54250,1., .31886,.54308,1., .34634,.48000,1.,
C           purple,           red,              white
     2      .32592,.12348,1., .59985,.47955,1., .19366,.46435,1.,
C           yellow,
     3      .24702,.55471,1.  /

C  CIE coordinates for group 1 of mixed hues
C                 purplish-blue,    greenish-blue,    yellowish-green,
      DATA CIEGR1/.20462,.06966,1., .05689,.33083,1., .08567,.57794,1.,
C                 greenish-yellow,  orange-yellow,    purplish-red
     1            .21172,.55987,1., .27978,.54823,1., .53137,.39053,1. /

C  CIE coordinates for group 2 of mixed hues
C                 bluish-green,     yellow-green,     reddish-orange,
      DATA CIEGR2/.02205,.44449,1., .17644,.56634,1., .39700,.52885,1.,
C                 reddish-purple,   yellowish-pink,   purplish-pink,
     1            .43880,.27271,1., .31241,.50870,1., .29942,.42000,1. /

      CALL INITGL ('04.03.02.02/07')

C open PHIGS
      CALL XPOPPH (6, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 11
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL PEXST (102)
      CALL PCLST

C  Check to see that color is available
C    SIZPAL = number of colours available (size of palette)
C    COLA = COLOR/MONOCHROME
      CALL PQCF (SPECWT, ERRIND, SIZPAL, COLA, NPCI, CC )
      CALL CHKINQ ('pqcf', ERRIND)

      IF (COLA .NE. PCOLOR) THEN
         CALL INMSG ('Multi-hue color not available; ' //
     1               'skipping all hue tests.')
         GOTO 666
      ENDIF

      IF (SIZPAL.GT.0 .AND. SIZPAL.LT.27) THEN
         CALL INMSG ('Number of available colors too low for ' //
     1               'reliable testing; skipping all hue tests.')
         GOTO 666
      ENDIF

C  Determine the maximum number of color indices (MCOLI) available.
      CALL PQWKSL (SPECWT, ERRIND,IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             MCOLI, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C  Maximum available # foreground colors, besides #1
      MAXFG = MCOLI-2
      IF (MAXFG .LT. 4) THEN
         CALL INMSG ('Number of available color entries too low for ' //
     1               'reliable testing; skipping all hue tests.')
         GOTO 666
      ENDIF

C  Determine how to fill in rectangles, use solid style
C  if it is available, otherwise use dense polyline cross-hatch
      FILMOD = INTSTY (SPECWT, PSOLID)

C  Determine list of color models to test.
      CALL PQCMDF (SPECWT, 0, ERRIND, NMOD, IDUM1,IDUM2)
      CALL CHKINQ ('pqcmdf', ERRIND)

      DO 110, I = 1,NMOD
         CALL PQCMDF (SPECWT, I, ERRIND, IDUM1, CMOD, IDUM2)
         CALL CHKINQ ('pqcmdf', ERRIND)
         IF (PRGB.LE.CMOD .AND. CMOD.LE.PHLS) THEN
            CMODEL(CMOD) = .TRUE.
         ENDIF
110   CONTINUE

C  prompt for color selection for every color model other than CIE
      PRMPT1 = '1-black, 2-blue, 3-cyan, 4-gray, 5-green, ' //
     1         '6-magenta, 7-red, 8-white, 9-yellow'

C  prompt for basic colors
      PRMBAS = 'Enter a list of color identifiers which corresponds ' //
     1         'to the order (from top to bottom) of displayed '      //
     1         'rectangles.  The color identifiers are: '
C  prompt for intermediate colors
      PRMINT = 'Enter a list of shading identifiers which '        //
     1         'corresponds to the order (from top to bottom) of ' //
     1         'displayed rectangles.  The identifiers are: '      //
     1         '1-normal, 2-light (closer to white), 3-muted '     //
     1         '(closer to gray), and 4-dark (closer to black) '   //
     1         'shade of '

C  keep background as dark gray, #1 foreground as white
      CALL PSCMD (WKID, PRGB)
      CALL SETRVS ('.25,.25,.25', CC, IX)
      CALL PSCR  (WKID, 0, 3, CC)

      CALL SETRVS ('1,1,1', CC, IX)
      CALL PSCR  (WKID, 1, 3, CC)

      CALL POPST (102)

C  **** **** **** ****   RGB Color Model   **** **** **** ****

C  Make sure RGB model is available
      IF (.NOT. CMODEL(PRGB)) THEN
         CALL INMSG ('RGB color model not available; ' //
     1               'skipping RGB tests.')
         GOTO 199
      ENDIF

      CALL SETHUE (WKID,PRGB,MAXFG,9,RGBCC, NUMSET,LSCOLI)

      IF (NUMSET .LT. 4) THEN
         CALL INMSG ('Realized basic colors not accurate enough ' //
     1               'for testing RGB color model.')
         GOTO 199
      ENDIF

      CALL SETMSG ('1 5 16 17 21 22 32 33', 'The basic hues and ' //
     1             'neutral colors should appear as described '   //
     2             'within the RGB color model.')

      RESULT = TSTHUE ('APPEARANCE OF BASIC COLORS IN RGB: ' //
     1                 PRMBAS // PRMPT1, FILMOD, NUMSET, LSCOLI)
      IF (RESULT.EQ.-2) CALL OPCOFL
      CALL IFPF (RESULT.EQ.1)

      IF (SIZPAL.GT.0 .AND. SIZPAL.LT.64) THEN
         CALL INMSG ('Number of available colors too low for ' //
     1               'reliable testing of intermediate RGB hues.')
         GOTO 199
      ENDIF

      DIDTST = .FALSE.

      DO 130 IX = 1,6
C  set up next hue
         HUEDX = HUEENT(IX)
C  primary,light,gray,dark
         DO 133 IY = 1,3
C  primary
            SHADCC(IY,1) = RGBCC(IY,HUEDX)
C  light
            SHADCC(IY,2) = 0.3 * RGBCC(IY,HUEDX) + 0.7 * 1.0
C  grayish
            SHADCC(IY,3) = 0.3 * RGBCC(IY,HUEDX) + 0.7 * 0.5
C  dark
            SHADCC(IY,4) = 0.4 * RGBCC(IY,HUEDX) + 0.6 * 0.0
133      CONTINUE

         CALL SETHUE (WKID,PRGB,MAXFG,4,SHADCC, NUMSET,LSCOLI)
C  skip hue, if not all shown
         IF (NUMSET .LT. 4) GOTO 130

         DIDTST = .TRUE.
         RESULT = TSTHUE ('APPEARANCE OF INTERMEDIATE COLORS IN ' //
     1                    'RGB: ' // PRMINT // COLIST(HUEDX),
     2                    FILMOD, NUMSET, LSCOLI)

         IF (RESULT .LT. 0) THEN
            GOTO 140
         ENDIF
130   CONTINUE

140   CONTINUE

      IF (DIDTST) THEN
         CALL SETMSG ('1 5 16 17 21 22 32 33', 'The intermediate '  //
     1                'hues should appear as described within the ' //
     2                'RGB color model.')
         IF (RESULT.EQ.-2) CALL OPCOFL
         CALL IFPF (RESULT.GT.0)
      ELSE
         CALL INMSG ('Realized intermediate colors not accurate ' //
     1               'enough for testing RGB color model.')
      ENDIF

C  end RGB
199   CONTINUE

C  **** **** **** ****   HSV Color Model   **** **** **** ****

C  Make sure HSV model is available
      IF (.NOT. CMODEL(PHSV)) THEN
         CALL INMSG ('HSV color model not available; ' //
     1               'skipping HSV tests.')
         GOTO 299
      ENDIF

      CALL SETHUE (WKID,PHSV,MAXFG,9,HSVCC, NUMSET,LSCOLI)

      IF (NUMSET .LT. 4) THEN
         CALL INMSG ('Realized basic colors not accurate enough ' //
     1               'for testing HSV color model.')
         GOTO 299
      ENDIF

      CALL SETMSG ('1 5 16 17 21 24 32 33', 'The basic hues and ' //
     1             'neutral colors should appear as described '   //
     2             'within the HSV color model.')

      RESULT = TSTHUE ('APPEARANCE OF BASIC COLORS IN HSV: ' //
     1                 PRMBAS // PRMPT1, FILMOD, NUMSET, LSCOLI)
      IF (RESULT.EQ.-2) CALL OPCOFL
      CALL IFPF (RESULT.EQ.1)

      IF (SIZPAL.GT.0 .AND. SIZPAL.LT.64) THEN
         CALL INMSG ('Number of available colors too low for ' //
     1               'reliable testing of intermediate HSV hues.')
         GOTO 299
      ENDIF

      DIDTST = .FALSE.

      DO 230 IX = 1,6
C  set up next hue
         HUEDX = HUEENT(IX)

C  shadcc(component-index, shade)
C  shade: 1-normal, 2-light, 3-grayish, and 4-dark
         DO 233 IY = 1,3
         DO 235 IZ = 1,4
            SHADCC(IY,IZ) = HSVCC(IY,HUEDX)
235      CONTINUE
233      CONTINUE
C  light - set saturation to 0.5
         SHADCC(2,2) = 0.5
C  grayish - set saturation to 0.5 and value to 0.7
         SHADCC(2,3) = 0.5
         SHADCC(3,3) = 0.7
C  dark - set value to 0.3
         SHADCC(3,4) = 0.3

         CALL SETHUE (WKID,PHSV,MAXFG,4,SHADCC, NUMSET,LSCOLI)
C  skip hue, if not all shown
         IF (NUMSET .LT. 4) GOTO 230

         DIDTST = .TRUE.
         RESULT = TSTHUE ('APPEARANCE OF INTERMEDIATE COLORS IN ' //
     1                    'HSV: ' // PRMINT // COLIST(HUEDX),
     2                    FILMOD, NUMSET, LSCOLI)

         IF (RESULT .LT. 0) THEN
            GOTO 240
         ENDIF
230   CONTINUE

240   CONTINUE

      IF (DIDTST) THEN
         CALL SETMSG ('1 5 16 17 21 24 32 33', 'The intermediate '  //
     1                'hues should appear as described within the ' //
     2                'HSV color model.')
         IF (RESULT.EQ.-2) CALL OPCOFL
         CALL IFPF (RESULT.GT.0)
      ELSE
         CALL INMSG ('Realized intermediate colors not accurate ' //
     1               'enough for testing HSV color model.')
      ENDIF

C  end HSV
299   CONTINUE

C  **** **** **** ****   HLS Color Model   **** **** **** ****

C  Make sure HLS model is available
      IF (.NOT. CMODEL(PHLS)) THEN
         CALL INMSG ('HLS color model not available; ' //
     1               'skipping HLS tests.')
         GOTO 399
      ENDIF

      CALL SETHUE (WKID,PHLS,MAXFG,9,HLSCC, NUMSET,LSCOLI)

      IF (NUMSET .LT. 4) THEN
         CALL INMSG ('Realized basic colors not accurate enough ' //
     1               'for testing HLS color model.')
         GOTO 399
      ENDIF

      CALL SETMSG ('1 5 16 17 21 25 32 33', 'The basic hues and ' //
     1             'neutral colors should appear as described '   //
     2             'within the HLS color model.')

      RESULT = TSTHUE ('APPEARANCE OF BASIC COLORS IN HLS: ' //
     1                 PRMBAS // PRMPT1, FILMOD, NUMSET, LSCOLI)
      IF (RESULT.EQ.-2) CALL OPCOFL
      CALL IFPF (RESULT.EQ.1)

      IF (SIZPAL.GT.0 .AND. SIZPAL.LT.64) THEN
         CALL INMSG ('Number of available colors too low for ' //
     1               'reliable testing of intermediate HLS hues.')
         GOTO 399
      ENDIF

      DIDTST = .FALSE.

      DO 330 IX = 1,6
C  set up next hue
         HUEDX = HUEENT(IX)

C  shadcc(component-index, shade)
C  shade: 1-normal, 2-light, 3-grayish, and 4-dark
         DO 333 IY = 1,3
         DO 335 IZ = 1,4
            SHADCC(IY,IZ) = HLSCC(IY,HUEDX)
335      CONTINUE
333      CONTINUE
C  light - set lightness to 0.8
         SHADCC(2,2) = 0.8
C  grayish - set saturation to 0.5
         SHADCC(3,3) = 0.5
C  dark - set lightness to 0.3
         SHADCC(2,4) = 0.3

         CALL SETHUE (WKID,PHLS,MAXFG,4,SHADCC, NUMSET,LSCOLI)
C  skip hue, if not all shown
         IF (NUMSET .LT. 4) GOTO 330

         DIDTST = .TRUE.
         RESULT = TSTHUE ('APPEARANCE OF INTERMEDIATE COLORS IN ' //
     1                    'HLS: ' // PRMINT // COLIST(HUEDX),
     2                    FILMOD, NUMSET, LSCOLI)
         IF (RESULT .LT. 0) THEN
C  have hit failure
            GOTO 340
         ENDIF
330   CONTINUE

340   CONTINUE

      IF (DIDTST) THEN
         CALL SETMSG ('1 5 16 17 21 25 32 33', 'The intermediate '  //
     1                'hues should appear as described within the ' //
     2                'HLS color model.')
         IF (RESULT.EQ.-2) CALL OPCOFL
         CALL IFPF (RESULT.GT.0)
      ELSE
         CALL INMSG ('Realized intermediate colors not accurate ' //
     1               'enough for testing HLS color model.')
      ENDIF

C  end HLS
399   CONTINUE

C  **** **** **** ****   CIE Color Model   **** **** **** ****

C  Make sure CIE model is available
      IF (.NOT. CMODEL(PCIE)) THEN
         CALL INMSG ('CIE color model not available; ' //
     1               'skipping CIE tests.')
         GOTO 499
      ENDIF

C  CIE prompt for basic hues and neutrals:
      CIEPR1 = '1-black, 2-blue, 3-gray, 4-green, 5-orange, ' //
     1         '6-pink, 7-purple, 8-red, 9-white, 10-yellow'

      CALL SETHUE (WKID,PCIE,MAXFG,10,CIEBAS, NUMSET,LSCOLI)

      IF (NUMSET .LT. 4) THEN
         CALL INMSG ('Realized basic colors not accurate enough ' //
     1               'for testing CIE color model.')
         GOTO 499
      ENDIF

      CALL SETMSG ('1 5 16 17 21 23 32 33', 'The basic hues and ' //
     1             'neutral colors should appear as described '   //
     2             'within the CIE color model.')

      RESULT = TSTHUE ('APPEARANCE OF BASIC COLORS IN CIE: ' //
     1                 PRMBAS // CIEPR1, FILMOD, NUMSET, LSCOLI)
      IF (RESULT.EQ.-2) CALL OPCOFL
      CALL IFPF (RESULT.EQ.1)

      IF (SIZPAL.GT.0 .AND. SIZPAL.LT.64) THEN
         CALL INMSG ('Number of available colors too low for ' //
     1               'reliable testing of intermediate CIE hues.')
         GOTO 499
      ENDIF

C  CIE prompt for group 1 of mixed hues
      CIEPR2 = '1-purplish blue, 2-greenish blue, 3-yellowish ' //
     1         'green, 4-greenish yellow, 5-orange yellow, '    //
     2         '6-purplish red'
C  CIE prompt for group 2 of mixed hues
      CIEPR3 = '1-bluish green, 2-yellow green, 3-reddish orange, ' //
     1         '4-reddish purple, 5-yellowish pink, 6-purplish pink'

      DIDTST = .FALSE.
      CALL SETHUE (WKID,PCIE,MAXFG,6,CIEGR1, NUMSET,LSCOLI)

C  maybe skip group 1
      IF (NUMSET .LT. 4) GOTO 450

      DIDTST = .TRUE.
      RESULT = TSTHUE ('APPEARANCE OF COMPOUND HUES IN CIE: ' //
     1                 PRMBAS // CIEPR2, FILMOD, NUMSET, LSCOLI)
      IF (RESULT .LT. 0) THEN
         GOTO 480
      ENDIF

450   CONTINUE
      CALL SETHUE (WKID,PCIE,MAXFG,6,CIEGR2, NUMSET,LSCOLI)

C  maybe skip group 2
      IF (NUMSET .LT. 4) GOTO 480

      DIDTST = .TRUE.
      RESULT = TSTHUE ('APPEARANCE OF COMPOUND HUES IN CIE: ' //
     1                 PRMBAS // CIEPR3, FILMOD, NUMSET, LSCOLI)

480   CONTINUE
      IF (DIDTST) THEN
         CALL SETMSG ('1 5 16 17 21 23 32 33', 'The compound hues ' //
     1                'should appear as described within the CIE '  //
     2                'color model.')
         IF (RESULT.EQ.-2) CALL OPCOFL
         CALL IFPF (RESULT.GT.0)
      ELSE
         CALL INMSG ('Realized compound hues not accurate ' //
     1               'enough for testing CIE color model.')
      ENDIF

C  end CIE
499   CONTINUE

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
