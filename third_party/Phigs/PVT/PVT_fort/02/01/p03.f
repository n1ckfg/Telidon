C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01/03                              *
C  *    TEST TITLE : Inquiring about descendant paths      *
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

      CALL INITGL ('02.01/03')

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

      CALL SETMSG ('1 4 5 6 8',
     1             '<Inquire paths to descendants> should '        //
     1             'retrieve all maximal descendant paths when '   //
     1             'path depth is zero.' )

      CALL PTHSEQ ('D', 101, PHEAD, 0, RETCOD,
     1             '101,1, 102,1, 109,0 /'        //
     1             '101,1, 102,2, 104,1, 109,0 /' //
     1             '101,2, 103,1, 104,1, 109,0 /' //
     1             '101,2, 103,2, 105,1, 109,0 /' //
     1             '101,2, 103,3, 105,1, 109,0 /' //
     1             '101,3, 107,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF

      CALL PTHSEQ ('D', 103, PTAIL, 0, RETCOD,
     1             '103,1, 104,1, 109,0 /' //
     1             '103,2, 105,1, 109,0 /' //
     1             '103,3, 105,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF

      CALL PTHSEQ ('D', 109, PTAIL, 0, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF

      CALL PTHSEQ ('D', 108, PHEAD, 0, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 2000
      ENDIF

      CALL PASS

C  *** *** *** *** ***   Truncating via TOPFIRST   *** *** *** *** ***

2000  CONTINUE

      CALL SETMSG ('1 4 5 6 11 14',
     1             '<Inquire paths to descendants> should '        //
     1             'retrieve all qualifying descendant paths (or ' //
     1             'portions thereof), with no repetition, when '  //
     1             'path depth is positive and path order is '     //
     1             'TOPFIRST.' )

      CALL PTHSEQ ('D', 101, PHEAD, 2, RETCOD,
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

      CALL PTHSEQ ('D', 101, PHEAD, 1, RETCOD,
     1             '101,1 /' //
     1             '101,2 /' //
     1             '101,3 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF

      CALL PTHSEQ ('D', 104, PHEAD, 5, RETCOD,
     1             '104,1, 109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF

      CALL PTHSEQ ('D', 109, PHEAD, 5, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 3000
      ENDIF

      CALL PASS

C  *** *** *** *** ***   Truncating via BOTTOMFIRST   *** *** *** *** ***

3000  CONTINUE

      CALL SETMSG ('1 4 5 6 12 14',
     1             '<Inquire paths to descendants> should retrieve ' //
     1             'all qualifying descendant paths (or portions '   //
     1             'thereof), with no repetition, when path depth '  //
     1             'is positive and path order is BOTTOMFIRST.' )

      CALL PTHSEQ ('D', 101, PTAIL, 2, RETCOD,
     1             '102,1, 109,0 /' //
     1             '104,1, 109,0 /' //
     1             '105,1, 109,0 /' //
     1             '101,3, 107,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF

      CALL PTHSEQ ('D', 102, PTAIL, 1, RETCOD, '109,0 /' )
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF

      CALL PTHSEQ ('D', 108, PTAIL, 1, RETCOD, ' ')
      IF (RETCOD .NE. 0) THEN
         CALL FAIL
         GOTO 666
      ENDIF

      CALL PASS

666   CONTINUE
      CALL ENDIT
      END
