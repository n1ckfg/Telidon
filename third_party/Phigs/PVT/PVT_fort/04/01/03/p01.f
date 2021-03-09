C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.03/01                           *
C  *    TEST TITLE : Text element                          *
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

      INTEGER CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR, INLEN,
     1        STLEN, RELEN, STRID

      PARAMETER (INLEN = 50, STLEN = 10, RELEN = 50, STRID = 1)

      INTEGER INTAR(INLEN), STRARL(STLEN)

      REAL XCORD, YCORD, ZCORD, XDV(2), YDV(2), ZDV(2), RLAR(RELEN)

      CHARACTER STRAR(STLEN)*50, CHASTR*17, ACSTR*200

      INTEGER   ACS, NACS, IXACS, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6

      CALL INITGL ('04.01.03/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  *** *** *** *** ***   Text 3   *** *** *** *** ***

      XCORD   = 2.33
      YCORD   = -4.4
      ZCORD   = 3.2E22
      CHASTR  = '*#Testing#* ..123'
      XDV(1)  = -99.99
      YDV(1)  = 0.0
      ZDV(1)  = 3.2E-13
      XDV(2)  = 7.30
      YDV(2)  = -9876.5
      ZDV(2)  = -99E-9

C  <text 3> with xcord, ycord, zcord, xdv, ydv, zdv, chastr

      CALL POPST (STRID)
      CALL PTX3 (XCORD, YCORD, ZCORD, XDV, YDV, ZDV, CHASTR)

C  <inquire current element type and size> to set celtyp, celsiz

      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return text 3 as the type of the '         //
     2             'created element and the appropriate element '     //
     3             'size.')

C    (celtyp = text 3 and
C     celsiz = values specified by the standard and language binding;
C              fortran binding values are intlen, rllen, and strlen)

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   6   .AND.
     2           INTLEN   .EQ.   0   .AND.
     3           RLLEN    .EQ.   9   .AND.
     4           STRLEN   .EQ.   1)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for text 3.')

C ensure garbage in strar prior to inquire
      STRAR(1) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      CALL IFPF (ERRIND    .EQ.   0       .AND.
     1           INTG      .EQ.   0       .AND.
     2           RL        .EQ.   9       .AND.
     3           RLAR(1)   .EQ.   XCORD   .AND.
     4           RLAR(2)   .EQ.   YCORD   .AND.
     5           RLAR(3)   .EQ.   ZCORD   .AND.
     6           RLAR(4)   .EQ.   XDV(1)  .AND.
     7           RLAR(5)   .EQ.   YDV(1)  .AND.
     8           RLAR(6)   .EQ.   ZDV(1)  .AND.
     9           RLAR(7)   .EQ.   XDV(2)  .AND.
     O           RLAR(8)   .EQ.   YDV(2)  .AND.
     1           RLAR(9)   .EQ.   ZDV(2)  .AND.
     2           STR       .EQ.   1       .AND.
     3           STRARL(1) .EQ.  17       .AND.
     4           STRAR(1)  .EQ.   CHASTR)

C  *** *** *** *** ***   Text   *** *** *** *** ***

C  <text> with xcord, ycord, chastr

      CALL PTX (XCORD, YCORD, CHASTR)

C  <inquire current element type and size> to set celtyp, celsiz

      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return text as the type of the '           //
     2             'created element and the appropriate element '     //
     3             'size.')

C    (celtyp = text and
C     celsiz = values specified by the standard and language binding;
C              fortran binding values are intlen, rllen, and strlen)

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   7   .AND.
     2           INTLEN   .EQ.   0   .AND.
     3           RLLEN    .EQ.   2   .AND.
     4           STRLEN   .EQ.   1)

      CALL SETMSG ('4 6', '<Inquire current element content> should ' //
     1             'return the standard representation for '          //
     2             'text.')

C ensure garbage in strar prior to inquire
      STRAR(1) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      CALL IFPF (ERRIND    .EQ.   0     .AND.
     1           INTG      .EQ.   0     .AND.
     3           RL        .EQ.   2     .AND.
     4           RLAR(1)   .EQ.   XCORD .AND.
     5           RLAR(2)   .EQ.   YCORD .AND.
     6           STR       .EQ.   1     .AND.
     7           STRARL(1) .EQ.  17     .AND.
     8           STRAR(1)  .EQ.   CHASTR)

C  *** *** *** *** ***   Character sets   *** *** *** *** ***

      CALL SETMSG ('7', '<Inquire phigs facilities> should be able ' //
     1             'to report the list of available character sets.')
      NACS = -6
      CALL PQPHF (0, ERRIND, IDUM1, IDUM2, IDUM3, NACS,
     1               IDUM4, IDUM5, IDUM6)
      IF (ERRIND .NE. 0 .OR. NACS .LT. 0) THEN
         CALL FAIL
         GOTO 777
      ENDIF

      ACSTR = ' '
      DO 710 IXACS = 1,NACS
         CALL PQPHF (IXACS, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1               ACS, IDUM5, IDUM6)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 777
         ENDIF
C collect character sets
         WRITE (ACSTR(IXACS*5-4:IXACS*5), '(I5)') ACS
710   CONTINUE
      CALL PASS
      CALL INMSG ('Character sets in list:' // ACSTR)

      CALL SETMSG ('7 8', 'The first entry in the list of '   //
     1             'available character sets should be zero.')
      IF (NACS .GE. 1) THEN
         CALL PQPHF (1, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1                  ACS, IDUM5, IDUM6)
         CALL CHKINQ ('pqphf', ERRIND)
         CALL IFPF (ACS .EQ. 0)
      ELSE
         CALL FAIL
      ENDIF

777   CONTINUE
C wrap it up
      CALL ENDIT
      END
