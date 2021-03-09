C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.04/05                           *
C  *    TEST TITLE : Deleting structure elements in        *
C  *                 REPLACE edit mode                     *
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
 
      INTEGER ELEPOS, ELPOS1, ELPOS2, LABL1, LABL2, LABL3, LABL4,
     1        LABL5, LABL6, LABL7, LABL8, LABL9, LABL10, STRID,
     2        STSTIN
 
      PARAMETER (LABL1 = 1, LABL2 = 2, LABL3 = 3, LABL4 = 4,
     1           LABL5 = 5, LABL6 = 6, LABL7 = 7, LABL8 = 8,
     2           LABL9 = 9, LABL10 = 10, STRID = 100)
 
C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)
 
C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)
 
      LOGICAL STRCON
 
      CALL INITGL ('02.02.04/05')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  <open structure> for strid
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
 
C  <set edit mode> to REPLACE
      CALL PSEDM (PREPLC)
 
      ELEPOS = 9
      CALL SETMSG ('1', 'When the edit mode is REPLACE, <delete '     //
     1             'element> should delete the element pointed to '   //
     2             'by the element pointer.')
C  <set element pointer> to elepos and <delete element>
      CALL PSEP (ELEPOS)
      CALL PDEL
      CALL IFPF (STRCON (STRID, '67, 1,67,2,67,4,67,3,67, 4,67,6,'    //
     1                          '67, 5,67,6,67,7,67,8,67,10,67,9,'    //
     2                          '67,10,67,2,67,1,67,2,67, 4'))
 
      CALL SETMSG ('7', 'When the edit mode is REPLACE, following '   //
     1             '<delete element>, the element pointer should be ' //
     2             'positioned at the element immediately preceding ' //
     3             'the deleted structure element.')
      CALL CHKELP (8)
 
      ELPOS1 = 2
      ELPOS2 = 6
      CALL SETMSG ('3', 'When the edit mode is REPLACE, <delete '     //
     1             'element range> should delete all structure '      //
     2             'elements between and including the lower '        //
     3             'element position and the higher element '         //
     4             'position.')
C  <delete element range> elpos1, elpos2
      CALL PDELRA (ELPOS1, ELPOS2)
      CALL IFPF (STRCON (STRID, '67,1,67, 5,67,6,67,7,67,8,67,10,'    //
     1                          '67,9,67,10,67,2,67,1,67,2,67, 4'))
 
      CALL SETMSG ('7', 'When the edit mode is REPLACE, following '   //
     1             '<delete element range>, the element pointer '     //
     2             'should be positioned at the element immediately ' //
     3             'preceding the deleted group elements.')
      CALL CHKELP (1)
 
      ELEPOS = 0
      CALL SETMSG ('5 6', 'When the edit mode is REPLACE, <delete '   //
     1             'elements between labels> should delete elements ' //
     2             'between but not including the occurences of two ' //
     3             'specified labels.')
C  <set element pointer> to elepos and
C  <delete elements between labels> with labl10, labl10
      CALL PSEP (ELEPOS)
      CALL PDELLB (LABL10, LABL10)
      CALL IFPF (STRCON (STRID, '67, 1,67,5,67,6,67,7,67,8,67,10,'    //
     1                          '67,10,67,2,67,1,67,2,67,4'))
 
      CALL SETMSG ('7', 'When the edit mode is REPLACE, following '   //
     1             '<delete elements between labels>, the element '   //
     2             'pointer should be positioned at the element '     //
     3             'immediately preceding the deleted group '         //
     4             'elements.')
      CALL CHKELP (6)
 
      CALL SETMSG ('8 9', 'When the edit mode is REPLACE, <empty '    //
     1             'structure> should delete all the elements of a '  //
     2             'specified structure, but the structure itself '   //
     3             'should still exist.')
C  <empty structure> with strid
      CALL PEMST (STRID)
 
C  <inquire structure status> with strid to set ststin
      CALL PQSTST (STRID, ERRIND, STSTIN)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STSTIN   .EQ.   PSEMPT)
 
      CALL ENDIT
      END
