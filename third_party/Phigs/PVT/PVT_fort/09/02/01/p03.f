C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.01/03                           *
C  *    TEST TITLE : Error indicator = 5                   *
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

      INTEGER    IVAL1, IVAL2, IVAL3, IVAL4, IA10(10), IB10(10)
      REAL       RA10(10)
      CHARACTER*45 STR10(10)

      CALL INITGL ('09.02.01/03')
      CURCON = 'PHIGS is closed'
      CALL SETVS ('5', EXPERR, EXPSIZ)
      ERRSRS = '3'
  
      CALL RQEP (ERRIND, IVAL1)
      CALL RQCETS (ERRIND, IVAL1, IVAL2, IVAL3, IVAL4)
      CALL RQCECO (10, 10, 10, ERRIND, IVAL1, IA10, IVAL2, RA10, 
     1             IVAL3, IB10, STR10)

      CURCON = 'PHIGS is open but no structure is open'
      CALL XPOPPH (ERRFIL, MEMUN)

      CALL RQEP (ERRIND, IVAL1)
      CALL RQCETS (ERRIND, IVAL1, IVAL2, IVAL3, IVAL4)
      CALL RQCECO (10, 10, 10, ERRIND, IVAL1, IA10, IVAL2, RA10, 
     1             IVAL3, IB10, STR10)

      CALL ENDIT
      END

