C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.03/05                           *
C  *    TEST TITLE : Error indicator = 109                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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
      INTEGER        PHOLLO,   PSOLID,   PPATTR,   PHATCH,  PISEMP
      PARAMETER     (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3,PISEMP=4)

      INTEGER   IVAL1, IVAL2, IA1010(10, 10), SPECWT

      LOGICAL   INTSTY

      CALL INITGL ('09.02.03/05')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'interior style PATTERN is not supported on the '//
     1         'workstation'
      ERRSRS = '5'
      CALL SETVS ('109,101', EXPERR, EXPSIZ)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      IF (INTSTY(SPECWT, PPATTR)) THEN
         CALL INMSG ('This workstation supports the interior style ' //
     1               'PATTERN; skip the test.')
      ELSE
         CALL RQPAR (WKID, 1, 0, 10,10, ERRIND, IVAL1,IVAL2,IA1010)
      ENDIF

      CALL ENDIT

      END
