C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.02/02                           *
C  *    TEST TITLE : Validity of predefined view table     *
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

      INTEGER    SPECON, SPECWT, NPVW, IVW, VCID(3)

      REAL       VOM(4,4), VMM(4,4), VCLM(6), IDENT(4,4), EXVCLM(6)

      LOGICAL    RAREQ

C expected values for default clipping limits
      DATA EXVCLM /0.0, 1.0, 0.0, 1.0, 0.0, 1.0/

      CALL INITGL ('06.02.02/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL SETMSG ('4 5', 'The reported number of predefined views '  //
     1             'should be at least 6.')
C  <Inquire view facilities> to determine
C    npvw = number of predefined views
      NPVW = -6
      CALL PQVWF (SPECWT, ERRIND, NPVW)
      CALL IFPF  (ERRIND .EQ. 0 .AND. NPVW .GT. 5)

      CALL SETMSG ('4 6', 'All the predefined view entries should '   //
     1             'be accessible by <inquire predefined view '       //
     2             'representation>.')

      DO 100 IVW = 0, NPVW-1
         CALL PQPVWR (SPECWT, IVW,
     1                ERRIND, VOM, VMM, VCLM, VCID(1),VCID(2),VCID(3))
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 110
         ENDIF
100   CONTINUE
      CALL PASS
110   CONTINUE

C  <inquire predefined view representation> on entry #0 to determine:
C     vom(4,4) = orientation matrix
C     vmm(4,4) = mapping matrix
C     vclm(6)  = view clipping limits
C     vcid(3)  = clipping indicators
      VCLM(1) = -6.0
      VCID(1) = -6
      CALL PQPVWR (SPECWT, 0,
     1             ERRIND, VOM, VMM, VCLM, VCID(1),VCID(2),VCID(3))
      CALL CHKINQ ('pqpvwr', ERRIND)

      CALL SETMSG ('6 7', 'The orientation and mapping matrices for ' //
     1             'predefined view #0 should both be the identity '  //
     2             'matrix.')
      CALL IDMAT ( 4, IDENT)
      CALL IFPF  ( RAREQ(16, VOM, IDENT, 0.0, 0.0)  .AND.
     1             RAREQ(16, VMM, IDENT, 0.0, 0.0) )

      CALL SETMSG ('6 7', 'The clipping limits for predefined view '  //
     1             '#0 should be [0,1] in all three dimensions.')
      CALL IFPF  ( RAREQ(6, VCLM, EXVCLM, 0.0, 0.0))

      CALL SETMSG ('6 7', 'All three clipping indicators for '        //
     1             'predefined view #0 should be CLIP.')
      CALL IFPF ( VCID(1) .EQ. PCLIP .AND.
     1            VCID(2) .EQ. PCLIP .AND.
     2            VCID(3) .EQ. PCLIP )

666   CONTINUE
      CALL ENDIT
      END
