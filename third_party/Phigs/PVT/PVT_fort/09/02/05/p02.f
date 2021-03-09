C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.05/02                           *
C  *    TEST TITLE : Error indicator = 202                 *
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

      INTEGER      IVAL1, IVAL2, IVAL3, IVAL4, IRA10(10)
      REAL         RA10(10), PX(2), PY(2)
      CHARACTER*80 STR10(10)
      DATA PX/0.,1./, PY/0.,1./

      CALL INITGL ('09.02.05/02')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified element does not exist'
      ERRSRS = '2'
      CALL SETVS ('202', EXPERR, EXPSIZ)

      CALL POPST (100)
      CALL PPL (2, PX, PY)
      CALL PCLST

      CALL RQETS (100, 2, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4)
      CALL RQECO (100, 2, 10,10,10, ERRIND, IVAL1, IRA10, IVAL2,
     1            RA10, IVAL3, IRA10, STR10)

      CALL ENDIT
      END
