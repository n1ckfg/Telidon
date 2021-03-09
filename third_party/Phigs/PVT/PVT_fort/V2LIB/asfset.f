      SUBROUTINE ASFSET (ASFIX, ASFTAB, START, END)

C  ASFSET is used to set a sequence of ASFs to values specified in
C  an indicated row of the ASF table.

C  Input parameters:
C    ASFIX     : the row (1-5) of the table from which values are taken
C    ASFTAB    : table containing ASF values
C    START,END : first,last column in the table (corresponding to aspect
C                identifier) from which values are taken.

C aspect identifier
      INTEGER    PLN,      PEDCI
      PARAMETER (PLN  = 0, PEDCI=17)

      INTEGER    ASFIX, IX, START, END, ASFTAB(5, PLN:PEDCI)

      DO 100 IX = START,END
         CALL PSIASF (IX, ASFTAB(ASFIX, IX))
100   CONTINUE

      END
