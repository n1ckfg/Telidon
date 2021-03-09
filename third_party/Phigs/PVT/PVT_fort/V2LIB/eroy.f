      SUBROUTINE EROY (ROTANG, XFRMT)

      REAL XFRMT (4,4), SN, CS, ROTANG

      CALL IDMAT (4, XFRMT)
      SN = SIN(ROTANG)
      CS = COS(ROTANG)
      XFRMT (1,1) =  CS
      XFRMT (3,3) =  CS
      XFRMT (1,3) =  SN
      XFRMT (3,1) = -SN

      END
