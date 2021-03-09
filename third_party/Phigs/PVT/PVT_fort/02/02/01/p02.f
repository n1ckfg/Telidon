C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.01/02                           *
C  *    TEST TITLE : Opening and closing a non-empty       *
C  *                 existing structure                    *
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
 
      INTEGER ELEPOS, LABEL1, LABEL2, OPSTST, STRID, RSTRID, STSTIN
 
      PARAMETER (LABEL1 = 1, LABEL2 = 2, STRID = 40)
 
C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)
 
C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)
 
      CALL INITGL ('02.02.01/02')
 
C open PHIGS
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  <Open structure> with strid
 
      CALL POPST (STRID)
 
C  Fill open structure with elements:
 
      CALL PLB (LABEL1)
      CALL PLB (LABEL2)
 
C  <inquire open structure> to set opstst, strid
 
      CALL SETMSG ('1 5', 'If a non-empty structure is open '         //
     1             '<inquire open structure> should return an OPEN '  //
     2             'structure status and the structure identifier '   //
     3             'of the open structure.')
 
      CALL PQOPST (ERRIND, OPSTST, RSTRID)
      CALL IFPF (ERRIND   .EQ.   0      .AND.
     1           OPSTST   .EQ.   POPNST .AND.
     2           RSTRID   .EQ.   STRID)
 
C  <inquire structure status> to set ststin
      CALL SETMSG ('7', '<Inquire structure status> should return ' //
     1             'the appropriate structure status as NOTEMPTY '  //
     2             'for a non-empty structure when the structure '  //
     3             'is open.')
 
      CALL PQSTST (STRID, ERRIND, STSTIN)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           STSTIN   .EQ.   PSNEMP)
 
C check that re-opening structure re-sets element pointer
      CALL PSEP (1)
      CALL PCLST
      CALL POPST (STRID)
C  <inquire element pointer> to set elepos
      CALL SETMSG ('2 8', '<Inquire element pointer> should return '//
     1             'the element pointer position as the last '      //
     2             'element after opening a non-empty structure.')
 
      CALL PQEP (ERRIND, ELEPOS)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           ELEPOS   .EQ.   2)
 
C  <close structure>
      CALL PCLST
 
C  <inquire structure status> to set ststin
      CALL SETMSG ('7', '<Inquire structure status> should return ' //
     1             'the appropriate structure status as NOTEMPTY '  //
     2             'for a non-empty structure when the structure '  //
     3             'is closed.')
 
      CALL PQSTST (STRID, ERRIND, STSTIN)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           STSTIN   .EQ.   PSNEMP)
 
777   CONTINUE
      CALL ENDIT
      END
