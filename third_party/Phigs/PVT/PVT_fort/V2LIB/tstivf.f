      SUBROUTINE TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C  TSTIVF tests that the appropriate primitives are invisible for
C  a given inclusion and exclusion set used as the invisibility
C  filter.

C  Input parameters:
C    WKID          : workstation identifier
C    INCSIZ,INCSET : inclusion set
C    EXCSIZ,EXCSET : exclusion set

      INTEGER  WKID, INCSIZ,INCSET(*), EXCSIZ,EXCSET(*)
      INTEGER  TRUSIZ,TRULIS(8)

C  <set invisibility filter>:
      CALL PSIVFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  Compute expected subset of invisible primitives from incl,excl
      CALL ELGPRM (INCSIZ,INCSET, EXCSIZ,EXCSET, TRUSIZ,TRULIS)

      CALL DLSTPF ('INVISIBILITY FILTER: Which primitives are ' //
     1             'invisible (n if none)?', TRUSIZ, TRULIS, 'S')

      END
