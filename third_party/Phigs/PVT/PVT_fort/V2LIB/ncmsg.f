      SUBROUTINE NCMSG (MSG)

C NCMSG is used to generate messages for unanticipated errors
C which imply non-conformance of the implementation under test.
C It then forces a program abort.

      CHARACTER  MSG*(*)

      CALL ABEND ('NC', MSG)

      END
