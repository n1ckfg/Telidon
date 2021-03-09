C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.03/01                        *
C  *    TEST TITLE : Text font in <inquire text extent>    *
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

      INTEGER  FONT, TXP, TXALH, TXALV, SPECWT, FNTX, NUMFNT, IGENX,
     1         IFONT, PREC, WKNUM, WKNO, GENTYP, LAVTYP, SPEC2,
     2         WKID2, CONID2, WTYPE2, MAXCC,CC
      INTEGER  IDUM1, IDUM2, IDUM3, IDUM4, IDUM5

      REAL     CHXP, CHSP, CHH, TXEXRX(2), TXEXRY(2), HW,VW
      REAL     SCHH, SCHW, PWID, BWID, WWID, ABSTOL, RELTOL
      REAL     RDUM1, RDUM2, RDUM3, RDUM4

      CHARACTER  STR*20, CDUM1*1, MSG*300, RESULT*1

      LOGICAL  APPEQ

      CALL INITGL ('04.02.03.03/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

      CALL POPWK (WKID, CONID, WTYPE)
C  Establish specwt = specific primary workstation type
      CALL PQWKC (WKID, ERRIND, IDUM1, SPECWT)
      CALL CHKINQ ('pqwkc',ERRIND)

C  Throughout, use variable names:
C  font:  text font
C  chxp:  character expansion factor
C  chsp:  character spacing
C  chh:   character height
C  txp:   text path
C  txal:  text alignment
C  str:   character string

C  For approximate equality:
C  abstol = absolute tolerance = .02
C  reltol = relative tolerance = .02
      ABSTOL = .02
      RELTOL = .02

      FONT  = 1
      CHXP  = 1.0
      CHSP  = 0.0
      CHH   = 1.0
      TXP   = PRIGHT
      TXALH = PALEFT
      TXALV = PABOTT
      STR   = 'Text extent'
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:11), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)

C  schw = standard character width
      SCHW = ABS(TXEXRX(2) - TXEXRX(1)) / 11.
C  schh = standard character height
      SCHH = ABS(TXEXRY(2) - TXEXRY(1))

      CALL SETMSG ('1 3 4 10 15', 'For a horizontal text path, the '  //
     1             'width of a character string in font 1 should be ' //
     2             'proportional to the number of characters it '     //
     3             'contains.')

C  <Inquire text extent> as before, but with:
C     str   = "WWWW"

      STR   = 'WWWW'
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:4), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)
      WWID = TXEXRX(2)

C  <Inquire text extent> as before, but with:
C     str   = "...", txp = LEFT

      TXP   = PLEFT
      STR   = '...'
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:3), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)
      PWID = TXEXRX(2)

C  <Inquire text extent> as before, but with:
C     str   = "  "

      STR   = '  '
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:2), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)
      BWID = TXEXRX(2)

      CALL IFPF (APPEQ(WWID, 4 * SCHW, ABSTOL, RELTOL) .AND.
     1           APPEQ(PWID, 3 * SCHW, ABSTOL, RELTOL) .AND.
     2           APPEQ(BWID, 2 * SCHW, ABSTOL, RELTOL))

      CALL SETMSG ('1 3 4 10 16', 'For a vertical text path, the ' //
     1             'width of a character string in font 1 should ' //
     2             'always be the width of a single character.')

      STR   = 'WWW'
      TXP   = PDOWN
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:3), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)
      WWID = TXEXRX(2)

      STR   = '....'
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:4), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)
      PWID = TXEXRX(2)

      TXP = PUP
      STR   = '     '
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:5), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)
      BWID = TXEXRX(2)

      CALL IFPF (APPEQ(WWID, SCHW, ABSTOL, RELTOL) .AND.
     1           APPEQ(PWID, SCHW, ABSTOL, RELTOL) .AND.
     2           APPEQ(BWID, SCHW, ABSTOL, RELTOL))

      CALL SETMSG ('1 13', 'All fonts reportedly available in '     //
     1             'stroke precision should be valid for use with ' //
     2             '<inquire text extent>.')

      CHXP  = 1.0
      CHSP  = 0.0
      CHH   = 1.0
      TXP   = PRIGHT
      TXALH = PALEFT
      TXALV = PABOTT
      STR   = 'Text extent'

C  Use <inquire text facilities> using specwt to determine
C     lstfnt = list of fonts available in STROKE precision
      CALL PQTXF (SPECWT, 0, ERRIND, NUMFNT, IDUM1,IDUM2,
     1            IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
      CALL CHKINQ ('pqtxf',ERRIND)

      DO 100 IFONT = 1, NUMFNT
         CALL PQTXF (SPECWT, IFONT, ERRIND, IDUM1, FNTX, PREC,
     1               IDUM3, RDUM1, RDUM2, IDUM4, RDUM3, RDUM4, IDUM5)
         CALL CHKINQ ('pqtxf',ERRIND)
         IF (PREC .NE. PSTRKP) GOTO 100

         CALL PQTXX (SPECWT, FNTX, CHXP, CHSP, CHH, TXP, TXALH,
     1               TXALV, STR(1:11), ERRIND, TXEXRX, TXEXRY,
     2               RDUM1, RDUM2)
         IF (ERRIND .NE. 0)  THEN
            CALL FAIL
            GOTO 500
         END IF
100   CONTINUE
      CALL PASS

C end valid fonts:
500   CONTINUE

      CALL SETMSG ('1 2 3 9 10 15 16', 'For any font, the nominal ' //
     1             'width of any rectangle whose text path is '     //
     1             'vertical should equal the nominal width of '    //
     1             'the widest character in the font.')

C  maximum valid character code
      MAXCC = 255

C  for each stroke fntx in lstfnt
      DO 510 IFONT = 1, NUMFNT
         CALL PQTXF (SPECWT, IFONT, ERRIND, IDUM1, FNTX, PREC,
     1               IDUM3, RDUM1, RDUM2, IDUM4, RDUM3, RDUM4, IDUM5)
         CALL CHKINQ ('pqtxf',ERRIND)
         IF (PREC .NE. PSTRKP) GOTO 510

C  determine vw = width of vertical rectangle
         CALL PQTXX (SPECWT, FNTX, 1.0,0.0,1.0, PDOWN, PALEFT,PABOTT,
     1               '.', ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
         IF (ERRIND .NE. 0) GOTO 510
         VW = TXEXRX(2)

C  all characters so far are narrower
         RESULT = 'L'

C  character code from 0 to maxcc
         DO 520 CC = 0,MAXCC

C  determine hw = width of horizontal rectangle
            CALL PQTXX (SPECWT,FNTX, 1.0,0.0,1.0, PRIGHT, PALEFT,PABOTT,
     1                  CHAR(CC), ERRIND, TXEXRX,TXEXRY, RDUM1,RDUM2)
            IF (ERRIND .NE. 0) GOTO 520
            HW = TXEXRX(2)

            IF (APPEQ(HW, VW, 0.0, RELTOL)) THEN
C  some character of equal width exists
               RESULT = 'E'
            ELSEIF (HW .GT. VW) THEN
               CALL FAIL
               WRITE (MSG, '(A,I5,A,I5,A)') 'Horizontal character ' //
     1           'is too wide: failed on font = ', FNTX,
     2           '; character code = ', CC, '.'
               CALL INMSG (MSG)
               GOTO 550
            ENDIF
C  next_char:
520      CONTINUE

         IF (RESULT .EQ. 'L') THEN
            CALL FAIL
            WRITE (MSG, '(A,I5,A)') 'All horizontal characters ' //
     1        'are too narrow: failed on font = ', FNTX, '.'
            CALL INMSG (MSG)
            GOTO 550
         ENDIF

C  next_font:
510   CONTINUE
      CALL PASS

C  end_other_fonts:
550   CONTINUE

      CALL SETMSG ('1 2 4 5 15 16', 'Font 1 should generate '       //
     1             'character bodies of the same height and width ' //
     2             'for all workstation types.')

C close primary workstation (because may not be able to open
C    several simultaneously)
      CALL PCLWK (WKID)

C  test other specific types:
C  for each accessible secondary output workstation = wkid2
      CALL MULTWS (0, 'od', WKNO, IDUM1, IDUM2, IDUM3, CDUM1)

      FONT   = 1
      CHXP   = 1.0
      CHSP   = 0.0
      CHH    = 1.0
      TXP    = PRIGHT
      TXALH   = PALEFT
      TXALV   = PABOTT
      STR    = '.......'

      DO  600, WKNUM = 1, WKNO
         CALL MULTWS (WKNUM, 'od', IDUM1, WKID2, CONID2, WTYPE2, CDUM1)
         CALL POPWK (WKID2, CONID2, WTYPE2)
         CALL PQWKC (WKID2, ERRIND, IDUM1, SPEC2)
         CALL CHKINQ ('pqwkc', ERRIND)
         CALL PQTXX (SPEC2, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1               STR(1:7), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
         CALL PCLWK (WKID2)
         IF (ERRIND .NE. 0                                    .OR.
     1       (.NOT. APPEQ(TXEXRX(2), 7*SCHW, ABSTOL, RELTOL)) .OR.
     2       (.NOT. APPEQ(TXEXRY(2),   SCHH, ABSTOL, RELTOL))) THEN
            CALL FAIL
            WRITE (MSG,'(A,I6)')
     1            'Failure on specific workstation type #', SPEC2
            CALL INMSG (MSG)
            GOTO 666
         END IF
C  next wkid2
600   CONTINUE

C  test generic types:
C  <inquire list of available workstation types>
C     to determine lavtyp = list of generic workstation types
      CALL PQEWK (0, ERRIND, LAVTYP, IDUM1)
      CALL CHKINQ ('pqewk', ERRIND)

      STR = 'WWWWW'
      TXP = PUP

C  for each gentyp in lavtyp:
      DO 200 IGENX = 1, LAVTYP
         CALL PQEWK (IGENX, ERRIND, IDUM1, GENTYP)
         CALL CHKINQ ('pqewk', ERRIND)

         CALL PQTXX (GENTYP, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1               STR(1:5), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
         IF (ERRIND .EQ. 51) THEN
            GOTO 200
         END IF
         IF (ERRIND .NE. 0                                    .OR.
     1       (.NOT. APPEQ(TXEXRX(2),   SCHW, ABSTOL, RELTOL)) .OR.
     2       (.NOT. APPEQ(TXEXRY(2), 5*SCHH, ABSTOL, RELTOL))) THEN
            CALL FAIL
            WRITE (MSG,'(A,I6)')
     1            'Failure on generic workstation type #', GENTYP
            CALL INMSG (MSG)
            GOTO 666
         ENDIF
200   CONTINUE
      CALL PASS

C  end_other_types:
666   CONTINUE
      CALL ENDIT
      END
