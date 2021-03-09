C  The routines in 09.01/sublib are used to support the checking of
C  error signalling for the various error codes.  The calling
C  structure looks like this:
C
C
C                    Pxx.FOR
C                     |
C                     |
C              ----------------
C              Emmeee or Cmmeee   =   E/C <module#> <error#>
C              ----------------
C                     |                
C      --------------------------------------
C      |         |        |        |        |
C    esetup    enderr   tstign   streq    rfuncs
C                |                          |
C                |                          |
C                |                          |
C                |----------              echkz
C                |         |
C              tsterr      | 
C                |         |
C                |-------gterrm
C                |         |
C              scherr    ermsgh
C
C
C  These routines communicate largely through the common areas
C  ERRINF and ERRCHR.  Here is the meaning of their variables:
C
C     /ERRINF/
C  ERRCOM : error code returned by system to user-defined PERHND
C  FUNCOM : function code returned by system to user-defined PERHND
C  FILCOM : error file returned by system to user-defined PERHND
C  ERNMSW : switch set by INITPH:
C             1-program can explicitly open and name error file,
C             2-program cannot set name of error file
C  EXPSIZ : Number of correct values for error code
C  EXPERR : List of expected/correct value(s) for error code
C  USRERR : switch indicating type of error checking:
C             0 - normal mode (non-09 tests); not testing error handling
C             1 - user-defined error handling
C             2 - system-defined error handling
C             3 - user-defined error handling, when PHIGS is closed at
C                 the time the error is generated.  This is a special
C                 case because the value of the error file parameter
C                 should not be checked.
C             4 - system-defined error handling, when PHIGS is closed at
C                 the time the error is generated.  This is a special
C                 case because the error file, to which messages are
C                 normally written, is closed and therefore inaccessible.
C             5 - system-defined error handling, but use CURCON as total
C                 test message, rather than constructing additional
C                 parts of message automatically.
C  ERRSAV : Array of error codes returned by system to user-defined PERHND
C  FUNSAV : Array of function codes actually returned by system
C           to user-defined PERHND
C  FILSAV : Array of error file identifiers returned by system to
C           user-defined PERHND
C  EFCNT  : Number of error-signalling function invocations (each of
C           which may generate several errors)
C  EFID   : Table of expected identifiers of error-signalling functions,
C           indexed by EFCNT
C
C     /ERRCHR/
C  CURCON : description of the current condition expected to cause an error
C  ERRSRS : string containing the SRs which support the current test case
C  ERRMRK : string set by INITPH to identify distinct system-generated
C           error messages in error file
C  ERFLNM : character string for name of error file
C  CONTAB : table of current condition descriptions at the time error-
C           generating function was invoked


C  Data flow within 09/01/sublib
C 
C  Producers:
C  initph  perhnd  pvt-code  esetup  echkz   tsterr
C                                                     Consumers:
C  - - - - - - - - - - - - - - - - - - - - - - - - -
C  ERNMSW          USRERR                             esetup
C  - - - - - - - - - - - - - - - - - - - - - - - - -
C  ERNMSW          USRERR    ERFLNM  EFCNT
C                                    EFID             enderr
C                                    CONTAB
C  - - - - - - - - - - - - - - - - - - - - - - - - -
C                  CURCON                             tstign
C                  ERRSRS
C  - - - - - - - - - - - - - - - - - - - - - - - - -
C                  USRERR    EFCNT                    rfuncs/echkz
C                  CURCON
C  - - - - - - - - - - - - - - - - - - - - - - - - -
C          ERRSAV  EXPSIZ                    ERRCOM
C          FUNSAV  EXPERR                    FUNCOM   tsterr 
C          FILSAV  USRERR                    FILCOM
C                  ERRSRS
C  - - - - - - - - - - - - - - - - - - - - - - - - -
C  ERRMRK                                             gterrm


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/esetup                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ESETUP (USEPRM)

C  ESETUP initializes USRERR from its parameter USEPRM.  It also
C  initializes ERFLNM and opens PHIGS.  ESETUP is always called by
C  the Emmeee routines before they start generating errors.
C
C  Input parameter:
C    USEPRM : switch indicating type of error checking:
C             1 - user-defined error handling
C             2 - system-defined error handling
C             3 - user-defined error handling, when PHIGS is closed.
C             4 - system-defined error handling, when PHIGS is closed.

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
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80, 
     1                CONTAB(40)*150

      INTEGER    ITRIM, USEPRM, IX, IOERR

      CHARACTER  MSG*300

      IF (USEPRM.GE.1 .AND. USEPRM.LE.5) THEN
         USRERR = USEPRM
      ELSE
         CALL UNMSG ('ESETUP called with invalid USEPRM.')
      ENDIF

      ERFLNM = ' '
      IF (USRERR.EQ.2 .OR. USRERR.EQ.5) THEN
         IF (ERNMSW .EQ. 1) THEN
C  set up error file
            IX = ITRIM(PIDENT)
            ERFLNM = 'p' // PIDENT(IX-1:IX) // '.erf'
            OPEN (UNIT=ERRFIL, FILE=ERFLNM, STATUS='UNKNOWN',
     1            IOSTAT=IOERR)
            IF (IOERR.NE.0) THEN
               WRITE (MSG, '(A,I7,A)') 'ESETUP failed to open '      //
     1               'error file.  OPEN returned Fortran IO status ' //
     2               '= ', IOERR, '.'
               CALL UNMSG (MSG)
            ENDIF
C  rewind error file, so that its contents can be written
            REWIND (UNIT=ERRFIL, IOSTAT=IOERR)
            IF (IOERR.NE.0) THEN
               WRITE (MSG, '(A,I7,A)') 'ESETUP failed to rewind '   //
     1               'the error file.  REWIND returned Fortran IO ' //
     2               'status = ', IOERR, '.'
               CALL UNMSG (MSG)
            ENDIF
         ENDIF
      ELSEIF (USRERR.EQ.1 .OR. USRERR.EQ.3) THEN
         CALL ERRCTL (.TRUE.)
      ENDIF

      EFCNT = 0
      CALL XPOPPH (ERRFIL, MEMUN)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/enderr                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ENDERR

C  ENDERR closes PHIGS.  Also, when system error handling is being
C  tested, it determines the file name of the system error file so
C  that it can re-open and rewind the file for inspection.  ENDERR
C  is normally called by the Emmeee routines after generating errors,
C  but before testing them.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW,  MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE,GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW,  MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE,GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL   DUMRL(20)

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR, 
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80, 
     1                CONTAB(40)*150

C  special strings to control processing of error file
      CHARACTER  BOFMRK*10
      PARAMETER (BOFMRK = 'first call')

      INTEGER  IOERR, FUNCIX, SEPLUN

      LOGICAL OPSTAT

      CHARACTER MSG*200, ERLOGT*800, ERSNAM*80

      DATA ERLOGT / ' ' /

      IF ((USRERR.EQ.2 .OR. USRERR.EQ.5) .AND. ERNMSW.EQ.2) THEN
C  try to find out system-name for error file
         INQUIRE (UNIT=ERRFIL, NAME=ERFLNM, IOSTAT=IOERR)
         IF (IOERR.NE.0 .OR. ERFLNM.EQ.' ') THEN
            WRITE (MSG, '(A,I7,A)') 'ENDERR failed to determine ' //
     1            'name of system error file.  Inquire returned ' //
     2            'Fortran IO status = ', IOERR, '.'
            CALL UNMSG (MSG)
         ENDIF
      ENDIF

      IF (USRERR.EQ.1 .OR. USRERR.EQ.2 .OR. USRERR.EQ.5) CALL PCLPH

      IF (USRERR.EQ.2 .OR. USRERR.EQ.5) THEN
         INQUIRE (UNIT=ERRFIL, OPENED=OPSTAT)
C  re-open error file if necessary (closing PHIGS should have closed 
C  error file).
         IF (.NOT. OPSTAT) THEN
            OPEN (UNIT=ERRFIL, FILE=ERFLNM, STATUS='OLD', IOSTAT=IOERR)
            IF (IOERR.NE.0) THEN
               WRITE (MSG, '(A,I7,A)') 'ENDERR failed to re-open ' //
     1               'error file after closing PHIGS.  OPEN '      //
     2               'returned Fortran IO status = ', IOERR, '.'
               CALL UNMSG (MSG)
            ENDIF
         ENDIF
C  rewind error file, so that its contents can be read and examined
         REWIND (UNIT=ERRFIL, IOSTAT=IOERR)
         IF (IOERR.NE.0) THEN
            WRITE (MSG, '(A,I7,A)') 'ENDERR failed to rewind '   //
     1            'the error file.  REWIND returned Fortran IO ' //
     2            'status = ', IOERR, '.'
            CALL UNMSG (MSG)
         ENDIF

CUSERMOD  Insert here filename for error separator file, usually in
CUSERMOD  PVT root directory
         ERSNAM = '/home/cugini/pvt/work/v2.1/errsep.erf'

C  get error separator message
         SEPLUN = MAX(GLBLUN,INDLUN,ERRFIL) + 1
         OPEN (UNIT=SEPLUN, FILE=ERSNAM, STATUS='OLD', IOSTAT=IOERR)
         IF (IOERR.NE.0) THEN
            WRITE (MSG, '(A,I7,A)') 'ENDERR failed to open errsep ' //
     1            'file.  OPEN returned Fortran IO status = ',IOERR, '.'
            CALL UNMSG (MSG)
         ENDIF
         REWIND (UNIT=SEPLUN, IOSTAT=IOERR)
         IF (IOERR.NE.0) THEN
            WRITE (MSG, '(A,I7,A)') 'ENDERR failed to rewind errsep ' //
     1            'file.  REWIND returned Fortran IO status = ',
     2            IOERR, '.'
            CALL UNMSG (MSG)
         ENDIF

C  get the first (and presumably only) message from the errsep file,
C  to be used as pattern to recognize terminator message
         ERLOGT = BOFMRK
         CALL GTERRM (SEPLUN, ERLOGT)
         CLOSE (UNIT=SEPLUN)
      ELSE
C  user-defined error handling
         CALL ERRCTL (.FALSE.)
      ENDIF

C  loop thru expected functions and see whether they match actual results
      DO 100 FUNCIX = 1,EFCNT
         CALL TSTERR (EFID(FUNCIX), CONTAB(FUNCIX), ERLOGT)
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/tsterr                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTERR (EXPFUN, CONDES, ERLOGT)

C  TSTERR sets up one test case for error handling and then issues
C  pass or fail for it.  It sets up the test case based on the SRs
C  to be tested (ERRSRS), the list of expected errors (EXPERR) and
C  the expected error-generating function (EXPFUN).  The test
C  procedure adopted depends on whether TSTERR is invoked for
C  user-defined error handling, or system-defined, as indicated by
C  USRERR.
C
C  Input parameters:
C    EXPFUN : code for the expected generating function.
C    CONDES : description of condition that should have caused error
C    ERLOGT : content of error message serving as terminator

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW,  MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE,GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW,  MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE,GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL   DUMRL(20)

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
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80, 
     1                CONTAB(40)*150

C  special strings to control processing of error file
      CHARACTER  EOFMRK*17,                    BOFMRK*10
      PARAMETER (EOFMRK = 'end of error file', BOFMRK = 'first call')

C  for user error handling, ERRCT is used to scan through array
C  of actual results generated by error-signalling functions
      SAVE ERRCT

      INTEGER    EESC,       EPREC,      EUREC
      PARAMETER (EESC  =180, EPREC =181, EUREC =182 )

      INTEGER    EXPFUN, GENERR, GENFUN, IERR, ERRCT, TSTAT
      INTEGER    IX, LST, LNB, ITRIM, LEADNB, IARFND

      LOGICAL    ERROK, FUNOK, FILOK

      CHARACTER  ACODE*4, TMSG*500, ANS*1, MSG*160, ERLOGT*(*)
      CHARACTER  FUNNAM*80, ERRMSG*180, FUNMSG*80, EMSG*1000
      CHARACTER  CONDES*(*)

      DATA ERRCT  / 0 /
      DATA EMSG   / BOFMRK /

C  set up test message
      CALL ERFUNM (EXPFUN, FUNNAM)
      TMSG = 'If ' // FUNNAM
      TMSG(ITRIM(TMSG)+2:) = 'is called and ' // CONDES
      TMSG(ITRIM(TMSG)+1:) = ', it should'

      IF (USRERR.EQ.1 .OR. USRERR.EQ.3) THEN
         IF (EXPSIZ.LT.1) THEN
            CALL UNMSG ('TSTERR called with invalid EXPSIZ.')
         ENDIF
         TMSG(ITRIM(TMSG)+2:) = 'return error code'
C  may be several valid error code possibilities
         DO 20 IX = 1, EXPSIZ-1
            WRITE (ACODE, '(I4.3)') EXPERR(IX)
            TMSG(ITRIM(TMSG)+2:) = ACODE // ','
20       CONTINUE
         IF (EXPSIZ.GE.2) TMSG(ITRIM(TMSG):) = ' and/or'
         WRITE (ACODE, '(I4.3)') EXPERR(EXPSIZ)
         TMSG(ITRIM(TMSG)+2:) = ACODE
         WRITE (ACODE, '(I4.3)') EXPFUN

         IF (USRERR.EQ.1) THEN
            TMSG(ITRIM(TMSG)+1:) = ', function identifier ' // ACODE //
     1           ', and the current error file identifier'
         ELSE
            TMSG(ITRIM(TMSG)+2:) = 'and function identifier ' // ACODE
         ENDIF

         TMSG(ITRIM(TMSG)+2:) = 'to the user defined error handler.'
      ELSEIF (USRERR.EQ.2) THEN
         TMSG(ITRIM(TMSG)+2:) = 'write an accurate, ' //
     1       'self-identifying error message on the error file.'
      ELSEIF (USRERR.EQ.4) THEN
         CALL UNMSG ('TSTERR called with USRERR=4.')
         TMSG(ITRIM(TMSG)+2:) = 'write an accurate, ' //
     1       'self-identifying error message to the operator.'
      ELSEIF (USRERR.EQ.5) THEN
         TMSG = CONDES
      ELSE
         CALL UNMSG ('TSTERR detected an invalid value for USRERR.')
      ENDIF

      CALL SETMSG (ERRSRS, TMSG)

C  use this to make sure that error handler was called at least once:
C  for TSTAT, -1:fail, 0:pass, 1:no test yet
      TSTAT = 1

      IF (USRERR.EQ.1 .OR. USRERR.EQ.3) THEN
         GOTO 100
      ELSE
         GOTO 150
      ENDIF

C  *** *** *** ***   user-defined error handling   *** *** *** ***
100   CONTINUE
C  loop thru and make sure all entries are valid

C  get next actual error result
      ERRCT = ERRCT + 1
      IF (ERRCT.GT.200) THEN
         CALL UNMSG ('TSTERR tried to read past last entry in ' //
     1               'internal table of generated errors.')
      ENDIF
      ERRCOM = ERRSAV(ERRCT)
      FUNCOM = FUNSAV(ERRCT)
      FILCOM = FILSAV(ERRCT)

C  check if no more entries in this group
      IF (ERRCOM.EQ.2 .AND. FUNCOM.EQ.EESC .AND. FILCOM.EQ.-666) THEN
         IF (TSTAT.EQ.0) THEN
            CALL PASS
         ELSEIF (TSTAT.EQ.1) THEN
            CALL FAIL
            CALL INMSG ('Tested function apparently did not call ' //
     1                  'user defined error handling subroutine.')
         ENDIF
         GOTO 999
      ENDIF

C  determine validity of actual error report
      ERROK = IARFND(ERRCOM, EXPSIZ, EXPERR) .GT. 0
      FUNOK = FUNCOM.EQ.EXPFUN
C  no checking of error file when PHIGS is closed at time of error generation
      FILOK = FILCOM.EQ.ERRFIL .OR. USRERR.EQ.3

C  OK so far?
      IF (ERROK .AND. FUNOK .AND. FILOK) THEN
         TSTAT = MIN(TSTAT, 0)
         GOTO 100
      ENDIF

      IF (TSTAT .GE. 0) THEN
C  first detected failure condition
         CALL FAIL
         TSTAT = -1
      ENDIF

      IF (.NOT. ERROK) THEN
         WRITE (MSG, '(A,I6.3,A)') 'Reported error number ', ERRCOM, 
     1               ' is not one of the expected values.'
         CALL INMSG (MSG)
      ENDIF

      IF (.NOT. FUNOK) THEN
         WRITE (MSG, '(A,I4.3,A,I4.3,A)') 'Reported function ' //
     1          'identifier ', FUNCOM, ' does not match '      //
     2          'expected function identifier ', EXPFUN, '.'
         CALL INMSG (MSG)
      ENDIF

      IF (.NOT. FILOK) THEN
         WRITE (MSG, '(A,I4.3,A,I4.3,A)') 'Reported error file ' //
     1          'identifier ', FILCOM, ' does not match '        //
     2          'expected error file identifier ', ERRFIL, '.'
         CALL INMSG (MSG)
      ENDIF

      GOTO 100

C  *** *** *** ***   system-defined error handling   *** *** *** *** 
150   CONTINUE
C  loop thru and make sure all error file messages are valid

      CALL GTERRM (ERRFIL, EMSG)
C  check if no more entries
      IF (EMSG.EQ.EOFMRK .OR. 
     1    EMSG(LEADNB(EMSG):ITRIM(EMSG)).EQ.ERLOGT) THEN
         IF (TSTAT.EQ.0) THEN
            CALL PASS
         ELSEIF (TSTAT.EQ.1) THEN
            CALL FAIL
            CALL INMSG ('Tested function apparently did not call ' //
     1                  'system defined error handling subroutine.')
         ENDIF
         GOTO 999
      ENDIF

      CALL OPMSG (' ')
      CALL OPMSG ('------- Begin error message -------')
      CALL OPMSG (EMSG)
      CALL OPMSG ('------- End error message -------')
      CALL OPMSG (' ')

C  determine validity of actual error report
      CALL OPMSG ('Based on the error message, which function '   //
     1            'caused the error?  Enter either generic name ' //
     1            'in lower case, or numeric function code from ' //
     1            'Fortran binding.  Enter a negative number if ' //
     1            'function cannot be determined from the message.')
         
550   CONTINUE
      CALL OPLIN (FUNMSG)
      LNB = LEADNB (FUNMSG)
      LST = ITRIM  (FUNMSG)
      CALL PRSINT (FUNMSG(LNB:LST), GENFUN, IERR)
      IF (IERR.EQ.0) THEN
C        integer response from operator - GENFUN set
      ELSE
C  string response from operator
         CALL ERFUCD (FUNMSG, GENFUN)
         IF (GENFUN .LT. 0) THEN
            CALL OPMSG ('Could not find the function you typed, ' //
     1                  'try again.')
            GOTO 550
         ENDIF
      ENDIF

C  GENFUN is now set
      FUNOK = GENFUN .EQ. EXPFUN

600   CONTINUE
      CALL OPMSG ('If the error message indicates the numeric ' //
     1            'error code, enter it; otherwise type "n".')
      CALL OPLIN (FUNMSG)
      IF (FUNMSG .EQ. 'n') GOTO 610
      
      LNB = LEADNB (FUNMSG)
      LST = ITRIM  (FUNMSG)
      CALL PRSINT (FUNMSG(LNB:LST), GENERR, IERR)
      IF (IERR .NE. 0) THEN
         CALL OPMSG ('Invalid reply; re-enter.')
         GOTO 600
      ENDIF

C  Explicit error code in message
      ERROK = IARFND(GENERR, EXPSIZ, EXPERR) .GT. 0
      GOTO 690

C  No explicit error code in message
610   CONTINUE
      IF (EXPSIZ.GT.1) THEN
         CALL OPMSG ('Here are the standard error messages ' //
     1               'for the valid error codes:')
      ELSE
         CALL OPMSG ('Here is the standard message wording:')
      ENDIF

      CALL OPMSG ('------- Begin standard wording -------')
      DO 50 IX = 1,EXPSIZ
         CALL SCHERR (EXPERR(IX), ERRMSG)
         CALL OPMSG (ERRMSG)
         IF (IX.LT.EXPSIZ) THEN
            CALL OPMSG ('-----------')
         ELSE
            CALL OPMSG ('------- End standard wording -------')
         ENDIF
50    CONTINUE

      CALL OPYN ('Does the meaning of the actual message ' //
     1           'match (one of) the standard message(s)?', ANS)
      ERROK = ANS.EQ.'y'

690   CONTINUE
C  OK so far?
      IF (ERROK .AND. FUNOK) THEN
         TSTAT = MIN(TSTAT, 0)
         GOTO 150
      ENDIF

      IF (TSTAT .GE. 0) THEN
C  first detected failure condition
         CALL FAIL
         TSTAT = -1
      ENDIF

      IF (.NOT. ERROK) THEN
         IF (FUNMSG .EQ. 'n') THEN
            CALL INMSG ('Incorrect description of error condition ' //
     1                  'in error message.')
         ELSE
            WRITE (MSG, '(A,I6.3,A)') 'Reported error number ', GENERR,
     1                  ' is not one of the expected values.'
            CALL INMSG (MSG)
         ENDIF
      ENDIF

      IF (.NOT. FUNOK) THEN
         IF (GENFUN.LT.0) THEN
            CALL INMSG ('Missing function identifier in error message.')
         ELSE
            WRITE (MSG, '(A,I4.3,A,I4.3,A)') 'Reported function ' //
     1             'identifier ', GENFUN, ' does not match '      //
     2             'expected function identifier ', EXPFUN, '.'
            CALL INMSG (MSG)
         ENDIF
      ENDIF
      GOTO 150

999   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/gterrm                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE GTERRM (ELUN, EMSG)

C  GTERRM retrieves one error message from a specified error file
C  and returns it.

C  Input parameter:
C    ELUN : logical unit number from which to read
C  Output parameter:
C    EMSG : complete text of error message, even if spread over
C           several records; also used as input to tell whether
C           this is the first read or not.

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR, 
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80, 
     1                CONTAB(40)*150

      SAVE EREC

      INTEGER    ELUN, NMRK, ITRIM
      LOGICAL    FIRST, ERMSGH
      CHARACTER  EMSG*(*), EREC*200, ANS*1

C  special strings to control processing of error file
      CHARACTER  EOFMRK*17,                    BOFMRK*10
      PARAMETER (EOFMRK = 'end of error file', BOFMRK = 'first call')

      DATA EREC / ' ' /

      NMRK  = ITRIM (ERRMRK)
      
      IF (ERRMRK .NE. ' ') THEN
C  use special string to identify start of error message
         FIRST = EMSG.EQ.BOFMRK

C  start to fill EMSG from EREC
210      CONTINUE
         IF (FIRST) THEN
            EMSG = ' '
         ELSE
C  EREC has first record of error message or EOF indicator
            EMSG = EREC
         ENDIF

         IF (EMSG .EQ. EOFMRK) RETURN

250      CONTINUE
         READ (UNIT=ELUN, FMT='(A)', END=290) EREC
C  EREC now has next record 
         IF (ERMSGH (EREC, ERRMRK, NMRK)) THEN
C  message header
            GOTO 295
         ELSE
C  non-header 
            EMSG(ITRIM(EMSG)+2:) = EREC
            GOTO 250
         ENDIF

290      CONTINUE
         EREC = EOFMRK

295      CONTINUE
C  EREC contains either EOFMRK or message header
         IF (FIRST) THEN
            FIRST = .FALSE.
            GOTO 210
         ENDIF

      ELSE
C  operator must identify completion of error message
         EMSG = ' '
300      CONTINUE
         READ (UNIT=ELUN, FMT='(A)', END=310) EREC

         IF (EMSG.EQ.' ') THEN
            EMSG = EREC
         ELSE
            EMSG(ITRIM(EMSG)+2:) = EREC
         ENDIF

         IF (EMSG.EQ.' ') GOTO 300

         CALL OPMSG ('------- Begin message from error file: ' //
     1               '-------')
         CALL OPMSG (EMSG)
         CALL OPMSG ('------- End message from error file: -------')
         CALL OPYN ('Is the error message completely displayed? ', ANS)
         IF (ANS .EQ. 'n') GOTO 300
         GOTO 320

310      CONTINUE
         CALL OPMSG ('Hit EOF while trying to read error file.')

320      CONTINUE
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 09.01/ermsgh                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION ERMSGH (EREC, ERRMRK, NMRK)

C  ERMSGH determines whether or not a given record from the error file is
C  the header of an error message, i.e. whether it is the first record of
C  a possibly multi-record message.  The default logic allows for
C  searching for the presence of a given string (ERRMRK) within the
C  record, but users may code any logic needed by which to distinguish
C  message headers.

CUSERMOD modify if necessary.

C  Input parameters:
C    EREC   : record from error file to be examined
C    ERRMRK : distinctive character string identifying message header
C    NMRK   : number of significant characters in ERRMRK

      INTEGER    NMRK
      CHARACTER  EREC*(*), ERRMRK*(*)

      ERMSGH = INDEX(EREC, ERRMRK(1:NMRK)) .GE. 1

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/scherr                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SCHERR (ERRNUM, ERRMSG)

C  SCHERR accepts a valid error code and returns the standard
C  corresponding error message.
C  
C  Input parameter:
C    ERRNUM: Standard error code
C  Output parameter:
C    ERRMSG: Wording of corresponding standard error message

      INTEGER    LISIZE
      PARAMETER (LISIZE = 111)
      INTEGER    ERRNUM, STDNUM(LISIZE), MSGDX, IARFND

      CHARACTER  ERRMSG*(*), STDMSG*180

C  List of standard error codes
      DATA STDNUM / 
     1     1,2,3,4,5,6,7,
     2     50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,
     3     100,101,102,103,104,105,106,107,108,109,
     4     110,111,112,113,114,115,116,117,118,
     5     150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,
     6     200,201,202,203,204,205,206,207,208,
     7     250,251,252,253,254,255,256,257,258,259,260,261,262,263,
     8     300,301,302,303,304,305,306,307,350,351,
     9     400,401,402,403,404,405,406,407,408,450,
     A     2000,2001,2002,2003,2004,2005,2006, 
     B     2200,2201,2202,2203,2204  /

      MSGDX = IARFND(ERRNUM, LISIZE, STDNUM)
      IF (MSGDX.LT.1) CALL UNMSG ('SCHERR called with invalid ERRNUM.')

      GOTO ( 01,02,03,04,05,06,07,08,09,10,
     1       11,12,13,14,15,16,17,18,19,20,
     2       21,22,23,24,25,26,27,28,29,30,
     3       31,32,33,34,35,36,37,38,39,40,
     4       41,42,43,44,45,46,47,48,49,50,
     5       51,52,53,54,55,56,57,58,59,60,
     6       61,62,63,64,65,66,67,68,69,70,
     7       71,72,73,74,75,76,77,78,79,80,
     8       81,82,83,84,85,86,87,88,89,90,
     9       91,92,93,94,95,96,97,98,99,
     A       2000,2001,2002,2003,2004,2005,2006, 
     B       2200,2201,2202,2203,2204),  MSGDX
                                                            
      CALL UNMSG ('SCHERR called with very invalid ERRNUM.')

C  List of standard error messages

01    STDMSG = '(PHCL,WSCL,STCL,ARCL)'
      GOTO 101
02    STDMSG = '(PHOP,*,*,*)'
      GOTO 101
03    STDMSG = '(PHOP,WSOP,*,*)'
      GOTO 101
04    STDMSG = '(PHOP,WSCL,STCL,ARCL)'
      GOTO 101
05    STDMSG = '(PHOP,*,STOP,*)'
      GOTO 101
06    STDMSG = '(PHOP,*,STCL,*)'
      GOTO 101
07    STDMSG = '(PHOP,*,*,AROP)'
      GOTO 101
08    STDMSG = 'connection identifier not recognized by the ' //
     1         'implementation'
      GOTO 101
09    STDMSG = 'this information is not yet available for this ' //
     1         'generic workstation type; open a workstation of ' //
     1         'this type and use the specific workstation type'
      GOTO 101
10    STDMSG = 'workstation type not recognized by the implementation'
      GOTO 101
11    STDMSG = 'workstation identifier already is in use'
      GOTO 101
12    STDMSG = 'the specified workstation is not open'
      GOTO 101
13    STDMSG = 'workstation cannot be opened for an implementation ' //
     1         'dependent reason'
      GOTO 101
14    STDMSG = 'specified workstation is not of category MO'
      GOTO 101
15    STDMSG = 'specified workstation is of category MI'
      GOTO 101
16    STDMSG = 'specified workstation is not of category MI'
      GOTO 101
17    STDMSG = 'the specified workstation does not have output ' //
     1         'capability (i.e., the workstation category is ' //
     1         'neither OUTPUT, OUTIN, nor MO)'
      GOTO 101
18    STDMSG = 'specified workstation is not of category OUTIN'
      GOTO 101
19    STDMSG = 'specified workstation is neither of category INPUT ' //
     1         'nor of category OUTIN'
      GOTO 101
20    STDMSG = 'this information is not available for this MO ' //
     1         'workstation type'
      GOTO 101
21    STDMSG = 'opening this workstation would exceed the maximum ' //
     1         'number of simultaneously open workstations'
      GOTO 101
22    STDMSG = 'the specified workstation type is not able to ' //
     1         'generate the specified GDP'
      GOTO 101
23    STDMSG = 'the bundle index value is less than one'
      GOTO 101
24    STDMSG = 'the specified representation has not been defined'
      GOTO 101
25    STDMSG = 'the specified representation has not been ' //
     1         'predefined on this workstation'
      GOTO 101
26    STDMSG = 'setting this bundle table entry would exceed the ' //
     1         'maximum number of entries allowed in the ' //
     1         'workstation bundle table'
      GOTO 101
27    STDMSG = 'the specified linetype is not available on the ' //
     1         'specified workstation'
      GOTO 101
28    STDMSG = 'the specified marker type is not available on the ' //
     1         'specified workstation'
      GOTO 101
29    STDMSG = 'the specified font is not available for the ' //
     1         'requested text precision on the specified workstation'
      GOTO 101
30    STDMSG = 'the specified edgetype is not available on the ' //
     1         'specified workstation'
      GOTO 101
31    STDMSG = 'the specified interior style is not available on ' //
     1         'the workstation'
      GOTO 101
32    STDMSG = 'interior style PATTERN is not suppported on the ' //
     1         'workstation'
      GOTO 101
33    STDMSG = 'the specified colour model is not available on the ' //
     1         'workstation'
      GOTO 101
34    STDMSG = 'the specified HLHSR model is not available on the ' //
     1         'specified workstation'
      GOTO 101
35    STDMSG = 'the pattern index value is less than one'
      GOTO 101
36    STDMSG = 'the colour index value is less than zero'
      GOTO 101
37    STDMSG = 'the view index value is less than zero'
      GOTO 101
38    STDMSG = 'the view index value is less than one'
      GOTO 101
39    STDMSG = 'one of the dimensions of pattern colour index array ' //
     1         'is less than one'
      GOTO 101
40    STDMSG = 'one of the dimensions of the colour index array is ' //
     1         'less than zero'
      GOTO 101
41    STDMSG = 'one of the components of the colour specification ' //
     1         'is out of range.  The valid range is dependent ' //
     1         'upon the current colour model'
      GOTO 101
42    STDMSG = 'setting this view table entry would exceed the ' //
     1         'maximum number of entries allowed in the ' //
     1         'workstation view table'
      GOTO 101
43    STDMSG = 'invalid window: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, ' //
     1         'UMIN>=UMAX or VMIN>=VMAX'
      GOTO 101
44    STDMSG = 'invalid viewport: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX'
      GOTO 101
45    STDMSG = 'invalid view clipping limits: XMIN>=XMAX, ' //
     1         'YMIN>=YMAX or ZMIN>ZMAX'
      GOTO 101
46    STDMSG = 'the view clipping limits are not within NPC range'
      GOTO 101
47    STDMSG = 'the projection viewport limits are not within NPC range'
      GOTO 101
48    STDMSG = 'the workstation window limits are not within NPC range'
      GOTO 101
49    STDMSG = 'the workstation viewport is not within display space'
      GOTO 101
50    STDMSG = 'front plane and back plane distances are equal ' //
     1         'when z-extent of the projection viewport is non-zero'
      GOTO 101
51    STDMSG = 'the view plane normal vector has length zero'
      GOTO 101
52    STDMSG = 'the view up vector has length zero'
      GOTO 101
53    STDMSG = 'the view up and view plane normal vectors are ' //
     1         'parallel thus the viewing coordinate system ' //
     1         'cannot be established'
      GOTO 101
54    STDMSG = 'the projection reference point is between the ' //
     1         'front and back planes'
      GOTO 101
55    STDMSG = 'the projection reference point cannot be ' //
     1         'positioned on the view plane'
      GOTO 101
56    STDMSG = 'the back plane is in front of the front plane'
      GOTO 101
57    STDMSG = 'Warning, ignoring structures that do not exist'
      GOTO 101
58    STDMSG = 'the specified structure does not exist'
      GOTO 101
59    STDMSG = 'the specified element does not exist'
      GOTO 101
60    STDMSG = 'specified starting path not found in CSS'
      GOTO 101
61    STDMSG = 'specified search ceiling index out of range'
      GOTO 101
62    STDMSG = 'the table does not exist in the open structure ' //
     1         'between the element pointer and the end of the ' //
     1         'structure'
      GOTO 101
63    STDMSG = 'one or both of the labels does not exist in the ' //
     1         'open structure between the element pointer and ' //
     1         'the end of structure'
      GOTO 101
64    STDMSG = 'the specified path depth is less than zero'
      GOTO 101
65    STDMSG = 'the display priority is out of range'
      GOTO 101
66    STDMSG = 'the specified device is not available on the ' //
     1         'specified workstation '
      GOTO 101
67    STDMSG = 'the function requires the input device to be in ' //
     1         'REQUEST mode'
      GOTO 101
68    STDMSG = 'the function requires the input device to be in ' //
     1         'SAMPLE mode'
      GOTO 101
69    STDMSG = 'the specified prompt/echo type is not available on ' //
     1         'the specified workstation'
      GOTO 101
70    STDMSG = 'invalid echo area/volume; XMIN>=XMAX,YMIN>=YMAX or ' //
     1         'ZMIN>ZMAX'
      GOTO 101
71    STDMSG = 'one of the echo area/volume boundary points is ' //
     1         'outside the range of the device'
      GOTO 101
72    STDMSG = 'Warning, the input queue has overflowed'
      GOTO 101
73    STDMSG = 'input queue has not overflowed, since OPEN PHIGS ' //
     1         'or last invocation of INQUIRE INPUT QUEUE OVERFLOW'
      GOTO 101
74    STDMSG = 'input queue has overflowed, but associated ' //
     1         'workstation has been closed'
      GOTO 101
75    STDMSG = 'the input device class of the current input report ' //
     1         'does not match the class being requested'
      GOTO 101
76    STDMSG = 'one of the fields within the input device data ' //
     1         'record is in error'
      GOTO 101
77    STDMSG = 'initial value is invalid'
      GOTO 101
78    STDMSG = 'number of points in the initial stroke is greater ' //
     1         'than the buffer size'
      GOTO 101
79    STDMSG = 'length of the initial string is greater than the ' //
     1         'buffer size'
      GOTO 101
80    STDMSG = 'item type is not allowed for user items'
      GOTO 101
81    STDMSG = 'item length is invalid '
      GOTO 101
82    STDMSG = 'no item is left in metafile input'
      GOTO 101
83    STDMSG = 'metafile item is invalid'
      GOTO 101
84    STDMSG = 'item type is unknown'
      GOTO 101
85    STDMSG = 'content of item data record is invalid for the ' //
     1         'specified item type'
      GOTO 101
86    STDMSG = 'maximum item data record length is invalid'
      GOTO 101
87    STDMSG = 'user item cannot be interpreted'
      GOTO 101
88    STDMSG = 'Warning, the specified escape is not available on ' //
     1         'one or more workstations in this implementation.  ' //
     1         'The escape will be processed by those workstations ' //
     1         'on which it is available'
      GOTO 101
89    STDMSG = 'one of the fields within the escape data record is ' //
     1         'in error'
      GOTO 101
90    STDMSG = 'the archive file cannot be opened'
      GOTO 101
91    STDMSG = 'opening this archive file would exceed the maximum ' //
     1         'number of simultaneously open archive files'
      GOTO 101
92    STDMSG = 'archive file identifier already in use'
      GOTO 101
93    STDMSG = 'the archive file is not a PHIGS archive file'
      GOTO 101
94    STDMSG = 'the specified archive file is not open'
      GOTO 101
95    STDMSG = 'name conflict occurred while conflict resolution ' //
     1         'flag has value ABANDON'
      GOTO 101
96    STDMSG = 'Warning, the archive file is full.  Any structures ' //
     1         'that were archived were archived in total'
      GOTO 101
97    STDMSG = 'Warning, some of the specified structures do not ' //
     1         'exist on the archive file'
      GOTO 101
98    STDMSG = 'Warning, some of the specified structures do not ' //
     1         'exist on the archive file.  PHIGS will create ' //
     1         'empty structure in their place'
      GOTO 101
99    STDMSG = 'the specified error file is invalid'
      GOTO 101

2000  STDMSG = 'enumeration type out of range'
      GOTO 101
2001  STDMSG = 'output parameter size insufficient'
      GOTO 101
2002  STDMSG = 'list or set element not available'
      GOTO 101
2003  STDMSG = 'invalid data record'
      GOTO 101
2004  STDMSG = 'input parameter size out of range'
      GOTO 101
2005  STDMSG = 'invalid list of point lists'
      GOTO 101
2006  STDMSG = 'invalid list of filters'
      GOTO 101
2200  STDMSG = 'start index is out of range'
      GOTO 101
2201  STDMSG = 'length of application''s list is negative'
      GOTO 101
2202  STDMSG = 'enumeration type out of range'
      GOTO 101
2203  STDMSG = 'error while allocating a Store'
      GOTO 101
2204  STDMSG = 'error while allocating memory'
      GOTO 101

101   CONTINUE

      IF (MSGDX .LE. 7) THEN
         ERRMSG = 'Ignoring function, function requires state ' //
     1            STDMSG
      ELSEIF (STDMSG(1:7) .EQ. 'Warning') THEN
         ERRMSG = STDMSG
      ELSE
         ERRMSG = 'Ignoring function, ' // STDMSG
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/tstign                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTIGN (IGNORE)

C  TSTIGN is used to test that a function signalling an error is
C  ignored.

C  Input parameters:
C    IGNORE : logical variable indicating whether the function was ignored

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR, 
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80, 
     1                CONTAB(40)*150

      INTEGER   ITRIM
      LOGICAL   IGNORE
      CHARACTER MSG*300, FUNNAM*80

      CALL ERFUNM (EFID(EFCNT), FUNNAM)
      MSG = 'If ' // FUNNAM
      MSG(ITRIM(MSG)+2:) = 'signals an error because ' // CURCON
      MSG(ITRIM(MSG)+1:) = ', it should not cause any other effect.'

      CALL SETMSG (ERRSRS, MSG)
      CALL IFPF (IGNORE)

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 09.01/streq                       *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION STREQ (REQ)

C  STREQ determines whether a required state is actually in force,
C  as reported by all the relevant inquire functions.
C  
C  Input parameter:
C    REQ : 4-character code for required state, position 1-4 standing
C          for PHIGS, Workstation, Structure, and Archive, respectively.
C          Each position must be 'O', 'C', or '*', standing for open,
C          closed, and don't care.

C system state value
      INTEGER    PPHCL,     PPHOP
      PARAMETER (PPHCL = 0, PPHOP = 1)
C workstation state
      INTEGER    PWSCL,     PWSOP
      PARAMETER (PWSCL = 0, PWSOP = 1)
C structure state value
      INTEGER    PSTCL,     PSTOP
      PARAMETER (PSTCL = 0, PSTOP = 1)
C archive state
      INTEGER    PARCL,   PAROP
      PARAMETER (PARCL=0, PAROP=1)
C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER   PST,WST,SST,AST, NWK,NAR, OPSTAT, ERRIND
      INTEGER   IDUM1, IDUM2

      CHARACTER REQ*4

      STREQ = .FALSE.
      CALL PQSYS  (PST)
      CALL PQWKST (WST)
      CALL PQSTRS (SST)
      CALL PQARS  (AST)

      IF (REQ(1:1).EQ.'O') THEN
C  PHIGS should be open
         IF (PST.NE.PPHOP) RETURN
         IF (REQ(2:2).EQ.'*') THEN
C           don't care about workstation status
         ELSE
            CALL PQOPWK (0, ERRIND, NWK, IDUM1)
            CALL CHKINQ ('pqopwk', ERRIND)
            IF (REQ(2:2).EQ.'O') THEN
               IF (WST.NE.PWSOP) RETURN
               IF (NWK.LT.1)     RETURN
            ELSEIF (REQ(2:2).EQ.'C') THEN
               IF (WST.NE.PWSCL) RETURN
               IF (NWK.NE.0)     RETURN
            ELSE
               CALL UNMSG ('Second character of parameter to ' //
     1               'STREQ must be O or C or *.')
            ENDIF
         ENDIF

         IF (REQ(3:3).EQ.'*') THEN
C           don't care about structure status
         ELSE
            CALL PQOPST (ERRIND, OPSTAT, IDUM1)
            CALL CHKINQ ('pqopst', ERRIND)
            IF (REQ(3:3).EQ.'O') THEN
               IF (SST.NE.PSTOP)     RETURN
               IF (OPSTAT.NE.POPNST) RETURN
            ELSEIF (REQ(3:3).EQ.'C') THEN
               IF (SST.NE.PSTCL)     RETURN
               IF (OPSTAT.NE.PNONST) RETURN
            ELSE
               CALL UNMSG ('Third character of parameter to ' //
     1               'STREQ must be O or C or *.')
            ENDIF
         ENDIF

         IF (REQ(4:4).EQ.'*') THEN
C           don't care about archive status
         ELSE
            CALL PQARF (0, ERRIND, NAR, IDUM1,IDUM2)
            CALL CHKINQ ('pqarf', ERRIND)
            IF (REQ(4:4).EQ.'O') THEN
               IF (AST.NE.PAROP) RETURN
               IF (NAR.LT.1)     RETURN
            ELSEIF (REQ(4:4).EQ.'C') THEN
               IF (AST.NE.PARCL) RETURN
               IF (NAR.NE.0)     RETURN
            ELSE
               CALL UNMSG ('Fourth character of parameter to ' //
     1               'STREQ must be O or C or *.')
            ENDIF
         ENDIF

      ELSEIF (REQ(1:1).EQ.'C') THEN
C  PHIGS should be closed
         IF (REQ.NE.'CCCC') THEN
            CALL UNMSG ('STREQ parameter should be CCCC.')
         ENDIF
         IF (PST.NE.PPHCL) RETURN
         IF (WST.NE.PWSCL) RETURN 
         IF (SST.NE.PSTCL) RETURN 
         IF (AST.NE.PARCL) RETURN
      ELSE
         CALL UNMSG ('First character of parameter to STREQ must ' //
     1               'be O or C.')
      ENDIF

      STREQ = .TRUE.

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/rfuncs                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE RFUNCS ()

C  RFUNCS is the home of the entry points for PHIGS functions which
C  are called in order to generate an error.  The functions are
C  followed a wrapper routine which records what should have
C  happened.

C PHIGS function names (for those functions which signal error)
      INTEGER    EOPPH,      ECLPH,      EOPWK,      ECLWK
      PARAMETER (EOPPH =000, ECLPH =001, EOPWK =002, ECLWK =003)
      INTEGER    ERST,       EUWK,       ESDUS,      EMSG
      PARAMETER (ERST  =004, EUWK  =005, ESDUS =006, EMSG  =007)
      INTEGER    EPL3,       EPL,        EPM3,       EPM
      PARAMETER (EPL3  =008, EPL   =009, EPM3  =010, EPM   =011)
      INTEGER    ETX3,       ETX,        EATR3,      EATR
      PARAMETER (ETX3  =012, ETX   =013, EATR3 =014, EATR  =015)
      INTEGER    EFA3,       EFA,        EFAS3,      EFAS
      PARAMETER (EFA3  =016, EFA   =017, EFAS3 =018, EFAS  =019)
      INTEGER    ECA3,       ECA,        EGDP3,      EGDP
      PARAMETER (ECA3  =020, ECA   =021, EGDP3 =022, EGDP  =023)
      INTEGER    ESPLI,      ESPMI,      ESTXI,      ESII
      PARAMETER (ESPLI =024, ESPMI =025, ESTXI =026, ESII  =027)
      INTEGER    ESEDI,      ESLN,       ESLWSC,     ESPLCI
      PARAMETER (ESEDI =028, ESLN  =029, ESLWSC=030, ESPLCI=031)
      INTEGER    ESMK,       ESMKSC,     ESPMCI,     ESTXFN
      PARAMETER (ESMK  =032, ESMKSC=033, ESPMCI=034, ESTXFN=035)
      INTEGER    ESTXPR,     ESCHXP,     ESCHSP,     ESTXCI
      PARAMETER (ESTXPR=036, ESCHXP=037, ESCHSP=038, ESTXCI=039)
      INTEGER    ESCHH,      ESCHUP,     ESTXP,      ESTXAL
      PARAMETER (ESCHH =040, ESCHUP=041, ESTXP =042, ESTXAL=043)
      INTEGER    ESATCH,     ESATCU,     ESATP,      ESATAL
      PARAMETER (ESATCH=044, ESATCU=045, ESATP =046, ESATAL=047)
      INTEGER    ESANS,      ESIS,       ESISI,      ESICI
      PARAMETER (ESANS =048, ESIS  =049, ESISI =050, ESICI =051)
      INTEGER    ESEDFG,     ESEDT,      ESEWSC,     ESEDCI
      PARAMETER (ESEDFG=052, ESEDT =053, ESEWSC=054, ESEDCI=055)
      INTEGER    ESPA,       ESPRPV,     ESPARF,     EADS
      PARAMETER (ESPA  =056, ESPRPV=057, ESPARF=058, EADS  =059)
      INTEGER    ERES,       ESIASF,     ESPLR,      ESPMR
      PARAMETER (ERES  =060, ESIASF=061, ESPLR =062, ESPMR =063)
      INTEGER    ESTXR,      ESIR,       ESEDR,      ESPAR
      PARAMETER (ESTXR =064, ESIR  =065, ESEDR =066, ESPAR =067)
      INTEGER    ESCR,       ESHLFT,     ESIVFT,     ESCMD
      PARAMETER (ESCR  =068, ESHLFT=069, ESIVFT=070, ESCMD =071)
      INTEGER    ESHRID,     ESHRM,      ESLMT3,     ESLMT
      PARAMETER (ESHRID=072, ESHRM =073, ESLMT3=074, ESLMT =075)
      INTEGER    ESGMT3,     ESGMT,      ESMCV3,     ESMCV
      PARAMETER (ESGMT3=076, ESGMT =077, ESMCV3=078, ESMCV =079)
      INTEGER    ESMCLI,     ERMCV,      ESVWI,      ESVWR3
      PARAMETER (ESMCLI=080, ERMCV =081, ESVWI =082, ESVWR3=083)
      INTEGER    ESVWR,      ESVTIP,     ESWKW3,     ESWKW
      PARAMETER (ESVWR =084, ESVTIP=085, ESWKW3=086, ESWKW =087)
      INTEGER    ESWKV3,     ESWKV,      EOPST,      ECLST
      PARAMETER (ESWKV3=088, ESWKV =089, EOPST =090, ECLST =091)
      INTEGER    EEXST,      ELB,        EAP,        EGSE
      PARAMETER (EEXST =092, ELB   =093, EAP   =094, EGSE  =095)
      INTEGER    ESEDM,      ECELST,     ESEP,       EOSEP
      PARAMETER (ESEDM =096, ECELST=097, ESEP  =098, EOSEP =099)
      INTEGER    ESEPLB,     EDEL,       EDELRA,     EDELLB
      PARAMETER (ESEPLB=100, EDEL  =101, EDELRA=102, EDELLB=103)
      INTEGER    EEMST,      EDST,       EDSN,       EDAS
      PARAMETER (EEMST =104, EDST  =105, EDSN  =106, EDAS  =107)
      INTEGER    ECSTID,     ECSTRF,     ECSTIR,     EPOST
      PARAMETER (ECSTID=108, ECSTRF=109, ECSTIR=110, EPOST =111)
      INTEGER    EUPOST,     EUPAST,     EOPARF,     ECLARF
      PARAMETER (EUPOST=112, EUPAST=113, EOPARF=114, ECLARF=115)
      INTEGER    EARST,      EARSN,      EARAST,     ESCNRS
      PARAMETER (EARST =116, EARSN =117, EARAST=118, ESCNRS=119)
      INTEGER    ERSID,      EREST,      ERESN,      ERAST
      PARAMETER (ERSID =120, EREST =121, ERESN =122, ERAST =123)
      INTEGER    EREPAN,     EREPDE,     EDSTAR,     EDSNAR
      PARAMETER (EREPAN=124, EREPDE=125, EDSTAR=126, EDSNAR=127)
      INTEGER    EDASAR,     ESPKID,     ESPKFT,     EINLC3
      PARAMETER (EDASAR=128, ESPKID=129, ESPKFT=130, EINLC3=131)
      INTEGER    EINLC,      EINSK3,     EINSK,      EINVL3
      PARAMETER (EINLC =132, EINSK3=133, EINSK =134, EINVL3=135)
      INTEGER    EINVL,      EINCH3,     EINCH,      EINPK3
      PARAMETER (EINVL =136, EINCH3=137, EINCH =138, EINPK3=139)
      INTEGER    EINPK,      EINST3,     EINST,      ESLCM
      PARAMETER (EINPK =140, EINST3=141, EINST =142, ESLCM =143)
      INTEGER    ESSKM,      ESVLM,      ESCHM,      ESPKM
      PARAMETER (ESSKM =144, ESVLM =145, ESCHM =146, ESPKM =147)
      INTEGER    ESSTM,      ERQLC3,     ERQLC,      ERQSK3
      PARAMETER (ESSTM =148, ERQLC3=149, ERQLC =150, ERQSK3=151)
      INTEGER    ERQSK,      ERQVL,      ERQCH,      ERQPK
      PARAMETER (ERQSK =152, ERQVL =153, ERQCH =154, ERQPK =155)
      INTEGER    ERQST,      ESMLC3,     ESMLC,      ESMSK3
      PARAMETER (ERQST =156, ESMLC3=157, ESMLC =158, ESMSK3=159)
      INTEGER    ESMSK,      ESMVL,      ESMCH,      ESMPK
      PARAMETER (ESMSK =160, ESMVL =161, ESMCH =162, ESMPK =163)
      INTEGER    ESMST,      EWAIT,      EFLUSH,     EGTLC3
      PARAMETER (ESMST =164, EWAIT =165, EFLUSH=166, EGTLC3=167)
      INTEGER    EGTLC,      EGTSK3,     EGTSK,      EGTVL
      PARAMETER (EGTLC =168, EGTSK3=169, EGTSK =170, EGTVL =171)
      INTEGER    EGTCH,      EGTPK,      EGTST,      EWITM
      PARAMETER (EGTCH =172, EGTPK =173, EGTST =174, EWITM =175)
      INTEGER    EGTITM,     ERDITM,     EIITM,      ESERHM
      PARAMETER (EGTITM=176, ERDITM=177, EIITM =178, ESERHM=179)
      INTEGER    EESC,       EPREC,      EUREC
      PARAMETER (EESC  =180, EPREC =181, EUREC =182 )

      INTEGER  WKID, I1,I2,I3,I4,I5,I6,I7,I8, IA(*),IB(*)

      REAL     R1,R2,R3,R4, RA(*),RB(*),RC(*)
      REAL     XFA(3,3), XFB(3,3), VCLIP(*), XGA(4,4), XGB(4,4)

      CHARACTER  CHARS*(*)

C *** *** *** control *** *** ***

      ENTRY       ROPPH (I1, I2)
      CALL        POPPH (I1, I2)
      CALL ECHKZ (EOPPH)
      RETURN

      ENTRY       RCLPH 
      CALL        PCLPH 
      CALL ECHKZ (ECLPH)
      RETURN
 
      ENTRY       ROPWK (WKID, I1, I2)
      CALL        POPWK (WKID, I1, I2)
      CALL ECHKZ (EOPWK)
      RETURN

      ENTRY       ROPST (I1)
      CALL        POPST (I1)
      CALL ECHKZ (EOPST)
      RETURN

      ENTRY       RCLWK (WKID)
      CALL        PCLWK (WKID)
      CALL ECHKZ (ECLWK)
      RETURN

      ENTRY       RRST (WKID, I1)
      CALL        PRST (WKID, I1)
      CALL ECHKZ (ERST)
      RETURN

      ENTRY       RUWK (WKID, I1)
      CALL        PUWK (WKID, I1)
      CALL ECHKZ (EUWK)
      RETURN

      ENTRY       RSDUS (WKID, I1,I2)
      CALL        PSDUS (WKID, I1,I2)
      CALL ECHKZ (ESDUS)
      RETURN

C *** *** *** output primitives *** *** ***

      ENTRY       RPL3 (I1, RA,RB,RC)
      CALL        PPL3 (I1, RA,RB,RC)
      CALL ECHKZ (EPL3)
      RETURN
                     
      ENTRY       RPL (I1, RA,RB)
      CALL        PPL (I1, RA,RB)
      CALL ECHKZ (EPL)
      RETURN

      ENTRY       RTX (R1, R2, CHARS)
      CALL        PTX (R1, R2, CHARS)
      CALL ECHKZ (ETX)
      RETURN

      ENTRY       RFA (I1, RA, RB)
      CALL        PFA (I1, RA, RB)
      CALL ECHKZ (EFA)
      RETURN

      ENTRY       RFA3 (I1, RA, RB, RC)
      CALL        PFA3 (I1, RA, RB, RC)
      CALL ECHKZ (EFA3)
      RETURN

      ENTRY       RPM (I1, RA, RB)
      CALL        PPM (I1, RA, RB)
      CALL ECHKZ (EPM)
      RETURN

      ENTRY       RATR (R1, R2, R3, R4, CHARS)
      CALL        PATR (R1, R2, R3, R4, CHARS)
      CALL ECHKZ (EATR)
      RETURN

      ENTRY       RFAS (I1, IA, RA, RB)
      CALL        PFAS (I1, IA, RA, RB)
      CALL ECHKZ (EFAS)
      RETURN

      ENTRY       RFAS3 (I1, IA, RA, RB, RC)
      CALL        PFAS3 (I1, IA, RA, RB, RC)
      CALL ECHKZ (EFAS3)
      RETURN

      ENTRY       RCA3 (RA,RB,RC,I1,I2,I3,I4,I5,I6,IA)
      CALL        PCA3 (RA,RB,RC,I1,I2,I3,I4,I5,I6,IA)
      CALL ECHKZ (ECA3)
      RETURN

      ENTRY       RCA (R1,R2,R3,R4,I1,I2,I3,I4,I5,I6,IA)
      CALL        PCA (R1,R2,R3,R4,I1,I2,I3,I4,I5,I6,IA)
      CALL ECHKZ (ECA)
      RETURN

      

C *** *** *** attributes *** *** ***

      ENTRY       RSPLR (WKID, I1,I2,R1,I3)
      CALL        PSPLR (WKID, I1,I2,R1,I3)
      CALL ECHKZ (ESPLR)
      RETURN

      ENTRY       RSPMR (WKID, I1,I2,R1,I3)
      CALL        PSPMR (WKID, I1,I2,R1,I3)
      CALL ECHKZ (ESPMR)
      RETURN

      ENTRY       RSTXP (I1)
      CALL        PSTXP (I1)
      CALL ECHKZ (ESTXP)
      RETURN

      ENTRY       RSTXAL (I1, I2)
      CALL        PSTXAL (I1, I2)
      CALL ECHKZ (ESTXAL)
      RETURN
      
      ENTRY       RSATAL (I1, I2)
      CALL        PSATAL (I1, I2)
      CALL ECHKZ (ESATAL)
      RETURN

      ENTRY       RSIS (I1)
      CALL        PSIS (I1)
      CALL ECHKZ (ESIS)
      RETURN

      ENTRY       RSII (I1)
      CALL        PSII (I1)
      CALL ECHKZ (ESII)
      RETURN

      ENTRY       RSMKSC (R1)
      CALL        PSMKSC (R1)
      CALL ECHKZ (ESMKSC)
      RETURN

      ENTRY       RSTXFN (I1)
      CALL        PSTXFN (I1)
      CALL ECHKZ (ESTXFN)
      RETURN

      ENTRY       RSANS (I1)
      CALL        PSANS (I1)
      CALL ECHKZ (ESANS)
      RETURN

      ENTRY       RSPARF (R1, R2)
      CALL        PSPARF (R1, R2)
      CALL ECHKZ (ESPARF)
      RETURN

      ENTRY       RSIR (WKID, I1,I2,I3,I4)
      CALL        PSIR (WKID, I1,I2,I3,I4)
      CALL ECHKZ (ESIR)
      RETURN
      
      ENTRY       RSPAR (WKID, I1,I2,I3,I4,I5,I6,I7,IA)
      CALL        PSPAR (WKID, I1,I2,I3,I4,I5,I6,I7,IA)
      CALL ECHKZ (ESPAR)
      RETURN

      ENTRY       RSTXR (WKID, I1,I2,I3,R1,R2,I4)
      CALL        PSTXR (WKID, I1,I2,I3,R1,R2,I4)
      CALL ECHKZ (ESTXR)
      RETURN

      ENTRY       RSEDI (I1)
      CALL        PSEDI (I1)
      CALL ECHKZ (ESEDI)
      RETURN

      ENTRY       RSEDCI (I1)
      CALL        PSEDCI (I1)
      CALL ECHKZ (ESEDCI)
      RETURN

      ENTRY       RSPLCI (I1)
      CALL        PSPLCI (I1)
      CALL ECHKZ (ESPLCI)
      RETURN

      ENTRY       RSTXCI (I1)
      CALL        PSTXCI (I1)
      CALL ECHKZ (ESTXCI)
      RETURN

      ENTRY       RSTXI (I1)
      CALL        PSTXI (I1)
      CALL ECHKZ (ESTXI)
      RETURN

      ENTRY       RSEDR (WKID, I1,I2,I3,R1,I4)
      CALL        PSEDR (WKID, I1,I2,I3,R1,I4)
      CALL ECHKZ (ESEDR)
      RETURN

      ENTRY       RSPLI (I1)
      CALL        PSPLI (I1)
      CALL ECHKZ (ESPLI)
      RETURN

      ENTRY       RSLN (I1)
      CALL        PSLN (I1)
      CALL ECHKZ (ESLN)
      RETURN

      ENTRY       RSPMCI (I1)
      CALL        PSPMCI (I1)
      CALL ECHKZ (ESPMCI)
      RETURN

      ENTRY       RSCHXP (R1)
      CALL        PSCHXP (R1)
      CALL ECHKZ (ESCHXP)
      RETURN

      ENTRY       RSEDFG (I1)
      CALL        PSEDFG (I1)
      CALL ECHKZ (ESEDFG)
      RETURN

C *** *** *** generic attributes *** *** *** 

      ENTRY       RADS (I1, IA)
      CALL        PADS (I1, IA)
      CALL ECHKZ (EADS)
      RETURN

      ENTRY       RRES (I1, IA)
      CALL        PRES (I1, IA)
      CALL ECHKZ (ERES)
      RETURN

      ENTRY       RSIASF (I1, I2)
      CALL        PSIASF (I1, I2)
      CALL ECHKZ (ESIASF)
      RETURN

      ENTRY       RSHLFT (WKID, I1,IA, I2,IB)
      CALL        PSHLFT (WKID, I1,IA, I2,IB)
      CALL ECHKZ (ESHLFT)
      RETURN

      ENTRY       RSHRID (I1)
      CALL        PSHRID (I1)
      CALL ECHKZ (ESHRID)
      RETURN

      ENTRY       RSIVFT (WKID, I1,IA, I2,IB)
      CALL        PSIVFT (WKID, I1,IA, I2,IB)
      CALL ECHKZ (ESIVFT)
      RETURN

      ENTRY       RSCMD (WKID, I1)
      CALL        PSCMD (WKID, I1)
      CALL ECHKZ (ESCMD)
      RETURN

      ENTRY       RSCR (WKID, I1, I2, RA)
      CALL        PSCR (WKID, I1, I2, RA)
      CALL ECHKZ (ESCR)
      RETURN

      ENTRY       RSHRM (WKID, I1)
      CALL        PSHRM (WKID, I1)
      CALL ECHKZ (ESHRM)
      RETURN

C *** *** *** geometry *** *** *** 

      ENTRY       RSVWR (WKID, I1, XFA,XFB,VCLIP, I2)
      CALL        PSVWR (WKID, I1, XFA,XFB,VCLIP, I2)
      CALL ECHKZ (ESVWR)
      RETURN

      ENTRY       RSWKW (WKID, R1,R2,R3,R4)
      CALL        PSWKW (WKID, R1,R2,R3,R4)
      CALL ECHKZ (ESWKW)
      RETURN

      ENTRY       RSWKW3 (WKID, RA)
      CALL        PSWKW3 (WKID, RA)
      CALL ECHKZ (ESWKW3)
      RETURN

      ENTRY       RSWKV3 (WKID, RA)
      CALL        PSWKV3 (WKID, RA)
      CALL ECHKZ (ESWKV3)
      RETURN

      ENTRY       RSWKV (WKID, R1,R2,R3,R4)
      CALL        PSWKV (WKID, R1,R2,R3,R4)
      CALL ECHKZ (ESWKV)
      RETURN

      ENTRY       RSGMT (XFA)
      CALL        PSGMT (XFA)
      CALL ECHKZ (ESGMT)
      RETURN

      ENTRY       RSVWR3 (WKID, I1, XGA, XGB, VCLIP, I2,I3,I4)
      CALL        PSVWR3 (WKID, I1, XGA, XGB, VCLIP, I2,I3,I4)
      CALL ECHKZ (ESVWR3)
      RETURN

      ENTRY       RSLMT (XFA, I1)
      CALL        PSLMT (XFA, I1)
      CALL ECHKZ (ESLMT)
      RETURN

      ENTRY       RSMCV (I1, I2, RA)
      CALL        PSMCV (I1, I2, RA)
      CALL ECHKZ (ESMCV)
      RETURN
  
      ENTRY       RSVWI (I1)
      CALL        PSVWI (I1)
      CALL ECHKZ (ESVWI)
      RETURN

      ENTRY       RSVTIP (WKID, I1,I2,I3)
      CALL        PSVTIP (WKID, I1,I2,I3)
      CALL ECHKZ (ESVTIP)
      RETURN

C *** *** *** structures *** *** *** 

      ENTRY       RCLST
      CALL        PCLST
      CALL ECHKZ (ECLST)
      RETURN

      ENTRY       RLB (I1)
      CALL        PLB (I1)
      CALL ECHKZ (ELB)
      RETURN

      ENTRY       RSEP (I1)
      CALL        PSEP (I1)
      CALL ECHKZ (ESEP)
      RETURN

      ENTRY       REXST (I1)
      CALL        PEXST (I1)
      CALL ECHKZ (EEXST)
      RETURN

      ENTRY       RCELST (I1)
      CALL        PCELST (I1)
      CALL ECHKZ (ECELST)
      RETURN

      ENTRY       RDEL 
      CALL        PDEL
      CALL ECHKZ (EDEL)
      RETURN

      ENTRY       RSEDM (I1)
      CALL        PSEDM (I1)
      CALL ECHKZ (ESEDM)
      RETURN

      ENTRY       REMST (I1)
      CALL        PEMST (I1)
      CALL ECHKZ (EEMST)
      RETURN

      ENTRY       RDSN (I1, I2)
      CALL        PDSN (I1, I2)
      CALL ECHKZ (EDSN)
      RETURN

      ENTRY       RCSTIR (I1, I2)
      CALL        PCSTIR (I1, I2)
      CALL ECHKZ (ECSTIR)
      RETURN

      ENTRY       RSCNRS (I1, I2)
      CALL        PSCNRS (I1, I2)
      CALL ECHKZ (ESCNRS)
      RETURN

      ENTRY       RPOST (WKID, I1,R1)
      CALL        PPOST (WKID, I1,R1)
      CALL ECHKZ (EPOST)
      RETURN

      ENTRY       RSEPLB (I1)
      CALL        PSEPLB (I1)
      CALL ECHKZ (ESEPLB)
      RETURN

      ENTRY       RDELLB (I1, I2)
      CALL        PDELLB (I1, I2)
      CALL ECHKZ (EDELLB)
      RETURN

      ENTRY       RUPOST (WKID, I1)
      CALL        PUPOST (WKID, I1)
      CALL ECHKZ (EUPOST)
      RETURN

      ENTRY       RUPAST (WKID)
      CALL        PUPAST (WKID)
      CALL ECHKZ (EUPAST)
      RETURN

C *** *** *** archives *** *** *** 

      ENTRY       ROPARF (I1, I2)
      CALL        POPARF (I1, I2)
      CALL ECHKZ (EOPARF)
      RETURN

      ENTRY       RCLARF (I1)
      CALL        PCLARF (I1)
      CALL ECHKZ (ECLARF)
      RETURN

      ENTRY       RARST (I1, I2, IA)
      CALL        PARST (I1, I2, IA)
      CALL ECHKZ (EARST)
      RETURN

      ENTRY       RARSN (I1, I2, IA)
      CALL        PARSN (I1, I2, IA)
      CALL ECHKZ (EARSN)
      RETURN

      ENTRY       RARAST (I1)
      CALL        PARAST (I1)
      CALL ECHKZ (EARAST)
      RETURN

      ENTRY       RRSID (I1, I2, I3, IA)
      CALL        PRSID (I1, I2, I3, IA)
      CALL ECHKZ (ERSID)
      RETURN

      ENTRY       RRAST (I1)
      CALL        PRAST (I1)
      CALL ECHKZ (ERAST)
      RETURN

      ENTRY       RREST (I1, I2, IA)
      CALL        PREST (I1, I2, IA)
      CALL ECHKZ (EREST)
      RETURN

      ENTRY       RRESN (I1, I2, IA)
      CALL        PRESN (I1, I2, IA)
      CALL ECHKZ (ERESN)
      RETURN

      ENTRY       RREPAN (I1,I2,I3,I4,I5,I6,I7,I8,IA)
      CALL        PREPAN (I1,I2,I3,I4,I5,I6,I7,I8,IA)
      CALL ECHKZ (EREPAN)
      RETURN

      ENTRY       RREPDE (I1,I2,I3,I4,I5,I6,I7,I8,IA)
      CALL        PREPDE (I1,I2,I3,I4,I5,I6,I7,I8,IA)
      CALL ECHKZ (EREPDE)
      RETURN

      ENTRY       RDSTAR (I1, I2, IA)
      CALL        PDSTAR (I1, I2, IA)
      CALL ECHKZ (EDSTAR)
      RETURN

      ENTRY       RDASAR (I1)
      CALL        PDASAR (I1)
      CALL ECHKZ (EDASAR)
      RETURN

      ENTRY       RDSNAR (I1, I2, IA)
      CALL        PDSNAR (I1, I2, IA)
      CALL ECHKZ (EDSNAR)
      RETURN

      ENTRY       RSERHM (I1)
      CALL        PSERHM (I1)
      CALL ECHKZ (ESERHM)
      RETURN

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/echkz                             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ECHKZ (FUNCID)

C  ECHKZ does post-processing after an error-signalling function has
C  been called.

C  Input parameter:
C    FUNCID: numeric identifier of function that signalled error 

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW,  MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE,GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW,  MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE,GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL   DUMRL(20)

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR, 
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80, 
     1                CONTAB(40)*150

      INTEGER    EESC,       EPREC,      EUREC
      PARAMETER (EESC  =180, EPREC =181, EUREC =182 )

      INTEGER    FUNCID, ITRIM

      IF (USRERR.EQ.1 .OR. USRERR.EQ.3) THEN
C  user-defined error handling
C  make bogus entry in error table to mark end of function effect
         CALL PERHND (2, EESC, -666)
      ELSE
C  system-defined error handling
C  make bogus entry in error file to mark end of function effect
         CALL PERLOG (2, EESC, ERRFIL)
      ENDIF

C  fill table of expected error-signalling function identifiers
      EFCNT = EFCNT+1
      EFID(EFCNT) = FUNCID

      IF (ITRIM(CURCON) .GT. 150) THEN
         CALL UNMSG ('ECHKZ detected CURCON of excessive length.')
      ENDIF

      IF (EFCNT .GT. 40) THEN
         CALL UNMSG ('ECHKZ detected CONTAB table overflow.')
      ENDIF
C  fill table of condition descriptions
      CONTAB(EFCNT) = CURCON

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/tstwan                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTWAN (WARNIN, WANACT)

C  TSTWAN is used to test that functions which issue a warning
C  take the correct action.

C  Input parameters:
C    WARNIN : logical variable indicating whether the function took
C             the correct action             
C    WANACT : description of correct action

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR, 
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80, 
     1                CONTAB(40)*150

      INTEGER   ITRIM
      LOGICAL   WARNIN
      CHARACTER MSG*300, FUNNAM*80, WANACT*(*), WBUF*300

      WBUF = WANACT
      IF (WANACT .NE. WBUF) THEN
         CALL UNMSG ('Action description passed to TSTWAN is too long.')
      ENDIF

      IF (INDEX (WBUF, 'should') .LT. 1) THEN
         CALL UNMSG ('Action description passed to TSTWAN does not ' //
     1               'contain "should": ' // WBUF)
      ENDIF

      CALL ERFUNM (EFID(EFCNT), FUNNAM)
      MSG = 'If ' // FUNNAM
      MSG(ITRIM(MSG)+2:) = 'issues a warning because ' // CURCON 
      MSG(ITRIM(MSG)+1:) = ', ' // WBUF

      CALL SETMSG (ERRSRS, MSG)
      CALL IFPF (WARNIN)

      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01/crest                             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
                      
      SUBROUTINE CREST
 
C   create a structure network
 
      REAL        XA(2), YA(2)
      DATA        XA/0.,0./, YA/0.5,0.5/
 
      CALL POPST (100)
      CALL PPL (2, XA, YA)
      CALL PEXST (101)
      CALL PCLST
      CALL POPST (101)
      CALL PSCHH (0.1)
      CALL PTX (0.55, 0.55, 'TEXT')
      CALL PCLST
 
      END

