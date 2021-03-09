      SUBROUTINE WINDUP

C  Windup handles end-of-test processing - it formulates two
C  messages, one with the total error count, the second to proclaim
C  end of execution.  If there has been an unanticipated error it
C  also generates a message for that.  It then closes the error
C  files, as needed.  It is normally the last thing called by a
C  test.

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

      INTEGER    ITRIM, ISZ, ICSZ

      CHARACTER AERRCT*3, ATSTCT*3, ERR*7, CWORD*11

      ERR   = ' errors'
      CWORD = ' conditions'

      WRITE (AERRCT, '(I3)') IERRCT
      WRITE (ATSTCT, '(I3)') TESTCT
      IF (IERRCT .EQ. 1) THEN
         ISZ = 6
      ELSE
         ISZ = 7
      ENDIF
      IF (TESTCT .EQ. 1) THEN
         ICSZ = 10
      ELSE
         ICSZ = 11
      ENDIF

      CALL BRDMSG ('SY: SUMMARY of PVT #' // PIDENT(1:ITRIM(PIDENT)) //
     1             ' : ' // AERRCT // ERR(1:ISZ) //
     2             ' detected, out of ' // ATSTCT //
     3             CWORD(1:ICSZ) // '.')

      IF (UNERR .NE. 0) THEN
         WRITE (AERRCT, '(I3)') UNERR
         IF (UNERR .EQ. 1) THEN
            ISZ = 6
         ELSE
            ISZ = 7
         ENDIF
         CALL BRDMSG ('SY: Encountered ' // AERRCT //
     1                ' unanticipated' // ERR(1:ISZ) // '.')
      ENDIF

C  Both pass and fail blank out tstmsg as a sign that they have processed
C  it, and so windup requires that it be blank upon entry.

      IF (TSTMSG .NE. ' ') CALL INMSG ('Non-blank tstmsg detected ' //
     1                     'by WINDUP.  Program logic error.')

      CALL BRDMSG ('SY: ------- End execution of PVT #' // PIDENT)
      CALL BRDMSG ('.')
      CALL BRDMSG ('.')
      CALL BRDMSG ('.')

C close error files

      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3) THEN
C close global file
         CLOSE (UNIT=GLBLUN)
      ENDIF

      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3) THEN
C close individual error file
         CLOSE (UNIT=INDLUN)
      ENDIF

      END
