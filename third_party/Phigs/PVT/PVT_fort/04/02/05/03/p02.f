C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/02                        *
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

      INTEGER    MAXED
C define a number greater than the number of initialized edge entries
      PARAMETER (MAXED=300)

C PHIGS parameter types
      INTEGER    MEDBTE, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6,
     1           IDUM7
      INTEGER    EDI, EFLAG, ETYPE, COLI, EFLAG2, ETYPE2, COLI2

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      REAL       EWDTH, EWDTH2, RDUM1, RDUM2, RDUM3
C used to control tests
      INTEGER    MNE, NIE, AII, LISTEL, LISTOT, DEFI(MAXED)
      INTEGER    LUI, DEI, CNDE, NNDE, NAET, AVET

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      DATA DEFI / MAXED*0 /

      CALL INITGL ('04.02.05.03/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             MEDBTE, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of edge bundle table entries
      MNE = MEDBTE

C *** *** *** *** ***    initialized entries   *** *** *** *** ***

C There should be at least 5 initialized edge bundles - this
C inquiry gets the first, so it should work.  This statement
C is NOT meant to test the requirement of 5 initialized bundles;
C that is done elsewhere.

      CALL SETMSG ('12', '<Inquire list of edge indices> should ' //
     1             'return initialized indices.')
C   nie = number of initialized edge entries
C   aii = an initialized index (the first)
      CALL PQEEDI (WKID, 1, ERRIND, NIE, AII)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         GOTO 200
      ELSE
         CALL PASS
      ENDIF

C get initialized attributes
      CALL PQEDR (WKID, AII, PSET, ERRIND, EFLAG, ETYPE, EWDTH, COLI)
      CALL CHKINQ ('pqedr', ERRIND)

C set different values for attributes

C make sure edgeflag is valid
      IF (EFLAG .EQ. PON) THEN
          EFLAG2 = POFF
      ELSE
          EFLAG2 = PON
      ENDIF

C  get an available edgetype
      CALL PQEDF (SPECWT, 0,    ERRIND, NAET,  IDUM1, IDUM2,
     1            RDUM1, RDUM2, RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)
      CALL PQEDF (SPECWT, (NAET+1)/2, ERRIND, IDUM1, AVET, IDUM2,
     1            RDUM1, RDUM2, RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)

      IF (ETYPE .NE. 1) THEN
         ETYPE2 = 1
      ELSE
         ETYPE2 = AVET
      ENDIF

      EWDTH2 = EWDTH * 1.5
      COLI2  = COLI + 1
      CALL PSEDR (WKID, AII, EFLAG2, ETYPE2, EWDTH2, COLI2)

C get current number of defined entries
      CALL PQEEDI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqeedi', ERRIND)

      CALL SETMSG ('10 12', 'Re-defining a system-initialized entry ' //
     1             'should not change the number of defined entries.')
      CALL IFPF (CNDE .EQ. NIE)

C check that aii is still among defined entries
      CALL SETMSG ('10 12', 'Initialized bundle entry should be ' //
     1             'reported as defined after being set.')

      DO 150 LISTEL = 1, CNDE
         CALL PQEEDI (WKID, LISTEL, ERRIND, IDUM1, EDI)
         CALL CHKINQ ('pqeedi', ERRIND)
         IF (EDI .EQ. AII) THEN
            CALL PASS
            GOTO 160
         ENDIF
150   CONTINUE
      CALL FAIL
      GOTO 200
160   CONTINUE

      CALL PQEDR (WKID, AII, PSET, ERRIND, EFLAG, ETYPE, EWDTH, COLI)
      CALL CHKINQ ('pqedr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'initialized bundle entry.')

      CALL IFPF (EFLAG .EQ. EFLAG2 .AND.
     1           ETYPE .EQ. ETYPE2 .AND.
     2           EWDTH .EQ. EWDTH2 .AND.
     3           COLI  .EQ. COLI2)

C *** *** *** *** ***    undefined entries   *** *** *** *** ***
200   CONTINUE

C get lowest undefined index
C get current number defined entries
      CALL PQEEDI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqeedi', ERRIND)
C defi is originally an array of zeros
      DO 250 LISTEL = 1, CNDE
         CALL PQEEDI (WKID, LISTEL, ERRIND, IDUM1, EDI)
         CALL CHKINQ ('pqeedi', ERRIND)
C mark as defined any index .le. cnde+1
C This will leave at least one UNmarked.
         IF (EDI .LE. CNDE+1) DEFI (EDI) = 1
250   CONTINUE

C first remaining zero indicates undefined entry
      DO 260 EDI = 1, CNDE+1
         IF (DEFI (EDI) .EQ. 0) THEN
C determine lowest undefined index (not in defined list) = lui
            LUI = EDI
            GOTO 270
         ENDIF
260   CONTINUE
      CALL UNMSG
     1     ('Cannot find undefined index - error in test algorithm.')

C established lui as lowest undefined index
270   CONTINUE
      CALL SETMSG ('12 15 16', '<Inquire edge representation> '   //
     1             'should return attributes for bundle #1 when ' //
     2             'inquiring an undefined entry as REALIZED.')

C inquire undefined bundle as REALIZED
      CALL PQEDR  (WKID, LUI, PREALI, ERRIND, EFLAG, ETYPE,
     1             EWDTH,  COLI)
      CALL CHKINQ ('pqedr', ERRIND)
C inquire bundle #1 as REALIZED
      CALL PQEDR  (WKID, 1, PREALI, ERRIND, EFLAG2, ETYPE2,
     1             EWDTH2, COLI2)
      CALL CHKINQ ('pqedr', ERRIND)
C should have same attributes
      CALL IFPF (EFLAG .EQ. EFLAG2 .AND.
     1           ETYPE .EQ. ETYPE2 .AND.
     2           EWDTH .EQ. EWDTH2 .AND.
     3           COLI  .EQ. COLI2)

C  If number of initialized entries >= implementation max then skip test
C  of setting undefined entry - goto redefined_test.
      IF (NIE .GE. MNE) THEN
         CALL INMSG ('Skipping undefined-test because all edge ' //
     1               'entries are initialized.')
         GOTO 300
      ENDIF

C Check that program allows enough room
      IF (NIE .GE. MAXED) THEN
         CALL INMSG ('Skipping undefined-test because number of ' //
     1               'initialized entries exceed program limits.')
         GOTO 300
      ENDIF

C set values for attributes
      EFLAG2 = POFF
      ETYPE2 = 3
      EWDTH2 = 4.0
      COLI2  = 5
      CALL PSEDR (WKID, LUI, EFLAG2, ETYPE2, EWDTH2, COLI2)

      CALL PQEEDI (WKID, 0, ERRIND, LISTOT, IDUM1)
      CALL CHKINQ ('pqeedi', ERRIND)

      CALL SETMSG ('10 12', 'Defining an undefined entry should ' //
     1             'increment the number of defined entries.')
      CALL IFPF (LISTOT .EQ. CNDE + 1)

C check that lui is now among defined entries
      CALL SETMSG ('10 12', 'Undefined bundle entry should be ' //
     1             'reported as defined after set.')
      DO 280 LISTEL = 1, LISTOT
         CALL PQEEDI (WKID, LISTEL, ERRIND, IDUM1, EDI)
         CALL CHKINQ ('pqeedi', ERRIND)
         IF (EDI .EQ. LUI) THEN
            CALL PASS
            GOTO 290
         ENDIF
280   CONTINUE
      CALL FAIL
      GOTO 300
290   CONTINUE

      CALL PQEDR (WKID, LUI, PSET, ERRIND, EFLAG, ETYPE, EWDTH, COLI)
      CALL CHKINQ ('pqedr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'undefined bundle entry.')
      CALL IFPF (EFLAG .EQ. EFLAG2 .AND.
     1           ETYPE .EQ. ETYPE2 .AND.
     2           EWDTH .EQ. EWDTH2 .AND.
     3           COLI  .EQ. COLI2)

C *** *** *** *** ***    redefined entries   *** *** *** *** ***
300   CONTINUE

C get current number defined entries
      CALL PQEEDI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqeedi', ERRIND)

C let dei = a defined edge index from middle of list
      CALL PQEEDI (WKID, (CNDE+1)/2, ERRIND, IDUM1, DEI)
      CALL CHKINQ ('pqeedi', ERRIND)

C set to first set of values
      CALL PQEDF (SPECWT, (NAET+1)/2, ERRIND, IDUM1, ETYPE, IDUM2,
     1            RDUM1, RDUM2, RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)
      EFLAG = PON
      EWDTH = 3.0
      COLI  = 4
      CALL PSEDR (WKID, DEI, EFLAG, ETYPE, EWDTH, COLI)
C re-set to different values
      CALL PQEDF (SPECWT, NAET, ERRIND, IDUM1, ETYPE2, IDUM2,
     1            RDUM1, RDUM2, RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)
      EFLAG2 = POFF
      EWDTH2 = 4.0
      COLI2  = 5
      CALL PSEDR (WKID, DEI, EFLAG2, ETYPE2, EWDTH2, COLI2)

C get list size - nnde = new number of defined entries
      CALL PQEEDI (WKID, 0, ERRIND, NNDE, IDUM1)
      CALL CHKINQ ('pqeedi', ERRIND)

      CALL SETMSG ('10 12', 'Re-defining a user-defined entry ' //
     1             'should not change number of defined entries.')
      CALL IFPF (NNDE .EQ. CNDE)

C check that dei is among defined entries
      CALL SETMSG ('10 12', 'Redefined bundle entry should be ' //
     1             'reported as defined after set.')
      DO 320 LISTEL = 1, NNDE
         CALL PQEEDI (WKID, LISTEL, ERRIND, IDUM1, EDI)
         CALL CHKINQ ('pqeedi', ERRIND)
         IF (EDI .EQ. DEI) THEN
            CALL PASS
            GOTO 330
         ENDIF
320   CONTINUE
      CALL FAIL
      GOTO 399
330   CONTINUE

      CALL PQEDR (WKID, DEI, PSET, ERRIND, EFLAG, ETYPE, EWDTH, COLI)
      CALL CHKINQ ('pqedr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'redefined bundle entry.')
      CALL IFPF (EFLAG .EQ. EFLAG2 .AND.
     1           ETYPE .EQ. ETYPE2 .AND.
     2           EWDTH .EQ. EWDTH2 .AND.
     3           COLI  .EQ. COLI2)

399   CONTINUE

C *** *** *** ***   access all defined entries   *** *** *** ***

      CALL SETMSG ('12 13', '<Inquire list of edge indices> and ' //
     1             '<inquire edge representation> should detect ' //
     2             'all defined entries.')
C get listel-th element of defined edge indices
      DO 410 LISTEL = 1, NNDE
         CALL PQEEDI (WKID, LISTEL, ERRIND, IDUM1, EDI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 415
         ENDIF
         CALL PQEDR (WKID, EDI, PSET, ERRIND, EFLAG, ETYPE, EWDTH,
     1               COLI)
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
