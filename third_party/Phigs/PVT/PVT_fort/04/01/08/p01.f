C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.08/01                           *
C  *    TEST TITLE : Generalized drawing primitive         *
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

      INTEGER    PEGDP3,      PEGDP,       PEPLI,       PEPMI
      PARAMETER (PEGDP3 = 16, PEGDP  = 17, PEPLI  = 18, PEPMI  = 19)

C GDP attributes
      INTEGER    PPLATT,   PPMATT,   PTXATT,   PINATT,   PEDATT
      PARAMETER (PPLATT=0, PPMATT=1, PTXATT=2, PINATT=3, PEDATT=4)
C GDP attributes for PHIGS-PLUS
      INTEGER    PRFATT,   PPSATT
      PARAMETER (PRFATT=5, PPSATT=5)

      INTEGER CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR, INLEN,
     1        STLEN, RELEN, STRID, LDR, LDRACT

      PARAMETER (INLEN = 50, STLEN = 10, RELEN = 50, STRID = 1)
      PARAMETER (LDR = 20)

      INTEGER INTAR(INLEN), STRL2(STLEN)
      INTEGER DRININ(INLEN), DRINSL(STLEN), DROTIN(INLEN), DROTSL(STLEN)
      INTEGER ITRIM, NUMGDP, IDUM, GDPEL(300), NBND, BNDL(5), MAXGDP
      INTEGER I,J, ID, NUMPTS, THISET, UGDPID

      REAL    XARR(5), YARR(5), ZARR(5)
      REAL    RLAR(RELEN), RLCOMB(15)
      REAL    DRINRL(RELEN), DROTRL(RELEN)

      LOGICAL    RAREQ

      CHARACTER  DRINDR(LDR)*80, DROTDR(LDR)*80
      CHARACTER  DRINST(STLEN)*30, DROTST(STLEN)*30, MSG*300

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      DATA XARR /0.0, -99.99, .00013, 3.2E-12, -3.4E23/
      DATA YARR /4.2, 0.0, 99.99, 0.0, .002/
      DATA ZARR /34.2, 1.4, .032E2, 99E2, 0.0/

      CALL INITGL ('04.01.08/01')

      NUMPTS = 5

C set up comparison values
      DO 10 I = 1, NUMPTS
         RLCOMB(I)    = XARR(I)
         RLCOMB(I+5)  = YARR(I)
         RLCOMB(I+10) = ZARR(I)
10    CONTINUE

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
C get this workstation type
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  dr = data record to hold
C  integers: 174, 175, 176
C  reals:    17.4,17.5,17.6
C  strings:  "This is a GDP test string.", "This is another."

      DRININ(1) = 174
      DRININ(2) = 175
      DRININ(3) = 176

      DRINRL(1) = 17.4
      DRINRL(2) = 17.5
      DRINRL(3) = 17.6

      DRINST(1) = 'This is a GDP test string.'
      DRINST(2) = 'This is another.'

      DRINSL(1) = ITRIM(DRINST(1))
      DRINSL(2) = ITRIM(DRINST(2))

C pack data record
      CALL PPREC (3,DRININ, 3,DRINRL, 2,DRINSL,DRINST, LDR,
     1            ERRIND, LDRACT, DRINDR)
      CALL CHKINQ ('pprec', ERRIND)

C  *** *** *** *** ***   Generalized drawing primitive 3   *** *** *** *** ***

      CALL SETMSG ('4', '<Inquire list of available generalized '     //
     1             'drawing primitives 3> should be able to return '  //
     2             'the list of GDP 3 identifiers.')

C get list size
      NUMGDP = 666
      CALL PQEGD3 (SPECWT, 0, ERRIND, NUMGDP, IDUM)
      CALL CHKINQ ('pqegd3', ERRIND)
      MAXGDP = -999999

      DO 100 I = 1,NUMGDP
         ID = -666
         CALL PQEGD3 (SPECWT, I, ERRIND, IDUM, ID)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 110
         ENDIF
C save GDP id's
         GDPEL(I) = ID
         MAXGDP = MAX (MAXGDP, ID)
100   CONTINUE
      CALL PASS

110   CONTINUE

      CALL SETMSG ('5', '<Inquire generalized drawing primitive 3> '  //
     1             'should be able to return the list of sets of '    //
     2             'attributes used by a given GDP 3 identifier.')

      DO 200 I = 1,NUMGDP
         NBND = -6
         BNDL(1) = -6
         CALL PQGDP3 (SPECWT, GDPEL(I), ERRIND, NBND, BNDL)
         IF ( ERRIND .NE. 0 .OR.
     1        NBND   .LT. 0 .OR.
     2        NBND   .GT. 7)   THEN
            GOTO 210
         ENDIF
C check bndl validity
         DO 2010 J = 1,NBND
            THISET = BNDL(J)
            IF (THISET .LT. PPLATT .OR. THISET .GT. PPSATT) GOTO 210
2010     CONTINUE
200   CONTINUE
      CALL PASS
      GOTO 220

210   CONTINUE
      CALL FAIL
      WRITE (MSG, '(A,I4,A)') 'Failure at GDP id = ', I, '.'
      CALL INMSG (MSG)

220   CONTINUE

C  select ugdpid = not in gdplist (unsupported)
      UGDPID = MAXGDP+1

      CALL POPST (STRID)
      CALL PGDP3 (NUMPTS, XARR, YARR, ZARR, UGDPID, LDRACT, DRINDR)

      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return generalized drawing primitive 3 '   //
     2             'as the type of the created element and the '      //
     3             'appropriate element size.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0        .AND.
     1           CELTYP   .EQ.  PEGDP3    .AND.
     2           INTLEN   .EQ.   2        .AND.
     3           RLLEN    .EQ.  3*NUMPTS  .AND.
     4           STRLEN   .EQ.  LDRACT)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'generalized drawing primitive 3.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRL2, DROTDR)

      IF (ERRIND   .EQ.   0       .AND.
     1    INTG     .EQ.   2       .AND.
     2    INTAR(1) .EQ.   NUMPTS  .AND.
     3    INTAR(2) .EQ.   UGDPID  .AND.
     4    RL       .EQ.  3*NUMPTS .AND.
     5    STR      .EQ.  LDRACT)     THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes from PQCECO are incorrect.')
         GOTO 625
      ENDIF

      IF (.NOT. RAREQ (3*NUMPTS, RLAR, RLCOMB, 0.0, 0.0)) THEN
         CALL FAIL
         CALL INMSG ('Geometric point values are incorrect.')
         GOTO 625
      ENDIF

      DO 20 J = 1,LDRACT
         IF (STRL2(J) .NE. 80) THEN
            CALL FAIL
            CALL INMSG ('Reported length of data record from ' //
     1                  'PQCECO is incorrect.')
            GOTO 625
         ENDIF
20    CONTINUE

C  unpack DR and compare all 4 arrays

      CALL PUREC (LDRACT, DROTDR, INLEN, RELEN, STLEN,
     1            ERRIND, INTG, DROTIN, RL, DROTRL, STR, DROTSL, DROTST)

      IF (ERRIND  .EQ. 0    .AND.
     1    INTG    .EQ. 3    .AND.
     2    RL      .EQ. 3    .AND.
     3    STR     .EQ. 2)     THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes from PUREC are incorrect.')
         GOTO 625
      ENDIF

      IF (DRININ(1) .EQ. DROTIN(1) .AND.
     1    DRININ(2) .EQ. DROTIN(2) .AND.
     2    DRININ(3) .EQ. DROTIN(3))  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Integer array from PUREC is incorrect.')
         GOTO 625
      ENDIF

      IF (DRINRL(1) .EQ. DROTRL(1) .AND.
     1    DRINRL(2) .EQ. DROTRL(2) .AND.
     2    DRINRL(3) .EQ. DROTRL(3))   THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Real array from PUREC is incorrect.')
         GOTO 625
      ENDIF

      IF (DRINSL(1) .EQ. DROTSL(1) .AND.
     1    DRINSL(2) .EQ. DROTSL(2))  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('String-length array from PUREC is incorrect.')
         GOTO 625
      ENDIF

      IF (DRINST(1) .EQ. DROTST(1) .AND.
     1    DRINST(2) .EQ. DROTST(2))  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('String array from PUREC is incorrect.')
         GOTO 625
      ENDIF

      CALL PASS

625   CONTINUE

C  *** *** *** *** ***   Generalized drawing primitive   *** *** *** *** ***

      CALL SETMSG ('9', '<Inquire list of available generalized '     //
     1             'drawing primitives> should be able to return '    //
     2             'the list of GDP identifiers.')

C get list size
      NUMGDP = 666
      CALL PQEGDP (SPECWT, 0, ERRIND, NUMGDP, IDUM)
      CALL CHKINQ ('pqegdp', ERRIND)
      MAXGDP = -999999

      DO 2100 I = 1,NUMGDP
         ID = -666
         CALL PQEGDP (SPECWT, I, ERRIND, IDUM, ID)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 2110
         ENDIF
C save GDP id's
         GDPEL(I) = ID
         MAXGDP = MAX (MAXGDP, ID)
2100  CONTINUE
      CALL PASS

2110  CONTINUE

      CALL SETMSG ('10', '<Inquire generalized drawing primitive> '   //
     1             'should be able to return the list of sets of '    //
     2             'attributes used by a given GDP identifier.')

      DO 2200 I = 1,NUMGDP
         NBND = -6
         BNDL(1) = -6
         CALL PQGDP (SPECWT, GDPEL(I), ERRIND, NBND, BNDL)
         IF ( ERRIND .NE. 0 .OR.
     1        NBND   .LT. 0 .OR.
     2        NBND   .GT. 7)   THEN
            GOTO 2210
         ENDIF
C check bndl validity
         DO 22010 J = 1,NBND
            THISET = BNDL(J)
            IF (THISET .LT. PPLATT .OR. THISET .GT. PPSATT) GOTO 2210
22010    CONTINUE
2200  CONTINUE
      CALL PASS
      GOTO 2220

2210  CONTINUE
      CALL FAIL
      WRITE (MSG, '(A,I4,A)') 'Failure at GDP id = ', I, '.'
      CALL INMSG (MSG)

2220  CONTINUE

C  select ugdpid = not in gdplist (unsupported)
      UGDPID = MAXGDP+1
      CALL PGDP (NUMPTS, XARR, YARR, UGDPID, LDRACT, DRINDR)

      CALL SETMSG ('6 7', '<Inquire current element type and size> '  //
     1             'should return generalized drawing primitive as '  //
     2             'the type of the created element and the '         //
     3             'appropriate element size.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0       .AND.
     1           CELTYP   .EQ.  PEGDP    .AND.
     2           INTLEN   .EQ.   2       .AND.
     3           RLLEN    .EQ.  2*NUMPTS .AND.
     4           STRLEN   .EQ.  LDRACT)

      CALL SETMSG ('6 8', '<Inquire current element content> should ' //
     1             'return the standard representation for a '        //
     2             'generalized drawing primitive.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRL2, DROTDR)

      IF (ERRIND   .EQ. 0        .AND.
     1    INTG     .EQ. 2        .AND.
     2    INTAR(1) .EQ. NUMPTS   .AND.
     3    INTAR(2) .EQ. UGDPID   .AND.
     4    RL       .EQ. 2*NUMPTS .AND.
     5    STR      .EQ. LDRACT)   THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes from PQCECO are incorrect.')
         GOTO 777
      ENDIF

      IF (.NOT. RAREQ (2*NUMPTS, RLAR, RLCOMB, 0.0, 0.0)) THEN
         CALL FAIL
         CALL INMSG ('Geometric point values are incorrect.')
         GOTO 777
      ENDIF

      DO 120 J = 1,LDRACT
         IF (STRL2(J) .NE. 80) THEN
            CALL FAIL
            CALL INMSG ('Reported length of data record from ' //
     1                  'PQCECO is incorrect.')
            GOTO 777
         ENDIF
120   CONTINUE

C  unpack DR and compare all 4 arrays

      CALL PUREC (LDRACT, DROTDR, INLEN, RELEN, STLEN,
     1            ERRIND, INTG, DROTIN, RL, DROTRL, STR, DROTSL, DROTST)

      IF (ERRIND  .EQ. 0    .AND.
     1    INTG    .EQ. 3    .AND.
     2    RL      .EQ. 3    .AND.
     3    STR     .EQ. 2)     THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes from PUREC are incorrect.')
         GOTO 777
      ENDIF

      IF (DRININ(1) .EQ. DROTIN(1) .AND.
     1    DRININ(2) .EQ. DROTIN(2) .AND.
     2    DRININ(3) .EQ. DROTIN(3))  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Integer array from PUREC is incorrect.')
         GOTO 777
      ENDIF

      IF (DRINRL(1) .EQ. DROTRL(1) .AND.
     1    DRINRL(2) .EQ. DROTRL(2) .AND.
     2    DRINRL(3) .EQ. DROTRL(3))   THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Real array from PUREC is incorrect.')
         GOTO 777
      ENDIF

      IF (DRINSL(1) .EQ. DROTSL(1) .AND.
     1    DRINSL(2) .EQ. DROTSL(2))  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('String-length array from PUREC is incorrect.')
         GOTO 777
      ENDIF

      IF (DRINST(1) .EQ. DROTST(1) .AND.
     1    DRINST(2) .EQ. DROTST(2))  THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('String array from PUREC is incorrect.')
         GOTO 777
      ENDIF

      CALL PASS

777   CONTINUE
      CALL ENDIT
      END
