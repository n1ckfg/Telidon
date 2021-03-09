C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/06                        *
C  *    TEST TITLE : Text font and precision support       *
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

      INTEGER   PREALI, PSTRP, PCHARP, PSTRKP
      PARAMETER (PREALI=1, PSTRP=0, PCHARP=1, PSTRKP=2)

      INTEGER   EEL, RPR, NFPP, THISFN, THISPR, RFN, TSTPR
      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5

      LOGICAL   STRGAE, CHARAE, FNT(2), STRK(2)
      LOGICAL   PRECOK, FONTOK, CANSET, PREVAL

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3, RDUM4

      CHARACTER MSG*300

      CALL INITGL ('04.02.03.02/06')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  in fortran, the list of font/precision pairs (lfnpr) is given by:
C  nfpp = number of available font/prec pairs
C  font (thisfn) = nth element of list of text fonts
C  prec (thispr) = nth element of list of text precisions

      CALL PQTXF (SPECWT, 1, ERRIND, NFPP, IDUM1, IDUM2, IDUM3,
     1            RDUM1, RDUM2, IDUM4, RDUM3, RDUM4, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)
C  strgae = STRING precision available directly
C  charae = CHAR precision available directly
      STRGAE = .FALSE.
      CHARAE = .FALSE.
C  no standard fonts found yet
      FNT(1) = .FALSE.
      FNT(2) = .FALSE.
C  no STROKE precsion found yet
      STRK(1) = .FALSE.
      STRK(2) = .FALSE.
C go through each element in list of available font/precision pairs
      DO 200 EEL = 1, NFPP
         CALL PQTXF (SPECWT, EEL, ERRIND, IDUM1, THISFN, THISPR,
     1               IDUM2, RDUM1, RDUM2, IDUM3, RDUM3, RDUM4, IDUM4)
C  keep track of non-zero error indicators
         IF (ERRIND .NE. 0) THEN
            WRITE (MSG, '(A,I5,A,I5,A)') 'Got error indicator ',
     1             ERRIND, ' while accessing font/prec-list element #',
     2             EEL, '.'
            CALL INMSG (MSG)
            GOTO 200
         ENDIF
C  check for fonts 1 and 2
         IF (THISFN .EQ. 1 .OR. THISFN .EQ. 2) THEN
            FNT(THISFN) = .TRUE.
C  check on precision
            IF (THISPR .EQ. PSTRKP) STRK(THISFN) = .TRUE.
         ENDIF
C  check for at least 1 STRING precision (directly available)
         CALL PSTXR (WKID, 1, THISFN, PSTRP, 1.0, 0.0, 1)
         CALL PQTXR (WKID, 1, PREALI, ERRIND, IDUM1, RPR, RDUM1,
     1               RDUM2, IDUM2)
         CALL CHKINQ ('pqtxr', ERRIND)
         IF (RPR .EQ. PSTRP) STRGAE = .TRUE.
C  check for at least 1 CHAR precision (directly available)
         IF (THISPR .LT. PCHARP) GOTO 200
         CALL PSTXR (WKID, 2, THISFN, PCHARP, 1.0, 0.0, 1)
         CALL PQTXR (WKID, 2, PREALI, ERRIND, IDUM1, RPR, RDUM1,
     1               RDUM2, IDUM2)
         CALL CHKINQ ('pqtxr', ERRIND)
         IF (RPR .EQ. PCHARP) CHARAE = .TRUE.
200   CONTINUE

      CALL SETMSG ('30', 'The list of available font/precision '     //
     1             'pairs should contain font 1 and font 2.')
      CALL IFPF (FNT(1) .AND. FNT(2))

      CALL SETMSG ('31', 'Stroke precision should be available for ' //
     1             'both font 1 and font 2.')
      CALL IFPF (STRK(1) .AND. STRK(2))

      CALL SETMSG ('32', 'At least 1 STRING precision font should '  //
     1             'be available directly.')
      CALL IFPF (STRGAE)

      CALL SETMSG ('33', 'At least 1 CHAR precision font should '    //
     1             'be available directly.')
      CALL IFPF (CHARAE)

C  keep track of precision validity
      CALL SETMSG ('15 35', 'All text font/precision pairs within ' //
     1             'the list of available font/precision pairs '    //
     2             'should be valid and available directly.')

      PREVAL = .TRUE.
C  get each element in list of font/precision pairs
      DO 300 EEL = 1, NFPP
         CALL PQTXF (SPECWT, EEL, ERRIND, IDUM1, THISFN, THISPR,
     1               IDUM2, RDUM1, RDUM2, IDUM3, RDUM3, RDUM4,
     2               IDUM4)
         CALL CHKINQ ('pqtxf', ERRIND)
C  check that precision is valid
         IF (THISPR .LT. PSTRP .OR. THISPR .GT. PSTRKP) THEN
            PREVAL = .FALSE.
            WRITE (MSG, '(A, A, I5, A, I5, A)') 'Invalid ',
     1             'precision', THISPR, 'in bundle #', EEL,
     2             ' in the list of font/precision pairs.'
            CALL INMSG (MSG)
         ENDIF
C  set font and precision
         CALL ERRCTL (.TRUE.)
         CALL PSTXR (WKID, 2, THISFN, THISPR, 1.0, 0.0, 1)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A, 2I5, A, I5, A, I5, A)')
     1            'Font/precision pair ', THISFN, THISPR,
     2            ' in bundle #', EEL,
     3            ' rejected as invalid: signalled error #',
     4             ERRSIG, '.'
            CALL INMSG (MSG)
            GOTO 350
         ENDIF
         CALL ERRCTL (.FALSE.)
C  inquire font and precision as realized
C  rfn = realized font, rpr = realized prec
         CALL PQTXR (WKID, 2, PREALI, ERRIND, RFN, RPR, RDUM1,
     1               RDUM2, IDUM1)
         CALL CHKINQ ('pqtxr', ERRIND)
         IF (RFN .NE. THISFN) THEN
            CALL FAIL
            WRITE (MSG, '(A, I5, A, I5, A)') 'Font set as ', THISFN,
     1             ' but realized as ', RFN, '.'
            CALL INMSG (MSG)
            GOTO 350
         ENDIF
         IF (RPR .NE. THISPR) THEN
            CALL FAIL
            WRITE (MSG, '(A, I5, A, I5, A)') 'Precision set as ',
     1             THISPR, ' but realized as ', RPR, '.'
            CALL INMSG (MSG)
            GOTO 350
         ENDIF
300   CONTINUE
      CALL PASS

350   CONTINUE
      CALL SETMSG ('34', 'All precisions in the list of text ' //
     1             'font and precision pairs should be of '    //
     2             'type STRING, CHAR, or STROKE.')
      CALL IFPF (PREVAL)

      PRECOK = .TRUE.
      FONTOK = .TRUE.
      CANSET = .TRUE.
      DO 450 EEL = 1, NFPP
         CALL PQTXF (SPECWT, EEL, ERRIND, IDUM1, THISFN, THISPR,
     1               IDUM2, RDUM1, RDUM2, IDUM3, RDUM3, RDUM4,
     2               IDUM4)
         CALL CHKINQ ('pqtxf', ERRIND)
         DO 400 TSTPR = PSTRP, THISPR
            CALL ERRCTL (.TRUE.)
            CALL PSTXR (WKID, 1, THISFN, TSTPR, 1.0, 0.0, 1)
            CALL ERRCTL (.FALSE.)
            IF (ERRSIG .NE. 0) THEN
               CANSET = .FALSE.
               WRITE (MSG, '(A, 2I5, A, I5, A, I5, A)')
     1            'Font/precision pair ', THISFN, TSTPR,
     2            ' in bundle #', EEL,
     3            ' rejected as invalid: signalled error #',
     4             ERRSIG, '.'
               CALL INMSG (MSG)
               GOTO 460
            ENDIF
            CALL PQTXR (WKID,1,PREALI, ERRIND, RFN, RPR, RDUM1,
     1                  RDUM2, IDUM1)
            CALL CHKINQ ('pqtxr', ERRIND)
            IF (RFN .NE. THISFN) THEN
               FONTOK = .FALSE.
               WRITE (MSG, '(3(A,I5),A)') 'Font set as ', THISFN,
     1                ' but realized as ', RFN, ' for fn_pr pair #',
     2                EEL, '.'
               CALL INMSG (MSG)
               GOTO 460
            ENDIF
            IF (RPR .LT. TSTPR) THEN
               PRECOK = .FALSE.
               WRITE (MSG, '(3(A,I5),A)') 'Precison set as ', TSTPR,
     1                ' but realized as ', RPR, ' for fn_pr pair #',
     2                EEL, '.'
               CALL INMSG (MSG)
               GOTO 460
            ENDIF
400      CONTINUE
450   CONTINUE

460   CONTINUE

      CALL SETMSG ('36 37 47', 'If a given font/precision pair ' //
     1             'is reported as supported, then that font '   //
     2             'should be available in all lower or equal '  //
     3             'precisions.')
      CALL IFPF (CANSET)

      CALL SETMSG ('15 36 37 47', 'A valid font/precision pair ' //
     1             'should be realized as that font and at an '  //
     2             'equal or higher precision.')
      CALL IFPF (FONTOK .AND. PRECOK)

666   CONTINUE
C wrap it up
      CALL ENDIT
      END

