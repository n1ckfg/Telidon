C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.02/04                           *
C  *    TEST TITLE : Setting and inquiring on the WSL view *
C  *                 table                                 *
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
 
      INTEGER    MAXVW, SPECON, SPECWT, IVWDX, VWTUPD
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7
 
      INTEGER    E2VCID, ROW, COL, SROW, SCOL
      REAL       E2VOM(3,3), E2VMM(3,3), E2VCLM(4)
 
      INTEGER    EXVCID(3), INVCID(3)
      REAL       EXVOM(4,4), EXVMM(4,4), EXVCLM(6)
      REAL       INVOM(4,4), INVMM(4,4), INVCLM(6)
 
      LOGICAL    RAREQ
 
      CHARACTER  MSG*300
 
C control functions that return both Current and Requested values.
      INTEGER    PCURVL,     PRQSVL
      PARAMETER (PCURVL = 0, PRQSVL = 1)
 
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
 
C  expected values for entry are:
C  exvom(4,4) = orientation matrix   =
C     | -5.378     -2.251  -7.886     30.706    |
C     | -0.4014    0.6207  9.1292E-02 -5.423    |
C     | -104.806   0.0     2.804      8.502E-02 |
C     | -7.375E-02 -21.465 -128.958   -0.2066   |
 
      DATA EXVOM  /
     1      -5.378, -0.4014, -104.806, -7.375E-02,
     2      -2.251, 0.6207, 0.0, -21.465,
     3      -7.886, 9.1292E-02, 2.804, -128.958,
     4      30.706, -5.423, 8.502E-02, -0.2066   /
 
C  exvmm(4,4) = mapping matrix       =
C     | 28.482  106.135 -131.300 16.022 |
C     | -150.45 0.0     0.0      13.851 |
C     | 35.318  -0.5466 84.676   0.7512 |
C     | 2.4107  -5.7922 -101.682 1.1572 |
 
       DATA EXVMM /
     1      28.482, -150.45, 35.318, 2.4107,
     2      106.135, 0.0, -0.5466, -5.7922,
     3      -131.300, 0.0, 84.676, -101.682,
     4      16.022, 13.851, 0.7512, 1.1572  /
 
C  exvclm(6)  = view clipping limits = .2 .3 .4 .5 .6 .7
      DATA  EXVCLM / .2, .3, .4, .5, .6, .7 /
 
C  exvcid(3)  = clipping indicators  = NOCLIP, CLIP, NOCLIP
      DATA  EXVCID / PNCLIP, PCLIP, PNCLIP /
 
C  Set/expected values for entry are:
C  e2vom(3,3) = orientation matrix   =
C     | -5.378     -2.251  30.706    |
C     | -0.4014    0.6207  -5.423    |
C     | -7.375E-02 -21.465 -0.2066   |
 
      DATA E2VOM /
     1     -5.378, -0.4014, -7.375E-02,
     2     -2.251, 0.6207, -21.465,
     3     30.706, -5.423, -0.2066  /
 
C  e2vmm(3,3) = mapping matrix       =
C     | 28.482  106.135 16.022 |
C     | -150.45 0.0     13.851 |
C     | 2.4107  -5.7922 1.1572 |
      DATA E2VMM /
     1     28.482, -150.45, 2.4107,
     1     106.135, 0.0, -5.7922,
     1     16.022, 13.851, 1.1572 /
 
C  e2vclm(4)  = view clipping limits = .1 .2 .3 .4
      DATA E2VCLM / .1, .2, .3, .4 /
 
C  e2vcid     = x-y clipping indicator = NOCLIP
      DATA  E2VCID / PNCLIP /
 
      CALL INITGL ('06.02.02/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
C  <inquire workstation state table lengths> to determine
C     maxvw = maximum size of the view table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7, MAXVW)
      CALL CHKINQ ('pqwksl', ERRIND)
 
      CALL SETMSG ('12 13', 'Reported maximum size of the view '      //
     1             'table should be at least 6.')
      CALL IFPF (MAXVW .GT. 5)
 
      CALL SETMSG ('12 14 17 23', '<Set view representation 3> '      //
     1             'should be able to set all requested entries, up ' //
     2             'to the maximum table size.')
 
      CALL ERRCTL (.TRUE.)
      DO 100 IVWDX = 1, MAXVW-1
C        <Set view representation 3> for index #ivwdx, with entry value =
C           exvom, exvmm, exvclm, exvcid
         CALL PSVWR3 (WKID, IVWDX, EXVOM,EXVMM,EXVCLM,
     1                EXVCID(1), EXVCID(2), EXVCID(3))
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A,I5)') '<Set view rep 3> for view #',
     1            IVWDX, ' signalled error #', ERRSIG
            CALL INMSG (MSG)
            GOTO 110
         ENDIF
 
         CALL PQVWR (WKID, IVWDX, PRQSVL, ERRIND, VWTUPD,
     1               INVOM,INVMM,INVCLM,INVCID(1),INVCID(2),INVCID(3) )
         IF (ERRIND .EQ. 0                          .AND.
     1       RAREQ (16,  INVOM,  EXVOM, 0.0, 0.0)   .AND.
     2       RAREQ (16,  INVMM,  EXVMM, 0.0, 0.0)   .AND.
     3       RAREQ ( 6, INVCLM, EXVCLM, 0.0, 0.0)   .AND.
     4       INVCID(1) .EQ. EXVCID(1)               .AND.
     5       INVCID(2) .EQ. EXVCID(2)               .AND.
     6       INVCID(3) .EQ. EXVCID(3)  )  THEN
C           OK so far
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I5,A)') 'Inquire view rep for view #',
     1            IVWDX, ' failed to match expected values.'
            CALL INMSG (MSG)
            GOTO 110
         ENDIF
100   CONTINUE
      CALL PASS
110   CONTINUE
      CALL ERRCTL (.FALSE.)
 
C  exvom(4,4) = properly expanded version of e2vom
C  exvmm(4,4) = properly expanded version of e2vmm
      DO 200 ROW = 1,4
         SROW = MIN( 3,ROW)
         DO 210 COL = 1,4
            SCOL = MIN( 3,COL)
            IF (ROW .EQ. 3 .OR. COL .EQ. 3) THEN
               EXVOM (ROW,COL) = 0.0
               EXVMM (ROW,COL) = 0.0
            ELSE
               EXVOM (ROW,COL) = E2VOM (SROW,SCOL)
               EXVMM (ROW,COL) = E2VMM (SROW,SCOL)
            ENDIF
210      CONTINUE
200   CONTINUE
      EXVOM (3,3) = 1.0
      EXVMM (3,3) = 1.0
 
      CALL SETMSG ('15 16 17 23', '<Set view representation> should ' //
     1             'be able to re-set a user-defined requested '      //
     2             'entry, with correct defaults supplied by the '    //
     3             'implementation.')
 
      CALL ERRCTL (.TRUE.)
C  <Set view representation> for index #1, with entry value =
C     e2vom, e2vmm, e2vclm, e2vcid
      CALL PSVWR (WKID, 1, E2VOM, E2VMM, E2VCLM, E2VCID)
      CALL ERRCTL (.FALSE.)
 
      IF (ERRSIG .NE. 0) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5)')
     1         '<Set view rep> signalled error #', ERRSIG
         CALL INMSG (MSG)
         GOTO 666
      ENDIF
 
      CALL PQVWR (WKID, 1, PRQSVL, ERRIND, VWTUPD,
     1            INVOM,INVMM,INVCLM,INVCID(1),INVCID(2),INVCID(3) )
      CALL IFPF (ERRIND .EQ. 0                   .AND.
     1    RAREQ (16,  INVOM,  EXVOM, 0.0, 0.0)   .AND.
     2    RAREQ (16,  INVMM,  EXVMM, 0.0, 0.0)   .AND.
     3    RAREQ ( 4, INVCLM, E2VCLM, 0.0, 0.0)   .AND.
     4    INVCLM(5) .EQ. 0.0                     .AND.
     5    INVCLM(6) .EQ. 1.0                     .AND.
     6    INVCID(1) .EQ. E2VCID                  .AND.
     7    INVCID(2) .EQ. PCLIP                   .AND.
     8    INVCID(3) .EQ. PCLIP )
 
666   CONTINUE
      CALL ENDIT
      END
