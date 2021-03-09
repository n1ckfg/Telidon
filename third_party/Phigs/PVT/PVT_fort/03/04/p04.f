 
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.04/04                              *
C  *    TEST TITLE : Retrieve descendant paths             *
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

C truncation method
      INTEGER    PHEAD,     PTAIL
      PARAMETER (PHEAD = 0, PTAIL = 1)
 
      INTEGER     RETCOD, ARID, ARNM, ARCLST(5), ARCNUM
 
      CALL INITGL ('03.04/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  open new archive file, with arid = archive identifier
      ARID = 30
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
 
C  set up archive as follows:
C
C                   101        106       108
C                  / | \       /
C                 /  |  \    1/
C               1/  2|  3\   /
C               /    |    \ /
C              /     |    107
C             /      |
C          102      103
C          | \      / \\
C          |  \   1/   \\
C         1|  2\  /    2\\3
C          |    \/       \\
C          |    104      105
C          |     |      /
C          |    1|    1/
C           \    |    /
C            \   |   /
C             \  |  /
C              \ | /
C               109
C
C
C  The nodes of the graph (101-109) represent structures, and the
C  labelled edges are references to invoked (lower) structures.
C  The labels (1-3) represent the element position of the <execute
C  structure> function within the calling structure.  Eg, an element
C  reference path from 101 to 109 would be: (101, 2), (103, 3),
C  (105, 1), (109, 0).
 
      CALL CSSPTH
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
      CALL PDAS
 
C  *** *** *** ***   No truncation   *** *** *** ***
 
      CALL SETMSG ('6 7 8 11', '<Retrieve paths to descendants> '  //
     1             'should retrieve all maximal descendant paths ' //
     2             'when path depth is zero.')
 
C  Use <retrieve paths to descendants> with
C       structure id = 101
C       path order   = TOPFIRST
C       path depth   = zero
      CALL ARCPTH (ARID, 'D', 101, PHEAD, 0, RETCOD,
     1             '101,1, 102,1, 109,0 /'           //
     1             '101,1, 102,2, 104,1, 109,0 /'    //
     1             '101,2, 103,1, 104,1, 109,0 /'    //
     1             '101,2, 103,2, 105,1, 109,0 /'    //
     1             '101,2, 103,3, 105,1, 109,0 /'    //
     1             '101,3, 107,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 103
C       path order   = BOTTOMFIRST
C       path depth   = zero
      CALL ARCPTH (ARID, 'D', 103, PTAIL, 0, RETCOD,
     1             '103,1, 104,1, 109,0 /' //
     1             '103,2, 105,1, 109,0 /' //
     1             '103,3, 105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 109
C       path order   = BOTTOMFIRST
C       path depth   = zero
      CALL ARCPTH (ARID, 'D', 109, PTAIL, 0, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 108
C       path order   = TOPFIRST
C       path depth   = zero
      CALL ARCPTH (ARID, 'D', 108, PHEAD, 0, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF
 
      CALL PASS
 
C  *** *** *** ***   Truncating via TOPFIRST   *** *** *** ***
 
2000  CONTINUE
 
      CALL SETMSG ('6 7 8 11 14 17', '<Retrieve paths to '            //
     1             'descendants> should retrieve all qualifying '     //
     2             'descendant paths (or portions thereof), with no ' //
     3             'repetition, when path depth is positive and '     //
     4             'path order is TOPFIRST.')
 
C  Use <retrieve paths to descendants> with
C       structure id = 101
C       path order   = TOPFIRST
C       path depth   = 2
      CALL ARCPTH (ARID, 'D', 101, PHEAD, 2, RETCOD,
     1             '101,1, 102,1 /' //
     1             '101,1, 102,2 /' //
     1             '101,2, 103,1 /' //
     1             '101,2, 103,2 /' //
     1             '101,2, 103,3 /' //
     1             '101,3, 107,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 101
C       path order   = TOPFIRST
C       path depth   = 1
      CALL ARCPTH (ARID, 'D', 101, PHEAD, 1, RETCOD,
     1             '101,1 /' //
     1             '101,2 /' //
     1             '101,3 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 104
C       path order   = TOPFIRST
C       path depth   = 5
      CALL ARCPTH (ARID, 'D', 104, PHEAD, 5, RETCOD, '104,1, 109,0 /')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 109
C       path order   = TOPFIRST
C       path depth   = 5
      CALL ARCPTH (ARID, 'D', 109, PHEAD, 5, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF
 
      CALL PASS
 
C  *** *** *** ***   Truncating via BOTTOMFIRST   *** *** *** ***
 
3000  CONTINUE
 
      CALL SETMSG ('6 7 8 11 15 17', '<Retrieve paths to '            //
     1             'descendants> should retrieve all qualifying '     //
     2             'descendant paths (or portions thereof), with no ' //
     3             'repetition, when path depth is positive and '     //
     4             'path order is BOTTOMFIRST.')
 
C  Use <retrieve paths to descendants> with
C       structure id = 101
C       path order   = BOTTOMFIRST
C       path depth   = 2
      CALL ARCPTH (ARID, 'D', 101, PTAIL, 2, RETCOD,
     1             '102,1, 109,0 /' //
     1             '104,1, 109,0 /' //
     1             '105,1, 109,0 /' //
     1             '101,3, 107,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 4000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 103
C       path order   = BOTTOMFIRST
C       path depth   = 5
      CALL ARCPTH (ARID, 'D', 103, PTAIL, 5, RETCOD,
     1             '103,1, 104,1, 109,0 /' //
     2             '103,2, 105,1, 109,0 /' //
     3             '103,3, 105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 4000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 102
C       path order   = BOTTOMFIRST
C       path depth   = 1
      CALL ARCPTH (ARID, 'D', 102, PTAIL, 1, RETCOD, '109,0 /')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 4000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 108
C       path order   = BOTTOMFIRST
C       path depth   = 1
      CALL ARCPTH (ARID, 'D', 108, PTAIL, 1, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 4000
      ENDIF
 
      CALL PASS
 
C  *** *** ***   Retrieve with missing structure   *** *** ***
 
4000  CONTINUE
 
C  delete structure #104 from archive
      CALL SETVS  ('104', ARCLST, ARCNUM)
      CALL PDSTAR (ARID, ARCNUM, ARCLST)
 
      CALL SETMSG ('6 7 8 9', 'If a referenced structure T does not ' //
     1             'exist in the archive, then <retrieve paths to '   //
     2             'descendants> should behave as if T were an '      //
     3             'existing structure containing no references.')
 
C  Use <retrieve paths to descendants> with
C       structure id = 103
C       path order   = TOPFIRST
C       path depth   = 0
      CALL ARCPTH (ARID, 'D', 103, PHEAD, 0, RETCOD,
     1             '103,1, 104,0 /'         //
     2             '103,2, 105,1, 109,0 /'  //
     3             '103,3, 105,1, 109,0 /')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 5000
      ENDIF
 
C  Use <retrieve paths to descendants> with
C       structure id = 102
C       path order   = BOTTOMFIRST
C       path depth   = 1
      CALL ARCPTH (ARID, 'D', 102, PTAIL, 1, RETCOD,
     1             '104,0 /' //
     2             '109,0 /')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 5000
      ENDIF
 
      CALL PASS
 
5000  CONTINUE
      CALL PCLARF (ARID)
      CALL ENDIT
      END
