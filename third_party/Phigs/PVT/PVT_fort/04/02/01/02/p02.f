C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/02                        *
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
C define a number greater than the number of initialized polyline entries
      PARAMETER (MAXPL=300)

C PHIGS parameter types
      INTEGER    MPLBTE, MPMBTE, MTXBTE, MINBTE, MEDBTE, MPAI, MCOLI,
     1           VWTBI
      INTEGER    PLI, LTYPE, COLI, LTYPE2, COLI2, PSET, PREALI

      PARAMETER  (PSET = 0, PREALI = 1)

      REAL       LWDTH, LWDTH2
C used to control tests
      INTEGER    MNE, NIE, AII, LISTEL, LISTOT, DEFI(MAXPL), IDUM
      INTEGER    LUI, DPI, CNDE, NNDE

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      DATA DEFI / MAXPL*0 /

      CALL INITGL ('04.02.01.02/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, MPLBTE, MPMBTE, MTXBTE, MINBTE,
     1             MEDBTE, MPAI, MCOLI, VWTBI)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of polyline bundle table entries
      MNE = MPLBTE

C *** *** *** *** ***    initialized entries   *** *** *** *** ***

C There should be at least 5 initialized polyline bundles - this
C inquiry gets the first, so it should work.  This statement
C is NOT meant to test the requirement of 5 initialized bundles;
C that is done elsewhere.

      CALL SETMSG ('12', '<Inquire list of polyline indices> ' //
     1             'should return initialized indices.')
C   nie = number of initialized polyline entries
C   aii = an initialized index (the first)
      CALL PQEPLI (WKID, 1, ERRIND, NIE, AII)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         GOTO 200
      ELSE
         CALL PASS
      ENDIF

C get initialized attributes
      CALL PQPLR (WKID, AII, PSET, ERRIND, LTYPE, LWDTH, COLI)
      CALL CHKINQ ('pqplr', ERRIND)

C set different values for attributes

C make sure linetype is valid
      IF (LTYPE .LT. 4) THEN
         LTYPE2 = LTYPE + 1
      ELSE
         LTYPE2 = 3
      ENDIF
      LWDTH2 = LWDTH * 1.5
      COLI2  = COLI  + 1
      CALL PSPLR (WKID, AII, LTYPE2, LWDTH2, COLI2)

C get current number of defined entries
      CALL PQEPLI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqepli', ERRIND)

      CALL SETMSG ('10 12', 'Re-defining a system-initialized ' //
     1             'entry should not change the number of defined '//
     2             'entries.')
      CALL IFPF (CNDE .EQ. NIE)

C check that aii is still among defined entries
      CALL SETMSG ('10 12', 'Initialized bundle entry should ' //
     1             'be reported as defined after being set.')

      DO 150 LISTEL = 1, NIE
         CALL PQEPLI (WKID, LISTEL, ERRIND, IDUM, PLI)
         CALL CHKINQ ('pqepli', ERRIND)
         IF (PLI .EQ. AII) THEN
            CALL PASS
            GOTO 160
         ENDIF
150   CONTINUE
      CALL FAIL
      GOTO 200
160   CONTINUE

      CALL PQPLR (WKID, AII, PSET, ERRIND, LTYPE, LWDTH, COLI)
      CALL CHKINQ ('pqplr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'initialized bundle entry.')

      CALL IFPF (LTYPE .EQ. LTYPE2 .AND.
     1           LWDTH .EQ. LWDTH2 .AND.
     2           COLI  .EQ. COLI2)

C *** *** *** *** ***    undefined entries   *** *** *** *** ***
200   CONTINUE

C get lowest undefined index
C get current number defined entries
      CALL PQEPLI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqepli', ERRIND)
C defi is originally an array of zeros
      DO 250 LISTEL = 1, CNDE
         CALL PQEPLI (WKID, LISTEL, ERRIND, IDUM, PLI)
         CALL CHKINQ ('pqepli', ERRIND)
C mark as defined any index .le. cnde+1
C This will leave at least one UNmarked.
         IF (PLI .LE. CNDE+1) DEFI (PLI) = 1
250   CONTINUE

C first remaining zero indicates undefined entry
      DO 260 PLI = 1, CNDE+1
         IF (DEFI (PLI) .EQ. 0) THEN
C determine lowest undefined index (not in defined list) = lui
            LUI = PLI
            GOTO 270
         ENDIF
260   CONTINUE
      CALL UNMSG
     1     ('Cannot find undefined index - error in test algorithm.')

C established lui as lowest undefined index
270   CONTINUE
      CALL SETMSG ('12 15 16', '<Inquire polyline representation> ' //
     1             'should return attributes for bundle #1 when '   //
     2             'inquiring an undefined entry as REALIZED.')

C inquire undefined bundle as REALIZED
      CALL PQPLR  (WKID, LUI, PREALI, ERRIND, LTYPE,  LWDTH,  COLI)
      CALL CHKINQ ('pqplr', ERRIND)
C inquire bundle #1 as REALIZED
      CALL PQPLR  (WKID, 1,   PREALI, ERRIND, LTYPE2, LWDTH2, COLI2)
      CALL CHKINQ ('pqplr', ERRIND)
C should have same attributes
      CALL IFPF (LTYPE .EQ. LTYPE2 .AND.
     1           LWDTH .EQ. LWDTH2 .AND.
     2           COLI  .EQ. COLI2)

C  If number of initialized entries >= implementation max then skip test
C  of setting undefined entry - goto redefined_test.
      IF (NIE .GE. MNE) THEN
         CALL INMSG ('Skipping undefined-test because all polyline ' //
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
      LTYPE2 = 3
      LWDTH2 = 4.0
      COLI2  = 5
      CALL PSPLR (WKID, LUI, LTYPE2, LWDTH2, COLI2)

      CALL PQEPLI (WKID, 1, ERRIND, LISTOT, IDUM)
      CALL CHKINQ ('pqepli', ERRIND)

      CALL SETMSG ('10 12', 'Defining an undefined entry should '//
     1             'increment the number of defined entries.')
      CALL IFPF (LISTOT .EQ. CNDE + 1)

C check that lui is now among defined entries
      CALL SETMSG ('10 12', 'Undefined bundle entry should be '//
     1             'reported as defined after set.')
      DO 280 LISTEL = 1, LISTOT
         CALL PQEPLI (WKID, LISTEL, ERRIND, IDUM, PLI)
         CALL CHKINQ ('pqepli', ERRIND)
         IF (PLI .EQ. LUI) THEN
            CALL PASS
            GOTO 290
         ENDIF
280   CONTINUE
      CALL FAIL
      GOTO 300
290   CONTINUE

      CALL PQPLR (WKID, LUI, PSET, ERRIND, LTYPE, LWDTH, COLI)
      CALL CHKINQ ('pqplr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'undefined bundle entry.')
      CALL IFPF (LTYPE .EQ. LTYPE2 .AND.
     1           LWDTH .EQ. LWDTH2 .AND.
     2           COLI  .EQ. COLI2)

C *** *** *** *** ***    redefined entries   *** *** *** *** ***
300   CONTINUE

C get current number defined entries
      CALL PQEPLI (WKID, 1, ERRIND, CNDE, IDUM)
      CALL CHKINQ ('pqepli', ERRIND)

C let dpi = a defined polyline index from middle of list
      CALL PQEPLI (WKID, (CNDE+1)/2, ERRIND, IDUM, DPI)
      CALL CHKINQ ('pqepli', ERRIND)

C set to first set of values
      LTYPE = 2
      LWDTH = 3.0
      COLI  = 4
      CALL PSPLR (WKID, DPI, LTYPE, LWDTH, COLI)
C re-set to different values
      LTYPE2 = 3
      LWDTH2 = 4.0
      COLI2  = 5
      CALL PSPLR (WKID, DPI, LTYPE2, LWDTH2, COLI2)

C get list size - nnde = new number of defined entries
      CALL PQEPLI (WKID, 1, ERRIND, NNDE, IDUM)
      CALL CHKINQ ('pqepli', ERRIND)

      CALL SETMSG ('10 12', 'Re-defining a user-defined entry ' //
     1             'should not change number of defined entries.')
      CALL IFPF (NNDE .EQ. CNDE)

C check that dpi is among defined entries
      CALL SETMSG ('10 12', 'Redefined bundle entry should ' //
     1             'be reported as defined after set.')
      DO 320 LISTEL = 1, NNDE
         CALL PQEPLI (WKID, LISTEL, ERRIND, IDUM, PLI)
         CALL CHKINQ ('pqepli', ERRIND)
         IF (PLI .EQ. DPI) THEN
            CALL PASS
            GOTO 330
         ENDIF
320   CONTINUE
      CALL FAIL
      GOTO 399
330   CONTINUE

      CALL PQPLR (WKID, DPI, PSET, ERRIND, LTYPE, LWDTH, COLI)
      CALL CHKINQ ('pqplr', ERRIND)
      CALL SETMSG ('11 14', 'New values should be set for ' //
     1             'redefined bundle entry.')
      CALL IFPF (LTYPE .EQ. LTYPE2 .AND.
     1           LWDTH .EQ. LWDTH2 .AND.
     2           COLI  .EQ. COLI2)

399   CONTINUE

C *** *** *** *** ***  access all defined entries  *** *** *** *** ***

      CALL SETMSG ('12 13', '<Inquire list of polyline indices> ' //
     1             'and <inquire polyline representation> should '//
     2             'detect all defined entries.')
C get listel-th element of defined polyline indices
      DO 410 LISTEL = 1, NNDE
         CALL PQEPLI (WKID, LISTEL, ERRIND, IDUM, PLI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 415
         ENDIF
         CALL PQPLR (WKID, PLI, PSET, ERRIND, LTYPE, LWDTH, COLI)
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
