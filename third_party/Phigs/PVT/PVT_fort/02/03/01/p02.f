C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.01/02                           *
C  *    TEST TITLE : Inquire element type and size, and    *
C  *                 content when a structure is open      *
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
      INTEGER   ARRLIM
      PARAMETER (ARRLIM = 50)

      CHARACTER STRAR(ARRLIM)*30

      INTEGER   STRID, ELTYPE, INTSZ, RLSZ, STRSZ
      INTEGER   LNSTR(ARRLIM), INTAR(ARRLIM)

      REAL      RLAR(ARRLIM), TXX,TXY, CHVAL

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C element type
      INTEGER    PENIL,       PEPL,        PETX,
     8           PECHSP,      PETXCI,      PECHH,       PECHUP,
     9           PETXP,       PETXAL,      PEATCH,      PEATCU
      PARAMETER (PENIL  =  1, PEPL   =  3, PETX   =  7,
     8           PECHSP = 32, PETXCI = 33, PECHH  = 34, PECHUP = 35,
     9           PETXP  = 36, PETXAL = 37, PEATCH = 38, PEATCU = 39)

      CALL INITGL ('02.03.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

      STRID = 100
      CALL POPST (STRID)
      CALL PSCHUP (.24, .35)
      CALL PSTXAL (PALEFT, PAHALF)
      CHVAL = 0.4
      CALL PSCHH (CHVAL)
      CALL PSCHSP (.05)
      TXX = 0.16
      TXY = 0.2
      CALL PTX (TXX, TXY, 'PHIGS Validation Tests')
C
C  *** *** *** ***   specified element = text   *** *** *** ***
C

      CALL SETMSG ('1', '<Inquire current element type and size> '    //
     1             'should return text as the element type and an '   //
     2             'integer array entry size of 0, real array entry ' //
     3             'size of 2, and a string array entry size of 1 '   //
     4             'when the element pointer is positioned at the '   //
     5             'last element.')

      CALL PQCETS (ERRIND, ELTYPE, INTSZ, RLSZ, STRSZ)
      CALL IFPF (ERRIND .EQ. 0         .AND.
     1           ELTYPE .EQ. PETX      .AND.
     1           INTSZ  .EQ. 0         .AND.
     2           RLSZ   .EQ. 2         .AND.
     3           STRSZ  .EQ. 1)

      CALL SETMSG ('3', '<Inquire current element content> should '   //
     1             'return the appropriate information contained in ' //
     2             'the data record associated with text when the '   //
     3             'element pointer is positioned at the last '       //
     4             'element.')

C ensure garbage in strar prior to inquire
      STRAR(1) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'

      CALL PQCECO (ARRLIM, ARRLIM, ARRLIM, ERRIND,
     1             INTSZ, INTAR, RLSZ, RLAR, STRSZ, LNSTR, STRAR)
      CALL IFPF (ERRIND   .EQ. 0       .AND.
     1           INTSZ    .EQ. 0       .AND.
     1           RLSZ     .EQ. 2       .AND.
     2           RLAR(1)  .EQ. TXX     .AND.
     3           RLAR(2)  .EQ. TXY     .AND.
     4           STRSZ    .EQ. 1       .AND.
     5           LNSTR(1) .EQ. 22      .AND.
     6           STRAR(1) .EQ. 'PHIGS Validation Tests')

C  Make sure <inquire element type and size> is independent of
C  element pointer:
      CALL PSEP (3)

      CALL SETMSG ('4', '<Inquire element type and size> should '     //
     1             'return text as the element type and an integer '  //
     2             'array entry size of 0, real array entry size of ' //
     3             '2, and a string array entry size of 1 with text ' //
     4             'as the specified element of the open structure.')

      CALL PQETS (STRID, 5, ERRIND, ELTYPE, INTSZ, RLSZ, STRSZ)
      CALL IFPF (ERRIND .EQ. 0         .AND.
     1           ELTYPE .EQ. PETX      .AND.
     1           INTSZ  .EQ. 0         .AND.
     2           RLSZ   .EQ. 2         .AND.
     3           STRSZ  .EQ. 1)

      CALL SETMSG ('6', '<Inquire element content> should return '    //
     1             'the appropriate information contained in the '    //
     2             'data record associated with text as the '         //
     3             'specified element of the open structure.')

C ensure garbage in strar prior to inquire
      STRAR(1) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'

      CALL PQECO (STRID, 5, ARRLIM, ARRLIM, ARRLIM, ERRIND,
     1            INTSZ, INTAR, RLSZ, RLAR, STRSZ, LNSTR, STRAR)
      CALL IFPF (ERRIND   .EQ. 0       .AND.
     1           INTSZ    .EQ. 0       .AND.
     1           RLSZ     .EQ. 2       .AND.
     2           RLAR(1)  .EQ. TXX     .AND.
     3           RLAR(2)  .EQ. TXY     .AND.
     4           STRSZ    .EQ. 1       .AND.
     5           LNSTR(1) .EQ. 22      .AND.
     6           STRAR(1) .EQ. 'PHIGS Validation Tests')

C  *** *** *** *** specified element = character height *** *** *** ***

      CALL SETMSG ('1', '<Inquire current element type and size> '    //
     1             'should return character height as the element '   //
     2             'type and an integer array entry size of 0, real ' //
     3             'array entry size of 1, and a string array entry ' //
     4             'size of 0 when the element pointer indicates a '  //
     5             'character height element.')

      CALL PQCETS (ERRIND, ELTYPE, INTSZ, RLSZ, STRSZ)
      CALL IFPF (ERRIND  .EQ. 0          .AND.
     1           ELTYPE  .EQ. PECHH      .AND.
     1           INTSZ   .EQ. 0          .AND.
     2           RLSZ    .EQ. 1          .AND.
     3           STRSZ   .EQ. 0)

      CALL SETMSG ('3', '<Inquire current element content> should '   //
     1             'return the appropriate information contained in ' //
     2             'the data record associated with character '       //
     3             'height when indicated by the element pointer.')

      CALL PQCECO (ARRLIM, ARRLIM, ARRLIM, ERRIND,
     1             INTSZ, INTAR, RLSZ, RLAR, STRSZ, LNSTR, STRAR)
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           INTSZ   .EQ. 0      .AND.
     1           RLSZ    .EQ. 1      .AND.
     2           RLAR(1) .EQ. CHVAL  .AND.
     3           STRSZ   .EQ. 0)

C  Make sure <inquire element type and size> is independent of
C  element pointer:
      CALL PSEP (0)

      CALL SETMSG ('4', '<Inquire element type and size> should '     //
     1             'return character height as the element type and ' //
     2             'an integer array entry size of 0, real array '    //
     3             'entry size of 1, and a string array entry size '  //
     4             'of 0 with character height as the specified '     //
     5             'element of the open structure.')

      CALL PQETS (STRID, 3, ERRIND, ELTYPE, INTSZ, RLSZ, STRSZ)
      CALL IFPF (ERRIND .EQ. 0         .AND.
     1           ELTYPE .EQ. PECHH     .AND.
     1           INTSZ  .EQ. 0         .AND.
     2           RLSZ   .EQ. 1         .AND.
     3           STRSZ  .EQ. 0)

      CALL SETMSG ('6', '<Inquire element content> should return '    //
     1             'the appropriate information contained in the '    //
     2             'data record associated with character height '    //
     3             'as the specified element of the open structure.')

      CALL PQECO (STRID, 3, ARRLIM, ARRLIM, ARRLIM, ERRIND,
     1            INTSZ, INTAR, RLSZ, RLAR, STRSZ, LNSTR, STRAR)
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           INTSZ   .EQ. 0     .AND.
     1           RLSZ    .EQ. 1     .AND.
     2           RLAR(1) .EQ. CHVAL .AND.
     3           STRSZ   .EQ. 0)
C
C  *** *** *** ***   specified element = NIL   *** *** *** ***
C
      CALL SETMSG ('2', '<Inquire current element type and size> '    //
     1             'should return NIL as the element type and 0 as '  //
     2             'the length of all array entry sizes when the '    //
     3             'element pointer is 0.')

      INTSZ = -6
      RLSZ  = -6
      STRSZ = -6
      CALL PQCETS (ERRIND, ELTYPE, INTSZ, RLSZ, STRSZ)
      CALL IFPF (ERRIND  .EQ. 0        .AND.
     1           ELTYPE  .EQ. PENIL    .AND.
     1           INTSZ   .EQ. 0        .AND.
     2           RLSZ    .EQ. 0        .AND.
     3           STRSZ   .EQ. 0)

      CALL SETMSG ('3', '<Inquire current element content> should '   //
     1             'return 0 as the length of all array entry sizes ' //
     2             'associated with the data record when the '        //
     3             'element pointer is 0.')

      INTSZ = -6
      RLSZ  = -6
      STRSZ = -6
      CALL PQCECO (ARRLIM, ARRLIM, ARRLIM, ERRIND,
     1             INTSZ, INTAR, RLSZ, RLAR, STRSZ, LNSTR, STRAR)
      CALL IFPF (ERRIND .EQ. 0       .AND.
     1           INTSZ  .EQ. 0       .AND.
     1           RLSZ   .EQ. 0       .AND.
     2           STRSZ  .EQ. 0)

C  Make sure <inquire element type and size> is independent of
C  element pointer:
      CALL PSEP (77)

      CALL SETMSG ('5', '<Inquire element type and size> should '     //
     1             'return NIL as the element type and 0 as the '     //
     2             'length of all array entry sizes when the '        //
     3             'specified element position of the open '          //
     4             'structure is 0.')

      INTSZ = -6
      RLSZ  = -6
      STRSZ = -6
      CALL PQETS (STRID, 0, ERRIND, ELTYPE, INTSZ, RLSZ, STRSZ)
      CALL IFPF (ERRIND .EQ. 0       .AND.
     1           ELTYPE .EQ. PENIL   .AND.
     1           INTSZ  .EQ. 0       .AND.
     2           RLSZ   .EQ. 0       .AND.
     3           STRSZ  .EQ. 0)

      CALL SETMSG ('6', '<Inquire element content> should return 0 '  //
     1             'as the length of all arrays associated with the ' //
     2             'data record when the specified element position ' //
     3             'of the open structure is 0.')

      INTSZ = -6
      RLSZ  = -6
      STRSZ = -6
      CALL PQECO (STRID, 0, ARRLIM, ARRLIM, ARRLIM, ERRIND,
     1            INTSZ, INTAR, RLSZ, RLAR, STRSZ, LNSTR, STRAR)
      CALL IFPF (ERRIND .EQ. 0      .AND.
     1           INTSZ  .EQ. 0      .AND.
     1           RLSZ   .EQ. 0      .AND.
     2           STRSZ  .EQ. 0)

      CALL PCLST

666   CONTINUE
      CALL ENDIT
      END
