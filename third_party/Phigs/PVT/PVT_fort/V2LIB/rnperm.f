      SUBROUTINE RNPERM (SIZE, PERM)

C  RNPERM returns a random permutation of integers 1-SIZE in PERM.
C  For example, if SIZE is specified as 4, PERM might = [2,3,1,4].

      INTEGER   SIZE, PERM(SIZE), IX, RANPOS, SWAP, RNDINT

      DO 100 IX = 1,SIZE
         PERM(IX) = IX
100   CONTINUE

      DO 200 IX = SIZE,2, -1
         RANPOS = RNDINT (1,IX)
         SWAP = PERM(IX)
         PERM(IX) = PERM(RANPOS)
         PERM(RANPOS) = SWAP
200   CONTINUE

      END
