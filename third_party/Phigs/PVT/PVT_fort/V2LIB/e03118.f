      SUBROUTINE E03118 (USEPRM)

C  E03118 tests the handling of error 118.

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

C  type of returned values
      INTEGER        PSET,      PREALI
      PARAMETER     (PSET=0,    PREALI=1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

      INTEGER   USEPRM, NCLMOD, IDUM1, IDUM2, LCLMOD, IX
      INTEGER   NUMCP2, ISIZ, SPECWT
      REAL      SPEC1(10), SPEC2(10), SPEC(10)
      LOGICAL   STREQ,  RAREQ

      CURCON = 'one of the components of the colour ' //
     1         'specification is out of range'
      CALL SETVS ('118', EXPERR, EXPSIZ)
      ERRSRS = '17'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQCMDF (SPECWT,0,ERRIND,NCLMOD,IDUM1,IDUM2)
      CALL CHKINQ ('pqcmdf', ERRIND)

      DO 150 IX = 1, NCLMOD

         CALL PQCMDF (SPECWT, IX, ERRIND, IDUM1, LCLMOD,IDUM2)
         CALL CHKINQ ('pqcmdf', ERRIND)
         IF (LCLMOD.LT.PRGB .OR. LCLMOD.GT.PHLS) GOTO 150

         CALL PSCMD (WKID, LCLMOD)
         CALL SETRVS ('0.5,0.5,0.5', SPEC1, ISIZ)
         CALL PSCR (WKID, 2, 3, SPEC1)

         CALL SETRVS ('-0.5, 0., 1.', SPEC, ISIZ)
         CALL RSCR (WKID, 2, 3, SPEC)

         CALL SETRVS ('0., 1.01, 0.5', SPEC, ISIZ)
         CALL RSCR (WKID, 2, 3, SPEC)

         CALL SETRVS ('0., 0.5, -0.01', SPEC, ISIZ)
         CALL RSCR (WKID, 2, 3, SPEC)

         CALL PQCR (WKID,2,10,PSET,ERRIND,NUMCP2,SPEC2)
         CALL CHKINQ ('pqcr', ERRIND)
         CALL TSTIGN (STREQ('OO**')  .AND.
     1                NUMCP2.EQ.3    .AND.
     2                RAREQ(3,SPEC2,SPEC1,0.01,0.01))

150   CONTINUE

      CALL PCLWK (WKID)

      CALL ENDERR

      END
