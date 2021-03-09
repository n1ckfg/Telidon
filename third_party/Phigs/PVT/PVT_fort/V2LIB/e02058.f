      SUBROUTINE E02058 (USEPRM)

C  E02058 tests the handling of error number 58.
      INTEGER USEPRM

      CALL SETMSG ('8', 'Test for error 58 (metafile retrieval '   //
     1             'from workstation not of category MI) not yet ' //
     1             'available.')
      CALL PASS

      END
