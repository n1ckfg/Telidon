C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/14                        *
C  *    TEST TITLE : Appearance of character expansion     *
C  *                 factor for STRING and CHAR precision  *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      CALL INITGL ('04.02.03.02/14')

      CALL SETMSG ('39 47 48 49 57 58 59', 'Test cases for the '     //
     1             'visual effect of the approximated text '         //
     2             'attribute character expansion factor in STRING ' //
     3             'and CHAR precision are not yet available.')
      CALL PASS

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
