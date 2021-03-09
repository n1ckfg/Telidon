      SUBROUTINE IDMAT (SZ, MAT)

C General purpose routine to initialize a square matrix to
C the identity matrix.

      INTEGER   SZ, I,J
      REAL      MAT(SZ, SZ)

      DO 100 I = 1,SZ
      DO 200 J = 1,SZ
         IF (I .EQ. J) THEN
            MAT (I,J) = 1.0
         ELSE
            MAT (I,J) = 0.0
         ENDIF
200   CONTINUE
100   CONTINUE

      END
