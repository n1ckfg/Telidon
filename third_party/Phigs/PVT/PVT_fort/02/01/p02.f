C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01/02                              *
C  *    TEST TITLE : Inquiring about ancestor paths        *
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
     3        DUMINT(20)
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

C truncation method
      INTEGER    PHEAD,     PTAIL
      PARAMETER (PHEAD = 0, PTAIL = 1)

      INTEGER     RETCOD

      CALL INITGL ('02.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  Use <open structure> and <execute structure> to set up
C  the CSS as follows:
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

C  common setup routine here
      CALL CSSPTH

C  *** *** *** *** ***   No truncation   *** *** *** *** ***

      CALL SETMSG ('1 3 5 6 7', '<Inquire paths to ancestors> '  //
     1             'should retrieve all maximal ancestor paths ' //
     2             'when path depth is zero.')

C compare set of all reported ancestor paths to expected value.
      CALL PTHSEQ ('A', 109, PHEAD, 0, RETCOD,
     1             '101,1, 102,1, 109,0        /'  //
     2             '101,1, 102,2, 104,1, 109,0 /'  //
     3             '101,2, 103,1, 104,1, 109,0 /'  //
     4             '101,2, 103,2, 105,1, 109,0 /'  //
     5             '101,2, 103,3, 105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF

      CALL PTHSEQ ('A', 107, PTAIL, 0, RETCOD,
     1             '101,3, 107,0 /' //
     2             '106,1, 107,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF

      CALL PTHSEQ ('A', 106, PTAIL, 0, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF

      CALL PTHSEQ ('A', 108, PHEAD, 0, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF

      CALL PASS

C  *** *** *** *** ***   Truncating via TOPFIRST   *** *** *** *** ***

2000  CONTINUE

      CALL SETMSG ('1 3 5 6 9 13', '<Inquire paths to ancestors> ' //
     1             'should retrieve all qualifying ancestor '      //
     2             'paths (or portions thereof), with no '         //
     3             'repetition, when path depth is positive and '  //
     4             'path order is TOPFIRST.' )

      CALL PTHSEQ ('A', 109, PHEAD, 3, RETCOD,
     1             '101,1, 102,1, 109,0 /' //
     2             '101,1, 102,2, 104,1 /' //
     3             '101,2, 103,1, 104,1 /' //
     4             '101,2, 103,2, 105,1 /' //
     5             '101,2, 103,3, 105,1 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF

      CALL PTHSEQ ('A', 105, PHEAD, 1, RETCOD, '101,2 /')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF

      CALL PTHSEQ ('A', 101, PHEAD, 5, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF

      CALL PASS

C  *** *** *** *** ***   Truncating via BOTTOMFIRST   *** *** *** *** ***

3000  CONTINUE

      CALL SETMSG ('1 3 5 6 10 13',
     1             '<Inquire paths to ancestors> should retrieve ' //
     2             'all qualifying ancestor paths (or portions '   //
     3             'thereof), with no repetition, when path '      //
     4             'depth is positive and path order is BOTTOMFIRST.')

      CALL PTHSEQ ('A', 109, PTAIL, 3, RETCOD,
     1             '101,1, 102,1, 109,0 /' //
     2             '102,2, 104,1, 109,0 /' //
     3             '103,1, 104,1, 109,0 /' //
     4             '103,2, 105,1, 109,0 /' //
     5             '103,3, 105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF

      CALL PTHSEQ ('A', 109, PTAIL, 2, RETCOD,
     1             '102,1, 109,0 /' //
     2             '104,1, 109,0 /' //
     3             '105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF

      CALL PTHSEQ ('A', 107, PTAIL, 5, RETCOD,
     1             '101,3, 107,0 / ' //
     2             '106,1, 107,0 / ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF

      CALL PTHSEQ ('A', 107, PTAIL, 1, RETCOD, '107,0 /')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF

      CALL PTHSEQ ('A', 106, PTAIL, 1, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF

      CALL PASS

666   CONTINUE
      CALL ENDIT
      END
