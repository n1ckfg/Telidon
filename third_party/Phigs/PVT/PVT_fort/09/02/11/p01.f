C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.11/01                           *
C  *    TEST TITLE : Error indicator = 2200                *
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


      CALL INITGL ('09.02.11/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)



C  DESIGN:
C  
C  <open workstation>
C  
C  Use <inquire list of available workstation types> to get:
C     number = number of available workstation types
C  if (number <> 0) then
C  <inquire list of available workstation types> with start index = number
      CALL SETMSG ('1', 'If <inquire list of available workstation ' //
     1             'types> is called and start index is out of ' //
     2             'range, it should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire phigs facilities> to get:
C     number = number of available character sets
C  if (number <> 0) then
C  <inquire phigs facilities> with start index = -1
      CALL SETMSG ('1', 'If <inquire phigs facilities> is called ' //
     1             'and start index is out of range, it should ' //
     2             'return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire modelling clipping facilities> to get:
C     number = number of modelling clipping operators
C  if (number <> 0) then
C  <inquire modelling clipping facilities> with start index = number
      CALL SETMSG ('1', 'If <inquire modelling clipping facilities> ' //
     1             'is called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  <inquire set of open workstations> with start index = -1
      CALL SETMSG ('1', 'If <inquire set of open workstations> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  
C  <open structure> 100
C  <text>
C  <execute structure> 101
C  <close structure>
C  <open structure> 101
C  <text>
C  <close structure>
C  <inquire structure identifiers> with start index = 3
      CALL SETMSG ('1', 'If <inquire structure identifiers> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  
C  <open archive file> 11
C  
C  <archive all structures>
C  Use <inquire all conflicting structures> to get:
C      number = number of structure identifiers in list
C  if (number <> 0) then
C  <inquire all conflicting structures> with start index requested = number
      CALL SETMSG ('1', 'If <inquire all conflicting structures> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  <close archive file> 11
C  
C  Use <inquire list of view indices> to get:
C      number = number of view bundle table entries
C  if (number <> 0) then
C  <inqurie list of view indices> with start index = number
      CALL SETMSG ('1', 'If <inquire list of view indices> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  <post structure> 100
C  <inquire posted structures> with start index = 1
      CALL SETMSG ('1', 'If <inquire posted structures> is called ' //
     1             'and start index is out of range, it should ' //
     2             'return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  
C  Use <inquire list of polyline indices> to get:
C      number = number of polyline bundle table entries
C  if (number <> 0) then
C  <inqurie list of polyline indices> with start index = number
      CALL SETMSG ('1', 'If <inquire list of polyline indices> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire list of text indices> to get:
C      number = number of text bundle table entries
C  if (number <> 0) then
C  <inquire list of text indices> with start index = number
      CALL SETMSG ('1', 'If <inquire list of text indices> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire list of edge indices> to get:
C      number = number of edge bundle table entries
C  if (number <> 0) then
C  <inquire list of edge indices> with start index = -2
      CALL SETMSG ('1', 'If <inquire list of edge indices> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire list of colour indices> to get:
C      number = number of colour bundle table entries
C  if (number <> 0) then
C  <inquire list of colour indices> with start index = number
      CALL SETMSG ('1', 'If <inquire list of colour indices> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire hlhsr (identifier) facilities> to get:
C      number = number of HLHSR identifiers
C  if (number <> 0) then
C  <inquire hlhsr (identifier) facilities> with start index = number
      CALL SETMSG ('1', 'If <inquire hlhsr facilities> is called ' //
     1             'and start index is out of range, it should ' //
     2             'return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire polyline facilities> to get:
C      number = number of available linetypes
C  if (number <> 0) then
C  <inquire polyline facilities> with start index = -1
      CALL SETMSG ('1', 'If <inquire polyline facilities> is called ' //
     1             'and start index is out of range, it should ' //
     2             'return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire annotation facilities> to get:
C      number = number of available annotation styles
C  if (number <> 0) then
C  <inquire annotation facilities> with start index = number
      CALL SETMSG ('1', 'If <inquire annotation facilities> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire interior facilities> to get:
C      number = number of available hatch styles
C  if (number <> 0) then
C  <inquire interior facilties> with start index = -1
      CALL SETMSG ('1', 'If <inquire interior facilities> is called ' //
     1             'and start index is out of range, it should ' //
     2             'return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire colour model facilities> to get:
C      number = number of available colour models
C  if (number <> 0) then
C  <inquire colour model facilities> with start index = number
      CALL SETMSG ('1', 'If <inquire colour model facilities> is ' //
     1             'called and start index is out of range, it ' //
     2             'should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire list of available generalized drawing primitives> to get:
C      number = number of available generalized drawing primitives
C  if (number <> 0 ) then
C  <inquire list of available generalized drawing primitives>
C      with start index = number
      CALL SETMSG ('1', 'If <inquire list of available generalized ' //
     1             'drawing primitives> is called and start index ' //
     2             'is out of range, it should return error ' //
     3             'indicator = <2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <inquire set of workstations to which posted> to get:
C      number = number of workstations to which the structure is posted
C  if (number <> 0) then
C  <inquire set of workstations to which posted> with start index = number
      CALL SETMSG ('1', 'If <inquire set of workstations to which ' //
     1             'posted> is called and start index is out of ' //
     2             'range, it should return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  endif
C  
C  Use <incremental spatial search> to get:
C     number = number of found paths
C  if (number <> 0) then
C  <incremental spatial search> with start index = number
      CALL SETMSG ('1', 'If <incremental spatial search> is called ' //
     1             'and start index is out of range, it should ' //
     2             'return error indicator = 2200.')


C  pass/fail depending on (returned error indicator = 2200)
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
