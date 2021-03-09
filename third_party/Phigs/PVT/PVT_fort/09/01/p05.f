C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01/05                              *
C  *    TEST TITLE : Error logging function for default    *
C  *                 error handling                        *
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

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER    EUPOST,     EUPAST,     EOPARF,     ECLARF
      PARAMETER (EUPOST=112, EUPAST=113, EOPARF=114, ECLARF=115)

      CALL INITGL ('09.01/05')
      ERRSRS = '9'
      CURCON = '<Error logging> should write the specified error ' //
     1         'message on the error file.'
C  expected error
      CALL SETVS ('59', EXPERR, EXPSIZ)
      CALL ESETUP (5)

      CALL PSERHM (POFF)
C  simulate error #59 for <unpost all structures>
      CALL PERLOG (59, EUPAST, ERRFIL)
C  expected function
      CALL ECHKZ  (EUPAST)

      CALL ENDERR

      CALL ENDIT

      END
