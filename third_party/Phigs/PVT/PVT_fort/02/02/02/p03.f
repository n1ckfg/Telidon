C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.02/03                           *
C  *    TEST TITLE : Generalized structure element         *
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

      INTEGER CELTYP, INLEN, INTLEN, INTG, JWK, LDR, LDRACT,
     1        RELEN, RL, RLLEN, STR, STRLEN, STLEN, STRID
      INTEGER I, J, K, M, IDUM, JDUM
      INTEGER AVGSE, GSEID, GSEL, MAXGSE, PLIM,
     1        WAVGSE, WKDEP, WORKNM, UGSEID

      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, STRID = 1)
      PARAMETER (LDR = 20)

C workstation dependency indicator
      INTEGER    PWKI,     PWKD
      PARAMETER (PWKI = 0, PWKD = 1)

      INTEGER INTAR(INLEN), STRARL(STLEN)
      INTEGER DRININ(INLEN), DRINSL(STLEN), DROTIN(INLEN), DROTSL(STLEN)
      INTEGER LGSEIM(50)
      INTEGER ITRIM

      LOGICAL MARK(100), GSEOK

      REAL RLAR(RELEN)
      REAL DRINRL(RELEN), DROTRL(RELEN)

      CHARACTER DRINDR(LDR)*80, DROTDR(LDR)*80
      CHARACTER DRINST(STLEN)*40, DROTST(STLEN)*40, GSEMSG*80

      DATA MARK / 100 * .FALSE. /

      CALL INITGL ('02.02.02/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

      CALL POPST (STRID)

C dr = data record to hold
C integers:  174,  175,  176
C reals:     17.4, 17.5, 17.6
C strings:   "This is a GSE test string.", "This is another."

      DRININ(1) = 174
      DRININ(2) = 175
      DRININ(3) = 176

      DRINRL(1) = 17.4
      DRINRL(2) = 17.5
      DRINRL(3) = 17.6

      DRINST(1) = 'This is a GSE test string.'
      DRINST(2) = 'This is another.'

      DRINSL(1) = ITRIM(DRINST(1))
      DRINSL(2) = ITRIM(DRINST(2))

C set dr
      CALL PPREC (3, DRININ, 3, DRINRL, 2, DRINSL, DRINST, LDR,
     1            ERRIND, LDRACT, DRINDR)
      CALL CHKINQ ('pprec', ERRIND)

      CALL SETMSG ('12', '<Inquire generalized structure element '  //
     1             'facilities> should return a valid list of GSE ' //
     2             'identifiers and workstation dependency '        //
     3             'indicators.')

C  <inquire generalized structure element facilities> to set
C    ugseid = an unsupported GSE identifier
C    lgseim = list of workstation-dependent GSE's for this
C             implementation.

      AVGSE = -6
      CALL PQGSEF (0, ERRIND, AVGSE, IDUM, JDUM)
      CALL CHKINQ ('pqgsef', ERRIND)
      MAXGSE = -99999
      PLIM = 0
      GSEOK = (AVGSE .GE. 0)
      DO 5 I = 1, AVGSE
         WKDEP = -6
         CALL PQGSEF (I, ERRIND, IDUM, GSEID, WKDEP)
         CALL CHKINQ ('pqgsef', ERRIND)
         MAXGSE = MAX (MAXGSE, GSEID)
         IF (WKDEP .EQ. PWKD) THEN
            PLIM = PLIM + 1
            LGSEIM (PLIM) = GSEID
         ELSEIF (WKDEP .EQ. PWKI) THEN
C           OK: do nothing
         ELSE
            GSEOK = .FALSE.
         ENDIF
5     CONTINUE
      UGSEID = MAXGSE + 1
      CALL IFPF (GSEOK)

C <generalized structure element> with gseid, ldr, dr
      CALL PGSE (UGSEID, LDRACT, DRINDR)

      CALL SETMSG ('7 8 9', '<Inquire current element type and '     //
     1             'size> should return generalized structure '      //
     2             'element as the type of the created element and ' //
     3             'the appropriate element size.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   69  .AND.
     2           INTLEN   .EQ.   1   .AND.
     3           RLLEN    .EQ.   0   .AND.
     4           STRLEN   .EQ.   LDRACT)

      CALL SETMSG ('7 8 10', '<Inquire current element content> '     //
     1             'should return the standard representation for '   //
     2             'generalized structure element.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, DROTDR)
      IF (ERRIND   .EQ.   0       .AND.
     1    INTG     .EQ.   1       .AND.
     2    INTAR(1) .EQ.   UGSEID  .AND.
     3    RL       .EQ.   0       .AND.
     4    STR      .EQ.   LDRACT)       THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes from PQCECO are incorrect.')
         GOTO 777
      ENDIF

      DO 10 I = 1, LDRACT
         IF (STRARL(I)   .NE.   80) THEN
            CALL FAIL
            CALL INMSG ('String length STRARL for PQCECO is incorrect.')
            GOTO 777
         ENDIF
10    CONTINUE

      DROTST(1) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'
      DROTST(2) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'

C unpack DR and compare all 4 arrays
      CALL PUREC (LDRACT, DROTDR, INLEN, RELEN, STLEN, ERRIND,
     1            INTG, DROTIN, RL, DROTRL, STR, DROTSL, DROTST)

      IF (ERRIND   .EQ.   0   .AND.
     1    INTG     .EQ.   3   .AND.
     2    RL       .EQ.   3   .AND.
     3    STR      .EQ.   2)        THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes from PQCECO are incorrect.')
         GOTO 777
      ENDIF

      IF (DRININ(1)   .EQ.    DROTIN(1)   .AND.
     1    DRININ(2)   .EQ.    DROTIN(2)   .AND.
     2    DRININ(3)   .EQ.    DROTIN(3))        THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Integer array from PUREC is incorrect.')
         GOTO 777
      ENDIF

      IF (DRINRL(1)   .EQ.   DROTRL(1)   .AND.
     1    DRINRL(2)   .EQ.   DROTRL(2)   .AND.
     2    DRINRL(3)   .EQ.   DROTRL(3))        THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Real array from PUREC is incorrect')
         GOTO 777
      ENDIF

      IF (DRINSL(1)   .EQ.   DROTSL(1)   .AND.
     1    DRINSL(2)   .EQ.   DROTSL(2))        THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('String-length array from PUREC is incorrect.')
         GOTO 777
      ENDIF

      IF (DRINST(1)   .EQ.   DROTST(1)   .AND.
     1    DRINST(2)   .EQ.   DROTST(2))        THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('String array from PUREC is incorrect')
         GOTO 777
      ENDIF

      CALL PASS

777   CONTINUE
      GSEMSG = 'No error yet'

C get list of workstation types
      CALL PQEWK (0, ERRIND, WORKNM, IDUM)
      CALL CHKINQ ('pqewk', ERRIND)

      DO 25 J = 1, WORKNM
         CALL PQEWK (J, ERRIND, IDUM, JWK)
         CALL CHKINQ ('pqewk', ERRIND)
         WAVGSE = 666
         CALL PQEGSE (JWK, 0, ERRIND, WAVGSE, IDUM)
         IF (ERRIND .EQ. 51) GOTO 888
C info unavailable for metafile-out type workstation
         IF (ERRIND .EQ. 62) GOTO 888
         CALL CHKINQ ('pqegse', ERRIND)
         DO 20 K = 1, WAVGSE
            GSEL = -67
            CALL PQEGSE (JWK, K, ERRIND, IDUM, GSEL)
            IF (ERRIND .EQ. 51) GOTO 888
            CALL CHKINQ ('pqegse', ERRIND)
            DO 15 M = 1, PLIM
               IF (GSEL  .EQ. LGSEIM(M)) THEN
                  MARK(M) = .TRUE.
                  GOTO 20
               ENDIF
15          CONTINUE
            GSEMSG = 'Unmatched workstation GSE.'
            GOTO 880
20       CONTINUE
25    CONTINUE

C all elements should be marked
      DO 35 I = 1, PLIM
         IF (MARK(I)) THEN
C OK so far
         ELSE
            GSEMSG = 'Unmatched PHIGS GSE.'
            GOTO 880
         ENDIF
35    CONTINUE

C test can be performed
880   CONTINUE
      CALL SETMSG ('11 12 13', 'The set of workstation dependent '    //
     1             'GSEs within the PHIGS GSE list as reported '      //
     2             'by <inquire generalized structure element '       //
     3             'facilities> should be the union of the '          //
     4             'workstation GSE lists as reported by <inquire '   //
     5             'list of available generalized structure '         //
     6             'elements>.')
      IF (GSEMSG .EQ. 'No error yet') THEN
         CALL PASS
      ELSE
         CALL FAIL
         CALL INMSG (GSEMSG)
      ENDIF

C skip test
888   CONTINUE
      CALL ENDIT
      END
