C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01.01.02/02                        *
C  *    TEST TITLE : Error 2 handled by system             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      CALL INITGL ('09.01.01.02/02')
      CALL INMSG  ('No test performed, because the standard does '  //
     1             'not specify the effect of signalling an error ' //
     2             'when PHIGS is closed and the default system '   //
     3             'error handler is in effect.')
      CALL ENDIT
      END
