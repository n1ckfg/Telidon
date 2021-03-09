C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/01                           *
C  *    TEST TITLE : Setting and inquiring local           *
C  *                 transformations                       *
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
 
C Composition type
      INTEGER     PCPRE,     PCPOST,     PCREPL
      PARAMETER  (PCPRE = 0, PCPOST = 1, PCREPL = 2)
 
C Element type
      INTEGER     PELMT3, PELMT
      PARAMETER  (PELMT3 = 57, PELMT = 58)
 
C array sizes
      INTEGER    INLEN, RELEN, STLEN
      PARAMETER (INLEN = 20, RELEN = 20, STLEN = 20)
 
      INTEGER    CELTYP, STRID, INTLEN, RLLEN, STRLEN, ROW, COL, IX
 
      INTEGER    INTG, INTAR(INLEN), RL, STR, STRARL(STLEN)
 
      REAL       M3(3,3), M4(4,4), RLAR(RELEN)
 
      CHARACTER  STRAR(STLEN)
 
C              | 2.2 -33.33e33 9.9e-11 |
C  matrix m3 = | 4.4   5.5     6.6     |
C              | 0.0  -5.2     9.9     |
 
      DATA M3 /2.2, 4.4, 0.0, -33.33E33, 5.5, -5.2, 9.9E-11, 6.6, 9.9/
 
C              | 2.2 -33.33e33 9.9e-11   1.34 |
C  matrix m4 = | 4.4   5.5     6.6      12.4  |
C              | 0.0  -5.2     9.9     123.0  |
C              | 3.1   4.1     5.9265   66.66 |
 
      DATA M4 /2.2, 4.4, 0.0, 3.1, -33.33E33, 5.5, -5.2, 4.1,
     1         9.9E-11, 6.6, 9.9, 5.9265, 1.34, 12.4, 123.0, 66.66/
 
      CALL INITGL ('06.01.02/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      STRID = 101
      CALL POPST (STRID)
 
C  Use <inquire current element type and size> thoughout to determine
C    current element type and size
C
C  Use <inquire current element content> throughout to determine
C    current element content
 
C  <Set local transformation 3> with m4, PRECONCATENATE
      CALL PSLMT3 (M4, PCPRE)
 
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return set local transformation 3 as the ' //
     2             'type of the created element and the appropriate ' //
     3             'element size, when PRECONCATENATE is specified.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PELMT3 .AND.
     2            INTLEN   .EQ.   1      .AND.
     3            RLLEN    .EQ.  16      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('1 3 7', '<Inquire current element content> '      //
     1             'should return the standard representation for '   //
     2             'set local transformation 3, when PRECONCATENATE ' //
     3             'is specified.')
 
C  garbage up output parameters where expected value is zero
      INTAR(1) = 666
      ERRIND = 666
      STR = 666
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  1      .AND.
     2    INTAR(1) .EQ.  PCPRE  .AND.
     3    RL       .EQ. 16      .AND.
     4    STR      .EQ.  0)  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes or composition type are incorrect.')
         GOTO 190
      ENDIF
 
      IX = 0
      DO 100 COL = 1,4
      DO 110 ROW = 1,4
         IX = IX+1
         IF (M4(ROW, COL) .NE. RLAR(IX)) THEN
            CALL FAIL
            CALL INMSG ('Matrix values are incorrect.')
            GOTO 190
         ENDIF
110   CONTINUE
100   CONTINUE
 
      CALL PASS
 
190   CONTINUE
 
C  <Set local transformation 3> with m4, REPLACE
      CALL PSLMT3 (M4, PCREPL)
 
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return set local transformation 3 as the ' //
     2             'type of the created element and the appropriate ' //
     3             'element size, when REPLACE is specified.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PELMT3 .AND.
     2            INTLEN   .EQ.   1      .AND.
     3            RLLEN    .EQ.  16      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('1 3 7', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'set local transformation 3, when REPLACE is '   //
     3             'specified.')
 
C  garbage up output parameters where expected value is zero
      INTAR(1) = 666
      ERRIND = 666
      STR = 666
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  1      .AND.
     2    INTAR(1) .EQ.  PCREPL .AND.
     3    RL       .EQ. 16      .AND.
     4    STR      .EQ.  0)  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes or composition type are incorrect.')
         GOTO 290
      ENDIF
 
      IX = 0
      DO 200 COL = 1,4
      DO 210 ROW = 1,4
         IX = IX+1
         IF (M4(ROW, COL) .NE. RLAR(IX)) THEN
            CALL FAIL
            CALL INMSG ('Matrix values are incorrect.')
            GOTO 290
         ENDIF
210   CONTINUE
200   CONTINUE
 
      CALL PASS
 
290   CONTINUE
 
C  <Set local transformation> with m3, POSTCONCATENATE
      CALL PSLMT (M3, PCPOST)
 
      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return set local transformation as the '   //
     2             'type of the created element and the appropriate ' //
     3             'element size, when POSTCONCATENATE is '           //
     4             'specified.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PELMT  .AND.
     2            INTLEN   .EQ.   1      .AND.
     3            RLLEN    .EQ.   9      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('4 6 7', '<Inquire current element content> '     //
     1             'should return the standard representation for '  //
     2             'set local transformation, when POSTCONCATENATE ' //
     3             'is specified.')
 
C  garbage up output parameters where expected value is zero
      INTAR(1) = 666
      ERRIND = 666
      STR = 666
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  1      .AND.
     2    INTAR(1) .EQ.  PCPOST .AND.
     3    RL       .EQ.  9      .AND.
     4    STR      .EQ.  0)  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes or composition type are incorrect.')
         GOTO 390
      ENDIF
 
      IX = 0
      DO 300 COL = 1,3
      DO 310 ROW = 1,3
         IX = IX+1
         IF (M3(ROW, COL) .NE. RLAR(IX)) THEN
            CALL FAIL
            CALL INMSG ('Matrix values are incorrect.')
            GOTO 390
         ENDIF
310   CONTINUE
300   CONTINUE
 
      CALL PASS
 
390   CONTINUE
 
666   CONTINUE
      CALL ENDIT
      END
