C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01/04                              *
C  *    TEST TITLE : Default error handling with error     *
C  *                 mode OFF                              *
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

      INTEGER         POFF,      PON
      PARAMETER      (POFF=0,    PON=1)

      INTEGER    ISIZ, N
      REAL       PXA(2), PYA(2), PZA(2)

      CALL INITGL ('09.01/04')

      ERRSRS = '1 4 10'
      CURCON = 'If error handling mode is OFF, and no structure is ' //
     1         'open, then <polyline> should not write any error ' //
     2         'message to error file.'
      CALL SETVS ('5', EXPERR, EXPSIZ)
      CALL ESETUP (5)

      CALL SETRVS ('0.,0.5', PXA, ISIZ)
      CALL SETRVS ('0.,0.5', PYA, ISIZ)
      N = 2

      CALL PSERHM (POFF)
      CALL PPL (N, PXA, PYA)
      CALL PSERHM (PON)
      CALL RPL3 (N, PXA, PYA, PZA)
      CALL ENDERR

666   CONTINUE

      CALL ENDIT

      END
