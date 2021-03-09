      SUBROUTINE BRDMSG (MSG)

C Brdmsg broadcasts a message to various destinations.  It uses
C variables in common to control how it issues the message passed to it.

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

      INTEGER    ITRIM, IB, ISP, LSTLIN

      CHARACTER  MSG*(*), BUF*999, MSGLIN*300

C leading space is as Fortran carriage control character.
      BUF   = ' ' // MSG

C  This loop breaks up msg into chunks of size .le. maxlin.  It also
C  puts 5 spaces to the start of each non-first line, so that message-type
C  will stand out.

100   CONTINUE

      DO 200 IB = MAXLIN+1, 1, -1
         IF (BUF(IB:IB) .EQ. ' ') THEN
            ISP = IB
            GOTO 210
         ENDIF
200   CONTINUE
      ISP = MAXLIN
210   CONTINUE
C isp now points to a line-breaking space.

      MSGLIN = BUF (1:ISP-1)
      LSTLIN = ITRIM(MSGLIN)

C ensure *at least* 5 spaces in start of buf.
      BUF    = '     ' // BUF (ISP+1:)

C Message to operator
      IF (ERRSW .EQ. 1) THEN
         CALL OPMSG (MSGLIN (1:LSTLIN))
      ENDIF

800   FORMAT(A)

C Message to files
      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3) THEN
C append to global file
         WRITE (GLBLUN, 800) MSGLIN (1:LSTLIN)
      ENDIF

      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3) THEN
C add to individual file
         WRITE (INDLUN, 800) MSGLIN (1:LSTLIN)
      ENDIF

C any more non-blanks to send out?  If not, quit.
      IF (BUF .EQ. ' ') GOTO 666

C ensure *exactly* 5 leading blanks
300   CONTINUE
      IF (BUF(6:6) .NE. ' ') GOTO 100
      BUF = BUF(2:)
      GOTO 300

666   CONTINUE

      END
