      SUBROUTINE DISCOL (MAXREQ, WKID, NDISCT)

C  DISCOL attempts to change the color table so as to put distinct
C  foreground colors in entries 1-MAXREQ.  These are to be
C  distinct from the background color as well as from each other.
C  DISCOL also attempts to put the color "farthest" from the
C  background color (and hence, the most conspicuous) as color #1.

C  Input parameters:
C    MAXREQ : Number of requested distinct colors
C    WKID   : Workstation identifier
C  Output parameters:
C    NDISCT : Actual number of distinct colors in color table 1-NDISCT

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER    IX, MAXREQ,WKID,NDISCT, NCC, ERRIND, SZCOLT, PERM(30)
      INTEGER    NXTCOL, ICOL, MAXSIZ, CHOSEN(50), BESTC, THISCL
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7

      REAL       POSSC(3,27), RUSE, GUSE, BUSE, RVAL, GVAL, BVAL
      REAL       RLZCOL(3, 0:27), CDIST, BESTD

C  set color model = RGB
      CALL PSCMD (WKID, PRGB)

C  set up possible values - all points at 0.0, 0.67, 1.0 -
C  bias towards lighter side of RGB cube
      IX = 0
      DO 100 RVAL = 0, 1.4, 0.67
         RUSE = MIN(RVAL, 1.0)
      DO 110 GVAL = 0, 1.4, 0.67
         GUSE = MIN(GVAL, 1.0)
      DO 120 BVAL = 0, 1.4, 0.67
         BUSE = MIN(BVAL, 1.0)
         IX = IX+1
         POSSC(1,IX) = RUSE
         POSSC(2,IX) = GUSE
         POSSC(3,IX) = BUSE
120   CONTINUE
110   CONTINUE
100   CONTINUE

C  get realized background color
      CALL PQCR (WKID, 0, 3, PREALI, ERRIND, NCC, RLZCOL(1,0))
      CALL CHKINQ ('pqcr', ERRIND)

C  szcolt = maximum size of color table (including entry #0)
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             SZCOLT, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)
C  maxsiz = maximum size to try to fill
      MAXSIZ = MIN(MAXREQ, SZCOLT-1)
C  get permutation of 27 colors
      CALL RNPERM (27,PERM)
C  how many distinct so far
      NDISCT = 0
      BESTD = -666.0
      DO 200 IX = 1,27
         NXTCOL = NDISCT+1
         THISCL = PERM(IX)
C  try next possibility from 27
         CALL PSCR  (WKID, NXTCOL, 3, POSSC(1, THISCL))

C  get color as realized
         CALL PQCR (WKID, NXTCOL, 3, PREALI,
     1                 ERRIND, NCC, RLZCOL(1,NXTCOL))
         CALL CHKINQ ('pqcr', ERRIND)

C  if realized color different from others and from 0 - got a new one,
C  else re-try same slot
         DO 300 ICOL = NDISCT,0,-1

C  inter-color distance squared
            CDIST = (RLZCOL(1,NXTCOL) - RLZCOL(1,ICOL))**2 +
     1              (RLZCOL(2,NXTCOL) - RLZCOL(2,ICOL))**2 +
     2              (RLZCOL(3,NXTCOL) - RLZCOL(3,ICOL))**2
C  minimum closeness is .3**2
            IF (CDIST .LT. 0.09) THEN
C  too close - skip it
               GOTO 200
            ENDIF
300      CONTINUE
C  OK - use it
         NDISCT = NDISCT+1
         CHOSEN(NDISCT) = THISCL
C  save color farthest from color #0
         IF (CDIST .GT. BESTD) THEN
            BESTD = CDIST
            BESTC = NDISCT
         ENDIF

         IF (NDISCT .GE. MAXSIZ) GOTO 210
200   CONTINUE

210   CONTINUE

C  switch color farthest from #0 into slot #1
      CALL PSCR (WKID, 1,     3, POSSC(1, CHOSEN(BESTC)))
      CALL PSCR (WKID, BESTC, 3, POSSC(1, CHOSEN(1)))

      END
