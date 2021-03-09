      SUBROUTINE ESC (FX,FY, XFRMT)

      REAL FX,FY, XFRMT (3,3)

      CALL IDMAT (3, XFRMT)
      XFRMT (1,1) = FX
      XFRMT (2,2) = FY

      END
