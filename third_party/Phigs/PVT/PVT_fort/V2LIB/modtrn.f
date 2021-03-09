      INTEGER FUNCTION MODTRN (DIM)

C  MODTRN performs a random transformation on six line segments using
C  various modelling facilities, and marks the expected endpoints
C  with circle-polymarkers.  It returns the identifier of the line
C  segment which is marked incorrectly.
C
C  Input parameter:
C     DIM: dimensionality of the transformations to be tested (2 or 3)

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

C Marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

      REAL       PI
      PARAMETER (PI = 3.14159265)

      INTEGER DIM, LISBOX(6), THIS, IX, RNDINT, NGBOX

      REAL XSIZ, YSIZ, XWINLO(6), YWINLO(6)
      REAL IDXF(4,4), XF(4,4), TMP4(4,4), BOXF(4,4), FIXF(4,4)
      REAL ROTXF(4,4), WC1X,WC1Y,WC1Z, WC2X,WC2Y,WC2Z, XF2(3,3)
      REAL XA(2),YA(2), PX(2),PY(2),PZ(2), NGXF(4,4)
      REAL XSCF, YSCF, ZSCF, XMID, YMID, ZMID, XSHF, YSHF, ZSHF

      DATA PX / 1.0, 2.0 /, PY / 1.0, 2.0 /, PZ / 1.0, 2.0 /

C  Set up structure 106 to label 6 windows
      CALL WIN6 (106, 1, XSIZ,YSIZ, XWINLO, YWINLO)
C  Open test structure
      CALL POPST (102)
C  Set polymarker type
      CALL PSMK   (POMARK)
C  Initialize identity matrix
      CALL IDMAT (4,IDXF)

      CALL RNPERM (6,LISBOX)
C  box to be drawn incorrectly
      NGBOX = RNDINT(1,6)

      CALL PSPLCI (2)
      CALL PSPMCI (3)

      DO 100, IX = 1,6
         THIS = LISBOX(IX)

         IF (DIM .EQ. 2) THEN
C  set up for 2D
            CALL RANARY (3, XF2)
            CALL EXP34 (XF2,XF)
         ELSEIF (DIM .EQ. 3) THEN
C  set up for 3D
            CALL RANARY (4, XF)
         ELSE
            CALL UNMSG ('MODTRN called with invalid dimension.')
         ENDIF

         IF ((THIS.EQ.1) .OR. (THIS.EQ.4)) THEN
C  Rotate 90 around x axis
            CALL EROX ( PI/2., ROTXF)
         ELSE IF ((THIS.EQ.2) .OR. (THIS.EQ.5)) THEN
C  Rotate 90 around y axis
            CALL EROY ( PI/2., ROTXF)
         ELSE
C  Rotate 90 around z axis
            CALL EROZ ( PI/2., ROTXF)
         ENDIF
C
C  Compose new transformation matrix
         CALL ECOM3 (ROTXF,XF,TMP4)
C
C  Calculate transformation by ROTXF x XF of (1,1,1) and (2,2,2)
         CALL ETP3 (PX(1),PY(1),PZ(1), TMP4, WC1X,WC1Y,WC1Z)
         CALL ETP3 (PX(2),PY(2),PZ(2), TMP4, WC2X,WC2Y,WC2Z)

         XSCF = 0.8 * XSIZ / ( WC2X - WC1X )
         YSCF = 0.8 * YSIZ / ( WC2Y - WC1Y )
         ZSCF = 0.8        / ( WC2Z - WC1Z )

         XMID = XSCF * ( WC1X + WC2X )/2
         YMID = YSCF * ( WC1Y + WC2Y )/2
         ZMID = ZSCF * ( WC1Z + WC2Z )/2

         XSHF = XWINLO(IX) + XSIZ/2 - XMID
         YSHF = YWINLO(IX) + YSIZ/2 - YMID
         ZSHF = 0.5                 - ZMID

         CALL EBLTM3 (0.,0.,0., XSHF,YSHF,ZSHF, 0.,0.,0.,
     1                XSCF,YSCF,ZSCF, BOXF)
C
C  Compose new transformation matrix = BOX x ROTXF x XF
         CALL ECOM3 (BOXF,ROTXF,FIXF)
         CALL ECOM3 (FIXF,XF,TMP4)
C
C  Calculate expected positions of (1,1,1) and (2,2,2)
         CALL ETP3 (PX(1),PY(1),PZ(1), TMP4, WC1X,WC1Y,WC1Z)
         CALL ETP3 (PX(2),PY(2),PZ(2), TMP4, WC2X,WC2Y,WC2Z)

         IF ( IX .EQ. NGBOX) THEN
C  distort result - rotate by 10 degrees
            CALL EBLTM3 (XWINLO(IX) + XSIZ/2, YWINLO(IX) + YSIZ/2 , 0.5,
     1                   0.,0.,0.,  0.,0.,(2*PI*10)/360,
     2                   1.0,1.0,1.0, NGXF)
            CALL ECOM3 (NGXF,FIXF,TMP4)
            CALL CPYIAR (16,TMP4,FIXF)
         ENDIF

         IF ( THIS .LT. 3 ) THEN
            CALL PSLMT3 (FIXF,PCREPL)
            IF (DIM .EQ. 2 ) THEN
               CALL PSLMT (XF2,PCPRE)
            ELSE
               CALL PSLMT3 (XF,PCPRE)
            ENDIF
         ELSEIF ( THIS .LT. 5 ) THEN
            IF (DIM .EQ. 2 ) THEN
               CALL PSLMT (XF2,PCREPL)
            ELSE
               CALL PSLMT3 (XF,PCREPL)
            ENDIF
            CALL PSLMT3 (FIXF,PCPOST)
         ELSE
            IF (DIM .EQ. 2 ) THEN
               CALL PSLMT (XF2,PCREPL)
            ELSE
               CALL PSLMT3 (XF,PCREPL)
            ENDIF
            CALL PSGMT3 (FIXF)
         ENDIF

C  Draw line segment as changed by transformation matrix
         CALL PPL3 (2,PX,PY,PZ)

C  Now expected endpoints with no transformations
         CALL PSLMT3 (IDXF,PCREPL)
         CALL PSGMT3 (IDXF)

         XA(1) = WC1X
         YA(1) = WC1Y
         XA(2) = WC2X
         YA(2) = WC2Y
         CALL PPM (2, XA,YA)
100   CONTINUE
      CALL PCLST
      MODTRN = NGBOX

      END
