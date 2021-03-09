      SUBROUTINE EXP34  (MAT3, MAT4)

C  Expand a 3x3 matrix into a 4x4 matrix.

      INTEGER  I,J, IRECV,JRECV

      REAL   MAT3(3,3), MAT4(4,4)

      CALL IDMAT (4,MAT4)
      DO 100 I = 1,3
         IF (I.EQ.3) THEN
            IRECV = 4
         ELSE
            IRECV = I
         ENDIF
         DO 200 J = 1,3
            IF (J.EQ.3) THEN
               JRECV = 4
            ELSE
               JRECV = J
            ENDIF
            MAT4 (IRECV, JRECV) = MAT3 (I, J)
200      CONTINUE
100   CONTINUE

      END
