      SUBROUTINE PF (RESULT)

C  pf handles the processing of the pass/fail condition.

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

      CHARACTER  MSGTYP*4, CONDVB*10, RESULT*1, ACOND*3, BUF*999

      IF (.NOT. (RESULT.EQ.'p' .OR. RESULT.EQ.'f'))
     1   CALL UNMSG ('Input parameter to pf neither p nor f.')

      IF (TSTMSG .EQ. ' ')
     1   CALL UNMSG ('Blank tstmsg detected by pf.  ' //
     2               'Program logic error.')

      TESTCT = TESTCT + 1
      WRITE (ACOND, '(I3)') TESTCT

      IF (RESULT .EQ. 'p') THEN
         MSGTYP = 'OK: '
         CONDVB = ' passed:  '
      ELSE
         MSGTYP = 'FA: '
         CONDVB = ' failed:  '
      ENDIF
      BUF = MSGTYP // 'Condition #' // ACOND // CONDVB // TSTMSG

C blank out tstmsg to signify use by pass/fail.
      TSTMSG = ' '

C optional suppression of pass-messages done here.
      IF (RESULT .EQ. 'f' .OR. PASSSW .EQ. 1) CALL BRDMSG (BUF)

      END
