C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 06.02.02/tstvip                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTVIP  (SPCPOS, REFPOS, RELPRI, NDVI)

C  TSTVIP tests the PSVTIP function by computing the correct
C  effect of the function call on the current list of view
C  indices, and comparing it with the actual result.
C  Pass or fail is issued as a result.

C  ------- INPUT PARAMETERS
C  spcpos     : position in current list of specified index
C  refpos     : position in current list of reference index
C  relpri     : relative priority of specified index
C  ndvi       : number of defined view indices

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

C relative input priority
      INTEGER    PHIGHR,     PLOWER
      PARAMETER (PHIGHR = 0, PLOWER = 1)

      INTEGER   SPCPOS, REFPOS, RELPRI, NDVI, SPCVW, REFVW, IVW
      INTEGER   ARSIZ
      PARAMETER (ARSIZ = 500)
      INTEGER   CURORD(ARSIZ), EXPORD(ARSIZ), ACTORD(ARSIZ)
      INTEGER   ISEND, IRECV, NSPOS, IDUM1

      LOGICAL   IAREQ

C check array size is sufficient
      IF (ARSIZ .LT. NDVI) THEN
         CALL UNMSG ('Allocated array size in TSTVIP is too small.')
      ENDIF

C  Use <inquire list of view indices> to determine
C        curord = current order
      DO 100 IVW = 1,NDVI
         CALL PQEVWI (WKID, IVW, ERRIND, IDUM1, CURORD(IVW))
         CALL CHKINQ ('pqevwi', ERRIND)
100   CONTINUE

C from parameters, calculate expord = expected order
C     nspos is new position of specified view index
      NSPOS = REFPOS
      IF     (SPCPOS .LT. REFPOS .AND. RELPRI .EQ. PHIGHR) THEN
         NSPOS = NSPOS-1
      ELSEIF (SPCPOS .GT. REFPOS .AND. RELPRI .EQ. PLOWER) THEN
         NSPOS = NSPOS+1
      ENDIF

C irecv and isend are receiving and sending positions in curord
C and expord, respectively.
      IRECV=0
      ISEND=0

150   CONTINUE
      ISEND = ISEND+1
      IRECV = IRECV+1
C skip sending of old position of specified view
      IF (ISEND .EQ. SPCPOS) ISEND = ISEND+1
C skip reception of new position of specified view
      IF (IRECV .EQ. NSPOS)  IRECV = IRECV+1
C check if done with loop
      IF (ISEND .GT. NDVI .OR. IRECV .GT. NDVI) GOTO 200
      EXPORD(IRECV) = CURORD(ISEND)
      GOTO 150

200   CONTINUE
C fill in last slot
      EXPORD(NSPOS) = CURORD(SPCPOS)

C  establish identity (not just position) of specified and reference view
      SPCVW = CURORD (SPCPOS)
      REFVW = CURORD (REFPOS)

C  invoke <set view transformation input priority> using
C        spcvw, refvw, relpri
      CALL PSVTIP (WKID, SPCVW, REFVW, RELPRI)

C  Use <inquire list of view indices> to determine
C        actord = actual order
      DO 300 IVW = 1,NDVI
         CALL PQEVWI (WKID, IVW, ERRIND, IDUM1, ACTORD(IVW))
         CALL CHKINQ ('pqevwi', ERRIND)
300   CONTINUE

C  pass/fail depending on (actord = expord)
      CALL IFPF (IAREQ (NDVI, ACTORD, EXPORD) )

      END
