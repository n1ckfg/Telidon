      SUBROUTINE E05205 (USEPRM)

C  E05205 tests the handling of error 205.

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

      INTEGER     USEPRM, ELPNT1, ELPNT2
      REAL        XA(2), YA(2)
      LOGICAL     STREQ

      CURCON = 'the specified label does not exist '//
     1         'in the open structure between the element pointer '//
     2         'and the end of the structure'
      CALL SETVS ('205', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)

      CALL POPST (100)

      XA(1) = 0.
      XA(2) = 0.5
      YA(1) = 0.
      YA(2) = 0.5
      CALL PPL (2, XA, YA)

      CALL PQEP (ERRIND, ELPNT1)
      CALL CHKINQ ('pqep', ERRIND)
      CALL RSEPLB (1)
      CALL PQEP (ERRIND, ELPNT2)
      CALL CHKINQ ('pqep', ERRIND)
      CALL TSTIGN (STREQ('O*O*') .AND. ELPNT1.EQ.ELPNT2)

      CALL PLB (1)
      CALL PPL (2, XA, YA)
      CALL PLB (2)
      CALL POSEP (-1)
      CALL RSEPLB (1)

      CALL PCLST

      CALL ENDERR

      END
