C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/e01001                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E01001 (USEPRM)
 
C  E01001 tests the handling of error number 1: function requires
C  state (PHCL,WSCL,STCL,ARCL).
 
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
 
      INTEGER   USEPRM
      LOGICAL   STREQ
 
      CURCON = 'PHIGS is open'
      CALL SETVS ('1', EXPERR,EXPSIZ)
      ERRSRS = '1'
      CALL ESETUP (USEPRM)
 
      CALL ROPPH (ERRFIL, MEMUN)
      CALL TSTIGN (STREQ('O***'))
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/c01002                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE C01002 (USEPRM)
 
C  C01002 tests the handling of error number 2: function requires
C  state (PHOP,*,*,*).
 
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
 
C  edit mode
      INTEGER         PINSRT,    PREPLC
      PARAMETER      (PINSRT=0,  PREPLC=1)
 
C  reference handling flag
      INTEGER         PDELE,     PKEEP
      PARAMETER      (PDELE=0,   PKEEP=1)
 
C  conflict resolution maintain,  abandon,    update
      INTEGER          PCRMNT,    PCRABA,     PCRUPD
      PARAMETER       (PCRMNT=0,  PCRABA=1,   PCRUPD=2)
 
      INTEGER   USEPRM, MODE, RNDINT, DSNT, ARCCR, RETCR
      LOGICAL   STREQ
 
      CALL IFPHCL (USEPRM)
      CALL SETVS ('2', EXPERR,EXPSIZ)
      ERRSRS = '2'
 
      CALL ROPWK (WKID, CONID, WTYPE)
      CALL TSTIGN (STREQ('CCCC'))
 
      MODE = RNDINT (PINSRT, PREPLC)
      CALL RSEDM (MODE)
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL REMST (101)
      CALL TSTIGN (STREQ('CCCC'))
 
      DSNT = RNDINT (PDELE, PKEEP)
      CALL RDSN (101, DSNT)
 
      CALL RCSTIR (101, 102)
 
      ARCCR = RNDINT (PCRMNT, PCRUPD)
      RETCR = RNDINT (PCRMNT, PCRUPD)
      CALL ROPARF (11, 24)
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL RSCNRS (ARCCR, RETCR)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/e01003                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E01003 (USEPRM)
 
C  E01003 tests the handling of error number 3: function requires
C  state (PHOP,WSOP,*,*), when PHIGS is open.
 
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
 
C  clipping indicator
      INTEGER     PNCLIP,       PCLIP
      PARAMETER  (PNCLIP=0,     PCLIP=1)
C  colour model
      INTEGER     PRGB,     PCIE,    PHSV,     PHLS
      PARAMETER  (PRGB=1,   PCIE=2,  PHSV=3,   PHLS=4)
C  control flag conditionally
      INTEGER     PCONDI,       PALWAY
      PARAMETER  (PCONDI=0,     PALWAY=1)
C  deferral mode
      INTEGER     PASAP,     PBNIG,     PBNIL,   PASTI,    PWAITD
      PARAMETER  (PASAP=0,   PBNIG=1,   PBNIL=2, PASTI=3,  PWAITD=4)
C  edge flag
      INTEGER     POFF,      PON
      PARAMETER  (POFF=0,    PON=1)
C  regenerate flag
      INTEGER     PPOSTP,    PPERFO
      PARAMETER  (PPOSTP=0,  PPERFO=1)
C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)
 
      INTEGER   USEPRM, INC(3), EXC(3), ISIZ
      LOGICAL   STREQ
 
      CURCON = 'PHIGS is open but all workstations are closed'
 
      CALL SETVS ('3,54', EXPERR,EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)
 
      CALL RCLWK (WKID)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RRST (WKID, PCONDI)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RUWK (WKID, PPOSTP)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RSPMR (WKID, 1,1,1.0,1)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RSIR (WKID, 1, PHOLLO, 1, 1)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL SETVS ('2,3,5', INC, ISIZ)
      CALL SETVS ('6', EXC, ISIZ)
      CALL RSIVFT (WKID, 3, INC, 1, EXC)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RSHRM (WKID, 1)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RSWKW (WKID, 0., 1., 0., 1.)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RSWKV (WKID, 0., 1., 0., 1.)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RUPOST (WKID, 101)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/c01003                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE C01003 (USEPRM)
 
C  C01003 tests the handling of error number 3: function requires
C  state (PHOP,WSOP,*,*), when PHIGS is closed.
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)
 
      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20
 
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
 
C  clipping indicator
      INTEGER     PNCLIP,       PCLIP
      PARAMETER  (PNCLIP=0,     PCLIP=1)
C  colour model
      INTEGER     PRGB,     PCIE,    PHSV,     PHLS
      PARAMETER  (PRGB=1,   PCIE=2,  PHSV=3,   PHLS=4)
C  control flag conditionally
      INTEGER     PCONDI,       PALWAY
      PARAMETER  (PCONDI=0,     PALWAY=1)
C  deferral mode
      INTEGER     PASAP,     PBNIG,     PBNIL,   PASTI,    PWAITD
      PARAMETER  (PASAP=0,   PBNIG=1,   PBNIL=2, PASTI=3,  PWAITD=4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C  edge flag
      INTEGER     POFF,      PON
      PARAMETER  (POFF=0,    PON=1)
C  regenerate flag
      INTEGER     PPOSTP,    PPERFO
      PARAMETER  (PPOSTP=0,  PPERFO=1)
 
      INTEGER   USEPRM, INC(3), EXC(3), DEFMOD, MODMOD, ISIZ, RNDINT
      REAL      XFRMT(3,3), LIMT(4)
      LOGICAL   STREQ
 
      CALL IFPHCL (USEPRM)
      CALL SETVS ('3,54', EXPERR,EXPSIZ)
      ERRSRS = '3'
 
      CALL RCLWK (WKID)
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL RRST (WKID, PCONDI)
 
      CALL RUWK (WKID, PPOSTP)
 
      DEFMOD = RNDINT (PASAP, PWAITD)
      MODMOD = RNDINT (PNIVE, PUQUM)
      CALL RSDUS (WKID, DEFMOD, MODMOD)
 
      CALL RSPLR (WKID, 1, 1, 1.0, 0)
 
      CALL RSEDR (WKID, 1, PON, 1, 1.0, 0)
 
      CALL SETVS ('2,3,5', INC, ISIZ)
      CALL SETVS ('6', EXC, ISIZ)
      CALL RSHLFT (WKID, 3, INC, 1, EXC)
 
      CALL RSCMD (WKID, PRGB)
 
      CALL IDMAT (3, XFRMT)
      CALL SETRVS ('0.,1.,0.,1.', LIMT, ISIZ)
      CALL RSVWR (WKID, 1, XFRMT, XFRMT, LIMT, PCLIP)
 
      CALL RSWKW (WKID, 0., 1., 0., 1.)
 
      CALL RSWKV (WKID, 0., 1., 0., 1.)
 
      CALL RPOST (WKID, 101, 0.5)
 
      CALL RUPAST (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/e01004                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E01004 (USEPRM)
 
C  E01004 tests the handling of error number 4: function requires
C  state (PHOP,WSCL,STCL,ARCL) when PHIGS is open.
 
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
 
      INTEGER   USEPRM, ARNM
 
      LOGICAL   STREQ
 
      CALL SETVS ('4', EXPERR,EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CURCON = 'PHIGS is open and a workstation is open'
      CALL RCLPH
      CALL TSTIGN (STREQ('OO**'))
 
      CALL PCLWK (WKID)
      CALL POPST (101)
      CURCON = 'PHIGS is open and a structure is open'
      CALL RCLPH
      CALL TSTIGN (STREQ('OCO*'))
 
      CALL PCLST
      CALL AVARNM (ARNM)
      CALL POPARF (11, ARNM)
      CURCON = 'PHIGS is open and an archive file is open'
      CALL RCLPH
      CALL TSTIGN (STREQ('OCCO'))
 
      CALL PCLARF (11)
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/c01004                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE C01004 (USEPRM)
 
C  C01004 tests the handling of error number 4: function requires
C  state (PHOP,WSCL,STCL,ARCL) when PHIGS is closed.
 
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
 
      INTEGER   USEPRM
 
      LOGICAL   STREQ
 
      CALL IFPHCL (USEPRM)
      CALL SETVS ('4', EXPERR,EXPSIZ)
      ERRSRS = '4'
 
      CALL RCLPH
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/e01005                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
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
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/c01005                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
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
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/e01006                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E01006 (USEPRM)
 
C  E01006 tests the handling of error number 6: function requires
C  state (PHOP,*,STCL,*) when PHIGS is open.
 
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
 
C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)
 
C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)
 
      INTEGER   USEPRM, ERRIND, OPSTAT, OPID
 
      LOGICAL   STREQ
 
      CURCON = 'PHIGS is open and a structure is open'
      CALL SETVS ('6', EXPERR,EXPSIZ)
      ERRSRS = '6'
      CALL ESETUP (USEPRM)
 
      CALL POPST (101)
      CALL ROPST (102)
      CALL PQOPST (ERRIND, OPSTAT, OPID)
      CALL CHKINQ ('pqopst', ERRIND)
      CALL TSTIGN (STREQ('O*O*') .AND. OPSTAT.EQ.POPNST .AND.
     1             OPID.EQ.101)
 
      CALL PCLST
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/c01006                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE C01006 (USEPRM)
 
C  C01006 tests the handling of error number 6: function requires
C  state (PHOP,*,STCL,*) when PHIGS is closed.
 
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
 
      INTEGER   USEPRM
 
      LOGICAL   STREQ
 
      CALL IFPHCL (USEPRM)
      CALL SETVS ('6', EXPERR,EXPSIZ)
      ERRSRS = '6'
 
      CALL ROPST (101)
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/e01007                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E01007 (USEPRM)
 
C  E01007 tests the handling of error number 7: function requires
C  state (PHOP,*,*,AROP), when PHIGS is open.
 
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
 
C  path order
      INTEGER      PPOTOP,     PPOBOT
      PARAMETER   (PPOTOP=0,   PPOBOT=1)
 
      INTEGER   ARID, STID, STLIST(2), PATHOD, PATHDP, N, OL,
     1          USEPRM, APTHSZ, PATHS(2, 10)
 
      LOGICAL   STREQ
 
      CURCON = 'PHIGS is open but no archive file is open'
      CALL SETVS ('7,404', EXPERR,EXPSIZ)
      ERRSRS = '7'
      CALL ESETUP (USEPRM)
 
      CALL POPST (100)
      CALL PTX (0.5,0.5,'TEXT')
      CALL PEXST (101)
      CALL PCLST
      CALL POPST (101)
      CALL PTX (0.3,0.7,'TEXT')
      CALL PCLST
 
      ARID = 11
      STID = 101
      STLIST(1) = 100
      STLIST(2) = 101
      PATHOD = PPOTOP
      PATHDP = 0
 
      CALL RCLARF (ARID)
      CALL TSTIGN (STREQ('O**C'))
 
      CALL RARST (ARID, 2, STLIST)
      CALL TSTIGN (STREQ('O**C'))
 
      CALL RRSID (ARID, 2, N, STLIST)
 
      CALL RREST (ARID, 2, STLIST)
 
      CALL RRAST (ARID)
      CALL TSTIGN (STREQ('O**C'))
 
      CALL RREPAN (ARID, STID, PATHOD, PATHDP, 10, 0, OL,
     1             APTHSZ, PATHS)
      CALL TSTIGN (STREQ('O**C'))
 
      CALL RDSTAR (ARID, 2, STLIST)
      CALL TSTIGN (STREQ('O**C'))
 
      CALL ENDERR
 
      END
 
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/c01007                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE C01007 (USEPRM)
 
C  C01007 tests the handling of error number 7: function requires
C  state (PHOP,*,*,AROP), when PHIGS is closed.
 
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
 
C  path order
      INTEGER      PPOTOP,     PPOBOT
      PARAMETER   (PPOTOP=0,   PPOBOT=1)
 
      INTEGER   ARID, STID, STLIST(2), PATHOD, PATHDP, N, OL,
     1          USEPRM, APTHSZ, PATHS(2, 10)
 
      LOGICAL   STREQ
 
      CALL IFPHCL (USEPRM)
      CALL SETVS ('7,404', EXPERR,EXPSIZ)
      ERRSRS = '7'

      ARID = 11
      STID = 100
      STLIST(1) = 100
      STLIST(2) = 101
      PATHOD = PPOTOP
      PATHDP = 0
 
      CALL RCLARF (ARID)
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL RARST (ARID, 2, STLIST)
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL RRSID (ARID, 2, N, STLIST)
 
      CALL RREST (ARID, 2, STLIST)
 
      CALL RRAST (ARID)
 
      CALL RREPAN (ARID, STID, PATHOD, PATHDP, 10, 0, OL,
     1             APTHSZ, PATHS)
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL RDSTAR (ARID, 2, STLIST)
      CALL TSTIGN (STREQ('CCCC'))
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.01/ifphcl                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE IFPHCL (USEPRM)
 
C  IFPHCL initializes things for the special case where error
C  handling is to be tested in the state where PHIGS is closed.
C  This requires special handling, since ordinarily the error
C  file will not be available for writing.
 
C  Input parameters:
C    USEPRM : Handling mode: 1 for user, 2 for system
 
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
 
      INTEGER   USEPRM
 
      CURCON = 'PHIGS is closed'
C  add 2 to "normal" USRERR value to signify PHCL
      CALL ESETUP (USEPRM+2)
      CALL PCLPH
 
      END
