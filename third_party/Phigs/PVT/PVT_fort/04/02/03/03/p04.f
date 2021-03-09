C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.03/04                        *
C  *    TEST TITLE : Text alignment                        *
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
     1           IDUM1, WKTYPE, NHORAL, NVERAL, HTXAL, VTXAL,
     2           LOW, HIGH, AHTXAL, AVTXAL, ITRIM
      PARAMETER (LOW = 1, HIGH = 2)

      REAL       CHXP, CHSP, CHH, TXEXRX(2), TXEXRY(2)
      REAL       HORLIM(PALEFT:PARITE, LOW:HIGH)
      REAL       VERLIM(PATOP :PABOTT, LOW:HIGH)
      REAL       VERTAB(PAVNOR:PABOTT), VLOC(PACAP:PABASE)
      REAL       ABSTOL, RELTOL, NOMCPX, NOMCPY, CPX, CPY
      REAL       RECHIX,RECLOX, RECLOY,RECHIY
      REAL       NOMW, NOMH, FRLOX, FRHIX, FRLOY, FRHIY, EXPCPX, EXPCPY

      LOGICAL    APPEQ

      CHARACTER  STR*20, CONMSG*400, VERMSG*400
      CHARACTER  VNMTAB(PAVNOR:PABOTT)*7, HNMTAB(PAHNOR:PARITE)*7
      CHARACTER  TXPTAB(PRIGHT:PDOWN)*7, TXBUF*7, VBUF*7, HBUF*7

      DATA VNMTAB / 'NORMAL', 'TOP', 'CAP', 'HALF', 'BASE',
     1              'BOTTOM' /
      DATA HNMTAB / 'NORMAL', 'LEFT', 'CENTRE', 'RIGHT' /
      DATA TXPTAB / 'RIGHT', 'LEFT', 'UP', 'DOWN' /

      CALL INITGL ('04.02.03.03/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C  Establish specwt = specific primary workstation type
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, IDUM1, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  set up for basic vertical tests
      CHXP  = 1.3
      CHSP  = 0.4
      CHH   = 3.4

      DO 50 TXALV = PACAP,PABASE
         CALL PQTXX (SPECWT, 2, CHXP, CHSP, CHH, PRIGHT, PACENT, TXALV,
     1               'NIST', ERRIND, TXEXRX, TXEXRY, CPX, CPY)
         CALL CHKINQ ('pqtxx',ERRIND)
         VLOC(TXALV) = TXEXRY(1)
50    CONTINUE

C  For approximate equality:
      ABSTOL = .02 * CHH
      RELTOL = .02

      CALL SETMSG ('8 11', 'Character height should set the '      //
     1             'distance between the CAP and BASE lines of a ' //
     2             'capital letter.')
      CALL IFPF ( APPEQ(VLOC(PABASE)-VLOC(PACAP), CHH, ABSTOL, RELTOL))

      CALL SETMSG ('11', 'Text alignment for HALF should be ' //
     1             'approximately halfway between CAP and BASE.')
      CALL IFPF (0.7*VLOC(PABASE)+0.3*VLOC(PACAP).GT.VLOC(PAHALF) .AND.
     1           0.3*VLOC(PABASE)+0.7*VLOC(PACAP).LT.VLOC(PAHALF))

C  default character height
      CHH = 4.4
C  For approximate equality:
      ABSTOL = .02 * CHH
      RELTOL = .02

C  Set horizontal and vertical limits for reasonable fraction of
C  text rectangle indicated by text alignment:
      HORLIM (PALEFT,  LOW)  = -.01
      HORLIM (PALEFT, HIGH)  =  .01
      HORLIM (PACENT,  LOW)  =  .49
      HORLIM (PACENT, HIGH)  =  .51
      HORLIM (PARITE,  LOW)  =  .99
      HORLIM (PARITE, HIGH)  = 1.01

      VERLIM (PATOP,   LOW)  =  .99
      VERLIM (PATOP,  HIGH)  = 1.01
      VERLIM (PACAP,   LOW)  =  .60
      VERLIM (PACAP,  HIGH)  = 1.01
      VERLIM (PAHALF,  LOW)  =  .20
      VERLIM (PAHALF, HIGH)  =  .80
      VERLIM (PABASE,  LOW)  =  .01
      VERLIM (PABASE, HIGH)  =  .40
      VERLIM (PABOTT,  LOW)  = -.01
      VERLIM (PABOTT, HIGH)  =  .01

      DO 100, TXP = PRIGHT, PDOWN
C     <inquire text extent> with:
         WKTYPE = SPECWT
C  font = 2 (ASCII font)
         FONT   = 2
         CHXP   = -0.33
         CHSP   = -0.1
         TXALH  = PALEFT
         TXALV  = PABOTT
         STR    = 'W.j '
C get nominal concatenation point offset
         CALL PQTXX (WKTYPE, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
     1               STR(1:4), ERRIND, TXEXRX, TXEXRY, NOMCPX, NOMCPY)
         CALL CHKINQ ('pqtxx',ERRIND)
C get nominal width and height
         NOMW   = ABS (TXEXRX(2) - TXEXRX(1))
         NOMH   = ABS (TXEXRY(2) - TXEXRY(1))

C     calculate NORMAL alignment, based on this txp:
         IF     (TXP .EQ. PRIGHT) THEN
            NHORAL = PALEFT
            NVERAL = PABASE
         ELSEIF (TXP .EQ. PLEFT) THEN
            NHORAL = PARITE
            NVERAL = PABASE
         ELSEIF (TXP .EQ. PUP) THEN
            NHORAL = PACENT
            NVERAL = PABASE
         ELSEIF (TXP .EQ. PDOWN) THEN
            NHORAL = PACENT
            NVERAL = PATOP
         ELSE
            CALL UNMSG ('Illegal text path.')
         ENDIF

         DO 200, HTXAL = PAHNOR, PARITE
C        calculate actual horizontal alignment:
            IF (HTXAL .EQ. PAHNOR) THEN
               AHTXAL = NHORAL
            ELSE
               AHTXAL = HTXAL
            ENDIF
            DO 300, VTXAL = PAVNOR, PABOTT
C           calculate actual vertical alignment:
               IF (VTXAL .EQ. PAVNOR) THEN
                  AVTXAL = NVERAL
               ELSE
                  AVTXAL = VTXAL
               ENDIF
               TXBUF = TXPTAB (TXP)
               HBUF  = HNMTAB (HTXAL)
               VBUF  = VNMTAB (VTXAL)

               CONMSG = 'When text path is ' // TXBUF(1:ITRIM(TXBUF)) //
     1                  ' and text alignment is (' //
     2                  HBUF(1:ITRIM(HBUF)) // ',' //
     3                  VBUF(1:ITRIM(VBUF)) // ') '

C           <inquire text extent> with wktype, font, chxp, chsp,
C                 chh, txp, str unchanged, but
               TXALH = HTXAL
               TXALV = VTXAL
               CALL PQTXX (WKTYPE, FONT, CHXP, CHSP, CHH, TXP, TXALH,
     1                     TXALV, STR(1:4), ERRIND, TXEXRX, TXEXRY,
     2                     CPX, CPY)
               CALL CHKINQ ('pqtxx',ERRIND)
               RECLOX = TXEXRX(1)
               RECHIX = TXEXRX(2)
               RECLOY = TXEXRY(1)
               RECHIY = TXEXRY(2)

               CALL SETMSG ('2 10 11 12 13 15 16',
     1                      CONMSG(1:ITRIM(CONMSG)) // ' the size ' //
     2                      'of the text extent rectangle should '  //
     3                      'be unaffected.')

               CALL IFPF (APPEQ((RECHIX-RECLOX), NOMW, ABSTOL, RELTOL)
     1              .AND. APPEQ((RECHIY-RECLOY), NOMH, ABSTOL, RELTOL))

               CALL SETMSG ('2 10 11 12 13 15 16',
     1                      CONMSG(1:ITRIM(CONMSG)) // ' the '       //
     2                      'location of the text extent rectangle ' //
     3                      'should be shifted as indicated by the ' //
     4                      'text alignment.')

C           calculate low, high fraction of rectangle:
               FRLOX =    -RECLOX / NOMW
               FRHIX = 1 - RECHIX / NOMW
               FRLOY =    -RECLOY / NOMH
               FRHIY = 1 - RECHIY / NOMH
C
C           pass/fail depending on
               CALL IFPF (HORLIM(AHTXAL,  LOW) .LE. FRLOX .AND.
     1                    HORLIM(AHTXAL, HIGH) .GE. FRLOX .AND.
     2                    HORLIM(AHTXAL,  LOW) .LE. FRHIX .AND.
     3                    HORLIM(AHTXAL, HIGH) .GE. FRHIX .AND.
     4                    VERLIM(AVTXAL,  LOW) .LE. FRLOY .AND.
     5                    VERLIM(AVTXAL, HIGH) .GE. FRLOY .AND.
     6                    VERLIM(AVTXAL,  LOW) .LE. FRHIY .AND.
     7                    VERLIM(AVTXAL, HIGH) .GE. FRHIY)
C
               IF (TXP .EQ. PLEFT .OR. TXP .EQ. PRIGHT) THEN
                   EXPCPX = NOMCPX + RECLOX
                   EXPCPY = .0
               ELSE
                   EXPCPX = .0
                   EXPCPY = NOMCPY + RECLOY
               ENDIF

               CALL SETMSG ('10 11 12 13 17 18',
     1                      CONMSG(1:ITRIM(CONMSG)) // ' the '       //
     2                      'concatenation point should be shifted ' //
     3                      'along the text path dimension by the '  //
     4                      'same amount as the text extent rectangle.')

C           pass/fail depending on
               CALL IFPF (APPEQ(CPX, EXPCPX, ABSTOL, RELTOL) .AND.
     1                    APPEQ(CPY, EXPCPY, ABSTOL, RELTOL))
C           save vertical displacements:
               VERTAB (VTXAL) = RECLOY
C           next vtxal
300         CONTINUE

            VERMSG = 'When text path is ' // TXBUF(1:ITRIM(TXBUF)) //
     1               ' and horizontal text alignment is '          //
     2               HBUF(1:ITRIM(HBUF)) // ','
            VBUF = VNMTAB(NVERAL)

            CALL SETMSG ('10 11 12 13 16', VERMSG(1:ITRIM(VERMSG)) //
     1                   ' then NORMAL vertical alignment should ' //
     2                   'have the same effect as '                //
     3                   VBUF(1:ITRIM(VBUF)) // '.')
            CALL IFPF (APPEQ(VERTAB(PAVNOR), VERTAB(NVERAL), ABSTOL,
     1                                                       RELTOL))

            CALL SETMSG ('10 11 13 16', VERMSG(1:ITRIM(VERMSG)) //
     1                   ' then vertical alignments TOP, CAP, ' //
     2                   'HALF, BASE, and BOTTOM should cause ' //
     3                   'increasing vertical displacements.')
            CALL IFPF (VERTAB(PATOP)  .LE. VERTAB(PACAP)  .AND.
     1                 VERTAB(PACAP)  .LT. VERTAB(PAHALF) .AND.
     2                 VERTAB(PAHALF) .LT. VERTAB(PABASE) .AND.
     3                 VERTAB(PABASE) .LT. VERTAB(PABOTT))

C        next htxal
200      CONTINUE
C     next txp
100   CONTINUE

666   CONTINUE
C close PHIGS and workstation
      CALL ENDIT
      END
