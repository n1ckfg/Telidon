      SUBROUTINE E02061 (USEPRM)

C  E02061 tests the handling of error number 61.
      INTEGER USEPRM

      CALL SETMSG ('11', 'Test for error 61 (graphical input from ' //
     1             'workstation not of category OUTIN or INPUT) '   //
     2             'not yet available.')
      CALL PASS

      END
