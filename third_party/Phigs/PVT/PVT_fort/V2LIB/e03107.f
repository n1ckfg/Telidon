      SUBROUTINE E03107 (USEPRM)

C  E03107 tests the handling of error 107

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
      INTEGER     PSET,      PREALI
      PARAMETER  (PSET=0,    PREALI=1)
C   off/on switch for edge flag and error handling
      INTEGER     POFF,      PON
      PARAMETER  (POFF=0,    PON=1)

      INTEGER  USEPRM, NEDTP1, MXTYPE,IX,EDGEFG, EDGETY,EDGECL
      INTEGER  IDUM1,IDUM2,IDUM3, SPECWT, UNTYPE, THISED
      REAL     RDUM1, RDUM2, RDUM3, EDGESC
      LOGICAL  STREQ,APPEQ

      CURCON = 'the specified edgetype is not available on the '//
     1         'specified workstation'
      CALL SETVS ('107', EXPERR, EXPSIZ)
      ERRSRS = '7'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
      CALL PQEDF (SPECWT,1, ERRIND, NEDTP1, MXTYPE,IDUM2,RDUM1,RDUM2,
     1            RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)
      DO 50 IX = 1, ABS(NEDTP1)
         CALL PQEDF (SPECWT, IX, ERRIND, IDUM1, THISED, IDUM2, RDUM1,
     1               RDUM2, RDUM3, IDUM3)
         CALL CHKINQ ('pqedf', ERRIND)
         IF (THISED .GT. MXTYPE) MXTYPE = THISED
50    CONTINUE
      UNTYPE = MXTYPE + 1

      CALL PSEDR (WKID, 1, POFF, THISED, 1., 0)
      CALL RSEDR (WKID, 1, PON,  UNTYPE,    0.5, 1)
      CALL PQEDR (WKID, 1,PSET, ERRIND, EDGEFG, EDGETY,EDGESC,EDGECL)
      CALL CHKINQ ('pqedr', ERRIND)
      CALL TSTIGN (STREQ('OO**')                .AND.
     1             EDGEFG.EQ.POFF               .AND.
     1             EDGETY.EQ.THISED             .AND.
     2             APPEQ(EDGESC,1.0,0.01,0.01)  .AND.
     3             EDGECL.EQ.0)

      CALL PCLWK (WKID)

      CALL ENDERR

      END
