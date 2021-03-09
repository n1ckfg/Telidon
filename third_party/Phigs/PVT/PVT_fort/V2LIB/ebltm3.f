      SUBROUTINE EBLTM3 (X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ,
     1                   XFRMT)

      REAL   X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ,
     1       XFRMT (4,4), WKA(4,4), WKB(4,4), WKC(4,4)

C shift so that fixed point is at origin
      CALL ETR3  (-X0,-Y0,-Z0, WKA)
C scale
      CALL ESC3  ( FX, FY, FZ, WKB)
      CALL ECOM3 (WKB, WKA, WKC)
C rotations
      CALL EROX  (PHIX, WKA)
      CALL ECOM3 (WKA, WKC, WKB)
      CALL EROY  (PHIY, WKA)
      CALL ECOM3 (WKA, WKB, WKC)
      CALL EROZ  (PHIZ, WKA)
      CALL ECOM3 (WKA, WKC, WKB)
C do specified shift and undo fixed-point shift
      CALL ETR3  (X0+DX, Y0+DY, Z0+DZ, WKA)
      CALL ECOM3 (WKA, WKB, XFRMT)

      END
