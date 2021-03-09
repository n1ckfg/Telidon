C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.01/01                           *
C  *    TEST TITLE : Inquire element type and size, and    *
C  *                 content when a structure is closed    *
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

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C element type
      INTEGER    PENIL,       PEPL,          PETX,
     1           PECHSP,      PECHUP,        PETXAL
      PARAMETER (PENIL  =  1, PEPL   =  3,   PETX   =  7,
     1           PECHSP = 32, PECHUP = 35,   PETXAL = 37 )

      INTEGER   RCNT, ARRLIM
      PARAMETER (ARRLIM = 50)

      CHARACTER STRAR(ARRLIM)*30

      INTEGER   STRID, ELTYPE, INTSZ, RLSZ, STRSZ
      INTEGER   LNSTR(ARRLIM), INTAR(ARRLIM)

      REAL XPTS(5), YPTS(5), RLAR(ARRLIM)
      DATA XPTS / .02, .05, .08, .11, .14/
      DATA YPTS / .17, .20, .23, .26, .29/

      CALL INITGL ('02.03.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

      STRID = 100
      CALL POPST (STRID)
      CALL PSCHUP (.24, .35)
      CALL PSTXAL (PALEFT, PAHALF)
      CALL PPL (5, XPTS, YPTS)
      CALL PSCHSP (.05)
      CALL PTX (.16, .2, 'PHIGS Validation Tests')
      CALL PCLST

      CALL SETMSG ('5', '<Inquire element type and size> should '     //
     1             'return NIL as the element type and 0 as the '     //
     2             'length of all array entry sizes when the '        //
     3             'specified element position of the closed '        //
     4             'structure is 0.')
      INTSZ = -6
      RLSZ  = -6
      STRSZ = -6
      CALL PQETS (STRID, 0, ERRIND, ELTYPE, INTSZ, RLSZ, STRSZ)
      CALL IFPF (ERRIND .EQ. 0        .AND.
     1           ELTYPE .EQ. PENIL    .AND.
     1           INTSZ  .EQ. 0        .AND.
     2           RLSZ   .EQ. 0        .AND.
     3           STRSZ  .EQ. 0)

      CALL SETMSG ('6', '<Inquire element content> should return 0 '  //
     1             'as the length of all arrays associated with the ' //
     2             'data record when the specified element position ' //
     3             'of the closed structure is 0.')

      INTSZ = -6
      RLSZ  = -6
      STRSZ = -6
      CALL PQECO (STRID, 0, ARRLIM, ARRLIM, ARRLIM, ERRIND,
     1            INTSZ, INTAR, RLSZ, RLAR, STRSZ, LNSTR, STRAR)
      CALL IFPF (ERRIND .EQ. 0   .AND.
     1           INTSZ  .EQ. 0   .AND.
     1           RLSZ   .EQ. 0   .AND.
     2           STRSZ  .EQ. 0)

      CALL SETMSG ('4', '<Inquire element type and size> should '     //
     1             'return polyline as the element type and an '      //
     2             'integer array entry size of 1, real array entry ' //
     3             'size of 10, and a string array entry size of 0 '  //
     4             'for the specified element of the closed '         //
     5             'structure.')

      STRSZ = -6
      CALL PQETS (STRID, 3, ERRIND, ELTYPE, INTSZ, RLSZ, STRSZ)
      CALL IFPF (ERRIND .EQ. 0        .AND.
     1           ELTYPE .EQ. PEPL     .AND.
     1           INTSZ  .EQ. 1        .AND.
     2           RLSZ   .EQ. 10       .AND.
     3           STRSZ  .EQ. 0)

      CALL SETMSG ('6', '<Inquire element content> should return '    //
     1             'the appropriate information contained in the '    //
     2             'data record associated with polyline, the '       //
     3             'specified element of the closed structure.')

      STRSZ = -6
      CALL PQECO (STRID, 3, ARRLIM, ARRLIM, ARRLIM, ERRIND,
     1            INTSZ, INTAR, RLSZ, RLAR, STRSZ, LNSTR, STRAR)
      IF (ERRIND   .EQ. 0    .AND.
     1    INTSZ    .EQ. 1    .AND.
     1    INTAR(1) .EQ. 5    .AND.
     2    RLSZ     .EQ. 10   .AND.
     3    STRSZ    .EQ. 0)      THEN
C OK so far - test array contents
         DO 100 RCNT = 1,10
            IF (RCNT .LE. 5) THEN
               IF (RLAR(RCNT) .NE. XPTS(RCNT)) GOTO 110
            ELSE
               IF (RLAR(RCNT) .NE. YPTS(RCNT-5)) GOTO 110
            ENDIF
100      CONTINUE
         CALL PASS
         GOTO 666
      ENDIF

110   CONTINUE
      CALL FAIL

666   CONTINUE
      CALL ENDIT
      END
