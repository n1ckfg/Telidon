C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01/02                              *
C  *    TEST TITLE : User error handling capabilities      *
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


C PHIGS function names (for those functions which signal error)
      INTEGER    EPL3,       EPL,        EPM3,       EPM
      PARAMETER (EPL3  =008, EPL   =009, EPM3  =010, EPM   =011)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER         ISIZ, N
      REAL PXA(2), PYA(2)

      CALL INITGL ('09.01/02')

      CALL ESETUP (1)

      CALL SETRVS ('0.,0.5', PXA, ISIZ)
      CALL SETRVS ('0.,0.5', PYA, ISIZ)
      N = 2

      CALL SETMSG ('1 5 7', 'If error handling mode is ON, and no ' //
     1             'structure is open, then <polyline> should ' //
     2             'return error number, function identifier, and ' //
     3             'error file to the user defined error handler.')

      CALL PSERHM (PON)
      ERRCOM = 999
      FUNCOM = 999
      FILCOM = 999
      CALL ERRCTL (.TRUE.)
      CALL PPL (N, PXA, PYA)
      CALL ERRCTL (.FALSE.)

      CALL IFPF (ERRCOM.EQ.5 .AND. FUNCOM.EQ.EPL .AND. FILCOM.EQ.ERRFIL)

      CALL SETMSG ('1 10', 'If error handling mode is OFF, and no ' //
     1             'structure is open, then <polyline> should not ' //
     2             'return error number, function identifier and ' //
     3             'error file to the user defined error handler.')

      CALL PSERHM (POFF)
      ERRCOM = 999
      FUNCOM = 999
      FILCOM = 999
      CALL ERRCTL (.TRUE.)
      CALL PPL (2, PXA, PYA)
      CALL ERRCTL (.FALSE.)

      CALL IFPF (ERRCOM .EQ. 999 .AND. FUNCOM .EQ. 999 .AND.
     1           FILCOM .EQ. 999)

      CALL ENDIT

      END
