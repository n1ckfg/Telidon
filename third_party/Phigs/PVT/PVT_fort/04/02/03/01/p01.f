C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.01/01                        *
C  *    TEST TITLE : Element creation and inquiring        *
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

C element type
      INTEGER    PEPMCI,      PETXFN,      PETXPR,      PECHXP
      PARAMETER (PEPMCI = 28, PETXFN = 29, PETXPR = 30, PECHXP = 31)

      INTEGER    PECHSP,      PETXCI,      PECHH,       PECHUP
      PARAMETER (PECHSP = 32, PETXCI = 33, PECHH  = 34, PECHUP = 35)

      INTEGER    PETXP,       PETXAL,      PEATCH,      PEATCU
      PARAMETER (PETXP  = 36, PETXAL = 37, PEATCH = 38, PEATCU = 39)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    INLEN, RELEN, STLEN
      PARAMETER  (INLEN=50, RELEN=50, STLEN=50)

C PHIGS parameter types
      INTEGER    ELTYPE, INTLEN, INTG, RLLEN, RL, STRLEN, STR, STRID
      INTEGER    INTAR(INLEN), STRARL(STLEN)
      REAL       RLAR(RELEN), TXATR1,TXATR2
      CHARACTER  STRAR(STLEN), MSG*200

      INTEGER TXPREC, TXPATH, TXHOR, TXVER

      CALL INITGL ('04.02.03.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C structure identifier = 1
      STRID = 1
C open structure
      CALL POPST (STRID)

C *** *** *** *** ***    Text font   *** *** *** *** ***
C set value for attribute
      CALL PSTXFN (33)

      CALL SETMSG ('9 12', '<Inquire current element type and size> ' //
     1             'should return text font as the type of the '      //
     2             'created element and the appropriate element '     //
     3             'size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 29 is the PHIGS enumeration type for petxfn
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PETXFN .AND.
     2           INTLEN  .EQ. 1      .AND.
     3           RLLEN   .EQ. 0      .AND.
     4           STRLEN  .EQ. 0)

C checking correct output parameters for data record type petxfn
      CALL SETMSG ('10 12', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'the text font value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
      CALL IFPF (ERRIND      .EQ. 0  .AND.
     1           INTAR(1)    .EQ. 33 .AND.
     2           INTG        .EQ. 1  .AND.
     3           RL          .EQ. 0  .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***    Text precision   *** *** *** *** ***
C set value for attribute
      CALL PSTXPR (PSTRKP)

      CALL SETMSG ('9 25', '<Inquire current element type and size> ' //
     1             'should return text precision as the type of the ' //
     2             'created element and the appropriate element '     //
     3             'size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
C 30 is the PHIGS enumeration type for petxpr
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PETXPR .AND.
     2           INTLEN  .EQ. 1      .AND.
     3           RLLEN   .EQ. 0      .AND.
     4           STRLEN  .EQ. 0)

C checking correct output parameters for data record type petxpr
      CALL SETMSG ('10 25 26', '<Inquire current element content> ' //
     1             'should return the standard representation for ' //
     2             'all valid text precision values.')
      DO 100 TXPREC = PSTRP, PSTRKP
         CALL PSTXPR (TXPREC)
         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND      .EQ. 0       .AND.
     1       INTAR(1)    .EQ. TXPREC  .AND.
     2       INTG        .EQ. 1       .AND.
     3       RL          .EQ. 0       .AND.
     4       STR         .EQ. 0) THEN
C            OK so far
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I2,A)') 'Failure for text precision = ',
     1             TXPREC, '.'
            CALL INMSG (MSG)
            GOTO 110
         ENDIF

100   CONTINUE
      CALL PASS

110   CONTINUE

C *** *** *** *** ***    Character expansion   *** *** *** *** ***
C set value for attribute
      TXATR1 = 0.40
      CALL PSCHXP (TXATR1)

      CALL SETMSG ('9 34', '<Inquire current element type and size> ' //
     1             'should return character expansion as the type '   //
     2             'of the created element and the appropriate '      //
     3             'element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
C 31 is the PHIGS enumeration type for pechxp
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PECHXP .AND.
     2           INTLEN  .EQ. 0      .AND.
     3           RLLEN   .EQ. 1      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('10 34', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'the character expansion value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pechxp
      CALL IFPF (ERRIND      .EQ. 0       .AND.
     1           RLAR(1)     .EQ. TXATR1  .AND.
     2           INTG        .EQ. 0       .AND.
     3           RL          .EQ. 1       .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***    Character spacing  *** *** *** *** ***
C set value for attribute
      TXATR1 = 0.25
      CALL PSCHSP (TXATR1)

      CALL SETMSG ('9 40', '<Inquire current element type and size> ' //
     1             'should return character spacing as the type of '  //
     2             'the created element and the appropriate element ' //
     3             'size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
C 32 is the PHIGS enumeration type for pechsp
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PECHSP .AND.
     2           INTLEN  .EQ. 0      .AND.
     3           RLLEN   .EQ. 1      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('10 40', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'the character spacing value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pechsp
      CALL IFPF (ERRIND      .EQ. 0       .AND.
     1           RLAR(1)     .EQ. TXATR1  .AND.
     2           INTG        .EQ. 0       .AND.
     3           RL          .EQ. 1       .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***    Text colour index  *** *** *** *** ***
C set value for attribute
      CALL PSTXCI (2)

      CALL SETMSG ('9 46', '<Inquire current element type and size> ' //
     1             'should return text colour index as the type of '  //
     2             'the created element and the appropriate element ' //
     3             'size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
C 33 is the PHIGS enumeration type for petxci
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PETXCI .AND.
     2           INTLEN  .EQ. 1      .AND.
     3           RLLEN   .EQ. 0      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('10 46', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'the text colour index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

C checking correct output parameters for data record type petxci
      CALL IFPF (ERRIND      .EQ. 0       .AND.
     1           INTAR(1)    .EQ. 2       .AND.
     2           INTG        .EQ. 1       .AND.
     3           RL          .EQ. 0       .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***    Character height  *** *** *** *** ***
C set value for attribute
      TXATR1 = 0.35
      CALL PSCHH (TXATR1)

      CALL SETMSG ('9 52', '<Inquire current element type and size> ' //
     1             'should return character height as the type of '   //
     2             'the created element and the appropriate element ' //
     3             'size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
C 34 is the PHIGS enumeration type for pechh
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. PECHH .AND.
     2           INTLEN  .EQ. 0     .AND.
     3           RLLEN   .EQ. 1     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('10 52', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'the character height value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

C checking correct output parameters for data record type pechh
      CALL IFPF (ERRIND      .EQ. 0       .AND.
     1           RLAR(1)     .EQ. TXATR1  .AND.
     2           INTG        .EQ. 0       .AND.
     3           RL          .EQ. 1       .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***    Character up vector  *** *** *** *** ***
C set value for attribute
      TXATR1 = 0.25
      TXATR2 = 0.13
      CALL PSCHUP (TXATR1, TXATR2)

      CALL SETMSG ('9 79', '<Inquire current element type and size> ' //
     1             'should return character up vector as the type '   //
     2             'of the created element and the appropriate '      //
     3             'element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
C 35 is the PHIGS enumeration type for pechup
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PECHUP .AND.
     2           INTLEN  .EQ. 0      .AND.
     3           RLLEN   .EQ. 2      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('10 79', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'the character up vector value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

C checking correct output parameters for data record type pechup
      CALL IFPF (ERRIND      .EQ. 0       .AND.
     1           RLAR(1)     .EQ. TXATR1  .AND.
     2           RLAR(2)     .EQ. TXATR2  .AND.
     3           INTG        .EQ. 0       .AND.
     4           RL          .EQ. 2       .AND.
     5           STR         .EQ. 0)

C *** *** *** *** ***    Text path  *** *** *** *** ***
C set value for attribute
      CALL PSTXP (PLEFT)

      CALL SETMSG ('9 64', '<Inquire current element type and size> ' //
     1             'should return text path as the type of the '      //
     2             'created element and the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
C 36 is the PHIGS enumeration type for petxp
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. PETXP .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('10 64 65', '<Inquire current element content> ' //
     1             'should return the standard representation for ' //
     2             'all valid text path values.')

      DO 200 TXPATH = PRIGHT, PDOWN
         CALL PSTXP (TXPATH)
         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND      .EQ. 0       .AND.
     1       INTAR(1)    .EQ. TXPATH  .AND.
     2       INTG        .EQ. 1       .AND.
     3       RL          .EQ. 0       .AND.
     4       STR         .EQ. 0) THEN
C            OK so far
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I2,A)') 'Failure for text path = ',
     1             TXPATH, '.'
            CALL INMSG (MSG)
            GOTO 210
         ENDIF

200   CONTINUE
      CALL PASS

210   CONTINUE

C *** *** *** *** ***    Text alignment    *** *** *** *** ***
C set value for attribute
      CALL PSTXAL (PACENT,PABASE)

      CALL SETMSG ('9 72', '<Inquire current element type and size> ' //
     1             'should return text alignment as the type of the ' //
     2             'created element and the appropriate element '     //
     3             'size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
C 37 is the PHIGS enumeration type for petxal
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PETXAL .AND.
     2           INTLEN  .EQ. 2      .AND.
     3           RLLEN   .EQ. 0      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('10 72 73', '<Inquire current element content> ' //
     1             'should return the standard representation for ' //
     2             'all valid text alignment values.')

      DO 300 TXHOR = PAHNOR, PARITE
      DO 305 TXVER = PAVNOR, PABOTT
         CALL PSTXAL (TXHOR, TXVER)
         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND      .EQ. 0       .AND.
     1       INTG        .EQ. 2       .AND.
     2       INTAR(1)    .EQ. TXHOR   .AND.
     3       INTAR(2)    .EQ. TXVER   .AND.
     4       RL          .EQ. 0       .AND.
     5       STR         .EQ. 0) THEN
C            OK so far
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I2,A,I2,A)') 'Failure for text horiz = ',
     1                          TXHOR, ', text vert = ', TXVER, '.'
            CALL INMSG (MSG)
            GOTO 310
         ENDIF

305   CONTINUE
300   CONTINUE
      CALL PASS

310   CONTINUE

      CALL ENDIT
      END
