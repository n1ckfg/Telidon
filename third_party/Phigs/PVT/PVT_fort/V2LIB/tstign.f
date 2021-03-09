      SUBROUTINE TSTIGN (IGNORE)

C  TSTIGN is used to test that a function signalling an error is
C  ignored.

C  Input parameters:
C    IGNORE : logical variable indicating whether the function was ignored

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
      LOGICAL   IGNORE
      CHARACTER MSG*300, FUNNAM*80

      CALL ERFUNM (EFID(EFCNT), FUNNAM)
      MSG = 'If ' // FUNNAM
      MSG(ITRIM(MSG)+2:) = 'signals an error because ' // CURCON
      MSG(ITRIM(MSG)+1:) = ', it should not cause any other effect.'

      CALL SETMSG (ERRSRS, MSG)
      CALL IFPF (IGNORE)

      END
