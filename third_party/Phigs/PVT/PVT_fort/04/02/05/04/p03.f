C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.04/03                        *
C  *    TEST TITLE : Pattern table length                  *
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

      INTEGER   MPAI, MPTE, NDE, MDPI, NEMP, II, PAI
C set up pattern color index array
      INTEGER    DIMX, DIMY, ISC, ISR, DX, DY
      PARAMETER  (DIMX = 100, DIMY = 100, ISC=1, ISR=1, DX=2, DY=2)
      INTEGER    COLIA(DIMX,DIMY)
      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      LOGICAL   NOPAT, PATAVL

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.04/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      NOPAT = .NOT. PATAVL(SPECWT)
      IF (NOPAT) THEN
         CALL INMSG ('Pattern interior style is not supported ' //
     1               'on this workstation.')
      ENDIF

      MPAI = -6
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             IDUM5, MPAI, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of pattern table entries
      MPTE = MPAI

C  nde  = number of defined entries
C  mdpi = maximum defined pattern index
C  nemp = number of empty entries

      IF (NOPAT) THEN
         CALL SETMSG ('8 9', 'If PATTERN interior style is not '     //
     1                'supported, <inquire workstation state table ' //
     2                'lengths> should report 0 entries as maximum ' //
     3                'size of pattern table.')
         CALL IFPF (MPTE .EQ. 0)
         GOTO 666
      ENDIF

      CALL SETMSG ('8 10', 'If PATTERN interior style is supported, ' //
     1             '<inquire workstation state table lengths> '       //
     2             'should report at least 10 entries as maximum '    //
     3             'size of pattern table.')

      CALL IFPF (MPTE .GE. 10)

      CALL PQEPAI (WKID, 0, ERRIND, NDE, IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)
      MDPI = -9999
      DO 100 II = 1, NDE
         CALL PQEPAI (WKID, II, ERRIND, IDUM1, PAI)
         CALL CHKINQ ('pqepai', ERRIND)
         IF (PAI .GT. MDPI) MDPI = PAI
100   CONTINUE

C set up values for pattern color index array
      COLIA(1,1) = 97
      COLIA(2,1) = 5
      COLIA(1,2) = 33
      COLIA(2,2) = 53

      NEMP = MPTE - NDE

      CALL SETMSG ('8', 'The program should be able to define ' //
     1             'additional pattern table entries, up '      //
     2             'to the maximum.')
C  set new entries
      CALL ERRCTL (.TRUE.)
      DO 250 PAI = MDPI+1, MDPI+NEMP
         CALL PSPAR (WKID, PAI, DIMX, DIMY, ISC, ISR, DX, DY, COLIA)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I6,A)')
     1      'Unable to fill pattern table slot #', NDE+PAI-MDPI,'.'
            CALL INMSG (MSG)
            GOTO 300
         ENDIF
250   CONTINUE
      CALL PASS

300   CONTINUE
      CALL ERRCTL (.FALSE.)

666   CONTINUE
      CALL ENDIT
      END
