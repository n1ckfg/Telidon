C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.01.01/03                           *
C  *    TEST TITLE : Opening and closing multiple          *
C  *                 workstations                          *
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
 
C workstation state
      INTEGER    PWSCL,     PWSOP
      PARAMETER (PWSCL = 0, PWSOP = 1)
 
      INTEGER    NUMACC, MAXSIM, MAXCT, IDENT(200), TYPE(200)
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6
      INTEGER    OWKID, OCONID, OWTYPE, SETOPN(200), NUMOPW, N
      INTEGER    WKSVAL, SPECWT, ID, ID2
 
      LOGICAL    OPENOK, SETOK, SETEQ, WSOPOK, WSCLOK
 
      CHARACTER  CDUM1*1, MSG*300
 
 
      CALL INITGL ('05.01.01/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  numacc = number of accessible workstations (from configuration file)
      CALL MULTWS (0, 'a', NUMACC, IDUM1, IDUM2, IDUM3, CDUM1)
 
      CALL SETMSG ('9 10', 'The maximum number of simultaneously '    //
     1             'open workstations returned by <inquire phigs '    //
     2             'facilities> should be at least 1.')
 
C  <inquire phigs facilities> to determine
C     maxsim = maximum number of simultaneously open workstations
      CALL PQPHF (1, ERRIND, MAXSIM,
     1            IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6)
      CALL CHKINQ ('pqphf', ERRIND)
      CALL IFPF (MAXSIM .GE. 1)
 
      IF (MAXSIM .LE. NUMACC) THEN
         MAXCT = MAXSIM
         CALL SETMSG ('9 11', 'If the maximum number of '          //
     1                'simultaneously open workstations is less '  //
     2                'than or equal to the number of accessible ' //
     3                'workstations, then it should be possible '  //
     4                'to have that maximum simultaneously open.')
      ELSE
         MAXCT = NUMACC
         CALL SETMSG ('9 11', 'If the maximum number of '         //
     1                'simultaneously open workstations is '      //
     2                'greater than the number of accessible '    //
     3                'workstations, then it should be possible ' //
     4                'to open all accessible workstations '      //
     5                'simultaneously.')
      ENDIF
 
C  *** *** *** *** ***   open workstations  *** *** *** *** ***
C
C  openok = true = workstation state value is open
C  setok  = true = set of open workstations is correct
C  ident(maxct) = array of workstation identifiers
C  type(maxct)  = array of specific workstation types
      OPENOK = .TRUE.
      SETOK  = .TRUE.
      DO 100 ID = 1,MAXCT
         CALL MULTWS (ID, 'a', IDUM1, OWKID, OCONID, OWTYPE, CDUM1)
         CALL ERRCTL (.TRUE.)
         CALL POPWK (OWKID, OCONID, OWTYPE)
         CALL ERRCTL (.FALSE.)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A,I5)') '<Open workstation> failed ' //
     1            'with error code = ', ERRSIG,
     2            ' for workstation identifier = ', OWKID
            CALL INMSG (MSG)
            MAXCT = ID-1
            GOTO 110
         ENDIF
 
C        <inquire workstation state value> to determine
C           wksval = workstation state value
         CALL PQWKST (WKSVAL)
         IF (WKSVAL .NE. PWSOP) THEN
            OPENOK = .FALSE.
         ENDIF
 
C save opened workstations
         IDENT(ID) = OWKID
 
C        <inquire workstation connection and type> to determine
C           specwt = specific workstation type
         CALL PQWKC (OWKID, ERRIND, IDUM1, SPECWT)
         CALL CHKINQ ('pqwkc', ERRIND)
         TYPE(ID) = SPECWT
 
C        <inquire set of open workstations> to determine
C           setopn = set of open workstations
         CALL PQOPWK (0, ERRIND, NUMOPW, IDUM1)
         CALL CHKINQ ('pqopwk', ERRIND)
         IF (NUMOPW .EQ. ID) THEN
            DO 120 N = 1, NUMOPW
               CALL PQOPWK (N, ERRIND, IDUM1, SETOPN(N))
               CALL CHKINQ ('pqopwk', ERRIND)
120         CONTINUE
            IF (SETEQ (NUMOPW, IDENT, SETOPN)) THEN
C              OK so far
            ELSE
               SETOK = .FALSE.
            ENDIF
         ELSE
            SETOK = .FALSE.
         ENDIF
 
C  loop for next workstation
100   CONTINUE
      CALL PASS
 
C  end_open_test:
110   CONTINUE
 
      CALL SETMSG ('3 5', 'If at least 1 workstation is open, the '   //
     1             'workstation state value should be WSOP.')
      CALL IFPF (OPENOK)
 
      CALL SETMSG ('6 7', 'As workstations are opened, the set of '   //
     1             'open workstations should contain the '            //
     2             'identifiers of the open workstations and '        //
     3             'nothing else.')
      CALL IFPF (SETOK)
 
      CALL SETMSG ('8', 'Every open workstation should have a '       //
     1             'unique specific workstation type.')
 
      DO 200 ID  =    1, MAXCT-1
      DO 210 ID2 = ID+1, MAXCT
         IF (TYPE(ID) .EQ. TYPE(ID2)) THEN
            CALL FAIL
            WRITE (MSG, '(3(A,I5))') 'Workstations ', IDENT(ID),
     1            ' and ', IDENT(ID2), ' both have type = ', TYPE(ID)
            CALL INMSG (MSG)
            GOTO 290
         ENDIF
210   CONTINUE
200   CONTINUE
      CALL PASS
 
C  end_typedif
290   CONTINUE
 
C  *** *** *** *** close workstations *** *** *** ***
C
C  wsopok = true = workstation state value WSOP is ok
C  wsclok = true = workstation state value WSCL is ok
C  setok  = true = set of open workstations is correct
      WSOPOK = .TRUE.
      WSCLOK = .TRUE.
      SETOK  = .TRUE.
 
      DO 300 ID = 1, MAXCT
         CALL PCLWK (IDENT(ID))
 
         CALL PQWKST (WKSVAL)
         IF (ID .LT. MAXCT) THEN
            IF (WKSVAL .NE. PWSOP) THEN
               WSOPOK = .FALSE.
            ENDIF
         ELSE
            IF (WKSVAL .NE. PWSCL) THEN
               WSCLOK = .FALSE.
            ENDIF
         ENDIF
 
C        <inquire set of open workstations> to determine
C           setopn = set of open workstations
         CALL PQOPWK (0, ERRIND, NUMOPW, IDUM1)
         CALL CHKINQ ('pqopwk', ERRIND)
         IF (NUMOPW .EQ. MAXCT-ID) THEN
            DO 320 N = 1, NUMOPW
               CALL PQOPWK (N, ERRIND, IDUM1, SETOPN(N))
               CALL CHKINQ ('pqopwk', ERRIND)
320         CONTINUE
            IF (SETEQ (NUMOPW, IDENT(ID+1), SETOPN)) THEN
C              OK so far
            ELSE
               SETOK = .FALSE.
            ENDIF
         ELSE
            SETOK = .FALSE.
         ENDIF
 
C  loop for next workstation
300   CONTINUE
 
      CALL SETMSG ('3 5', 'As workstations are closed, if at least '  //
     1             'one workstation is still open, the workstation '  //
     2             'state value should be WSOP.')
      CALL IFPF (WSOPOK)
 
      CALL SETMSG ('3 4', 'After the last open workstation is '       //
     1             'closed, the workstation state value should be '   //
     2             'WSCL.')
      CALL IFPF (WSCLOK)
 
      CALL SETMSG ('7 12', 'As workstations are closed, the set of '  //
     1             'open workstations should contain the '            //
     2             'identifiers of the workstations left open and '   //
     3             'nothing else.')
      CALL IFPF (SETOK)
 
666   CONTINUE
      CALL ENDIT
      END
