C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 11.02/03                              *
C  *    TEST TITLE : Normalize prototypes and typedefs     *
C  *                 in phigs.h                            *
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

      INTEGER    IX, IY, UIN,UOUT, IOERR, NXTPOS, ITRIM, CC, BLEVEL
      INTEGER    C1,C2,C3, NNB, BUFLEN, LEADNB, NG
C  NG must be greater than the length of INBUF to signify not-found
      PARAMETER (NG = 99999)

      CHARACTER INBUF*10000, MSG*300, INREC*500, RSTREC*500
      CHARACTER THISCH*2, CHTOK(9)*1, ENDCH*1, CHBUF*10000

      DATA CHTOK / '[', ']', '{', '}', '(', ')', ';', ',', '*' /

801   FORMAT (A)

      CALL INITGL ('11.02/03')

      CALL INMSG ('This program does not perform any test cases, '  //
     1            'but merely normalizes the contents of phigs.hp ' //
     2            'as phigs.hpn for later comparison.')

      UIN  = MAX(20, INDLUN, GLBLUN) + 1
      UOUT = UIN+1

C  open output file
      OPEN (UNIT=UOUT, IOSTAT=IOERR, FILE='phigs.hpn', RECL=9000,
     1      STATUS='UNKNOWN', FORM='FORMATTED')
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code opening output file ' //
     1          'phigs.hpn = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF
      REWIND (UNIT=UOUT, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code rewinding output file ' //
     1          'phigs.hpn = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF

C  open input file
      OPEN (UNIT=UIN, IOSTAT=IOERR, FILE='phigs.hp', RECL=2000,
     1      STATUS='OLD', FORM='FORMATTED')
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code opening input file ' //
     1          'phigs.hp = ', IOERR, '.  Create phigs.hp as '    //
     2          'pre-processed version of phigs.h and re-execute.'
         CALL UNMSG (MSG)
      ENDIF
      REWIND (UNIT=UIN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code rewinding input file ' //
     1          'phigs.hp = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF

C  record as read in from input file
      INREC = ' '
C  the part of inbuf beyond the first statement
      RSTREC = ' '

C  try to get next statement in inbuf
100   CONTINUE
      INBUF = RSTREC

C  search inbuf for zero-level semi-colon
      BLEVEL = 0
      NXTPOS = 1

110   CONTINUE
      C1 = INDEX(INBUF(NXTPOS:), '{')
      IF (C1.EQ.0) C1 = NG

      C2 = INDEX(INBUF(NXTPOS:), '}')
      IF (C2.EQ.0) C2 = NG

      IF (BLEVEL.EQ.0) THEN
         C3 = INDEX(INBUF(NXTPOS:), ';')
         IF (C3.EQ.0) C3 = NG
      ELSE
         C3 = NG
      ENDIF
      CC = MIN(C1,C2,C3)

      IF (CC.GE.NG) GOTO 200

C  get absolute position of next interesting character
      CC = CC + NXTPOS - 1
C  where to start next search
      NXTPOS = CC+1
      THISCH = INBUF(CC:CC)

      IF (THISCH .EQ. '{') THEN
         BLEVEL = BLEVEL+1
         GOTO 110
      ELSEIF (THISCH .EQ. '}') THEN
         BLEVEL = BLEVEL-1
         GOTO 110
      ELSEIF (THISCH .EQ. ';') THEN
         GOTO 300
      ELSE
         CALL UNMSG ('Logic error searching for delimiter in: ' // 
     1                INBUF(1:300))
      ENDIF

C  not found - need more records in inbuf
200   CONTINUE

      READ (UNIT=UIN, FMT=801, END=601, IOSTAT=IOERR) INREC

      IF (IOERR .EQ. 0) THEN
C  skip any records left with leading "#" or blanks
         IF (INREC(1:1).EQ.'#' .OR. INREC.EQ.' ') GOTO 200
C  append INREC to INBUF
         NXTPOS = ITRIM(INBUF)
         IF (INBUF(NXTPOS:NXTPOS) .NE. '\') THEN
C  not C-continuation
            NXTPOS = NXTPOS+2
         ENDIF
         INBUF(NXTPOS:) = INREC

         GOTO 110
      ELSE
         WRITE (MSG, '(A,I6,A)') 'Error #', IOERR, 
     1                           ' occurred reading phigs.hp.'
         CALL UNMSG (MSG)
      ENDIF

601   CONTINUE
      IF (INBUF .NE. ' ') THEN
         CALL UNMSG ('Hit end-of-file in phigs.hp with partial ' //
     1               'statement: ' // INBUF(1:300))
      ENDIF
      GOTO 666

C  found zero-level semi-colon
300   CONTINUE

C  put rest of record in rstrec
      RSTREC = INBUF(CC+1:)
      INBUF(CC+1:) = ' '

C  INBUF now has full statement

CUSERMOD  convert HT,LF,VT,FF,CR to space
C  convert all white space to spaces - we'll take
C  these to be ASCII 9-13 ...
      DO 310 CC = 9,13
315      CONTINUE
         NXTPOS = INDEX(INBUF, CHAR(CC))
         IF (NXTPOS .NE. 0) THEN
            INBUF(NXTPOS:NXTPOS) = ' '
            GOTO 315
         ENDIF
310   CONTINUE

C  keep this statement?
      CC = LEADNB(INBUF)
      IF (INBUF(CC:CC+7) .EQ. 'typedef ' .OR.
     1    INBUF(CC:CC+6) .EQ. 'extern ') THEN
C        keep it
      ELSE
C        toss it
         GOTO 100
      ENDIF

C  delete all extra spaces
      NXTPOS = 1

320   CONTINUE
C  next non-blank
      NNB = LEADNB(INBUF(NXTPOS:))
      IF (NNB .LE. 0) GOTO 350
C  compress only if extra spaces found
      IF (NNB.GT.1) THEN
         CHBUF = INBUF(NXTPOS + NNB - 1:)
         INBUF(NXTPOS:) = CHBUF
      ENDIF
C  where is next blank?
      CC = INDEX(INBUF(NXTPOS:), ' ')
C  position one beyond next blank - next receiving position
      NXTPOS = NXTPOS + CC
      GOTO 320

350   CONTINUE

C  delete spaces adjacent to character-tokens: []{}();,*
      BUFLEN = ITRIM(INBUF)
      DO 340 IX = 1,9
      DO 345 IY = 0,1
         IF (IY .EQ. 0) THEN
            THISCH = ' ' // CHTOK(IX) 
         ELSE
            THISCH = CHTOK(IX) // ' '
         ENDIF

355      CONTINUE
         CC = INDEX(INBUF, THISCH)
         IF (CC.LE.0 .OR. CC.GE.BUFLEN) GOTO 345
         INBUF(CC+IY:) = INBUF(CC+IY+1:) 
         BUFLEN = BUFLEN-1
         GOTO 355

345   CONTINUE
340   CONTINUE

C  INBUF now normalized
      BUFLEN = ITRIM(INBUF)

C  if typedef, swing type name up to front
      IF (INBUF(1:7) .NE. 'typedef') GOTO 400

C  search backwards for "}", "*" or " "
      DO 370 IX = BUFLEN,1,-1
         ENDCH = INBUF(IX:IX)
         IF (ENDCH.EQ.'}' .OR. ENDCH.EQ.'*' .OR. ENDCH.EQ.' ') GOTO 380
370   CONTINUE
      CALL UNMSG ('Could not find last "}", "*", or " " in typedef: ' //
     1            INBUF(1:300))

380   CONTINUE
      CHBUF = INBUF(IX+1:BUFLEN-1) // ' ' // INBUF(1:BUFLEN)
      BUFLEN = BUFLEN + BUFLEN - IX
      INBUF = CHBUF

400   CONTINUE
      WRITE (UNIT=UOUT, FMT=801) INBUF(1:BUFLEN)

      GOTO 100

666   CONTINUE
      CLOSE (UNIT=UOUT)
      CLOSE (UNIT=UIN)

      CALL WINDUP
      END
