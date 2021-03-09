C  FILE: sublib.f

C  This library of subroutines is meant to be used by the individual
C  programs of the PHIGS Validation Tests (PVT).  

C   Routines, in order:
C
C      SUBROUTINE initgl        : initialize globally
C    * SUBROUTINE xpopph        : Open PHIGS, allow implementor-dependent code
C    * SUBROUTINE multws        : access multiple workstation
C      SUBROUTINE setmsg        : set up pass/fail message
C      SUBROUTINE ifpf          : if _ then pass else fail
C      SUBROUTINE pass          : test case passed
C      SUBROUTINE fail          : test case failed
C      SUBROUTINE pf            : pass/fail common subroutine
C      SUBROUTINE chkinq        : check previous inquire
C      SUBROUTINE windup        : wind up this test
C      SUBROUTINE set2d         : set values in ragged 2d array
C      LOGICAL FUNCTION setis   : set is these values
C      LOGICAL FUNCTION seteq   : these sets are equal
C      SUBROUTINE setval        : set array to these values
C      SUBROUTINE setvs         : set array to integer values and get size
C      SUBROUTINE iniari        : like setvs, but report error
C      SUBROUTINE setrvs        : set array to real values and get size
C      LOGICAL FUNCTION iareq   : equality for two integer arrays
C      LOGICAL FUNCTION iareql  : equality for two integer lengths and arrays
C      LOGICAL FUNCTION rareq   : approximate equality for two real arrays
C      LOGICAL FUNCTION appeq   : approximate equality for two real numbers
C      INTEGER FUNCTION iarfnd  : find location of key value in integer array
C      SUBROUTINE cpyiar        : copy integer array
C      SUBROUTINE srtiar        : sort integer array
C      SUBROUTINE srtrar        : sort real array
C      SUBROUTINE prsint        : parse integer
C      SUBROUTINE prsuin        : parse unsigned integer
C      SUBROUTINE prsrl         : parse real
C      SUBROUTINE ncmsg         : unanticipated non-conformance message
C      SUBROUTINE unmsg         : unanticipated condition message
C      SUBROUTINE inmsg         : informational message
C    * SUBROUTINE abend         : abnormal ending
C      SUBROUTINE brdmsg        : broadcast message
C      SUBROUTINE opmsg         : send operator message, sans workstation
C      SUBROUTINE opyn          : get operator yes/no response
C      SUBROUTINE opint         : get operator integer response
C      SUBROUTINE oplin         : get operator one-line response
C      SUBROUTINE deblnk        : compress out blanks from string
C      INTEGER FUNCTION leadnb  : find leading non-blank in string
C      INTEGER FUNCTION itrim   : locate last non-blank
C      SUBROUTINE errctl        : Error-handling control
C      SUBROUTINE sigtst        : Test signalled error
C      SUBROUTINE sigmsg        : Signalled error message
C      SUBROUTINE erfucd        : get function code from name
C      SUBROUTINE erfunm        : get function name from code
C    * SUBROUTINE stdcss        : sets up standard CSS
C    * SUBROUTINE csspth        : sets up standard CSS for path testing
C    * LOGICAL FUNCTION csseq   : Is CSS .eq. to set of ER paths?
C    * LOGICAL FUNCTION strcon  : Is a structure .eq. to type-content sequence?
C    * SUBROUTINE setstr        : set up a structure in the CSS
C    * SUBROUTINE newstr        : find identifier for a non-existent structure
C    * SUBROUTINE gtroot        : Get CSS roots
C    * LOGICAL FUNCTION sphdis  : Does ISS use Euclidean metric?
C    * SUBROUTINE chkelp        : Check element pointer value
C    * SUBROUTINE avarnm        : get valid archive name

C  ----- Routines for interactive tests -----

C    * SUBROUTINE setdlg        : set up dialogue area for interactive test
C    * SUBROUTINE endit         : close everything and end program
C    * SUBROUTINE win6          : draws 6 labelled windows on the screen
C    * SUBROUTINE wcnpc         : converts from WC to NPC
C    * SUBROUTINE locppm        : draws polymarker at indexed y-location
C    * SUBROUTINE drwrec        : draw rectangle
C    * SUBROUTINE txexal        : return size, alignments of text rectangle
C    * LOGICAL FUNCTION intsty  : availability of interior styles
C    * SUBROUTINE denhat        : pick dense hatch style
C    * SUBROUTINE numlab        : draw numeric labels in a column
C    * SUBROUTINE vislab        : draw a text label in a box
C      SUBROUTINE dynpf         : pass/fail based on yes/no response
C      LOGICAL FUNCTION dyn     : get yes/no from operator
C      SUBROUTINE dchpf         : pass/fail based on location response
C      SUBROUTINE dchpfv        : pass/fail based on integer response
C      LOGICAL FUNCTION dchfl   : fail based on location response 
C      LOGICAL FUNCTION dchflv  : fail based on integer response
C      SUBROUTINE dchoic        : get integer choice from operator
C      SUBROUTINE dlstpf        : pass/fail based on integer list response
C      SUBROUTINE dilist        : get integer list from operator
C      SUBROUTINE drlval        : get real number from operator
C      SUBROUTINE dline         : get one-line string from operator
C      SUBROUTINE opfail        : get failure comment and do fail
C      SUBROUTINE opcofl        : get failure comment from operator
C      SUBROUTINE opcomt        : get neutral comment from operator
C      SUBROUTINE opco          : get operator comment
C      SUBROUTINE dstrng        : get multi-line string from operator
C      SUBROUTINE opmsgw        : put message to operator, and wait
C    * SUBROUTINE iacmsg        : put message to operator, no waiting
C    * SUBROUTINE iacans        : get single line response from operator
C    * SUBROUTINE setasf        : set all ASF's individual or bundled
C    * SUBROUTINE pstctl        : control posting of dialogue and picture
C      SUBROUTINE fitpar        : get line size to fit paragraph in rectangle
C      SUBROUTINE linbrk        : calculate line breaks for paragraph
C      SUBROUTINE scapar        : calculate scaling factor to fit paragraph
C      REAL FUNCTION ylocel     : calculate y position for inheritance tests
C      SUBROUTINE rn1shf        : random permutation for inheritance tests
C      SUBROUTINE rnperm        : random permutation of first n integers
C      SUBROUTINE rnset         : random set n integers, chosen from 1-max
C      SUBROUTINE rnbset        : random set n integers, chosen from m-n
C      INTEGER FUNCTION rndint  : random integer between two values
C      REAL FUNCTION rndrl      : random real between two values
C      REAL FUNCTION rnd01      : random real between 0 and 1

* interacts with PHIGS; not pure Fortran.

C  Invocation structure:

C                rareq                              chkelp
C                  |                                  |
C                  |                   ------------------------------
C                appeq                 |                   |        |
C                  |                 chkinq               pass    fail
C                  |                   |                   |        |
C                unmsg                 V                   V        V
C                  |
C                  V
C errctl                                                          sigtst
C                                                                   |
C                                                                   |
C                                          perhnd*   ---------------+-------
C                      csseq                 |  \    |     |        |      |
C            setval    / | \------------     |   \   |     |        |      |
C              |      /  |  \          |     |    sigmsg   |  ifpf  |      |
C       setis  |  set2d  |   gtroot    |     |             |  /  \  |      |
C       /   \  |  /   \  |  /      \   |     |    multws   | /    \ |      |
C   seteq    \ | /     \ | /         chkinq  |    setmsg  pass    fail   inmsg   initgl
C             \|/       \|/            |     |      |         \  /         |     / |
C              |         |             |------------|          pf*         |    /  |
C              | strcon  |             |            |           |          |   /   |
C              | /    |  |             |            ------------|          |  /    |
C  setstr    setvs    |  |             |                 |      |          | /     |
C    |   \ /   | \    |  |            ncmsg            unmsg    |          |/    opyn
C    |    X    |  \   |  |             |                 |      |          /      /
C    |   / \   |   \  |  |             -------------------      |         /      /
C  deblnk   prsint  \ |  |                |                     |        /      /
C              |     unmsg-->           abend*                  |       /      /
C              |                          |  \                  |      /      /
C           prsuin                        |   \                 |     /      /
C                                      windup  \                |    /      /
C                                         |     \               |   /      /
C           setrvs                        --------------------------      /
C              |                                    |                    /
C              |                                  brdmsg*               /
C           prsrl                                   |                  /
C                                                   -------------------
C                                                          |
C                                                        opmsg*

C  * not designed to be callable directly by test programs


C  Dictionary of variables used globally throughout PVT.
C
C  Variable   Type*   Description
C  --------   ----    -----------
C  conid      S  I    Connection identifier, for <open workstation>
C  ctlhnd     D  I    Tell PERHND whether to abort (0) or return (1)
C  dumch      S  C    Dummy character variables for future use
C  dumint     S  I    Dummy integer variables for future use
C  dumrl      S  R    Dummy real variables for future use
C  errind     D  I    Error indicator, returned from inquire functions
C  errfil     S  I    PHIGS error file, for <open phigs>
C  errsig     D  I    Signalled error code returned by PERHND
C  errsw      S  I    Indicates whether to send messages to operator
C  funcid     D  C    Function signalling the error, returned by PERHND
C  glberr     S  C    Absolute name of global message file
C  glblun     S  I    Logical unit number of global message file
C  ierrct     D  I    Count of errors detected by test
C  iflerr     S  I    Controls writing of messages to message files
C  indlun     S  I    Logical unit number of individual message file
C  maxlin     S  I    Maximum characters per line in messages
C  memun      S  I    Number of memory units, for <open phigs>
C  passsw     S  I    Controls writing/suppression of pass-messages
C  pident     D  C    Unique program identifier - hierarchical number
C  testct     D  I    Count of conditions tested so far within program
C  tstmsg     D  C    Text for next condition to be reported.
C  unerr      D  I    Count of unanticipated errors detected by test
C  wkid       S  I    Workstation id, for <open workstation>
C  wtype      S  I    Workstation type, for <open workstation>
C
C  * S: Static value read from configuration file
C    D: Dynamic variable, altered during test execution
C
C    I: Integer
C    C: Character
C    R: Real

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/initgl                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE INITGL (IDENT)

C  Initgl accepts the identifying hierarchical number of the test
C  program and initializes the GLOBAL COMMON variables, mostly from
C  values read from the INITPH.DAT file.  It then opens message
C  files as indicated by control variables.  This routine is
C  normally the first thing called by a test program.

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

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR, 
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80, 
     1                CONTAB(40)*150

      COMMON /OPCOMM/ OPHEAD
      CHARACTER  OPHEAD*300

      COMMON /RANCTL/ RLSEED
      REAL            RLSEED

      INTEGER    ITRIM, LUN, IOERR, IT, NWKSAV, IX

      CHARACTER  IDENT*(*), FILENM*60, INDERR*30
      CHARACTER  DUMREC*300, ANS*1, ERRPRF*30, IDCHAR*1

C check validity of IDENT
      IT = ITRIM(IDENT)
      IF (IT.LT.5) GOTO 60
      DO 50 IX = 1, IT
         IDCHAR = IDENT(IX:IX)
         IF (IX .EQ. IT-2) THEN
            IF (IDCHAR .NE. '/') GOTO 60
         ELSEIF (MOD(IX,3) .EQ. 0) THEN
            IF (IDCHAR .NE. '.') GOTO 60
         ELSE
            IF (IDCHAR.LT.'0' .OR. IDCHAR.GT.'9') GOTO 60
         ENDIF
50    CONTINUE
      GOTO 70

60    CONTINUE
      PRINT *, 'Format of program-identifier is invalid: ', IDENT
      STOP

70    CONTINUE

C *** *** *** ***  Initialize common for operator comment
      OPHEAD = 'NO TEST CASES YET:'

C *** *** *** ***  Initialize global common

C initialize global common from input parameter
      PIDENT = IDENT
      TSTMSG = ' '

C set error and test counts to 0
      UNERR  = 0
      IERRCT = 0
      TESTCT = 0

C set handler-control to default (perhnd reports and aborts).
      CTLHND = 0

C initialize global common from system configuration file

C filename and logical unit number for system configuration file.

C **********************************************************
C
CUSERMOD  NOTE: The following must be initialized to the absolute file
CUSERMOD  name for the system configuration file.  This must be
CUSERMOD  customized for each installation.  See the MULTWS
CUSERMOD  subroutine, immediately below, and also the INITPH
CUSERMOD  program which writes the file.
C
C **********************************************************

      FILENM = '/home/cugini/pvt/work/v2.1/INITPH.DAT'

C *********************************************************
C
CUSERMOD  End of customization
C
C *********************************************************

C  Use random unit number - no other files open yet, so should be OK.
      LUN = 21

      ERRPRF = 'INITGL abort.  Error code for '

      OPEN (UNIT=LUN, IOSTAT=IOERR, FILE=FILENM, STATUS='OLD',
     1      FORM='UNFORMATTED')
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'OPEN of configuration file = ', IOERR
         STOP
      ENDIF

C  position at beginning of file
      REWIND (UNIT=LUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'REWIND of configuration file = ', IOERR
         STOP
      ENDIF

      READ (UNIT=LUN, IOSTAT=IOERR) ERNMSW, ERRMRK
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'READ1 of configuration file = ', IOERR
         STOP
      ENDIF

      READ (UNIT=LUN, IOSTAT=IOERR) DOUTYP, DTCLIM, DINTYP, DSTDNR,
     1      DSIZE, EFRAC, SCRMOD, MTRPDC
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'READ2 of configuration file = ', IOERR
         STOP
      ENDIF

      READ (UNIT=LUN, IOSTAT=IOERR) ERRFIL, IFLERR, PASSSW, ERRSW,
     1     MAXLIN, CONID, MEMUN, WKID, WTYPE, GLBERR, GLBLUN, INDLUN,
     2     NWKSAV, RLSEED
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'READ3 of configuration file = ', IOERR
         STOP
      ENDIF

      CLOSE (UNIT=LUN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         PRINT *, ERRPRF, 'CLOSE of configuration file = ', IOERR
         STOP
      ENDIF

C *** *** ***  Initialize error-handling common area   *** *** *** 

C  set these to invalid values to make sure error handling routines
C  initialize them:
      ERRCOM = -1
      FUNCOM = -1
      FILCOM = -1
      EXPSIZ = -1
      DO 80 IT = 1,10
         EXPERR(IT) = -1
80    CONTINUE
      DO 90 IT = 1,200
         ERRSAV(IT) = -1
         FUNSAV(IT) = -1
         FILSAV(IT) = -1
90    CONTINUE

      ERRSRS = 'Un-initialized'
      ERFLNM = 'Un-initialized'
      CURCON = 'Un-initialized'
      CONTAB(1) =  'Un-initialized'

C  normal mode: NOT testing error handling.
      USRERR = 0

C *** *** *** ***  Initialize global common from operator, if necessary

      IF (PASSSW .EQ. 2) THEN
         CALL OPYN ('Generate run-time messages for successful ' //
     1              'conditions?', ANS)
         IF (ANS .EQ. 'y') THEN
            PASSSW = 1
         ELSE
            PASSSW = 0
         ENDIF
      ENDIF

C *** *** *** ***  Open message files, as needed.

      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3) THEN
C open global file for append
         OPEN (UNIT=GLBLUN, IOSTAT=IOERR, FILE=GLBERR, STATUS='OLD',
     1         FORM='FORMATTED')
         IF (IOERR .NE. 0) THEN
            PRINT *, ERRPRF, 'OPEN of global file = ', IOERR
            STOP
         ENDIF

800      FORMAT (A)

C *********************************************************
C
CUSERMOD  To make append work more efficiently, if desired, change
CUSERMOD  the following to system-specific magic code which will
CUSERMOD  open the global message file and position it after the
CUSERMOD  last record, to allow new records to be added.  The
CUSERMOD  routine above seems to be the only Fortran-standard way
CUSERMOD  to do it. 
C
C *********************************************************

C position at end-of-file
100      CONTINUE
         READ (UNIT=GLBLUN, FMT=800, IOSTAT=IOERR, END=200) DUMREC
         IF (IOERR .NE. 0) THEN
            PRINT *, ERRPRF, 'READ of global file = ', IOERR
            STOP
         ENDIF
         GOTO 100

200      CONTINUE
         BACKSPACE (UNIT=GLBLUN)

C *********************************************************
C
CUSERMOD  End of customization
C
C *********************************************************

      ENDIF

      IT = ITRIM(PIDENT)
      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3) THEN
C create individual message file
C generate file name
         INDERR = 'p' // PIDENT(IT-1:IT) // '.msg'
         OPEN (UNIT=INDLUN, IOSTAT=IOERR, FILE=INDERR, STATUS='UNKNOWN',
     1         FORM='FORMATTED')
         REWIND INDLUN
         IF (IOERR .NE. 0) THEN
            PRINT *, ERRPRF, 'OPEN of individual file = ', IOERR
            STOP
         ENDIF

      ENDIF

C Broadcast beginning-of-program message

      CALL BRDMSG ('SY: ------- Begin execution of PVT #' //
     1             PIDENT(1:IT) // ', version 2.2')

C  Following statement is never executed, but may help cause PERHND 
C  to be linked into executable module, as well as routines called
C  directly by PVT version of PERHND.
      IF (PIDENT .EQ. 'A bogus string value') THEN
         CALL UNMSG  ('This should never happen.')
         CALL NCMSG  ('This should never happen.')
         CALL SIGMSG (0, 'bogus function name', DUMREC)
         CALL ERFUNM (-1, FUNCID)
         CALL PERHND (0, 0, 0)
      ENDIF

666   CONTINUE
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/xpopph                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE XPOPPH (ERRPRM, MEMPRM)

C XPOPPH serves to open PHIGS on the system under test.

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

      INTEGER     ERRPRM, MEMPRM

CUSERMOD If needed, insert implementation-dependent code before
CUSERMOD opening PHIGS.

      CALL POPPH (ERRPRM, MEMPRM)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/multws                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/setmsg                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETMSG (SRLIST, MSG)

C  Setmsg parses the srlist (a list of semantic requirements), accepts an
C  associated message describing the condition about to be tested, and
C  sets the COMMON variable tstmsg to a resulting value, to be issued by
C  either pass or fail, whichever is next executed.

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

      INTEGER    ITRIM, IT, LOC, LIM, IDIG

      CHARACTER  SRLIST*(*), MSG*(*), FIXSR*80, TERM*1, CH*1

C  Both pass and fail blank out tstmsg as a sign that they have processed
C  it, and so setmsg requires that it be blank upon entry.

      IF (TSTMSG .NE. ' ') CALL UNMSG ('Non-blank tstmsg detected ' //
     1                     'by setmsg.  Program logic error.')

C srlist must be a list of 1 or 2-digit numbers separated by spaces.
C This routine edits out extra spaces and leading zeros.

C term is an "unusual" character, used to terminate string
      TERM  = CHAR (15)
      FIXSR = ' ' // SRLIST
      IT    = ITRIM(FIXSR) + 1
      FIXSR (IT:IT) = TERM

C edit out extra spaces - we assume fixsr is longer than srlist and has
C some trailing spaces.
100   CONTINUE
      LOC = INDEX(FIXSR, '  ')
      LIM = INDEX(FIXSR, TERM)
      IF (LOC .GT. 0 .AND. LOC .LT. LIM) THEN
         FIXSR(LOC:) = FIXSR(LOC+1:)
         GOTO 100
      ENDIF
C edit out leading zeros
200   CONTINUE
      LOC = INDEX(FIXSR, ' 0')
      IF (LOC .GT. 0) THEN
         FIXSR(LOC+1:) = FIXSR(LOC+2:)
         GOTO 200
      ENDIF

C should be only digits and spaces
      LOC = 0
      IDIG = 0
300   CONTINUE
      LOC = LOC+1
      CH = FIXSR(LOC:LOC)
      IF (CH .EQ. TERM) GOTO 400
      IF (CH .EQ. ' ')  GOTO 300
      IF (CH .GE. '0' .AND. CH .LE. '9') THEN
         IDIG = 1
         GOTO 300
      ENDIF
C Illegal character in parameter - bomb this test
      CALL UNMSG('Illegal character in setmsg srlist-parameter.')

400   CONTINUE
      IF (IDIG .EQ. 0) CALL UNMSG ('No digits found in setmsg ' //
     1                 'srlist-parameter.')

C OK, fixsr looks valid...
      LIM = INDEX(FIXSR, TERM) - 1

C set up pass/fail message
      TSTMSG = '#SR' // FIXSR(1:LIM) // ', ' // MSG

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/ifpf                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE IFPF (COND)

C  Ifpf simply provides a short form for the typical coding: if
C  (condition) then pass else fail.

      LOGICAL  COND

      IF (COND) THEN
         CALL PASS
      ELSE
         CALL FAIL
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/pass                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PASS

C  pass handles the processing of a pass-condition.

      CALL PF ('p')

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/fail                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE FAIL

C  pass handles the processing of a fail-condition.

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

      IERRCT = IERRCT+1
      CALL PF ('f')

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/pf                                   *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PF (RESULT)

C  pf handles the processing of the pass/fail condition.

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

      CHARACTER  MSGTYP*4, CONDVB*10, RESULT*1, ACOND*3, BUF*999

      IF (.NOT. (RESULT.EQ.'p' .OR. RESULT.EQ.'f'))
     1   CALL UNMSG ('Input parameter to pf neither p nor f.')

      IF (TSTMSG .EQ. ' ')
     1   CALL UNMSG ('Blank tstmsg detected by pf.  ' //
     2               'Program logic error.')

      TESTCT = TESTCT + 1
      WRITE (ACOND, '(I3)') TESTCT

      IF (RESULT .EQ. 'p') THEN
         MSGTYP = 'OK: '
         CONDVB = ' passed:  '
      ELSE
         MSGTYP = 'FA: '
         CONDVB = ' failed:  '
      ENDIF
      BUF = MSGTYP // 'Condition #' // ACOND // CONDVB // TSTMSG

C blank out tstmsg to signify use by pass/fail.
      TSTMSG = ' '

C optional suppression of pass-messages done here.
      IF (RESULT .EQ. 'f' .OR. PASSSW .EQ. 1) CALL BRDMSG (BUF)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/chkinq                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CHKINQ (ROUTNM, IERRCD)

C  Chkinq is used to check that inquire-functions have returned a value
C  of zero as the error code.  It is normally called after invoking an
C  inquire which is being used incidentally, i.e., one which is NOT the
C  object of interest of the test, but rather one whose returned values
C  are needed to test OTHER functions.  Nonetheless, the failure of such
C  an inquire is a failure of the implementation, since these inquires
C  are called only in circumstances when they should work.

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

      INTEGER    ITRIM, IERRCD

      CHARACTER  ROUTNM*(*), BUF*200, AERR*9

      IF (IERRCD .EQ. 0) RETURN
      WRITE (AERR, '(I9)' ) IERRCD

      BUF = 'Unexpected error in ' // PIDENT(1:ITRIM(PIDENT)) //
     1      ', Function = "' // ROUTNM // '", Error code = ' //
     2      AERR // '.'
      CALL NCMSG (BUF)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/windup                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE WINDUP

C  Windup handles end-of-test processing - it formulates two
C  messages, one with the total error count, the second to proclaim
C  end of execution.  If there has been an unanticipated error it
C  also generates a message for that.  It then closes the error
C  files, as needed.  It is normally the last thing called by a
C  test.

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

      INTEGER    ITRIM, ISZ, ICSZ

      CHARACTER AERRCT*3, ATSTCT*3, ERR*7, CWORD*11

      ERR   = ' errors'
      CWORD = ' conditions'

      WRITE (AERRCT, '(I3)') IERRCT
      WRITE (ATSTCT, '(I3)') TESTCT
      IF (IERRCT .EQ. 1) THEN
         ISZ = 6
      ELSE
         ISZ = 7
      ENDIF
      IF (TESTCT .EQ. 1) THEN
         ICSZ = 10
      ELSE
         ICSZ = 11
      ENDIF

      CALL BRDMSG ('SY: SUMMARY of PVT #' // PIDENT(1:ITRIM(PIDENT)) //
     1             ' : ' // AERRCT // ERR(1:ISZ) //
     2             ' detected, out of ' // ATSTCT //
     3             CWORD(1:ICSZ) // '.')

      IF (UNERR .NE. 0) THEN
         WRITE (AERRCT, '(I3)') UNERR
         IF (UNERR .EQ. 1) THEN
            ISZ = 6
         ELSE
            ISZ = 7
         ENDIF
         CALL BRDMSG ('SY: Encountered ' // AERRCT //
     1                ' unanticipated' // ERR(1:ISZ) // '.')
      ENDIF

C  Both pass and fail blank out tstmsg as a sign that they have processed
C  it, and so windup requires that it be blank upon entry.

      IF (TSTMSG .NE. ' ') CALL INMSG ('Non-blank tstmsg detected ' //
     1                     'by WINDUP.  Program logic error.')

      CALL BRDMSG ('SY: ------- End execution of PVT #' // PIDENT)
      CALL BRDMSG ('.')
      CALL BRDMSG ('.')
      CALL BRDMSG ('.')

C close error files

      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3) THEN
C close global file
         CLOSE (UNIT=GLBLUN)
      ENDIF

      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3) THEN
C close individual error file
         CLOSE (UNIT=INDLUN)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/set2d                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SET2D (VALS, MAXCOL, NOCOLS, COLLEN, ARR)

C  Set2d is used to initialize a ragged 2D array of integers, based
C  on an input string.
C
C  --- Input Parameter:
C  vals      : Input string, with integer values.  Values separated by
C              commas, array columns terminated by slashes.
C  maxcol    : Maximum column size = size of first dimension of 2D array.
C  --- Output parameters:
C  nocols    : Number of columns initialized
C  collen    : 1D array of lengths of each column
C  arr       : 2D array of integers

C  Syntax of vals:
C  vals         = column*
C  column       = col-values "/"
C  col-values   = " " | integer-list
C  integer-list = integer | integer "," integer-list

      CHARACTER  VALS*(*), WK*2000

      INTEGER    NOCOLS, MAXCOL, COLLEN(*), ARR(MAXCOL,*)
      INTEGER    ITRIM, SLPOS, LAST

      IF (LEN(VALS) .GT. 1998) THEN
         CALL UNMSG ('String passed to SET2D exceeds length of ' //
     1               'work area.')
      ENDIF

C no columns so far
      NOCOLS = 0

C blank means no columns at all
      IF (VALS .EQ. ' ') RETURN
C check for terminating slash
      LAST = ITRIM(VALS)
      IF (VALS(LAST:LAST) .NE. '/') THEN
         CALL UNMSG
     1        ('String sent to set2d does not terminate with slash.')
      ENDIF
      WK = ' ' // VALS

C begin a new column
100   CONTINUE
      SLPOS = INDEX (WK, '/')

C put next column and its length in arrays
      NOCOLS = NOCOLS+1
      CALL SETVS (WK(1:SLPOS-1), ARR(1, NOCOLS), COLLEN(NOCOLS))
      IF (COLLEN(NOCOLS) .GT. MAXCOL) THEN
          WK = 'Column passed to set2d exceeds maximum length: ' //
     1         WK(1:SLPOS-1)
          CALL UNMSG (WK)
      ENDIF
C delete encoded column - set up for next; ensure one blank
      WK = ' ' // WK (SLPOS+1: )
C any more columns ?
      IF (WK .NE. ' ') GOTO 100

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/setis                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION SETIS (ARR, ST)

C  setis compares the contents of the integer array ARR with the set
C  of integers encoded in the character string ST and returns .true.
C  iff the leading elements of ARR contain exactly those values *in
C  any order*.  ST contains integer-like strings separated by
C  commas, e.g. "3, +4, -5".

      INTEGER    ARRSIZ
      PARAMETER (ARRSIZ = 500)
      INTEGER    ARR(*), WK(ARRSIZ), NSZ

      CHARACTER ST*(*)
      LOGICAL   SETEQ

C  store ST values in WK array; NSZ is number of values
      CALL SETVS (ST, WK, NSZ)
      IF (NSZ .GT. ARRSIZ) THEN
         CALL UNMSG ('Number of values in string passed to SETIS ' //
     1               'exceeds size of work area.')
      ENDIF
C  compare the two arrays
      SETIS = SETEQ (NSZ, ARR, WK)

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/seteq                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION SETEQ (N, A, B)

C  seteq compares the contents of the first N elements of two
C  arrays, A and B.  If they contain the same elements *in any
C  order*, seteq returns .true., else .false.

      INTEGER    ARRSIZ
      PARAMETER (ARRSIZ = 5000)
      INTEGER    N, I,J, A(*), B(*), WK(ARRSIZ), WKLEFT

      IF (N .GT. ARRSIZ) THEN
         CALL UNMSG ('Size of array passed to SETEQ exceeds size ' //
     1               'of work area.')
      ENDIF

C save contents of B in WK, so as not to clobber B
      DO 50 I = 1,N
         WK(I) = B(I)
50    CONTINUE

      WKLEFT = N
C check all elements of A
      DO 100 I = 1,N
C against remaining elements of WK
      DO 200 J = 1,WKLEFT
         IF (A(I) .EQ. WK(J)) THEN
            WK(J) = WK(WKLEFT)
            WKLEFT = WKLEFT - 1
            GOTO 100
         ENDIF
200   CONTINUE
      SETEQ = .FALSE.
      RETURN
100   CONTINUE
      SETEQ = .TRUE.

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/setval                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETVAL (ST, ARR)

C  setval initializes the integer array ARR, based on the
C  value-representations in ST.

      CHARACTER ST*(*)
      INTEGER   ARR(*), NSZ

      CALL SETVS (ST, ARR, NSZ)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/setvs                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETVS (ST, ARR, NSZ)

C  SETVS initializes the integer array ARR, based on the
C  value-representations in ST and also returns the number
C  of values in NSZ.  SETVS is meant to be called to parse
C  strings generated directly by other PVT code, and thus
C  aborts on invalid strings.  To handle strings from operator,
C  use INIARI directly.

      CHARACTER ST*(*), TMPMSG*300
      INTEGER   ARR(*), NSZ, IERR

      CALL INIARI (ST, ARR, NSZ, IERR)

      IF (IERR .NE. 0) THEN
         TMPMSG = 'Invalid string sent to SETVS: ' // ST
         CALL UNMSG (TMPMSG)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/iniari                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE INIARI (ST, ARR, NSZ, IERR)

C  INIARI initializes the integer array ARR, based on the
C  value-representations in ST and also returns the number
C  of values in NSZ.  INIARI does not abort when faced with
C  an invalid string, just returns a non-zero error code in IERR.

      CHARACTER ST*(*), STWK*700
      INTEGER   ARR(*), NSZ, LST, NC, IVAL, IERR

      NSZ = 0
      IERR = 0

C blank means zero entries
      IF (ST .EQ. ' ') RETURN

C get rid of leading, internal blanks
      CALL DEBLNK (ST, STWK, LST)

300   CONTINUE
C add trailing comma
      LST = LST+1
      STWK(LST:LST) = ','

C now sitting at alleged number
400   CONTINUE
C find next comma
      NC = INDEX(STWK, ',')
      IF (NC .LE. 1) THEN
         IERR = 1
         RETURN
      ENDIF
C parse up to comma
      CALL PRSINT (STWK(1:NC-1), IVAL, IERR)
      IF (IERR .NE. 0) THEN
         IERR = 100 + IERR
         RETURN
      ENDIF
C add new entry to array
      NSZ = NSZ+1
      ARR(NSZ) = IVAL
C delete thru comma
      STWK = STWK(NC+1:)
      IF (STWK .NE. ' ') GOTO 400

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/setrvs                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETRVS (ST, ARR, NSZ)

C  setrvs initializes the real array ARR, based on the
C  value-representations in ST and also returns the number
C  of values in NSZ.

      CHARACTER ST*(*), STWK*700, TMPMSG*730
      INTEGER   NSZ, LST, NC, IERR
      REAL      ARR(*), RVAL

      NSZ = 0

C blank means zero entries
      IF (ST .EQ. ' ') RETURN

C get rid of leading, internal blanks
      CALL DEBLNK (ST, STWK, LST)

300   CONTINUE
C add trailing comma
      LST = LST+1
      STWK(LST:LST) = ','

C now sitting at alleged number
400   CONTINUE
C find next comma
      NC = INDEX(STWK, ',')
      IF (NC .LE. 1) THEN
         CALL UNMSG ('Adjacent commas passed to SETRVS.')
      ENDIF
C parse up to comma
      CALL PRSRL (STWK(1:NC-1), RVAL, IERR)
      IF (IERR .NE. 0) THEN
         TMPMSG = 'Invalid string sent to SETRVS: ' // ST
         CALL UNMSG (TMPMSG)
      ENDIF
      NSZ = NSZ+1
      ARR(NSZ) = RVAL
C delete thru comma
      STWK = STWK(NC+1:)
      IF (STWK .NE. ' ') GOTO 400

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/iareq                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION IAREQ (SIZE, ACT,EXP)

C  General purpose routine for equality of two integer arrays.
C  ------- Input parameters:
C  size    : Number of elements to be compared
C  act     : actual values
C  exp     : expected values

C  This will handle multi-dimensional arrays according to the usual
C  Fortran rules for overlaying arrays.

      INTEGER  SIZE, IX, ACT(*), EXP(*)

      DO 100 IX = 1,SIZE
         IF (ACT(IX) .NE. EXP(IX)) THEN
            IAREQ = .FALSE.
            RETURN
         ENDIF
100   CONTINUE
      IAREQ = .TRUE.

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/iareql                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION IAREQL (SIZEA, ARRA, SIZEB, ARRB)

C  General purpose routine for equality of two variable-length
C  integer lists.
C  ------- Input parameters:
C  sizea   : size of first list
C  arra    : contents of first list
C  sizeb   : size of second list
C  arrb    : contents of second list

C  This will handle multi-dimensional arrays according to the usual
C  Fortran rules for overlaying arrays.

      INTEGER  SIZEA, ARRA(*), SIZEB, ARRB(*)
      LOGICAL  IAREQ

      IF (SIZEA .EQ. SIZEB) THEN
         IAREQL = IAREQ (SIZEA, ARRA, ARRB)
      ELSE
         IAREQL = .FALSE.
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/rareq                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION RAREQ (SIZE, ACT,EXP, ABSERR, RELERR)

C  General purpose routine for approximate equality of two real arrays.
C  ------- Input parameters:
C  size    : Number of elements to be compared
C  act     : actual values
C  exp     : expected values
C  abserr  : absolute tolerance
C  relerr  : relative tolerance

C  This will handle multi-dimensional arrays according to the usual
C  Fortran rules for overlaying arrays.

      INTEGER  SIZE, IX
      REAL     ACT(SIZE), EXP(SIZE), ABSERR, RELERR
      LOGICAL  APPEQ

      DO 100 IX = 1,SIZE
         IF (APPEQ ( ACT(IX), EXP(IX), ABSERR, RELERR)) THEN
C OK so far
         ELSE
            RAREQ = .FALSE.
            RETURN
         ENDIF
100   CONTINUE
      RAREQ = .TRUE.

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/appeq                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION APPEQ (ACT,EXP, ABSERR, RELERR)

C  General purpose routine for approximate equality of two real-numbers.
C  The 1st parameter is the actual value, the 2nd, the expected value.
C  Tests as true iff:
C     1. absolute error of act wrt exp .le. abserr, OR
C     2. relative error of act wrt exp .le. relerr

      REAL ACT,EXP, ABSERR, RELERR, ABDIF

      IF (ABSERR .LT. 0.0 .OR. RELERR .LT. 0.0) THEN
         CALL UNMSG ('Negative tolerance passed to APPEQ.')
      ENDIF

      ABDIF = ABS(ACT-EXP)

C note that this expression is "safe" even if act or exp is zero.

      APPEQ = (ABDIF .LE. ABSERR)   .OR.
     1        (ABDIF .LE. ABS(RELERR*EXP) )

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION GL/iarfnd                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      INTEGER FUNCTION IARFND (KEY, ARSIZ, IARR)

C  IARFND searches the first ARSIZ entries within IARR, and returns
C  the first location equal to KEY. If not found, 0 is returned.

      INTEGER   IX, KEY, ARSIZ, IARR(*)

      DO 100 IX = 1,ARSIZ
         IF (IARR(IX) .EQ. KEY) THEN
            IARFND = IX
            RETURN
         ENDIF
100   CONTINUE
      IARFND = 0

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/cpyiar                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CPYIAR (SIZE,FROM,TO)

C  CPYIAR copies the contents of an array of a given size to
C  another array.

C  Input parameters:
C    SIZE : number of elements to copy
C    TO   : source array
C  Output parameter:
C    FROM : destination array

      INTEGER   SIZE,I
      REAL      FROM(*), TO(*)

      DO 100 I = 1, SIZE
        TO(I) = FROM(I)
100   CONTINUE
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/srtiar                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SRTIAR (SIZ, ARR)

C  SRTIAR sorts an integer array in place, into ascending order.
C
C  Input parameter:
C    SIZ : number of elements in array to be sorted.
C  Input/output parameter:
C    ARR : the array of integers to be sorted.

      INTEGER   SIZ, ARR(SIZ), I,J,TMP

      DO 100 I = 1,SIZ-1
      DO 200 J = I+1,SIZ
         IF (ARR(I) .GT. ARR(J)) THEN
            TMP    = ARR(I)
            ARR(I) = ARR(J)
            ARR(J) = TMP
         ENDIF
200   CONTINUE
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/srtrar                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SRTRAR (SIZ, ARR)

C  SRTRAR sorts a real array in place, into ascending order.
C
C  Input parameter:
C    SIZ : number of elements in array to be sorted.
C  Input/output parameter:
C    ARR : the array of integers to be sorted.

      INTEGER   SIZ, I,J
      REAL      ARR(SIZ), TMP

      DO 100 I = 1,SIZ-1
      DO 200 J = I+1,SIZ
         IF (ARR(I) .GT. ARR(J)) THEN
            TMP    = ARR(I)
            ARR(I) = ARR(J)
            ARR(J) = TMP
         ENDIF
200   CONTINUE
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/prsint                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PRSINT (STR, IVAL, IERR)

C  Prsint parses a possibly signed integer.  Assumes no leading spaces.
C  The value is returned in IVAL, and IERR gets a non-zero code if
C  something goes wrong.

      CHARACTER  STR*(*)
      INTEGER    IVAL, IERR, ISIGN, LST

      ISIGN = INDEX ('+-', STR(1:1))
      LST = LEN(STR)
      IF (ISIGN .EQ. 0) THEN
C unsigned
         CALL PRSUIN (STR, IVAL, IERR)
      ELSE
C signed
         IF (LST .LE. 1) THEN
C no digits
            IERR = 50
         ELSE
            CALL PRSUIN (STR(2:), IVAL, IERR)
            IF (ISIGN .EQ. 2) IVAL = -IVAL
         ENDIF
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/prsuin                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PRSUIN (STR, IVAL, IERR)

C  Prsuin parses an unsigned integer.  Assumes no leading spaces.
C  The value is returned in IVAL, and IERR gets a non-zero code if
C  something goes wrong.

      CHARACTER  STR*(*)
      INTEGER    IVAL, IERR, LST, ITOT, I, IDIG, ITRIM

      LST = ITRIM(STR)
      IF (LST .LE. 0) THEN
         IERR = 2
         RETURN
      ENDIF
      ITOT = 0
      DO 100 I = 1,LST
         IDIG = INDEX('0123456789', STR(I:I)) - 1
         IF (IDIG .GE. 0 .AND. IDIG .LE. 9) THEN
            ITOT = 10*ITOT + IDIG
         ELSE
            IERR = 1
            RETURN
         ENDIF
100   CONTINUE
      IERR = 0
      IVAL = ITOT

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/prsrl                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PRSRL (STR, RVAL, IERR)

C  Prsrl parses a real number.  Assumes no leading spaces.
C  The value is returned in RVAL, and IERR gets a non-zero code
C  if something goes wrong.

      CHARACTER   STR*(*), WSTR*18
      INTEGER     POSDEC, POSEXP, ITRIM, SZSTR, IERR
      REAL        RVAL

      SZSTR = ITRIM(STR)
      RVAL  = -666.666
      IF (SZSTR .GT. 15) THEN
         IERR = -3
         RETURN
      ENDIF

      POSDEC = INDEX(STR, '.')
      IF (POSDEC .LE. 0) THEN
C No explicit decimal
         POSEXP = INDEX(STR, 'E')
         IF (POSEXP .LE. 0) THEN
C No explicit exponent
            WSTR = STR(1:SZSTR) // '.0'
         ELSE
            WSTR = STR(1:POSEXP-1) // '.0' // STR(POSEXP:SZSTR)
         ENDIF
         SZSTR = SZSTR + 2
      ELSE
C Explicit decimal
         WSTR = STR
      ENDIF

      READ (WSTR, '(F18.2)', IOSTAT = IERR) RVAL

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/ncmsg                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE NCMSG (MSG)

C NCMSG is used to generate messages for unanticipated errors
C which imply non-conformance of the implementation under test.
C It then forces a program abort.

      CHARACTER  MSG*(*)

      CALL ABEND ('NC', MSG)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/unmsg                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE UNMSG (MSG)

C UNMSG is used to generate messages for unanticipated errors
C which do not imply non-conformance of the implementation under test.
C It then forces a program abort.

      CHARACTER  MSG*(*)

      CALL ABEND ('UN', MSG)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/inmsg                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE INMSG (MSG)

C INMSG is used to generate informational messages.

      CHARACTER  MSG*(*), BUF*900

      BUF = 'IN: ' // MSG
      CALL BRDMSG (BUF)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/abend                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ABEND (SVRTY, MSG)

C Abend handles program-aborting messages.

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

      CHARACTER  MSG*(*), BUF*900, SVRTY*2

      UNERR = UNERR+1
      BUF = SVRTY // ': Program ABORT.  ' // MSG
      CALL BRDMSG (BUF)

      IF (SVRTY .NE. 'UN' .AND. SVRTY .NE. 'NC') THEN
         UNERR = UNERR+1
         CALL BRDMSG ('UN: unknown severity code passed to abend = '
     1                // SVRTY)
      ENDIF

C wrap it up - emergency close
      CALL PECLPH
C blank out tstmsg to prevent spurious informational message from windup
      TSTMSG = ' '
C kill program
      CALL WINDUP
      STOP

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/brdmsg                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE BRDMSG (MSG)

C Brdmsg broadcasts a message to various destinations.  It uses
C variables in common to control how it issues the message passed to it.

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

      INTEGER    ITRIM, IB, ISP, LSTLIN

      CHARACTER  MSG*(*), BUF*999, MSGLIN*300

C leading space is as Fortran carriage control character.
      BUF   = ' ' // MSG

C  This loop breaks up msg into chunks of size .le. maxlin.  It also
C  puts 5 spaces to the start of each non-first line, so that message-type
C  will stand out.

100   CONTINUE

      DO 200 IB = MAXLIN+1, 1, -1
         IF (BUF(IB:IB) .EQ. ' ') THEN
            ISP = IB
            GOTO 210
         ENDIF
200   CONTINUE
      ISP = MAXLIN
210   CONTINUE
C isp now points to a line-breaking space.

      MSGLIN = BUF (1:ISP-1)
      LSTLIN = ITRIM(MSGLIN)

C ensure *at least* 5 spaces in start of buf.
      BUF    = '     ' // BUF (ISP+1:)

C Message to operator
      IF (ERRSW .EQ. 1) THEN
         CALL OPMSG (MSGLIN (1:LSTLIN))
      ENDIF

800   FORMAT(A)

C Message to files
      IF (IFLERR .EQ. 1 .OR. IFLERR .EQ. 3) THEN
C append to global file
         WRITE (GLBLUN, 800) MSGLIN (1:LSTLIN)
      ENDIF

      IF (IFLERR .EQ. 2 .OR. IFLERR .EQ. 3) THEN
C add to individual file
         WRITE (INDLUN, 800) MSGLIN (1:LSTLIN)
      ENDIF

C any more non-blanks to send out?  If not, quit.
      IF (BUF .EQ. ' ') GOTO 666

C ensure *exactly* 5 leading blanks
300   CONTINUE
      IF (BUF(6:6) .NE. ' ') GOTO 100
      BUF = BUF(2:)
      GOTO 300

666   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/opmsg                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPMSG (MSG)

C  OPMSG writes out a message to the operator.  No assumptions are
C  made that a workstation is open.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      INTEGER     NXT, ITRIM, IX, IY, MLEN, LASTB

      CHARACTER   MSG*(*)
                       
      IF (MSG .EQ. ' ') THEN
         PRINT *, ' '
         RETURN
      ENDIF

C  set IX,LASTB to start, end of substring to be printed
      IX = 1
      MLEN = ITRIM(MSG)

100   CONTINUE
      IF (MLEN-IX .LT. MAXLIN) THEN
         PRINT *, MSG(IX:MLEN)
         RETURN
      ENDIF

      DO 200 IY = IX+MAXLIN, IX, -1
         IF (MSG(IY:IY) .EQ. ' ') THEN
            LASTB = IY
            NXT = LASTB+1
            GOTO 210
         ENDIF
200   CONTINUE

      LASTB = IX+MAXLIN
      NXT = LASTB

210   CONTINUE
      PRINT *, MSG(IX:LASTB-1)
      IX = NXT
      GOTO 100

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/opyn                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPYN (PROMPT, ANS)

C opyn gets a yes or no reply from operator - encoded as y or n.

      CHARACTER PROMPT*(*), ANS*1, BUF*132

800   FORMAT(A)

100   CONTINUE
      BUF = PROMPT // ' (y or n)'
      CALL OPMSG (BUF)
      READ (*, 800) ANS
      IF (ANS .EQ. 'y' .OR. ANS .EQ. 'n') RETURN
      CALL OPMSG ('Response must be y or n.')
      GOTO 100

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/opint                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPINT (IANS)

C  OPINT gets an integer response from the operator.

      INTEGER    IANS, LEADNB, ITRIM, IERR
      CHARACTER  CANS*40

10    CONTINUE
      CALL OPLIN (CANS)
      IF (CANS .EQ. ' ') THEN
         CALL OPMSG ('Response must be a non-blank valid integer.  ' //
     1               'Re-enter.')
         GOTO 10
      ENDIF

      CALL PRSINT (CANS(LEADNB(CANS):ITRIM(CANS)), IANS, IERR)
      IF (IERR .NE. 0) THEN
         CALL OPMSG ('Response must be a non-blank valid integer.  ' //
     1               'Re-enter.')
         GOTO 10
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/oplin                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPLIN (ANS)

C  OPLIN gets a single-line response from the operator.

      CHARACTER ANS*(*)

      READ (*, 800) ANS
800   FORMAT(A)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/deblnk                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DEBLNK (STRIN, STROUT, NEWSIZ)

C  deblnk accepts a string (strin) and generates from it another
C  string (strout) with all leading and internal blanks deleted. It
C  also returns the new size of the compressed string as newsiz,
C  which points to the last non-blank (0 if all blank).

      CHARACTER  STRIN*(*), STROUT*(*)
      INTEGER    NEWSIZ, ITRIM, IX, NBLEN, NBLOC, RECV

      STROUT = ' '
      NBLOC  = 0
      NBLEN  = 1
      RECV   = 1

100   CONTINUE
C get next sending non-blank
      DO 200 IX = NBLOC+NBLEN, LEN(STRIN)
         IF (STRIN(IX:IX) .NE. ' ') THEN
            NBLOC = IX
            GOTO 210
         ENDIF
200   CONTINUE
C no more non-blanks
      GOTO 300

C send next non-blank field
210   CONTINUE
      STROUT (RECV:) = STRIN(NBLOC:)

C more blanks to compress out?
      NBLEN = INDEX(STRIN(NBLOC:), ' ') - 1
      IF (NBLEN .EQ. -1) THEN
C        all done
      ELSE
C set recv
         RECV = RECV + NBLEN
         GOTO 100
      ENDIF

300   CONTINUE
      NEWSIZ = ITRIM(STROUT)

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION GL/leadnb                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      INTEGER FUNCTION LEADNB (TXT)

C  LEADNB returns the character position of the first (leftmost)
C  non-blank character within TXT.  If there is none, 0 is returned.

      INTEGER    LO,HI,MID
      CHARACTER  TXT*(*)

      IF (TXT .EQ. ' ') THEN
         LEADNB = 0
         RETURN
      ENDIF

C  LO always points to a location *before* the first non-blank,
C  HI to a location *at or after* the first non-blank.
      LO = 0
      HI = LEN(TXT)

100   CONTINUE
      IF (HI-LO .LE. 1) GOTO 666
      MID = (HI+LO)/2
      IF (TXT(1:MID) .EQ. ' ') THEN
         LO = MID
      ELSE
         HI = MID
      ENDIF
      GOTO 100

666   CONTINUE
      LEADNB = HI
      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION GL/itrim                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      INTEGER FUNCTION ITRIM (WORD)

C itrim returns the position of the rightmost non-blank within
C a string, zero if all blank.

      INTEGER   LW, ILO, IHI, IMID

      CHARACTER WORD*(*)

      LW  = LEN(WORD)
      ILO = 0
      IHI = LW+1

C do binary search looking for trailing blank portion of word
100   CONTINUE
      IF (IHI-ILO .LE. 1) GOTO 666
      IMID = (IHI+ILO)/2
      IF (WORD(IMID:) .EQ. ' ') THEN
         IHI = IMID
      ELSE
         ILO = IMID
      ENDIF
      GOTO 100

666   CONTINUE
      ITRIM = ILO

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/errctl                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ERRCTL (LOCCTL)

C  Errctl is called by test programs to control whether or not perhnd
C  should handle signalled errors and abort (locctl = .false.) or rather
C  should simply return error information (locctl = .true.) in the
C  COMMON variables errsig and funcid.

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

C Should there be local control over signalled errors?
      LOGICAL LOCCTL

      IF (LOCCTL) THEN
         CTLHND = 1
         ERRSIG = 0
         FUNCID = ' '
      ELSE
         CTLHND = 0
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/sigtst                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SIGTST (EXPSIG, FAILED)

C  Sigtst is used to compare an signalled error code with an expected
C  value.  If not equal, failure and informative messages are generated,
C  including the error code and function name.  If equal, pass is
C  invoked.

C  Input parameter:
C    EXPSIG : expected value of error code (usually 0)
C  Output parameter
C    FAILED : true if expected not equal to actual, else false

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

      INTEGER    EXPSIG
      CHARACTER  MSG*300
      LOGICAL    FAILED

      IF (EXPSIG .EQ. ERRSIG) THEN
         FAILED = .FALSE.
         CALL PASS
      ELSE
         FAILED = .TRUE.
         CALL FAIL
         CALL SIGMSG (ERRSIG, FUNCID, MSG)
         CALL INMSG (MSG)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/sigmsg                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SIGMSG (PERRSG, FUNCNM, MSG)

C  SIGMSG formulates a message indicating that the function named by
C  funcnm signalled the error code perrsg.

C  Input parameters:
C    PERRSG : Error code to be incorporated in MSG
C    FUNCNM : Name of erroneous function to be incorporated in MSG
C  Output parameters:
C    MSG    : Resulting descriptive message

      INTEGER    PERRSG, ITRIM
      CHARACTER  FUNCNM*(*), MSG*(*)

      CHARACTER  ERRCH*6

      WRITE (ERRCH, '(I6)') PERRSG
      IF (FUNCNM .EQ. ' ') THEN
         MSG = 'No error signalled; current error code = ' //
     1          ERRCH // '.'
      ELSE
         MSG = 'Function ' // FUNCNM(1:ITRIM(FUNCNM)) //
     1         ' signalled error code ' // ERRCH // '.'
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/erfucd                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ERFUCD (FUNNAM, FUNCCD)

C  ERFUCD accepts a character string identifying a generic function 
C  and returns the standard function code.
C  
C  Input parameter:
C    FUNNAM : generic name of function
C  Output parameter:
C    FUNCCD : integer code for offending function

      INTEGER    FUNCCD, IX,IY, LEADNB, ITRIM
      CHARACTER  FUNNAM*(*), WNAM*100, TRUNAM*100

      FUNCCD = -1
      IF (FUNNAM.EQ.' ') RETURN

C  check whether already enclosed in angle brackets
      IX = INDEX (FUNNAM, '<')
      IF (IX.GT.0) THEN
         WNAM = FUNNAM(IX:)
      ELSE
         IX = LEADNB(FUNNAM)
         IY = ITRIM(FUNNAM)
         WNAM = '<' // FUNNAM(IX:IY) // '>'
      ENDIF

C  WNAM now has canonical function name
      DO 100 IY = 0,182
         CALL ERFUNM (IY, TRUNAM)
         IF (WNAM.EQ.TRUNAM) THEN
            FUNCCD = IY
            RETURN
         ENDIF
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/erfunm                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ERFUNM (FUNCCD, FUNNAM)

C  ERFUNM accepts an integer identifying a function and returns the generic
C  name of the function.  These are the "official" function codes from the
C  standard Fortran binding.  Only functions that generate errors are
C  encoded.
C  
C  Input parameter:
C    FUNCCD : integer code for offending function
C  Output parameter:
C    FUNNAM : generic name of function

      INTEGER    FUNCCD, IX
      CHARACTER  FUNNAM*(*), FUNTAB(0:182)*45

      DATA (FUNTAB(IX), IX=0,9) / '<open phigs>', 
     1  '<close phigs>', '<open workstation>', '<close workstation>',
     1  '<redraw all structures>', '<update workstation>', 
     1  '<set display update state>', '<message>', '<polyline 3>',
     1  '<polyline>'  /

      DATA (FUNTAB(IX), IX=10,19) / '<polymarker 3>',
     1  '<polymarker>', '<text 3>', '<text>', 
     1  '<annotation text relative 3>',  '<annotation text relative>',
     1  '<fill area 3>', '<fill area>', '<fill area set 3>', 
     1  '<fill area set>' /

      DATA (FUNTAB(IX), IX=20,29) / '<cell array 3>',
     1  '<cell array>', '<generalized drawing primitive 3>',
     1  '<generalized drawing primitive>', '<set polyline index>', 
     1  '<set polymarker index>', '<set text index>', 
     1  '<set interior index>', '<set edge index>', '<set linetype>' /

      DATA (FUNTAB(IX), IX=30,39) / '<set linewidth scale factor>',
     1  '<set polyline colour index>', '<set marker type>', 
     1  '<set marker size scale factor>', 
     1  '<set polymarker colour index>', '<set text font>', 
     1  '<set text precision>', '<set character expansion factor>',
     1  '<set character spacing>', '<set text colour index>' /

      DATA (FUNTAB(IX), IX=40,49) / '<set character height>',
     1  '<set character up vector>', '<set text path>', 
     1  '<set text alignment>', 
     1  '<set annotation text character height>', 
     1  '<set annotation text character up vector>', 
     1  '<set annotation text path>', '<set annotation text alignment>',
     1  '<set annotation style>', '<set interior style>' /

      DATA (FUNTAB(IX), IX=50,59) / '<set interior style index>',
     1  '<set interior colour index>', '<set edge flag>', 
     1  '<set edgetype>', '<set edgewidth scale factor>', 
     1  '<set edge colour index>', '<set pattern size>', 
     1  '<set pattern reference point and vectors>', 
     1  '<set pattern reference point>', '<add names to set>' /

      DATA (FUNTAB(IX), IX=60,69) / '<remove names from set>',
     1  '<set individual asf>', '<set polyline representation>', 
     1  '<set polymarker representation>', '<set text representation>',
     1  '<set interior representation>', '<set edge representation>',
     1  '<set pattern representation>', '<set colour representation>',
     1  '<set highlighting filter>' /

      DATA (FUNTAB(IX), IX=70,79) / '<set invisibility filter>',
     1  '<set colour model>', '<set hlhsr identifier>', 
     1  '<set hlhsr mode>', '<set local transformation 3>', 
     1  '<set local transformation>', '<set global transformation 3>',
     1  '<set global transformation>', 
     1  '<set modelling clipping volume 3>', 
     1  '<set modelling clipping volume>' /

      DATA (FUNTAB(IX), IX=80,89) /'<set modelling clipping indicator>',
     1  '<restore modelling clipping volume>', '<set view index>', 
     1  '<set view representation 3>', '<set view representation>',
     1  '<set view transformation input priority>', 
     1  '<set workstation window 3>', '<set workstation window>', 
     1  '<set workstation viewport 3>', '<set workstation viewport>' /

      DATA (FUNTAB(IX), IX=90,99) / '<open structure>',
     1  '<close structure>', '<execute structure>', '<label>',
     1  '<application data>', '<generalized structure element>', 
     1  '<set edit mode>', '<copy all elements from structure>', 
     1  '<set element pointer>', '<offset element pointer>' /

      DATA (FUNTAB(IX), IX=100,109) / '<set element pointer at label>',
     1  '<delete element>', '<delete element range>', 
     1  '<delete elements between labels>', '<empty structure>',
     1  '<delete structure>', '<delete structure network>', 
     1  '<delete all structures>', '<change structure identifier>',
     1  '<change structure references>' /

      DATA (FUNTAB(IX), IX=110,119) / 
     1  '<change structure identifier and references>', 
     1  '<post structure>', '<unpost structure>', 
     1  '<unpost all structures>', '<open archive file>', 
     1  '<close archive file>', '<archive structures>', 
     1  '<archive structure networks>', '<archive all structures>',
     1  '<set conflict resolution>' /

      DATA (FUNTAB(IX), IX=120,129) /'<retrieve structure identifiers>',
     1  '<retrieve structures>', '<retrieve structure networks>',
     1  '<retrieve all structures>', 
     1  '<retrieve paths to ancestors>', 
     1  '<retrieve paths to descendants>', 
     1  '<delete structures from archive>', 
     1  '<delete structure networks from archive>', 
     1  '<delete all structures from archive>', '<set pick identifier>'/

      DATA (FUNTAB(IX), IX=130,139) / '<set pick filter>',
     1  '<initialize locator 3>', '<initialize locator>', 
     1  '<initialize stroke 3>', '<initialize stroke>', 
     1  '<initialize valuator 3>', '<initialize valuator>', 
     1  '<initialize choice 3>', '<initialize choice>', 
     1  '<initialize pick 3>' /

      DATA (FUNTAB(IX), IX=140,149) / '<initialize pick>',
     1  '<initialize string 3>', '<initialize string>', 
     1  '<set locator mode>', '<set stroke mode>', 
     1  '<set valuator mode>', '<set choice mode>', '<set pick mode>',
     1  '<set string mode>', '<request locator 3>' /

      DATA (FUNTAB(IX), IX=150,159) / '<request locator>',
     1  '<request stroke 3>', '<request stroke>', '<request valuator>',
     1  '<request choice>', '<request pick>', '<request string>',
     1  '<sample locator 3>', '<sample locator>', '<sample stroke 3>' /

      DATA (FUNTAB(IX), IX=160,169) / '<sample stroke>', 
     1  '<sample valuator>', '<sample choice>', '<sample pick>',
     1  '<sample string>', '<await event>', '<flush device events>',
     1  '<get locator 3>', '<get locator>', '<get stroke 3>' /

      DATA (FUNTAB(IX), IX=170,179) / '<get stroke>',
     1  '<get valuator>', '<get choice>', '<get pick>', '<get string>',
     1  '<write item to metafile>', '<get item type from metafile>',
     1  '<read item from metafile>', '<interpret item>', 
     1  '<set error handling mode>' /

      DATA (FUNTAB(IX), IX=180,182) / '<escape>', '<pack data record>',
     1  '<unpack data record>' /

      IF (FUNCCD.GE.0 .AND. FUNCCD.LE.182) THEN
         FUNNAM = FUNTAB(FUNCCD)
      ELSE
         CALL UNMSG ('ERFUNM called with invalid value.')
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/nfunm                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE NFUNM (FUNCCD, FUNNAM)

C  NFUNM accepts an integer identifying a function and returns the generic
C  name of the function.  These are the codes used by the PVT system, as
C  documented in sys-dict.prt and used in the #F entries of DOC.PRT.

C  Input parameter:
C    FUNCCD : integer code for function
C  Output parameter:
C    FUNNAM : generic name of function

      INTEGER    FUNCCD
      CHARACTER  FUNNAM*(*)

      INTEGER    NOPPH,      NCLPH,      NOPWK,      NCLWK
      PARAMETER (NOPPH =001, NCLPH =002, NOPWK =003, NCLWK =004)
      INTEGER    NRST,       NUWK,       NSDUS,      NMSG
      PARAMETER (NRST  =005, NUWK  =006, NSDUS =007, NMSG  =008)
      INTEGER    NPL3,       NPL,        NPM3,       NPM
      PARAMETER (NPL3  =009, NPL   =010, NPM3  =011, NPM   =012)
      INTEGER    NTX3,       NTX,        NATR3,      NATR
      PARAMETER (NTX3  =013, NTX   =014, NATR3 =015, NATR  =016)
      INTEGER    NFA3,       NFA,        NFAS3,      NFAS
      PARAMETER (NFA3  =017, NFA   =018, NFAS3 =019, NFAS  =020)
      INTEGER    NCA3,       NCA,        NGDP3,      NGDP
      PARAMETER (NCA3  =021, NCA   =022, NGDP3 =023, NGDP  =024)
      INTEGER    NSPLI,      NSPMI,      NSTXI,      NSII
      PARAMETER (NSPLI =025, NSPMI =026, NSTXI =027, NSII  =028)
      INTEGER    NSEDI,      NSLN,       NSLWSC,     NSPLCI
      PARAMETER (NSEDI =029, NSLN  =030, NSLWSC=031, NSPLCI=032)
      INTEGER    NSMK,       NSMKSC,     NSPMCI,     NSTXFN
      PARAMETER (NSMK  =033, NSMKSC=034, NSPMCI=035, NSTXFN=036)
      INTEGER    NSTXPR,     NSCHXP,     NSCHSP,     NSTXCI
      PARAMETER (NSTXPR=037, NSCHXP=038, NSCHSP=039, NSTXCI=040)
      INTEGER    NSCHH,      NSCHUP,     NSTXP,      NSTXAL
      PARAMETER (NSCHH =041, NSCHUP=042, NSTXP =043, NSTXAL=044)
      INTEGER    NSATCH,     NSATCU,     NSATP,      NSATAL
      PARAMETER (NSATCH=045, NSATCU=046, NSATP =047, NSATAL=048)
      INTEGER    NSANS,      NSIS,       NSISI,      NSICI
      PARAMETER (NSANS =049, NSIS  =050, NSISI =051, NSICI =052)
      INTEGER    NSEDFG,     NSEDT,      NSEWSC,     NSEDCI
      PARAMETER (NSEDFG=053, NSEDT =054, NSEWSC=055, NSEDCI=056)
      INTEGER    NSPA,       NSPRPV,     NSPARF,     NADS
      PARAMETER (NSPA  =057, NSPRPV=058, NSPARF=059, NADS  =060)
      INTEGER    NRES,       NSIASF,     NSPLR,      NSPMR
      PARAMETER (NRES  =061, NSIASF=062, NSPLR =063, NSPMR =064)
      INTEGER    NSTXR,      NSIR,       NSEDR,      NSPAR
      PARAMETER (NSTXR =065, NSIR  =066, NSEDR =067, NSPAR =068)
      INTEGER    NSCR,       NSHLFT,     NSIVFT,     NSCMD
      PARAMETER (NSCR  =069, NSHLFT=070, NSIVFT=071, NSCMD =072)
      INTEGER    NSHRID,     NSHRM,      NSLMT3,     NSLMT
      PARAMETER (NSHRID=073, NSHRM =074, NSLMT3=075, NSLMT =076)
      INTEGER    NSGMT3,     NSGMT,      NSMCV3,     NSMCV
      PARAMETER (NSGMT3=077, NSGMT =078, NSMCV3=079, NSMCV =080)
      INTEGER    NSMCLI,     NRMCV,      NSVWI,      NSVWR3
      PARAMETER (NSMCLI=081, NRMCV =082, NSVWI =083, NSVWR3=084)
      INTEGER    NSVWR,      NSVTIP,     NSWKW3,     NSWKW
      PARAMETER (NSVWR =085, NSVTIP=086, NSWKW3=087, NSWKW =088)
      INTEGER    NSWKV3,     NSWKV,      NTR3,       NTR
      PARAMETER (NSWKV3=089, NSWKV =090, NTR3  =091, NTR   =092)
      INTEGER    NSC3,       NSC,        NROX,       NROY
      PARAMETER (NSC3  =093, NSC   =094, NROX  =095, NROY  =096)
      INTEGER    NROZ,       NRO,        NCOM3,      NCOM
      PARAMETER (NROZ  =097, NRO   =098, NCOM3 =099, NCOM  =100)
      INTEGER    NTP3,       NTP,        NBLTM3,     NBLTM
      PARAMETER (NTP3  =101, NTP   =102, NBLTM3=103, NBLTM =104)
      INTEGER    NCOTM3,     NCOTM,      NEVOM3,     NEVOM
      PARAMETER (NCOTM3=105, NCOTM =106, NEVOM3=107, NEVOM =108)
      INTEGER    NEVMM3,     NEVMM,      NOPST,      NCLST
      PARAMETER (NEVMM3=109, NEVMM =110, NOPST =111, NCLST =112)
      INTEGER    NEXST,      NLB,        NAP,        NGSE
      PARAMETER (NEXST =113, NLB   =114, NAP   =115, NGSE  =116)
      INTEGER    NSEDM,      NCELST,     NSEP,       NOSEP
      PARAMETER (NSEDM =117, NCELST=118, NSEP  =119, NOSEP =120)
      INTEGER    NSEPLB,     NDEL,       NDELRA,     NDELLB
      PARAMETER (NSEPLB=121, NDEL  =122, NDELRA=123, NDELLB=124)
      INTEGER    NEMST,      NDST,       NDSN,       NDAS
      PARAMETER (NEMST =125, NDST  =126, NDSN  =127, NDAS  =128)
      INTEGER    NCSTID,     NCSTRF,     NCSTIR,     NPOST
      PARAMETER (NCSTID=129, NCSTRF=130, NCSTIR=131, NPOST =132)
      INTEGER    NUPOST,     NUPAST,     NOPARF,     NCLARF
      PARAMETER (NUPOST=133, NUPAST=134, NOPARF=135, NCLARF=136)
      INTEGER    NARST,      NARSN,      NARAST,     NSCNRS
      PARAMETER (NARST =137, NARSN =138, NARAST=139, NSCNRS=140)
      INTEGER    NRSID,      NREST,      NRESN,      NRAST
      PARAMETER (NRSID =141, NREST =142, NRESN =143, NRAST =144)
      INTEGER    NREPAN,     NREPDE,     NDSTAR,     NDSNAR
      PARAMETER (NREPAN=145, NREPDE=146, NDSTAR=147, NDSNAR=148)
      INTEGER    NDASAR,     NSPKID,     NSPKFT,     NINLC3
      PARAMETER (NDASAR=149, NSPKID=150, NSPKFT=151, NINLC3=152)
      INTEGER    NINLC,      NINSK3,     NINSK,      NINVL3
      PARAMETER (NINLC =153, NINSK3=154, NINSK =155, NINVL3=156)
      INTEGER    NINVL,      NINCH3,     NINCH,      NINPK3
      PARAMETER (NINVL =157, NINCH3=158, NINCH =159, NINPK3=160)
      INTEGER    NINPK,      NINST3,     NINST,      NSLCM
      PARAMETER (NINPK =161, NINST3=162, NINST =163, NSLCM =164)
      INTEGER    NSSKM,      NSVLM,      NSCHM,      NSPKM
      PARAMETER (NSSKM =165, NSVLM =166, NSCHM =167, NSPKM =168)
      INTEGER    NSSTM,      NRQLC3,     NRQLC,      NRQSK3
      PARAMETER (NSSTM =169, NRQLC3=170, NRQLC =171, NRQSK3=172)
      INTEGER    NRQSK,      NRQVL,      NRQCH,      NRQPK
      PARAMETER (NRQSK =173, NRQVL =174, NRQCH =175, NRQPK =176)
      INTEGER    NRQST,      NSMLC3,     NSMLC,      NSMSK3
      PARAMETER (NRQST =177, NSMLC3=178, NSMLC =179, NSMSK3=180)
      INTEGER    NSMSK,      NSMVL,      NSMCH,      NSMPK
      PARAMETER (NSMSK =181, NSMVL =182, NSMCH =183, NSMPK =184)
      INTEGER    NSMST,      NWAIT,      NFLUSH,     NGTLC3
      PARAMETER (NSMST =185, NWAIT =186, NFLUSH=187, NGTLC3=188)
      INTEGER    NGTLC,      NGTSK3,     NGTSK,      NGTVL
      PARAMETER (NGTLC =189, NGTSK3=190, NGTSK =191, NGTVL =192)
      INTEGER    NGTCH,      NGTPK,      NGTST,      NWITM
      PARAMETER (NGTCH =193, NGTPK =194, NGTST =195, NWITM =196)
      INTEGER    NGTITM,     NRDITM,     NIITM,      NQSYS
      PARAMETER (NGTITM=197, NRDITM=198, NIITM =199, NQSYS =200)
      INTEGER    NQWKST,     NQSTRS,     NQARS,      NQEWK
      PARAMETER (NQWKST=201, NQSTRS=202, NQARS =203, NQEWK =204)
      INTEGER    NQPHF,      NQGSEF,     NQMCLF,     NQEDM
      PARAMETER (NQPHF =205, NQGSEF=206, NQMCLF=207, NQEDM =208)
      INTEGER    NQOPWK,     NQSID,      NQARF,      NQCNRS
      PARAMETER (NQOPWK=209, NQSID =210, NQARF =211, NQCNRS=212)
      INTEGER    NQCST,      NQCSTN,     NQSIM,      NQWKC
      PARAMETER (NQCST =213, NQCSTN=214, NQSIM =215, NQWKC =216)
      INTEGER    NQEVWI,     NQVWR,      NQHRM,      NQPOST
      PARAMETER (NQEVWI=217, NQVWR =218, NQHRM =219, NQPOST=220)
      INTEGER    NQDUS,      NQEPLI,     NQPLR,      NQEPMI
      PARAMETER (NQDUS =221, NQEPLI=222, NQPLR =223, NQEPMI=224)
      INTEGER    NQPMR,      NQETXI,     NQTXR,      NQEII
      PARAMETER (NQPMR =225, NQETXI=226, NQTXR =227, NQEII =228)
      INTEGER    NQIR,       NQEEDI,     NQEDR,      NQEPAI
      PARAMETER (NQIR  =229, NQEEDI=230, NQEDR =231, NQEPAI=232)
      INTEGER    NQPAR,      NQCMD,      NQECI,      NQCR
      PARAMETER (NQPAR =233, NQCMD =234, NQECI =235, NQCR  =236)
      INTEGER    NQHLFT,     NQIVFT,     NQWKT3,     NQWKT
      PARAMETER (NQHLFT=237, NQIVFT=238, NQWKT3=239, NQWKT =240)
      INTEGER    NQLCS3,     NQLCS,      NQSKS3,     NQSKS
      PARAMETER (NQLCS3=241, NQLCS =242, NQSKS3=243, NQSKS =244)
      INTEGER    NQVLS3,     NQVLS,      NQCHS3,     NQCHS
      PARAMETER (NQVLS3=245, NQVLS =246, NQCHS3=247, NQCHS =248)
      INTEGER    NQPKS3,     NQPKS,      NQSTS3,     NQSTS
      PARAMETER (NQPKS3=249, NQPKS =250, NQSTS3=251, NQSTS =252)
      INTEGER    NQWKCA,     NQDSP3,     NQDSP,      NQHRIF
      PARAMETER (NQWKCA=253, NQDSP3=254, NQDSP =255, NQHRIF=256)
      INTEGER    NQHRMF,     NQVWF,      NQPVWR,     NQWKCL
      PARAMETER (NQHRMF=256, NQVWF =257, NQPVWR=258, NQWKCL=259)
      INTEGER    NQDSWA,     NQDDUS,     NQPLF,      NQPPLR
      PARAMETER (NQDSWA=260, NQDDUS=261, NQPLF =262, NQPPLR=263)
      INTEGER    NQPMF,      NQPPMR,     NQTXF,      NQPTXR
      PARAMETER (NQPMF =264, NQPPMR=265, NQTXF =266, NQPTXR=267)
      INTEGER    NQANF,      NQTXX,      NQIF,       NQPIR
      PARAMETER (NQANF =268, NQTXX =269, NQIF  =270, NQPIR =271)
      INTEGER    NQEDF,      NQPEDR,     NQPAF,      NQPPAR
      PARAMETER (NQEDF =272, NQPEDR=273, NQPAF =274, NQPPAR=275)
      INTEGER    NQCMDF,     NQCF,       NQPCR,      NQEGD3
      PARAMETER (NQCMDF=276, NQCF  =277, NQPCR =278, NQEGD3=279)
      INTEGER    NQEGDP,     NQGDP3,     NQGDP,      NQEGSE
      PARAMETER (NQEGDP=280, NQGDP3=281, NQGDP =282, NQEGSE=283)
      INTEGER    NQDP,       NQWKSL,     NQDSTR,     NQLI
      PARAMETER (NQDP  =284, NQWKSL=285, NQDSTR=286, NQLI  =287)
      INTEGER    NQDLC3,     NQDLC,      NQDSK3,     NQDSK
      PARAMETER (NQDLC3=288, NQDLC =289, NQDSK3=290, NQDSK =291)
      INTEGER    NQDVL3,     NQDVL,      NQDCH3,     NQDCH
      PARAMETER (NQDVL3=292, NQDVL =293, NQDCH3=294, NQDCH =295)
      INTEGER    NQDPK3,     NQDPK,      NQDST3,     NQDST
      PARAMETER (NQDPK3=296, NQDPK =297, NQDST3=298, NQDST =299)
      INTEGER    NQWKPO,     NQOPST,     NQEP,       NQCETS
      PARAMETER (NQWKPO=300, NQOPST=301, NQEP  =302, NQCETS=303)
      INTEGER    NQCECO,     NQETS,      NQECO,      NQSTST
      PARAMETER (NQCECO=304, NQETS =305, NQECO =306, NQSTST=307)
      INTEGER    NQPAN,      NQPDE,      NELS,       NISS3
      PARAMETER (NQPAN =308, NQPDE =309, NELS  =310, NISS3 =311)
      INTEGER    NISS,       NQIQOV,     NQERHM,     NECLPH
      PARAMETER (NISS  =312, NQIQOV=313, NQERHM=314, NECLPH=315)
      INTEGER    NERHND,     NERLOG,     NSERHM,     NESC
      PARAMETER (NERHND=316, NERLOG=317, NSERHM=318, NESC  =319)
      INTEGER    NPREC,      NUREC,      NCRSTO,     NDLSTO
      PARAMETER (NPREC =320, NUREC =321, NCRSTO=322, NDLSTO=323)
      INTEGER    NSEHND
      PARAMETER (NSEHND=324)

      IF (FUNCCD.LT.1 .OR. FUNCCD.GT.324) THEN
         CALL UNMSG ('NFUNM called with invalid value.')
      ENDIF

      IF (FUNCCD .LE. 100) GOTO 9000
      IF (FUNCCD .LE. 200) GOTO 9100
      IF (FUNCCD .LE. 300) GOTO 9200
      GOTO 9300

9000  CONTINUE
      GOTO ( 001,002,003,004,005,006,007,008,009,010,
     1       011,012,013,014,015,016,017,018,019,020,
     2       021,022,023,024,025,026,027,028,029,030,
     3       031,032,033,034,035,036,037,038,039,040,
     4       041,042,043,044,045,046,047,048,049,050,
     5       051,052,053,054,055,056,057,058,059,060,
     6       061,062,063,064,065,066,067,068,069,070,
     7       071,072,073,074,075,076,077,078,079,080,
     8       081,082,083,084,085,086,087,088,089,090,         
     9       091,092,093,094,095,096,097,098,099,100 ), FUNCCD

9100  CONTINUE
      GOTO ( 101,102,103,104,105,106,107,108,109,110,
     1       111,112,113,114,115,116,117,118,119,120,
     2       121,122,123,124,125,126,127,128,129,130,
     3       131,132,133,134,135,136,137,138,139,140,
     4       141,142,143,144,145,146,147,148,149,150,
     5       151,152,153,154,155,156,157,158,159,160,
     6       161,162,163,164,165,166,167,168,169,170,
     7       171,172,173,174,175,176,177,178,179,180,
     8       181,182,183,184,185,186,187,188,189,190,
     9       191,192,193,194,195,196,197,198,199,200 ), FUNCCD-100

9200  CONTINUE
      GOTO ( 201,202,203,204,205,206,207,208,209,210,
     1       211,212,213,214,215,216,217,218,219,220,
     2       221,222,223,224,225,226,227,228,229,230,
     3       231,232,233,234,235,236,237,238,239,240,
     4       241,242,243,244,245,246,247,248,249,250,
     5       251,252,253,254,255,256,257,258,259,260,
     6       261,262,263,264,265,266,267,268,269,270,
     7       271,272,273,274,275,276,277,278,279,280,
     8       281,282,283,284,285,286,287,288,289,290,
     9       291,292,293,294,295,296,297,298,299,300 ), FUNCCD-200

9300  CONTINUE
      GOTO ( 301,302,303,304,305,306,307,308,309,310,
     1       311,312,313,314,315,316,317,318,319,320,
     2       321,322,323,324 ), FUNCCD-300

001   FUNNAM = '<open phigs>'
      RETURN
002   FUNNAM = '<close phigs>'
      RETURN
003   FUNNAM = '<open workstation>'
      RETURN
004   FUNNAM = '<close workstation>'
      RETURN
005   FUNNAM = '<redraw all structures>'
      RETURN
006   FUNNAM = '<update workstation>'
      RETURN
007   FUNNAM = '<set display update state>'
      RETURN
008   FUNNAM = '<message>'
      RETURN
009   FUNNAM = '<polyline 3>'
      RETURN
010   FUNNAM = '<polyline>'
      RETURN
011   FUNNAM = '<polymarker 3>'
      RETURN
012   FUNNAM = '<polymarker>'
      RETURN
013   FUNNAM = '<text 3>'
      RETURN
014   FUNNAM = '<text>'
      RETURN
015   FUNNAM = '<annotation text relative 3>'
      RETURN
016   FUNNAM = '<annotation text relative>'
      RETURN
017   FUNNAM = '<fill area 3>'
      RETURN
018   FUNNAM = '<fill area>'
      RETURN
019   FUNNAM = '<fill area set 3>'
      RETURN
020   FUNNAM = '<fill area set>'
      RETURN
021   FUNNAM = '<cell array 3>'
      RETURN
022   FUNNAM = '<cell array>'
      RETURN
023   FUNNAM = '<generalized drawing primitive 3>'
      RETURN
024   FUNNAM = '<generalized drawing primitive>'
      RETURN
025   FUNNAM = '<set polyline index>'
      RETURN
026   FUNNAM = '<set polymarker index>'
      RETURN
027   FUNNAM = '<set text index>'
      RETURN
028   FUNNAM = '<set interior index>'
      RETURN
029   FUNNAM = '<set edge index>'
      RETURN
030   FUNNAM = '<set linetype>'
      RETURN
031   FUNNAM = '<set linewidth scale factor>'
      RETURN
032   FUNNAM = '<set polyline colour index>'
      RETURN
033   FUNNAM = '<set marker type>'
      RETURN
034   FUNNAM = '<set marker size scale factor>'
      RETURN
035   FUNNAM = '<set polymarker colour index>'
      RETURN
036   FUNNAM = '<set text font>'
      RETURN
037   FUNNAM = '<set text precision>'
      RETURN
038   FUNNAM = '<set character expansion factor>'
      RETURN
039   FUNNAM = '<set character spacing>'
      RETURN
040   FUNNAM = '<set text colour index>'
      RETURN
041   FUNNAM = '<set character height>'
      RETURN
042   FUNNAM = '<set character up vector>'
      RETURN
043   FUNNAM = '<set text path>'
      RETURN
044   FUNNAM = '<set text alignment>'
      RETURN
045   FUNNAM = '<set annotation text character height>'
      RETURN
046   FUNNAM = '<set annotation text character up vector>'
      RETURN
047   FUNNAM = '<set annotation text path>'
      RETURN
048   FUNNAM = '<set annotation text alignment>'
      RETURN
049   FUNNAM = '<set annotation style>'
      RETURN
050   FUNNAM = '<set interior style>'
      RETURN
051   FUNNAM = '<set interior style index>'
      RETURN
052   FUNNAM = '<set interior colour index>'
      RETURN
053   FUNNAM = '<set edge flag>'
      RETURN
054   FUNNAM = '<set edgetype>'
      RETURN
055   FUNNAM = '<set edgewidth scale factor>'
      RETURN
056   FUNNAM = '<set edge colour index>'
      RETURN
057   FUNNAM = '<set pattern size>'
      RETURN
058   FUNNAM = '<set pattern reference point and vectors>'
      RETURN
059   FUNNAM = '<set pattern reference point>'
      RETURN
060   FUNNAM = '<add names to set>'
      RETURN
061   FUNNAM = '<remove names from set>'
      RETURN
062   FUNNAM = '<set individual asf>'
      RETURN
063   FUNNAM = '<set polyline representation>'
      RETURN
064   FUNNAM = '<set polymarker representation>'
      RETURN
065   FUNNAM = '<set text representation>'
      RETURN
066   FUNNAM = '<set interior representation>'
      RETURN
067   FUNNAM = '<set edge representation>'
      RETURN
068   FUNNAM = '<set pattern representation>'
      RETURN
069   FUNNAM = '<set colour representation>'
      RETURN
070   FUNNAM = '<set highlighting filter>'
      RETURN
071   FUNNAM = '<set invisibility filter>'
      RETURN
072   FUNNAM = '<set colour model>'
      RETURN
073   FUNNAM = '<set hlhsr identifier>'
      RETURN
074   FUNNAM = '<set hlhsr mode>'
      RETURN
075   FUNNAM = '<set local transformation 3>'
      RETURN
076   FUNNAM = '<set local transformation>'
      RETURN
077   FUNNAM = '<set global transformation 3>'
      RETURN
078   FUNNAM = '<set global transformation>'
      RETURN
079   FUNNAM = '<set modelling clipping volume 3>'
      RETURN
080   FUNNAM = '<set modelling clipping volume>'
      RETURN
081   FUNNAM = '<set modelling clipping indicator>'
      RETURN
082   FUNNAM = '<restore modelling clipping volume>'
      RETURN
083   FUNNAM = '<set view index>'
      RETURN
084   FUNNAM = '<set view representation 3>'
      RETURN
085   FUNNAM = '<set view representation>'
      RETURN
086   FUNNAM = '<set view transformation input priority>'
      RETURN
087   FUNNAM = '<set workstation window 3>'
      RETURN
088   FUNNAM = '<set workstation window>'
      RETURN
089   FUNNAM = '<set workstation viewport 3>'
      RETURN
090   FUNNAM = '<set workstation viewport>'
      RETURN
091   FUNNAM = '<translate 3>'
      RETURN
092   FUNNAM = '<translate>'
      RETURN
093   FUNNAM = '<scale 3>'
      RETURN
094   FUNNAM = '<scale>'
      RETURN
095   FUNNAM = '<rotate x>'
      RETURN
096   FUNNAM = '<rotate y>'
      RETURN
097   FUNNAM = '<rotate z>'
      RETURN
098   FUNNAM = '<rotate>'
      RETURN
099   FUNNAM = '<compose matrix 3>'
      RETURN
100   FUNNAM = '<compose matrix>'
      RETURN
101   FUNNAM = '<transform point 3>'
      RETURN
102   FUNNAM = '<transform point>'
      RETURN
103   FUNNAM = '<build transformation matrix 3>'
      RETURN
104   FUNNAM = '<build transformation matrix>'
      RETURN
105   FUNNAM = '<compose transformation matrix 3>'
      RETURN
106   FUNNAM = '<compose transformation matrix>'
      RETURN
107   FUNNAM = '<evaluate view orientation matrix 3>'
      RETURN
108   FUNNAM = '<evaluate view orientation matrix>'
      RETURN
109   FUNNAM = '<evaluate view mapping matrix 3>'
      RETURN
110   FUNNAM = '<evaluate view mapping matrix>'
      RETURN
111   FUNNAM = '<open structure>'
      RETURN
112   FUNNAM = '<close structure>'
      RETURN
113   FUNNAM = '<execute structure>'
      RETURN
114   FUNNAM = '<label>'
      RETURN
115   FUNNAM = '<application data>'
      RETURN
116   FUNNAM = '<generalized structure element>'
      RETURN
117   FUNNAM = '<set edit mode>'
      RETURN
118   FUNNAM = '<copy all elements from structure>'
      RETURN
119   FUNNAM = '<set element pointer>'
      RETURN
120   FUNNAM = '<offset element pointer>'
      RETURN
121   FUNNAM = '<set element pointer at label>'
      RETURN
122   FUNNAM = '<delete element>'
      RETURN
123   FUNNAM = '<delete element range>'
      RETURN
124   FUNNAM = '<delete elements between labels>'
      RETURN
125   FUNNAM = '<empty structure>'
      RETURN
126   FUNNAM = '<delete structure>'
      RETURN
127   FUNNAM = '<delete structure network>'
      RETURN
128   FUNNAM = '<delete all structures>'
      RETURN
129   FUNNAM = '<change structure identifier>'
      RETURN
130   FUNNAM = '<change structure references>'
      RETURN
131   FUNNAM = '<change structure identifier and references>'
      RETURN
132   FUNNAM = '<post structure>'
      RETURN
133   FUNNAM = '<unpost structure>'
      RETURN
134   FUNNAM = '<unpost all structures>'
      RETURN
135   FUNNAM = '<open archive file>'
      RETURN
136   FUNNAM = '<close archive file>'
      RETURN
137   FUNNAM = '<archive structures>'
      RETURN
138   FUNNAM = '<archive structure networks>'
      RETURN
139   FUNNAM = '<archive all structures>'
      RETURN
140   FUNNAM = '<set conflict resolution>'
      RETURN
141   FUNNAM = '<retrieve structure identifiers>'
      RETURN
142   FUNNAM = '<retrieve structures>'
      RETURN
143   FUNNAM = '<retrieve structure networks>'
      RETURN
144   FUNNAM = '<retrieve all structures>'
      RETURN
145   FUNNAM = '<retrieve paths to ancestors>'
      RETURN
146   FUNNAM = '<retrieve paths to descendants>'
      RETURN
147   FUNNAM = '<delete structures from archive>'
      RETURN
148   FUNNAM = '<delete structure networks from archive>'
      RETURN
149   FUNNAM = '<delete all structures from archive>'
      RETURN
150   FUNNAM = '<set pick identifier>'
      RETURN
151   FUNNAM = '<set pick filter>'
      RETURN
152   FUNNAM = '<initialize locator 3>'
      RETURN
153   FUNNAM = '<initialize locator>'
      RETURN
154   FUNNAM = '<initialize stroke 3>'
      RETURN
155   FUNNAM = '<initialize stroke>'
      RETURN
156   FUNNAM = '<initialize valuator 3>'
      RETURN
157   FUNNAM = '<initialize valuator>'
      RETURN
158   FUNNAM = '<initialize choice 3>'
      RETURN
159   FUNNAM = '<initialize choice>'
      RETURN
160   FUNNAM = '<initialize pick 3>'
      RETURN
161   FUNNAM = '<initialize pick>'
      RETURN
162   FUNNAM = '<initialize string 3>'
      RETURN
163   FUNNAM = '<initialize string>'
      RETURN
164   FUNNAM = '<set locator mode>'
      RETURN
165   FUNNAM = '<set stroke mode>'
      RETURN
166   FUNNAM = '<set valuator mode>'
      RETURN
167   FUNNAM = '<set choice mode>'
      RETURN
168   FUNNAM = '<set pick mode>'
      RETURN
169   FUNNAM = '<set string mode>'
      RETURN
170   FUNNAM = '<request locator 3>'
      RETURN
171   FUNNAM = '<request locator>'
      RETURN
172   FUNNAM = '<request stroke 3>'
      RETURN
173   FUNNAM = '<request stroke>'
      RETURN
174   FUNNAM = '<request valuator>'
      RETURN
175   FUNNAM = '<request choice>'
      RETURN
176   FUNNAM = '<request pick>'
      RETURN
177   FUNNAM = '<request string>'
      RETURN
178   FUNNAM = '<sample locator 3>'
      RETURN
179   FUNNAM = '<sample locator>'
      RETURN
180   FUNNAM = '<sample stroke 3>'
      RETURN
181   FUNNAM = '<sample stroke>'
      RETURN
182   FUNNAM = '<sample valuator>'
      RETURN
183   FUNNAM = '<sample choice>'
      RETURN
184   FUNNAM = '<sample pick>'
      RETURN
185   FUNNAM = '<sample string>'
      RETURN
186   FUNNAM = '<await event>'
      RETURN
187   FUNNAM = '<flush device events>'
      RETURN
188   FUNNAM = '<get locator 3>'
      RETURN
189   FUNNAM = '<get locator>'
      RETURN
190   FUNNAM = '<get stroke 3>'
      RETURN
191   FUNNAM = '<get stroke>'
      RETURN
192   FUNNAM = '<get valuator>'
      RETURN
193   FUNNAM = '<get choice>'
      RETURN
194   FUNNAM = '<get pick>'
      RETURN
195   FUNNAM = '<get string>'
      RETURN
196   FUNNAM = '<write item to metafile>'
      RETURN
197   FUNNAM = '<get item type from metafile>'
      RETURN
198   FUNNAM = '<read item from metafile>'
      RETURN
199   FUNNAM = '<interpret item>'
      RETURN
200   FUNNAM = '<inquire system state value>'
      RETURN
201   FUNNAM = '<inquire workstation state value>'
      RETURN
202   FUNNAM = '<inquire structure state value>'
      RETURN
203   FUNNAM = '<inquire archive state value>'
      RETURN
204   FUNNAM = '<inquire list of available workstation types>'
      RETURN
205   FUNNAM = '<inquire phigs facilities>'
      RETURN
206   FUNNAM = '<inquire generalized structure element facilities>'
      RETURN
207   FUNNAM = '<inquire modelling clipping facilities>'
      RETURN
208   FUNNAM = '<inquire edit mode>'
      RETURN
209   FUNNAM = '<inquire set of open workstations>'
      RETURN
210   FUNNAM = '<inquire structure identifiers>'
      RETURN
211   FUNNAM = '<inquire archive files>'
      RETURN
212   FUNNAM = '<inquire conflict resolution>'
      RETURN
213   FUNNAM = '<inquire all conflicting structures>'
      RETURN
214   FUNNAM = '<inquire conflicting structures in network>'
      RETURN
215   FUNNAM = '<inquire more simultaneous events>'
      RETURN
216   FUNNAM = '<inquire workstation connection and type>'
      RETURN
217   FUNNAM = '<inquire list of view indices>'
      RETURN
218   FUNNAM = '<inquire view representation>'
      RETURN
219   FUNNAM = '<inquire hlhsr mode>'
      RETURN
220   FUNNAM = '<inquire posted structures>'
      RETURN
221   FUNNAM = '<inquire display update state>'
      RETURN
222   FUNNAM = '<inquire list of polyline indices>'
      RETURN
223   FUNNAM = '<inquire polyline representation>'
      RETURN
224   FUNNAM = '<inquire list of polymarker indices>'
      RETURN
225   FUNNAM = '<inquire polymarker representation>'
      RETURN
226   FUNNAM = '<inquire list of text indices>'
      RETURN
227   FUNNAM = '<inquire text representation>'
      RETURN
228   FUNNAM = '<inquire list of interior indices>'
      RETURN
229   FUNNAM = '<inquire interior representation>'
      RETURN
230   FUNNAM = '<inquire list of edge indices>'
      RETURN
231   FUNNAM = '<inquire edge representation>'
      RETURN
232   FUNNAM = '<inquire list of pattern indices>'
      RETURN
233   FUNNAM = '<inquire pattern representation>'
      RETURN
234   FUNNAM = '<inquire colour model>'
      RETURN
235   FUNNAM = '<inquire list of colour indices>'
      RETURN
236   FUNNAM = '<inquire colour representation>'
      RETURN
237   FUNNAM = '<inquire highlighting filter>'
      RETURN
238   FUNNAM = '<inquire invisibility filter>'
      RETURN
239   FUNNAM = '<inquire workstation transformation 3>'
      RETURN
240   FUNNAM = '<inquire workstation transformation>'
      RETURN
241   FUNNAM = '<inquire locator device state 3>'
      RETURN
242   FUNNAM = '<inquire locator device state>'
      RETURN
243   FUNNAM = '<inquire stroke device state 3>'
      RETURN
244   FUNNAM = '<inquire stroke device state>'
      RETURN
245   FUNNAM = '<inquire valuator device state 3>'
      RETURN
246   FUNNAM = '<inquire valuator device state>'
      RETURN
247   FUNNAM = '<inquire choice device state 3>'
      RETURN
248   FUNNAM = '<inquire choice device state>'
      RETURN
249   FUNNAM = '<inquire pick device state 3>'
      RETURN
250   FUNNAM = '<inquire pick device state>'
      RETURN
251   FUNNAM = '<inquire string device state 3>'
      RETURN
252   FUNNAM = '<inquire string device state>'
      RETURN
253   FUNNAM = '<inquire workstation category>'
      RETURN
254   FUNNAM = '<inquire display space size 3>'
      RETURN
255   FUNNAM = '<inquire display space size>'
      RETURN
256   FUNNAM = '<inquire hlhsr facilities>'
      RETURN
257   FUNNAM = '<inquire view facilities>'
      RETURN
258   FUNNAM = '<inquire predefined view representation>'
      RETURN
259   FUNNAM = '<inquire workstation classification>'
      RETURN
260   FUNNAM = '<inquire dynamics of workstation attributes>'
      RETURN
261   FUNNAM = '<inquire default display update state>'
      RETURN
262   FUNNAM = '<inquire polyline facilities>'
      RETURN
263   FUNNAM = '<inquire predefined polyline representation>'
      RETURN
264   FUNNAM = '<inquire polymarker facilities>'
      RETURN
265   FUNNAM = '<inquire predefined polymarker representation>'
      RETURN
266   FUNNAM = '<inquire text facilities>'
      RETURN
267   FUNNAM = '<inquire predefined text representation>'
      RETURN
268   FUNNAM = '<inquire annotation facilities>'
      RETURN
269   FUNNAM = '<inquire text extent>'
      RETURN
270   FUNNAM = '<inquire interior facilities>'
      RETURN
271   FUNNAM = '<inquire predefined interior representation>'
      RETURN
272   FUNNAM = '<inquire edge facilities>'
      RETURN
273   FUNNAM = '<inquire predefined edge representation>'
      RETURN
274   FUNNAM = '<inquire pattern facilities>'
      RETURN
275   FUNNAM = '<inquire predefined pattern representation>'
      RETURN
276   FUNNAM = '<inquire colour model facilities>'
      RETURN
277   FUNNAM = '<inquire colour facilities>'
      RETURN
278   FUNNAM = '<inquire predefined colour representation>'
      RETURN
279   FUNNAM = '<inquire list of available generalized drawing ' //
     1         'primitives 3>'
      RETURN
280   FUNNAM = '<inquire list of available generalized drawing ' //
     1         'primitives>'
      RETURN
281   FUNNAM = '<inquire generalized drawing primitive 3>'
      RETURN
282   FUNNAM = '<inquire generalized drawing primitive>'
      RETURN
283   FUNNAM = '<inquire list of available generalized structure ' //
     1         'elements>'
      RETURN
284   FUNNAM = '<inquire number of display priorities supported>'
      RETURN
285   FUNNAM = '<inquire workstation state table lengths>'
      RETURN
286   FUNNAM = '<inquire dynamics of structures>'
      RETURN
287   FUNNAM = '<inquire number of available logical input devices>'
      RETURN
288   FUNNAM = '<inquire default locator device data 3>'
      RETURN
289   FUNNAM = '<inquire default locator device data>'
      RETURN
290   FUNNAM = '<inquire default stroke device data 3>'
      RETURN
291   FUNNAM = '<inquire default stroke device data>'
      RETURN
292   FUNNAM = '<inquire default valuator device data 3>'
      RETURN
293   FUNNAM = '<inquire default valuator device data>'
      RETURN
294   FUNNAM = '<inquire default choice device data 3>'
      RETURN
295   FUNNAM = '<inquire default choice device data>'
      RETURN
296   FUNNAM = '<inquire default pick device data 3>'
      RETURN
297   FUNNAM = '<inquire default pick device data>'
      RETURN
298   FUNNAM = '<inquire default string device data 3>'
      RETURN
299   FUNNAM = '<inquire default string device data>'
      RETURN
300   FUNNAM = '<inquire set of workstations to which posted>'
      RETURN
301   FUNNAM = '<inquire open structure>'
      RETURN
302   FUNNAM = '<inquire element pointer>'
      RETURN
303   FUNNAM = '<inquire current element type and size>'
      RETURN
304   FUNNAM = '<inquire current element content>'
      RETURN
305   FUNNAM = '<inquire element type and size>'
      RETURN
306   FUNNAM = '<inquire element content>'
      RETURN
307   FUNNAM = '<inquire structure status>'
      RETURN
308   FUNNAM = '<inquire paths to ancestors>'
      RETURN
309   FUNNAM = '<inquire paths to descendants>'
      RETURN
310   FUNNAM = '<element search>'
      RETURN
311   FUNNAM = '<incremental spatial search 3>'
      RETURN
312   FUNNAM = '<incremental spatial search>'
      RETURN
313   FUNNAM = '<inquire input queue overflow>'
      RETURN
314   FUNNAM = '<inquire error handling mode>'
      RETURN
315   FUNNAM = '<emergency close phigs>'
      RETURN
316   FUNNAM = '<error handling>'
      RETURN
317   FUNNAM = '<error logging>'
      RETURN
318   FUNNAM = '<set error handling mode>'
      RETURN
319   FUNNAM = '<escape>'
      RETURN
320   FUNNAM = '<pack data record>'
      RETURN
321   FUNNAM = '<unpack data record>'
      RETURN
322   FUNNAM = '<create store>'
      RETURN
323   FUNNAM = '<delete store>'
      RETURN
324   FUNNAM = '<set error handler>'
      RETURN

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/stdcss                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE STDCSS

C  Stdcss sets up a "standard" CSS network for several of the PVT
C  tests.  <Open structure> and <execute structure> set up the CSS
C  network as follows:


C                  100
C                 /  \
C                /    \
C              1/      \2
C              /        \
C             /          \
C         101              102     120   130             140
C          |              / | \     |    /|               |
C          |2            /  |  \    |   / |              1|
C          |           1/  2|  5\  2|  /3 |5              |
C          |           /    |    \  | /   |               |
C         103         /     |     \ |/    |              142
C                  104     105     106   107
C                  | |       |     |    / /\
C                 2| |5     /|\    |   / /  \
C                  | |    1/ | \2 1| 1/ /4   \5
C                  109    /  |  \  | / /      \
C                        /   |   \ |/ /       113
C                      110   |    108
C                            |     |
C                            |3    |2
C                            |     |
C                            |     |
C                            |    111
C                            |   / |
C                            |  /  |
C                            |1/  3|
C                            |/    |
C                           114   115

C  The nodes of the graph between (100 and 200) represent structures,
C  and the labelled edges are references to invoke (lower)
C  structures.  The labels (1-5) represent the element position of
C  the <execute structure> function within the calling structure.

C  <Execute structure> and <label> are the structure elements of the
C  individual structures contained in the network.  The values
C  between 100 and 199, inclusive, represent structures associated
C  with <execute structure> and the values between 900 and 999
C  represent label identifiers for <label>.

C open-structure status    none,        open
      INTEGER              PNONST,      POPNST
      PARAMETER           (PNONST = 0,  POPNST = 1)

C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)

      INTEGER EDMODE, STYPE, STRID, ERRIND

      CALL PQEDM (ERRIND, EDMODE)
      IF (ERRIND.EQ.0 .AND. EDMODE.EQ.PINSRT) THEN
C        lovely
      ELSE
         CALL UNMSG ('STDCSS invoked with edit-mode not = INSERT')
      ENDIF

C close any structure left opened
      CALL PQOPST (ERRIND, STYPE, STRID)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .EQ. POPNST) CALL PCLST

C delete old CSS
      CALL PDAS

      CALL POPST (100)
      CALL PEXST (101)
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (101)
      CALL PLB (902)
      CALL PEXST (103)
      CALL PLB (960)
      CALL PCLST

      CALL POPST (102)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PLB (900)
      CALL PLB (901)
      CALL PEXST (106)
      CALL PCLST

      CALL POPST (120)
      CALL PLB (907)
      CALL PEXST (106)
      CALL PCLST

      CALL POPST (130)
      CALL PLB (910)
      CALL PLB (912)
      CALL PEXST (106)
      CALL PLB (914)
      CALL PEXST (107)
      CALL PCLST

      CALL POPST (140)
      CALL PEXST (142)
      CALL PCLST

      CALL POPST (104)
      CALL PLB (920)
      CALL PEXST (109)
      CALL PLB (925)
      CALL PLB (926)
      CALL PEXST (109)
      CALL PCLST

      CALL POPST (105)
      CALL PEXST (110)
      CALL PEXST (108)
      CALL PEXST (114)
      CALL PLB (950)
      CALL PCLST

      CALL POPST (106)
      CALL PEXST (108)
      CALL PCLST

      CALL POPST (107)
      CALL PEXST (108)
      CALL PLB (930)
      CALL PLB (935)
      CALL PEXST (108)
      CALL PEXST (113)
      CALL PCLST

      CALL POPST (108)
      CALL PLB (961)
      CALL PEXST (111)
      CALL PCLST

      CALL POPST (111)
      CALL PEXST (114)
      CALL PLB (940)
      CALL PEXST (115)
      CALL PLB (942)
      CALL PLB (916)
      CALL PLB (947)
      CALL PLB (955)
      CALL PLB (947)
      CALL PLB (955)
      CALL PLB (940)
      CALL PLB (947)
      CALL PCLST

      CALL POPST (113)
      CALL PLB (901)
      CALL PCLST

      CALL POPST (114)
      CALL PLB (901)
      CALL PCLST

      CALL POPST (115)
      CALL PLB (901)
      CALL PCLST

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/csspth                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CSSPTH

C  Csspth sets up the "standard" CSS network for testing
C  ancestor and descendant paths.

C  Use <open structure> and <execute structure> to set up
C  the CSS as follows:
C
C                   101        106       108
C                  / | \       /
C                 /  |  \    1/
C               1/  2|  3\   /
C               /    |    \ /
C              /     |    107
C             /      |
C          102      103
C          | \      / \\
C          |  \   1/   \\
C         1|  2\  /    2\\3
C          |    \/       \\
C          |    104      105
C          |     |      /
C          |    1|    1/
C           \    |    /
C            \   |   /
C             \  |  /
C              \ | /
C               109

      CALL POPST (101)
      CALL PEXST (102)
      CALL PEXST (103)
      CALL PEXST (107)
      CALL PCLST

      CALL POPST (102)
      CALL PEXST (109)
      CALL PEXST (104)
      CALL PCLST

      CALL POPST (103)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PEXST (105)
      CALL PCLST

      CALL POPST (104)
      CALL PEXST (109)
      CALL PCLST

      CALL POPST (105)
      CALL PEXST (109)
      CALL PCLST

      CALL POPST (106)
      CALL PEXST (107)
      CALL PCLST

      CALL POPST (108)
      CALL PCLST

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/csseq                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION CSSEQ (CSSSHD)

C  CSSEQ accepts a character string parameter (cssshd = "CSS
C  should") which describes a CSS network and compares it to the CSS
C  state as reported by PHIGS inquire functions.  Csseq returns
C  .true. if they are equal, else .false.  The syntax of the input
C  string is:

C  cssshd             = path-list | blank
C  path-list          = path slash | path slash path-list
C  path               = path-element | path-element comma path
C  path-element       = structure-id comma element-reference
C  comma              = ","
C  slash              = "/"
C  blank              = " "
C  structure-id       = unsigned-integer
C  element-reference  = unsigned-integer

C  Spaces may appear anywhere.

C  Eg:  2,0/
C       2,3,4,0/
C       2, 3, 4, 0 / 2, 3, 5, 0 / 2, 3, 6, 0  /
C       20,0/30,0/40,0/
C       20,0/30,1,50,0/40,0/

C  If the CSS contains two networks:
C
C            10              110
C           /  \              |
C         20   30            120
C        /  \ /
C       40   50
C
C  it could be represented by:
C     "10,1,20,1,40,0/  10,1,20,2,50,0/  10,2,30,1,50,0/  110,3,120,0/"

C  A blank cssshd indicates an empty CSS

      CHARACTER  CSSSHD*(*)

C truncation method
      INTEGER    PHEAD,     PTAIL
      PARAMETER (PHEAD = 0, PTAIL = 1)

      INTEGER    PSIZE
      PARAMETER (PSIZE = 50)

      INTEGER    PATHSH(PSIZE, 50), PATHLN(PSIZE), ROOT(PSIZE)
      INTEGER    ERPATH (2,PSIZE), STRID
      INTEGER    APTHSZ, NUMPTH, IDUM, NDPATH, ISH, IR, IXPTH
      INTEGER    IEL, IPATH, NROOT, IEL1, IEL2, ERRIND

      LOGICAL    SINGLE

C interpret cssshd string into ragged 2D array of integers.
      CALL SET2D (CSSSHD, PSIZE, NUMPTH, PATHLN, PATHSH)

C now get all roots
      CALL GTROOT (NROOT, ROOT)

C Get all descendant paths of each root
      DO 300 IR = 1,NROOT
C structure ID of next root
         STRID = ROOT(IR)

C ndpath = how many descendant paths ?
         CALL PQPDE (STRID, PHEAD, 0, PSIZE, 0,
     1               ERRIND, NDPATH, IDUM, ERPATH)
         CALL CHKINQ ('pqpde', ERRIND)

C for singleton root, gotta force path of length 1
         SINGLE = (NDPATH .EQ. 0)
         IF (SINGLE) NDPATH = 1

C retrieve each descendant path
         DO 400 IXPTH = 1, NDPATH
            IF (SINGLE) THEN
               APTHSZ = 1
               ERPATH (1,1) = STRID
               ERPATH (2,1) = 0
            ELSE
               CALL PQPDE (STRID, PHEAD, 0, PSIZE, IXPTH,
     1                     ERRIND, IDUM, APTHSZ, ERPATH)
               CALL CHKINQ ('pqpde', ERRIND)
            ENDIF

C look for a matching should-path
            DO 500 ISH = 1, NUMPTH
C - start by seeking matching length
               IF (2*APTHSZ .NE. PATHLN(ISH) ) GOTO 500
C lengths match - try contents
               DO 600 IEL = 1, APTHSZ
                  IEL2 = 2*IEL
                  IEL1 = IEL2-1
                  IF (PATHSH (IEL1, ISH) .NE. ERPATH(1, IEL)) GOTO 500
                  IF (PATHSH (IEL2, ISH) .NE. ERPATH(2, IEL)) GOTO 500
600            CONTINUE
C OK they matched - delete out that should-path to prevent re-use
               PATHLN(ISH) = -1
               GOTO 400
500         CONTINUE
C No should-path match found for path reported by PHIGS - fail
            CSSEQ = .FALSE.
            RETURN

C next descendant path from current root
400      CONTINUE

C next root structure
300   CONTINUE

C match has been found for every path returned by pqpde.
C Now, simply check that all expected paths have been "used" by CSS

      DO 700 IPATH = 1,NUMPTH
         IF (PATHLN (IPATH) .NE. -1) THEN
            CSSEQ = .FALSE.
            RETURN
         ENDIF
700   CONTINUE
      CSSEQ = .TRUE.

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/strcon                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION STRCON (STRID, STRG)

C  Strcon is used to check the contents of a single structure.
C
C  Strid is the identifier of the structure to be examined.
C  Strg is a string representing a list of integers, which are
C  interpreted as type-content pairs.  Only the first integer
C  in an element's content is checked, i.e. that mapped to
C  the first slot in the integer array by PQCECO or PQECO
C
C  If the structure contains a sequence of elements exactly matching
C  these type-content pairs, strcon returns TRUE, otherwise FALSE.
C  A blank string may be used to designate an empty structure, but
C  the structure must exist.

C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)

      INTEGER    TYPCON(300), EP, SIZE, LSTELE, STRID, ERRIND
      INTEGER    IDIM,RDIM,SDIM, ISIZ,RSIZ,SSIZ, ELTYPE, STAT
      PARAMETER (IDIM = 20, RDIM = 20, SDIM = 20)

      INTEGER    IA(IDIM), SL(SDIM), ICON,ITYP, NOELEM
      REAL       RA(RDIM)
      CHARACTER  SA(SDIM)*80, MSG*100

C  error code for non-existent element
      PARAMETER (NOELEM = 202)

      CHARACTER  STRG*(*)

C generate integer array from strg
      CALL SETVS (STRG, TYPCON, SIZE)

      IF (MOD(SIZE,2) .NE. 0) THEN
         MSG = 'Illegal string passed to strcon; must be ' //
     1         'even number of elements: ' // STRG
         CALL UNMSG (MSG)
      ENDIF
C last element
      LSTELE = SIZE/2

C check structure existence
      CALL PQSTST (STRID, ERRIND, STAT)
      CALL CHKINQ ('pqstst', ERRIND)

      IF (STAT .EQ. PSNOEX) THEN
         WRITE (MSG, '(A,I7)')
     1     'Non-existent structure passed to strcon: ', STRID
         CALL UNMSG (MSG)
      ENDIF

C check that structure is not too long
      CALL PQETS (STRID, LSTELE+1, ERRIND, ELTYPE, ISIZ,RSIZ,SSIZ)
      IF (ERRIND .NE. NOELEM) THEN
         GOTO 666
      ENDIF

      IF (LSTELE .GT. 0) THEN
C check that structure is not too short
         CALL PQETS (STRID, LSTELE, ERRIND, ELTYPE, ISIZ,RSIZ,SSIZ)
         IF (ERRIND .EQ. NOELEM) THEN
            GOTO 666
         ENDIF
      ENDIF

      DO 100 EP = 1, LSTELE
         CALL PQETS (STRID, EP, ERRIND, ELTYPE, ISIZ,RSIZ,SSIZ)
         IF (ERRIND .EQ. 0) THEN
C  Normal return from pqets
            ICON = EP*2
            ITYP = ICON-1
            IF (ELTYPE .NE. TYPCON(ITYP)) THEN
C  types don't match
               GOTO 666
            ENDIF
            CALL PQECO (STRID, EP, IDIM,RDIM,SDIM,
     1                  ERRIND, ISIZ,IA, RSIZ,RA, SSIZ,SL,SA)
            IF (ERRIND .NE. 0) THEN
C  weird errind from pqeco
               WRITE (MSG, '(A,I7)')
     1           'Strange errind from pqeco in strcon: ', ERRIND
               CALL UNMSG (MSG)
            ENDIF
            IF (IA(1) .NE. TYPCON(ICON)) THEN
C  contents don't match
               GOTO 666
            ENDIF
         ELSE
C  weird errind from pqets
            WRITE (MSG, '(A,I7)')
     1        'Strange errind from pqets in strcon: ', ERRIND
            CALL UNMSG (MSG)
         ENDIF
100   CONTINUE
      STRCON = .TRUE.
      GOTO 667

666   CONTINUE
      STRCON = .FALSE.

667   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/setstr                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETSTR (STRID, STRG)

C  Setstr is used to set the contents of a single structure.
C
C  Strid is the identifier of the structure to be set.
C  Strg is a string representing a list of letter-integer pairs,
C  separated by commas, which are interpreted as type-content pairs.
C  A blank string may be used to designate an empty structure.  The
C  only two valid letters are L (for LABEL) and E (for EXECUTE
C  STRUCTURE). E.g. the string "L11,E101,L901" indicates that the
C  structure is to contain 3 elements: LABEL 11, EXECUTE STRUCTURE
C  101 and LABEL 901.  Blanks are ignored.

C  The specified structure is left closed.  If another structure is
C  originally open, it is closed.

C  open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER    STRID, ERRIND, OPSTAT, OPSTID, WLEN, NCOMMA
      INTEGER    IVAL, IERR

      CHARACTER  STRG*(*), WSTR*700

C de-blank string
      CALL DEBLNK (STRG, WSTR, WLEN)
      WLEN = WLEN+1
      WSTR(WLEN:WLEN) = ','

C  check open structure
      CALL PQOPST (ERRIND, OPSTAT, OPSTID)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (OPSTAT .EQ. POPNST) CALL PCLST

C  set up empty structure
      CALL PEMST (STRID)
      CALL POPST (STRID)

100   CONTINUE
      IF (WSTR .EQ. ' ') GOTO 600
      NCOMMA = INDEX(WSTR, ',')
      CALL PRSINT (WSTR(2:NCOMMA-1), IVAL, IERR)
      IF (IERR .NE. 0) THEN
         WRITE (WSTR, '(A,I4,A)') 'SETSTR got error code ', IERR,
     1          ' from PRSINT.'
         CALL UNMSG (WSTR)
      ENDIF

      IF     (WSTR(1:1) .EQ. 'L') THEN
         CALL PLB (IVAL)
      ELSEIF (WSTR(1:1) .EQ. 'E') THEN
         CALL PEXST (IVAL)
      ELSE
         CALL UNMSG ('Illegal code: ' // WSTR(1:1) //
     1               ' passed to SETSTR.')
      ENDIF
      WSTR = WSTR (NCOMMA+1:)
      GOTO 100

600   CONTINUE
      CALL PCLST

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/newstr                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE NEWSTR (START, NEWID)

C  NEWSTR searches for a non-existent structure identifier, starting
C  with START, and returns it, if found, in NEWID.

C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)

      INTEGER     START, NEWID, IX, STRSTI, ERRIND

      DO 100 IX = START, START+100
         CALL PQSTST (IX, ERRIND, STRSTI)
         CALL CHKINQ ('pqstst', ERRIND)
         IF (STRSTI .EQ. PSNOEX) THEN
            NEWID = IX
            RETURN
         ENDIF
100   CONTINUE
      CALL UNMSG ('NEWSTR cannot find a new structure identifier.')

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/gtroot                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE GTROOT (IROOT, ROOT)

C  gtroot gets all identifiers for root structures in the CSS and
C  returns them in the array root.  Iroot contains the number
C  of roots found.

      INTEGER    PSIZE
      PARAMETER (PSIZE = 50)

      INTEGER    ROOT(PSIZE), ERRIND, ERPATH (2,PSIZE)
      INTEGER    IXSTR, IDUM, IDSTR, NANPTH, IROOT, TOTSTR

C truncation method
      INTEGER    PHEAD,     PTAIL
      PARAMETER (PHEAD = 0, PTAIL = 1)

C totstr = how many structures?
      CALL PQSID  (0, ERRIND, TOTSTR, IDUM)
      CALL CHKINQ ('pqsid', ERRIND)
C number of roots so far
      IROOT = 0
C go thru all the structures, looking for roots
      DO 200 IXSTR = 1, TOTSTR
C idstr = next structure ID to check for rootedness
         CALL PQSID (IXSTR, ERRIND, IDUM, IDSTR)
         CALL CHKINQ ('pqsid', ERRIND)
C is idstr a root?  Ie, how many ancestor paths (nanpth) are there?
         CALL PQPAN (IDSTR, PTAIL, 1, PSIZE, 0,
     1               ERRIND, NANPTH, IDUM, ERPATH)
         CALL CHKINQ ('pqpan', ERRIND)
C if there are ancestor paths, then this is NOT a root.
         IF (NANPTH .GT. 0) GOTO 200
C check overflow
         IF (IROOT .GE. PSIZE) THEN
            CALL UNMSG ('Number of roots found by GTROOT ' //
     1                  'exceeds maximum.')
         ELSE
            IROOT = IROOT + 1
            ROOT (IROOT) = IDSTR
         ENDIF
200   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/sphdis                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION SPHDIS (STRID)

C  SPHDIS determines whether this implementation uses "spherical" or
C  "cubic" distance metric for purposes of ISS.  Based on fact that between
C  (0,0) and (.85,.85), the "spherical" distance = 1.202 but the "cubic"
C  distance = 0.85.

C  Input parameter:
C    STRID: available structure ID

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER   SPATH(2,1), FPATH(2,10), STRID, ERRIND, FPTHSZ
      INTEGER   IDUM(1)
      REAL      XA(1),YA(1)
      CHARACTER MSG*200

      CALL POPST (STRID)
      CALL PEMST (STRID)
      XA(1) = 0.85
      YA(1) = 0.85
      CALL PPL (1, XA,YA)
      CALL PCLST

      SPATH (1,1) = STRID
      SPATH (2,1) = 0
C  search distance of 1.0 should find marker for cubic, but not for spherical
      CALL PISS  (0.,0., 1.0, 1, SPATH, PNCLIP, 1,
     1            0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            10, ERRIND, FPTHSZ, FPATH)

      CALL PEMST (STRID)

      IF (ERRIND .NE. 0) THEN
         WRITE (MSG, '(A,I6)') 'ISS in SPHDIS returned error ' //
     1                         'indicator = ', ERRIND
         CALL UNMSG (MSG)
      ENDIF

      SPHDIS = FPTHSZ.EQ.0

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/chkelp                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CHKELP (ELPOS)

C  Chkelp checks whether or not the current actual element position
C  equals the expected position, as indicated by the parameter,
C  and issues pass or fail as appropriate.  In the case of
C  failure, it attempts to re-set the pointer to the correct value.

      INTEGER  ELPOS, ACTPOS, ERRIND

      CALL PQEP (ERRIND, ACTPOS)
      CALL CHKINQ ('pqep', ERRIND)
      IF (ELPOS .EQ. ACTPOS) THEN
         CALL PASS
      ELSE
         CALL FAIL
         CALL PSEP (ELPOS)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/avarnm                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE AVARNM (ARNM)

C  This routine returns an integer to be used as the name of an
C  archive file in an <open archive file> statement.  This file
C  is empty upon open, i.e. contains no structures.

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

      INTEGER    ARNM, NUMOLD, OLDNMS(1000), IX, NAMCT
      CHARACTER  ARNMCH*12
      LOGICAL    EXFILE

      DATA       NUMOLD /0/

C  Avoid individual, global logical unit numbers, any previously
C  used logical units, and special Fortran units 5,6,7
      ARNM = 1 + MAX(INDLUN, GLBLUN, 10)
      DO 100 IX = 1,NUMOLD
         IF (OLDNMS(IX) .GE. ARNM) ARNM = ARNM+1
100   CONTINUE
      NUMOLD = NUMOLD+1
      OLDNMS(NUMOLD) = ARNM

C  Seek new file name and ensure that a named file is opened with
C  the logical unit number = ARNM
      ARNMCH = 'PVT00000.ARC'
      DO 200 NAMCT = 1,100
         WRITE (ARNMCH(4:8), '(I5.5)') NAMCT
         INQUIRE (FILE=ARNMCH, EXIST=EXFILE, ERR=606)
         IF (.NOT. EXFILE) GOTO 300
200   CONTINUE
      CALL UNMSG ('AVARNM unable to find name of non-existent file.')

600   CONTINUE
      CALL UNMSG ('Error encountered in AVARNM when opening ' //
     1            'archive file: ' // ARNMCH)

606   CONTINUE
      CALL UNMSG ('Error encountered in AVARNM when inquiring file: ' //
     1             ARNMCH)

300   CONTINUE
      OPEN (UNIT=ARNM, ERR=600, STATUS='unknown', FILE=ARNMCH)

      END

C  This section of SUBLIB provides features for interactive tests,
C  especially the handling of the dialogue area.

C  Calling structure among major subroutines:

C                 DCHPF,DCHPFV,DCHFL,DCHFLV
C                 -------------------------
C                           |
C             --------------|
C             |             |
C             |  DYNPF      |
C             |  / |        |
C             | /  |        |               DLSTPF
C             |/   |        |                 |
C             |   DYN     DCHOIC   DRLVAL   DILIST   OPMSGW
C             |    |        |        |        |        |
C             |    -------------------------------------
C             |                 |
C           OPFAIL            DLINE
C              \              /  |
C               \            /   |
C             OPCOFL     OPCOMT  |
C                  \      /      |
C                   \    /       |
C                    \  /        |
C                    OPCO        |
C                      |         |
C                   DSTRNG       |
C                       \        |
C                        \       |
C                      --------------
C                      |            |
C                   IACMSG        IACANS
C                   / |  \
C                  /  |   \
C             FITPAR  |   SETASF
C               |  \  |
C               |   \ |
C               |   LINBRK
C               |   /
C               |  /
C             SCAPAR
  

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/setdlg                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETDLG (PICSTR, DLGSTR, TXCI)

C  SETDLG performs a number of chores to initialize the workstation
C  for interaction with the operator.  It is normally called right
C  after <open phigs>.  There are three input parameters:
C    PICSTR : structure identifier for the picture to be shown
C    DLGSTR : structure identifier for the dialogue area (if used)
C    TXCI   : text color index for dialogue text = absolute value
C             of TXCI.  If TXCI negative, color table initialization
C             is suppressed.

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

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C   Example of screen layout set by SETDLG, with dialogue area at right.
C   Dialogue area = prompt area + echo area = rectangle at right or
C   bottom of screen.
C
C   screen:
C   -------------------------------------------
C   |         unused            |             |
C   |---------------------------|             |
C   |                           |             |
C   |                           |   prompt    |
C   |                           |             |
C   |       picture area        |             |
C   |         (square)          |             |
C   |                           |             |
C   |                           |             |
C   |                           |-------------|
C   |                           |             |
C   |                           |    echo     |
C   |                           |             |
C   -------------------------------------------

C  COMMON DIALOG variables
C  -----------------------
C  DOUTYP* : method of sending interactive output to operator:
C            1-Fortran print, 2-PHIGS <message>, 3-PHIGS <text>.
C  DINTYP* : method of receiving interactive input from operator:
C            1-Fortran read, 2-PHIGS <request string>.
C  DSTDNR* : Logical device number for request string
C  DSTRID  : Identifier of structure for interactive dialogue
C  PSTRID  : Identifier of structure for interactive picture
C  DTCLIM* : Maximum number of characters per line for interactive prompt
C  SCRMOD* : Screen mode for operator interaction: 0-interaction off-screen,
C            1-dialogue at bottom, 2-dialogue at right, 3-toggle dialogue
C            and picture on full screen.
C  DTXCI   : Dialogue text color index
C  SPECWT  : Specific workstation type in which dialogue takes place
C  DSIZE*  : For split screen, size of dialogue area as fraction of
C            full screen
C  EFRAC*  : Fraction of dialogue area for echo, if DINTYP=2 and DOUTYP=3
C  DYXRAT  : Ratio of height to width of prompt area within dialogue area
C  SYXRAT  : Ratio of height to width of full screen
C  MTRPDC* : Absolute size of DC units = meters per DC unit
C  WCPDC   : WC units per DC unit for view #1 (picture)
C  QVIS    : Minimum distance assumed to be visually distinguishable,
C            in DC units
C  *initialized by INITGL

      COMMON /SCRFMT/ PICL,PICR,PICB,PICT, PRTL,PRTR,PRTB,PRTT,
     1                ECHL,ECHR,ECHB,ECHT
      REAL            PICL,PICR,PICB,PICT, PRTL,PRTR,PRTB,PRTT,
     1                ECHL,ECHR,ECHB,ECHT

C  COMMON SCRFMT (screen format) variables
C  -----------------------
C  PICL,PICR,PICB,PICT : NPC bounds of picture area
C  PRTL,PRTR,PRTB,PRTT : NPC bounds of prompt area
C  ECHL,ECHR,ECHB,ECHT : DC bounds of echo area

C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)

C viewtype
      INTEGER    PPARL,     PPERS
      PARAMETER (PPARL = 0, PPERS = 1)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

C device coordinate units
      INTEGER    PMETRE,     POTHU
      PARAMETER (PMETRE = 0, POTHU = 1)
C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C colour available
C                monochrome  color
      INTEGER    PMONOC,     PCOLOR
      PARAMETER (PMONOC = 0, PCOLOR = 1)

      INTEGER    SPECON, DCUN, ADMAXX,ADMAXY
      INTEGER    IA(2), IL, LDR, WNSIZ, PICSTR, DLGSTR, TXCI
      INTEGER    NUMCOL, COLAVL, IX
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM8

      REAL       DCMAXX,DCMAXY, VORMAT(4,4), VMPMAT(4,4)
      REAL       Z,U, RA(2), VWCPLM(6), WNLM(4), SCRX,SCRY, SCRMIN
      REAL       RGBV(3,0:4), RDUM(9)
      PARAMETER (Z=0.0, U=1.0)

      INTEGER    MLDR
      PARAMETER (MLDR = 10)
      CHARACTER  MSG*300, SA(2)*80, DATREC(MLDR)*80

CUSERMOD  default color initialization
C                 black        bluish-green pale-yellow  
C                 sky-blue     white
      DATA RGBV / 0.0,0.0,0.0, 0.0,1.0,0.3, 1.0,1.0,0.3, 
     1            0.3,1.0,1.0, 1.0,1.0,1.0 /

C open workstation
      CALL POPWK (WKID, CONID, WTYPE)

C save parameters in DIALOG common
      PSTRID = PICSTR
      DSTRID = DLGSTR
      DTXCI  = ABS(TXCI)

C  SETDLG sets up views for picture and prompt as follows:
C
C       PICTURE (view #1)      PROMPT (view #2)       FULL SCREEN (view #3)
C       x-bounds   y-bounds    x-bounds   y-bounds    x-bounds   y-bounds
C       --------   --------    --------   --------    --------   --------
C  WC   0-1        0-1         0-1        0-DYXRAT    0-1        0-SYXRAT
C  NPC  PICL-PICR  PICB-PICT   PRTL-PRTR  PRTB-PRTT   0-SCRX     0-SCRY

      CALL PSDUS  (WKID, PWAITD, PNIVE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
      CALL PQDSP  (SPECWT, ERRIND, DCUN, DCMAXX,DCMAXY, ADMAXX,ADMAXY)
      CALL CHKINQ ('pqdsp', ERRIND)

C make half-hearted attempt to set up colors 0,1,2,3,4
      IF (TXCI .LT. 0) GOTO 60
      CALL PQCF  (SPECWT, ERRIND, IDUM1, COLAVL, IDUM2, RDUM)
      CALL CHKINQ ('pqcf', ERRIND)
      IF (COLAVL .NE. PCOLOR) GOTO 60

      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             NUMCOL,IDUM8)
      CALL CHKINQ ('pqwksl', ERRIND)
      CALL PSCMD (WKID, PRGB)
      DO 50 IX = 0, MIN(4, NUMCOL-1)
         CALL PSCR  (WKID, IX, 3, RGBV(1, IX))
50    CONTINUE
60    CONTINUE

C set up workstation transformation to use full screen
      SYXRAT = DCMAXY/DCMAXX
      IF (SYXRAT .GT. U) THEN
C tall screen
         SCRY = U
         SCRX = 1/SYXRAT
      ELSE
C wide screen
         SCRY = SYXRAT
         SCRX = U
      ENDIF
C NPC
      CALL PSWKW (WKID, Z, SCRX, Z, SCRY)
C DC
      CALL PSWKV (WKID, Z, DCMAXX, Z, DCMAXY)

C default NPC values for picture area = largest square in screen.
      SCRMIN = MIN(SCRX,SCRY)
      PICL = Z
      PICR = SCRMIN
      PICB = Z
      PICT = SCRMIN

C default NPC values for prompt area = whole screen.
      PRTL = Z
      PRTR = SCRX
      PRTB = Z
      PRTT = SCRY

      IF (SCRMOD .EQ. 1) THEN
C  dialogue at bottom
         PRTT = DSIZE * SCRY
         PICB = PRTT
         PICR = MIN (SCRY-PICB, SCRX)
         PICT = PICB + PICR
      ELSEIF (SCRMOD .EQ. 2) THEN
C  dialogue at right
         PRTL = (1-DSIZE) * SCRX
         PICT = MIN (PRTL, SCRY)
         PICR = PICT
      ELSE
C        SCRMOD .EQ. 0 or 3 - OK as is
      ENDIF

C  break up dialogue area into prompt/echo areas
      ECHL = PRTL
      ECHR = PRTR
      ECHB = PRTB
      ECHT = EFRAC * (PRTT-PRTB) + PRTB
      PRTB = ECHT

C ratio of height of prompt area to its width - allows constant
C width of 1.0
      DYXRAT = (PRTT-PRTB) / (PRTR-PRTL)

C set up view #1 for picture
      CALL PEVOM3 (Z,Z,Z, Z,Z,U, Z,U,Z, ERRIND, VORMAT)
      CALL CHKINQ ('pevom3', ERRIND)
      CALL SETRVS ('0,1,0,1', WNLM, WNSIZ)
      VWCPLM(1) = PICL
      VWCPLM(2) = PICR
      VWCPLM(3) = PICB
      VWCPLM(4) = PICT
      VWCPLM(5) = Z
      VWCPLM(6) = U
      CALL PEVMM3 (WNLM, VWCPLM, PPARL, .5,.5,2.0, Z,Z,U,
     1             ERRIND, VMPMAT)
      CALL CHKINQ ('pevmm3', ERRIND)
      CALL PSVWR3 (WKID, 1, VORMAT,VMPMAT, VWCPLM,
     1             PNCLIP,PNCLIP,PNCLIP)

C set up view #2 for prompt
      WNLM(4) = DYXRAT
      VWCPLM(1) = PRTL
      VWCPLM(2) = PRTR
      VWCPLM(3) = PRTB
      VWCPLM(4) = PRTT
      CALL PEVMM3 (WNLM, VWCPLM, PPARL, .5,DYXRAT/2,U, Z,Z,U,
     1             ERRIND, VMPMAT)
      CALL CHKINQ ('pevmm3', ERRIND)
      CALL PSVWR3 (WKID, 2, VORMAT,VMPMAT, VWCPLM,
     1             PNCLIP,PNCLIP,PNCLIP)

C set up view #3 for full screen
      WNLM(4) = SYXRAT
      VWCPLM(1) = 0.
      VWCPLM(2) = SCRX
      VWCPLM(3) = 0.
      VWCPLM(4) = SCRY
      CALL PEVMM3 (WNLM, VWCPLM, PPARL, .5,SYXRAT/2,U, Z,Z,U,
     1             ERRIND, VMPMAT)
      CALL CHKINQ ('pevmm3', ERRIND)
      CALL PSVWR3 (WKID, 3, VORMAT,VMPMAT, VWCPLM,
     1             PNCLIP,PNCLIP,PNCLIP)

300   CONTINUE
      IF (DINTYP .EQ. 1) THEN
C  input via READ: skip initialization of string device.
         GOTO 600
      ELSEIF (DINTYP .NE. 2) THEN
         WRITE (MSG, '(A,I5)') 'Invalid input type in SETDLG: ', DINTYP
         CALL UNMSG (MSG)
      ENDIF

C Input to be done via request-string: convert NPC values for
C echo area to DC
      ECHL = DCMAXX * ECHL/SCRX
      ECHR = DCMAXX * ECHR/SCRX
      ECHB = DCMAXY * ECHB/SCRY
      ECHT = DCMAXY * ECHT/SCRY

C  pack data record with 72,1, signifying buffer size and edit position
      CALL SETVS ('72,1', IA, IL)

      CALL PPREC (IL,IA, 0,RA, 0,IA,SA, MLDR, ERRIND, LDR,DATREC)
      CALL CHKINQ ('pprec', ERRIND)
C initialize string device
      CALL PINST (WKID, DSTDNR, 1, ' ', 1, ECHL,ECHR,ECHB,ECHT,
     1            LDR,DATREC)

600   CONTINUE
C  compute WC per DC within picture area
      WCPDC = SCRX / (DCMAXX * (PICR-PICL) )

C  set "quantum" of visual distinguishability to 2.0 mm, in DC units
      QVIS = 0.002 / MTRPDC

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/endit                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ENDIT

C  ENDIT performs all normal close-out chores for a PVT test:
C  it clears and closes all open workstations, closes the open
C  structure if there is one, closes PHIGS and issues WINDUP.

C system state value
      INTEGER    PPHCL,     PPHOP
      PARAMETER (PPHCL = 0, PPHOP = 1)

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER    WKID, ERRIND, NUMWK, OPSTAT, IX, SYSST, IDUM

C  check if PHIGS open
      CALL PQSYS (SYSST)
      IF (SYSST .EQ. PPHCL) GOTO 666

C  close all open workstations
      CALL PQOPWK (0, ERRIND, NUMWK, IDUM)
      CALL CHKINQ ('pqopwk', ERRIND)
      DO 100 IX = 1,NUMWK
C  always delete 1st element of remaining list - list changes each
C  time thru loop because of call to PCLWK
         CALL PQOPWK (1, ERRIND, IDUM, WKID)
         CALL CHKINQ ('pqopwk', ERRIND)
         CALL PUPAST (WKID)
         CALL PCLWK  (WKID)
100   CONTINUE

C  close open structure
      CALL PQOPST (ERRIND, OPSTAT, IDUM)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (OPSTAT .EQ. POPNST) THEN
         CALL PCLST
      ENDIF
      CALL PCLPH

666   CONTINUE
      CALL WINDUP

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/win6                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE WIN6 (STRID, COLI, XSIZ,YSIZ, XWINLO, YWINLO)

C  WIN6 sets up a structure which generates 6 labelled
C  windows on the screen.

C  Input parameters:
C    STRID         : Identifier of structure to contain windows
C    COLI          : Color index to be used
C  Output parameters:
C    XSIZ,YSIZ     : Size of windows
C    XWINLO,YWINLO : Location of lower left corner of windows

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)
C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    IX,IY,STRID, COLI, WINID

      REAL       TXHT, XSIZ,YSIZ, XWINLO(6), YWINLO(6)
      REAL       XA(2),YA(2), Z,U, XLOC,YLOC
      PARAMETER (Z = 0.0, U = 1.0)

      CHARACTER  DIG*1

      XSIZ = 0.3333
      YSIZ = 0.3333
      TXHT = 0.1666

      CALL POPST (STRID)
      CALL PSLWSC (0.0)
      CALL PSPLCI (COLI)
      CALL PSTXCI (COLI)
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (U)
      CALL PSCHH  (0.3 * TXHT)
      CALL PSCHUP (Z,U)
      CALL PSTXAL (PACENT, PATOP)
      WINID = 1
      DO 100 IY = 1,0,-1
         XA(1) = Z
         XA(2) = U
         YLOC = TXHT + IY*(YSIZ+TXHT)
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL (2, XA,YA)
         YA(1) = YLOC + YSIZ
         YA(2) = YA(1)
         CALL PPL (2, XA,YA)

      DO 200 IX = 0,3
         XLOC = IX*XSIZ
         YA(1) = YLOC
         YA(2) = YLOC + YSIZ
         XA(1) = XLOC
         XA(2) = XLOC
         CALL PPL (2, XA,YA)
         IF (IX .EQ. 3) GOTO 200

         XWINLO(WINID) = XLOC
         YWINLO(WINID) = YLOC
         WRITE (DIG, '(I1)') WINID
         CALL PTX (XLOC + XSIZ/2, YLOC - 0.1*TXHT, DIG)
         WINID = WINID+1
200   CONTINUE
100   CONTINUE

      CALL PCLST

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/wcnpc                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE WCNPC (WCX,WCY, NPCX,NPCY, NPCPWC)

C  WCNPC converts a 2D point in WC to the equivalent point in NPC
C  within view#1 for the picture area, which maps 0:1,0:1 (WC) to
C  PICL:PICR, PICB:PICT (NPC).  It also returns the NPC/WC ratio.

      COMMON /SCRFMT/ PICL,PICR,PICB,PICT, PRTL,PRTR,PRTB,PRTT,
     1                ECHL,ECHR,ECHB,ECHT
      REAL            PICL,PICR,PICB,PICT, PRTL,PRTR,PRTB,PRTT,
     1                ECHL,ECHR,ECHB,ECHT

      REAL    WCX,WCY, NPCX,NPCY, NPCPWC

      NPCX = WCX * (PICR-PICL) + PICL
      NPCY = WCY * (PICT-PICB) + PICB
      NPCPWC = PICT-PICB

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/locppm                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LOCPPM (YLOC, XVAL)

C  LOCPPM draws a polymarker at the real y-location corresponding to
C  the integer index given in YLOC.

      INTEGER    YLOC

      REAL       XVAL(1), YVAL(1), YLOCEL

      YVAL(1) = YLOCEL(YLOC)
      CALL PPM (1, XVAL,YVAL)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/drwrec                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DRWREC (XL,XH, YL,YH)

C  DRWREC draws a rectangle as specified by x-low,x-high,y-low,y-high

      REAL     XL,XH, YL,YH, XA(5),YA(5)

      XA(1) = XL
      XA(2) = XL
      XA(3) = XH
      XA(4) = XH
      XA(5) = XL

      YA(1) = YL
      YA(2) = YH
      YA(3) = YH
      YA(4) = YL
      YA(5) = YL
      CALL PPL (5,XA,YA)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/txexal                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TXEXAL (TXFONT, TXPATH, TXSTR,
     1                   NTXWD, NTXHT, HTAB, VTAB)

C  TXEXAL returns not only the size of the nominal text extent
C  rectangle, but also the location within it of the various text
C  alignment positions.

C  Input parameters:
C    TXFONT : text font to be used for inquiry
C    TXPATH : text path to be used for inquiry
C    TXSTR  : text string to be used for inquiry
C  Output parameters:
C    NTXWD  : nominal width of text rectangle
C    NTXHT  : nominal height of text rectangle
C    HTAB   : nominal position of horizontal text alignments
C    VTAB   : nominal position of vertical text alignments

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C text alignment horizontal                                
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

      INTEGER    TXFONT, TXPATH, ERRIND, IX

      REAL       NTXWD, NTXHT, HTAB(PALEFT:PARITE), VTAB(PATOP:PABOTT)
      REAL       TXRX(2),TXRY(2), RDUM1,RDUM2

      CHARACTER  TXSTR*(*)

      CALL PQTXX  (SPECWT, TXFONT, 1.,0.,1., TXPATH, PALEFT, PABOTT,
     1             TXSTR, ERRIND, TXRX,TXRY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      NTXWD = ABS(TXRX(2) - TXRX(1))
      NTXHT = ABS(TXRY(2) - TXRY(1))

C  save normalized heights in table:
      DO 100 IX = PATOP, PABOTT
         CALL PQTXX  (SPECWT, TXFONT, 1.,0.,1., TXPATH, PALEFT, IX,
     1                TXSTR, ERRIND, TXRX,TXRY, RDUM1,RDUM2)
         CALL CHKINQ ('pqtxx', ERRIND)
         VTAB(IX) = NTXHT - TXRY(2)
100   CONTINUE

C  save normalized widths in table:
      HTAB(PALEFT) = 0.0
      HTAB(PACENT) = NTXWD/2
      HTAB(PARITE) = NTXWD

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/intsty                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION INTSTY (SPECWT, RQSTYL)

C  INTSTY indicates whether or not a requested interior style is
C  available for a workstation type.
C
C  Input parameters:
C    SPECWT : workstation type
C    RQSTYL : the interior style in question

      INTEGER  SPECWT, RQSTYL, IX, ERRIND, NIS, THISIS
      INTEGER  IDUM1,IDUM2,IDUM3,IDUM4

      CALL PQIF (SPECWT, 0,0, ERRIND, NIS, IDUM1,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)

      DO 100 IX = 1,NIS
         CALL PQIF (SPECWT, IX, 0, ERRIND,
     1              IDUM1, THISIS, IDUM2,IDUM3,IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS .EQ. RQSTYL) THEN
            INTSTY = .TRUE.
            RETURN
         ENDIF
100   CONTINUE

      INTSTY = .FALSE.

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/denhat                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DENHAT (STRID, MAXH, SPECWT, IHAT)

C  DENHAT displays a random selection of hatch styles and asks the 
C  operator to select a dense one.
  
C  Input parameters:
C    STRID  : identifier for available closed posted structure 
C    MAXH   : maximum number of styles to display
C    SPECWT : specific workstation type
C  Output parameters:
C    IHAT   : selected hatch style
           
C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)
                                                                  
      INTEGER   STRID, MAXH, SPECWT, IHAT, NUMHS, NUMLIN, PERM(100)
      INTEGER   ERRIND, HS(100), IX, ANS
      INTEGER   IDUM1,IDUM2,IDUM3,IDUM4

      REAL      YINCR,YTOP,YLOC, XA(4),YA(4)

      CALL POPST (STRID)
      CALL PQIF (SPECWT,0,0,ERRIND, IDUM1,IDUM2, NUMHS,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
      NUMLIN = MIN(MAXH, ABS(NUMHS))
      CALL RNSET (NUMLIN, ABS(NUMHS), PERM)
      YINCR = 1 / (NUMLIN+1.0)
      YTOP  = 1 - YINCR
      YLOC = YTOP
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      CALL PSIS (PHATCH)
      XA(1) = 0.2
      XA(2) = 0.9
      XA(3) = 0.9
      XA(4) = 0.2
      DO 60 IX = 1,NUMLIN
         YA(1) = YLOC + 0.4*YINCR
         YA(2) = YLOC + 0.4*YINCR
         YA(3) = YLOC - 0.4*YINCR
         YA(4) = YLOC - 0.4*YINCR
         CALL PQIF (SPECWT,0,PERM(IX), ERRIND,
     1              IDUM1,IDUM2,IDUM3,HS(IX),IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         CALL PSISI (HS(IX))
         CALL PFA (4, XA,YA)
         YLOC = YLOC-YINCR
60    CONTINUE
      CALL DCHOIC ('Pick a dense hatch style, preferably diagonal.',
     1             1, NUMLIN, ANS)
      CALL PEMST (STRID)
      CALL PCLST
      IHAT = HS(ANS)
      
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/numlab                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE NUMLAB (HINUM, RTMARG, YTOP, YINCR)

C  NUMLAB draws a sequence of numeric labels down a vertical column.
C  Labels are drawn in stroke precision.  A non-existent structure
C  is used as a substructure if there is a currently open structure,
C  otherwise it is used as the main structure.  If used as a
C  substructure, an <execute structure> element is inserted in the
C  main structure.  Most text attributes are set explicitly, but
C  text colour index is inherited.

C  Input parameters:
C    HINUM  : highest number; labels 1-HINUM are drawn.
C    RTMARG : right-hand margin for labels
C    YTOP   : vertically centered location of top label (#1)
C    YINCR  : vertical increment for labels

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)
C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

      INTEGER    HINUM, ERRIND, EDITMO, OPSTAT, OPID, ELPTR, LABSTR
      INTEGER    TXFNT, IX

      REAL       RTMARG, YTOP, YINCR, Z,U, CHXP,CHHT,CHSP, YPOS
      REAL       TXX(2),TXY(2), CCX,CCY, TXH,TXV

      CHARACTER  D2*3

      IF (HINUM.LT.1 .OR. HINUM.GT.99) THEN
         CALL UNMSG ('Invalid value for HINUM in NUMLAB.')
      ENDIF

C  save edit state, open-structure state
      CALL PQEDM  (ERRIND, EDITMO)
      CALL CHKINQ ('pqedm', ERRIND)
      CALL PQOPST (ERRIND, OPSTAT, OPID)
      CALL CHKINQ ('pqopst', ERRIND)
C  If a structure is open, save element-pointer and close structure
      IF (OPSTAT .EQ. POPNST) THEN
         CALL PQEP (ERRIND, ELPTR)
         CALL CHKINQ ('pqep', ERRIND)
         CALL PCLST
      ENDIF

C  get a new structure identifier
      CALL NEWSTR (950, LABSTR)
      CALL PSEDM (PINSRT)
      CALL POPST (LABSTR)
      CALL PEMST (LABSTR)

C  set all aspects to individual
      CALL SETASF (PINDIV)

CUSERMOD  text attributes for labels
      Z = 0.0
      U = 1.0
      TXFNT = 1
      CHSP  = 0.0
      CHXP  = 0.8
      CALL PSTXFN (TXFNT)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (CHXP)
      CALL PSCHSP (CHSP)
      CALL PSCHUP (Z,U)
      CALL PSTXP  (PRIGHT)
      CALL PSTXAL (PARITE, PAHALF)

C  adjust character height according to text-extent
      CALL PQTXX (SPECWT, TXFNT, CHXP, CHSP, 1., PRIGHT, PALEFT,PABOTT,
     1            '88:', ERRIND, TXX,TXY, CCX,CCY)
      CALL CHKINQ ('pqtxx', ERRIND)
      TXH = ABS(TXX(1) - TXX(2))
      TXV = ABS(TXY(1) - TXY(2))

C  scale down vertically or horizontally, to lower size
      CHHT = MIN (0.9*RTMARG/TXH, 0.65*YINCR / TXV)
      CALL PSCHH  (CHHT)
      YPOS = YTOP

      DO 100 IX = 1,HINUM
         WRITE (D2, '(I2,A)') IX, ':'
         CALL PTX (RTMARG, YPOS, D2)
         YPOS = YPOS-YINCR
100   CONTINUE
      CALL PCLST

C  restore edit state, open-structure state
      CALL PSEDM (EDITMO)
      IF (OPSTAT .EQ. POPNST) THEN
         CALL POPST (OPID)
         CALL PSEP  (ELPTR)
         CALL PEXST (LABSTR)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/vislab                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE VISLAB (TXT, ALIGN, XLO,XHI,YLO,YHI)

C  VISLAB draws a text label within a specified box.  Labels are
C  drawn in stroke precision.  The text label is scaled uniformly
C  (aspect ratio preserved) so that it just fits in the box, and
C  then aligned as requested.  Thus, there may be empty space left
C  within the box. A new structure is used as a substructure if
C  there is a currently open structure, otherwise it is used as the
C  main structure.  If used as a substructure, an <execute
C  structure> element is inserted in the main structure. Most text
C  attributes are set explicitly, but text colour index is
C  inherited.

C  Input parameters:
C    TXT     : Contents of text label to be written
C    ALIGN   : alignment code: L,R,T,B,C for left,right,top,bottom,center
C    XLO,XHI : horizontal location for label
C    YLO,YHI : vertical location for label

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)
C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

      INTEGER    ERRIND, EDITMO, OPSTAT, OPID, ELPTR, LABSTR
      INTEGER    TXFNT, ALDEX, ALH(5), ALV(5)

      REAL       XLO,XHI, YLO,YHI, Z,U, CHXP,CHHT,CHSP
      REAL       XLOC,YLOC
      REAL       TXX(2),TXY(2), CCX,CCY, TXH,TXV

      CHARACTER  TXT*(*), ALIGN*1

      DATA  ALH / PALEFT,PARITE,PACENT,PACENT,PACENT /
      DATA  ALV / PAHALF,PAHALF,PATOP, PABOTT,PAHALF /

      ALDEX = INDEX('LRTBC', ALIGN) 
      IF (ALDEX .LE. 0) THEN
         CALL UNMSG ('Invalid alignment code in VISLAB: ' // ALIGN)
      ENDIF

C  save edit state, open-structure state
      CALL PQEDM  (ERRIND, EDITMO)
      CALL CHKINQ ('pqedm', ERRIND)
      CALL PQOPST (ERRIND, OPSTAT, OPID)
      CALL CHKINQ ('pqopst', ERRIND)
C  If a structure is open, save element-pointer and close structure
      IF (OPSTAT .EQ. POPNST) THEN
         CALL PQEP (ERRIND, ELPTR)
         CALL CHKINQ ('pqep', ERRIND)
         CALL PCLST
      ENDIF

C  set up new structure for labels
      CALL NEWSTR (950, LABSTR)
      CALL PSEDM (PINSRT)
      CALL POPST (LABSTR)
      CALL PEMST (LABSTR)

C  set all aspects to individual
      CALL SETASF (PINDIV)

CUSERMOD  text attributes for labels
      Z = 0.0
      U = 1.0
      TXFNT = 1
      CHHT  = 1.0
      CHSP  = 0.1
      CHXP  = 0.8
      CALL PSTXFN (TXFNT)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (CHXP)
      CALL PSCHSP (CHSP)
      CALL PSCHUP (Z,U)
      CALL PSTXP  (PRIGHT)
      CALL PSTXAL (ALH(ALDEX), ALV(ALDEX))

C  adjust character height according to text-extent
      CALL PQTXX (SPECWT, TXFNT, CHXP, CHSP, CHHT, PRIGHT, 
     1            PALEFT,PABOTT, TXT, ERRIND, TXX,TXY, CCX,CCY)
      CALL CHKINQ ('pqtxx', ERRIND)
      TXH = ABS(TXX(1) - TXX(2))
      TXV = ABS(TXY(1) - TXY(2))

C  scale vertically and horizontally by same amount to fit within box.
      CHHT = MIN((XHI-XLO)/TXH, (YHI-YLO)/TXV)
      CALL PSCHH (CHHT)
C  get correct alignment point - assume centered and then move
      XLOC = (XLO+XHI)/2
      YLOC = (YLO+YHI)/2
      IF (ALDEX .EQ. 1) XLOC = XLO
      IF (ALDEX .EQ. 2) XLOC = XHI
      IF (ALDEX .EQ. 3) YLOC = YHI
      IF (ALDEX .EQ. 4) YLOC = YLO

      CALL PTX (XLOC, YLOC, TXT)
      CALL PCLST

C  restore edit state, open-structure state
      CALL PSEDM (EDITMO)
      IF (OPSTAT .EQ. POPNST) THEN
         CALL POPST (OPID)
         CALL PSEP  (ELPTR)
         CALL PEXST (LABSTR)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/dynpf                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DYNPF (PROMPT, EXPCTD)

C  DYNPF is used to ask the operator a yes/no question and issue pass
C  or fail as a result.  If the answer indicates failure, the operator
C  is given the opportunity to comment.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    EXPCTD      : expected answer (to pass) - must be y or n

      CHARACTER   PROMPT*(*), EXPCTD*1

      LOGICAL     EXPY, DYN

      IF     (EXPCTD.EQ.'Y' .OR. EXPCTD.EQ.'y') THEN
         EXPY = .TRUE.
      ELSEIF (EXPCTD.EQ.'N' .OR. EXPCTD.EQ.'n') THEN
         EXPY = .FALSE.
      ELSE
         CALL UNMSG ('DYNPF called with invalid value: ' // EXPCTD)
      ENDIF

      IF (EXPY .EQV. DYN (PROMPT)) THEN
         CALL PASS
      ELSE
         CALL OPFAIL
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/dyn                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION DYN (PROMPT)

C  DYN is used to ask the operator a yes/no question and return
C  a logical value as a result: .true. for yes, .false. for no.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.

      INTEGER     ITRIM

      CHARACTER   PROMPT*(*), LINEIN*100, MSGTXT*3000

C  display prompt
      MSGTXT = PROMPT(1:ITRIM(PROMPT)) // ' (y or n)'

100   CONTINUE
      CALL DLINE (MSGTXT, LINEIN)
      IF     (LINEIN.EQ.'Y' .OR. LINEIN.EQ.'y') THEN
         DYN = .TRUE.
      ELSEIF (LINEIN.EQ.'N' .OR. LINEIN.EQ.'n') THEN
         DYN = .FALSE.
      ELSE
C  show error message in dialogue area and pause
         CALL OPMSGW ('Response must be y or n.')
         GOTO 100
      ENDIF

      END

C  There are four closely related functions all of which use
C  DCHOIC.  DCHPF and DCHFL both treat the response as a location
C  in PERM.  The value at that location is tested against TRUANS.
C  DCHPFV and DCHFLV both treat the response as an integer value to
C  be tested directly against TRUANS.  DCHPF and DCHPFV both issue
C  either pass or fail as a result.  DCHFL and DCHFLV both issue
C  fail, but not pass, and, being functions rather than subroutines,
C  their returned value may be used for further control.
C
C             |  location   value
C  -----------+-------------------
C  pass/fail  |  DCHPF      DCHPFV
C  fail only  |  DCHFL      DCHFLV

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/dchpf                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DCHPF (PROMPT, MAXVAL, TRUANS, PERM)

C  DCHPF gets an integer response from the operator, to be used as
C  an index into PERM, and issues pass/fail as a result.  In all
C  cases the operator is given a choice between 0 and MAXVAL, where
C  0 indicates "none of the above" and triggers an operator comment.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    MAXVAL      : highest valid response.
C    TRUANS      : expected value from operator.
C    PERM        : permutation of 1-MAXVAL, used to randomize prompt.

      INTEGER     TRUANS, MAXVAL, PERM(*), ANS

      CHARACTER   PROMPT*(*)

      CALL DCHOIC (PROMPT, 0,MAXVAL, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPFAIL
      ELSE
         CALL IFPF (PERM(ANS) .EQ. TRUANS)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/dchpfv                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DCHPFV (PROMPT, MAXVAL, TRUANS)

C  DCHPFV operates just like DCHPF, except that the response is
C  tested directly against TRUANS.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    MAXVAL      : highest valid response.
C    TRUANS      : expected value from operator.

      INTEGER     TRUANS, MAXVAL, ANS

      CHARACTER   PROMPT*(*)

      CALL DCHOIC (PROMPT, 0,MAXVAL, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPFAIL
      ELSE
         CALL IFPF (ANS .EQ. TRUANS)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/dchfl                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION DCHFL (PROMPT, MAXVAL, TRUANS, PERM)

C  DCHFL gets an integer response from the operator, to be used as
C  an index into PERM, and, if the result is incorrect, issues fail
C  and returns TRUE.  If correct, it returns FALSE, but does not
C  issue pass.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    MAXVAL      : highest valid response.
C    TRUANS      : expected value from operator.
C    PERM        : permutation of 1-MAXVAL, used to randomize prompt.

      INTEGER     TRUANS, MAXVAL, PERM(*), ANS

      CHARACTER   PROMPT*(*)

      CALL DCHOIC (PROMPT, 0,MAXVAL, ANS)
      IF (ANS .EQ. 0) THEN
         DCHFL = .TRUE.
         CALL OPFAIL
      ELSE
         IF (PERM(ANS) .EQ. TRUANS) THEN
            DCHFL = .FALSE.
         ELSE
            DCHFL = .TRUE.
            CALL FAIL
         ENDIF
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION GL/dchflv                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION DCHFLV (PROMPT, MAXVAL, TRUANS)

C  DCHFLV operates just like DCHFL, except that the response is
C  tested directly against TRUANS.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    MAXVAL      : highest valid response.
C    TRUANS      : expected value from operator.

      INTEGER     TRUANS, MAXVAL, ANS

      CHARACTER   PROMPT*(*)

      CALL DCHOIC (PROMPT, 0,MAXVAL, ANS)
      DCHFLV = ANS .NE. TRUANS
      IF (ANS .EQ. 0) THEN
         CALL OPFAIL
      ELSEIF (DCHFLV) THEN
         CALL FAIL
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/dchoic                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DCHOIC (PROMPT, LOLIM, HILIM, ANS)

C  DCHOIC is used to get an integer response from the operator.
C
C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    LOLIM,HILIM : low, high limit (inclusive) for answer.
C  Output parameters:
C    ANS         : valid answer from operator.

      INTEGER     LOLIM,HILIM, ANS, IERR

      CHARACTER   PROMPT*(*), RESP*100, MSG*100

110   CONTINUE
C  display prompt and get response string
      CALL DLINE (PROMPT, RESP)
      IF (RESP .EQ. ' ') THEN
         MSG = 'Response must be non-blank.'
      ELSE
         CALL PRSINT (RESP, ANS,IERR)
         IF (IERR .EQ. 0) THEN
            IF (ANS.GE.LOLIM .AND. ANS.LE.HILIM) THEN
               MSG = 'OK'
            ELSE
               MSG = 'Response out of range.'
            ENDIF
         ELSE
            MSG = 'Response not an integer.'
         ENDIF
      ENDIF

      IF (MSG .EQ. 'OK') THEN
C        OK - do nothing
      ELSE
C  show error message in dialogue area and pause
         CALL OPMSGW (MSG)
         GOTO 110
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/dlstpf                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DLSTPF (PROMPT, EXPSIZ, EXPLST, SLSW)

C  DLSTPF gets an integer list response from the operator, and
C  issues pass/fail as a result of comparing the operator response
C  to the expected list. A list with one element = 0 indicates "fail
C  - cannot answer" and triggers an operator comment.

C  Input parameters:
C    PROMPT : prompt to be sent to operator.
C    EXPSIZ : expected size of list
C    EXPLST : expected contents of list
C    SLSW   : S/L switch to indicate comparison by set-equality
C             (unordered) of list-equality (ordered)

      INTEGER     EXPSIZ, EXPLST(*), ANSSIZ, ANSLST(100)

      CHARACTER   PROMPT*(*), SLSW*1

      LOGICAL     IAREQL, SETEQ

      CALL DILIST (PROMPT, ANSSIZ, ANSLST)
      IF (ANSSIZ.EQ.1 .AND. ANSLST(1).EQ.0) THEN
         CALL OPFAIL
      ELSE
         IF (SLSW .EQ. 'L') THEN
            CALL IFPF (IAREQL(ANSSIZ,ANSLST, EXPSIZ,EXPLST))
         ELSEIF (SLSW .EQ. 'S') THEN
            CALL IFPF (ANSSIZ.EQ.EXPSIZ .AND.
     1                 SETEQ(ANSSIZ, ANSLST, EXPLST))
         ELSE
            CALL UNMSG ('DLSTPF called with SLSW = ' // SLSW // '.')
         ENDIF
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/dilist                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DILIST (PROMPT, ANSSIZ, ANSLST)

C  DILIST is used to get an integer-list response from the operator.
C
C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C  Output parameters:
C    ANSSIZ      : size of list from operator.
C    ANSLST      : contents of list from operator

      CHARACTER   PROMPT*(*), RESP*100, MSG*100

      INTEGER     IERR, ANSSIZ, ANSLST(*)

110   CONTINUE
C  display prompt and get response string
      CALL DLINE (PROMPT, RESP)
      IF (RESP .EQ. ' ') THEN
         MSG = 'Response must be non-blank.'
      ELSEIF (RESP .EQ. 'N' .OR. RESP .EQ. 'n') THEN
C  null list
         ANSSIZ = 0   
         MSG = 'OK'
      ELSE
         CALL INIARI (RESP, ANSLST, ANSSIZ, IERR)
         IF (IERR .EQ. 0) THEN
            MSG = 'OK'
         ELSE
            MSG = 'Invalid list.'
         ENDIF
      ENDIF

      IF (MSG .EQ. 'OK') THEN
C        OK - do nothing
      ELSE
C  show error message in dialogue area and pause
         CALL OPMSGW (MSG)
         GOTO 110
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/drlval                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DRLVAL (PROMPT, ANS)

C  DRLVAL is used to get a real-number response from the operator.
C
C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C  Output parameters:
C    ANS         : valid answer from operator.

      INTEGER     IERR

      REAL        ANS

      CHARACTER   PROMPT*(*), RESP*100, MSG*100

110   CONTINUE
C  display prompt and get response string
      CALL DLINE (PROMPT, RESP)
      IF (RESP .EQ. ' ') THEN
         MSG = 'Response must be non-blank.'
      ELSE
         CALL PRSRL (RESP, ANS,IERR)
         IF (IERR .EQ. 0) THEN
            MSG = 'OK'
         ELSE
            MSG = 'Response not a real number.'
         ENDIF
      ENDIF

      IF (MSG .EQ. 'OK') THEN
C        OK - do nothing
      ELSE
C  show error message in dialogue area and pause
         CALL OPMSGW (MSG)
         GOTO 110
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/dline                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DLINE (PROMPT, RESP)

C  DLINE issues a prompt to the operator and gets a single line
C  character string response.  If the operator responds with
C  the escape character "@", DLINE allows entry of a non-committal
C  operator comment (neither pass nor fail), to be sent out as
C  an OP message, and then re-issues the original prompt.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C  Output parameters:
C    RESP        : answer from operator.

      CHARACTER   PROMPT*(*), RESP*(*)

100   CONTINUE
      CALL IACMSG (PROMPT)
      CALL IACANS (RESP)

C  allow operator-requested comment.
      IF (RESP .EQ. '@') THEN
         CALL OPCOMT
         GOTO 100
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/opfail                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPFAIL

C  OPFAIL allows the operator to enter a character string as a
C  comment, by using OPCO, and then issues a failure.

      CALL OPCOFL
      CALL FAIL

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/opcofl                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPCOFL

C  OPCOFL allows the operator to enter a character string as a
C  comment, by using OPCO.  The comment is made in anticipation
C  of failure of the current test case.

      CALL OPCO ('on failure')
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/opcomt                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPCOMT

C  OPCOMT allows the operator to enter a character string as a
C  comment, by using OPCO.  No presumption is made about passing
C  or failing.

      CALL OPCO (' ')
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/opco                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPCO (TOPIC)

C  OPCO allows the operator to enter a character string as a
C  comment, which is then generated as an OP-type message.
C  If there is a current topical heading, it is prefixed to
C  the string.

      COMMON /OPCOMM/ OPHEAD
      CHARACTER  OPHEAD*300

      INTEGER    ITRIM, OPLEN
      CHARACTER  TOPIC*(*), PROMPT*300, RESP*900

      OPLEN = ITRIM(OPHEAD) + 1

      IF (TOPIC .EQ. ' ') THEN
         PROMPT = OPHEAD(:OPLEN) // 'Operator comment?'
      ELSE
         PROMPT = OPHEAD(:OPLEN) // 'Operator comment ' // TOPIC // '?'
      ENDIF

      CALL DSTRNG (PROMPT, RESP)
      IF (RESP .NE. ' ') THEN
         CALL BRDMSG ('OP: ' // OPHEAD(:OPLEN) // RESP)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/dstrng                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DSTRNG (PROMPT, RESP)

C  DSTRNG is used to get possibly multi-line character string
C  response from the operator.  Operator response is terminated
C  by a single "." on a line.  This termination line is not
C  included in the response.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C  Output parameters:
C    RESP        : answer from operator.

      INTEGER     ITRIM, NXTPOS

      CHARACTER   PROMPT*(*), RESP*(*), LINEIN*200

C  display prompt
      CALL IACMSG (PROMPT)
      NXTPOS = 1
      RESP = ' '

100   CONTINUE
C  get response string
      CALL IACANS (LINEIN)
      IF (LINEIN .EQ. '.') GOTO 200
C  append last line to non-blank stuff in RESP
      RESP (NXTPOS:) = LINEIN
      NXTPOS = ITRIM(RESP) + 2
C  check if at or near overflow ...
      IF (NXTPOS+5 .LT. LEN(RESP)) GOTO 100

200   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/opmsgw                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE OPMSGW (MSG)

C  OPMSGW sends a character string (MSG) to the operator in
C  accordance with DOUTYP.  It then waits for a response, to ensure
C  that the message has been read.

      INTEGER    ITRIM
      CHARACTER  MSG*(*), PMSG*999, RESP*80

      PMSG = MSG(1:ITRIM(MSG)) // '  Enter anything to continue.'
      CALL DLINE (PMSG, RESP)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/iacmsg                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE IACMSG (MSGTXT)

C  IACMSG sends a character string (MSGTXT) to the operator in
C  accordance with DOUTYP.  For DOUTYP 3 IACMSG formats MSGTXT
C  into structure #DSTRID. For DOUTYP 1 OR 2 IACMSG simply breaks up
C  MSGTXT into the specified line-length and sends out each line
C  via PRINT or MESSAGE, respectively.

C  If the MSGTXT looks like a topical heading for a test case (caps
C  followed by ":"), then the heading is saved in a common area
C  shared with OPCO, so the operator's comments are tagged.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      COMMON /OPCOMM/ OPHEAD
      CHARACTER  OPHEAD*300

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      INTEGER    LINMAX
      PARAMETER (LINMAX = 90)

      INTEGER    ITRIM, EDITMO, OPSTAT, OPID, ELPTR
      INTEGER    ERR, NUMLIN, LINPOS(LINMAX), OUTL, MA,MB, ILINE
      INTEGER    COLLOC, IX, TXFNT

      REAL       XA(10),YA(10), EXTX(2),EXTY(2),COPX,COPY
      REAL       Z,U, TM3(3,3), YPOS,XMAX, XSIZE,YSIZE, SCF, LOGHW
      REAL       CHWRAT, RDUM, CHSP

      PARAMETER (Z=0.0, U=1.0)

      CHARACTER  MSGTXT*(*), MSG*300

C  put MSGTXT in OPHEAD if it's a topical header for a test case.
C  look for colon location
      COLLOC = INDEX(MSGTXT, ':')
      IF (COLLOC .LE. 0) GOTO 100

      DO 50 IX = 1, MIN(10, LEN(MSGTXT))
C  treat as non-header if first 10 chars not all caps or digits or spaces
         IF (INDEX('ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789', 
     1             MSGTXT(IX:IX)) .LE. 0) GOTO 100
50    CONTINUE
      OPHEAD = MSGTXT(:COLLOC)

100   CONTINUE

      IF (DOUTYP.EQ.1 .OR. DOUTYP.EQ.2) THEN
C  if direct output, skip initialization of structure (DSTRID)
C  for dialogue.
         GOTO 110
      ELSEIF (DOUTYP.EQ.3) THEN
C        OK - do nothing
      ELSE
         WRITE (MSG, '(A,I5)') 'Invalid output type in IACMSG: ', DINTYP
         CALL UNMSG (MSG)
      ENDIF

C  save edit state, open-structure state
      CALL PQEDM  (ERRIND, EDITMO)
      CALL CHKINQ ('pqedm', ERRIND)
      CALL PQOPST (ERRIND, OPSTAT, OPID)
      CALL CHKINQ ('pqopst', ERRIND)
C  If a structure is open, save element-pointer and close structure
      IF (OPSTAT .EQ. POPNST) THEN
         IF (OPID .EQ. DSTRID) THEN
            CALL UNMSG ('IACMSG found dialogue structure open.')
         ENDIF
         CALL PQEP (ERRIND, ELPTR)
         CALL CHKINQ ('pqep', ERRIND)
         CALL PCLST
      ENDIF

      CALL PSEDM (PINSRT)
      CALL POPST (DSTRID)
      CALL PEMST (DSTRID)
      CALL PSVWI (2)

C  set all aspects to individual
      CALL SETASF (PINDIV)

C  outline dialogue area
      CALL PSPLCI (DTXCI)
      CALL SETRVS ('0,0,1,1,0', XA, OUTL)
      CALL SETRVS ('0,0,0,0,0', YA, OUTL)
      YA(2) = DYXRAT
      YA(3) = DYXRAT
      CALL PPL (5,XA,YA)
C  mark start of text elements in structure
      CALL PLB (101)

CUSERMOD  text attributes for dialogue
      TXFNT = 1
      CHSP  = 0.1
      CALL PSTXFN (TXFNT)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (U)
      CALL PSCHSP (CHSP)
      CALL PSTXCI (DTXCI)
      CALL PSCHH  (U)
      CALL PSCHUP (Z,U)
      CALL PSTXP  (PRIGHT)
      CALL PSTXAL (PALEFT,PATOP)

CUSERMOD  Control character height/width ratio for dialogue here: if
CUSERMOD  characters too skinny, decrease, if too fat, increase.
      CHWRAT = 2.5
C  calculate line-size, for a paragraph based on desired
C  character body height/width ratio
      CALL FITPAR (MSGTXT, CHWRAT, DYXRAT, DTCLIM)
      YPOS = 0.0
      XMAX = 0.0

110   CONTINUE

C  break up MSGTXT into DTCLIM-size chunks - get array of
C  line starting positions
      CALL LINBRK (MSGTXT, DTCLIM, ERR, NUMLIN, LINPOS)
      IF (NUMLIN .GE. LINMAX) THEN
         CALL UNMSG ('Too many lines computed by IACMSG.')
      ENDIF

C  send each line to screen or print or message, as specified
      DO 200 ILINE = 1,NUMLIN
C  MA and MB point to substring within MSGTXT to be output
         MA = LINPOS(ILINE)
         MB = ITRIM(MSGTXT(1:LINPOS(ILINE+1) - 1))
         IF (DOUTYP .EQ. 1) THEN
            PRINT *, MSGTXT(MA:MB)
         ELSEIF (DOUTYP .EQ. 2) THEN
            CALL PMSG (WKID, MSGTXT(MA:MB))
         ELSE
C  write MSGTXT into prompt area - WC = x:0-1, y:0-DYXRAT
            CALL PTX (0.0, YPOS, MSGTXT(MA:MB))
C  keep track of widest line and vertical position
            CALL PQTXX (SPECWT, TXFNT,U,CHSP,U,PRIGHT,PALEFT,PATOP,
     1                  MSGTXT(MA:MB), ERRIND, EXTX,EXTY,COPX,COPY)
            CALL CHKINQ ('pqtxx', ERRIND)
            XSIZE = ABS(EXTX(1)-EXTX(2))
            YSIZE = ABS(EXTY(1)-EXTY(2))
            XMAX = MAX(XMAX, XSIZE)
CUSERMOD  Control separation of dialogue lines here - if too crowded,
CUSERMOD  increase coefficient of YSIZE, if too sparse, decrease.
            YPOS = YPOS - 1.02*YSIZE
         ENDIF
200   CONTINUE

      IF (SCRMOD .EQ. 3) THEN
C  make sure dialogue is posted
         CALL PSTCTL (2)
      ELSEIF (SCRMOD .EQ. 0) THEN
C  post picture only
         CALL PSTCTL (1)
      ELSE
C  split screen - post dialogue and picture
         CALL PSTCTL (3)
      ENDIF

C  if direct output, we're done
      IF (DOUTYP .NE. 3) RETURN

C  Text written into rectangle with x-bounds = 0:xmax,
C  y-bounds = ypos:0. Must transform to fit into 0:1, 0:dyxrat
C  rectangle, with scaling adjusted for CHWRAT = character
C  height/width ratio.

      CALL SCAPAR (DTCLIM,CHWRAT,DYXRAT,NUMLIN,LINPOS, RDUM,LOGHW)
      SCF = 0.94 * MIN(1.0, DYXRAT/LOGHW)

      CALL PBLTM (Z,Z, .03,DYXRAT, Z, SCF/XMAX,-SCF*LOGHW/YPOS,
     1            ERRIND, TM3)
      CALL CHKINQ ('pbltm', ERRIND)
C  insert transformation just before text elements
      CALL PSEP   (1)
      CALL PSEPLB (101)
      CALL PSLMT  (TM3, PCREPL)
      CALL PCLST

C  restore edit state, open-structure state
      CALL PSEDM (EDITMO)
      IF (OPSTAT .EQ. POPNST) THEN
         CALL POPST (OPID)
         CALL PSEP  (ELPTR)
      ENDIF

      END
            
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/iacans                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE IACANS (RESP)

C  IACANS gets a single-line character string response (RESP) from
C  the operator in accordance with DINTYP.  For DINTYP 1, IACANS
C  simply issues a Fortran read statement. For DINTYP 2, IACANS
C  invokes the PHIGS <request string> function.  If the response
C  is non-blank, leading blanks are deleted.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)

C input device status
      INTEGER    PNONE,     POK,     PNPICK,     PNCHOI
      PARAMETER (PNONE = 0, POK = 1, PNPICK = 2, PNCHOI = 3)

      INTEGER   RQSTAT,LOSTR,LEADNB

      CHARACTER RESP*(*), MSG*100

100   CONTINUE
C  force screen update
      CALL PUWK (WKID, PPERFO)
      RESP = ' '
C  get response
      IF (DINTYP .EQ. 1) THEN
         READ (*,'(A)') RESP
      ELSEIF (DINTYP .EQ. 2) THEN
         CALL PRQST (WKID, DSTDNR, RQSTAT,LOSTR,RESP)
         IF (RQSTAT .NE. POK) THEN
            WRITE (MSG, '(A,I5)') 'Non-OK status from ' //
     1                            '<request string>: ', RQSTAT
            CALL UNMSG (MSG)
         ENDIF

C  ensure trailing blanks
         IF (LOSTR .LT. LEN(RESP)) RESP(LOSTR+1:) = ' '

      ELSE
         WRITE (MSG, '(A,I5)') 'Invalid input type in IACANS: ', DINTYP
         CALL UNMSG (MSG)
      ENDIF

C  delete leading blanks
      IF (RESP .NE. ' ') RESP = RESP(LEADNB(RESP):)

C  check for toggling
      IF (SCRMOD.EQ.3 .AND. (RESP.EQ.'T' .OR. RESP.EQ.'t')) THEN
         CALL PSTCTL (4)
         GOTO 100
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/setasf                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETASF (FLAG)

C  SETASF sets all ASF flags to the same value, either individual or
C  bundled.

C aspect identifier
      INTEGER    PLN,      PEDCI
      PARAMETER (PLN  = 0, PEDCI=17)

      INTEGER   FLAG, ASPECT

      DO 50 ASPECT = PLN, PEDCI
         CALL PSIASF (ASPECT, FLAG)
50    CONTINUE

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/pstctl                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PSTCTL (CTL)

C  PSTCTL controls the posting of structures.

C  CTL function
C  --- --------
C   0  unpost both picture and dialogue structure
C   1  post picture only
C   2  post dialogue only
C   3  post both
C   4  switch picture/dialogue posting; dialogue if neither or both

C  POSTAT keeps track of current posting status:
C  POSTAT  status
C  ------  ------
C     0    neither posted
C     1    picture posted
C     2    dialogue posted
C     3    both posted

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

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      INTEGER    CTL, POSTAT

C  action table: what to do based on POSTAT and CTL
      CHARACTER  ACT(0:3, 0:4)*4, DOACT*4

      DATA       POSTAT / 0 /
C                POSTAT: 0         1        2        3
      DATA       ACT /  'n',      'Up',    'Ud',    'UpUd',
     1                  'Pp',     'n',     'UdPp',  'Ud',
     1                  'Pd',     'UpPd',  'n',     'Up',
     1                  'PpPd',   'Pd',    'Pp',    'n',
     1                  'Pd',     'UpPd',  'UdPp',  'Up' /

      DOACT = ACT(POSTAT, CTL)
      IF (DOACT .EQ. 'n') RETURN
      IF (INDEX(DOACT, 'Up') .GT. 0) CALL PUPOST (WKID, PSTRID)
      IF (INDEX(DOACT, 'Ud') .GT. 0) CALL PUPOST (WKID, DSTRID)
      IF (INDEX(DOACT, 'Pp') .GT. 0) CALL  PPOST (WKID, PSTRID, 0.0)
      IF (INDEX(DOACT, 'Pd') .GT. 0) CALL  PPOST (WKID, DSTRID, 1.0)

      IF (CTL .EQ. 4) THEN
         IF (POSTAT .EQ. 2) THEN
            POSTAT = 1
         ELSE
            POSTAT = 2
         ENDIF
      ELSE
         POSTAT = CTL
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/fitpar                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE FITPAR (MSGTXT, CHWRAT, PHWRAT, LINSIZ)

C  FITPAR calculates a reasonably good line size (number of characters)
C  for fitting MSGTXT into a rectangular area.

C  Input parameters:
C    MSGTXT : Text to be fit
C    CHWRAT : Desired height/width ratio of each character
C    PHWRAT : Height/width ratio of area to hold paragraph
C  Output parameters:
C    LINSIZ : Number of characters per line

C  let:
C    #chars = #lines * chars-per-line
C    char-height = phwrat/#lines
C    char-width  = 1/chars-per-line
C    char-height/char-width = CHWRAT
C  then
C    chars-per-line = sqrt(CHWRAT*#chars / phwrat)

      INTEGER    LINSIZ, LENMSG, ITRIM, MINLIN, ERR, NUMLIN,LINPOS(300)
      INTEGER    SIZSAV

      REAL       CHWRAT, PHWRAT, CHHT1,CHHT2, LOGHW

      CHARACTER  MSGTXT*(*)

      LENMSG = ITRIM(MSGTXT)
C  3 is fudge factor, because there won't be perfect packing.
      LINSIZ = SQRT(CHWRAT*LENMSG/PHWRAT) + 3
C  15 is minimum tolerable line-length
      MINLIN = 15
      LINSIZ = MAX (MINLIN,LINSIZ)
C  Generate line-breaks for LINSIZ:
      CALL LINBRK (MSGTXT, LINSIZ, ERR, NUMLIN, LINPOS)
C  get resulting character height
      CALL SCAPAR (LINSIZ,CHWRAT,PHWRAT,NUMLIN,LINPOS, CHHT1,LOGHW)

C  alter LINSIZ for attempted better fit
      SIZSAV = LINSIZ
      IF (LOGHW .GT. PHWRAT .AND. NUMLIN .EQ. 2) THEN
C  2-line message is too tall ... force to 1 line
         LINSIZ = LENMSG
      ELSE
C  try to converge on proper height/width ratio for paragraph
         LINSIZ = LINSIZ * LOGHW / PHWRAT
      ENDIF

      LINSIZ = MAX (MINLIN,LINSIZ)
C  Generate line-breaks for 2nd LINSIZ:
      CALL LINBRK (MSGTXT, LINSIZ, ERR, NUMLIN, LINPOS)
C  get 2nd resulting character height
      CALL SCAPAR (LINSIZ,CHWRAT,PHWRAT,NUMLIN,LINPOS, CHHT2,LOGHW)

C  If 2nd attempt generated smaller characters, re-set to 1st,
C  otherwise leave LINSIZ as is.
      IF (CHHT1 .GT. CHHT2) LINSIZ = SIZSAV

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/linbrk                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LINBRK (MSGTXT, DTCLIM, ERR, NUMLIN, LINPOS)

C  LINBRK calculates starting positions within a character string so
C  as to break it up into lines of at most DTCLIM characters. LINBRK
C  tries to break lines only on blanks, and it constructs the
C  longest line possible within the DTCLIM limit.  It returns the
C  number of lines in NUMLIN, and the starting positions within
C  LINPOS.  An "extra" position is calculated after the last line,
C  pointing just beyond the last non-blank, so that the location of
C  the end of the last line is available.  If a single word
C  (contiguous non-blanks) is longer than DTCLIM, it is broken up
C  after DTCLIM characters, and ERR is set to 1.

C  Input parameters:
C    MSGTXT : character string to be broken up
C    DTCLIM : maximum number of characters in each chunk
C  Output parameters:
C    ERR    : error code: 0 if OK, 1 if line overflow
C    NUMLIN : number of logical lines found in MSGTXT
C    LINPOS : array of starting positions of lines within MSGTXT

      INTEGER     NXTPOS, ERR, DTCLIM, NUMLIN, LINPOS(*), LENMSG
      INTEGER     ITRIM, STLIN, LEADNB

      CHARACTER   MSGTXT*(*)

      ERR = 0
      NUMLIN = 0
      IF (MSGTXT .EQ. ' ') RETURN
      LENMSG = ITRIM(MSGTXT)
      NXTPOS = 1

100   CONTINUE
C  seek next non-blank
      STLIN = LEADNB (MSGTXT(NXTPOS:))
C  get absolute position of line-starting non-blank
      STLIN = STLIN + NXTPOS - 1
C  record starting position
      NUMLIN = NUMLIN + 1
      LINPOS(NUMLIN) = STLIN
C  any non-blanks beyond this line?
      IF (LENMSG-STLIN .LT. DTCLIM) THEN
         LINPOS(NUMLIN+1) = LENMSG+1
         RETURN
      ENDIF

      DO 200 NXTPOS = STLIN+DTCLIM, STLIN, -1
         IF (MSGTXT(NXTPOS:NXTPOS) .EQ. ' ') GOTO 100
200   CONTINUE

C  no space within line
      ERR = 1
      NXTPOS = STLIN+DTCLIM
      GOTO 100

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/scapar                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SCAPAR (DTCLIM,CHWRAT,DYXRAT,NUMLIN,LINPOS, CHHT,LOGHW)

C  SCAPAR calculates the needed scaling factor and logical
C  height/width ratio of a paragraph, given a line break-up.

C  Input parameters:
C    DTCLIM : maximum number of characters per line
C    CHWRAT : desired height/width ratio of each character
C    DYXRAT : height/width ratio of paragraph area
C    NUMLIN : number of logical lines in paragraph
C    LINPOS : array of starting positions of lines within MSGTXT
C  Output parameters:
C    CHHT   : resulting character height
C    LOGHW  : logical height/width ratio of resulting paragraph

      INTEGER   DTCLIM, NUMLIN, LINPOS(*)
      REAL      CHWRAT, DYXRAT, CHHT, LOGHW, LOGWID,LOGHT

      IF (NUMLIN .GT. 1) THEN
         LOGWID = DTCLIM
      ELSE
         LOGWID = LINPOS(2)-1
      ENDIF
      LOGHT = NUMLIN*CHWRAT
      LOGHW = LOGHT / LOGWID

C  1/LOGWID takes effect for a "full" multi-line paragraph.
C  DYXRAT/LOGHT takes effect for a partially-filled single-line paragraph.
      CHHT  = MIN (1/LOGWID, DYXRAT/LOGHT)

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION GL/ylocel                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION YLOCEL (YTH)

C  YLOCEL returns the appropriate y-coordinate in WC for element
C  number YTH, when comparing pairs of elements for traversal
C  saving and restoring.

      INTEGER    YTH

      YLOCEL = (15 - YTH) / 15.0

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/rn1shf                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE RN1SHF (SIZ, PERM)

C  Incredibly special-purpose subroutine which returns a permutation in
C  PERM with the constraint that:
C
C     PERM(12) - PERM(11) = PERM(06) - PERM(05)
C
C  so as to force uniform scaling.  This is needed in inheritance tests
C  when displaying primitives with an intrinsic size, such as fill area
C  or text, as opposed to a single segment of a polyline or a single
C  polymarker.

      INTEGER    TMP, IX,IY, SIZ, PERM(*), SWVALS(4)
      INTEGER    LDX,HDX, SWLOC, IARFND, NEEDVL

      DATA       SWVALS / 5,6,11,12 /

      CALL RNPERM (SIZ, PERM)

C  put locations of 5,6,11,12 in ascending order
      DO 200 IX = 1,3
      DO 300 IY = IX+1,4
         LDX = SWVALS(IX)
         HDX = SWVALS(IY)
         IF (PERM(LDX) .GT. PERM(HDX)) THEN
            TMP = PERM(LDX)
            PERM(LDX) = PERM(HDX)
            PERM(HDX) = TMP
         ENDIF
300   CONTINUE
200   CONTINUE

C  switch values for shortest interval
      IF (PERM(6)-PERM(5) .LT. PERM(12)-PERM(11)) THEN
C  switch contents of PERM(11) with needed value
         NEEDVL = PERM(12) + PERM(5) - PERM(6)
         SWLOC = 11
      ELSE
C  switch contents of PERM(5) with needed value
         NEEDVL = PERM(11) + PERM(6) - PERM(12)
         SWLOC = 5
      ENDIF

      PERM(IARFND(NEEDVL,SIZ,PERM)) = PERM(SWLOC)
      PERM(SWLOC) = NEEDVL

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/rnperm                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE RNPERM (SIZE, PERM)

C  RNPERM returns a random permutation of integers 1-SIZE in PERM.
C  For example, if SIZE is specified as 4, PERM might = [2,3,1,4].

      INTEGER   SIZE, PERM(SIZE), IX, RANPOS, SWAP, RNDINT

      DO 100 IX = 1,SIZE
         PERM(IX) = IX
100   CONTINUE

      DO 200 IX = SIZE,2, -1
         RANPOS = RNDINT (1,IX)
         SWAP = PERM(IX)
         PERM(IX) = PERM(RANPOS)
         PERM(RANPOS) = SWAP
200   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/rnset                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE RNSET  (SIZE, MAXMEM, SET)

C RNSET returns a random set of SIZE distinct integers, chosen from
C the universe of 1-MAXMEM, returned in SET.  For example, if SIZE is
C specified as 4, and MAXMEM as 7, SET might = [2,5,7,4].

      INTEGER   SIZE, MAXMEM, SET (SIZE)

      CALL RNBSET (SIZE, 1, MAXMEM, SET)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE GL/rnbset                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE RNBSET  (SIZE, LO, HI, SET)

C  RNBSET returns a random set of SIZE distinct integers, chosen from
C  the universe of LO-HI (inclusive), returned in SET.  For example,
C  if SIZE is specified as 4, LO=3 and HI=10, SET might = [9,5,7,4].

      INTEGER   SIZE, LO,HI, SET (SIZE), IX, IY, RNDINT

      IF (SIZE .GT. HI-LO+1) THEN
         CALL UNMSG ('In RNBSET, size of set exceeds universe.')
      ENDIF

      DO 100 IX = 1,SIZE
110      CONTINUE
         SET (IX) = RNDINT (LO,HI)
         DO 200 IY = 1, IX-1
            IF (SET(IX) .EQ. SET(IY)) GOTO 110
200      CONTINUE
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION GL/rndint                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      INTEGER FUNCTION RNDINT (LO,HI)

C  RNDINT returns a random integer value between LO and HI,
C  inclusive.

      INTEGER LO,HI
      REAL    RND01

      RNDINT = INT (RND01() * (1+HI-LO) + LO)

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION GL/rndrl                             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION RNDRL (LO, HI)

C  RNDRL returns a random real number, X, uniformly distributed,
C  such that LO .LE. X .LT. HI.

      REAL       RND01, LO, HI

      RNDRL = RND01()*(HI-LO) + LO

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION GL/rnd01                             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION RND01 ()

C  RND01 returns a random real number, X, uniformly distributed,
C  such that 0 .LE. X .LT. 1.

C  This is a very low-grade random number generator; it should be
C  portable except for the call to SECNDS.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /RANCTL/ RLSEED
      REAL            RLSEED

      SAVE

      INTEGER  IX

      REAL     SECNDS
      DOUBLE PRECISION  X, FACTOR, ADDEND
      LOGICAL  FIRST

      DATA     FIRST  / .TRUE. /
      DATA     FACTOR / .53736255218 /
      DATA     ADDEND / .63535248281 /

      IF (FIRST) THEN
         FIRST = .FALSE.
         IF (RLSEED .LT. 0.1 .OR. RLSEED .GT. 0.9) THEN

C *********************************************************
C
CUSERMOD  put in a time function to initialize X (true randomization)
C
C *********************************************************

            X = SECNDS(0.0)

C *********************************************************
C
CUSERMOD  End of customization
C
C *********************************************************

         ELSE
C  pseudo-random sequence - seed taken from configuration file
            X = RLSEED
         ENDIF
      ENDIF

      X  = 97.8272 * (X * FACTOR + ADDEND)
      IX = INT(X)
      X  = X - IX
      RND01 = X 

      END
