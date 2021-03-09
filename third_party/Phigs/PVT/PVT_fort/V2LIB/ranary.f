      SUBROUTINE RANARY (SIZE,ARRAY)

C  RANARY initializes a 2D array of size x size to random values
C  between 0.5 and 1.5

      INTEGER SIZE, I,J
      REAL    ARRAY(SIZE,SIZE), RNDRL

      DO 100 I = 1, SIZE
      DO 200 J = 1, SIZE
         ARRAY(I,J) = RNDRL(0.5,1.5)
200   CONTINUE
100   CONTINUE

      END
