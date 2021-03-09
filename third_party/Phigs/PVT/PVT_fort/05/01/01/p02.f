C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.01.01/02                           *
C  *    TEST TITLE : Simple open and close of a single     *
C  *                 workstation                           *
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

      INTEGER WKSVAL, NUMOPW, N, NWKID
      INTEGER IWK, NUMACC, SPECWT, IDUM1, IDUM2, IDUM3
      INTEGER OWKID, OCONID, OWTYPE

      CHARACTER MSG*900, CDUM1*1

      LOGICAL WKOPEN, WKCLOS, ONEOPN, INSET, NOOPWK, VALOK,
     1        TYPDIF

C workstation category
      INTEGER    POUTPT,   PINPUT,   POUTIN,   PMO,   PMI
      PARAMETER (POUTPT=0, PINPUT=1, POUTIN=2, PMO=3, PMI=4)
C workstation state
      INTEGER    PWSCL,     PWSOP
      PARAMETER (PWSCL = 0, PWSOP = 1)

      CALL INITGL ('05.01.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  wkopen = true = workstation state is WSOP
C  wkclos = true = workstation state is WSCL
C  oneopn = true = one workstation identifier in 'set of open
C                  workstations'
C  inset  = true = correct workstation identifier in 'set of open
C                  workstations'
C  noopwk = true = no workstations open
C  valok  = true = state value either WSOP or WSCL
C  typdif = true = workstation type different
      WKOPEN = .TRUE.
      WKCLOS = .TRUE.
      ONEOPN = .TRUE.
      INSET  = .TRUE.
      NOOPWK = .TRUE.
      VALOK  = .TRUE.
      TYPDIF = .TRUE.

      WKSVAL = -6
C  <inquire workstation state value> to determine
C     wksval = workstation state value
      CALL PQWKST (WKSVAL)
      IF (WKSVAL .NE. PWSCL .AND. WKSVAL .NE. PWSOP) THEN
         VALOK = .FALSE.
         WRITE (MSG, '(A, A, I5)') 'Workstation state value ',
     1          'invalid, reported as ', WKSVAL
         CALL INMSG (MSG)
      ENDIF

C  get each accessible workstation
      CALL MULTWS (0, 'a', NUMACC, IDUM1, IDUM2, IDUM3, CDUM1)
      DO 200 IWK = 1, NUMACC
         CALL MULTWS (IWK, 'a', IDUM1, OWKID, OCONID, OWTYPE, CDUM1)
         CALL POPWK (OWKID, OCONID, OWTYPE)

         WKSVAL = -6
C     <inquire workstation state value> to determine wksval
         CALL PQWKST (WKSVAL)
         IF (WKSVAL .NE. PWSOP) THEN
            WKOPEN = .FALSE.
            IF (WKSVAL .NE. PWSCL) THEN
               VALOK = .FALSE.
            ENDIF
         ENDIF

C     <inquire set of open workstations> to determine
C        numopw = number of open workstations
         CALL PQOPWK (0, ERRIND, NUMOPW, IDUM1)
         CALL CHKINQ ('pqopwk', ERRIND)
         IF (NUMOPW .NE. 1) THEN
            ONEOPN = .FALSE.
         ENDIF

C check that owkid is in set
         DO 100 N = 1, NUMOPW
            CALL PQOPWK (N, ERRIND, IDUM1, NWKID)
            CALL CHKINQ ('pqopwk', ERRIND)
            IF (OWKID .EQ. NWKID) GOTO 110
100      CONTINUE
         INSET = .FALSE.
110      CONTINUE

C     <inquire workstation connection and type> to determine
C        specwt = specific workstation type
         CALL PQWKC (OWKID, ERRIND, IDUM1, SPECWT)
         CALL CHKINQ ('pqwkc', ERRIND)
         IF (SPECWT .EQ. OWTYPE) THEN
            TYPDIF = .FALSE.
         ENDIF

C close workstation
        CALL PCLWK (OWKID)

        CALL PQOPWK (0,ERRIND, NUMOPW, IDUM1)
        CALL CHKINQ ('pqopwk', ERRIND)
        IF (NUMOPW .NE. 0) THEN
           NOOPWK = .FALSE.
        ENDIF
        WKSVAL = -6
        CALL PQWKST (WKSVAL)
        IF (WKSVAL .NE. PWSCL) THEN
           WKCLOS = .FALSE.
           IF (WKSVAL .NE. PWSOP) THEN
              VALOK = .FALSE.
           ENDIF
        ENDIF

C  next workstation
200   CONTINUE

C  *** *** *** actual tests go here *** ***

      CALL SETMSG ('3 4 5', 'In all circumstances, the reported '     //
     1             'workstation state values should be either WSOP '  //
     2             'or WSCL.')
      CALL IFPF (VALOK)

      CALL SETMSG ('3 5', 'After <open workstation>, the '            //
     1             'workstation state value should be WSOP.')
      CALL IFPF (WKOPEN)

      CALL SETMSG ('6 7', 'If no workstations are open, then '        //
     1             'immediately after <open workstation>, the '       //
     2             'number of workstation identifiers in the set of ' //
     3             'open workstations should be 1.')
      CALL IFPF (ONEOPN)

      CALL SETMSG ('6 7', 'Immediately after <open workstation>, '    //
     1             'the set of open workstations should contain the ' //
     2             'workstation identifier just opened.')
      CALL IFPF (INSET)

      CALL SETMSG ('8', 'The specific workstation type of an open '   //
     1             'workstation should be different from the '        //
     2             'generic type with which it was opened.')
      CALL IFPF (TYPDIF)

      CALL SETMSG ('7 12', 'If only one workstation is open, then '   //
     1             '<close workstation> should result in the set of ' //
     2             'open workstations being empty.')
      CALL IFPF (NOOPWK)

      CALL SETMSG ('3 4', 'If no workstations are open, then the '    //
     1             'workstation state value should be WSCL.')
      CALL IFPF (WKCLOS)

666   CONTINUE
      CALL ENDIT
      END
