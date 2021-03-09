      SUBROUTINE E02056 (USEPRM)

C  E02056 tests the handling of error number 56.
      INTEGER USEPRM

      CALL SETMSG ('6', 'Test for error 56 (writing to workstation ' //
     1             'not of category MO) not yet available.')
      CALL PASS

      END
