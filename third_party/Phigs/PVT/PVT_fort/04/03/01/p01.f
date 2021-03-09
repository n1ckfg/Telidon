C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.01/01                           *
C  *    TEST TITLE : Set individual ASF element            *
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

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

      INTEGER    PEDT,     PEWSC,    PEDCI
      PARAMETER (PEDT=15,  PEWSC=16, PEDCI=17)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

      INTEGER ATRID, ASFVAL, CELTYP, INTLEN, INTG, RLLEN, RL
      INTEGER STRLEN, STR, INLEN, STLEN, RELEN, STRID

      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, STRID = 1)

      INTEGER INTAR(INLEN), STRARL(STLEN)

      LOGICAL BADTYP, BADCON

      REAL RLAR(RELEN)

      CHARACTER MSG*80, STRAR(STLEN)

      CALL INITGL ('04.03.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

100   FORMAT ('Failure occurred with attribute-id = ', I3,
     1        ', and asfval = ', I3)

C  *** *** ***   Set individual ASF for each ASF value   *** *** ***

      BADTYP = .FALSE.
      BADCON = .FALSE.

C <set individual ASF> with atrid, asfval and
C <inquire current element type and size>

      CALL POPST (STRID)
      DO 10 ATRID = PLN, PEDCI
         DO 5 ASFVAL = PBUNDL, PINDIV
            CALL PSIASF (ATRID, ASFVAL)
            CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
            IF (ERRIND   .EQ.   0   .AND.
     1          CELTYP   .EQ.  55   .AND.
     2          INTLEN   .EQ.   2   .AND.
     3          RLLEN    .EQ.   0   .AND.
     4          STRLEN   .EQ.   0)        THEN
C OK so far, do nothing
            ELSE
                BADTYP = .TRUE.
                GOTO 15
            ENDIF
5        CONTINUE
10    CONTINUE
15    CONTINUE

      CALL SETMSG ('1 2 4 5', '<Inquire current element type and '    //
     1             'size> should return set individual ASF as the '   //
     2             'type of the created element and the appropriate ' //
     3             'element size.')

      IF (BADTYP) THEN
         CALL FAIL
         WRITE (MSG, 100) ATRID, ASFVAL
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

C <set individual ASF> with atrid, asfval>
C <inquire current element content>

      DO 25 ATRID = PLN, PEDCI
         DO 20 ASFVAL = PBUNDL, PINDIV
            CALL PSIASF (ATRID, ASFVAL)
            CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                   RL, RLAR, STR, STRARL, STRAR)
            IF (ERRIND   .EQ.  0      .AND.
     1          INTG     .EQ.  2      .AND.
     2          INTAR(1) .EQ.  ATRID  .AND.
     3          INTAR(2) .EQ.  ASFVAL .AND.
     4          RL       .EQ.  0      .AND.
     5          STR      .EQ.  0)  THEN
C OK so far, do nothing
            ELSE
                BADCON = .TRUE.
                GOTO 30
            ENDIF
20       CONTINUE
25    CONTINUE
30    CONTINUE

      CALL SETMSG ('1 3 4 5', '<Inquire current element content> '  //
     1             'should return the standard representation for ' //
     2             'set individual ASF.')

      IF (BADCON) THEN
          CALL FAIL
          WRITE (MSG, 100) ATRID, ASFVAL
      ELSE
          CALL PASS
      ENDIF

777   CONTINUE
      CALL ENDIT
      END
