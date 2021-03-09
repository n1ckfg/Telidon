      SUBROUTINE E02060 (USEPRM)

C  E02060 tests the handling of error number 60.
      INTEGER USEPRM

      CALL SETMSG ('10', 'Test for error 60 (using pick on '     //
     1             'workstation not of category OUTIN) not yet ' //
     2             'available.')
      CALL PASS

      END
