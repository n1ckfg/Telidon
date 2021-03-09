C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/02                        *
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

      INTEGER    MAXPM
C define a number greater than the number of initialized polymarker entries
      PARAMETER (MAXPM=300)

C PHIGS parameter types
      INTEGER    MPLBTE, MPMBTE, MTXBTE, MINBTE, MEDBTE, MPAI, MCOLI,
     1           VWTBI
      INTEGER    PMI, MTYPE, COLI, MTYPE2, COLI2

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      REAL       MSZSF, MSZSF2
C used to control tests
      INTEGER    MNE, NIE, AII, LISTEL, LISTOT, DEFI(MAXPM), IDUM
      INTEGER    LUI, DPI, CNDE, NNDE

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      DATA DEFI / MAXPM*0 /

      CALL INITGL ('04.02.02.02/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqkwc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, MPLBTE, MPMBTE, MTXBTE, MINBTE,
     1             MEDBTE, MPAI, MCOLI, VWTBI)
      CALL CHKINQ ('pqwksl', ERRIND)
C maximum number of polymarker bundle table entries
      MNE = MPMBTE

C *** *** *** *** ***    initialized entries   *** *** *** *** ***

C There should be at least 5 initialized polymarker bundles - this
C inquiry gets the first, so it should work.  This statement
C is NOT meant to test the requirement of 5 initialized bundles;
C that is done elsewhere.

      CALL SETMSG ('12', '<Inquire list of polymarker indices> ' //
     1             'should return initialized indices.')
C   nie = number of initialized polymarker entries
C   aii = an initialized index (the first)
      CALL PQEPMI (WKID, 1, ERRIND, NIE, AII)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         GOTO 200
      ELSE
         CALL PASS
      ENDIF

C get initialized attributes
      CALL PQPMR (WKID, AII, PSET, ERRIND, MTYPE, MSZSF, COLI)
      CALL CHKINQ ('pqpmr', ERRIND)

C set different values for attributes
C make sure marker type is valid
      IF (MTYPE .LT. 5) THEN
         MTYPE2 = MTYPE + 1
      ELSE
         MTYPE2 = 2
      ENDIF
      MSZSF2 = MSZSF * 0.15
      COLI2  = COLI  + 1
      CALL PSPMR (WKID, AII, MTYPE2, MSZSF2, COLI2)

C get current number of defined entries
      CALL PQEPMI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqepmi', ERRIND)

      CALL SETMSG ('10 12', 'Re-defining a system-initialized entry ' //
     1             'should not change the number of defined entries.')
      CALL IFPF (CNDE .EQ. NIE)

C check that aii is still among defined entries
      CALL SETMSG ('10 12', 'Initialized bundle entry should be ' //
     1             'reported as defined after being set.')
      DO 150 LISTEL = 1, NIE
         CALL PQEPMI (WKID, LISTEL, ERRIND, IDUM, PMI)
         CALL CHKINQ ('pqepmi', ERRIND)
         IF (PMI .EQ. AII) THEN
            CALL PASS
            GOTO 160
         ENDIF
150   CONTINUE
      CALL FAIL
      GOTO 200
160   CONTINUE

      CALL PQPMR (WKID, AII, PSET, ERRIND, MTYPE, MSZSF, COLI)
      CALL CHKINQ ('pqpmr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'initialized bundle entry.')
      CALL IFPF (MTYPE .EQ. MTYPE2 .AND.
     1           MSZSF .EQ. MSZSF2 .AND.
     2           COLI  .EQ. COLI2)

C *** *** *** *** ***    undefined entries   *** *** *** *** ***
200   CONTINUE

C get lowest undefined index
C get current number of defined entries
      CALL PQEPMI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqepmi', ERRIND)
C defi is originally an array of zeros
      DO 250 LISTEL = 1, CNDE
         CALL PQEPMI (WKID, LISTEL, ERRIND, IDUM, PMI)
         CALL CHKINQ ('pqepmi', ERRIND)
C mark as defined any index .le. cnde+1
C This will leave at least one UNmarked.
         IF (PMI .LE. CNDE+1) DEFI (PMI) = 1
250   CONTINUE

C first remaining zero indicates undefined entry
      DO 260 PMI = 1, CNDE+1
         IF (DEFI (PMI) .EQ. 0) THEN
C determine lowest undefined index (not in defined list) = lui
            LUI = PMI
            GOTO 270
         ENDIF
260   CONTINUE
      CALL UNMSG
     1     ('Cannot find undefined index - error in test algorithm.')

C established lui as lowest undefined index
270   CONTINUE
      CALL SETMSG ('12 15 16', '<Inquire polymarker representation> ' //
     1             'should return attributes for bundle #1 when '     //
     2             'inquiring an undefined entry as REALIZED.')

C inquire undefined bundle as REALIZED
      CALL PQPMR  (WKID, LUI, PREALI, ERRIND, MTYPE,  MSZSF,  COLI)
      CALL CHKINQ ('pqpmr', ERRIND)
C inquire bundle #1 as REALIZED
      CALL PQPMR  (WKID, 1,   PREALI, ERRIND, MTYPE2, MSZSF2, COLI2)
      CALL CHKINQ ('pqpmr', ERRIND)
C should have same attributes
      CALL IFPF (MTYPE .EQ. MTYPE2 .AND.
     1           MSZSF .EQ. MSZSF2 .AND.
     2           COLI  .EQ. COLI2)

C  If number of initialized entries >= implementation max then skip test
C  of setting undefined entry - goto redefined_test.
      IF (NIE .GE. MNE) THEN
         CALL INMSG ('Skipping undefined-test because all ' //
     1               'polymarker entries are initialized.')
         GOTO 300
      ENDIF

C Check that program allows enough room
      IF (NIE .GE. MAXPM) THEN
         CALL INMSG ('Skipping undefined-test because number ' //
     1               'of initialized entries exceed program limits.')
         GOTO 300
      ENDIF

C set values for attributes
      MTYPE2 = 2
      MSZSF2 = 0.25
      COLI2  = 4
      CALL PSPMR (WKID, LUI, MTYPE2, MSZSF2, COLI2)

      CALL PQEPMI (WKID, 1, ERRIND, LISTOT, IDUM)
      CALL CHKINQ ('pqepmi', ERRIND)

      CALL SETMSG ('10 12', 'Defining an undefined entry should ' //
     1             'increment the number of defined entries.')
      CALL IFPF (LISTOT .EQ. CNDE + 1)

C check that lui is now among defined entries
      CALL SETMSG ('10 12', 'Undefined bundle entry should be ' //
     1             'reported as defined after set.')
      DO 280 LISTEL = 1, LISTOT
         CALL PQEPMI (WKID, LISTEL, ERRIND, IDUM, PMI)
         CALL CHKINQ ('pqepmi', ERRIND)
         IF (PMI .EQ. LUI) THEN
            CALL PASS
            GOTO 290
         ENDIF
280   CONTINUE
      CALL FAIL
      GOTO 300
290   CONTINUE

      CALL PQPMR (WKID, LUI, PSET, ERRIND, MTYPE, MSZSF, COLI)
      CALL CHKINQ ('pqpmr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'undefined bundle entry.')
      CALL IFPF (MTYPE .EQ. MTYPE2 .AND.
     1           MSZSF .EQ. MSZSF2 .AND.
     2           COLI  .EQ. COLI2)

C *** *** *** *** ***    redefined entries   *** *** *** *** ***
300   CONTINUE

C get current number defined entries
      CALL PQEPMI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqepmi', ERRIND)

C let dpi = a defined polymarker index from middle of list
      CALL PQEPMI (WKID, (CNDE+1)/2, ERRIND, IDUM, DPI)
      CALL CHKINQ ('pqepmi', ERRIND)

C set to first set of values
      MTYPE = 4
      MSZSF = 0.35
      COLI  = 3
      CALL PSPMR (WKID, DPI, MTYPE, MSZSF, COLI)
C re-set to different values
      MTYPE2 = 3
      MSZSF2 = 0.40
      COLI2  = 2
      CALL PSPMR (WKID, DPI, MTYPE2, MSZSF2, COLI2)

C get list size - nnde = new number of defined entries
      CALL PQEPMI (WKID, 1, ERRIND, NNDE, IDUM)
      CALL CHKINQ ('pqepmi', ERRIND)

      CALL SETMSG ('10 12', 'Re-defining a user-defined entry ' //
     1             'should not change number of defined entries.')
      CALL IFPF (NNDE .EQ. CNDE)

C check that dpi is among defined entries
      CALL SETMSG ('10 12', 'Redefined bundle entry should be ' //
     1             'reported as defined after set.')
      DO 320 LISTEL = 1, NNDE
         CALL PQEPMI (WKID, LISTEL, ERRIND, IDUM, PMI)
         CALL CHKINQ ('pqepmi', ERRIND)
         IF (PMI .EQ. DPI) THEN
            CALL PASS
            GOTO 330
         ENDIF
320   CONTINUE
      CALL FAIL
      GOTO 399
330   CONTINUE

      CALL PQPMR (WKID, DPI, PSET, ERRIND, MTYPE, MSZSF, COLI)
      CALL CHKINQ ('pqpmr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'redefined bundle entry.')
      CALL IFPF (MTYPE .EQ. MTYPE2 .AND.
     1           MSZSF .EQ. MSZSF2 .AND.
     2           COLI  .EQ. COLI2)

399   CONTINUE

C *** *** *** *** ***  access all defined entries  *** *** *** *** ***

      CALL SETMSG ('12 13', '<Inquire list of polymarker indices> '  //
     1             'and <inquire polymarker representation> should ' //
     2             'detect all defined entries.')
C get listel-th element of defined polymarker indices
      DO 410 LISTEL = 1, NNDE
         CALL PQEPMI (WKID, LISTEL, ERRIND, IDUM, PMI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 415
         ENDIF
         CALL PQPMR (WKID, PMI, PSET, ERRIND, MTYPE, MSZSF, COLI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 415
         ENDIF
410   CONTINUE
      CALL PASS
415   CONTINUE

666   CONTINUE
      CALL ENDIT

      END
