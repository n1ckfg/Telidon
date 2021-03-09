      SUBROUTINE ERRCTL (LOCCTL)

C  Errctl is called by test programs to control whether or not perhnd
C  should handle signalled errors and abort (locctl = .false.) or rather
C  should simply return error information (locctl = .true.) in the
C  COMMON variables errsig and funcid.

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

C Should there be local control over signalled errors?
      LOGICAL LOCCTL

      IF (LOCCTL) THEN
         CTLHND = 1
         ERRSIG = 0
         FUNCID = ' '
      ELSE
         CTLHND = 0
      ENDIF

      END
