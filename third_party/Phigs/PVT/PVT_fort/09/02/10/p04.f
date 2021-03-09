C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.10/04                           *
C  *    TEST TITLE : Error indicator = 2004                *
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
 
      INTEGER     IA210(2,10), SPATH(2,1), EIS(2), EES(1),IDUM1,ISIZ
      INTEGER     I1(2),I2(2),I3(2),I4(2),I5(2),I6(2),I7(2),I8(2)
      REAL        PX(1),PY(1), RA(3)
      DATA        PX/1./,PY/0.5/

      CALL INITGL ('09.02.10/04')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'input parameter size is out of range'
      CALL SETVS ('2004', EXPERR,EXPSIZ)
      ERRSRS = '4'

      CALL POPST (100)
      CALL PTX (0.5,0.5,'TEXT100')
      CALL PEXST (101)
      CALL PCLST
      CALL POPST (101)    
      CALL PPM (1, PX, PY)
      CALL PCLST

      CALL SETVS ('1,3', EIS, ISIZ)
      CALL SETVS ('2', EES, ISIZ)
      CALL RELS (100,1,1,-1,EIS,1,EES,ERRIND,IDUM1,IDUM1)
      CALL RELS (100,1,1, 2,EIS,-1,EES,ERRIND,IDUM1,IDUM1)

      CALL SETVS ('100,1', SPATH, ISIZ)
      CALL RISS3 (0.,0.1,0.,0.1,-1, SPATH,0,0,
     1            0,I1,I2,I3,I4, 0, I5,I6,I7,I8,
     2            10, ERRIND, IDUM1, IA210)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL RQCR  (WKID, 1, -1, 0, ERRIND, IDUM1, RA)
      CALL PCLWK (WKID)

      CALL ENDIT
 
      END

