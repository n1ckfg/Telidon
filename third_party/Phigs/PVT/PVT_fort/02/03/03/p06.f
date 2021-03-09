C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.03/06                           *
C  *    TEST TITLE : Modelling transformation and clipping *
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
 
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
 
C modelling clipping operator
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)
 
C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
      INTEGER     IPTHSZ
      PARAMETER  (IPTHSZ = 20)
 
      INTEGER     M1LEN,M2LEN, PMLEN, STPATH(2,5), IDUM1, IDUM(2)
      INTEGER     FPTHSZ,FPATH(2,IPTHSZ), EXLEN,EXPATH(2,IPTHSZ)
      INTEGER     FALEN
 
      REAL        M1(4,4), M2(4,4), PMLOCX(5), PMLOCY(5), PMLOCZ(5)
      REAL        FALOCX(10), FALOCY(10), FALOCZ(10), TX,TY,TZ
      REAL        TPLOCX(10), TPLOCY(10), TPLOCZ(10), RDUM
      REAL        MCOMP(4,4), EXLOCX,EXLOCY,EXLOCZ, SDIST, PTREGD
      REAL        SRPX,SRPY,SRPZ, HALFSP(6,10), NVECX,NVECY,NVECZ
      REAL        CLPTX,CLPTY,CLPTZ, CLVCX,CLVCY,CLVCZ
      REAL        DVECX,DVECY,DVECZ, NVECL, VECL
 
      LOGICAL     IAREQL, SPHDIS
 
      CALL INITGL ('02.03.03/06')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      IF (.NOT. SPHDIS(123)) THEN
         CALL INMSG ('Skipping test because implementation '     //
     1               'apparently uses non-Euclidean metric for ' //
     2               'search distance.')
         GOTO 666
      ENDIF
 
C  m1 = random transformation matrix
C     =   1.43  -2.41  3.25 -1.15
C        -3.25  -3.13  2.54 -1.35
C        -2.43  -1.54  2.31  1.42
C         3.51  -2.32  2.41  3.25
 
      CALL SETRVS (' 1.43,  -3.25, -2.43,  3.51,  ' //
     1             '-2.41,  -3.13, -1.54, -2.32,  ' //
     2             ' 3.25,   2.54,  2.31,  2.41,  ' //
     3             '-1.15,  -1.35,  1.42,  3.25', M1, M1LEN)
 
C  m2 = random transformation matrix
C     =   -1.23   1.23  -1.02   9.30
C          1.28  -9.34   0.93  -4.89
C          2.03   9.85   4.01  -9.23
C          4.18  -0.12  -9.34   8.01
 
      CALL SETRVS ( '-1.23,  1.28,  2.03,  4.18, ' //
     1              ' 1.23, -9.34,  9.85, -0.12, ' //
     2              '-1.02,  0.93,  4.01, -9.34, ' //
     3              ' 9.30, -4.89, -9.23,  8.01', M2, M2LEN)
 
C  *** *** *** ***   Modelling transformations   *** *** *** ***
C
C  set up structure #101:
C  1. set local transformation = m1
C  2. execute structure 102
      CALL POPST  (101)
      CALL PSLMT3 (M1, PCREPL)
      CALL PEXST  (102)
      CALL PCLST
 
C  pmloc = polymarker location = -6.347, 4.637, 1.082
      PMLOCX(1) = -6.347
      PMLOCY(1) =  4.637
      PMLOCZ(1) =  1.082
 
C  set up structure #102:
C  1. set global transformation = m2
C  2. polymarker at pmloc
      CALL POPST  (102)
      CALL PSGMT3 (M2)
      CALL PPM3   (1, PMLOCX, PMLOCY, PMLOCZ)
      CALL PCLST
 
C  exloc = expected WC location = m2 X m1 X pmloc
      CALL ECOM3 (M2,M1, MCOMP)
      CALL ETP3  (PMLOCX(1),PMLOCY(1),PMLOCZ(1), MCOMP,
     1            EXLOCX,EXLOCY,EXLOCZ)
 
      SDIST = 0.1
      SRPX = EXLOCX + SDIST
      SRPY = EXLOCY
      SRPZ = EXLOCZ
 
      CALL SETMSG ('2 3 4 5 6 8 10', 'ISS should detect a primitive ' //
     1             'according to its location in world coordinates, ' //
     2             'computed with the current composite modelling '   //
     3             'transformation, including the effect of '         //
     4             'inherited transformations.')
 
C  ISS twice with SRP, varying search distance
C    starting path:  101,1, 102,1
C    search ceiling: 2
C    expected path:  101,1, 102,2
 
      CALL ISSAB (SRPX,SRPY,SRPZ, SDIST, '101,1, 102,1', PNCLIP, 2,
     1            '101,1, 102,2')
 
C  exloc = expected WC location = m2 X pmloc
      CALL ETP3  (PMLOCX(1),PMLOCY(1),PMLOCZ(1), M2,
     1            EXLOCX,EXLOCY,EXLOCZ)
 
      SDIST = 0.1
      SRPX = EXLOCX + SDIST
      SRPY = EXLOCY
      SRPZ = EXLOCZ
 
      CALL SETMSG ('2 3 4 5 6 10', 'ISS should detect a primitive '   //
     1             'according to its location in world coordinates, ' //
     2             'computed with the current composite modelling '   //
     3             'transformation when there are no inherited '      //
     4             'transformations.')
 
C  ISS twice with SRP, varying search distance
C    starting path:  102,1
C    search ceiling: 1
C    expected path:  102,2
 
      CALL ISSAB (SRPX,SRPY,SRPZ, SDIST, '102,1', PNCLIP, 1, '102,2')
 
C  *** *** *** ***   Modelling clipping   *** *** *** ***
C
C  clear CSS
      CALL PDAS
 
C  set up structure #101:
C    1. set modelling clipping CLIP
C    2. set modelling clipping volume with:
C          point         =  5, 5, 5
C          normal vector = -1,-1,-1
C    3. set local transformation = shift by +3,+3,+3
C    4. polymarker at MC: 4,4,4 (WC will be 7,7,7)
C    5. polymarker at MC: 1,1,1 (WC will be 4,4,4)
 
      CALL POPST  (101)
      CALL PSMCLI (PCLIP)
      CALL SETRVS ('5,5,5, -1,-1,-1', HALFSP, IDUM1)
      CALL PSMCV3 (PMCREP, 1, HALFSP)
      CALL ETR3   (3.0,3.0,3.0, M2)
      CALL PSLMT3 (M2, PCREPL)
      CALL SETRVS ('4,1', PMLOCX, PMLEN)
      CALL SETRVS ('4,1', PMLOCY, PMLEN)
      CALL SETRVS ('4,1', PMLOCZ, PMLEN)
      CALL PPM3   (1, PMLOCX(1), PMLOCY(1), PMLOCZ(1))
      CALL PPM3   (1, PMLOCX(2), PMLOCY(2), PMLOCZ(2))
 
      CALL SETMSG ('2 3 4 5 6 10', 'If the modelling clip flag is '   //
     1             'NOCLIP, ISS should detect a primitive whether '   //
     2             'or not its location in world coordinates is '     //
     3             'outside the current modelling clipping volume, '  //
     4             'even if the current modelling clipping '          //
     5             'indicator is CLIP.')
 
C  ISS twice with
C    modelling clip flag: NOCLIP
C    SRP:                 5.5,5.5,5.5
C    search distance:     1.02*1.5
C
C  pass/fail depending on
C    (found at 101,4 with starting path = 101,0  and
C     found at 101,5 with starting path = 101,4)
 
      CALL SETVS ('101,0', STPATH, IDUM1)
      CALL SETVS ('101,4', EXPATH, EXLEN)
      CALL PISS3 (5.5,5.5,5.5, 1.02*1.5, 1, STPATH, PNCLIP, 1,
     1            0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)
 
      IF (ERRIND .EQ. 0 .AND. IAREQL(2*FPTHSZ,FPATH, EXLEN,EXPATH)) THEN
C        OK so far
      ELSE
         CALL FAIL
         GOTO 300
      ENDIF
 
      CALL SETVS ('101,4', STPATH, IDUM1)
      CALL SETVS ('101,5', EXPATH, EXLEN)
      CALL PISS3 (5.5,5.5,5.5, 1.02*1.5, 1, STPATH, PNCLIP, 1,
     1            0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)
 
      CALL IFPF (ERRIND.EQ.0 .AND. IAREQL(2*FPTHSZ,FPATH, EXLEN,EXPATH))
 
300   CONTINUE
 
C  change element #1 of structure 101 to:
C    1. set modelling clipping NOCLIP
      CALL PSEP (1)
      CALL PDEL
      CALL PSMCLI (PNCLIP)
      CALL PCLST
 
      CALL SETMSG ('2 3 4 5 6 10', 'If the modelling clip flag is '   //
     1             'CLIP, ISS should detect only those primitives '   //
     2             'whose location in world coordinates is inside '   //
     3             'the current modelling clipping volume, even if '  //
     4             'the current modelling clipping indicator is '     //
     5             'NOCLIP.')
 
C  ISS with
C    modelling clip flag: CLIP
C    SRP:                 5.5,5.5,5.5
C    search distance:     1.02*1.5
C
C  pass/fail depending on
C    (found at 101,5 with starting path = 101,0)
 
      CALL SETVS ('101,0', STPATH, IDUM1)
      CALL SETVS ('101,5', EXPATH, EXLEN)
      CALL PISS3 (5.5,5.5,5.5, 1.02*1.5, 1, STPATH, PCLIP, 1,
     1            0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)
 
      CALL IFPF (ERRIND.EQ.0 .AND. IAREQL(2*FPTHSZ,FPATH, EXLEN,EXPATH))
 
 
C  *** *** *** ***   Complex primitive   *** *** *** ***
C
C  clear CSS
      CALL PDAS
 
C  set up vertices for complex fill area:
C
C     1----------2    p1: 0, 1
C     |          |    p2: 3, 1
C     |  5---6   |    p3: 3,-2
C     |  |   |   |    p4: 1,-2
C     |  |   |   |    p5: 1, 0
C     8--+---7   |    p6: 2, 0
C        |       |    p7: 2,-1
C        4-------3    p8: 0,-1
 
      CALL SETRVS (' 0, 3, 3, 1, 1, 2, 2, 0', FALOCX, FALEN)
      CALL SETRVS (' 1, 1,-2,-2, 0, 0,-1,-1', FALOCY, FALEN)
      CALL SETRVS (' 0, 0, 0, 0, 0, 0, 0, 0', FALOCZ, FALEN)
 
C  tp1-tp8 = WC vertices = m1 X p1-p8
      CALL ARRTP3 (FALEN, FALOCX, FALOCY, FALOCZ, M1,
     1                    TPLOCX, TPLOCY, TPLOCZ)
 
C  nvec = unit vector normal to WC plane of fill area
      CALL PTSPL (FALEN, TPLOCX,TPLOCY,TPLOCZ, TX,TY,TZ, RDUM)
      CALL VEC1  (TX,TY,TZ, NVECX,NVECY,NVECZ)
 
C  set up structure #101:
C  1. set global transformation = m1
C  2. fill area at p1-p8
      CALL POPST  (101)
      CALL PSGMT3 (M1)
      CALL PFA    (FALEN, FALOCX,FALOCY)
      CALL PCLST
 
C  SRP   = point over hole in fill area = average of pt5,pt6,pt7 + 0.02*nvec
      SRPX = (TPLOCX(5)+TPLOCX(6)+TPLOCX(7)) / 3 + 0.02 * NVECX
      SRPY = (TPLOCY(5)+TPLOCY(6)+TPLOCY(7)) / 3 + 0.02 * NVECY
      SRPZ = (TPLOCZ(5)+TPLOCZ(6)+TPLOCZ(7)) / 3 + 0.02 * NVECZ
C  Note: the particular values chosen for FALOC preserve the "hole"
C  at p5-7, but since M1 is a distorting transformation, this will
C  not always be the case with other values for FALOC.
 
C  sdist = distance from SRP to fill area, as computed by PTREGD
      SDIST = PTREGD (SRPX,SRPY,SRPZ, FALEN, TPLOCX,TPLOCY,TPLOCZ)
 
      CALL SETMSG ('2 3 4 5 6 10 13', 'ISS should detect a complex ' //
     1             'primitive according to its location in world '   //
     2             'coordinates.')
 
C  ISS twice with SRP, NOCLIP, varying search distance
C    starting path:  101,0
C    search ceiling: 1
C    expected path:  101,2
 
      CALL ISSAB (SRPX,SRPY,SRPZ, SDIST, '101,0', PNCLIP, 1, '101,2')
 
 
C  *** *** *** ***   Complex clipping   *** *** *** ***
C
C  set up vertices for fill area:
C
C        1----------2     p1: 3,2
C       /           /     p2: 6,2
C      /           /      p3: 4,-1
C     4           /       p4: 1,1
C      \         /
C       \       /
C        \     /
C         \   /
C          \ /
C           3
 
      CALL SETRVS ('3,6, 4,1', FALOCX, FALEN)
      CALL SETRVS ('2,2,-1,1', FALOCY, FALEN)
      CALL SETRVS ('0,0, 0,0', FALOCZ, FALEN)
 
C  tp1-tp4 = WC vertices = m1 X p1-p4
      CALL ARRTP3 (FALEN, FALOCX, FALOCY, FALOCZ, M1,
     1                    TPLOCX, TPLOCY, TPLOCZ)
 
C  clpt  = WC clip point  = point on tp2:tp4 line segment closest to tp1
C    (tp1 normal projection onto line segment)
      CALL PTLNDS ( TPLOCX(1),TPLOCY(1),TPLOCZ(1),
     1  TPLOCX(2)-TPLOCX(4), TPLOCY(2)-TPLOCY(4), TPLOCZ(2)-TPLOCZ(4),
     2  TPLOCX(4),TPLOCY(4),TPLOCZ(4), CLPTX,CLPTY,CLPTZ, RDUM)
 
C  clvec = WC clip vector = vector from clpt to tp1 (in WC plane of
C     fill area, normal to line between tp2 and tp4, towards tp1).
      CLVCX = TPLOCX(1) - CLPTX
      CLVCY = TPLOCY(1) - CLPTY
      CLVCZ = TPLOCZ(1) - CLPTZ
 
C  nvec  = unit vector normal to WC fill area plane
      CALL PTSPL (FALEN, TPLOCX,TPLOCY,TPLOCZ, TX,TY,TZ, RDUM)
      CALL VEC1  (TX,TY,TZ, NVECX,NVECY,NVECZ)
 
C  set up structure #102:
C  1. set modelling clipping volume with:
C        point         = clpt
C        normal vector = clvec
C  2. set global transformation = m1
C  3. fill area at p1-p4
      CALL POPST  (102)
 
      HALFSP (1,1) = CLPTX
      HALFSP (2,1) = CLPTY
      HALFSP (3,1) = CLPTZ
      HALFSP (4,1) = CLVCX
      HALFSP (5,1) = CLVCY
      HALFSP (6,1) = CLVCZ
      CALL PSMCV3 (PMCREP, 1, HALFSP)
 
      CALL PSGMT3 (M1)
      CALL PFA    (FALEN, FALOCX,FALOCY)
      CALL PCLST
 
C  dvec = vector away from clipping volume and up from fill area plane
      NVECL = VECL(CLVCX, CLVCY, CLVCZ) / 10
      DVECX = NVECL*NVECX - CLVCX/2
      DVECY = NVECL*NVECY - CLVCY/2
      DVECZ = NVECL*NVECZ - CLVCZ/2
 
C  SRP = clpt + dvec (outside clipping volume)
      SRPX = CLPTX + DVECX
      SRPY = CLPTY + DVECY
      SRPZ = CLPTZ + DVECZ
 
C  sdist = length of dvec
      SDIST = VECL (DVECX,DVECY,DVECZ)
C  Note: this is not a general-purpose formula - only works when
C  clip point is inside transformed quadrilateral.  Since M1 is a
C  distorting transformation, this will not always be the case,
C  although it is for the particular values chosen for FALOC.
 
      CALL SETMSG ('2 3 4 5 6 10 13', 'If the modelling clip flag '   //
     1             'is CLIP, ISS should detect only those portions '  //
     2             'of a complex primitive whose location in world '  //
     3             'coordinates is inside the current modelling '     //
     4             'clipping volume.')
 
C  ISS twice with SRP, CLIP, varying search distance
C    starting path:  102,0
C    search ceiling: 1
C    expected path:  102,3
      CALL ISSAB (SRPX,SRPY,SRPZ, SDIST, '102,0', PCLIP, 1, '102,3')
 
666   CONTINUE
      CALL ENDIT
      END
