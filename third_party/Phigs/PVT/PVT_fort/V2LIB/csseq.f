      LOGICAL FUNCTION CSSEQ (CSSSHD)

C  CSSEQ accepts a character string parameter (cssshd = "CSS
C  should") which describes a CSS network and compares it to the CSS
C  state as reported by PHIGS inquire functions.  Csseq returns
C  .true. if they are equal, else .false.  The syntax of the input
C  string is:

C  cssshd             = path-list | blank
C  path-list          = path slash | path slash path-list
C  path               = path-element | path-element comma path
C  path-element       = structure-id comma element-reference
C  comma              = ","
C  slash              = "/"
C  blank              = " "
C  structure-id       = unsigned-integer
C  element-reference  = unsigned-integer

C  Spaces may appear anywhere.

C  Eg:  2,0/
C       2,3,4,0/
C       2, 3, 4, 0 / 2, 3, 5, 0 / 2, 3, 6, 0  /
C       20,0/30,0/40,0/
C       20,0/30,1,50,0/40,0/

C  If the CSS contains two networks:
C
C            10              110
C           /  \              |
C         20   30            120
C        /  \ /
C       40   50
C
C  it could be represented by:
C     "10,1,20,1,40,0/  10,1,20,2,50,0/  10,2,30,1,50,0/  110,3,120,0/"

C  A blank cssshd indicates an empty CSS

      CHARACTER  CSSSHD*(*)

C truncation method
      INTEGER    PHEAD,     PTAIL
      PARAMETER (PHEAD = 0, PTAIL = 1)

      INTEGER    PSIZE
      PARAMETER (PSIZE = 50)

      INTEGER    PATHSH(PSIZE, 50), PATHLN(PSIZE), ROOT(PSIZE)
      INTEGER    ERPATH (2,PSIZE), STRID
      INTEGER    APTHSZ, NUMPTH, IDUM, NDPATH, ISH, IR, IXPTH
      INTEGER    IEL, IPATH, NROOT, IEL1, IEL2, ERRIND

      LOGICAL    SINGLE

C interpret cssshd string into ragged 2D array of integers.
      CALL SET2D (CSSSHD, PSIZE, NUMPTH, PATHLN, PATHSH)

C now get all roots
      CALL GTROOT (NROOT, ROOT)

C Get all descendant paths of each root
      DO 300 IR = 1,NROOT
C structure ID of next root
         STRID = ROOT(IR)

C ndpath = how many descendant paths ?
         CALL PQPDE (STRID, PHEAD, 0, PSIZE, 0,
     1               ERRIND, NDPATH, IDUM, ERPATH)
         CALL CHKINQ ('pqpde', ERRIND)

C for singleton root, gotta force path of length 1
         SINGLE = (NDPATH .EQ. 0)
         IF (SINGLE) NDPATH = 1

C retrieve each descendant path
         DO 400 IXPTH = 1, NDPATH
            IF (SINGLE) THEN
               APTHSZ = 1
               ERPATH (1,1) = STRID
               ERPATH (2,1) = 0
            ELSE
               CALL PQPDE (STRID, PHEAD, 0, PSIZE, IXPTH,
     1                     ERRIND, IDUM, APTHSZ, ERPATH)
               CALL CHKINQ ('pqpde', ERRIND)
            ENDIF

C look for a matching should-path
            DO 500 ISH = 1, NUMPTH
C - start by seeking matching length
               IF (2*APTHSZ .NE. PATHLN(ISH) ) GOTO 500
C lengths match - try contents
               DO 600 IEL = 1, APTHSZ
                  IEL2 = 2*IEL
                  IEL1 = IEL2-1
                  IF (PATHSH (IEL1, ISH) .NE. ERPATH(1, IEL)) GOTO 500
                  IF (PATHSH (IEL2, ISH) .NE. ERPATH(2, IEL)) GOTO 500
600            CONTINUE
C OK they matched - delete out that should-path to prevent re-use
               PATHLN(ISH) = -1
               GOTO 400
500         CONTINUE
C No should-path match found for path reported by PHIGS - fail
            CSSEQ = .FALSE.
            RETURN

C next descendant path from current root
400      CONTINUE

C next root structure
300   CONTINUE

C match has been found for every path returned by pqpde.
C Now, simply check that all expected paths have been "used" by CSS

      DO 700 IPATH = 1,NUMPTH
         IF (PATHLN (IPATH) .NE. -1) THEN
            CSSEQ = .FALSE.
            RETURN
         ENDIF
700   CONTINUE
      CSSEQ = .TRUE.

      END
