C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.05/01                           *
C  *    TEST TITLE : Copy all elements from structure      *
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
 
      INTEGER ELEPOS, LABL1, LABL2, LABL3, LABL9, LABL8, LABL7,
     1        STRID1, STRID2, STRID3
 
      PARAMETER (LABL1 = 1, LABL2 = 2, LABL3 = 3, LABL9 = 9,
     1           LABL8 = 8, LABL7 = 7, STRID1 = 100,
     2           STRID2 = 200, STRID3 = 300)
 
C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)
 
      LOGICAL STRCON
 
      CALL INITGL ('02.02.05/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  create structure strid1:
      CALL POPST (STRID1)
C  fill strid1 with elements:
      CALL PLB (LABL1)
      CALL PLB (LABL2)
      CALL PLB (LABL3)
C  <close structure>
      CALL PCLST
 
C  create structure strid2:
      CALL POPST (STRID2)
C  fill strid2 with elements:
      CALL PLB (LABL9)
      CALL PLB (LABL8)
      CALL PLB (LABL7)
C  <close structure>
      CALL PCLST
 
C  <open structure> for strid1
      CALL POPST (STRID1)
      ELEPOS = 2
      CALL SETMSG ('4', 'If the specified structure in <copy all '    //
     1             'elements from structure> is nonexistent, no '     //
     2             'action should take place.')
 
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <copy all elements from structure> with strid3
      CALL PCELST (STRID3)
 
      IF (STRCON (STRID1, '67,1,67,2,67,3')) THEN
C OK so far
         CALL CHKELP (2)
      ELSE
         CALL FAIL
      ENDIF
 
C  Use <empty structure> to create structure strid3
      CALL PEMST (STRID3)
      ELEPOS = 0
      CALL SETMSG ('4', 'If the specified structure in <copy all '    //
     1             'elements from structure> is empty, no action '    //
     2             'should take place.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <copy all elements from structure> with strid3
      CALL PCELST (STRID3)
 
      IF (STRCON (STRID1, '67,1,67,2,67,3')) THEN
C OK so far
         CALL CHKELP (0)
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('1', '<Copy all elements from structure> should '  //
     1             'copy all elements of a specified structure into ' //
     2             'an open structure after the element pointer '     //
     3             'when the element pointer is positioned at the '   //
     4             'beginning of the structure.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <copy all elements from structure> with strid2
      CALL PCELST (STRID2)
      CALL IFPF (STRCON (STRID1, '67,9,67,8,67,7,67,1,67,2,67,3'))
 
      CALL SETMSG ('3', 'After <copy all elements from structure>, '  //
     1             'the element pointer positioned at the beginning ' //
     2             'of the structure should be updated to point to '  //
     3             'the last element that was copied.')
      CALL CHKELP (3)
 
      ELEPOS = 4
      CALL SETMSG ('1', '<Copy all elements from structure> should '  //
     1             'copy all elements of a specified structure into ' //
     2             'an open structure after the element pointer '     //
     3             'when the element pointer is positioned at the '   //
     4             'middle of the structure.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <copy all elements from structure> with strid2
      CALL PCELST (STRID2)
      CALL IFPF (STRCON (STRID1, '67,9,67,8,67,7,67,1,67,9,67,8,67,7,'//
     1                           '67,2,67,3'))
 
      CALL SETMSG ('3', 'After <copy all elements from structure>, '  //
     1             'the element pointer positioned at the middle of ' //
     2             'the structure should be updated to point to the ' //
     3             'last element that was copied.')
      CALL CHKELP (7)
 
      ELEPOS = 9
      CALL SETMSG ('1', '<Copy all elements from structure> should '  //
     1             'copy all elements of a specified structure into ' //
     2             'an open structure after the element pointer when '//
     3             'the element pointer is positioned at the end of ' //
     4             'the structure.')
C  <set element pointer> with elepos
      CALL PSEP (ELEPOS)
C  <copy all elements from structure> with strid2
      CALL PCELST (STRID2)
      CALL IFPF (STRCON (STRID1, '67,9,67,8,67,7,67,1,67,9,67,8,67,7,'//
     1                           '67,2,67,3,67,9,67,8,67,7'))
 
      CALL SETMSG ('3', 'After <copy all elements from structure>, '  //
     1             'the element pointer positioned at the end of '    //
     2             'the structure should be updated to point to the ' //
     3             'last element that was copied.')
      CALL CHKELP (12)
 
      ELEPOS = 8
      CALL SETMSG ('1', '<Copy all elements from structure> should '  //
     1             'insert elements even when the edit mode is '      //
     2             'REPLACE.')
C  <set edit mode> to REPLACE
      CALL PSEDM (PREPLC)
C  <set element pointer> with elepos
      CALL PSEP (ELEPOS)
C  <copy all elements from structure> with strid2
      CALL PCELST (STRID2)
      CALL IFPF (STRCON (STRID1, '67,9,67,8,67,7,67,1,67,9,67,8,67,7,'//
     1                           '67,2,67,9,67,8,67,7,67,3,67,9,67,8,'//
     2                           '67,7'))
 
      CALL SETMSG ('3', 'After <copy all elements from structure>, '  //
     1             'the element pointer should be updated to point '  //
     2             'to the last element that was copied when the '    //
     3             'edit mode is set to REPLACE.')
      CALL CHKELP (11)
 
C  <close structure>
      CALL PCLST
C  <open structure> for strid2
      CALL POPST (STRID2)
      ELEPOS = 2
      CALL SETMSG ('2', 'If the specified structure in <copy all '    //
     1             'elements from structure> is the open structure, ' //
     2             'its contents should be copied into itself after ' //
     3             'the element pointer.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <copy all elements from structure> with strid2
      CALL PCELST (STRID2)
      CALL IFPF (STRCON (STRID2, '67,9,67,8,67,9,67,8,67,7,67,7'))
 
      CALL SETMSG ('3', 'After <copy all elements from structure>, '  //
     1             'the element pointer should be updated to point '  //
     2             'to the last element that was copied when the '    //
     3             'specified structure is the open structure.')
      CALL CHKELP (5)
 
777   CONTINUE
      CALL ENDIT
      END
