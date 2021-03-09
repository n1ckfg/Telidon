      SUBROUTINE PL2LN (A1,B1,C1,D1, A2,B2,C2,D2, A,B,C, PX,PY,PZ)

C  Given two planes, return line-intersection

      INTEGER  IXYZ, ABEST3
      REAL     A1,B1,C1,D1, A2,B2,C2,D2, A,B,C, PX,PY,PZ

C  Direction of line is cross-product of normal vectors
      CALL CROSSP (A1,B1,C1, A2,B2,C2, A,B,C)

C  use most stable variable as basis - effectively, use x=0, y=0,
C  or z=0 as 3rd plane.
      IXYZ = ABEST3 (A,B,C)
      IF (IXYZ .EQ. 1) THEN
         PX = 0
         CALL LINTPT (B1,C1,D1, B2,C2,D2, PY,PZ)
      ELSEIF (IXYZ .EQ. 2) THEN
         PY = 0
         CALL LINTPT (A1,C1,D1, A2,C2,D2, PX,PZ)
      ELSE
         PZ = 0
         CALL LINTPT (A1,B1,D1, A2,B2,D2, PX,PY)
      ENDIF

      END
