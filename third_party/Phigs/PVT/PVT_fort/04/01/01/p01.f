C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.01/01                           *
C  *    TEST TITLE : Polyline element                      *
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

      INTEGER   CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR, INLEN
      INTEGER   STLEN, RELEN, N, I, STRID

      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, STRID = 1)

      INTEGER   INTAR(INLEN), STRARL(STLEN)

      LOGICAL   OKSOFR, RAREQ

      REAL      XARR(5), YARR(5), ZARR(5), RLAR(RELEN), RLCOMB(15)

      CHARACTER STRAR(STLEN)

      DATA XARR /2.33, 55.55, -4.4, 123.0, 0.0/
      DATA YARR /0.0, 3.2, -99.99, 3.2E22, -2.2E-22/
      DATA ZARR /4.44, 0.0, 0.0, 5.5, 22.22/

      CALL INITGL ('04.01.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C set up expected values
      N = 5
      DO 10 I = 1, N
         RLCOMB(I)     = XARR(I)
         RLCOMB(I+N)   = YARR(I)
         RLCOMB(I+2*N) = ZARR(I)
10    CONTINUE

      CALL POPST (STRID)

C  *** *** *** *** ***   Polyline 3   *** *** *** *** ***

C  <polyline 3> with n,xarr,yarr,zarr
      CALL PPL3 (N, XARR, YARR, ZARR)

C  <inquire current element type and size> to set celtyp, celsiz
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return polyline 3 as the type of the '     //
     2             'created element and the appropriate element '     //
     3             'size for a multipoint element.')

C    (celtyp = polyline 3 and
C     celsiz = values specified by the standard and language binding;
C              fortran binding values are intlen, rllen, and strlen)

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   2   .AND.
     2           INTLEN   .EQ.   1   .AND.
     3           RLLEN    .EQ. 3*N   .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'multipoint polyline 3.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1            RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.  0      .AND.
     1    INTG     .EQ.  1      .AND.
     2    INTAR(1) .EQ.  N      .AND.
     3    RL       .EQ.  3*N    .AND.
     4    STR      .EQ.  0)            THEN
         OKSOFR = .TRUE.
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Array sizes are incorrect.')
      ENDIF

      IF (RAREQ (3*N, RLAR, RLCOMB, 0.0, 0.0)) THEN
C        ok
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Geometric point values are incorrect.')
      ENDIF

      CALL IFPF (OKSOFR)

C  <polyline 3> with n, xarr, yarr, zarr
      N = 1
      CALL PPL3 (N, XARR, YARR, ZARR)

C  <inquire current element type and size> to set celtyp, celsiz
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return polyline 3 as the type of the '     //
     2             'created element and the appropriate element '     //
     3             'size for a single point element.')

C    (celtyp = polyline 3 and
C     celsiz = values specified by the standard and language binding)

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   2   .AND.
     2           INTLEN   .EQ.   1   .AND.
     3           RLLEN    .EQ.   3   .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for a single ' //
     2             'point polyline 3.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      CALL IFPF (ERRIND   .EQ.   0         .AND.
     1           INTG     .EQ.   1         .AND.
     2           INTAR(1) .EQ.   N         .AND.
     3           RL       .EQ.   3*N       .AND.
     4           RLAR(1)  .EQ.   XARR(1)   .AND.
     5           RLAR(2)  .EQ.   YARR(1)   .AND.
     6           RLAR(3)  .EQ.   ZARR(1)   .AND.
     7           STR      .EQ.   0)

C  *** *** *** *** ***   Polyline   *** *** *** *** ***

C  <polyline> with n,xarr,yarr

      N = 5
      CALL PPL (N, XARR, YARR)

C  <inquire current element type and size> to set celtyp, celsiz

      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return polyline as the type of the '       //
     2             'created element and the appropriate element '     //
     3             'size for a multipoint element.')

C    (celtyp = polyline and
C     celsiz = values specified by the standard and language binding)
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   3   .AND.
     2           INTLEN   .EQ.   1   .AND.
     3           RLLEN    .EQ.   2*N .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('4 6', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'multipoint polyline.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.   0   .AND.
     1    INTG     .EQ.   1   .AND.
     2    INTAR(1) .EQ.   N   .AND.
     3    RL       .EQ.   2*N .AND.
     4    STR      .EQ.   0)    THEN
         OKSOFR = .TRUE.
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Array sizes are incorrect.')
      ENDIF

      IF (RAREQ (2*N, RLAR, RLCOMB, 0.0, 0.0)) THEN
C        ok
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Geometric point values are incorrect.')
      ENDIF

      CALL IFPF (OKSOFR)

C  <polyline> with n,xarr,yarr
      N = 1
      CALL PPL (N, XARR, YARR)

C  <inquire current element type and size> to set celtyp, celsiz

      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return polyline as the type of the '       //
     2             'created element and the appropriate element '     //
     3             'size for a single point element.')

C    (celtyp = polyline and
C     celsiz = values specified by the standard and language binding)

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   3   .AND.
     2           INTLEN   .EQ.   1   .AND.
     3           RLLEN    .EQ.   2   .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('4 6', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'single point polyline.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      CALL IFPF (ERRIND   .EQ.   0         .AND.
     1           INTG     .EQ.   1         .AND.
     2           INTAR(1) .EQ.   N         .AND.
     3           RL       .EQ.   2*N       .AND.
     4           RLAR(1)  .EQ.   XARR(1)   .AND.
     5           RLAR(2)  .EQ.   YARR(1)   .AND.
     7           STR      .EQ.   0)

777   CONTINUE

      CALL ENDIT
      END
