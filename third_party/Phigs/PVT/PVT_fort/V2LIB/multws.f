      SUBROUTINE MULTWS (IWK, CATEG,
     1                   ONWK, OWKID, OCONID, OWTYPE, OWCAT)

C  Multws returns information about access to multiple workstations:
C
C  ------- Input parameters:
C  IWK     : requested element of list of available workstations
C            within requested categories (must be between 0 and ONWK).
C  CATEG   : Requested categories of workstation, according to the
C            following code:
C                o : OUTPUT
C                i : INPUT
C                d : OUTIN
C                m : MO (metafile output)
C                n : MI (metafile input)
C                a : all accessible workstations, regardless of category
C            Eg, to request all metafile workstations, specify 'mn';
C            to request all OUTPUT and OUTIN workstations, specify 'od'.
C
C  ------- Output parameters:
C  ONWK    : number of accessible workstations within the
C            requested categories.
C  OWKID   : workstation identifier for IWKth workstation
C  OCONID  : connection identifier for IWKth workstation
C  OWTYPE  : workstation type for IWKth workstation
C  OWCAT   : workstation category for IWKth workstation
C            (one character; see category codes under CATEG above).
C
C  This information is taken from the configuration file, which is
C  read only on the first invocation.  The three parameters for
C  opening the workstation when IWK=1 are identical to those of the
C  default workstation in COMMON: wkid, conid, wtype.

      SAVE

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

C dummy variables to read into - mostly skip 1st two records of config file
      INTEGER    DUMI(9), DUMJ(2)
      REAL       DUMR
      CHARACTER  DUMC1*60, DUMC2*20

      INTEGER    IWK, OWKID, OCONID, OWTYPE, LUN, IOERR, I, NWKSAV
      INTEGER    MAXWS, ONWK, WKCAT, SPECON, SPECWT
      PARAMETER (MAXWS = 100)
      INTEGER    MWKID (MAXWS), MCONID (MAXWS), MWTYPE (MAXWS)
      LOGICAL    RDFILE
      CHARACTER  FILENM*60, MSG*300, ERRPRF*30, CATEG*(*), OWCAT*1
      CHARACTER  MCAT(MAXWS)*1, CATCOD*6

      INTEGER    DOUTYP, DTCLIM, DINTYP, DSTDNR, SCRMOD
      REAL       DSIZE, MTRPDC, EFRAC

C workstation category
      INTEGER    POUTPT,     PINPUT,     POUTIN,     PMO,     PMI
      PARAMETER (POUTPT = 0, PINPUT = 1, POUTIN = 2, PMO = 3, PMI = 4)

      DATA       RDFILE / .FALSE. /

C check validity of CATEG
      IF (INDEX(CATEG, 'a') .GT. 0 .AND. LEN(CATEG) .GT. 1) THEN
         MSG = 'Invalid category ("a" is not alone) passed ' //
     1         'to MULTWS:' // CATEG
         CALL UNMSG (MSG)
      ENDIF

      CATCOD = 'oidmna'
      DO 20 I = 1, LEN(CATEG)
         IF (INDEX(CATCOD, CATEG(I:I)) .LE. 0) THEN
            MSG = 'Invalid category passed to MULTWS:' // CATEG
            CALL UNMSG (MSG)
         ENDIF
20    CONTINUE

C read file first time only
      IF (RDFILE) GOTO 100

C **********************************************************
C
CUSERMOD  NOTE: The following must be initialized to the absolute file
CUSERMOD  name for the system configuration file.  This must be
CUSERMOD  customized for each installation.  See the INITGL
CUSERMOD  subroutine, immediately above, and also the INITPH
CUSERMOD  program which writes the file.
C
C **********************************************************

      FILENM = '/home/cugini/pvt/work/v2.1/INITPH.DAT'

C *********************************************************
C
CUSERMOD  End of customization
C
C *********************************************************

C find unused unit number:
      IF (ABS(INDLUN - GLBLUN) .GE. 2) THEN
         LUN = (INDLUN+GLBLUN) / 2
      ELSE
         LUN = GLBLUN+2
      ENDIF

C prefix for error messages
      ERRPRF = 'MULTWS abort.  Error code for '

      OPEN  (UNIT=LUN, IOSTAT=IOERR, FILE=FILENM, STATUS='OLD',
     1       FORM='UNFORMATTED')
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I8)') ERRPRF // 'OPEN = ', IOERR
         CALL UNMSG (MSG)
      ENDIF
C  position at beginning of file
      REWIND(UNIT=LUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I8)') ERRPRF // 'REWIND = ', IOERR
         CALL UNMSG (MSG)
      ENDIF

C  skip past first two records
      READ (UNIT=LUN, IOSTAT=IOERR) DUMI(1), DUMC2
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I8)') ERRPRF // 'READ #1 = ', IOERR
         CALL UNMSG (MSG)
      ENDIF

      READ (UNIT=LUN, IOSTAT=IOERR) DOUTYP, DTCLIM, DINTYP, DSTDNR,
     1      DSIZE, EFRAC, SCRMOD, MTRPDC
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I8)') ERRPRF // 'READ #2 = ', IOERR
         CALL UNMSG (MSG)
      ENDIF

C get NWKSAV - number of accessible workstations
      READ (UNIT=LUN, IOSTAT=IOERR) DUMI, DUMC1, DUMJ, NWKSAV, DUMR
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I8)') ERRPRF // 'READ #3 = ', IOERR
         CALL UNMSG (MSG)
      ENDIF

C go thru accessible workstations and initialize arrays
      DO 50 I = 1,NWKSAV
         READ (UNIT=LUN, IOSTAT=IOERR)
     1         MWKID (I), MCONID (I), MWTYPE (I)
         IF (IOERR .NE. 0) THEN
            WRITE (MSG, '(A,I3,A,I8)') ERRPRF // 'wkst #', I,
     1             ' READ = ', IOERR
            CALL UNMSG (MSG)
         ENDIF

C determine category of workstation
         CALL PQWKCA (MWTYPE(I), ERRIND, WKCAT)
         IF (ERRIND.EQ.51) THEN
C generic no good - try to open wkstat and get category for specific type
            CALL POPWK  (MWKID (I), MCONID (I), MWTYPE (I))
            CALL PQWKC  (MWKID (I), ERRIND, SPECON, SPECWT)
            CALL CHKINQ ('pqwkc', ERRIND)
            CALL PQWKCA (SPECWT, ERRIND, WKCAT)
            CALL CHKINQ ('pqwkca', ERRIND)
            CALL PCLWK  (MWKID(I))
         ELSE
            CALL CHKINQ ('pqwkca', ERRIND)
         ENDIF

C encode category
         IF (WKCAT .GE. POUTPT .AND. WKCAT .LE. PMI) THEN
            MCAT (I) = CATCOD ( WKCAT+1 : WKCAT+1 )
         ELSE
C got invalid category
            MCAT (I) = 'x'
         ENDIF

50    CONTINUE

      CLOSE (UNIT=LUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I8)') ERRPRF // 'CLOSE = ', IOERR
         CALL UNMSG (MSG)
      ENDIF
C prevent re-reading of file
      RDFILE = .TRUE.

100   CONTINUE
C fill output parameters from array

C here are defaults:
      OWKID   = -1
      OCONID  = -1
      OWTYPE  = -1
      OWCAT   = '?'

      ONWK = 0
      DO 200 I = 1, NWKSAV
C skip if this wkst not in requested category-set
         IF (CATEG .NE. 'a' .AND. INDEX(CATEG, MCAT(I)) .LE. 0) GOTO 200
         ONWK = ONWK + 1
         IF (ONWK .EQ. IWK) THEN
C requested entry:
            OWKID   = MWKID  (I)
            OCONID  = MCONID (I)
            OWTYPE  = MWTYPE (I)
            OWCAT   = MCAT   (I)
         ENDIF
200   CONTINUE

      IF (IWK .LT. 0 .OR. IWK .GT. ONWK) THEN
         WRITE (MSG, '(A,I5)')
     1         'Requested workstation out of range in MULTWS:', IWK
         CALL UNMSG (MSG)
      ENDIF

      END
