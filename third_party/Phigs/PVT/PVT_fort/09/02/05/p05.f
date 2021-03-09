C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.05/05                           *
C  *    TEST TITLE : Error indicator = 207                 *
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

      INTEGER     IVAL1, IVAL2, IRA210(2,10)
      REAL        PX(1), PY(1)

C  path order
      INTEGER      PPOTOP,      PPOBOT
      PARAMETER   (PPOTOP=0,    PPOBOT=1)

      DATA        PX/2./, PY/2./

      CALL INITGL ('09.02.05/05')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified path depth is less than zero'
      ERRSRS = '5'
      CALL SETVS ('207', EXPERR, EXPSIZ)

      CALL POPST (101)
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (102)
      CALL PPM (1, PX, PY)
      CALL PCLST

      CALL RQPAN (101, PPOTOP, -1, 10, 0, ERRIND, IVAL1,IVAL2,IRA210)
      CALL RQPDE (101, PPOBOT, -5, 10, 0, ERRIND, IVAL1,IVAL2,IRA210)        

      CALL ENDIT

      END
