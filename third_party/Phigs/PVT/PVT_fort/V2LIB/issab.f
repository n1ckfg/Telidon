      SUBROUTINE ISSAB (SRPX,SRPY,SRPZ, SDIST, STPATH, MCLIPI, SCEIL,
     1                  EXPATH)

C  This subroutine invokes the 3D spatial search routine with the
C  search distance set just below and above the theoretically
C  correct distance.  Thus, the search should first be unsuccessful,
C  and then successful.  ISSAB issues pass or fail as a result
C  of these two searches.

C  Input parameters:
C    SRPX,Y,Z   : search reference point
C    SDIST      : correct search distance
C    STPATH     : starting path
C    MCLIPI     : modelling clipping indicator
C    SCEIL      : search ceiling
C    EXPATH     : expected found path

      REAL       SRPX,SRPY,SRPZ, SDIST

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 100)

      INTEGER    ISTPTH(2,IPTHSZ),ISTLEN, IDUM(2),ERRIND, MCLIPI, SCEIL
      INTEGER    IEXPTH(2,IPTHSZ), IEXLEN, FPATH(2,IPTHSZ), FPTHSZ

      LOGICAL    IAREQL

      CHARACTER  MSG*200, EXPATH*(*), STPATH*(*)

      CALL SETVS (STPATH, ISTPTH, ISTLEN)
      CALL SETVS (EXPATH, IEXPTH, IEXLEN)

      CALL PISS3 (SRPX,SRPY,SRPZ, 0.98*SDIST, ISTLEN/2, ISTPTH, MCLIPI,
     1            SCEIL, 0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND. FPTHSZ .EQ. 0) THEN
C OK so far
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'ISS did not return null ' //
     1      'path as expected; error indicator = ', ERRIND, '.'
         CALL INMSG (MSG)
         RETURN
      ENDIF

      CALL PISS3 (SRPX,SRPY,SRPZ, 1.02*SDIST, ISTLEN/2, ISTPTH, MCLIPI,
     1            SCEIL, 0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND.
     1    IAREQL (2*FPTHSZ, FPATH, IEXLEN, IEXPTH)) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'ISS did not return correct ' //
     1      'found path; error indicator = ', ERRIND, '.'
         CALL INMSG (MSG)
      ENDIF

      END
