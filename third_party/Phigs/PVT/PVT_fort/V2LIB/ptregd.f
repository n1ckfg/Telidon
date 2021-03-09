      REAL FUNCTION PTREGD (PX,PY,PZ, NSZ, XA,YA,ZA)

C  PTREGD computes the minimum distance from a 3D point to a planar
C  3D region.

C Input parameters:
C   PX,PY,PZ : point for which distance is found.
C   NSZ      : number of points in region.
C   XA,YA,ZA : coordinates of planar region.

      INTEGER    NSZ, IA, IB, SIDE

      REAL       PX,PY,PZ, XA(NSZ),YA(NSZ),ZA(NSZ)
      REAL       XN,YN,ZN, PTMIN, EDGMIN
      REAL       SEGA,SEGB,SEGC, D1,D2, ABCP, DTMP,VECL, PLDIST

      IF (NSZ .LT. 3) THEN
         CALL UNMSG ('Degenerate region passed to PTREGD.')
      ENDIF

      CALL INVOL (PX,PY,PZ, NSZ, XA,YA,ZA, SIDE, PLDIST)
      IF (SIDE .LE. 2) THEN
C  Distance is simply distance of point from containing plane
         PTREGD = PLDIST
         RETURN
      ENDIF

C  Distance is minimum of distances from points and from individual edges

C  Get point minimum:
      PTMIN = 1E38
      DO 100 IA = 1,NSZ
         DTMP = VECL (PX-XA(IA), PY-YA(IA), PZ-ZA(IA) )
         IF (DTMP .LT. PTMIN) PTMIN = DTMP
100   CONTINUE

C  Get edge minimum:
      EDGMIN = 1E38
      DO 200 IA = 1,NSZ
         IB = MOD(IA, NSZ) + 1
C  Determine if point is between the two planes that contain the
C  endpoints of the segment, and are normal to it.  If not, ignore -
C  handled by point minimum.  If so, distance is that from point to
C  containing line.

C  attitude of planes:
         SEGA = XA(IA) - XA(IB)
         SEGB = YA(IA) - YA(IB)
         SEGC = ZA(IA) - ZA(IB)
C  d-coefficient of each plane:
         D1 = -(SEGA*XA(IA) + SEGB*YA(IA) + SEGC*ZA(IA))
         D2 = -(SEGA*XA(IB) + SEGB*YA(IB) + SEGC*ZA(IB))
C  ABC terms for px,py,pz:
         ABCP = SEGA*PX + SEGB*PY + SEGC*PZ
         IF ( (ABCP + D1) * (ABCP + D2) .LT. 0.0 ) THEN
C  Opposite signs imply point is between planes - get distance from
C  point to line.
            CALL PTLNDS (PX,PY,PZ, SEGA,SEGB,SEGC,
     1                   XA(IA),YA(IA),ZA(IA), XN,YN,ZN, DTMP)
            IF (DTMP .LT. EDGMIN) EDGMIN = DTMP
         ENDIF
200   CONTINUE

      PTREGD = MIN (PTMIN, EDGMIN)

      END
