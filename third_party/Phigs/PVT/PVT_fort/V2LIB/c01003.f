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
