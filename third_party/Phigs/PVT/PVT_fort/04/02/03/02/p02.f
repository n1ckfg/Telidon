C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/02                        *
C  *    TEST TITLE : Setting entries of various kinds      *
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

      INTEGER    MAXPL
C define a number greater than the number of initialized text entries
      PARAMETER (MAXPL=300)

C PHIGS parameter types
      INTEGER    MPLBTE, MPMBTE, MTXBTE, MINBTE, MEDBTE, MPAI, MCOLI,
     1           VWTBI, SPECON, SPECWT
      INTEGER    TXI, FONT, PREC, COLI, FONT2, PREC2, COLI2,
     1            PSET,   PREALI,   PSTRP,   PCHARP,   PSTRKP
      PARAMETER  (PSET=0, PREALI=1, PSTRP=0, PCHARP=1, PSTRKP=2)
      REAL       CHXP, CHSP, CHXP2, CHSP2
C used to control tests
      INTEGER    MNE, NIE, AII, LISTEL, LISTOT, DEFI(MAXPL), IDUM
      INTEGER    LUI, DPI, CNDE, NNDE

      DATA DEFI / MAXPL*0 /

      CALL INITGL ('04.02.03.02/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, MPLBTE, MPMBTE, MTXBTE, MINBTE,
     1             MEDBTE, MPAI, MCOLI, VWTBI)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of text bundle table entries
      MNE = MTXBTE

C *** *** *** *** ***    initialized entries   *** *** *** *** ***

      CALL SETMSG ('12', '<Inquire list of text indices> should ' //
     1             'return initialized indices.')

C <inquire list of text indices> to determine initialized entries
C   nie = number of initialized text entries
C   aii = an initialized index
      CALL PQETXI (WKID, 1, ERRIND, NIE, AII)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         GOTO 200
      ELSE
         CALL PASS
      ENDIF

C initialized_test:

C get initialized attributes
      CALL PQTXR (WKID, AII, PSET, ERRIND, FONT, PREC, CHXP, CHSP, COLI)
      CALL CHKINQ ('pqtxr', ERRIND)

C set different values for attributes

C make sure font is valid
      IF (FONT .EQ. 1) THEN
          FONT2 = 2
      ELSE
          FONT2 = 1
      ENDIF
C make sure precision is valid
      IF (PREC .EQ. PSTRKP) THEN
         PREC2 = PSTRP
      ELSE
         PREC2 = PSTRKP
      ENDIF
      CHXP2 = CHXP + 0.5
      CHSP2 = CHSP + 0.25
      COLI2  = COLI  + 1
      CALL PSTXR (WKID, AII, FONT2, PREC2, CHXP2, CHSP2, COLI2)

C get current number of defined entries
      CALL PQETXI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqetxi', ERRIND)

      CALL SETMSG ('10 12', 'Redefining a system-initialized entry ' //
     1             'should not change the number of defined entries.')
      CALL IFPF (CNDE .EQ. NIE)

C check that aii is still among defined entries
      CALL SETMSG ('10 12', 'Initialized bundle entry should be ' //
     1             'reported as defined after being set.')

      DO 150 LISTEL = 1, NIE
         CALL PQETXI (WKID, LISTEL, ERRIND, IDUM, TXI)
         CALL CHKINQ ('pqetxi', ERRIND)
         IF (TXI .EQ. AII) THEN
            CALL PASS
            GOTO 160
         ENDIF
150   CONTINUE
      CALL FAIL
      GOTO 200
160   CONTINUE

      CALL PQTXR (WKID, AII, PSET, ERRIND, FONT, PREC, CHXP, CHSP, COLI)
      CALL CHKINQ ('pqtxr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'initialized bundle entry.')

      CALL IFPF (FONT .EQ. FONT2 .AND.
     1           PREC .EQ. PREC2 .AND.
     2           CHXP .EQ. CHXP2 .AND.
     3           CHSP .EQ. CHSP2 .AND.
     4           COLI .EQ. COLI2)

C *** *** *** *** ***    undefined entries   *** *** *** *** ***
200   CONTINUE

C get lowest undefined index
C get current number defined entries
      CALL PQETXI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqetxi', ERRIND)
C defi is originally an array of zeros
      DO 250 LISTEL = 1, CNDE
         CALL PQETXI (WKID, LISTEL, ERRIND, IDUM, TXI)
         CALL CHKINQ ('pqetxi', ERRIND)
C mark as defined any index .le. cnde+1
C This will leave at least one UNmarked.
         IF (TXI .LE. CNDE+1) DEFI (TXI) = 1
250   CONTINUE

C first remaining zero indicates undefined entry
      DO 260 TXI = 1, CNDE+1
         IF (DEFI (TXI) .EQ. 0) THEN
C determine lowest undefined index (not in defined list) = lui
            LUI = TXI
            GOTO 270
         ENDIF
260   CONTINUE
      CALL UNMSG
     1     ('Cannot find undefined index - error in test algorithm.')

C established lui as lowest undefined index
270   CONTINUE
      CALL SETMSG ('12 15 16', '<Inquire text representation> '   //
     1             'should return attributes for bundle #1 when ' //
     2             'inquiring an undefined entry as REALIZED.')

C inquire undefined bundle as REALIZED
      CALL PQTXR  (WKID, LUI, PREALI, ERRIND, FONT, PREC, CHXP,
     1             CHSP, COLI)
      CALL CHKINQ ('pqtxr', ERRIND)
C inquire bundle #1 as REALIZED
      CALL PQTXR  (WKID, 1, PREALI, ERRIND, FONT2, PREC2, CHXP2,
     1             CHSP2, COLI2)
      CALL CHKINQ ('pqtxr', ERRIND)
C should have same attributes
      CALL IFPF (FONT .EQ. FONT2  .AND.
     1           PREC .EQ. PREC2  .AND.
     2           CHXP .EQ. CHXP2  .AND.
     3           CHSP .EQ. CHSP2  .AND.
     4           COLI .EQ. COLI2)

C  If number of initialized entries >= implementation max then skip test
C  of setting undefined entry - goto redefined_test.
      IF (NIE .GE. MNE) THEN
         CALL INMSG ('Skipping undefined-test because all text ' //
     1               'entries are initialized.')
         GOTO 300
      ENDIF

C Check that program allows enough room
      IF (NIE .GE. MAXPL) THEN
         CALL INMSG ('Skipping undefined-test because number of ' //
     1               'initialized entries exceed program limits.')
         GOTO 300
      ENDIF

C set values for attributes
      FONT2 = 1
      PREC2 = PCHARP
      CHXP2 = 1.75
      CHSP2 = 0.0
      COLI2 = 5
      CALL PSTXR (WKID, LUI, FONT2, PREC2, CHXP2, CHSP2, COLI2)

      CALL PQETXI (WKID, 1, ERRIND, LISTOT, IDUM)
      CALL CHKINQ ('pqetxi', ERRIND)

      CALL SETMSG ('10 12', 'Defining an undefined entry should ' //
     1             'increment the number of defined entries.')
      CALL IFPF (LISTOT .EQ. CNDE + 1)

C check that lui is now among defined entries
      CALL SETMSG ('10 12', 'Undefined bundle entry should be ' //
     1             'reported as defined after set.')
      DO 280 LISTEL = 1, LISTOT
         CALL PQETXI (WKID, LISTEL, ERRIND, IDUM, TXI)
         CALL CHKINQ ('pqetxi', ERRIND)
         IF (TXI .EQ. LUI) THEN
            CALL PASS
            GOTO 290
         ENDIF
280   CONTINUE
      CALL FAIL
      GOTO 300
290   CONTINUE

      CALL PQTXR (WKID, LUI, PSET, ERRIND, FONT, PREC, CHXP, CHSP, COLI)
      CALL CHKINQ ('pqtxr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'undefined bundle entry.')
      CALL IFPF (FONT .EQ. FONT2 .AND.
     1           PREC .EQ. PREC2 .AND.
     2           CHXP .EQ. CHXP2 .AND.
     3           CHSP .EQ. CHSP2 .AND.
     4           COLI .EQ. COLI2)

C *** *** *** *** ***    redefined entries   *** *** *** *** ***
300   CONTINUE

C get current number of defined entries
      CALL PQETXI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqetxi', ERRIND)

C let dpi = a defined text index from middle of list
      CALL PQETXI (WKID, (CNDE+1)/2, ERRIND, IDUM, DPI)
      CALL CHKINQ ('pqetxi', ERRIND)

C set to first set of values
      FONT = 2
      PREC = PSTRP
      CHXP = 0.75
      CHSP = 0.2
      COLI = 4
      CALL PSTXR (WKID, DPI, FONT, PREC, CHXP, CHSP, COLI)
C re-set to different values
      FONT2 = 1
      PREC2 = PSTRKP
      CHXP2 = 1.5
      CHSP2 = 0.4
      COLI2  = 5
      CALL PSTXR (WKID, DPI, FONT2, PREC2, CHXP2, CHSP2, COLI2)

C get list size - nnde = new number of defined entries
      CALL PQETXI (WKID, 1, ERRIND, NNDE, IDUM)
      CALL CHKINQ ('pqetxi', ERRIND)

      CALL SETMSG ('10 12', 'Redefining an entry should not change ' //
     1             'the number of defined entries.')
      CALL IFPF (NNDE .EQ. CNDE)

C check that dpi is among defined entries

      CALL SETMSG ('10 12', 'Redefined bundle entry should be ' //
     1             'reported as defined after set.')
      DO 320 LISTEL = 1, NNDE
         CALL PQETXI (WKID, LISTEL, ERRIND, IDUM, TXI)
         CALL CHKINQ ('pqetxi', ERRIND)
         IF (TXI .EQ. DPI) THEN
            CALL PASS
            GOTO 330
         ENDIF
320   CONTINUE
      CALL FAIL
      GOTO 399
330   CONTINUE

      CALL PQTXR (WKID, DPI, PSET, ERRIND, FONT, PREC, CHXP, CHSP, COLI)
      CALL CHKINQ ('pqtxr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'redefined bundle entry.')
      CALL IFPF (FONT .EQ. FONT2 .AND.
     1           PREC .EQ. PREC2 .AND.
     2           CHXP .EQ. CHXP2 .AND.
     3           CHSP .EQ. CHSP2 .AND.
     4           COLI .EQ. COLI2)

399   CONTINUE

C *** *** *** *** ***  access all defined entries  *** *** *** *** ***

      CALL SETMSG ('12 13', '<Inquire list of text indices> and ' //
     1             '<inquire text representation> should detect ' //
     2             'all defined entries.')
C get listel-th element of defined text indices
      DO 410 LISTEL = 1, NNDE
         CALL PQETXI (WKID, LISTEL, ERRIND, IDUM, TXI)
         IF (ERRIND .NE. 0) THEN
             CALL FAIL
             GOTO 415
         ENDIF
         CALL PQTXR (WKID, TXI, PSET, ERRIND, FONT, PREC, CHXP,
     1               CHSP, COLI)
         IF (ERRIND .NE. 0) THEN
             CALL FAIL
             GOTO 415
         ENDIF
410   CONTINUE
      CALL PASS
415   CONTINUE

666   CONTINUE
C wrap up it
      CALL ENDIT
      END
