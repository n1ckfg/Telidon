      SUBROUTINE SETMSG (SRLIST, MSG)

C  Setmsg parses the srlist (a list of semantic requirements), accepts an
C  associated message describing the condition about to be tested, and
C  sets the COMMON variable tstmsg to a resulting value, to be issued by
C  either pass or fail, whichever is next executed.

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

      INTEGER    ITRIM, IT, LOC, LIM, IDIG

      CHARACTER  SRLIST*(*), MSG*(*), FIXSR*80, TERM*1, CH*1

C  Both pass and fail blank out tstmsg as a sign that they have processed
C  it, and so setmsg requires that it be blank upon entry.

      IF (TSTMSG .NE. ' ') CALL UNMSG ('Non-blank tstmsg detected ' //
     1                     'by setmsg.  Program logic error.')

C srlist must be a list of 1 or 2-digit numbers separated by spaces.
C This routine edits out extra spaces and leading zeros.

C term is an "unusual" character, used to terminate string
      TERM  = CHAR (15)
      FIXSR = ' ' // SRLIST
      IT    = ITRIM(FIXSR) + 1
      FIXSR (IT:IT) = TERM

C edit out extra spaces - we assume fixsr is longer than srlist and has
C some trailing spaces.
100   CONTINUE
      LOC = INDEX(FIXSR, '  ')
      LIM = INDEX(FIXSR, TERM)
      IF (LOC .GT. 0 .AND. LOC .LT. LIM) THEN
         FIXSR(LOC:) = FIXSR(LOC+1:)
         GOTO 100
      ENDIF
C edit out leading zeros
200   CONTINUE
      LOC = INDEX(FIXSR, ' 0')
      IF (LOC .GT. 0) THEN
         FIXSR(LOC+1:) = FIXSR(LOC+2:)
         GOTO 200
      ENDIF

C should be only digits and spaces
      LOC = 0
      IDIG = 0
300   CONTINUE
      LOC = LOC+1
      CH = FIXSR(LOC:LOC)
      IF (CH .EQ. TERM) GOTO 400
      IF (CH .EQ. ' ')  GOTO 300
      IF (CH .GE. '0' .AND. CH .LE. '9') THEN
         IDIG = 1
         GOTO 300
      ENDIF
C Illegal character in parameter - bomb this test
      CALL UNMSG('Illegal character in setmsg srlist-parameter.')

400   CONTINUE
      IF (IDIG .EQ. 0) CALL UNMSG ('No digits found in setmsg ' //
     1                 'srlist-parameter.')

C OK, fixsr looks valid...
      LIM = INDEX(FIXSR, TERM) - 1

C set up pass/fail message
      TSTMSG = '#SR' // FIXSR(1:LIM) // ', ' // MSG

      END
