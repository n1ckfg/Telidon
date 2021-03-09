C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/07                        *
C  *    TEST TITLE : Character expansion factor support    *
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

      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5
      INTEGER    NAEXP, RPR, TXI, PREC
      INTEGER    PREALI, PSTRP, PCHARP, PSTRKP
      PARAMETER  (PREALI=1, PSTRP=0, PCHARP=1, PSTRKP=2)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL       MINEXP, MAXEXP, RDUM1, RDUM2, LCHEXP(3)
      REAL       CHEXP, REXP, EXPI, LOLOG,HILOG, LOGVAL
      LOGICAL    APPEQ
      CHARACTER  MSG*300

      CALL INITGL ('04.02.03.02/07')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  <inquire text facilities> to determine:
C     naexp  = number of available character expansion factors
C     minexp = minimum character expansion factor
C     maxexp = maximum character expansion factor

      CALL PQTXF (SPECWT, 1, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4, RDUM1,
     1            RDUM2, NAEXP, MINEXP, MAXEXP, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)

      WRITE (MSG, '(A,A,I6,A,A, 2(E13.4,A))')
     1       'Implementation reports number of available character ',
     2       'expansion factors = ', NAEXP, ';  minimum, maximum ',
     3       'expansion factors = ', MINEXP, ',', MAXEXP, '.'
      CALL INMSG (MSG)

      CALL SETMSG ('51', 'Maximum character expansion factor should ' //
     1             'not be less than the minimum character '          //
     2             'expansion factor.')
      CALL IFPF (MAXEXP .GE. MINEXP)

      CALL SETMSG ('51 52', 'The minimum and maximum character ' //
     1             'expansion factors should be positive.')
      CALL IFPF (MINEXP .GT. 0.0 .AND. MAXEXP .GT. 0.0)

      CALL SETMSG ('51 53 55', 'The reported number of available ' //
     1             'character expansion factors should be at '     //
     2             'least 0.')
      CALL IFPF (NAEXP .GE. 0)

      CALL SETMSG ('51 56', 'All character expansion factors should ' //
     1             'be accepted as valid.')

      IF (ABS(MINEXP) .GT. 1.0E-37) THEN
         LCHEXP(1) = 0.6 * MINEXP
      ELSE
         LCHEXP(1) = MINEXP
      ENDIF

      IF (ABS(MAXEXP) .LT. 1.0E+37) THEN
         LCHEXP(2) = 1.6 * MAXEXP
      ELSE
         LCHEXP(2) = MAXEXP
      ENDIF

      LCHEXP(3) = -10.0

      CALL ERRCTL (.TRUE.)
      PREC = PSTRP
      DO 100 TXI = 1, 3
         IF (TXI .EQ. 3) PREC = PCHARP
         CALL PSTXR (WKID, TXI, 1, PREC, LCHEXP(TXI), 0.0, 1)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,E13.4,A,I6,A)')
     1         'Character expansion factor of ', LCHEXP(TXI),
     2         ' rejected with error code = ', ERRSIG, '.'
            CALL INMSG (MSG)
            GOTO 199
         ENDIF
100   CONTINUE
      CALL PASS
199   CONTINUE
      CALL ERRCTL (.FALSE.)

C  inquire as realized (Stroke precision)
C  rexp = realized character expansion factor
      CALL SETMSG ('15 59', 'For STROKE precision, any character ' //
     1             'expansion factor should be realized as the '   //
     2             'absolute value of itself.')

      DO 200 TXI = 1, 3
         CALL PSTXR (WKID, 2, 1, PSTRKP, LCHEXP(TXI), 0., 1)
         CALL PQTXR (WKID, 2, PREALI, ERRIND, IDUM1, IDUM2, REXP,
     1               RDUM1, IDUM3)
         CALL CHKINQ ('pqtxr', ERRIND)
         IF (.NOT. (APPEQ (REXP,ABS(LCHEXP(TXI)),0.005,0.005))) THEN
            CALL FAIL
            WRITE (MSG, '(A, E13.4, A, E13.4, A)')
     1             'Character expansion factor set as ',
     2             LCHEXP(TXI), ' but realized as ', REXP, '.'
            CALL INMSG (MSG)
            GOTO 250
         ENDIF
200   CONTINUE
      CALL PASS
250   CONTINUE

C  rpr = realized precision
      IF (ABS(MINEXP) .GT. 1.0E-37) THEN
         CHEXP = 0.6 * MINEXP
      ELSE
         CHEXP = MINEXP
      ENDIF
      CALL PSTXR (WKID, 1, 1, PSTRP, CHEXP, 0.0, 1)
      CALL PQTXR (WKID, 1, PREALI, ERRIND, IDUM1, RPR, REXP,
     1            RDUM1, IDUM2)
      CALL CHKINQ ('pqtxr', ERRIND)
C  check that we have STRING precision
      IF (RPR .EQ. PSTRP) THEN
         CALL SETMSG ('15 54 59', 'For font 1 and STRING '         //
     1                'precision realized directly, the absolute ' //
     2                'value of all character expansion factors '  //
     3                'less than the minimum character expansion ' //
     4                'factor should be realized as the minimum '  //
     5                'character expansion factor.')
         CALL IFPF (REXP .EQ. MINEXP)
      ENDIF

      CALL PSTXR (WKID, 2, 1, PCHARP, CHEXP, 0.0, 1)
      CALL PQTXR (WKID, 2, PREALI, ERRIND, IDUM1, RPR, REXP,
     1            RDUM1, IDUM2)
      CALL CHKINQ ('pqtxr', ERRIND)
C  check that we have CHAR precision
      IF (RPR .EQ. PCHARP) THEN
         CALL SETMSG ('15 54 59', 'For font 1 and CHAR '           //
     1                'precision realized directly, the absolute ' //
     2                'value of all character expansion factors '  //
     3                'less than the minimum character expansion ' //
     4                'factor should be realized as the minimum '  //
     5                'character expansion factor.')
         CALL IFPF (REXP .EQ. MINEXP)
      ENDIF

      IF (ABS(MAXEXP) .LT. 1.0E+37) THEN
         CHEXP = 1.6 * MAXEXP
      ELSE
         CHEXP = MAXEXP
      ENDIF
      CALL PSTXR (WKID, 1, 1, PSTRP, CHEXP, 0.0, 1)
      CALL PQTXR (WKID, 1, PREALI, ERRIND, IDUM1, RPR, REXP,
     1            RDUM1, IDUM2)
      CALL CHKINQ ('pqtxr', ERRIND)
C  check that we have STRING precision
      IF (RPR .EQ. PSTRP) THEN
         CALL SETMSG ('15 54 59', 'For font 1 and STRING '         //
     1                'precision realized directly, the absolute ' //
     2                'value of all character expansion factors '  //
     3                'greater than the maximum character '        //
     4                'expansion factor should be realized as '    //
     5                'the maximum character expansion factor.')
         CALL IFPF (REXP .EQ. MAXEXP)
      ENDIF

      CALL PSTXR (WKID, 2, 1, PCHARP, CHEXP, 0.0, 1)
      CALL PQTXR (WKID, 2, PREALI, ERRIND, IDUM1, RPR, REXP,
     1            RDUM1, IDUM2)
      CALL CHKINQ ('pqtxr', ERRIND)
C  check that we have CHAR precision
      IF (RPR .EQ. PCHARP) THEN
         CALL SETMSG ('15 54 59', 'For font 1 and CHAR '           //
     1                'precision realized directly, the absolute ' //
     2                'value of all character expansion factors '  //
     3                'greater than the maximum character '        //
     4                'expansion factor should be realized as '    //
     5                'the maximum character expansion factor.')
         CALL IFPF (REXP .EQ. MAXEXP)
      ENDIF

C  check that there is a continuous range
      IF (NAEXP .NE. 0) GOTO 666
      CALL SETMSG ('15 55', 'For continuous character expansion ' //
     1             'factors, a character expansion factor '       //
     2             'within the min-max range should be '          //
     3             'realized as itself.')

      LOLOG = LOG(MINEXP)
      HILOG = LOG(MAXEXP)
      DO 400 LOGVAL = LOLOG, HILOG, (HILOG-LOLOG) / 6.00001
         EXPI = EXP(LOGVAL)
         CALL PSTXR (WKID, 6, 1, PSTRP, EXPI, 0.0, 1)
         CALL PQTXR (WKID, 6, PREALI, ERRIND, IDUM1, IDUM2,
     1               REXP, RDUM1, IDUM3)
         CALL CHKINQ ('pqtxr', ERRIND)
         IF (.NOT. APPEQ(REXP, EXPI, 0.0, 0.005)) THEN
            CALL FAIL
            GOTO 666
         ENDIF
400   CONTINUE
      CALL PASS

666   CONTINUE

C wrap it up
      CALL ENDIT
      END
