C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/04                        *
C  *    TEST TITLE : Colour specification facilities       *
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

      INTEGER    CI, COLA, NCOL, IDUM1, IDUM2, COLMOD, NACM, IMOD
      INTEGER    SPECWT, SPECON, SETCOD, NUMRET
      INTEGER    RED,   GREEN,   BLUE
      PARAMETER (RED=1, GREEN=2, BLUE=3)

      REAL       ACTCOL(RED:BLUE), EXPCOL(RED:BLUE), NEWCOL(RED:BLUE)
      REAL       SETPRM(3), INQPRM(3), CSPEC(6)
      REAL       VAL, RDUM(9), Z,U
      PARAMETER (Z = 0.0, U = 1.0)

      LOGICAL    RAREQ, SETERR, INQERR

      CHARACTER MSG*300

      CALL INITGL ('04.03.02.02/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQCMDF (SPECWT, 0, ERRIND, NACM, IDUM1, IDUM2)
      CALL CHKINQ ('pqcmdf', ERRIND)
C no set or inquire error yet
      SETERR = .FALSE.
      INQERR = .FALSE.
      CALL ERRCTL (.TRUE.)

C go thru registered color models
      DO 100 IMOD = 1,NACM
         CALL PQCMDF (SPECWT, IMOD, ERRIND, IDUM1, COLMOD, IDUM2)
         CALL CHKINQ ('pqcmdf', ERRIND)
         IF (COLMOD .LT. 1 .OR. COLMOD .GT. 4) GOTO 100
         CALL PSCMD (WKID, COLMOD)

         DO 110 VAL = 0, 1, .19999
            CSPEC (1) = VAL
            CSPEC (2) = VAL**2
            CSPEC (3) = VAL**3
            CALL PSCR (WKID, 1, 3, CSPEC)
            IF (ERRSIG .NE. 0) THEN
               SETERR = .TRUE.
               SETPRM(1) = CSPEC(1)
               SETPRM(2) = CSPEC(2)
               SETPRM(3) = CSPEC(3)
               SETCOD = ERRSIG
               ERRSIG = 0
            ENDIF

            CALL PQCR (WKID, 1, 6, PREALI, ERRIND, NUMRET, CSPEC)
            CALL CHKINQ ('pqcr', ERRIND)
            IF (NUMRET .NE. 3    .OR.
     1          CSPEC(1) .LT. Z .OR. CSPEC(1) .GT. U .OR.
     2          CSPEC(2) .LT. Z .OR. CSPEC(2) .GT. U .OR.
     3          CSPEC(3) .LT. Z .OR. CSPEC(3) .GT. U)  THEN
               INQERR = .TRUE.
               INQPRM(1) = CSPEC(1)
               INQPRM(2) = CSPEC(2)
               INQPRM(3) = CSPEC(3)
            ENDIF
110      CONTINUE
100   CONTINUE
      CALL ERRCTL (.FALSE.)

      CALL SETMSG ('21 26 27', 'All colour specification parameters '//
     1             'within range of the current colour model '       //
     2             'should be accepted as valid.')
      IF (SETERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I2,A,3F9.3)') 'Error code ', SETCOD,
     1         ' signalled for color model ', COLMOD,
     2         ', color-spec = ', SETPRM
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('21 26 32 33', 'The components of a realized '    //
     1             'colour specification should be reported within ' //
     2             'the range of the current colour model.' )
      IF (INQERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I2,A,3F9.3)') 'For color model ', COLMOD,
     2         ', reported color-spec = ', INQPRM
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('21 26 32 33', 'The components of a realized '     //
     1             'colour specification should be reported within '  //
     2             'the range of the current colour model, even when '//
     3             'converted from another colour model.')

      CALL PSCMD (WKID, PCIE)
      CSPEC(1) = 0.6
      CSPEC(2) = 0.48
      CSPEC(3) = 1.0
      CALL PSCR (WKID, 0, 3, CSPEC)
      CSPEC(1) = 0.1
      CSPEC(2) = 0.53
      CSPEC(3) = 0.1
      CALL PSCR (WKID, 1, 3, CSPEC)
      CALL PSCMD (WKID, PRGB)

      DO 300 CI = 0,1
         CALL PQCR (WKID, CI, 6, PREALI, ERRIND, NUMRET, CSPEC)
         CALL CHKINQ ('pqcr', ERRIND)
         IF (NUMRET .NE. 3   .OR.
     1       CSPEC(1) .LT. Z .OR. CSPEC(1) .GT. U .OR.
     2       CSPEC(2) .LT. Z .OR. CSPEC(2) .GT. U .OR.
     3       CSPEC(3) .LT. Z .OR. CSPEC(3) .GT. U)    THEN
            CALL FAIL
            GOTO 310
         ENDIF
300   CONTINUE
      CALL PASS
310   CONTINUE

C <inquire colour facilities> to determine
C cola = colour available and
C ncol = number of colours
      CALL PQCF (SPECWT, ERRIND, NCOL, COLA, IDUM1, RDUM)
      CALL CHKINQ ('pqcf', ERRIND)
      IF (COLA .EQ. PCOLOR .AND. NCOL .EQ. 0) THEN
         CALL SETMSG ('3 5 32 33', 'For colour workstations with '   //
     1                'a continuous range of colours, the colour '   //
     2                'specification parameters should be realized ' //
     3                'as themselves.')
C <set colour representation> index #1, red=.78, green=.36, blue=.23
         EXPCOL(RED)   = .78
         EXPCOL(GREEN) = .36
         EXPCOL(BLUE)  = .23
         CALL PSCR (WKID, 1, 3, EXPCOL)
         CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)
         CALL IFPF (NUMRET .EQ. 3 .AND.
     1              RAREQ (3, ACTCOL, EXPCOL, .01, 0.0))
      ELSE
         CALL SETMSG ('3 6 32 33', 'For workstations with a '         //
     1                'noncontinuous range of colours or monochrome ' //
     2                'workstations, the colour specification '       //
     4                'parameters should be realized as closely as '  //
     5                'possible.')
C <set colour representation> index #1, red=.17, green=.92, blue=.87
         ACTCOL(RED)   = .17
         ACTCOL(GREEN) = .92
         ACTCOL(BLUE)  = .87
         CALL PSCR (WKID, 1, 3, ACTCOL)
         CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, EXPCOL)
         CALL CHKINQ ('pqcr', ERRIND)
         CALL PSCR (WKID, 1, 3, EXPCOL)
         CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, NEWCOL)
         CALL CHKINQ ('pqcr', ERRIND)
         CALL IFPF (NUMRET .EQ. 3 .AND.
     1              RAREQ (3, NEWCOL, EXPCOL, .01, 0.0))
      ENDIF

666   CONTINUE

C wrap it up
      CALL ENDIT
      END
