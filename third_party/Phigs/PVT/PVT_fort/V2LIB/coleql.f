      LOGICAL FUNCTION COLEQL (SIZE, ACT,EXP, ABSERR,RELERR)

C  Special purpose routine for testing approximate equality of
C  all three color components, unless one is -1.

C  Input parameters:
C    SIZE    : Number of elements to be compared
C    ACT     : actual values
C    EXP     : expected values
C    ABSERR  : absolute tolerance
C    RELERR  : relative tolerance

      INTEGER  SIZE, IX
      REAL     ACT(SIZE), EXP(SIZE), ABSERR, RELERR
      LOGICAL  APPEQ

      DO 100 IX = 1,SIZE
         IF (ACT(IX) .EQ. -1 .OR. EXP(IX) .EQ. -1) THEN
C OK so far
         ELSEIF (APPEQ (ACT(IX), EXP(IX), ABSERR, RELERR)) THEN
C OK so far
         ELSE
            COLEQL = .FALSE.
            RETURN
         ENDIF
100   CONTINUE
      COLEQL = .TRUE.

      END
