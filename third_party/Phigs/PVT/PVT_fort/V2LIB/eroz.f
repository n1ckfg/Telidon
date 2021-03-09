      SUBROUTINE EROZ (ROTANG, XFRMT)

      REAL XFRMT (4,4), SN, CS, ROTANG

      CALL IDMAT (4, XFRMT)
      SN = SIN(ROTANG)
      CS = COS(ROTANG)
      XFRMT (1,1) =  CS
      XFRMT (2,2) =  CS
      XFRMT (1,2) = -SN
      XFRMT (2,1) =  SN

      END
