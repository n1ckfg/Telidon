C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.01.02/01                           *
C  *    TEST TITLE : Characteristics of workstations       *
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
 
C workstation category
      INTEGER    POUTPT,     PINPUT,     POUTIN,     PMO,     PMI
      PARAMETER (POUTPT = 0, PINPUT = 1, POUTIN = 2, PMO = 3, PMI = 4)
 
C vector/raster/other type
      INTEGER    PVECTR,     PRASTR,     POTHWK
      PARAMETER (PVECTR = 0, PRASTR = 1, POTHWK = 2)
 
      INTEGER     LATY(200), NUMTYP, IX, WKCAT, IWK, NUMACC
      INTEGER     OWKID, OCONID, OWTYPE, SPECON, SPECWT, SPECAT
      INTEGER     WCLASS
      INTEGER     IDUM1, IDUM2, IDUM3
 
      LOGICAL     TYPEOK, GNONLY, CONOK, INQOK, CLASOK, GOTONE, CATOK
 
      CHARACTER   MSG*300, CDUM1*1
 
      CALL INITGL ('05.01.02/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('5 7', 'The number of available workstation '      //
     1             'types should be reported as at least 1.')
 
C  <inquire list of available workstation types> to determine
C     laty   = list of available types
      NUMTYP = -6
      CALL PQEWK (0, ERRIND, NUMTYP, IDUM1)
      IF (ERRIND .NE. 0 .OR. NUMTYP .LE. 0) THEN
         CALL FAIL
         GOTO 50
      ENDIF
 
      DO 20 IX = 1,NUMTYP
         CALL PQEWK (IX, ERRIND, IDUM1, LATY(IX))
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 50
         ENDIF
20    CONTINUE
      CALL PASS
 
      CALL SETMSG ('1 2 3 5', 'The result of <inquire workstation '   //
     1             'category> using a generic workstation type '      //
     2             'should be either a valid category or error 51.')
 
C  for each gtype = generic type in laty
      DO 40 IX = 1,NUMTYP
C        <inquire workstation category> using gtype to determine
C           wkcat = workstation category
         WKCAT = -6
         CALL PQWKCA (LATY(IX), ERRIND, WKCAT)
         IF ((ERRIND .EQ. 51)       .OR.
     1       (ERRIND .EQ. 0     .AND.
     2        WKCAT .GE. POUTPT .AND.
     3        WKCAT .LE. PMI))     THEN
C           OK so far - do nothing
         ELSE
            CALL FAIL
            WRITE (MSG, '(3(A,I6))')
     1         '<Inquire workstation category> for type = ', LATY(IX),
     2         ' returned error = ', ERRIND, ' and category = ', WKCAT
            CALL INMSG (MSG)
            GOTO 50
         ENDIF
40    CONTINUE
      CALL PASS
 
C  end_gtype:
50    CONTINUE
 
C  laccwk = list of accessible workstations
C     owkid  = workstation identifier for iwk'th workstation in laccwk
C     oconid = connection identifier for iwk'th workstation in laccwk
C     owtype = workstation type for iwk'th workstation in laccwk
C
C  typeok = true  = list of available workstation types
C                   contains all generic types
C  gnonly = true  = list of available workstation types
C                   contains only generic types
C  conok  = true  = connection identifiers ok
C  catok  = true  = <inquire workstation category> returns a
C                   valid category
C  inqok  = true  = <inquire workstation connection and type>
C                   works
C  clasok = true  = workstation classifications ok
C  gotone = false = got one OUTIN workstation
      TYPEOK = .TRUE.
      GNONLY = .TRUE.
      CONOK  = .TRUE.
      CATOK  = .TRUE.
      INQOK  = .TRUE.
      CLASOK = .TRUE.
      GOTONE = .FALSE.
 
      CALL MULTWS (0, 'a', NUMACC, IDUM1, IDUM2, IDUM3, CDUM1)
C  for each iwk in laccwk
      DO 100 IWK = 1,NUMACC
         CALL MULTWS (IWK, 'a', IDUM1, OWKID, OCONID, OWTYPE, CDUM1)
         DO 110 IX = 1,NUMTYP
            IF (OWTYPE .EQ. LATY(IX)) GOTO 120
110      CONTINUE
         TYPEOK = .FALSE.
120      CONTINUE
 
C     <open workstation> owkid(iwk)
         CALL POPWK (OWKID, OCONID, OWTYPE)
 
C     <inquire workstation connection and type> to determine
C        specon = connection identifier
C        specwt = specific workstation type
         CALL PQWKC (OWKID, ERRIND, SPECON, SPECWT)
 
         IF (ERRIND .EQ. 0) THEN
            IF (SPECON .NE. OCONID) THEN
               CONOK = .FALSE.
            ENDIF
            DO 130 IX = 1,NUMTYP
               IF (SPECWT .EQ. LATY(IX)) THEN
                  GNONLY = .FALSE.
                  GOTO 140
               ENDIF
130         CONTINUE
140         CONTINUE
         ELSE
            INQOK = .FALSE.
         ENDIF
 
C     <inquire workstation category> using specwt to determine
C        specat = workstation category
         SPECAT = -6
         CALL PQWKCA (SPECWT, ERRIND, SPECAT)
         IF (ERRIND .NE. 0       .OR.
     1       SPECAT .LT. POUTPT  .OR.
     2       SPECAT .GT. PMI)   THEN
            CATOK = .FALSE.
         ENDIF
 
         IF (SPECAT .EQ. POUTPT .OR. SPECAT .EQ. POUTIN) THEN
            WCLASS = -6
            CALL PQWKCL (SPECWT, ERRIND, WCLASS)
            IF (ERRIND .NE. 0          .OR.
     1          WCLASS .LT. PVECTR     .OR.
     2          WCLASS .GT. POTHWK) THEN
               CLASOK = .FALSE.
            ENDIF
         ENDIF
 
         IF (SPECAT .EQ. POUTIN) THEN
            GOTONE = .TRUE.
         ENDIF
 
         CALL PCLWK (OWKID)
C  next iwk
100   CONTINUE
 
      CALL SETMSG ('5 6', 'The generic workstation type of each '     //
     1             'accessible workstation should be in the list of ' //
     2             'available workstation types.')
      CALL IFPF (TYPEOK)
 
      CALL SETMSG ('5 6 8', 'The list of available workstation '      //
     1             'types should contain only generic types.')
      CALL IFPF (GNONLY)
 
      CALL SETMSG ('8', '<Inquire workstation connection and type> '  //
     1             'should report the same connection identifier as ' //
     2             'used in <open workstation>.')
      CALL IFPF (CONOK)
 
      CALL SETMSG ('8', '<Inquire workstation connection and type> '  //
     1             'should report a connection identifier and '       //
     2             'specific type for any open workstation.')
      CALL IFPF (INQOK)
 
      CALL SETMSG ('2 3', 'The reported category for any '          //
     1             'workstation type should be either OUTPUT, '     //
     2             'INPUT, OUTIN, MO, or MI.')
      CALL IFPF (CATOK)
 
      CALL SETMSG ('9 10', 'The reported workstation classification ' //
     1             'for workstations of category OUTPUT or OUTIN '    //
     2             'should be either VECTOR, RASTER, or OTHER.')
      CALL IFPF (CLASOK)
 
      CALL SETMSG ('2 3 4', 'There should be at least one '           //
     1             'workstation of category OUTIN.')
      CALL IFPF (GOTONE)
 
666   CONTINUE
      CALL ENDIT
      END
