      INTEGER FUNCTION MOD1 (X,M)

C  MOD1 returns X mod M, but coerced between 1 and M, not between
C  0 and M-1.

      INTEGER    X,M, XW

      IF (X.LT.0) THEN
         XW = X - (X/M - 2) * M
      ELSE
         XW = X
      ENDIF
      MOD1 = MOD(XW,M)
      IF (MOD1.LE.0) MOD1 = M

      END
