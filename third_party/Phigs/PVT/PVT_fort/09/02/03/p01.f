C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.03/01                           *
C  *    TEST TITLE : Error indicator = 100                 *
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

      INTEGER    IVAL1, IVAL2, IVAL3, SPECWT
      REAL       RVAL1, RVAL2

      CALL INITGL ('09.02.03/01')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the bundle index value is less than one'
      ERRSRS = '1'
      CALL SETVS ('100', EXPERR, EXPSIZ)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL RQPLR (WKID, 0, 0, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQPMR (WKID, -1, 1, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQTXR (WKID, -100, 0, ERRIND, IVAL1, IVAL2, RVAL1, RVAL2,
     1            IVAL3)

      CALL RQIR (WKID, 0, 1, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQEDR (WKID, -1, 0, ERRIND, IVAL1, IVAL2, RVAL1, IVAL3)

      CALL RQPPLR (SPECWT, -100, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQPPMR (SPECWT, 0, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQPTXR (SPECWT, -1, ERRIND, IVAL1,IVAL2,RVAL1,RVAL2,IVAL3)

      CALL RQPIR (SPECWT, -100, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQPEDR (SPECWT, 0, ERRIND, IVAL1, IVAL2, RVAL1, IVAL3)

      CALL ENDIT

      END
