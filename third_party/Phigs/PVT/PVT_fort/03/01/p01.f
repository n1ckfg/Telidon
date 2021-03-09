C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.01/01                              *
C  *    TEST TITLE : Effect of <open archive file> and     *
C  *                 <close archive file>                  *
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

C archive state
C                closed   open
      INTEGER    PARCL,   PAROP
      PARAMETER (PARCL=0, PAROP=1)

      INTEGER    PGMAX
      PARAMETER (PGMAX = 200)

      INTEGER    ARID, ARNM, ALISIZ, MXARNO, ARSTAT, CUSTID,
     1           ACIDLS(PGMAX), ACNMLS(PGMAX),
     2           EXIDLS(PGMAX), EXNMLS(PGMAX),
     2           IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6,
     3           STRUID, ARCNUM, CNT, NUMSTR, LOOPCT

      LOGICAL    OPENOK, CLOSOK, STATOK, ARSET, ACCOK, SETEQ

      CHARACTER  MSG*300

C  Throughout, use variable names:
C  arid   : archive file identifier
C  arnm   : archive file name
C  mxarno : maximum number of simultaneously open archive files
C  arstat : archive file state
C  openok : <open archive file> ok flag
C  closok : <close archive file> ok flag
C  statok : archive state ok flag
C  arset  : open archive file set ok flag
C  accok  : access archive file ok flag
C  alisiz : actual size of open archive list
C  acidls : actual open archive file id. list
C  acnmls : actual open archive file name list
C  exidls : expected open archive file id. list
C  exnmls : expected open archive file name list
C  arcnum : opened archive file counter
C  struid : structure identifier
C  custid : structure identifier list in CSS

      CALL INITGL ('03.01/01')

      CALL SETMSG ('10', 'Before opening PHIGS, <inquire archive '    //
     1             'state value> should return the archive state as ' //
     2             'ARCL.')
C  <Inquire archive state value> to determine
C     arstat = archive file state
      ARSTAT = -66
      CALL PQARS (ARSTAT)
      CALL IFPF (ARSTAT .EQ. PARCL)

      CALL XPOPPH (ERRFIL, MEMUN)
      CALL SETMSG ('3 10', 'Immediately after <open phigs>, the ' //
     1             'archive state should be reported as ARCL.')
      ARSTAT = -66
      CALL PQARS (ARSTAT)
      CALL IFPF (ARSTAT .EQ. PARCL)

      CALL SETMSG ('4 11', 'Immediately after <open phigs>, the set ' //
     1             'of open archive files should be reported as empty.')
C  <Inquire archive files> to determine acidls
      ALISIZ = -66
      CALL PQARF (0, ERRIND, ALISIZ, IDUM1, IDUM2)
      CALL IFPF (ERRIND .EQ. 0 .AND. ALISIZ .EQ. 0)

      CALL SETMSG ('1 2', '<Inquire phigs facilities> should report ' //
     1             'the maximum number of simultaneously open '       //
     2             'archive files to be greater than 0.')
C  <Inquire phigs facilities> to determine
C     mxarno = maximum number of simultaneously open archive files
      CALL PQPHF (0, ERRIND, IDUM1, MXARNO, IDUM2, IDUM3, IDUM4, IDUM5,
     1            IDUM6)
      IF (ERRIND .EQ. 0 .AND. MXARNO .GT. 0) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') '<Inquire phigs facilities> ' //
     1         'reported error indicator = ', ERRIND,
     2         ' and maximum open archive files = ', MXARNO,
     3         '.  Skipping opening/closing tests.'
         CALL INMSG (MSG)
         GOTO 500
      ENDIF

      OPENOK = .TRUE.
      STATOK = .TRUE.
      ARSET  = .TRUE.
      ACCOK  = .TRUE.

C loop to open simultaneously the maximum number of archive files,
C up to the program maximum
      LOOPCT = MIN(PGMAX, MXARNO)
      DO 100 ARCNUM = 1, LOOPCT
         ARID = ARCNUM + 10
         CALL AVARNM (ARNM)
         CALL ERRCTL (.TRUE.)
C open next archive file
         CALL POPARF (ARID, ARNM)
         CALL ERRCTL (.FALSE.)
         IF (ERRSIG .NE. 0) THEN
            WRITE (MSG, '(A,I5,A,I4,A)') 'Got error ', ERRSIG,
     1            ' when attempting to open archive file named ',
     2            ARNM, '.'
            CALL INMSG (MSG)
            OPENOK = .FALSE.
            GOTO 100
         ENDIF

C  <Inquire archive state value> to determine
C  arstat = archive file state
         ARSTAT = -66
         CALL PQARS (ARSTAT)
         IF (ARSTAT .NE. PAROP) THEN
            STATOK = .FALSE.
         ENDIF

C  expected list of open archive files
         EXIDLS (ARCNUM) = ARID
         EXNMLS (ARCNUM) = ARNM
C  get actual list of open archive files
         CALL PQARF (0, ERRIND, ALISIZ, IDUM1, IDUM2)
         IF (ERRIND .NE. 0) THEN
            ARSET = .FALSE.
            GOTO 210
         ENDIF
         DO 200 CNT = 1, ALISIZ
            CALL PQARF (CNT, ERRIND, IDUM1, ACIDLS(CNT), ACNMLS(CNT))
            IF (ERRIND .NE. 0) THEN
               ARSET = .FALSE.
               GOTO 210
            ENDIF
200      CONTINUE
C  compare expected and actual list of open archive files
         IF (ALISIZ .EQ. ARCNUM             .AND.
     1       SETEQ (ALISIZ, EXIDLS, ACIDLS) .AND.
     2       SETEQ (ALISIZ, EXNMLS, ACNMLS))  THEN
C           OK so far
         ELSE
            ARSET = .FALSE.
         ENDIF
210      CONTINUE

C create structure and test access
         CALL PDAS
         CALL PDASAR (ARID)
         STRUID = ARCNUM+20
         CALL POPST (STRUID)
         CALL PLB   (ARCNUM+30)
         CALL PCLST

C  <archive all structures> with arid
         CALL PARAST (ARID)
         CALL PDAS
C  <retrieve all structures> with arid
         CALL PRAST (ARID)

C  <inquire structure identifiers> to determine:
C  custid = current structure identifier list in CSS
         CALL PQSID (1, ERRIND, NUMSTR, CUSTID)
         IF (ERRIND .EQ. 0  .AND.
     1       NUMSTR .EQ. 1  .AND.
     2       CUSTID .EQ. STRUID) THEN
C           OK so far
         ELSE
            ACCOK = .FALSE.
         ENDIF

C  end_open_loop
100   CONTINUE
C
      CALL SETMSG ('1 2', 'Opening the maximum number of '        //
     1             'simultaneously open archive files should be ' //
     2             'allowed.')
      CALL IFPF (OPENOK)

      CALL SETMSG ('5 10', 'A successful <open archive file> should ' //
     1             'set the archive state to AROP.')
      CALL IFPF (STATOK)

      CALL SETMSG ('6 11', 'A successful <open archive file> should ' //
     1             'add the specified file to the set of open '       //
     2             'archive files.')
      CALL IFPF (ARSET)

      CALL SETMSG ('7', 'A successful <open archive file> should ' //
     1             'provide access to the archive file of the '    //
     2             'specified name through the specified identifier.')
      CALL IFPF (ACCOK)

      CLOSOK = .TRUE.
      STATOK = .TRUE.
      ARSET  = .TRUE.
C loop to close the archive files
      DO 300 ARCNUM = LOOPCT, 1, -1
         ARID = ARCNUM + 10
         CALL ERRCTL (.TRUE.)
         CALL PCLARF (ARID)
         CALL ERRCTL (.FALSE.)
         IF (ERRSIG .NE. 0) THEN
            WRITE (MSG, '(A,I5,A,I4,A)') 'Got error ', ERRSIG,
     1            ' when attempting to close archive file with ' //
     2            'identifier #', ARID, '.'
            CALL INMSG (MSG)
            CLOSOK = .FALSE.
         ENDIF

C check archive state value
         ARSTAT = -66
         CALL PQARS (ARSTAT)
         IF (ARCNUM .EQ. 1) THEN
            IF (ARSTAT .NE. PARCL) THEN
               STATOK = .FALSE.
            ENDIF
         ELSE
            IF (ARSTAT .NE. PAROP) THEN
               STATOK = .FALSE.
            ENDIF
         ENDIF

C get actual list of open archive files
         CALL PQARF (0, ERRIND, ALISIZ, IDUM1, IDUM2)
         IF (ERRIND .NE. 0) THEN
            ARSET = .FALSE.
            GOTO 410
         ENDIF
         DO 400, CNT = 1, ALISIZ
            CALL PQARF (CNT, ERRIND, IDUM1, ACIDLS(CNT), ACNMLS(CNT))
            IF (ERRIND .NE. 0) THEN
               ARSET = .FALSE.
               GOTO 410
            ENDIF
400      CONTINUE

C  compare expected and actual list of open archive files
         IF (ALISIZ .EQ. ARCNUM - 1         .AND.
     1       SETEQ (ALISIZ, EXIDLS, ACIDLS) .AND.
     2       SETEQ (ALISIZ, EXNMLS, ACNMLS))  THEN
C           OK so far
         ELSE
            ARSET = .FALSE.
         ENDIF
410      CONTINUE

300   CONTINUE
C
      CALL SETMSG ('8 10', 'A successful <close archive file> on '   //
     1             'the last open archive file should set the '      //
     2             'archive state to ARCL, but otherwise leave the ' //
     3             'state as AROP.')
      CALL IFPF (STATOK)

      CALL SETMSG ('9', 'Closing an archive file in the set of open ' //
     1             'archive files should succeed.')
      CALL IFPF (CLOSOK)

      CALL SETMSG ('9 11', 'A successful <close archive file> '     //
     1             'should remove the specified file from the set ' //
     2             'of open archive files.')
      CALL IFPF (ARSET)

C check_close:
500   CONTINUE
      CALL PCLPH

      CALL SETMSG ('10', 'After closing PHIGS, <inquire archive '     //
     1             'state value> should return the archive state as ' //
     2             'ARCL.')
      ARSTAT = -66
      CALL PQARS (ARSTAT)
      CALL IFPF (ARSTAT .EQ. PARCL)

      CALL XPOPPH (ERRFIL, MEMUN)
      CALL SETMSG ('3 10', 'After closing and re-opening PHIGS, the ' //
     1             'archive state should be reported as ARCL.')
      ARSTAT = -66
      CALL PQARS (ARSTAT)
      CALL IFPF (ARSTAT .EQ. PARCL)

      CALL SETMSG ('4 11', 'After closing and re-opening PHIGS, the ' //
     1             'set of open archive files should be reported as ' //
     2             'empty.')
      CALL PQARF (0, ERRIND, ALISIZ, IDUM1, IDUM2)
      CALL IFPF (ERRIND .EQ. 0 .AND. ALISIZ .EQ. 0)

666   CONTINUE
      CALL ENDIT
      END
