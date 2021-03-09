C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.03/06                              *
C  *    TEST TITLE : Retrieving open structure             *
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
 
      INTEGER    ARID, ARNM, SPCSTR(20), SPCSIZ
 
      CALL INITGL ('03.03/06')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  open new archive file, with arid = archive identifier
      CALL AVARNM (ARNM)
      ARID = 6
      CALL POPARF (ARID, ARNM)
 
C  set retrieval conflict resolution flag = UPDATE
      CALL PSCNRS (PCRABA, PCRUPD)
 
C  set up structures:
C     archive : 102-A, 104-A (3 elements), with 102-A invoking 104-A
C     CSS     : 101-C, 104-C (4 elements)
      CALL PDAS
      CALL SETSTR (104, 'L911,L912,L913')
      CALL SETSTR (102, 'E104')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETSTR (101, 'L931')
      CALL SETSTR (104, 'L931,L932,L933,L934')
 
C  <open structure> 104
      CALL POPST (104)
C  <retrieve all structures>
      CALL PRAST (ARID)
 
      CALL SETMSG ('11 16 18', 'When <retrieve all structures> '   //
     1             'causes a structure in the archive to replace ' //
     2             'the open CSS structure, the structure should ' //
     3             'remain open, with the element pointer '        //
     4             'indicating the last element.')
 
C  pass/fail depending on (104-A is open structure and
C                          element pointer = 3)
      CALL RETOPN (104, 3, '67,911,67,912,67,913')
 
C  set up structures:
C     CSS     : 101-C, 104-C (4 elements)
      CALL PDAS
      CALL SETSTR (101, 'L931')
      CALL SETSTR (104, 'L931,L932,L933,L934')
 
C  <open structure> 101
      CALL POPST (101)
C  <retrieve structures> 102, 101
      CALL SETVS  ('102,101', SPCSTR, SPCSIZ)
      CALL ERRCTL (.TRUE.)
      CALL PREST  (ARID, SPCSIZ, SPCSTR)
      CALL ERRCTL (.FALSE.)
 
      CALL SETMSG ('9 17 18', 'When <retrieve structures> specifies ' //
     1             'a non-existent archive structure to replace the ' //
     2             'open CSS structure, the structure should become ' //
     3             'empty but remain open, with the element pointer ' //
     4             'indicating zero.')
 
C  pass/fail depending on (101-E is open structure and
C                          element pointer = 0)
      CALL RETOPN (101, 0, ' ')
 
C  set up structures:
C     CSS     : 101-C, 104-C (2 elements)
      CALL PDAS
      CALL SETSTR (101, 'L931')
      CALL SETSTR (104, 'L931,L932')
 
C  <open structure> 104
      CALL POPST (104)
C  <retrieve structure networks> 102
      CALL SETVS  ('102', SPCSTR, SPCSIZ)
      CALL PRESN  (ARID, SPCSIZ, SPCSTR)
 
      CALL SETMSG ('10 16 18', 'When <retrieve structure networks> '  //
     1             'causes an implicitly specified structure in the ' //
     2             'archive to replace the open CSS structure, the '  //
     3             'structure should remain open, with the element '  //
     4             'pointer indicating the last element.')
 
C  pass/fail depending on (104-A is open structure and
C                          element pointer = 3)
      CALL RETOPN (104, 3, '67,911,67,912,67,913')
 
666   CONTINUE
C close archive and PHIGS
      CALL PCLARF (ARID)
      CALL ENDIT
      END
