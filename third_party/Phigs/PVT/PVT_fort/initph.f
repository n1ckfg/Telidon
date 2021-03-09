C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 00/initph                             *
C  *    TEST TITLE : PVT System Initialization             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

C  FILE: INITPH.FOR

C  This program is run once, before all the other tests in the system.
C  Its only purpose is to initialize a system-configuration file which
C  will be used by all subsequent tests to control their operation.

C  Dictionary of variables used globally throughout PVT.
C
C  Variable   Type*   Description
C  --------   ----    -----------
C  conid      S  I    Connection identifier, for <open workstation>
C  ctlhnd     D  I    Tell PERHND whether to abort (0) or return (1)
C  dumch      S  C    Dummy character variables for future use
C  dumint     S  I    Dummy integer variables for future use
C  dumrl      S  R    Dummy real variables for future use
C  errind     D  I    Error indicator, returned from inquire functions
C  errfil     S  I    PHIGS error file, for <open phigs>
C  errsig     D  I    Signalled error code returned by PERHND
C  errsw      S  I    Indicates whether to send messages to operator
C  funcid     D  C    Function signalling the error, returned by PERHND
C  glberr     S  C    Absolute name of global message file
C  glblun     S  I    Logical unit number of global message file
C  ierrct     D  I    Count of errors detected by test
C  iflerr     S  I    Controls writing of messages to message files
C  indlun     S  I    Logical unit number of individual message file
C  maxlin     S  I    Maximum characters per line in messages
C  memun      S  I    Number of memory units, for <open phigs>
C  passsw     S  I    Controls writing/suppression of pass-messages
C  pident     D  C    Unique program identifier - hierarchical number
C  testct     D  I    Count of conditions tested so far within program
C  tstmsg     D  C    Text for next condition to be reported.
C  unerr      D  I    Count of unanticipated errors detected by test
C  wkid       S  I    Workstation id, for <open workstation>
C  wtype      S  I    Workstation type, for <open workstation>
C  rlseed     S  R    Seed for random number generator
C
C  * S: Static value read from configuration file
C    D: Dynamic variable, altered during test execution
C
C    I: Integer
C    C: Character
C    R: Real

      PROGRAM INITPH

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

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      INTEGER    EESC,       EPREC,      EUREC
      PARAMETER (EESC=180,   EPREC =181, EUREC =182 )

C definitions for /DIALOG/ variables in SETDLG subroutine

C these are the only two variables from the error handling common areas
C that need to be set by INITPH:
      INTEGER         ERNMSW
      CHARACTER       ERRMRK*20

C limit for number of multiple workstations to be tested.
      INTEGER    MAXWS
      PARAMETER (MAXWS = 100)

      INTEGER    MWKID(MAXWS), MCONID(MAXWS), MWTYPE(MAXWS), ITRIM
      INTEGER    IOERR, LUN, MAXOP, IWK, NWKSAV, LPRT, NXTCH, ANS

      CHARACTER  SYSFIL*60, SUFFIX*35, PRTFIL*60, SUCMSG(0:2)*48
      CHARACTER  MSGDST*40, DOTMSG(3)*15, DINMSG(2)*21, ERRPRF*30
      CHARACTER  DLGLOC(2)*7, RSEED*30, NOTSTR*5, ERRSEP*60

      INTEGER    PICSTR, TXCI, PSZ
      REAL       XA(5),YA(5), RLSEED

      DATA SUCMSG / 'Never generate success messages.',
     1              'Always generate success messages.',
     2              'Operator option to generate success messages.' /

      DATA DOTMSG / 'Fortran print', 'PHIGS message', 'PHIGS text' /

      DATA DINMSG / 'Fortran read', 'PHIGS request string' /

      DATA DLGLOC / 'bottom.', 'right.' /

      DATA NOTSTR / ' not ' /

C *********************************************************
C
CUSERMOD  NOTE: The following must be initialized to absolute file
CUSERMOD  name of the system configuration file.  This must be
CUSERMOD  customized for each installation.  See also the INITGL
CUSERMOD  and MULTWS subroutines in the subroutine library, which
CUSERMOD  read the file.
C
C *********************************************************

C real system configuration file
      SYSFIL = 'INITPH.DAT'
C human-readable version
      PRTFIL = 'INITPH.PRT'

800   FORMAT(A)

      PRINT *,
     1   'This program creates a system configuration file which is'
      PRINT *,
     1   'used by all subsequent PHIGS validation programs.'
      PRINT *,
     1   'Please answer all questions carefully.  All responses should'
      PRINT *,
     1   'be in the format of an integer, except as noted.'
      PRINT *, ' '
      PRINT *,
     1   '*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** '
      PRINT *, ' '
      PRINT *, 'PHIGS-error-file number to be passed to <open phigs>'
      PRINT *, '(must be a readable file, do not route to printer) ?'
      READ  *, ERRFIL
      PRINT *, 'Memory units to be passed to <open phigs>'
      PRINT *, '(-1 to use implementation-defined value)?'
      READ  *, MEMUN

15    CONTINUE
      PRINT *, 'Enter the number of accessible workstations for'
      PRINT *, 'this implementation.  (To be accessible, it is'
      PRINT *, 'required only that a successful open may be'
      PRINT *, 'performed on the workstation, NOT that all the'
      PRINT *, 'accessible workstations may be opened simultaneously.)'

      READ  *, MAXOP
      IF (MAXOP .LT. 1) THEN
         PRINT *, 'Must allow at least 1 open workstation.'
         GOTO 15
      ENDIF

      IF (MAXOP .GT. MAXWS) THEN
         PRINT *, 'Will store information about 1st ', MAXWS,
     1            ' workstations.'
         PRINT *, ' '
         NWKSAV = MAXWS
      ELSE
         NWKSAV = MAXOP
      ENDIF

      SUFFIX = ' to be passed to open_workstation?'
      PRINT *, 'Workstation #1 is the default workstation for all'
      PRINT *, 'the PHIGS tests which use a single non-metafile'
      PRINT *, 'workstation.  Other workstations (2 - n) are used'
      PRINT *, 'for multiple-workstation tests.'

      DO 20 IWK = 1, NWKSAV
         PRINT *, '----- For workstation #',  IWK, ':'
         PRINT *, 'Workstation identifier' // SUFFIX
         READ  *, MWKID (IWK)
         PRINT *, 'Connection identifier' // SUFFIX
         READ  *, MCONID (IWK)
         PRINT *, 'Workstation type' // SUFFIX
         READ  *, MWTYPE (IWK)
20    CONTINUE
      WKID  = MWKID (1)
      CONID = MCONID (1)
      WTYPE = MWTYPE (1)

100   CONTINUE
      PRINT *, 'Indicate whether run-time messages are to be ',
     1         'generated for successful handling of conditions.'
      PRINT *, '0 - ' // SUCMSG(0)
      PRINT *, '1 - ' // SUCMSG(1)
      PRINT *, '2 - ' // SUCMSG(2)
      READ  *, PASSSW
      IF (PASSSW .LT. 0 .OR. PASSSW .GT. 2) THEN
         PRINT *, 'Invalid response - re-enter.'
         GOTO 100
      ENDIF

200   CONTINUE
      PRINT *, 'Indicate whether run-time messages are to be sent to ',
     1         'the operator.'
      PRINT *, '0 - Do not send messages to operator.'
      PRINT *, '1 - Send messages to operator.'
      READ  *, ERRSW
      IF (ERRSW .LT. 0 .OR. ERRSW .GT. 1) THEN
         PRINT *, 'Invalid response - re-enter.'
         GOTO 200
      ENDIF

300   CONTINUE
      PRINT *, 'Indicate which files are destinations for ',
     1         'run-time messages.'
      PRINT *, '0 - Do not send messages to any file.'
      PRINT *, '1 - Append messages to end of global file.'
      PRINT *, '2 - Send messages to program-specific file.'
      PRINT *, '3 - Both 1 and 2.'
      READ  *, IFLERR
      IF (IFLERR .LT. 0 .OR. IFLERR .GT. 3) THEN
         PRINT *, 'Invalid response - re-enter.'
         GOTO 300
      ENDIF

C default units
      GLBLUN = 21
      INDLUN = 22

      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3) THEN
C set up global message file

C name of global message file
         PRINT *, 'Absolute file name for the global message file'
         PRINT *, '(Character input, not integer)?'
         READ (*, 800) GLBERR

         PRINT *, 'Logical unit number to be used for ',
     1            'global message file?'
         READ  *, GLBLUN
C create global message file
         OPEN  (UNIT=GLBLUN, IOSTAT=IOERR, FILE=GLBERR, STATUS='NEW',
     1          FORM='FORMATTED')
         IF (IOERR .NE. 0) THEN
            PRINT *, 'Abort.  Error code for OPEN of global message ',
     1               'file = ', IOERR
            GOTO 666
         ENDIF
         WRITE (UNIT=GLBLUN, FMT=801)
801      FORMAT (' GLOBAL MESSAGE FILE',/,' .',/,' .',/,' .')
         CLOSE  (UNIT=GLBLUN)
      ENDIF

      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3) THEN
C set up individual message file
         PRINT *, 'Logical unit number to be used for ',
     1            'individual message file?'
         READ  *, INDLUN
      ENDIF

400   CONTINUE
      PRINT *, 'Maximum characters per line in messages (40-300)?'
      READ  *, MAXLIN
      IF (MAXLIN .LT. 40 .OR. MAXLIN .GT. 300) THEN
         PRINT *, 'Response out of range - re-enter.'
         GOTO 400
      ENDIF

C set up for error handling

404   CONTINUE
      PRINT *, 'Indicate whether the implementation allows the error ',
     1         'file to be '
      PRINT *, 'explicitly opened and named by the application ',
     1         'program prior to '
      PRINT *, 'execution of <open phigs>: 1-yes, 2-no.'
      READ  *, ERNMSW
      IF (ERNMSW.LT.1 .OR. ERNMSW.GT.2) THEN
         PRINT *, 'Invalid response - re-enter.'
         GOTO 404
      ENDIF

      PRINT *, 'If the error messages written by the system error ',
     1         'handler all '
      PRINT *, 'contain a special string by which they can be ',
     1         'individuated '
      PRINT *, '(such as "%PHIGS-ERROR:"), enter that string.  ',
     1         'If not, enter blanks.'
      READ (*, 800) ERRMRK

C write out error message to serve as separator of function invocations
      IF (ERNMSW.EQ.1) THEN
         ERRSEP = 'errsep.erf'
         OPEN (UNIT=ERRFIL, IOSTAT=IOERR, FILE=ERRSEP, STATUS='UNKNOWN',
     1         FORM='FORMATTED')
         IF (IOERR .NE. 0) THEN
            PRINT *, 'Abort.  Error code for ',ERRSEP, ' OPEN = ',IOERR
            GOTO 666
         ENDIF
         REWIND ERRFIL
      ELSE
         PRINT *, '********************************************'
         PRINT *, 'Cannot explicitly name file holding error ' //
     1            'separator; ensure that un-named'
         PRINT *, 'error file is re-named to "errsep.erf".'
         PRINT *, '********************************************'
      ENDIF

C set up parameters for interactive tests:
410   CONTINUE
C set up bogus values
      DOUTYP = -1
      DTCLIM = -1
      DSIZE  = -1.0
      EFRAC  = -1.0
      DINTYP = -1
      DSTDNR = -1
      MTRPDC = -1.0

415   CONTINUE
      PRINT *, 'If the random number function is to generate a ' //
     1         'pseudo-random'
      PRINT *, 'sequence (allowing exactly repeatable test ' //
     1         'results), enter'
      PRINT *, 'a real value between 0.1 and 0.9 as a seed; any ' //
     1         'other value'
      PRINT *, 'will generate an unpredictable sequence.'
      READ (*, 800) RSEED
      CALL PRSRL (RSEED, RLSEED, IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, 'Incorrect format for real number; re-enter.'
         GOTO 415
      ENDIF

      PRINT *, 'Is the primary workstation to be tested ',
     1         'interactively as category'
      PRINT *, 'OUTPUT or OUTIN (1-yes, 2-no)?'
      READ  *, ANS
      IF     (ANS .EQ. 1) THEN
C OK - fall thru to set-up routine
      ELSEIF (ANS .EQ. 2) THEN
         GOTO 450
      ELSE
C invalid response
         GOTO 410
      ENDIF

420   CONTINUE
      PRINT *, 'Method for prompting operator: 1-Fortran print, ' 
      PRINT *, '2-PHIGS <message>, 3-PHIGS <text>?'
      READ  *, DOUTYP

      IF (DOUTYP.EQ.1 .OR. DOUTYP.EQ.2) THEN
         PRINT *, 'Maximum number of characters per line in ',
     1            'interactive prompts?'
         READ  *, DTCLIM
      ELSEIF (DOUTYP.EQ.3) THEN
C        OK - DTCLIM to be set automatically when prompt is generated
      ELSE
         GOTO 420
      ENDIF

C set up input
430   CONTINUE
      PRINT *, 'Method for operator responses: 1-Fortran read, ' 
      PRINT *, '2-PHIGS <request string>?'
      READ  *, DINTYP

      IF (DINTYP .EQ. 1) THEN    
         DSTDNR = 1
      ELSEIF (DINTYP .EQ. 2) THEN
         PRINT *, 'Device number for <request string>?'
         READ  *, DSTDNR
      ELSE
         GOTO 430
      ENDIF

435   CONTINUE
      IF (DINTYP.EQ.2 .OR. DOUTYP.EQ.3) THEN
         PRINT *, 'Dialogue area: 1-dialogue at bottom, ',
     1            '2-dialogue at right, '
         PRINT *, '3-toggle picture and dialogue?'
         READ  *, SCRMOD
         IF (SCRMOD.EQ.1 .OR. SCRMOD.EQ.2) THEN
            PRINT *, 'Dialogue area as percentage of screen (1-99)?'
            READ  *, DSIZE
            IF (DSIZE.LT.1 .OR. DSIZE.GT.99) GOTO 435
            DSIZE = DSIZE/100
         ELSEIF (SCRMOD.EQ.3) THEN
            DSIZE = 1.0
         ELSE
            GOTO 435
         ENDIF

C  set EFRAC
         IF (DINTYP.EQ.2 .AND. DOUTYP.EQ.3) THEN
            PRINT *, 'Echo area as percentage of dialogue area (1-99)?'
            READ  *, EFRAC
            IF (EFRAC .LT. 1 .OR. EFRAC .GT. 99) GOTO 435
            EFRAC = EFRAC/100
         ELSEIF (DINTYP.EQ.2) THEN
C  <request string> only
            EFRAC = 0.99
         ELSE
C  <text> only
            EFRAC = 0.01
         ENDIF
      ELSE
C  no dialogue area
         SCRMOD = 0
         DSIZE  = 0.0
         EFRAC  = 0.0
      ENDIF

440   CONTINUE
      PRINT *, 'For meters per DC unit on the primary workstation: '
      PRINT *, '1-enter number directly, 2-use PHIGS to measure ' 
      PRINT *, 'right now on the primary workstation?'
      READ  *, ANS

      IF (ANS.LT.1 .OR. ANS.GT.2) GOTO 440

C  Create an error file with a single error message; this otherwise unused
C  message will be used as a separator when later tests analyze the
C  contents of error files generated by the system.  Therefore, this
C  single-message error file must be readable by those tests, under the
C  name "errsep.erf".
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL PERLOG (2, EESC, ERRFIL)

      IF (ANS .EQ. 1) THEN
         PRINT *, 'For primary workstation, how many meters per ',
     1            'DC unit?'
         READ  *, MTRPDC
      ELSE
C set-up of workstation and dialogue area
         PICSTR = 101
         TXCI = 1
         CALL SETDLG (PICSTR, 801,TXCI)

         CALL POPST (PICSTR)
         CALL PSVWI (1)
         CALL SETRVS ('0.1,0.9', XA, PSZ)
         CALL SETRVS ('0.1,0.9', YA, PSZ)
         CALL PPL (PSZ, XA,YA)
         CALL SETRVS ('0.88,0.92', XA, PSZ)
         CALL SETRVS ('0.92,0.88', YA, PSZ)
         CALL PPL (PSZ, XA,YA)
         CALL SETRVS ('0.08,0.12', XA, PSZ)
         CALL SETRVS ('0.12,0.08', YA, PSZ)
         CALL PPL (PSZ, XA,YA)
         CALL DRLVAL ('Please enter length of the diagonal line ' //
     1                'segment, expressed in centimeters (e.g. '  //
     2                '"25.4" if exactly 10 inches).', MTRPDC)
         MTRPDC = (MTRPDC / (100 * 0.8 * SQRT(2.0))) * WCPDC
         CALL PCLST
         CALL PCLWK (WKID)
      ENDIF
      CALL PCLPH

C interactive parameters set by now
450   CONTINUE

C Guessing at a good logical unit number to open SYSFIL (config file)
      LUN = MAX(GLBLUN,INDLUN) + 1

      ERRPRF = 'INITPH abort.  Error code for '

      OPEN  (UNIT=LUN, IOSTAT=IOERR, FILE=SYSFIL, STATUS='UNKNOWN',
     1       FORM='UNFORMATTED')
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'OPEN of configuration file = ', IOERR
         STOP
      ENDIF

      REWIND (UNIT=LUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'REWIND of configuration file = ', IOERR
         STOP
      ENDIF

C write info to system configuration file
      WRITE (UNIT=LUN, IOSTAT=IOERR) ERNMSW, ERRMRK
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'WRITE1 of configuration file = ', IOERR
         STOP
      ENDIF

      WRITE (UNIT=LUN, IOSTAT=IOERR) DOUTYP, DTCLIM, DINTYP, DSTDNR,
     1      DSIZE, EFRAC, SCRMOD, MTRPDC
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'WRITE2 of configuration file = ', IOERR
         STOP
      ENDIF

      WRITE (UNIT=LUN, IOSTAT=IOERR) ERRFIL, IFLERR, PASSSW, ERRSW,
     1      MAXLIN, CONID, MEMUN, WKID, WTYPE, GLBERR, GLBLUN, INDLUN,
     2      NWKSAV, RLSEED
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'WRITE3 of configuration file = ', IOERR
         STOP
      ENDIF

      DO 500 IWK = 1,NWKSAV
         WRITE (UNIT=LUN, IOSTAT=IOERR)
     1          MWKID (IWK), MCONID (IWK), MWTYPE  (IWK)
         IF (IOERR .NE. 0) THEN
            PRINT *, ERRPRF, 'WRITE of workstation #', IWK,
     1               'to configuration file = ', IOERR
            STOP
         ENDIF
500   CONTINUE

      CLOSE (UNIT=LUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, 'Abort.  Error code for ', SYSFIL, ' CLOSE = ', IOERR
         GOTO 666
      ENDIF
      PRINT *, 'Wrote configuration information to: ', SYSFIL

C now write printable version for user-inspection
      LPRT = MAX(GLBLUN,INDLUN) + 2
      OPEN  (UNIT=LPRT, IOSTAT=IOERR, FILE=PRTFIL, STATUS='UNKNOWN',
     1       FORM='FORMATTED')
      IF (IOERR .NE. 0) THEN
         PRINT *, 'Abort.  Error code for ', PRTFIL, ' OPEN = ', IOERR
         GOTO 666
      ENDIF
      REWIND LPRT

C parms for open-phigs
      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Parameters to be ' //
     1       'passed to OPEN PHIGS:'
      IF (IOERR .NE. 0) GOTO 660
      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) '   Error-file number = ',
     1       ERRFIL
      IF (IOERR .NE. 0) GOTO 660
      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) '   Memory units = ', MEMUN
      IF (IOERR .NE. 0) GOTO 660

C parms for open-workstation
      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Recorded number of ' //
     1       'accessible workstations = ', NWKSAV
      DO 310 IWK = 1,NWKSAV
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Parameters to be ' //
     1          'passed to OPEN WORKSTATION for wkst #', IWK, ':'
         IF (IOERR .NE. 0) GOTO 660
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) '   Workstation ' //
     1          'identifier = ', MWKID (IWK)
         IF (IOERR .NE. 0) GOTO 660
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) '   Connection ' //
     1          'identifier = ', MCONID (IWK)
         IF (IOERR .NE. 0) GOTO 660
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) '   Workstation ' //
     1          'type = ',  MWTYPE (IWK)
         IF (IOERR .NE. 0) GOTO 660
310   CONTINUE

      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Random generator seed = ',
     1       RSEED
      IF (IOERR .NE. 0) GOTO 660

      IF (DOUTYP .EQ. -1) GOTO 330

      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Interactive output to ',
     1      'operator via ', DOTMSG(DOUTYP)
      IF (IOERR .NE. 0) GOTO 660
      IF (DOUTYP .EQ. 1 .OR. DOUTYP .EQ. 2) THEN
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Maximum characters ',
     1      'per line in interactive messages = ', DTCLIM
         IF (IOERR .NE. 0) GOTO 660
      ENDIF

      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Interactive input from ',
     1      'operator via ', DINMSG(DINTYP)
      IF (IOERR .NE. 0) GOTO 660
      IF (DINTYP .EQ. 2) THEN
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Standard string ',
     1      'device #', DSTDNR
         IF (IOERR .NE. 0) GOTO 660
      ENDIF

      IF (SCRMOD .EQ. 0) THEN
C        do nothing
      ELSEIF (SCRMOD .EQ. 3) THEN
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR)
     1         'Dialogue via toggled screen.'
         IF (IOERR .NE. 0) GOTO 660
      ELSE
C  dialog on split screen
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR)
     1         'Split screen, dialogue at ', DLGLOC(SCRMOD)
         IF (IOERR .NE. 0) GOTO 660
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Dialog area as ',
     1         'fraction of screen = ', DSIZE
         IF (IOERR .NE. 0) GOTO 660
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Echo area as ',
     1         'fraction of dialogue area = ', EFRAC
         IF (IOERR .NE. 0) GOTO 660
      ENDIF

      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Meters per DC unit = ',
     1   MTRPDC
      IF (IOERR .NE. 0) GOTO 660

330   CONTINUE
      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) SUCMSG(PASSSW)
      IF (IOERR .NE. 0) GOTO 660

      IF (ERRSW .EQ. 0) THEN
         MSGDST = ' '
         NXTCH = 1
      ELSE
         MSGDST = 'operator'
         NXTCH = 9
      ENDIF
      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3 ) THEN
         MSGDST (NXTCH:) = ', global-file'
         NXTCH = NXTCH + 13
      ENDIF
      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3 ) THEN
         MSGDST (NXTCH:) = ', individual-file'
         NXTCH = NXTCH + 17
      ENDIF
      IF (MSGDST .EQ. ' ') MSGDST = 'None.'
      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Message destination: ' //
     1       MSGDST
      IF (IOERR .NE. 0) GOTO 660

      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3 ) THEN
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Global file unit ' //
     1          'number = ', GLBLUN, ', filename = ' // GLBERR
         IF (IOERR .NE. 0) GOTO 660
      ENDIF

      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3 ) THEN
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Individual file ' //
     1          'unit number = ', INDLUN
         IF (IOERR .NE. 0) GOTO 660
      ENDIF

      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Maximum characters ' //
     1       'per line in messages = ',  MAXLIN
      IF (IOERR .NE. 0) GOTO 660

      WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Error file may' // 
     1       NOTSTR(1:ERNMSW*4-3) // 'be explicitly opened and named.'
      IF (IOERR .NE. 0) GOTO 660

      IF (ERRMRK .EQ. ' ') THEN
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Error messages do ' //
     1          'not contain an identifying string.'
      ELSE
         WRITE (UNIT=LPRT, FMT=*, IOSTAT=IOERR) 'Identifying string ' //
     1         'for error messages: "' // ERRMRK(1:ITRIM(ERRMRK)) // '"'
      ENDIF
      IF (IOERR .NE. 0) GOTO 660

      CLOSE (UNIT=LPRT, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, 'Abort.  Error code for ', PRTFIL, ' CLOSE = ', IOERR
         GOTO 666
      ENDIF
      PRINT *, 'Wrote printable configuration information to: ', PRTFIL
      GOTO 666

660   CONTINUE
      PRINT *, 'Abort.  Error code for ', PRTFIL, ' WRITE = ', IOERR

666   CONTINUE
      END
