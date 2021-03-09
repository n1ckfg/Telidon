      SUBROUTINE CHKINQ (ROUTNM, IERRCD)

C  Chkinq is used to check that inquire-functions have returned a value
C  of zero as the error code.  It is normally called after invoking an
C  inquire which is being used incidentally, i.e., one which is NOT the
C  object of interest of the test, but rather one whose returned values
C  are needed to test OTHER functions.  Nonetheless, the failure of such
C  an inquire is a failure of the implementation, since these inquires
C  are called only in circumstances when they should work.

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

      INTEGER    ITRIM, IERRCD

      CHARACTER  ROUTNM*(*), BUF*200, AERR*9

      IF (IERRCD .EQ. 0) RETURN
      WRITE (AERR, '(I9)' ) IERRCD

      BUF = 'Unexpected error in ' // PIDENT(1:ITRIM(PIDENT)) //
     1      ', Function = "' // ROUTNM // '", Error code = ' //
     2      AERR // '.'
      CALL NCMSG (BUF)

      END
