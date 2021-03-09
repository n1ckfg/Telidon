      SUBROUTINE E09402 (USEPRM)

C   E09402 tests the handling of error 402.

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

      INTEGER    USEPRM, ARID, ARNM1, ARNM2, NARF, QARID,QARNM
      LOGICAL    STREQ

      CURCON = 'the archive file identifier is already in use'
      CALL SETVS ('402', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)

      ARID = 11
      CALL AVARNM (ARNM1)
      CALL POPARF (ARID, ARNM1)
      CALL AVARNM (ARNM2)
      CALL ROPARF (ARID, ARNM2)

      CALL PQARF (1, ERRIND, NARF, QARID, QARNM)
      CALL TSTIGN (STREQ('O**O')   .AND.
     1             ERRIND.EQ.0     .AND.
     2             NARF .EQ.1      .AND.
     3             QARID.EQ.ARID   .AND.
     4             QARNM.EQ.ARNM1)

      CALL PCLARF (ARID)

      CALL ENDERR

      END
