C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.03/03                        *
C  *    TEST TITLE : Text rectangle size and concatenation *
C  *                 point for vertical text orientation   *
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

      INTEGER    FONT, TXP, TXALH ,TXALV, SPECWT,
     1           TXOR, HRIZNT, VERTIC,
     2           IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6
      PARAMETER (HRIZNT = 1, VERTIC = 2)

      REAL       CHXP, CHSP, CHH, TXEXRX(2), TXEXRY(2),
     1           MNCHH, MXCHH, MNCHXP, MXCHXP, NOMCHH,
     2           NOMW, NOMH, RDUM1,RDUM2

      CHARACTER  STR*20, MSG*200

      LOGICAL    DIDTST, RECTOK, CCPOK, ROK1, ROK2, CCPOK1, CCPOK2

      CALL INITGL ('04.02.03.03/03')

C open PHIGS and workstation
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, IDUM1, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  Throughout, use variable names:
C  specwt: workstation type
C  font:   text font
C  chxp:   character expansion factor
C  chsp:   character spacing
C  chh:    character height
C  txp:    text path
C  txal:   text alignment
C  str:    character string
C
C  <inquire text facilities> to determine:
C     mnchxp = minimum character expansion factor
C     mxchxp = maximum character expansion factor
C     mnchh  = minimum character height
C     mxchh  = maximum character height
      CALL PQTXF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1            MNCHH, MXCHH, IDUM5, MNCHXP, MXCHXP, IDUM6)
      CALL CHKINQ ('pqtxf', ERRIND)

C  <Inquire text extent> with:
C     txp    = DOWN
C     txal   = LEFT, BOTTOM
C     str    = "Inquire text extent"
C  to determine:
C     nomw   = nominal width  = abs (txexrx(2) - txexrx(1))
C     nomh   = nominal height = abs (txexry(2) - txexry(1))

C  font   = a randomly selected font; non-monospaced if possible
      CALL PRPFNT (SPECWT, FONT)
      WRITE (MSG, '(A,I5,A)') 'Font selected for test: ', FONT, '.'
      CALL INMSG (MSG)
      CHXP  = 1.0
      CHSP  = 0.0
      CHH   = 1.0
      TXP   = PDOWN
      TXALH = PALEFT
      TXALV = PABOTT
      STR   = 'Inquire text extent'
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:19), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)
      NOMW   = ABS (TXEXRX(2) - TXEXRX(1))
      NOMH   = ABS (TXEXRY(2) - TXEXRY(1))

C  *** *** ***   character expansion factor   *** *** ***
C
C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP = 1.7
      CHSP = 0.0
      CHH  = 1.0
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6001

      CALL SETMSG ('6 13 16', 'The width of a text rectangle with '   //
     1             'zero character spacing and a vertical text path ' //
     2             'should expand in proportion to the character '    //
     3             'expansion factor.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('6 10 13 17', 'With zero character spacing and ' //
     1             'a vertical text path, the concatenation point ' //
     2             'of a text rectangle should be unaffected by '   //
     3             'its expansion in proportion to the character '  //
     4             'expansion factor.')
      CALL IFPF (CCPOK)

6001  CONTINUE

C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      IF (ABS(MXCHXP) .LT. 1.0E+37) THEN
         CHXP = 1.9 * MXCHXP
      ELSE
         CHXP = MXCHXP
      ENDIF
      CHSP = 0.0
      CHH  = 1.0
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6002

      CALL SETMSG ('6 13 14 16', 'The width of a text rectangle '     //
     1             'with zero character spacing and a vertical text ' //
     2             'path should expand in proportion to the '         //
     3             'character expansion factor, even when it '        //
     4             'exceeds the maximum for the workstation type.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('6 10 13 14 17', 'With zero character spacing '    //
     1             'and a vertical text path, the concatenation '     //
     2             'point of a text rectangle should be unaffected '  //
     3             'by its expansion in proportion to the character ' //
     4             'expansion factor, even when it exceeds the '      //
     5             'maximum for the workstation type.')
      CALL IFPF (CCPOK)

6002  CONTINUE

C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      IF (ABS(MNCHXP) .GT. 1.0E-37) THEN
         CHXP = 0.6 * MNCHXP
      ELSE
         CHXP = MNCHXP
      ENDIF
      CHSP = 0.0
      CHH  = 1.0
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6003

      CALL SETMSG ('6 13 14 16', 'The width of a text rectangle with '//
     1             'zero character spacing and a vertical text path ' //
     2             'should expand in proportion to the character '    //
     3             'expansion factor, even when it is less than the ' //
     4             'minimum for the workstation type.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('6 10 13 14 17', 'With zero character spacing and '//
     1             'a vertical text path, the concatenation point '   //
     2             'of a text rectangle should be unaffected by its ' //
     3             'expansion in proportion to the character '        //
     4             'expansion factor, even when it is less than the ' //
     5             'minimum for the workstation type.')
      CALL IFPF (CCPOK)

6003  CONTINUE

C  *** *** ***   character height   *** *** ***
C
C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP = 1.0
      CHSP = 0.0
      CHH  = 1.9
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6004

      CALL SETMSG ('8 9 13 16', 'The size of a text rectangle '       //
     1             'with character spacing = 0, character expansion ' //
     2             'factor = 1, and a vertical text path should '     //
     3             'expand in proportion to the character height.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('8 9 10 13 17', 'With character spacing = 0, '    //
     1             'character expansion factor = 1, and a vertical ' //
     2             'text path, the concatenation point of a text '   //
     3             'rectangle should reflect its expansion in '      //
     4             'proportion to the character height.')
      CALL IFPF (CCPOK)

6004  CONTINUE

C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP = 1.0
      CHSP = 0.0
      IF (ABS(MXCHH) .LT. 1.0E+37) THEN
         CHH = 1.9 * MXCHH
      ELSE
         CHH = MXCHH
      ENDIF
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6005

      CALL SETMSG ('8 9 13 14 16', 'The size of a text rectangle '   //
     1             'with character spacing = 0, character expansion '//
     2             'factor = 1, and a vertical text path should '    //
     3             'expand in proportion to the character height, '  //
     4             'even when it exceeds the maximum for the '       //
     5             'workstation type.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('8 9 10 13 14 17', 'With character spacing = 0, ' //
     1             'character expansion factor = 1, and a vertical ' //
     2             'text path, the concatenation point of a text '   //
     3             'rectangle should reflect its expansion in '      //
     4             'proportion to the character height, even when '  //
     5             'it exceeds the maximum for the workstation type.')
      CALL IFPF (CCPOK)

6005  CONTINUE

C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP = 1.0
      CHSP = 0.0
      IF (ABS(MNCHH) .GT. 1.0E-37) THEN
         CHH = 0.6 * MNCHH
      ELSE
         CHH = MNCHH
      ENDIF
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6006

      CALL SETMSG ('8 9 13 14 16', 'The size of a text rectangle '   //
     1             'with character spacing = 0, character expansion '//
     2             'factor = 1, and a vertical text path should '    //
     3             'expand in proportion to the character height, '  //
     4             'even when it is less than the minimum for the '  //
     5             'workstation type.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('8 9 10 13 14 17', 'With character spacing = 0, '  //
     1             'character expansion factor = 1, and a vertical '  //
     2             'text path, the concatenation point of a text '    //
     3             'rectangle should reflect its expansion in '       //
     4             'proportion to the character height, even when '   //
     5             'it is less than the minimum for the workstation ' //
     6             'type.')
      CALL IFPF (CCPOK)

6006  CONTINUE

C  *** *** ***   character spacing   *** *** ***
C
C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP = 1.0
      CHSP = 0.3
      CHH  = 1.0
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6007

      CALL SETMSG ('7 13 16', 'The height of a text rectangle with ' //
     1             'character expansion factor = 1, character '      //
     2             'height = 1, and a vertical text path should '    //
     3             'increase by the character spacing times one '    //
     4             'less than the number of characters.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('7 10 13 17 18', 'With character expansion factor '//
     1             '= 1, character height = 1, and a vertical text '  //
     2             'path, the concatenation point of a text '         //
     3             'rectangle should reflect its increased size due ' //
     4             'to character spacing.')
      CALL IFPF (CCPOK)

6007  CONTINUE

C  *** *** ***   combined attributes   *** *** ***
C
C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP = 35.3
      CHSP = 6.2
      CHH  = 21.1
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6008

      CALL SETMSG ('6 7 8 9 13 16', 'The size of a text rectangle '  //
     1             'with a vertical text path should reflect the '   //
     2             'combined effects of large values for character ' //
     3             'expansion factor, character spacing, and '       //
     4             'character height.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('6 7 8 9 10 13 17 18', 'With large values for '    //
     1             'character expansion factor, character spacing, '  //
     2             'and character height, and a vertical text path, ' //
     3             'the concatenation point of a text rectangle '     //
     4             'should reflect its increased size.')
      CALL IFPF (CCPOK)

6008  CONTINUE

C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP = .035
      CHSP = .0062
      CHH  = .021
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6009

      CALL SETMSG ('6 7 8 9 13 16', 'The size of a text rectangle '  //
     1             'with a vertical text path should reflect the '   //
     2             'combined effects of small values for character ' //
     3             'expansion factor, character spacing, and '       //
     4             'character height.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('6 7 8 9 10 13 17 18', 'With small values for '    //
     1             'character expansion factor, character spacing, '  //
     2             'and character height, and a vertical text path, ' //
     3             'the concatenation point of a text rectangle '     //
     4             'should reflect its decreased size.')
      CALL IFPF (CCPOK)

6009  CONTINUE

C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP = -8.035
      CHSP =  -.09
      CHH  =   .021
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6010

      CALL SETMSG ('6 7 8 9 13 16', 'The size of a text rectangle ' //
     1             'with a vertical text path should reflect the '  //
     2             'combined effects of negative values for '       //
     3             'character expansion factor and character '      //
     4             'spacing.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('6 7 8 9 10 13 17 18', 'With negative values for ' //
     1             'character expansion factor and character '        //
     2             'spacing, and a vertical text path, the '          //
     3             'concatenation point of a text rectangle should '  //
     4             'reflect its altered size.')
      CALL IFPF (CCPOK)

6010  CONTINUE

C  call CHTXRC with: nomw, nomh, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP =   .035
      CHSP =  -.03
      CHH  = -9.02
      CALL CHTXRC (NOMW, NOMH, SPECWT, FONT, STR(1:19),
     1             TXOR, CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)
      IF (.NOT. DIDTST) GOTO 6011

      CALL SETMSG ('6 7 8 9 13 16', 'The size of a text rectangle ' //
     1             'with a vertical text path should reflect the '  //
     2             'combined effects of negative values for '       //
     3             'character spacing and character height.')
      CALL IFPF (RECTOK)

      CALL SETMSG ('6 7 8 9 10 13 17 18', 'With negative values for ' //
     1             'character spacing and character height, and a '   //
     2             'vertical text path, the concatenation point of '  //
     3             'a text rectangle should reflect its altered '     //
     4             'size.')
      CALL IFPF (CCPOK)

6011  CONTINUE

C  *** *** ***   Excessive character spacing   *** *** ***
C
C  <Inquire text extent> with:
      FONT   = 2
      CHXP   = 1.0
      CHSP   = 0.0
      CHH    = 1.0
      TXP    = PDOWN
      TXALH  = PALEFT
      TXALV  = PABOTT
      STR    = 'qqqq'
      CALL PQTXX (SPECWT, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1            STR(1:4), ERRIND, TXEXRX, TXEXRY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx',ERRIND)
      NOMCHH  = ABS (TXEXRY(2) - TXEXRY(1)) / 4
      NOMW    = ABS (TXEXRX(2) - TXEXRX(1))

C  call CHMONO with: nomchh, nomw, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP =  6.35
      CHSP = -8.51 * NOMCHH
      CHH  =  -.021
      CALL CHMONO (NOMCHH, NOMW, SPECWT, FONT, STR(1:4),
     1             TXOR, CHXP, CHSP, CHH, ROK1, CCPOK1)

C  call CHMONO with: nomchh, nomw, specwt, font, str unchanged
      TXOR = VERTIC
      CHXP =  -.065
      CHSP = -1.01 * NOMCHH
      CHH  = -7.21
      CALL CHMONO (NOMCHH, NOMW, SPECWT, FONT, STR(1:4),
     1             TXOR, CHXP, CHSP, CHH, ROK2, CCPOK2)

      CALL SETMSG ('6 7 8 9 13 16', 'The size of a text rectangle '   //
     1             'with a vertical text path should reflect the '    //
     2             'effect of negative character spacing of greater ' //
     3             'magnitude than the height of a single character.')
      CALL IFPF (ROK1 .AND. ROK2)

666   CONTINUE
C close PHIGS and workstation
      CALL ENDIT
      END
