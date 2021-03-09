      SUBROUTINE ICHKZ (CERIND, FUNCID)

C  ICHKZ does post-processing after an error-indicator function has
C  been called.

C  Input parameters:
C    CERIND: actual error indicator returned by function
C    FUNCID: numeric identifier of function that returned error indicator

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

      INTEGER     IX, FUNCID, ITRIM, CERIND
      CHARACTER   FUNNAM*80, TMSG*500, MSG*160, ACODE*4
      INTEGER     IARFND

      IF (EXPSIZ.LT.1) THEN
         CALL UNMSG ('ICHKZ is called with invalid EXPSIZ.')
      ENDIF

C  set up test message
      CALL NFUNM (FUNCID, FUNNAM)
      TMSG = 'If ' // FUNNAM
      TMSG(ITRIM(TMSG)+2:) = 'is called and ' // CURCON
      TMSG(ITRIM(TMSG)+1:) = ', it should return error indicator = '

C  may be several valid error code possibilities
      DO 50 IX = 1, EXPSIZ-1
         WRITE (ACODE, '(I4.3)') EXPERR(IX)
         TMSG(ITRIM(TMSG)+2:) = ACODE // ','
50    CONTINUE
      IF (EXPSIZ.GE.2) TMSG(ITRIM(TMSG):) = ' or '
      WRITE(ACODE, '(I4.3)') EXPERR(EXPSIZ)
      TMSG(ITRIM(TMSG)+2:) = ACODE // '.'
      CALL SETMSG (ERRSRS, TMSG)

      IF (IARFND(CERIND, EXPSIZ, EXPERR) .GT. 0) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I6.3,A)') 'Reported error indicator ',
     1          CERIND, ' is not one of the expected values.'
         CALL INMSG (MSG)
      ENDIF

      END
