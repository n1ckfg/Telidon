C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.02/03                           *
C  *    TEST TITLE : Initialization of WSL view table      *
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
 
      CHARACTER  MSG*300, MSGSUF*25
      INTEGER    IVW, IVWDX, MAXVW, VWTUPD, SPECON, SPECWT
      INTEGER    NDVI, NPVW, ROW, COL, IX
      INTEGER    PDCID(3), DFCID(3), E0CID(3)
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7
      REAL       PDVOM(4,4), PDVMM(4,4), PDVCLM(6)
      REAL       DFVOM(4,4), DFVMM(4,4), DFVCLM(6)
      REAL       E0VOM(4,4), E0VMM(4,4), E0VCLM(6)
      LOGICAL    RAREQ, IAREQ
 
C control functions that return both Current and Requested values.
      INTEGER    PCURVL,     PRQSVL
      PARAMETER (PCURVL = 0, PRQSVL = 1)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
C relative input priority
      INTEGER    PHIGHR,     PLOWER
      PARAMETER (PHIGHR = 0, PLOWER = 1)
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND = 1)
 
      CALL INITGL ('06.02.02/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C  message suffix
      MSGSUF = 'opening workstation.'
 
C  top of check_table loop
100   CONTINUE
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
C  <Inquire list of view indices> to determine
C     ndvi = number of defined indices in the view table
      CALL PQEVWI (WKID, 0, ERRIND, NDVI, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)
 
      CALL SETMSG ('8 18 19', 'List of view indices should be in '    //
     1             'consecutive ascending order, starting with '      //
     2             'zero, after ' // MSGSUF)
 
      DO 200 IVW = 1,NDVI
         CALL PQEVWI (WKID, IVW, ERRIND, IDUM1, IVWDX)
         CALL CHKINQ ('pqevwi', ERRIND)
         IF (IVWDX .NE. IVW-1) THEN
            CALL FAIL
            GOTO 210
         ENDIF
200   CONTINUE
      CALL PASS
210   CONTINUE
 
C  <Inquire view facilities> to determine
C     npvw = number of predefined views
      NPVW = 666
      CALL PQVWF (SPECWT, ERRIND, NPVW)
      CALL CHKINQ ('pqvwf', ERRIND)
 
C  <inquire workstation state table lengths> to determine
C     maxvw = maximum size of the view table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7, MAXVW)
      CALL CHKINQ ('pqwksl', ERRIND)
 
      CALL SETMSG ('4 9', 'There should be at least as many '         //
     1             'defined view indices as predefined view '         //
     2             'entries, after ' // MSGSUF)
      CALL IFPF (NDVI .GE. NPVW)
 
      CALL SETMSG ('10 12', 'The number of defined view indices '     //
     1             'should be the same as the maximum table length, ' //
     2             'after ' // MSGSUF)
      CALL IFPF (NDVI .EQ. MAXVW)
 
      CALL SETMSG ('6 9 17', 'For each WDT predefined view, the '     //
     1             'corresponding WSL requested and current view '    //
     2             'table entry should have the same values, after '  //
     3             MSGSUF)
 
      DO 300 IVWDX = 0, NPVW-1
C        <Inquire predefined view representation> to determine
C        set of values from WDT for index=ivwdx
         CALL PQPVWR (SPECWT,IVWDX, ERRIND,
     1                PDVOM,PDVMM,PDVCLM,PDCID(1),PDCID(2),PDCID(3) )
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5)') '<Inquire predefined view ' //
     1            'representation> failed with error = ', ERRIND
            CALL INMSG (MSG)
            GOTO 310
         ENDIF
 
C        <Inquire view representation> to determine
C        set of values from WSL for index=ivwdx
 
C ----- requested values
         CALL PQVWR (WKID, IVWDX, PRQSVL, ERRIND, VWTUPD,
     1               DFVOM,DFVMM,DFVCLM,DFCID(1),DFCID(2),DFCID(3) )
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5)') '<Inquire view representation> ' //
     1            'for requested values failed with error = ', ERRIND
            CALL INMSG (MSG)
            GOTO 310
         ENDIF
C check matrices and clip limits
         IF (.NOT. (RAREQ (16,  DFVOM,  PDVOM,  0.0, 0.0) .AND.
     1              RAREQ (16,  DFVMM,  PDVMM,  0.0, 0.0) .AND.
     2              RAREQ ( 6,  DFVCLM, PDVCLM, 0.0, 0.0) .AND.
     3              IAREQ ( 3,  DFCID,  PDCID)  )) THEN
            CALL FAIL
            GOTO 310
         ENDIF
 
C ----- current values
         CALL PQVWR (WKID, IVWDX, PCURVL, ERRIND, VWTUPD,
     1               DFVOM,DFVMM,DFVCLM,DFCID(1),DFCID(2),DFCID(3) )
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5)') '<Inquire view representation> ' //
     1            'for current values failed with error = ', ERRIND
            CALL INMSG (MSG)
            GOTO 310
         ENDIF
C check matrices and clip limits
         IF (.NOT. (RAREQ (16,  DFVOM,  PDVOM,  0.0, 0.0) .AND.
     1              RAREQ (16,  DFVMM,  PDVMM,  0.0, 0.0) .AND.
     2              RAREQ ( 6,  DFVCLM, PDVCLM, 0.0, 0.0) .AND.
     3              IAREQ ( 3,  DFCID,  PDCID)  )) THEN
            CALL FAIL
            GOTO 310
         ENDIF
 
300   CONTINUE
      CALL PASS
310   CONTINUE
 
      CALL SETMSG ('10 17', 'Each WSL requested and current view '    //
     1             'table entry for which there is no corresponding ' //
     2             'WDT predefined entry should have the same '       //
     3             'values as entry #0, after ' // MSGSUF)
 
C  <Inquire view representation> to determine
C     ent0 = set of values from WSL for index=0
      CALL PQVWR (WKID, 0, PRQSVL, ERRIND, VWTUPD,
     1            E0VOM,E0VMM,E0VCLM,E0CID(1),E0CID(2),E0CID(3) )
      CALL CHKINQ ('pqvwr', ERRIND)
 
      DO 400 IVWDX = NPVW, NDVI-1
 
C ----- requested values
         CALL PQVWR (WKID, IVWDX, PRQSVL, ERRIND, VWTUPD,
     1               DFVOM,DFVMM,DFVCLM,DFCID(1),DFCID(2),DFCID(3) )
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5)') '<Inquire view representation> ' //
     1            'for requested values failed with error = ', ERRIND
            CALL INMSG (MSG)
            GOTO 410
         ENDIF
C check matrices and clip limits
         IF (.NOT. (RAREQ (16,  DFVOM,  E0VOM,  0.0, 0.0) .AND.
     1              RAREQ (16,  DFVMM,  E0VMM,  0.0, 0.0) .AND.
     2              RAREQ ( 6,  DFVCLM, E0VCLM, 0.0, 0.0) .AND.
     3              IAREQ ( 3,  DFCID,  E0CID)  )) THEN
            CALL FAIL
            GOTO 410
         ENDIF
 
C ----- current values
         CALL PQVWR (WKID, IVWDX, PCURVL, ERRIND, VWTUPD,
     1               DFVOM,DFVMM,DFVCLM,DFCID(1),DFCID(2),DFCID(3) )
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5)') '<Inquire view representation> ' //
     1            'for current values failed with error = ', ERRIND
            CALL INMSG (MSG)
            GOTO 410
         ENDIF
C check matrices and clip limits
         IF (.NOT. (RAREQ (16,  DFVOM,  E0VOM,  0.0, 0.0) .AND.
     1              RAREQ (16,  DFVMM,  E0VMM,  0.0, 0.0) .AND.
     2              RAREQ ( 6,  DFVCLM, E0VCLM, 0.0, 0.0) .AND.
     3              IAREQ ( 3,  DFCID,  E0CID)  )) THEN
            CALL FAIL
            GOTO 410
         ENDIF
 
400   CONTINUE
      CALL PASS
410   CONTINUE
 
      CALL SETMSG ('11 24', 'The view transformation update state '   //
     1             'for each entry in the WSL view table should be '  //
     2             'NOTPENDING after ' // MSGSUF)
      DO 500 IVWDX = 0, NDVI-1
         CALL PQVWR (WKID, IVWDX, PRQSVL, ERRIND, VWTUPD,
     1               DFVOM,DFVMM,DFVCLM,DFCID(1),DFCID(2),DFCID(3) )
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5)') '<Inquire view representation> ' //
     1            'failed with error = ', ERRIND
            CALL INMSG (MSG)
            GOTO 510
         ENDIF
         IF (VWTUPD .NE. PNPEND) THEN
            CALL FAIL
            GOTO 510
         ENDIF
 
500   CONTINUE
      CALL PASS
510   CONTINUE
 
C  alter view table:
C    for view #1:
C       add 1.0 to orientation matrix, mapping matrix
C       new clip limits = old_limits / 2 + 0.1
C       new clip indicator = reverse of old
 
      CALL PQVWR (WKID, 1, PRQSVL, ERRIND, VWTUPD,
     1            DFVOM,DFVMM,DFVCLM,DFCID(1),DFCID(2),DFCID(3) )
      CALL CHKINQ ('pqvwr', ERRIND)
      DO 600 ROW = 1,4
      DO 610 COL = 1,4
         DFVOM (ROW,COL) = DFVOM (ROW,COL) + 1.0
         DFVMM (ROW,COL) = DFVMM (ROW,COL) + 1.0
610   CONTINUE
600   CONTINUE
 
      DO 620 IX = 1,6
         DFVCLM (IX) = DFVCLM (IX) / 2 + 0.1
620   CONTINUE
 
      CALL PSVWR3 (WKID, 1, DFVOM,DFVMM,DFVCLM,
     1             1 - DFCID(1), 1 - DFCID(2), 1 - DFCID(3) )
 
C  change order of entries in view table
C     make view #2 higher priority than view #0
      CALL PSVTIP (WKID, 2, 0, PHIGHR)
 
C  <close workstation>
      CALL PCLWK (WKID)
 
C check whether to repeat
      IF (MSGSUF .EQ. 'opening workstation.') THEN
         MSGSUF = 're-opening workstation.'
         GOTO 100
      ENDIF
 
666   CONTINUE
      CALL ENDIT
      END
