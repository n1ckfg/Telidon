      LOGICAL FUNCTION SPHDIS (STRID)

C  SPHDIS determines whether this implementation uses "spherical" or
C  "cubic" distance metric for purposes of ISS.  Based on fact that between
C  (0,0) and (.85,.85), the "spherical" distance = 1.202 but the "cubic"
C  distance = 0.85.

C  Input parameter:
C    STRID: available structure ID

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER   SPATH(2,1), FPATH(2,10), STRID, ERRIND, FPTHSZ
      INTEGER   IDUM(1)
      REAL      XA(1),YA(1)
      CHARACTER MSG*200

      CALL POPST (STRID)
      CALL PEMST (STRID)
      XA(1) = 0.85
      YA(1) = 0.85
      CALL PPL (1, XA,YA)
      CALL PCLST

      SPATH (1,1) = STRID
      SPATH (2,1) = 0
C  search distance of 1.0 should find marker for cubic, but not for spherical
      CALL PISS  (0.,0., 1.0, 1, SPATH, PNCLIP, 1,
     1            0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            10, ERRIND, FPTHSZ, FPATH)

      CALL PEMST (STRID)

      IF (ERRIND .NE. 0) THEN
         WRITE (MSG, '(A,I6)') 'ISS in SPHDIS returned error ' //
     1                         'indicator = ', ERRIND
         CALL UNMSG (MSG)
      ENDIF

      SPHDIS = FPTHSZ.EQ.0

      END
