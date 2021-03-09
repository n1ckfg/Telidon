C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 11.02/04                              *
C  *    TEST TITLE : Check prototypes and typedefs in      *
C  *                 phigs.h                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

      INTEGER    UFUT,UREF, IOERR, ITRIM, CMPLEN, KEY1, REFLEN
      INTEGER    ARBLOC, FUTLOC

      CHARACTER  CHBUF*6000, FUTARB*6000
      CHARACTER  ARB*10, MSG*300, REFREC*6000, FUTREC*6000, SRID*4
      PARAMETER (ARB = '{IMPL-DEP}')

801   FORMAT (A)

      CALL INITGL ('11.02/04')

      UFUT = MAX(20, INDLUN, GLBLUN) + 1
      UREF = UFUT+1

C  open input file under test (FUT)
      OPEN (UNIT=UFUT, IOSTAT=IOERR, FILE='phigs.hpns', RECL=4000,
     1      STATUS='OLD', FORM='FORMATTED')
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code opening input file ' //
     1          'phigs.hpns = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF
      REWIND (UNIT=UFUT, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code rewinding input file ' //
     1          'phigs.hpns = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF

C  open input reference file (REF)
      OPEN (UNIT=UREF, IOSTAT=IOERR, FILE='std_phigs.hpns', RECL=4000,
     1      STATUS='OLD', FORM='FORMATTED')
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code opening input file ' //
     1          'std_phigs.hpns = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF
      REWIND (UNIT=UREF, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code rewinding input file ' //
     1          'std_phigs.hpns = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF
      FUTREC = ' '
      REFREC = ' '

C  get next REF record
100   CONTINUE
      READ (UNIT=UREF, FMT=801, END=666, IOSTAT=IOERR) REFREC

C  set length and location to be compared within REFREC
      IF (REFREC(1:12) .EQ. 'extern void ') THEN
         CMPLEN = INDEX(REFREC, '(') - 1
         KEY1 = 13
         SRID = '1 12'
      ELSE
         CMPLEN = INDEX(REFREC, ' typedef') - 1
         KEY1 = 1
         SRID = '1 11'
      ENDIF

      IF (CMPLEN.LT.0) THEN
         CALL UNMSG ('Invalid record in std_phigs.hpns.')
      ENDIF
                 
      CALL SETMSG (SRID, 'The phigs.h file should contain a correct ' //
     1             'declaration for ' // REFREC(KEY1:CMPLEN) // '.')

C  Look for matching FUT record
120   CONTINUE
      IF (FUTREC(1:CMPLEN) .LT. REFREC(1:CMPLEN)) THEN
         READ (UNIT=UFUT, FMT=801, END=660, IOSTAT=IOERR) FUTREC
         GOTO 120
      ELSEIF (FUTREC(1:CMPLEN) .GT. REFREC(1:CMPLEN)) THEN
C  no equivalent name in FUT
         CALL FAIL
         CALL INMSG ('No declaration for ' // REFREC(KEY1:CMPLEN) //
     1               ' found in phigs.h.')
         GOTO 100
      ENDIF

C  got a name match between FUT and REF
200   CONTINUE
      REFLEN = ITRIM(REFREC)

C  If the statement has "typedef enum", insert the explicit marker
C  "{IMPL-DEP}" to allow extra enumeration values.
      IF (INDEX(REFREC, ' typedef enum{') .GT. 0) THEN
         CHBUF  = REFREC(1:REFLEN-2-CMPLEN) // ARB //
     1            REFREC(REFLEN-1-CMPLEN:REFLEN)
         REFREC = CHBUF
         REFLEN = REFLEN + LEN(ARB)
      ENDIF

C  put ARB at end for uniform treatment
      CHBUF  = REFREC(1:REFLEN) // ARB
      REFREC = CHBUF
      ARBLOC = INDEX(REFREC,ARB)
      IF (FUTREC(1:ARBLOC-1) .NE. REFREC(1:ARBLOC-1)) THEN
         CALL FAIL
         GOTO 100
      ENDIF
      FUTLOC = ARBLOC

C  Start loop to compare chunks of REFREC between occurrences of ARB
C  with chunks of FUTARB
      FUTARB = FUTREC
150   CONTINUE
C  discard chunks already matched
      CHBUF  = FUTARB(FUTLOC:)
      FUTARB = CHBUF
      CHBUF  = REFREC(ARBLOC + LEN(ARB):)
      REFREC = CHBUF

C  check if done
      IF (REFREC .EQ. ' ') THEN
         CALL IFPF (FUTARB .EQ. ' ')
         GOTO 100
      ENDIF

C  search for next REF chunk to be matched in FUTARB
      ARBLOC = INDEX(REFREC,ARB)
      FUTLOC = INDEX(FUTARB, REFREC(1:ARBLOC-1))
      IF (FUTLOC .LE. 0) THEN
         CALL FAIL
         GOTO 100
      ENDIF
      FUTLOC = FUTLOC + ARBLOC - 1
      GOTO 150

660   CONTINUE
      CALL FAIL
      CALL INMSG ('No more declarations to be checked; hit end of ' //
     1            'phigs.hpns.')

666   CONTINUE
      CLOSE (UNIT=UFUT)
      CLOSE (UNIT=UREF)

      CALL WINDUP
      END
