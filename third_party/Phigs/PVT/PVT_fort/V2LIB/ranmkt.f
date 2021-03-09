      INTEGER FUNCTION RANMKT (STDDX,LAVSMT, REGDX,LAVRMT,IMPDX,LAVIMT)

C  RANMKT chooses a marker type at random from the three lists of
C  available marker types.

      INTEGER    STDDX,REGDX,IMPDX, WHLIST, RNDINT
      INTEGER    LAVSMT(*), LAVRMT(*), LAVIMT(*)

100   CONTINUE
      WHLIST = RNDINT (1,3)
      IF (WHLIST .EQ. 1) THEN
         IF (STDDX .LE. 0) GOTO 100
         RANMKT = LAVSMT(RNDINT(1,STDDX))
C don't allow marker type 1 (dot)
         IF (RANMKT .EQ. 1) GOTO 100
      ELSEIF (WHLIST .EQ. 2) THEN
         IF (REGDX .LE. 0) GOTO 100
         RANMKT = LAVRMT(RNDINT(1,REGDX))
      ELSE
         IF (IMPDX .LE. 0) GOTO 100
         RANMKT = LAVIMT(RNDINT(1,IMPDX))
      ENDIF

      END
