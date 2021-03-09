      SUBROUTINE INTINH (ASFTAB, START, END, PERM)

C  INTINH creates the structure network for testing interior ASFs.

C  Input parameters:
C    ASFTAB    : table containing ASF values
C    START,END : first,last column in the table (corresponding to aspect
C                identifier) from which values are taken.
C  Output parameters:
C    PERM      : permutation of locations used for structure network

C aspect identifier
      INTEGER    PLN,      PEDFG,    PEDCI
      PARAMETER (PLN  = 0, PEDFG=14, PEDCI=17)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER    START,END, ASFTAB(5, PLN:PEDCI), PERM(14), ERRIND
      INTEGER    IX, EXPDX(14), SIZ

      REAL       XACT(4),XEXP(4),XFORM(3,3), YLOCEL

C  x-location of actual/expected interiors
      CALL SETRVS ('0.2,0.2,0.5,0.5', XACT, SIZ)
      CALL SETRVS ('0.6,0.6,0.9,0.9', XEXP, SIZ)

C  randomize order of interiors
      CALL RN1SHF (14, PERM)

C  set edge flag = OFF
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (POFF)

C  set up CSS as described above
      CALL LOCINT (PERM(1), XACT)
      CALL PEXST  (102)
      CALL LOCINT (PERM(9), XACT)
      CALL ASFSET (2, ASFTAB, START,END)
      CALL LOCINT (PERM(10), XACT)
      CALL XFINH  (PERM)

C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCINT (PERM(13), XACT)
      CALL LOCINT (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCINT (PERM(2), XACT)
      CALL ASFSET (3, ASFTAB, START,END)
      CALL PEXST (103)
      CALL LOCINT (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCINT (PERM(3), XACT)
      CALL ASFSET (4, ASFTAB, START,END)
      CALL LOCINT (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCINT (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCINT (PERM(5), XACT)
      CALL ASFSET (5, ASFTAB, START,END)
C  polymarker 6 / 12
      CALL LOCINT (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for expected ASFs:
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,4', EXPDX)
      DO 400 IX =1,14
         CALL ASFSET (EXPDX(IX), ASFTAB, START,END)
         CALL LOCINT (PERM(IX), XEXP)
400   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      END
