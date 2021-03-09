C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.03/03                           *
C  *    TEST TITLE : HLHSR facilities                      *
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

C  Declare program-specific variables
      INTEGER  NAID, NAMOD, HR, THISID, THISMD, REQMOD
      INTEGER  IDUM1, IDUM2, IDUM3

      LOGICAL  ERRCOD, DEFID, DEFMOD

      CHARACTER  MSG*300

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      CALL INITGL ('04.03.03/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
C get this workstation type
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  <inquire HLHSR facilities> to determine
C     naid  = number of available HLHSR identifiers
      NAID = -6
      CALL PQHRIF (SPECWT, 0, ERRIND, NAID, IDUM3)
      CALL CHKINQ ('pqhrif', ERRIND)

C *** *** *** *** HLHSR identifier tests *** *** *** ***
      ERRCOD = .FALSE.
      DEFID  = .FALSE.

      DO 100 HR = 1, NAID
         THISID = -6
         CALL PQHRIF (SPECWT, HR, ERRIND, IDUM1, THISID)
         IF (ERRIND .NE. 0) THEN
            ERRCOD = .TRUE.
            WRITE  (MSG, '(A,I5,A,I5,A)') 'Got error indicator ',
     1              ERRIND, ' while accessing HLHSR indentifier #',
     2              THISID, '.'
            CALL INMSG (MSG)
            GOTO 100
         ENDIF
C check for HLHSR identifier 0
         IF (THISID .EQ. 0)  THEN
            DEFID = .TRUE.
         ENDIF
100   CONTINUE
      CALL SETMSG ('8', 'All HLHSR identifiers in the list of ' //
     1             'available HLHSR identifiers should be '     //
     2             'accessible.')
      CALL IFPF (.NOT. ERRCOD)

      CALL SETMSG ('9', 'The reported number of HLHSR identifiers '   //
     1             'should be at least 1.')
      CALL IFPF (NAID .GE. 1)

      CALL SETMSG ('9', 'The list of available HLHSR identifiers '    //
     1             'should contain 0.')
      CALL IFPF (DEFID)

*** *** *** *** HLHSR mode tests *** *** *** ***

C  <inquire HLHSR facilities> to determine
C     namod = number of available HLHSR modes
      NAMOD = -6
      CALL PQHRMF (SPECWT, 0, ERRIND, NAMOD, IDUM3)
      CALL CHKINQ ('pqhrmf', ERRIND)

      ERRCOD = .FALSE.
      DEFMOD = .FALSE.

      DO 400 HR = 1, NAMOD
         THISMD = -6
         CALL PQHRMF (SPECWT, HR, ERRIND, IDUM3, THISMD)
         IF (ERRIND .NE. 0) THEN
            ERRCOD = .TRUE.
            WRITE  (MSG, '(A,I5,A,I5,A)') 'Got error indicator ',
     1              ERRIND, ' while accessing HLHSR mode #',
     2              THISMD, '.'
            CALL INMSG (MSG)
            GOTO 400
         ENDIF
C check for HLHSR mode 0
         IF (THISMD .EQ. 0)  THEN
            DEFMOD = .TRUE.
         ENDIF
400   CONTINUE

      CALL SETMSG ('8', 'All HLHSR modes in the list of ' //
     1             'available HLHSR modes should be '     //
     2             'accessible.')
      CALL IFPF (.NOT. ERRCOD)

      CALL SETMSG ('10', 'The reported number of HLHSR modes should ' //
     1             'be at least 1.')
      CALL IFPF (NAMOD .GE. 1)

      CALL SETMSG ('10', 'The list of available HLHSR modes should '  //
     1             'contain 0.')
      CALL IFPF (DEFMOD)

      CALL SETMSG ('11', 'All modes within the reported list of ' //
     1             'available HLHSR modes should be valid.')
      CALL ERRCTL (.TRUE.)
      DO 500 HR = 1, NAMOD
C get each HLHSR mode and set it
         THISMD = -6
         CALL PQHRMF (SPECWT, HR, ERRIND, IDUM3, THISMD)
         CALL CHKINQ ('pqhrmf', ERRIND)
         CALL PSHRM (WKID, THISMD)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A)') 'HLHSR mode ', THISMD,
     1             ' rejected as invalid.'
            CALL INMSG (MSG)
            GOTO 666
         ENDIF
C <inquire HLHSR mode> to determine
C  reqmod = requested HLHSR mode
         CALL PQHRM (WKID, ERRIND, IDUM1, IDUM2, REQMOD)
         CALL CHKINQ ('pqhrm', ERRIND)
         IF (REQMOD .NE. THISMD) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A, I5,A)') 'HLHSR mode set as ',
     1             THISMD, ' but reported as ', REQMOD, '.'
            CALL INMSG (MSG)
            GOTO 666
         ENDIF
500   CONTINUE
      CALL PASS

666   CONTINUE
      CALL ERRCTL (.FALSE.)
      CALL ENDIT
      END
