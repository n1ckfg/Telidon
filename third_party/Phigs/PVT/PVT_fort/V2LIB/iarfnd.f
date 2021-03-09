      INTEGER FUNCTION IARFND (KEY, ARSIZ, IARR)

C  IARFND searches the first ARSIZ entries within IARR, and returns
C  the first location equal to KEY. If not found, 0 is returned.

      INTEGER   IX, KEY, ARSIZ, IARR(*)

      DO 100 IX = 1,ARSIZ
         IF (IARR(IX) .EQ. KEY) THEN
            IARFND = IX
            RETURN
         ENDIF
100   CONTINUE
      IARFND = 0

      END
