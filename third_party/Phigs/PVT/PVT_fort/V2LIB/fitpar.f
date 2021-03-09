      SUBROUTINE FITPAR (MSGTXT, CHWRAT, PHWRAT, LINSIZ)

C  FITPAR calculates a reasonably good line size (number of characters)
C  for fitting MSGTXT into a rectangular area.

C  Input parameters:
C    MSGTXT : Text to be fit
C    CHWRAT : Desired height/width ratio of each character
C    PHWRAT : Height/width ratio of area to hold paragraph
C  Output parameters:
C    LINSIZ : Number of characters per line

C  let:
C    #chars = #lines * chars-per-line
C    char-height = phwrat/#lines
C    char-width  = 1/chars-per-line
C    char-height/char-width = CHWRAT
C  then
C    chars-per-line = sqrt(CHWRAT*#chars / phwrat)

      INTEGER    LINSIZ, LENMSG, ITRIM, MINLIN, ERR, NUMLIN,LINPOS(300)
      INTEGER    SIZSAV

      REAL       CHWRAT, PHWRAT, CHHT1,CHHT2, LOGHW

      CHARACTER  MSGTXT*(*)

      LENMSG = ITRIM(MSGTXT)
C  3 is fudge factor, because there won't be perfect packing.
      LINSIZ = SQRT(CHWRAT*LENMSG/PHWRAT) + 3
C  15 is minimum tolerable line-length
      MINLIN = 15
      LINSIZ = MAX (MINLIN,LINSIZ)
C  Generate line-breaks for LINSIZ:
      CALL LINBRK (MSGTXT, LINSIZ, ERR, NUMLIN, LINPOS)
C  get resulting character height
      CALL SCAPAR (LINSIZ,CHWRAT,PHWRAT,NUMLIN,LINPOS, CHHT1,LOGHW)

C  alter LINSIZ for attempted better fit
      SIZSAV = LINSIZ
      IF (LOGHW .GT. PHWRAT .AND. NUMLIN .EQ. 2) THEN
C  2-line message is too tall ... force to 1 line
         LINSIZ = LENMSG
      ELSE
C  try to converge on proper height/width ratio for paragraph
         LINSIZ = LINSIZ * LOGHW / PHWRAT
      ENDIF

      LINSIZ = MAX (MINLIN,LINSIZ)
C  Generate line-breaks for 2nd LINSIZ:
      CALL LINBRK (MSGTXT, LINSIZ, ERR, NUMLIN, LINPOS)
C  get 2nd resulting character height
      CALL SCAPAR (LINSIZ,CHWRAT,PHWRAT,NUMLIN,LINPOS, CHHT2,LOGHW)

C  If 2nd attempt generated smaller characters, re-set to 1st,
C  otherwise leave LINSIZ as is.
      IF (CHHT1 .GT. CHHT2) LINSIZ = SIZSAV

      END
