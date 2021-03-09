C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.11/03                           *
C  *    TEST TITLE : Error indicator = 2202                *
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


      CALL INITGL ('09.02.11/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)



C  DESIGN:
C  
C  <open workstation>
C  
C  <open archive file> 11
C  <open structure> 100
C  <text>
C  <execute structure> 101
C  <close structure>
C  <open structure> 101
C  <text>
C  <close structure>
C  
C  <inquire conflicting structures in network> with structure network source=2
      CALL SETMSG ('3', 'If <inquire conflicting structures in ' //
     1             'network> is called and specified enumeration ' //
     2             'type is out of range, it should return error ' //
     3             'indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202)
C  
C  <inquire polyline representation> with type of returned values = 2
      CALL SETMSG ('3', 'If <inquire polyline representation> is ' //
     1             'called and specified enumeration type is out of ' //
     2             'range, it should return error indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202)
C  
C  <inquie edge representation> with type of returned values = -1
      CALL SETMSG ('3', 'If <inquire edge representation> is called ' //
     1             'and specified enumeration type is out of range, ' //
     2             'it should return error indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202)
C  
C  <inquire text extent> with text path = 4
      CALL SETMSG ('3', 'If <inquire text extent> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202)
C  
C  <inquire text extent> with text alignment horizontal = 4
      CALL SETMSG ('3', 'If <inquire text extent> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202)
C  
C  <inquire text extent> with text alignment vertical =  6
      CALL SETMSG ('3', 'If <inquire text extent> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202)
C  
C  
C  <open structure> 200
C  <text>
C  <execute structure> 201
C  <close structure>
C  <open structure> 201
C  <text>
C  <execute structure> 202
C  <close sturcture>
C  <open structure> 202
C  <text>
C  <close structure>
C  
C  <inquire paths to descendants> with path order = 2
      CALL SETMSG ('3', 'If <inquire paths to descendants> is ' //
     1             'called and specified enumeration type is out of ' //
     2             'range, it should return error indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202)
C  
C  <element search> with search direction = 2
      CALL SETMSG ('3', 'If <element search> is called and ' //
     1             'specified enumeration type is out of range, it ' //
     2             'should return error indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202)
C  
C  <open structure> 301
C  <execute structure> 302
C  <close structure>
C  <open structure> 302
C  <text>
C  <close structure>
C  
C  <incremental spatial search 3> with modelling clip flag = 2
      CALL SETMSG ('3', 'If <incremental spatial search 3> is ' //
     1             'called and specified enumeration type is out of ' //
     2             'range, it should return error indicator = 2202.')


C  pass/fail depending on (returned error indicator = 2202
C  
C  <close archive file>
C  



666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
