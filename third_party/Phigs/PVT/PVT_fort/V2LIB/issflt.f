      SUBROUTINE ISSFLT (STPATH, NFILT, IFILT, EXPATH)

C  ISSFLT tests the effect of various filter lists on the behavior
C  of ISS.  It issues pass or fail depending on whether or not the
C  actual result of ISS matches the expected result.  All the
C  parameters are encoded in character form, and thus must be
C  translated before invoking ISS.

C  Input parameters:
C    STPATH : starting path for ISS
C    NFILT  : normal filter list
C    IFILT  : inverted filter list
C    EXPATH : expected path

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 10)

      INTEGER    SCEIL, MCLIPI, ERRIND
      INTEGER    NFLN, NFLISX(60),NFLIS(200), NFLESX(60),NFLES(200)
      INTEGER    IFLN, IFLISX(60),IFLIS(200), IFLESX(60),IFLES(200)
      INTEGER    FPTHSZ, FPATH(2,IPTHSZ)
      INTEGER    ISTLEN, ISTPTH(2,10), IEXLEN, IEXPTH(2*IPTHSZ)

      REAL       SRPX,SRPY,SRPZ, SDIST

      CHARACTER  STPATH*(*), NFILT*(*), IFILT*(*), EXPATH*(*)

      LOGICAL    IAREQL

C  Throughout, keep fixed for ISS:
C    SRP = 1,2,3
C    search distance = 0.1
C    search ceiling = 1
C    clipping flag = OFF

      DATA  SRPX / 1.0 /, SRPY / 2.0 /, SRPZ / 3.0 /

      DATA  SDIST  / 0.1 /
      DATA  SCEIL  / 1 /
      DATA  MCLIPI / PNCLIP /

C  Set up starting path
      CALL SETVS (STPATH, ISTPTH, ISTLEN)

      CALL SETFIL (NFILT, NFLN, NFLISX,NFLIS, NFLESX,NFLES)
      CALL SETFIL (IFILT, IFLN, IFLISX,IFLIS, IFLESX,IFLES)

      CALL PISS3 (SRPX,SRPY,SRPZ, SDIST, ISTLEN/2, ISTPTH, MCLIPI,
     1            SCEIL, NFLN, NFLISX,NFLIS, NFLESX,NFLES,
     2                   IFLN, IFLISX,IFLIS, IFLESX,IFLES,
     3            IPTHSZ, ERRIND, FPTHSZ, FPATH)

C  Set up expected path
      CALL SETVS (EXPATH, IEXPTH, IEXLEN)

      CALL IFPF (ERRIND .EQ. 0 .AND.
     1           IAREQL(FPTHSZ*2, FPATH, IEXLEN, IEXPTH))

      END
