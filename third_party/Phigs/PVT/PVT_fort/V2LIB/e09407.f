      SUBROUTINE E09407 (USEPRM)

C   E09407 tests the handling of error 407.

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

      INTEGER     USEPRM, ISIZ, IDUM1,ARID,ARNM,NSTID,STLIST(10)
      LOGICAL     STREQ
      CHARACTER   MSG*100

      CURCON = 'some of the specified structures do not exist on '//
     1         'the archive file'
      MSG = 'it should ignore the structures that do not exist.'
      CALL SETVS ('407', EXPERR, EXPSIZ)
      ERRSRS = '8'
      CALL ESETUP (USEPRM)

      ARID = 11
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
      CALL PDASAR (ARID)
      CALL CREST

      CALL PARAST (ARID)
      CALL SETVS ('100,102,101', STLIST, ISIZ)

      CALL RDSTAR (ARID, ISIZ, STLIST)

      CALL PDST (100)
      CALL PDST (101)
      CALL PRAST (ARID)
      CALL PQSID (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL TSTWAN (STREQ('O**O') .AND. NSTID.EQ.0, MSG)

      CALL CREST

      CALL PARAST (ARID)
      CALL SETVS ('100,102', STLIST, ISIZ)

      CALL RDSNAR (ARID, ISIZ, STLIST)

      CALL PCLARF (ARID)

      CALL ENDERR

      END
