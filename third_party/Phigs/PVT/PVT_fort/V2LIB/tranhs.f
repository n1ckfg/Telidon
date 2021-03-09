      SUBROUTINE TRANHS (HS, XFORM, A,B,C,D)

C  TRANHS accepts a 3D half-space, described as a point (on the
C  boundary plane) and normal vector, applies a transform, and
C  returns the coefficients of the new boundary plane, such that
C  x,y,z is in the new half-space iff A*x + B*y + C*z + D .GE. 0

C  Input parameters:
C    HS(1,2,3)  : x,y,z coordinates of point of half-space
C    HS(4,5,6)  : x,y,z coordinates of normal vector of half-space
C    XFORM      : transformation matrix
C  Output parameters:
C    A,B,C,D    : coefficients of new boundary plane.

      REAL    HS(6), XFORM(4,4), TMPX,TMPY,TMPZ, A,B,C,D
      REAL    VECAX,VECAY,VECAZ, VECBX,VECBY,VECBZ
      REAL    OLDX(4),OLDY(4),OLDZ(4), NEWX(4),NEWY(4),NEWZ(4)

C  VECA is a unit vector orthogonal to the normal vector
      CALL PRPV1 (HS(4),HS(5),HS(6), TMPX, TMPY, TMPZ)
      CALL VEC1  (TMPX, TMPY, TMPZ,  VECAX,VECAY,VECAZ)
C  VECB is a unit vector orthogonal to the normal vector and VECA
      CALL CROSSP (VECAX,VECAY,VECAZ, HS(4),HS(5),HS(6),
     1             TMPX, TMPY, TMPZ)
      CALL VEC1 (TMPX,TMPY,TMPZ, VECBX,VECBY,VECBZ)

C  OLD-1, OLD-2, and OLD-3 are all in the (old) boundary plane,
C  forming an L-shape.
      OLDX(1) = HS(1) + VECAX
      OLDY(1) = HS(2) + VECAY
      OLDZ(1) = HS(3) + VECAZ

      OLDX(2) = HS(1) + VECBX
      OLDY(2) = HS(2) + VECBY
      OLDZ(2) = HS(3) + VECBZ

      OLDX(3) = HS(1)
      OLDY(3) = HS(2)
      OLDZ(3) = HS(3)

C  OLD-4 is a point inside the (old) half-space
      OLDX(4) = HS(1) + HS(4)
      OLDY(4) = HS(2) + HS(5)
      OLDZ(4) = HS(3) + HS(6)

C  transform 4 old points to 4 new points
      CALL ARRTP3 (4, OLDX,OLDY,OLDZ, XFORM, NEWX,NEWY,NEWZ)

C  first 3 new points define new boundary plane
      CALL PT3PL (NEWX,NEWY,NEWZ, A,B,C,D)

C  check that parity is OK - if not, negate co-efficients
      IF (A*NEWX(4) + B*NEWY(4) + C*NEWZ(4) + D .LT. 0) THEN
         A = -A
         B = -B
         C = -C
         D = -D
      ENDIF

      END
