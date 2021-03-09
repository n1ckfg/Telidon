      LOGICAL FUNCTION DCHFLV (PROMPT, MAXVAL, TRUANS)

C  DCHFLV operates just like DCHFL, except that the response is
C  tested directly against TRUANS.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    MAXVAL      : highest valid response.
C    TRUANS      : expected value from operator.

      INTEGER     TRUANS, MAXVAL, ANS

      CHARACTER   PROMPT*(*)

      CALL DCHOIC (PROMPT, 0,MAXVAL, ANS)
      DCHFLV = ANS .NE. TRUANS
      IF (ANS .EQ. 0) THEN
         CALL OPFAIL
      ELSEIF (DCHFLV) THEN
         CALL FAIL
      ENDIF

      END
