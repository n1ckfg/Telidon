C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.02/01                           *
C  *    TEST TITLE : Element search within a single closed *
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

C search success
      INTEGER    PFAIL,     PSUCC
      PARAMETER (PFAIL = 0, PSUCC = 1) 
C search direction
      INTEGER    PBWD,     PFWD
      PARAMETER (PBWD = 0, PFWD = 1) 
C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1) 
C attribute identifier
      INTEGER    PLN
      PARAMETER (PLN  = 0)
 
C element type
      INTEGER    PEALL,       PENIL,       PEPL3,       PEPL
      PARAMETER (PEALL  =  0, PENIL  =  1, PEPL3  =  2, PEPL   =  3)
      INTEGER    PEPM3,       PEPM,        PETX3,       PETX
      PARAMETER (PEPM3  =  4, PEPM   =  5, PETX3  =  6, PETX   =  7)
      INTEGER    PEPMCI,      PETXFN,      PETXPR,      PECHXP
      PARAMETER (PEPMCI = 28, PETXFN = 29, PETXPR = 30, PECHXP = 31)
      INTEGER    PECHSP,      PETXCI,      PECHH,       PECHUP
      PARAMETER (PECHSP = 32, PETXCI = 33, PECHH  = 34, PECHUP = 35)
      INTEGER    PERMCV,      PEVWI,       PEEXST,      PELB        
      PARAMETER (PERMCV = 64, PEVWI  = 65, PEEXST = 66, PELB   = 67)
      INTEGER    PEAP,        PEGSE,       PEPKID
      PARAMETER (PEAP   = 68, PEGSE  = 69, PEPKID = 70)

      INTEGER    ASFVAL, ATTRID, FONT, LABL1, N, PKID, STRID, STRIDX
      INTEGER    ELEXC(68), ELINC(68)
      PARAMETER (STRID = 40)

      REAL      CHARHT, XPOS, YPOS, ZPOS, XVAL(4), YVAL(4), ZVAL(4)
      REAL      XVEC(2), YVEC(2), ZVEC(2)
                      
      CHARACTER CHRSTR*70
 
C  <polyline 3>, <polymarker 3> parameters:
      DATA XVAL / 0.0001, 99.99, -1.3E20, 1.3E13 /
      DATA YVAL / -99.99, 0.0,   .0015,   5.0 /
      DATA ZVAL /  .5E10, 1.2,   -5.0,    0.0 /

      CALL INITGL ('02.03.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  <polyline 3>, <polymarker 3> parameters:
      N = 4
 
C  <text 3> parameters:
      XPOS = 0.0001
      YPOS = -99.99
      ZPOS = .5E10
      XVEC(1) = 1.0
      XVEC(2) = .3
      YVEC(1) = 2.5
      YVEC(2) = -1.6E13
      ZVEC(1) = 0.003
      ZVEC(2) = 999.0
      CHRSTR = 'This is a TEXT_3 character string for <element search>.'
 
C  <set text font> parameters:
      FONT = -2
 
C  <set character height> parameters:
      CHARHT = .5
 
C  <set individual asf> parameters:
      ATTRID = PLN
      ASFVAL = PBUNDL
 
C  <execute structure> parameters:
      STRIDX = 30
 
C  <label> parameters:
      LABL1 = 1
 
C  <set pick identifier> parameters:
      PKID = 5

C  POSITION     CONTENTS
C  --------     --------
C     1         <polyline 3>           with n, xval, yval, zval
C     2         <polymarker 3>         with n, xval, yval, zval
C     3         <text 3>               with xpos,ypos,zpos, xvec,yvec,zvec,
C                                           chrstr
C     4         <set text font>        with font
C     5         <set character height> with charht
C     6         <set individual asf>   with attrid, asfval
C     7         <execute structure>    with stridx
C     8         <label>                with labl1
C     9         <set pick identifier>  with pkid

C  create structure strid:
       CALL POPST (STRID)
       CALL PPL3 (N, XVAL, YVAL, ZVAL)
       CALL PPM3 (N, XVAL, YVAL, ZVAL)
       CALL PTX3 (XPOS, YPOS, ZPOS, XVEC, YVEC, ZVEC, CHRSTR)
       CALL PSTXFN (FONT)
       CALL PSCHH (CHARHT)
       CALL PSIASF (ATTRID, ASFVAL)
       CALL PEXST (STRIDX)
       CALL PLB (LABL1)
       CALL PSPKID (PKID)
       CALL PCLST

      CALL SETMSG ('1 2 3 6 8', '<Element search> should find the '   //
     1             'next matching element in the structure '          //
     2             'identified when searching FORWARD, and when the ' //
     3             'start element position is at the beginning of '   //
     4             'the structure.')

C  selpos = 0, dir = FORWARD
C  elinc = EXECUTE_STRUCTURE, LABEL
C  elexc = POLYLINE_3, POLYMARKER_3, TEXT_3
      ELINC(1) = PEEXST
      ELINC(2) = PELB
      ELEXC(1) = PEPL3
      ELEXC(2) = PEPM3
      ELEXC(3) = PETX3
      CALL TSTELS (STRID, 0, PFWD, 2, ELINC, 3, ELEXC, PSUCC, 7)

      CALL SETMSG ('1 2 3 6 8', '<Element search> should find the '  //
     1             'next matching element in the structure '         //
     2             'identified when searching BACKWARD, and when '   //
     3             'the start element position is at the middle of ' //
     4             'the structure.')

C  selpos = 5, dir = BACKWARD              
C  elinc = TEXT_3, POLYMARKER_3
C  elexc = SET_TEXT_FONT, SET_CHARACTER_HEIGHT
      ELINC(1) = PETX3
      ELINC(2) = PEPM3
      ELEXC(1) = PETXFN
      ELEXC(2) = PECHH
      CALL TSTELS (STRID, 5, PBWD, 2, ELINC, 2, ELEXC, PSUCC, 3)

      CALL SETMSG ('1 2 3 8', '<Element search> should find the '     //
     1             'next matching element in the structure '          //
     2             'identified when searching BACKWARD, and when '    //
     3             'the start element position is at the end of the ' //
     4             'structure.')

C  selpos = 9, dir = BACKWARD
C  elinc = SET_TEXT_FONT      
C  elexc = SET_PICK_IDENTIFIER
      ELINC(1) = PETXFN
      ELEXC(1) = PEPKID
      CALL TSTELS (STRID, 9, PBWD, 1, ELINC, 1, ELEXC, PSUCC, 4)

      CALL SETMSG ('1 2 3 4 8', '<Element search> should find the '   //
     1             'next matching element in the structure '          //
     2             'identified when searching forward, and when the ' //
     3             'start element position is on the sought element.')
C  selpos = 8, dir = FORWARD
C  elinc = LABEL, EXECUTE_STRUCTURE, SET_PICK_ID
C  elexc = NIL
      ELINC(1) = PELB
      ELINC(2) = PEEXST
      ELINC(3) = PEPKID
      ELEXC(1) = PENIL
      CALL TSTELS (STRID, 8, PFWD, 3, ELINC, 1, ELEXC, PSUCC, 8)

      CALL SETMSG ('1 2 3 4 7 8', 'When using <element search>, if ' //
     1             'the start element position is less than 0, the ' //
     2             'search should begin at element 0.')

C  selpos = -5, dir = FORWARD
C  elinc = POLYLINE_3, POLYMARKER_3
C  elexc = NIL
      ELINC(1) = PEPL3
      ELINC(2) = PEPM3
      ELEXC(1) = PENIL
      CALL TSTELS (STRID, -5, PFWD, 2, ELINC, 1, ELEXC, PSUCC, 1)

      CALL SETMSG ('1 2 3 4 7 8', 'When using <element search>, if '  //
     1             'the start element position is greater than the '  //
     2             'number of elements in the structure, the search ' //
     3             'should begin at the last element in the '         //
     4             'structure.')
C  selpos = 15, dir = BACKWARD
C  elinc = SET_PICK_IDENTIFIER, LABEL
C  elexc = NIL
      ELINC(1) = PEPKID
      ELINC(2) = PELB
      ELEXC(1) = PENIL
      CALL TSTELS (STRID, 15, PBWD, 2, ELINC, 1, ELEXC, PSUCC, 9)

      CALL SETMSG ('1 2 3 5 7 8', 'When using <element search> and '  //
     1             'searching BACKWARD, if the start element '        //
     2             'position is less than 0 the search should begin ' //
     3             'at element position 0.')

C  selpos = -5, dir = BACKWARD
C  elinc = POLYLINE_3, NIL
C  elexc = TEXT_3
      ELINC(1) = PEPL3
      ELINC(2) = PENIL
      ELEXC(1) = PETX3
      CALL TSTELS (STRID, -5, PBWD, 2, ELINC, 1, ELEXC, PSUCC, 0)

      CALL SETMSG ('1 2 3 7 9', 'When using <element search> and '    //
     1             'searching FORWARD, if the start element '         //
     2             'position is greater than the number of elements ' //
     3             'in the structure the search should examine only ' //
     4             'the last element.')

C  selpos = 15, dir = FORWARD
C  elinc = SET_PICK_IDENTIFIER, LABEL, POLYLINE_3
C  elexc = EXECUTE_STRUCTURE
      ELINC(1) = PEPKID
      ELINC(2) = PELB
      ELINC(3) = PEPL3
      ELEXC(1) = PEEXST
      CALL TSTELS (STRID, 15, PFWD, 3, ELINC, 1, ELEXC, PSUCC, 9)

      CALL SETMSG ('1 2 3 4 8', 'When using <element search>, the ' //
     1             'element type ALL in the inclusion set should '  //
     2             'designate all possible element types.')

C  selpos = 0, dir = FORWARD
C  elinc = ALL
C  elexc = POLYLINE_3, NIL
      ELINC(1) = PEALL
      ELEXC(1) = PEPL3
      ELEXC(2) = PENIL
      CALL TSTELS (STRID, 0, PFWD, 1, ELINC, 2, ELEXC, PSUCC, 2)

      CALL SETMSG ('1 2 3 4 9', 'When using <element search>, the ' //
     1             'element type NIL in the inclusion set should '  //
     2             'designate the type of the virtual element in '  //
     3             'position #0.')

C  selpos = 9, dir = BACKWARD
C  elinc = NIL       
C  elexc = POLYLINE_3
      ELINC(1) = PENIL
      ELEXC(1) = PEPL3
      CALL TSTELS (STRID, 9, PBWD, 1, ELINC, 1, ELEXC, PSUCC, 0)

      CALL SETMSG ('1 2 3 6 9', 'When using <element search>, an '    //
     1             'empty inclusion set should designate no element ' //
     2             'type.')

C  selpos = 9, dir = BACKWARD
C  elinc = empty
C  elexc = POLYLINE_3
      ELEXC(1) = PEPL3
      CALL TSTELS (STRID, 9, PBWD, 0, ELINC, 1, ELEXC, PFAIL, 7)

      CALL SETMSG ('1 2 3 4 6 9', 'When using <element search>, the ' //
     1             'element type ALL in the exclusion set should '    //
     2             'designate all element types.')

C  selpos = 0, dir = FORWARD
C  elinc = POLYLINE_3, TEXT_3
C  elexc = ALL
      ELINC(1) = PEPL3
      ELINC(2) = PETX3
      ELEXC(1) = PEALL
      CALL TSTELS (STRID, 0, PFWD, 2, ELINC, 1, ELEXC, PFAIL, 7)

      CALL SETMSG ('1 2 3 6 8', 'When using <element search>, an '    //
     1             'empty exclusion set should designate no element ' //
     2             'type.')

C  selpos = 9, dir = BACKWARD
C  elinc = ALL
C  elexc = empty
      ELINC(1) = PEALL
      CALL TSTELS (STRID, 9, PBWD, 1, ELINC, 0, ELEXC, PSUCC, 9)

      CALL SETMSG ('1 2 3 9', 'When using <element search>, an '      //
     1             'empty inclusion and exclusion set should result ' //
     2             'in no elements being found.')

C  selpos = 2, dir = FORWARD
C  elinc = empty
C  elexc = empty
      CALL TSTELS (STRID, 2, PFWD, 0, ELINC, 0, ELEXC, PFAIL, 7)

      CALL SETMSG ('1 2 3 9', 'When using <element search>, if an '   //
     1             'element type is specified in both the exclusion ' //
     2             'set and inclusion set, it should be excluded.')

C  selpos = 0, dir = FORWARD
C  elinc = LABEL
C  elexc = LABEL
      ELINC(1) = PELB
      ELEXC(1) = PELB
      CALL TSTELS (STRID, 0, PFWD, 1, ELINC, 1, ELEXC, PFAIL, 7)

      CALL SETMSG ('1 2 3 4 9', 'When using <element search>, if an ' //
     1             'element type is not specified in the exclusion '  //
     2             'set nor the inclusion set, it should be '         //
     3             'excluded.')

C  selpos = 1, dir = FORWARD
C  elinc = NIL
C  elexc = NIL
      ELINC(1) = PENIL
      ELEXC(1) = PENIL
      CALL TSTELS (STRID, 1, PFWD, 1, ELINC, 1, ELEXC, PFAIL, 7)

      CALL SETMSG ('1 2 3 6 8', 'When using <element search>, an '  //
     1             'element should qualify for selection if and '   //
     2             'only if its type belongs to the inclusion set ' //
     3             'and does not belong to the exclusion set.')

C  selpos = 0, dir = FORWARD
C  elinc = POLYLINE_3, TEXT_3, LABEL, SET_PICK_IDENTIFIER
C  elexc = POLYLINE_3, TEXT_3, EXECUTE_STRUCTURE
      ELINC(1) = PEPL3
      ELINC(2) = PETX3
      ELINC(3) = PELB
      ELINC(4) = PEPKID
      ELEXC(1) = PEPL3
      ELEXC(2) = PETX3
      ELEXC(3) = PEEXST
      CALL TSTELS (STRID, 0, PFWD, 4, ELINC, 3, ELEXC, PSUCC, 8)

      CALL SETMSG ('1 2 3 4 6 8', '<Element search> should take the ' //
     1             'union of the element type ALL and other element ' //
     2             'types in the inclusion set.')

C  selpos = 0, dir = FORWARD
C  elinc = SET_TEXT_FONT, POLYLINE_3, ALL
C  elexc = NIL
      ELINC(1) = PETXFN
      ELINC(2) = PEPL3
      ELINC(3) = PEALL
      ELEXC(1) = PENIL
      CALL TSTELS (STRID, 0, PFWD, 3, ELINC, 1, ELEXC, PSUCC, 1)

      CALL SETMSG ('1 2 3 4 6 8', '<Element search> should take the ' //
     1             'union of the element type NIL and other element ' //
     2             'types in the inclusion set.')

C  selpos = 0, dir = FORWARD
C  elinc = SET_TEXT_FONT, POLYMARKER_3, NIL
C  elexc = POLYMARKER_3
      ELINC(1) = PETXFN
      ELINC(2) = PEPM3
      ELINC(3) = PENIL
      ELEXC(1) = PEPM3
      CALL TSTELS (STRID, 0, PFWD, 3, ELINC, 1, ELEXC, PSUCC, 0)

      CALL SETMSG ('1 2 3 4 6 9', '<Element search> should take the ' //
     1             'union of the element type ALL and other element ' //
     2             'types in the exclusion set.')

C  selpos = 9, dir = BACKWARD
C  elinc = POLYLINE_3, POLYMARKER_3, TEXT_3
C  elexc = SET_TEXT_FONT, EXECUTE_STRUCTURE, ALL
      ELINC(1) = PEPL3
      ELINC(2) = PEPM3
      ELINC(3) = PETX3
      ELEXC(1) = PETXFN
      ELEXC(2) = PEEXST
      ELEXC(3) = PEALL
      CALL TSTELS (STRID, 9, PBWD, 3, ELINC, 3, ELEXC, PFAIL, 7)

      CALL SETMSG ('1 2 3 4 6 8', '<Element search> should take the ' //
     1             'union of the element type NIL and other element ' //
     2             'types in the exclusion set.')

C  selpos = 9, dir = BACKWARD
C  elinc = POLYLINE_3, POLYMARKER_3, TEXT_3
C  elexc = POLYLINE_3, TEXT_3, NIL
      ELINC(1) = PEPL3
      ELINC(2) = PEPM3
      ELINC(3) = PETX3
      ELEXC(1) = PETX3
      ELEXC(2) = PENIL
      ELEXC(3) = PEPL3
      CALL TSTELS (STRID, 9, PBWD, 3, ELINC, 3, ELEXC, PSUCC, 2)

      CALL SETMSG ('1 2 3 4 6 8', '<Element search> should take the ' //
     1             'union of the element types ALL and NIL in the '   //
     2             'inclusion set.')

C  selpos = 0, dir = FORWARD
C  elinc = ALL, NIL
C  elexc = empty
      ELINC(1) = PEALL
      ELINC(2) = PENIL
      CALL TSTELS (STRID, 0, PFWD, 2, ELINC, 0, ELEXC, PSUCC, 0)

      CALL SETMSG ('1 2 3 4 6 9', '<Element search> should take the ' //
     1             'union of the element types ALL and NIL in the '   //
     2             'exclusion set.')

C  selpos = 9, dir = BACKWARD
C  elinc = SET_PICK_IDENTIFIER, LABEL, EXECUTE_STRUCTURE
C  elexc = ALL, NIL
      ELINC(1) = PEPKID
      ELINC(2) = PELB
      ELINC(3) = PEEXST
      ELEXC(1) = PEALL
      ELEXC(2) = PENIL
      CALL TSTELS (STRID, 9, PBWD, 3, ELINC, 2, ELEXC, PFAIL, 7)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
