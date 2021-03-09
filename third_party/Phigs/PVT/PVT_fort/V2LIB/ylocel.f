      REAL FUNCTION YLOCEL (YTH)

C  YLOCEL returns the appropriate y-coordinate in WC for element
C  number YTH, when comparing pairs of elements for traversal
C  saving and restoring.

      INTEGER    YTH

      YLOCEL = (15 - YTH) / 15.0

      END
