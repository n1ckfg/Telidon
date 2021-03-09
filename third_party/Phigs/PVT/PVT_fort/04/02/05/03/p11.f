C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/11                        *
C  *    TEST TITLE : Edge bundle index                     *
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
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

      INTEGER    MAXET, PICSTR, TXCI, IX, NPTS(1), RNDINT
      INTEGER    NUMET, LAET(10), ALTET, SWITCH, SZBT, NUMBUN
      INTEGER    BUNDIS(10), BUNDIF, EXPLCT, BUNEL, UNDF(3), PERM(10)
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

      REAL       XA(41), YA(41), YLOC, YINCR, RAD, CENTX, CENTY, PI
      REAL       RDUM1, RDUM2, RDUM3

      CALL INITGL ('04.02.05.03/11')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)

C  use bundled attributes
      CALL SETASF (PBUNDL)
C  set interior style attribute ASFs to INDIVIDUAL
C  set interior style = EMPTY, interior color index = 1
      CALL PSIASF (PIS, PINDIV)
      CALL PSIASF (PICI, PINDIV)
      CALL PSIS (PISEMP)
      CALL PSICI (1)

C  szbt   = maximum size of edge bundle table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             SZBT, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C  numet = number of available edgetypes
C  laet  = list of available edgetypes
      CALL PQEDF (SPECWT, 0, ERRIND, NUMET, IDUM1, IDUM2, RDUM1, RDUM2,
     1            RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)

C  ten is more than enough - limit to list size
      MAXET = MIN (10, ABS(NUMET))

      DO 50 IX=1, MAXET
         CALL PQEDF (SPECWT, IX, ERRIND, IDUM1, LAET(IX), IDUM2, RDUM1,
     1               RDUM2, RDUM3, IDUM3)
         CALL CHKINQ ('pqedf', ERRIND)
50    CONTINUE

C  sort laet
      CALL SRTIAR (MAXET, LAET)

C  *** *** ***   edge index   *** *** ***

C  mark start of edge bundles
      CALL PLB (1)

      CALL SETMSG ('3 4 5 6', 'A defined edge index should cause '  //
     1             'the addressed entry in the bundle table to be ' //
     2             'used when rendering a edge.')

C  numbun = number of bundles to be displayed = min(8, szbt)
      NUMBUN = MIN (8, SZBT)

C  initialize all of bundis
      DO 60 IX = 1, NUMBUN
         CALL PSEDR (WKID, IX, PON, 1, 1.0, 1)
         BUNDIS(IX) = IX
60    CONTINUE

C  altet  = alternative edgetype
C  switch = switch edge flag ON or OFF
      IF (MAXET .GT. 1) THEN
         ALTET  = LAET(2)
         SWITCH = PON
      ELSE
         ALTET  = LAET(1)
         SWITCH = POFF
      ENDIF

C  bundif = randomly selected bundle from BUNDIS
      BUNDIF = RNDINT (1, NUMBUN)

C  set edge represent bundif
      CALL PSEDR (WKID, BUNDIF, SWITCH, ALTET, 2.0, 2)

C  Display and label triangles with edges for each bundle in bundis
      CALL DRBUED (NUMBUN, BUNDIS)

C  mark end of edgetype
      CALL PLB (2)
      CALL DCHPFV ('DEFINED EDGE INDICES: which triangle is ' //
     1             'different?', NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 5 7', 'An undefined edge index should cause ' //
     1             'bundle number 1 in the edge bundle table to be '  //
     2             'used when rendering an edge.')

C  set index #1 in bundle table
      CALL PSEDR (WKID, 1, PON, ALTET, 2.0, 2)

C  u1,u2,u3 = 3 undefined, positive indices
      UNDF(1) = SZBT + 1
      UNDF(2) = SZBT + 10
      UNDF(3) = SZBT + 90

C  explct = number of explicit edges
      EXPLCT = RNDINT (0, 4)
      NUMBUN = EXPLCT + 3
      CALL RNPERM (NUMBUN, PERM)

C  draw star with bundle index 1
      RAD = 0.15
      CENTX = .5
      CENTY = .75
      PI = 3.14159265
      DO 400 IX = 1, 5
          YA(IX) = CENTY + RAD * COS((4*PI*IX)/5)
          XA(IX) = CENTX + RAD * SIN((4*PI*IX)/5)
400   CONTINUE
      CALL PSEDI (1)
      NPTS(1) = 5
      CALL PFAS (1,NPTS, XA, YA)

C  display interleaved:
      YLOC = 0.5
      YINCR = 0.5/8
      XA(1) = 0.3
      XA(2) = 0.3
      XA(3) = 0.7
      NPTS(1) = 3
      DO 500 IX = 1, NUMBUN
        BUNEL = PERM(IX)
        IF (BUNEL .LE. 3) THEN
            CALL PSEDI (UNDF(BUNEL))
        ELSE
            CALL PSEDI (1)
        ENDIF
        YA(1) = YLOC - 0.25*YINCR
        YA(2) = YLOC + 0.25*YINCR
        YA(3) = YLOC - 0.25*YINCR
        CALL PFAS (1, NPTS, XA, YA)
        YLOC = YLOC - YINCR
500   CONTINUE

      CALL DCHPFV ('UNDEFINED EDGE INDICES: How many of the '   //
     1            'triangles have the same edge attributes as ' //
     2            'the star?', 12, NUMBUN)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
