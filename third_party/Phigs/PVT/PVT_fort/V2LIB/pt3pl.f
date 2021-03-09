      SUBROUTINE PT3PL (X,Y,Z, A,B,C,D)

      REAL   X(3),Y(3),Z(3), A,B,C,D

C Given 3 points, find containing plane
      A = Y(2)*Z(3) + Y(3)*Z(1) + Y(1)*Z(2)
     1  - Y(1)*Z(3) - Y(2)*Z(1) - Y(3)*Z(2)
      B = Z(2)*X(3) + Z(3)*X(1) + Z(1)*X(2)
     1  - Z(1)*X(3) - Z(2)*X(1) - Z(3)*X(2)
      C = X(2)*Y(3) + X(3)*Y(1) + X(1)*Y(2)
     1  - X(1)*Y(3) - X(2)*Y(1) - X(3)*Y(2)

      D = - (A*X(1) + B*Y(1) + C*Z(1) +
     1       A*X(2) + B*Y(2) + C*Z(2) +
     2       A*X(3) + B*Y(3) + C*Z(3)) / 3

      END
