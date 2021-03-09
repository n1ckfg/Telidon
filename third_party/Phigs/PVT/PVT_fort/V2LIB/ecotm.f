      SUBROUTINE ECOTM (XFRMTI, X0,Y0, DX,DY, PHI,
     1                  FX,FY, XFRMTO)

      REAL   X0,Y0, DX,DY, PHI, FX,FY,
     1       XFRMTI (3,3), XFRMTO (3,3), WKA(3,3)

      CALL EBLTM (X0,Y0, DX,DY, PHI, FX,FY, WKA)
      CALL ECOM  (XFRMTI, WKA, XFRMTO)

      END
