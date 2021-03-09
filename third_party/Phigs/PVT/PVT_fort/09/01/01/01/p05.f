C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01.01.01/05                        *
C  *    TEST TITLE : Error 5 handled by user               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      CALL INITGL ('09.01.01.01/05')
      CALL E01005 (1)
      CALL C01005 (1)
      CALL ENDIT
      END
