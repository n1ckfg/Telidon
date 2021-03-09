      SUBROUTINE NDMW (REQMW, NOMMW)

C  NDMW attempts to set marker size to a requested value, but not
C  near the default (=1).
C
C  Input parameters:
C    REQMW       : requested marker size(WC)- actual will be no greater
C    NOMMW       : nominal marker size

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      REAL      REQMW, NOMMW, NDMWSC

C  get requested scale factor
      NDMWSC = REQMW / (NOMMW*WCPDC)

      IF (.95 .LT. NDMWSC .AND. NDMWSC .LT. 1.05) THEN
C  default near maximum requested - set down by 25%
         NDMWSC = 0.75 * NDMWSC
      ENDIF
      CALL PSMKSC (NDMWSC)

      END
