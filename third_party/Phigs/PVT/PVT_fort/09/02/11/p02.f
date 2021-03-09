C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.11/02                           *
C  *    TEST TITLE : Error indicator = 2201                *
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


      CALL INITGL ('09.02.11/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)



C  DESIGN:
C  
C  <open workstation>
C  
C  Use <inquire list of available workstation types> to get:
C      number = number of available workstation types
C  If (number <> 0) then
C  <inquire list of available workstation types>
C      with length of application list = -1
      CALL SETMSG ('2', 'If <inquire list of available workstation ' //
     1             'types> is called and length of application list ' //
     2             'is negative, it should return error indicator = ' //
     3             '2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire phigs facilities> to get:
C      number = number of available character sets
C  If (number <> 0) then
C  <inquire phigs facilities> with length of application list = -2
      CALL SETMSG ('2', 'If <inquire phigs facilities> is called ' //
     1             'and length of application list is negative, it ' //
     2             'should return error indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire generalized structure element facilities> to get:
C      number = number of available GSEs
C  If (number  <> 0) then
C  <inquire generalized structure element facilities>
C      with length of application list = -1
      CALL SETMSG ('2', 'If <inquire generalized structure element ' //
     1             'facilities> is called and length of application ' //
     2             'list is negative, it should return error ' //
     3             'indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire set of open workstation> to get:
C      number = number of open workstations
C  If (number <> 0) then
C  <inquire set of open workstations> with length of application list = -3
      CALL SETMSG ('2', 'If <inquire set of open workstations> is ' //
     1             'called and length of application list is ' //
     2             'negative, it should return error indicator = ' //
     3             '2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  <open structure> 100
C  <text>
C  <execute structure> 101
C  <close structure>
C  <open structure> 101
C  <text>
C  <close structure>
C  <inquire structure identifiers> with length of application list = -10
      CALL SETMSG ('2', 'If <inquire structure identifiers> is ' //
     1             'called and length of application list is ' //
     2             'negative, it should return error indicator = ' //
     3             '2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  
C  <open archive file> 11
C  <archive all structure>
C  <inquire conflicting structures in network>
C      with length of application list = -1
      CALL SETMSG ('2', 'If <inquire conflicting structures in ' //
     1             'network> is called and length of application ' //
     2             'list is negative, it should return error ' //
     3             'indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  
C  <close archive file> 11
C  
C  Use <inquire list of polymarker indices> to get:
C      number = number of polymarker bundle table entries
C  If (number <> 0) then
C  <inqurie list of polymarker indices> with length of application list = -1
      CALL SETMSG ('2', 'If <inquire list of polymarker indices> is ' //
     1             'called and length of application list is ' //
     2             'negative, it should return error indicator = ' //
     3             '<2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire list of interior indices> to get:
C      number = number of interior bundle table entries
C  If (number <> 0) then
C  <inquire list of interior indices> with length of application list = -1
      CALL SETMSG ('2', 'If <inquire list of interior indices> is ' //
     1             'called and length of application list is ' //
     2             'negative, it should return error indicator = ' //
     3             '<2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire list of pattern indices> to get:
C      number = number of pattern table entries
C  If (number <> 0) then
C  <inquire list of pattern indices> with length of application list = -1
      CALL SETMSG ('2', 'If <inquire list of pattern indices> is ' //
     1             'called and length of application list is ' //
     2             'negative, it should return error indicator = ' //
     3             '<2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire list of colour indices> to get:
C      number = number of colour table entries
C  If (number <> 0) then
C  <inquire list of colour indices> with length of application list = -1
      CALL SETMSG ('2', 'If <inquire list of colour indices> is ' //
     1             'called and length of application list is ' //
     2             'negative, it should return error indicator = ' //
     3             '<2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire polyline facilities> to get:
C      number = number of available linetypes
C  If (number <> 0) then
C  <inquire polyline facilities> with length of application list = -6
      CALL SETMSG ('2', 'If <inquire polyline facilities> is called ' //
     1             'and length of application list is negative, it ' //
     2             'should return error indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire text facilities> to get:
C      number = number of text font and precision pairs
C  If (number <> 0) then
C  <inquire text facilities> with length of application list = -1
      CALL SETMSG ('2', 'If <inquire text facilities> is called and ' //
     1             'length of application list is negative, it ' //
     2             'should return error indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire edge facilities> to get:
C      number = number of available edgetypes
C  If <number <> 0) then
C  <inquire edge facilities> with length of application list = -2
      CALL SETMSG ('2', 'If <inquire edge facilities> is called and ' //
     1             'length of application list is negative, it ' //
     2             'should return error indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire list of available generalized drawing primitives 3> to get:
C      number of number of available 3D generalized drawing primitives
C  If (number <> 0 ) then
C  <inquire list of available generalized drawing primitives 3>
C      with length of application list = -1
      CALL SETMSG ('2', 'If <inquire list of available generalized ' //
     1             'drawing primitives 3> is called and length of ' //
     2             'application list is negative, it should return ' //
     3             'error indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  Use <inquire list of available generalized structure elements> to get:
C      number = number of sets of attributes used
C  If (number <> 0) then
C  <inquire list of available generalized structure elements>
C      with length of application list = -1
      CALL SETMSG ('2', 'If <inquire list of available generalized ' //
     1             'structure elements> is called and length of ' //
     2             'application list is negative, it should return ' //
     3             'error indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  endif
C  
C  <open structure> 301
C  <text>
C  <execute structure> 302
C  <close structure>
C  <open structure>
C  <ppm> with x,y,z cooridates=1.0,1.0,1.0
C  <close structure>
C  
C  <incremental spatial search> with length of application list = -1,
C                                    reference point=(0.9,0.9,0.9), distance=0.15
      CALL SETMSG ('2', 'If <incremental spatial search> is called ' //
     1             'and length of application list is negative, it ' //
     2             'should return error indicator = 2201.')


C  pass/fail depending on (returned error indicator = 2201)
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
