      SUBROUTINE SIGMSG (PERRSG, FUNCNM, MSG)

C  SIGMSG formulates a message indicating that the function named by
C  funcnm signalled the error code perrsg.

C  Input parameters:
C    PERRSG : Error code to be incorporated in MSG
C    FUNCNM : Name of erroneous function to be incorporated in MSG
C  Output parameters:
C    MSG    : Resulting descriptive message

      INTEGER    PERRSG, ITRIM
      CHARACTER  FUNCNM*(*), MSG*(*)

      CHARACTER  ERRCH*6

      WRITE (ERRCH, '(I6)') PERRSG
      IF (FUNCNM .EQ. ' ') THEN
         MSG = 'No error signalled; current error code = ' //
     1          ERRCH // '.'
      ELSE
         MSG = 'Function ' // FUNCNM(1:ITRIM(FUNCNM)) //
     1         ' signalled error code ' // ERRCH // '.'
      ENDIF

      END
