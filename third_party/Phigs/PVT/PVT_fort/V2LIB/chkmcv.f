      SUBROUTINE CHKMCV (STPATH, EXPTHS)

C  CHKMCV checks that the correct sequence of found paths is returned
C  by ISS as a result of the starting path.  It issues pass or fail
C  depending on whether the actual found paths match those expected.
C  It always uses a search reference point of 0,0,0 and distance of 2.

C  Input parameters:
C    STPATH : starting path for ISS
C    EXPTHS : expected found paths

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      CHARACTER  STPATH*(*), EXPTHS*(*)

      CALL ISPTHS (0.,0.,0., 2., 1, PCLIP, STPATH, EXPTHS)

      END
