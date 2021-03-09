C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01.01.01/03                        *
C  *    TEST TITLE : Error 3 handled by user               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      CALL INITGL ('09.01.01.01/03')
      CALL E01003 (1)
      CALL C01003 (1)
      CALL ENDIT
      END
