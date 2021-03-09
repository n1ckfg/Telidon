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
