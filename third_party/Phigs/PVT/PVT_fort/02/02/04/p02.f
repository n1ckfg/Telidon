C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.04/02                           *
C  *    TEST TITLE : Delete element range                  *
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
 
      INTEGER ELPOS1, ELPOS2, LABL1, LABL2, LABL3, LABL4,
     1        LABL5, LABL6, LABL7, LABL8, LABL9, LABL10, STRID
      PARAMETER (LABL1 = 1, LABL2 = 2, LABL3 = 3, LABL4 = 4,
     1           LABL5 = 5, LABL6 = 6, LABL7 = 7, LABL8 = 8,
     2           LABL9 = 9, LABL10 = 10, STRID = 100)
 
      LOGICAL STRCON
 
      CALL INITGL ('02.02.04/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  <open structure> with strid
      CALL POPST (STRID)
 
C  fill structure with elements:
      CALL PLB (LABL1)
      CALL PLB (LABL2)
      CALL PLB (LABL4)
      CALL PLB (LABL3)
      CALL PLB (LABL4)
      CALL PLB (LABL6)
      CALL PLB (LABL5)
      CALL PLB (LABL6)
      CALL PLB (LABL8)
      CALL PLB (LABL7)
      CALL PLB (LABL8)
      CALL PLB (LABL10)
      CALL PLB (LABL9)
      CALL PLB (LABL10)
      CALL PLB (LABL2)
      CALL PLB (LABL1)
      CALL PLB (LABL2)
      CALL PLB (LABL4)
      CALL PLB (LABL3)
 
      ELPOS1 = 9
      ELPOS2 = 11
      CALL SETMSG ('3', '<Delete element range> should delete all '   //
     1             'structure elements between and including the '    //
     2             'lower element position and the higher element '   //
     3             'position when the lower position is the first '   //
     4             'parameter.')
C  <delete element range> with elpos1, elpos2
      CALL PDELRA (ELPOS1, ELPOS2)
      CALL IFPF (STRCON (STRID, '67,1,67,2,67,4,67,3,67,4,67,6,67,5,' //
     1                          '67,6,67,10,67,9,67,10,67,2,67,1,'    //
     2                          '67,2,67,4,67,3'))
 
      ELPOS1 = 16
      ELPOS2 = 14
      CALL SETMSG ('3', '<Delete element range> should delete all '   //
     1             'structure elements between and including the '    //
     2             'lower element position and the higher element '   //
     3             'position when the lower position is the second '  //
     4             'parameter.')
C  <delete element range> with elpos1, elpos2
      CALL PDELRA (ELPOS1, ELPOS2)
      CALL IFPF (STRCON (STRID, '67,1,67,2,67,4,67,3,67,4,67,6,67,5,' //
     1                          '67,6,67,10,67,9,67,10,67,2,67,1'))
 
      CALL SETMSG ('7', 'Following <delete element range>, the '      //
     1             'element pointer should be positioned at the '     //
     2             'element immediately preceding the group of '      //
     3             'elements deleted at the end of the structure.')
      CALL CHKELP (13)
 
      ELPOS1 = 1
      ELPOS2 = 3
      CALL SETMSG ('3', '<Delete element range> should delete all '   //
     1             'structure elements between and including the '    //
     2             'lower element position and the higher element '   //
     3             'position when the lower element position is '     //
     4             'defined as the beginning of the structure.')
C  <delete element range> with elpos1, elpos2
      CALL PDELRA (ELPOS1, ELPOS2)
      CALL IFPF (STRCON (STRID, '67,3,67,4,67,6,67,5,67,6,67,10,67,9,'//
     1                          '67,10,67,2,67,1'))
 
      CALL SETMSG ('7', 'Following <delete element range>, the '      //
     1             'element pointer should be positioned at the '     //
     2             'element immediately preceding the group of '      //
     3             'elements deleted at the beginning of the '        //
     4             'structure.')
      CALL CHKELP (0)
 
      ELPOS1 = -10
      ELPOS2 = 3
      CALL SETMSG ('3 4', 'If <delete element range> is used, and '   //
     1             'if an element position is less than 1, a value '  //
     2             'of 0 should be used.')
C  <delete element range> with elpos1, elpos2
      CALL PDELRA (ELPOS1, ELPOS2)
      CALL IFPF (STRCON (STRID, '67,5,67,6,67,10,67,9,67,10,67,2,67,1'))
 
      CALL SETMSG ('7', 'Following <delete element range>, the '      //
     1             'element pointer should be positioned at the '     //
     2             'element immediately preceding the group of '      //
     3             'elements deleted when the element position is '   //
     4             'less than 1.')
      CALL CHKELP (0)
 
      ELPOS1 = 5
      ELPOS2 = 10
      CALL SETMSG ('3 4', 'If <delete element range> is used, and '   //
     1             'if an element position is greater than the '      //
     2             'number of elements in the open structure, a '     //
     3             'value pointing to the last element in the '       //
     4             'structure should be used.')
C  <delete element range> with elpos1, elpos2
      CALL PDELRA (ELPOS1, ELPOS2)
      CALL IFPF (STRCON (STRID, '67,5,67,6,67,10,67,9'))
 
      CALL SETMSG ('7', 'Following <delete element range>, the '      //
     1             'element pointer should be positioned at the '     //
     2             'element immediately preceding the group of '      //
     3             'elements deleted when the element position is '   //
     4             'greater than the number of elements in the open ' //
     5             'structure.')
      CALL CHKELP (4)
 
      ELPOS1 = -10
      ELPOS2 = 15
      CALL SETMSG ('3 4', 'If <delete element range> is used, and '   //
     1             'if an element position is less than 1, a value '  //
     2             'of 0 should be used; if an element position is '  //
     3             'greater than the number of elements in the open ' //
     4             'structure, a value pointing to the last element ' //
     5             'in the structure should be used.')
C  <delete element range> with elpos1, elpos2
      CALL PDELRA (ELPOS1, ELPOS2)
      CALL IFPF (STRCON (STRID, ' '))
 
      CALL SETMSG ('7', 'Following <delete element range>, the '      //
     1             'element pointer should be positioned at the '     //
     2             'element immediately preceding the group of '      //
     3             'elements deleted when the element positions are ' //
     4             'less than 1 and greater than the number of '      //
     5             'elements in the open structure.')
      CALL CHKELP (0)
 
777   CONTINUE
      CALL ENDIT
      END
