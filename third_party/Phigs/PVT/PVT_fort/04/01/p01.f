C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01/01                              *
C  *    TEST TITLE : 2D polymarker and display space       *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

      INTEGER    NLEFT,   NRIGHT,   NBOTT,   NTOP
      PARAMETER (NLEFT=1, NRIGHT=2, NBOTT=3, NTOP=4)

      INTEGER    PICSTR, TXCI, IX, JX, NMARK
      INTEGER    RAN4(4), RAN12(12), ANSSIZ,ANSLIS(10)
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4

      REAL       XNOM(NLEFT:NRIGHT), YNOM(NBOTT:NTOP), XA(20), YA(20)
      REAL       RSIDE,LSIDE,BSIDE,TSIDE, XLOC,YLOC, XOP,YOP, XCM,YCM
      REAL       DCMAXX,DCMAXY, NOMMS, RNDRL, MRGIN, SCF
C  distance in WC from edge of display space
      PARAMETER (MRGIN = 0.004)
      REAL       RDUM1,RDUM2

      LOGICAL    APPEQ, IAREQ

      CALL INITGL ('04.01/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  For all test cases: use individual attributes
      CALL SETASF (PINDIV)
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
C  set polymarker size to 3.0mm.
      SCF = 0.003 / (NOMMS * MTRPDC)
      CALL PSMKSC (SCF)
C  thin lines
      CALL PSLWSC (0.0)
C  set view for entire display space
      CALL PSVWI (3)
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (102)

      CALL SETMSG ('1', 'The location of 2D polymarkers should be ' //
     1             'determined by their associated modelling '      //
     2             'coordinates as modified by the transformation ' //
     3             'pipeline.')

C  draw outline of display space using polyline
      CALL DRWREC (0.0,1.0, 0.0,SYXRAT)
      CALL PEXST (103)
      CALL PCLST
      CALL POPST (103)

C  get display space DC-size to derive WC/DC ratio for view #3
      CALL PQDSP  (SPECWT, ERRIND, IDUM1, DCMAXX,DCMAXY, IDUM2,IDUM3)
      CALL CHKINQ ('pqdsp', ERRIND)

C  WC coordinate of right side of empty display space
      IF (SCRMOD.EQ.2) THEN
C  left edge of dialogue area
         RSIDE = 1-DSIZE
      ELSE
C  dialogue area not at right
         RSIDE = 1
      ENDIF

C  WC coordinate of bottom side of empty display space
      IF (SCRMOD.EQ.1) THEN
C  top edge of dialogue area
         BSIDE = SYXRAT*DSIZE
      ELSE
C  dialogue area not at bottom
         BSIDE = 0
      ENDIF

C  WC coordinate of left,top side of empty display space
      LSIDE = 0
      TSIDE = SYXRAT

C  for all 5 polymarker types
      DO 200 IX = PPOINT,PXMARK
C  random from 0.1 to 0.9 between lside and rside
         XLOC = RNDRL(0.1,0.9)
         XA(1) = (1-XLOC)*LSIDE + XLOC*RSIDE
C  random from 0.1 to 0.9 between bside and tside
         YLOC = RNDRL(0.1,0.9)
         YA(1) = (1-YLOC)*TSIDE + YLOC*BSIDE
C  draw marker of type ix at xloc,yloc
         CALL PSMK (IX)
         CALL PPM  (1, XA,YA)
         CALL DRLVAL ('LOCATION OF 2D POLYMARKER: Enter the '    //
     1                'distance, in centimeters, from the left ' //
     1                'edge of the display space to the center ' //
     1                'of the polymarker.', XOP)
         CALL DRLVAL ('LOCATION OF 2D POLYMARKER: Enter the '    //
     1                'distance, in centimeters, from the top '  //
     1                'edge of the display space to the center ' //
     1                'of the polymarker.', YOP)
         XCM  = 100 * MTRPDC * (XA(1)-LSIDE) * DCMAXX
         YCM  = 100 * MTRPDC * (TSIDE-YA(1)) * DCMAXX
         CALL PEMST (103)

C  must be within 0.5cm to pass ...
         IF (APPEQ (XOP,XCM, 0.5, 0.0) .AND.
     1       APPEQ (YOP,YCM, 0.5, 0.0) ) THEN
C           OK so far
         ELSE
            CALL FAIL
            GOTO 299
         ENDIF

C  next ix
200   CONTINUE
      CALL PASS

C  end_loc:
299   CONTINUE

      CALL PCLST
      CALL POPST (102)
      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 2', 'All polymarkers drawn within the display ' //
     1             'space should be visible, and all others should '  //
     2             'not be visible.')

C  set marker type to asterisk
      CALL PSMK (PAST)
C  try for different color
      CALL PSPMCI (2)
C  ran4 = ensure each side has a different number of markers, between 3 and 8
      CALL RNBSET (4, 3,8, RAN4)

C  nominal location of edges
      XNOM(NLEFT)  = MRGIN
      XNOM(NRIGHT) = 1-MRGIN
      YNOM(NBOTT)  = MRGIN
      YNOM(NTOP)   = SYXRAT-MRGIN

C  for ix = left,right,bottom,top
      DO 100 IX = NLEFT,NTOP
C  randomize 12 locations along each edge
         CALL RNPERM (12, RAN12)
C  nmark = number of markers to be drawn
         NMARK = RAN4(IX)
C  draw NMARK markers just inside edge #ix at locations ran12(1 : nmark),
C  and a few more outside
         DO 150 JX = 1,12
            IF (IX.EQ.NLEFT .OR. IX.EQ.NRIGHT) THEN
               XA(JX) = XNOM(IX)
               YA(JX) = SYXRAT * (RAN12(JX) - 0.5) / 12.0
C  move to outside, if more than NMARK
               IF (JX.GT.NMARK) XA(JX) = XA(JX) + (MRGIN * (IX*4-6))
            ELSE
               YA(JX) = YNOM(IX)
               XA(JX) = (RAN12(JX) - 0.5) / 12.0
C  move to outside, if more than NMARK
               IF (JX.GT.NMARK) YA(JX) = YA(JX) + (MRGIN * (IX*4-14))
            ENDIF

150      CONTINUE
         CALL PPM (12, XA,YA)
100   CONTINUE

110   CONTINUE

      CALL DILIST ('SIZE OF DISPLAY SPACE: Enter four numbers '    //
     1             'indicating how many markers are visible '      //
     1             'along the left, right, bottom, and top edges ' //
     1             'respectively of the entire display space.',
     1             ANSSIZ,ANSLIS)
      IF (ANSSIZ.EQ.1 .AND. ANSLIS(1).EQ.0) THEN
         CALL OPFAIL
      ELSEIF (ANSSIZ.EQ.4) THEN
         CALL IFPF (IAREQ(4, ANSLIS, RAN4))
      ELSE
         CALL OPMSGW ('List must contain exactly four numbers.')
         GOTO 110
      ENDIF
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
