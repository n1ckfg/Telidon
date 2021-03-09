      SUBROUTINE PTPLDS (PX,PY,PZ, A,B,C,D, XN,YN,ZN, DIST)

C Given a point and plane-coefficients, find nearest
C point on plane and distance from plane to point.

      REAL   PX,PY,PZ, A,B,C,D, XN,YN,ZN, DIST, SQ,SOL,U, VECL2

      SQ   = VECL2 (A,B,C)
      SOL  = A*PX + B*PY + C*PZ + D
      DIST = ABS(SOL) / SQRT(SQ)
      U    = - SOL / SQ
      XN = PX + A*U
      YN = PY + B*U
      ZN = PZ + C*U

      END
