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
