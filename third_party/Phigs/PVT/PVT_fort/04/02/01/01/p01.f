C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.01/01                        *
C  *    TEST TITLE : Element creation and inquiring        *
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

      INTEGER    INLEN, RELEN, STLEN
      PARAMETER  (INLEN=50, RELEN=50, STLEN=50)

C PHIGS parameter types
      INTEGER    ELTYPE, INTLEN, INTG, RLLEN, RL, STRLEN, STR, STRID
      INTEGER    INTAR (INLEN), STRARL (STLEN), LTVAL
      REAL       RLAR (RELEN), LWSCF
      CHARACTER  STRAR (STLEN)

      CALL INITGL ('04.02.01.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C structure identifier = 1
      STRID = 1
C open structure
      CALL POPST (STRID)

C *** *** *** *** ***    Linetype    *** *** *** *** ***
C set value for attribute
      LTVAL = 33
      CALL PSLN (LTVAL)

      CALL SETMSG ('1 4', '<Inquire current element type ' //
     1             'and size> should return linetype as '  //
     2             'the type of the created element and ' //
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 23 is the PHIGS enumeration type for peln
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 23    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 4', '<Inquire current element content> '      //
     1             'should return the standard representation for ' //
     2             'the linetype value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peln
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           INTAR(1)    .EQ. LTVAL .AND.
     2           INTG        .EQ. 1     .AND.
     3           RL          .EQ. 0     .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***   Linewidth scale factor   *** *** *** *** ***
C set value for attribute
      LWSCF = 0.45
      CALL PSLWSC (LWSCF)

      CALL SETMSG ('1 13', '<Inquire current element type '   //
     1             'and size> should return linewidth scale ' //
     2             'factor as the type of the created '       //
     3             'element and the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 24 is the PHIGS enumeration type for pelwsc
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 24    .AND.
     2           INTLEN  .EQ. 0     .AND.
     3           RLLEN   .EQ. 1     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 13', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the linewidth scale factor value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pelwsc
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           RLAR(1)     .EQ. LWSCF .AND.
     2           INTG        .EQ. 0     .AND.
     3           RL          .EQ. 1     .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***    Polyline colour index    *** *** *** *** ***
C set value for attribute
      CALL PSPLCI (6)

      CALL SETMSG ('1 19', '<Inquire current element type '  //
     1             'and size> should return polyline '       //
     2             'colour index as the type of the '        //
     3             'created element and the appropriate '    //
     4             'element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 25 is the PHIGS enumeration type for peplci
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 25    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 19', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the polyline colour index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peplci
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           INTAR(1)    .EQ. 6     .AND.
     2           INTG        .EQ. 1     .AND.
     3           RL          .EQ. 0     .AND.
     4           STR         .EQ. 0)

C close it up
      CALL ENDIT
      END
