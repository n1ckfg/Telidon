C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.05/01                           *
C  *    TEST TITLE : Error indicator = 201                 *
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

C   search direction
      INTEGER    PBWD,       PFWD
      PARAMETER (PBWD=0,     PFWD=1)
C   path order
      INTEGER    PPOTOP,     PPOBOT
      PARAMETER (PPOTOP=0,   PPOBOT=1)
C   structure network source
      INTEGER    PCSS,       PARCHV
      PARAMETER (PCSS=0,     PARCHV=1)

      INTEGER     IVAL1, IVAL2, IVAL3, IVAL4, IRA10(10), IRB10(10)
      INTEGER     IRA210(2,10), EIS(1), EES(1), ARID, ARNM
      REAL        RA10(10), PX(2), PY(2)
      CHARACTER*80 STR10(10)

      DATA  PX/0.,1./, PY/0.,1./

      CALL INITGL ('09.02.05/01')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified structure does not exist'
      ERRSRS = '1'
      CALL SETVS ('201', EXPERR, EXPSIZ)

      CALL POPST (101)
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (102)
      CALL PPL (2, PX, PY)
      CALL PCLST

      ARID = 11
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
      CALL PARAST (ARID)

      CALL RQCSTN (ARID, 100, PCSS, 0, ERRIND, IVAL1, IVAL2)
      CALL RQCSTN (ARID, 100, PARCHV, 1, ERRIND, IVAL1, IVAL2)
      CALL PCLARF (ARID)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PPOST (WKID, 102, 0.)
      CALL RQWKPO (100, 0, ERRIND, IVAL1, IVAL2)
      CALL PCLWK (WKID)

      CALL RQETS (100, 1, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4)
      CALL RQECO (100, 1, 10,10,10, ERRIND, IVAL1, IRA10, IVAL2,
     1            RA10, IVAL3, IRB10, STR10)
      CALL RQPAN (100, PPOTOP, 1, 10, 0, ERRIND, IVAL1, IVAL2, IRA210)
      CALL RQPDE (100, PPOBOT, 1, 10, 0, ERRIND, IVAL1, IVAL2, IRA210)
      CALL RELS (100, 1, PFWD, 1, EIS, 1, EES, ERRIND, IVAL1, IVAL2)

      CALL ENDIT
      END

