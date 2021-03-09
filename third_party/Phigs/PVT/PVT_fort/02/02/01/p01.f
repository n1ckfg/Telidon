C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.01/01                           *
C  *    TEST TITLE : Opening and closing an empty existing *
C  *                 structure                             *
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
 
      INTEGER ELEPOS, OPSTST, STRID, RSTRID, STSTIN, STRSTA
 
      PARAMETER (STRID = 50)
 
C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)
 
C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)
 
C structure state value
      INTEGER    PSTCL,     PSTOP
      PARAMETER (PSTCL = 0, PSTOP = 1)
 
      CALL INITGL ('02.02.01/01')
 
      CALL SETMSG ('9', 'Before opening PHIGS, <inquire structure '   //
     1             'state value> should return the structure state '  //
     2             'value as CLOSED.')
 
C <inquire structure state value> to set strsta
      STRSTA = -6
      CALL PQSTRS (STRSTA)
      CALL IFPF (STRSTA .EQ. PSTCL)
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('9', '<Inquire structure state value> should '     //
     1             'return the structure state value as CLOSED when ' //
     2             'the CSS is empty after opening PHIGS.')
 
C <inquire structure state value> to set strsta
      STRSTA = -6
      CALL PQSTRS (STRSTA)
      CALL IFPF (STRSTA .EQ. PSTCL)
 
      CALL SETMSG ('6', 'If no structures exist, <inquire open '   //
     1             'structure> should return a NONE structure '    //
     2             'status and the structure identifier is undefined.')
 
      CALL PQOPST (ERRIND, OPSTST, RSTRID)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           OPSTST   .EQ.   PNONST)
 
C <inquire structure status> to set ststin
 
      CALL SETMSG ('7', '<Inquire structure status> should return '  //
     1             'the appropriate structure status as NONEXISTENT '//
     2             'for a non-existent structure.')
 
      CALL PQSTST (STRID, ERRIND, STSTIN)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           STSTIN   .EQ.   PSNOEX)
 
C <Open structure> with strid
 
      CALL POPST (STRID)
 
      CALL SETMSG ('9', '<Inquire structure state value> should '     //
     1             'return the structure state value as OPEN when '   //
     2             'an open structure exists in the CSS.')
 
C <inquire structure state value> to set strsta
      STRSTA = -6
      CALL PQSTRS (STRSTA)
      CALL IFPF (STRSTA .EQ. PSTOP)
 
C <inquire open structure> to set opstst, strid
 
      CALL SETMSG ('1 5', 'If an empty structure is open <inquire '   //
     1             'open structure> should return an OPEN structure ' //
     2             'status and the structure identifier of the open ' //
     3             'structure.')
 
      CALL PQOPST (ERRIND, OPSTST, RSTRID)
      CALL IFPF (ERRIND   .EQ.   0      .AND.
     1           OPSTST   .EQ.   POPNST .AND.
     2           RSTRID   .EQ.   STRID)
 
C  <inquire structure status> to set ststin
 
      CALL SETMSG ('7', '<Inquire structure status> should return ' //
     1             'the appropriate structure status as EMPTY for ' //
     2             'an empty structure when the structure is open.')
 
      CALL PQSTST (STRID, ERRIND, STSTIN)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           STSTIN   .EQ.   PSEMPT)
 
C  <inquire element pointer> to set elepos
 
      CALL SETMSG ('3 8', '<Inquire element pointer> should return ' //
     1             'zero as the element pointer position of an '     //
     2             'empty structure.')
 
      CALL PQEP (ERRIND, ELEPOS)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           ELEPOS   .EQ.   0)
 
C  <Close structure>
 
      CALL PCLST
 
      CALL SETMSG ('9', '<Inquire structure state value> should '     //
     1             'return the structure state value as CLOSED when ' //
     2             'a closed structure exists in the CSS.')
 
C <inquire structure state value> to set strsta
      STRSTA = -6
      CALL PQSTRS (STRSTA)
      CALL IFPF (STRSTA .EQ. PSTCL)
 
C  <inquire open structure> to set opstst, strid
 
      CALL SETMSG ('4 6', 'If a structure exists, but none is '      //
     1             'open, <inquire open structure> should return a ' //
     2             'NONE structure status and the structure '        //
     3             'identifier is undefined.')
 
      CALL PQOPST (ERRIND, OPSTST, RSTRID)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           OPSTST   .EQ.   PNONST)
 
C  <inquire structure status> to set ststin
 
      CALL SETMSG ('7', '<Inquire structure status> should return ' //
     1             'the appropriate structure status as EMPTY for ' //
     2             'an empty structure when the structure is closed.')
 
      CALL PQSTST (STRID, ERRIND, STSTIN)
      CALL IFPF (ERRIND   .EQ.   0   .AND.
     1           STSTIN   .EQ.   PSEMPT)
 
777   CONTINUE
 
C close PHIGS
      CALL PCLPH
 
      CALL SETMSG ('9', 'After closing PHIGS, <inquire structure '    //
     1             'state value> should return the structure state '  //
     2             'value as CLOSED.')
 
C <inquire structure state value> to set strsta
      STRSTA = -6
      CALL PQSTRS (STRSTA)
      CALL IFPF (STRSTA .EQ. PSTCL)
 
      CALL ENDIT
      END
