C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.04/02                           *
C  *    TEST TITLE : Error indicator = 152                 *
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

      REAL         VWWNLM(4), PJVPLM(6), PJVPL2(4)
      REAL         PRP(3), VPD, BPD, FPD, RA44(4,4), RA33(3,3)

      CALL INITGL ('09.02.04/02')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified viewport is invalid: XMIN>=XMAX, '//
     1         'YMIN>=YMAX, or ZMIN>ZMAX'
      ERRSRS = '2'
      CALL SETVS ('152', EXPERR, EXPSIZ)

C  XMIN > XMAX
      CALL SETRVS ('-462.27, -80.95, -4891.85, -94.78', VWWNLM, ASIZ)
      CALL SETRVS ('0.4082, 0.2640, 0.01339, 0.7457, 0.1395, 0.30036',
     1             PJVPLM, ASIZ)
      PJTYPE = PPARL
      CALL SETRVS ('-15.044, 1.318, 34.873', PRP, ASIZ)
      VPD = -1.213
      BPD = -3.311
      FPD = 15.332
      CALL REVMM3 (VWWNLM, PJVPLM, PJTYPE, PRP(1), PRP(2), PRP(3),
     1             VPD, BPD, FPD, ERRIND, RA44)

C  YMIN > YMAX
      CALL SETRVS ('0.2640, 0.4082, 0.7357, 0.01339, 0.1395, 0.1395',
     1             PJVPLM, ASIZ)
      CALL REVMM3 (VWWNLM, PJVPLM, PJTYPE, PRP(1), PRP(2), PRP(3),
     1             VPD, BPD, FPD, ERRIND, RA44)

C  XMIN = XMAX
      CALL SETRVS ('-62.2236, -11.39577, -60.530, 24.255',
     1             VWWNLM, ASIZ)
      CALL SETRVS ('0.1063, 0.1063, 0.1001, 0.1539, 0.2469, 0.8826',
     1             PJVPLM, ASIZ)
      PJTYPE = PPERS
      CALL SETRVS ('-3.6054E-2, 2.1181E-3, 3.0569', PRP, ASIZ)
      VPD = 0.16487
      BPD = -5.2858E-3
      FPD = 3.0531
      CALL REVMM3 (VWWNLM, PJVPLM, PJTYPE, PRP(1), PRP(2), PRP(3),
     1             VPD, BPD, FPD, ERRIND, RA44)

C  ZMIN > ZMAX
      CALL SETRVS ('0.1063, 0.2224, 0.1001, 0.1539, 0.8826, 0.2469',
     1             PJVPLM, ASIZ)
      CALL REVMM3 (VWWNLM, PJVPLM, PJTYPE, PRP(1), PRP(2), PRP(3),
     1             VPD, BPD, FPD, ERRIND, RA44)

C  XMIN > XMAX
      CALL SETRVS ('-23.32, 3.56E4, 2.29, 2.295', VWWNLM, ASIZ)
      CALL SETRVS ('0.736, 0.298, 0.22, 0.89', PJVPL2, ASIZ)
      CALL REVMM (VWWNLM, PJVPL2, ERRIND, RA33)

C  YMIN = YMAX
      CALL SETRVS ('0.298, 0.736, 0.89, 0.89', PJVPL2, ASIZ)
      CALL REVMM (VWWNLM, PJVPL2, ERRIND, RA33)

      CALL ENDIT

      END
