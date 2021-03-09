      SUBROUTINE SETPCL (PCCTAB)

C  SETPCL: loads the pcctab table with the names of the picture
C  change categories.

      CHARACTER  PCCTAB(17)*34

      PCCTAB(01) = 'polyline bundle representation'
      PCCTAB(02) = 'polymarker bundle representation'
      PCCTAB(03) = 'text bundle representation'
      PCCTAB(04) = 'interior bundle representation'
      PCCTAB(05) = 'edge bundle representation'
      PCCTAB(06) = 'pattern representation'
      PCCTAB(07) = 'colour representation'
      PCCTAB(08) = 'view representation'
      PCCTAB(09) = 'workstation transformation'
      PCCTAB(10) = 'highlighting filter'
      PCCTAB(11) = 'invisibility filter'
      PCCTAB(12) = 'HLHSR mode'
      PCCTAB(13) = 'structure content'
      PCCTAB(14) = 'post structure'
      PCCTAB(15) = 'unpost structure'
      PCCTAB(16) = 'delete structure'
      PCCTAB(17) = 'reference modification'

      END
