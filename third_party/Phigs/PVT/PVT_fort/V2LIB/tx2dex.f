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
