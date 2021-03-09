      SUBROUTINE SETDLG (PICSTR, DLGSTR, TXCI)

C  SETDLG performs a number of chores to initialize the workstation
C  for interaction with the operator.  It is normally called right
C  after <open phigs>.  There are three input parameters:
C    PICSTR : structure identifier for the picture to be shown
C    DLGSTR : structure identifier for the dialogue area (if used)
C    TXCI   : text color index for dialogue text = absolute value
C             of TXCI.  If TXCI negative, color table initialization
C             is suppressed.

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

C   Example of screen layout set by SETDLG, with dialogue area at right.
C   Dialogue area = prompt area + echo area = rectangle at right or
C   bottom of screen.
C
C   screen:
C   -------------------------------------------
C   |         unused            |             |
C   |---------------------------|             |
C   |                           |             |
C   |                           |   prompt    |
C   |                           |             |
C   |       picture area        |             |
C   |         (square)          |             |
C   |                           |             |
C   |                           |             |
C   |                           |-------------|
C   |                           |             |
C   |                           |    echo     |
C   |                           |             |
C   -------------------------------------------

C  COMMON DIALOG variables
C  -----------------------
C  DOUTYP* : method of sending interactive output to operator:
C            1-Fortran print, 2-PHIGS <message>, 3-PHIGS <text>.
C  DINTYP* : method of receiving interactive input from operator:
C            1-Fortran read, 2-PHIGS <request string>.
C  DSTDNR* : Logical device number for request string
C  DSTRID  : Identifier of structure for interactive dialogue
C  PSTRID  : Identifier of structure for interactive picture
C  DTCLIM* : Maximum number of characters per line for interactive prompt
C  SCRMOD* : Screen mode for operator interaction: 0-interaction off-screen,
C            1-dialogue at bottom, 2-dialogue at right, 3-toggle dialogue
C            and picture on full screen.
C  DTXCI   : Dialogue text color index
C  SPECWT  : Specific workstation type in which dialogue takes place
C  DSIZE*  : For split screen, size of dialogue area as fraction of
C            full screen
C  EFRAC*  : Fraction of dialogue area for echo, if DINTYP=2 and DOUTYP=3
C  DYXRAT  : Ratio of height to width of prompt area within dialogue area
C  SYXRAT  : Ratio of height to width of full screen
C  MTRPDC* : Absolute size of DC units = meters per DC unit
C  WCPDC   : WC units per DC unit for view #1 (picture)
C  QVIS    : Minimum distance assumed to be visually distinguishable,
C            in DC units
C  *initialized by INITGL

      COMMON /SCRFMT/ PICL,PICR,PICB,PICT, PRTL,PRTR,PRTB,PRTT,
     1                ECHL,ECHR,ECHB,ECHT
      REAL            PICL,PICR,PICB,PICT, PRTL,PRTR,PRTB,PRTT,
     1                ECHL,ECHR,ECHB,ECHT

C  COMMON SCRFMT (screen format) variables
C  -----------------------
C  PICL,PICR,PICB,PICT : NPC bounds of picture area
C  PRTL,PRTR,PRTB,PRTT : NPC bounds of prompt area
C  ECHL,ECHR,ECHB,ECHT : DC bounds of echo area

C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)

C viewtype
      INTEGER    PPARL,     PPERS
      PARAMETER (PPARL = 0, PPERS = 1)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

C device coordinate units
      INTEGER    PMETRE,     POTHU
      PARAMETER (PMETRE = 0, POTHU = 1)
C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C colour available
C                monochrome  color
      INTEGER    PMONOC,     PCOLOR
      PARAMETER (PMONOC = 0, PCOLOR = 1)

      INTEGER    SPECON, DCUN, ADMAXX,ADMAXY
      INTEGER    IA(2), IL, LDR, WNSIZ, PICSTR, DLGSTR, TXCI
      INTEGER    NUMCOL, COLAVL, IX
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM8

      REAL       DCMAXX,DCMAXY, VORMAT(4,4), VMPMAT(4,4)
      REAL       Z,U, RA(2), VWCPLM(6), WNLM(4), SCRX,SCRY, SCRMIN
      REAL       RGBV(3,0:4), RDUM(9)
      PARAMETER (Z=0.0, U=1.0)

      INTEGER    MLDR
      PARAMETER (MLDR = 10)
      CHARACTER  MSG*300, SA(2)*80, DATREC(MLDR)*80

CUSERMOD  default color initialization
C                 black        bluish-green pale-yellow
C                 sky-blue     white
      DATA RGBV / 0.0,0.0,0.0, 0.0,1.0,0.3, 1.0,1.0,0.3,
     1            0.3,1.0,1.0, 1.0,1.0,1.0 /

C open workstation
      CALL POPWK (WKID, CONID, WTYPE)

C save parameters in DIALOG common
      PSTRID = PICSTR
      DSTRID = DLGSTR
      DTXCI  = ABS(TXCI)

C  SETDLG sets up views for picture and prompt as follows:
C
C       PICTURE (view #1)      PROMPT (view #2)       FULL SCREEN (view #3)
C       x-bounds   y-bounds    x-bounds   y-bounds    x-bounds   y-bounds
C       --------   --------    --------   --------    --------   --------
C  WC   0-1        0-1         0-1        0-DYXRAT    0-1        0-SYXRAT
C  NPC  PICL-PICR  PICB-PICT   PRTL-PRTR  PRTB-PRTT   0-SCRX     0-SCRY

      CALL PSDUS  (WKID, PWAITD, PNIVE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
      CALL PQDSP  (SPECWT, ERRIND, DCUN, DCMAXX,DCMAXY, ADMAXX,ADMAXY)
      CALL CHKINQ ('pqdsp', ERRIND)

C make half-hearted attempt to set up colors 0,1,2,3,4
      IF (TXCI .LT. 0) GOTO 60
      CALL PQCF  (SPECWT, ERRIND, IDUM1, COLAVL, IDUM2, RDUM)
      CALL CHKINQ ('pqcf', ERRIND)
      IF (COLAVL .NE. PCOLOR) GOTO 60

      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             NUMCOL,IDUM8)
      CALL CHKINQ ('pqwksl', ERRIND)
      CALL PSCMD (WKID, PRGB)
      DO 50 IX = 0, MIN(4, NUMCOL-1)
         CALL PSCR  (WKID, IX, 3, RGBV(1, IX))
50    CONTINUE
60    CONTINUE

C set up workstation transformation to use full screen
      SYXRAT = DCMAXY/DCMAXX
      IF (SYXRAT .GT. U) THEN
C tall screen
         SCRY = U
         SCRX = 1/SYXRAT
      ELSE
C wide screen
         SCRY = SYXRAT
         SCRX = U
      ENDIF
C NPC
      CALL PSWKW (WKID, Z, SCRX, Z, SCRY)
C DC
      CALL PSWKV (WKID, Z, DCMAXX, Z, DCMAXY)

C default NPC values for picture area = largest square in screen.
      SCRMIN = MIN(SCRX,SCRY)
      PICL = Z
      PICR = SCRMIN
      PICB = Z
      PICT = SCRMIN

C default NPC values for prompt area = whole screen.
      PRTL = Z
      PRTR = SCRX
      PRTB = Z
      PRTT = SCRY

      IF (SCRMOD .EQ. 1) THEN
C  dialogue at bottom
         PRTT = DSIZE * SCRY
         PICB = PRTT
         PICR = MIN (SCRY-PICB, SCRX)
         PICT = PICB + PICR
      ELSEIF (SCRMOD .EQ. 2) THEN
C  dialogue at right
         PRTL = (1-DSIZE) * SCRX
         PICT = MIN (PRTL, SCRY)
         PICR = PICT
      ELSE
C        SCRMOD .EQ. 0 or 3 - OK as is
      ENDIF

C  break up dialogue area into prompt/echo areas
      ECHL = PRTL
      ECHR = PRTR
      ECHB = PRTB
      ECHT = EFRAC * (PRTT-PRTB) + PRTB
      PRTB = ECHT

C ratio of height of prompt area to its width - allows constant
C width of 1.0
      DYXRAT = (PRTT-PRTB) / (PRTR-PRTL)

C set up view #1 for picture
      CALL PEVOM3 (Z,Z,Z, Z,Z,U, Z,U,Z, ERRIND, VORMAT)
      CALL CHKINQ ('pevom3', ERRIND)
      CALL SETRVS ('0,1,0,1', WNLM, WNSIZ)
      VWCPLM(1) = PICL
      VWCPLM(2) = PICR
      VWCPLM(3) = PICB
      VWCPLM(4) = PICT
      VWCPLM(5) = Z
      VWCPLM(6) = U
      CALL PEVMM3 (WNLM, VWCPLM, PPARL, .5,.5,2.0, Z,Z,U,
     1             ERRIND, VMPMAT)
      CALL CHKINQ ('pevmm3', ERRIND)
      CALL PSVWR3 (WKID, 1, VORMAT,VMPMAT, VWCPLM,
     1             PNCLIP,PNCLIP,PNCLIP)

C set up view #2 for prompt
      WNLM(4) = DYXRAT
      VWCPLM(1) = PRTL
      VWCPLM(2) = PRTR
      VWCPLM(3) = PRTB
      VWCPLM(4) = PRTT
      CALL PEVMM3 (WNLM, VWCPLM, PPARL, .5,DYXRAT/2,U, Z,Z,U,
     1             ERRIND, VMPMAT)
      CALL CHKINQ ('pevmm3', ERRIND)
      CALL PSVWR3 (WKID, 2, VORMAT,VMPMAT, VWCPLM,
     1             PNCLIP,PNCLIP,PNCLIP)

C set up view #3 for full screen
      WNLM(4) = SYXRAT
      VWCPLM(1) = 0.
      VWCPLM(2) = SCRX
      VWCPLM(3) = 0.
      VWCPLM(4) = SCRY
      CALL PEVMM3 (WNLM, VWCPLM, PPARL, .5,SYXRAT/2,U, Z,Z,U,
     1             ERRIND, VMPMAT)
      CALL CHKINQ ('pevmm3', ERRIND)
      CALL PSVWR3 (WKID, 3, VORMAT,VMPMAT, VWCPLM,
     1             PNCLIP,PNCLIP,PNCLIP)

300   CONTINUE
      IF (DINTYP .EQ. 1) THEN
C  input via READ: skip initialization of string device.
         GOTO 600
      ELSEIF (DINTYP .NE. 2) THEN
         WRITE (MSG, '(A,I5)') 'Invalid input type in SETDLG: ', DINTYP
         CALL UNMSG (MSG)
      ENDIF

C Input to be done via request-string: convert NPC values for
C echo area to DC
      ECHL = DCMAXX * ECHL/SCRX
      ECHR = DCMAXX * ECHR/SCRX
      ECHB = DCMAXY * ECHB/SCRY
      ECHT = DCMAXY * ECHT/SCRY

C  pack data record with 72,1, signifying buffer size and edit position
      CALL SETVS ('72,1', IA, IL)

      CALL PPREC (IL,IA, 0,RA, 0,IA,SA, MLDR, ERRIND, LDR,DATREC)
      CALL CHKINQ ('pprec', ERRIND)
C initialize string device
      CALL PINST (WKID, DSTDNR, 1, ' ', 1, ECHL,ECHR,ECHB,ECHT,
     1            LDR,DATREC)

600   CONTINUE
C  compute WC per DC within picture area
      WCPDC = SCRX / (DCMAXX * (PICR-PICL) )

C  set "quantum" of visual distinguishability to 2.0 mm, in DC units
      QVIS = 0.002 / MTRPDC

      END
