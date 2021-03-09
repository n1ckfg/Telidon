C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.01/01                        *
C  *    TEST TITLE : Setting and inquiring colour table    *
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
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C Note: INTEGER rather than enumeration type.  Explicitly defined and
C required portion of conceptually unbounded range defined here.

C type of returned values   set,    realized
      INTEGER               PSET,   PREALI
      PARAMETER            (PSET=0, PREALI=1)

      INTEGER    MAXPL
C define a number greater than the number of initialized color entries
      PARAMETER (MAXPL=5000)

      INTEGER    RED,   GREEN,   BLUE
      PARAMETER (RED=1, GREEN=2, BLUE=3)
      REAL       ACTCOL(RED:BLUE), EXPCOL(RED:BLUE)

      INTEGER    ICOL, MCOLI, NUMRET
      INTEGER    MNE, NIE, AII, LISTEL, LISTOT, DEFI(0:MAXPL)
      INTEGER    LUI, DCI, CTI, CNDE, NNDE, SPECWT, SPECON
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

      LOGICAL    RAREQ

      DATA DEFI / 0, MAXPL*0 /

      CALL INITGL ('04.03.02.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C set colour model to RGB
      CALL PSCMD (WKID, PRGB)

      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             IDUM5, IDUM6, MCOLI, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of entries in workstation's color table:
      MNE = MCOLI

C *** *** *** *** ***    initialized entries   *** *** *** *** ***

C <inquire list of colour indices> to determine initialized entries
      CALL SETMSG ('3', '<Inquire list of colour indices> should ' //
     1             'return initialized indices.')

C   nie = number of initialized colour entries
C   aii = an initialized index
      CALL PQECI (WKID, 1, ERRIND, NIE, AII)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         GOTO 200
      ELSE
         CALL PASS
      ENDIF

C  avoid aii=0, because background color may be un-changeable
      IF (AII .EQ. 0) THEN
         CALL PQECI (WKID, 2, ERRIND, IDUM1, AII)
         CALL CHKINQ ('pqeci', ERRIND)
      ENDIF

C get initialized attributes
      CALL PQCR (WKID, AII, 3, PSET, ERRIND, NUMRET, ACTCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C set different values for attributes
C make sure colour specifications are within 0 - 1
      DO 50 ICOL = RED,BLUE
         IF (ACTCOL(ICOL) .LT. 0.5) THEN
            EXPCOL(ICOL) = ACTCOL(ICOL) + 0.25
         ELSE
            EXPCOL(ICOL) = ACTCOL(ICOL) - 0.15
         ENDIF
50    CONTINUE
      CALL PSCR (WKID, AII, 3, EXPCOL)

C get current number of defined entries
      CALL PQECI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)

      CALL SETMSG ('1 3', 'Re-defining a system-initialized entry ' //
     1             'should not change the number of defined entries.')
      CALL IFPF (CNDE .EQ. NIE)

C check that aii is still among defined entries
      CALL SETMSG ('1 3', 'Initialized table entry should be ' //
     1             'reported as defined after being set.')
      DO 150 LISTEL = 1, NIE
         CALL PQECI (WKID, LISTEL, ERRIND, IDUM1, CTI)
         CALL CHKINQ ('pqeci', ERRIND)
         IF (CTI .EQ. AII) THEN
            CALL PASS
            GOTO 160
         ENDIF
150   CONTINUE
      CALL FAIL
      GOTO 200
160   CONTINUE

      CALL PQCR (WKID, AII, 3, PSET, ERRIND, NUMRET, ACTCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL SETMSG ('2 5', 'New values should be set for ' //
     1             'initialized table entry.')
C check that colour specifications are approximately equal
      CALL IFPF (NUMRET.EQ.3 .AND. RAREQ (3, ACTCOL, EXPCOL, .01, .01))

C *** *** *** *** ***    undefined entries   *** *** *** *** ***
200   CONTINUE

C get lowest undefined index
C get current number defined entries
      CALL PQECI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)

C Check that program allows enough room
      IF (CNDE .GE. MAXPL) THEN
         CALL INMSG ('Skipping undefined-entries tests because ' //
     1               'number of initialized entries exceed '     //
     2               'program limits.')
         GOTO 300
      ENDIF

C defi is originally an array of zeros
      DO 250 LISTEL = 1, CNDE
         CALL PQECI (WKID, LISTEL, ERRIND, IDUM1, CTI)
         CALL CHKINQ ('pqeci', ERRIND)
C mark as defined any index .le. cnde+1
C This will leave at least one UNmarked.
         IF (CTI .LE. CNDE+1) DEFI (CTI) = 1
250   CONTINUE

C first remaining zero indicates undefined entry
      DO 260 CTI = 1, CNDE+1
         IF (DEFI (CTI) .EQ. 0) THEN
C determine lowest undefined index (not in defined list) = lui
            LUI = CTI
            GOTO 270
         ENDIF
260   CONTINUE
      CALL UNMSG
     1     ('Cannot find undefined index - error in test algorithm.')

C established lui as lowest undefined index
270   CONTINUE
      CALL SETMSG ('3 6', '<Inquire colour representation> '       //
     1             'should return attributes for colour index #1 ' //
     2             'when inquiring an undefined entry as REALIZED.')

C <inquire color representation> as REALIZED for index #lui to get
C color_spec for undefined_entry .
      CALL PQCR (WKID, LUI, 3, PREALI, ERRIND, NUMRET, ACTCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C <inquire colour representation> as REALIZED for index #1  to get
C color_spec for index #1.
      CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, EXPCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C should have same attributes (approximately equal)
      CALL IFPF (NUMRET.EQ.3 .AND. RAREQ (3, ACTCOL, EXPCOL, .01, .01))

C  If (number of initialized entries >= max size of colour table) then
C  skip test of undefined_test ; goto redefined_test.
      IF (CNDE .GE. MNE) THEN
         CALL INMSG ('Skipping set-undefined test because all ' //
     1               'colour table entries are initialized.')
         GOTO 300
      ENDIF

C set values for attributes
      EXPCOL(RED)   = .85
      EXPCOL(GREEN) = .27
      EXPCOL(BLUE)  = .76
      CALL PSCR (WKID, LUI, 3, EXPCOL)

      CALL PQECI (WKID, 0, ERRIND, LISTOT, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)

      CALL SETMSG ('1 3', 'Defining an undefined entry should ' //
     1             'increment the number of defined entries.')
      CALL IFPF (LISTOT .EQ. CNDE + 1)

C check that lui is now among defined entries
      CALL SETMSG ('1 3', 'Undefined table entry should be ' //
     1             'reported as defined after set.')
      DO 280 LISTEL = 1, LISTOT
         CALL PQECI (WKID, LISTEL, ERRIND, IDUM1, CTI)
         CALL CHKINQ ('pqeci', ERRIND)
         IF (CTI .EQ. LUI) THEN
            CALL PASS
            GOTO 290
         ENDIF
280   CONTINUE
      CALL FAIL
      GOTO 300
290   CONTINUE

      CALL PQCR (WKID, LUI, 3, PSET, ERRIND, NUMRET, ACTCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL SETMSG ('2 5', 'New values should be set for ' //
     1             'undefined table entry.')
C check that colour specifications are approximately equal
      CALL IFPF (NUMRET.EQ.3 .AND. RAREQ (3, ACTCOL, EXPCOL, .01, .01))

C *** *** *** *** ***    redefined entries   *** *** *** *** ***
300   CONTINUE

C get current number defined entries
      CALL PQECI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)

C let dci = a defined colour index from middle of list
      CALL PQECI (WKID, (CNDE+1)/2, ERRIND, IDUM1, DCI)
      CALL CHKINQ ('pqeci', ERRIND)

C set to first set of values
      EXPCOL(RED)   = 0.0
      EXPCOL(GREEN) = 1.0
      EXPCOL(BLUE)  = 0.0
      CALL PSCR (WKID, DCI, 3, EXPCOL)

C re-set to different values
      EXPCOL(RED)   = 1.0
      EXPCOL(GREEN) = 0.0
      EXPCOL(BLUE)  = 1.0
      CALL PSCR (WKID, DCI, 3, EXPCOL)

C get list size - nnde = new number of defined entries
      CALL PQECI (WKID, 0, ERRIND, NNDE, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)

      CALL SETMSG ('1 3', 'Re-defining a user-defined entry should ' //
     1             'not change number of defined entries.')
      CALL IFPF (NNDE .EQ. CNDE)

C check that dci is among defined entries
      CALL SETMSG ('1 3', 'Redefined table entry should be ' //
     1             'reported as defined after set.')
      DO 320 LISTEL = 1, NNDE
         CALL PQECI (WKID, LISTEL, ERRIND, IDUM1, CTI)
         CALL CHKINQ ('pqeci', ERRIND)
         IF (CTI .EQ. DCI) THEN
            CALL PASS
            GOTO 330
         ENDIF
320   CONTINUE
      CALL FAIL
      GOTO 399
330   CONTINUE

      CALL PQCR (WKID, DCI, 3, PSET, ERRIND, NUMRET, ACTCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL SETMSG ('2 5', 'New values should be set for ' //
     1             'redefined table entry.')
C check that colour speicfications are approximately equal
      CALL IFPF (NUMRET.EQ.3 .AND. RAREQ (3, ACTCOL, EXPCOL, .01, .01))

399   CONTINUE

C *** *** *** *** ***  access all defined entries  *** *** *** *** ***

      CALL SETMSG ('3 4', '<Inquire list of colour indices> and ' //
     1             '<inquire colour representation> should '      //
     2             'detect all defined entries.')
C get listel-th element of defined colour indices
      DO 410 LISTEL = 1, NNDE
         CALL PQECI (WKID, LISTEL, ERRIND, IDUM1, CTI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 415
         ENDIF
         CALL PQCR (WKID, CTI, 3, PSET, ERRIND, NUMRET, ACTCOL)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 415
         ENDIF
410   CONTINUE
      CALL PASS
415   CONTINUE

666   CONTINUE

C wrap it up
      CALL ENDIT
      END
