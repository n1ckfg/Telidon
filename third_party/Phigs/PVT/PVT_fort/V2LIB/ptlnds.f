      SUBROUTINE PTLNDS (PX,PY,PZ, A,B,C,LX,LY,LZ, XN,YN,ZN, DIST)

C  Given a point and a line, find nearest point on line and
C  distance from line to point.

      REAL   PX,PY,PZ, A,B,C,LX,LY,LZ, XN,YN,ZN, DIST, VECL2, VECL
      REAL   DX,DY,DZ, D2ABC, DP, U, DOTPRD

      DX = PX-LX
      DY = PY-LY
      DZ = PZ-LZ
      D2ABC = VECL2 (A,B,C)

      DP = DOTPRD (A,B,C, DX,DY,DZ)
      U  = DP / D2ABC
      XN = LX + A*U
      YN = LY + B*U
      ZN = LZ + C*U

      DIST = VECL (PX-XN, PY-YN, PZ-ZN)

      END
