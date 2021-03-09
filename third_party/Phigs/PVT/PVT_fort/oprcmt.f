C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 00/oprcmt                             *
C  *    TEST TITLE : Operator comments                     *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

C  FILE: OPRCMT.FOR

C  This program allows the operator to enter comments into the
C  relevant message files while not within a numbered test. It
C  should be used to record the result of an aborted test, or a test
C  that cannot start execution (e.g. cannot compile or link).

      PROGRAM OPRCMT

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

      INTEGER    ITRIM, NXTPOS

      CHARACTER  RESP*2000, RLINE*300

      PRINT *, 'Enter the identifier for the module and program ' //
     1         '(e.g. "06.01.02/02")'
      PRINT *, 'about which operator comment(s) are to be made.'

800   FORMAT (A)
      READ (*, 800) PIDENT

      CALL INITGL (PIDENT)

100   CONTINUE

      PRINT *, 'Enter next multi-line comment.  A line with a ' //
     1         'single period'
      PRINT *, 'terminates the comment.  A line with a single ' //
     1         '"q" terminates the'
      PRINT *, 'comment and this program.'
      RESP = 'OP:'

200   READ (*, 800) RLINE
      IF (RLINE.EQ.'.' .OR. RLINE.EQ.'q') THEN
C        do nothing
      ELSE
         NXTPOS = ITRIM(RESP) + 2
         RESP(NXTPOS:) = RLINE
         GOTO 200
      ENDIF

      IF (RESP .NE. 'OP:') CALL BRDMSG (RESP)

      IF (RLINE .EQ. '.') GOTO 100

      CALL WINDUP
      END
