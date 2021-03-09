      SUBROUTINE ELGPRM (INCSIZ,INCSET, EXCSIZ,EXCSET, TRUSIZ,TRULIS)

C  Subroutine ELGPRM determines the eligible primitives for the
C  given inclusion and exclusion set. The eligible primitives are
C  returned in TRULIS.

C  Input parameters:
C    INCSIZ,INCSET : inclusion set
C    EXCSIZ,EXCSET : exclusion set
C  Output parameters:
C    TRUSIZ,TRULIS : list of eligible primitives

      INTEGER INCSIZ,INCSET(*), EXCSIZ,EXCSET(*), TRUSIZ,TRULIS(*)

      INTEGER SVAL, IX, PRIMID, LIST(8)

C   Check the include and exclude sets to determine which
C   of the following primitives will be highlighted.

C   position  primitive        color   nameset
C     1       polyline           1      0, 1, 2
C     2       polymarker         2      3, 4, 5
C     3       fill area          3      6, 7, 8
C     4       cell array         4      9,10,11
C     5       text               1     12,13,14
C     6       polyline 3         2     15,16,17
C     7       annotation text    3     18,19,20
C     8       fill area set      4     21,22,23

C   First check the inclusion set, include any primitive that
C   appears, then check the exclusion set, removing any primitive
C   that appears, the set we are left with are the eligible ones.
C   Names outside of 0-23 are ignored.

      CALL SETVAL ('0,0,0,0,0,0,0,0', LIST)

      DO 100 IX = 1,INCSIZ
         SVAL = INCSET(IX)
         IF (SVAL.GE.0 .AND. SVAL.LE.23) THEN
            PRIMID = SVAL/3 + 1
            LIST(PRIMID) =  1
         ENDIF
  100 CONTINUE

      DO 110 IX = 1,EXCSIZ
         SVAL = EXCSET(IX)
         IF (SVAL.GE.0 .AND. SVAL.LE.23) THEN
            PRIMID = SVAL/3 + 1
            LIST(PRIMID) =  0
         ENDIF
  110 CONTINUE

      TRUSIZ = 0
      DO 120 IX = 1,8
         IF (LIST(IX) .EQ. 1) THEN
            TRUSIZ = TRUSIZ + 1
            TRULIS(TRUSIZ) = IX
         ENDIF
  120 CONTINUE

      END
