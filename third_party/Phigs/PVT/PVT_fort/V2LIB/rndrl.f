      REAL FUNCTION RNDRL (LO, HI)

C  RNDRL returns a random real number, X, uniformly distributed,
C  such that LO .LE. X .LT. HI.

      REAL       RND01, LO, HI

      RNDRL = RND01()*(HI-LO) + LO

      END
