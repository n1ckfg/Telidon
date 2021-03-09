C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01.01.01/07                        *
C  *    TEST TITLE : Error 7 handled by user               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      CALL INITGL ('09.01.01.01/07')
      CALL E01007 (1)
      CALL C01007 (1)
      CALL ENDIT
      END
