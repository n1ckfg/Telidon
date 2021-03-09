C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.04.02/01                        *
C  *    TEST TITLE : Highlighting filter - setting and     *
C  *                 inquiring                             *
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

      INTEGER      SETSIZ, IX
      PARAMETER   (SETSIZ=100)
      INTEGER      INQSET(SETSIZ), EXQSET(SETSIZ), INQSIZ,EXQSIZ
      INTEGER      INCSET(SETSIZ), EXCSET(SETSIZ), INCSIZ,EXCSIZ
      INTEGER      IDUM1,IDUM2, NANAMS, IDUM4,IDUM5,IDUM6,IDUM7

      LOGICAL      SETEQ

      CALL INITGL ('04.03.04.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

      CALL SETMSG ('2 3', 'Immediately after opening the '            //
     1             'workstation, the highlighting filter inclusion '  //
     2             'and exclusion sets should be null.')

      CALL POPWK (WKID, CONID, WTYPE)

C  <inquire highlighting filter>
      CALL PQHLFT (WKID, SETSIZ,SETSIZ,
     1             ERRIND, INQSIZ,INQSET, EXQSIZ,EXQSET)
      CALL IFPF (ERRIND .EQ. 0  .AND.
     1           INQSIZ .EQ. 0  .AND.
     2           EXQSIZ .EQ. 0)

      CALL SETMSG ('1 2 10', 'Highlighting filter should be '     //
     1             'reported as it was set for any set of names ' //
     2             'drawn from the accessible range.')

      CALL SETVS ('2,44,8,4,63', INCSET,INCSIZ)
      CALL SETVS ('0,4,5,32,59', EXCSET,EXCSIZ)

C  <set highlighting filter>:
      CALL PSHLFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  <inquire highlighting filter>
      CALL PQHLFT (WKID, SETSIZ,SETSIZ,
     1             ERRIND, INQSIZ,INQSET, EXQSIZ,EXQSET)

C  pass/fail depending on (inclusion set = orig_inclusion and
C                          exclusion set = orig_inclusion)
      CALL IFPF (ERRIND .EQ. 0                  .AND.
     1           INQSIZ .EQ. INCSIZ             .AND.
     2           EXQSIZ .EQ. EXCSIZ             .AND.
     3           SETEQ (INCSIZ, INCSET, INQSET) .AND.
     4           SETEQ (EXCSIZ, EXCSET, EXQSET) )

      CALL SETMSG ('1 2', 'Highlighting filter should be reported ' //
     1             'as it was re-set for any set of names drawn '   //
     2             'from the accessible range.')

      CALL SETVS ('59,47',    INCSET,INCSIZ)
      CALL SETVS ('13,15,18', EXCSET,EXCSIZ)

C  <set highlighting filter>
      CALL PSHLFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  <inquire highlighting filter>
      CALL PQHLFT (WKID, SETSIZ,SETSIZ,
     1             ERRIND, INQSIZ,INQSET, EXQSIZ,EXQSET)

C  pass/fail depending on (inclusion set = new_inclusion  and
C                          exclusion set = new_exclusion)
      CALL IFPF (ERRIND .EQ. 0                  .AND.
     1           INQSIZ .EQ. INCSIZ             .AND.
     2           EXQSIZ .EQ. EXCSIZ             .AND.
     3           SETEQ (INCSIZ, INCSET, INQSET) .AND.
     4           SETEQ (EXCSIZ, EXCSET, EXQSET) )

      CALL SETMSG ('1 2 11', 'Highlighting filter should be capable ' //
     1             'of containing at at least 64 names in its '       //
     2             'inclusion and exclusion sets.')

      DO 100 IX = 1,64
         INCSET(IX) = 64-IX
         EXCSET(IX) = 64-IX
100   CONTINUE
      INCSIZ = 64
      EXCSIZ = 64

C  <set highlighting filter>
      CALL PSHLFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  <inquire highlighting filter>
      CALL PQHLFT (WKID, SETSIZ,SETSIZ,
     1             ERRIND, INQSIZ,INQSET, EXQSIZ,EXQSET)

C  pass/fail depending on (inclusion set = new_inclusion  and
C                          exclusion set = new_exclusion)
      CALL IFPF (ERRIND .EQ. 0                  .AND.
     1           INQSIZ .EQ. INCSIZ             .AND.
     2           EXQSIZ .EQ. EXCSIZ             .AND.
     3           SETEQ (INCSIZ, INCSET, INQSET) .AND.
     4           SETEQ (EXCSIZ, EXCSET, EXQSET) )

C  <inquire PHIGS facilities> to determine
C    nanams = number of available names in namesets
      CALL PQPHF (1, ERRIND, IDUM1,IDUM2, NANAMS,
     1            IDUM4,IDUM5,IDUM6,IDUM7)
      CALL CHKINQ ('pqphf', ERRIND)

      CALL SETMSG ('1 2 12', 'Highlighting filter should be capable ' //
     1             'of containing the minimum and maximum allowed '   //
     2             'value for a name.')

      INCSET(1) = 0
      INCSET(2) = NANAMS-1
      EXCSET(2) = 0
      EXCSET(1) = NANAMS-1
      INCSIZ = 2
      EXCSIZ = 2

C  <set highlighting filter>
C     new_inclusion set = 0,nanams-1
C     new_exclusion set = 0,nanams-1
      CALL PSHLFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  <inquire highlighting filter>
      CALL PQHLFT (WKID, SETSIZ,SETSIZ,
     1             ERRIND, INQSIZ,INQSET, EXQSIZ,EXQSET)

C  pass/fail depending on (inclusion set = new_inclusion  and
C                          exclusion set = new_exclusion)
      CALL IFPF (ERRIND .EQ. 0                  .AND.
     1           INQSIZ .EQ. INCSIZ             .AND.
     2           EXQSIZ .EQ. EXCSIZ             .AND.
     3           SETEQ (INCSIZ, INCSET, INQSET) .AND.
     4           SETEQ (EXCSIZ, EXCSET, EXQSET) )

      CALL SETMSG ('1 2 12 13', 'Highlighting filter should contain ' //
     1             'only the valid names as set; invalid names '      //
     2             'specified by <set highlighting filter> should '   //
     3             'be ignored.')

C  <set highlighting filter>
C     inv_inclusion set = 0, nanams-1, nanams,    -10
C     inv_exclusion set = 0, nanams-1, nanams+10, -10
      INCSET(1) = 0
      INCSET(2) = NANAMS
      INCSET(3) = -10
      INCSET(4) = NANAMS-1

      EXCSET(1) = -10
      EXCSET(2) = NANAMS+10
      EXCSET(3) = 0
      EXCSET(4) = NANAMS-1
      INCSIZ = 4
      EXCSIZ = 4

      CALL PSHLFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  <inquire highlighting filter>
      CALL PQHLFT (WKID, SETSIZ,SETSIZ,
     1             ERRIND, INQSIZ,INQSET, EXQSIZ,EXQSET)

      INCSET(1) = 0
      INCSET(2) = NANAMS-1
      EXCSET(2) = 0
      EXCSET(1) = NANAMS-1
      INCSIZ = 2
      EXCSIZ = 2

      CALL IFPF (ERRIND .EQ. 0                  .AND.
     1           INQSIZ .EQ. INCSIZ             .AND.
     2           EXQSIZ .EQ. EXCSIZ             .AND.
     3           SETEQ (INCSIZ, INCSET, INQSET) .AND.
     4           SETEQ (EXCSIZ, EXCSET, EXQSET) )


      CALL SETMSG ('2 3', 'Immediately after re-opening the '         //
     1             'workstation, the highlighting filter inclusion '  //
     2             'and exclusion sets should be null.')

      CALL PCLWK (WKID)
      CALL POPWK (WKID, CONID, WTYPE)

C  <inquire highlighting filter>
      CALL PQHLFT (WKID, SETSIZ,SETSIZ,
     1             ERRIND, INQSIZ,INQSET, EXQSIZ,EXQSET)

C  pass/fail depending on (inclusion = null and
C                          exclusion = null)
      CALL IFPF (ERRIND .EQ. 0  .AND.
     1           INQSIZ .EQ. 0  .AND.
     2           EXQSIZ .EQ. 0)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
