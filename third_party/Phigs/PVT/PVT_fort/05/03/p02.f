C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.03/02                              *
C  *    TEST TITLE : Setting and inquiring display         *
C  *                 priorities                            *
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
 
      INTEGER    NDPSUP, SPECON, SPECWT, STRID(3), ISTR
      INTEGER    NUMSTR, REPID
 
      REAL       STRPRI(3), REPPRI, PRI1,PRI2
 
      CHARACTER  MSG*300
 
C  strpri = array of display priorities
      DATA  STRPRI /0.0, 0.67, 1.0/
 
      CALL INITGL ('05.03/02')
 
C open PHIGS & workstation
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
C  Use <inquire number of display priorities supported> to determine:
C     ndpsup = number of display priorities supported
      CALL PQDP (SPECWT, ERRIND, NDPSUP)
      WRITE (MSG, '(A,I5)') 'Reported number of display priorities ' //
     1       'for primary workstation type = ', NDPSUP
      CALL INMSG (MSG)
 
      CALL SETMSG ('16 17', '<Inquire number of display priorities '  //
     1             'supported> should report the number of display '  //
     2             'priorities for any specific workstation type as ' //
     3             '0 or >= 2.')
 
      IF (ERRIND .EQ. 0 .AND. (NDPSUP .EQ. 0 .OR. NDPSUP .GE. 2)) THEN
         CALL PASS
      ELSE
         CALL FAIL
         CALL INMSG ('Skipping all further tests for display priority.')
         GOTO 600
      ENDIF
 
C post 3 structures
      DO 100 ISTR = 1,3
         STRID (ISTR) = 100+ISTR
         CALL PPOST (WKID, STRID(ISTR), STRPRI(ISTR))
100   CONTINUE
 
      IF (NDPSUP .EQ. 0) THEN
         CALL SETMSG ('3 15 16 18', 'A workstation with the '     //
     1                'number of display priorities equal to 0 '  //
     2                'should report any valid display priority ' //
     3                'exactly as it was set.')
         CALL PQPOST (WKID, 0, ERRIND, NUMSTR, REPID, REPPRI)
         CALL CHKINQ ('pqpost', ERRIND)
         IF (NUMSTR .NE. 3) GOTO 160
         DO 110 ISTR = 1,3
            CALL PQPOST (WKID, ISTR, ERRIND, NUMSTR, REPID, REPPRI)
            CALL CHKINQ ('pqpost', ERRIND)
            IF (REPID  .LT. 101 .OR. REPID .GT. 103) GOTO 160
            IF (REPPRI .NE. STRPRI (REPID-100))      GOTO 160
C prevent re-use of same priority
            STRPRI (REPID-100) = -66.6
110      CONTINUE
         CALL PASS
         GOTO 600
160      CONTINUE
         CALL FAIL
      ELSE
         CALL SETMSG ('3 15 16 19', 'A workstation with the '      //
     1                'number of display priorities equal to at '  //
     2                'least 2 should be able to distinguish the ' //
     3                'highest and lowest valid priority.')
         PRI1 =  1E33
         PRI2 = -1E33
         DO 120 ISTR = 1,3
            CALL PQPOST (WKID, ISTR, ERRIND, NUMSTR, REPID, REPPRI)
            CALL CHKINQ ('pqpost', ERRIND)
            IF (REPID .EQ. 101) PRI1 = REPPRI
            IF (REPID .EQ. 103) PRI2 = REPPRI
120      CONTINUE
         CALL IFPF (PRI1 .LT. PRI2)
      ENDIF
 
C  done:
600   CONTINUE
      CALL ENDIT
      END
