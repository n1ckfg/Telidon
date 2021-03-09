C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 11.02/01                              *
C  *    TEST TITLE : Definition of macros in phigs.h       *
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


      CALL INITGL ('11.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)



C  DESIGN:
C  
C  This program exploits the ifdef facility of the C-preprocessor.
C  In order to pass, every required macro must be defined to the
C  correct value.  If a macro is undefined or defined to the wrong
C  value, the test case fails.
C  
C  For every required macro with a numeric value, check that it is
C  defined to the correct value.
C  
C  for expfun = expected function identifiers
C     macnam = name of macro for expfun
         CALL SETMSG ('1 2', macnam // ' should be defined as ' //
     1                expfun // '.')


C     #ifdef macnam
C        pass/fail depending on (macnam = expfun)
C     #else
C        fail
C     #endif
C  next expfun
C  
C  for experr = expected error codes
C     macnam = name of macro for experr
         CALL SETMSG ('1 3', macnam // ' should be defined as ' //
     1                experr // '.')


C     #ifdef macnam
C        pass/fail depending on (macnam = experr)
C     #else
C        fail
C     #endif
C  next experr
C  
C  for explin = expected linetypes
C     macnam = name of macro for explin
         CALL SETMSG ('1 4', macnam // ' should be defined as ' //
     1                explin // '.')


C     #ifdef macnam
C        pass/fail depending on (macnam = explin)
C     #else
C        fail
C     #endif
C  next explin
C  
C  for expmrk = expected marker types
C     macnam = name of macro for expmrk
         CALL SETMSG ('1 5', macnam // ' should be defined as ' //
     1                expmrk // '.')


C     #ifdef macnam
C        pass/fail depending on (macnam = expmrk)
C     #else
C        fail
C     #endif
C  next expmrk
C  
C  for expann = expected annotation styles
C     macnam = name of macro for expann
         CALL SETMSG ('1 6', macnam // ' should be defined as ' //
     1                expann // '.')


C     #ifdef macnam
C        pass/fail depending on (macnam = expann)
C     #else
C        fail
C     #endif
C  next expann
C  
C  for expcmd = expected colour models
C     macnam = name of macro for expcmd
         CALL SETMSG ('1 7', macnam // ' should be defined as ' //
     1                expcmd // '.')


C     #ifdef macnam
C        pass/fail depending on (macnam = expcmd)
C     #else
C        fail
C     #endif
C  next expcmd
C  
C  for exppet = expected prompt and echo types
C     macnam = name of macro for exppet
         CALL SETMSG ('1 8', macnam // ' should be defined as ' //
     1                exppet // '.')


C     #ifdef macnam
C        pass/fail depending on (macnam = exppet)
C     #else
C        fail
C     #endif
C  next exppet
C  end processing of numeric macros
C  
C  for expsym = expected enumeration constant values
C     macnam = name of macro for expsym
         CALL SETMSG ('1 10', macnam // ' should be defined as ' //
     1                expsym // '.')


C     #ifdef macnam
C        pass/fail depending on (macnam = expsym)
C     #else
C        fail
C     #endif
C  next expsym
C  
      CALL SETMSG ('1 9', 'PDEF_MEM_SIZE should be defined as ' //
     1             '((size_t) (-1)).')


C  
C  #ifdef PDEF_MEM_SIZE
C     exp_def_mem = ((size_t) (-1))
C     pass/fail depending on (exp_def_mem = PDEF_MEM_SIZE)
C  #else
C     fail
C  #endif
C  
      CALL SETMSG ('1 9', 'PDEF_ERR_FILE should be defined as ' //
     1             '((char *) (0)).')


C  
C  #ifdef PDEF_ERR_FILE
C     exp_def_err = ((char *) (0))
C     pass/fail depending on (exp_def_err = PDEF_ERR_FILE)
C  #else
C     fail
C  #endif
C  
      CALL SETMSG ('1 15', 'Size_t should be defined to some ' //
     1             'implementation dependent value.')


C  #ifdef size_t
C     pass
C  #else
C     fail
C  #endif
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
