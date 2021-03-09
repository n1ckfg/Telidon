      SUBROUTINE PERVEC (VX1,VY1,VZ1, VX2,VY2,VZ2, VX3,VY3,VZ3)

C  This subroutine accepts two 3D vectors and returns a vector
C  orthogonal to the first, in the plane of the first two vectors,
C  whose dot product with the second vector is positive, hence
C  the angle between them is < 90 degrees.  I.e. the 2nd vector
C  minus the 3rd results in a vector with the same direction (but
C  not length) as the 1st.  K is the factor by which V1 is
C  multiplied and then subtracted from V2 - i.e.
C
C       V3 = V2 - K*V1


C                     _
C                     /|A
C                   /   |
C                 /     |
C            V2 /       | V3
C             /         |
C           /           |
C         /             |
C       /               |
C      ----------->.....|
C          V1
C      \________________/
C           V2 - V3

C  Or, V1 can be thought of as the attitude numbers for a plane, and
C  then V3 is the result of the normal projection of V2 into the plane.
C
C  Closely related to PTPLDS, which is a slightly more general case.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2, VX3,VY3,VZ3, K, DOTPRD, VECL2

      K = DOTPRD (VX1,VY1,VZ1, VX2,VY2,VZ2) / VECL2 (VX1, VY1, VZ1)
      VX3 = VX2 - K*VX1
      VY3 = VY2 - K*VY1
      VZ3 = VZ2 - K*VZ1

      END
