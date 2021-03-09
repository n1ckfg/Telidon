      LOGICAL FUNCTION IAREQ (SIZE, ACT,EXP)

C  General purpose routine for equality of two integer arrays.
C  ------- Input parameters:
C  size    : Number of elements to be compared
C  act     : actual values
C  exp     : expected values

C  This will handle multi-dimensional arrays according to the usual
C  Fortran rules for overlaying arrays.

      INTEGER  SIZE, IX, ACT(*), EXP(*)

      DO 100 IX = 1,SIZE
         IF (ACT(IX) .NE. EXP(IX)) THEN
            IAREQ = .FALSE.
            RETURN
         ENDIF
100   CONTINUE
      IAREQ = .TRUE.

      END
