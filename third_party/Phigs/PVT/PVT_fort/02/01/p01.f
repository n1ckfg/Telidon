C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01/01                              *
C  *    TEST TITLE : Inquiring about structure identifiers *
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

      INTEGER LASI(20), IX, IDUM, NSTR
      LOGICAL SETIS

      CALL INITGL ('02.01/01')

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

      CALL SETMSG ('1 2', '<Inquire structure identifiers> should ' //
     1             'retrieve all identifiers as created by <open '  //
     2             'structure> and <execute structure>.')

C get list of all structure identifiers = lasi
      CALL PQSID  (0, ERRIND, NSTR, IDUM)
      CALL CHKINQ ('pqsid', ERRIND)

C full list should contain exactly 9 elements

      IF (NSTR .NE. 9) THEN
         CALL FAIL
         GOTO 100
      ENDIF

C get entire list
      DO 50 IX = 1,NSTR
         CALL PQSID  (IX, ERRIND, IDUM, LASI(IX) )
         CALL CHKINQ ('pqsid', ERRIND)
50    CONTINUE

C full list should contain exactly: 101, 102, 103, 104, 105, 106,
C 107, 108, 109

      CALL IFPF (SETIS (LASI, '101,102,103,104,105,106,107,108,109'))

100   CONTINUE
      CALL ENDIT
      END
