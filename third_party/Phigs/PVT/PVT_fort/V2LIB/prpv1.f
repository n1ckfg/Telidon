      SUBROUTINE PRPV1 (VX1,VY1,VZ1, VX2,VY2,VZ2)

C  PRPV1 accepts a 3D vector and returns another 3D vector
C  perpendicular to it.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2, Z

      Z = 0.0
      VX2 = Z
      VY2 = Z
      VZ2 = Z
      IF (VX1 .EQ. Z) THEN
         VX2 = 1.0
      ELSEIF (VY1 .EQ. Z) THEN
         VY2 = 1.0
      ELSEIF (VZ1 .EQ. Z) THEN
         VZ2 = 1.0
      ELSE
         VX2 =  VY1
         VY2 = -VX1
      ENDIF

      END
