      SUBROUTINE C01005 (USEPRM)

C  C01005 tests the handling of error number 5: function requires
C  state (PHOP,*,STOP,*), when PHIGS is closed.

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

C   aspect identifier
      INTEGER      PLN
      PARAMETER   (PLN = 0)
C   aspect source
      INTEGER      PINDIV
      PARAMETER   (PINDIV = 1)
C   composition  type
      INTEGER      PCREPL
      PARAMETER   (PCREPL = 2)

      INTEGER USEPRM, N, NPL, IXA(2), ISIZ, NAMEST(1)
      REAL    PXA(10), PYA(10), PZA(10), XFRMT(3,3)

      LOGICAL   STREQ

      CALL IFPHCL (USEPRM)
      CALL SETVS ('5', EXPERR,EXPSIZ)
      ERRSRS = '5'

      N = 2
      PXA(1) = 0.
      PXA(2) = 0.5
      PYA(1) = 0.
      PYA(2) = 0.5
      PZA(1) = 0.
      PZA(2) = 0.5

      CALL RPM (N, PXA, PYA)
      CALL TSTIGN (STREQ('CCCC'))

      CALL RATR (0., 0., 0.1, 0.1, 'annotation-text')

      NPL = 1
      IXA(1) = 4
      CALL SETRVS ('0.,0.4,0.4,0.',PXA,ISIZ)
      CALL SETRVS ('0.,0.,0.4,0.4',PYA,ISIZ)
      CALL RFAS (NPL, IXA, PXA, PYA)

      CALL RSII (1)

      CALL RSMKSC (1.0)

      CALL RSTXFN (1)

      CALL RSANS (1)

      CALL RSPARF (0., 0.)

      CALL RRES (1, NAMEST)

      CALL RSHRID (33)

      CALL IDMAT (3, XFRMT)
      CALL RSGMT (XFRMT)

      CALL RCLST

      CALL RLB (100)

      CALL RSEP (200)
      CALL TSTIGN (STREQ('CCCC'))

      CALL ENDERR

      END
