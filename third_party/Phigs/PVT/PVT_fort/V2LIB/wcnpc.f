      SUBROUTINE WCNPC (WCX,WCY, NPCX,NPCY, NPCPWC)

C  WCNPC converts a 2D point in WC to the equivalent point in NPC
C  within view#1 for the picture area, which maps 0:1,0:1 (WC) to
C  PICL:PICR, PICB:PICT (NPC).  It also returns the NPC/WC ratio.

      COMMON /SCRFMT/ PICL,PICR,PICB,PICT, PRTL,PRTR,PRTB,PRTT,
     1                ECHL,ECHR,ECHB,ECHT
      REAL            PICL,PICR,PICB,PICT, PRTL,PRTR,PRTB,PRTT,
     1                ECHL,ECHR,ECHB,ECHT

      REAL    WCX,WCY, NPCX,NPCY, NPCPWC

      NPCX = WCX * (PICR-PICL) + PICL
      NPCY = WCY * (PICT-PICB) + PICB
      NPCPWC = PICT-PICB

      END
