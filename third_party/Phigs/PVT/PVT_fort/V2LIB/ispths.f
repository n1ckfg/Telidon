      SUBROUTINE ISPTHS (SRPX,SRPY,SRPZ, SDIST, SCEIL, MCLIPI,
     1                   STPTH, EXPTHS)

C  This subroutine repeatedly invokes spatial search, using the
C  found path of one search as the starting path for the next, and
C  issues pass or fail, depending on whether the actual paths match
C  those expected.

C  Input parameters:
C    SRPX,Y,Z : search reference point to be used in ISS's
C    SDIST    : search distance to be used in ISS's
C    SCEIL    : search ceiling to be used in ISS's
C    MCLIPI   : modelling clipping indicator
C    STPTH    : starting path for first ISS
C    EXPTHS   : sequence of expected found paths for ISS's

      INTEGER    EXDIM,IPTHSZ
      PARAMETER (EXDIM = 30, IPTHSZ = 30)

      INTEGER    EXNUM, EXLEN(EXDIM), EXPATH(EXDIM, EXDIM)
      INTEGER    SPSIZ,  SPATH(2,IPTHSZ), SCEIL, IDUM(2), IPATH, IX
      INTEGER    FPTHSZ, FPATH(2,IPTHSZ), ERRIND, MCLIPI

      REAL       SRPX,SRPY,SRPZ, SDIST

      LOGICAL    IAREQL

      CHARACTER  EXPTHS*(*), STPTH*(*)

      CALL SETVS (STPTH, SPATH, SPSIZ)
      SPSIZ = SPSIZ/2
      CALL SET2D (EXPTHS, EXDIM, EXNUM,EXLEN,EXPATH)

      DO 100 IPATH = 1,EXNUM
         CALL PISS3 (SRPX,SRPY,SRPZ, SDIST, SPSIZ, SPATH, MCLIPI, SCEIL,
     1               0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2               IPTHSZ, ERRIND, FPTHSZ, FPATH)
         IF (ERRIND .EQ. 0 .AND.
     1       IAREQL (FPTHSZ*2,FPATH, EXLEN(IPATH),EXPATH(1,IPATH))) THEN
C OK so far - copy found path to next starting path
            SPSIZ = FPTHSZ
            DO 110 IX = 1,SPSIZ
               SPATH(1,IX) = FPATH(1,IX)
               SPATH(2,IX) = FPATH(2,IX)
110         CONTINUE
         ELSE
            CALL FAIL
            RETURN
         ENDIF
100   CONTINUE
      CALL PASS

      END
