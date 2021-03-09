      SUBROUTINE SETFIL (FILT, FLN, FLISX,FLIS, FLESX,FLES)

C  SETFIL translates the character version of a filter list into the
C  appropriate integer arrays.

      INTEGER     FLN, FLISX(*),FLIS(*), FLESX(*),FLES(*)

C  Declaration of COLLEN and WORK allows for a filter list with 55
C  filters, each with an inclusion set and exclusion set of up to 20
C  members.  Generated test case from P07 uses at most 50 filters.
      INTEGER     NUMCOL, COLLEN(110), WORK(20,110)
      INTEGER     ITOT,ETOT, FLTDX,ELDX, ICOL,ECOL

      CHARACTER   FILT*(*)

      CALL SET2D (FILT, 20, NUMCOL, COLLEN, WORK)
      FLN = NUMCOL/2
      IF (FLN*2 .NE. NUMCOL) THEN
         CALL UNMSG ('Illegal filter list passed to SETFIL.')
      ENDIF

      ITOT = 0
      ETOT = 0
      DO 100 FLTDX = 1,FLN
         ICOL = 2*FLTDX - 1
         ECOL = 2*FLTDX

C  inclusion set
         DO 200 ELDX = 1,COLLEN(ICOL)
            ITOT = ITOT+1
            FLIS(ITOT) = WORK(ELDX, ICOL)
200      CONTINUE
         FLISX(FLTDX) = ITOT

C  exclusion set
         DO 300 ELDX = 1,COLLEN(ECOL)
            ETOT = ETOT+1
            FLES(ETOT) = WORK(ELDX, ECOL)
300      CONTINUE
         FLESX(FLTDX) = ETOT
100   CONTINUE

      END
