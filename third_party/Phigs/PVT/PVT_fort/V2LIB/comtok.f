      SUBROUTINE COMTOK (EXPCOM, EXPATH)

C  COMTOK accepts an expected composite transformation and found
C  path.  It performs an incremental spatial search of structure
C  #101, using the transformed value of (3,4,5) as the SRP, and
C  issues pass or fail depending on whether the actual found path
C  matches that expected.

C  Input parameters:
C    EXPCOM : expected composite transformation
C    EXPATH : expected found path

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 100)

      INTEGER    IDUM(2), FPATH(2,IPTHSZ), ERRIND, FPTHSZ
      INTEGER    SPATH(2,1), IEXPTH(2,IPTHSZ), IEXLEN

      REAL       EXPCOM(4,4), SRPX,SRPY,SRPZ

      CHARACTER  EXPATH*(*)

      LOGICAL    IAREQL

      DATA  SPATH / 101,0 /

C  get expected point in WC
      CALL ETP3 (3.0,4.0,5.0, EXPCOM, SRPX,SRPY,SRPZ)

C  decode expected found path
      CALL SETVS (EXPATH, IEXPTH, IEXLEN)

      CALL PISS3 (SRPX,SRPY,SRPZ, 0.03, 1, SPATH, PNCLIP, 1,
     1            0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)

      CALL IFPF (ERRIND .EQ. 0 .AND.
     1           IAREQL (2*FPTHSZ, FPATH, IEXLEN, IEXPTH))

      END
