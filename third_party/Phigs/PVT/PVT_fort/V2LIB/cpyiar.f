      SUBROUTINE CPYIAR (SIZE,FROM,TO)

C  CPYIAR copies the contents of an array of a given size to
C  another array.

C  Input parameters:
C    SIZE : number of elements to copy
C    TO   : source array
C  Output parameter:
C    FROM : destination array

      INTEGER   SIZE,I
      REAL      FROM(*), TO(*)

      DO 100 I = 1, SIZE
        TO(I) = FROM(I)
100   CONTINUE
      END
