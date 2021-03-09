C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE ER/perhnd                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PERHND (ERRNR, FUNCCD, ERFLID)

C  Perhnd is the standard routine name for error handling in
C  PHIGS/Fortran.  Generally, no errors should be signalled during
C  execution of the tests.  Perhnd does one of two things:
C
C  1. Expected errors: If a test program specifies that a signalled error
C  is possibly expected, and wants to test the error code explicitly, it
C  does so by using errctl to set the value of ctlhnd (a COMMON variable)
C  to 1.  Perhnd will then simply set errsig to the error code signalled,
C  funcid to the name of the signalling function and return.  No message
C  is written by perhnd; the test program assumes all responsibility for
C  handling the error.  Normally the test program should use errctl to
C  re-set ctlhnd to 0 immediately after calling the potentially
C  error-signalling function.
C
C  2. Unexpected errors: By default, errors are unexpected, and their
C  occurrence causes perhnd to write a message and abort the program,
C  using NCMSG.  This happens if ctlhnd has a value of 0, as initialized.
C
C  Note that inquires never signal an error, but merely return a non-zero
C  error indicator, normally checked by CHKINQ.

C  PERHND is stored in a separate library (ERRLIB) to allow the
C  system linker more easily to insert it into the executable, or to
C  exclude it so as to allow the default error handler of the same
C  name to take effect.  The subroutine INITGL in the global
C  subroutine library contains dummy calls to PERHND and to all
C  subroutines immediately invoked by PERHND so as to allow optional
C  linking of ERRLIB following SUBLIB.

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

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR, 
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)

      SAVE ERRCT

      INTEGER    ERRNR, FUNCCD, ERFLID, ERRCT 
      CHARACTER  MSG*300, ERRCH*6, ERRFUN*45

      DATA ERRCT /0/

C put name of function into errfun
      IF (FUNCCD .GE. 0 .AND. FUNCCD .LE. 182) THEN
         CALL ERFUNM (FUNCCD, ERRFUN)
      ELSE
         WRITE (ERRCH, '(I6)') FUNCCD
         ERRFUN = '<Function of unknown code: ' // ERRCH // '>'
      ENDIF

      IF (CTLHND .EQ. 1) THEN
C let test program handle error
         ERRSIG = ERRNR
         FUNCID = ERRFUN
         ERRCOM = ERRNR
         FUNCOM = FUNCCD
         FILCOM = ERFLID
         IF (USRERR.EQ.1 .OR. USRERR.EQ.3) THEN
            ERRCT = ERRCT + 1
            IF (ERRCT.GT.200) THEN
               CALL UNMSG ('PERHND tried to write past last entry ' //
     1                     'in internal table of generated errors.')
            ENDIF
            ERRSAV(ERRCT) = ERRCOM
            FUNSAV(ERRCT) = FUNCOM
            FILSAV(ERRCT) = FILCOM
         ELSEIF (USRERR .EQ. 0) THEN
C           normal - not testing error handling - do nothing
         ELSE
            CALL UNMSG ('User-defined PERHND called with invalid ' //
     1                  'value for USRERR.')
         ENDIF

         RETURN
      ENDIF

      CALL SIGMSG (ERRNR, ERRFUN, MSG)

      IF (ERRNR .GE. 0) THEN
         CALL NCMSG (MSG)
      ELSE
C implementation-dependent errors - could be warning - at any rate
C not necessarily non-conforming.
         CALL UNMSG (MSG)
      ENDIF

      END
