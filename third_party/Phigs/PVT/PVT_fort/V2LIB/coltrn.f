      SUBROUTINE COLTRN (WKID, COLABL, FROMCC, FROMMD, TOCC, TOMD, SRS)

C  COLTRN tests the ability to translate color from one model to
C  another and issues pass or fail as a result.

C  Input parameters:
C    WKID   : workstation identifier
C    COLABL : labels (names) of colors to be tested
C    FROMCC : color coordinates to translate from
C    FROMMD : color model to translate from
C    TOCC   : color coordinates to translate to (expected result)
C    TOMD   : color model to translate to
C    SRS    : SR identifiers for test case

C colour model
      INTEGER    PRGB,   PCIE,   PHSV,   PHLS
      PARAMETER (PRGB=1, PCIE=2, PHSV=3, PHLS=4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER    WKID, FROMMD, TOMD, IX,IY, NUMRET, ERRIND, PASSCT

      REAL       FROMCC(3,9), TOCC(3,9), CSPEC(3),ACTCOL(3),EXPCOL(3)
      REAL       RNDRL

      LOGICAL    COLEQL

      CHARACTER  MSG*300, SRS*(*), MODNAM(PRGB:PHLS)*3, COLABL(9)*8

      DATA  MODNAM  / 'RGB', 'CIE', 'HSV', 'HLS' /

      PASSCT = 0
      DO 100 IX = 1,9
C <set colour model>
         CALL PSCMD (WKID, FROMMD)
C  <set colour representation> index #1, entry #ix, change -1 to
C     random value between 0 and 1
         DO 110 IY = 1,3
            IF (FROMCC(IY,IX) .EQ. -1) THEN
               CSPEC(IY) = RNDRL (0., 1.)
            ELSE
               CSPEC(IY) = FROMCC(IY,IX)
            ENDIF
            EXPCOL(IY) = TOCC(IY,IX)
110      CONTINUE
         CALL PSCR (WKID, 1, 3, CSPEC)
         CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)
C  attempt to convert only realizable colors
         IF (.NOT. COLEQL (3, ACTCOL, CSPEC, 0.02, 0.0)) GOTO 100

C  <re-set colour model>
         CALL PSCMD (WKID, TOMD)
C  <inquire colour representation> as SET, to determine cspec
         CALL PQCR (WKID, 1, 3, PSET, ERRIND, NUMRET, ACTCOL)
         CALL CHKINQ ('pqcr', ERRIND)

         IF (NUMRET.EQ.3 .AND.
     1       COLEQL (3, ACTCOL, EXPCOL, 0.1, 0.0)) THEN
C  OK so far
            PASSCT = PASSCT+1
         ELSE
            PASSCT = -666
            WRITE (MSG, '(A)') 'Fail to change colour model from ' //
     1             MODNAM(FROMMD) // ' to ' // MODNAM(TOMD) //
     2             ' for colour = ' // COLABL(IX) // '.'
            CALL INMSG (MSG)
         ENDIF
100   CONTINUE

      IF (PASSCT .EQ. 0) THEN
         CALL INMSG ('No realizable ' // MODNAM(FROMMD) //
     1               ' colors for ' // MODNAM(FROMMD) // ' to ' //
     2               MODNAM(TOMD) // ' conversion test.')
      ELSE
         CALL SETMSG (SRS, 'Changing the colour model from '   //
     1                MODNAM(FROMMD) // ' to ' // MODNAM(TOMD) //
     2                ' should not affect the colours in the ' //
     3                'colour table.')
         CALL IFPF (PASSCT .GT. 0)
      ENDIF

      END
