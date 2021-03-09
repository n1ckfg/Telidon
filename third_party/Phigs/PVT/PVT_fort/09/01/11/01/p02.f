C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01.11.01/02                        *
C  *    TEST TITLE : First call <set error handler>        *
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


      CALL INITGL ('09.01.11.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)



C  DESIGN:
C  (1) Generates an error using default system error handling subroutine
C  "perr_hand" which will be written in error file.
C  (2) Set error handler to "my_err_handler" and return old error handler.
C  Generates an error.
C  (3) Set error handler to old error handler, and generates an error which
C  will be stored in error file.
C  (4) Rewind error file, read two error messages and compare them to test
C  if <set error handler> returns system error handler when called first time.
C  
C  **** **** ****
C  
C  cur_error=0, cur_function=555
C  
C  <open phigs>
C  <text>: signals error
C  <set error handler> with (my_err_handler, default_err_handler)
C  <text>: signals error
C  <set error handler> with (default_err_handler, old_err_handler)
C  <text>: signals error
      CALL SETMSG ('3', '<Set error handler> should return default ' //
     1             'system error handler when called first time.')


C  
C  rewind error file
C  get first error massage from error file and store at mesg1
C  get second error message from error file and store at mesg2
C  pass/fail depending of (mesg1 = mesg2)
C  
C  <close phigs>
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
