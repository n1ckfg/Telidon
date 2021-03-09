      SUBROUTINE E01006 (USEPRM)

C  E01006 tests the handling of error number 6: function requires
C  state (PHOP,*,STCL,*) when PHIGS is open.

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

C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER   USEPRM, ERRIND, OPSTAT, OPID

      LOGICAL   STREQ

      CURCON = 'PHIGS is open and a structure is open'
      CALL SETVS ('6', EXPERR,EXPSIZ)
      ERRSRS = '6'
      CALL ESETUP (USEPRM)

      CALL POPST (101)
      CALL ROPST (102)
      CALL PQOPST (ERRIND, OPSTAT, OPID)
      CALL CHKINQ ('pqopst', ERRIND)
      CALL TSTIGN (STREQ('O*O*') .AND. OPSTAT.EQ.POPNST .AND.
     1             OPID.EQ.101)

      CALL PCLST

      CALL ENDERR

      END
