C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.03/05                              *
C  *    TEST TITLE : Retrieval conflict resolution         *
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
 
C conflict resolution
C                maintain    abandon     update
      INTEGER    PCRMNT,     PCRABA,     PCRUPD
      PARAMETER (PCRMNT = 0, PCRABA = 1, PCRUPD = 2)
 
      INTEGER     ARID, ARNM, SPCSTR(100), SPCSIZ
 
      LOGICAL     FAILFL, STRCON, CSSIDS
 
C  When structures with the same identifiers are set up for testing,
C  the contents of those in the CSS differ from those in the
C  archive, so that the two versions are distinguishable. This is
C  noted by following the structure identifier with a "C" (for CSS),
C  "A" (for archive), or "E" (for empty).
 
      CALL INITGL ('03.03/05')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  open new archive file, with arid = archive identifier
      CALL AVARNM (ARNM)
      ARID = 5
      CALL POPARF (ARID, ARNM)
 
C  *** *** ***   retrieving with MAINTAIN   *** *** ***
      CALL PSCNRS (PCRABA, PCRMNT)
 
C  ***  retrieve existing structures
 
C  set up structures:
C     archive : 102-A, 104-A, 105-A,
C        with 102-A invoking 104-A, and 104-A invoking 105-A
C     CSS:      101-C, 104-C
      CALL PDAS
      CALL SETSTR (105, 'L1')
      CALL SETSTR (104, 'L1,E105')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('10 12 14', 'When the retrieval resolution flag ' //
     1             'is MAINTAIN, <retrieve structure networks> '     //
     2             'should insert new structures into the CSS, but ' //
     3             'not replace existing structures.')
 
C  <retrieve structure networks> 102
      CALL SETVS ('102', SPCSTR, SPCSIZ)
      CALL PRESN (ARID, SPCSIZ, SPCSTR)
 
C  pass/fail depending on (CSS = 101-C, 102-A, 104-C, 105-A)
      IF (CSSIDS ('101,102,104,105')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,3')        .AND.
     3              STRCON (105, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
C  set up structures:
C     archive : 102-A, 104-A, with 102-A invoking 104-A
C     CSS:      101-C, 104-C
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('11 12 14', 'When the retrieval resolution flag ' //
     1             'is MAINTAIN, <retrieve all structures> should '  //
     2             'insert new structures into the CSS, but not '    //
     3             'replace existing structures.')
 
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 101-C, 102-A, 104-C)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,3'))
      ELSE
         CALL FAIL
      ENDIF
 
C  ***  retrieve with some non-existing structures
C
C  set up CSS: 101-C, 104-C
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('9 12 13 14', 'When the retrieval resolution '  //
     1             'flag is MAINTAIN and some of the specified '   //
     2             'structures do not exist in the archive, '      //
     3             '<retrieve structures> should insert existing ' //
     4             'structures into the CSS and create empty '     //
     5             'structures for those not existing, but not '   //
     6             'replace existing CSS structures.')
 
C  <retrieve structures> 101,102,103,104
      CALL SETVS  ('101,102,103,104', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PREST  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
C  pass/fail depending on (CSS = 101-C, 102-A, 103-E, 104-C)
      IF (CSSIDS ('101,102,103,104')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (103, ' ')           .AND.
     3              STRCON (104, '67,3'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('9 13', 'When the retrieval resolution flag is ' //
     1             'MAINTAIN and some of the specified structures ' //
     2             'do not exist in the archive, <retrieve '        //
     3             'structures> should signal error 408.')
 
C  pass/fail depending on (Error 408 signalled from <retrieve
C                          structures>)
      CALL SIGTST (408, FAILFL)
 
 
C  *** *** ***   retrieving with UPDATE   *** *** ***
      CALL PSCNRS (PCRABA, PCRUPD)
 
C  ***  retrieve existing structures
 
C  set up CSS: 101-C, 104-C
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('10 12 16', 'When the retrieval resolution flag '  //
     1             'is UPDATE, <retrieve structure networks> should ' //
     2             'insert new structures into the CSS, and replace ' //
     3             'existing structures.')
 
C  <retrieve structure networks> 102
      CALL SETVS ('102', SPCSTR, SPCSIZ)
      CALL PRESN (ARID, SPCSIZ, SPCSTR)
 
C  pass/fail depending on (CSS = 101-C, 102-A, 104-A)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
C  ***  retrieve with some non-existing structures
C
C  set up CSS: 101-C, 104-C
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('10 12 16 17', 'When the retrieval resolution '   //
     1             'flag is UPDATE and some of the specified '       //
     2             'structures do not exist in the archive, '        //
     3             '<retrieve structure networks> should insert '    //
     4             'existing structures into the CSS, create empty ' //
     5             'structures for those not existing, and replace ' //
     6             'existing CSS structures, even if the '           //
     7             'replacement did not exist in the archive.')
 
C  <retrieve structure networks> 101,102,104
      CALL SETVS  ('101,102,104', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PRESN  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
C  pass/fail depending on (CSS = 101-E, 102-A, 104-A)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, ' ')           .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('10 17', 'When the retrieval resolution flag is ' //
     1             'UPDATE and some of the specified structures do ' //
     2             'not exist in the archive, <retrieve structure '  //
     3             'networks> should signal error 408.')
 
 
C  pass/fail depending on (Error 408 signalled from <retrieve
C                          structure networks>)
      CALL SIGTST (408, FAILFL)
 
 
C  *** *** ***   retrieving with ABANDON   *** *** ***
      CALL PSCNRS (PCRABA, PCRABA)
 
C  ***  retrieve existing structures
 
C  set up CSS: 101-C, 104-C
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('9 12', 'When the retrieval resolution flag is ' //
     1             'ABANDON and all of the specified structures '   //
     2             'exist in the archive file but not in the CSS, ' //
     3             '<retrieve structures> should insert the new '   //
     4             'structures into the CSS.')
 
C  <retrieve structures> 102
      CALL SETVS ('102', SPCSTR, SPCSIZ)
      CALL PREST (ARID, SPCSIZ, SPCSTR)
 
C  pass/fail depending on (CSS = 101-C, 102-A, 104-C)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,3'))
      ELSE
         CALL FAIL
      ENDIF
 
C  ***  retrieve with some non-existing structures
 
C  set up CSS: 101-C
      CALL PDAS
      CALL SETSTR (101, 'L3')
 
      CALL SETMSG ('10 12 13', 'When the retrieval resolution flag '  //
     1             'is ABANDON and some of the specified structures ' //
     2             'do not exist in the archive, <retrieve '          //
     3             'structure networks> should insert existing '      //
     4             'structures into the CSS and create empty '        //
     5             'structures for those not existing.')
 
C  <retrieve structure networks> 102,103
      CALL SETVS  ('102,103', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PRESN  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
C  pass/fail depending on (CSS = 101-C, 102-A, 103-E, 104-A)
      IF (CSSIDS ('101,102,103,104')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (103, ' ')           .AND.
     3              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('10 13', 'When the retrieval resolution flag is '  //
     1             'ABANDON and some of the specified structures do ' //
     2             'not exist in the archive, <retrieve structure '   //
     3             'networks> should signal error 408.')
 
C  pass/fail depending on (Error 408 signalled from <retrieve
C                          structure networks>)
      CALL SIGTST (408, FAILFL)
 
C  ***  retrieve with duplicate structures to trigger ABANDON
C
C  set up CSS: 101-C, 104-C
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('11 15', 'When the retrieval resolution flag is ' //
     1             'ABANDON and some of the specified structures '   //
     2             'are already in the CSS, <retrieve all '          //
     3             'structures> should leave the CSS unchanged.')
 
C  <retrieve all structures> from arid
      CALL ERRCTL (.TRUE.)
      CALL PRAST  (ARID)
      CALL ERRCTL (.FALSE.)
 
C  pass/fail depending on (CSS = 101-C, 104-C)
      IF (CSSIDS ('101,104')) THEN
         CALL IFPF (STRCON (101, '67,3')  .AND.
     1              STRCON (104, '67,3'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('11 15', 'When the retrieval resolution flag is ' //
     1             'ABANDON and some of the specified structures '   //
     2             'are already in the CSS, <retrieve all '          //
     3             'structures> should signal error 405.')
 
C  pass/fail depending on (Error 405 signalled from <retrieve all
C                          structures>)
      CALL SIGTST (405, FAILFL)
 
C  ***  retrieve with duplicate structures to trigger ABANDON and
C  ***  non-existent structures
C
C  set up CSS: 101-C, 104-C
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('10 15', 'When the retrieval resolution flag is ' //
     1             'ABANDON and some of the specified structures '   //
     2             'exist in the archive and also in the CSS, '      //
     3             '<retrieve structure networks> should leave the ' //
     4             'CSS unchanged.')
 
C  <retrieve structure networks> 103, 102
      CALL SETVS  ('103,102', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PRESN  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
C  pass/fail depending on (CSS = 101-C, 104-C)
      IF (CSSIDS ('101,104')) THEN
         CALL IFPF (STRCON (101, '67,3')  .AND.
     1              STRCON (104, '67,3'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('10 13 15', 'When the retrieval resolution flag '  //
     1             'is ABANDON and some of the specified structures ' //
     2             'are already in the CSS, and others do not exist ' //
     3             'in the archive file, then <retrieve structure '   //
     4             'networks> should signal error 405 or 408.')
 
C  pass/fail depending on (Error 405 or 408 signalled from <retrieve
C                          structure networks>)
C make 408 look like 405 for pass/fail purposes:
      IF (ERRSIG .EQ. 408) ERRSIG = 405
      CALL SIGTST (405, FAILFL)
 
C  set up CSS: 101-C, 104-C
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
      CALL SETMSG ('10 15', 'When the retrieval resolution flag is '  //
     1             'ABANDON and a specified structure is already in ' //
     2             'the CSS, <retrieve structures> should leave the ' //
     3             'CSS unchanged even if the structure does not '    //
     4             'exist in the archive.')
 
C  <retrieve structures> 102, 101
      CALL SETVS  ('102,101', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PREST  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
C  pass/fail depending on (CSS = 101-C, 104-C)
      IF (CSSIDS ('101,104')) THEN
         CALL IFPF (STRCON (101, '67,3')  .AND.
     1              STRCON (104, '67,3'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('10 13 15', 'When the retrieval resolution flag '  //
     1             'is ABANDON and a specified non-existent '         //
     2             'structure is already in the CSS, then <retrieve ' //
     3             'structures> should signal error 405 or 408.')
 
C  pass/fail depending on (Error 405 or 408 signalled from <retrieve
C                          structures>)
C make 408 look like 405 for pass/fail purposes:
      IF (ERRSIG .EQ. 408) ERRSIG = 405
      CALL SIGTST (405, FAILFL)
 
666   CONTINUE
C close archive and PHIGS
      CALL PCLARF (ARID)
      CALL ENDIT
      END
