      SUBROUTINE E02063 (USEPRM)

C  E02063 tests the handling of error number 63.

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

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6
      INTEGER    MAXWK, USEPRM, IX, NMOPWK
      INTEGER    NWKALL,OWKID,OCONID,OWTYPE
      CHARACTER  CDUM, OWCAT
      LOGICAL    STREQ

      CURCON = 'it would exceed the maximum number of ' //
     1         'simultaneously open workstations'

      CALL SETVS ('63', EXPERR, EXPSIZ)
      ERRSRS = '12'
      CALL ESETUP (USEPRM)

      CALL MULTWS (0, 'a', NWKALL,IDUM1,IDUM2,IDUM3,CDUM)
      CALL PQPHF (0, ERRIND, MAXWK,IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,
     1            IDUM6)
      CALL CHKINQ ('pqphf',ERRIND)

      IF (NWKALL .LE. MAXWK) THEN
         CALL INMSG ('The number of all accessible workstations '   //
     1               'is less than or equal to maximum number of '  //
     2               'simultaneously open workstations; therefore ' //
     3               'this test is skipped.')
         RETURN
      ENDIF

      DO 150 IX = 1, MAXWK+1
         CALL MULTWS (IX, 'a', IDUM1, OWKID, OCONID, OWTYPE, OWCAT)
         IF (IX .LE. MAXWK) THEN
            CALL POPWK (OWKID, OCONID, OWTYPE)
         ELSE
            CALL ROPWK (OWKID, OCONID, OWTYPE)
         ENDIF
150   CONTINUE

      CALL PQOPWK (0, ERRIND, NMOPWK, IDUM1)
      CALL CHKINQ ('pqopwk', ERRIND)
      CALL TSTIGN (STREQ('OO**')  .AND. NMOPWK.EQ.MAXWK)

      CALL ENDERR

      END
