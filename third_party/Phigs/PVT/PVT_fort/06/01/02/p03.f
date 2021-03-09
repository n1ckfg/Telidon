C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/03                           *
C  *    TEST TITLE : Setting and inquiring modelling       *
C  *                 clipping                              *
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
      INTEGER     PEMCV3,      PEMCV,      PEMCLI,      PERMCV
      PARAMETER  (PEMCV3 = 61, PEMCV = 62, PEMCLI = 63, PERMCV = 64)
 
C Clipping indicator
      INTEGER     PNCLIP,     PCLIP
      PARAMETER  (PNCLIP = 0, PCLIP = 1)
 
C array sizes
      INTEGER    INLEN, RELEN, STLEN
      PARAMETER (INLEN = 20, RELEN = 20, STLEN = 20)
 
      INTEGER    CELTYP, INTLEN, RLLEN, STRLEN, ROW, COL, IX
      INTEGER    OPRATR, NDPMCV, NAVMCO, IDUM1, IDUM2, MAXOP, MINOP
      INTEGER    OPVAL, ACTMIN, LHSLIM, IOP, NOHS, I,J
 
C program limit on number of half-spaces
      PARAMETER  (LHSLIM = 100)
 
      INTEGER    INTG, INTAR(INLEN), RL, STR, STRARL(STLEN)
 
      LOGICAL    GOTOP(2)
 
      CHARACTER  STRAR(STLEN), MSG*300
 
      REAL       LHS3(6,3), LHS2(4,3), RLAR(RELEN), HSVAL
      REAL       LHSM(6, LHSLIM), REPLHS(6*LHSLIM)
 
C  lhs3 = 3D half space list, in point-vector format:
C
C                point                     vector
C                -----                     ------
      DATA LHS3 /2.2, -33.33E33, 9.9E-11,  -1.2,     3.4,   5.6,
     1           4.4,   5.5,     6.6,     -98.76,  543.21,  0.1E-11,
     2           0.0,  -5.2,     9.9,       2.2,     3.3,   4.4  /
 
 
C  lhs2 = 2D half space list, in point-vector format:
C
C                 point                 vector
C                 -----                 ------
      DATA LHS2 / -33.33E33, 9.9E-11,    -1.2,     3.4,
     1              5.5,     6.6,       -98.76,  543.21,
     2             -5.2,     9.9,         2.2,     3.3 /
 
      CALL INITGL ('06.01.02/03')
 
C open PHIGS and structure
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPST (10)
 
C  Use <inquire current element type and size> thoughout to determine
C      current element type
C
C  Use <inquire current element content> throughout to determine
C      current element content
 
C  *** *** ***   Set modelling clipping volume 3   *** *** ***
 
      OPRATR = 1
C  <Set modelling clipping volume 3> with operator, lhs3
      CALL PSMCV3 (OPRATR, 3, LHS3)
 
      CALL SETMSG ('23 24', '<Inquire current element type and '      //
     1             'size> should return set modelling clipping '      //
     2             'volume 3 as the type of the created element and ' //
     3             'the appropriate element size.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PEMCV3 .AND.
     2            INTLEN   .EQ.   2      .AND.
     3            RLLEN    .EQ.  18      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('23 25', '<Inquire current element content> '      //
     1             'should return the standard representation for '   //
     2             'set modelling clipping volume 3.')
 
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  2      .AND.
     2    INTAR(1) .EQ.  OPRATR .AND.
     3    INTAR(2) .EQ.  3      .AND.
     4    RL       .EQ. 18      .AND.
     5    STR      .EQ.  0)  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes or operator type are incorrect.')
         GOTO 190
      ENDIF
 
      IX = 0
      DO 100 COL = 1,3
      DO 110 ROW = 1,6
         IX = IX+1
         IF (LHS3(ROW, COL) .NE. RLAR(IX)) THEN
            CALL FAIL
            CALL INMSG ('Half-space values are incorrect.')
            GOTO 190
         ENDIF
110   CONTINUE
100   CONTINUE
 
      CALL PASS
 
190   CONTINUE
 
C  *** *** ***   Set modelling clipping volume   *** *** ***
 
      OPRATR = 2
C  <Set modelling clipping volume> with operator, lhs2
      CALL PSMCV (OPRATR, 3, LHS2)
 
      CALL SETMSG ('26 27', '<Inquire current element type and '      //
     1             'size> should return set modelling clipping '      //
     2             'volume as the type of the created element and '   //
     3             'the appropriate element size.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PEMCV  .AND.
     2            INTLEN   .EQ.   2      .AND.
     3            RLLEN    .EQ.  12      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('26 28', '<Inquire current element content> '      //
     1             'should return the standard representation for '   //
     2             'set modelling clipping volume.')
 
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  2      .AND.
     2    INTAR(1) .EQ.  OPRATR .AND.
     3    INTAR(2) .EQ.  3      .AND.
     4    RL       .EQ. 12      .AND.
     5    STR      .EQ.  0)  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes or operator type are incorrect.')
         GOTO 290
      ENDIF
 
      IX = 0
      DO 200 COL = 1,3
      DO 210 ROW = 1,4
         IX = IX+1
         IF (LHS2(ROW, COL) .NE. RLAR(IX)) THEN
            CALL FAIL
            CALL INMSG ('Half-space values are incorrect.')
            GOTO 290
         ENDIF
210   CONTINUE
200   CONTINUE
 
      CALL PASS
 
290   CONTINUE
 
C  *** *** ***   Modelling clipping volume facilities   *** *** ***
 
      CALL PQMCLF (0, ERRIND, NDPMCV, NAVMCO, IDUM1)
      CALL CHKINQ ('pqmclf', ERRIND)
C keep track of op 1 and 2
      GOTOP (1) = .FALSE.
      GOTOP (2) = .FALSE.
C set up for max,min op
      MAXOP = -9999
      MINOP =  9999
 
      DO 300 IOP = 1,NAVMCO
         CALL PQMCLF (IOP, ERRIND, IDUM1, IDUM2, OPVAL)
         CALL CHKINQ ('pqmclf', ERRIND)
         IF (OPVAL .GE. 1 .AND. OPVAL .LE. 2) GOTOP (OPVAL) = .TRUE.
         MAXOP = MAX (MAXOP, OPVAL)
         MINOP = MIN (MINOP, OPVAL)
300   CONTINUE
 
      CALL SETMSG ('35 36', 'The list of of available modelling '     //
     1             'clipping operators reported by <inquire '         //
     2             'modelling clipping facilities> should contain 1 ' //
     3             'and 2.')
      CALL IFPF (GOTOP(1) .AND. GOTOP(2))
 
      CALL SETMSG ('35 37', 'The number of distinct planes for a '    //
     1             'modelling clipping volume reported by <inquire '  //
     2             'modelling clipping facilities> should be at '     //
     3             'least 6.')
      CALL IFPF (NDPMCV .GE. 6)
 
      CALL SETMSG ('38', '<Set modelling clipping volume> should be ' //
     1             'able to specify an operator with an integer '     //
     2             'value greater than those supported.')
 
      CALL ERRCTL (.TRUE.)
      CALL PSMCV  (MAXOP+1, 3, LHS2)
      CALL ERRCTL (.FALSE.)
      IF (ERRSIG .EQ. 0) THEN
C        <inquire current element content>
         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         CALL IFPF (ERRIND   .EQ.  0      .AND.
     1              INTG     .EQ.  2      .AND.
     2              INTAR(1) .EQ.  MAXOP+1)
      ELSE
         CALL FAIL
         CALL SIGMSG (ERRSIG, FUNCID, MSG)
         CALL INMSG (MSG)
      ENDIF
 
      CALL SETMSG ('38', '<Set modelling clipping volume 3> should '  //
     1             'be able to specify an operator with an integer '  //
     2             'value less than those supported.')
 
      CALL ERRCTL (.TRUE.)
      ACTMIN = MIN (-1, MINOP-1)
      CALL PSMCV3 (ACTMIN, 3, LHS3)
      CALL ERRCTL (.FALSE.)
      IF (ERRSIG .EQ. 0) THEN
C  <inquire current element content>
         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         CALL IFPF (ERRIND   .EQ.  0      .AND.
     1              INTG     .EQ.  2      .AND.
     2              INTAR(1) .EQ.  ACTMIN)
      ELSE
         CALL FAIL
         CALL SIGMSG (ERRSIG, FUNCID, MSG)
         CALL INMSG (MSG)
      ENDIF
 
      CALL SETMSG ('39', '<Set modelling clipping volume 3> should '  //
     1             'be able to specify a modelling clipping volume '  //
     2             'with zero half-spaces.')
 
      CALL ERRCTL (.TRUE.)
      CALL PSMCV3 (ACTMIN, 0, LHS3)
      CALL ERRCTL (.FALSE.)
      IF (ERRSIG .EQ. 0) THEN
C  <inquire current element content>
         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         CALL IFPF (ERRIND   .EQ.  0      .AND.
     1              INTG     .EQ.  2      .AND.
     2              INTAR(2) .EQ.  0)
      ELSE
         CALL FAIL
         CALL SIGMSG (ERRSIG, FUNCID, MSG)
         CALL INMSG (MSG)
      ENDIF
 
      CALL SETMSG ('39', '<Set modelling clipping volume> should be ' //
     1             'able to specify a modelling clipping volume '     //
     2             'with many half-spaces.')
 
C number of half-spaces to try
      NOHS = MIN (LHSLIM, NDPMCV+1)
C generate some numbers
      HSVAL = 5.5
      DO 330 I = 1,6
      DO 340 J = 1,NOHS
         HSVAL = HSVAL * 1.1
         IF (HSVAL .GT. 20.0) HSVAL = HSVAL / 21.3
         LHSM (I,J) = HSVAL
340   CONTINUE
330   CONTINUE
 
      CALL ERRCTL (.TRUE.)
      CALL PSMCV3 (1, NOHS, LHSM)
      CALL ERRCTL (.FALSE.)
      IF (ERRSIG .EQ. 0) THEN
C  <inquire current element content>
         CALL PQCECO (INLEN, 6*LHSLIM, STLEN, ERRIND, INTG, INTAR,
     1                RL, REPLHS, STR, STRARL, STRAR)
         IF (ERRIND   .EQ.  0      .AND.
     1       INTG     .EQ.  2      .AND.
     2       INTAR(2) .EQ.  NOHS)    THEN
C OK so far
            IX = 0
            DO 351 COL = 1,NOHS
            DO 352 ROW = 1,6
               IX = IX+1
               IF (LHSM(ROW, COL) .NE. REPLHS(IX)) THEN
                  CALL FAIL
                  CALL INMSG ('Half-space values are incorrect.')
                  GOTO 360
               ENDIF
352         CONTINUE
351         CONTINUE
            CALL PASS
360         CONTINUE
         ELSE
            CALL FAIL
            CALL INMSG ('Error code or array size incorrect.')
         ENDIF
      ELSE
         CALL FAIL
         CALL SIGMSG (ERRSIG, FUNCID, MSG)
         CALL INMSG (MSG)
      ENDIF
 
C  *** *** ***   Set modelling clipping indicator   *** *** ***
 
C  <Set modelling clipping indicator> with CLIP
      CALL PSMCLI (PCLIP)
 
      CALL SETMSG ('29 30', '<Inquire current element type and '      //
     1             'size> should return set modelling clipping '      //
     2             'indicator as the type of the created element '    //
     3             'and the appropriate element size, when CLIP is '  //
     4             'specified.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PEMCLI .AND.
     2            INTLEN   .EQ.   1      .AND.
     3            RLLEN    .EQ.   0      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('29 31 52', '<Inquire current element content> '   //
     1             'should return the standard representation for '   //
     2             'set modelling clipping indicator, when CLIP is '  //
     3             'specified.')
 
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      CALL IFPF (ERRIND   .EQ.  0      .AND.
     1           INTG     .EQ.  1      .AND.
     2           INTAR(1) .EQ.  PCLIP  .AND.
     3           RL       .EQ.  0      .AND.
     4           STR      .EQ.  0)
 
C  <Set modelling clipping indicator> with NOCLIP
      CALL PSMCLI (PNCLIP)
 
      CALL SETMSG ('29 30', '<Inquire current element type and '      //
     1             'size> should return set modelling clipping '      //
     2             'indicator as the type of the created element '    //
     3             'and the appropriate element size, when NOCLIP '   //
     4             'is specified.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PEMCLI .AND.
     2            INTLEN   .EQ.   1      .AND.
     3            RLLEN    .EQ.   0      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('29 31 52', '<Inquire current element content> '   //
     1             'should return the standard representation for '   //
     2             'set modelling clipping indicator, when NOCLIP '   //
     3             'is specified.')
 
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      CALL IFPF (ERRIND   .EQ.  0      .AND.
     1           INTG     .EQ.  1      .AND.
     2           INTAR(1) .EQ.  PNCLIP .AND.
     3           RL       .EQ.  0      .AND.
     4           STR      .EQ.  0)
 
 
C  *** *** ***   Restore modelling clipping volume   *** *** ***
 
C  <Restore modelling clipping volume>
      CALL PRMCV
 
      CALL SETMSG ('32 33', '<Inquire current element type and '      //
     1             'size> should return restore modelling clipping '  //
     2             'volume as the type of the created element and '   //
     3             'the appropriate element size.')
 
C  <inquire current element type and size>
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF ( ERRIND   .EQ.   0      .AND.
     1            CELTYP   .EQ.   PERMCV .AND.
     2            INTLEN   .EQ.   0      .AND.
     3            RLLEN    .EQ.   0      .AND.
     4            STRLEN   .EQ.   0)
 
      CALL SETMSG ('32 34', '<Inquire current element content> '      //
     1             'should return the standard representation for '   //
     2             'restore modelling clipping volume.')
 
C  <inquire current element content>
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
      CALL IFPF (ERRIND   .EQ.  0      .AND.
     1           INTG     .EQ.  0      .AND.
     2           RL       .EQ.  0      .AND.
     3           STR      .EQ.  0)
 
666   CONTINUE
      CALL ENDIT
      END
