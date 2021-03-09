C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01.11.01/03                        *
C  *    TEST TITLE : Error 2202 handled by user            *
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


      CALL INITGL ('09.01.11.01/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)



C  DESIGN:
C  
C  Throughout this program, every time an error is signalled (as noted
C  by the tag "signals error"), the user-defined error handler saves
C  the error code, function identifier, and error file identifier in
C  an error table.
C  
C  *** *** ***  Generate errors *** *** ***
C  
C  <open workstation>
C  
C  <redraw all structures> with control flag = 2: signals error
C  <update workstation> with regenerated flag = 3: signals error
C  <set display update state> with deferral mode = 5: signals error
C  <set display update state> with modification mode = 3: signals error
C  <set text path> with text path = 4: signals error
C  <set annotation text alignment> with annotation text alignment horizontal=4:
C      signals error
C  <set annotation text alignment> with annotation text alignment vertical=6:
C      signals error
C  <set interior style> with interior style = 5: signals error
C  <set edge flag> with edge flag = 2: signals error
C  <set individual asf> with aspect identifier = 18: signals error
C  <set individual asf> with aspect source flag value = 2: signals error
C  <set edge representation> with edge flag = 2: signals error
C  <set local transformation> with composition type = 3: signals error
C  <set view representation> with x-y clipping indicator = 2: signals error
C  <set view transformation input priority> with relative priority = 2:
C      signals error
C  <set edit mode> with edit mode = 2: signals error
C  <delete structure network> with reference handling flag = 2: signals error
C  <set conflict resolution> with archival conflict resolution = 3: signale error
C  <set conflict resolution> with retrieval conflict resulution = 3:
C      signals error
C  <retrieve paths to ancestors> with path order = 2: signals error
C  <set error handling mode> with error handling mode = 2: signals error
C  
C  *** *** ***  Results of user-defined error handling  *** *** ***
C  
      CALL SETMSG ('4', 'If <redraw all structures> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 004, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <update workstation> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 005, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set display update state> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should return error code 2202, function ' //
     3             'identifier 006, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set display update state> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should return error code 2202, function ' //
     3             'identifier 006, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set text path> is called and specified ' //
     1             'enumeration type is out of range, it should ' //
     2             'return error code 2202, function identifier ' //
     3             '042, and the current error file identifier to ' //
     4             'the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set annotation text alignment> is ' //
     1             'called and specified enumeration type is out of ' //
     2             'range, it should return error code 2202, ' //
     3             'function identifier 047, and the current error ' //
     4             'file identifier to the user defined error ' //
     5             'handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set annotation text alignment> is ' //
     1             'called and specified enumeration type is out of ' //
     2             'range, it should return error code 2202, ' //
     3             'function identifier 047, and the current error ' //
     4             'file identifier to the user defined error ' //
     5             'handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set interior style> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 049, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set edge flag> is called and specified ' //
     1             'enumeration type is out of range, it should ' //
     2             'return error code 2202, function identifier ' //
     3             '052, and the current error file identifier to ' //
     4             'the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set individual asf> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 061, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set individual asf> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 061, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set edge representation> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 066, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set local transformation> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should return error code 2202, function ' //
     3             'identifier 075, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set view representation> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 084, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set view transformation input ' //
     1             'priority> is called and specified enumeration ' //
     2             'type is out of range, it should return error ' //
     3             'code 2202, function identifier 085, and the ' //
     4             'current error file identifier to the user ' //
     5             'defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set edit mode> is called and specified ' //
     1             'enumeration type is out of range, it should ' //
     2             'return error code 2202, function identifier ' //
     3             '096, and the current error file identifier to ' //
     4             'the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <delete structure network> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should return error code 2202, function ' //
     3             'identifier 106, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set conflict resolution> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 119, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set conflict resolution> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 119, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <retrieve paths to ancestors> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should return error code 2202, function ' //
     3             'identifier 124, and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  
      CALL SETMSG ('4', 'If <set error handling mode> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error code 2202, function ' //
     3             'identifier 179 , and the current error file ' //
     4             'identifier to the user defined error handler.')


C  pass/fail depending on (next entry in error table = expected values)
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
