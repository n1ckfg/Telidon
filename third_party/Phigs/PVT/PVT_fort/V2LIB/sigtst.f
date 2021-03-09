      SUBROUTINE SIGTST (EXPSIG, FAILED)

C  Sigtst is used to compare an signalled error code with an expected
C  value.  If not equal, failure and informative messages are generated,
C  including the error code and function name.  If equal, pass is
C  invoked.

C  Input parameter:
C    EXPSIG : expected value of error code (usually 0)
C  Output parameter
C    FAILED : true if expected not equal to actual, else false

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

      INTEGER    EXPSIG
      CHARACTER  MSG*300
      LOGICAL    FAILED

      IF (EXPSIG .EQ. ERRSIG) THEN
         FAILED = .FALSE.
         CALL PASS
      ELSE
         FAILED = .TRUE.
         CALL FAIL
         CALL SIGMSG (ERRSIG, FUNCID, MSG)
         CALL INMSG (MSG)
      ENDIF

      END
