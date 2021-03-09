C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.10/01                           *
C  *    TEST TITLE : Error indicator = 2000                *
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

      INTEGER   SPATH(2,1), ISIZ,ESIZ,ARNM,IA210(2,10),EIS(10),EES(10)
      INTEGER   I1(2),I2(2),I3(2),I4(2),I5(2),I6(2),I7(2),I8(2)
      INTEGER   SPECWT, IDUM1

      REAL      RA2(2), RDUM1

      CALL INITGL ('09.02.10/01')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'enumeration type is out of range'
      CALL SETVS ('2000', EXPERR,EXPSIZ)
      ERRSRS = '1'

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL AVARNM (ARNM)
      CALL POPARF (11, ARNM)

      CALL POPST (100)
      CALL PTX (0.5, 0.5, 'TEXT100')
      CALL PEXST (101)
      CALL PCLST
      CALL POPST (101)
      CALL PTX (0.3,0.3, 'TEXT101')
      CALL PCLST

      CALL RQCSTN (11, 100, 2, 0, ERRIND, IDUM1, IDUM1)

      CALL RQPLR (WKID, 1, 2, ERRIND, IDUM1, RDUM1, IDUM1)

      CALL RQEDR (WKID, 1, -1, ERRIND, IDUM1, IDUM1, RDUM1, IDUM1)

      CALL RQTXX (SPECWT, 1, 0.5,0.1,0.2,4,0,0,'TEXT EXTENT',
     1            ERRIND, RA2, RA2, RDUM1, RDUM1)
      CALL RQTXX (SPECWT, 1, 0.5,0.1,0.2,0,4,0,'TEXT EXTENT',
     1            ERRIND, RA2, RA2, RDUM1, RDUM1)
      CALL RQTXX (SPECWT, 1, 0.5,0.1,0.2,0,1,6,'TEXT EXTENT',
     1            ERRIND, RA2, RA2, RDUM1, RDUM1)

      CALL POPST (200)
      CALL PTX (0.5,0.5,'TEXT200')
      CALL PEXST (201)
      CALL PCLST
      CALL POPST (201)
      CALL PTX (0.3,0.3,'TEXT201')
      CALL PEXST (202)
      CALL PCLST
      CALL POPST(202)
      CALL PTX (0.6,0.6,'TEXT202')
      CALL PCLST
      CALL RQPDE (200,2,2,10,0,ERRIND,IDUM1,IDUM1,IA210)

      CALL SETVS ('1,3,8', EIS, ISIZ)
      CALL SETVS ('2,4', EES, ESIZ)
      CALL RELS (200,1,2, ISIZ,EIS, ESIZ,EES,ERRIND,IDUM1, IDUM1)

      CALL SETVS ('-1,2,4', EES, ESIZ)
      CALL RELS (200,1,1, ISIZ,EIS, ESIZ,EES,ERRIND,IDUM1, IDUM1)

      CALL POPST (301)
      CALL PEXST (302)
      CALL PCLST
      CALL POPST (302)
      CALL PTX (0.9,0.3, 'TEXT302')

      CALL PCLST
      CALL SETVS ('301,1', SPATH, ISIZ)
      CALL RISS3 (1.,1.,1.,0.1,1,SPATH,2,2,
     1            0,I1,I2,I3,I4, 0, I5,I6,I7,I8,
     2            10,ERRIND,IDUM1, IA210)

      CALL PCLARF (11)

      CALL ENDIT

      END

