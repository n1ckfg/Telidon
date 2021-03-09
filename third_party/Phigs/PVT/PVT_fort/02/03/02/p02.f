C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.02/02                           *
C  *    TEST TITLE : Element search with varying types of  *
C  *                 structures                            *
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

      INTEGER ASFVAL, ATTRID, FONT, LABL1, N, PKID, ELEXC(68), ELINC(68)
      INTEGER STRIDC, STRIDE, STRIDO, STRIDX

      PARAMETER (STRIDE = 10, STRIDO = 20, STRIDC = 30)

      CHARACTER CHRSTR*70

      REAL CHARHT, XPOS,YPOS,ZPOS, XVAL(4),YVAL(4),ZVAL(4),
     1     XVEC(2),YVEC(2),ZVEC(2)

C  <polyline 3>, <polymarker 3> parameters:
      DATA XVAL / 0.0001, 99.99, -1.3E20, 1.3E13 /
      DATA YVAL / -99.99, 0.0,   .0015,   5.0 /
      DATA ZVAL /  .5E10, 1.2,   -5.0,    0.0 /

      CALL INITGL ('02.03.02/02')

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
 
C  create empty structure stride:
      CALL POPST (STRIDE)
      CALL PCLST
 
C  create closed structure stridc:
      CALL POPST (STRIDC)
      CALL PSPKID (PKID)
      CALL PLB (LABL1)
      CALL PEXST (STRIDX)
      CALL PSIASF (ATTRID, ASFVAL)
      CALL PSCHH (CHARHT)
      CALL PSTXFN (FONT)
      CALL PTX3 (XPOS, YPOS, ZPOS, XVEC, YVEC, ZVEC, CHRSTR)
      CALL PPM3 (N, XVAL, YVAL, ZVAL)
      CALL PPL3 (N, XVAL, YVAL, ZVAL)
      CALL PCLST
 
C  create open structure strido:
      CALL POPST (STRIDO)
      CALL PPL3 (N, XVAL, YVAL, ZVAL)
      CALL PPM3 (N, XVAL, YVAL, ZVAL)
      CALL PTX3 (XPOS, YPOS, ZPOS, XVEC, YVEC, ZVEC, CHRSTR)
      CALL PSTXFN (FONT)
      CALL PSCHH (CHARHT)
      CALL PSIASF (ATTRID, ASFVAL)
      CALL PEXST (STRIDX)
      CALL PLB (LABL1)
      CALL PSPKID (PKID)
C  strido left open
 
C  closed structure:
C  POSITION     CONTENTS
C  --------     --------                        
C     1         <set pick identifier>  with pkid
C     2         <label>                with labl1
C     3         <execute structure>    with stridx
C     4         <set individual asf>   with attrid, asfval
C     5         <set character height> with charht
C     6         <set text font>        with font
C     7         <text 3>               with xpos, ypos, zpox, xvec, yvec, zvec,
C                                           chrstr
C     8         <polymarker 3>         with n, xval, yval, zval
C     9         <polyline 3>           with n, xval, yval, zval

C  open structure:
C  POSITION     CONTENTS
C  --------     --------
C     1         <polyline 3>           with n, xval, yval, zval
C     2         <polymarker 3>         with n, xval, yval, zval
C     3         <text 3>               with xpos, ypos, zpos, xvec, yvec, zvec,
C                                           chrstr
C     4         <set text font>        with font
C     5         <set character height> with charht
C     6         <set individual asf>   with attrid, asfval
C     7         <execute structure>    with stridx
C     8         <label>                with labl1
C     9         <set pick identifier>  with pkid

      CALL SETMSG ('1 2 6 9', 'When using <element search> with an '  //
     1             'empty structure and searching for non-NIL '       //
     2             'elements, the search should be unsuccessful and ' //
     3             'the status indicator should return the value '    //
     4             'FAILURE.')

C  selpos = 0, dir = FORWARD
C  elinc = POLYLINE_3, SET_CHARACTER_HEIGHT, LABEL
C  elexc = POLYMARKER_3
      ELINC(1) = PEPL3
      ELINC(2) = PECHH
      ELINC(3) = PELB
      ELEXC(1) = PEPM3
      CALL TSTELS (STRIDE, 0, PFWD, 3, ELINC, 1, ELEXC, PFAIL, 7)

      CALL SETMSG ('1 2 3 4 5 7 8', 'When using <element search> '    //
     1             'with an empty structure and searching for a NIL ' //
     2             'element, the search should find the element at '  //
     3             'position #0.')

C  selpos = 93, dir = BACKWARD
C  elinc = ALL
C  elexc = POLYMARKER_3
      ELINC(1) = PEALL
      ELEXC(1) = PEPM3
      CALL TSTELS (STRIDE, 93, PBWD, 1, ELINC, 1, ELEXC, PSUCC, 0)

      CALL SETMSG ('1 2 3 6 8', 'When using <element search> with '   //
     1             'an open structure, an element should qualify '    //
     2             'for selection if and only if its type belongs '   //
     3             'to the inclusion set and does not belong to the ' //
     4             'exclusion set.')

C  selpos = 0, dir = FORWARD
C  elinc = POLYMARKER_3, SET_TEXT_FONT, LABEL, SET_PICK_IDENTIFIER
C  elexc = POLYMARKER_3, SET_TEXT_FONT, EXECUTE_STRUCTURE
      ELINC(1) = PEPM3
      ELINC(2) = PETXFN
      ELINC(3) = PELB
      ELINC(4) = PEPKID
      ELEXC(1) = PEPM3
      ELEXC(2) = PEEXST
      ELEXC(3) = PETXFN
      CALL TSTELS (STRIDO, 0, PFWD, 4, ELINC, 3, ELEXC, PSUCC, 8)

      CALL SETMSG ('1 2 3 6 8', 'When using <element search> with a ' //
     1             'closed structure, an element should qualify for ' //
     2             'selection if and only if its type belongs to '    //
     3             'the inclusion set and does not belong to the '    //
     4             'exclusion set.')

C  selpos = 9
C  dir = BACKWARD
C  elinc = POLYLINE_3, TEXT_3, POLYMARKER_3
C  elexc = POLYLINE_3, POLYMARKER_3
      ELINC(1) = PEPM3
      ELINC(2) = PETX3
      ELINC(3) = PEPL3
      ELEXC(1) = PEPL3
      ELEXC(2) = PEPM3
      CALL TSTELS (STRIDC, 9, PBWD, 3, ELINC, 2, ELEXC, PSUCC, 7)
              
666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
