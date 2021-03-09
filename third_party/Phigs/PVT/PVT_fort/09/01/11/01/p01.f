C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01.11.01/01                        *
C  *    TEST TITLE : Function of <Set error handler>       *
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


      CALL INITGL ('09.01.11.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)



C  DESIGN:
C  (1) Design a new error handler "my_err_hand" which saves error code and
C  function identifier at cur_error, cur_function with initial cur_error=0,
C  cur_function = 555.
C  (2) Use user defined "perr_hand" which is used by other test programs and
C  generates  an error. The error information will be stored at common variable
C  errsav[0], funsav[0].
C  (3) Use <set error handler> to set a new error handler as "my_err_handler"
C  and  return old error handler. Generate an error using same function with (2).
C  Compare cur_error with errsav[0], cur_function with funsav[0] to test
C  if "my_err_hand" is invoked.
C  (4) Set error handler back to old error handler. Generate an error again.
C  It should be stored in errsav[1], funsav[1]. Compare errsav[0] with errsav[1],
C  funsav[0] with funsav[1] to test if <set error handler> returned correct
C  error handler.
C  
C  *** *** ***
C  
C  cur_error=0, cur_function=555
C  
C  <open phigs>
C  <text>: signals error
C  <set error handler> with (my_err_handler, old_err_handler)
C  <text>: signals error
      CALL SETMSG ('1', '<Set error handler> should set PHIGS error ' //
     1             'handler to application defined error handler ' //
     2             'specified with parameter new error handling ' //
     3             'function.')


C  pass/fail depending on (cur_error = errsav[0]       and
C                          cur_function = funsav[0])
C  
C  <set error handler> with (old_err_handler, new_err_handler)
C  <text>: signals error
      CALL SETMSG ('2', '<set error handler> should return previous ' //
     1             'error handling subroutine.')


C  pass/fail depending on (errsav[1] = errsav[0]      and
C                          funsav[1] = funsav[0])
C  
C  <close phigs>
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
