C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/02                        *
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
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, MINBTE, MPAI,
     1           MCOLI
      INTEGER    II, INTS, INTS2, STYLI, STYLI2, COLI, COLI2

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C used to control tests
      INTEGER    MNE, NIE, AII, LISTEL, LISTOT, DEFI(MAXPL), IDUM
      INTEGER    LUI, DII, CNDE, NNDE

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      DATA DEFI / MAXPL*0 /

      CALL INITGL ('04.02.05.02/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, MINBTE,
     1             IDUM4, MPAI, MCOLI, IDUM5)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of interior bundle table entries
      MNE = MINBTE

C *** *** *** *** ***    initialized entries   *** *** *** *** ***

C There should be at least 5 initialized interior bundles - this
C inquiry gets the first, so it should work.  This statement
C is NOT meant to test the requirement of 5 initialized bundles;
C that is done elsewhere.

      CALL SETMSG ('13', '<Inquire list of interior indices> ' //
     1             'should return initialized indices.')

C   nie = number of initialized interior entries
C   aii = an initialized index (the first)
      CALL PQEII (WKID, 1, ERRIND, NIE, AII)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         GOTO 200
      ELSE
         CALL PASS
      ENDIF

C get initialized attributes
      CALL PQIR (WKID, AII, PSET, ERRIND, INTS, STYLI, COLI)
      CALL CHKINQ ('pqir', ERRIND)

C set different values for attributes

C make sure style is valid
      IF (INTS .EQ. PHOLLO) THEN
          INTS2 = PISEMP
      ELSE
          INTS2 = PHOLLO
      ENDIF
      STYLI2 = STYLI + 1
      COLI2  = COLI  + 1
      CALL PSIR (WKID, AII, INTS2, STYLI2, COLI2)

C get current number of defined entries
      CALL PQEII (WKID, 0, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqeii', ERRIND)

      CALL SETMSG ('11 13', 'Redefining a system-initialized entry ' //
     1             'should not change the number of defined entries.')
      CALL IFPF (CNDE .EQ. NIE)

C check that aii is still among defined entries
      CALL SETMSG ('11 13', 'Initialized bundle entry should ' //
     1             'be reported as defined after being set.')

      DO 150 LISTEL = 1, NIE
         CALL PQEII (WKID, LISTEL, ERRIND, IDUM, II)
         CALL CHKINQ ('pqeii', ERRIND)
         IF (II .EQ. AII) THEN
            CALL PASS
            GOTO 160
         ENDIF
150   CONTINUE
      CALL FAIL
      GOTO 200
160   CONTINUE

      CALL PQIR (WKID, AII, PSET, ERRIND, INTS, STYLI, COLI)
      CALL CHKINQ ('pqir', ERRIND)
      CALL SETMSG ('12 15', 'New values should be set for ' //
     1             'initialized bundle entry.')

      CALL IFPF (INTS  .EQ. INTS2  .AND.
     1           STYLI .EQ. STYLI2 .AND.
     2           COLI  .EQ. COLI2)

C *** *** *** *** ***    undefined entries   *** *** *** *** ***
200   CONTINUE

C get lowest undefined index
C get current number defined entries
      CALL PQEII (WKID, 0, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqeii', ERRIND)
C defi is originally an array of zeros
      DO 250 LISTEL = 1, CNDE
         CALL PQEII (WKID, LISTEL, ERRIND, IDUM, II)
         CALL CHKINQ ('pqeii', ERRIND)
C mark as defined any index .le. cnde+1
C This will leave at least one UNmarked.
         IF (II .LE. CNDE+1) DEFI (II) = 1
250   CONTINUE

C first remaining zero indicates undefined entry
      DO 260 II = 1, CNDE+1
         IF (DEFI (II) .EQ. 0) THEN
C determine lowest undefined index (not in defined list) = lui
            LUI = II
            GOTO 270
         ENDIF
260   CONTINUE
      CALL UNMSG
     1     ('Cannot find undefined index - error in test algorithm.')

C established lui as lowest undefined index
270   CONTINUE
      CALL SETMSG ('13 16 17', '<Inquire interior representation> ' //
     1             'should return attributes for bundle #1 when '   //
     2             'inquiring an undefined entry as REALIZED.')

C inquire undefined bundle as REALIZED
      CALL PQIR  (WKID, LUI, PREALI, ERRIND, INTS, STYLI, COLI)
      CALL CHKINQ ('pqir', ERRIND)
C inquire bundle #1 as REALIZED
      CALL PQIR  (WKID, 1, PREALI, ERRIND, INTS2, STYLI2, COLI2)
      CALL CHKINQ ('pqir', ERRIND)
C should have same attributes
      CALL IFPF (INTS  .EQ. INTS2  .AND.
     1           STYLI .EQ. STYLI2 .AND.
     2           COLI  .EQ. COLI2)

C  If number of initialized entries >= implementation max then skip test
C  of setting undefined entry - goto redefined_test.
      IF (NIE .GE. MNE) THEN
         CALL INMSG ('Skipping undefined-test because all interior '//
     1               'entries are initialized.')
         GOTO 300
      ENDIF

C Check that program allows enough room
      IF (NIE .GE. MAXPL) THEN
         CALL INMSG ('Skipping undefined-test because number ' //
     1               'of initialized entries exceed program limits.')
         GOTO 300
      ENDIF

C set values for attributes
      INTS2  = PISEMP
      STYLI2 = 1
      COLI2  = 5
      CALL PSIR (WKID, LUI, INTS2, STYLI2, COLI2)

      CALL PQEII (WKID, 0, ERRIND, LISTOT, IDUM)
      CALL CHKINQ ('pqeii', ERRIND)

      CALL SETMSG ('11 13', 'Defining an undefined entry should ' //
     1             'increment the number of defined entries.')
      CALL IFPF (LISTOT .EQ. CNDE + 1)

C check that lui is now among defined entries
      CALL SETMSG ('11 13', 'Undefined bundle entry should be ' //
     1             'reported as defined after set.')
      DO 280 LISTEL = 1, LISTOT
         CALL PQEII (WKID, LISTEL, ERRIND, IDUM, II)
         CALL CHKINQ ('pqeii', ERRIND)
         IF (II .EQ. LUI) THEN
            CALL PASS
            GOTO 290
         ENDIF
280   CONTINUE
      CALL FAIL
      GOTO 300
290   CONTINUE

      CALL PQIR (WKID, LUI, PSET, ERRIND, INTS, STYLI, COLI)
      CALL CHKINQ ('pqir', ERRIND)
      CALL SETMSG ('12 15', 'New values should be set for ' //
     1             'undefined bundle entry.')
      CALL IFPF (INTS  .EQ. INTS2  .AND.
     1           STYLI .EQ. STYLI2 .AND.
     2           COLI  .EQ. COLI2)

C *** *** *** *** ***    redefined entries   *** *** *** *** ***
300   CONTINUE

C get current number defined entries
      CALL PQEII (WKID, 0, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqeii', ERRIND)

C let dii = a defined interior index from middle of list
      CALL PQEII (WKID, (CNDE+1)/2, ERRIND, IDUM, DII)
      CALL CHKINQ ('pqeii', ERRIND)

C set to first set of values
      INTS  = PHOLLO
      STYLI = 2
      COLI  = 4
      CALL PSIR (WKID, DII, INTS, STYLI, COLI)
C re-set to different values
      INTS2  = PISEMP
      STYLI2 = 0
      COLI2  = 5
      CALL PSIR (WKID, DII, INTS2, STYLI2, COLI2)

C get list size - nnde = new number of defined entries
      CALL PQEII (WKID, 0, ERRIND, NNDE, IDUM)
      CALL CHKINQ ('pqeii', ERRIND)

      CALL SETMSG ('11 13', 'Redefining a user-defined entry ' //
     1             'should not change number of defined entries.')
      CALL IFPF (NNDE .EQ. CNDE)

C check that dii is among defined entries
      CALL SETMSG ('11 13', 'Redefined bundle entry should ' //
     1             'be reported as defined after set.')
      DO 320 LISTEL = 1, NNDE
         CALL PQEII (WKID, LISTEL, ERRIND, IDUM, II)
         CALL CHKINQ ('pqeii', ERRIND)
         IF (II .EQ. DII) THEN
            CALL PASS
            GOTO 330
         ENDIF
320   CONTINUE
      CALL FAIL
      GOTO 399
330   CONTINUE

      CALL PQIR (WKID, DII, PSET, ERRIND, INTS, STYLI, COLI)
      CALL CHKINQ ('pqir', ERRIND)
      CALL SETMSG ('12 15', 'New values should be set for ' //
     1             'redefined bundle entry.')
      CALL IFPF (INTS  .EQ. INTS2  .AND.
     1           STYLI .EQ. STYLI2 .AND.
     2           COLI  .EQ. COLI2)

399   CONTINUE

C *** *** *** *** ***  access all defined entries  *** *** *** *** ***

      CALL SETMSG ('13 14', '<Inquire list of interior indices> '  //
     1             'and <inquire interior representation> should ' //
     2             'detect all defined entries.')
C get listel-th element of defined interior indices
      DO 410 LISTEL = 1, NNDE
         CALL PQEII (WKID, LISTEL, ERRIND, IDUM, II)
         IF (ERRIND .NE. 0) THEN
             CALL FAIL
             GOTO 415
         ENDIF
         CALL PQIR (WKID, II, PSET, ERRIND, INTS, STYLI, COLI)
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
