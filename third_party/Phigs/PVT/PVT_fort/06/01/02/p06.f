C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/06                           *
C  *    TEST TITLE : Effect of modelling clipping in a     *
C  *                 single structure                      *
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
 
C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)
 
      INTEGER  ENDSIZ, HSDX, HSSIZ
 
      REAL     A1(4,4), ENDPTX(5),ENDPTY(5),ENDPTZ(5), HS(6,5)
      REAL     LINLEN, VECL, ANGSTP, ANG, HS2D(4,5), SRPX,SRPY,SRPZ
 
      LOGICAL    SPHDIS

      CALL INITGL ('06.01.02/06')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      IF (.NOT. SPHDIS(123)) THEN
         CALL INMSG ('Skipping test because implementation '     //
     1               'apparently uses non-Euclidean metric for ' //
     2               'search distance.')
         GOTO 666
      ENDIF

C  Throughout, use incremental spatial search (ISS) to test the
C  effects of modelling clipping.  In general, ISS will be performed
C  with the search distance (sdist) set just below and above the
C  distance needed to reach the unclipped part of a primitive from
C  the search reference point (srp).
C
C  A1 = rigid transformation  = rotate: .1 .2 .3, shift: .4 .5 .6
C                               fixed point: .7 .8 .9
      CALL EBLTM3 (.7,.8,.9, .4,.5,.6, .1,.2,.3, 1.,1.,1., A1)
 
C  endpt = polyline end points
      CALL SETRVS ('1.2, 9.4', ENDPTX, ENDSIZ)
      CALL SETRVS ('3.1, 7.0', ENDPTY, ENDSIZ)
      CALL SETRVS ('0.2, 1.9', ENDPTZ, ENDSIZ)
 
C  Set up structure #101:
      CALL POPST  (101)
      CALL PSGMT3 (A1)
      CALL PPL3 (ENDSIZ,  ENDPTX,ENDPTY,ENDPTZ)
 
      SRPX = ENDPTX(2)
      SRPY = ENDPTY(2)
      SRPZ = ENDPTZ(2) + 0.1
 
      CALL SETMSG ('42 50', 'Before any explicit clipping volume is ' //
     1             'applied, the clipping volume should be all of '   //
     2             'WC space, and all parts of primitives should be ' //
     3             'detected.')
      CALL ISSDIS (SRPX,SRPY,SRPZ, 0.1, A1, PCLIP, '101,2')
 
C  clip off half of line near endpt(2)
      HS(1,1) = (ENDPTX(1) + ENDPTX(2)) / 2
      HS(2,1) = (ENDPTY(1) + ENDPTY(2)) / 2
      HS(3,1) = (ENDPTZ(1) + ENDPTZ(2)) / 2
      HS(4,1) =  ENDPTX(1) - ENDPTX(2)
      HS(5,1) =  ENDPTY(1) - ENDPTY(2)
      HS(6,1) =  ENDPTZ(1) - ENDPTZ(2)
C  insert MCV element:
      CALL PSEDM  (PINSRT)
      CALL PSEP   (1)
      CALL PSMCV3 (PMCINT, 1, HS)
 
      SRPZ = ENDPTZ(2)
 
C  linlen = length of line segment
      LINLEN = VECL (HS(4,1), HS(5,1), HS(6,1) )
 
      CALL SETMSG ('40 41 42 43 50 57', 'When a primitive line '  //
     1             'segment intersects the boundary plane of a '  //
     2             'clipping volume, that part of it not in the ' //
     3             'half-space of the volume should be clipped.')
      CALL ISSDIS (SRPX,SRPY,SRPZ, LINLEN/2, A1, PCLIP, '101,3')
 
C  <empty structure> 101
      CALL PEMST (101)
 
C  center of rays = 2.91, 0.92, 0.18
      SRPX = 2.91
      SRPY = 0.92
      SRPZ = 0.18
 
C  angstp = angle step = 25 degrees
      ANGSTP = 25.0 * 3.14159265 / 180
 
      ENDPTX(1) = SRPX
      ENDPTY(1) = SRPY
      ENDPTZ(1) = SRPZ
 
      DO 100 HSDX = 1,3
         ANG = 10.0 * 3.14159265 / 180 + HSDX*ANGSTP
C  set up half-space vector:
         HS (4,HSDX) = 0.0
         HS (5,HSDX) = COS(ANG)
         HS (6,HSDX) = SIN(ANG)
C  set up half-space point:
         HS (1,HSDX) = SRPX + HS (4,HSDX)
         HS (2,HSDX) = SRPX + HS (5,HSDX)
         HS (3,HSDX) = SRPX + HS (6,HSDX)
C  set up primitives:
         ENDPTX(2) = SRPX + 3 * HS (4,HSDX)
         ENDPTY(2) = SRPY + 3 * HS (5,HSDX)
         ENDPTZ(2) = SRPZ + 3 * HS (6,HSDX)
C  insert polyline with endpts into structure
         CALL PPL3 (2, ENDPTX,ENDPTY,ENDPTZ)
C  next hsdx
100   CONTINUE
 
C  set element pointer to 0, insert at start of structure:
C    1: set global transformation 3: A1
C    2: set MCV: 3 points = hspt(1:3)
C                3 normal vector = vec(1:3)
C                operator = replace
      CALL PSEP (0)
      CALL PSGMT3 (A1)
      CALL PSMCV3 (PMCREP, 3, HS)
 
      CALL SETMSG ('40 41 42 43 57', 'When several primitive line '   //
     1             'segments intersect several boundary planes of a ' //
     2             'single clipping volume, the portions of the '     //
     3             'segments that are not in all the half-spaces of ' //
     4             'the volume should be clipped.')
      CALL ISSDIS (SRPX,SRPY,SRPZ, 1/COS(ANGSTP), A1, PCLIP, '101,4')
 
C  delete element #2 from structure #101 and insert
      CALL PDELRA (2,2)
 
      CALL PSMCV3 (PMCINT, 1, HS(1,1))
      CALL PSMCV3 (PMCINT, 1, HS(1,2))
      CALL PSMCV3 (PMCINT, 1, HS(1,3))
 
      CALL SETMSG ('40 41 42 43 50 57', 'When several primitive '    //
     1             'line segments intersect the boundary planes of ' //
     2             'several intersected clipping volumes, the '      //
     3             'portions of the segments that are not in the '   //
     4             'half-spaces of all the volumes should be '       //
     5             'clipped.')
      CALL ISSDIS (SRPX,SRPY,SRPZ, 1/COS(ANGSTP), A1, PCLIP, '101,6')
 
C  replace element 2-4 in structure #101:
      CALL PDELRA (2,4)
 
      CALL PSMCV3 (PMCREP, 1, HS(1,1))
      CALL PSMCV3 (PMCREP, 1, HS(1,2))
      CALL PSMCV3 (PMCREP, 1, HS(1,3))
 
C  Now only half-space(3) should be operative.
      CALL SETMSG ('40 41 42 43 57', 'When the operator of a set '    //
     1             'modelling clipping volume element is REPLACE, '   //
     2             'only its volume should be used to clip '          //
     3             'primitives and previous clipping volumes should ' //
     4             'be ignored.')
      CALL ISSDIS (SRPX,SRPY,SRPZ, 1.0, A1, PCLIP, '101,7')
 
      CALL PEMST (101)
      CALL PSLMT3 (A1, PCREPL)
 
C  set up 2D points and vectors for 4 half-spaces
      CALL SETRVS ('0,1, 3,-3, 1,0, -3,-3, 0,-1, -3,3, -1,0, 3,3',
     1             HS2D, HSSIZ)
      CALL PSMCV (PMCREP, 4, HS2D)
C  set up fill area
      CALL SETRVS ('-2, -2, 2,  2', ENDPTX, ENDSIZ)
      CALL SETRVS ('-2,  2, 2, -2', ENDPTY, ENDSIZ)
      CALL SETRVS (' 3,  3, 3,  3', ENDPTZ, ENDSIZ)
      CALL PFA3 (4, ENDPTX,ENDPTY,ENDPTZ)
 
      SRPX = ENDPTX(2)
      SRPY = ENDPTY(2)
      SRPZ = ENDPTZ(2)
 
      CALL SETMSG ('40 41 42 43 49 57', 'When a 2D clip volume is '  //
     1             'applied to a 3D fill area primitive, it should ' //
     2             'behave as if the z-coordinate of its point and ' //
     3             'normal vector were zero.')
      CALL ISSDIS (SRPX,SRPY,SRPZ, 3*SQRT(2.0) / 2, A1, PCLIP, '101,3')
 
666   CONTINUE
      CALL ENDIT
      END
