      SUBROUTINE DOIMOD (WKID, INCLAS, INMODE)

C  DOIMOD: on the workstation (wkid), sets device #1 of the
C  specified input class (inclas) to the requested mode (inmode).

C operating mode
C                request  sample    event
      INTEGER    PREQU,   PSAMPL,   PEVENT
      PARAMETER (PREQU=0, PSAMPL=1, PEVENT=2)
C echo switch
      INTEGER    PNECHO,   PECHO
      PARAMETER (PNECHO=0, PECHO=1)

      INTEGER   WKID, INCLAS, INMODE

      GOTO (10, 20, 30, 40, 50, 60), INCLAS
      CALL UNMSG ('Invalid input class passed to DOIMOD.')

10    CONTINUE
C     set locator mode
      CALL PSLCM (WKID, 1, INMODE, PNECHO)
      GOTO 100
20    CONTINUE
C     set stroke mode
      CALL PSSKM (WKID, 1, INMODE, PNECHO)
      GOTO 100
30    CONTINUE
C     set valuator mode
      CALL PSVLM (WKID, 1, INMODE, PNECHO)
      GOTO 100
40    CONTINUE
C     set choice mode
      CALL PSCHM (WKID, 1, INMODE, PNECHO)
      GOTO 100
50    CONTINUE
C     set pick mode
      CALL PSPKM (WKID, 1, INMODE, PNECHO)
      GOTO 100
60    CONTINUE
C     set string mode
      CALL PSSTM (WKID, 1, INMODE, PNECHO)
      GOTO 100

100   CONTINUE

      END
