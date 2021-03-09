C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.03.03/chtxrc                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CHTXRC (NOMW, NOMH, WKTYPE, FONT, STR, TXOR,
     1                   CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)

C  CHTXRC computes expected results for various parameter values
C  which affect the size of the text extent rectangle and the
C  concatenation point.  Computation is based on deviation from
C  nominal width and length of entire string.  Therefore, CHTXRC may
C  be used for non-monospaced fonts.

C Input parameters:
C   nomw    : nominal width of string
C   nomh    : nominal height of string
C   wktype  : workstation type
C   font    : text font
C   str     : character string
C   txor    : text path orientation
C   chxp    : character expansion factor
C   chsp    : character spacing
C   chh     : character height
C
C Output parameters:
C   didtst  : was able to perform test
C   rectok  : text rectangle OK
C   ccpok   : concatenation point OK

      INTEGER    WKTYPE, FONT
      INTEGER    TXOR, HRIZNT, VERTIC, NCHAR

      PARAMETER (HRIZNT = 1, VERTIC = 2)

      REAL       NOMW, NOMH, CHXP, CHSP, CHH, MINSP
      REAL       ACHH, ACHXP, EXTXHI, EXTYHI, EXCCX, EXCCY

      CHARACTER  STR*(*)

      LOGICAL    DIDTST, RECTOK, CCPOK

      ACHH  = ABS (CHH)
      ACHXP = ABS (CHXP)

      IF (ACHH .LT.1.0E-37 .OR. ACHH .GT.1.0E+37 .OR.
     1    ACHXP.LT.1.0E-37 .OR. ACHXP.GT.1.0E+37) THEN
         CALL INMSG ('Magnitude of character height or expansion '  //
     1               'factor too high or low to allow computation ' //
     2               'of expected value; skipping test case.')
         DIDTST = .FALSE.
         RETURN
      ELSE
         DIDTST = .TRUE.
      ENDIF

      IF     (TXOR .EQ. HRIZNT) THEN
         MINSP = -0.1 * ACHXP
      ELSEIF (TXOR .EQ. VERTIC) THEN
         MINSP = -0.1
      ELSE
         CALL UNMSG ('Invalid text orientation passed to CHXTRC.')
      ENDIF

      IF (CHSP .LT. MINSP) THEN
         CALL UNMSG ('Cannot compute expected values because '   //
     1               'negative character spacing may overwhelm ' //
     2               'character width.')
      ENDIF

C  nchar = number of characters in str
      NCHAR = LEN (STR)

C calculate expected values for rectangle and concatenation point
      IF     (TXOR .EQ. HRIZNT) THEN
         EXTXHI = ACHH * (NOMW * ACHXP + CHSP * (NCHAR - 1))
         EXTYHI = ACHH * NOMH
         EXCCX  = EXTXHI + ACHH * CHSP
         EXCCY  = 0.0
      ELSEIF (TXOR .EQ. VERTIC) THEN
         EXTYHI = ACHH * (NOMH + CHSP * (NCHAR - 1))
         EXTXHI = ACHH * NOMW * ACHXP
         EXCCX  = 0.0
         EXCCY  = EXTYHI + ACHH * CHSP
      ENDIF

      CALL TXCOMP (WKTYPE, TXOR, FONT, CHXP, CHSP, CHH, STR,
     1             EXTXHI, EXTYHI, EXCCX, EXCCY, RECTOK, CCPOK)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.03.03/chmono                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CHMONO (NOMCSZ, NOMSTH, WKTYPE, FONT, STR,
     1                   TXOR, CHXP, CHSP, CHH, RECTOK, CCPOK)

C  CHMONO computes expected results for various parameter values
C  which affect the size of the text extent rectangle and the
C  concatenation point.  Computation is based on deviation from
C  nominal character size in text path dimension and thickness of
C  entire string in other dimension.  Therefore, CHMONO is valid
C  only when every character in the string has the same size.

C Input parameters:
C   nomcsz  : nominal character size, in dimension of
C             text orientation
C   nomsth  : nominal thickness of string, in dimension
C             perpendicular to text orientation
C   wktype  : workstation type
C   font    : text font
C   str     : character string
C   txor    : text path orientation
C   chxp    : character expansion factor
C   chsp    : character spacing
C   chh     : character height
C
C Output parameters:
C   rectok  : text rectangle OK
C   ccpok   : concatenation point OK

      INTEGER    HRIZNT,     VERTIC,     FONT, WKTYPE, TXOR, NCHAR
      PARAMETER (HRIZNT = 1, VERTIC = 2)

      REAL      EXTXHI, EXTYHI, XPCW, EXCCX, EXCCY
      REAL      CHXP, CHSP, CHH, ACHH, ACHXP, CHRINC, NOMCSZ, NOMSTH

      CHARACTER STR*(*)

      LOGICAL   RECTOK, CCPOK

      ACHH  = ABS(CHH)
      ACHXP = ABS(CHXP)

C     nchar = number of characters in str
      NCHAR = LEN (STR)

C calculate expected values for rectangle and concatenation point
      IF (TXOR .EQ. HRIZNT) THEN
         XPCW   =  ACHXP * NOMCSZ
C  chrinc = character increment
         CHRINC =  XPCW + CHSP
         EXTXHI =  ACHH * (XPCW + (NCHAR - 1) * ABS(CHRINC))
         EXTYHI =  ACHH * NOMSTH
         IF (CHRINC .LE. 0.0) THEN
            EXCCX = ACHH * CHRINC
         ELSE
            EXCCX = ACHH * CHRINC * NCHAR
         ENDIF
         EXCCY  = 0.0
      ELSE IF (TXOR .EQ. VERTIC) THEN
C  chrinc = character increment
         CHRINC = NOMCSZ + CHSP
         EXTXHI = ACHH * NOMSTH * ACHXP
         EXTYHI = ACHH * (NOMCSZ + (NCHAR - 1) * ABS(CHRINC))
         EXCCX  = 0.0
         IF (CHRINC .LE. 0.0) THEN
            EXCCY = ACHH * CHRINC
         ELSE
            EXCCY = ACHH * CHRINC * NCHAR
         ENDIF
      ELSE
         CALL UNMSG ('Invalid text orientation passed to CHMONO.')
      ENDIF

      CALL TXCOMP (WKTYPE, TXOR, FONT, CHXP, CHSP, CHH, STR,
     1             EXTXHI, EXTYHI, EXCCX, EXCCY, RECTOK, CCPOK)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.03.03/txcomp                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TXCOMP (WKTYPE, TXOR, FONT, CHXP, CHSP, CHH,
     1                   STR, EXTXHI, EXTYHI, EXCCX, EXCCY,
     2                   RECTOK, CCPOK)

C  TXCOMP compares actual and expected values for results of
C  <inquire text extent> and reports results in two logical
C  variables. TXCOMP tests both text paths for the given
C  orientation, i.e. LEFT and RIGHT for horizontal, UP and
C  DOWN for vertical.

C Input parameters:
C   wktype  : workstation type
C   txor    : text path orientation
C   font    : text font
C   chxp    : character expansion factor
C   chsp    : character spacing
C   chh     : character height
C   str     : character string
C   extxhi  : expected value for x size of text rectangle
C   extyhi  : expected value for y size of text rectangle
C   exccx   : expected value for x concatenation point
C   exccy   : expected value for y concatenation point
C Output parameters:
C   rectok  : text rectangle OK
C   ccpok   : concatenation point OK

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

      INTEGER    WKTYPE, TXOR, FONT, TXALH, TXALV, TXP, ERRIND
      INTEGER    HRIZNT,     VERTIC
      PARAMETER (HRIZNT = 1, VERTIC = 2)

      REAL       CHXP, CHSP, CHH, EXTXHI, EXTYHI, EXCCX, EXCCY
      REAL       ABSTOL, RELTOL, EXTXLO, EXTYLO, BASBOT
      REAL       ACTX(2), ACTY(2), ACCX, ACCY, ACHH, ADJCCY

      LOGICAL    APPEQ, RECTOK, CCPOK

      CHARACTER  STR*(*)

      ACHH = ABS (CHH)

C abstol = absolute tolerance
C reltol = relative tolerance
      ABSTOL = .02 * ACHH
      RELTOL = .02

C  Since txal = LEFT,BOTTOM, expected lower bounds are always zero:
C  extxlo = 0, extylo = 0
      TXALH = PALEFT
      TXALV = PABOTT
      EXTXLO  = 0.0
      EXTYLO  = 0.0

      IF     (TXOR .EQ. HRIZNT) THEN
         TXP = PRIGHT
         ADJCCY = EXCCY
      ELSEIF (TXOR .EQ. VERTIC) THEN
         TXP = PUP
C  this is to compensate for the additional space between the
C  bottom and baseline.
         ADJCCY = EXCCY + ACHH * BASBOT (WKTYPE, FONT)
      ELSE
         CALL UNMSG ('Invalid text orientation passed to TXCOMP.')
      ENDIF

C <Inquire text extent> with:
C       wktype, font, chxp, chsp, chh, txp, txal, str
C    to determine actual results:
C       actxlo,actxhi, actylo,actyhi, accx,accy

      CALL PQTXX (WKTYPE, FONT, CHXP, CHSP, CHH, TXP, TXALH,
     1            TXALV, STR, ERRIND, ACTX, ACTY, ACCX, ACCY)
      CALL CHKINQ ('pqtxx', ERRIND)

      RECTOK = APPEQ (ACTX(1), EXTXLO, ABSTOL, RELTOL) .AND.
     1         APPEQ (ACTX(2), EXTXHI, ABSTOL, RELTOL) .AND.
     2         APPEQ (ACTY(1), EXTYLO, ABSTOL, RELTOL) .AND.
     3         APPEQ (ACTY(2), EXTYHI, ABSTOL, RELTOL)
      CCPOK = APPEQ (ACCX,  EXCCX, ABSTOL, RELTOL) .AND.
     1        APPEQ (ACCY, ADJCCY, ABSTOL, RELTOL)

C Switch text path direction:
      IF (TXOR .EQ. HRIZNT) THEN
         TXP = PLEFT
         EXCCX  = EXTXHI - EXCCX
      ELSE
         TXP = PDOWN
         EXCCY  = EXTYHI - EXCCY
      ENDIF

      CALL PQTXX (WKTYPE, FONT, CHXP, CHSP, CHH, TXP, TXALH,
     1            TXALV, STR, ERRIND, ACTX, ACTY, ACCX, ACCY)
      CALL CHKINQ ('pqtxx', ERRIND)

      RECTOK = APPEQ (ACTX(1), EXTXLO, ABSTOL, RELTOL) .AND.
     1         APPEQ (ACTX(2), EXTXHI, ABSTOL, RELTOL) .AND.
     2         APPEQ (ACTY(1), EXTYLO, ABSTOL, RELTOL) .AND.
     3         APPEQ (ACTY(2), EXTYHI, ABSTOL, RELTOL) .AND.
     4         RECTOK
      CCPOK = APPEQ (ACCX, EXCCX, ABSTOL, RELTOL) .AND.
     1        APPEQ (ACCY, EXCCY, ABSTOL, RELTOL) .AND.
     2        CCPOK

      END
