      SUBROUTINE SRTRAR (SIZ, ARR)

C  SRTRAR sorts a real array in place, into ascending order.
C
C  Input parameter:
C    SIZ : number of elements in array to be sorted.
C  Input/output parameter:
C    ARR : the array of integers to be sorted.

      INTEGER   SIZ, I,J
      REAL      ARR(SIZ), TMP

      DO 100 I = 1,SIZ-1
      DO 200 J = I+1,SIZ
         IF (ARR(I) .GT. ARR(J)) THEN
            TMP    = ARR(I)
            ARR(I) = ARR(J)
            ARR(J) = TMP
         ENDIF
200   CONTINUE
100   CONTINUE

      END
