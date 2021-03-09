      SUBROUTINE E05208 (USEPRM)

C   E05208 tests the handling of error 208.

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

      INTEGER     USEPRM, NUMBER, POSTST
      REAL        ORGPRI
      LOGICAL     STREQ, APPEQ

      CURCON = 'the specified display priority is out of range'
      CALL SETVS ('208', EXPERR, EXPSIZ)
      ERRSRS = '6'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)

      CALL CREST

      CALL PPOST (WKID, 100, 0.5)
      CALL RPOST (WKID, 101, -0.1)
      CALL RPOST (WKID, 101, 1.1)

      CALL PQPOST (WKID, 1, ERRIND, NUMBER, POSTST, ORGPRI)
      CALL TSTIGN (STREQ('OO**') .AND. ERRIND.EQ.0 .AND.
     1             NUMBER.EQ.1   .AND.
     2             POSTST.EQ.100 .AND.
     3             APPEQ(ORGPRI, 0.5, .001,.001))

      CALL PCLWK (WKID)

      CALL ENDERR

      END
