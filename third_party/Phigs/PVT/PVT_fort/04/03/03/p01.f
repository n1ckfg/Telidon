C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.03/01                           *
C  *    TEST TITLE : Set and inquire HLHSR identifier      *
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
      INTEGER NUMID, IDUM1
      INTEGER CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR, INLEN,
     1        STLEN, RELEN, LDR, HRID, STRID, UNAVID, I
      PARAMETER (INLEN=50, STLEN=10, RELEN=50, STRID=1, LDR=20)

      INTEGER INTAR(INLEN), STRL2(STLEN)

      REAL    RLAR(RELEN)

      CHARACTER  DROTDR (LDR)*80, MSG*300

C  parameters for <inquire workstation connection and type>
      INTEGER SPECWT, SPECON

      CALL INITGL ('04.03.03/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
C get this workstation type
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
C open structure
      CALL POPST (STRID)
C hrid = HLHSR identifier
      HRID = 0
      CALL PSHRID (HRID)

C      celtyp = current element type
C      celsiz = current element size
C      celcon = current element content

      CALL SETMSG ('1 2', '<Inquire current element type and size> '//
     1             'should return HLHSR identifier as the type of ' //
     2             'the created element and the appropriate '//
     3             'element size.')

C <inquire current element type and size> to determine celtyp, celsiz
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
      CALL IFPF (ERRIND    .EQ.    0    .AND.
     1           CELTYP    .EQ.   56    .AND.
     2           INTLEN    .EQ.    1    .AND.
     3           RLLEN     .EQ.    0    .AND.
     4           STRLEN    .EQ.    0)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for HLHSR '    //
     2             'identifier.')
C  <inquire current element content> to determine celcon
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRL2, DROTDR)
      CALL IFPF (ERRIND    .EQ.   0     .AND.
     1           INTG      .EQ.   1     .AND.
     2           INTAR(1)  .EQ.   HRID  .AND.
     3           RL        .EQ.   0     .AND.
     4           STR       .EQ.   0)

C find an unavailable HLHSR identifier
      UNAVID = 999
      CALL PQHRIF (SPECWT, 0, ERRIND, NUMID, IDUM1)
      CALL CHKINQ ('pqhrif', ERRIND)
90    CONTINUE
      DO 100 I = 1, NUMID
         CALL PQHRIF (SPECWT, I, ERRIND, IDUM1, HRID)
         CALL CHKINQ ('pqhrif', ERRIND)
         IF (HRID .EQ. UNAVID) THEN
            UNAVID = UNAVID * 3
            GOTO 90
         ENDIF
100   CONTINUE

      CALL SETMSG ('1 3', 'Any HLHSR identifier should be accepted ' //
     1             'as valid, even if not supported by some '        //
     2             'workstation types.')
      CALL ERRCTL (.TRUE.)
      CALL PSHRID (UNAVID)
      CALL ERRCTL (.FALSE.)
      IF (ERRSIG .NE. 0) THEN
         CALL FAIL
         WRITE (MSG, '(A, I5, A, I5)') 'HSHLR identifier set = ',
     1          UNAVID, ' signalled error = ', ERRSIG
         CALL INMSG (MSG)
         GOTO 666
      ENDIF
C  <inquire current element content> to determine celcon
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRL2, DROTDR)
      CALL IFPF (ERRIND    .EQ.   0      .AND.
     1           INTG      .EQ.   1      .AND.
     2           INTAR(1)  .EQ.   UNAVID .AND.
     3           RL        .EQ.   0      .AND.
     4           STR       .EQ.   0)

666   CONTINUE
      CALL ENDIT
      END
