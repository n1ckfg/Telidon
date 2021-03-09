      SUBROUTINE ABEND (SVRTY, MSG)

C Abend handles program-aborting messages.

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

      CHARACTER  MSG*(*), BUF*900, SVRTY*2

      UNERR = UNERR+1
      BUF = SVRTY // ': Program ABORT.  ' // MSG
      CALL BRDMSG (BUF)

      IF (SVRTY .NE. 'UN' .AND. SVRTY .NE. 'NC') THEN
         UNERR = UNERR+1
         CALL BRDMSG ('UN: unknown severity code passed to abend = '
     1                // SVRTY)
      ENDIF

C wrap it up - emergency close
      CALL PECLPH
C blank out tstmsg to prevent spurious informational message from windup
      TSTMSG = ' '
C kill program
      CALL WINDUP
      STOP

      END
