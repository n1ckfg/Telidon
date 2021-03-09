      SUBROUTINE CSSPTH

C  Csspth sets up the "standard" CSS network for testing
C  ancestor and descendant paths.

C  Use <open structure> and <execute structure> to set up
C  the CSS as follows:
C
C                   101        106       108
C                  / | \       /
C                 /  |  \    1/
C               1/  2|  3\   /
C               /    |    \ /
C              /     |    107
C             /      |
C          102      103
C          | \      / \\
C          |  \   1/   \\
C         1|  2\  /    2\\3
C          |    \/       \\
C          |    104      105
C          |     |      /
C          |    1|    1/
C           \    |    /
C            \   |   /
C             \  |  /
C              \ | /
C               109

      CALL POPST (101)
      CALL PEXST (102)
      CALL PEXST (103)
      CALL PEXST (107)
      CALL PCLST

      CALL POPST (102)
      CALL PEXST (109)
      CALL PEXST (104)
      CALL PCLST

      CALL POPST (103)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PEXST (105)
      CALL PCLST

      CALL POPST (104)
      CALL PEXST (109)
      CALL PCLST

      CALL POPST (105)
      CALL PEXST (109)
      CALL PCLST

      CALL POPST (106)
      CALL PEXST (107)
      CALL PCLST

      CALL POPST (108)
      CALL PCLST

      END
