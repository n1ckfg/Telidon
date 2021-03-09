C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.04/01                           *
C  *    TEST TITLE : Delete element                        *
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
 
      INTEGER ELEPOS, LABL1, LABL2, LABL3, LABL4, LABL5, LABL6,
     1        LABL7, LABL8, LABL9, LABL10, STRID
      PARAMETER (LABL1 = 1, LABL2 = 2, LABL3 = 3, LABL4 = 4,
     1           LABL5 = 5, LABL6 = 6, LABL7 = 7, LABL8 = 8,
     2           LABL9 = 9, LABL10 = 10, STRID = 100)
 
      LOGICAL STRCON
 
      CALL INITGL ('02.02.04/01')
 
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
 
      ELEPOS = 0
 
      CALL SETMSG ('2', 'If <delete element> is used, and if the '    //
     1             'element position is zero nothing should be '      //
     2             'deleted.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <delete element>
      CALL PDEL
      CALL IFPF (STRCON (STRID, '67,1,67,2,67,4,67,3,67,4,67,6,67,5,' //
     1                          '67,6,67,8,67,7,67,8,67,10,67,9,67,10'))
 
      CALL SETMSG ('7', 'If <delete element> is used, and nothing '   //
     1             'is deleted the element pointer should be '        //
     2             'unchanged.')
      CALL CHKELP (0)
 
      ELEPOS = 1
      CALL SETMSG ('1', '<Delete element> should delete a leading '   //
     1             'structure element pointed to by the element '     //
     2             'pointer.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <delete element>
      CALL PDEL
      CALL IFPF (STRCON (STRID, '67,2,67,4,67,3,67,4,67,6,67,5,67,6,' //
     1                          '67,8,67,7,67,8,67,10,67,9,67,10'))
 
      CALL SETMSG ('7', 'Following <delete element>, the element '    //
     1             'pointer should be positioned at the element '     //
     2             'immediately preceding the deleted leading '       //
     3             'structure element.')
      CALL CHKELP (0)
 
      ELEPOS = 3
      CALL SETMSG ('1', '<Delete element> should delete a middle '    //
     1             'structure element pointed to by the element '     //
     2             'pointer.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <delete element>
      CALL PDEL
      CALL IFPF (STRCON (STRID, '67,2,67,4,67,4,67,6,67,5,67,6,67,8,' //
     1                          '67,7,67,8,67,10,67,9,67,10'))
 
      CALL SETMSG ('7', 'Following <delete element>, the element '    //
     1             'pointer should be positioned at the element '     //
     2             'immediately preceding the deleted middle '        //
     3             'structure element.')
      CALL CHKELP (2)
 
      ELEPOS = 12
      CALL SETMSG ('1', '<Delete element> should delete a last '      //
     1             'structure element pointed to by the element '     //
     2             'pointer.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <delete element>
      CALL PDEL
      CALL IFPF (STRCON (STRID, '67,2,67,4,67,4,67,6,67,5,67,6,67,8,' //
     1                          '67,7,67,8,67,10,67,9'))
 
      CALL SETMSG ('7', 'Following <delete element>, the element '    //
     1             'pointer should be positioned at the element '     //
     2             'immediately preceding the deleted last '          //
     3             'structure element.')
      CALL CHKELP (11)
 
777   CONTINUE
      CALL ENDIT
      END
