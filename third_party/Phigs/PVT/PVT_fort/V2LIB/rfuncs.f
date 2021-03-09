      SUBROUTINE RFUNCS ()

C  RFUNCS is the home of the entry points for PHIGS functions which
C  are called in order to generate an error.  The functions are
C  followed a wrapper routine which records what should have
C  happened.

C PHIGS function names (for those functions which signal error)
      INTEGER    EOPPH,      ECLPH,      EOPWK,      ECLWK
      PARAMETER (EOPPH =000, ECLPH =001, EOPWK =002, ECLWK =003)
      INTEGER    ERST,       EUWK,       ESDUS,      EMSG
      PARAMETER (ERST  =004, EUWK  =005, ESDUS =006, EMSG  =007)
      INTEGER    EPL3,       EPL,        EPM3,       EPM
      PARAMETER (EPL3  =008, EPL   =009, EPM3  =010, EPM   =011)
      INTEGER    ETX3,       ETX,        EATR3,      EATR
      PARAMETER (ETX3  =012, ETX   =013, EATR3 =014, EATR  =015)
      INTEGER    EFA3,       EFA,        EFAS3,      EFAS
      PARAMETER (EFA3  =016, EFA   =017, EFAS3 =018, EFAS  =019)
      INTEGER    ECA3,       ECA,        EGDP3,      EGDP
      PARAMETER (ECA3  =020, ECA   =021, EGDP3 =022, EGDP  =023)
      INTEGER    ESPLI,      ESPMI,      ESTXI,      ESII
      PARAMETER (ESPLI =024, ESPMI =025, ESTXI =026, ESII  =027)
      INTEGER    ESEDI,      ESLN,       ESLWSC,     ESPLCI
      PARAMETER (ESEDI =028, ESLN  =029, ESLWSC=030, ESPLCI=031)
      INTEGER    ESMK,       ESMKSC,     ESPMCI,     ESTXFN
      PARAMETER (ESMK  =032, ESMKSC=033, ESPMCI=034, ESTXFN=035)
      INTEGER    ESTXPR,     ESCHXP,     ESCHSP,     ESTXCI
      PARAMETER (ESTXPR=036, ESCHXP=037, ESCHSP=038, ESTXCI=039)
      INTEGER    ESCHH,      ESCHUP,     ESTXP,      ESTXAL
      PARAMETER (ESCHH =040, ESCHUP=041, ESTXP =042, ESTXAL=043)
      INTEGER    ESATCH,     ESATCU,     ESATP,      ESATAL
      PARAMETER (ESATCH=044, ESATCU=045, ESATP =046, ESATAL=047)
      INTEGER    ESANS,      ESIS,       ESISI,      ESICI
      PARAMETER (ESANS =048, ESIS  =049, ESISI =050, ESICI =051)
      INTEGER    ESEDFG,     ESEDT,      ESEWSC,     ESEDCI
      PARAMETER (ESEDFG=052, ESEDT =053, ESEWSC=054, ESEDCI=055)
      INTEGER    ESPA,       ESPRPV,     ESPARF,     EADS
      PARAMETER (ESPA  =056, ESPRPV=057, ESPARF=058, EADS  =059)
      INTEGER    ERES,       ESIASF,     ESPLR,      ESPMR
      PARAMETER (ERES  =060, ESIASF=061, ESPLR =062, ESPMR =063)
      INTEGER    ESTXR,      ESIR,       ESEDR,      ESPAR
      PARAMETER (ESTXR =064, ESIR  =065, ESEDR =066, ESPAR =067)
      INTEGER    ESCR,       ESHLFT,     ESIVFT,     ESCMD
      PARAMETER (ESCR  =068, ESHLFT=069, ESIVFT=070, ESCMD =071)
      INTEGER    ESHRID,     ESHRM,      ESLMT3,     ESLMT
      PARAMETER (ESHRID=072, ESHRM =073, ESLMT3=074, ESLMT =075)
      INTEGER    ESGMT3,     ESGMT,      ESMCV3,     ESMCV
      PARAMETER (ESGMT3=076, ESGMT =077, ESMCV3=078, ESMCV =079)
      INTEGER    ESMCLI,     ERMCV,      ESVWI,      ESVWR3
      PARAMETER (ESMCLI=080, ERMCV =081, ESVWI =082, ESVWR3=083)
      INTEGER    ESVWR,      ESVTIP,     ESWKW3,     ESWKW
      PARAMETER (ESVWR =084, ESVTIP=085, ESWKW3=086, ESWKW =087)
      INTEGER    ESWKV3,     ESWKV,      EOPST,      ECLST
      PARAMETER (ESWKV3=088, ESWKV =089, EOPST =090, ECLST =091)
      INTEGER    EEXST,      ELB,        EAP,        EGSE
      PARAMETER (EEXST =092, ELB   =093, EAP   =094, EGSE  =095)
      INTEGER    ESEDM,      ECELST,     ESEP,       EOSEP
      PARAMETER (ESEDM =096, ECELST=097, ESEP  =098, EOSEP =099)
      INTEGER    ESEPLB,     EDEL,       EDELRA,     EDELLB
      PARAMETER (ESEPLB=100, EDEL  =101, EDELRA=102, EDELLB=103)
      INTEGER    EEMST,      EDST,       EDSN,       EDAS
      PARAMETER (EEMST =104, EDST  =105, EDSN  =106, EDAS  =107)
      INTEGER    ECSTID,     ECSTRF,     ECSTIR,     EPOST
      PARAMETER (ECSTID=108, ECSTRF=109, ECSTIR=110, EPOST =111)
      INTEGER    EUPOST,     EUPAST,     EOPARF,     ECLARF
      PARAMETER (EUPOST=112, EUPAST=113, EOPARF=114, ECLARF=115)
      INTEGER    EARST,      EARSN,      EARAST,     ESCNRS
      PARAMETER (EARST =116, EARSN =117, EARAST=118, ESCNRS=119)
      INTEGER    ERSID,      EREST,      ERESN,      ERAST
      PARAMETER (ERSID =120, EREST =121, ERESN =122, ERAST =123)
      INTEGER    EREPAN,     EREPDE,     EDSTAR,     EDSNAR
      PARAMETER (EREPAN=124, EREPDE=125, EDSTAR=126, EDSNAR=127)
      INTEGER    EDASAR,     ESPKID,     ESPKFT,     EINLC3
      PARAMETER (EDASAR=128, ESPKID=129, ESPKFT=130, EINLC3=131)
      INTEGER    EINLC,      EINSK3,     EINSK,      EINVL3
      PARAMETER (EINLC =132, EINSK3=133, EINSK =134, EINVL3=135)
      INTEGER    EINVL,      EINCH3,     EINCH,      EINPK3
      PARAMETER (EINVL =136, EINCH3=137, EINCH =138, EINPK3=139)
      INTEGER    EINPK,      EINST3,     EINST,      ESLCM
      PARAMETER (EINPK =140, EINST3=141, EINST =142, ESLCM =143)
      INTEGER    ESSKM,      ESVLM,      ESCHM,      ESPKM
      PARAMETER (ESSKM =144, ESVLM =145, ESCHM =146, ESPKM =147)
      INTEGER    ESSTM,      ERQLC3,     ERQLC,      ERQSK3
      PARAMETER (ESSTM =148, ERQLC3=149, ERQLC =150, ERQSK3=151)
      INTEGER    ERQSK,      ERQVL,      ERQCH,      ERQPK
      PARAMETER (ERQSK =152, ERQVL =153, ERQCH =154, ERQPK =155)
      INTEGER    ERQST,      ESMLC3,     ESMLC,      ESMSK3
      PARAMETER (ERQST =156, ESMLC3=157, ESMLC =158, ESMSK3=159)
      INTEGER    ESMSK,      ESMVL,      ESMCH,      ESMPK
      PARAMETER (ESMSK =160, ESMVL =161, ESMCH =162, ESMPK =163)
      INTEGER    ESMST,      EWAIT,      EFLUSH,     EGTLC3
      PARAMETER (ESMST =164, EWAIT =165, EFLUSH=166, EGTLC3=167)
      INTEGER    EGTLC,      EGTSK3,     EGTSK,      EGTVL
      PARAMETER (EGTLC =168, EGTSK3=169, EGTSK =170, EGTVL =171)
      INTEGER    EGTCH,      EGTPK,      EGTST,      EWITM
      PARAMETER (EGTCH =172, EGTPK =173, EGTST =174, EWITM =175)
      INTEGER    EGTITM,     ERDITM,     EIITM,      ESERHM
      PARAMETER (EGTITM=176, ERDITM=177, EIITM =178, ESERHM=179)
      INTEGER    EESC,       EPREC,      EUREC
      PARAMETER (EESC  =180, EPREC =181, EUREC =182 )

      INTEGER  WKID, I1,I2,I3,I4,I5,I6,I7,I8, IA(*),IB(*)

      REAL     R1,R2,R3,R4, RA(*),RB(*),RC(*)
      REAL     XFA(3,3), XFB(3,3), VCLIP(*), XGA(4,4), XGB(4,4)

      CHARACTER  CHARS*(*)

C *** *** *** control *** *** ***

      ENTRY       ROPPH (I1, I2)
      CALL        POPPH (I1, I2)
      CALL ECHKZ (EOPPH)
      RETURN

      ENTRY       RCLPH
      CALL        PCLPH
      CALL ECHKZ (ECLPH)
      RETURN

      ENTRY       ROPWK (WKID, I1, I2)
      CALL        POPWK (WKID, I1, I2)
      CALL ECHKZ (EOPWK)
      RETURN

      ENTRY       ROPST (I1)
      CALL        POPST (I1)
      CALL ECHKZ (EOPST)
      RETURN

      ENTRY       RCLWK (WKID)
      CALL        PCLWK (WKID)
      CALL ECHKZ (ECLWK)
      RETURN

      ENTRY       RRST (WKID, I1)
      CALL        PRST (WKID, I1)
      CALL ECHKZ (ERST)
      RETURN

      ENTRY       RUWK (WKID, I1)
      CALL        PUWK (WKID, I1)
      CALL ECHKZ (EUWK)
      RETURN

      ENTRY       RSDUS (WKID, I1,I2)
      CALL        PSDUS (WKID, I1,I2)
      CALL ECHKZ (ESDUS)
      RETURN

C *** *** *** output primitives *** *** ***

      ENTRY       RPL3 (I1, RA,RB,RC)
      CALL        PPL3 (I1, RA,RB,RC)
      CALL ECHKZ (EPL3)
      RETURN

      ENTRY       RPL (I1, RA,RB)
      CALL        PPL (I1, RA,RB)
      CALL ECHKZ (EPL)
      RETURN

      ENTRY       RTX (R1, R2, CHARS)
      CALL        PTX (R1, R2, CHARS)
      CALL ECHKZ (ETX)
      RETURN

      ENTRY       RFA (I1, RA, RB)
      CALL        PFA (I1, RA, RB)
      CALL ECHKZ (EFA)
      RETURN

      ENTRY       RFA3 (I1, RA, RB, RC)
      CALL        PFA3 (I1, RA, RB, RC)
      CALL ECHKZ (EFA3)
      RETURN

      ENTRY       RPM (I1, RA, RB)
      CALL        PPM (I1, RA, RB)
      CALL ECHKZ (EPM)
      RETURN

      ENTRY       RATR (R1, R2, R3, R4, CHARS)
      CALL        PATR (R1, R2, R3, R4, CHARS)
      CALL ECHKZ (EATR)
      RETURN

      ENTRY       RFAS (I1, IA, RA, RB)
      CALL        PFAS (I1, IA, RA, RB)
      CALL ECHKZ (EFAS)
      RETURN

      ENTRY       RFAS3 (I1, IA, RA, RB, RC)
      CALL        PFAS3 (I1, IA, RA, RB, RC)
      CALL ECHKZ (EFAS3)
      RETURN

      ENTRY       RCA3 (RA,RB,RC,I1,I2,I3,I4,I5,I6,IA)
      CALL        PCA3 (RA,RB,RC,I1,I2,I3,I4,I5,I6,IA)
      CALL ECHKZ (ECA3)
      RETURN

      ENTRY       RCA (R1,R2,R3,R4,I1,I2,I3,I4,I5,I6,IA)
      CALL        PCA (R1,R2,R3,R4,I1,I2,I3,I4,I5,I6,IA)
      CALL ECHKZ (ECA)
      RETURN



C *** *** *** attributes *** *** ***

      ENTRY       RSPLR (WKID, I1,I2,R1,I3)
      CALL        PSPLR (WKID, I1,I2,R1,I3)
      CALL ECHKZ (ESPLR)
      RETURN

      ENTRY       RSPMR (WKID, I1,I2,R1,I3)
      CALL        PSPMR (WKID, I1,I2,R1,I3)
      CALL ECHKZ (ESPMR)
      RETURN

      ENTRY       RSTXP (I1)
      CALL        PSTXP (I1)
      CALL ECHKZ (ESTXP)
      RETURN

      ENTRY       RSTXAL (I1, I2)
      CALL        PSTXAL (I1, I2)
      CALL ECHKZ (ESTXAL)
      RETURN

      ENTRY       RSATAL (I1, I2)
      CALL        PSATAL (I1, I2)
      CALL ECHKZ (ESATAL)
      RETURN

      ENTRY       RSIS (I1)
      CALL        PSIS (I1)
      CALL ECHKZ (ESIS)
      RETURN

      ENTRY       RSII (I1)
      CALL        PSII (I1)
      CALL ECHKZ (ESII)
      RETURN

      ENTRY       RSMKSC (R1)
      CALL        PSMKSC (R1)
      CALL ECHKZ (ESMKSC)
      RETURN

      ENTRY       RSTXFN (I1)
      CALL        PSTXFN (I1)
      CALL ECHKZ (ESTXFN)
      RETURN

      ENTRY       RSANS (I1)
      CALL        PSANS (I1)
      CALL ECHKZ (ESANS)
      RETURN

      ENTRY       RSPARF (R1, R2)
      CALL        PSPARF (R1, R2)
      CALL ECHKZ (ESPARF)
      RETURN

      ENTRY       RSIR (WKID, I1,I2,I3,I4)
      CALL        PSIR (WKID, I1,I2,I3,I4)
      CALL ECHKZ (ESIR)
      RETURN

      ENTRY       RSPAR (WKID, I1,I2,I3,I4,I5,I6,I7,IA)
      CALL        PSPAR (WKID, I1,I2,I3,I4,I5,I6,I7,IA)
      CALL ECHKZ (ESPAR)
      RETURN

      ENTRY       RSTXR (WKID, I1,I2,I3,R1,R2,I4)
      CALL        PSTXR (WKID, I1,I2,I3,R1,R2,I4)
      CALL ECHKZ (ESTXR)
      RETURN

      ENTRY       RSEDI (I1)
      CALL        PSEDI (I1)
      CALL ECHKZ (ESEDI)
      RETURN

      ENTRY       RSEDCI (I1)
      CALL        PSEDCI (I1)
      CALL ECHKZ (ESEDCI)
      RETURN

      ENTRY       RSPLCI (I1)
      CALL        PSPLCI (I1)
      CALL ECHKZ (ESPLCI)
      RETURN

      ENTRY       RSTXCI (I1)
      CALL        PSTXCI (I1)
      CALL ECHKZ (ESTXCI)
      RETURN

      ENTRY       RSTXI (I1)
      CALL        PSTXI (I1)
      CALL ECHKZ (ESTXI)
      RETURN

      ENTRY       RSEDR (WKID, I1,I2,I3,R1,I4)
      CALL        PSEDR (WKID, I1,I2,I3,R1,I4)
      CALL ECHKZ (ESEDR)
      RETURN

      ENTRY       RSPLI (I1)
      CALL        PSPLI (I1)
      CALL ECHKZ (ESPLI)
      RETURN

      ENTRY       RSLN (I1)
      CALL        PSLN (I1)
      CALL ECHKZ (ESLN)
      RETURN

      ENTRY       RSPMCI (I1)
      CALL        PSPMCI (I1)
      CALL ECHKZ (ESPMCI)
      RETURN

      ENTRY       RSCHXP (R1)
      CALL        PSCHXP (R1)
      CALL ECHKZ (ESCHXP)
      RETURN

      ENTRY       RSEDFG (I1)
      CALL        PSEDFG (I1)
      CALL ECHKZ (ESEDFG)
      RETURN

C *** *** *** generic attributes *** *** ***

      ENTRY       RADS (I1, IA)
      CALL        PADS (I1, IA)
      CALL ECHKZ (EADS)
      RETURN

      ENTRY       RRES (I1, IA)
      CALL        PRES (I1, IA)
      CALL ECHKZ (ERES)
      RETURN

      ENTRY       RSIASF (I1, I2)
      CALL        PSIASF (I1, I2)
      CALL ECHKZ (ESIASF)
      RETURN

      ENTRY       RSHLFT (WKID, I1,IA, I2,IB)
      CALL        PSHLFT (WKID, I1,IA, I2,IB)
      CALL ECHKZ (ESHLFT)
      RETURN

      ENTRY       RSHRID (I1)
      CALL        PSHRID (I1)
      CALL ECHKZ (ESHRID)
      RETURN

      ENTRY       RSIVFT (WKID, I1,IA, I2,IB)
      CALL        PSIVFT (WKID, I1,IA, I2,IB)
      CALL ECHKZ (ESIVFT)
      RETURN

      ENTRY       RSCMD (WKID, I1)
      CALL        PSCMD (WKID, I1)
      CALL ECHKZ (ESCMD)
      RETURN

      ENTRY       RSCR (WKID, I1, I2, RA)
      CALL        PSCR (WKID, I1, I2, RA)
      CALL ECHKZ (ESCR)
      RETURN

      ENTRY       RSHRM (WKID, I1)
      CALL        PSHRM (WKID, I1)
      CALL ECHKZ (ESHRM)
      RETURN

C *** *** *** geometry *** *** ***

      ENTRY       RSVWR (WKID, I1, XFA,XFB,VCLIP, I2)
      CALL        PSVWR (WKID, I1, XFA,XFB,VCLIP, I2)
      CALL ECHKZ (ESVWR)
      RETURN

      ENTRY       RSWKW (WKID, R1,R2,R3,R4)
      CALL        PSWKW (WKID, R1,R2,R3,R4)
      CALL ECHKZ (ESWKW)
      RETURN

      ENTRY       RSWKW3 (WKID, RA)
      CALL        PSWKW3 (WKID, RA)
      CALL ECHKZ (ESWKW3)
      RETURN

      ENTRY       RSWKV3 (WKID, RA)
      CALL        PSWKV3 (WKID, RA)
      CALL ECHKZ (ESWKV3)
      RETURN

      ENTRY       RSWKV (WKID, R1,R2,R3,R4)
      CALL        PSWKV (WKID, R1,R2,R3,R4)
      CALL ECHKZ (ESWKV)
      RETURN

      ENTRY       RSGMT (XFA)
      CALL        PSGMT (XFA)
      CALL ECHKZ (ESGMT)
      RETURN

      ENTRY       RSVWR3 (WKID, I1, XGA, XGB, VCLIP, I2,I3,I4)
      CALL        PSVWR3 (WKID, I1, XGA, XGB, VCLIP, I2,I3,I4)
      CALL ECHKZ (ESVWR3)
      RETURN

      ENTRY       RSLMT (XFA, I1)
      CALL        PSLMT (XFA, I1)
      CALL ECHKZ (ESLMT)
      RETURN

      ENTRY       RSMCV (I1, I2, RA)
      CALL        PSMCV (I1, I2, RA)
      CALL ECHKZ (ESMCV)
      RETURN

      ENTRY       RSVWI (I1)
      CALL        PSVWI (I1)
      CALL ECHKZ (ESVWI)
      RETURN

      ENTRY       RSVTIP (WKID, I1,I2,I3)
      CALL        PSVTIP (WKID, I1,I2,I3)
      CALL ECHKZ (ESVTIP)
      RETURN

C *** *** *** structures *** *** ***

      ENTRY       RCLST
      CALL        PCLST
      CALL ECHKZ (ECLST)
      RETURN

      ENTRY       RLB (I1)
      CALL        PLB (I1)
      CALL ECHKZ (ELB)
      RETURN

      ENTRY       RSEP (I1)
      CALL        PSEP (I1)
      CALL ECHKZ (ESEP)
      RETURN

      ENTRY       REXST (I1)
      CALL        PEXST (I1)
      CALL ECHKZ (EEXST)
      RETURN

      ENTRY       RCELST (I1)
      CALL        PCELST (I1)
      CALL ECHKZ (ECELST)
      RETURN

      ENTRY       RDEL
      CALL        PDEL
      CALL ECHKZ (EDEL)
      RETURN

      ENTRY       RSEDM (I1)
      CALL        PSEDM (I1)
      CALL ECHKZ (ESEDM)
      RETURN

      ENTRY       REMST (I1)
      CALL        PEMST (I1)
      CALL ECHKZ (EEMST)
      RETURN

      ENTRY       RDSN (I1, I2)
      CALL        PDSN (I1, I2)
      CALL ECHKZ (EDSN)
      RETURN

      ENTRY       RCSTIR (I1, I2)
      CALL        PCSTIR (I1, I2)
      CALL ECHKZ (ECSTIR)
      RETURN

      ENTRY       RSCNRS (I1, I2)
      CALL        PSCNRS (I1, I2)
      CALL ECHKZ (ESCNRS)
      RETURN

      ENTRY       RPOST (WKID, I1,R1)
      CALL        PPOST (WKID, I1,R1)
      CALL ECHKZ (EPOST)
      RETURN

      ENTRY       RSEPLB (I1)
      CALL        PSEPLB (I1)
      CALL ECHKZ (ESEPLB)
      RETURN

      ENTRY       RDELLB (I1, I2)
      CALL        PDELLB (I1, I2)
      CALL ECHKZ (EDELLB)
      RETURN

      ENTRY       RUPOST (WKID, I1)
      CALL        PUPOST (WKID, I1)
      CALL ECHKZ (EUPOST)
      RETURN

      ENTRY       RUPAST (WKID)
      CALL        PUPAST (WKID)
      CALL ECHKZ (EUPAST)
      RETURN

C *** *** *** archives *** *** ***

      ENTRY       ROPARF (I1, I2)
      CALL        POPARF (I1, I2)
      CALL ECHKZ (EOPARF)
      RETURN

      ENTRY       RCLARF (I1)
      CALL        PCLARF (I1)
      CALL ECHKZ (ECLARF)
      RETURN

      ENTRY       RARST (I1, I2, IA)
      CALL        PARST (I1, I2, IA)
      CALL ECHKZ (EARST)
      RETURN

      ENTRY       RARSN (I1, I2, IA)
      CALL        PARSN (I1, I2, IA)
      CALL ECHKZ (EARSN)
      RETURN

      ENTRY       RARAST (I1)
      CALL        PARAST (I1)
      CALL ECHKZ (EARAST)
      RETURN

      ENTRY       RRSID (I1, I2, I3, IA)
      CALL        PRSID (I1, I2, I3, IA)
      CALL ECHKZ (ERSID)
      RETURN

      ENTRY       RRAST (I1)
      CALL        PRAST (I1)
      CALL ECHKZ (ERAST)
      RETURN

      ENTRY       RREST (I1, I2, IA)
      CALL        PREST (I1, I2, IA)
      CALL ECHKZ (EREST)
      RETURN

      ENTRY       RRESN (I1, I2, IA)
      CALL        PRESN (I1, I2, IA)
      CALL ECHKZ (ERESN)
      RETURN

      ENTRY       RREPAN (I1,I2,I3,I4,I5,I6,I7,I8,IA)
      CALL        PREPAN (I1,I2,I3,I4,I5,I6,I7,I8,IA)
      CALL ECHKZ (EREPAN)
      RETURN

      ENTRY       RREPDE (I1,I2,I3,I4,I5,I6,I7,I8,IA)
      CALL        PREPDE (I1,I2,I3,I4,I5,I6,I7,I8,IA)
      CALL ECHKZ (EREPDE)
      RETURN

      ENTRY       RDSTAR (I1, I2, IA)
      CALL        PDSTAR (I1, I2, IA)
      CALL ECHKZ (EDSTAR)
      RETURN

      ENTRY       RDASAR (I1)
      CALL        PDASAR (I1)
      CALL ECHKZ (EDASAR)
      RETURN

      ENTRY       RDSNAR (I1, I2, IA)
      CALL        PDSNAR (I1, I2, IA)
      CALL ECHKZ (EDSNAR)
      RETURN

      ENTRY       RSERHM (I1)
      CALL        PSERHM (I1)
      CALL ECHKZ (ESERHM)
      RETURN

      END
