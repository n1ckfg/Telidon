C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.02.03/01                           *
C  *    TEST TITLE : Set edit mode to INSERT and           *
C  *                 manipulate element pointer            *
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
      INTEGER EDMOD, ELEPOS, ELPSOF, LABEL1,
     1        LABEL2, LABEL3, LABEL4, LABEL5, STRID

      PARAMETER (LABEL1 = 11, LABEL2 = 12, LABEL3 = 13, LABEL4 = 14,
     1           LABEL5 = 15, STRID = 35)

C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)

      LOGICAL STRCON

      CALL INITGL ('02.02.03/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  <open structure> with strid
      CALL POPST (STRID)

C  fill structure with elements:
      CALL PLB (LABEL1)
      CALL PLB (LABEL2)
      CALL PLB (LABEL3)
      CALL PLB (LABEL4)
      CALL PLB (LABEL5)

      CALL SETMSG ('5 11', '<Inquire edit mode> should return the '   //
     1             'current edit mode as the default edit mode '      //
     2             'INSERT.')
      CALL PQEDM (ERRIND, EDMOD)
      CALL IFPF  (ERRIND .EQ. 0   .AND.
     1            EDMOD  .EQ. PINSRT)

      ELEPOS = 2
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
      CALL SETMSG ('7', '<Set element pointer> should set the '       //
     1             'element pointer to an absolute position.')
      CALL CHKELP (ELEPOS)

      CALL PSEPLB (LABEL5)
      CALL SETMSG ('9', '<Set element pointer at label> should '      //
     1             'position the element pointer at the next '        //
     2             'occurrence of a specified label, when the '       //
     3             'current element is not that label.')
      CALL CHKELP (5)

      ELPSOF = -3
      CALL POSEP (ELPSOF)
      CALL SETMSG ('8', '<Offset element pointer> should offset the ' //
     1             'element pointer by a relative position.')
      CALL CHKELP (2)

C  <set edit mode> to REPLACE to nullify default
      CALL PSEDM (PREPLC)
C  <set edit mode> to INSERT
      CALL PSEDM (PINSRT)

      CALL SETMSG ('1 11', '<Inquire edit mode> should return the '   //
     1             'current edit mode as INSERT after an explicit '   //
     2             'setting.')
      CALL PQEDM (ERRIND, EDMOD)
      CALL IFPF  (ERRIND .EQ. 0   .AND.
     1            EDMOD  .EQ. PINSRT)

C  <label> with label4
      CALL PLB (LABEL4)

      CALL SETMSG ('2', 'When <set edit mode> is INSERT, new '        //
     1             'elements should be inserted after the element '   //
     2             'pointed to by the element pointer.')
      CALL IFPF (STRCON (STRID, '67,11,67,12,67,14,67,13,67,14,67,15'))

      CALL SETMSG ('4', 'When the edit mode is INSERT, the element '  //
     1             'pointer should be updated to point to the new '   //
     2             'element after insertion.')
      CALL CHKELP (3)

      ELEPOS = 10
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
      CALL SETMSG ('7 10', 'If <set element pointer> is used to '     //
     1             'position the element pointer to a position '      //
     2             'greater than the last element in the open '       //
     3             'structure, the element pointer should point to '  //
     4             'the last element.')
      CALL CHKELP (6)

      ELPSOF = 1
C  <offset element pointer> with elpsof
      CALL POSEP (ELPSOF)
      CALL SETMSG ('8 10', 'If <offset element pointer> is used to '  //
     1             'position the element pointer to a position '      //
     2             'greater than the last element in the open '       //
     3             'structure, the element pointer should point to '  //
     4             'the last element.')
      CALL CHKELP (6)

      ELEPOS = -3
C  <set element pointer> to elepos
      CALL PSEP (ELEPOS)
      CALL SETMSG ('7 10', 'If <set element pointer> is used to '     //
     1             'position the element pointer to a position less ' //
     2             'than zero, the element pointer should point to '  //
     3             'zero.')
      CALL CHKELP (0)

      ELPSOF = -1
C  <offset element pointer> with elpsof
      CALL POSEP (ELPSOF)
      CALL SETMSG ('8 10', 'If <offset element pointer> is used to '  //
     1             'position the element pointer to a position less ' //
     2             'than zero, the element pointer should point to '  //
     3             'zero.')
      CALL CHKELP (0)

      CALL PLB (LABEL5)
      CALL SETMSG ('6', 'If the element pointer is 0, then the new '  //
     1             'element should be inserted immediately before '   //
     2             'element 1.')
      CALL IFPF (STRCON (STRID,
     1           '67,15,67,11,67,12,67,14,67,13,67,14,67,15'))

      CALL SETMSG ('6', 'After an insertion of an element at the '    //
     1             'beginning of a structure, the element pointer '   //
     2             'should become 1 and point at the new element.')
      CALL CHKELP (1)

C  <set element pointer at label> with label5
      CALL PSEPLB (LABEL5)
      CALL SETMSG ('9', 'If the element pointer is already '          //
     1             'positioned at a label element, <set element '     //
     2             'pointer at label> should position the element '   //
     3             'pointer at the next occurence of a specified '    //
     4             'label element within the open structure.')
      CALL CHKELP (7)

777   CONTINUE
      CALL ENDIT
      END
