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
