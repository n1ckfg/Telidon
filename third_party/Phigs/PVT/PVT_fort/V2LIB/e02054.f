      SUBROUTINE E02054 (USEPRM)

C  E02054 tests the handling of error number 54

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

C control flag
C                conditionally  always
      INTEGER    PCONDI,        PALWAY
      PARAMETER (PCONDI = 0,    PALWAY = 1)
C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C relative input priority
      INTEGER     PHIGHR,     PLOWER
      PARAMETER  (PHIGHR=0,   PLOWER=1)
C deferring model
      INTEGER     PASAP,     PBNIG,    PBNIL,    PAST1,    PWAIT
      PARAMETER  (PASAP=0,   PBNIG=1,  PBNIL=2,  PAST1=3,  PWAIT=4)

      INTEGER   USEPRM, COLIA(1,1), ISIZ, XYCLPI, BCLIPI
      INTEGER   FCLIPI, NUMOWK, OPWKID
      REAL      VWORMT(4,4), VWMPMT(4,4), VWCPLM(6), CSPEC(3)
      LOGICAL   STREQ

      CURCON = 'the specified workstation is not open'

      CALL SETVS ('54,3', EXPERR, EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)

C   generate errors
      CALL RCLWK (WKID)
      CALL TSTIGN (STREQ('OC**'))

      CALL RRST (WKID, PALWAY)
      CALL TSTIGN (STREQ('OC**'))

      CALL RUWK (WKID, PPERFO)
      CALL TSTIGN (STREQ('OC**'))

      CALL RSTXR (WKID, 1, 1, PSTRP, 1., 0.1, 1)
      CALL TSTIGN (STREQ('OC**'))

      CALL SETVS ('1', COLIA, ISIZ)
      CALL RSPAR (WKID, 1,1,1,1,1,1,1, COLIA)

      CALL SETRVS ('1.,0.,0.', CSPEC, ISIZ)
      CALL RSCR (WKID, 1, 3, CSPEC)

      CALL RSHRM (WKID, 0)

      CALL IDMAT (4, VWORMT)
      CALL IDMAT (4, VWMPMT)
      CALL SETRVS ('0.,1.,0.,1.,0.,1.', VWCPLM, ISIZ)
      XYCLPI = PCLIP
      BCLIPI = PCLIP
      FCLIPI = PCLIP
      CALL RSVWR3 (WKID, 1, VWORMT, VWMPMT, VWCPLM, XYCLPI, BCLIPI,
     1             FCLIPI)

      CALL RSVTIP (WKID, 1, 1, PHIGHR)

      CALL POPST (101)
      CALL RUPOST (WKID, 101)
      CALL TSTIGN (STREQ('OCO*'))
      CALL PCLST

      CALL POPWK (WKID, CONID, WTYPE)

      CALL RRST (WKID+1, PALWAY)
      CALL PQOPWK (1, ERRIND, NUMOWK, OPWKID)
      CALL CHKINQ ('pqopwk', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. NUMOWK.EQ.1 .AND.
     1             OPWKID.EQ.WKID)

      CALL RSDUS (WKID+1, PASAP, PNIVE)

      CALL RSPAR (WKID+1, 1,1,1,1,1,1,1, COLIA)

      CALL RSWKW (WKID+1, 0.,1.,0.,1.)
      CALL PQOPWK (1, ERRIND, NUMOWK, OPWKID)
      CALL CHKINQ ('pqopwk', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. NUMOWK.EQ.1 .AND.
     1             OPWKID.EQ.WKID)

      CALL POPST (101)
      CALL RPOST (WKID+1, 101, 1.0)
      CALL PQOPWK (1, ERRIND, NUMOWK, OPWKID)
      CALL CHKINQ ('pqopwk', ERRIND)
      CALL TSTIGN (STREQ('OOO*') .AND. NUMOWK.EQ.1 .AND.
     1             OPWKID.EQ.WKID)

      CALL PCLST
      CALL PCLWK (WKID)

C  examine saved errors

      CALL ENDERR

      END
