C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.10/e12000                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E12000 (USEPRM)
 
C  E12000 tests the handling of FORTRAN specific error 2000.
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20)
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
 
C  type of returned values
      INTEGER        PSET,      PREALI
      PARAMETER     (PSET=0,    PREALI=1)
C   off/on switch for edge flag and error handling
      INTEGER     POFF,      PON
      PARAMETER  (POFF=0,    PON=1)
 
      INTEGER   USEPRM, ISIZ, OL, APTHSZ, PATHS(2,10), ARNM, ELP
      INTEGER   EDGEFG, EDGETY,EDGECL, ERRIND
      REAL      EDGESC, XFRMT3(3,3), CPLM(4)
      LOGICAL   STREQ, APPEQ

      CURCON = 'enumeration type is out of range'
      CALL SETVS ('2000', EXPERR,EXPSIZ)
      ERRSRS = '1'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL POPST (101)
 
C  workstation control functions
      CALL RRST (WKID, 2)
 
      CALL RUWK (WKID, -1)
 
      CALL RSDUS (WKID, 5, 0)
      CALL RSDUS (WKID, 1, 3)
 
C  element creation functions
      CALL RSTXP (4)
 
      CALL RSATAL (4, 2)
      CALL RSATAL (1, 6)
 
      CALL RSIS (5)

      CALL RSEDFG (2)
                         
      CALL RSIASF (-1, 1)
      CALL RSIASF (2, 2)
 
      CALL IDMAT (3, XFRMT3)
      CALL RSLMT (XFRMT3, 3)
 
      CALL PQEP (ERRIND, ELP)
      CALL TSTIGN (ERRIND.EQ.0 .AND. ELP.EQ.0)
 
C  workstation table
      CALL PSEDR (WKID, 1, POFF, 1, 1., 0)
      CALL RSEDR (WKID, 1, 2,    1, 0.5,1)
      CALL PQEDR (WKID, 1,PSET, ERRIND, EDGEFG, EDGETY,EDGESC,EDGECL)
      CALL CHKINQ ('pqedr', ERRIND)
      CALL TSTIGN (STREQ('OO**')                .AND.
     1             EDGEFG.EQ.POFF               .AND.
     1             EDGETY.EQ.1                  .AND.
     2             APPEQ(EDGESC,1.0,0.01,0.01)  .AND.
     3             EDGECL.EQ.0)
 
      CALL SETRVS ('0.,1.,0.,1.', CPLM, ISIZ)
      CALL RSVWR (WKID, 1, XFRMT3, XFRMT3, CPLM, 2)
 
      CALL PSVWR (WKID, 2, XFRMT3, XFRMT3, CPLM, 0)
      CALL RSVTIP (WKID,1,2,2)
 
      CALL RSEDM (2)
 
      CALL PEMST (100)
      CALL PTX (0.5, 0.5, 'TEXT')
      CALL PCLST
      CALL RDSN (100, 2)
 
      CALL RSCNRS (3, 0)
      CALL RSCNRS (0, 3)

      CALL AVARNM (ARNM)
      CALL POPARF (11, ARNM)
      CALL PARAST (11)
      CALL RREPAN (11, 100, 2, 1, 10, 0, OL, APTHSZ, PATHS)
 
      CALL RSERHM (2)
 
      CALL PCLARF (11)
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.10/e12001                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E12001 (USEPRM)
 
C  E12001 tests the handling of FORTRAN specific error 2001.
 
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
 
      INTEGER   USEPRM, IDUM1, IA210(2,10), ARNM, IA10(10),IDUM2
 
      CURCON = 'output parameter size is insufficient'
      CALL SETVS ('2001', EXPERR, EXPSIZ)
      ERRSRS = '2'
      CALL ESETUP (USEPRM)
 
      CALL AVARNM (ARNM)
      CALL POPARF (11, ARNM)
      CALL PDASAR (11)
 
      CALL POPST (100)
      CALL PTX (0.5, 0.5, 'TEXT100')
      CALL PEXST (101)
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (101)
      CALL PTX (0.3,0.3, 'TEXT101')
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (102)
      CALL PTX (0.8,0.9,'TEXT102')
      CALL PCLST
 
      CALL PARAST (11)
 
      CALL RRSID (11, 2, IDUM1, IA10)

      CALL RREPAN (11,102,0,0,1,1,IDUM1,IDUM2,IA210)

      CALL RREPDE (11,100,0,0,1,1,IDUM1,IDUM2,IA210)
 
      CALL PCLARF (11)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.10/e12004                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E12004 (USEPRM)
 
C  E12004 tests the handling of FORTRAN specific error 2004.
 
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
  
      INTEGER   NUMARC, USEPRM, COLIA(3,3),NAMSET(3),ISIZ
      INTEGER   LSTID(1), ARNM, ELP
      INTEGER   ISN,IS(2), ESN, ES(2), OUTST(10)
      REAL      PX(6), PY(6), PZ(6), HALFSP(4,1)

      DATA PX/0.,0.3,0.5,1.5,3.,0./, PY/0.1,0.4,0.6,1.3,2.4,0./,
     1     PZ/0.5,0.8,1.2,0.3,1.,0./

      CURCON = 'input parameter size is out of range'
      CALL SETVS ('2004', EXPERR,EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)

      CALL POPST (100)

      CALL RPL3 (-1, PX, PY, PZ)
 
      CALL RPM (-2, PX, PY)

      CALL RFA3 (-1, PX, PY, PZ)

      CALL SETVS ('0,1,2,3,4,5,6,7,8', COLIA, ISIZ)
      CALL RCA  (1.1,2.2, 3.3,4.4,  0,2,  1,1,1,1, COLIA)
      CALL RCA3 (PX,PY,PZ,          3,-2, 1,1,1,2, COLIA)
      CALL RCA  (1.1,2.2, 3.3,4.4, -2,-3, 1,1,2,2, COLIA)
 
      CALL SETVS ('1,2,3', NAMSET, ISIZ)
      CALL RADS (-1, NAMSET)
 
      CALL PQEP (ERRIND, ELP)
      CALL TSTIGN (ERRIND.EQ.0 .AND. ELP.EQ.0)
 
      CALL SETVS ('1,2', IS, ISN)
      CALL SETVS ('2', ES, ESN)
      CALL RSHLFT (WKID, -1, IS, ESN, ES)
      CALL RSHLFT (WKID, ISN, IS, -1, ES)
 
      CALL SETRVS ('0.,1.,0.,0.', HALFSP,ISIZ)
      CALL RSMCV (1, -1, HALFSP)
 
      CALL PCLST
 
      CALL AVARNM (ARNM)
      CALL POPARF (11, ARNM)
      CALL PDASAR (11)
 
      CALL SETVS ('100', LSTID, ISIZ)
      CALL RARST (11, -1, LSTID)
 
      CALL PRSID (11, 10, NUMARC, OUTST)
      CALL TSTIGN (NUMARC.EQ.0)
 
      CALL RREST (11, -1, LSTID)
 
      CALL RDSTAR (11, -1, LSTID)
 
      CALL PCLARF (11)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.10/e12005                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E12005 (USEPRM)
         
C  E12005 tests the handling of FORTRAN specific error 2005.
                                                            
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

      INTEGER   USEPRM, NPL, ELP, IXA(5)
      REAL      PX(6), PY(6), PZ(6)

      DATA PX/0.,0.3,0.5,1.5,3.,0./, PY/0.1,0.4,0.6,1.3,2.4,0./,
     1     PZ/0.5,0.8,1.2,0.3,1.,0./

      CURCON = 'an invalid list of point lists is specified'
      CALL SETVS ('2005', EXPERR,EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)
 
      CALL POPST (100)

      CALL SETVS ('3,6', IXA, NPL)
      CALL RFAS (-2, IXA, PX, PY)
      CALL RFAS3 (0, IXA, PX, PY, PZ)

      CALL PQEP (ERRIND, ELP)
      CALL TSTIGN (ERRIND.EQ.0 .AND. ELP.EQ.0)
   
      CALL PCLST
  
      CALL ENDERR
 
      END
