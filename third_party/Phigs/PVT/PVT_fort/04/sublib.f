C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04/arcpts                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ARCPTS (NUMPTS, XMID,YMID,RAD, ANG1, ANGINC, XA,YA,ZA)

C  ARCPTS fills in an array with points on an arc in x and y, on
C  an oblique plane (z = (x+y)/2)

C  Input parameters:
C    NUMPTS    : number of points to fill in
C    XMID,YMID : center of circle
C    RAD       : radius of circle
C    ANG1      : first angle 
C    ANGINC    : angle increment
C  Output parameters:
C    XA,YA,ZA  : arc points returned

      INTEGER    NUMPTS, IX

      REAL       ANG, ANG1, ANGINC, XMID,YMID,RAD, XA(*),YA(*),ZA(*)

      ANG = ANG1
      DO 100 IX = 1,NUMPTS
         XA(IX) = XMID + RAD*COS(ANG)
         YA(IX) = YMID + RAD*SIN(ANG)
         ZA(IX) = 0.5*XA(IX) + 0.5*YA(IX)
         ANG = ANG + ANGINC
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04/discol                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04/xfinh                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE XFINH (PERM)

C  More special-purpose code here for testing inheritance.
C  Since structure 104 is re-invoked, it generates polyline #5,6 on
C  first invocation, and 11,12 on 2nd.  But 11,12 would simply
C  overlay 5,6, so we must also pass down a transformation which
C  maps locations 5,6 to locations 11,12, respectively.

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      INTEGER   PERM(14), ERRIND

      REAL      Z,U,YLOCEL,FXPTY, SHIFTY,SCALEY, XFORM(3,3)

      Z = 0.0
      U = 1.0
      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      SCALEY = (YLOCEL(PERM(12)) - YLOCEL(PERM(11))) /
     1         (YLOCEL(PERM(06)) - YLOCEL(PERM(05)))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,SCALEY, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04/locppl                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCPPL (YLOC, XVAL)

C  LOCPPL draws a polyline at the real y-location corresponding to
C  the integer index given in YLOC.

      INTEGER    YLOC

      REAL       XVAL(2), YVAL(2), YLOCEL

      YVAL(1) = YLOCEL(YLOC)
      YVAL(2) = YVAL(1)
      CALL PPL (2, XVAL,YVAL)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04/loctxt                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCTXT (YLOC, XVAL)

C  LOCTXT draws a text primitive at the real y-location
C  corresponding to the integer index given in YLOC.

      INTEGER   YLOC
      REAL      XVAL, YLOCEL

      CALL PTX (XVAL, YLOCEL(YLOC), 'Hi ho!')

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04/locatx                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCATX (YLOC, XVAL)

C  LOCATX draws an annotation text primitive at the real y-location
C  corresponding to the integer index given in YLOC.

      INTEGER   YLOC
      REAL      XVAL, YLOCEL

      CALL PATR (XVAL, YLOCEL(YLOC), 0.0,0.0, 'Hi ho!')

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04/locint                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCINT (YLOC, XVAL)

C  LOCINT draws a fill area or fill area set at the real y-location
C  corresponding to the integer index given in YLOC.  It may be used
C  to check interiors.

      INTEGER    YLOC, NPTS(1)

      REAL       XVAL(4), YVAL(4), YLOCEL, YMID, YHALF

      NPTS(1) = 4
      YMID  = YLOCEL(YLOC)
      YHALF = 0.02
      YVAL(1) = YMID + YHALF
      YVAL(2) = YMID - YHALF
      YVAL(3) = YMID - YHALF
      YVAL(4) = YMID + YHALF

      IF (MOD(YLOC,2) .EQ. 0) THEN
         CALL PFA (4, XVAL,YVAL)
      ELSE
         CALL PFAS (1, NPTS, XVAL,YVAL)
      ENDIF
 
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04/loctri                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCTRI (YLOC, XVAL)

C  LOCTRI draws a triangle using fill area set at the real
C  y-location corresponding to the integer index given in YLOC.
C  LOCTRI is normally used to display edges (unique to fill area
C  set, as opposed to simple fill area) rather than interiors.

      INTEGER    YLOC, NPTS(1)

      REAL       XVAL(3), YVAL(3), YLOCEL

      NPTS(1) = 3
      YVAL(2) = YLOCEL(YLOC) - .02
      YVAL(3) = YVAL(2)
      YVAL(1) = YVAL(2) + .035
 
      CALL PFAS (1, NPTS, XVAL,YVAL)
 
      END
