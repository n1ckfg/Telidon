C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 00/complt                             *
C  *    TEST TITLE : Completion check                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

C  FILE: COMPLT.FOR

C  This program checks the global message file for the presence of
C  an "End execution" message from every appropriate program in the
C  PHIGS validation suite.

      PROGRAM COMPLT

      INTEGER    GLBUN, PGMUN, IOERR, PTOT, FIRSTB, ENX
      INTEGER    LANGSW, WKCAT, PGMLIM
      PARAMETER (PGMLIM = 400)

      LOGICAL    GOTPGM(PGMLIM)

      CHARACTER  PGMNO(PGMLIM)*17, GLFNAM*60, PGMREC*100
      CHARACTER  MKEY*17, OICAT*2

800   FORMAT (A)

      PGMUN = 22
      OPEN (UNIT=PGMUN, FILE='pgm-char.prt', STATUS='OLD',
     1      FORM='FORMATTED', IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, 'OPEN failed for program title file, error code = ',
     1            IOERR
         STOP
      ENDIF

      REWIND (UNIT=PGMUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, 'REWIND failed for program title file, error ' //
     1            'code = ', IOERR
         STOP
      ENDIF

      PRINT *, 'Enter the name of the global message file '
      PRINT *, 'to be checked for completeness.'
      READ (*, 800) GLFNAM

      GLBUN = 21
      OPEN (UNIT=GLBUN, FILE=GLFNAM, STATUS='OLD', FORM='FORMATTED',
     1      IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, 'OPEN failed for global message file, error code = ',
     1            IOERR
         STOP
      ENDIF

      REWIND (UNIT=GLBUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, 'REWIND failed for global message file, error ' //
     1            'code = ', IOERR
         STOP
      ENDIF

110   CONTINUE
      PRINT *, 'Language binding? 1:Fortran, 2:C'
      READ  *, LANGSW
      IF (LANGSW.LT.1 .OR. LANGSW.GT.2) GOTO 110

120   CONTINUE
      PRINT *, 'Subset of PVT, based on primary workstation category?'
      PRINT *, '1:All tests, 2:OUTIN only, 3:OUTPUT only, 4:INPUT only'
      READ  *, WKCAT
      IF (WKCAT.LT.1 .OR. WKCAT.GT.4) GOTO 120

C  loop to fill PGMNO table from program title file
      PTOT = 0
200   CONTINUE
      READ (UNIT=PGMUN, FMT=800, END=266) PGMREC
      IF (INDEX(PGMREC, '/') .NE. 13) GOTO 200
      IF (PGMREC(1:1).NE.'0' .AND. PGMREC(1:1).NE.'1') GOTO 200

C  filter out unneeded workstation categories
      OICAT  = PGMREC(20:21)
      IF (WKCAT.EQ.2 .AND. OICAT.EQ.'nn') GOTO 200
      IF (WKCAT.EQ.3 .AND. OICAT.NE.'yn') GOTO 200
      IF (WKCAT.EQ.4 .AND. OICAT.NE.'ny') GOTO 200

C  filter out language-specific programs, assuming only Fortran or C 
C  tests exist, e.g. not Ada - no 11.03

      IF (LANGSW.EQ.1) THEN
C  This is Fortran - get rid of C modules
         IF (PGMREC(1:5).EQ.'11.02')    GOTO 200
         IF (PGMREC(1:8).EQ.'09.01.11') GOTO 200
         IF (PGMREC(1:8).EQ.'09.02.11') GOTO 200
      ENDIF

      IF (LANGSW.EQ.2) THEN
C  This is C - get rid of Fortran modules
         IF (PGMREC(1:5).EQ.'11.01')    GOTO 200
         IF (PGMREC(1:8).EQ.'09.01.10') GOTO 200
         IF (PGMREC(1:8).EQ.'09.02.10') GOTO 200
      ENDIF

      PTOT = PTOT+1
      IF (PTOT .GT. PGMLIM) THEN
         PRINT *, 'Number of programs exceeds internal table size;'
         PRINT *, 'increase PGMLIM.'
         STOP
      ENDIF

C  add entry to table of required programs
      FIRSTB = INDEX(PGMREC, ' ') - 1
      PGMNO(PTOT) = PGMREC(1:FIRSTB) // '/' // PGMREC(16:17)
      GOTPGM(PTOT) = .FALSE.
      GOTO 200

C  end loop: table of required programs now complete
266   CONTINUE
      CLOSE (UNIT=PGMUN)

C  loop to check message file against PGMNO table
300   CONTINUE
      READ (UNIT=GLBUN, FMT=800, END=366) PGMREC
      ENX = INDEX(PGMREC, 'End execution of PVT #')
      IF (ENX .LE. 0) GOTO 300

      MKEY = PGMREC(ENX + 22:)
      DO 310 ENX = 1,PTOT
         IF (PGMNO(ENX) .EQ. MKEY) THEN
C  found pgm#
            GOTPGM(ENX) = .TRUE.
            GOTO 300
         ENDIF
310   CONTINUE

C  not found - strange ...
      PRINT *, 'No reference record in the program title file was '
      PRINT *, 'found for message from program #', MKEY
      GOTO 300

366   CONTINUE

      DO 400 ENX = 1,PTOT
         IF (.NOT. GOTPGM(ENX)) THEN
            PRINT *, 'No "End execution" found for program #',
     1               PGMNO(ENX)
         ENDIF
400   CONTINUE

      CLOSE (UNIT=GLBUN)

      END

