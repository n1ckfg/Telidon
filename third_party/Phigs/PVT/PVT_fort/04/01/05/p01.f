C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.05/01                           *
C  *    TEST TITLE : Fill area element                     *
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

      INTEGER    CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR, INLEN,
     1           STLEN, RELEN, N, I, STRID

      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, STRID = 1)

      INTEGER    INTAR(INLEN), STRARL(STLEN), DEGEN

      LOGICAL    OKSOFR, RAREQ, VALETS,VALEC

      REAL       XARR(5), YARR(5), ZARR(5), RLAR(RELEN), RLCOMB(15)

      CHARACTER  STRAR(STLEN)

      DATA XARR /2.33, 55.55, -4.4, 123.0,     0.0/
      DATA YARR /0.0,   3.2, -99.99,  3.2E22, -2.2E-22/
      DATA ZARR /4.44,  0.0,   0.0,   5.5,    22.22/

      CALL INITGL ('04.01.05/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPST (STRID)

      N = 5
C set up expected values
      DO 10 I = 1, N
         RLCOMB(I)     = XARR(I)
         RLCOMB(I+N)   = YARR(I)
         RLCOMB(I+2*N) = ZARR(I)
10    CONTINUE

C  *** *** *** *** ***   Fill area 3   *** *** *** *** ***

C  <fill area 3> with n,xarr,yarr,zarr
      CALL PFA3 (N, XARR, YARR, ZARR)

C  <inquire current element type and size> to set celtyp, celsiz
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return fill area 3 as the type of the '    //
     2             'created element and the appropriate element '     //
     3             'size for a multipoint element.')

C    (celtyp = fill area 3 and
C     celsiz = values specified by the standard and language binding;
C              fortran binding values are intlen, rllen, and strlen)

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0  .AND.
     1           CELTYP   .EQ.  10  .AND.
     2           INTLEN   .EQ.   1  .AND.
     3           RLLEN    .EQ.  3*N .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'multipoint fill area 3.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  1      .AND.
     2    INTAR(1) .EQ.  N      .AND.
     3    RL       .EQ. 3*N     .AND.
     4    STR      .EQ.  0)           THEN
         OKSOFR = .TRUE.
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Array sizes are incorrect.')
      ENDIF

      IF (RAREQ (3*N, RLAR, RLCOMB, 0.0, 0.0)) THEN
C        ok so far
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Geometric point values are incorrect.')
      ENDIF

      CALL IFPF (OKSOFR)

C  valid type and content so far for degenerate elements
      VALETS = .TRUE.
      VALEC  = .TRUE.

      DO 100 DEGEN = 1,2
         CALL PFA3 (DEGEN, XARR, YARR, ZARR)
         CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
         IF (ERRIND   .EQ.   0      .AND.
     1       CELTYP   .EQ.  10      .AND.
     2       INTLEN   .EQ.   1      .AND.
     3       RLLEN    .EQ.  DEGEN*3 .AND.
     4       STRLEN   .EQ.   0) THEN
C           OK so far
         ELSE
            VALETS = .FALSE.
         ENDIF

         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND   .EQ.   0         .AND.
     1       INTG     .EQ.   1         .AND.
     2       INTAR(1) .EQ.   DEGEN     .AND.
     3       RL       .EQ.   DEGEN*3   .AND.
     4       RAREQ(DEGEN, RLAR(1),         XARR, 0.0, 0.0) .AND.
     5       RAREQ(DEGEN, RLAR(  DEGEN+1), YARR, 0.0, 0.0) .AND.
     6       RAREQ(DEGEN, RLAR(2*DEGEN+1), ZARR, 0.0, 0.0) .AND.
     7       STR      .EQ.   0) THEN
C           OK so far
         ELSE
            VALEC = .FALSE.
         ENDIF
100   CONTINUE

      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return fill area 3 as the type of the '    //
     2             'created element and the appropriate element '     //
     3             'size for a single or double point element.')
      CALL IFPF (VALETS)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for a single ' //
     2             'or double point fill area 3.')
      CALL IFPF (VALEC)

C  *** *** *** *** ***   Fill area   *** *** *** *** ***

C  <fill area> with n,xarr,yarr
      N = 5
      CALL PFA (N, XARR, YARR)

C  <inquire current element type and size> to set celtyp, celsiz

      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return fill area as the type of the '      //
     2             'created element and the appropriate element '     //
     3             'size for a multipoint element.')

C    (celtyp = fill area and
C     celsiz = values specified by the standard and language binding)
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.  11   .AND.
     2           INTLEN   .EQ.   1   .AND.
     3           RLLEN    .EQ.  2*N  .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('4 6', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'multipoint fill area.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.   0  .AND.
     1    INTG     .EQ.   1  .AND.
     2    INTAR(1) .EQ.   N  .AND.
     3    RL       .EQ.  2*N .AND.
     4    STR      .EQ.   0)    THEN
         OKSOFR = .TRUE.
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Array sizes are incorrect.')
      ENDIF

      IF (RAREQ (2*N, RLAR, RLCOMB, 0.0, 0.0)) THEN
C        ok so far
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Geometric point values are incorrect.')
      ENDIF

      CALL IFPF (OKSOFR)

C  valid type and content so far for degenerate elements
      VALETS = .TRUE.
      VALEC  = .TRUE.

      DO 200 DEGEN = 1,2
         CALL PFA (DEGEN, XARR, YARR)
         CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
         IF (ERRIND   .EQ.   0      .AND.
     1       CELTYP   .EQ.  11      .AND.
     2       INTLEN   .EQ.   1      .AND.
     3       RLLEN    .EQ.  DEGEN*2 .AND.
     4       STRLEN   .EQ.   0) THEN
C           OK so far
         ELSE
            VALETS = .FALSE.
         ENDIF

         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND   .EQ.   0         .AND.
     1       INTG     .EQ.   1         .AND.
     2       INTAR(1) .EQ.   DEGEN     .AND.
     3       RL       .EQ.   DEGEN*2   .AND.
     4       RAREQ(DEGEN, RLAR(1),         XARR, 0.0, 0.0) .AND.
     5       RAREQ(DEGEN, RLAR(  DEGEN+1), YARR, 0.0, 0.0) .AND.
     6       STR      .EQ.   0) THEN
C           OK so far
         ELSE
            VALEC = .FALSE.
         ENDIF
200   CONTINUE

C  <inquire current element type and size> to set celtyp, celsiz
      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return fill area as the type of the '      //
     2             'created element and the appropriate element '     //
     3             'size for a single or double point element.')
      CALL IFPF (VALETS)

      CALL SETMSG ('4 6', '<Inquire current element content> should ' //
     1             'return the standard representation for a single ' //
     2             'or double point fill area.')
      CALL IFPF (VALEC)

777   CONTINUE
      CALL ENDIT
      END
