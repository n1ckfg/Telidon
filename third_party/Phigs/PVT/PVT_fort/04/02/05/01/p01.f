C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.01/01                        *
C  *    TEST TITLE : Simple setting and inquiring          *
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

      INTEGER    INLEN, RELEN, STLEN
      PARAMETER  (INLEN=50, RELEN=50, STLEN=50)

C PHIGS parameter types
      INTEGER    ELTYPE, INTLEN, INTG, RLLEN, RL, STRLEN, STR, STRID
      INTEGER    INTAR (INLEN), STRARL (STLEN)
      REAL       RLAR  (RELEN), RPTVAR (9)
      CHARACTER  STRAR (STLEN), MSG*200

      INTEGER    I, ISTYLE, EFLAG
      REAL       RINCR, RATR1,RATR2

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)
C edge flag indicator
      INTEGER    POFF,   PON
      PARAMETER (POFF=0, PON=1)

      CALL INITGL ('04.02.05.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C structure identifier = 1
      STRID = 1
C open structure
      CALL POPST (STRID)

C *** *** *** *** ***    Interior style    *** *** *** *** ***
C set value for attribute
      CALL PSIS (PPATTR)

      CALL SETMSG ('1 5', '<Inquire current element type '   //
     1             'and size> should return interior style ' //
     2             'as the type of the created element and ' //
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 43 is the PHIGS enumeration type for peis
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 43    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 5 6', '<Inquire current element content> '    //
     1             'should return the standard representation for ' //
     2             'all valid interior style values.')

      DO 100 ISTYLE = PHOLLO, PISEMP
         CALL PSIS (ISTYLE)
         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND      .EQ. 0       .AND.
     1       INTAR(1)    .EQ. ISTYLE  .AND.
     2       INTG        .EQ. 1       .AND.
     3       RL          .EQ. 0       .AND.
     4       STR         .EQ. 0) THEN
C            OK so far
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I2,A)') 'Failure for interior style = ',
     1             ISTYLE, '.'
            CALL INMSG (MSG)
            GOTO 110
         ENDIF

100   CONTINUE
      CALL PASS

110   CONTINUE

C *** *** *** *** ***   Interior style index   *** *** *** *** ***
C set value for attribute
      CALL PSISI (5)

      CALL SETMSG ('1 18', '<Inquire current element type '    //
     1             'and size> should return interior style '   //
     2             'index as the type of the created element ' //
     3             'and the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 44 is the PHIGS enumeration type for peisi
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 44    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 18', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the interior style index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peisi
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           INTAR(1)    .EQ. 5     .AND.
     2           INTG        .EQ. 1     .AND.
     3           RL          .EQ. 0     .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***    Interior colour index    *** *** *** *** ***
C set value for attribute
      CALL PSICI (2)

      CALL SETMSG ('1 26', '<Inquire current element type ' //
     1             'and size> should return interior '      //
     2             'colour index as the type of the '       //
     3             'created element and the appropriate '   //
     4             'element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 45 is the PHIGS enumeration type for peici
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 45    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 26', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the interior colour index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peici
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           INTAR(1)    .EQ. 2     .AND.
     2           INTG        .EQ. 1     .AND.
     3           RL          .EQ. 0     .AND.
     4           STR         .EQ. 0)


C *** *** *** *** ***    Pattern size    *** *** *** *** ***
C set value for attribute
      RATR1 = 4.1
      RATR2 = 5.1
      CALL PSPA (RATR1, RATR2)

      CALL SETMSG ('1 61', '<Inquire current element type '   //
     1             'and size> should return pattern size '    //
     2             'as the type of the created element and '  //
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 50 is the PHIGS enumeration type for pepa
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 50    .AND.
     2           INTLEN  .EQ. 0     .AND.
     3           RLLEN   .EQ. 2     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 61', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the pattern size value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peii
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           RLAR(1)     .EQ. RATR1 .AND.
     1           RLAR(2)     .EQ. RATR2 .AND.
     2           INTG        .EQ. 0     .AND.
     3           RL          .EQ. 2     .AND.
     4           STR         .EQ. 0)

C *** *** ***   Pattern reference point and vectors   *** *** ***
C set value for attribute
      RINCR = 0.5
      DO 200 I = 1,9
         RPTVAR(I) = RINCR
         RINCR = RINCR + 0.2
200   CONTINUE
      CALL PSPRPV (RPTVAR(1), RPTVAR(2), RPTVAR(3),
     1             RPTVAR(4), RPTVAR(6), RPTVAR(8) )

      CALL SETMSG ('1 66', '<Inquire current element type '     //
     1             'and size> should return pattern reference ' //
     2             'point and vectors as the type of the '      //
     3             'created element and the appropriate '       //
     4             'element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 51 is the PHIGS enumeration type for peprpv
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 51    .AND.
     2           INTLEN  .EQ. 0     .AND.
     3           RLLEN   .EQ. 9     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 66', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the pattern reference point and vectors values.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peprpv
      CALL IFPF (ERRIND  .EQ. 0         .AND.
C reference point:
     1           RLAR(1) .EQ. RPTVAR(1) .AND.
     2           RLAR(2) .EQ. RPTVAR(2) .AND.
     3           RLAR(3) .EQ. RPTVAR(3) .AND.
C vector 1:
     1           RLAR(4) .EQ. RPTVAR(4) .AND.
     2           RLAR(5) .EQ. RPTVAR(6) .AND.
     3           RLAR(6) .EQ. RPTVAR(8) .AND.
C vector 2:
     1           RLAR(7) .EQ. RPTVAR(5) .AND.
     2           RLAR(8) .EQ. RPTVAR(7) .AND.
     3           RLAR(9) .EQ. RPTVAR(9) .AND.
C array sizes:
     1           INTG        .EQ. 0     .AND.
     2           RL          .EQ. 9     .AND.
     3           STR         .EQ. 0)

C *** *** *** ***   Pattern reference point    *** *** *** ***
300   CONTINUE
C set value for attribute
      RATR1 = 0.35
      RATR2 = 0.21
      CALL PSPARF (RATR1, RATR2)

      CALL SETMSG ('1 67', '<Inquire current element type '     //
     1             'and size> should return pattern reference ' //
     2             'point as the type of the created element '  //
     3             'and the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 52 is the PHIGS enumeration type for peparf
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 52    .AND.
     2           INTLEN  .EQ. 0     .AND.
     3           RLLEN   .EQ. 2     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 67', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the pattern reference point values.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peprpv
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           RLAR(1)     .EQ. RATR1 .AND.
     2           RLAR(2)     .EQ. RATR2 .AND.
     3           INTG        .EQ. 0     .AND.
     4           RL          .EQ. 2     .AND.
     5           STR         .EQ. 0)

C *** *** *** *** ***    Edge flag   *** *** *** *** ***
C set value for attribute
      CALL PSEDFG (PON)

      CALL SETMSG ('1 32', '<Inquire current element type ' //
     1             'and size> should return edge flag as '  //
     2             'the type of the created element and '   //
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 46 is the PHIGS enumeration type for peedfg
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 46    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 32 33', '<Inquire current element content> '  //
     1             'should return the standard representation for ' //
     2             'all valid edge flag values.')

      DO 1100 EFLAG = POFF, PON
         CALL PSEDFG (EFLAG)
         CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1                RL, RLAR, STR, STRARL, STRAR)
         IF (ERRIND      .EQ. 0       .AND.
     1       INTAR(1)    .EQ. EFLAG   .AND.
     2       INTG        .EQ. 1       .AND.
     3       RL          .EQ. 0       .AND.
     4       STR         .EQ. 0) THEN
C            OK so far
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I2,A)') 'Failure for edge flag = ',
     1             EFLAG, '.'
            CALL INMSG (MSG)
            GOTO 1110
         ENDIF

1100   CONTINUE
      CALL PASS

1110   CONTINUE

C *** *** *** *** ***   Edgetype   *** *** *** *** ***
C set value for attribute
      CALL PSEDT (6)

      CALL SETMSG ('1 40', '<Inquire current element type '  //
     1             'and size> should return edgetype '       //
     2             'as the type of the created element and ' //
     3             'the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 47 is the PHIGS enumeration type for peedt
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 47    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 40', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the edgetype value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peedt
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           INTAR(1)    .EQ. 6     .AND.
     2           INTG        .EQ. 1     .AND.
     3           RL          .EQ. 0     .AND.
     4           STR         .EQ. 0)

C *** *** *** ***    Edgewidth scale factor    *** *** *** ***
C set value for attribute
      RATR1 = 0.33
      CALL PSEWSC (RATR1)

      CALL SETMSG ('1 49', '<Inquire current element type ' //
     1             'and size> should return edgewidth '     //
     2             'scale factor as the type of the '       //
     3             'created element and the appropriate '   //
     4             'element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 48 is the PHIGS enumeration type for peewsc
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 48    .AND.
     2           INTLEN  .EQ. 0     .AND.
     3           RLLEN   .EQ. 1     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 49', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the edgewidth scale factor value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type peewsc
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           RLAR(1)     .EQ. RATR1 .AND.
     2           INTG        .EQ. 0     .AND.
     3           RL          .EQ. 1     .AND.
     4           STR         .EQ. 0)

C *** *** *** *** ***    Edge colour index   *** *** *** *** ***
C set value for attribute
      CALL PSEDCI (3)

      CALL SETMSG ('1 55', '<Inquire current element type '     //
     1             'and size> should return edge colour index ' //
     2             'as the type of the created element '        //
     3             'and the appropriate element size.')
      CALL PQCETS (ERRIND, ELTYPE, INTLEN, RLLEN, STRLEN)
C checking correct element type
C 49 is the PHIGS enumeration type for peedci
      CALL IFPF (ERRIND  .EQ. 0     .AND.
     1           ELTYPE  .EQ. 49    .AND.
     2           INTLEN  .EQ. 1     .AND.
     3           RLLEN   .EQ. 0     .AND.
     4           STRLEN  .EQ. 0)

      CALL SETMSG ('2 55', '<Inquire current element content> '     //
     1             'should return the standard representation for ' //
     2             'the edge colour index value.')
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRARL, STRAR)
C checking correct output parameters for data record type pepmi
      CALL IFPF (ERRIND      .EQ. 0     .AND.
     1           INTAR(1)    .EQ. 3     .AND.
     2           INTG        .EQ. 1     .AND.
     3           RL          .EQ. 0     .AND.
     4           STR         .EQ. 0)

      CALL ENDIT
      END
