C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/07                        *
C  *    TEST TITLE : Edgetype facilities                   *
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

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   ETBOUN
      PARAMETER (ETBOUN = 1024)

      INTEGER   NAET, ETID, IMPET, RET, ET(ETBOUN)
      INTEGER   THISET, IDUM1, IDUM2, IDUM3

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3

      LOGICAL   ERRCOD, IMPDEP, STDET

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.03/07')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  naet = number of available edgetypes
      CALL PQEDF (SPECWT, 0, ERRIND, NAET, IDUM1, IDUM2,
     1            RDUM1, RDUM2, RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)

C no inaccessible edgetypes found yet
      ERRCOD = .FALSE.
C no standard edgetypes found yet
      STDET  = .FALSE.
C no implementation-dependent edgetypes found yet
      IMPDEP = .FALSE.

C go through list of available edgetypes
      DO 200 ETID = 1, ABS(NAET)
         CALL PQEDF (SPECWT, ETID, ERRIND, IDUM1, THISET, IDUM2,
     1               RDUM1, RDUM2, RDUM3, IDUM3)
C  keep track of non-zero error indicators
         IF (ERRIND .NE. 0) THEN
            ERRCOD = .TRUE.
            WRITE (MSG, '(A,I5,A,I5,A)') 'Got error indicator ',
     1             ERRIND, ' while accessing edgetype-list element #',
     2             ETID, '.'
            CALL INMSG (MSG)
            GOTO 200
         ENDIF
         IF (ETID .LE. ETBOUN) ET(ETID) = THISET
C  keep track of edgetype 1
         IF (THISET .EQ. 1 ) STDET = .TRUE.
C  keep track of implementation-dependent types (non-positives):
         IF (THISET .LT. 1) IMPDEP = .TRUE.
200   CONTINUE
      CALL SETMSG ('32', 'All entries within the reported size of ' //
     1             'the list of available edgetypes should be '     //
     2             'accessible.')

      CALL IFPF (.NOT. ERRCOD)

      CALL SETMSG ('33', 'The list of available edgetypes should ' //
     1             'contain edgetype 1.')
      CALL IFPF (STDET)

      IF (NAET .GT. 0) THEN
C  positive number of available edgetypes - includes imp-dep
         IF (IMPDEP) THEN
C  looks OK - do nothing
         ELSE
            CALL SETMSG ('34 37', 'When system reports that no '   //
     1                   'implementation-dependent edgetypes are ' //
     2                   'available, none should be.')
            CALL ERRCTL (.TRUE.)
            DO 300 IMPET = 0, -3, -1
               CALL PSEDR (WKID, 1, PON, IMPET, 1.0, 1)
               IF (ERRSIG .NE. 107) THEN
                  CALL FAIL
                  WRITE (MSG, '(A,I5,A)')
     1                   'Implementation-dependent edgetype #', IMPET,
     2                   ' not rejected by set edge representation.'
                  CALL INMSG (MSG)
                  GOTO 350
               ENDIF
300         CONTINUE
            CALL PASS
350         CONTINUE
            CALL ERRCTL (.FALSE.)
         ENDIF
      ELSE
C  non-positive number of available edgetypes - excludes imp-dep
         CALL SETMSG ('35 37', 'Negative number of available '        //
     1                'edgetypes should indicate that list contains ' //
     2                'no implementation-dependent edgetypes.')
         CALL IFPF (.NOT. IMPDEP)
      ENDIF

      CALL SETMSG ('15 36', 'All entries within the reported list ' //
     1             'of available edgetypes should be realizable '   //
     2             'and valid.')
      CALL ERRCTL (.TRUE.)
C set all edgetypes
      DO 400 ETID = 1, MIN(ETBOUN, ABS(NAET))
        THISET = ET(ETID)
        CALL PSEDR (WKID, 3, PON, THISET, 1.0, 1)
        IF (ERRSIG .NE. 0) THEN
           CALL FAIL
           WRITE (MSG, '(A,I5,A)') 'Edgetype #', THISET,
     1            ' rejected as invalid.'
           CALL INMSG (MSG)
           GOTO 500
        ENDIF
C  inquire attributes as realized
C  ret = realized edgetype
        CALL PQEDR (WKID, 3, PREALI, ERRIND, IDUM1, RET, RDUM1, IDUM2)
        CALL CHKINQ ('pqedr', ERRIND)
        IF (RET .NE. THISET) THEN
           CALL FAIL
           WRITE (MSG, '(A,I5,A,I5,A)') 'Edgetype set as #', THISET,
     1            ' but realized as #', RET, '.'
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
