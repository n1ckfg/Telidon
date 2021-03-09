C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/06                        *
C  *    TEST TITLE : Interior style facilities             *
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

      INTEGER    NAINTS, RINTS, THISIS, ISI, NPDPI
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      LOGICAL    STYLE(PHOLLO:PISEMP), STYVAL

      CHARACTER MSG*300

C  parameters for <inquire workstation connection and type>
      INTEGER SPECWT, SPECON

      CALL INITGL ('04.02.05.02/06')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
C
C  naints = number of available interior styles
      CALL PQIF (SPECWT, 0, 0, ERRIND, NAINTS, IDUM1, IDUM2, IDUM3,
     1            IDUM4)
      CALL CHKINQ ('pqif', ERRIND)

      CALL SETMSG ('16 33', 'All interior styles within the list ' //
     1             'of available interior styles should be '       //
     2             'accepted as valid and realizable.')
C  keep track of style and validity
      DO 50 ISI = PHOLLO, PISEMP
         STYLE(ISI) = .FALSE.
50    CONTINUE
      STYVAL = .TRUE.
C  get each element in list of available interior styles
      DO 100 ISI = 1, NAINTS
         CALL PQIF (SPECWT, ISI, 0, ERRIND, IDUM1, THISIS, IDUM2,
     1               IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
C  set interior style
         CALL ERRCTL (.TRUE.)
         CALL PSIR (WKID, 2, THISIS, 1, 1)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A, I5, A, I5, A, I5, A)')
     1            'Interior style ', THISIS, ' in bundle #', ISI,
     2            ' rejected as invalid: signalled error #',
     3             ERRSIG, '.'
            CALL INMSG (MSG)
            GOTO 150
         ENDIF
         CALL ERRCTL (.FALSE.)
C  inquire interior style as realized
C  rints = realized interior style
         CALL PQIR (WKID, 2, PREALI, ERRIND, RINTS, IDUM1, IDUM2)
         CALL CHKINQ ('pqir', ERRIND)
         IF (RINTS .NE. THISIS) THEN
            CALL FAIL
            WRITE (MSG, '(A, I5, A, I5, A)') 'Interior style set as ',
     1             THISIS, ' but realized as ', RINTS, '.'
            CALL INMSG (MSG)
            GOTO 150
         ENDIF
100   CONTINUE
      CALL PASS

150   CONTINUE

C keep track of available interior styles and
C check that interior style is valid
      DO 200 ISI = 1, NAINTS
         CALL PQIF (SPECWT, ISI, 0, ERRIND, IDUM1, THISIS, IDUM2,
     1              IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (PHOLLO .LE. THISIS .AND. THISIS .LE. PISEMP) THEN
C style is valid
            STYLE(THISIS) = .TRUE.
         ELSE
            STYVAL = .FALSE.
            WRITE (MSG, '(A, A, I5, A, I5, A)') 'Invalid ',
     1             'interior style ', THISIS, ' in bundle #', ISI,
     2             ' in the list of available interior styles.'
            CALL INMSG (MSG)
         ENDIF
200   CONTINUE

      CALL SETMSG ('31', 'All interior styles in the list of '    //
     1             'available interior styles should be of type ' //
     2             'HOLLOW, SOLID, PATTERN, HATCH, or EMPTY.')
      CALL IFPF (STYVAL)

      CALL SETMSG ('32', 'The list of available interior styles ' //
     1             'should contain HOLLOW and EMPTY.')
      CALL IFPF (STYLE(PHOLLO) .AND. STYLE(PISEMP))

      IF (STYLE(PPATTR)) THEN
         CALL SETMSG ('34', 'For PATTERN interior style, at least '//
     1                '1 predefined pattern index should be '      //
     2                'available.')
C npdpi = number of predefined pattern index
         CALL PQPAF (SPECWT, ERRIND, NPDPI)
         CALL CHKINQ ('pqpaf', ERRIND)
         CALL IFPF (NPDPI .GE. 1)
      ENDIF

666   CONTINUE
      CALL ENDIT
      END
