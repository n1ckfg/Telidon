C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/07                        *
C  *    TEST TITLE : Marker size facilities                *
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

      INTEGER    NAMS, IX, IDUM1, IDUM2, IDUM3

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL       NOMMS, MINMS, MAXMS, MSIZE, MINSC, MAXSC, INCR, THISC

      LOGICAL    VALOK, RLZMS

      CHARACTER  MSG*300

      CALL INITGL ('04.02.02.02/07')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  <inquire polymarker facilities> to determine:
C     nams  = number of available marker sizes
C     nomms = nominal marker size
C     minms = minimum marker size
C     maxms = maximum marker size

      CALL PQPMF (SPECWT, 1, ERRIND, IDUM1, IDUM2,
     1            NAMS, NOMMS, MINMS, MAXMS, IDUM3)
      CALL CHKINQ ('pqpmf', ERRIND)

      WRITE (MSG, '(A,I6,3(A,E13.4))')
     1  'Implementation reports number of available marker sizes = ',
     2   NAMS, ';  nominal, minimum, maximum marker sizes = ',
     3   NOMMS, ',', MINMS, ',', MAXMS
      CALL INMSG (MSG)

      CALL SETMSG ('39', 'Maximum marker size should not be less ' //
     1             'than minimum.')
      CALL IFPF (MAXMS .GE. MINMS)

      CALL SETMSG ('40', 'The nominal marker size, minimum marker ' //
     1             'size, and maximum marker size should all be '   //
     2             'positive.')
      CALL IFPF (MINMS .GT. 0 .AND. MAXMS .GT. 0 .AND. NOMMS .GT. 0)

      CALL SETMSG ('41', 'The reported number of available ' //
     1             'marker sizes should be at least 0.')
      CALL IFPF (NAMS .GE. 0)

C  minsc = minimum effective scale factor
C  maxsc = maximum effective scale factor
      MINSC = MINMS/NOMMS
      MAXSC = MAXMS/NOMMS

      CALL SETMSG ('42', 'All marker size scale factors should be ' //
     1             'accepted as valid.')

      CALL ERRCTL (.TRUE.)

      MSIZE = MINSC/10
      CALL PSPMR (WKID, 4, 1, MSIZE, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      MSIZE = MAXSC*10
      CALL PSPMR (WKID, 4, 1, MSIZE, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      MSIZE = -10.0
      CALL PSPMR (WKID, 4, 1, MSIZE, 1)
      IF (ERRSIG .NE. 0) GOTO 500
      CALL PASS
      VALOK = .TRUE.
      GOTO 600

C  fail and informational message about scale_factor
500   CONTINUE
      CALL FAIL
      VALOK = .FALSE.
      WRITE (MSG, '(A,F11.2,A,I6,A)') 'Marker size scale factor of ',
     1         MSIZE, ' rejected with error code = ', ERRSIG, '.'
      CALL INMSG (MSG)

600   CONTINUE

      CALL SETMSG ('11 15 39', 'The reported minimum marker size ' //
     1             'should be realizable.')
      CALL IFPF (RLZMS (MINSC, MINSC))

      CALL SETMSG ('11 15 39', 'The reported maximum marker size ' //
     1             'should be realizable.')
      CALL IFPF (RLZMS (MAXSC, MAXSC))

      IF (.NOT. VALOK) THEN
         CALL INMSG ('Skipping tests of marker size coercion, since ' //
     1               'validity test was failed.')
         GOTO 610
      ENDIF

      CALL SETMSG ('11 15 39', 'A marker size scale factor set as ' //
     1             'less than the minimum should be realized as '   //
     2             'the reported minimum.')
      CALL IFPF (RLZMS (MINSC/3, MINSC))

      CALL SETMSG ('11 15 39', 'A marker size scale factor set as ' //
     1             'greater than the maximum should be realized '   //
     2             'as the reported maximum.')
      CALL IFPF (RLZMS (MAXSC*3, MAXSC))

      CALL SETMSG ('11 15 39', 'A marker size scale factor set as ' //
     1             'less than zero should be realized as the '      //
     2             'reported minimum.')
      CALL IFPF (RLZMS (-ABS(MAXSC), MINSC))

C  skip_coerce:
610   CONTINUE

      IF (NAMS .NE. 0) GOTO 666

      CALL SETMSG ('11 15 39', 'If the reported number of available ' //
     1             'marker sizes is zero, then all marker sizes '     //
     2             'between the reported minimum and maximum should ' //
     3             'be realizable.')

      INCR = (MAXSC/MINSC) ** 0.25
      THISC = MINSC
      DO 620 IX = 1,3
         THISC = THISC * INCR
         IF (RLZMS (THISC, THISC)) THEN
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

