      SUBROUTINE RNBSET  (SIZE, LO, HI, SET)

C  RNBSET returns a random set of SIZE distinct integers, chosen from
C  the universe of LO-HI (inclusive), returned in SET.  For example,
C  if SIZE is specified as 4, LO=3 and HI=10, SET might = [9,5,7,4].

      INTEGER   SIZE, LO,HI, SET (SIZE), IX, IY, RNDINT

      IF (SIZE .GT. HI-LO+1) THEN
         CALL UNMSG ('In RNBSET, size of set exceeds universe.')
      ENDIF

      DO 100 IX = 1,SIZE
110      CONTINUE
         SET (IX) = RNDINT (LO,HI)
         DO 200 IY = 1, IX-1
            IF (SET(IX) .EQ. SET(IY)) GOTO 110
200      CONTINUE
100   CONTINUE

      END
