C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 05.02/setpcl                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETPCL (PCCTAB)

C  SETPCL: loads the pcctab table with the names of the picture
C  change categories.

      CHARACTER  PCCTAB(17)*34

      PCCTAB(01) = 'polyline bundle representation'
      PCCTAB(02) = 'polymarker bundle representation'
      PCCTAB(03) = 'text bundle representation'
      PCCTAB(04) = 'interior bundle representation'
      PCCTAB(05) = 'edge bundle representation'
      PCCTAB(06) = 'pattern representation'
      PCCTAB(07) = 'colour representation'
      PCCTAB(08) = 'view representation'
      PCCTAB(09) = 'workstation transformation'
      PCCTAB(10) = 'highlighting filter'
      PCCTAB(11) = 'invisibility filter'
      PCCTAB(12) = 'HLHSR mode'
      PCCTAB(13) = 'structure content'
      PCCTAB(14) = 'post structure'
      PCCTAB(15) = 'unpost structure'
      PCCTAB(16) = 'delete structure'
      PCCTAB(17) = 'reference modification'

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 05.02/setsvr                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETSVR (WKID, REQSVR)

C  SETSVR: attempts to set the SVR of the specified workstation
C  to requested state.  There is no error report; the caller must
C  determine success.

C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C dynamic modification
      INTEGER    PIRG,      PIMM,      PCBS
      PARAMETER (PIRG = 0,  PIMM = 1,  PCBS = 2)
C clear control flag
C                conditionally  always
      INTEGER    PCONDI,        PALWAY
      PARAMETER (PCONDI = 0,    PALWAY = 1)
C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)

      INTEGER   WKID, REQSVR, ACTSEV, ACTPCC

      CALL PSDUS (WKID, PWAITD, PUQUM)
C make SVR correct
      CALL PRST  (WKID, PCONDI)

      IF (REQSVR .EQ. PVRDFR) THEN
C  attempt IRG-type picture change
         CALL PICCHG (WKID, '0', '13,14,15,16,17,9,8,1,2,3,4,5,6,7,' //
     1                '10,11,12', ACTSEV, ACTPCC)
      ELSEIF (REQSVR .EQ. PVRSIM) THEN
C  attempt CBS-type picture change
         CALL PICCHG (WKID, '2', '13,14,15,16,17,9,8,1,2,3,4,5,6,7,' //
     1                '10,11,12', ACTSEV, ACTPCC)
      ENDIF

      END


C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 05.02/surfok                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION SURFOK (WKID, EXPSUR)

C  SURFOK: true iff display surface flag equals expected value.

      INTEGER   WKID, EXPSUR, ERRIND, ACTSUR
      INTEGER   IDUM1, IDUM2, IDUM3

      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, ACTSUR, IDUM3)
      CALL CHKINQ ('pqdus', ERRIND)
      SURFOK = ACTSUR .EQ. EXPSUR

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 05.02/svrok                       *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION SVROK (WKID, EXPVLS)

C  SVROK: true iff current SVR is one of the expected values,
C  encoded by character: c-correct, s-simulated, d-deferred.
C  E.g. expvls = 'cd' means SVR must be either CORRECT or
C  DEFERRED.

C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)

      INTEGER   WKID, ERRIND, ACTSVR
      INTEGER   IDUM1, IDUM2, IDUM3
      CHARACTER EXPVLS*(*), SVRCOD(PVROK:PVRSIM)*1

      DATA SVRCOD /'c', 'd', 's'/

      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, IDUM3, ACTSVR)
      CALL CHKINQ ('pqdus', ERRIND)
      SVROK = INDEX(EXPVLS, SVRCOD(ACTSVR)) .GT. 0

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 05.02/picenv                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PICENV (WKID)

C  PICENV: sets up an environment of posted structures to the
C  specified workstation, so that PICCHG can be perform requested
C  changes.

C  Structure Conventions:
C
C  #101 is posted and contains a polyline, polymarker, text,
C       fill-area-set to exercise primitive representation changes
C       (PCC 1-7).
C
C  #201 is posted with lines fanning out from the bottom,
C       available for element deletion (PCC 13).
C
C  #301-350 are posted each with line fanning out from the top,
C       available for unposting or structure deletion (PCC 15-16)
C
C  #400,401,402 is a small network, with 400 executing either 401 or
C       402, available for <change structure references> (PCC 17).
C       401 has a 60-deg line, 402 a 150-deg line.
C
C  PCC 8-12, 14 require no additional environment.  PCC 14 will post
C  a new structure 5xx, with vertical lines.

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER   WKID, ENDPTS(2), IX, LIM2, NAMSET(5), ATTRIB

      REAL      IMAT(3,3), VCLIP(4), PLX(2),PLY(2), PMX(1), PMY(1)
      REAL      FASX(6), FASY(6), ANG, PI
      PARAMETER (PI = 3.14159265)

      DATA VCLIP / 0.0, 1.0, 0.0, 1.0  /

      DATA PLX   / 0.3,0.7 /, PMX /0.08/
      DATA PLY   / 0.7,0.3 /, PMY /0.08/

      DATA FASX   / 0.1, 0.2, 0.3, 0.7, 0.8, 0.9 /
      DATA FASY   / 0.1, 0.3, 0.1, 0.9, 0.7, 0.9 /
      DATA ENDPTS / 3,6 /

C first, clear the decks
      CALL PDAS

C set up 101 with bundled primitives
      CALL POPST (101)
      DO 100 ATTRIB = 0,17
         CALL PSIASF (ATTRIB, PBUNDL)
100   CONTINUE
C use entry #1 in all bundles. This is the default, except for view,
C which must be set explicitly.
      CALL PSVWI (1)
      CALL IDMAT (3, IMAT)
C set up view #1 like default
      CALL PSVWR (WKID, 1, IMAT,IMAT, VCLIP, PCLIP)
      CALL PPL (2, PLX,PLY)
      CALL PPM (1, PMX,PMY)
C potential highlight: filter = [1]
      NAMSET(1) = 1
      CALL PADS (1, NAMSET)
      CALL PSCHH (0.1)
      CALL PTX (0.15, 0.50, '?')
C potential invisibility: filter = [2]
      CALL PRES (1, NAMSET)
      NAMSET(1) = 2
      CALL PADS (1, NAMSET)
      CALL PFAS (2, ENDPTS, FASX,FASY)
      CALL PRES (1, NAMSET)
      CALL PCLST
      CALL PPOST (WKID, 101, 0.5)

C set up 201, posted, with lines fanning out from the bottom
      CALL POPST (201)
      PLX(1) = 0.5
      PLY(1) = 0.0
      LIM2 = 50
      DO 200 IX = 1,LIM2-1
         ANG = PI * IX / LIM2
         PLX(2) = PLX(1) + 0.3 * COS(ANG)
         PLY(2) = PLY(1) + 0.3 * SIN(ANG)
         CALL PPL (2, PLX,PLY)
200   CONTINUE
      CALL PCLST
      CALL PPOST (WKID, 201, 0.5)

C  set up 301-350, posted, each with line fanning out from the top
      PLX(1) = 0.5
      PLY(1) = 1.0
      LIM2 = 50
      DO 300 IX = 1,LIM2
         CALL POPST (300+IX)
         ANG = PI * IX / LIM2
         PLX(2) = PLX(1) + 0.3 * COS(ANG)
         PLY(2) = PLY(1) - 0.3 * SIN(ANG)
         CALL PPL (2, PLX,PLY)
         CALL PCLST
         CALL PPOST (WKID, 300+IX, 0.5)
300   CONTINUE

C  set up 400,401,402 as a small posted network, with 400
C  executing either 401 or 402.  401 has a 60-deg line, 402 a
C  150-deg line.
      CALL POPST (400)
      CALL PEXST (401)
      CALL PCLST
      CALL PPOST (WKID, 400, 0.5)

      PLX(1) = 0.5
      PLY(1) = SQRT(0.75)
      PLY(2) = 0.0

      CALL POPST (401)
      PLX(2) = 0.0
      CALL PPL (2, PLX,PLY)
      CALL PCLST

      CALL POPST (402)
      PLX(2) = 1.0
      CALL PPL (2, PLX,PLY)
      CALL PCLST

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 05.02/picchg                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PICCHG (WKID, SEVLST, PCCLST, ACTSEV, ACTPCC)

C  PICCHG: attempts to perform a visual change according to the
C  preferred order of the requested severity-list and of the
C  specified categories (a subset of the 17 kinds of picture
C  change).  It then returns the actual severity and actual picture
C  change category performed, or indicates that nothing in the
C  severity-list / pcc-list combination could be done.

C  --- Input Parameters:
C  wkid    : Identifier of workstation for picture change
C  sevlst  : List of severity codes in preferred order,
C            string format.  E.g. '0,2' means first try IRG,
C            then CBS.
C  pcclst  : List of picture change categories in preferred
C            order (within a given severity code), string format.
C            E.g. '2,3' means first try polymarker bundle change,
C            then text bundle change.
C
C  --- Output Parameters:
C  actsev  : Severity code of actual change; 0 if nothing done.
C  actpcc  : Picture change category code of actual change; 0 if
C            nothing done.

      SAVE

C attribute identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

      INTEGER    PEDT,     PEWSC,    PEDCI
      PARAMETER (PEDT=15,  PEWSC=16, PEDCI=17)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)
C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)
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
C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)
C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)
C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)
C polyline/fill area control flag
      INTEGER    PPLINE,     PFILLA,     PFILAS
      PARAMETER (PPLINE = 1, PFILLA = 2, PFILAS = 3)
C dynamic modification
      INTEGER    PIRG,      PIMM,      PCBS
      PARAMETER (PIRG = 0,  PIMM = 1,  PCBS = 2)
C Current and Requested values.
      INTEGER    PCURVL,     PRQSVL
      PARAMETER (PCURVL = 0, PRQSVL = 1)

C size of pattern-aray
      INTEGER    CLIM
      PARAMETER (CLIM = 50)

      INTEGER    WKID, ERRIND, SPECON, SPECWT, ACTSEV, ACTPCC
      INTEGER    SEVCOD(10), SEVSIZ, SEVDX, PCCCOD(20), PCCSIZ, PCCDX
      INTEGER    PCCSEV(17), NAINTS, II, PDX,PDY, COLIA(CLIM,CLIM)
      INTEGER    THISIS, LTYPE, MTYPE, EDFLAG, FCLIP, ISTYLE, NUMRET
      INTEGER    INSET(CLIM), EXSET(CLIM), INSIZ,EXSIZ, CURMOD, IX
      INTEGER    NUMODE, NEWMOD, POSTCT, KILLCT, OLDSTR, NEWSTR

      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4

      REAL       CHEXP, CURVP(6), PX(10),PY(10), CSPEC(3)
      REAL       RADUM1(6), RADUM2(6), RADUM3(6)
      REAL       RDUM1, RDUM4(4,4), RDUM5(4,4), RDUM6(6)

      LOGICAL    NOPAT

      CHARACTER  SEVLST*(*), PCCLST*(*)

C  postct keeps track of new structure to be posted
C  killct keeps track of old structures to be deleted or unposted
      DATA POSTCT / 1 /, KILLCT / 1 /
C  which structure is currently referenced?
      DATA OLDSTR / 401 /
      DATA PCCSEV / 17*666 /

C  Category codes:
C
C  01 : polyline bundle representation
C  02 : polymarker bundle representation
C  03 : text bundle representation
C  04 : interior bundle representation
C  05 : edge bundle representation
C  06 : pattern representation
C  07 : colour representation
C  08 : view representation
C  09 : workstation transformation
C  10 : highlighting filter
C  11 : invisibility filter
C  12 : HLHSR mode
C  13 : structure content
C  14 : post structure
C  15 : unpost structure
C  16 : delete structure
C  17 : reference modification

C  convert lists to numeric
      CALL SETVS (SEVLST, SEVCOD, SEVSIZ)
      CALL SETVS (PCCLST, PCCCOD, PCCSIZ)

C  specific workstation type from wkid
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  get actual severity codes
      CALL PQDSWA (SPECWT, ERRIND,         PCCSEV(01), PCCSEV(02),
     1             PCCSEV(03), PCCSEV(04), PCCSEV(05), PCCSEV(06),
     2             PCCSEV(07), PCCSEV(08), PCCSEV(09), PCCSEV(10),
     3             PCCSEV(11), PCCSEV(12) )
      CALL CHKINQ ('pqdswa', ERRIND)

      CALL PQDSTR (SPECWT, ERRIND, PCCSEV(13), PCCSEV(14),
     1                 PCCSEV(15), PCCSEV(16), PCCSEV(17) )
      CALL CHKINQ ('pqdstr', ERRIND)

C  determine pattern availability
C     nopat = no pattern interior style available
      NOPAT = .FALSE.
      CALL PQIF (SPECWT, 0, 0, ERRIND, NAINTS, IDUM1, IDUM2, IDUM3,
     1           IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
C loop thru list of available interior styles till find PPATTR
      DO 20 II = 1, NAINTS
         CALL PQIF (SPECWT, II, 0, ERRIND, IDUM1, THISIS, IDUM2,
     1               IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS .EQ. PPATTR) GOTO 25
20    CONTINUE
      NOPAT = .TRUE.
25    CONTINUE

C  run through all eligible severities and change-categories
      DO 100 SEVDX = 1, SEVSIZ
         ACTSEV = SEVCOD(SEVDX)
         DO 110 PCCDX = 1, PCCSIZ
            ACTPCC = PCCCOD(PCCDX)
            IF (PCCSEV(ACTPCC) .EQ. ACTSEV) THEN
               IF (ACTPCC .EQ. 6 .AND. NOPAT) THEN
C                 do nothing - pattern requested but unavailable
               ELSE
                  GOTO 1000
               ENDIF
            ENDIF
110      CONTINUE
100   CONTINUE

C  failed to find available combination
      ACTSEV = 0
      ACTPCC = 0
      RETURN

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  got performable picture change category = actpcc
1000  CONTINUE
      GOTO (2010,2020,2030,2040,2050,2060,2070,2080,2090,2100,
     1      2110,2120,2130,2140,2150,2160,2170), ACTPCC

C  01:polyline bundle representation
2010  CONTINUE
      CALL PQPLR (WKID,1,PSET, ERRIND,LTYPE,RDUM1,IDUM1)
      CALL CHKINQ ('pqplr', ERRIND)
      LTYPE = MOD (LTYPE,4) + 1
      CALL PSPLR (WKID,1, LTYPE,RDUM1,IDUM1)
      GOTO 3000

C  02:polymarker bundle representation
2020  CONTINUE
      CALL PQPMR (WKID,1,PSET, ERRIND,MTYPE,RDUM1,IDUM1)
      CALL CHKINQ ('pqpmr', ERRIND)
      MTYPE = MOD (MTYPE,5) + 1
      CALL PSPMR (WKID,1, MTYPE,RDUM1,IDUM1)
      GOTO 3000

C  03:text bundle representation
2030  CONTINUE
      CALL PQTXR (WKID,1,PSET, ERRIND, IDUM1,IDUM2, CHEXP, RDUM1,IDUM3)
      CALL CHKINQ ('pqtxr', ERRIND)
      CHEXP = CHEXP * 1.05
      CALL PSTXR (WKID,1, IDUM1,IDUM2, CHEXP, RDUM1,IDUM3)
      GOTO 3000

C  04:interior bundle representation
2040  CONTINUE
      CALL PQIR (WKID,1,PSET, ERRIND, ISTYLE, IDUM1,IDUM2)
      CALL CHKINQ ('pqir', ERRIND)
C these two styles are mandatory
      IF (ISTYLE .EQ. PHOLLO) THEN
         ISTYLE = PISEMP
      ELSE
         ISTYLE = PHOLLO
      ENDIF
      CALL PSIR (WKID,1, ISTYLE, IDUM1,IDUM2)
      GOTO 3000

C  05:edge bundle representation
2050  CONTINUE
      CALL PQEDR (WKID,1,PSET, ERRIND, EDFLAG, IDUM1,RDUM1,IDUM2)
      CALL CHKINQ ('pqedr', ERRIND)
      EDFLAG = 1 - EDFLAG
      CALL PSEDR (WKID,1, EDFLAG, IDUM1,RDUM1,IDUM2)
      GOTO 3000

C  06:pattern representation
2060  CONTINUE
      CALL PQPAR (WKID,1,PSET,CLIM,CLIM, ERRIND, PDX,PDY,COLIA)
      CALL CHKINQ ('pqpar', ERRIND)
      IF (COLIA(1,1) .EQ. 0) THEN
         COLIA(1,1) = 1
      ELSE
         COLIA(1,1) = 0
      ENDIF
      CALL PSPAR (WKID,1,CLIM,CLIM, 1,1, PDX,PDY, COLIA)
      GOTO 3000

C  07:colour representation
2070  CONTINUE
      CALL PQCR (WKID,1,3,PSET, ERRIND, NUMRET, CSPEC)
      CALL CHKINQ ('pqcr', ERRIND)
      CSPEC(NUMRET) = MOD (CSPEC(NUMRET) + 0.5, 1.0)
      CALL PSCR (WKID,1, NUMRET, CSPEC)
      GOTO 3000

C  08:view representation
2080  CONTINUE
      CALL PQVWR (WKID,1,PCURVL, ERRIND, IDUM1,RDUM4,RDUM5,RDUM6,
     1                                   IDUM2,IDUM3, FCLIP)
      CALL CHKINQ ('pqvwr', ERRIND)
      FCLIP = 1 - FCLIP
      CALL PSVWR3 (WKID,1, RDUM4,RDUM5,RDUM6, IDUM2,IDUM3, FCLIP)
      GOTO 3000

C  09:workstation transformation
2090  CONTINUE
      CALL PQWKT3 (WKID, ERRIND, IDUM1, RADUM1, RADUM2, RADUM3, CURVP)
      CALL CHKINQ ('pqwkt3', ERRIND)
C shrink y-dim of viewport slightly
      CURVP(4) = 0.99 * (CURVP(4) - CURVP(3)) + CURVP(3)
      CALL PSWKV3 (WKID, CURVP)
      GOTO 3000

C  10:highlighting filter
2100  CONTINUE
      CALL PQHLFT (WKID, CLIM,CLIM, ERRIND, INSIZ,INSET,EXSIZ,EXSET)
      CALL CHKINQ ('pqhlft', ERRIND)
      EXSIZ = 0
      IF (INSIZ .EQ. 0) THEN
         INSIZ = 1
         INSET(1) = 1
      ELSE
         INSIZ = 0
      ENDIF
      CALL PSHLFT (WKID, INSIZ,INSET,EXSIZ,EXSET)
      GOTO 3000

C  11:invisibility filter
2110  CONTINUE
      CALL PQIVFT (WKID, CLIM,CLIM, ERRIND, INSIZ,INSET,EXSIZ,EXSET)
      CALL CHKINQ ('pqivft', ERRIND)
      EXSIZ = 0
      IF (INSIZ .EQ. 0) THEN
         INSIZ = 1
         INSET(1) = 2
      ELSE
         INSIZ = 0
      ENDIF
      CALL PSIVFT (WKID, INSIZ,INSET,EXSIZ,EXSET)
      GOTO 3000

C  12:HLHSR mode
2120  CONTINUE
      CALL PQHRM (WKID, ERRIND, IDUM1, CURMOD, IDUM2)
      CALL CHKINQ ('pqhrm', ERRIND)
      CALL PQHRMF (SPECWT, 0, ERRIND, NUMODE, IDUM3)
      CALL CHKINQ ('pqhrmf', ERRIND)
C look for different, valid mode
      DO 2125 IX = 1,NUMODE
         CALL PQHRMF (SPECWT, IX, ERRIND, IDUM3, NEWMOD)
         CALL CHKINQ ('pqhrmf', ERRIND)
         IF (NEWMOD .NE. CURMOD) GOTO 2127
2125  CONTINUE
      NEWMOD = CURMOD
2127  CONTINUE
      CALL PSHRM (WKID, NEWMOD)
      GOTO 3000

C  13:structure content
2130  CONTINUE
C delete last element of 201
      CALL POPST (201)
      CALL PDEL
      CALL PCLST
      GOTO 3000

C  14:post structure
2140  CONTINUE
C  PCC 14 posts a new structure 5xx, with vertical lines.
      CALL PPOST (WKID, 500 + POSTCT, 0.5)
      PY(1) = 0.4
      PY(2) = 0.6
      PX(1) = 1.0 / (2 ** POSTCT)
      PX(2) = PX(1)
      CALL POPST (500 + POSTCT)
      CALL PPL (2, PX,PY)
      CALL PCLST
      POSTCT = POSTCT+1
      GOTO 3000

C  15:unpost structure
2150  CONTINUE
      CALL PUPOST (WKID, 300 + KILLCT)
      KILLCT = KILLCT + 1
      GOTO 3000

C  16:delete structure
2160  CONTINUE
      CALL PDST (300 + KILLCT)
      KILLCT = KILLCT + 1
      GOTO 3000

C  17:reference modification
2170  CONTINUE
C alternate between 401 and 402
      NEWSTR = 803 - OLDSTR
      CALL PCSTRF (OLDSTR, NEWSTR)
      OLDSTR = NEWSTR
      GOTO 3000

3000  CONTINUE

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 05.02/exsvrs                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EXSVRS (SEVRTY, DEFMOD, MODMD, OLDSVR, 
     1                   SVRLST, EXPLBL)

C  EXSVRS returns a string that represents the expected state(s) of visual
C  representation.  It contains c, d, and/or s to indicate that the allowed
C  state(s) are correct, deferred, or simulated, respectively.  It also
C  returns a English label to describe the states.  This function applies
C  only to defer mode WAIT, PBNIL, PBNIG, and ASTI.

C  Input parameters:
C    SEVRTY : severity code for the category of picture change (IRG,IMM,CBS)
C    DEFMOD : deferral mode (WAIT,ASTI,BNIL,BNIG)
C    MODMD  : modification mode (UWOR,UQUM)
C    OLDSVR : original state of visual representation (CORRECT, DEFERRED,
C             SIMULATED)
C  Output parameters:
C    SVRLST : 3-character code, containing some combination of c,d,s for
C             CORRECT, DEFERRED, SIMULATED         
C    EXPLBL : English label corresponding to SVRLST

C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C dynamic modification
      INTEGER    PIRG,      PIMM,      PCBS
      PARAMETER (PIRG = 0,  PIMM = 1,  PCBS = 2)
C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)

      INTEGER    SEVRTY, DEFMOD, MODMD, OLDSVR, SVRX, NXTPOS, ITRIM

      LOGICAL    SVRST(PVROK:PVRSIM), NONF

      CHARACTER  SVRLAB(PVROK:PVRSIM)*10, EXPLBL*(*)
      CHARACTER  SVRCOD(PVROK:PVRSIM)*1, SVRLST*3

      DATA SVRCOD / 'c', 'd', 's' /
      DATA SVRLAB / 'CORRECT', 'DEFERRED', 'SIMULATED' /

      IF (DEFMOD.LT.PBNIG .OR. DEFMOD.GT.PWAITD) THEN
         CALL UNMSG ('Illegal deferral mode passed to EXSVRS.')
      ENDIF

      IF (MODMD.EQ.PUWOR .OR. MODMD.EQ.PUQUM) THEN
C        OK
      ELSE
         CALL UNMSG ('Illegal modification mode passed to EXSVRS.')
      ENDIF

      IF (OLDSVR.EQ.PVROK  .OR.
     1    OLDSVR.EQ.PVRDFR .OR.
     2    OLDSVR.EQ.PVRSIM) THEN
C        OK
      ELSE
         CALL UNMSG ('Illegal SVR passed to EXSVRS.')
      ENDIF

C  so much for validity checking - now compute expected state(s)
      SVRST(PVROK)  = .FALSE.
      SVRST(PVRDFR) = .FALSE.
      SVRST(PVRSIM) = .FALSE.

      SVRST(OLDSVR) = .TRUE.
      IF (SEVRTY .EQ. PIMM) THEN
C        OK as is
      ELSEIF (SEVRTY .EQ. PIRG) THEN
         SVRST(PVRDFR) = .TRUE.
         IF (MODMD.EQ.PUQUM .AND. OLDSVR.EQ.PVROK) THEN
            SVRST(PVRSIM) = .TRUE.
         ENDIF
      ELSEIF (SEVRTY .EQ. PCBS) THEN
         IF (MODMD.EQ.PUQUM) THEN
            IF (OLDSVR.EQ.PVROK) THEN
               SVRST(PVRSIM) = .TRUE.
            ENDIF
         ELSE
C           MODMD.EQ.PUWOR
            SVRST(PVRDFR) = .TRUE.
         ENDIF
      ELSE
         CALL UNMSG ('Illegal severity code passed to EXSVRS.')
      ENDIF

      IF (DEFMOD.EQ.PASTI .OR. DEFMOD.EQ.PBNIG .OR. DEFMOD.EQ.PBNIL) 
     1    SVRST(PVROK) = .TRUE.

      SVRLST = '   '

      IF (SVRST(PVROK)  ) SVRLST(1:1) = 'c'
      IF (SVRST(PVRDFR) ) SVRLST(2:2) = 'd'
      IF (SVRST(PVRSIM) ) SVRLST(3:3) = 's'

      NONF = .FALSE.
      NXTPOS = 1

      DO 98 SVRX = PVROK,PVRSIM
         IF (SVRST(SVRX)) THEN
            IF (NONF) THEN
               EXPLBL(NXTPOS:) = ' or '
               NXTPOS = NXTPOS + 4
            ELSE
               NONF = .TRUE.
            ENDIF
            EXPLBL(NXTPOS:) = SVRLAB(SVRX)
            NXTPOS = ITRIM(EXPLBL) + 1
         ENDIF
98    CONTINUE

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 05.02/doimod                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
                                              
      SUBROUTINE DOIMOD (WKID, INCLAS, INMODE)

C  DOIMOD: on the workstation (wkid), sets device #1 of the
C  specified input class (inclas) to the requested mode (inmode).

C operating mode
C                request  sample    event
      INTEGER    PREQU,   PSAMPL,   PEVENT
      PARAMETER (PREQU=0, PSAMPL=1, PEVENT=2)
C echo switch
      INTEGER    PNECHO,   PECHO
      PARAMETER (PNECHO=0, PECHO=1)

      INTEGER   WKID, INCLAS, INMODE

      GOTO (10, 20, 30, 40, 50, 60), INCLAS
      CALL UNMSG ('Invalid input class passed to DOIMOD.')

10    CONTINUE
C     set locator mode
      CALL PSLCM (WKID, 1, INMODE, PNECHO)
      GOTO 100
20    CONTINUE
C     set stroke mode
      CALL PSSKM (WKID, 1, INMODE, PNECHO)
      GOTO 100
30    CONTINUE
C     set valuator mode
      CALL PSVLM (WKID, 1, INMODE, PNECHO)
      GOTO 100
40    CONTINUE
C     set choice mode
      CALL PSCHM (WKID, 1, INMODE, PNECHO)
      GOTO 100
50    CONTINUE
C     set pick mode
      CALL PSPKM (WKID, 1, INMODE, PNECHO)
      GOTO 100
60    CONTINUE
C     set string mode
      CALL PSSTM (WKID, 1, INMODE, PNECHO)
      GOTO 100

100   CONTINUE

      END
