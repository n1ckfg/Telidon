C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/06                        *
C  *    TEST TITLE : Edge flag facilities                  *
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

C    Declare program-specific variables
      INTEGER   EFI, REF, IDUM1, IDUM2

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      REAL      RDUM1
C   parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.03/06')

C  open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C   open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL SETMSG ('15 29', 'A valid edge flag should be realized ' //
     1             'as itself.')
      DO 100 EFI =  POFF, PON
C <set edge representation> index #1, edge flag = efi
         CALL ERRCTL (.TRUE.)
         CALL PSEDR (WKID, 1, EFI, 1, 1.0, 1)
            IF (ERRSIG .NE. 0) THEN
               CALL FAIL
               WRITE (MSG, '(A,I5,A)')
     1                'Edge flag', EFI, ' rejected as invalid.'
               CALL INMSG (MSG)
               GOTO 666
            ENDIF
         CALL ERRCTL (.FALSE.)
C <inquire edge representation> index #1 to determine
C ref = realized edge flag
         CALL PQEDR (WKID, 1, PREALI, ERRIND, REF, IDUM1, RDUM1, IDUM2)
         CALL CHKINQ ('pqedr', ERRIND)
         IF (REF .NE. EFI) THEN
           CALL FAIL
           WRITE (MSG, '(A,I5,A,I5,A)') 'Edge flag set as ', EFI,
     1            ' but realized as ', REF, '.'
           CALL INMSG (MSG)
           GOTO 666
         ENDIF
100   CONTINUE
      CALL PASS

666   CONTINUE
      CALL ENDIT
      END
