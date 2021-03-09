C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.01/11                        *
C  *    TEST TITLE : Geometric interaction of text         *
C  *                 attributes                            *
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

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

      INTEGER    PICSTR, TXCI, NGLINE, IDUM1, NUMLIN

      CALL INITGL ('04.02.03.01/11')

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
C  Throughout, use font#1 (monospaced), STROKE precision.
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
C  use color #1 for text, color #2 and dashed lines for outline
      CALL DISCOL (2, WKID, IDUM1)
      CALL PSTXCI (1)
      CALL PSPLCI (2)
      CALL PSLN   (PLDASH)
      CALL PEXST  (102)
      CALL PCLST
      NUMLIN = 5

C  call routine to set up nominal expected outlines
      CALL INOUTL ()

C  leave #102 open
      CALL POPST (102)

      CALL SETMSG ('1 2 11 27 28 31 35 36 41 42 58 59 60 66 67 68 '   //
     1             '69 74 75 80 81',
     2             'The transformation effects of text path, text '   //
     3             'alignment, and character up vector and of '       //
     4             'various positive values for character expansion ' //
     5             'factor, character spacing, and character height ' //
     6             'should work correctly in conjunction with the '   //
     7             'text direction vectors for a 3D test primitive.')

C  GEOTXT generates display in structure #102
      CALL GEOTXT (.FALSE., NUMLIN, NGLINE)
      CALL DCHPFV ('GEOMETRY OF TEXT ATTRIBUTES: Which text '     //
     1             'primitive is NOT similar in size, position, ' //
     2             'and orientation to the dashed outline?', 
     3             NUMLIN, NGLINE)

      CALL SETMSG ('1 2 11 27 28 31 35 36 41 42 58 59 60 66 67 68 '   //
     1             '69 74 75 80 81',
     2             'The transformation effects of text path, text '   //
     3             'alignment, and character up vector and of '       //
     4             'various negative values for character expansion ' //
     5             'factor, character spacing, and character height ' //
     6             'should work correctly in conjunction with the '   //
     7             'text direction vectors for a 3D test primitive.')
                                             
C  GEOTXT generates display in structure #102
      CALL GEOTXT (.TRUE., NUMLIN, NGLINE)
      CALL DCHPFV ('GEOMETRY OF NEGATIVE TEXT ATTRIBUTES: Which ' //
     1             'text primitive is NOT similar in size, '      //
     2             'position, and orientation to the dashed outline?', 
     3             NUMLIN, NGLINE)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
