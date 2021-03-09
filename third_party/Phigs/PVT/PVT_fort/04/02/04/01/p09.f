C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/09                        *
C  *    TEST TITLE : Annotation text character up vector   *
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

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    PICSTR, TXCI, NUMSTR, NGSTR

      CALL INITGL ('04.02.04.01/09')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

      CALL PSTXPR (PSTRKP)
      CALL PSCHH  (1.0)
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (102)

C  use font #1 for horizontal path
      CALL TSANUP (1, PRIGHT, 'Going up?', NUMSTR, NGSTR)

      CALL SETMSG ('1 2 5 9 19 23 57 58 60 65 66 71 72', 'An '        //
     1             'annotation text primitive with STROKE precision ' //
     2             'and a horizontal annotation text path should be ' //
     3             'rotated according to the annotation text '        //
     4             'character up vector.')

      CALL DCHPFV ('CHARACTER UP FOR HORIZONTAL ANNOTATION TEXT '  //
     1             'PATH: Which annotation text primitive is NOT ' //
     2             'aligned within the dotted annotation text '    //
     3             'extent rectangle on the dashed baseline?',
     4             NUMSTR, NGSTR)
      CALL PEMST (102)

C  use font#2 for vertical path
      CALL TSANUP (2, PDOWN, 'Up&@M', NUMSTR, NGSTR)

      CALL SETMSG ('1 2 5 9 19 23 57 58 59 65 66 71 72', 'An '        //
     1             'annotation text primitive with STROKE precision ' //
     2             'and a vertical annotation text path should be '   //
     3             'rotated according to the annotation text '        //
     4             'character up vector.')

      CALL DCHPFV ('CHARACTER UP FOR VERTICAL ANNOTATION TEXT PATH: ' //
     1             'Which annotation text primitive is NOT aligned '  //
     2             'within the dotted annotation text extent '        //
     3             'rectangle on the dashed centerline?', NUMSTR, NGSTR)
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END

