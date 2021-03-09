C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/07                           *
C  *    TEST TITLE : Saving and restoring the modelling    *
C  *                 clipping volume                       *
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
 
C modelling clipping operator
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)
 
      INTEGER     IX
 
      REAL        HS(6,3), XA(8),YA(8),ZA(8)

      CALL INITGL ('06.01.02/07')
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  Throughout, use incremental spatial search (ISS) to test the
C  effects of modelling clipping.  In general, ISS checks which
C  subset of primitives have been clipped so as to determine the
C  current modelling clipping volume.  The search reference point
C  and distance are constant and are set so as to reach all the
C  primitives.
 
C  hs(1) = half-space #1 = all points for which x > 0
C  hs(2) = half-space #2 = all points for which y > 0
C  hs(3) = half-space #3 = all points for which z > 0
      DATA  HS / 18 * 0.0 /
 
      HS (4,1) = .1
      HS (5,2) = .1
      HS (6,3) = .1
 
C  Set up structure #101:
      CALL POPST  (101)
      CALL PSMCV3 (PMCREP, 1, HS(1,1))
      CALL PEXST  (102)
      CALL PEXST  (109)
      CALL PSMCV3 (PMCINT, 1, HS(1,2))
      CALL PEXST  (102)
      CALL PEXST  (109)
      CALL PSMCV3 (PMCREP, 1, HS(1,2))
      CALL PEXST  (103)
      CALL PEXST  (109)
      CALL PCLST
 
C  Set up structure #102:
      CALL POPST  (102)
      CALL PSMCV3 (PMCINT, 1, HS(1,3))
      CALL PEXST  (103)
      CALL PEXST  (109)
      CALL PCLST
 
C  Set up structure #103:
      CALL POPST  (103)
      CALL PSMCV3 (PMCREP, 1, HS(1,3))
      CALL PEXST  (109)
      CALL PCLST
 
C  Set up structure #109:
      CALL SETRVS ('-1,-1,-1,-1, 1, 1, 1, 1', XA, IX)
      CALL SETRVS ('-1,-1, 1, 1,-1,-1, 1, 1', YA, IX)
      CALL SETRVS ('-1, 1,-1, 1,-1, 1,-1, 1', ZA, IX)
 
      CALL POPST  (109)
      DO 100 IX = 1,8
         CALL PPM3 (1, XA(IX), YA(IX), ZA(IX))
100   CONTINUE
      CALL PCLST
 
      CALL SETMSG ('40 43 57', 'When an executed structure sets the ' //
     1             'MCV with REPLACE, it should override the '        //
     2             'inherited current MCV.')
      CALL CHKMCV ('101,0', '101,2, 102,2, 103,2, 109,2 /' //
     1                      '101,2, 102,2, 103,2, 109,4 /' //
     2                      '101,2, 102,2, 103,2, 109,6 /' //
     3                      '101,2, 102,2, 103,2, 109,8 /')
C  based on expected MCV = HS(3)
 
      CALL SETMSG ('40 43 51 57', 'A calling structure should have ' //
     1             'its current MCV restored after traversal '       //
     2             'returns from the executed structure.')
      CALL CHKMCV ('101,2, 102,2, 103,2', '101,2, 102,3, 109,6 /' //
     1                                    '101,2, 102,3, 109,8 /')
C  based on expected MCV = HS(1),HS(3)
 
      CALL SETMSG ('40 43 51 57', 'A calling structure should have ' //
     1             'its current MCV restored after traversal '       //
     2             'returns from two levels of execution.')
      CALL CHKMCV ('101,2, 102,3', '101,3, 109,5 /' //
     1                             '101,3, 109,6 /' //
     2                             '101,3, 109,7 /' //
     3                             '101,3, 109,8 /')
C  based on expected MCV = HS(1)
 
      CALL SETMSG ('40 43 57', 'When an executed structure sets the ' //
     1             'MCV with REPLACE, it should override the '        //
     2             'inherited current MCV, even when called twice.')
      CALL CHKMCV ('101,3', '101,5, 102,2, 103,2, 109,2 /' //
     1                      '101,5, 102,2, 103,2, 109,4 /' //
     2                      '101,5, 102,2, 103,2, 109,6 /' //
     3                      '101,5, 102,2, 103,2, 109,8 /')
C  based on expected MCV = HS(3)
 
      CALL SETMSG ('40 43 51 57', 'A calling structure should have ' //
     1             'its current MCV restored after executing the '   //
     2             'same structure twice.')
      CALL CHKMCV ('101,5, 102,2, 103,2', '101,5, 102,3, 109,8 /')
C  based on expected MCV = HS(1),HS(2),HS(3)
 
      CALL SETMSG ('40 43 51 57', 'A calling structure should have ' //
     1             'its current MCV restored after traversal '       //
     2             'repeatedly returns from two levels of execution.')
      CALL CHKMCV ('101,5, 102,3', '101,6, 109,7 /' //
     1                             '101,6, 109,8 /')
C  based on expected MCV = HS(1),HS(2)
 
      CALL SETMSG ('40 43 57', 'When an executed structure sets the ' //
     1             'MCV with REPLACE, it should override the '        //
     2             'inherited current MCV, even when called by a '    //
     3             'different structure.')
      CALL CHKMCV ('101,6', '101,8, 103,2, 109,2 /' //
     1                      '101,8, 103,2, 109,4 /' //
     2                      '101,8, 103,2, 109,6 /' //
     3                      '101,8, 103,2, 109,8 /')
C  based on expected MCV = HS(3)
 
      CALL SETMSG ('40 43 51 57', 'A calling structure should have ' //
     1             'its current MCV restored after traversal '       //
     2             'returns from different structures.')
      CALL CHKMCV ('101,8, 103,2', '101,9, 109,3 /' //
     1                             '101,9, 109,4 /' //
     2                             '101,9, 109,7 /' //
     3                             '101,9, 109,8 /')
C  based on expected MCV = HS(2)
 
C  *** *** *** ***   <restore MCV>   *** *** *** ***
 
C  Add to structure #103:
C  3: restore MCV
C  4: execute structure 109
      CALL POPST  (103)
      CALL PRMCV
      CALL PEXST  (109)
 
      CALL SETMSG ('40 43 56 57', '<Restore MCV> should cause the '   //
     1             'current MCV to be reset to the original value '   //
     2             'it had upon entry to the structure, even though ' //
     3             'the value was replaced within the structure.')
      CALL CHKMCV ('101,5,102,2,103,2', '101,5, 102,2, 103,4, 109,8 /')
C  based on expected MCV = HS(1),HS(2),HS(3)
 
C  change structure #103:
C  1: set MCV = hs2 with intersect
      CALL PDELRA (1,1)
      CALL PSMCV3 (PMCINT, 1, HS(1,2))
      CALL PCLST
 
      CALL SETMSG ('40 43 56 57', '<Restore MCV> should cause the '   //
     1             'current MCV to be reset to the original value '   //
     2             'it had upon entry to the structure, even though ' //
     3             'the value was altered by intersection within '    //
     4             'the structure.')
      CALL CHKMCV ('101,2,102,2,103,2','101,2, 102,2, 103,4, 109,6 /' //
     1                                 '101,2, 102,2, 103,4, 109,8 /')
C  based on expected MCV = HS(1),HS(3)
 
666   CONTINUE
      CALL ENDIT
      END
