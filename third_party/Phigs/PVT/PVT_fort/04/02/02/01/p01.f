C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.01/01                        *
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
      INTEGER    INTAR(INLEN), STRARL(STLEN), MTVAL
      REAL       RLAR(RELEN), MKSCF
      CHARACTER  STRAR(STLEN)
 
      CALL INITGL ('04.02.02.01/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C structure identifier = 1
      STRID = 1
C open structure
      CALL POPST (STRID)
 
C *** *** *** *** ***    Marker type    *** *** *** *** ***
C set value for attribute
      MTVAL = 17
      CALL PSMK (MTVAL)
 
      CALL SETMSG ('1 4', '<Inquire current element type '   //
     1             'and size> should return marker type as ' //
     2             'the type of the created element and '    //
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 26 is the PHIGS enumeration type for pemk
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 26    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)
 
      CALL SETMSG ('2 4', '<Inquire current element content> '      //
     1             'should return the standard representation for ' //
     2             'the marker type value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pemk
      CALL IFPF (ERRIND      .EQ. 0      .AND.
     1           INTAR(1)    .EQ. MTVAL  .AND.
     2           INTG        .EQ. 1      .AND.
     3           RL          .EQ. 0      .AND.
     4           STR         .EQ. 0)
 
C *** *** *** *** ***   Marker size scale factor   *** *** *** *** ***
C set value for attribute
      MKSCF = 0.25
      CALL PSMKSC (MKSCF)
 
      CALL SETMSG ('1 13', '<Inquire current element type '   //
     1             'and size> should return marker size '     //
     2             'scale factor as the type of the created ' //
     3             'element and the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 27 is the PHIGS enumeration type for pemksc
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 27    .AND.
     2           INTLEN  .EQ. 0     .AND.
     3           RLLEN   .EQ. 1     .AND.
     4           STRLEN  .EQ. 0)
 
      CALL SETMSG ('2 13', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the marker size scale factor value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pemksc
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           RLAR(1)     .EQ. MKSCF .AND.
     2           INTG        .EQ. 0     .AND.
     3           RL          .EQ. 1     .AND.
     4           STR         .EQ. 0)
 
C *** *** *** *** ***    Polymarker colour index    *** *** *** *** ***
C set value for attribute
      CALL PSPMCI (2)
 
      CALL SETMSG ('1 20', '<Inquire current element type and '   //
     1             'size> should return polymarker colour index ' //
     2             'as the type of the created element and the '  //
     3             'appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 28 is the PHIGS enumeration type for pepmci
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 28    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)
 
      CALL SETMSG ('2 20', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the polymarker colour index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pepmci
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           INTAR(1)    .EQ. 2     .AND.
     2           INTG        .EQ. 1     .AND.
     3           RL          .EQ. 0     .AND.
     4           STR         .EQ. 0)
 
      CALL ENDIT
      END
