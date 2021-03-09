C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.03.03/isspf                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ISSPF (DIMENS, SRPX,SRPY,SRPZ, SDIST, EXPATH)

C  This subroutine invokes the specified spatial search routine and
C  issues pass or fail, depending on its agreement with the expected
C  result.  Always: structure #101 is searched, search ceiling is 1,
C  modelling clip off, filter lists empty.

C  Input parameters:
C    DIMENS         : dimension of search: 2 or 3
C    SRPX,SRPY,SRPZ : search reference point (SRPZ ignored if DIMENS=2)
C    SDIST          : search distance
C    EXPATH         : expected found path

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      REAL       SRPX,SRPY,SRPZ, SDIST

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 100)

      INTEGER    DIMENS, IDUM(2), FPATH(2,IPTHSZ), ERRIND, FPTHSZ
      INTEGER    SPATH(2,1), IEXPTH(2,IPTHSZ), IEXLEN

      LOGICAL    IAREQL

      CHARACTER  EXPATH*(*)

      DATA SPATH / 101,0 /

      IF (DIMENS .EQ. 2) THEN
         CALL PISS  (SRPX,SRPY,      SDIST, 1, SPATH, PNCLIP, 1,
     1               0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2               IPTHSZ, ERRIND, FPTHSZ, FPATH)
      ELSEIF (DIMENS .EQ. 3) THEN
         CALL PISS3 (SRPX,SRPY,SRPZ, SDIST, 1, SPATH, PNCLIP, 1,
     1               0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2               IPTHSZ, ERRIND, FPTHSZ, FPATH)
      ELSE
         CALL UNMSG ('Illegal dimension passed to ISSPF.')
      ENDIF

      CALL SETVS (EXPATH, IEXPTH, IEXLEN)

      CALL IFPF (ERRIND .EQ. 0 .AND.
     1           IAREQL (2*FPTHSZ, FPATH, IEXLEN, IEXPTH))

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.03.03/issgeo                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ISSGEO (STPTH, EXIX, EXXLO,EXYLO,EXXHI,EXYHI, EXPTH)

C  This subroutine tests whether ISS successfully detects the
C  corners of a text extent rectangle.

C  Input parameters:
C    STPTH    : starting path for ISS
C    EXIX, EXXLO,EXYLO,EXXHI,EXYHI
C             : expected corner values for rectangle
C    EXPTH    : expected found path for ISS

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 30)

      INTEGER    EXLEN,  EXPATH(IPTHSZ), EXIX, IDUM(2)
      INTEGER    SPSIZ,  SPATH(2,IPTHSZ)
      INTEGER    FPTHSZ, FPATH(2,IPTHSZ), ERRIND

      REAL       EXXLO(0:10),EXYLO(0:10),EXXHI(0:10),EXYHI(0:10)
      REAL       SRATIO,SDIST, INCRVX,INCRVY, SRPX,SRPY, VECL

      LOGICAL    IAREQL

      CHARACTER  STPTH*(*), EXPTH*(*)

C  sratio = search ratio = 0.1
      SRATIO = 0.1
C  diagv = diagonal vector = vector from lower-left expected corner
C    to upper-right
C  incrv = incremental vector = sratio*diagv
      INCRVX = (EXXHI(EXIX) - EXXLO(EXIX)) * SRATIO
      INCRVY = (EXYHI(EXIX) - EXYLO(EXIX)) * SRATIO

C  sdist = search distance  = length of incrv
      SDIST = VECL (INCRVX,INCRVY,0.0)

C  srp = upper-right corner + incrv
      SRPX = EXXHI(EXIX) + INCRVX
      SRPY = EXYHI(EXIX) + INCRVY
C  starting path
      CALL SETVS (STPTH, SPATH, SPSIZ)
      SPSIZ = SPSIZ/2
C  expected path
      CALL SETVS (EXPTH, EXPATH, EXLEN)

C  ISS: with stpath, srp, try search distance first just below and
C     then just above sdist.
C  pass/fail depending on (text first not found with expected path,
C     then found with expected path)

      CALL PISS (SRPX,SRPY, 0.98*SDIST, SPSIZ,SPATH, PNCLIP, 1,
     1           0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2           IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND.
     1    (.NOT. IAREQL (2*FPTHSZ, FPATH, EXLEN, EXPATH))) THEN
C OK so far
      ELSE
         CALL FAIL
         CALL INMSG ('ISS erroneously found expected path, even ' //
     1               'though search distance was insufficient.')
         RETURN
      ENDIF

      CALL PISS (SRPX,SRPY, 1.02*SDIST, SPSIZ,SPATH, PNCLIP, 1,
     1           0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2           IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND.
     1    IAREQL (2*FPTHSZ, FPATH, EXLEN, EXPATH)) THEN
         CALL PASS
      ELSE
         CALL FAIL
         CALL INMSG ('ISS did not find expected path, even ' //
     1               'though search distance was sufficient.')
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.03.03/tx2dex                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TX2DEX (SPECWT, CHUPX,CHUPY, CHHT, TXPATH, TXALH,TXALV,
     1                   TPOSX,TPOSY,STR, EXIX, EXXLO,EXYLO,EXXHI,EXYHI)

C  This subroutine computes the expected lower-left and upper-right
C  corner of a text extent rectangle, including the effect of text
C  position and character-up vector, which are not taken into
C  account by <inquire text extent>.

      INTEGER    SPECWT, TXPATH, TXALH,TXALV, EXIX, ERRIND

      REAL       TPOSX,TPOSY, CHUPX,CHUPY, CHHT, RECX(2),RECY(2)
      REAL       EXXLO(0:10),EXYLO(0:10),EXXHI(0:10),EXYHI(0:10)
      REAL       PI, ROTANG, XFRM(3,3), RDUM1,RDUM2, SATAN2
      PARAMETER (PI = 3.14159265)

      CHARACTER  STR*(*)

C  <inquire text extent> with
C    workstation type           = primary workstation type
C      (ignored because font #1 is workstation-independent)
C    text font                  = 1
C    character expansion factor = 1.0
C    character spacing          = 0.0
C      (three above set as assumed by spatial search, see SR15)
C    character height           = chht
C    text path                  = txpath
C    text alignment             = txal
C    character string           = str
C      to determine:
C    recxlo,recxhi,recylo,recyhi = text extent rectangle
C      in TLC, with assumed text position = 0,0 character up vector
C      = (0,1), and text precision = STROKE
      CALL PQTXX (SPECWT, 1,1.0,0.0, CHHT, TXPATH, TXALH,TXALV, STR,
     1            ERRIND, RECX,RECY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)

C  rotang = rotation angle for character up vector
      ROTANG = SATAN2(CHUPY, CHUPX) - PI/2

C  xfrm = 2D transform for rotation by rotang and shift by tpos
      CALL EBLTM (0.0,0.0, TPOSX,TPOSY, ROTANG, 1.0,1.0, XFRM)
C  Get lower-left and upper-right corner:
C  transform recxlo,recylo, using xfrm to exxlo,exylo
      CALL ETP (RECX(1),RECY(1), XFRM, EXXLO(EXIX),EXYLO(EXIX))
C  transform recxhi,recyhi, using xfrm to exxhi,exyhi
      CALL ETP (RECX(2),RECY(2), XFRM, EXXHI(EXIX),EXYHI(EXIX))

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.03.03/fltran                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE FLTRAN (A,B,C, MAT)

C  Given a set of attitude numbers for a plane, FLTRAN returns a
C  4 X 4 transformation matrix which rotates the plane so as to be
C  parallel to the z=0 plane.  This is useful for visualizing a
C  planar 3D primitive.

      REAL     A,B,C, MAT(4,4), ZZ,UU, VECL, SATAN2

      ZZ = 0.0
      UU = 1.0

      CALL EBLTM3 (ZZ,ZZ,ZZ, ZZ,ZZ,ZZ,
     1     -SATAN2(-B,C), -ASIN(A/VECL(A,B,C)),ZZ, UU,UU,UU, MAT)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.03.03/issflt                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.03.03/setfil                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETFIL (FILT, FLN, FLISX,FLIS, FLESX,FLES)

C  SETFIL translates the character version of a filter list into the
C  appropriate integer arrays.

      INTEGER     FLN, FLISX(*),FLIS(*), FLESX(*),FLES(*)

C  Declaration of COLLEN and WORK allows for a filter list with 55
C  filters, each with an inclusion set and exclusion set of up to 20
C  members.  Generated test case from P07 uses at most 50 filters.
      INTEGER     NUMCOL, COLLEN(110), WORK(20,110)
      INTEGER     ITOT,ETOT, FLTDX,ELDX, ICOL,ECOL

      CHARACTER   FILT*(*)

      CALL SET2D (FILT, 20, NUMCOL, COLLEN, WORK)
      FLN = NUMCOL/2
      IF (FLN*2 .NE. NUMCOL) THEN
         CALL UNMSG ('Illegal filter list passed to SETFIL.')
      ENDIF

      ITOT = 0
      ETOT = 0
      DO 100 FLTDX = 1,FLN
         ICOL = 2*FLTDX - 1
         ECOL = 2*FLTDX

C  inclusion set
         DO 200 ELDX = 1,COLLEN(ICOL)
            ITOT = ITOT+1
            FLIS(ITOT) = WORK(ELDX, ICOL)
200      CONTINUE
         FLISX(FLTDX) = ITOT

C  exclusion set
         DO 300 ELDX = 1,COLLEN(ECOL)
            ETOT = ETOT+1
            FLES(ETOT) = WORK(ELDX, ECOL)
300      CONTINUE
         FLESX(FLTDX) = ETOT
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION 02.03.03/zval                        *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION ZVAL (X,Y)

C  ZVAL is just a simple linear function of x and y so as to
C  generate 3D points on the plane: 3x + 4y - z - 7 = 0, so
C    z = f(x,y) = 3x + 4y - 7

      REAL  X,Y

      ZVAL = 3*X + 4*Y - 7

      END
