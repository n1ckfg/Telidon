C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.04/02                        *
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
C define a number greater than the number of initialized pattern entries
      PARAMETER (MAXPL=300)

C PHIGS parameter types
      INTEGER    MPAI, PAI, DIMX, DIMY, ISC, ISR, DX, DY, DX2, DY2
      PARAMETER  (DIMX = 100, DIMY = 100)
      INTEGER    COLIA(DIMX,DIMY), COLIA2(DIMX, DIMY)

      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      LOGICAL    ARREQ, PATAVL

C used to control tests
      INTEGER    NIE, AII, LISTEL, LISTOT, DEFI(MAXPL)
      INTEGER    LUI, DPI, CNDE, NNDE, I, J

      CHARACTER  MSG*300

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      DATA DEFI / MAXPL*0 /

      CALL INITGL ('04.02.05.04/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      IF (.NOT. PATAVL(SPECWT)) THEN
         CALL INMSG ('Skipping all tests because pattern interior ' //
     1               'style is not supported on this workstation.')
         GOTO 666
      ENDIF

C determine mpai = max # pattern entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             IDUM5, MPAI, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)


C *** *** *** *** ***    initialized entries   *** *** *** *** ***

C There should be at least 1 predefined pattern -
C This statement is NOT meant to test the requirement of
C 1 predefined pattern; that is done elsewhere.

      CALL SETMSG ('3', '<Inquire list of pattern indices> should ' //
     1             'return initialized indices.')
C   nie = number of initialized pattern entries
C   aii = an initialized index (the first)
      CALL PQEPAI (WKID, 1, ERRIND, NIE, AII)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         GOTO 200
      ELSE
         CALL PASS
      ENDIF

C get initialized attributes
      CALL PQPAR (WKID, AII, PSET, DIMX, DIMY, ERRIND, DX, DY, COLIA)
C check errind for overflow
      IF (ERRIND .EQ. 2001) THEN
         WRITE (MSG, '(A,A,2I5,A)') 'PQPAR returned Fortran error ',
     1          '2001: declared array size of (', DIMX, DIMY,
     2          ') insufficient.'
         CALL INMSG (MSG)
         GOTO 200
      ENDIF
      CALL CHKINQ ('pqpar', ERRIND)

C set different values for attributes
      DO 80 I = 1, DX
         DO 75 J = 1, DY
            COLIA2(I,J) = COLIA(I,J) +1
75       CONTINUE
80    CONTINUE
      ISC = 1
      ISR = 1
      DX2 = DX
      DY2 = DY
      CALL PSPAR (WKID, AII, DIMX, DIMY, ISC, ISR, DX2, DY2, COLIA2)

C get current number of defined entries
      CALL PQEPAI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)

      CALL SETMSG ('1 3', 'Redefining a system-initialized entry ' //
     1             'should not change the number of defined entries.')
      CALL IFPF (CNDE .EQ. NIE)

C check that aii is still among defined entries
      CALL SETMSG ('1 3', 'Initialized table entry should be ' //
     1             'reported as defined after being set.')

      DO 150 LISTEL = 1, NIE
         CALL PQEPAI (WKID, LISTEL, ERRIND, IDUM1, PAI)
         CALL CHKINQ ('pqepai', ERRIND)
         IF (PAI .EQ. AII) THEN
            CALL PASS
            GOTO 160
         ENDIF
150   CONTINUE
      CALL FAIL
      GOTO 200
160   CONTINUE

      CALL PQPAR (WKID, AII, PSET, DIMX, DIMY, ERRIND, DX, DY, COLIA)
      CALL CHKINQ ('pqpar', ERRIND)
      CALL SETMSG ('2 5', 'New values should be set for ' //
     1             'initialized table entry.')
      CALL IFPF (DX2 .EQ. DX   .AND.
     1           DY2 .EQ. DY   .AND.
     2           ARREQ(DIMX, DIMY, ISC, ISR, DX2, DY2, COLIA2, COLIA))

C *** *** *** *** ***    undefined entries   *** *** *** *** ***
200   CONTINUE

C get lowest undefined index
C get current number defined entries
      CALL PQEPAI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)
C defi is originally an array of zeros
      DO 250 LISTEL = 1, CNDE
         CALL PQEPAI (WKID, LISTEL, ERRIND, IDUM1, PAI)
         CALL CHKINQ ('pqepai', ERRIND)
C mark as defined any index .le. cnde+1
C This will leave at least one UNmarked
         IF (PAI .LE. CNDE+1) DEFI (PAI) = 1
250   CONTINUE

C first remaining zero indicates undefined entry
      DO 260 PAI = 1, CNDE+1
         IF (DEFI (PAI) .EQ. 0) THEN
C determine lowest undefined index (not in defined list) = lui
            LUI = PAI
            GOTO 270
         ENDIF
260   CONTINUE
      CALL UNMSG
     1     ('Cannot find undefined index - error in test algorithm.')

C established lui as lowest undefined index
270   CONTINUE
C inquire undefined table entry as REALIZED
      CALL PQPAR  (WKID, LUI, PREALI, DIMX, DIMY, ERRIND, DX, DY, COLIA)
C check errind for overflow
      IF (ERRIND .EQ. 2001) THEN
         WRITE (MSG, '(A,A,2I5,A)') 'PQPAR returned Fortran error ',
     1          '2001: declared array size of (', DIMX, DIMY,
     2          ') insufficient.'
         CALL INMSG (MSG)
         GOTO 350
      ENDIF
      CALL CHKINQ ('pqpar', ERRIND)

C inquire pattern index #1 as REALIZED
      CALL PQPAR  (WKID, 1, PREALI, DIMX, DIMY, ERRIND, DX2,DY2, COLIA2)
C check errind for overflow
      IF (ERRIND .EQ. 2001) THEN
         WRITE (MSG, '(A,A,2I5,A)') 'PQPAR returned Fortran error ',
     1          '2001: declared array size of (', DIMX, DIMY,
     2          ') insufficient.'
         CALL INMSG (MSG)
         GOTO 350
      ENDIF
      CALL CHKINQ ('pqpar', ERRIND)

      CALL SETMSG ('3 7', '<Inquire pattern representation> '       //
     1             'should return attributes for pattern index #1 ' //
     2             'when inquiring an undefined entry as REALIZED.')
C should have same attributes
      CALL IFPF (DX2 .EQ. DX   .AND.
     1           DY2 .EQ. DY   .AND.
     2           ARREQ(DIMX, DIMY, 1,1, DX, DY, COLIA, COLIA2))

350   CONTINUE

C  If number of initialized entries >= implementation max then skip test
C  of setting undefined entry - goto redefined_test.
      IF (NIE .GE. MPAI) THEN
         CALL INMSG ('Skipping undefined-test because all pattern ' //
     1               'table entries are initialized.')
         GOTO 400
      ENDIF

C Check that program allows enough room
      IF (NIE .GE. MAXPL) THEN
         CALL INMSG ('Skipping undefined-test because number ' //
     1               'of initialized entries exceed program limits.')
         GOTO 400
      ENDIF

C set values for attributes
      ISC = 4
      ISR = 5
      DX2 = 2
      DY2 = 2
      COLIA2(4,5) = 33
      COLIA2(5,5) = 53
      COLIA2(4,6) = 32
      COLIA2(5,6) = 48
      CALL PSPAR (WKID, LUI, DIMX, DIMY, ISC, ISR, DX2, DY2, COLIA2)
      CALL PQEPAI (WKID, 0, ERRIND, LISTOT, IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)

      CALL SETMSG ('1 3', 'Defining an undefined entry should ' //
     1             'increment the number of defined entries.')
      CALL IFPF (LISTOT .EQ. CNDE + 1)

C check that lui is now among defined entries
      CALL SETMSG ('1 3', 'Undefined table entry should be ' //
     1             'reported as defined after set.')
      DO 380 LISTEL = 1, LISTOT
         CALL PQEPAI (WKID, LISTEL, ERRIND, IDUM1, PAI)
         CALL CHKINQ ('pqepai', ERRIND)
         IF (PAI .EQ. LUI) THEN
            CALL PASS
            GOTO 390
         ENDIF
380   CONTINUE
      CALL FAIL
      GOTO 400
390   CONTINUE

      CALL PQPAR (WKID, LUI, PSET, DIMX, DIMY, ERRIND, DX, DY, COLIA)
      CALL CHKINQ ('pqpar', ERRIND)
      CALL SETMSG ('2 5', 'New values should be set for ' //
     1             'undefined table entry.')
      CALL IFPF (DX     .EQ. DX2             .AND.
     1           DY     .EQ. DY2             .AND.
     2           ARREQ(DIMX, DIMY, ISC, ISR, DX2, DY2, COLIA2, COLIA))

C *** *** *** *** ***    redefined entries   *** *** *** *** ***
400   CONTINUE

C get current number defined entries
      CALL PQEPAI (WKID, 0, ERRIND, CNDE, IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)

C let dpi = a defined pattern index from middle of list
      CALL PQEPAI (WKID, (CNDE+1)/2, ERRIND, IDUM1, DPI)
      CALL CHKINQ ('pqepai', ERRIND)

C set to first set of values
      ISC = 1
      ISR = 1
      DX = 3
      DY = 2
      COLIA(1,1) = 8
      COLIA(2,1) = 22
      COLIA(3,1) = 36
      COLIA(1,2) = 19
      COLIA(2,2) = 53
      COLIA(3,2) = 89
      CALL PSPAR (WKID, DPI, DIMX, DIMY, ISC, ISR, DX, DY, COLIA)
C re-set to different values
      DX2  = 2
      DY2  = 2
      COLIA2(1,1) = 3
      COLIA2(2,1) = 19
      COLIA2(1,2) = 9
      COLIA2(2,2) = 47
      CALL PSPAR (WKID, DPI, DIMX, DIMY, ISC, ISR, DX2, DY2, COLIA2)

C get list size - nnde = new number of defined entries
      CALL PQEPAI (WKID, 0, ERRIND, NNDE, IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)

      CALL SETMSG ('1 3', 'Redefining a user-defined entry should ' //
     1             'not change number of defined entries.')
      CALL IFPF (NNDE .EQ. CNDE)

C check that dpi is among defined entries
      CALL SETMSG ('1 3', 'Redefined table entry should be ' //
     1             'reported as defined after set.')
      DO 420 LISTEL = 1, NNDE
         CALL PQEPAI (WKID, LISTEL, ERRIND, IDUM1, PAI)
         CALL CHKINQ ('pqepai', ERRIND)
         IF (PAI .EQ. DPI) THEN
            CALL PASS
            GOTO 430
         ENDIF
420   CONTINUE
      CALL FAIL
      GOTO 499
430   CONTINUE

      CALL PQPAR (WKID, DPI, PSET, DIMX, DIMY, ERRIND, DX, DY, COLIA)
      CALL CHKINQ ('pqpar', ERRIND)
      CALL SETMSG ('2 5', 'New values should be set for ' //
     1             'redefined table entry.')
      CALL IFPF (DX  .EQ. DX2 .AND.
     1           DY  .EQ. DY2 .AND.
     2           ARREQ(DIMX, DIMY, ISC, ISR, DX2, DY2, COLIA2, COLIA))

499   CONTINUE

C *** *** *** *** ***  access all defined entries  *** *** *** *** ***

      CALL SETMSG ('3 4', '<Inquire list of pattern indices> and '   //
     1             '<inquire pattern representation> should detect ' //
     2             'all defined entries.')
C get listel-th element of defined pattern indices
      DO 510 LISTEL = 1, NNDE
         CALL PQEPAI (WKID, LISTEL, ERRIND, IDUM1, PAI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 515
         ENDIF
         CALL PQPAR (WKID, PAI, PSET, DIMX, DIMY, ERRIND, DX, DY, COLIA)
C check errind for overflow
         IF (ERRIND .EQ. 2001 .OR. ERRIND .EQ. 0) THEN
C OK so far
         ELSE
            CALL FAIL
            GOTO 515
         ENDIF
510   CONTINUE
      CALL PASS

515   CONTINUE

666   CONTINUE
      CALL ENDIT
      END
