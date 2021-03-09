      SUBROUTINE ISSGEO (STPTH, EXIX, EXXLO,EXYLO,EXXHI,EXYHI, EXPTH)

C  This subroutine tests whether ISS successfully detects the
C  corners of a text extent rectangle.

C  Input parameters:
C    STPTH    : starting path for ISS
C    EXIX, EXXLO,EXYLO,EXXHI,EXYHI
C             : expected corner values for rectangle
C    EXPTH    : expected found path for ISS

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 30)

      INTEGER    EXLEN,  EXPATH(IPTHSZ), EXIX, IDUM(2)
      INTEGER    SPSIZ,  SPATH(2,IPTHSZ)
      INTEGER    FPTHSZ, FPATH(2,IPTHSZ), ERRIND

      REAL       EXXLO(0:10),EXYLO(0:10),EXXHI(0:10),EXYHI(0:10)
      REAL       SRATIO,SDIST, INCRVX,INCRVY, SRPX,SRPY, VECL

      LOGICAL    IAREQL

      CHARACTER  STPTH*(*), EXPTH*(*)

C  sratio = search ratio = 0.1
      SRATIO = 0.1
C  diagv = diagonal vector = vector from lower-left expected corner
C    to upper-right
C  incrv = incremental vector = sratio*diagv
      INCRVX = (EXXHI(EXIX) - EXXLO(EXIX)) * SRATIO
      INCRVY = (EXYHI(EXIX) - EXYLO(EXIX)) * SRATIO

C  sdist = search distance  = length of incrv
      SDIST = VECL (INCRVX,INCRVY,0.0)

C  srp = upper-right corner + incrv
      SRPX = EXXHI(EXIX) + INCRVX
      SRPY = EXYHI(EXIX) + INCRVY
C  starting path
      CALL SETVS (STPTH, SPATH, SPSIZ)
      SPSIZ = SPSIZ/2
C  expected path
      CALL SETVS (EXPTH, EXPATH, EXLEN)

C  ISS: with stpath, srp, try search distance first just below and
C     then just above sdist.
C  pass/fail depending on (text first not found with expected path,
C     then found with expected path)

      CALL PISS (SRPX,SRPY, 0.98*SDIST, SPSIZ,SPATH, PNCLIP, 1,
     1           0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2           IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND.
     1    (.NOT. IAREQL (2*FPTHSZ, FPATH, EXLEN, EXPATH))) THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('ISS erroneously found expected path, even ' //
     1               'though search distance was insufficient.')
         RETURN
      ENDIF

      CALL PISS (SRPX,SRPY, 1.02*SDIST, SPSIZ,SPATH, PNCLIP, 1,
     1           0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2           IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND.
     1    IAREQL (2*FPTHSZ, FPATH, EXLEN, EXPATH)) THEN
         CALL PASS
      ELSE
         CALL FAIL
         CALL INMSG ('ISS did not find expected path, even ' //
     1               'though search distance was sufficient.')
      ENDIF

      END
