      SUBROUTINE ISSPF (DIMENS, SRPX,SRPY,SRPZ, SDIST, EXPATH)

C  This subroutine invokes the specified spatial search routine and
C  issues pass or fail, depending on its agreement with the expected
C  result.  Always: structure #101 is searched, search ceiling is 1,
C  modelling clip off, filter lists empty.

C  Input parameters:
C    DIMENS         : dimension of search: 2 or 3
C    SRPX,SRPY,SRPZ : search reference point (SRPZ ignored if DIMENS=2)
C    SDIST          : search distance
C    EXPATH         : expected found path

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      REAL       SRPX,SRPY,SRPZ, SDIST

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 100)

      INTEGER    DIMENS, IDUM(2), FPATH(2,IPTHSZ), ERRIND, FPTHSZ
      INTEGER    SPATH(2,1), IEXPTH(2,IPTHSZ), IEXLEN

      LOGICAL    IAREQL

      CHARACTER  EXPATH*(*)

      DATA SPATH / 101,0 /

      IF (DIMENS .EQ. 2) THEN
         CALL PISS  (SRPX,SRPY,      SDIST, 1, SPATH, PNCLIP, 1,
     1               0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2               IPTHSZ, ERRIND, FPTHSZ, FPATH)
      ELSEIF (DIMENS .EQ. 3) THEN
         CALL PISS3 (SRPX,SRPY,SRPZ, SDIST, 1, SPATH, PNCLIP, 1,
     1               0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2               IPTHSZ, ERRIND, FPTHSZ, FPATH)
      ELSE
         CALL UNMSG ('Illegal dimension passed to ISSPF.')
      ENDIF

      CALL SETVS (EXPATH, IEXPTH, IEXLEN)

      CALL IFPF (ERRIND .EQ. 0 .AND.
     1           IAREQL (2*FPTHSZ, FPATH, IEXLEN, IEXPTH))

      END
