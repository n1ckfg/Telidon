C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.03/08                           *
C  *    TEST TITLE : Error indicator = 114                 *
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
    
      INTEGER     IVAL1, IVAL2, IVAL3, SPECWT
      REAL        RA44(4,4), RB44(4,4), RA6(6)

      CALL INITGL ('09.02.03/08')

      CALL XPOPPH (ERRFIL, MEMUN)
      CURCON = 'the view index value is less than zero'
      ERRSRS = '8'
      CALL SETVS ('114', EXPERR, EXPSIZ)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL RQVWR (WKID, -1, 0, ERRIND, IVAL1, RA44, RB44, RA6, IVAL2,
     1            IVAL2, IVAL3)

      CALL RQPVWR (SPECWT, -10, ERRIND, RA44, RB44, RA6, IVAL1,
     1             IVAL2, IVAL3)

      CALL ENDIT

      END
