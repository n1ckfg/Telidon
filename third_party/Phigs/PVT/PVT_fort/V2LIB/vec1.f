      SUBROUTINE VEC1 (VX,VY,VZ, VX1,VY1,VZ1)

C  This subroutine accepts an arbitrary 3D vector and returns a
C  parallel vector normalized to unit size.

      REAL  VX,VY,VZ, VX1,VY1,VZ1, D, VECL

      D = VECL(VX,VY,VZ)
      VX1 = VX/D
      VY1 = VY/D
      VZ1 = VZ/D

      END
