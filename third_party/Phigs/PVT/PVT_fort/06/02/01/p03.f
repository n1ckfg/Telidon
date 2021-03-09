C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.01/03                           *
C  *    TEST TITLE : Behavior of 2D mapping                *
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
      REAL       VWWNLM(4), PJVPLM(4), ACT3X3(3,3), EXP3X3(3,3)
      LOGICAL    TRNSEQ
      CHARACTER  MSG*300
 
      CALL INITGL ('06.02.01/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('1 2 11 12 13', '<Evaluate view mapping matrix> '  //
     1             'should return a correct representation for the '  //
     2             'transformation from the view window to the 2D '   //
     3             'projection viewport.')
 
C  Set 2D mapping parameters:
      VWWNLM(1) = -23.32
      VWWNLM(2) = 3.56E4
      VWWNLM(3) = 2.29
      VWWNLM(4) = 2.295
 
      PJVPLM(1) = 0.298
      PJVPLM(2) = 0.736
      PJVPLM(3) = 0.22
      PJVPLM(4) = 0.89
 
C  <Evaluate view mapping matrix> returns act3x3 = actual array
      CALL PEVMM (VWWNLM, PJVPLM, ERRIND, ACT3X3)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5)')
     1         'Non-zero error code from PEVMM:', ERRIND
         CALL INMSG (MSG)
         GOTO 666
      ENDIF
 
C  Compute exp3x3 = expected array
      CALL EEVMM (VWWNLM, PJVPLM, EXP3X3)
 
C  pass/fail depending on (act3x3 represents same transformation as exp3x3)
      CALL IFPF (TRNSEQ (3, ACT3X3, EXP3X3))
 
666   CONTINUE
      CALL ENDIT
      END
