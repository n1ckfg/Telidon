C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.06/03                           *
C  *    TEST TITLE : Appearance of fill area set interiors *
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
 
C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)
 
C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)
 
C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
      INTEGER    PICSTR, TXCI, IX,IY, NUMLIN, PERM(20), NTURNS, PPTURN
      INTEGER    NPTS, COLIA(2,2), RAN6(6), INTSTY, NGSQ, ENDPTS(10)
      INTEGER    THIS, ANS, IPAT, SIZ, ISI, THISIS, NUMHS, HS(20), IHAT
      INTEGER    I1,I2,I3,I4, XLO(20),XHI(20),YLO(20),YHI(20)
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4

      REAL       XT(10),YT(10),ZT(10), CFRAC
      REAL       XA(101),YA(101),ZA(101), ANG,RAD1,RAD2
      REAL       XB(101),YB(101),ZB(101), YTOP,YINCR,YLOC, RADBAS,RADINC
      REAL       XSIZ,YSIZ, XWINLO(6),YWINLO(6), XF(3,3),Z,H,U, PI
      PARAMETER (Z = 0.0, H = 0.5, U = 1.0, PI = 3.14159265)
 
      LOGICAL    INSTAV(PSOLID:PHATCH), FILLOK
 
      CHARACTER  INSTNM(PSOLID:PHATCH)*7
 
      DATA INSTAV / 3 * .FALSE. /
      DATA INSTNM / 'solid', 'pattern', 'hatch' /
 
      CALL INITGL ('04.01.06/03')
 
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
C  default attributes
      CALL PSEDFG (POFF)
      CALL PEXST (106)
      CALL PEXST (102)
      CALL PCLST
 
C  determine if solid, hatch, pattern interior style is supported:
      FILLOK = .FALSE.
      CALL PQIF (SPECWT,0,0,ERRIND, SIZ, IDUM1,NUMHS,IDUM2,IDUM3)
      CALL CHKINQ ('pqif', ERRIND)
C get interior styles
      DO 50 ISI = 1, SIZ
         CALL PQIF (SPECWT, ISI,0,ERRIND, IDUM1, THISIS,
     1              IDUM2, IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS .GE. PSOLID .AND. THISIS .LE. PHATCH) THEN
C mark which interior styles are available
            INSTAV(THISIS) = .TRUE.
            FILLOK = .TRUE.
         ENDIF
50    CONTINUE
 
      IF (.NOT. FILLOK) THEN
         CALL INMSG ('Skipping all tests because no ' //
     1               'interior-filling style is available.')
         GOTO 666
      ENDIF
 
      IF (INSTAV(PHATCH)) THEN
C  get a dense hatch style from 10 random ones
         CALL POPST (102)
         NUMLIN = MIN(10, ABS(NUMHS))
         CALL RNSET (NUMLIN, ABS(NUMHS), PERM)
         YINCR = 1 / (NUMLIN+1.0)
         YTOP  = 1 - YINCR
         YLOC = YTOP
         CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
         CALL PSIS (PHATCH)
         XA(1) = 0.2
         XA(2) = 0.9
         XA(3) = 0.9
         XA(4) = 0.2
         ENDPTS(1) = 4
         DO 60 IX = 1,NUMLIN
            YA(1) = YLOC + 0.4*YINCR
            YA(2) = YLOC + 0.4*YINCR
            YA(3) = YLOC - 0.4*YINCR
            YA(4) = YLOC - 0.4*YINCR
            CALL PQIF (SPECWT,0,PERM(IX), ERRIND,
     1                 IDUM1,IDUM2,IDUM3,HS(IX),IDUM4)
            CALL CHKINQ ('pqif', ERRIND)
            CALL PSISI (HS(IX))
            CALL PFAS (1, ENDPTS, XA,YA)
            YLOC = YLOC-YINCR
60       CONTINUE
 
         CALL DCHOIC ('Pick a dense hatch style, preferably diagonal.',
     1                1, NUMLIN, ANS)
         CALL PEMST (102)
         CALL PCLST
         IHAT = HS(ANS)
      ENDIF
 
      IF (INSTAV(PPATTR)) THEN
C  define pattern #ipat as simple checkerboard pattern
         IPAT = 1
         CALL SETVAL ('0,1,1,0', COLIA)
         CALL PSPAR (WKID,IPAT, 2,2, 1,1, 2,2, COLIA)
         CALL PSPA (.02,.02)
      ENDIF
 
C  set up structure 106 to label 6 windows
      CALL WIN6 (106, 2, XSIZ,YSIZ, XWINLO, YWINLO)
      CALL POPST (102)
 
C  *** *** ***   interior of self-overlapping fill area set *** *** ***
 
      FILLOK = .TRUE.
 
C  coordinates for overlapping fill area set
      CALL SETRVS ('.05,.05,.75,.75,.15,.15,.60,.60,'//
     1             '.25,.25,.85,.85,.40,.40,.95,.95', XA, NPTS)
      CALL SETRVS ('.25,.95,.95,.40,.40,.85,.85,.25,'//
     1             '.05,.60,.60,.15,.15,.75,.75,.05', YA, NPTS)
      DO 70 IX = 1,NPTS
         ZA(IX) = 0.5*XA(IX) + 0.5*YA(IX)
         IY = NPTS+1-IX
         XB(IY) = XA(IX)
         YB(IY) = YA(IX)
         ZB(IY) = ZA(IX)
70    CONTINUE
 
      ENDPTS(1) = 8
      ENDPTS(2) = 16
 
      DO 100 INTSTY = PSOLID,PHATCH
C  for each available intsty = SOLID, HATCH, PATTERN
         IF (.NOT. INSTAV(INTSTY)) GOTO 100
 
C  ran6 = random order for 1-6
         CALL RNPERM (6,RAN6)
         CALL PSIS (INTSTY)
         IF (INTSTY .EQ. PHATCH) THEN
            CALL PSISI (IHAT)
         ELSEIF (INTSTY .EQ. PPATTR) THEN
            CALL PSISI (IPAT)
         ENDIF
 
         DO 110 IX = 1,6
            THIS = RAN6(IX)
C  scale 0:1,0:1 into window #ix
            CALL EBLTM (Z,Z, XWINLO(IX), YWINLO(IX), Z, XSIZ,XSIZ, XF)
            CALL PSLMT (XF, PCREPL)
 
            IF (THIS .EQ. 1) THEN
C   1 - simulate the figure, filling in the wrong interiors
               NGSQ = IX
               CALL SETVS ('1,6, 7,5,  9, 9,12, 4, 14,10,10, 7',XLO,SIZ)
               CALL SETVS ('6,3, 3,9, 13,16,15,11,  3,13, 8, 4',XHI,SIZ)
               CALL SETVS ('1,6, 7,5,  1, 9,12,14, 14,10, 5,10',YLO,SIZ)
               CALL SETVS ('2,3,15,1, 13,13,15,11, 10, 5, 8, 4',YHI,SIZ)
               DO 120 IY = 1,SIZ
                  CALL FILREC (XLO(IY),XHI(IY),YLO(IY),YHI(IY), XA,YA)
120            CONTINUE
 
            ELSEIF (THIS .EQ. 2) THEN
C   2 - simulate the figure, filled correctly
               CALL SETVS ('1,6, 7,5,  9, 9,12, 4, 14,10,13, 7',XLO,SIZ)
               CALL SETVS ('6,3, 3,9, 13,16,15,11,  7,13, 8, 4',XHI,SIZ)
               CALL SETVS ('1,6, 7,5,  1, 9,12,14, 14,10, 5,10',YLO,SIZ)
               CALL SETVS ('2,3,15,1, 13,13,15,11, 10, 5, 8, 4',YHI,SIZ)
               DO 130 IY = 1,SIZ
                  CALL FILREC (XLO(IY),XHI(IY),YLO(IY),YHI(IY), XA,YA)
130            CONTINUE
 
            ELSEIF (THIS .EQ. 3) THEN
C   3 - generate the overlapping 3D fill area set
               CALL PFAS3 (2, ENDPTS, XA,YA,ZA)
            ELSEIF (THIS .EQ. 4) THEN
C   4 - generate the overlapping 3D fill area set,
C       reverse order of point list
               CALL PFAS3 (2, ENDPTS, XB,YB,ZB)
            ELSEIF (THIS .EQ. 5) THEN
C   5 - generate the overlapping 2D fill area set
               CALL PFAS (2, ENDPTS, XA,YA)
            ELSEIF (THIS .EQ. 6) THEN
C   6 - generate the overlapping 2D fill area set,
C       reverse order of point list
               CALL PFAS (2, ENDPTS, XB,YB)
            ENDIF
C  next ix
110      CONTINUE
         CALL DCHOIC ('INTERIOR OF SELF-OVERLAPPING FILL AREA SETS: ' //
     1                'Which figure is different?', 0,6, ANS)
         CALL PEMST (102)
 
         IF (ANS .EQ. NGSQ) THEN
C           OK so far
         ELSE
            IF (ANS .EQ. 0) CALL OPCOFL
            FILLOK = .FALSE.
            CALL INMSG ('Overlap failed on interior style = ' //
     1                  INSTNM(INTSTY))
         ENDIF
 
C  next intsty
100   CONTINUE
 
      CALL SETMSG ('1 4 7 8', 'The interiors of a self-overlapping ' //
     1             'fill area set should be filled correctly.')
      CALL IFPF (FILLOK)
 
C  *** *** ***   interior of concave fill area set  *** *** ***
 
      FILLOK = .TRUE.
 
C  number of turns and points per turn
      NTURNS = 3
      PPTURN = 10
      NPTS = 2*NTURNS*PPTURN
      RADBAS = 0.08
      RADINC = (0.98 - H - RADBAS) / (NTURNS + H)
C  coordinates for spiral fill area
      DO 150 IX = 1,NPTS/2
         CFRAC = REAL(IX) / PPTURN
         ANG = PI * (2*CFRAC + 0.25)
         RAD1 = RADBAS + CFRAC * RADINC
         RAD2 = RAD1 + RADINC/2
         IY = NPTS + 1 - IX
         XA(IX) = H + RAD1 * COS(ANG)
         YA(IX) = H + RAD1 * SIN(ANG)
         ZA(IX) = 0.5*XA(IX) + 0.5*YA(IX)
         XA(IY) = H + RAD2 * COS(ANG)
         YA(IY) = H + RAD2 * SIN(ANG)
         ZA(IY) = 0.5*XA(IY) + 0.5*YA(IY)
150   CONTINUE
 
      DO 160 IX = 1,NPTS
         IY = NPTS + 1 - IX
         XB(IY) = XA(IX)
         YB(IY) = YA(IX)
         ZB(IY) = ZA(IX)
160   CONTINUE
 
      DO 200 INTSTY = PSOLID,PHATCH
C  for each available intsty = SOLID, HATCH, PATTERN
         IF (.NOT. INSTAV(INTSTY)) GOTO 200
 
C  ran6 = random order for 1-6
         CALL RNPERM (6,RAN6)
         CALL PSIS (INTSTY)
         IF (INTSTY .EQ. PHATCH) THEN
            CALL PSISI (IHAT)
         ELSEIF (INTSTY .EQ. PPATTR) THEN
            CALL PSISI (IPAT)
         ENDIF
 
         DO 210 IX = 1,6
            THIS = RAN6(IX)
C  scale 0:1,0:1 into window #ix
            CALL EBLTM (Z,Z, XWINLO(IX), YWINLO(IX), Z, XSIZ,XSIZ, XF)
            CALL PSLMT (XF, PCREPL)
 
            IF (THIS.EQ.1 .OR. THIS.EQ.2) THEN
C  simulate the figure, filled correctly
               DO 220 IY = 1, NPTS/2 - 1
                  I1 = IY
                  I2 = IY+1
                  I3 = NPTS-IY
                  I4 = I3+1
                  XT(1) = XA(I1)
                  XT(2) = XA(I2)
                  XT(3) = XA(I3)
                  XT(4) = XA(I4)
                  YT(1) = YA(I1)
                  YT(2) = YA(I2)
                  YT(3) = YA(I3)
                  YT(4) = YA(I4)
                  ENDPTS(1) = 4
                  CALL PFAS (1, ENDPTS, XT,YT)
220            CONTINUE
               IF (THIS .EQ. 1) THEN
C  mark as incorrect, and muck up
                  NGSQ = IX
                  CALL ARCPTS (PPTURN, H,H, 2*RADBAS, Z, 2*PI/PPTURN,
     1                         XT,YT,ZT)
                  ENDPTS(1) = PPTURN
                  CALL PFAS (1, ENDPTS, XT,YT)
               ENDIF
            ELSEIF (THIS .EQ. 3) THEN
C  3 - generate the spiral 3D fill area set
               ENDPTS(1) = NPTS
               CALL PFAS3 (1, ENDPTS, XA,YA,ZA)
            ELSEIF (THIS .EQ. 4) THEN
C  4 - generate the spiral 3D fill area set,
C      reverse order of point list
               ENDPTS(1) = NPTS
               CALL PFAS3 (1, ENDPTS, XB,YB,ZB)
            ELSEIF (THIS .EQ. 5) THEN
C  5 - generate the spiral 2D fill area set
               ENDPTS(1) = NPTS
               CALL PFAS (1, ENDPTS, XA,YA)
            ELSEIF (THIS .EQ. 6) THEN
C  6 - generate the spiral 2D fill area set,
C      reverse order of point list
               ENDPTS(1) = NPTS
               CALL PFAS (1, ENDPTS, XB,YB)
            ENDIF
C     next ix
210      CONTINUE
 
         CALL DCHOIC ('INTERIOR OF CONCAVE FILL AREA SETS: ' //
     1                'Which figure is different?', 0,6, ANS)
         CALL PEMST (102)
 
         IF (ANS .EQ. NGSQ) THEN
C           OK so far
         ELSE
            IF (ANS .EQ. 0) CALL OPCOFL
            FILLOK = .FALSE.
            CALL INMSG ('Concave failed on interior style = ' //
     1                  INSTNM(INTSTY))
         ENDIF
C  next intsty
200   CONTINUE
 
      CALL SETMSG ('1 4 7 8', 'The interiors of a concave spiral ' //
     1             'fill area set should be filled correctly.')
      CALL IFPF (FILLOK)
 
C  end_it_all:
666   CONTINUE
      CALL ENDIT
      END
