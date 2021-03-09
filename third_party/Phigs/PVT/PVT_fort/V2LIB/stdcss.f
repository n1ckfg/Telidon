      SUBROUTINE STDCSS

C  Stdcss sets up a "standard" CSS network for several of the PVT
C  tests.  <Open structure> and <execute structure> set up the CSS
C  network as follows:


C                  100
C                 /  \
C                /    \
C              1/      \2
C              /        \
C             /          \
C         101              102     120   130             140
C          |              / | \     |    /|               |
C          |2            /  |  \    |   / |              1|
C          |           1/  2|  5\  2|  /3 |5              |
C          |           /    |    \  | /   |               |
C         103         /     |     \ |/    |              142
C                  104     105     106   107
C                  | |       |     |    / /\
C                 2| |5     /|\    |   / /  \
C                  | |    1/ | \2 1| 1/ /4   \5
C                  109    /  |  \  | / /      \
C                        /   |   \ |/ /       113
C                      110   |    108
C                            |     |
C                            |3    |2
C                            |     |
C                            |     |
C                            |    111
C                            |   / |
C                            |  /  |
C                            |1/  3|
C                            |/    |
C                           114   115

C  The nodes of the graph between (100 and 200) represent structures,
C  and the labelled edges are references to invoke (lower)
C  structures.  The labels (1-5) represent the element position of
C  the <execute structure> function within the calling structure.

C  <Execute structure> and <label> are the structure elements of the
C  individual structures contained in the network.  The values
C  between 100 and 199, inclusive, represent structures associated
C  with <execute structure> and the values between 900 and 999
C  represent label identifiers for <label>.

C open-structure status    none,        open
      INTEGER              PNONST,      POPNST
      PARAMETER           (PNONST = 0,  POPNST = 1)

C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)

      INTEGER EDMODE, STYPE, STRID, ERRIND

      CALL PQEDM (ERRIND, EDMODE)
      IF (ERRIND.EQ.0 .AND. EDMODE.EQ.PINSRT) THEN
C        lovely
      ELSE
         CALL UNMSG ('STDCSS invoked with edit-mode not = INSERT')
      ENDIF

C close any structure left opened
      CALL PQOPST (ERRIND, STYPE, STRID)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .EQ. POPNST) CALL PCLST

C delete old CSS
      CALL PDAS

      CALL POPST (100)
      CALL PEXST (101)
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (101)
      CALL PLB (902)
      CALL PEXST (103)
      CALL PLB (960)
      CALL PCLST

      CALL POPST (102)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PLB (900)
      CALL PLB (901)
      CALL PEXST (106)
      CALL PCLST

      CALL POPST (120)
      CALL PLB (907)
      CALL PEXST (106)
      CALL PCLST

      CALL POPST (130)
      CALL PLB (910)
      CALL PLB (912)
      CALL PEXST (106)
      CALL PLB (914)
      CALL PEXST (107)
      CALL PCLST

      CALL POPST (140)
      CALL PEXST (142)
      CALL PCLST

      CALL POPST (104)
      CALL PLB (920)
      CALL PEXST (109)
      CALL PLB (925)
      CALL PLB (926)
      CALL PEXST (109)
      CALL PCLST

      CALL POPST (105)
      CALL PEXST (110)
      CALL PEXST (108)
      CALL PEXST (114)
      CALL PLB (950)
      CALL PCLST

      CALL POPST (106)
      CALL PEXST (108)
      CALL PCLST

      CALL POPST (107)
      CALL PEXST (108)
      CALL PLB (930)
      CALL PLB (935)
      CALL PEXST (108)
      CALL PEXST (113)
      CALL PCLST

      CALL POPST (108)
      CALL PLB (961)
      CALL PEXST (111)
      CALL PCLST

      CALL POPST (111)
      CALL PEXST (114)
      CALL PLB (940)
      CALL PEXST (115)
      CALL PLB (942)
      CALL PLB (916)
      CALL PLB (947)
      CALL PLB (955)
      CALL PLB (947)
      CALL PLB (955)
      CALL PLB (940)
      CALL PLB (947)
      CALL PCLST

      CALL POPST (113)
      CALL PLB (901)
      CALL PCLST

      CALL POPST (114)
      CALL PLB (901)
      CALL PCLST

      CALL POPST (115)
      CALL PLB (901)
      CALL PCLST

      END
