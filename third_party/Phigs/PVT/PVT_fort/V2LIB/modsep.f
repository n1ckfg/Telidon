      REAL FUNCTION MODSEP (PERIOD, A, B)

C  Given a period and two values, a and b, modsep calculates the
C  absolute value of the smallest "distance" between the values,
C  treating them as points on a circle with circumference of size =
C  period.  For example, if period=360, as for degree-measure,
C  modsep of 5 and 15 would of course be 10, but so would modsep of
C  5 and 355, or 0 and 710, or 0 and 730.

      REAL PERIOD, A, B, AM,BM, ABDIF

      IF (PERIOD .EQ. 0.0) THEN
         MODSEP = 0.0
         RETURN
      ENDIF

C get normalized mod-values - correct for loopy way Fortran
C mods negative numbers.
      AM = MOD (A,PERIOD)
      IF (A.LT.0) AM = AM+PERIOD
      BM = MOD (B,PERIOD)
      IF (B.LT.0) BM = BM+PERIOD
C now:   0 .le. am,bm  .lt. period

      ABDIF = ABS(AM-BM)
      MODSEP = MIN (ABDIF, PERIOD-ABDIF)

      END
