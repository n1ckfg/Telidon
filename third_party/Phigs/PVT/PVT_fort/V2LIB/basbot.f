      REAL FUNCTION BASBOT (WKTYPE, FONT)

C  BASBOT returns the nominal distance (i.e. for character height =
C  1.0) between the baseline and bottom of characters for a given
C  workstation type and font.

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

      INTEGER    WKTYPE,FONT, ERRIND

      REAL       XB(2),YB(2),CCX,CCY

      CHARACTER  STR*7
      DATA       STR / 'ISO Wg2' /

      CALL PQTXX (WKTYPE, FONT, 1.0,0.0,1.0,PRIGHT,PALEFT,PABASE,
     1            STR, ERRIND, XB,YB,CCX,CCY)
      CALL CHKINQ ('pqtxx', ERRIND)

      BASBOT = -YB(1)

      END
