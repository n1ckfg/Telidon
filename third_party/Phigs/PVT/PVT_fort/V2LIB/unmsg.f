      SUBROUTINE UNMSG (MSG)

C UNMSG is used to generate messages for unanticipated errors
C which do not imply non-conformance of the implementation under test.
C It then forces a program abort.

      CHARACTER  MSG*(*)

      CALL ABEND ('UN', MSG)

      END
