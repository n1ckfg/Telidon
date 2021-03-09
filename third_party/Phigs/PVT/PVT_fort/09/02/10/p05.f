C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.10/05                           *
C  *    TEST TITLE : Error indicator = 2006                *
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
 
      INTEGER   NFLN, IFLN, ISIZ, IDUM, IA210(2,10),SPATH(2,1)
      INTEGER   NFLISX(10), NFLESX(10), IFLISX(10), IFLESX(10)
      INTEGER   NFLIS(100), NFLES(100), IFLIS(100), IFLES(100)
 
      CALL INITGL ('09.02.10/05')
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CURCON = 'list of filters is invalid'
      CALL SETVS ('2006', EXPERR,EXPSIZ)
      ERRSRS = '5'
 
      CALL POPST (100)
      CALL PTX (0.5,0.5,'TEXT100')
      CALL PEXST (101)
      CALL PCLST
      CALL POPST (101)
      CALL PTX (0.3,0.3,'TEXT101')
      CALL PCLST
 
      CALL SETVS ('100,1', SPATH, ISIZ)
      NFLN = 2
      CALL SETVS ('2,4', NFLISX, ISIZ)
      CALL SETVS ('3,4', NFLESX, ISIZ)
      CALL SETVS ('1,3,5,7', NFLIS, ISIZ)
      CALL SETVS ('2,4,6,8', NFLES, ISIZ)
 
      IFLN = 2
      CALL SETVS ('2,4', IFLISX, ISIZ)
      CALL SETVS ('3,4', IFLESX, ISIZ)
      CALL SETVS ('1,3,5,7', IFLIS, ISIZ)
      CALL SETVS ('2,4,6,8', IFLES, ISIZ)
 
      CALL RISS3 (0.,0.1,0.,0.1,1, SPATH,0,2, -1, NFLISX,NFLIS,
     1            NFLESX,NFLES,IFLN,IFLISX,IFLIS,IFLESX,IFLES,10,
     2            ERRIND, IDUM, IA210)
      CALL RISS3 (0.,0.1,0.,0.1,1, SPATH,0,2, NFLN,NFLISX,NFLIS,
     1            NFLESX,NFLES,-1,IFLISX,IFLIS, IFLESX,IFLES,10,
     2            ERRIND, IDUM, IA210)
 
      CALL ENDIT
 
      END
