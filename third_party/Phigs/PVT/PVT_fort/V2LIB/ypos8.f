      REAL FUNCTION YPOS8 (YTH)

C  YPOS8 returns the appropriate y-coordinate in WC for element
C  number yth.

      INTEGER    YTH
      YPOS8 =  (9 - YTH) / 9.0

      END
