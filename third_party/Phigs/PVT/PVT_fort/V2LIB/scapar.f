      SUBROUTINE SCAPAR (DTCLIM,CHWRAT,DYXRAT,NUMLIN,LINPOS, CHHT,LOGHW)

C  SCAPAR calculates the needed scaling factor and logical
C  height/width ratio of a paragraph, given a line break-up.

C  Input parameters:
C    DTCLIM : maximum number of characters per line
C    CHWRAT : desired height/width ratio of each character
C    DYXRAT : height/width ratio of paragraph area
C    NUMLIN : number of logical lines in paragraph
C    LINPOS : array of starting positions of lines within MSGTXT
C  Output parameters:
C    CHHT   : resulting character height
C    LOGHW  : logical height/width ratio of resulting paragraph

      INTEGER   DTCLIM, NUMLIN, LINPOS(*)
      REAL      CHWRAT, DYXRAT, CHHT, LOGHW, LOGWID,LOGHT

      IF (NUMLIN .GT. 1) THEN
         LOGWID = DTCLIM
      ELSE
         LOGWID = LINPOS(2)-1
      ENDIF
      LOGHT = NUMLIN*CHWRAT
      LOGHW = LOGHT / LOGWID

C  1/LOGWID takes effect for a "full" multi-line paragraph.
C  DYXRAT/LOGHT takes effect for a partially-filled single-line paragraph.
      CHHT  = MIN (1/LOGWID, DYXRAT/LOGHT)

      END
