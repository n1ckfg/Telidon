      SUBROUTINE LINTPT (A,B,C, D,E,F, X,Y)

C Given two sets of line-coefficients, find intersection point

      REAL  A,B,C,D,E,F,X,Y, DEN

      DEN = D*B - A*E
      X = (C*E - F*B) / DEN
      Y = (F*A - C*D) / DEN

      END
