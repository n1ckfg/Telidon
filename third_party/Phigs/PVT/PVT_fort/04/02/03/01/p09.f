C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.01/09                        *
C  *    TEST TITLE : Character up vector                   *
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

      CALL INITGL ('04.02.03.01/09')

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
      CALL TSCHUP (1, PRIGHT, 'Going up?', NUMSTR, NGSTR)
      CALL SETMSG ('16 27 31 66 67 69 74 75 80 81', 'A text ' //
     1             'primitive with STROKE precision and a '   //
     2             'horizontal text path should be rotated '  //
     3             'according to the character up vector.')
      CALL DCHPFV ('CHARACTER UP FOR HORIZONTAL TEXT PATH: Which ' //
     1             'text primitive is NOT aligned within the '     //
     2             'dotted text extent rectangle on the dashed '   //
     3             'baseline?', NUMSTR, NGSTR)
      CALL PEMST (102)

C  use font #2 for vertical path
      CALL TSCHUP (2, PDOWN, 'Up&@M', NUMSTR, NGSTR)
      CALL SETMSG ('16 27 31 66 67 68 74 75 80 81', 'A text '        //
     1             'primitive with STROKE precision and a vertical ' //
     2             'text path should be rotated according to the '   //
     3             'character up vector.')
      CALL DCHPFV ('CHARACTER UP FOR VERTICAL TEXT PATH: Which ' //
     1             'text primitive is NOT aligned within the '   //
     2             'dotted text extent rectangle on the dashed ' //
     3             'centerline?', NUMSTR, NGSTR)
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
