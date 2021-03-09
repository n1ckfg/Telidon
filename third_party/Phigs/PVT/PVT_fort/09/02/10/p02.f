C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.10/02                           *
C  *    TEST TITLE : Error indicator = 2001                *
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

C interior style                          
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      INTEGER   SPATH(2,1), COLIA(3,3), ISIZ,IA10(10)       
      INTEGER   IA5(5), IB5(5), IA210(2,10),IB10(10), SPECWT
      INTEGER   I1(2),I2(2),I3(2),I4(2),I5(2),I6(2),I7(2),I8(2)
      INTEGER   IDUM1,IDUM2,IDUM3

      REAL      PX(1),PY(1),PZ(1),RA10(10),CSPEC(3)

      CHARACTER STR10(10)*80, SS(10)*6

      LOGICAL   INTSTY

      DATA  PX/1./,PY/1./,PZ/1./
      DATA COLIA/0,1,1,0,0,1,1,1,0/
      DATA CSPEC/0.,1.,0./

      CALL INITGL ('09.02.10/02')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'output parameter size is insufficient'
      CALL SETVS ('2001', EXPERR,EXPSIZ)
      ERRSRS = '2'

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      IF (INTSTY (SPECWT, PPATTR)) THEN
         CALL PSPAR (WKID, 1, 3,3,1,1,3,3,COLIA)
         CALL RQPAR (WKID, 1, 0, 2,2, ERRIND, IDUM1,IDUM2,COLIA)
      ENDIF

      CALL PSCR (WKID, 1, 3, CSPEC)
      CALL RQCR (WKID, 1, 2, 0, ERRIND, IDUM1, CSPEC)

      CALL SETVS ('1,2,3,4,5', IA5, ISIZ)
      CALL SETVS ('2,4,6,8,9', IB5, ISIZ)
      CALL PSHLFT (WKID, 5, IA5, 5, IB5)
      CALL RQHLFT (WKID, 4,4, ERRIND, IDUM1, IA5, IDUM1, IB5)

      CALL POPST (100)
      CALL PTX (0.5,0.5,'TEXT100')
      CALL PEXST (101)
      CALL PCLST
      CALL POPST (101)
      CALL PTX (0.3,0.3,'TEXT101')
      CALL PEXST (102)
      CALL PCLST
      CALL POPST(102)
      CALL PTX (0.6,0.6,'TEXT102')
      CALL PCLST

C  real array too small
      CALL RQECO (100, 1, 10, 1, 10,  ERRIND, IDUM1,IA10,IDUM2,RA10,
     1            IDUM3, IB10, STR10)
C  length of character string ss too short
      CALL RQECO (100, 1, 10, 10, 10, ERRIND, IDUM1,IA10,IDUM2,RA10,
     1            IDUM3, IB10, SS)

      CALL RQPDE (100,0,0,1,1,ERRIND,IDUM1,IDUM2,IA210)

      CALL POPST (201)
      CALL PTX (0.4,0.4,'TEXT201')
      CALL PEXST (202)
      CALL PCLST
      CALL POPST (202)
      CALL PPM3 (1, PX, PY, PZ)
      CALL PCLST
      CALL SETVS ('201,1', SPATH, ISIZ)
      CALL RISS3 (.9,.9,.9,0.15,1,SPATH,0,1,
     1            0,I1,I2,I3,I4, 0, I5,I6,I7,I8,
     2            1,ERRIND, IDUM1,IA210)
      CALL ENDIT

      END
