      SUBROUTINE EROX (ROTANG, XFRMT)

      REAL XFRMT (4,4), SN, CS, ROTANG

      CALL IDMAT (4, XFRMT)
      SN = SIN(ROTANG)
      CS = COS(ROTANG)
      XFRMT (2,2) =  CS
      XFRMT (3,3) =  CS
      XFRMT (2,3) = -SN
      XFRMT (3,2) =  SN

      END
