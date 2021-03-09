C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/06                        *
C  *    TEST TITLE : Colour or monochrome                  *
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

C colour:        monochrome  colour
      INTEGER    PMONOC,     PCOLOR
      PARAMETER (PMONOC = 0, PCOLOR = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

      INTEGER     NCOLI, COLA, PICSTR, TXCI, IX, COLIX, OPANS, HUECT
      INTEGER     IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7

      REAL        CLRS(3,6), COLARY(3), CC(9)

      LOGICAL     FILMOD, NEWHUE(6), INTSTY

      DATA  NEWHUE / 6 * .TRUE. /

C Red
      CLRS(1,1)  =  1.
      CLRS(2,1)  =  0.
      CLRS(3,1)  =  0.
C Yellow
      CLRS(1,2)  =  1.
      CLRS(2,2)  =  1.
      CLRS(3,2)  =  0.
C Green
      CLRS(1,3)  =  0.
      CLRS(2,3)  =  1.
      CLRS(3,3)  =  0.
C Cyan
      CLRS(1,4)  =  0.
      CLRS(2,4)  =  1.
      CLRS(3,4)  =  1.
C Blue
      CLRS(1,5)  =  0.
      CLRS(2,5)  =  0.
      CLRS(3,5)  =  1.
C Magenta
      CLRS(1,6)  =  1.
      CLRS(2,6)  =  0.
      CLRS(3,6)  =  1.

      CALL INITGL ('04.03.02.02/06')

C open PHIGS
      CALL XPOPPH (6, MEMUN)
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
      CALL POPST (102)

C  Set Color Model to RGB
      CALL PSCMD (WKID, PRGB)

C  Check to see that color is available
C    cola = colour or monochrome
C    ncoli = number of colours available
      CALL PQCF (SPECWT, ERRIND, IDUM1, COLA, IDUM2, CC)
      CALL CHKINQ ('pqcf', ERRIND)

      IF (COLA .EQ. PCOLOR) THEN
         CALL SETMSG ('4 5 21 22 26 27 33', 'A workstation ' //
     1                'reported as capable of colour should ' //
     2                'be able to display more than one hue.')
      ELSEIF (COLA .EQ. PMONOC) THEN
         CALL SETMSG ('4 6 21 22 26 27 33', 'A workstation ' //
     1                'reported as capable of monochrome '  //
     2                'should be able to display at most one hue.')
      ELSE
         CALL INMSG('Non-standard code for colour available; ' //
     1              'skipping test.')
         GOTO 666
      ENDIF

C maximum number of colour bundle table entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, NCOLI, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (NCOLI .GT. 2) THEN
C Use index #2, unless only 0 and 1 are available:
         COLIX = 2
      ELSE
         COLIX = 1
      ENDIF

C  Determine how to fill in rectangles, use solid style
C  if it is available, otherwise use dense polyline cross-hatch
      FILMOD = INTSTY (SPECWT, PSOLID)

C  *** *** *** ***   Test COLOR Model   *** *** *** ***

C  count up distinct hues
      HUECT = 0
      DO 110 IX = 1,6
         COLARY(1) = CLRS (1,IX)
         COLARY(2) = CLRS (2,IX)
         COLARY(3) = CLRS (3,IX)
         CALL PSCR (WKID, COLIX, 3, COLARY)
         CALL COLPCH (FILMOD, COLIX, 0.3,0.3, 0.7,0.7)
         CALL DCHOIC ('HUE DISCRIMINATION FOR AVAILABLE COLOUR: ' //
     1                'The color of the square patch is best '    //
     1                'described as: 1-red, 2-yellow, '           //
     1                '3-green, 4-cyan, 5-blue, 6-magenta, '      //
     1                '7-white, 8-gray, or 9-black?', 0,9,OPANS)

C   opans = operator response
         IF ( OPANS .EQ. 0 ) THEN
            CALL OPFAIL
            GOTO 666
         ELSEIF ( OPANS .LT. 7 ) THEN
            IF (NEWHUE(OPANS)) THEN
               HUECT = HUECT+1
               IF (HUECT.GT.1) GOTO 210
               NEWHUE(OPANS) = .FALSE.
            ENDIF
         ELSE
C           not a hue - do nothing
         ENDIF
110   CONTINUE

210   CONTINUE

      IF (COLA .EQ. PCOLOR) THEN
C  pass/fail depending on (response = expected subset)
          CALL IFPF (HUECT .GT. 1)
      ELSE
          CALL IFPF (HUECT .LE. 1)
      ENDIF

666   CONTINUE
C  wrap it up.
      CALL ENDIT

      END
