C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/08                        *
C  *    TEST TITLE : Interior style index: hatch           *
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

      INTEGER    HSBOUN
      PARAMETER (HSBOUN = 1024)

      INTEGER   NAINTS, INTS, NAHS, THISHS, ISI, HSID, IMDHS, RSTYI
      INTEGER   HS(HSBOUN), IDUM1, IDUM2, IDUM3, IDUM4

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      LOGICAL   ERRCOD, IMPDEP

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.02/08')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  naints = number of available interior styles
C  nahs   = number of available hatch styles
      CALL PQIF (SPECWT, 0, 0, ERRIND, NAINTS, IDUM1, NAHS, IDUM2,
     1            IDUM3)
      CALL CHKINQ ('pqif', ERRIND)
C loop thru list of interior styles to determine if hatch is supported
      DO 100 ISI = 1, NAINTS
         CALL PQIF (SPECWT, ISI, 0, ERRIND, IDUM1, INTS, IDUM2, IDUM3,
     1              IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (INTS .EQ. PHATCH) GOTO 150
100   CONTINUE
      CALL SETMSG ('43', 'If HATCH interior style is not available, '//
     1             '<inquire interior facilities> should report 0 '  //
     2             'available hatch styles.')
      CALL IFPF (NAHS .EQ. 0)
      GOTO 666

150   CONTINUE
      CALL SETMSG ('42', 'The absolute value of the number of '//
     1             'available hatch styles should be greater ' //
     2             'than or equal to 3.')
      CALL IFPF (ABS(NAHS) .GE. 3)

C no inaccessible hatch styles found yet
      ERRCOD = .FALSE.
C no implementation-dependent hatch style found yet
      IMPDEP = .FALSE.

C go through list of available hatch styles
      DO 200 HSID = 1, ABS(NAHS)
         CALL PQIF (SPECWT, 0, HSID, ERRIND, IDUM1, IDUM2, IDUM3,
     1               THISHS, IDUM4)
C  keep track of non-zero error indicators
         IF (ERRIND .NE. 0) THEN
            ERRCOD = .TRUE.
            WRITE (MSG, '(A,I5,A,I5,A)') 'Got error indicator ',
     1         ERRIND, ' while accessing hatch style list element #',
     2         HSID, '.'
            CALL INMSG (MSG)
            GOTO 200
         ENDIF
         IF (HSID .LE. HSBOUN) HS(HSID) = THISHS
C  keep track of implementation-dependent types (non-positives):
         IF (THISHS .LT. 1) THEN
            IMPDEP = .TRUE.
         ENDIF
200   CONTINUE

      CALL SETMSG ('44', 'All entries within the reported size of ' //
     1             'the list of available hatch styles should be '  //
     2             'accessible.')
      CALL IFPF (.NOT. ERRCOD)

      IF (NAHS .GT. 0) THEN
C  positive number of available hatch styles - includes imp-dep
         IF (IMPDEP) THEN
C  looks OK - do nothing
         ELSE
            CALL SETMSG ('16 41 45 47', 'When system reports that '  //
     1                   'no implementation-dependent hatch styles ' //
     2                   'are available, none should be.')
            DO 300 IMDHS = 0, -3, -1
               CALL PSIR (WKID, 1, PHATCH, IMDHS, 1)
               CALL PQIR (WKID, 1, PREALI, ERRIND, IDUM1, RSTYI, IDUM2)
               CALL CHKINQ ('pqir', ERRIND)
               IF (RSTYI .EQ. IMDHS) THEN
                  CALL FAIL
                  WRITE (MSG, '(A, I5,A)')
     1               'Implementation-dependent hatch index #', IMDHS,
     2               ' in error, because realized as itself.'
                  CALL INMSG (MSG)
                  GOTO 350
               ENDIF
300         CONTINUE
            CALL PASS
350         CONTINUE
         ENDIF
      ELSE
C  non-positive number of available hatch styles - excludes imp-dep
         CALL SETMSG ('46 47', 'Negative number of available '  //
     1                'hatch styles should indicate that list ' //
     2                'contains no implementation-dependent '   //
     3                'hatch styles.')
         CALL IFPF (.NOT. IMPDEP)
      ENDIF

      CALL SETMSG ('16 40', 'All entries within the list of ' //
     1             'available hatch styles should be realizable.')
      CALL ERRCTL (.TRUE.)
C set all hatch styles
      DO 400 HSID = 1, MIN(HSBOUN, ABS(NAHS))
         THISHS = HS(HSID)
         CALL PSIR (WKID, 3, PHATCH, THISHS, 1)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A)') 'Hatch style #', THISHS,
     1             ' rejected as invalild.'
            CALL INMSG (MSG)
            GOTO 500
         ENDIF
C  inquire attributes as realized
C  rstyi = realized hatch style
         CALL PQIR (WKID, 3, PREALI, ERRIND, IDUM1, RSTYI, IDUM2)
         CALL CHKINQ ('pqir', ERRIND)
         IF (RSTYI .NE. THISHS) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A,I5,A)') 'Hatch style set as #', THISHS,
     1             ' but realized as #', RSTYI, '.'
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
