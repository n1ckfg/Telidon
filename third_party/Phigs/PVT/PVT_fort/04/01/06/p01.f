C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.06/01                           *
C  *    TEST TITLE : Fill area set element                 *
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

      INTEGER   CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR,
     1          INLEN, STLEN, RELEN, I, N, STRID, ENDPTS(10),
     2          IX, DEGEN

      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, STRID = 1)

      INTEGER   INTAR(INLEN), STRARL(STLEN)

      LOGICAL   OKSOFR, IAREQ, RAREQ, VALETS, VALEC

      REAL      XARR(6), YARR(6), ZARR(6), RLAR(RELEN), RLCOMB(18)

      CHARACTER STRAR(STLEN)

      DATA XARR / 2.33, 55.55, -4.4, 123.0,     0.0,     2.3 /
      DATA YARR / 0.0,   3.2, -99.99,  3.2E22, -2.2E-22, 4.5 /
      DATA ZARR / 4.44,  0.0,   0.0,   5.5,    22.22,    6.7 /

      CALL INITGL ('04.01.06/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPST (STRID)

      DO 10 I = 1, 6
         RLCOMB(I)    = XARR(I)
         RLCOMB(I+6)  = YARR(I)
         RLCOMB(I+12) = ZARR(I)
10    CONTINUE

C  *** *** *** *** ***   Fill area set 3   *** *** *** *** ***
C  fill area set with 2 subareas

C  set up expected values
      N = 2
      ENDPTS(1) = 3
      ENDPTS(2) = 6

      CALL PFAS3 (N, ENDPTS, XARR, YARR, ZARR)

      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return fill area set 3 as the type of the '//
     2             'created element and the appropriate element size.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.  12   .AND.
     2           INTLEN   .EQ.   N   .AND.
     3           RLLEN    .EQ.  18   .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for a fill '   //
     2             'area set 3.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1            RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.  0  .AND.
     1    INTG     .EQ.  N  .AND.
     5    RL       .EQ. 18  .AND.
     6    STR      .EQ.  0)     THEN
         OKSOFR = .TRUE.
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Array sizes are incorrect.')
      ENDIF

      IF (IAREQ (2, INTAR, ENDPTS)) THEN
C        ok so far
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Endpoints are incorrect.')
      ENDIF

      IF (RAREQ (18, RLAR, RLCOMB, 0.0, 0.0)) THEN
C        ok
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Geometric point values are incorrect.')
      ENDIF

      CALL IFPF (OKSOFR)

      VALETS = .TRUE.
      VALEC  = .TRUE.
      DO 100 IX = 0, 2
         IF (IX .EQ. 0) THEN
            ENDPTS(1) = 2
            ENDPTS(2) = 3
            ENDPTS(3) = 3
            DEGEN = 3
            CALL PFAS3 (3, ENDPTS, XARR, YARR, ZARR)
         ELSE
            ENDPTS(1) = IX
            ENDPTS(2) = IX * 2
            ENDPTS(3) = IX * 3
            DEGEN = IX * 3
            CALL PFAS3 (3, ENDPTS, XARR, YARR, ZARR)
         ENDIF

         CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
         IF (ERRIND    .EQ.    0      .AND.
     1       CELTYP    .EQ.   12      .AND.
     2       INTLEN    .EQ.    3      .AND.
     3       RLLEN     .EQ.  DEGEN*3  .AND.
     4       STRLEN    .EQ.    0 ) THEN
C           Ok as far
         ELSE
             VALETS = .FALSE.
         ENDIF

         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND    .EQ.    0          .AND.
     1       INTG      .EQ.    3          .AND.
     2       RL        .EQ.   DEGEN*3     .AND.
     3       STR       .EQ.    0          .AND.
     4       IAREQ(3,     INTAR, ENDPTS)  .AND.
     5       RAREQ(DEGEN, RLAR(0*DEGEN+1), XARR,   0.0,  0.0)   .AND.
     6       RAREQ(DEGEN, RLAR(1*DEGEN+1), YARR,   0.0,  0.0)   .AND.
     7       RAREQ(DEGEN, RLAR(2*DEGEN+1), ZARR,   0.0,  0.0))   THEN
C         Ok, so far
         ELSE
            VALEC = .FALSE.
         ENDIF
100   CONTINUE

      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return fill area set 3 as the type of the '//
     2             'created element and the appropriate element size '//
     3             'for an element with subareas with 0, 1, and/or 2 '//
     4             'points.')

      CALL IFPF (VALETS)

      CALL SETMSG ('1 3','<Inquire current element content> should ' //
     1             'return the standard representation for a <fill ' //
     2             'area set 3> whose subareas have 0, 1, and/or 2 ' //
     3             'points.')

      CALL IFPF (VALEC)

C  *** *** *** *** ***   Fill area set   *** *** *** *** ***
C  fill area set with two subareas

C  set up expected values
      N = 2
      ENDPTS(1) = 3
      ENDPTS(2) = 6
      CALL PFAS (N, ENDPTS, XARR, YARR)

      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return fill area set as the type of the '  //
     2             'created element and the appropriate element size '//
     3             'for a multipoint element.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.  13   .AND.
     2           INTLEN   .EQ.   N   .AND.
     3           RLLEN    .EQ.  12   .AND.
     4           STRLEN   .EQ.   0)

      CALL SETMSG ('4 6', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'multipoint fill area set.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      IF (ERRIND   .EQ.  0  .AND.
     1    INTG     .EQ.  N  .AND.
     5    RL       .EQ. 12  .AND.
     6    STR      .EQ.  0)     THEN
          OKSOFR = .TRUE.
      ELSE
          OKSOFR = .FALSE.
          CALL INMSG ('Array sizes are incorrect.')
      ENDIF

      IF (IAREQ (2, INTAR, ENDPTS)) THEN
C        ok so far
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Endpoints are incorrect.')
      ENDIF

      IF (RAREQ (12, RLAR, RLCOMB, 0.0, 0.0)) THEN
C        ok
      ELSE
         OKSOFR = .FALSE.
         CALL INMSG ('Geometric point values are incorrect.')
      ENDIF

      CALL IFPF (OKSOFR)

      VALETS = .TRUE.
      VALEC  = .TRUE.

      DO 200 IX = 0, 2
         IF (IX .EQ. 0) THEN
            ENDPTS(1) = 2
            ENDPTS(2) = 3
            ENDPTS(3) = 3
            DEGEN = 3
            CALL PFAS (3, ENDPTS, XARR, YARR)
         ELSE
            ENDPTS(1) = IX
            ENDPTS(2) = IX * 2
            ENDPTS(3) = IX * 3
            DEGEN = IX * 3
            CALL PFAS (3, ENDPTS, XARR, YARR)
         ENDIF

         CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
         IF (ERRIND     .EQ.     0      .AND.
     1       CELTYP     .EQ.    13      .AND.
     2       INTLEN     .EQ.     3      .AND.
     3       RLLEN      .EQ.  DEGEN*2   .AND.
     4       STRLEN     .EQ.     0) THEN
C         OK as far
         ELSE
            VALETS = .FALSE.
         ENDIF

         CALL PQCECO (INLEN, RLLEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND    .EQ.    0          .AND.
     1       INTG      .EQ.    3          .AND.
     2       RL        .EQ.   DEGEN*2     .AND.
     3       STR       .EQ.    0          .AND.
     4       IAREQ(3,     INTAR, ENDPTS)  .AND.
     5       RAREQ(DEGEN, RLAR(1),         XARR,   0.0,  0.0)   .AND.
     6       RAREQ(DEGEN, RLAR(DEGEN+1),   YARR,   0.0,  0.0)) THEN
C         Ok, so far
         ELSE
            VALEC = .FALSE.
         ENDIF
200   CONTINUE

      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return fill area set as the type of the '  //
     2             'created element and the appropriate element size '//
     3             'for an element with subareas with 0, 1, and/or 2 '//
     4             'points.')
      CALL IFPF (VALETS)

      CALL SETMSG ('4 6','<Inquire current element content> should ' //
     1             'return the standard representation for a <fill ' //
     2             'area set> whose subareas have 0, 1, and/or 2 '   //
     3             'points.')
      CALL IFPF (VALEC)

777   CONTINUE
      CALL ENDIT
      END
