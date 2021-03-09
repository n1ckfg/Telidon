C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/01                        *
C  *    TEST TITLE : Simple setting and inquiring          *
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

      INTEGER     INLEN,    RELEN,    STLEN
      PARAMETER  (INLEN=50, RELEN=50, STLEN=50)

C PHIGS parameter types
      INTEGER    EMTYPE, INTLEN, INTG, RLLEN, RL, STRLEN, STR, STRID
      INTEGER    INTAR (INLEN), STRARL (STLEN)
      REAL       RLAR (RELEN)
      CHARACTER  STRAR (STLEN)

C types of parameter values
      INTEGER    PMI, MTYPE, COLI, MTYPE2, COLI2
      REAL       MWDTH, MWDTH2

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      CALL INITGL ('04.02.02.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)

C structure identifier = 1
      STRID = 1
C open structure
      CALL POPST (STRID)


C *** *** *** *** ***    Polymarker index *** *** *** *** ***
C set value for attribute
      CALL PSPMI (8)

      CALL SETMSG ('1 4', '<Inquire current element type '    //
     1             'and size> should return polymarker index '//
     2             'as the type of the created element and '  //
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, EMTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 19 is the PHIGS enumeration type for pepmi
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           EMTYPE  .EQ. 19    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 4', '<Inquire current element content> '        //
     1             'should return the standard representation for ' //
     2             'the polymarker index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pepli
      CALL IFPF (ERRIND      .EQ. 0  .AND.
     1           INTAR(1)    .EQ. 8  .AND.
     2           INTG        .EQ. 1  .AND.
     3           RL          .EQ. 0  .AND.
     4           STR         .EQ. 0)

C *** *** *** polymarker representation set and inquire

C polymarker index, marker type, marker size scale factor, and colour index
      PMI    = 4
      MTYPE  = 3
      MWDTH  = 0.25
      COLI   = 4
      CALL PSPMR (WKID, PMI, MTYPE, MWDTH, COLI)

C type of returned value = set
      CALL PQPMR (WKID, PMI, PSET, ERRIND, MTYPE2, MWDTH2, COLI2)
      CALL CHKINQ ('pqpmr', ERRIND)

      CALL SETMSG ('11 14',
     1             'Polymarker attributes should be returned as set.')
      CALL IFPF ( ERRIND .EQ. 0          .AND.
     1            MTYPE2 .EQ. MTYPE      .AND.
     2            MWDTH2 .EQ. MWDTH      .AND.
     3            COLI2  .EQ. COLI )

666   CONTINUE
      CALL ENDIT

      END
