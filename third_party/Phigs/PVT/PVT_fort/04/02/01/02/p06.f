C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/06                        *
C  *    TEST TITLE : Linetype facilities                   *
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

      INTEGER   LTBOUN
      PARAMETER (LTBOUN = 1024)

      INTEGER   NALT, LTID, IMPLT, RLT, LT(LTBOUN)
      INTEGER   THISLT, IDUM1, IDUM2, IDUM3

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3

      LOGICAL   ERRCOD, IMPDEP, STDLT(4)

      CHARACTER MSG*300

      CALL INITGL ('04.02.01.02/06')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  nalt = number of available linetypes
      CALL PQPLF (SPECWT, 1, ERRIND, NALT, IDUM2, IDUM3,
     1            RDUM1, RDUM2, RDUM3, IDUM1)
      CALL CHKINQ ('pqplf', ERRIND)

C no inaccessible linetypes found yet
      ERRCOD = .FALSE.
C no standard linetypes found yet
      DO 100 LTID = 1,4
         STDLT(LTID) = .FALSE.
100   CONTINUE
C no implementation-dependent linetypes found yet
      IMPDEP = .FALSE.

C go through list of available linetypes
      DO 200 LTID = 1, ABS(NALT)
         CALL PQPLF (SPECWT, LTID, ERRIND, IDUM1, THISLT, IDUM3,
     1               RDUM1, RDUM2, RDUM3, IDUM2)
C  keep track of non-zero error indicators
         IF (ERRIND .NE. 0) THEN
            ERRCOD = .TRUE.
            WRITE (MSG, '(A,I5,A,I5,A)') 'Got error indicator ',
     1         ERRIND, ' while accessing linetype-list element #',
     2         LTID, '.'
            CALL INMSG (MSG)
            GOTO 200
         ENDIF
         IF (LTID .LE. LTBOUN) LT(LTID) = THISLT
C  keep track of linetypes 1-4:
         IF (THISLT .GE. 1 .AND. THISLT .LE. 4) THEN
            STDLT(THISLT) = .TRUE.
         ENDIF
C  keep track of implementation-dependent types (non-positives):
         IF (THISLT .LT. 1) THEN
            IMPDEP = .TRUE.
         ENDIF
200   CONTINUE
      CALL SETMSG ('29', 'All entries within the reported size of ' //
     1             'the list of available linetypes should be '     //
     2             'accessible.')

      CALL IFPF (.NOT. ERRCOD)

      CALL SETMSG ('30', 'The list of available linetypes should ' //
     1             'contain 1 thru 4.')
      CALL IFPF (STDLT(1) .AND. STDLT(2) .AND. STDLT(3) .AND. STDLT(4))

      IF (NALT .GT. 0) THEN
C  positive number of available linetypes - includes imp-dep
         IF (IMPDEP) THEN
C  looks OK - do nothing
         ELSE
            CALL SETMSG ('31 34', 'When system reports that no '    //
     1                   'implementation-dependent linetypes are '  //
     2                   'available, none should be.')
            CALL ERRCTL (.TRUE.)
            DO 300 IMPLT = 0, -3, -1
               CALL PSPLR (WKID, 1, IMPLT, 1.0, 1)
               IF (ERRSIG .NE. 104) THEN
                  CALL FAIL
                  WRITE (MSG, '(A,I5,A)')
     1               'Implementation-dependent linetype #', IMPLT,
     2               ' not rejected by set polyline representation.'
                  CALL INMSG (MSG)
                  GOTO 350
               ENDIF
300         CONTINUE
            CALL PASS
350         CONTINUE
            CALL ERRCTL (.FALSE.)
         ENDIF
      ELSE
C  non-positive number of available linetypes - excludes imp-dep
         CALL SETMSG ('32 34', 'Negative number of available '        //
     1                'linetypes should indicate that list contains ' //
     2                'no implementation-dependent linetypes.')
         CALL IFPF (.NOT. IMPDEP)
      ENDIF

      CALL SETMSG ('15 33', 'All entries within the reported list ' //
     1             'of available linetypes should be realizable '   //
     2             'and valid.')
      CALL ERRCTL (.TRUE.)
C set all linetypes
      DO 400 LTID = 1, MIN(LTBOUN, ABS(NALT))
        THISLT = LT(LTID)
        CALL PSPLR (WKID, 3, THISLT, 1.0, 1)
        IF (ERRSIG .NE. 0) THEN
           CALL FAIL
           WRITE (MSG, '(A,I5,A)') 'Linetype #', THISLT,
     1            ' rejected as invalild.'
           CALL INMSG (MSG)
           GOTO 500
        ENDIF
C  inquire attributes as realized
C  rlt = realized linetype
        CALL PQPLR (WKID, 3, 1, ERRIND, RLT, RDUM1, IDUM1)
        CALL CHKINQ ('pqplr', ERRIND)
        IF (RLT .NE. THISLT) THEN
           CALL FAIL
           WRITE (MSG, '(A,I5,A,I5,A)') 'Linetype set as #', THISLT,
     1            ' but realized as #', RLT, '.'
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
