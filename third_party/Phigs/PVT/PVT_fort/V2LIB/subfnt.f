      SUBROUTINE SUBFNT (SPECWT, BESTFN, NCBHTW,NCBWDW,NCBHTI,NCBWDI)

C  SUBFNT looks for a stroke text font other than 1, preferably not
C  #2 and not monospaced, and returns nominal size for "W" and "i".

C  Input parameters:
C    SPECWT : workstation type
C  Output parameters:
C    BESTFN        : selected font
C    NCBHTW,NCBWDW : nominal height, width of "W" in selected font
C    NCBHTI,NCBWDI : nominal height, width of "i" in selected font

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    NFPP, IX, THISFN,THISPR, BESTFN, BESTSC, FNSCOR
      INTEGER    ERRIND, PERM(400), SPECWT
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5

      REAL       TCBHTI,TCBWDI, TCBHTW,TCBWDW
      REAL       NCBHTI,NCBWDI, NCBHTW,NCBWDW
      REAL       TXRX(2),TXRY(2)
      REAL       RDUM1,RDUM2,RDUM3,RDUM4

      LOGICAL    APPEQ

      CALL PQTXF (SPECWT, 0, ERRIND, NFPP, IDUM1,IDUM2,
     1            IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)
      BESTSC = -1
      BESTFN =  1
C  go thru the fonts, in random order, looking for a good one
      CALL RNPERM (NFPP, PERM)
      DO 300 IX = 1,NFPP
         CALL PQTXF (SPECWT, PERM(IX), ERRIND, IDUM1, THISFN,THISPR,
     1               IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
         CALL CHKINQ ('pqtxf', ERRIND)
C  must be non-1 stroke font
         IF (THISFN.EQ.1 .OR. THISPR.NE.PSTRKP) GOTO 300

C  determine
C    tcbhtw = nominal character body height for W
C    tcbwdw = nominal character body width for W
         CALL PQTXX  (SPECWT, THISFN, 1.,0.,1., PRIGHT, PALEFT,PABOTT,
     1                'WWW', ERRIND, TXRX,TXRY, RDUM1,RDUM2)
         CALL CHKINQ ('pqtxx', ERRIND)
         TCBHTW = ABS(TXRY(2) - TXRY(1))
         TCBWDW = ABS(TXRX(2) - TXRX(1)) / 3
C  determine
C    tcbhti = nominal character body height for i
C    tcbwdi = nominal character body width for i
         CALL PQTXX  (SPECWT, THISFN, 1.,0.,1., PRIGHT, PALEFT,PABOTT,
     1                'iii', ERRIND, TXRX,TXRY, RDUM1,RDUM2)
         CALL CHKINQ ('pqtxx', ERRIND)
         TCBHTI = ABS(TXRY(2) - TXRY(1))
         TCBWDI = ABS(TXRX(2) - TXRX(1)) / 3

C  "goodness" score for this font
         IF (THISFN .EQ. 2) THEN
            FNSCOR = 0
         ELSE
            FNSCOR = 1
         ENDIF
C  add 2 to score if not monospaced
         IF (.NOT. APPEQ(TCBWDW, TCBWDI, 0.0, 0.02)) FNSCOR = FNSCOR+2

         IF (FNSCOR .GT. BESTSC) THEN
C  best font so far
            BESTSC = FNSCOR
            BESTFN = THISFN
            NCBHTW = TCBHTW
            NCBWDW = TCBWDW
            NCBHTI = TCBHTI
            NCBWDI = TCBWDI
C  got a non-2, non-monospaced font
            IF (FNSCOR .GE. 3) GOTO 310
         ENDIF
300   CONTINUE

C  got_font:
310   CONTINUE

      END
