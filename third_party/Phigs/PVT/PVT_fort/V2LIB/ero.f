      SUBROUTINE ERO (ROTANG, XFRMT)

      REAL XFRMT (3,3), SN, CS, ROTANG

      CALL IDMAT (3, XFRMT)
      SN = SIN(ROTANG)
      CS = COS(ROTANG)
      XFRMT (1,1) =  CS
      XFRMT (2,2) =  CS
      XFRMT (1,2) = -SN
      XFRMT (2,1) =  SN

      END
