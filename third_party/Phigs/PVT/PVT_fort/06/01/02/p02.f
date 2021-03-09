C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/02                           *
C  *    TEST TITLE : Setting and inquiring global          *
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
 
C Element type
      INTEGER     PEGMT3, PEGMT
      PARAMETER  (PEGMT3 = 59, PEGMT = 60)
 
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
 
      CALL INITGL ('06.01.02/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      STRID = 101
      CALL POPST (STRID)
 
 
C  Use <inquire current element type and size> thoughout to determine
C      current element type
C
C  Use <inquire current element content> throughout to determine
C      current element content
 
C  <Set global transformation 3> with m4
      CALL PSGMT3 (M4)
 
      CALL SETMSG ('9 10', '<Inquire current element type and size> ' //
     1             'should return set global transformation 3 as '    //
     2             'the type of the created element and the '         //
     3             'appropriate element size.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PEGMT3 .AND.
     2            INTLEN   .EQ.   0      .AND.
     3            RLLEN    .EQ.  16      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('9 11', '<Inquire current element content> should '//
     1             'return the standard representation for set '      //
     2             'global transformation 3.')
 
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  0      .AND.
     2    RL       .EQ. 16      .AND.
     3    STR      .EQ.  0)  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes are incorrect.')
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
 
C  <Set global transformation> with m3
      CALL PSGMT (M3)
 
      CALL SETMSG ('12 13', '<Inquire current element type and '      //
     1             'size> should return set global transformation '   //
     2             'as the type of the created element and the '      //
     3             'appropriate element size.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PEGMT  .AND.
     2            INTLEN   .EQ.   0      .AND.
     3            RLLEN    .EQ.   9      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('12 14', '<Inquire current element content> '      //
     1             'should return the standard representation for '   //
     2             'set global transformation.')
 
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  0      .AND.
     2    RL       .EQ.  9      .AND.
     3    STR      .EQ.  0)  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes are incorrect.')
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
