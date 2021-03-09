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
