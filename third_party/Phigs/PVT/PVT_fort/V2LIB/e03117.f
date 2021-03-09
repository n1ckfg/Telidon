      SUBROUTINE E03117 (USEPRM)

C  E03117 tests the handling of Error 117.

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

      INTEGER   USEPRM, DX, DY, COLIA(2,3),ISIZ
      REAL      PX,PY, QX,QY, CPXA(3), CPYA(3), CPZA(3)
      LOGICAL   STREQ, STRCON

      CURCON = 'one of the dimensions of the colour index array '//
     1         'is less than one'
      CALL SETVS ('117', EXPERR, EXPSIZ)
      ERRSRS = '16'
      CALL ESETUP (USEPRM)

      CALL POPST (100)
      CALL PLB   (801)

      CALL SETVS ('1,1,1,0,0,1', COLIA, ISIZ)
      CALL SETRVS ('0.,3.,4.', CPXA, ISIZ)
      CALL SETRVS ('0.,1.,0.', CPYA, ISIZ)
      CALL SETRVS ('0.,0.,0.', CPZA, ISIZ)

      DX = -1
      DY = 3
      CALL RCA3 (CPXA,CPYA,CPZA,2,3,1,1,DX,DY,COLIA)
      CALL TSTIGN (STREQ('O*O*') .AND. STRCON(100, '67,801'))

      DX = 3
      DY = 0
      CALL RCA3 (CPXA,CPYA,CPZA,2,3,1,1,DX,DY,COLIA)
 
      PX = 1.
      PY = 0.
      QX = 3.
      QY = 2.
      DX = 0
      DY = 3
      CALL RCA (PX,PY,QX,QY,2,3,1,1,DX,DY,COLIA)
 
      DX = 2
      DY = -2
      CALL RCA (PX,PY,QX,QY,2,3,1,1,DX,DY,COLIA)
 
      CALL RCA (PX,PY,QX,QY,2,3,1,1,0,3,COLIA)
      CALL RCA3 (CPXA,CPYA,CPZA,2,3,1,1,2,0,COLIA)
      CALL TSTIGN (STREQ('O*O*') .AND. STRCON(100, '67,801'))
 
      CALL PCLST
 
      CALL ENDERR

      END
