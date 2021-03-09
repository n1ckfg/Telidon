C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.09/01                           *
C  *    TEST TITLE : Error indicator = 404                 *
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

      INTEGER    ARID, ARNM, IVAL1, IVAL2

      CALL INITGL ('09.02.09/01')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified archive file is not open'
      ERRSRS = '1'
      CALL SETVS ('404', EXPERR, EXPSIZ)

      CALL AVARNM (ARNM)
      ARID = 11
      CALL POPARF (ARID, ARNM)

      CALL POPST (100)
      CALL PTX (0.5, 0.5, 'TEXT')
      CALL PCLST

      CALL PARAST (ARID)

      CALL RQCST (12, 0, ERRIND, IVAL1, IVAL2)

      CALL RQCSTN (14, 100, 0, 0, ERRIND, IVAL1, IVAL2)
      CALL RQCSTN (18, 100, 1, 0, ERRIND, IVAL1, IVAL2)

      CALL PCLARF (ARID)

      CALL ENDIT

      END
