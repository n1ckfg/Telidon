      SUBROUTINE RN1SHF (SIZ, PERM)

C  Incredibly special-purpose subroutine which returns a permutation in
C  PERM with the constraint that:
C
C     PERM(12) - PERM(11) = PERM(06) - PERM(05)
C
C  so as to force uniform scaling.  This is needed in inheritance tests
C  when displaying primitives with an intrinsic size, such as fill area
C  or text, as opposed to a single segment of a polyline or a single
C  polymarker.

      INTEGER    TMP, IX,IY, SIZ, PERM(*), SWVALS(4)
      INTEGER    LDX,HDX, SWLOC, IARFND, NEEDVL

      DATA       SWVALS / 5,6,11,12 /

      CALL RNPERM (SIZ, PERM)

C  put locations of 5,6,11,12 in ascending order
      DO 200 IX = 1,3
      DO 300 IY = IX+1,4
         LDX = SWVALS(IX)
         HDX = SWVALS(IY)
         IF (PERM(LDX) .GT. PERM(HDX)) THEN
            TMP = PERM(LDX)
            PERM(LDX) = PERM(HDX)
            PERM(HDX) = TMP
         ENDIF
300   CONTINUE
200   CONTINUE

C  switch values for shortest interval
      IF (PERM(6)-PERM(5) .LT. PERM(12)-PERM(11)) THEN
C  switch contents of PERM(11) with needed value
         NEEDVL = PERM(12) + PERM(5) - PERM(6)
         SWLOC = 11
      ELSE
C  switch contents of PERM(5) with needed value
         NEEDVL = PERM(11) + PERM(6) - PERM(12)
         SWLOC = 5
      ENDIF

      PERM(IARFND(NEEDVL,SIZ,PERM)) = PERM(SWLOC)
      PERM(SWLOC) = NEEDVL

      END
