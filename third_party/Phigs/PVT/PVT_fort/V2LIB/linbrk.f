      SUBROUTINE LINBRK (MSGTXT, DTCLIM, ERR, NUMLIN, LINPOS)

C  LINBRK calculates starting positions within a character string so
C  as to break it up into lines of at most DTCLIM characters. LINBRK
C  tries to break lines only on blanks, and it constructs the
C  longest line possible within the DTCLIM limit.  It returns the
C  number of lines in NUMLIN, and the starting positions within
C  LINPOS.  An "extra" position is calculated after the last line,
C  pointing just beyond the last non-blank, so that the location of
C  the end of the last line is available.  If a single word
C  (contiguous non-blanks) is longer than DTCLIM, it is broken up
C  after DTCLIM characters, and ERR is set to 1.

C  Input parameters:
C    MSGTXT : character string to be broken up
C    DTCLIM : maximum number of characters in each chunk
C  Output parameters:
C    ERR    : error code: 0 if OK, 1 if line overflow
C    NUMLIN : number of logical lines found in MSGTXT
C    LINPOS : array of starting positions of lines within MSGTXT

      INTEGER     NXTPOS, ERR, DTCLIM, NUMLIN, LINPOS(*), LENMSG
      INTEGER     ITRIM, STLIN, LEADNB

      CHARACTER   MSGTXT*(*)

      ERR = 0
      NUMLIN = 0
      IF (MSGTXT .EQ. ' ') RETURN
      LENMSG = ITRIM(MSGTXT)
      NXTPOS = 1

100   CONTINUE
C  seek next non-blank
      STLIN = LEADNB (MSGTXT(NXTPOS:))
C  get absolute position of line-starting non-blank
      STLIN = STLIN + NXTPOS - 1
C  record starting position
      NUMLIN = NUMLIN + 1
      LINPOS(NUMLIN) = STLIN
C  any non-blanks beyond this line?
      IF (LENMSG-STLIN .LT. DTCLIM) THEN
         LINPOS(NUMLIN+1) = LENMSG+1
         RETURN
      ENDIF

      DO 200 NXTPOS = STLIN+DTCLIM, STLIN, -1
         IF (MSGTXT(NXTPOS:NXTPOS) .EQ. ' ') GOTO 100
200   CONTINUE

C  no space within line
      ERR = 1
      NXTPOS = STLIN+DTCLIM
      GOTO 100

      END
