      SUBROUTINE ETP3 (XI,YI,ZI, XFRMT, XO,YO,ZO)

      REAL XFRMT (4,4), PTI(4,1), PTO(4,1)
      REAL XI,YI,ZI, XO,YO,ZO, W

      PTI(1,1) = XI
      PTI(2,1) = YI
      PTI(3,1) = ZI
      PTI(4,1) = 1.0

      CALL MATMUL (4,4,1, XFRMT, PTI, PTO)
      W  = PTO(4,1)
      XO = PTO(1,1) / W
      YO = PTO(2,1) / W
      ZO = PTO(3,1) / W

      END
