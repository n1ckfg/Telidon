      SUBROUTINE C01006 (USEPRM)

C  C01006 tests the handling of error number 6: function requires
C  state (PHOP,*,STCL,*) when PHIGS is closed.

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

      INTEGER   USEPRM

      LOGICAL   STREQ

      CALL IFPHCL (USEPRM)
      CALL SETVS ('6', EXPERR,EXPSIZ)
      ERRSRS = '6'

      CALL ROPST (101)
      CALL TSTIGN (STREQ('CCCC'))

      CALL ENDERR

      END
