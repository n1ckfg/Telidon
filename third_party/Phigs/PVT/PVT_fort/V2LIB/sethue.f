      SUBROUTINE SETHUE (WKID,COLMOD,MAXFG,PALTTE,CC, NUMSET,LSCOLI)

C  SETHUE tries to set as many hues as possible in the color table
C  and reports back the order in which they were set and how many.
C
C  Input parameters
C    WKID   : workstation identifier
C    COLMOD : Color model to set up under
C    MAXFG  : Maximum number of available foreground entries in
C             color table, starting with #2
C    PALTTE : Number of colors to be displayed if possible
C    CC     : Color coordinates to be set in color table
C
C  Output parameters
C    NUMSET : Number of entries successfully set
C    LSCOLI : List of which entries in CC (palette) were set

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)
C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

      INTEGER   COLMOD, MAXFG, PALTTE, NUMSET, LSCOLI(*)
      INTEGER   RNCOL(20), IX, IY, ERRIND, CCSIZ, WKID, NUMDSP, PALIX

      REAL      CC(3,PALTTE), THISCC(3), REALCC(3), RNDRL

      LOGICAL   COLEQL, COLOK

      CALL PSCMD (WKID, COLMOD)

C  max number to be displayed
      NUMDSP = MIN(MAXFG, PALTTE)
      CALL RNSET (NUMDSP, PALTTE, RNCOL)

C  how many set so far?
      NUMSET = 0
      DO 100 IX = 1,NUMDSP
C  which color in palette to try
         PALIX = RNCOL(IX)
         DO 110 IY = 1,3
            THISCC(IY) = CC(IY, PALIX)
C  treat -1 as a "don't care" value
            IF (THISCC(IY) .EQ. -1) THISCC(IY) = RNDRL (0.,1.)
110      CONTINUE
         CALL PSCR (WKID, NUMSET+2, 3, THISCC)
         CALL PQCR (WKID, NUMSET+2, 3, PREALI, ERRIND, CCSIZ, REALCC)
         CALL CHKINQ ('pqcr', ERRIND)
         IF (CCSIZ .NE. 3) GOTO 100
C  is realized hue close enough ??
         IF (COLMOD .EQ. PCIE) THEN
            COLOK = COLEQL(2, REALCC,    THISCC,    0.01, 0.0) .AND.
     1              COLEQL(1, REALCC(3), THISCC(3), 0.1,  0.0)
         ELSE
            COLOK = COLEQL(3, REALCC, THISCC, 0.05, 0.0)
         ENDIF

         IF (COLOK) THEN
C  add to list
            NUMSET = NUMSET+1
            LSCOLI(NUMSET) = PALIX
         ELSE
C           not set
         ENDIF
100   CONTINUE

      END
