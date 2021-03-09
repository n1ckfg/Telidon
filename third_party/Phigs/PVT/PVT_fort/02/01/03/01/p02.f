
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.03.01/02                        *
C  *    TEST TITLE : Changing a structure identifier when  *
C  *                 the original and resulting identifier *
C  *                 are the same                          *
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

C string indicating the state of the CSS
      CHARACTER  EXCSS*900
      PARAMETER (EXCSS = '100,1, 101,2, 103,0/'                      //
     1                   '100,2, 102,1, 104,2, 109,0/'               //
     2                   '100,2, 102,1, 104,5, 109,0/'               //
     3                   '100,2, 102,2, 105,1, 110,0/'               //
     4                   '100,2, 102,2, 105,3, 114,0/'               //
     5                   '100,2, 102,2, 105,2, 108,2, 111,1, 114,0/' //
     6                   '100,2, 102,2, 105,2, 108,2, 111,3, 115,0/' //
     7                   '100,2, 102,5, 106,1, 108,2, 111,1, 114,0/' //
     8                   '100,2, 102,5, 106,1, 108,2, 111,3, 115,0/' //
     9                   '120,2, 106,1, 108,2, 111,1, 114,0/'        //
     O                   '120,2, 106,1, 108,2, 111,3, 115,0/'        //
     1                   '130,3, 106,1, 108,2, 111,1, 114,0/'        //
     2                   '130,3, 106,1, 108,2, 111,3, 115,0/'        //
     3                   '130,5, 107,1, 108,2, 111,1, 114,0/'        //
     4                   '130,5, 107,1, 108,2, 111,3, 115,0/'        //
     5                   '130,5, 107,4, 108,2, 111,1, 114,0/'        //
     6                   '130,5, 107,4, 108,2, 111,3, 115,0/'        //
     7                   '130,5, 107,5, 113,0/'                      //
     8                   '140,1, 142,0/'  )

C contents of structures 120 and 108
      CHARACTER  CON120*20,                 CON108*20
      PARAMETER (CON120 = '67,907, 66,106', CON108 = '67,961, 66,111')

      INTEGER    COMSTR, STRSTI, STYPE, OPNSTR, PSTNUM,
     1           PSTSTR, IDUM1

      REAL       RDUM1

      LOGICAL    CSSEQ, STRCON

      CALL INITGL ('02.01.03.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C open workstation
      CALL POPWK (WKID, CONID, WTYPE)

C  *** *** *** ***   Common structure = NON-EXISTENT   *** *** *** ***

      CALL SETMSG ('2', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure does not exist should '  //
     3             'create an empty structure.')

C subroutine to set up the CSS
      CALL STDCSS

      COMSTR = 300
      CALL PCSTID (COMSTR, COMSTR)

C use <inquire structure status> to determine
C    strsti = structure status indicator
      CALL PQSTST (COMSTR, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STRSTI .EQ. PSEMPT)

      CALL SETMSG ('2', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure does not exist should '  //
     3             'create an empty structure thus changing the '     //
     4             'contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS // '300,0/'))


C  *** *** *** Common structure = closed, not referenced, not posted *** *** ***

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is closed, not '         //
     3             'referenced and not posted should result in the '  //
     4             'structure being closed, contents unchanged and '  //
     5             'not posted.')

C subroutine to set up the CSS
      CALL STDCSS

      COMSTR = 120
      CALL PCSTID (COMSTR, COMSTR)

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
     2           STRCON (COMSTR, CON120))

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is closed, not '         //
     3             'referenced and not posted should have no effect ' //
     4             'on the contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** Common structure = closed, not referenced, posted *** *** ***


      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is closed, not '         //
     3             'referenced and posted should result in the '      //
     4             'structure being closed, contents unchanged and '  //
     5             'posted.')

C subroutine to set up the CSS
      CALL STDCSS

      COMSTR = 120
      CALL PPOST (WKID, COMSTR, 1.)
      CALL PCSTID (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, IDUM1)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pststr = posted structure
C     pstnum = number of posted structures
      CALL PQPOST (WKID, 1, ERRIND, PSTNUM, PSTSTR, RDUM1)

      CALL IFPF (ERRIND .EQ. 0        .AND.
     1           STYPE  .EQ. PNONST   .AND.
     2           PSTNUM .EQ. 1        .AND.
     3           PSTSTR .EQ. COMSTR   .AND.
     4           STRCON (COMSTR, CON120))

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is closed, not '         //
     3             'referenced and posted should have no effect on '  //
     4             'the contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** Common structure = closed, referenced, not posted *** *** ***

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is closed, referenced '  //
     3             'and not posted should result in the structure '   //
     4             'being closed, contents unchanged and not '        //
     5             'posted.')

C subroutine to set up the CSS
      CALL STDCSS
      COMSTR = 108
      CALL PCSTID (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, IDUM1)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pstnum = number of posted structures
      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)

      CALL IFPF (STYPE   .EQ. PNONST   .AND.
     1           PSTNUM  .EQ. 0        .AND.
     2           STRCON (COMSTR, CON108))

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is closed, referenced '  //
     3             'and not posted should have no effect on the '     //
     4             'contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** Common structure = closed, referenced, posted *** *** ***

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is closed, referenced '  //
     3             'and posted should result in the structure being ' //
     4             'closed, contents unchanged and posted.')

C subroutine to set up the CSS
      CALL STDCSS

      COMSTR = 108
      CALL PPOST (WKID, COMSTR, 1.)
      CALL PCSTID (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, IDUM1)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pststr = posted structure
C     pstnum = number of posted structures
      CALL PQPOST (WKID, 1, ERRIND, PSTNUM, PSTSTR, RDUM1)

      CALL IFPF (ERRIND .EQ. 0          .AND.
     1           STYPE  .EQ. PNONST     .AND.
     2           PSTNUM .EQ. 1          .AND.
     3           PSTSTR .EQ. COMSTR     .AND.
     4           STRCON (COMSTR, CON108))

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is closed, referenced '  //
     3             'and posted should have no effect on the '         //
     4             'contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** Common structure = opened, not referenced, not posted *** *** ***

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is opened, not '         //
     3             'referenced and not posted should result in the '  //
     4             'structure being opened, contents unchanged and '  //
     5             'not posted.')

C subroutine to set up the CSS
      CALL STDCSS

      COMSTR = 120
      CALL POPST (COMSTR)
      CALL PCSTID (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     opnstr = open structure
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, OPNSTR)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pstnum = number of posted structures
      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)

      CALL IFPF (STYPE  .EQ. POPNST     .AND.
     1           OPNSTR .EQ. COMSTR     .AND.
     2           PSTNUM .EQ. 0          .AND.
     3           STRCON (COMSTR, CON120))

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is opened, not '         //
     3             'referenced and not posted should have no effect ' //
     4             'on the contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** Common structure = opened, not referenced, posted *** *** ***

      CALL SETMSG ('3', '<Change structure identifier> where the '  //
     1             'original and resulting identifier are the same '//
     2             'and the common structure is opened, not '       //
     3             'referenced and posted should result in the '    //
     4             'structure being opened, contents unchanged '    //
     5             'and posted.')

C subroutine to set up the CSS
      CALL STDCSS

      COMSTR = 120
      CALL POPST (COMSTR)
      CALL PPOST (WKID, COMSTR, 1.)
      CALL PCSTID (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     opnstr = open structure
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, OPNSTR)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pststr = posted structure
C     pstnum = number of posted structures
      CALL PQPOST (WKID, 1, ERRIND, PSTNUM, PSTSTR, RDUM1)

      CALL IFPF (ERRIND .EQ. 0         .AND.
     1           STYPE  .EQ. POPNST    .AND.
     2           OPNSTR .EQ. COMSTR    .AND.
     3           PSTNUM .EQ. 1         .AND.
     4           PSTSTR .EQ. COMSTR    .AND.
     5           STRCON (COMSTR, CON120))

      CALL SETMSG ('3', '<Change structure identifier> where the '  //
     1             'original and resulting identifier are the same '//
     2             'and the common structure is opened, not '       //
     3             'referenced and posted should have no effect '   //
     4             'on the contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** Common structure = opened, referenced, not posted *** *** ***

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is opened, referenced '  //
     3             'and not posted should result in the structure '   //
     4             'being opened, contents unchanged and not '        //
     5             'posted.')

C subroutine to set up the CSS
      CALL STDCSS

      COMSTR = 108
      CALL POPST (COMSTR)
      CALL PCSTID (COMSTR, COMSTR)

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
     3           STRCON (COMSTR, CON108))

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is opened, referenced '  //
     3             'and not posted should have no effect on the '     //
     4             'contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

C  *** *** *** Common structure = opened, referenced, posted *** *** ***

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is opened, referenced '  //
     3             'and posted should result in the structure being ' //
     4             'opened, contents unchanged and posted.')

C subroutine to set up the CSS
      CALL STDCSS

      COMSTR = 108
      CALL POPST (COMSTR)
      CALL PPOST (WKID, COMSTR, RDUM1)
      CALL PCSTID (COMSTR, COMSTR)

C  use <inquire open structure> to determine
C     opnstr = open structure
C     stype  = open structure status
      CALL PQOPST (ERRIND, STYPE, OPNSTR)
      CALL CHKINQ ('pqopst', ERRIND)

C  use <inquire posted structures> to determine
C     pststr = posted structure
C     pstnum = number of posted structures
      CALL PQPOST (WKID, 1, ERRIND, PSTNUM, PSTSTR, RDUM1)

      CALL IFPF (ERRIND .EQ. 0         .AND.
     1           STYPE  .EQ. POPNST    .AND.
     2           OPNSTR .EQ. COMSTR    .AND.
     3           PSTNUM .EQ. 1         .AND.
     4           PSTSTR .EQ. COMSTR    .AND.
     5           STRCON (COMSTR, CON108))

      CALL SETMSG ('3', '<Change structure identifier> where the '    //
     1             'original and resulting identifier are the same '  //
     2             'and the common structure is opened, referenced '  //
     3             'and posted should have no effect on the '         //
     4             'contents of the CSS.')

      CALL IFPF (CSSEQ (EXCSS))

666   CONTINUE
      CALL ENDIT
      END
