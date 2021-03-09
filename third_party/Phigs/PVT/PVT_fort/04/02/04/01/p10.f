C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/10                        *
C  *    TEST TITLE : Annotation style                      *
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

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

C annotation style
      INTEGER    PUNCON,     PLDLN
      PARAMETER (PUNCON = 1, PLDLN = 2)

      INTEGER    IMPMAX, NUMLIN, PERM(20), NGSTYL, LNID, TRUANS
      PARAMETER (IMPMAX = 300)
      INTEGER    NUMAS,MINANS,MAXANS, STDDX,REGDX,IMPDX, ANSTYL
      INTEGER    ADX, THISAS, LAVRAS(20), LAVSAS(2), LAVIAS(IMPMAX)
      INTEGER    LUNSUP(10), UNSUDX, NUMLT,LNTYP,LNCOL, RNDINT
      INTEGER    PICSTR, TXCI, IX
      INTEGER    IDUM1, IDUM2

      REAL       NPCX,NPCY,NPCPWC, YINCR,YLOC, ANOFFX,ANOFFY, LWSCF
      REAL       XA(20),YA(20), XB(20),YB(20), XO(20),YO(20), NOMLW
      REAL       RDUM1, RDUM2

      CHARACTER  MSG*1600

      LOGICAL    ANSAVL(0:2)

      CALL INITGL ('04.02.04.01/10')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  defaults
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (0.7)
      CALL PSCHSP (0.1)
C  geometric attributes for annotation text
      CALL PSATCH (0.03 * NPCPWC)
      CALL PSATAL (PARITE, PAHALF)
C  geometric attributes for text
      CALL PSCHH  (0.03)
      CALL PSTXAL (PARITE, PAHALF)
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (102)

C  use <inquire annotation facilities> to determine:
C    numas  = number of available annotation styles
C    lavsas = list of available standard annotation styles
C    lavras = list of available registered (non-mandatory) annotation styles
C    lavias = list of available implementor-defined annotation styles

      CALL PQANF (SPECWT, 1, ERRIND, NUMAS, MINANS, IDUM2, RDUM1,RDUM2)
      CALL CHKINQ ('pqanf', ERRIND)
      MAXANS = MINANS
      STDDX = 0
      REGDX = 0
      IMPDX = 0
      ANSAVL(0) = .FALSE.
      ANSAVL(1) = .FALSE.
      ANSAVL(2) = .FALSE.

      DO 150 ADX = 1,NUMAS
         CALL PQANF (SPECWT,ADX, ERRIND, IDUM1, THISAS,
     1               IDUM2,RDUM1,RDUM2)
         CALL CHKINQ ('pqanf', ERRIND)
         MINANS = MIN (MINANS, THISAS)
         MAXANS = MAX (MAXANS, THISAS)
         IF  (THISAS .GT. 2) THEN
            REGDX = REGDX+1
            LAVRAS (REGDX) = THISAS
         ELSEIF (THISAS .GT. 0) THEN
            STDDX = STDDX +1
            LAVSAS (STDDX) = THISAS
            ANSAVL(THISAS) = .TRUE.
         ELSE
            IF (THISAS .EQ. 0) ANSAVL(0) = .TRUE.
            IF (IMPDX .LT. IMPMAX) THEN
               IMPDX = IMPDX+1
               LAVIAS (IMPDX) = THISAS
            ENDIF
         ENDIF
150   CONTINUE

      CALL SETMSG ('77', 'The list of available annotation styles ' //
     1             'returned by <inquire annotation facilities> '   //
     2             'should include styles number 1 and 2.')
      CALL IFPF (ANSAVL(1) .AND. ANSAVL(2))

      CALL DLINE ('Throughout this program, when an annotation '  //
     1            'text primitive is displayed, its reference '   //
     2            'point is marked with an asterisk polymarker, ' //
     3            'and its annotation point with a circle '       //
     4            'polymarker (enter anything to continue).', MSG)

      IF (.NOT. ANSAVL(PUNCON)) THEN
         CALL INMSG ('Skipping tests for annotation style #1: not ' //
     1               'available.')
         GOTO 300
      ENDIF

C  *** *** ***   style #1 (unconnected)   *** *** ***

C  set up perm to randomize order
      NUMLIN = 6
      CALL RNPERM (NUMLIN, PERM)

C  ngstyl = random integer from 1 to 3
      NGSTYL = RNDINT(1,3)

C  display interspersed 3 actual and 3 simulated examples of style #1,
C    with actual #ngstyl done incorrectly (use style #2)
      YINCR = 1.0 / (NUMLIN+1)
      YLOC  = 1 - YINCR
      CALL NUMLAB (NUMLIN, 0.2, YLOC, YINCR)
C  annotation offsets in WC
      ANOFFX = -0.2
      ANOFFY =  0.3 * YINCR
      DO 200 IX = 1,NUMLIN
C  mark reference and annotation point
         XO(IX) = 0.5
         YO(IX) = YLOC
         XA(IX) = XO(IX) - ANOFFX
         YA(IX) = YO(IX) - ANOFFY

         LNID = PERM(IX)
         IF (LNID .GT. 3) THEN
C  do simulation
            CALL PTX (XO(IX), YO(IX), 'Primitive')
         ELSE
C  do actual
            IF (LNID .EQ. NGSTYL) THEN
               ANSTYL = PLDLN
               TRUANS = IX
            ELSE
               ANSTYL = PUNCON
            ENDIF
            CALL PSANS (ANSTYL)
            CALL PATR (XA(IX),YA(IX), ANOFFX*NPCPWC, ANOFFY*NPCPWC,
     1                 'Primitive')
         ENDIF
         YLOC = YLOC-YINCR
200   CONTINUE
      CALL PSMK (PAST)
      CALL PPM  (NUMLIN, XA,YA)
      CALL PSMK (POMARK)
      CALL PPM  (NUMLIN, XO,YO)

      CALL SETMSG ('1 2 5 75 76 78 80', 'The mandatory annotation '   //
     1             'style number 1 should leave the reference point ' //
     2             'and the annotation point of the annotation text ' //
     3             'primitive unconnected.')

      CALL DCHPFV ('ANNOTATION STYLE 1: Which annotation style is ' //
     1             'different?', NUMLIN, TRUANS)
      CALL PEMST (102)

      IF (.NOT. ANSAVL(PLDLN)) GOTO 300
C  lunsup = list of (mostly) unsupported annotation styles, contains:
C    a negative unsupported type (< minimum in lavias)
C    a positive unsupported type (> maximum in lavras)
C    1,
C    2, if supported (the only non-#1 style)
C    0, if not in lavias
      LUNSUP(1) = MINANS-10
      LUNSUP(2) = MAXANS+1
      LUNSUP(3) = PUNCON
      LUNSUP(4) = PLDLN
      IF (ANSAVL(0)) THEN
         UNSUDX = 4
      ELSE
         UNSUDX = 5
         LUNSUP(5) = 0
      ENDIF

C  Display in random order annotation styles from lunsup
C  set up perm to randomize order
      CALL RNPERM (UNSUDX, PERM)

      YINCR = 1.0 / (UNSUDX+1)
      YLOC  = 1 - YINCR
      CALL NUMLAB (UNSUDX, 0.2, YLOC, YINCR)
      DO 220 IX = 1,UNSUDX
         ANSTYL = LUNSUP(PERM(IX))
         IF (ANSTYL .EQ. 2) TRUANS = IX
C  mark reference and annotation point
         XO(IX) = 0.5
         YO(IX) = YLOC
         XA(IX) = XO(IX) - ANOFFX
         YA(IX) = YO(IX) - ANOFFY

         CALL PSANS (ANSTYL)
         CALL PATR (XA(IX),YA(IX), ANOFFX*NPCPWC, ANOFFY*NPCPWC,
     1              'Primitive')
         YLOC = YLOC-YINCR
220   CONTINUE
      CALL PSMK (PAST)
      CALL PPM  (UNSUDX, XA,YA)
      CALL PSMK (POMARK)
      CALL PPM  (UNSUDX, XO,YO)

      CALL SETMSG ('5 75 76 78 79 80', 'Unavailable annotation '     //
     1             'styles should be displayed as annotation style ' //
     2             'number 1.')

      CALL DCHPFV ('UNSUPPORTED ANNOTATION STYLE: Which annotation ' //
     1             'style is different?', UNSUDX, TRUANS)
      CALL PEMST (102)

C  end_style_1:
300   CONTINUE

C  *** *** ***   style #2 (connected)   *** *** ***

      IF (.NOT. ANSAVL(PLDLN)) THEN
         CALL INMSG ('Skipping tests for annotation style #2: not ' //
     1               'available.')
         GOTO 400
      ENDIF

C  set up perm to randomize order
      NUMLIN = 6
      CALL RNPERM (NUMLIN, PERM)

C  ngstyl = random integer from 1 to 3
      NGSTYL = RNDINT(1,3)

C  display interspersed 3 actual and 3 simulated examples of style #2,
C    with actual #ngstyl done incorrectly (use style #1)
      YINCR = 1.0 / (NUMLIN+1)
      YLOC  = 1 - YINCR
      CALL NUMLAB (NUMLIN, 0.2, YLOC, YINCR)

C  set up exciting polyline attributes
      CALL PQPLF (SPECWT, 0, ERRIND, NUMLT, IDUM1,
     1            IDUM2,NOMLW,RDUM1,RDUM2, IDUM2)
      CALL CHKINQ ('pqplf', ERRIND)
      CALL PQPLF (SPECWT, RNDINT(1, ABS(NUMLT)), ERRIND, NUMLT,LNTYP,
     1            IDUM2,NOMLW,RDUM1,RDUM2, IDUM2)
      CALL CHKINQ ('pqplf', ERRIND)
      LWSCF = .02 / (NOMLW * WCPDC)
      LNCOL = 2
C  set linetype/width thru bundle, color individually
      CALL PSLN   (LNTYP+1)
      CALL PSLWSC (2*LWSCF)
      CALL PSPLCI (LNCOL)
      CALL PSPLI  (2)
      CALL PSPLR  (WKID, 2, LNTYP,LWSCF,LNCOL-1)
      CALL PSIASF (PLN,   PBUNDL)
      CALL PSIASF (PLWSC, PBUNDL)

      DO 310 IX = 1,NUMLIN
C  mark reference and annotation point
         XO(IX) = 0.5
         YO(IX) = YLOC
         XA(IX) = XO(IX) - ANOFFX
         YA(IX) = YO(IX) - ANOFFY

         LNID = PERM(IX)
         IF (LNID .GT. 3) THEN
C  do simulation
            CALL PTX (XO(IX),YO(IX), 'Primitive')
            XB(1) = XA(IX)
            YB(1) = YA(IX)
            XB(2) = XO(IX)
            YB(2) = YO(IX)
            CALL PPL (2, XB,YB)
         ELSE
C  do actual
            IF (LNID .EQ. NGSTYL) THEN
               ANSTYL = PUNCON
               TRUANS = IX
            ELSE
               ANSTYL = PLDLN
            ENDIF
            CALL PSANS (ANSTYL)
            CALL PATR (XA(IX),YA(IX), ANOFFX*NPCPWC, ANOFFY*NPCPWC,
     1                 'Primitive')
         ENDIF
         YLOC = YLOC-YINCR
310   CONTINUE
      CALL PSMK (PAST)
      CALL PPM  (NUMLIN, XA,YA)
      CALL PSMK (POMARK)
      CALL PPM  (NUMLIN, XO,YO)

      CALL SETMSG ('1 2 5 75 76 78 80', 'The mandatory annotation ' //
     1             'style number 2 should connect the reference '   //
     2             'point and annotation point with a polyline, '   //
     3             'using the current attributes.')

      CALL DCHPFV ('ANNOTATION STYLE 2: Which annotation style is ' //
     1             'different?', NUMLIN, TRUANS)
      CALL PEMST (102)

C  end_style_2:
400   CONTINUE

C  *** *** ***   registered styles   *** *** ***

C  regdx = size of lavras
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No registered annotation styles are supported.')
         GOTO 800
      ENDIF

C display and label at most 8 annotation styles in lavras
      CALL DSANST (REGDX, LAVRAS)

      CALL SETMSG ('5 75 76 78 81', 'The registered non-mandatory '   //
     1             'annotation styles (> 2) should agree with their ' //
     2             'registered description.')

      CALL DYNPF ('NON-MANDATORY REGISTERED ANNOTATION STYLES: Is '  //
     1            'each annotation style depicted according to its ' //
     2            'numeric identifier''s specification in the ISO '  //
     3            'register?', 'Y')
      CALL PEMST (102)

C  neg_type:
800   CONTINUE

C  *** *** ***   implementor-defined styles   *** *** ***

C  impdx = size of lavias
      IF (IMPDX .LT. 1) THEN
         CALL INMSG ('No implementor defined annotation styles ' //
     1               'are supported.')
         GOTO 666
      ENDIF

C display and label at most 8 annotation styles in lavias
      CALL DSANST (IMPDX, LAVIAS)

      CALL SETMSG ('5 75 76 78 82', 'Implementor-defined annotation ' //
     1             'styles (< 1) should agree with the descriptions ' //
     2             'supplied by the implementor.')

      CALL DYNPF ('IMPLEMENTOR DEFINED ANNOTATION STYLES: Is each ' //
     1            'annotation style depicted according to its '     //
     2            'numeric identifier''s specification in the '     //
     3            'implementor documentation?', 'Y')
      CALL PEMST (102)

      IF (IMPDX .LE. 8) GOTO 666

      CALL SETMSG ('82', 'All reported implementor-defined '       //
     1             'annotation styles available for a given '      //
     2             'workstation type should be documented by the ' //
     3             'implementor.')

      CALL SRTIAR (IMPDX, LAVIAS)
      WRITE (MSG, '(500I5)') (LAVIAS(IX), IX=1,IMPDX)

      CALL DYNPF ('COMPLETE DOCUMENTATION FOR IMPLEMENTOR '        //
     1            'ANNOTATION STYLES: Are all these reportedly '   //
     2            'available annotation styles documented by the ' //
     3            'implementor?' // MSG, 'Y')

C  end_annotation_style:
666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END

