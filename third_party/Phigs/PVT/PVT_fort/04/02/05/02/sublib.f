C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.02/disinb                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DISINB (SAMP, START, UNIV, SUBSET)

C  DISINB selects SAMP predefined bundles at random from the
C  interior bundle table which are distinct in all their attributes.
C  If there are not SAMP completely distinct bundles, DISINB tries
C  to maximize the number of different attributes.
C
C  Input parameters:
C    SAMP        : number of predefined bundles to be picked
C    START       : starting index
C    UNIV        : last element in universe to pick from
C  Output parameters:
C    SUBSET      : array containing the selected distinct bundles

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT, ERRIND
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      INTEGER    SAMP, START, UNIV, SUBSET(SAMP), I,J,JJ,K, OT
      INTEGER    ATRCNT, MAXATR,MAXLOC, JINTS, KINTS, JISTY, KISTY
      INTEGER    JCI,KCI, RNDINT, OPTATR
C  total number of attributes
      INTEGER    TOTATR
      PARAMETER (TOTATR=3)

      LOGICAL    ATRNEW(TOTATR)

      IF (UNIV+1-START .LT. SAMP) THEN
         CALL UNMSG ('Abort in DISPMB because size of universe ' //
     1               'is less than requested sample.')
      ENDIF

C  OPTATR is the best possible number of attributes that can be distinct
      OPTATR = TOTATR

C  this loop picks out samp elements
      DO 500 I = 1, SAMP
C  number of new attribute values so far
         MAXATR = -1
C  look at entire universe each time, starting at random location
         J = RNDINT(START, UNIV)
         DO 400 JJ = START, UNIV
            IF (J.GE.UNIV) THEN
C  cycle around to beginning
               J = START
            ELSE
               J = J+1
            ENDIF
            DO 50 OT = 1,TOTATR
               ATRNEW(OT) = .TRUE.
50          CONTINUE
C  get attributes of next candidate
            CALL PQPIR (SPECWT, J, ERRIND, JINTS, JISTY, JCI)
            CALL CHKINQ ('pqpir', ERRIND)

C  check against all those picked so far;
            DO 300 K = 1, I-1
C  if already picked, get another j
               IF (J .EQ. SUBSET(K)) GOTO 400
               CALL PQPIR (SPECWT, SUBSET(K), ERRIND,KINTS,KISTY,KCI)
               CALL CHKINQ ('pqpir', ERRIND)
C  check all attributes
               IF (JINTS .EQ. KINTS) ATRNEW(1) = .FALSE.
               IF (JISTY .EQ. KISTY) ATRNEW(2) = .FALSE.
               IF (JCI .EQ. KCI) ATRNEW(3) = .FALSE.
300         CONTINUE
C  count # of trues
            ATRCNT = 0
            DO 75 OT = 1,TOTATR
               IF (ATRNEW(OT)) ATRCNT = ATRCNT + 1
75          CONTINUE
C  take the best so far
            IF (ATRCNT .GT. MAXATR) THEN
               MAXATR = ATRCNT
               MAXLOC = J
            ENDIF
C  cannot get better than OPTATR
            IF (MAXATR .GE. OPTATR) GOTO 410
400      CONTINUE

C  put best one on the list
410      CONTINUE
         SUBSET(I) = MAXLOC
C  remember greatest number of distinct attributes
         OPTATR = MAXATR
500   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.02/drwint                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DRWINT (NUMBUN, BUNDIS, BUNDIF)

C  DRWINT draws a set of rectangles where the actual interiors
C  are drawn using the specified bundle values, and a set of
C  expected interiors are drawn using the attribute values
C  returned by <inquire predefined interior representation>.
C  It draws the expected interior incorrectly at the specified
C  position.
C
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of interior bundle indices to be displayed
C    BUNDIF : position of interior to be drawn incorrectly

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDIS, PDISI,
     1         PDCI, BUNDIF, IX, SIZ, NPTS(1)

      REAL     XA(5),YA(5), YINCR,YLOC

C  use bundled attributes, except for edge attributes
      CALL SETASF (PBUNDL)
C  to ensure edges predictable - set ASF individual:
C  set edge flag (pedfg=14) = off
      CALL PSIASF (14, PINDIV)
      CALL PSEDFG (0)

C  draw and label actual
      CALL SETRVS ('0.2, 0.2, 0.45, 0.45', XA, SIZ)
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL NUMLAB (NUMBUN, 0.15, YLOC, YINCR)
      NPTS(1) = 4
      DO 100 IX = 1,NUMBUN
         YA(1) = YLOC - 0.3*YINCR
         YA(2) = YLOC + 0.3*YINCR
         YA(3) = YA(2)
         YA(4) = YA(1)
         YA(5) = YA(1)
         CALL PSII (BUNDIS(IX))
C switch between fill area and fill area set
         IF (MOD(IX,2) .EQ. 0) THEN
            CALL PFAS (1, NPTS, XA, YA)
         ELSE
            CALL PFA (4, XA, YA)
         ENDIF
         YLOC  = YLOC-YINCR
100   CONTINUE

C  now draw expected results - with individual attributes from WDT
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL SETRVS ('0.6, 0.6, 0.85, 0.85', XA, SIZ)
      YLOC  = .9
      DO 200 IX = 1, NUMBUN
         CALL PQPIR (SPECWT, BUNDIS(IX), ERRIND, PDIS, PDISI, PDCI)
         CALL CHKINQ ('pqpir', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            IF (PDIS .EQ. PHOLLO) THEN
               PDIS = PISEMP
            ELSE
               PDIS = MOD(PDIS,4) + 1
            ENDIF
            PDISI = MOD(PDISI,4) +1
            PDCI = MOD(PDCI,5) + 1
         ENDIF
         CALL PSIS   (PDIS)
         CALL PSISI (PDISI)
         CALL PSICI (PDCI)
         YA(1) = YLOC - 0.3*YINCR
         YA(2) = YLOC + 0.3*YINCR
         YA(3) = YA(2)
         YA(4) = YA(1)
C switch between fill area and fill area set
         IF (MOD(IX, 2) .EQ. 0) THEN
            CALL PFAS (1, NPTS, XA, YA)
         ELSE
            CALL PFA (4, XA, YA)
         ENDIF
         YLOC  = YLOC-YINCR
200   CONTINUE

      END
