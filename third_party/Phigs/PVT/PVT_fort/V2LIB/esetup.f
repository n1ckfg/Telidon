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
