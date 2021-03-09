C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.04/01                           *
C  *    TEST TITLE : Annotation text relative element      *
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

      INTEGER CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR,
     1        INLEN, STLEN, RELEN, STRID
      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, STRID = 1)

      INTEGER INTAR(INLEN), STRARL(STLEN)

      REAL XREFPT, YREFPT, ZREFPT, XANNPT, YANNPT, ZANNPT, RLAR(RELEN)

      CHARACTER STRAR(STLEN)*50, CHASTR*17

      CALL INITGL ('04.01.04/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  *** *** *** *** ***  Annotation text  3 element  *** *** *** *** ***

      XREFPT = 2.33
      YREFPT = 0.0
      ZREFPT = 4E-4
      XANNPT = -4.4
      YANNPT = -99.99
      ZANNPT = 0.0001
      CHASTR = '*#Testing#* ..123'

      CALL POPST (STRID)
      CALL PATR3 (XREFPT, YREFPT, ZREFPT, XANNPT, YANNPT, ZANNPT,
     1            CHASTR)

      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return annotation text relative 3 as '     //
     2             'the type of the created element and the '         //
     3             'appropriate element size.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   8   .AND.
     2           INTLEN   .EQ.   0   .AND.
     3           RLLEN    .EQ.   6   .AND.
     4           STRLEN   .EQ.   1)

      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for '          //
     2             'annotation text relative 3.')

C ensure garbage in strar prior to inquire
      STRAR(1) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      CALL IFPF (ERRIND    .EQ.   0      .AND.
     1           INTG      .EQ.   0      .AND.
     3           RL        .EQ.   6      .AND.
     4           RLAR(1)   .EQ.   XREFPT .AND.
     5           RLAR(2)   .EQ.   YREFPT .AND.
     6           RLAR(3)   .EQ.   ZREFPT .AND.
     7           RLAR(4)   .EQ.   XANNPT .AND.
     8           RLAR(5)   .EQ.   YANNPT .AND.
     9           RLAR(6)   .EQ.   ZANNPT .AND.
     1           STR       .EQ.   1      .AND.
     2           STRARL(1) .EQ.   17     .AND.
     3           STRAR(1)  .EQ.   CHASTR)

C  *** *** *** *** ***   Annotation text element  *** *** *** *** ***

      CALL PATR (XREFPT, YREFPT, XANNPT, YANNPT, CHASTR)

      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return annotation text relative as the '   //
     2             'type of the created element and the '             //
     3             'appropriate element size.')

      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)

      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           CELTYP   .EQ.   9   .AND.
     2           INTLEN   .EQ.   0   .AND.
     3           RLLEN    .EQ.   4   .AND.
     4           STRLEN   .EQ.   1)

      CALL SETMSG ('4 6', '<Inquire current element content> should ' //
     1             'return the standard representation for '          //
     2             'annotation text relative.')

C ensure garbage in strar prior to inquire
      STRAR(1) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

      CALL IFPF (ERRIND    .EQ.   0      .AND.
     1           INTG      .EQ.   0      .AND.
     3           RL        .EQ.   4      .AND.
     4           RLAR(1)   .EQ.   XREFPT .AND.
     5           RLAR(2)   .EQ.   YREFPT .AND.
     6           RLAR(3)   .EQ.   XANNPT .AND.
     7           RLAR(4)   .EQ.   YANNPT .AND.
     8           STR       .EQ.   1      .AND.
     9           STRARL(1) .EQ.  17      .AND.
     1           STRAR(1)  .EQ.   CHASTR)

777   CONTINUE
C wrap it up
      CALL ENDIT
      END
