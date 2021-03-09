      INTEGER FUNCTION RNDINT (LO,HI)

C  RNDINT returns a random integer value between LO and HI,
C  inclusive.

      INTEGER LO,HI
      REAL    RND01

      RNDINT = INT (RND01() * (1+HI-LO) + LO)

      END
