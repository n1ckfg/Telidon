      SUBROUTINE TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C  TSTHLF tests that the appropriate primitives are highlighted for
C  a given inclusion and exclusion set used as the highlighting
C  filter.

C  Input parameters:
C    WKID          : workstation identifier
C    INCSIZ,INCSET : inclusion set
C    EXCSIZ,EXCSET : exclusion set

      INTEGER  WKID, INCSIZ,INCSET(*), EXCSIZ,EXCSET(*)
      INTEGER  TRUSIZ,TRULIS(8)

C  <set highlighting filter>:
      CALL PSHLFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  Compute expected subset of highlighted primitives from incl,excl
      CALL ELGPRM (INCSIZ,INCSET, EXCSIZ,EXCSET, TRUSIZ,TRULIS)

      CALL DLSTPF ('HIGHLIGHTING FILTER: For which pairs is the '  //
     1             'primitive on the left highlighted (n if none)?',
     2             TRUSIZ, TRULIS, 'S')

      END
