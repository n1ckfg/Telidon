      SUBROUTINE CROSSP (VX1,VY1,VZ1, VX2,VY2,VZ2, VX3,VY3,VZ3)

C  This subroutine accepts two 3D vectors and returns their
C  cross product.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2, VX3,VY3,VZ3

      VX3 = VY1*VZ2 - VZ1*VY2
      VY3 = VZ1*VX2 - VX1*VZ2
      VZ3 = VX1*VY2 - VY1*VX2

      END
