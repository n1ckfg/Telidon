      SUBROUTINE ESC3 (FX,FY,FZ, XFRMT)

      REAL FX,FY,FZ, XFRMT (4,4)

      CALL IDMAT (4, XFRMT)
      XFRMT (1,1) = FX
      XFRMT (2,2) = FY
      XFRMT (3,3) = FZ

      END
