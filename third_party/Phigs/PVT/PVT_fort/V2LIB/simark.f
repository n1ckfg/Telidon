      SUBROUTINE SIMARK (MKST, COLI, MKRAD, CX,CY)

C  SIMARK uses polyline to simulate markers of various styles.
C
C  Input parameters:
C    MKST   : Marker style (either plus, asterick, or circle)
C    COLI   : Color to be used in simulation = index #1
C    MKRAD  : Marker radius in WC
C    CX,CY  : Marker center in WC

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

      INTEGER    MKST, NOSEG, SIZ, COLI
      REAL       MKRAD, CX,CY, XA(60),YA(60), PI, ANG,ANG2
      PARAMETER (PI = 3.14159265)
      CHARACTER  MSG*100

C  use ASFs individual
      CALL SETASF (PINDIV)
C  use polyline to simulate polymarker
      CALL PSLN   (PLSOLI)
      CALL PSPLCI (COLI)
      CALL PSLWSC (0.0)

      IF (MKST .EQ. PPLUS) THEN
C  simulate plus
         XA(1) = CX - MKRAD
         XA(2) = CX + MKRAD
         YA(1) = CY
         YA(2) = CY
         CALL PPL (2, XA,YA)
         XA(1) = CX
         XA(2) = CX
         YA(1) = CY + MKRAD
         YA(2) = CY - MKRAD
         CALL PPL (2, XA,YA)
      ELSEIF (MKST .EQ. PAST) THEN
C simulate asterisk
         DO 100 SIZ = 0,2
            ANG   = SIZ * PI / 3
            XA(1) = CX + MKRAD * COS(ANG)
            YA(1) = CY + MKRAD * SIN(ANG)
            ANG2  = ANG + PI
            XA(2) = CX + MKRAD * COS(ANG2)
            YA(2) = CY + MKRAD * SIN(ANG2)
            CALL PPL (2,XA,YA)
100      CONTINUE
      ELSEIF (MKST .EQ. POMARK) THEN
C mkst = 4, simulate circle
         NOSEG = 40
         DO 200 SIZ = 1, NOSEG+1
            ANG = SIZ * 2 * PI / NOSEG
            XA(SIZ) = CX + MKRAD * COS(ANG)
            YA(SIZ) = CY + MKRAD * SIN(ANG)
200      CONTINUE
         CALL PPL (NOSEG+1, XA, YA)
      ELSE
C  invalid marker type
         WRITE (MSG, '(A,I5,A)') 'Invalid marker style passed ' //
     1         'to SIMARK: ', MKST, '.'
         CALL UNMSG (MSG)
      ENDIF

      END
