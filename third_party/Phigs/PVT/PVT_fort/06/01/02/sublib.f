C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/tranhs                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TRANHS (HS, XFORM, A,B,C,D)

C  TRANHS accepts a 3D half-space, described as a point (on the
C  boundary plane) and normal vector, applies a transform, and
C  returns the coefficients of the new boundary plane, such that
C  x,y,z is in the new half-space iff A*x + B*y + C*z + D .GE. 0

C  Input parameters:
C    HS(1,2,3)  : x,y,z coordinates of point of half-space
C    HS(4,5,6)  : x,y,z coordinates of normal vector of half-space
C    XFORM      : transformation matrix
C  Output parameters:
C    A,B,C,D    : coefficients of new boundary plane.

      REAL    HS(6), XFORM(4,4), TMPX,TMPY,TMPZ, A,B,C,D
      REAL    VECAX,VECAY,VECAZ, VECBX,VECBY,VECBZ
      REAL    OLDX(4),OLDY(4),OLDZ(4), NEWX(4),NEWY(4),NEWZ(4)

C  VECA is a unit vector orthogonal to the normal vector
      CALL PRPV1 (HS(4),HS(5),HS(6), TMPX, TMPY, TMPZ)
      CALL VEC1  (TMPX, TMPY, TMPZ,  VECAX,VECAY,VECAZ)
C  VECB is a unit vector orthogonal to the normal vector and VECA
      CALL CROSSP (VECAX,VECAY,VECAZ, HS(4),HS(5),HS(6),
     1             TMPX, TMPY, TMPZ)
      CALL VEC1 (TMPX,TMPY,TMPZ, VECBX,VECBY,VECBZ)

C  OLD-1, OLD-2, and OLD-3 are all in the (old) boundary plane, 
C  forming an L-shape.
      OLDX(1) = HS(1) + VECAX
      OLDY(1) = HS(2) + VECAY
      OLDZ(1) = HS(3) + VECAZ

      OLDX(2) = HS(1) + VECBX
      OLDY(2) = HS(2) + VECBY
      OLDZ(2) = HS(3) + VECBZ

      OLDX(3) = HS(1) 
      OLDY(3) = HS(2) 
      OLDZ(3) = HS(3) 

C  OLD-4 is a point inside the (old) half-space
      OLDX(4) = HS(1) + HS(4)
      OLDY(4) = HS(2) + HS(5)
      OLDZ(4) = HS(3) + HS(6)

C  transform 4 old points to 4 new points
      CALL ARRTP3 (4, OLDX,OLDY,OLDZ, XFORM, NEWX,NEWY,NEWZ)

C  first 3 new points define new boundary plane
      CALL PT3PL (NEWX,NEWY,NEWZ, A,B,C,D)

C  check that parity is OK - if not, negate co-efficients
      IF (A*NEWX(4) + B*NEWY(4) + C*NEWZ(4) + D .LT. 0) THEN
         A = -A
         B = -B
         C = -C
         D = -D
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/comtok                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE COMTOK (EXPCOM, EXPATH)

C  COMTOK accepts an expected composite transformation and found
C  path.  It performs an incremental spatial search of structure
C  #101, using the transformed value of (3,4,5) as the SRP, and
C  issues pass or fail depending on whether the actual found path
C  matches that expected.

C  Input parameters:
C    EXPCOM : expected composite transformation
C    EXPATH : expected found path

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 100)

      INTEGER    IDUM(2), FPATH(2,IPTHSZ), ERRIND, FPTHSZ
      INTEGER    SPATH(2,1), IEXPTH(2,IPTHSZ), IEXLEN

      REAL       EXPCOM(4,4), SRPX,SRPY,SRPZ

      CHARACTER  EXPATH*(*)

      LOGICAL    IAREQL

      DATA  SPATH / 101,0 /

C  get expected point in WC
      CALL ETP3 (3.0,4.0,5.0, EXPCOM, SRPX,SRPY,SRPZ)

C  decode expected found path
      CALL SETVS (EXPATH, IEXPTH, IEXLEN)

      CALL PISS3 (SRPX,SRPY,SRPZ, 0.03, 1, SPATH, PNCLIP, 1,
     1            0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)

      CALL IFPF (ERRIND .EQ. 0 .AND.
     1           IAREQL (2*FPTHSZ, FPATH, IEXLEN, IEXPTH))

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/chkmcv                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CHKMCV (STPATH, EXPTHS)

C  CHKMCV checks that the correct sequence of found paths is returned
C  by ISS as a result of the starting path.  It issues pass or fail
C  depending on whether the actual found paths match those expected.
C  It always uses a search reference point of 0,0,0 and distance of 2.

C  Input parameters:
C    STPATH : starting path for ISS
C    EXPTHS : expected found paths

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      CHARACTER  STPATH*(*), EXPTHS*(*)

      CALL ISPTHS (0.,0.,0., 2., 1, PCLIP, STPATH, EXPTHS)

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION 06.01.02/modtrn                   *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/ranary                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE RANARY (SIZE,ARRAY)

C  RANARY initializes a 2D array of size x size to random values
C  between 0.5 and 1.5

      INTEGER SIZE, I,J
      REAL    ARRAY(SIZE,SIZE), RNDRL

      DO 100 I = 1, SIZE
      DO 200 J = 1, SIZE
         ARRAY(I,J) = RNDRL(0.5,1.5)
200   CONTINUE
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/clpgon                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CLPGON (VISCT, NUMPL, RAD)

C  CLPGON draws a set of markers some of which are just inside the
C  clipping region shaped like a regular polygon, and the rest just
C  outside it.

C  Input parameters:
C    VISCT : number of markers to be drawn inside clipping region
C    NUMPL : total number of markers to be drawn = #sides of polygon
C    RAD   : radius of polygon (distance from center to face, not vertex)

      INTEGER    VISCT, NUMPL, VISLIS(50), IX, IARFND
C maximum number of planes to be tested
      INTEGER    TSTMAX
      PARAMETER (TSTMAX = 500)
                 
      REAL       XLOC(TSTMAX), YLOC(TSTMAX), ZLOC(TSTMAX)
      REAL       RAD, THSRAD, RNDRL, ANG, PI
      PARAMETER (PI = 3.14159265)

C  Choose visct markers to be inside
      CALL RNSET (VISCT, NUMPL, VISLIS)

C  calculate coordinates of polymarker:
      DO 100 IX = 1,NUMPL
         IF ( IARFND (IX, VISCT, VISLIS) .GT. 0) THEN
C  Inside:
            THSRAD = 0.99 * RAD
         ELSE
C  Outside:
            THSRAD = 1.01 * RAD
         ENDIF
         ANG = IX*2*PI / NUMPL
         XLOC (IX) = 0.5 + THSRAD * COS(ANG)
         YLOC (IX) = 0.5 + THSRAD * SIN(ANG)
         ZLOC (IX) = RNDRL(0.,1.0)
  100 CONTINUE
      CALL PPM3 (NUMPL, XLOC,YLOC,ZLOC)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/clpmk5                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CLPMK5 (DIM, MCVND, XF, INXF,OUTXF)

C  CLPMK5 generates a 5x5 grid of polymarkers, some of which should be
C  clipped (X style) and some of which should be visible (+ style) and then
C  passes or fails based on operator response.

C  Input parameters:
C    DIM   : dimensionality of test (2 or 3)
C    XF    : transformation to be applied to clipping plane
C    INXF  : transformation to apply to marker to put it inside MCV
C    OUTXF : transformation to apply to marker to put it outside MCV
C    MCVND : half-space for MCV, in 3D or 2D format

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

C modelling clipping operator
C                replace     intersect
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      INTEGER    IX, VISCT, RNDINT

      REAL       XF(4,4), INXF(4,4), OUTXF(4,4), PTXVEC(6)
      REAL       A,B,C,D, XX,YY, XA(3), YA(3), ZA(3), PI, MCVND(6,1)
      PARAMETER (PI = 3.14159265)

      LOGICAL    DYN, INMCV, NCLIPD

      CHARACTER  DIM*1

C  a,b,c,d = coefficients of transformed boundary plane
      DO 100 IX=1,6
         PTXVEC(IX) = MCVND(IX,1)
100   CONTINUE

      IF (DIM .EQ. '2') THEN
C  two-dimensionalize
         PTXVEC(6) = 0.0
         PTXVEC(5) = MCVND(4,1)
         PTXVEC(4) = MCVND(3,1)
         PTXVEC(3) = 0.0
      ELSEIF (DIM .EQ. '3') THEN
C        OK as is
      ELSE
         CALL UNMSG ('CLPMK5 called with DIM = ' // DIM // '.')
      ENDIF
      CALL TRANHS (PTXVEC, XF, A,B,C,D)

C  visct = number of polymarkers which should be visible
      VISCT = 0

      DO 10 XX = 0.1, 1.0, 0.2
      DO 20 YY = 0.1, 1.0, 0.2
         INMCV  = RNDINT(1,3) .EQ. 1
         NCLIPD = RNDINT(1,2) .EQ. 1
         XA(1) = XX
         YA(1) = YY
         ZA(1) = (-A*XX - B*YY - D) / C

         IF (INMCV) THEN
            CALL PSLMT3 (INXF,PCREPL)
         ELSE
            CALL PSLMT3 (OUTXF,PCREPL)
         ENDIF

         IF (NCLIPD) THEN
            CALL PSMCLI (PNCLIP)
         ELSE
            CALL PSMCLI (PCLIP)
         ENDIF

         IF (INMCV .OR. NCLIPD) THEN
C  should be visible
            CALL PSPMCI (2)
            CALL PSMK (PPLUS)
            VISCT = VISCT + 1
         ELSE
C  should be invisible
            CALL PSPMCI (3)
            CALL PSMK (PXMARK)
         ENDIF

         CALL PPM3 (1, XA,YA,ZA)
20    CONTINUE
10    CONTINUE

      IF (DYN (DIM // 'D GEOMETRY OF CLIPPING VOLUME: Is plus (+) ' //
     1         'the type of all visible markers?')) THEN
C        OK so far
      ELSE
         CALL FAIL
         GOTO 380
      ENDIF

      CALL DCHPFV (DIM // 'D GEOMETRY OF CLIPPING VOLUME: ' //
     1             'How many markers are visible?', 100, VISCT)

380   CONTINUE
      CALL PEMST (102)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/clpair                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CLPAIR (XWINLO,YWINLO,XSIZE,YSIZE, IWX, DELTA, ZVAL)

C  CLPAIR draws a double polymarker in the middle of the requested
C  window, one just in front and one just behind a given z-value, so
C  that exactly one of the pair will be clipped.

C  Input parameters:
C    XWINLO,YWINLO : List of locations of lower-left window corners
C    XSIZE,YSIZE   : Window size
C    IWX           : Index into window list; which window to draw in
C    DELTA         : offset in X and Z dimension from nominal window center
C    ZVAL          : nominal Z location = z-value of expected clipping plane

      INTEGER  IWX
      REAL     XWINLO(*),YWINLO(*),XSIZE,YSIZE, DELTA, ZVAL
      REAL     XA(2), YA(2), ZA(2)

      XA(1) =  XWINLO(IWX) + XSIZE/2 - DELTA
      YA(1) =  YWINLO(IWX) + YSIZE/2
      ZA(1) =  ZVAL - DELTA

      XA(2) =  XWINLO(IWX) + XSIZE/2 + DELTA
      YA(2) =  YWINLO(IWX) + YSIZE/2
      ZA(2) =  ZVAL + DELTA

      CALL PPM3 (2, XA,YA,ZA)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/locnpm                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCNPM (NPPM, YPOS, XLOC)

C  LOCNPM draws a polymarker with NPPM markers at the real y-location
C  corresponding to the integer index given in YPOS.

      INTEGER  IX,YPOS, NPPM

      REAL     YLOCEL, XLOC(*), YA(5), YVAL

      YVAL = YLOCEL(YPOS)
      DO 10 IX = 1,NPPM
         YA(IX) = YVAL
10    CONTINUE
      CALL PPM (NPPM, XLOC, YA)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/faclip                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE FACLIP (ACL,BCL,CCL,DCL, XCO,YCO,ZCO, MCV3)

C  FACLIP accepts the co-efficients for two given clipping planes,
C  generates a plane for a fill area primitive and computes
C  another clipping plane, perpendicular to the primitive's
C  plane, but intersecting it the same way as does the given
C  clipping plane.

C  Input parameters:
C    ACL,BCL,CCL,DCL : co-efficients of given planes (CCL usually zero)
C  Output parameters:
C    XCO,YCO         : x,y co-efficients of primitive plane
C    MCV3            : computed planes, perpendicular to primitive plane

      INTEGER JX

      REAL    AF,BF,CF,DF, ACL(3),BCL(3),CCL(3),DCL(3), XCO,YCO,ZCO
      REAL    MCV3(6,2), RNDRL

C  randomize plane of fill area (in MC): xco*x + yco*y - z + zco = 0
      XCO = RNDRL(0.0, 0.4)
      YCO = RNDRL(0.0, 0.4)
      ZCO = 0.1

C  calculate 3D MCVs perpendicular to MC fill area plane, with negative
C  x-component.
      DO 330 JX = 1,2
         CALL PL2PL (XCO,YCO,-1.0,ZCO,
     1               ACL(JX),BCL(JX),CCL(JX),DCL(JX),
     2               AF,BF,CF,DF)
         IF (AF .EQ. 0) THEN
            CALL UNMSG ('Generated invalid clipping plane.')
         ELSEIF (AF .GT. 0) THEN
            AF = -AF
            BF = -BF
            CF = -CF
            DF = -DF
         ENDIF
         MCV3(1,JX) = -DF/AF
         MCV3(2,JX) = 0.0
         MCV3(3,JX) = 0.0
         MCV3(4,JX) = AF
         MCV3(5,JX) = BF
         MCV3(6,JX) = CF
330   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.01.02/exedv                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EXEDV (VXSTR, XEXP,YEXP)

C  EXEDV draws a polyline using the indicated elements of the
C  arrays of expected vertices.

C  Input parameters:
C    VXSTR     : Positions in array to use as vertices
C    XEXP,YEXP : Array of expected vertices from which values are taken

      INTEGER   VXSIZ,VX(20),IX

      REAL      XEXP(*),YEXP(*), XA(20),YA(20)

      CHARACTER VXSTR*(*)

      CALL SETVS (VXSTR, VX, VXSIZ)
      DO 100 IX = 1,VXSIZ
         XA(IX) = XEXP(VX(IX))
         YA(IX) = YEXP(VX(IX))
100   CONTINUE

      CALL PPL (VXSIZ, XA,YA)

      END
