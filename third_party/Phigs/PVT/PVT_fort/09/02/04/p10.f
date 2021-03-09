C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.04/10                           *
C  *    TEST TITLE : Error indicator = 164                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C   viewtype
      INTEGER      PPARL,    PPERS
      PARAMETER   (PPARL=0,  PPERS=1)

      INTEGER      PJTYPE, ASIZ

      REAL         VWWNLM(4), PJVPLM(6)            
      REAL         PRP(3), VPD, BPD, FPD, RA44(4,4)

      CALL INITGL ('09.02.04/10')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the back plane is in front of the front plane'
      ERRSRS = '10'
      CALL SETVS ('164', EXPERR, EXPSIZ)

      CALL SETRVS ('-462.27, -80.95, -4891.85, -94.78', VWWNLM, ASIZ)
      CALL SETRVS ('0.2640, 0.4082, 0.01339, 0.7457, 0.1395, 0.30036',
     1             PJVPLM, ASIZ)
      PJTYPE = PPARL
      CALL SETRVS ('-15.044, 1.318, 34.873', PRP, ASIZ)
      VPD = -1.213
      BPD = -3.311
      FPD = -15.332
      CALL REVMM3 (VWWNLM, PJVPLM, PJTYPE, PRP(1), PRP(2), PRP(3),
     1             VPD, BPD, FPD, ERRIND, RA44)

      CALL SETRVS ('-62.2236, -11.39577, -60.530, 24.255',
     1             VWWNLM, ASIZ)
      CALL SETRVS ('0.1039, 0.2243, 0.1012, 0.1592, 0.2495, 0.8862',
     1             PJVPLM, ASIZ)
      PJTYPE = PPERS
      CALL SETRVS ('-3.6054E-2, 2.1181E-3, 3.0569', PRP, ASIZ)
      VPD = 0.16487
      BPD = 5.2858E-3
      FPD = 3.0531E-3
      CALL REVMM3 (VWWNLM, PJVPLM, PJTYPE, PRP(1), PRP(2), PRP(3),
     1             VPD, BPD, FPD, ERRIND, RA44)

      CALL ENDIT

      END

