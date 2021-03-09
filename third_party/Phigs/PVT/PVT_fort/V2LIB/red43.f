      SUBROUTINE RED43 (M4, M3)

C General purpose routine to reduce a 4x4 matrix to 3x3, by
C suppressing 3rd row and column

      REAL     M4(4,4), M3(3,3)
      INTEGER  I,J, IR,JR

      DO 100 I = 1,4
         IR = MIN(I,3)
         DO 200 J = 1,4
            JR = MIN(J,3)
            M3(IR,JR) = M4(I,J)
200      CONTINUE
100   CONTINUE

      END
