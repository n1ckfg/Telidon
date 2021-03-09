C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/01                        *
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

      INTEGER    PETXP,       PETXAL,      PEATCH,      PEATCU
      PARAMETER (PETXP  = 36, PETXAL = 37, PEATCH = 38, PEATCU = 39)

      INTEGER    PEATP,       PEATAL,      PEANST,      PEIS
      PARAMETER (PEATP  = 40, PEATAL = 41, PEANST = 42, PEIS   = 43)

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

C PHIGS parameter types
      INTEGER     INLEN,    RELEN,    STLEN
      PARAMETER  (INLEN=50, RELEN=50, STLEN=50)

      INTEGER    ELTYPE, INTLEN, INTG, RLLEN, RL, STRLEN, STR, STRID
      INTEGER    INTAR(INLEN), STRARL(STLEN)
      INTEGER    TXPATH, TXHOR, TXVER

      REAL       RLAR(RELEN), TXATR1,TXATR2

      CHARACTER  STRAR(STLEN), MSG*200

      CALL INITGL ('04.02.04.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C structure identifier = 101
      STRID = 101
C open structure
      CALL POPST (STRID)

C  *** ***   Annotation text character height   *** ***
C set value for attribute
      TXATR1 = 2.35
      CALL PSATCH (TXATR1)

      CALL SETMSG ('3 42', '<Inquire current element type and size> ' //
     1             'should return annotation text character height '  //
     2             'as the type of the created element and the '      //
     3             'appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PEATCH .AND.
     2           INTLEN  .EQ. 0      .AND.
     3           RLLEN   .EQ. 1      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('4 42', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the annotation text character height value.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

C checking correct output parameters for data record type pechh
      CALL IFPF (ERRIND      .EQ. 0       .AND.
     1           RLAR(1)     .EQ. TXATR1  .AND.
     2           INTG        .EQ. 0       .AND.
     3           RL          .EQ. 1       .AND.
     4           STR         .EQ. 0)

C  *** ***   Annotation text character up vector   *** ***

C set value for attribute
      TXATR1 = -4.25
      TXATR2 = -5.13
      CALL PSATCU (TXATR1, TXATR2)

      CALL SETMSG ('3 70', '<Inquire current element type and size> ' //
     1             'should return annotation text character up '      //
     2             'vector as the type of the created element and '   //
     3             'the appropriate element size.')

      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PEATCU .AND.
     2           INTLEN  .EQ. 0      .AND.
     3           RLLEN   .EQ. 2      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('4 70', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the annotation text character up vector value.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)

C checking correct output parameters for data record type pechup
      CALL IFPF (ERRIND      .EQ. 0       .AND.
     1           RLAR(1)     .EQ. TXATR1  .AND.
     2           RLAR(2)     .EQ. TXATR2  .AND.
     3           INTG        .EQ. 0       .AND.
     4           RL          .EQ. 2       .AND.
     5           STR         .EQ. 0)

C  *** *** ***   Annotation text path   *** *** ***

C set value for attribute
      CALL PSATP (PLEFT)

      CALL SETMSG ('3 55', '<Inquire current element type and size> ' //
     1             'should return annotation text path as the type '  //
     2             'of the created element and the appropriate '      //
     3             'element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. PEATP .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('4 55 56', '<Inquire current element content> '  //
     1             'should return the standard representation for ' //
     2             'all valid annotation text path values.')

      DO 200 TXPATH = PRIGHT, PDOWN
         CALL PSATP (TXPATH)
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

C  donepath:
210   CONTINUE

C  *** *** ***   Annotation text alignment   *** *** ***

C set value for attribute
      CALL PSATAL (PACENT,PABASE)

      CALL SETMSG ('3 63', '<Inquire current element type and size> ' //
     1             'should return annotation text alignment as the '  //
     2             'type of the created element and the appropriate ' //
     3             'element size.')

      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)

C checking correct element type
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PEATAL .AND.
     2           INTLEN  .EQ. 2      .AND.
     3           RLLEN   .EQ. 0      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('4 63 64', '<Inquire current element content> '  //
     1             'should return the standard representation for ' //
     2             'all valid annotation text alignment values.')

      DO 300 TXHOR = PAHNOR, PARITE
      DO 305 TXVER = PAVNOR, PABOTT
         CALL PSATAL (TXHOR, TXVER)
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

C  *** *** ***   Annotation style   *** *** ***

C set value for attribute
      CALL PSANS (-7)

      CALL SETMSG ('3 75', '<Inquire current element type and size> ' //
     1             'should return annotation style as the type of '   //
     2             'the created element and the appropriate element ' //
     3             'size.')

      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
      CALL IFPF (ERRIND  .EQ. 0      .AND.
     1           ELTYPE  .EQ. PEANST .AND.
     2           INTLEN  .EQ. 1      .AND.
     3           RLLEN   .EQ. 0      .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('4 75', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the annotation style value.')

      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
      CALL IFPF (ERRIND      .EQ.  0  .AND.
     1           INTAR(1)    .EQ. -7  .AND.
     2           INTG        .EQ.  1  .AND.
     3           RL          .EQ.  0  .AND.
     4           STR         .EQ.  0)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
