      SUBROUTINE INVOL (PX,PY,PZ, ILIM, ARX,ARY,ARZ, SIDE, PLDIST)

C  Given a 3D point and planar fill area, determine whether point
C  is within normal projection of the area, and distance of point
C  from the plane.

C  Input parameters:
C    PX,PY,PZ     : 3D point
C    ILIM         : Number of vertices of fill area
C    ARX,ARY,ARZ  : vertices of fill area

C  Output parameters:
C    SIDE         : location of point within volume -
C                 : 1 if inside, 2 if on an edge, 3 if outside
C    PLDIST       : distance of point from the plane.

      INTEGER   ILIM, INAREA, IDIM, SIDE

      REAL      PX,PY,PZ, ARX(*),ARY(*),ARZ(*)
      REAL      A,B,C,D, XN,YN,ZN, PLDIST, BEST

      IF (ILIM .LT. 3) THEN
         CALL UNMSG ('Degenerate fill area passed to INVOL.')
      ENDIF

C get plane from set of points
      CALL PTSPL (ILIM, ARX,ARY,ARZ, A,B,C,D)

C Given a point and plane-coefficients, find nearest
C point on plane and distance from plane to point.
      CALL PTPLDS (PX,PY,PZ, A,B,C,D, XN,YN,ZN, PLDIST)

C  Now project the planar points (fill area, plus the normal
C  projected point xn,yn,zn) to the "best" plane: x=0, y=0, or z=0,
C  depending on largest attitude number.
      IF (ABS(A) .GT. ABS(B)) THEN
         IDIM = 1
         BEST=ABS(A)
      ELSE
         IDIM = 2
         BEST=ABS(B)
      ENDIF

      IF (ABS(C) .GT. BEST) THEN
         IDIM = 3
      ENDIF

      IF     (IDIM .EQ. 1) THEN
C project to x=0
         SIDE = INAREA (YN,ZN, ILIM, ARY,ARZ)
      ELSEIF (IDIM .EQ. 2) THEN
C project to y=0
         SIDE = INAREA (XN,ZN, ILIM, ARX,ARZ)
      ELSE
C project to z=0
         SIDE = INAREA (XN,YN, ILIM, ARX,ARY)
      ENDIF

      END
