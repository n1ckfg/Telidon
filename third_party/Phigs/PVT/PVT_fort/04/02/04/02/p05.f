C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.02/05                        *
C  *    TEST TITLE : Appearance of character expansion     *
C  *                 factor for STRING and CHAR precision  *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      CALL INITGL ('04.02.04.02/05')
 
      CALL SETMSG ('12 20 21 22 24 25 26', 'Test cases for the '   //
     1             'visual effect of the approximated annotation ' //
     2             'text attribute character expansion factor in ' //
     3             'STRING and CHAR precision are not yet available.')
      CALL PASS
 
666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
