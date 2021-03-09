C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.04/04                           *
C  *    TEST TITLE : Empty structure                       *
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
 
      INTEGER LABL1, LABL2, LABL3, LABL4, LABL5, LABL6, LABL7,
     1        LABL8, LABL10, STRID, STRIDC, STRIDO, STSTIN
 
      INTEGER PSEMPT
 
      PARAMETER (LABL1 = 1, LABL2 = 2, LABL3 = 3, LABL4 = 4,
     1           LABL5 = 5, LABL6 = 6, LABL7 = 7, LABL8 = 8,
     2           LABL10 = 10, PSEMPT = 1, STRID = 90,
     3           STRIDC = 100, STRIDO = 110)
 
      LOGICAL STRCON
 
      CALL INITGL ('02.02.04/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  <open structure> with stridc
      CALL POPST (STRIDC)
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
C  <close structure>
      CALL PCLST
 
C  <open structure> with strido
      CALL POPST (STRIDO)
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
C  <close structure>
      CALL PCLST
 
C  create structure network:
 
C            90
C           /  \
C          /    \
C        100   110
 
C  <open structure> with strid
      CALL POPST (STRID)
C  execute structure strido, stridc into strid:
      CALL PEXST (STRIDC)
      CALL PEXST (STRIDO)
C  <close structure>
      CALL PCLST
 
      CALL SETMSG ('8 9', '<Empty structure> should delete all the '  //
     1             'elements of a specified closed structure, but '   //
     2             'the structure itself should still exist.')
C  <empty structure> with stridc
      CALL PEMST (STRIDC)
 
C  <inquire structure status> with stridc to set ststin
      CALL PQSTST (STRIDC, ERRIND, STSTIN)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STSTIN   .EQ.   PSEMPT)
 
      CALL SETMSG ('10', 'After using <empty structure> on a '        //
     1             'specified closed structure, references to the '   //
     2             'now empty closed structure should remain '        //
     3             'intact.')
      CALL IFPF (STRCON (STRID, '66,100,66,110'))
 
      CALL SETMSG ('8 9', '<Empty structure> should delete all the '  //
     1             'elements of a specified open structure, but the ' //
     2             'structure itself should still exist.')
 
C  <open structure> with strido
      CALL POPST (STRIDO)
C  <empty structure> with strido
      CALL PEMST (STRIDO)
C  <inquire structure status> with strido to set ststin
      CALL PQSTST (STRIDO, ERRIND, STSTIN)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STSTIN   .EQ.   PSEMPT)
 
      CALL SETMSG ('10', 'After using <empty structure> on a '        //
     1             'specified open structure, references to the now ' //
     2             'empty open structure should remain intact.')
      CALL IFPF (STRCON (STRID, '66,100,66,110'))
 
      CALL SETMSG ('11', 'If <empty structure> is used on a '         //
     1             'specified open structure, the element pointer '   //
     2             'should be set to 0.')
      CALL CHKELP (0)
 
777   CONTINUE
      CALL ENDIT
      END
