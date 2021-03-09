C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01.11.02/01                        *
C  *    TEST TITLE : Error 2202 handled by system          *
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

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
C  Declare program-specific variables
      INTEGER    PICSTR, TXCI, IX


      CALL INITGL ('09.01.11.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)



C  DESIGN:
C  
C  Throughout this program, every time an error is signalled (as noted by
C  the tag "signals error"), the system-defined error handler should call
C  <error logging> at least once to write an error message on the error file.
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
C  *** *** ***  Results of system-defined error handling  *** *** ***
C  
      CALL SETMSG ('1', 'If <redraw all structures> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <update workstation> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set display update state> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set display update state> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set text path> is called and specified ' //
     1             'enumeration type is out of range, it should ' //
     2             'write an accurate, self-identifying error ' //
     3             'message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set annotation text alignment> is ' //
     1             'called and specified enumeration type is out of ' //
     2             'range, it should write an accurate, ' //
     3             'self-identifying error message on the error ' //
     4             'file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set annotation text alignment> is ' //
     1             'called and specified enumeration type is out of ' //
     2             'range, it should write an accurate, ' //
     3             'self-identifying error message on the error ' //
     4             'file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set interior style> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set edge flag> is called and specified ' //
     1             'enumeration type is out of range, it should ' //
     2             'write an accurate, self-identifying error ' //
     3             'message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set individual asf> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set individual asf> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set edge representation> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set local transformation> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set view representation> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set view transformation input ' //
     1             'priority> is called and specified enumeration ' //
     2             'type is out of range, it should write an ' //
     3             'accurate, self-identifying error message on the ' //
     4             'error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set edit mode> is called and specified ' //
     1             'enumeration type is out of range, it should ' //
     2             'write an accurate, self-identifying error ' //
     3             'message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <delete structure network> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set conflict resolution> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set conflict resolution> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <retrieve paths to ancestors> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  
      CALL SETMSG ('1', 'If <set error handling mode> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should write an accurate, self-identifying ' //
     3             'error message on the error file.')


C  pass/fail depending on (operator verifies error message)
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
