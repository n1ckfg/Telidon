      LOGICAL FUNCTION RAREQ (SIZE, ACT,EXP, ABSERR, RELERR)

C  General purpose routine for approximate equality of two real arrays.
C  ------- Input parameters:
C  size    : Number of elements to be compared
C  act     : actual values
C  exp     : expected values
C  abserr  : absolute tolerance
C  relerr  : relative tolerance

C  This will handle multi-dimensional arrays according to the usual
C  Fortran rules for overlaying arrays.

      INTEGER  SIZE, IX
      REAL     ACT(SIZE), EXP(SIZE), ABSERR, RELERR
      LOGICAL  APPEQ

      DO 100 IX = 1,SIZE
         IF (APPEQ ( ACT(IX), EXP(IX), ABSERR, RELERR)) THEN
C OK so far
         ELSE
            RAREQ = .FALSE.
            RETURN
         ENDIF
100   CONTINUE
      RAREQ = .TRUE.

      END
