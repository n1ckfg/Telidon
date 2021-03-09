      SUBROUTINE AVARNM (ARNM)

C  This routine returns an integer to be used as the name of an
C  archive file in an <open archive file> statement.  This file
C  is empty upon open, i.e. contains no structures.

      SAVE

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

      INTEGER    ARNM, NUMOLD, OLDNMS(1000), IX, NAMCT
      CHARACTER  ARNMCH*12
      LOGICAL    EXFILE

      DATA       NUMOLD /0/

C  Avoid individual, global logical unit numbers, any previously
C  used logical units, and special Fortran units 5,6,7
      ARNM = 1 + MAX(INDLUN, GLBLUN, 10)
      DO 100 IX = 1,NUMOLD
         IF (OLDNMS(IX) .GE. ARNM) ARNM = ARNM+1
100   CONTINUE
      NUMOLD = NUMOLD+1
      OLDNMS(NUMOLD) = ARNM

C  Seek new file name and ensure that a named file is opened with
C  the logical unit number = ARNM
      ARNMCH = 'PVT00000.ARC'
      DO 200 NAMCT = 1,100
         WRITE (ARNMCH(4:8), '(I5.5)') NAMCT
         INQUIRE (FILE=ARNMCH, EXIST=EXFILE, ERR=606)
         IF (.NOT. EXFILE) GOTO 300
200   CONTINUE
      CALL UNMSG ('AVARNM unable to find name of non-existent file.')

600   CONTINUE
      CALL UNMSG ('Error encountered in AVARNM when opening ' //
     1            'archive file: ' // ARNMCH)

606   CONTINUE
      CALL UNMSG ('Error encountered in AVARNM when inquiring file: ' //
     1             ARNMCH)

300   CONTINUE
      OPEN (UNIT=ARNM, ERR=600, STATUS='unknown', FILE=ARNMCH)

      END
