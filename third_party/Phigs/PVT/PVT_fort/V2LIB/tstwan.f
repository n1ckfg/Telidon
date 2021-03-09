      SUBROUTINE TSTWAN (WARNIN, WANACT)

C  TSTWAN is used to test that functions which issue a warning
C  take the correct action.

C  Input parameters:
C    WARNIN : logical variable indicating whether the function took
C             the correct action
C    WANACT : description of correct action

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

      INTEGER   ITRIM
      LOGICAL   WARNIN
      CHARACTER MSG*300, FUNNAM*80, WANACT*(*), WBUF*300

      WBUF = WANACT
      IF (WANACT .NE. WBUF) THEN
         CALL UNMSG ('Action description passed to TSTWAN is too long.')
      ENDIF

      IF (INDEX (WBUF, 'should') .LT. 1) THEN
         CALL UNMSG ('Action description passed to TSTWAN does not ' //
     1               'contain "should": ' // WBUF)
      ENDIF

      CALL ERFUNM (EFID(EFCNT), FUNNAM)
      MSG = 'If ' // FUNNAM
      MSG(ITRIM(MSG)+2:) = 'issues a warning because ' // CURCON
      MSG(ITRIM(MSG)+1:) = ', ' // WBUF

      CALL SETMSG (ERRSRS, MSG)
      CALL IFPF (WARNIN)

      END
