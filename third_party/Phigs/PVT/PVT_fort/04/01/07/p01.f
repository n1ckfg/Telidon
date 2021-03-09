C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.07/01                           *
C  *    TEST TITLE : Cell array element                    *
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

      INTEGER    PEFAS3,      PEFAS,       PECA3,       PECA
      PARAMETER (PEFAS3 = 12, PEFAS  = 13, PECA3  = 14, PECA   = 15)

      INTEGER CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR, XDIM, YDIM
      INTEGER INLEN, STLEN, RELEN, K, STRID, CLIMIT, IROW, ICOL

      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, CLIMIT = 10,
     1           STRID = 1)

      INTEGER INTAR(INLEN), STRARL(STLEN), COLIA(CLIMIT, CLIMIT)
      INTEGER ARRLEN(CLIMIT), EXPCTD(50), NOCOLS, X1ST, Y1ST

      LOGICAL IAREQ

      REAL XPARPT(3), YPARPT(3), ZPARPT(3), RLAR(RELEN)

C Points for degenerate case
      REAL DEGXPT(3), DEGYPT(3), DEGZPT(3)

      CHARACTER STRAR(STLEN)

      DATA XPARPT / 55.55, -99.99,  3.2E5/
      DATA YPARPT /  0.0,    3.,   -3.2E-15/
      DATA ZPARPT /  4.44,   0.0,   0.00023/

C  Data points for degenerate case
      DATA DEGXPT / 1.0, 1.0,  1.0/
      DATA DEGYPT / 2.0, 2.0,  2.0/
      DATA DEGZPT / 2.0, 3.0,  5.0/

      CALL INITGL ('04.01.07/01')
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  *** *** ***   Cell array 3 - Normal Case  *** *** ***

C  Initialize 2D cell array - normal case
      CALL SET2D ('0/  0,0,  0, 2, 9, 3, 7, 2, 3/' //
     1                '0,0,  7, 2, 8, 6, 3, 8, 7/' //
     2                '0,0,  1, 0, 2, 3, 9, 3, 8/',
     3            CLIMIT, NOCOLS, ARRLEN, COLIA)
      XDIM = 7
      YDIM = 3
      X1ST = 3
      Y1ST = 2

C compute expected array - normal case
      K = 2
      DO 15 IROW = Y1ST, YDIM + Y1ST - 1
         DO 10 ICOL = X1ST, XDIM + X1ST - 1
            K = K + 1
            EXPCTD(K) = COLIA(ICOL, IROW)
10       CONTINUE
15    CONTINUE
 
      CALL POPST (STRID)

      CALL PCA3 (XPARPT, YPARPT, ZPARPT, CLIMIT, CLIMIT, X1ST,Y1ST,
     1           XDIM, YDIM, COLIA)

C  <inquire current element type and size> to set celtyp, celsiz
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return cell array 3 as the type of the '   //
     2             'created element and the appropriate element '     //
     3             'size.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0              .AND.
     1           CELTYP   .EQ.   PECA3          .AND.
     2           INTLEN   .EQ.   2 + XDIM*YDIM  .AND.
     3           RLLEN    .EQ.   9              .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for cell '     //
     2             'array 3.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1            RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.   0             .AND.
     1    INTG     .EQ.   2 + XDIM*YDIM .AND.
     2    INTAR(1) .EQ.   XDIM          .AND.
     3    INTAR(2) .EQ.   YDIM          .AND.
     4    RL       .EQ.   9             .AND.
     5    RLAR(1)  .EQ.   XPARPT(1)     .AND.
     6    RLAR(2)  .EQ.   YPARPT(1)     .AND.
     7    RLAR(3)  .EQ.   ZPARPT(1)     .AND.
     8    RLAR(4)  .EQ.   XPARPT(2)     .AND.
     9    RLAR(5)  .EQ.   YPARPT(2)     .AND.
     1    RLAR(6)  .EQ.   ZPARPT(2)     .AND.
     2    RLAR(7)  .EQ.   XPARPT(3)     .AND.
     3    RLAR(8)  .EQ.   YPARPT(3)     .AND.
     4    RLAR(9)  .EQ.   ZPARPT(3)     .AND.
     5    STR      .EQ.   0)           THEN

C        OK so far
         IF (IAREQ (K-2, INTAR(3), EXPCTD(3))) THEN
            CALL PASS
         ELSE
            CALL FAIL
            CALL INMSG ('Color index values are incorrect.')
         ENDIF
      ELSE
          CALL FAIL
          CALL INMSG ('Array sizes or corner points are incorrect.')
      ENDIF

C  *** *** *** *** ***   Cell array - normal case *** *** *** *** ***

      CALL PCA (XPARPT(1), YPARPT(1), XPARPT(2), YPARPT(2),
     1          CLIMIT,CLIMIT, X1ST,Y1ST, XDIM,YDIM, COLIA)

      CALL SETMSG ('6 7', '<Inquire current element type and size> '  //
     1             'should return cell array as the type of the '     //
     2             'created element and the appropriate element '     //
     3             'size.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0              .AND.
     1           CELTYP   .EQ.   PECA           .AND.
     2           INTLEN   .EQ.   2 + XDIM*YDIM  .AND.
     3           RLLEN    .EQ.   4              .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('6 8', '<Inquire current element content> should ' //
     1             'return the standard representation for cell array.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.   0             .AND.
     1    INTG     .EQ.   2 + XDIM*YDIM .AND.
     2    INTAR(1) .EQ.   XDIM          .AND.
     3    INTAR(2) .EQ.   YDIM          .AND.
     4    RL       .EQ.   4             .AND.
     5    RLAR(1)  .EQ.   XPARPT(1)     .AND.
     6    RLAR(2)  .EQ.   YPARPT(1)     .AND.
     7    RLAR(3)  .EQ.   XPARPT(2)     .AND.
     8    RLAR(4)  .EQ.   YPARPT(2)     .AND.
     9    STR      .EQ.   0)                THEN

C        OK so far
         IF (IAREQ (K-2, INTAR(3), EXPCTD(3))) THEN
            CALL PASS
         ELSE
            CALL FAIL
            CALL INMSG ('Color index values are incorrect.')
         ENDIF
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes or corner points are incorrect.')
      ENDIF

C  *** *** *** *** ***   Cell array 3 - Degenerate Case  *** *** *** *** ***

C  Initialize 2D cell array - degenerate case
      CALL SET2D ('0/  0,0,  9, 3/' //
     1                '0,0,  8, 6/' //
     2                '0,0,  1, 0/',
     3            CLIMIT, NOCOLS, ARRLEN, COLIA)

      XDIM = 2
      YDIM = 3
      X1ST = 3
      Y1ST = 2

C compute expected array - degenerate case
      K = 2
      DO 20 IROW = Y1ST, YDIM + Y1ST - 1
         DO 25 ICOL = X1ST, XDIM + X1ST - 1
            K = K + 1
            EXPCTD(K) = COLIA(ICOL, IROW)
25       CONTINUE
20    CONTINUE

      CALL PCA3 (DEGXPT, DEGYPT, DEGZPT, CLIMIT, CLIMIT, X1ST,Y1ST,
     1           XDIM, YDIM, COLIA)

C  <inquire current element type and size> to set celtyp, celsiz
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return cell array 3 as the type of the '   //
     2             'created element and the appropriate element '     //
     3             'size for a degenerate element.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0              .AND.
     1           CELTYP   .EQ.   PECA3          .AND.
     2           INTLEN   .EQ.   2 + XDIM*YDIM  .AND.
     3           RLLEN    .EQ.   9              .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'degenerate cell array 3.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1            RL, RLAR, STR, STRARL, STRAR)

C INTAR(1) = x dimension of cell index array
C INTAR(2) = y dimension of cell index array
C INTAR(3) - INTAR( XDIM*YDIM +2) =  index array in column major order
C          (e.g., INTAR(3) = COLIA(1,1) INTAR(4) = COLIA(2,1)...
C
      IF (ERRIND   .EQ.   0             .AND.
     1    INTG     .EQ.   2 + XDIM*YDIM .AND.
     2    INTAR(1) .EQ.   XDIM          .AND.
     3    INTAR(2) .EQ.   YDIM          .AND.
     4    RL       .EQ.   9             .AND.
C
C  9 Coordinates of the parallelagram
C
     5    RLAR(1)  .EQ.   DEGXPT(1)    .AND.
     6    RLAR(2)  .EQ.   DEGYPT(1)    .AND.
     7    RLAR(3)  .EQ.   DEGZPT(1)    .AND.
     8    RLAR(4)  .EQ.   DEGXPT(2)    .AND.
     9    RLAR(5)  .EQ.   DEGYPT(2)    .AND.
     1    RLAR(6)  .EQ.   DEGZPT(2)    .AND.
     2    RLAR(7)  .EQ.   DEGXPT(3)    .AND.
     3    RLAR(8)  .EQ.   DEGYPT(3)    .AND.
     4    RLAR(9)  .EQ.   DEGZPT(3)    .AND.
     5    STR      .EQ.   0)           THEN
C        OK so far
         IF (IAREQ (K-2, INTAR(3), EXPCTD(3))) THEN
            CALL PASS
         ELSE
            CALL FAIL
            CALL INMSG ('Color index values are incorrect.')
         ENDIF
      ELSE
          CALL FAIL
          CALL INMSG ('Array sizes or corner points are incorrect.')
      ENDIF

C  *** *** *** *** ***   Cell array - degenerate case *** *** *** *** ***

      CALL PCA (DEGXPT(1), DEGYPT(1), DEGXPT(2), DEGYPT(2),
     1          CLIMIT,CLIMIT, X1ST,Y1ST, XDIM,YDIM, COLIA)

      CALL SETMSG ('6 7', '<Inquire current element type and size> '  //
     1             'should return cell array as the type of the '     //
     2             'created element and the appropriate element '     //
     3             'size for a degenerate element.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0              .AND.
     1           CELTYP   .EQ.   PECA           .AND.
     2           INTLEN   .EQ.   2 + XDIM*YDIM  .AND.
     3           RLLEN    .EQ.   4              .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('6 8', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'degenerate cell array.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.   0             .AND.
C INTAR(1) = x dimension of cell index array
C INTAR(2) = y dimension of cell index array
C INTAR(3) - INTAR( XDIM*YDIM +2) =  index array in column major order
C          (e.g., INTAR(3) = COLIA(1,1) INTAR(4) = COLIA(2,1)...
C
     1    INTG     .EQ.   2 + XDIM*YDIM .AND.
     2    INTAR(1) .EQ.   XDIM          .AND.
     3    INTAR(2) .EQ.   YDIM          .AND.
     4    RL       .EQ.   4             .AND.
C  Coordinates of P,Q
     5    RLAR(1)  .EQ.   DEGXPT(1)     .AND.
     6    RLAR(2)  .EQ.   DEGYPT(1)     .AND.
     7    RLAR(3)  .EQ.   DEGXPT(2)     .AND.
     8    RLAR(4)  .EQ.   DEGYPT(2)     .AND.
     9    STR      .EQ.   0)                THEN
C        OK so far
         IF (IAREQ (K-2, INTAR(3), EXPCTD(3))) THEN
            CALL PASS
         ELSE
            CALL FAIL
            CALL INMSG ('Color index values are incorrect.')
         ENDIF
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes or corner points are incorrect.')
      ENDIF

777   CONTINUE
C close structure and PHIGS
      CALL ENDIT

      END
