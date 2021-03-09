      SUBROUTINE E01005 (USEPRM)

C  E01005 tests the handling of error number 5: function requires
C  state (PHOP,*,STOP,*), when PHIGS is open.

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
C modelling clipping operator
C                replace     intersect
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)

      INTEGER OP, USEPRM, N, ISIZ, NAMEST(1)
      REAL    PXA(10), PYA(10), PZA(10), XFRMT(3,3), HALFSP(4,2)

      LOGICAL   STREQ

      CURCON = 'PHIGS is open but no structure is open'
      CALL SETVS ('5', EXPERR,EXPSIZ)
      ERRSRS = '5'
      CALL ESETUP (USEPRM)

      N = 2
      PXA(1) = 0.
      PXA(2) = 0.5
      PYA(1) = 0.
      PYA(2) = 0.5
      PZA(1) = 0.
      PZA(2) = 0.5
      CALL RPL3 (2, PXA, PYA, PZA)
      CALL TSTIGN (STREQ('O*C*'))

      CALL RTX (0., 0.5, 'TEXT')

      CALL SETRVS ('0.,0.5,0.5,0.', PXA, ISIZ)
      CALL SETRVS ('0.,0.,0.5,0.5', PYA, ISIZ)
      CALL RFA (N, PXA, PYA)

      CALL RSPLI (1)

      CALL RSLN (1)

      CALL RSPMCI (1)

      CALL RSCHXP (1.0)

      CALL RSEDFG (1)

      NAMEST(1) = 1
      CALL RADS (1, NAMEST)

      CALL RSIASF (PLN, PINDIV)

      CALL IDMAT (3, XFRMT)
      CALL RSLMT (XFRMT, PCREPL)

      OP = PMCREP
      N = 2
      CALL SETRVS ('0.52,0.,-1.,0.,0.48,0.,1.,0.',HALFSP,ISIZ)
      CALL RSMCV (OP, N, HALFSP)

      CALL REXST (101)
      CALL TSTIGN (STREQ('O*C*'))

      CALL RCELST (101)
      CALL TSTIGN (STREQ('O*C*'))

      CALL RDEL
      CALL TSTIGN (STREQ('O*C*'))

      CALL ENDERR

      END
