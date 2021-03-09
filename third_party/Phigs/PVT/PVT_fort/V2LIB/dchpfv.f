      SUBROUTINE DCHPFV (PROMPT, MAXVAL, TRUANS)

C  DCHPFV operates just like DCHPF, except that the response is
C  tested directly against TRUANS.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    MAXVAL      : highest valid response.
C    TRUANS      : expected value from operator.

      INTEGER     TRUANS, MAXVAL, ANS

      CHARACTER   PROMPT*(*)

      CALL DCHOIC (PROMPT, 0,MAXVAL, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPFAIL
      ELSE
         CALL IFPF (ANS .EQ. TRUANS)
      ENDIF

      END
