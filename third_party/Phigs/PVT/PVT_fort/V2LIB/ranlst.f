      INTEGER FUNCTION RANLST (STDDX,LAVSLT, REGDX,LAVRLT, IMPDX,LAVILT)

C  RANLST chooses a linetype at random from the three lists of
C  available linetypes.

      INTEGER    STDDX,REGDX,IMPDX, WHLIST, RNDINT
      INTEGER    LAVSLT(*), LAVRLT(*), LAVILT(*)

100   CONTINUE
      WHLIST = RNDINT (1,3)
      IF (WHLIST .EQ. 1) THEN
         IF (STDDX .LE. 0) GOTO 100
         RANLST = LAVSLT(RNDINT(1,STDDX))
      ELSEIF (WHLIST .EQ. 2) THEN
         IF (REGDX .LE. 0) GOTO 100
         RANLST = LAVRLT(RNDINT(1,REGDX))
      ELSE
         IF (IMPDX .LE. 0) GOTO 100
         RANLST = LAVILT(RNDINT(1,IMPDX))
      ENDIF

      END
