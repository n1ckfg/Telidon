      SUBROUTINE ETR (DX,DY, XFRMT)

      REAL DX,DY, XFRMT (3,3)

      CALL IDMAT (3, XFRMT)
      XFRMT (1,3) = DX
      XFRMT (2,3) = DY

      END
