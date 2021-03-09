C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.04.01/01                        *
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

      INTEGER    PEPARF,      PEADS,       PERES,       PEIASF
      PARAMETER (PEPARF = 52, PEADS  = 53, PERES  = 54, PEIASF = 55)

      INTEGER    NAMSET(10), NAMSIZ
      INTEGER    CELTYP, INTLEN, INTG, RLLEN, RL, STRLEN, STR, INLEN,
     1           STLEN, RELEN, STRID, LDR
      PARAMETER (INLEN=5, STLEN=10, RELEN=50, STRID=1, LDR=20)
      INTEGER    INTAR(INLEN), STRL2(STLEN)
      LOGICAL    SETIS
      REAL       RLAR(RELEN)

      CHARACTER  DATREC(LDR)*80, NAMVAL*50

C  parameters for <inquire workstation connection and type>

      CALL INITGL ('04.03.04.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open structure
      CALL POPST (STRID)

C initialize array
      NAMVAL = '30,62,63,0,1'
      CALL SETVS (NAMVAL, NAMSET, NAMSIZ)

C <add name to set>
      CALL PADS (NAMSIZ,NAMSET)

      CALL SETMSG ('1 2', '<Inquire current element type and size> ' //
     1             'should return add names to set as the type of '  //
     2             'the created element and the appropriate '//
     3             'element size.')
C <inquire current element type and size> to determine celtyp, celsiz
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
      CALL IFPF (ERRIND    .EQ.      0  .AND.
     1           CELTYP    .EQ.  PEADS  .AND.
     2           INTLEN    .EQ. NAMSIZ  .AND.
     3           RLLEN     .EQ.      0  .AND.
     4           STRLEN    .EQ.      0)

      CALL SETMSG ('1 3 9', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'add names to set for any set of names drawn '   //
     3             'from the accessible range.')
C  <inquire current element content> to determine celcon
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRL2, DATREC)
      CALL IFPF (ERRIND    .EQ.      0  .AND.
     1           INTG      .EQ. NAMSIZ  .AND.
     2           SETIS (INTAR, NAMVAL)  .AND.
     3           RL        .EQ.      0  .AND.
     4           STR       .EQ.      0)

C  <remove name from set>
      CALL PRES (NAMSIZ, NAMSET)

      CALL SETMSG ('4 5', '<Inquire current element type and size> '  //
     1             'should return remove names from set as the '      //
     2             'type of the created element and the appropriate ' //
     3             'element size.')
C <inquire current element type and size> to determine celtyp, celsiz
      CALL PQCETS (ERRIND, CELTYP, INTLEN, RLLEN, STRLEN)
      CALL IFPF (ERRIND    .EQ.      0  .AND.
     1           CELTYP    .EQ.  PERES  .AND.
     2           INTLEN    .EQ. NAMSIZ  .AND.
     3           RLLEN     .EQ.      0  .AND.
     4           STRLEN    .EQ.      0)

      CALL SETMSG ('4 6 9', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'remove names from set for any set of names '    //
     3             'drawn from the accessible range.')
C  <inquire current element content> to determine celcon
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRL2, DATREC)
      CALL IFPF (ERRIND    .EQ.      0  .AND.
     1           INTG      .EQ. NAMSIZ  .AND.
     2           SETIS (INTAR, NAMVAL)  .AND.
     3           RL        .EQ.      0  .AND.
     4           STR       .EQ.      0)

666   CONTINUE
C wrap it up
      CALL ENDIT
      END
