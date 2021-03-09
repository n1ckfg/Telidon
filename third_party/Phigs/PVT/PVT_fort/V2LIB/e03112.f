      SUBROUTINE E03112 (USEPRM)

C  E03112 tests the handling of error 112.

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
      INTEGER      PHOLLO,   PSOLID,    PPATTR,    PHATCH,   PISEMP
      PARAMETER   (PHOLLO=0, PSOLID=1,  PPATTR=2,  PHATCH=3, PISEMP=4)

      INTEGER  USEPRM, PTRARY(1,1), SPECWT
      LOGICAL  STREQ, INTSTY

      CURCON = 'the pattern index value is less than one'
      CALL SETVS ('112', EXPERR, EXPSIZ)
      ERRSRS = '11'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      IF (.NOT. INTSTY (SPECWT, PPATTR)) THEN
         CALL INMSG ('Pattern style not supported by this ' //
     1               'workstation; test skipped.')
         GOTO 666
      ENDIF

      CALL RSIR (WKID, 1, PPATTR, -1, 0)
      CALL TSTIGN (STREQ('OO**'))

      PTRARY(1,1) = 0
      CALL RSPAR (WKID,0,1,1,1,1,1,1,PTRARY)

666   CONTINUE

      CALL PCLWK (WKID)

      CALL ENDERR

      END
