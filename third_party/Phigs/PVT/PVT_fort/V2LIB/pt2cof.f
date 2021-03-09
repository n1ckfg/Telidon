      SUBROUTINE PT2COF (X1,Y1, X2,Y2, A,B,C)
C Given two points, calculate line coefficients.

      REAL   X1,Y1, X2,Y2, A,B,C

      A = Y1-Y2
      B = X2-X1
      C = X1*Y2 - Y1*X2

      END
