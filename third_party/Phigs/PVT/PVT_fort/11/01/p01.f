C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 11.01/01                              *
C  *    TEST TITLE : Packing and unpacking                 *
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
      INTEGER     LDR,    INLEN,    RELEN,    STLEN
      PARAMETER  (LDR=20, INLEN=50, RELEN=50, STLEN=10)

      INTEGER   RLACT, STRACT, INTACT, ITRIM, LDRACT
      INTEGER   DRININ(INLEN),    DROTIN(INLEN)
      REAL      DRINRL(RELEN),    DROTRL(RELEN)
      INTEGER   DRINSL(STLEN),    DROTSL(STLEN)
      CHARACTER DRINST(STLEN)*50, DROTST(STLEN)*50, DATREC(LDR)*80,
     1          MSG*300

      LOGICAL   IAREQ, RAREQ

      CALL INITGL ('11.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C data record to hold:
C   drinin = (77, 32, -64, 286)
C   drinrl = (9.9, -4.88, 1e12)
C   drinst = "This string is to test pack and unpack", "THis is another"

      DRININ(1) = 77
      DRININ(2) = 32
      DRININ(3) = -64
      DRININ(4) = 286
      DRINRL(1) = 9.9
      DRINRL(2) = -4.88
      DRINRL(3) = 1E12
      DRINST(1) = 'This string is to test pack and unpack'
      DRINST(2) = 'THis is another'
      DRINSL(1) = ITRIM(DRINST(1))
      DRINSL(2) = ITRIM(DRINST(2))

      CALL SETMSG ('1', '<Pack data record> should report ' //
     1             'successful packing of valid data.')
      CALL PPREC (4, DRININ, 3, DRINRL, 2, DRINSL, DRINST, LDR,
     1            ERRIND, LDRACT, DATREC)
      IF (ERRIND .EQ. 0) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I6)') 'Skipping remaining test because ' //
     1          'PPREC failed with error code = ', ERRIND
         CALL INMSG (MSG)
         GOTO 666
      ENDIF

      CALL SETMSG ('1 2', 'Unpacking a packed data record should '  //
     1             'return the original data.')

C  <unpack data record> to determine
C    drotin = array with integer entries
C    drotrl = array with real entries
C    drotsl = string length entries
C    drotst = character string entries
      DROTST(1) = '**************************************************'
      DROTST(2) = '**************************************************'

      CALL PUREC (LDRACT, DATREC, INLEN, RELEN, STLEN,
     1            ERRIND, INTACT, DROTIN, RLACT, DROTRL,
     2            STRACT, DROTSL, DROTST)

      IF (ERRIND .EQ. 0) THEN
C        OK so far
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I6)') 'PUREC failed with error code = ', ERRIND
         CALL INMSG (MSG)
         GOTO 666
      ENDIF

      IF (INTACT    .EQ. 4         .AND.
     1    RLACT     .EQ. 3         .AND.
     2    STRACT    .EQ. 2)  THEN
C        OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Array sizes from PUREC are incorrect.')
         GOTO 666
      ENDIF

      IF (IAREQ (4, DROTIN, DRININ)) THEN
C        OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Integer array from PUREC is incorrect.')
         GOTO 666
      ENDIF

      IF (RAREQ (3, DROTRL, DRINRL, 0.0, 0.0)) THEN
C        OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('Real array from PUREC is incorrect.')
         GOTO 666
      ENDIF

      IF (IAREQ(2, DROTSL, DRINSL)) THEN
C        OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('String-length array from PUREC is incorrect.')
         GOTO 666
      ENDIF

      IF (DRINST(1)  .EQ. DROTST(1)  .AND.
     1    DRINST(2)  .EQ. DROTST(2)) THEN
C        OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('String array from PUREC is incorrect.')
         GOTO 666
      ENDIF

      CALL PASS

666   CONTINUE
      CALL ENDIT
      END
