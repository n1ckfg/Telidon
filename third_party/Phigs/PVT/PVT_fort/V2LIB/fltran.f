      SUBROUTINE FLTRAN (A,B,C, MAT)

C  Given a set of attitude numbers for a plane, FLTRAN returns a
C  4 X 4 transformation matrix which rotates the plane so as to be
C  parallel to the z=0 plane.  This is useful for visualizing a
C  planar 3D primitive.

      REAL     A,B,C, MAT(4,4), ZZ,UU, VECL, SATAN2

      ZZ = 0.0
      UU = 1.0

      CALL EBLTM3 (ZZ,ZZ,ZZ, ZZ,ZZ,ZZ,
     1     -SATAN2(-B,C), -ASIN(A/VECL(A,B,C)),ZZ, UU,UU,UU, MAT)

      END
