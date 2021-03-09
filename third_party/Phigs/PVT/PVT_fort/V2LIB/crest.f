      SUBROUTINE CREST

C   create a structure network

      REAL        XA(2), YA(2)
      DATA        XA/0.,0./, YA/0.5,0.5/

      CALL POPST (100)
      CALL PPL (2, XA, YA)
      CALL PEXST (101)
      CALL PCLST
      CALL POPST (101)
      CALL PSCHH (0.1)
      CALL PTX (0.55, 0.55, 'TEXT')
      CALL PCLST

      END
