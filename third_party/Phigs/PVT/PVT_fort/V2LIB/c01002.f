      SUBROUTINE C01002 (USEPRM)

C  C01002 tests the handling of error number 2: function requires
C  state (PHOP,*,*,*).

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

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

C  edit mode
      INTEGER         PINSRT,    PREPLC
      PARAMETER      (PINSRT=0,  PREPLC=1)

C  reference handling flag
      INTEGER         PDELE,     PKEEP
      PARAMETER      (PDELE=0,   PKEEP=1)

C  conflict resolution maintain,  abandon,    update
      INTEGER          PCRMNT,    PCRABA,     PCRUPD
      PARAMETER       (PCRMNT=0,  PCRABA=1,   PCRUPD=2)

      INTEGER   USEPRM, MODE, RNDINT, DSNT, ARCCR, RETCR
      LOGICAL   STREQ

      CALL IFPHCL (USEPRM)
      CALL SETVS ('2', EXPERR,EXPSIZ)
      ERRSRS = '2'

      CALL ROPWK (WKID, CONID, WTYPE)
      CALL TSTIGN (STREQ('CCCC'))

      MODE = RNDINT (PINSRT, PREPLC)
      CALL RSEDM (MODE)
      CALL TSTIGN (STREQ('CCCC'))

      CALL REMST (101)
      CALL TSTIGN (STREQ('CCCC'))

      DSNT = RNDINT (PDELE, PKEEP)
      CALL RDSN (101, DSNT)

      CALL RCSTIR (101, 102)

      ARCCR = RNDINT (PCRMNT, PCRUPD)
      RETCR = RNDINT (PCRMNT, PCRUPD)
      CALL ROPARF (11, 24)
      CALL TSTIGN (STREQ('CCCC'))

      CALL RSCNRS (ARCCR, RETCR)

      CALL ENDERR

      END
