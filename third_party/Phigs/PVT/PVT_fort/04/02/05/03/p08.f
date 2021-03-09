C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/08                        *
C  *    TEST TITLE : Edgewidth facilities                  *
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

      INTEGER    NAEW, IX, IDUM1, IDUM2, IDUM3

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      REAL       NOMEW, MINEW, MAXEW, EWIDTH, MINSC, MAXSC, INCR, THISC

      LOGICAL    VALOK, RLZEW

      CHARACTER  MSG*300

      CALL INITGL ('04.02.05.03/08')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  <inquire edge facilities> to determine:
C     naew  = number of available edgewidths
C     nomew = nominal edgewidth
C     minew = minimum edgewidth
C     maxew = maximum edgewidth

      CALL PQEDF (SPECWT, 0, ERRIND, IDUM1, IDUM2, NAEW,
     1            NOMEW, MINEW, MAXEW, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)

      WRITE (MSG, '(A,I6,3(A,E13.4))')
     1   'Implementation reports number of available edgewidths = ',
     2    NAEW, ';  nominal, minimum, maximum edgewidths = ',
     3    NOMEW, ',', MINEW, ',', MAXEW
      CALL INMSG (MSG)

      CALL SETMSG ('42', 'Maximum edgewidth should not be less ' //
     1             'than minimum.')
      CALL IFPF (MAXEW .GE. MINEW)

      CALL SETMSG ('43', 'The nominal edgewidth, minimum '    //
     1             'edgewidth, and maximum edgewidth should ' //
     2             'all be positive.')
      CALL IFPF (MINEW .GT. 0 .AND. MAXEW .GT. 0 .AND. NOMEW .GT. 0)

      CALL SETMSG ('44', 'The reported number of available ' //
     1             'edgewidths should be at least 0.')
      CALL IFPF (NAEW .GE. 0)

C  minsc = minimum effective scale factor
C  maxsc = maximum effective scale factor
      MINSC = MINEW/NOMEW
      MAXSC = MAXEW/NOMEW

      CALL SETMSG ('45', 'All edgewidth scale factors should be ' //
     1             'accepted as valid.')

      CALL ERRCTL (.TRUE.)

      EWIDTH = MINSC/10
      CALL PSEDR (WKID, 4, PON, 1, EWIDTH, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      EWIDTH = MAXSC*10
      CALL PSEDR (WKID, 4, PON, 1, EWIDTH, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      EWIDTH = -10.0
      CALL PSEDR (WKID, 4, PON, 1, EWIDTH, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      CALL PASS
      VALOK = .TRUE.
      GOTO 600

C  fail and informational message about scale_factor
500   CONTINUE
      CALL FAIL
      VALOK = .FALSE.
      WRITE (MSG, '(A,F11.2,A,I6,A)') 'Edgewidth scale factor of ',
     1         EWIDTH, ' rejected with error code = ', ERRSIG, '.'
      CALL INMSG (MSG)

600   CONTINUE

      CALL SETMSG ('11 15 42', 'The reported minimum edgewidth ' //
     1             'should be realizable.')
      CALL IFPF (RLZEW (MINSC, MINSC))

      CALL SETMSG ('11 15 42', 'The reported maximum edgewidth ' //
     1             'should be realizable.')
      CALL IFPF (RLZEW (MAXSC, MAXSC))

      IF (.NOT. VALOK) THEN
         CALL INMSG ('Skipping tests of edgewidth coercion, since ' //
     1               'validity test was failed.')
         GOTO 610
      ENDIF

      CALL SETMSG ('11 15 42', 'A edgewidth scale factor set as ' //
     1             'less than the minimum should be realized as ' //
     2             'the reported minimum.')
      CALL IFPF (RLZEW (MINSC/3, MINSC))

      CALL SETMSG ('11 15 42', 'A edgewidth scale factor set as ' //
     1             'greater than the maximum should be realized ' //
     2             'as the reported maximum.')
      CALL IFPF (RLZEW (MAXSC*3, MAXSC))

      CALL SETMSG ('11 15 42', 'A edgewidth scale factor set as ' //
     1             'less than zero should be realized as the '    //
     2             'reported minimum.')
      CALL IFPF (RLZEW (-ABS(MAXSC), MINSC))

C  skip_coerce:
610   CONTINUE

      IF (NAEW .NE. 0) GOTO 666

      CALL SETMSG ('11 15 42', 'If the reported number of available ' //
     1             'edgewidths is zero, then all edgewidths between ' //
     2             'the reported minimum and maximum should be '      //
     3             'realizable.')

      INCR = (MAXSC/MINSC) ** 0.25
      THISC = MINSC
      DO 620 IX = 1,3
         THISC = THISC * INCR
         IF (RLZEW (THISC, THISC)) THEN
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
