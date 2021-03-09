      LOGICAL FUNCTION ERMSGH (EREC, ERRMRK, NMRK)

C  ERMSGH determines whether or not a given record from the error file is
C  the header of an error message, i.e. whether it is the first record of
C  a possibly multi-record message.  The default logic allows for
C  searching for the presence of a given string (ERRMRK) within the
C  record, but users may code any logic needed by which to distinguish
C  message headers.

CUSERMOD modify if necessary.

C  Input parameters:
C    EREC   : record from error file to be examined
C    ERRMRK : distinctive character string identifying message header
C    NMRK   : number of significant characters in ERRMRK

      INTEGER    NMRK
      CHARACTER  EREC*(*), ERRMRK*(*)

      ERMSGH = INDEX(EREC, ERRMRK(1:NMRK)) .GE. 1

      END
