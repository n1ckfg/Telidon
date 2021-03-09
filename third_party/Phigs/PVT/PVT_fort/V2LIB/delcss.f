      SUBROUTINE DELCSS

C  Delcss sets up the "standard" CSS network for module 02.01.02.02:

C  Use <open structure> and <execute structure> to set up
C  the CSS as follows:
C
C
C                  100
C                 /  \
C                /    \
C              1/      \2
C              /        \
C             /          \
C         101              102     120   130             140
C         | |             / | \     |    /|               |
C        1| |2           /  |  \    |   / |              1|
C         | |          1/  2|  3\  1|  /1 |2              |
C         | |          /    |    \  | /   |               |
C         103         /     |     \ |/    |              142
C                  104     105     106   107
C                  | |       |     |    / /\
C                 1| |2     /|\    |   / /  \
C                  | |    1/ | \3 1| 1/ /2   \3
C                  109    /  |  \  | / /      \
C                        /   |   \ |/ /       113
C                      110   |    108
C                            |     |
C                            |2    |1
C                            |     |
C                            |     |
C                            |    111
C                            |   / |
C                            | 1/  |
C                            | /  2|
C                            |/    |
C                           114   115

C The nodes of the graph (100 and above) represent structures, and the
C labelled edges are references to invoke (lower) structures.  The
C labels (1-3) represent the element position of the <execute structure>
C function within the calling structure.

C creation of structures

      CALL POPST (100)
      CALL PEXST (101)
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (101)
      CALL PEXST (103)
      CALL PEXST (103)
      CALL PCLST
      CALL POPST (102)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PEXST (106)
      CALL PCLST
      CALL POPST (120)
      CALL PEXST (106)
      CALL PCLST
      CALL POPST (130)
      CALL PEXST (106)
      CALL PEXST (107)
      CALL PCLST
      CALL POPST (140)
      CALL PEXST (142)
      CALL PCLST
      CALL POPST (104)
      CALL PEXST (109)
      CALL PEXST (109)
      CALL PCLST
      CALL POPST (105)
      CALL PEXST (110)
      CALL PEXST (114)
      CALL PEXST (108)
      CALL PCLST
      CALL POPST (106)
      CALL PEXST (108)
      CALL PCLST
      CALL POPST (107)
      CALL PEXST (108)
      CALL PEXST (108)
      CALL PEXST (113)
      CALL PCLST
      CALL POPST (108)
      CALL PEXST (111)
      CALL PCLST
      CALL POPST (111)
      CALL PEXST (114)
      CALL PEXST (115)
      CALL PCLST

      END
