C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/06                        *
C  *    TEST TITLE : Marker type facilities                *
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

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER    MTBOUN
      PARAMETER (MTBOUN = 1024)

      INTEGER   NAMT, MTID, IMPMT, RMT, MT(MTBOUN)
      INTEGER   THISMT, IDUM1, IDUM2, IDUM3

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3

      LOGICAL   ERRCOD, IMPDEP, STDMT(5)

      CHARACTER MSG*300

      CALL INITGL ('04.02.02.02/06')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  namt = number of available marker types
      CALL PQPMF (SPECWT, 1, ERRIND, NAMT, IDUM2, IDUM3,
     1            RDUM1, RDUM2, RDUM3, IDUM1)
      CALL CHKINQ ('pqpmf', ERRIND)

C no inaccessible marker types found yet
      ERRCOD = .FALSE.
C no standard marker types found yet
      DO 100 MTID = 1,5
         STDMT(MTID) = .FALSE.
100   CONTINUE
C no implementation-dependent marker types found yet
      IMPDEP = .FALSE.

C go through list of available marker types
      DO 200 MTID = 1, ABS(NAMT)
         CALL PQPMF (SPECWT, MTID, ERRIND, IDUM1, THISMT, IDUM3,
     1               RDUM1, RDUM2, RDUM3, IDUM2)
C  keep track of non-zero error indicators
         IF (ERRIND .NE. 0) THEN
            ERRCOD = .TRUE.
            WRITE (MSG, '(A,I5,A,I5,A)') 'Got error indicator ',
     1         ERRIND, ' while accessing marker-type list element #',
     2         MTID, '.'
            CALL INMSG (MSG)
            GOTO 200
         ENDIF
         IF (MTID .LE. MTBOUN) MT(MTID) = THISMT
C  keep track of marker types 1-5:
         IF (THISMT .GE. 1 .AND. THISMT .LE. 5) THEN
            STDMT(THISMT) = .TRUE.
         ENDIF
C  keep track of implementation-dependent types (non-positives):
         IF (THISMT .LT. 1) THEN
            IMPDEP = .TRUE.
         ENDIF
200   CONTINUE

      CALL SETMSG ('29', 'All entries within the reported size of ' //
     1             'the list of available marker types should be '  //
     2             'accessible.')
      CALL IFPF (.NOT. ERRCOD)

      CALL SETMSG ('30', 'The list of available marker types should ' //
     1             'contain 1 thru 5.')
      CALL IFPF (STDMT(1) .AND. STDMT(2) .AND. STDMT(3) .AND.
     1           STDMT(4) .AND. STDMT(5))

      IF (NAMT .GT. 0) THEN
C  positive number of available marker types - includes imp-dep
         IF (IMPDEP) THEN
C  looks OK - do nothing
         ELSE
            CALL SETMSG ('31 34', 'When system reports that no '      //
     1                   'implementation-dependent marker types are ' //
     2                   'available, none should be.')
            CALL ERRCTL (.TRUE.)
            DO 300 IMPMT = 0, -3, -1
               CALL PSPMR (WKID, 1, IMPMT, 1.0, 1)
               IF (ERRSIG .NE. 105) THEN
                  CALL FAIL
                  WRITE (MSG, '(A,I5,A)')
     1               'Implementation-dependent marker type #', IMPMT,
     2               ' not rejected by set polymarker representation.'
                  CALL INMSG (MSG)
                  GOTO 350
               ENDIF
300         CONTINUE
            CALL PASS
350         CONTINUE
            CALL ERRCTL (.FALSE.)
         ENDIF
      ELSE
C  non-positive number of available marker types - excludes imp-dep
         CALL SETMSG ('32 34', 'Negative number of available '  //
     1                'marker types should indicate that list ' //
     2                'contains no implementation-dependent '   //
     3                'marker types.')
         CALL IFPF (.NOT. IMPDEP)
      ENDIF

      CALL SETMSG ('15 33', 'All entries within the reported list '  //
     1             'of available marker types should be realizable ' //
     2             'and valid.')
      CALL ERRCTL (.TRUE.)
C set all marker types
      DO 400 MTID = 1, MIN(MTBOUN, ABS(NAMT))
        THISMT = MT(MTID)
        CALL PSPMR (WKID, 3, THISMT, 1.0, 1)
        IF (ERRSIG .NE. 0) THEN
           CALL FAIL
           WRITE (MSG, '(A,I5,A)') 'Marker type #', THISMT,
     1            ' rejected as invalild.'
           CALL INMSG (MSG)
           GOTO 500
        ENDIF
C  inquire attributes as realized
C  rmt = realized marker type
        CALL PQPMR (WKID, 3, PREALI, ERRIND, RMT, RDUM1, IDUM1)
        CALL CHKINQ ('pqpmr', ERRIND)
        IF (RMT .NE. THISMT) THEN
           CALL FAIL
           WRITE (MSG, '(A,I5,A,I5,A)') 'Marker type set as #', THISMT,
     1            ' but realized as #', RMT, '.'
           CALL INMSG (MSG)
           GOTO 500
        ENDIF
400   CONTINUE
      CALL PASS

500   CONTINUE
      CALL ERRCTL (.FALSE.)

666   CONTINUE
      CALL ENDIT
      END
