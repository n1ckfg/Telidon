C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.04.01/locat2                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCAT2 (YLOC, XVAL)

C  LOCAT2 draws an annotation text string at the real y-location
C  corresponding to the integer index given in YLOC, and puts a
C  polymarker at the text position.

      INTEGER    YLOC

      REAL       XVAL, YLOCEL, XA(1),YA(1)

      XA(1) = XVAL
      YA(1) = YLOCEL(YLOC)
      CALL PPM (1, XA,YA)
      CALL LOCATX (YLOC, XVAL)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.04.01/locans                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCANS (YLOC, XVAL)

C  LOCANS draws an annotation text primitive with a distinct
C  annotation point and reference point, at the real y-location
C  corresponding to the integer index given in YLOC.

      INTEGER   YLOC
      REAL      XVAL, YLOCEL, XOFF,YOFF, NPCX,NPCY,NPCPWC

      DATA XOFF /-0.15/, YOFF /0.05/

      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)
      CALL PATR (XVAL-XOFF, YLOCEL(YLOC)-YOFF, 
     1           XOFF*NPCPWC,YOFF*NPCPWC, 'Hiho')

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.04.01/tsanup                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSANUP (TXFONT, TXPATH, TXSTR, NUMOUT, NGSTR)

C  TSANUP draws an annotation text string with various values for
C  character up and for annotation text alignment.  The annotation
C  text strings are displayed along radii of a circle and are
C  enclosed by a text extent rectangle (except for one which is
C  deliberately drawn incorrectly).  TSANUP assumes that default
C  character height has been set to 1.0.

C  Input parameters:
C    TXFONT : Text font to be used
C    TXPATH : Annotation text path to be used
C    TXSTR  : Annotation text string to be used
C  Output parameters:
C    NUMOUT : Number of annotation text primitives drawn
C    NGSTR  : Identifier of incorrect annotation text primitive

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

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

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

      INTEGER    IX, RNDINT, NUMSTR, NUMOUT, NGSTR
C  numstr = number of strings to display
      PARAMETER (NUMSTR = 7)
      INTEGER    TXFONT, TXPATH, ERRIND, ALGNH(NUMSTR), ALGNV(NUMSTR)

      REAL       NTXWD,NTXHT, ORAD,IRAD, PI, XF(3,3), XA(9),YA(9)
      REAL       VTAB(PATOP:PABOTT), HTAB(PALEFT:PARITE), Z
      REAL       TXANG, SINT,COST, TXPOSX,TXPOSY, SCF, RECLNG,RECSHT
      REAL       XRT,YRT, XUP,YUP, XVEC,YVEC, INTSP, XB(2),YB(2), LABRAD
      REAL       NPCX,NPCY,NPCPWC

      PARAMETER (PI = 3.14159265)

      LOGICAL    VERT

      CHARACTER  TXSTR*(*), DIG2*2

      NUMOUT = NUMSTR
      VERT = TXPATH.EQ.PUP .OR. TXPATH.EQ.PDOWN

      CALL PSTXFN (TXFONT)
C  use <inquire text extent> on txstr to determine:
C    ntxwd  = nominal width of text extent rectangle
C    ntxht  = nominal height of text extent rectangle
C    vtab,htab = normalized heights and widths
      CALL TXEXAL (TXFONT, TXPATH, TXSTR, NTXWD, NTXHT, HTAB, VTAB)
      IF (VERT) THEN
         RECLNG = NTXHT
         RECSHT = NTXWD
      ELSE
         RECLNG = NTXWD
         RECSHT = NTXHT
      ENDIF

C  ngstr = incorrect string identifier
      NGSTR = RNDINT(1,7)
C  irad = inner radius of circle for display of annotation text strings
      IRAD = 1.1 * (NUMSTR*RECSHT) / (2*PI)
C  orad = outer radius of circle for display of annotation text strings
      ORAD = IRAD + RECLNG

C  set up transform to fit annotation text circle on screen, from MC
C  centered at origin, with radius orad to WC radius=0.4, centered
C  at 0.5,0.5
      Z = 0.0
C  label radius factor
      LABRAD = 1.2
      SCF = 0.45 / (LABRAD*ORAD)
      CALL PBLTM  (Z,Z, 0.5,0.5, Z, SCF,SCF, ERRIND, XF)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT  (XF, PCPRE)

C  set height for annotation text, apply scale factor directly,
C  since annotation text unaffected by transformation.
      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)
      CALL PSATCH (NPCPWC * SCF)

C  annotation text alignments to be used:
C     algnh    algnv
C     ------   ------
C  1: center   base
C  2: left     cap
C  3: right    top
C  4: left     bottom
C  5: center   half
C  6: right    half
C  7: left     cap
      CALL SETVAL ('2,1,3,1,2,3,1', ALGNH)
      CALL SETVAL ('4,2,1,5,3,3,2', ALGNV)

C first draw labels and expected rectangles
      CALL PSPLCI (2)
      CALL PSTXCI (1)
      CALL PSTXAL (PACENT, PAHALF)
      CALL PSTXP (PRIGHT)

      DO 100 IX = 1,NUMSTR
C  txang = angle for annotation text string
         TXANG = IX*2*PI / NUMSTR
         COST = COS(TXANG)
         SINT = SIN(TXANG)
C  draw rectangle for expected position of annotation text string,
C     based on txang, ntxwd,ntxht
C  first draw bottom line along radius
         XA(1) = IRAD * COST
         XA(5) = XA(1)
         XA(4) = (IRAD + RECLNG) * COST

         YA(1) = IRAD * SINT
         YA(5) = YA(1)
         YA(4) = (IRAD + RECLNG) * SINT
C  unit up vector for rectangle  - this keeps left-bottom corner
C  on the radius for either horizontal or vertical path
         IF (VERT) THEN
            XVEC =  SINT
            YVEC = -COST
            INTSP = 0.5
         ELSE
            XVEC = -SINT
            YVEC =  COST
            INTSP = VTAB(PABASE) / VTAB(PATOP)
         ENDIF

         XA(2) = XA(1) + RECSHT*XVEC
         XA(3) = XA(4) + RECSHT*XVEC
         YA(2) = YA(1) + RECSHT*YVEC
         YA(3) = YA(4) + RECSHT*YVEC

         CALL PSLN (PLDOT)
         CALL PPL (5, XA,YA)

C  do baseline or centerline
         XB(1) = XA(1) + INTSP*RECSHT*XVEC
         XB(2) = XA(4) + INTSP*RECSHT*XVEC
         YB(1) = YA(1) + INTSP*RECSHT*YVEC
         YB(2) = YA(4) + INTSP*RECSHT*YVEC

         CALL PSLN (PLDASH)
         CALL PPL (2, XB, YB)

C  label each spoke
         WRITE (DIG2, '(A,I1)') '#', IX
         CALL PTX ( LABRAD*XA(4), LABRAD*YA(4), DIG2)
100   CONTINUE

      CALL PSATP (TXPATH)
      DO 200 IX = 1,NUMSTR
C  txang = angle for annotation text string
         TXANG = IX*2*PI / NUMSTR
         COST = COS(TXANG)
         SINT = SIN(TXANG)
C  txpos = requested annotation text position, based on txang,irad,
C    and annotation text alignment to be requested.
C  first get unit up,right direction
         IF (VERT) THEN
            XUP =  COST
            YUP =  SINT
            XRT =  SINT
            YRT = -COST
         ELSE
            XUP = -SINT
            YUP =  COST
            XRT =  COST
            YRT =  SINT
         ENDIF

         TXPOSX = IRAD * COST + HTAB(ALGNH(IX)) * XRT
     1                        + VTAB(ALGNV(IX)) * XUP
         TXPOSY = IRAD * SINT + HTAB(ALGNH(IX)) * YRT
     1                        + VTAB(ALGNV(IX)) * YUP
         CALL PSATAL (ALGNH(IX), ALGNV(IX))

         IF (IX .EQ. NGSTR) THEN
            TXANG = TXANG + (RNDINT(0,1)-0.5) * 0.5*PI/NUMSTR
            COST = COS(TXANG)
            SINT = SIN(TXANG)
            IF (VERT) THEN
               XUP =  COST
               YUP =  SINT
            ELSE
               XUP = -SINT
               YUP =  COST
            ENDIF
         ENDIF
         CALL PSATCU (XUP, YUP)
         CALL PATR (TXPOSX, TXPOSY, Z,Z, TXSTR)
C  next ix
200   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.04.01/dsanst                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DSANST (LSIZ, LANST)

C  DSANST accepts a list of annotation styles and displays at most 8
C  of them.

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

      INTEGER    LSIZ, LANST(LSIZ), NUMDIS, IX, PERM(10), LDIS(10)

      REAL       XA(10),YA(10),XO(10),YO(10)
      REAL       NPCX,NPCY,NPCPWC, YINCR,YLOC, ANOFFX,ANOFFY

      CHARACTER  ANSTID*11

      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)

      NUMDIS = MIN(8, LSIZ)
      CALL RNSET (NUMDIS, LSIZ, PERM)

C  build list of annotation styles to be displayed
      DO 100 IX = 1,NUMDIS
         LDIS(IX) = LANST(PERM(IX))
100   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, LDIS)
         
C  display in order and label all annotation styles in ldis
      YINCR = MIN (0.25, 1.0 / (LSIZ+1))
      YLOC  = 1 - YINCR
C  annotation offsets in WC
      ANOFFX = 0.2 
      ANOFFY = 0.3 * YINCR 
      DO 220 IX = 1,NUMDIS
C  mark reference and annotation point
         XO(IX) = 0.6
         YO(IX) = YLOC
         XA(IX) = XO(IX) - ANOFFX
         YA(IX) = YO(IX) - ANOFFY

         WRITE (ANSTID, '(A,I5,A)') 'Type#', LDIS(IX), ':'
         CALL VISLAB (ANSTID, 'R', 0.05,0.35,
     1                YLOC-0.3*YINCR, YLOC+0.3*YINCR)

         CALL PSANS (LDIS(IX))
         CALL PATR (XA(IX), YA(IX), ANOFFX*NPCPWC, ANOFFY*NPCPWC, 'abc')
         YLOC = YLOC-YINCR
220   CONTINUE
      CALL PSMK (PAST)
      CALL PPM  (NUMDIS, XA,YA)
      CALL PSMK (POMARK)
      CALL PPM  (NUMDIS, XO,YO)

      END
