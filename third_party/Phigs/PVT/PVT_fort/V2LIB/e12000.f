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
