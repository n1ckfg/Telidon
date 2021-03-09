      REAL FUNCTION VECANG (VX1,VY1,VZ1, VX2,VY2,VZ2)

C  This function accepts two 3D vectors and returns the
C  angle between them.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2, VECL, DOTPRD, VL, COSVAL

      VL = VECL(VX1,VY1,VZ1) * VECL(VX2,VY2,VZ2)

      IF (VL .EQ. 0) THEN
         VECANG = 0.0
      ELSE
         COSVAL = DOTPRD (VX1,VY1,VZ1, VX2,VY2,VZ2) / VL
         IF (ABS(COSVAL) .GT. 1.0) THEN
            CALL UNMSG ('Unstable parameters passed to VECANG.')
         ENDIF
         VECANG = ACOS (COSVAL)
      ENDIF

      END
