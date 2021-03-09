      SUBROUTINE HUEANG (R,G,B, ANG, DIST)

C  This program calculates a characteristic angle for a hue from the
C  RGB color cube.  It does so by rotating the cube 45 deg around the
C  y-axis and atan(sqrt(2)) around the z-axis (assuming xyz = RGB).
C  This lines up the black-white cube diagonal (0,0,0 to 1,1,1) along
C  the y-axis.  Now, transformed points along the color-saturated
C  vertices are such that their angle in the x-z plane is a measure
C  of hue; so atan2 is used to compute the hue of any RGB point.

C  BTW, somewhat surprisingly, the points which are transformed into
C  the x=0 plane are all those in the old plane described by:
C  x -2y + z = 0 (this plane contains the points (0,0,0), (1,1,1),
C  and (0,.5,1), all of which can be "seen" to be rotated into x=0
C  plane).  This plane is such that it is satisfied by any points of
C  the form: (q, q+c, q+2c), so that sample points like (3,4,5) will
C  always transform into the x=0 plane.

C  Hueang also returns the distance of the RGB point from the
C  neutral (black-white) axis.

      REAL TMAT(4,4), R,G,B, XO,YO,ZO, PI,A45, ZZ,U, ANG, DIST

      ZZ = 0.0
      U = 1.0
      PI = 3.14159265
      A45 = PI/4.0

      CALL EBLTM3 (ZZ,ZZ,ZZ, ZZ,ZZ,ZZ, ZZ,A45,ATAN(SQRT(2.0)),
     1             U,U,U, TMAT)

10    CONTINUE

      CALL ETP3 (R,G,B, TMAT,  XO,YO,ZO)

      DIST = SQRT(XO*XO + ZO*ZO)

      IF (DIST .EQ. ZZ) THEN
         ANG = -666.0
      ELSE
C  Normalize to 0..1
         ANG = ATAN2(XO,ZO) / (2*PI)
         IF (ANG .LT. 0.0) ANG = ANG + 1
      ENDIF

      END
