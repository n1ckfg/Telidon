      SUBROUTINE INOUTL

C  Build outlines for nominal ELF in structures 201,202,203;
C  lower left corner of character at 0,0 and height and width of
C  character = 1.  Note that height of character *body* (from
C  topline to bottomline) is usually greater than height of
C  character (from capline to baseline).

      INTEGER  SIZ
      REAL     XA(20), YA(20)

C  capital E
      CALL POPST (201)
      CALL SETRVS ('-0.125, -0.125, 1.125, 1.125, 0.125, 0.125, ' //
     1             ' 1.125,  1.125, 0.125, 0.125, 1.125, 1.125, -0.125',
     2             XA, SIZ)
      CALL SETRVS ('-0.125, 1.125, 1.125, 0.875, 0.875,  0.625, ' //
     1             ' 0.625, 0.375, 0.375, 0.125, 0.125, -0.125, -0.125',
     2             YA, SIZ)
      CALL PPL (SIZ, XA,YA)
      CALL PCLST

C  capital L
      CALL POPST (202)
      CALL SETRVS ('-0.125, -0.125, 0.125, 0.125, 1.125,  1.125, ' //
     1             '-0.125', XA, SIZ)
      CALL SETRVS ('-0.125,  1.125, 1.125, 0.125, 0.125, -0.125, ' //
     1             '-0.125', YA, SIZ)
      CALL PPL (SIZ, XA,YA)
      CALL PCLST

C  capital F
      CALL POPST (203)
      CALL SETRVS ('-0.125, -0.125, 1.125, 1.125,  0.125, 0.125, ' //
     1             ' 1.125,  1.125, 0.125, 0.125, -0.125', XA, SIZ)
      CALL SETRVS ('-0.125, 1.125, 1.125,  0.875,  0.875, 0.625, ' //
     1             ' 0.625, 0.375, 0.375, -0.125, -0.125', YA, SIZ)
      CALL PPL (SIZ, XA,YA)
      CALL PCLST

      END
