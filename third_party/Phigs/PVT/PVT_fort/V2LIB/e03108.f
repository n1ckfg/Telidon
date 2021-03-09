      SUBROUTINE E03108 (USEPRM)

C  E03108 tests the handling of error 108

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

C  interior style
      INTEGER    PHOLLO,     PSOLID,    PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0,   PSOLID=1,  PPATTR=2, PHATCH=3, PISEMP=4)
C  type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET=0,   PREALI=1)

      INTEGER   USEPRM,IX,NISTY1,ISTYLE,ISINDX,ISCOLO, THISIS
      INTEGER   SPECWT, UNTYPE,IDUM1,IDUM2,IDUM3,IDUM4,IDUM5
      LOGICAL   STREQ, ISAVL(PHOLLO:PISEMP)

      DATA      ISAVL / 5 * .FALSE. /

      CALL SETVS ('108', EXPERR, EXPSIZ)
      CURCON = 'the specified interior style is not available '//
     1         'on the specified workstation'
      ERRSRS = '8'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQIF (SPECWT, 0,0,ERRIND, NISTY1, IDUM1,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
      DO 50 IX = 1, NISTY1
         CALL PQIF (SPECWT, IX, 0, ERRIND, IDUM2, THISIS,
     1              IDUM3, IDUM4, IDUM5)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS.GE.PHOLLO .AND. THISIS.LE.PISEMP) THEN
            ISAVL(THISIS) = .TRUE.
         ENDIF
50    CONTINUE

      DO 60 IX = PHOLLO, PISEMP
         IF (.NOT. ISAVL(IX)) THEN
            UNTYPE = IX
            GOTO 70
         ENDIF
60    CONTINUE
      CALL INMSG ('No unavailable interior styles; test is skipped.')
      RETURN

70    CONTINUE
      CALL PSIR (WKID, 1, THISIS, 1, 0)
      CALL RSIR (WKID, 1, UNTYPE, 2, 1)
      CALL PQIR (WKID, 1, PSET, ERRIND, ISTYLE,ISINDX,ISCOLO)
      CALL CHKINQ ('pqir', ERRIND)
      CALL TSTIGN (STREQ('OO**')      .AND.
     1             ISTYLE.EQ.THISIS   .AND.
     2             ISINDX.EQ.1        .AND.
     3             ISCOLO.EQ.0)

      CALL PCLWK (WKID)

      CALL ENDERR

      END
