C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/01                        *
C  *    TEST TITLE : Colour facilities                     *
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

C colour model
      INTEGER    PRGB,   PCIE,   PHSV,   PHLS
      PARAMETER (PRGB=1, PCIE=2, PHSV=3, PHLS=4)
C NOTE:  INTEGER rather than enumeration type.  Explicitly defined and
C required portion of conceptually unbounded range defined here.

C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   SPECWT, SPECON, NUMCOL, COLAVL, IDUM1,I, IPCOL, NUMRET

      REAL     PRICOL(9), ANG0, ANG1, DIST0, DIST1, ACTCOL(3), MODSEP
      REAL     CSPEC(3), RSPEC(3)

      LOGICAL  RAREQ, HUSAME

      CALL INITGL ('04.03.02.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C <Inquire colour facilities> to determine
C  numcol = number of available colours
C  colavl = colour availability
C  pricol(1 to 3) = primary colours
      CALL PQCF (SPECWT, ERRIND, NUMCOL, COLAVL, IDUM1, PRICOL)
      CALL CHKINQ ('pqcf', ERRIND)
      CALL SETMSG ('7 26', 'The primary colours returned by '     //
     1             '<inquire colour facilities> should be valid ' //
     2             'CIELUV values.')
      DO 100 I = 1,9
         IF (PRICOL(I) .LT. 0.0 .OR. PRICOL(I) .GT. 1.0) THEN
            CALL FAIL
            GOTO 120
         ENDIF
100   CONTINUE
      CALL PASS

120   CONTINUE
      CALL SETMSG ('7 32 33', 'The primary colours of the ' //
     1             'workstation should be realizable.')
      CALL PSCMD (WKID, PCIE)

      DO 130 IPCOL = 1,7,3
         CALL PSCR (WKID, 1, 3, PRICOL(IPCOL))
         CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)
         IF (NUMRET .EQ. 3 .AND.
     1       RAREQ (3, ACTCOL, PRICOL(IPCOL), .01, .0)) THEN
C OK so far
         ELSE
            CALL FAIL
            GOTO 140
         ENDIF

130   CONTINUE
      CALL PASS
140   CONTINUE

      CALL SETMSG ('1 2 3', 'The number of available colours should ' //
     1             'be reported as 0 or at least 2.')
      CALL IFPF (NUMCOL .EQ. 0 .OR. NUMCOL .GE. 2)

      CALL SETMSG ('4', 'Colour availability should be of type '  //
     1             'MONOCHROME or COLOUR.')
      CALL IFPF (COLAVL .EQ. PMONOC .OR. COLAVL .EQ. PCOLOR)

C  <set colour model> = RGB
      CALL PSCMD (WKID, PRGB)

C  <set colour representation> index #1 = (0, 0, 1)
      CSPEC(1) = 0.0
      CSPEC(2) = 0.0
      CSPEC(3) = 1.0
      CALL PSCR (WKID, 1, 3, CSPEC)
C  <inquire colour representation> index #1 as REALIZED
C   to determine rspec = realized color spec
      CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, RSPEC)
      CALL CHKINQ ('pqcr', ERRIND)
C ang0 = angle for hue red, green, blue
C dist0 = distance of rspec from neutral axis
      CALL HUEANG (RSPEC(1), RSPEC(2), RSPEC(3), ANG0, DIST0)

C  <set colour representation> index #1 = (1, 1, 0)
      CSPEC(1) = 1.0
      CSPEC(2) = 1.0
      CSPEC(3) = 0.0
      CALL PSCR (WKID, 1, 3, CSPEC)
C  <inquire colour representation> index #1 as REALIZED
C   to determine rspec = realized color spec
      CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, RSPEC)
      CALL CHKINQ ('pqcr', ERRIND)
C ang1 = angle for hue red, green, blue
C dist1 = distance of rspec from neutral axis
      CALL HUEANG (RSPEC(1), RSPEC(2), RSPEC(3), ANG1, DIST1)

      HUSAME = (MODSEP(1.0, ANG0, ANG1) .LE. 0.05) .OR.
     1         (DIST0 .LT. 0.05) .OR.
     2         (DIST1 .LT. 0.05)

      IF (COLAVL .EQ. PCOLOR) THEN
         CALL SETMSG ('5 32 33', 'For colour workstations, very ' //
     1                'different hues should not be realized as ' //
     2                'the same hue.')
         CALL IFPF (.NOT. HUSAME)
      ELSE
         CALL SETMSG ('6 32 33', 'For monochrome workstations, '  //
     1                'different hues should be realized as the ' //
     2                'same hue.')
         CALL IFPF (HUSAME)
      ENDIF

666   CONTINUE

C wrap it up
      CALL ENDIT
      END
