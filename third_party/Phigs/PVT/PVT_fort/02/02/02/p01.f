C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.02/01                           *
C  *    TEST TITLE : Label                                 *
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
 
      INTEGER CELTYP, INLEN, INTLEN, INTG, LABID, RELEN, RL, RLLEN,
     1        STR, STRLEN, STLEN, STRID
      PARAMETER (INLEN = 50, STLEN = 50, RELEN = 50, STRID = 1)
 
      INTEGER INTAR(INLEN), STRARL(STLEN)
 
      REAL RLAR(RELEN)
 
      CHARACTER STRAR(STLEN)
 
      CALL INITGL ('02.02.02/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  *** *** *** *** ***   Label   *** *** *** *** ***
 
      LABID = 46
 
C <open structure>
      CALL POPST (STRID)
 
C <label> with labid
      CALL PLB (LABID)
 
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return label as the type of the created '  //
     2             'element and the appropriate element size.')
 
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
 
      CALL IFPF (ERRIND   .EQ.   0  .AND.
     1           CELTYP   .EQ.  67  .AND.
     2           INTLEN   .EQ.   1  .AND.
     3           RLLEN    .EQ.   0  .AND.
     4           STRLEN   .EQ.   0)
 
      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for label.')
 
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
 
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           INTG     .EQ.   1   .AND.
     2           INTAR(1) .EQ.  46   .AND.
     3           RL       .EQ.   0   .AND.
     4           STR      .EQ.   0)
777   CONTINUE
      CALL ENDIT
      END
