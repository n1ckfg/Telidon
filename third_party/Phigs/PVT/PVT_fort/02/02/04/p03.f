C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.04/03                           *
C  *    TEST TITLE : Delete elements between labels        *
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
 
      CALL INITGL ('02.02.04/03')
 
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
      CALL PLB (LABL7)
      CALL PLB (LABL8)
      CALL PLB (LABL10)
      CALL PLB (LABL9)
      CALL PLB (LABL10)
 
      ELEPOS = 6
      CALL SETMSG ('5 6', '<Delete elements between labels> should '  //
     1             'delete elements between but not including the '   //
     2             'occurrences of two specified labels when the '    //
     3             'element pointer is not pointing to a specified '  //
     4             'label.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <delete elements between labels> with labl5, labl8
      CALL PDELLB (LABL5, LABL8)
      CALL IFPF (STRCON (STRID, '67,1,67,2,67,4,67,3,67,4,67,6,67,5,' //
     1                          '67,8,67,7,67,7,67,8,67,10,67,9,67,10'))
 
      CALL SETMSG ('7', 'Following <delete elements between '         //
     1             'labels>, the element pointer should be '          //
     2             'positioned at the element immediately preceding ' //
     3             'the deleted group elements (when the element '    //
     4             'pointer was not pointing to a specified label).')
      CALL CHKELP (7)
 
      ELEPOS = 3
      CALL SETMSG ('5 6', '<Delete elements between labels> should '  //
     1             'delete elements between but not including the '   //
     2             'occurrences of two specified labels when the '    //
     3             'element pointer is currently pointing to a '      //
     4             'specified label.')
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
C  <delete elements between labels> with labl4, labl5
      CALL PDELLB (LABL4, LABL5)
      CALL IFPF (STRCON (STRID, '67,1,67,2,67,4,67,3,67,4,67,5,67,8,' //
     1                          '67,7,67,7,67,8,67,10,67,9,67,10'))
 
      CALL SETMSG ('7', 'Following <delete elements between '         //
     1             'labels>, the element pointer should be '          //
     2             'positioned at the element immediately preceding ' //
     3             'the deleted group elements (when the element '    //
     4             'pointer was pointing to a specified label).')
      CALL CHKELP (5)
          
      ELEPOS = 1
      CALL SETMSG ('5 6', '<Delete elements between labels> should ' //
     1             'delete elements between but not including the '  //
     2             'successive occurrences of two labels with the '  //
     3             'same value.')
      CALL PSEP (ELEPOS)
      CALL PDELLB (LABL8, LABL8)
      CALL IFPF (STRCON (STRID, '67,1,67,2,67,4,67,3,67,4,67,5,67,8,' //
     1                          '67,8,67,10,67,9,67,10'))

      CALL SETMSG ('7', 'Following <delete elements between '         //
     1             'labels>, the element pointer should be '          //
     2             'positioned at the element immediately preceding ' //
     3             'the deleted group elements (when both labels '    //
     4             'had the same value).')
      CALL CHKELP (7)

      ELEPOS = 0
      CALL SETMSG ('5 6', '<Delete elements between labels> should ' //
     1             'delete no elements if the two labels are adjacent.')
      CALL PSEP (ELEPOS)
      CALL PDELLB (LABL4, LABL3)
      CALL IFPF (STRCON (STRID, '67,1,67,2,67,4,67,3,67,4,67,5,67,8,' //
     1                          '67,8,67,10,67,9,67,10'))

      CALL SETMSG ('7', 'Following <delete elements between '         //
     1             'labels>, the element pointer should be '          //
     2             'positioned at the element immediately preceding ' //
     3             'the deleted group elements (when the labels '     //
     4             'were adjacent).')
      CALL CHKELP (3)

777   CONTINUE
      CALL ENDIT
      END
