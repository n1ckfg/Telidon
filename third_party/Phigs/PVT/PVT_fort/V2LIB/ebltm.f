      SUBROUTINE EBLTM (X0,Y0, DX,DY, PHI, FX,FY, XFRMT)

      REAL   X0,Y0, DX,DY, PHI, FX,FY,
     1       XFRMT (3,3), WKA(3,3), WKB(3,3), WKC(3,3)

C shift so that fixed point is at origin
      CALL ETR  (-X0,-Y0, WKA)
C scale
      CALL ESC  ( FX, FY, WKB)
      CALL ECOM (WKB, WKA, WKC)
C rotation
      CALL ERO  (PHI, WKA)
      CALL ECOM (WKA, WKC, WKB)
C do specified shift and undo fixed-point shift
      CALL ETR  (X0+DX, Y0+DY, WKA)
      CALL ECOM (WKA, WKB, XFRMT)

      END
