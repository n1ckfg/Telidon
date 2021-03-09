      INTEGER FUNCTION LEADNB (TXT)

C  LEADNB returns the character position of the first (leftmost)
C  non-blank character within TXT.  If there is none, 0 is returned.

      INTEGER    LO,HI,MID
      CHARACTER  TXT*(*)

      IF (TXT .EQ. ' ') THEN
         LEADNB = 0
         RETURN
      ENDIF

C  LO always points to a location *before* the first non-blank,
C  HI to a location *at or after* the first non-blank.
      LO = 0
      HI = LEN(TXT)

100   CONTINUE
      IF (HI-LO .LE. 1) GOTO 666
      MID = (HI+LO)/2
      IF (TXT(1:MID) .EQ. ' ') THEN
         LO = MID
      ELSE
         HI = MID
      ENDIF
      GOTO 100

666   CONTINUE
      LEADNB = HI
      END
