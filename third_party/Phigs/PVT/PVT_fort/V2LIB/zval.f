      REAL FUNCTION ZVAL (X,Y)

C  ZVAL is just a simple linear function of x and y so as to
C  generate 3D points on the plane: 3x + 4y - z - 7 = 0, so
C    z = f(x,y) = 3x + 4y - 7

      REAL  X,Y

      ZVAL = 3*X + 4*Y - 7

      END
