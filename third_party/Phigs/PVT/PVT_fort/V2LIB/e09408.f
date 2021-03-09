      SUBROUTINE E09408 (USEPRM)

C   E09408 tests the handling of error 408.

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

C  structure status indicator
      INTEGER     PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER  (PSNOEX=0,   PSEMPT=1,   PSNEMP=2)

      INTEGER     USEPRM, IX, IDUM1, ISIZ,ARID,ARNM,STLIST(10)
      INTEGER     STATUS, NSTID, STIDS(10)
      LOGICAL     STREQ, SETEQ
      CHARACTER   MSG*100

      CURCON = 'some of the specified structures do not exist '//
     1         'on the archive file'
      MSG = 'it should create empty structures in their place.'
      CALL SETVS ('408', EXPERR, EXPSIZ)
      ERRSRS = '9'
      CALL ESETUP (USEPRM)

      ARID = 11
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)

      CALL CREST

      CALL PARAST (ARID)
      CALL PDAS
      CALL SETVS ('100,102,101', STLIST, ISIZ)

      CALL RREST (ARID, ISIZ, STLIST)
      CALL PQSID (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      DO 100 IX = 1, NSTID
         CALL PQSID (IX,ERRIND, IDUM1, STIDS(IX))
         CALL CHKINQ ('pqsid', ERRIND)
100   CONTINUE
      CALL PQSTST (102, ERRIND, STATUS)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL TSTWAN (STREQ('O**O')             .AND.
     1             NSTID.EQ.3                .AND.
     2             SETEQ(3, STIDS, STLIST)   .AND.
     3             STATUS.EQ.PSEMPT, MSG)

      CALL PDAS

      CALL RRESN (ARID, ISIZ, STLIST)

      CALL PCLARF (ARID)

      CALL ENDERR

      END
