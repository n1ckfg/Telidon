      SUBROUTINE OPMSG (MSG)

C  OPMSG writes out a message to the operator.  No assumptions are
C  made that a workstation is open.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      INTEGER     NXT, ITRIM, IX, IY, MLEN, LASTB

      CHARACTER   MSG*(*)

      IF (MSG .EQ. ' ') THEN
         PRINT *, ' '
         RETURN
      ENDIF

C  set IX,LASTB to start, end of substring to be printed
      IX = 1
      MLEN = ITRIM(MSG)

100   CONTINUE
      IF (MLEN-IX .LT. MAXLIN) THEN
         PRINT *, MSG(IX:MLEN)
         RETURN
      ENDIF

      DO 200 IY = IX+MAXLIN, IX, -1
         IF (MSG(IY:IY) .EQ. ' ') THEN
            LASTB = IY
            NXT = LASTB+1
            GOTO 210
         ENDIF
200   CONTINUE

      LASTB = IX+MAXLIN
      NXT = LASTB

210   CONTINUE
      PRINT *, MSG(IX:LASTB-1)
      IX = NXT
      GOTO 100

      END
