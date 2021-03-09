C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.03.03/02                        *
C  *    TEST TITLE : Changing a structure identifier and   *
C  *                 references when the original and      *
C  *                 resulting identifier are the same     *
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

C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)

C open structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

C element types
      INTEGER    PEEXST,      PELB
      PARAMETER (PEEXST = 66, PELB = 67)

C string indicating the initial state of the CSS
      CHARACTER EXCSS*900
      PARAMETER (EXCSS = '100,1, 101,2, 103,0/'                //
     1            '100,2, 102,1, 104,2, 109,0/'                //
     2            '100,2, 102,1, 104,5, 109,0/'                //
     3            '100,2, 102,2, 105,1, 110,0/'                //
     4            '100,2, 102,2, 105,3, 114,0/'                //
     5            '100,2, 102,2, 105,2, 108,2, 111,1, 114,0/'  //
     6            '100,2, 102,2, 105,2, 108,2, 111,3, 115,0/'  //
     7            '100,2, 102,5, 106,1, 108,2, 111,1, 114,0/'  //
     8            '100,2, 102,5, 106,1, 108,2, 111,3, 115,0/'  //
     9            '120,2, 106,1, 108,2, 111,1, 114,0/'         //
     1            '120,2, 106,1, 108,2, 111,3, 115,0/'         //
     2            '130,3, 106,1, 108,2, 111,1, 114,0/'         //
     3            '130,3, 106,1, 108,2, 111,3, 115,0/'         //
     4            '130,5, 107,1, 108,2, 111,1, 114,0/'         //
     5            '130,5, 107,1, 108,2, 111,3, 115,0/'         //
     6            '130,5, 107,4, 108,2, 111,1, 114,0/'         //
     7            '130,5, 107,4, 108,2, 111,3, 115,0/'         //
     8            '130,5, 107,5, 113,0/'                       //
     9            '140,1, 142,0/'  )

C  Declare program-specific variables

      INTEGER COMSTR, STRSTI, STYPE, OPNSTR, PSTNUM,
     1        PSTSTR, IDUM1

      REAL PRIORI, COMPRI, RDUM1

      LOGICAL CSSEQ, STRCON

      CALL INITGL ('02.01.03.03/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C open workstation
      CALL POPWK (WKID, CONID, WTYPE)

C  *** *** *** ***   Common structure = NON-EXISTENT   *** *** *** ***

      CALL SETMSG ('2', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure does not exist should create an empty ' //
     4             'structure.')

      CALL STDCSS
      COMSTR = 300
      CALL PCSTIR (COMSTR, COMSTR)

C  Use <inquire structure status> to determine
C     strsti = structure status indicator
      CALL PQSTST (COMSTR, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STRSTI .EQ. PSEMPT)

      CALL SETMSG ('2', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure does not exist should create an empty ' //
     4             'structure thus changing the contents of the '     //
     5             'CSS.')

      CALL IFPF (CSSEQ (EXCSS // '300, 0/'))

C  *** *** *** *** *** Common structure = closed, not posted *** *** *** *** ***

      CALL SETMSG ('3', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure is closed and not posted should '       //
     4             'result in the structure being closed, contents '  //
     5             'unchanged, and not posted.')


      CALL STDCSS
      COMSTR = 120
      CALL PCSTIR (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, IDUM1)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pstnum = number of posted structures
      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)

      CALL IFPF (STYPE  .EQ. PNONST   .AND.
     1           PSTNUM .EQ. 0        .AND.
     2           STRCON (COMSTR, '67,907, 66,106'))

      CALL SETMSG ('3', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure is closed and not posted should have '  //
     4             'no effect on the contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** *** *** Common structure = closed, posted *** *** *** *** ***

      CALL SETMSG ('3', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure is closed and posted should result in ' //
     4             'the structure being closed, contents unchanged, ' //
     5             'and posted.')

      CALL STDCSS
      COMSTR = 108
      COMPRI = .47
      CALL PPOST (WKID, COMSTR, COMPRI)
      CALL PCSTIR (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, IDUM1)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pstnum = number of posted structures
C     pststr = posted structure
C     priori = priority of posted structure

      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      IF (PSTNUM .EQ. 1)  THEN
          CALL PQPOST (WKID, 1, ERRIND, IDUM1, PSTSTR, PRIORI)
          CALL CHKINQ ('pqpost', ERRIND)
          CALL IFPF (STYPE  .EQ. PNONST   .AND.
     1               PSTSTR .EQ. COMSTR   .AND.
     2               PRIORI .EQ. COMPRI   .AND.
     3               STRCON (COMSTR, '67,961, 66,111'))
      ELSE
          CALL FAIL
      ENDIF

      CALL SETMSG ('3', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure is closed and posted should have no '   //
     4             'effect on the contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** *** *** Common structure = opened, posted *** *** *** *** ***

      CALL SETMSG ('3', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure is opened and posted should result in ' //
     4             'the structure being opened, contents unchanged, ' //
     5             'and posted.')

      CALL STDCSS
      COMSTR = 120
      CALL POPST (COMSTR)
      COMPRI = .47
      CALL PPOST (WKID, COMSTR, COMPRI)
      CALL PCSTIR (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     opnstr = open structure
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, OPNSTR)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pstnum = number of posted structures
C     pststr = posted structure
C     priori = priority of posted structure

      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      IF (PSTNUM .EQ. 1)  THEN
          CALL PQPOST (WKID, 1, ERRIND, IDUM1, PSTSTR, PRIORI)
          CALL CHKINQ ('pqpost', ERRIND)
          CALL IFPF (STYPE  .EQ. POPNST   .AND.
     1               OPNSTR .EQ. COMSTR   .AND.
     2               PSTSTR .EQ. COMSTR   .AND.
     3               PRIORI .EQ. COMPRI   .AND.
     4               STRCON (COMSTR, '67,907, 66,106'))
      ELSE
          CALL FAIL
      ENDIF

      CALL SETMSG ('3', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure is opened and posted should have no '   //
     4             'effect on the contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** *** *** Common structure = opened, not posted *** *** *** *** ***

      CALL SETMSG ('3', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure is opened and not posted should '       //
     4             'result in the structure being opened, contents '  //
     5             'unchanged, and not posted.')

      CALL STDCSS
      COMSTR = 108
      CALL POPST (COMSTR)
      CALL PCSTIR (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     opnstr = open structure
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, OPNSTR)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pstnum = number of posted structures
      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)

      CALL IFPF (STYPE  .EQ. POPNST   .AND.
     1           OPNSTR .EQ. COMSTR   .AND.
     2           PSTNUM .EQ. 0        .AND.
     3           STRCON (COMSTR, '67,961, 66,111'))

      CALL SETMSG ('3', '<Change structure identifier and '           //
     1             'references> where the original and resulting '    //
     2             'identifier are the same and the common '          //
     3             'structure is opened and not posted should have '  //
     4             'no effect on the contents of the CSS.')
      CALL IFPF (CSSEQ (EXCSS))

      CALL ENDIT
      END
