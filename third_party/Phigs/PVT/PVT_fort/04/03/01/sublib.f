C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.01/asfset                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ASFSET (ASFIX, ASFTAB, START, END)

C  ASFSET is used to set a sequence of ASFs to values specified in
C  an indicated row of the ASF table.

C  Input parameters:
C    ASFIX     : the row (1-5) of the table from which values are taken
C    ASFTAB    : table containing ASF values
C    START,END : first,last column in the table (corresponding to aspect
C                identifier) from which values are taken.

C aspect identifier
      INTEGER    PLN,      PEDCI
      PARAMETER (PLN  = 0, PEDCI=17)

      INTEGER    ASFIX, IX, START, END, ASFTAB(5, PLN:PEDCI)

      DO 100 IX = START,END
         CALL PSIASF (IX, ASFTAB(ASFIX, IX))
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.01/asfint                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ASFINT (VIS, VISI, VICI, NUMLIN, NGPRIM)

C  ASFINT draws a set of fill areas and fill area sets to illustrate
C  the effect of various interior aspect source flags.

C  Input parameters:
C    VIS    : interior style to be displayed/suppressed
C    VISI   : interior style index to be displayed/suppressed
C    VICI   : interior color index to be displayed/suppressed
C    NUMLIN : number of primitives to display
C  Output parameters:
C    NGPRIM : which primitive is drawn differently

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

C aspect identifier
      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)
C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C aspect visibility
      INTEGER    DISPLY,     SUPPRS
      PARAMETER (DISPLY = 0, SUPPRS = 1)

      INTEGER    VIS  (DISPLY:SUPPRS), NPTS(1), IBSW, IPRIM, NEXT
      INTEGER    VISI (DISPLY:SUPPRS), VICI (DISPLY:SUPPRS)
      INTEGER    IX, NUMLIN,NGPRIM, RNDINT, STYSRC,IIXSRC,COLSRC
      INTEGER    P1(10),P2(10),P3(10)

      REAL       XA(10),YA(10),ZA(10), YTOP,YLOC,YINCR

C  use IBSW to switch individual/bundled
      IBSW = PINDIV+PBUNDL
C  primitive to be drawn incorrectly
      NGPRIM = RNDINT (1,NUMLIN)
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1-YINCR
      YLOC = YTOP
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      IPRIM = 1
      XA(1) = 0.2
      XA(2) = 0.2
      XA(3) = 0.8
      XA(4) = 0.8
      ZA(1) = 0.5
      ZA(2) = 0.5
      ZA(3) = 0.5
      ZA(4) = 0.5
C  set edge flag = OFF
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (POFF)
      NPTS(1) = 4
C  ensure both individual and bundle are picked for each aspect
      CALL RNPERM (NUMLIN, P1)
      CALL RNPERM (NUMLIN, P2)
      CALL RNPERM (NUMLIN, P3)

C  loop to draw primitives
      DO 100 IX = 1,NUMLIN
C  randomly pick source for aspects:
         STYSRC = MOD (P1(IX), 2)
         IIXSRC = MOD (P2(IX), 2)
         COLSRC = MOD (P3(IX), 2)

C  set bundle #ix to displayed aspects, for BUNDLED source
C               and suppressed aspects, for INDIVIDUAL source
         CALL PSIR (WKID, IX, VIS(STYSRC), VISI(IIXSRC), VICI(COLSRC))
         CALL PSII (IX)
C  set individual attributes
C                    to displayed aspects, for INDIVIDUAL source
C                  and suppressed aspects, for BUNDLED source
         CALL PSIS  (VIS (IBSW-STYSRC))
         CALL PSISI (VISI(IBSW-IIXSRC))
         CALL PSICI (VICI(IBSW-COLSRC))
C  set ASF flags in accordance with: stysrc, iixsrc, colsrc
         CALL PSIASF (PIS,  STYSRC)
         CALL PSIASF (PISI, IIXSRC)
         CALL PSIASF (PICI, COLSRC)

         IF (IX .EQ. NGPRIM) THEN
C  set ASF flag NOT in accordance with typsrc
            CALL PSIASF (PIS,  IBSW-STYSRC)
            CALL PSIASF (PISI, IBSW-IIXSRC)
            CALL PSIASF (PICI, IBSW-COLSRC)
            NEXT = IPRIM
         ELSE
            NEXT = IPRIM+1
         ENDIF

         YA(1) = YLOC + 0.3*YINCR
         YA(2) = YLOC - 0.3*YINCR
         YA(3) = YLOC - 0.3*YINCR
         YA(4) = YLOC + 0.3*YINCR

         IF (IPRIM .EQ. 1) THEN
            CALL PFA (4, XA,YA)
         ELSEIF (IPRIM .EQ. 2) THEN
            CALL PFA3 (4, XA,YA,ZA)
         ELSEIF (IPRIM .EQ. 3) THEN
            CALL PFAS (1, NPTS, XA,YA)
         ELSEIF (IPRIM .EQ. 4) THEN
            CALL PFAS3 (1, NPTS, XA,YA,ZA)
         ELSE
            CALL PFA (4, XA,YA)
         ENDIF
         YLOC = YLOC-YINCR
         IPRIM = NEXT

C  next ix
100   CONTINUE
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.01/intinh                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE INTINH (ASFTAB, START, END, PERM)

C  INTINH creates the structure network for testing interior ASFs.

C  Input parameters:
C    ASFTAB    : table containing ASF values
C    START,END : first,last column in the table (corresponding to aspect
C                identifier) from which values are taken.
C  Output parameters:
C    PERM      : permutation of locations used for structure network

C aspect identifier
      INTEGER    PLN,      PEDFG,    PEDCI
      PARAMETER (PLN  = 0, PEDFG=14, PEDCI=17)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER    START,END, ASFTAB(5, PLN:PEDCI), PERM(14), ERRIND
      INTEGER    IX, EXPDX(14), SIZ

      REAL       XACT(4),XEXP(4),XFORM(3,3), YLOCEL

C  x-location of actual/expected interiors
      CALL SETRVS ('0.2,0.2,0.5,0.5', XACT, SIZ)
      CALL SETRVS ('0.6,0.6,0.9,0.9', XEXP, SIZ)

C  randomize order of interiors
      CALL RN1SHF (14, PERM)

C  set edge flag = OFF
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (POFF)

C  set up CSS as described above
      CALL LOCINT (PERM(1), XACT)
      CALL PEXST  (102)
      CALL LOCINT (PERM(9), XACT)
      CALL ASFSET (2, ASFTAB, START,END)
      CALL LOCINT (PERM(10), XACT)
      CALL XFINH  (PERM)

C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCINT (PERM(13), XACT)
      CALL LOCINT (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCINT (PERM(2), XACT)
      CALL ASFSET (3, ASFTAB, START,END)
      CALL PEXST (103)
      CALL LOCINT (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCINT (PERM(3), XACT)
      CALL ASFSET (4, ASFTAB, START,END)
      CALL LOCINT (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCINT (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCINT (PERM(5), XACT)
      CALL ASFSET (5, ASFTAB, START,END)
C  polymarker 6 / 12
      CALL LOCINT (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for expected ASFs:
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,4', EXPDX)
      DO 400 IX =1,14
         CALL ASFSET (EXPDX(IX), ASFTAB, START,END)
         CALL LOCINT (PERM(IX), XEXP)
400   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      END
