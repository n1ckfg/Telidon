C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.03/05                        *
C  *    TEST TITLE : Text extent results derived from      *
C  *                 nominal character sizes               *
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

C  number of characters in string
      INTEGER    NCHAR
      PARAMETER (NCHAR=9)

      INTEGER    IX, SPECWT, FONT, TXP, TXALH,TXALV, TCIX(NCHAR), PDIR
      INTEGER    RNDINT, IDUM1

      REAL       MINCW,MAXCW, MINCH,MAXCH, THISCW, RNDRL
      REAL       CHHT, CHXP, CHSP, TXEXRX(2),TXEXRY(2), ACPX, ACPY
      REAL       CHHT2,CHXP2,      T2EXRX(2),T2EXRY(2), A2CPX,A2CPY
      REAL       NCW(3,PRIGHT:PLEFT), CHRINC
      REAL       VTAB(PATOP:PABOTT), HTAB(PALEFT:PARITE)
      REAL       XSIZ,XOFF,XLO,XHI, CCPX, MINX,MAXX,CURX
      REAL       YSIZ,YOFF,YLO,YHI, CCPY
      REAL       NOMCH, NOMVW, NOMRX, ABSTOL,RELTOL, NCWSZ(3)

      CHARACTER  TESTR*9, TCHARS(3)*1, NMTXP(PRIGHT:PDOWN)*5
      CHARACTER  MSG*300, HNAM(PALEFT:PARITE)*6, VNAM(PATOP:PABOTT)*6

      LOGICAL    LOCOK,CCPOK,NEGOK, NOMOK, APPEQ

      DATA TCHARS / 'W', '.', ' ' /
      DATA TCIX   / 1,1,3,3,3,2,2,2,2 /
      DATA HTAB   / 0.0, 0.5, 1.0 /
      DATA HNAM   / 'LEFT', 'CENTRE', 'RIGHT' /
      DATA VNAM   / 'TOP', 'CAP', 'HALF', 'BASE', 'BOTTOM' /
      DATA NMTXP  / 'RIGHT', 'LEFT', 'UP', 'DOWN' /

      CALL INITGL ('04.02.03.03/05')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  Establish specwt = specific primary workstation type
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, IDUM1, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  font = a randomly selected font; non-monospaced if possible
      CALL PRPFNT (SPECWT, FONT)
      WRITE (MSG, '(A,I5,A)') 'Font selected for test: ', FONT, '.'
      CALL INMSG (MSG)

C     mincw,maxcw = minimum,maximum value for ncw for vertical paths
      MINCW =  1.E35
      MAXCW = -1.E35

C     minch,maxch = minimum,maximum value for nch for all paths
      MINCH =  1.E35
      MAXCH = -1.E35

C  for text path = RIGHT,LEFT,UP,DOWN
      DO 100 TXP = PRIGHT,PDOWN
C  <inquire text extent> to determine:
C     ncw,nch = nominal character body width,height for "W", ".", " "
         DO 110 IX = 1,3
            CALL PQTXX (SPECWT, FONT, 1.0,0.0,1.0, TXP, PALEFT,PABOTT,
     2                  TCHARS(IX),ERRIND, TXEXRX,TXEXRY, ACPX,ACPY)
            CALL CHKINQ ('pqtxx',ERRIND)
            THISCW = ABS(TXEXRX(2) -TXEXRX(1))
            IF (TXP.EQ.PLEFT .OR. TXP.EQ.PRIGHT) THEN
C  character widths for horizontal path
               NCW(IX, TXP) = THISCW
            ELSE
C  vertical path
               MINCW = MIN(MINCW, THISCW)
               MAXCW = MAX(MAXCW, THISCW)
            ENDIF
            MINCH = MIN(MINCH, TXEXRY(2))
            MAXCH = MAX(MAXCH, TXEXRY(2))
110      CONTINUE
C  next text path
100   CONTINUE

C  tests for nominal size all OK
      NOMOK = .TRUE.
      CALL SETMSG ('1 2 3 15 16', 'The nominal height of all '    //
     1             'character bodies for a given font should be ' //
     2             'equal, regardless of text path.')

C  tolerances for comparison, based on char-ht = 1
      ABSTOL = .02
      RELTOL = .02

C  pass/fail depending on (minch approx= maxch)
      IF (APPEQ(MINCH,MAXCH, ABSTOL,RELTOL)) THEN
         CALL PASS
         NOMCH = (MINCH+MAXCH) / 2
      ELSE
         CALL FAIL
         NOMOK = .FALSE.
      ENDIF

      CALL SETMSG ('1 2 3 16', 'The nominal rectangle width of all ' //
     1             'vertical text paths for a given font should be ' //
     2             'equal.')

C  pass/fail depending on (mincw approx= maxcw)
      IF (APPEQ(MINCW,MAXCW, ABSTOL,RELTOL)) THEN
         CALL PASS
         NOMVW = (MINCW+MAXCW) / 2
      ELSE
         CALL FAIL
         NOMOK = .FALSE.
      ENDIF

      CALL SETMSG ('1 2 3 15', 'The nominal rectangle width for a '  //
     1             'given font and text string should be equal for ' //
     2             'all horizontal text paths.')

      IF (APPEQ(NCW(1,PLEFT), NCW(1,PRIGHT), ABSTOL,RELTOL) .AND.
     1    APPEQ(NCW(2,PLEFT), NCW(2,PRIGHT), ABSTOL,RELTOL) .AND.
     2    APPEQ(NCW(3,PLEFT), NCW(3,PRIGHT), ABSTOL,RELTOL))  THEN
         CALL PASS
C  nominal widths for "W", ".", " "
         NCWSZ(1) = (NCW(1,PRIGHT) + NCW(1,PLEFT)) / 2
         NCWSZ(2) = (NCW(2,PRIGHT) + NCW(2,PLEFT)) / 2
         NCWSZ(3) = (NCW(3,PRIGHT) + NCW(3,PLEFT)) / 2
      ELSE
         CALL FAIL
         NOMOK = .FALSE.
      ENDIF

      IF (.NOT. NOMOK) THEN
         CALL INMSG ('No more test cases can be executed because ' //
     1               'nominal sizes cannot be determined.')
         GOTO 666
      ENDIF

C  get nominal displacements for vertical text alignments:
C    vtab(TOP,CAP,HALF,BASE,BOTTOM) = vertical offsets from TOP
      DO 200 TXALV = PATOP,PABOTT
         CALL PQTXX (SPECWT, FONT, 1.0,0.0,1.0, PRIGHT, PALEFT,TXALV,
     2               'W', ERRIND, TXEXRX,TXEXRY, ACPX,ACPY)
         CALL CHKINQ ('pqtxx',ERRIND)
         VTAB(TXALV) = TXEXRY(2)
200   CONTINUE

C  test text string, based on TCIX - picks out characters
C  also compute nomimal width for horizontal
      NOMRX = 0.0
      DO 250 IX = 1,NCHAR
         TESTR(IX:IX) = TCHARS(TCIX(IX))
         NOMRX = NOMRX + NCWSZ(TCIX(IX))
250   CONTINUE

C  *** *** *** ***   horizontal text paths   *** *** *** ***

      LOCOK = .TRUE.
      CCPOK = .TRUE.
      NEGOK = .TRUE.

C  nomrx = nominal horizontal rectangle size,
C  based on nomvw,nomch, ncwsz

C  for horizontal text paths
      DO 300 TXP = PRIGHT,PLEFT
C  direction for path
         IF (TXP.EQ.PRIGHT) THEN
            PDIR = 1
         ELSE
            PDIR = -1
         ENDIF

C  for all text alignments (txal)
      DO 400 TXALH = PALEFT,PARITE
      DO 410 TXALV = PATOP,PABOTT

C  chht,chxp,chsp = some random values for character height,
C    expansion factor, and spacing
         CHHT = 10.0 ** RNDRL(-2.0, 2.0)
         CHXP = 10.0 ** RNDRL(-2.0, 2.0)
         CHSP = RNDRL(-3*CHXP, 3*CHXP)

C  calculate expected value for:
C     xlo,xhi,ylo,yhi = position of text extent rectangle
C     ccpx,ccpy       = concatenation point
C  build logical string - this is necessary because character
C  spacing may go backwards for skinny characters, and forward
C  for thick characters
         MINX =  1.E35
         MAXX = -1.E35
C  current position of 0
         CURX = 0.0
         DO 450 IX = 1,NCHAR
C  first edge of current character
            MINX = MIN(MINX, CURX)
            MAXX = MAX(MAXX, CURX)
            CURX = CURX + PDIR*CHXP*NCWSZ(TCIX(IX))
C  second edge of current character
            MINX = MIN(MINX, CURX)
            MAXX = MAX(MAXX, CURX)
            CURX = CURX + PDIR*CHSP
450      CONTINUE
         CCPX = CURX
C  shift based on horizontal alignment
         XSIZ = MAXX-MINX
         XOFF = -HTAB(TXALH)*XSIZ - MINX
         XLO = MINX + XOFF
         XHI = MAXX + XOFF
         CCPX = CCPX + XOFF
C  vertical based only on alignment
         YHI = VTAB(TXALV)
         YLO = YHI - NOMCH
         CCPY = 0.0
C  scale everything by character height
         XLO  = XLO  * CHHT
         XHI  = XHI  * CHHT
         CCPX = CCPX * CHHT
         YHI  = YHI  * CHHT
         YLO  = YLO  * CHHT
         CCPY = CCPY * CHHT

C  determine actual rectangle:
         CALL PQTXX (SPECWT, FONT, CHXP,CHSP,CHHT, TXP, TXALH,TXALV,
     2               TESTR, ERRIND, TXEXRX,TXEXRY, ACPX,ACPY)
         CALL CHKINQ ('pqtxx',ERRIND)

C  set up for negative values
         IX = RNDINT(1,3)
         IF (IX.EQ.1) THEN
            CHHT2 = -CHHT
            CHXP2 = -CHXP
         ELSEIF (IX.EQ.2) THEN
            CHHT2 =  CHHT
            CHXP2 = -CHXP
         ELSE
            CHHT2 = -CHHT
            CHXP2 =  CHXP
         ENDIF

C  determine 2nd actual rectangle, with negative values:
         CALL PQTXX (SPECWT, FONT, CHXP2,CHSP,CHHT2, TXP, TXALH,TXALV,
     2               TESTR, ERRIND, T2EXRX,T2EXRY, A2CPX,A2CPY)
         CALL CHKINQ ('pqtxx',ERRIND)

         IF (TXEXRX(1) .EQ. T2EXRX(1) .AND.
     1       TXEXRX(2) .EQ. T2EXRX(2) .AND.
     1       TXEXRY(1) .EQ. T2EXRY(1) .AND.
     1       TXEXRY(2) .EQ. T2EXRY(2) .AND.
     1       ACPX .EQ. A2CPX .AND. ACPY .EQ. A2CPY ) THEN
C           OK, then ...
         ELSE
            WRITE (MSG, '(A,3F11.4,7A)') 'Inconsistent locations ' //
     1         'with negative character height or expansion, for ' //
     2         'character height, expansion, and spacing = ',
     3         CHHT2,CHXP2,CHSP, ' with text path = ',
     4         NMTXP(TXP), ' and alignment = [', HNAM(TXALH), ',',
     5         VNAM(TXALV), '].'
            CALL INMSG (MSG)
            NEGOK = .FALSE.
         ENDIF

C  tolerances for comparison, based on char-ht
         ABSTOL = .02*ABS(CHHT)
         RELTOL = .02

         IF (APPEQ(TXEXRX(1),XLO, ABSTOL,RELTOL) .AND.
     1       APPEQ(TXEXRX(2),XHI, ABSTOL,RELTOL) .AND.
     1       APPEQ(TXEXRY(1),YLO, ABSTOL,RELTOL) .AND.
     1       APPEQ(TXEXRY(2),YHI, ABSTOL,RELTOL) ) THEN
C           OK, then ...
         ELSE
            WRITE (MSG, '(A,3F11.4,7A)') 'Incorrect rectangle ' //
     1         'location for character height, expansion, and ' //
     2         'spacing = ', CHHT,CHXP,CHSP, ' with text path = ',
     3         NMTXP(TXP), ' and alignment = [', HNAM(TXALH), ',',
     4         VNAM(TXALV), '].'
            CALL INMSG (MSG)
            LOCOK = .FALSE.
         ENDIF

         IF (APPEQ(ACPX, CCPX, ABSTOL,RELTOL) .AND.
     1       APPEQ(ACPY, CCPY, ABSTOL,RELTOL) ) THEN
C           OK, then ...
         ELSE
            WRITE (MSG, '(A,3F11.4,7A)') 'Incorrect concatenation '   //
     1         'point location for character height, expansion, and ' //
     2         'spacing = ', CHHT,CHXP,CHSP, ' with text path = ',
     3         NMTXP(TXP), ' and alignment = [', HNAM(TXALH), ',',
     4         VNAM(TXALV), '].'
            CALL INMSG (MSG)
            CCPOK = .FALSE.
         ENDIF

C  next alignment
410   CONTINUE
400   CONTINUE
C  next text path
300   CONTINUE

      CALL SETMSG ('6 8 10 15 17 18', 'Negating the character '    //
     1             'height or expansion factor should not change ' //
     2             'the location of a horizontal text extent '     //
     3             'rectangle nor its associated concatenation point.')
      CALL IFPF (NEGOK)

      CALL SETMSG ('1 2 3 6 7 8 9 10 11 13 14 15', 'For any valid '   //
     1             'parameter values, the location of a horizontal '  //
     2             'text extent rectangle should be as derived from ' //
     3             'nominal character body sizes and from nominal '   //
     4             'text alignments.')
      CALL IFPF (LOCOK)

      CALL SETMSG ('1 2 3 6 7 8 9 10 11 13 14 17 18', 'For any '      //
     1             'valid parameter values, the location of the '     //
     2             'concatenation point following a horizontal '      //
     3             'text extent rectangle should be as derived from ' //
     4             'nominal character body sizes and from nominal '   //
     5             'text alignments.')
      CALL IFPF (CCPOK)

C  *** *** *** ***   vertical text paths   *** *** *** ***

      LOCOK = .TRUE.
      CCPOK = .TRUE.
      NEGOK = .TRUE.

C  for vertical text paths
      DO 500 TXP = PUP,PDOWN

C  for all text alignments (txal)
      DO 600 TXALH = PALEFT,PARITE
      DO 610 TXALV = PATOP,PABOTT

C  chht,chxp,chsp = some random values for character height,
C    expansion factor, and spacing
         CHHT = 10.0 ** RNDRL(-2.0, 2.0)
         CHXP = 10.0 ** RNDRL(-2.0, 2.0)
         CHSP = RNDRL(-3.0, 3.0)

C  calculate expected value for:
C     xlo,xhi,ylo,yhi = position of text extent rectangle
C     ccpx,ccpy       = concatenation point

C  character increment
         CHRINC = NOMCH + CHSP
         YSIZ = NOMCH + (NCHAR-1)*ABS(CHRINC)
         CCPX = 0.0
         XLO  = -HTAB(TXALH) * NOMVW * CHXP
         XHI  = XLO + NOMVW * CHXP

C  compute Y-values for TOP alignment
         YHI  = 0.0
         YLO  = -YSIZ

         IF (TXP .EQ. PUP) THEN
            IF (CHRINC.LT.0) THEN
               CCPY = NCHAR*CHRINC - VTAB(PABASE)
            ELSE
               CCPY = CHSP + VTAB(PABOTT) - VTAB(PABASE)
            ENDIF
         ELSE
            IF (CHRINC.LT.0) THEN
               CCPY = -CHRINC
            ELSE
               CCPY = -NCHAR*CHRINC
            ENDIF
         ENDIF

C  offset for alignment
         IF (TXALV.EQ.PABOTT) THEN
            YOFF = YSIZ
         ELSEIF (TXALV.EQ.PABASE) THEN
            YOFF = YSIZ + VTAB(PABASE) - VTAB(PABOTT)
         ELSEIF (TXALV.EQ.PAHALF) THEN
            YOFF = VTAB(PAHALF) + ((NCHAR-1)/2.0)*ABS(CHRINC)
         ELSEIF (TXALV.EQ.PACAP) THEN
            YOFF = VTAB(PACAP)
         ELSE
C  alignment = TOP
            YOFF = 0.0
         ENDIF

C  offset y-values and then scale everything by character height
         XLO  = XLO  * CHHT
         XHI  = XHI  * CHHT
         CCPX = CCPX * CHHT
         YHI  = (YHI  + YOFF) * CHHT
         YLO  = (YLO  + YOFF) * CHHT
         CCPY = (CCPY + YOFF) * CHHT

C  determine actual rectangle:
         CALL PQTXX (SPECWT, FONT, CHXP,CHSP,CHHT, TXP, TXALH,TXALV,
     2               TESTR, ERRIND, TXEXRX,TXEXRY, ACPX,ACPY)
         CALL CHKINQ ('pqtxx',ERRIND)

C  set up for negative values
         IX = RNDINT(1,3)
         IF (IX.EQ.1) THEN
            CHHT2 = -CHHT
            CHXP2 = -CHXP
         ELSEIF (IX.EQ.2) THEN
            CHHT2 =  CHHT
            CHXP2 = -CHXP
         ELSE
            CHHT2 = -CHHT
            CHXP2 =  CHXP
         ENDIF

C  determine 2nd actual rectangle, with negative values:
         CALL PQTXX (SPECWT, FONT, CHXP2,CHSP,CHHT2, TXP, TXALH,TXALV,
     2               TESTR, ERRIND, T2EXRX,T2EXRY, A2CPX,A2CPY)
         CALL CHKINQ ('pqtxx',ERRIND)

         IF (TXEXRX(1) .EQ. T2EXRX(1) .AND.
     1       TXEXRX(2) .EQ. T2EXRX(2) .AND.
     1       TXEXRY(1) .EQ. T2EXRY(1) .AND.
     1       TXEXRY(2) .EQ. T2EXRY(2) .AND.
     1       ACPX .EQ. A2CPX .AND. ACPY .EQ. A2CPY ) THEN
C           OK, then ...
         ELSE
            WRITE (MSG, '(A,3F11.4,7A)') 'Inconsistent locations ' //
     1         'with negative character height or expansion, for ' //
     2         'character height, expansion, and spacing = ',
     3         CHHT2,CHXP2,CHSP, ' with text path = ',
     4         NMTXP(TXP), ' and alignment = [', HNAM(TXALH), ',',
     5         VNAM(TXALV), '].'
            CALL INMSG (MSG)
            NEGOK = .FALSE.
         ENDIF

C  tolerances for comparison, based on char-ht
         ABSTOL = .02*ABS(CHHT)
         RELTOL = .02

         IF (APPEQ(TXEXRX(1),XLO, ABSTOL,RELTOL) .AND.
     1       APPEQ(TXEXRX(2),XHI, ABSTOL,RELTOL) .AND.
     1       APPEQ(TXEXRY(1),YLO, ABSTOL,RELTOL) .AND.
     1       APPEQ(TXEXRY(2),YHI, ABSTOL,RELTOL) ) THEN
C           OK, then ...
         ELSE
            WRITE (MSG, '(A,3F11.4,7A)') 'Incorrect rectangle ' //
     1         'location for character height, expansion, and ' //
     2         'spacing = ', CHHT,CHXP,CHSP, ' with text path = ',
     3         NMTXP(TXP), ' and alignment = [', HNAM(TXALH), ',',
     4         VNAM(TXALV), '].'
            CALL INMSG (MSG)
            LOCOK = .FALSE.
         ENDIF

         IF (APPEQ(ACPX, CCPX, ABSTOL,RELTOL) .AND.
     1       APPEQ(ACPY, CCPY, ABSTOL,RELTOL) ) THEN
C           OK, then ...
         ELSE
            WRITE (MSG, '(A,3F11.4,7A)') 'Incorrect concatenation '   //
     1         'point location for character height, expansion, and ' //
     2         'spacing = ', CHHT,CHXP,CHSP, ' with text path = ',
     3         NMTXP(TXP), ' and alignment = [', HNAM(TXALH), ',',
     4         VNAM(TXALV), '].'
            CALL INMSG (MSG)
            CCPOK = .FALSE.
         ENDIF

C  next alignment
610   CONTINUE
600   CONTINUE
C  next text path
500   CONTINUE

      CALL SETMSG ('6 8 10 16 17 18', 'Negating the character '    //
     1             'height or expansion factor should not change ' //
     2             'the location of a vertical text extent '       //
     3             'rectangle nor its associated concatenation point.')
      CALL IFPF (NEGOK)

      CALL SETMSG ('1 2 3 6 7 8 9 10 11 13 14 16', 'For any valid '   //
     1             'parameter values, the location of a vertical '    //
     2             'text extent rectangle should be as derived from ' //
     3             'nominal character body sizes and from nominal '   //
     4             'text alignments.')
      CALL IFPF (LOCOK)

      CALL SETMSG ('1 2 3 6 7 8 9 10 11 13 14 17 18', 'For any '      //
     1             'valid parameter values, the location of the '     //
     2             'concatenation point following a vertical '        //
     3             'text extent rectangle should be as derived from ' //
     4             'nominal character body sizes and from nominal '   //
     5             'text alignments.')
      CALL IFPF (CCPOK)

C  endprog:
666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
