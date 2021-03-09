      SUBROUTINE E03105 (USEPRM)

C  E03105 tests the handling of error number 105

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

C  type of returned value
      INTEGER    PSET,      PREALI
      PARAMETER (PSET=0,    PREALI=1)

      INTEGER    USEPRM, IX, NMTYP1, MXTYPE, MARKTY,MARKCL
      INTEGER    IDUM1,IDUM2,IDUM3,UNTYPE, THISMT, SPECWT
      REAL       RDUM1, RDUM2, RDUM3, MARKSC
      LOGICAL    STREQ, APPEQ

      CURCON = 'the specified marker type is not available '//
     1         'on the specified workstation'
      CALL SETVS ('105', EXPERR, EXPSIZ)
      ERRSRS = '5'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQPMF (SPECWT, 1, ERRIND, NMTYP1, MXTYPE,IDUM2,RDUM1,RDUM2,
     1            RDUM3, IDUM3)
      CALL CHKINQ ('pqpmf', ERRIND)
      DO 50 IX = 1, ABS(NMTYP1)
         CALL PQPMF (SPECWT,IX,ERRIND,IDUM1,THISMT,IDUM2,RDUM1,
     1               RDUM2, RDUM3, IDUM3)
         CALL CHKINQ ('pqpmf',ERRIND)
         IF (THISMT .GT. MXTYPE) MXTYPE = THISMT
50    CONTINUE
      UNTYPE = MXTYPE + 1
C
      CALL PSPMR (WKID, 1, THISMT, 1., 0)
      CALL RSPMR (WKID, 1, UNTYPE,  .5,  1)
      CALL PQPMR (WKID, 1, PSET, ERRIND, MARKTY,MARKSC,MARKCL)
      CALL CHKINQ ('pqpmr', ERRIND)

      CALL TSTIGN (STREQ('OO**')               .AND.
     1             MARKTY.EQ.THISMT            .AND.
     2             APPEQ(MARKSC,1.,0.01,0.01)  .AND.
     3             MARKCL.EQ.0)

      CALL PCLWK (WKID)

      CALL ENDERR

      END
