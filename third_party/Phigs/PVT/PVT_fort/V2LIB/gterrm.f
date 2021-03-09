      SUBROUTINE GTERRM (ELUN, EMSG)

C  GTERRM retrieves one error message from a specified error file
C  and returns it.

C  Input parameter:
C    ELUN : logical unit number from which to read
C  Output parameter:
C    EMSG : complete text of error message, even if spread over
C           several records; also used as input to tell whether
C           this is the first read or not.

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

      SAVE EREC

      INTEGER    ELUN, NMRK, ITRIM
      LOGICAL    FIRST, ERMSGH
      CHARACTER  EMSG*(*), EREC*200, ANS*1

C  special strings to control processing of error file
      CHARACTER  EOFMRK*17,                    BOFMRK*10
      PARAMETER (EOFMRK = 'end of error file', BOFMRK = 'first call')

      DATA EREC / ' ' /

      NMRK  = ITRIM (ERRMRK)

      IF (ERRMRK .NE. ' ') THEN
C  use special string to identify start of error message
         FIRST = EMSG.EQ.BOFMRK

C  start to fill EMSG from EREC
210      CONTINUE
         IF (FIRST) THEN
            EMSG = ' '
         ELSE
C  EREC has first record of error message or EOF indicator
            EMSG = EREC
         ENDIF

         IF (EMSG .EQ. EOFMRK) RETURN

250      CONTINUE
         READ (UNIT=ELUN, FMT='(A)', END=290) EREC
C  EREC now has next record
         IF (ERMSGH (EREC, ERRMRK, NMRK)) THEN
C  message header
            GOTO 295
         ELSE
C  non-header
            EMSG(ITRIM(EMSG)+2:) = EREC
            GOTO 250
         ENDIF

290      CONTINUE
         EREC = EOFMRK

295      CONTINUE
C  EREC contains either EOFMRK or message header
         IF (FIRST) THEN
            FIRST = .FALSE.
            GOTO 210
         ENDIF

      ELSE
C  operator must identify completion of error message
         EMSG = ' '
300      CONTINUE
         READ (UNIT=ELUN, FMT='(A)', END=310) EREC

         IF (EMSG.EQ.' ') THEN
            EMSG = EREC
         ELSE
            EMSG(ITRIM(EMSG)+2:) = EREC
         ENDIF

         IF (EMSG.EQ.' ') GOTO 300

         CALL OPMSG ('------- Begin message from error file: ' //
     1               '-------')
         CALL OPMSG (EMSG)
         CALL OPMSG ('------- End message from error file: -------')
         CALL OPYN ('Is the error message completely displayed? ', ANS)
         IF (ANS .EQ. 'n') GOTO 300
         GOTO 320

310      CONTINUE
         CALL OPMSG ('Hit EOF while trying to read error file.')

320      CONTINUE
      ENDIF

      END
