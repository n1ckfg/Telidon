C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.04.02/03                        *
C  *    TEST TITLE : Appearance of highlighted primitives  *
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

      INTEGER    SETSIZ
      PARAMETER (SETSIZ=1025)

      INTEGER    PICSTR, TXCI, IX, NANAMS, RANORD(8)
      INTEGER    HLLIST(4), IVLIST(4), PRIMID
      INTEGER    INCSET(SETSIZ), EXCSET(SETSIZ), INCSIZ,EXCSIZ
      INTEGER    IDUM1, IDUM2, IDUM4, IDUM5, IDUM6, IDUM7

      CHARACTER  MSG*300

      CALL INITGL ('04.03.04.02/03')

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
      CALL PEXST (102)
      CALL PCLST

      CALL NMSCOL (WKID)
      CALL POPST  (102)
      CALL NMSPRM (.TRUE.)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4 10 11', 'Highlighting of primitives should ' //
     1             'be correctly controlled by the highlighting '    //
     2             'filter when its inclusion set is the largest '   //
     3             'guaranteed by the standard.')

C  incl = {0-63}
C  excl = random set of 6 elements chosen from 0-23
      INCSIZ = 64
      DO 100 IX = 1, INCSIZ
         INCSET(IX) = IX-1
100   CONTINUE
      EXCSIZ = 6
      CALL RNBSET (EXCSIZ,0,23,EXCSET)

      CALL TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4', 'Highlighting of primitives should be '     //
     1             'correctly controlled by the highlighting filter ' //
     2             'when its inclusion set is null.')

C  incl = null, excl = {2,4,6,8}
      INCSIZ = 0
      CALL SETVS ('2,4,6,8', EXCSET, EXCSIZ)

      CALL TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  <inquire PHIGS facilities> to determine:
C  nanams = number of available names for namesets
      CALL PQPHF (1, ERRIND, IDUM1,IDUM2, NANAMS,
     1            IDUM4,IDUM5,IDUM6,IDUM7)
      CALL CHKINQ ('pqphf', ERRIND)
      IF (NANAMS .GT. SETSIZ) THEN
         WRITE (MSG, '(A,I9,A,I9,A)') 'Number of available names ' //
     1         'exceeds current program limit.  The value of the ' //
     2         'PARAMETER SETSIZ must be changed to ', NANAMS,
     3         '.  The current value is ', SETSIZ, '.'
         CALL INMSG (MSG)
         GOTO 120
       ENDIF

      CALL SETMSG ('1 4 12', 'Highlighting of primitives should be '  //
     1             'correctly controlled by the highlighting filter ' //
     2             'when its inclusion set is the largest supported ' //
     3             'by the implementation.')

C  incl = {0-nanams}
C  excl = random set of 6 elements chosen from 0-23
      DO 110 IX = 1,NANAMS
         INCSET(IX) = NANAMS-IX
110   CONTINUE
      INCSIZ = NANAMS
      EXCSIZ = 6
      CALL RNBSET (EXCSIZ,0,23,EXCSET)

      CALL TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

120   CONTINUE

      CALL SETMSG ('1 4 12 13', 'Highlighting of primitives should ' //
     1             'be correctly controlled by the highlighting '    //
     2             'filter by ignoring invalid names in its '        //
     3             'inclusion set.')

C  incl = random set of 6 elements chosen from 0-23 plus -1, nanams
C  excl = null
      INCSIZ = 8
      CALL RNBSET (INCSIZ,0,23,INCSET)
      INCSET(1) = -1
      INCSET(8) = NANAMS
      EXCSIZ = 0

      CALL TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

      CALL SETMSG ('1 4 10 11', 'Highlighting of primitives should ' //
     1             'be correctly controlled by the highlighting '    //
     2             'filter when its exclusion set is the largest '   //
     3             'guaranteed by the standard.')

C  incl = random set of 6 elements chosen from 0-23
C  excl = {0-63}
      INCSIZ = 6
      CALL RNBSET (INCSIZ,0,23,INCSET)

      EXCSIZ = 64
      DO 130 IX = 1, EXCSIZ
         EXCSET(IX) = IX-1
130   CONTINUE

      CALL TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4', 'Highlighting of primitives should be '     //
     1             'correctly controlled by the highlighting filter ' //
     2             'when its exclusion set is null.')

C  incl = random set of 6 elements chosen from 0-23
C  excl = null
      INCSIZ = 6
      CALL RNBSET (INCSIZ,0,23,INCSET)
      EXCSIZ = 0

      CALL TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('1 4', 'Highlighting of primitives should be '     //
     1             'correctly controlled by the highlighting filter ' //
     2             'when its inclusion and exclusion set are '        //
     3             'neither null nor full.')

C  incl = random set of 7 elements chosen from 0-23
C  excl = random set of 5 elements chosen from 0-23
      INCSIZ = 7
      CALL RNBSET (INCSIZ,0,23,INCSET)
      EXCSIZ = 5
      CALL RNBSET (EXCSIZ,0,23,EXCSET)

      CALL TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  ranord = random order for 1-8
      CALL RNPERM (8, RANORD)

      DO 200 IX = 1,4
         PRIMID = RANORD(IX)
C  make primitive #primid eligible for highlighting
         INCSET(IX) = PRIMID*3 - 2
         HLLIST(IX) = PRIMID
200   CONTINUE
      CALL PSHLFT (WKID, 4,INCSET, 0,EXCSET)

      DO 300 IX = 3,6
         PRIMID = RANORD(IX)
C  make primitive #primid eligible for invisibility
         INCSET(IX-2) = PRIMID*3 - 2
         IVLIST(IX-2) = PRIMID
300   CONTINUE
      CALL PSIVFT (WKID, 4,INCSET, 0,EXCSET)

      CALL SETMSG ('1 4 5 8', 'Primitives eligible only for '      //
     1             'highlighting should be highlighted even when ' //
     2             'displayed along with invisible primitives.')
      CALL DLSTPF ('PRECEDENCE OF INVISIBILITY OVER HIGHLIGHTING: ' //
     1             'For which pairs of primitives is the left '     //
     2             'member highlighted (n if none)?', 2,HLLIST, 'S')

      CALL SETMSG ('1 4 5 8', 'Primitives eligible for both ' //
     1             'highlighting and invisibility should be ' //
     2             'invisible.')
      CALL DLSTPF ('PRECEDENCE OF INVISIBILITY OVER HIGHLIGHTING: ' //
     1             'For which pairs of primitives is the left '     //
     2             'member invisible (n if none)?', 4,IVLIST, 'S')

C  wrap it up.
      CALL ENDIT
      END
