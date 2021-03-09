C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.01/04                           *
C  *    TEST TITLE : Error indicator = 7                   *
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

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

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

      INTEGER   IVAL1, IVAL2

      CALL INITGL ('09.02.01/04')
      CURCON = 'PHIGS is closed'
      CALL SETVS ('7', EXPERR, EXPSIZ)
      ERRSRS = '4'

      CALL RQCST (11, 100, ERRIND, IVAL1, IVAL2)
      CALL RQCSTN (11, 100, 0, 1, ERRIND, IVAL1, IVAL2)

      CURCON = 'PHIGS is open but no archive file is open'
      CALL XPOPPH (ERRFIL, MEMUN)

      CALL RQCST (11, 100, ERRIND, IVAL1, IVAL2)
      CALL RQCSTN (11, 100, 0, 1, ERRIND, IVAL1, IVAL2)

      CALL ENDIT

      END

