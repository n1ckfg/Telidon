      SUBROUTINE EEVMM (VWWNLM, PJVPLM, VWMPMT)

C note: no 3D version (eevmm3) because standard does not specify
C a unique transformation.

      REAL   VWMPMT(3,3), VWWNLM(4), PJVPLM(4)

      CALL EBLTM (VWWNLM(1),VWWNLM(3),
     1             PJVPLM(1)-VWWNLM(1), PJVPLM(3)-VWWNLM(3), 0.0,
     2            (PJVPLM(2)-PJVPLM(1))/(VWWNLM(2)-VWWNLM(1)),
     3            (PJVPLM(4)-PJVPLM(3))/(VWWNLM(4)-VWWNLM(3)),  VWMPMT)

      END
