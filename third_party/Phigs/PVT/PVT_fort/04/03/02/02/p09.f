C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/09                        *
C  *    TEST TITLE : Background colour                     *
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

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C type of returned values = set, realized
      INTEGER    PSET,   PREALI
      PARAMETER (PSET=0, PREALI=1)

      INTEGER    PICSTR, TXCI, COLOR, SIZ, IARFND
      INTEGER    NUMTST, PALTTE, IX, REALIZ, NUMCL
C number to be tested, and size of palette
      PARAMETER (NUMTST=6, PALTTE=9)
      INTEGER    LISCOL(NUMTST), LISTST(NUMTST), COUNT, OPANS

      REAL       RGBVAL(3,PALTTE), REAL0(3), COLARY(3)

      LOGICAL    PASSED, COLEQL

C                    black     blue       cyan      gray
      DATA RGBVAL  / 0.,0.,0., 0.,0.,1.,  0.,1.,1., .5,.5,.5,
C                    green     magenta    red       white
     1               0.,1.,0., 1.,0.,1.,  1.,0.,0., 1.,1.,1.,
C                    yellow
     2               1.,1.,0. /

      CALL INITGL ('04.03.02.02/09')

      CALL XPOPPH (ERRFIL, MEMUN)

C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
C
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL PEXST (102)
      CALL PCLST

C  Set Color Model = RGB
      CALL PSCMD (WKID, PRGB)
      CALL POPST (102)

C  List of colors to be tested - do so in random order
      CALL RNSET (NUMTST,PALTTE,LISCOL)
C  all tests passed so far
      PASSED = .TRUE.
C  List of colors tested so far = empty
      COUNT  = 0

      DO 120 COLOR = 1,NUMTST
         COLARY(1) = RGBVAL(1,LISCOL(COLOR))
         COLARY(2) = RGBVAL(2,LISCOL(COLOR))
         COLARY(3) = RGBVAL(3,LISCOL(COLOR))

         CALL PSCR (WKID, 0, 3, COLARY)
         CALL PQCR (WKID, 0, 3, PREALI, ERRIND, NUMCL, REAL0)
         CALL CHKINQ ('pqcr', ERRIND)

C  look for realized color - is it near a named color??
         DO 210 IX = 1,PALTTE
            IF (COLEQL(3, REAL0,RGBVAL(1,IX), 0.1,0.0)) THEN
C  Found the realized color
               REALIZ = IX
               GOTO 220
            ENDIF
210      CONTINUE
C  if realized color not near a named color, skip this color
         GOTO 120

220      CONTINUE
C  if realized color already tested, skip this color
         IF (IARFND(REALIZ, COUNT, LISTST) .GT. 0) GOTO 120
C  new color - add to list of tested colors
         COUNT = COUNT + 1
         LISTST(COUNT) = REALIZ

C  Set colour representation for #1 opposite from #0
         CALL SETRVS ('0,0,0', COLARY, SIZ)
         IF (REAL0(1) .LT. 0.5) COLARY(1) = 1.0
         IF (REAL0(2) .LT. 0.5) COLARY(2) = 1.0
         IF (REAL0(3) .LT. 0.5) COLARY(3) = 1.0
         CALL PSCR (WKID, 1, 3, COLARY)

         CALL DCHOIC ('BACKGROUND COLOUR: The color of the '       //
     1                'background is best described as: 1-black, ' //
     2                '2-blue, 3-cyan, 4-gray, 5-green, '          //
     3                '6-magenta, 7-red, 8-white, 9-yellow?',
     4                0,PALTTE, OPANS)

         IF (OPANS .EQ. REALIZ) THEN
C           OK so far
         ELSE
            IF (OPANS .EQ. 0) CALL OPCOFL
            PASSED = .FALSE.
            GOTO 130
         ENDIF

C  next color
120   CONTINUE
130   CONTINUE

      IF (COUNT .EQ. 0) THEN
         CALL INMSG ('Cannot find nameable realized color for ' //
     1               'background; skipping test.')
      ELSE
         CALL SETMSG ('21 22 30 32', 'The background colour should ' //
     1                'correspond to entry #0 in the colour table.')
         CALL IFPF (PASSED)
      ENDIF

140   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
