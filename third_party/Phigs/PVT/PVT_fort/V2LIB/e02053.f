      SUBROUTINE E02053 (USEPRM)

C  E02053 tests the handling of error number 53

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

      INTEGER      USEPRM, IX,IDUM1,IDUM2,IDUM3,NWKALL, NUMOWK, OPWKID
      INTEGER      OWKID, OCONID, OWTYPE
      CHARACTER*1  CDUM, OWCAT
      LOGICAL      STREQ, IGNOK

      CURCON =  'the specified workstation identifier is in use'
      CALL SETVS ('53', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)

C  **** Generate errors

      IGNOK = .TRUE.
      CALL MULTWS (0, 'a',NWKALL,IDUM1,IDUM2,IDUM3,CDUM)
      DO 150 IX = 1, NWKALL
         CALL MULTWS (IX, 'a',IDUM1,OWKID,OCONID,OWTYPE,
     1                OWCAT)
         CALL POPWK (OWKID, OCONID, OWTYPE)
         CALL ROPWK (OWKID, OCONID, OWTYPE)
         CALL PQOPWK (1, ERRIND, NUMOWK, OPWKID)
         CALL CHKINQ ('pqopwk', ERRIND)
         IF (.NOT. (STREQ('OO**') .AND. NUMOWK.EQ.1 .AND.
     1              OPWKID.EQ.OWKID)) IGNOK = .FALSE.
         CALL PCLWK (OWKID)
150   CONTINUE
      CALL TSTIGN (IGNOK)

C  **** Examine saved errors

      CALL ENDERR

      END
