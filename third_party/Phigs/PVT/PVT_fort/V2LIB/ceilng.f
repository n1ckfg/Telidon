      INTEGER FUNCTION CEILNG (X)

C  CEILNG returns the integer ceiling for x, i.e. the lowest
C  integer .ge. x

      INTEGER    IX
      REAL       X

      IX = INT(X)
      IF (REAL(IX).EQ.X .OR. X.LE.0) THEN
         CEILNG = IX
      ELSE
         CEILNG = IX + 1
      ENDIF

      END
