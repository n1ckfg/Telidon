C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.02/02                           *
C  *    TEST TITLE : Application data                      *
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
 
      INTEGER CELTYP, I, INLEN, INTLEN, INTG, LDR, LDRACT, RELEN,
     1        RL, RLLEN, STR, STRLEN, STLEN, STRID
      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, STRID = 1)
      PARAMETER (LDR = 20)
 
      INTEGER INTAR(INLEN), STRARL(STLEN)
      INTEGER DRININ(INLEN), DRINSL(STLEN), DROTIN(INLEN), DROTSL(STLEN)
      INTEGER ITRIM
 
      REAL RLAR(RELEN)
      REAL DRINRL(RELEN), DROTRL(RELEN)
 
      CHARACTER DRINDR(LDR)*80, DROTDR(LDR)*80
      CHARACTER DRINST(STLEN)*80, DROTST(STLEN)*80
 
      CALL INITGL ('02.02.02/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  *** *** *** *** ***   Application data   *** *** *** *** ***
 
      CALL POPST (STRID)
 
C dr = data record to hold
C integers:  174,  175,   176
C reals:     17.4, 17.5, 17.6
C strings:   "This is a application data test string.", "This is another."
 
      DRININ(1) = 174
      DRININ(2) = 175
      DRININ(3) = 176
 
      DRINRL(1) = 17.4
      DRINRL(2) = 17.5
      DRINRL(3) = 17.6
 
      DRINST(1) = 'This is a application data test string.'
      DRINST(2) = 'This is another.'
 
      DRINSL(1) = ITRIM(DRINST(1))
      DRINSL(2) = ITRIM(DRINST(2))
 
C set dr
      CALL PPREC (3, DRININ, 3, DRINRL, 2, DRINSL, DRINST, LDR,
     1            ERRIND, LDRACT, DRINDR)
      CALL CHKINQ ('pprec', ERRIND)
 
C <application data> with dr
      CALL PAP (LDRACT, DRINDR)
 
      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return application data as the type of '   //
     2             'the created element and the appropriate element ' //
     3             'size.')
 
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF (ERRIND   .EQ.   0       .AND.
     1           CELTYP   .EQ.  68       .AND.
     2           INTLEN   .EQ.   0       .AND.
     3           RLLEN    .EQ.   0       .AND.
     4           STRLEN   .EQ.   LDRACT)
 
      CALL SETMSG ('4 6', '<Inquire current element content> should ' //
     1             'return the standard representation for '          //
     2             'application data.')
 
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, DROTDR)
 
      IF (ERRIND   .EQ.   0   .AND.
     1    INTG     .EQ.   0   .AND.
     2    RL       .EQ.   0   .AND.
     3    STR      .EQ.   LDRACT)   THEN
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
         CALL INMSG ('Array sizes from PUREC are incorrect.')
         GOTO 777
      ENDIF
 
      IF (DRININ(1)   .EQ.   DROTIN(1)   .AND.
     1    DRININ(2)   .EQ.   DROTIN(2)   .AND.
     2    DRININ(3)   .EQ.   DROTIN(3))        THEN
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
         CALL INMSG ('Real array from PUREC is incorrect.')
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
         CALL INMSG ('String array from PUREC is incorrect.')
         GOTO 777
      ENDIF
 
      CALL PASS
 
777   CONTINUE
      CALL ENDIT
      END
