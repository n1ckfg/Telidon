C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/01                        *
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

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER     INLEN,    RELEN,    STLEN
      PARAMETER  (INLEN=50, RELEN=50, STLEN=5)

      INTEGER    EETYPE, INTLEN, INTG, RLLEN, RL, STRLEN, STR, STRID
      INTEGER    INTAR (INLEN), STRARL (STLEN), SPECON, SPECWT, NAET
      INTEGER    EDI, ETYPE, COLI, ETYPE2, COLI2, EFLAG, EFLAG2
      INTEGER    IDUM1, IDUM2, IDUM3

      REAL       EWDTH, EWDTH2, RLAR (RELEN)
      REAL       RDUM1, RDUM2, RDUM3

      CHARACTER  STRAR(STLEN)*80 

      CALL INITGL ('04.02.05.03/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C structure identifier = 1
      STRID = 1
C open structure
      CALL POPST (STRID)

C *** *** *** *** ***    Edge index   *** *** *** *** ***
C set value for attribute
      CALL PSEDI (8)

      CALL SETMSG ('1 4', '<Inquire current element type '   //
     1             'and size> should return edge index '     //
     2             'as the type of the created element and ' //
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, EETYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 22 is the PHIGS enumeration type for peedi
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           EETYPE  .EQ. 22    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 4', '<Inquire current element content> '      //
     1             'should return the standard representation for ' //
     2             'the edge index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peedi
      CALL IFPF (ERRIND      .EQ. 0  .AND.
     1           INTAR(1)    .EQ. 8  .AND.
     2           INTG        .EQ. 1  .AND.
     3           RL          .EQ. 0  .AND.
     4           STR         .EQ. 0)

C *** *** ***   edge representation set and inquire   *** *** ***

C  get an available edgetype
      CALL PQEDF (SPECWT, 0,    ERRIND, NAET,  IDUM1, IDUM2,
     1            RDUM1, RDUM2, RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)

      CALL PQEDF (SPECWT, NAET, ERRIND, IDUM1, ETYPE, IDUM2,
     1            RDUM1, RDUM2, RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)

C edge index, edgetype, edgewidth scale factor, and colour index
      EDI    = 2
      EFLAG  = PON
      EWDTH  = 4.0
      COLI   = 5
      CALL PSEDR (WKID, EDI, EFLAG, ETYPE, EWDTH, COLI)

C type of returned value = set
      CALL PQEDR (WKID, EDI, PSET, ERRIND, EFLAG2, ETYPE2,
     1            EWDTH2, COLI2)
      CALL CHKINQ ('pqedr', ERRIND)

      CALL SETMSG ('11 14', 'Edge attributes should be returned ' //
     1             'as set.')

      CALL IFPF ( ERRIND .EQ. 0          .AND.
     1            EFLAG2 .EQ. EFLAG      .AND.
     2            ETYPE2 .EQ. ETYPE      .AND.
     3            EWDTH2 .EQ. EWDTH      .AND.
     4            COLI2  .EQ. COLI )

666   CONTINUE
      CALL ENDIT
      END
