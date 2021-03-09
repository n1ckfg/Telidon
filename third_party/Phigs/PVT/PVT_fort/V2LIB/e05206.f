      SUBROUTINE E05206 (USEPRM)

C  E05206 tests the handling of error 206.

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

      INTEGER     USEPRM,ELPNT1,ELPNT2
      REAL        XA(2), YA(2)
      LOGICAL     STREQ

      CURCON = 'one or both of the labels does not exist in the ' //
     1         'open structure between the element pointer and '  //
     2         'the end of the structure'
      CALL SETVS ('206', EXPERR, EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)

      XA(1) = 0.
      YA(1) = 0.5
      XA(2) = 1.
      YA(2) = 1.

      CALL POPST (100)

      CALL PQEP (ERRIND, ELPNT1)
      CALL CHKINQ ('pqep', ERRIND)
      CALL RDELLB (1, 2)
      CALL PQEP (ERRIND, ELPNT2)
      CALL CHKINQ ('pqep', ERRIND)
      CALL TSTIGN (STREQ('O*O*') .AND. ELPNT1.EQ.ELPNT2)

      CALL PPL (2, XA, YA)
      CALL PLB (1)
      CALL PPM (2, XA, YA)
      CALL PLB (2)

      CALL POSEP (-1)
      CALL PQEP (ERRIND, ELPNT1)
      CALL CHKINQ ('pqep', ERRIND)
      CALL RDELLB (1, 2)
      CALL PQEP (ERRIND, ELPNT2)
      CALL CHKINQ ('pqep', ERRIND)
      CALL TSTIGN (STREQ('O*O*') .AND. ELPNT1.EQ.ELPNT2)

      CALL PSEP (0)
      CALL RDELLB (2,4)

      CALL PCLST

      CALL ENDERR

      END
