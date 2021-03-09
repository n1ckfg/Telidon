C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.03/03                              *
C  *    TEST TITLE : Archival conflict resolution          *
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
 
      INTEGER    ARID, ARNM, SPCSTR(100), SPCSIZ
 
      LOGICAL    STRCON, CSSIDS, FAILFL
 
C  When structures with the same identifiers are set up for testing,
C  the contents of those in the CSS differ from those in the
C  archive, so that the two versions are distinguishable. This is
C  noted by following the structure identifier with a "C" (for CSS)
C  or "A" (for archive).
 
      CALL INITGL ('03.03/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  open new archive file, with arid = archive identifier
      CALL AVARNM (ARNM)
      ARID = 3
      CALL POPARF (ARID, ARNM)
 
C  *** *** ***   archiving with MAINTAIN   *** *** ***
      CALL PSCNRS (PCRMNT, PCRABA)
 
C  ***  archive existing structures
C
C  set up structures:
C     CSS     : 101-C, 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
C  <archive all structures> to arid
      CALL PARAST (ARID)
 
      CALL SETMSG ('3 4 7', 'When the archival resolution flag is ' //
     1             'MAINTAIN, <archive all structures> should '     //
     2             'insert new structures into the archive file, '  //
     3             'but not replace existing structures.')
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 101-C, 102-A, 104-A)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
C  set up structures:
C     CSS     : 101-C, 104-C, with 101-C invoking 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'E104,L3')
      CALL SETSTR (104, 'L3')
 
C  <archive structure networks> 101
      CALL SETVS  ('101', SPCSTR, SPCSIZ)
      CALL PARSN  (ARID, SPCSIZ, SPCSTR)
 
      CALL SETMSG ('2 4 7', 'When the archival resolution flag is ' //
     1             'MAINTAIN, <archive structure networks> should ' //
     2             'insert new structures into the archive file, '  //
     3             'but not replace existing structures.')
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 101-C, 102-A, 104-A)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '66,104,67,3') .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
C  ***  archive with some non-existent structures
C
C  set up structures:
C     CSS     : 101-C, 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
C  <archive structures> 101,102,103,104
      CALL SETVS  ('101,102,103,104', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PARST  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
      CALL SETMSG ('1 4 5 7', 'When the archival resolution flag is ' //
     1             'MAINTAIN and some of the specified structures '   //
     2             'do not exist in the CSS, <archive structures> '   //
     3             'should take no action for the non-existent '      //
     4             'structures, add new structures to the archive '   //
     5             'file, but not replace existing archive '          //
     6             'structures.')
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 101-C, 102-A, 104-A)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('1 5', 'When the archival resolution flag is '   //
     1             'MAINTAIN and some of the specified structures ' //
     2             'do not exist in the CSS, <archive structures> ' //
     3             'should signal error 200.')
 
C  pass/fail depending on (Error 200 signalled from <archive
C                          structures>)
      CALL SIGTST (200, FAILFL)
 
 
C  *** *** ***   archiving with UPDATE   *** *** ***
      CALL PSCNRS (PCRUPD, PCRABA)
 
C  ***  archive existing structures
C
C  set up structures:
C     CSS     : 101-C, 104-C, with 101-C invoking 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (104, 'L3')
      CALL SETSTR (101, 'E104,L3')
 
C  <archive structure networks> 101
      CALL SETVS  ('101', SPCSTR, SPCSIZ)
      CALL PARSN  (ARID, SPCSIZ, SPCSTR)
 
      CALL SETMSG ('2 4 6', 'When the archival resolution flag is ' //
     1             'UPDATE and all of the specified structures '    //
     2             'exist, <archive structure networks> should '    //
     3             'insert new structures into the archive file, '  //
     4             'and replace existing structures.')
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 101-C, 102-A, 104-C)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '66,104,67,3') .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,3'))
      ELSE
         CALL FAIL
      ENDIF
 
C  ***  archive with some non-existent structures
C
C  set up structures:
C     CSS     : 101-C, 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
C  <archive structure networks> 101,102,103,104
      CALL SETVS  ('101,102,103,104', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PARSN  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
      CALL SETMSG ('2 4 5 6', 'When the archival resolution flag is ' //
     1             'UPDATE and some of the specified structures do '  //
     2             'not exist in the CSS, <archive structure '        //
     3             'networks> should take no action for the '         //
     4             'non-existent structures, add new structures to '  //
     5             'the archive file, and replace existing archive '  //
     6             'structures.')
 
C  clear CSS
      CALL PDAS
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
 
      CALL SETMSG ('2 5', 'When the archival resolution flag is '    //
     1             'UPDATE and some of the specified structures do ' //
     2             'not exist in the CSS, <archive structure '       //
     3             'networks> should signal error 200.')
 
C  pass/fail depending on (Error 200 signalled from <archive
C                          structure networks>)
      CALL SIGTST (200, FAILFL)
 
C  *** *** ***   archiving with ABANDON   *** *** ***
      CALL PSCNRS (PCRABA, PCRABA)
 
C  ***  archive existing structures
C
C  set up structures:
C     CSS     : 101-C, 104-C, with 101-C invoking 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'E104,L3')
      CALL SETSTR (104, 'L3')
 
C  <archive structures> 101
      CALL SETVS  ('101', SPCSTR, SPCSIZ)
      CALL PARST  (ARID, SPCSIZ, SPCSTR)
 
      CALL SETMSG ('1 4', 'When the archival resolution flag is '   //
     1             'ABANDON and all of the specified structures '   //
     2             'exist in the CSS but not in the archive file, ' //
     3             '<archive structures> should insert the new '    //
     4             'structures into the archive file.')
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 101-C, 102-A, 104-A)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '66,104,67,3') .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
C  ***  archive with some non-existent structures
C
C  set up structures:
C     CSS     : 101-C, 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
C  <archive structure networks> 101,102,103
      CALL SETVS  ('101,102,103', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PARSN  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
      CALL SETMSG ('2 4 5', 'When the archival resolution flag is '   //
     1             'ABANDON and some of the specified structures do ' //
     2             'not exist in the CSS, <archive structure '        //
     3             'networks> should take no action for the '         //
     4             'non-existent structures and add new structures '  //
     5             'to the archive file.')
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 101-C, 102-A, 104-A)
      IF (CSSIDS ('101,102,104')) THEN
         CALL IFPF (STRCON (101, '67,3')        .AND.
     1              STRCON (102, '67,1,66,104') .AND.
     2              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('2 5', 'When the archival resolution flag is '     //
     1             'ABANDON and some of the specified structures do ' //
     2             'not exist in the CSS, <archive structure '        //
     3             'networks> should signal error 200.')
 
C  pass/fail depending on (Error 200 signalled from <archive
C                          structure networks>)
      CALL SIGTST (200, FAILFL)
 
C  ***  archive with duplicate structures to trigger ABANDON
C
C  set up structures:
C     CSS     : 101-C, 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'L3')
      CALL SETSTR (104, 'L3')
 
C  <archive all structures>
      CALL ERRCTL (.TRUE.)
      CALL PARAST (ARID)
      CALL ERRCTL (.FALSE.)
 
      CALL SETMSG ('3 8', 'When the archival resolution flag is '   //
     1             'ABANDON and some of the specified structures '  //
     2             'are already in the archive file, <archive all ' //
     3             'structures> should leave the archive file '     //
     4             'unchanged.')
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 102-A, 104-A)
      IF (CSSIDS ('102,104')) THEN
         CALL IFPF (STRCON (102, '67,1') .AND.
     1              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('3 8', 'When the archival resolution flag is '   //
     1             'ABANDON and some of the specified structures '  //
     2             'are already in the archive file, <archive all ' //
     3             'structures> should signal error 405.')
 
C  pass/fail depending on (Error 405 signalled from <archive all
C                          structures>)
      CALL SIGTST (405, FAILFL)
 
C  ***  archive with duplicate structures to trigger ABANDON and
C  ***  non-existent structures
C
C  set up structures:
C     CSS     : 101-C, 104-C, with 101-C invoking 104-C
C     archive : 102-A, 104-A
      CALL PDAS
      CALL SETSTR (104, 'L1')
      CALL SETSTR (102, 'L1,E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'E104,L3')
      CALL SETSTR (104, 'L3')
 
C  <archive structure networks> 101,103,102
      CALL SETVS  ('101,103,102', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PARSN  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
      CALL SETMSG ('2 8', 'When the archival resolution flag is '     //
     1             'ABANDON and some of the specified structures do ' //
     2             'not exist in the CSS and some are already in '    //
     3             'the archive file, <archive structure networks> '  //
     4             'should leave the archive file unchanged.')
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid
      CALL PRAST (ARID)
C  pass/fail depending on (CSS = 102-A, 104-A)
      IF (CSSIDS ('102,104')) THEN
         CALL IFPF (STRCON (102, '67,1,66,104') .AND.
     1              STRCON (104, '67,1'))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('2 5 8', 'When the archival resolution flag is ' //
     1             'ABANDON and some of the specified structures '  //
     2             'are already in the archive file and others do ' //
     3             'not exist in the CSS, then <archive structure ' //
     4             'networks> should signal error 200 or 405.')
 
C  pass/fail depending on (Error 200 or 405 signalled from <archive
C                          all structures>)
C make 200 look like 405 for pass/fail purposes:
      IF (ERRSIG .EQ. 200) ERRSIG = 405
      CALL SIGTST (405, FAILFL)
 
C  <close archive file> with arid
      CALL PCLARF (ARID)
 
666   CONTINUE
      CALL ENDIT
      END
