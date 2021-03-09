C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/01                        *
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

      INTEGER    INLEN, RELEN, STLEN
      PARAMETER  (INLEN=50, RELEN=50, STLEN=50)

C PHIGS parameter types
      INTEGER    ELTYPE, INTLEN, INTG, RLLEN, RL, STRLEN, STR, STRID
      INTEGER    INTAR (INLEN), STRARL (STLEN)
      REAL       RLAR (RELEN)
      CHARACTER  STRAR (STLEN)

C types of parameter values
      INTEGER    PLI, LTYPE, COLI, LTYPE2, COLI2, PSET
      REAL       LWDTH, LWDTH2

      PARAMETER  (PSET = 0)

      CALL INITGL ('04.02.01.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)

C structure identifier = 1
      STRID = 1
C open structure
      CALL POPST (STRID)


C *** *** *** *** ***    Polyline index *** *** *** *** ***
C set value for attribute
      CALL PSPLI (8)

      CALL SETMSG ('1 4', '<Inquire current element type ' //
     1             'and size> should return polyline index '//
     2             'as the type of the created element and '//
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 18 is the PHIGS enumeration type for pepli
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 18    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 4', '<Inquire current element content> '        //
     1             'should return the standard representation for ' //
     2             'the polyline index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pepli
      CALL IFPF (ERRIND      .EQ. 0  .AND.
     1           INTAR(1)    .EQ. 8  .AND.
     2           INTG        .EQ. 1  .AND.
     3           RL          .EQ. 0  .AND.
     4           STR         .EQ. 0)

C *** *** *** polyline representation set and inquire

C polyline index, linetype, linewidth scale factor, and colour index
      PLI    = 2
      LTYPE  = 3
      LWDTH  = 4.0
      COLI   = 5
      CALL PSPLR (WKID, PLI, LTYPE, LWDTH, COLI)

C type of returned value = set
      CALL PQPLR (WKID, PLI, PSET, ERRIND, LTYPE2, LWDTH2, COLI2)
      CALL CHKINQ ('pqplr', ERRIND)

      CALL SETMSG ('11 14',
     1             'Polyline attributes should be returned as set.')
      CALL IFPF ( ERRIND .EQ. 0          .AND.
     1            LTYPE2 .EQ. LTYPE      .AND.
     2            LWDTH2 .EQ. LWDTH      .AND.
     3            COLI2  .EQ. COLI )

666   CONTINUE
      CALL ENDIT
      END
