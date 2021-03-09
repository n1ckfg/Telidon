C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/07                        *
C  *    TEST TITLE : Linewidth facilities                  *
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

      INTEGER    NALW, IX, IDUM1, IDUM2, IDUM3

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL       NOMLW, MINLW, MAXLW, LWIDTH, MINSC, MAXSC, INCR, THISC

      LOGICAL    VALOK, RLZLW

      CHARACTER  MSG*300

      CALL INITGL ('04.02.01.02/07')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  <inquire polyline facilities> to determine:
C     nalw  = number of available linewidths
C     nomlw = nominal linewidth
C     minlw = minimum linewidth
C     maxlw = maximum linewidth

      CALL PQPLF (SPECWT, 1, ERRIND, IDUM1, IDUM2,
     1            NALW, NOMLW, MINLW, MAXLW, IDUM3)
      CALL CHKINQ ('pqplf', ERRIND)

      WRITE (MSG, '(A,I6,3(A,E13.4))')
     1  'Implementation reports number of available linewidths = ',
     2   NALW, ';  nominal, minimum, maximum linewidths = ',
     3   NOMLW, ',', MINLW, ',', MAXLW
      CALL INMSG (MSG)

      CALL SETMSG ('39', 'Maximum linewidth should not be less ' //
     1             'than minimum.')
      CALL IFPF (MAXLW .GE. MINLW)

      CALL SETMSG ('40', 'The nominal linewidth, minimum '    //
     1             'linewidth, and maximum linewidth should ' //
     2             'all be positive.')
      CALL IFPF (MINLW .GT. 0 .AND. MAXLW .GT. 0 .AND. NOMLW .GT. 0)

      CALL SETMSG ('41', 'The reported number of available ' //
     1             'linewidths should be at least 0.')
      CALL IFPF (NALW .GE. 0)

C  minsc = minimum effective scale factor
C  maxsc = maximum effective scale factor
      MINSC = MINLW/NOMLW
      MAXSC = MAXLW/NOMLW

      CALL SETMSG ('42', 'All linewidth scale factors should be ' //
     1             'accepted as valid.')

      CALL ERRCTL (.TRUE.)

      LWIDTH = MINSC/10
      CALL PSPLR (WKID, 4, 1, LWIDTH, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      LWIDTH = MAXSC*10
      CALL PSPLR (WKID, 4, 1, LWIDTH, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      LWIDTH = -10.0
      CALL PSPLR (WKID, 4, 1, LWIDTH, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      CALL PASS
      VALOK = .TRUE.
      GOTO 600

C  fail and informational message about scale_factor
500   CONTINUE
      CALL FAIL
      VALOK = .FALSE.
      WRITE (MSG, '(A,F11.2,A,I6,A)') 'Linewidth scale factor of ',
     1         LWIDTH, ' rejected with error code = ', ERRSIG, '.'
      CALL INMSG (MSG)

600   CONTINUE

      CALL SETMSG ('11 15 39', 'The reported minimum linewidth ' //
     1             'should be realizable.')
      CALL IFPF (RLZLW (MINSC, MINSC))

      CALL SETMSG ('11 15 39', 'The reported maximum linewidth ' //
     1             'should be realizable.')
      CALL IFPF (RLZLW (MAXSC, MAXSC))

      IF (.NOT. VALOK) THEN
         CALL INMSG ('Skipping tests of linewidth coercion, since ' //
     1               'validity test was failed.')
         GOTO 610
      ENDIF

      CALL SETMSG ('11 15 39', 'A linewidth scale factor set as ' //
     1             'less than the minimum should be realized as ' //
     2             'the reported minimum.')
      CALL IFPF (RLZLW (MINSC/3, MINSC))

      CALL SETMSG ('11 15 39', 'A linewidth scale factor set as ' //
     1             'greater than the maximum should be realized ' //
     2             'as the reported maximum.')
      CALL IFPF (RLZLW (MAXSC*3, MAXSC))

      CALL SETMSG ('11 15 39', 'A linewidth scale factor set as ' //
     1             'less than zero should be realized as the '    //
     2             'reported minimum.')
      CALL IFPF (RLZLW (-ABS(MAXSC), MINSC))

C  skip_coerce:
610   CONTINUE

      IF (NALW .NE. 0) GOTO 666

      CALL SETMSG ('11 15 39', 'If the reported number of available ' //
     1             'linewidths is zero, then all linewidths between ' //
     2             'the reported minimum and maximum should be '      //
     3             'realizable.')

      INCR = (MAXSC/MINSC) ** 0.25
      THISC = MINSC
      DO 620 IX = 1,3
         THISC = THISC * INCR
         IF (RLZLW (THISC, THISC)) THEN
C           OK so far
         ELSE
            CALL FAIL
            GOTO 666
         ENDIF
620   CONTINUE
      CALL PASS

C  done:
666   CONTINUE
      CALL ERRCTL (.FALSE.)
      CALL ENDIT
      END

