      SUBROUTINE ETP (XI,YI, XFRMT, XO,YO)

      REAL XFRMT (3,3), PTI(3,1), PTO(3,1)
      REAL XI,YI, XO,YO, W

      PTI(1,1) = XI
      PTI(2,1) = YI
      PTI(3,1) = 1.0

      CALL MATMUL (3,3,1, XFRMT, PTI, PTO)
      W  = PTO(3,1)
      XO = PTO(1,1) / W
      YO = PTO(2,1) / W

      END
