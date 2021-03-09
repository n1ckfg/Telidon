      SUBROUTINE INITGL (IDENT)

C  Initgl accepts the identifying hierarchical number of the test
C  program and initializes the GLOBAL COMMON variables, mostly from
C  values read from the INITPH.DAT file.  It then opens message
C  files as indicated by control variables.  This routine is
C  normally the first thing called by a test program.

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

      COMMON /OPCOMM/ OPHEAD
      CHARACTER  OPHEAD*300

      COMMON /RANCTL/ RLSEED
      REAL            RLSEED

      INTEGER    ITRIM, LUN, IOERR, IT, NWKSAV, IX

      CHARACTER  IDENT*(*), FILENM*60, INDERR*30
      CHARACTER  DUMREC*300, ANS*1, ERRPRF*30, IDCHAR*1

C check validity of IDENT
      IT = ITRIM(IDENT)
      IF (IT.LT.5) GOTO 60
      DO 50 IX = 1, IT
         IDCHAR = IDENT(IX:IX)
         IF (IX .EQ. IT-2) THEN
            IF (IDCHAR .NE. '/') GOTO 60
         ELSEIF (MOD(IX,3) .EQ. 0) THEN
            IF (IDCHAR .NE. '.') GOTO 60
         ELSE
            IF (IDCHAR.LT.'0' .OR. IDCHAR.GT.'9') GOTO 60
         ENDIF
50    CONTINUE
      GOTO 70

60    CONTINUE
      PRINT *, 'Format of program-identifier is invalid: ', IDENT
      STOP

70    CONTINUE

C *** *** *** ***  Initialize common for operator comment
      OPHEAD = 'NO TEST CASES YET:'

C *** *** *** ***  Initialize global common

C initialize global common from input parameter
      PIDENT = IDENT
      TSTMSG = ' '

C set error and test counts to 0
      UNERR  = 0
      IERRCT = 0
      TESTCT = 0

C set handler-control to default (perhnd reports and aborts).
      CTLHND = 0

C initialize global common from system configuration file

C filename and logical unit number for system configuration file.

C **********************************************************
C
CUSERMOD  NOTE: The following must be initialized to the absolute file
CUSERMOD  name for the system configuration file.  This must be
CUSERMOD  customized for each installation.  See the MULTWS
CUSERMOD  subroutine, immediately below, and also the INITPH
CUSERMOD  program which writes the file.
C
C **********************************************************

      FILENM = '/home/cugini/pvt/work/v2.1/INITPH.DAT'

C *********************************************************
C
CUSERMOD  End of customization
C
C *********************************************************

C  Use random unit number - no other files open yet, so should be OK.
      LUN = 21

      ERRPRF = 'INITGL abort.  Error code for '

      OPEN (UNIT=LUN, IOSTAT=IOERR, FILE=FILENM, STATUS='OLD',
     1      FORM='UNFORMATTED')
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'OPEN of configuration file = ', IOERR
         STOP
      ENDIF

C  position at beginning of file
      REWIND (UNIT=LUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'REWIND of configuration file = ', IOERR
         STOP
      ENDIF

      READ (UNIT=LUN, IOSTAT=IOERR) ERNMSW, ERRMRK
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'READ1 of configuration file = ', IOERR
         STOP
      ENDIF

      READ (UNIT=LUN, IOSTAT=IOERR) DOUTYP, DTCLIM, DINTYP, DSTDNR,
     1      DSIZE, EFRAC, SCRMOD, MTRPDC
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'READ2 of configuration file = ', IOERR
         STOP
      ENDIF

      READ (UNIT=LUN, IOSTAT=IOERR) ERRFIL, IFLERR, PASSSW, ERRSW,
     1     MAXLIN, CONID, MEMUN, WKID, WTYPE, GLBERR, GLBLUN, INDLUN,
     2     NWKSAV, RLSEED
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'READ3 of configuration file = ', IOERR
         STOP
      ENDIF

      CLOSE (UNIT=LUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'CLOSE of configuration file = ', IOERR
         STOP
      ENDIF

C *** *** ***  Initialize error-handling common area   *** *** ***

C  set these to invalid values to make sure error handling routines
C  initialize them:
      ERRCOM = -1
      FUNCOM = -1
      FILCOM = -1
      EXPSIZ = -1
      DO 80 IT = 1,10
         EXPERR(IT) = -1
80    CONTINUE
      DO 90 IT = 1,200
         ERRSAV(IT) = -1
         FUNSAV(IT) = -1
         FILSAV(IT) = -1
90    CONTINUE

      ERRSRS = 'Un-initialized'
      ERFLNM = 'Un-initialized'
      CURCON = 'Un-initialized'
      CONTAB(1) =  'Un-initialized'

C  normal mode: NOT testing error handling.
      USRERR = 0

C *** *** *** ***  Initialize global common from operator, if necessary

      IF (PASSSW .EQ. 2) THEN
         CALL OPYN ('Generate run-time messages for successful ' //
     1              'conditions?', ANS)
         IF (ANS .EQ. 'y') THEN
            PASSSW = 1
         ELSE
            PASSSW = 0
         ENDIF
      ENDIF

C *** *** *** ***  Open message files, as needed.

      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3) THEN
C open global file for append
         OPEN (UNIT=GLBLUN, IOSTAT=IOERR, FILE=GLBERR, STATUS='OLD',
     1         FORM='FORMATTED')
         IF (IOERR .NE. 0) THEN
            PRINT *, ERRPRF, 'OPEN of global file = ', IOERR
            STOP
         ENDIF

800      FORMAT (A)

C *********************************************************
C
CUSERMOD  To make append work more efficiently, if desired, change the
CUSERMOD  following to system-specific magic code which will open the
CUSERMOD  global message file and position it after the last record,
CUSERMOD  to allow new records to be added.  The routine above seems
CUSERMOD  to be the only Fortran-standard way to do it.
C
C *********************************************************

C position at end-of-file
100      CONTINUE
         READ (UNIT=GLBLUN, FMT=800, IOSTAT=IOERR, END=200) DUMREC
         IF (IOERR .NE. 0) THEN
            PRINT *, ERRPRF, 'READ of global file = ', IOERR
            STOP
         ENDIF
         GOTO 100

200      CONTINUE
         BACKSPACE (UNIT=GLBLUN)

C *********************************************************
C
CUSERMOD  End of customization
C
C *********************************************************

      ENDIF

      IT = ITRIM(PIDENT)
      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3) THEN
C create individual message file
C generate file name
         INDERR = 'p' // PIDENT(IT-1:IT) // '.msg'
         OPEN (UNIT=INDLUN, IOSTAT=IOERR, FILE=INDERR, STATUS='UNKNOWN',
     1         FORM='FORMATTED')
         REWIND INDLUN
         IF (IOERR .NE. 0) THEN
            PRINT *, ERRPRF, 'OPEN of individual file = ', IOERR
            STOP
         ENDIF

      ENDIF

C Broadcast beginning-of-program message

      CALL BRDMSG ('SY: ------- Begin execution of PVT #' //
     1             PIDENT(1:IT) // ', version 2.2')

C  Following statement is never executed, but may help cause PERHND
C  to be linked into executable module, as well as routines called
C  directly by PVT version of PERHND.
      IF (PIDENT .EQ. 'A bogus string value') THEN
         CALL UNMSG  ('This should never happen.')
         CALL NCMSG  ('This should never happen.')
         CALL SIGMSG (0, 'bogus function name', DUMREC)
         CALL ERFUNM (-1, FUNCID)
         CALL PERHND (0, 0, 0)
      ENDIF

666   CONTINUE
      END
