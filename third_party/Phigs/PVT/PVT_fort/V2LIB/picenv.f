      SUBROUTINE PICENV (WKID)

C  PICENV: sets up an environment of posted structures to the
C  specified workstation, so that PICCHG can be perform requested
C  changes.

C  Structure Conventions:
C
C  #101 is posted and contains a polyline, polymarker, text,
C       fill-area-set to exercise primitive representation changes
C       (PCC 1-7).
C
C  #201 is posted with lines fanning out from the bottom,
C       available for element deletion (PCC 13).
C
C  #301-350 are posted each with line fanning out from the top,
C       available for unposting or structure deletion (PCC 15-16)
C
C  #400,401,402 is a small network, with 400 executing either 401 or
C       402, available for <change structure references> (PCC 17).
C       401 has a 60-deg line, 402 a 150-deg line.
C
C  PCC 8-12, 14 require no additional environment.  PCC 14 will post
C  a new structure 5xx, with vertical lines.

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER   WKID, ENDPTS(2), IX, LIM2, NAMSET(5), ATTRIB

      REAL      IMAT(3,3), VCLIP(4), PLX(2),PLY(2), PMX(1), PMY(1)
      REAL      FASX(6), FASY(6), ANG, PI
      PARAMETER (PI = 3.14159265)

      DATA VCLIP / 0.0, 1.0, 0.0, 1.0  /

      DATA PLX   / 0.3,0.7 /, PMX /0.08/
      DATA PLY   / 0.7,0.3 /, PMY /0.08/

      DATA FASX   / 0.1, 0.2, 0.3, 0.7, 0.8, 0.9 /
      DATA FASY   / 0.1, 0.3, 0.1, 0.9, 0.7, 0.9 /
      DATA ENDPTS / 3,6 /

C first, clear the decks
      CALL PDAS

C set up 101 with bundled primitives
      CALL POPST (101)
      DO 100 ATTRIB = 0,17
         CALL PSIASF (ATTRIB, PBUNDL)
100   CONTINUE
C use entry #1 in all bundles. This is the default, except for view,
C which must be set explicitly.
      CALL PSVWI (1)
      CALL IDMAT (3, IMAT)
C set up view #1 like default
      CALL PSVWR (WKID, 1, IMAT,IMAT, VCLIP, PCLIP)
      CALL PPL (2, PLX,PLY)
      CALL PPM (1, PMX,PMY)
C potential highlight: filter = [1]
      NAMSET(1) = 1
      CALL PADS (1, NAMSET)
      CALL PSCHH (0.1)
      CALL PTX (0.15, 0.50, '?')
C potential invisibility: filter = [2]
      CALL PRES (1, NAMSET)
      NAMSET(1) = 2
      CALL PADS (1, NAMSET)
      CALL PFAS (2, ENDPTS, FASX,FASY)
      CALL PRES (1, NAMSET)
      CALL PCLST
      CALL PPOST (WKID, 101, 0.5)

C set up 201, posted, with lines fanning out from the bottom
      CALL POPST (201)
      PLX(1) = 0.5
      PLY(1) = 0.0
      LIM2 = 50
      DO 200 IX = 1,LIM2-1
         ANG = PI * IX / LIM2
         PLX(2) = PLX(1) + 0.3 * COS(ANG)
         PLY(2) = PLY(1) + 0.3 * SIN(ANG)
         CALL PPL (2, PLX,PLY)
200   CONTINUE
      CALL PCLST
      CALL PPOST (WKID, 201, 0.5)

C  set up 301-350, posted, each with line fanning out from the top
      PLX(1) = 0.5
      PLY(1) = 1.0
      LIM2 = 50
      DO 300 IX = 1,LIM2
         CALL POPST (300+IX)
         ANG = PI * IX / LIM2
         PLX(2) = PLX(1) + 0.3 * COS(ANG)
         PLY(2) = PLY(1) - 0.3 * SIN(ANG)
         CALL PPL (2, PLX,PLY)
         CALL PCLST
         CALL PPOST (WKID, 300+IX, 0.5)
300   CONTINUE

C  set up 400,401,402 as a small posted network, with 400
C  executing either 401 or 402.  401 has a 60-deg line, 402 a
C  150-deg line.
      CALL POPST (400)
      CALL PEXST (401)
      CALL PCLST
      CALL PPOST (WKID, 400, 0.5)

      PLX(1) = 0.5
      PLY(1) = SQRT(0.75)
      PLY(2) = 0.0

      CALL POPST (401)
      PLX(2) = 0.0
      CALL PPL (2, PLX,PLY)
      CALL PCLST

      CALL POPST (402)
      PLX(2) = 1.0
      CALL PPL (2, PLX,PLY)
      CALL PCLST

      END
