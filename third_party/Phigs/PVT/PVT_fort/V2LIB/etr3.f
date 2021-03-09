      SUBROUTINE ETR3 (DX,DY,DZ, XFRMT)

      REAL DX,DY,DZ, XFRMT (4,4)

      CALL IDMAT (4, XFRMT)
      XFRMT (1,4) = DX
      XFRMT (2,4) = DY
      XFRMT (3,4) = DZ

      END
