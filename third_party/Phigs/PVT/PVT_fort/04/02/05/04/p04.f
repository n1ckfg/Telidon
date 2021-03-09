C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.04/04                        *
C  *    TEST TITLE : Validity of predefined pattern        *
C  *                 table                                 *
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

      INTEGER    NPE, II, I, J, MPCI, ERPCI, IDUM1, IDUM2
C set up pattern color index array
      INTEGER    DIMX, DIMY, DX, DY
      PARAMETER  (DIMX = 100, DIMY = 100)
      INTEGER    COLIA(DIMX,DIMY)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      REAL       RDUM1(9)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      LOGICAL   COLERR, NOERR, NOPAT, PATAVL

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.04/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C nopat = no pattern interior style
      NOPAT = .NOT. PATAVL(SPECWT)
      IF (NOPAT) THEN
         CALL INMSG ('Pattern interior style is not supported ' //
     1               'on this workstation.')
      ENDIF

25    CONTINUE

C get maximum predefined color index and
C adjust for color index starting at 0 (not 1)
      CALL PQCF (SPECWT, ERRIND, IDUM1, IDUM2, MPCI, RDUM1)
      CALL CHKINQ ('pqcf', ERRIND)
      MPCI = MPCI - 1

C npe     = number of predefined entries
      CALL PQPAF (SPECWT, ERRIND, NPE)
      CALL CHKINQ ('pqpaf', ERRIND)

      IF (NOPAT) THEN
         CALL SETMSG ('11 14', 'If PATTERN interior style is not ' //
     1                'supported, <inquire pattern facilities> '   //
     2                'should report 0 predefined indices.')
         CALL IFPF (NPE .EQ. 0)
         GOTO 666
      ENDIF

C  color error found yet
      COLERR = .FALSE.
C  no access error found yet
      NOERR = .TRUE.
C should be able to access as many predefined pattern entries as
C    reported by pattern facilities
      DO 300 II = 1, NPE
         CALL PQPPAR (SPECWT, II, DIMX, DIMY, ERRIND, DX, DY, COLIA)

C check errind for overflow
         IF (ERRIND .EQ. 2001) THEN
            WRITE (MSG, '(A,A,2I5,A)') 'PQPPAR returned Fortran error ',
     1             '2001: declared array size of (', DIMX, DIMY,
     2             ') insufficient.'
            CALL INMSG (MSG)
            GOTO 400
         ELSEIF (ERRIND .NE. 0) THEN
            NOERR = .FALSE.
            GOTO 300
         ENDIF

C check color index as specified in pattern color index array
C loop thru each element of pattern color index array
         DO 50 I = 1, DX
            DO 50 J = 1, DY
               IF (COLIA(I,J) .LT. 0 .OR. COLIA(I,J) .GT. MPCI) THEN
                  COLERR = .TRUE.
                  ERPCI = COLIA(I,J)
               ENDIF
50       CONTINUE
300   CONTINUE

      CALL SETMSG ('11 12 15',
     1             '<Inquire predefined pattern representation> ' //
     2             'should be able to access as many entries as ' //
     3             'reported by <inquire pattern facilities>.')
      CALL IFPF (NOERR)

      CALL SETMSG ('12 18', 'All color indices in predefined '    //
     1             'pattern color index array should themselves ' //
     2             'be in the predefined color table.')
      IF (COLERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color #', ERPCI,
     1          ' found in predefined color index array.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

400   CONTINUE
      WRITE (MSG, '(A,I5,A)') 'PHIGS reported ', NPE,
     1       ' predefined pattern indices.'
      CALL INMSG (MSG)

      CALL SETMSG ('11 13', 'If PATTERN interior style is '          //
     1             'supported, <inquire pattern facilities> should ' //
     1             'report at least 1 predefined entry.')

      CALL IFPF (NPE .GE. 1)

666   CONTINUE
      CALL ENDIT
      END
