C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/05                        *
C  *    TEST TITLE : Colour model facilities               *
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

C colour model
      INTEGER    PRGB,   PCIE,   PHSV,   PHLS
      PARAMETER (PRGB=1, PCIE=2, PHSV=3, PHLS=4)
C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)
C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER    SPECWT, SPECON, INCODE, CDEX, I,IX,IY, PASSCT
      INTEGER    DEFMOD, CURMOD, NACM, THISCM, IDUM1,IDUM2, NUMRET

      REAL       ACTCOL(3), EXPCOL(3)
      REAL       CSPEC(3), RNDRL
      REAL       RGB(3,9), CIE(3,9), HSV(3,9), HLS(3,9)

      LOGICAL    ERRCOD, GOTDEF, REGMD(4), COLEQL

      CHARACTER*8 COLABL(9), CNAM, MSG*300

      DATA COLABL / 'red','yellow','green','cyan','blue','magenta',
     1              'white','gray','black' /
      DATA RGB / 1,0,0, 1,1,0, 0,1,0, 0,1,1, 0,0,1, 1,0,1,
     1           1,1,1, .5,.5,.5, 0,0,0 /
      DATA CIE / 0.600,0.480,1, 0.247,0.555,1, 0.007,0.542,1,
     1           -2,-2,-2, 0.117,0.203,1, -2,-2,-2,
     2           0.194,0.464,1, 0.194,0.464,0.5, -1,-1,0 /
      DATA HSV / 0,1,1, .1667,1,1, .3333,1,1, .5,1,1, .6667,1,1,
     1          .8333,1,1,  -1,0,1,  -1,0,.5,  -1,-1,0 /
      DATA HLS / 0,.5,1, .1667,.5,1, .3333,.5,1, .5,.5,1, .6667,.5,1,
     1           .8333,.5,1,  -1,1,-1,  -1,.5,0,  -1,0,-1 /

      CALL INITGL ('04.03.02.02/05')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  <Inquire colour model facilities> to determine
C  lacm = list of available colour models
C  in fortran: nacm   = number of available colour models
C              thiscm = nth available colour model
C  defmod = default colour model
      CALL PQCMDF (SPECWT, 0, ERRIND, NACM, IDUM1, DEFMOD)
      CALL CHKINQ ('pqcmdf', ERRIND)

      CALL SETMSG ('16 20', 'Immediately after <open workstation>, ' //
     1             'the current colour model should be the same as ' //
     2             'the default colour model.')
C curmod = current colour model
      CALL PQCMD (WKID, ERRIND, CURMOD)
      CALL CHKINQ ('pqcmd', ERRIND)
      CALL IFPF (CURMOD .EQ. DEFMOD)

      ERRCOD = .FALSE.
      GOTDEF = .FALSE.
      DO 50 I = 1,4
         REGMD(I) = .FALSE.
50    CONTINUE

      DO 100 I = 1, NACM
         CALL PQCMDF (SPECWT, I, ERRIND, IDUM1, THISCM, IDUM2)

         IF (ERRIND .NE. 0) THEN
            ERRCOD = .TRUE.
            WRITE (MSG, '(A,I5,A,I5,A)') 'Got error indicator ',
     1             ERRIND, ' while accessing colour model element #',
     2             I, '.'
            CALL INMSG (MSG)
            GOTO 100
         ENDIF

         IF (THISCM.GE.1 .AND. THISCM.LE.4) THEN
            REGMD(THISCM) = .TRUE.
         ENDIF
C check that defmod in list of colour models
         IF (THISCM .EQ. DEFMOD) GOTDEF = .TRUE.
100   CONTINUE

      CALL SETMSG ('16', 'All entries in the list of available ' //
     1             'colour models should be accessible.')
      CALL IFPF (.NOT. ERRCOD)

      CALL SETMSG ('16 18', 'The default colour model should be in ' //
     1             'the list of available colour models.')
      CALL IFPF (GOTDEF)

      CALL SETMSG ('16 19', 'The list of available colour models '    //
     1             'should contain the RGB and CIELUV colour models.')
      CALL IFPF (REGMD(PRGB) .AND. REGMD(PCIE))

      CALL SETMSG ('16 17', 'All entries within the reported list '   //
     1             'of available colour models should be realizable ' //
     2             'and valid.')
      CALL ERRCTL (.TRUE.)
C  go thru list of available colour models
      DO 200 I = 1, NACM
         CALL PQCMDF (SPECWT, I, ERRIND, IDUM1, THISCM, IDUM2)
         CALL CHKINQ ('pqcmdf', ERRIND)
         CALL PSCMD (WKID, THISCM)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A)') 'Colour model ', THISCM,
     1             ' rejected as invalid.'
            CALL INMSG (MSG)
            GOTO 250
         ENDIF

C inquire colour model to determine curmod
         CALL PQCMD (WKID, ERRIND, CURMOD)
         CALL CHKINQ ('pqcmd', ERRIND)
         IF (CURMOD .NE. THISCM) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A,I5,A)') 'Colour model set as ',
     1             THISCM, ' but realized as ', CURMOD, '.'
            CALL INMSG (MSG)
            GOTO 250
         ENDIF
200   CONTINUE
      CALL PASS

250   CONTINUE
      CALL ERRCTL (.FALSE.)

C  table of colour equivalents (-1 for indeterminate):
C
C  entry     colour     RGB        CIE                  HSV            HLS
C  -----     ------     ---        ---                  ---            ---
C    1       red        1, 0, 0    0.600,0.480,1        0, 1,1         0,.5,1
C    2       yellow     1, 1, 0    0.247,0.555,1    .1667, 1,1     .1667,.5,1
C    3       green      0, 1, 0    0.007,0.542,1    .3333, 1,1     .3333,.5,1
C    4       cyan       0, 1, 1                        .5, 1,1        .5,.5,1
C    5       blue       0, 0, 1    0.117,0.203,1    .6667, 1,1     .6667,.5,1
C    6       magenta    1, 0, 1                     .8333, 1,1     .8333,.5,1
C    7       white      1, 1, 1    0.194,0.464,1       -1, 0,1        -1,1,-1
C    8       gray      .5,.5,.5    0.194,0.464,0.5     -1, 0,.5       -1,.5,0
C    9       black      0, 0, 0   -1,   -1,    0       -1,-1,0        -1,0,-1


C *** *** *** *** ***    check CIE -> RGB  *** *** *** *** *** ***

C if got CIE, then do test
      IF (.NOT. REGMD(PCIE)) GOTO 399

      PASSCT = 0
      DO 300 IX = 1,9
         IF (IX.EQ.4 .OR. IX.EQ.6) GOTO 300
C  <set colour model> CIE
         CALL PSCMD (WKID, PCIE)
C  <set colour representation> index #1, CIE entry (ix) but changing -1
C     to random value between 0 and 1
         DO 310 IY = 1,3
            IF (CIE(IY, IX) .EQ. -1) THEN
               CSPEC(IY) = RNDRL (0., 1.)
            ELSE
               CSPEC(IY) = CIE(IY, IX)
            ENDIF
            EXPCOL(IY) = RGB(IY, IX)
310      CONTINUE

         CALL PSCR (WKID, 1, 3, CSPEC)
         CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)
C  attempt to convert only realizable colors
         IF (.NOT. COLEQL (3, ACTCOL, CSPEC, 0.02, 0.0)) GOTO 300

C  <set colour model> RGB
         CALL PSCMD (WKID, PRGB)
C  <inquire colour representation> #1 as SET, to determine cspec
         CALL PQCR (WKID, 1, 3, PSET, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)

         IF (NUMRET.EQ.3 .AND.
     1       COLEQL (3, ACTCOL, EXPCOL, 0.1, .0)) THEN
            PASSCT = PASSCT+1
         ELSE
            PASSCT = -666
            WRITE (MSG, '(A)') 'Fail to change colour model from ' //
     1             'CIE to RGB for colour = ' // COLABL(IX) // '.'
            CALL INMSG (MSG)
         ENDIF
300   CONTINUE
      IF (PASSCT .EQ. 0) THEN
         CALL INMSG ('No realizable CIE colors for CIE to RGB ' //
     1               'conversion test.')
      ELSE
         CALL SETMSG ('21 22 23', 'Changing the colour model from '  //
     1                'CIE to RGB should not affect the colours in ' //
     2                'the colour table.')
         CALL IFPF (PASSCT .GT. 0)
      ENDIF

C  end_from_cie:
350   CONTINUE

C *** *** *** *** ***    check RGB -> CIE   *** *** *** *** *** ***

      PASSCT = 0
      DO 360 IX = 1,9
         IF (IX.EQ.4 .OR. IX.EQ.6) GOTO 360

C  <set colour model> RGB
         CALL PSCMD (WKID, PRGB)
         DO 370 IY =1, 3
            CSPEC(IY) = RGB(IY,IX)
370      CONTINUE
C  <set colour representation> index #1, RGB entry (ix)
         CALL PSCR (WKID, 1, 3, CSPEC)
         CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)
C  attempt to convert only realizable colors
         IF (.NOT. COLEQL (3, ACTCOL, CSPEC, 0.02, 0.0)) GOTO 360

C  <set colour model> CIE
         CALL PSCMD (WKID, PCIE)
C  <inquire colour representation> as SET, to determine cspec
         CALL PQCR (WKID, 1, 3, PSET, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)

         CALL COLNAM (ACTCOL(1),ACTCOL(2), INCODE, CDEX, CNAM)

         IF (IX .LE. 7) THEN
            IF (CNAM.EQ.COLABL(IX) .AND. ACTCOL(3).GT.0.7) THEN
               GOTO 355
            ELSE
               GOTO 380
            ENDIF
         ELSEIF (IX .EQ. 8) THEN
            IF (CNAM.EQ.'white' .AND. ACTCOL(3).GT.0.2 .AND.
     1          ACTCOL(3).LT.0.8) THEN
               GOTO 355
            ELSE
               GOTO 380
            ENDIF
         ELSEIF (IX .EQ. 9) THEN
            IF (ACTCOL(3) .LT. 0.1) THEN
               GOTO 355
            ELSE
               GOTO 380
            ENDIF
         ENDIF

355      CONTINUE
         PASSCT = PASSCT+1
         GOTO 360

380      CONTINUE
         PASSCT = -666
         WRITE (MSG, '(A)') 'Fail to change colour model from RGB ' //
     1          'to CIE for colour = ' // COLABL(IX) // '.'
         CALL INMSG (MSG)
360   CONTINUE
      IF (PASSCT .EQ. 0) THEN
         CALL INMSG ('No realizable RGB colors for RGB to CIE ' //
     1               'conversion test.')                      
      ELSE
         CALL SETMSG ('21 22 23', 'Changing the colour model from '  //
     1                'RGB to CIE should not affect the colours in ' //
     2                'the colour table.')
         CALL IFPF (PASSCT .GT. 0)
      ENDIF

C  end_cie:
399   CONTINUE

C *** *** *** *** ***    check HSV <-> RGB  *** *** *** *** *** ***

C  if got HSV, then do test, otherwise skip
      IF (.NOT. REGMD(PHSV)) GOTO 499

      CALL COLTRN (WKID, COLABL, HSV, PHSV, RGB, PRGB, '21 22 24')
      CALL COLTRN (WKID, COLABL, RGB, PRGB, HSV, PHSV, '21 22 24')

C  end_hsv:
499   CONTINUE

C *** *** *** *** ***    check HLS <-> RGB  *** *** *** *** *** ***

C if got HLS, then do test, otherwise skip
      IF (.NOT. REGMD(PHLS)) GOTO 599

      CALL COLTRN (WKID, COLABL, HLS, PHLS, RGB, PRGB, '21 22 25')
      CALL COLTRN (WKID, COLABL, RGB, PRGB, HLS, PHLS, '21 22 25')

C  end_hls:
599   CONTINUE

      CALL PCLWK (WKID)
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL SETMSG ('16 20', 'Immediately after re-opening the '    //
     1             'workstation, the current colour model should ' //
     2             'be the same as the default colour model.')
C curmod = current colour model
      CALL PQCMD (WKID, ERRIND, CURMOD)
      CALL CHKINQ ('pqcmd', ERRIND)
      CALL IFPF (CURMOD .EQ. DEFMOD)

666   CONTINUE
C wrap it up
      CALL ENDIT
      END

