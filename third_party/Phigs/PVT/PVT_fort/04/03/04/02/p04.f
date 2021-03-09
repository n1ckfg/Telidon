C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.04.02/04                        *
C  *    TEST TITLE : Appearance of invisible primitives    *
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

      COMMON    /COLORS/ BLACK, GREEN, YELLOW, WHITE, BLUE
      INTEGER    BLACK, GREEN, YELLOW, WHITE, BLUE

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

      INTEGER    SETSIZ
      PARAMETER (SETSIZ=1025)

      INTEGER    PICSTR, TXCI, IX, INVOBS,NUMINV,INVSET(8), RNDINT
      INTEGER    INCSET(SETSIZ), EXCSET(SETSIZ), INCSIZ,EXCSIZ
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7
      INTEGER    NANAMS, NSTRUC, NAMES(8), ICOL

      REAL       XA(10), YA(10), ZA(10), NOMLW, YINCR,YTOP,YLOC, YPOS8
      REAL       RDUM1, RDUM2

      CHARACTER  MSG*300

      CALL INITGL ('04.03.04.02/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL PEXST (102)
      CALL PCLST

      CALL NMSCOL (WKID)
      CALL POPST  (102)
      CALL NMSPRM (.FALSE.)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('5 8 10 11', 'Invisibility of primitives should ' //
     1             'be correctly controlled by the invisibility '    //
     2             'filter when its inclusion set is the largest '   //
     3             'guaranteed by the standard.')

C  incl = {0-63}
C  excl = random set of 6 elements chosen from 0-23
      INCSIZ = 64
      DO 100 IX = 1, INCSIZ
         INCSET(IX) = IX-1
  100 CONTINUE
      EXCSIZ = 6
      CALL RNBSET (EXCSIZ,0,23,EXCSET)

      CALL TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('5 8', 'Invisibility of primitives should be '     //
     1             'correctly controlled by the invisibility filter ' //
     2             'when its inclusion set is null.')

C  incl = null, excl = {2,4,6,8}
      INCSIZ = 0
      CALL SETVS ('2,4,6,8', EXCSET, EXCSIZ)

      CALL TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  <inquire PHIGS facilities> to determine:
C  nanams = number of available names for namesets
      CALL PQPHF (1, ERRIND, IDUM1,IDUM2, NANAMS,
     1            IDUM4,IDUM5,IDUM6,IDUM7)
      CALL CHKINQ ('pqphf', ERRIND)
      IF (NANAMS .GT. SETSIZ) THEN
         WRITE (MSG, '(A,I9,A,I9,A)') 'Number of available names ' //
     1         'exceeds current program limit.  The value of the ' //
     2         'PARAMETER SETSIZ must be changed to ', NANAMS,
     3         '.  The current value is ', SETSIZ, '.'
         CALL INMSG (MSG)
         GOTO 120
       ENDIF

      CALL SETMSG ('5 8 12', 'Invisibility of primitives should be '  //
     1             'correctly controlled by the invisibility filter ' //
     2             'when its inclusion set is the largest supported ' //
     3             'by the implementation.')

C  incl = {0-nanams}
C  excl = random set of 6 elements chosen from 0-23
      DO 110 IX = 1,NANAMS
         INCSET(IX) = NANAMS-IX
  110 CONTINUE
      INCSIZ = NANAMS
      EXCSIZ = 6
      CALL RNBSET (EXCSIZ,0,23,EXCSET)

      CALL TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('5 8 12', 'Invisibility of primitives should be '  //
     1             'correctly controlled by the invisibility filter ' //
     2             'when its exclusion set is the largest supported ' //
     3             'by the implementation.')

C  incl = random set of 6 elements chosen from 0-23
C  excl = {0-63}
      INCSIZ = 6
      CALL RNBSET (INCSIZ,0,23,INCSET)

      EXCSIZ = NANAMS
      DO 130 IX = 1, EXCSIZ
         EXCSET(IX) = NANAMS-IX
130   CONTINUE

      CALL TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

120   CONTINUE

      CALL SETMSG ('5 8 12 13', 'Invisibility of primitives should ' //
     1             'be correctly controlled by the invisibility '    //
     2             'filter by ignoring invalid names in its '        //
     3             'exclusion set.')

C  incl = {0,63}
C  excl = random set of 6 elements chosen from 0-23 plus -11, nanams+11
      INCSIZ = 64
      DO 140 IX = 1,64
         INCSET(IX) = 64-IX
140   CONTINUE
      EXCSIZ = 8
      CALL RNBSET (EXCSIZ,0,23,EXCSET)
      EXCSET(1) = NANAMS+11
      EXCSET(8) = -11
                                                      
      CALL TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('5 8', 'Invisibility of primitives should be '     //
     1             'correctly controlled by the invisibility filter ' //
     2             'when its exclusion set is null.')

C  incl = random set of 6 elements chosen from 0-23
C  excl = null
      INCSIZ = 6
      CALL RNBSET (INCSIZ,0,23,INCSET)
      EXCSIZ = 0

      CALL TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('5 8', 'Invisibility of primitives should be '     //
     1             'correctly controlled by the invisibility filter ' //
     2             'when its inclusion and exclusion set are '        //
     3             'neither null nor full.')

C  incl = random set of 7 elements chosen from 0-23
C  excl = random set of 5 elements chosen from 0-23
      INCSIZ = 7
      CALL RNBSET (INCSIZ,0,23,INCSET)
      EXCSIZ = 5
      CALL RNBSET (EXCSIZ,0,23,EXCSET)

      CALL TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

      CALL PEMST (102)
      CALL PCLST

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('5 8 9', 'Invisible primitives should not ' //
     1             'obscure visible primitives.')
      YINCR = 1 / (9.0)
      YTOP  = 1 - YINCR
      YLOC = YTOP
      XA (1) = 0.2
      XA (2) = 0.8

C  Set up new structure with 8 numbered 2D (drawn in z=0 plane)
C    dotted lines.  Some of these should be invisible, some
C    visible but possibly obscured, and some directly visible:

C  Set display priority of picture to 0
      CALL PPOST (WKID, 150, 0.0)
      CALL POPST (150)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

      CALL PSTXCI (YELLOW)
      CALL NUMLAB (8, 0.15, YTOP, YINCR)

      CALL PSLN   (PLDOT)
      CALL PSLWSC (0.0)
      DO 200 IX = 1,8
         NAMES(1) = IX
         CALL PADS (1, NAMES)
         IF (BLUE.EQ.1) THEN
            ICOL = 1
         ELSE
            IF (IX.GT.4) THEN
               ICOL = IX-4
            ELSE
               ICOL = IX
            ENDIF
         ENDIF
         CALL PSPLCI (ICOL)
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL (2, XA,YA)
         CALL PRES (1, NAMES)
         YLOC = YLOC-YINCR
200   CONTINUE
      CALL PCLST

C  invobs = number invisible or obscured = random from 4 to 6
C  invset = 1-8, in random order
C  numinv = number invisible = invobs/2
      INVOBS = RNDINT (4,6)
      CALL RNPERM (8,INVSET)
      NUMINV = INVOBS/2

C  invset(1       :numinv) should be invisible
C  invset(numinv+1:invobs) should be visible, even though obscured
C  invset(invobs+1:8)      should be visible

C  set invisibility filter using incl = invset(1:numinv), excl = null
      CALL PSIVFT (WKID, NUMINV,INVSET, 0,EXCSET)

C  set up new root structure = nstruc, for obscuring primitives
C  post nstruc to workstation with priority = 1.0
      NSTRUC = 155
      CALL PPOST (WKID, NSTRUC, 1.0)
      CALL POPST (NSTRUC)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  set linewidth scale factor = wide
      CALL PQPLF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMLW,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqplf', ERRIND)
      CALL PSLWSC (0.3 * YINCR / (NOMLW * WCPDC))

C  add names to set: invset(1) to make all obscuring primitives invisible
      CALL PADS (1, INVSET)
      CALL PSLN (PLSOLI)
      ZA(1) = 0.5
      ZA(2) = 0.8
      DO 220 IX = NUMINV+1,INVOBS
C  alternate COLOR between 0 and 1
         CALL PSPLCI (MOD (IX,2))
         YLOC = YPOS8(INVSET(IX))
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL3 (2, XA,YA,ZA)
220   CONTINUE

      CALL DLSTPF ('OBSCURING BY INVISIBLE PRIMITIVES: Which '     //
     1             'primitives appear as visible dotted lines (n ' //
     2             'if none)?', 8-NUMINV, INVSET(NUMINV+1), 'S')

C  wrap it up.
      CALL ENDIT
      END
