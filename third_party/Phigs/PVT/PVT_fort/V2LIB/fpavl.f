      LOGICAL FUNCTION FPAVL (WKID, TXI, FONT, PREC)

C  Tests whether a given font and precision will be realized exactly
C  as such on the workstation type.  If a requested font is realized
C  in a higher precision, it is not considered to be directly
C  available.

C  Input parameters:
C    WKID : Workstation identifier
C    TXI  : Identifier for a text bundle which may be altered
C    FONT : font whose availability is at issue
C    PREC : precision whose availability is at issue

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER  WKID, TXI, NFPP, FONT, PREC, QFONT, QPREC, ERRIND
      INTEGER  IX, CONID, WTYPE, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5

      REAL     RDUM1,RDUM2,RDUM3,RDUM4

      CALL PQWKC (WKID, ERRIND, CONID, WTYPE)
      CALL CHKINQ ('pqwkc', ERRIND)
C  check if font,prec claimed in available list
      CALL PQTXF (WTYPE, 0, ERRIND, NFPP, IDUM1,IDUM2,
     1            IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)
      DO 100 IX = 1,NFPP
         CALL PQTXF (WTYPE, IX, ERRIND, IDUM1, QFONT,QPREC,
     1               IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
         CALL CHKINQ ('pqtxf', ERRIND)
         IF (QFONT.EQ.FONT .AND. QPREC.GE.PREC) THEN
            GOTO 110
         ENDIF
100   CONTINUE
C  font not claimed in list - give up
      FPAVL = .FALSE.
      RETURN

C  check if realized exactly as requested
110   CONTINUE
      CALL PSTXR (WKID, TXI, FONT,PREC, 1.0,0.0,1)
      CALL PQTXR (WKID, TXI, PREALI,
     1            ERRIND, QFONT,QPREC, RDUM1,RDUM2,IDUM1)
      CALL CHKINQ ('pqtxr', ERRIND)
      FPAVL = QFONT.EQ.FONT .AND. QPREC.EQ.PREC

      END
