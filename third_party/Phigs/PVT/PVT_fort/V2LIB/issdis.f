      SUBROUTINE ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, XFRMT,
     1                   MCLIPI, EXPATH)

C  This subroutine invokes the 3D spatial search routine with the
C  search distance set just below and above the theoretically
C  correct distance.  The search always begins at the start of
C  structure #101.  Thus, the search should first be unsuccessful,
C  and then successful.  ISSDIS issues pass or fail as a result
C  of these two searches.

C  Input parameters:
C    SISRPX,Y,Z : untransformed search reference point
C    SDIST      : correct search distance
C    XFRMT      : matrix used to transform search reference point
C    MCLIPI     : clipping indicator to be used
C    EXPATH     : expected found path

      INTEGER    MCLIPI

      REAL       SISRPX,SISRPY,SISRPZ, COSRPX,COSRPY,COSRPZ, SDIST
      REAL       XFRMT(4,4)

      CHARACTER  EXPATH*(*)

C  transform search reference point
      CALL ETP3 (SISRPX,SISRPY,SISRPZ, XFRMT, COSRPX,COSRPY,COSRPZ)

      CALL ISSAB (COSRPX,COSRPY,COSRPZ, SDIST, '101,0', MCLIPI, 1,
     1            EXPATH)

      END
