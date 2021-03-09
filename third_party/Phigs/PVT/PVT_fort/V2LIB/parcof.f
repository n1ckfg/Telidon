      SUBROUTINE PARCOF (X0,Y0, XCOEFF,YCOEFF, A,B,C)
C  given parametric form, find line coefficients

      REAL  X0,Y0, XCOEFF,YCOEFF, A,B,C

      A =  YCOEFF
      B = -XCOEFF
      C =  XCOEFF*Y0 - YCOEFF*X0

      END
