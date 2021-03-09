C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.04/03                              *
C  *    TEST TITLE : Retrieving ancestor paths             *
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

      INTEGER     RETCOD, ARID, ARNM

      CALL INITGL ('03.04/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  open new archive file, with arid = archive identifier
      ARID = 30
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
 
C  Set up archive as follows:
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
 
C  *** *** *** *** ***   No truncation   *** *** *** *** ***
C
      CALL SETMSG ('5 7 8 10', '<Retrieve paths to ancestors> '       //
     1             'should retrieve all maximal ancestor paths when ' //
     2             'path depth is zero.')
 
C  Use <retrieve paths to ancestors> with
C       structure id = 109
C       path order   = TOPFIRST
C       path depth   = zero
      CALL ARCPTH (ARID, 'A', 109, PHEAD, 0, RETCOD,
     1             '101,1, 102,1, 109,0        /'  //
     2             '101,1, 102,2, 104,1, 109,0 /'  //
     3             '101,2, 103,1, 104,1, 109,0 /'  //
     4             '101,2, 103,2, 105,1, 109,0 /'  //
     5             '101,2, 103,3, 105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 107
C       path order   = BOTTOMFIRST
C       path depth   = zero
      CALL ARCPTH (ARID, 'A', 107, PTAIL, 0, RETCOD,
     1             '101,3, 107,0 /' //
     2             '106,1, 107,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 106
C       path order   = BOTTOMFIRST
C       path depth   = zero
      CALL ARCPTH (ARID, 'A', 106, PTAIL, 0, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 108
C       path order   = TOPFIRST
C       path depth   = zero
      CALL ARCPTH (ARID, 'A', 108, PHEAD, 0, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF
 
      CALL PASS
 
C  *** *** *** ***   Truncating via TOPFIRST   *** *** *** ***
 
2000  CONTINUE
 
      CALL SETMSG ('5 7 8 10 12 16', '<Retrieve paths to ancestors> ' //
     1             'should retrieve all qualifying ancestor paths '   //
     2             '(or portions thereof), with no repetition, when ' //
     3             'path depth is positive and path order is '        //
     4             'TOPFIRST.')
 
C  Use <retrieve paths to ancestors> with
C       structure id = 109
C       path order   = TOPFIRST
C       path depth   = 3
      CALL ARCPTH (ARID, 'A', 109, PHEAD, 3, RETCOD,
     1             '101,1, 102,1, 109,0 /' //
     2             '101,1, 102,2, 104,1 /' //
     3             '101,2, 103,1, 104,1 /' //
     4             '101,2, 103,2, 105,1 /' //
     5             '101,2, 103,3, 105,1 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 104
C       path order   = TOPFIRST
C       path depth   = 5
C    saap = set of all ancestor paths.
      CALL ARCPTH (ARID, 'A', 104, PHEAD, 5, RETCOD,
     1             '101,1, 102,2, 104,0 /' //
     2             '101,2, 103,1, 104,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 105
C       path order   = TOPFIRST
C       path depth   = 1
      CALL ARCPTH (ARID, 'A', 105, PHEAD, 1, RETCOD, '101,2 /')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 101
C       path order   = TOPFIRST
C       path depth   = 5
      CALL ARCPTH (ARID, 'A', 101, PHEAD, 5, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF
 
      CALL PASS
 
C  *** *** *** ***   Truncating via BOTTOMFIRST   *** *** *** ***
3000  CONTINUE
 
      CALL SETMSG ('5 7 8 10 13 16', '<Retrieve paths to ancestors> ' //
     1             'should retrieve all qualifying ancestor paths '   //
     2             '(or portions thereof), with no repetition, when ' //
     3             'path depth is positive and path order is '        //
     4             'BOTTOMFIRST.')
 
C  Use <retrieve paths to ancestors> with
C       structure id = 109
C       path order   = BOTTOMFIRST
C       path depth   = 3
C    saap = set of all ancestor paths.
      CALL ARCPTH (ARID, 'A', 109, PTAIL, 3, RETCOD,
     1             '101,1, 102,1, 109,0 /' //
     2             '102,2, 104,1, 109,0 /' //
     3             '103,1, 104,1, 109,0 /' //
     4             '103,2, 105,1, 109,0 /' //
     5             '103,3, 105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 109
C       path order   = BOTTOMFIRST
C       path depth   = 2
      CALL ARCPTH (ARID, 'A', 109, PTAIL, 2, RETCOD,
     1             '102,1, 109,0 /' //
     2             '104,1, 109,0 /' //
     3             '105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 107
C       path order   = BOTTOMFIRST
C       path depth   = 5
      CALL ARCPTH (ARID, 'A', 107, PTAIL, 5, RETCOD,
     1             '101,3, 107,0 / ' //
     2             '106,1, 107,0 / ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 107
C       path order   = BOTTOMFIRST
C       path depth   = 1
      CALL ARCPTH (ARID, 'A', 107, PTAIL, 1, RETCOD, '107,0 /')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF
 
C  Use <retrieve paths to ancestors> with
C       structure id = 106
C       path order   = BOTTOMFIRST
C       path depth   = 1
      CALL ARCPTH (ARID, 'A', 106, PTAIL, 1, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF
 
      CALL PASS
 
666   CONTINUE
C  close archive file
      CALL PCLARF (ARID)
      CALL ENDIT
      END
