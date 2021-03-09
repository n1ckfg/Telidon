C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 11.02/05                              *
C  *    TEST TITLE : Create store and delete store         *
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

C  Declare program-specific variables


      CALL INITGL ('11.02/05')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)



C  DESIGN:
C  
      CALL SETMSG ('13', '<Create store> should return a non-null ' //
     1             'pointer.')


C  <create store> to set ptr
C  pass/fail depending on (error indicator = 0 and ptr not= null)
C  
      CALL SETMSG ('14', '<Delete store> should return a null ' //
     1             'pointer.')


C  <delete store> to set ptr
C  pass/fail depending on (error indicator = 0 and ptr = null)
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
