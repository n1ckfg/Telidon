C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.03.03/03                        *
C  *    TEST TITLE : Effects of <change structure          *
C  *                 identifier and references> on the     *
C  *                 element pointer                       *
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
 
C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)
 
C  Declare program-specific variables
      INTEGER COMSTR, ORGID, RESID
 
      CALL INITGL ('02.01.03.03/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('4', 'If the original and resulting identifier '   //
     1             'are the same and the common structure is open '   //
     2             'and empty after execution of <change structure '  //
     3             'identifier and references> then the element '     //
     4             'pointer should be at zero.')
 
C subroutine to set up the CSS
      CALL STDCSS
 
      COMSTR = 142
      CALL POPST (COMSTR)
      CALL PCSTIR (COMSTR, COMSTR)
      CALL CHKELP (0)
      CALL PCLST
 
      CALL SETMSG ('4', 'If the original and resulting identifier '   //
     1             'are the same and the common structure is open '   //
     2             'and not empty after execution of <change '        //
     3             'structure identifier and references> then the '   //
     4             'element pointer should remain at its current '    //
     5             'position.')
 
C subroutine to set up the CSS
      CALL STDCSS
 
      CALL PSEDM (PREPLC)
      COMSTR = 111
      CALL POPST (COMSTR)
 
C set element pointer to 4
      CALL PSEP (4)
      CALL PCSTIR (COMSTR, COMSTR)
      CALL CHKELP (4)
      CALL PCLST
 
      CALL SETMSG ('5', 'If the original and resulting identifiers '  //
     1             'differ and the original structure is open after ' //
     2             'execution of <change structure identifier and '   //
     3             'references> then the open structure should be '   //
     4             'empty and the element pointer set to zero.')
 
C subroutine to set up the CSS
      CALL PSEDM (PINSRT)
      CALL STDCSS
 
      ORGID = 111
      RESID = 130
      CALL POPST (ORGID)
 
C  set element pointer to 3
      CALL PSEP (3)
      CALL PCSTIR (ORGID, RESID)
      CALL CHKELP (0)
      CALL PCLST
 
      CALL SETMSG ('6', 'If the original and resulting identifiers '  //
     1             'differ, the original structure does not exist '   //
     2             'and the resulting structure is open after '       //
     3             'execution of <change structure identifier and '   //
     4             'references> then the element pointer of the '     //
     5             'open structure should be set to zero.')
 
C subroutine to set up the CSS
      CALL STDCSS
 
      ORGID = 300
      RESID = 111
      CALL POPST  (RESID)
      CALL PCSTIR (ORGID, RESID)
 
      CALL CHKELP (0)
      CALL PCLST
 
      CALL SETMSG ('6', 'If the original and resulting identifiers '  //
     1             'differ, the original structure does exist and '   //
     2             'is empty, and the resulting structure is open '   //
     3             'after execution of <change structure identifier ' //
     4             'and references> then the element pointer of the ' //
     5             'open structure should be set to zero.')
 
C subroutine to set up the CSS
      CALL STDCSS
 
      ORGID = 142
      RESID = 111
      CALL POPST (RESID)
 
C  set element pointer to 2
      CALL PSEP (2)
      CALL PCSTIR (ORGID, RESID)
      CALL CHKELP (0)
      CALL PCLST
 
      CALL SETMSG ('6', 'If the original and resulting identifiers '  //
     1             'differ, the original structure does exist and '   //
     2             'is not empty, and the resulting structure is '    //
     3             'open after execution of <change structure '       //
     4             'identifier and references> then the element '     //
     5             'pointer of the open structure should be set to '  //
     6             'the last element.')
 
C subroutine to set up the CSS
      CALL STDCSS
 
      ORGID = 111
      RESID = 104
      CALL POPST (RESID)
 
C  set element pointer to 3
      CALL PSEP (3)
      CALL PCSTIR (ORGID, RESID)
      CALL CHKELP (11)
 
      CALL ENDIT
      END
