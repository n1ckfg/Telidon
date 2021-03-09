C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/01                        *
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

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP=0,   PCHARP=1,   PSTRKP=2)

C type of return values
      INTEGER    PSET,     PREALI
      PARAMETER (PSET=0,   PREALI=1)

C PHIGS parameter types
      INTEGER    ELTYPE, INTLEN, INTG, RLLEN, RL, STRLEN, STR, STRID
      INTEGER    INTAR(INLEN), STRARL(STLEN)
      REAL       RLAR(RELEN), TXATR1,TXATR2
      CHARACTER  STRAR(STLEN)
      REAL       TCHXP, TCHSP
      INTEGER    TFONT, TPREC, TCOLI, SPECON, SPECWT

      CALL INITGL ('04.02.03.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C structure identifier = 1
      STRID = 1
C open structure
      CALL POPST (STRID)

C *** *** *** *** ***    Text index    *** *** *** *** ***
C  <set text index>:
      CALL PSTXI (4)
C
      CALL SETMSG ('1 4', '<Inquire current element type and size> ' //
     1             'should return text index as the type of the '    //
     2             'created element and the appropriate element '    //
     3             'size.')

C  <inquire current element type and size> for current element type
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
      CALL CHKINQ ('pqcets', ERRIND)

C checking correct element type
C 20 is the PHIGS enumeration type for petxi
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 20    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0  )


C  <inquire current element content> for current element representation
      CALL SETMSG ('2 4', '<Inquire current element content> should ' //
     1             'return the standard representation for the text ' //
     2             'index value.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
      CALL CHKINQ ('pqceco', ERRIND)

C checking correct output parameters for data record type petxi
      CALL IFPF (ERRIND      .EQ. 0       .AND.
     1           INTAR(1)    .EQ. 4       .AND.
     2           INTG        .EQ. 1       .AND.
     3           RL          .EQ. 0       .AND.
     4           STR         .EQ. 0)

C  *** ***  text representation set and inquire *** ***
C set text representation for index #2
      TXATR1 = 2.1
      TXATR2 = 0.7
      CALL PSTXR (WKID, 2, 2, PSTRKP, TXATR1, TXATR2, 5)

C  <inquire text representation> for index #2, as set
      CALL SETMSG ('11 14', 'Text attributes should be returned as ' //
     1             'set.')

      CALL PQTXR (WKID, 2, PSET, ERRIND, TFONT, TPREC, TCHXP, TCHSP,
     1            TCOLI)
      CALL CHKINQ ('pqtxr', ERRIND)
      CALL IFPF (ERRIND     .EQ.   0        .AND.
     1           TFONT      .EQ.   2        .AND.
     2           TPREC      .EQ.   PSTRKP   .AND.
     3           TCHXP      .EQ.   TXATR1   .AND.
     4           TCHSP      .EQ.   TXATR2   .AND.
     5           TCOLI      .EQ.   5)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
