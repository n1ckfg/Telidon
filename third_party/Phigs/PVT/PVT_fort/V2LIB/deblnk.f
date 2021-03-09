      SUBROUTINE DEBLNK (STRIN, STROUT, NEWSIZ)

C  deblnk accepts a string (strin) and generates from it another
C  string (strout) with all leading and internal blanks deleted. It
C  also returns the new size of the compressed string as newsiz,
C  which points to the last non-blank (0 if all blank).

      CHARACTER  STRIN*(*), STROUT*(*)
      INTEGER    NEWSIZ, ITRIM, IX, NBLEN, NBLOC, RECV

      STROUT = ' '
      NBLOC  = 0
      NBLEN  = 1
      RECV   = 1

100   CONTINUE
C get next sending non-blank
      DO 200 IX = NBLOC+NBLEN, LEN(STRIN)
         IF (STRIN(IX:IX) .NE. ' ') THEN
            NBLOC = IX
            GOTO 210
         ENDIF
200   CONTINUE
C no more non-blanks
      GOTO 300

C send next non-blank field
210   CONTINUE
      STROUT (RECV:) = STRIN(NBLOC:)

C more blanks to compress out?
      NBLEN = INDEX(STRIN(NBLOC:), ' ') - 1
      IF (NBLEN .EQ. -1) THEN
C        all done
      ELSE
C set recv
         RECV = RECV + NBLEN
         GOTO 100
      ENDIF

300   CONTINUE
      NEWSIZ = ITRIM(STROUT)

      END
