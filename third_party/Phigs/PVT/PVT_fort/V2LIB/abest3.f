      INTEGER FUNCTION ABEST3 (AA,BA,CA)

      REAL  A,B,C,BEST, AA,BA,CA

C  function to pick greatest magnitude of 3 numbers

      A = ABS(AA)
      B = ABS(BA)
      C = ABS(CA)

      IF (A .GT. B) THEN
         ABEST3 = 1
         BEST=A
      ELSE
         ABEST3 = 2
         BEST=B
      ENDIF

      IF (C .GT. BEST) THEN
         ABEST3 = 3
      ENDIF

      END
