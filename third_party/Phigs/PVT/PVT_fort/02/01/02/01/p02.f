C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.01/02                        *
C  *    TEST TITLE : Structure deletion with an open       *
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
 
C parameter type for structure state
 
      INTEGER POPNST, PSEMPT
      PARAMETER (POPNST = 1, PSEMPT = 1)
 
C PHIGS parameter types
      INTEGER DELSTR, STYPE, STRID, STRSTI
 
      LOGICAL CSSEQ
 
      CALL INITGL ('02.01.02.01/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C creation of structure network
      CALL POPST (100)
      CALL PEXST (105)
      CALL PEXST (110)
      CALL PCLST
      CALL POPST (110)
      CALL PEXST (115)
      CALL PEXST (120)
      CALL PCLST
 
      CALL SETMSG ('5', 'Deleting an open root structure should '   //
     1             'cause the structure to exist in the CSS as an ' //
     2             'open structure.')
 
      DELSTR = 100
      CALL POPST (DELSTR)
      CALL PDST (DELSTR)
 
C use <inquire open structure> to determine
C    stype = structure status
C    strid = structure id
 
      CALL PQOPST (ERRIND, STYPE, STRID)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .NE. POPNST .OR.
     1    STRID .NE. DELSTR)   THEN
         CALL FAIL
      ELSE
         CALL PASS
         CALL PCLST
      ENDIF
 
      CALL SETMSG ('5', 'Deleting an open root structure should ' //
     1             'cause the structure to exist in the CSS as '  //
     2             'an empty structure.')
 
C strsti = structure status identifier
      CALL PQSTST (DELSTR, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF   (STRSTI .EQ. PSEMPT)
 
      CALL SETMSG ('2', 'Deleting an open root structure should '  //
     1             'cause the deletion of all references made to ' //
     2             'that structure contained in other structures.')
 
      CALL IFPF (CSSEQ ('110,1, 115,0/ '//
     1                  '110,2, 120,0/ '//
     2                  '100,0/ '       //
     3                  '105,0/ '))
 
      CALL SETMSG ('5', 'Deleting a non-root structure should '  //
     1             'cause the structure to exist in the CSS as ' //
     2             'an open structure.')
 
      DELSTR = 115
      CALL POPST (DELSTR)
      CALL PDST (DELSTR)
 
C use <inquire open structure> to determine
C    stype = structure status
C    strid = structure id
 
      CALL PQOPST (ERRIND, STYPE, STRID)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .NE. POPNST   .OR.
     1    STRID .NE. DELSTR)     THEN
         CALL FAIL
      ELSE
         CALL PASS
         CALL PCLST
      ENDIF
 
      CALL SETMSG ('5', 'Deleting a non-root structure should '  //
     1             'cause the structure to exist in the CSS as ' //
     2             'an empty structure.')
 
C strsti = structure status identifier
      CALL PQSTST (DELSTR, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF   (STRSTI .EQ. PSEMPT)
 
      CALL SETMSG ('2', 'Deleting a non-root structure should '    //
     1             'cause the deletion of all references made to ' //
     2             'that structure contained in other '            //
     3             'structures.')
 
      CALL IFPF (CSSEQ ('110,1, 120,0/' //
     1                  '115,0/ '       //
     2                  '105,0/ '       //
     3                  '100,0/ '))
 
 666  CONTINUE
      CALL ENDIT
      END
