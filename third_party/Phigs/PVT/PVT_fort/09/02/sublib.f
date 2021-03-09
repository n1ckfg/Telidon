C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.02/ifuncs                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE IFUNCS ()

C  IFUNCS is the home of the entry points for PHIGS functions which
C  are called in order to generate a non-zero error indicator.
C  The functions are followed a a call to ICHKZ which tests what
C  the actual error code is among the expected error codes.

C  PHIGS function names (for those functions which return non-zero
C  error indicator)

      INTEGER    NOPPH,      NCLPH,      NOPWK,      NCLWK
      PARAMETER (NOPPH =001, NCLPH =002, NOPWK =003, NCLWK =004)
      INTEGER    NRST,       NUWK,       NSDUS,      NMSG
      PARAMETER (NRST  =005, NUWK  =006, NSDUS =007, NMSG  =008)
      INTEGER    NPL3,       NPL,        NPM3,       NPM
      PARAMETER (NPL3  =009, NPL   =010, NPM3  =011, NPM   =012)
      INTEGER    NTX3,       NTX,        NATR3,      NATR
      PARAMETER (NTX3  =013, NTX   =014, NATR3 =015, NATR  =016)
      INTEGER    NFA3,       NFA,        NFAS3,      NFAS
      PARAMETER (NFA3  =017, NFA   =018, NFAS3 =019, NFAS  =020)
      INTEGER    NCA3,       NCA,        NGDP3,      NGDP
      PARAMETER (NCA3  =021, NCA   =022, NGDP3 =023, NGDP  =024)
      INTEGER    NSPLI,      NSPMI,      NSTXI,      NSII
      PARAMETER (NSPLI =025, NSPMI =026, NSTXI =027, NSII  =028)
      INTEGER    NSEDI,      NSLN,       NSLWSC,     NSPLCI
      PARAMETER (NSEDI =029, NSLN  =030, NSLWSC=031, NSPLCI=032)
      INTEGER    NSMK,       NSMKSC,     NSPMCI,     NSTXFN
      PARAMETER (NSMK  =033, NSMKSC=034, NSPMCI=035, NSTXFN=036)
      INTEGER    NSTXPR,     NSCHXP,     NSCHSP,     NSTXCI
      PARAMETER (NSTXPR=037, NSCHXP=038, NSCHSP=039, NSTXCI=040)
      INTEGER    NSCHH,      NSCHUP,     NSTXP,      NSTXAL
      PARAMETER (NSCHH =041, NSCHUP=042, NSTXP =043, NSTXAL=044)
      INTEGER    NSATCH,     NSATCU,     NSATP,      NSATAL
      PARAMETER (NSATCH=045, NSATCU=046, NSATP =047, NSATAL=048)
      INTEGER    NSANS,      NSIS,       NSISI,      NSICI
      PARAMETER (NSANS =049, NSIS  =050, NSISI =051, NSICI =052)
      INTEGER    NSEDFG,     NSEDT,      NSEWSC,     NSEDCI
      PARAMETER (NSEDFG=053, NSEDT =054, NSEWSC=055, NSEDCI=056)
      INTEGER    NSPA,       NSPRPV,     NSPARF,     NADS
      PARAMETER (NSPA  =057, NSPRPV=058, NSPARF=059, NADS  =060)
      INTEGER    NRES,       NSIASF,     NSPLR,      NSPMR
      PARAMETER (NRES  =061, NSIASF=062, NSPLR =063, NSPMR =064)
      INTEGER    NSTXR,      NSIR,       NSEDR,      NSPAR
      PARAMETER (NSTXR =065, NSIR  =066, NSEDR =067, NSPAR =068)
      INTEGER    NSCR,       NSHLFT,     NSIVFT,     NSCMD
      PARAMETER (NSCR  =069, NSHLFT=070, NSIVFT=071, NSCMD =072)
      INTEGER    NSHRID,     NSHRM,      NSLMT3,     NSLMT
      PARAMETER (NSHRID=073, NSHRM =074, NSLMT3=075, NSLMT =076)
      INTEGER    NSGMT3,     NSGMT,      NSMCV3,     NSMCV
      PARAMETER (NSGMT3=077, NSGMT =078, NSMCV3=079, NSMCV =080)
      INTEGER    NSMCLI,     NRMCV,      NSVWI,      NSVWR3
      PARAMETER (NSMCLI=081, NRMCV =082, NSVWI =083, NSVWR3=084)
      INTEGER    NSVWR,      NSVTIP,     NSWKW3,     NSWKW
      PARAMETER (NSVWR =085, NSVTIP=086, NSWKW3=087, NSWKW =088)
      INTEGER    NSWKV3,     NSWKV,      NTR3,       NTR
      PARAMETER (NSWKV3=089, NSWKV =090, NTR3  =091, NTR   =092)
      INTEGER    NSC3,       NSC,        NROX,       NROY
      PARAMETER (NSC3  =093, NSC   =094, NROX  =095, NROY  =096)
      INTEGER    NROZ,       NRO,        NCOM3,      NCOM
      PARAMETER (NROZ  =097, NRO   =098, NCOM3 =099, NCOM  =100)
      INTEGER    NTP3,       NTP,        NBLTM3,     NBLTM
      PARAMETER (NTP3  =101, NTP   =102, NBLTM3=103, NBLTM =104)
      INTEGER    NCOTM3,     NCOTM,      NEVOM3,     NEVOM
      PARAMETER (NCOTM3=105, NCOTM =106, NEVOM3=107, NEVOM =108)
      INTEGER    NEVMM3,     NEVMM,      NOPST,      NCLST
      PARAMETER (NEVMM3=109, NEVMM =110, NOPST =111, NCLST =112)
      INTEGER    NEXST,      NLB,        NAP,        NGSE
      PARAMETER (NEXST =113, NLB   =114, NAP   =115, NGSE  =116)
      INTEGER    NSEDM,      NCELST,     NSEP,       NOSEP
      PARAMETER (NSEDM =117, NCELST=118, NSEP  =119, NOSEP =120)
      INTEGER    NSEPLB,     NDEL,       NDELRA,     NDELLB
      PARAMETER (NSEPLB=121, NDEL  =122, NDELRA=123, NDELLB=124)
      INTEGER    NEMST,      NDST,       NDSN,       NDAS
      PARAMETER (NEMST =125, NDST  =126, NDSN  =127, NDAS  =128)
      INTEGER    NCSTID,     NCSTRF,     NCSTIR,     NPOST
      PARAMETER (NCSTID=129, NCSTRF=130, NCSTIR=131, NPOST =132)
      INTEGER    NUPOST,     NUPAST,     NOPARF,     NCLARF
      PARAMETER (NUPOST=133, NUPAST=134, NOPARF=135, NCLARF=136)
      INTEGER    NARST,      NARSN,      NARAST,     NSCNRS
      PARAMETER (NARST =137, NARSN =138, NARAST=139, NSCNRS=140)
      INTEGER    NRSID,      NREST,      NRESN,      NRAST
      PARAMETER (NRSID =141, NREST =142, NRESN =143, NRAST =144)
      INTEGER    NREPAN,     NREPDE,     NDSTAR,     NDSNAR
      PARAMETER (NREPAN=145, NREPDE=146, NDSTAR=147, NDSNAR=148)
      INTEGER    NDASAR,     NSPKID,     NSPKFT,     NINLC3
      PARAMETER (NDASAR=149, NSPKID=150, NSPKFT=151, NINLC3=152)
      INTEGER    NINLC,      NINSK3,     NINSK,      NINVL3
      PARAMETER (NINLC =153, NINSK3=154, NINSK =155, NINVL3=156)
      INTEGER    NINVL,      NINCH3,     NINCH,      NINPK3
      PARAMETER (NINVL =157, NINCH3=158, NINCH =159, NINPK3=160)
      INTEGER    NINPK,      NINST3,     NINST,      NSLCM
      PARAMETER (NINPK =161, NINST3=162, NINST =163, NSLCM =164)
      INTEGER    NSSKM,      NSVLM,      NSCHM,      NSPKM
      PARAMETER (NSSKM =165, NSVLM =166, NSCHM =167, NSPKM =168)
      INTEGER    NSSTM,      NRQLC3,     NRQLC,      NRQSK3
      PARAMETER (NSSTM =169, NRQLC3=170, NRQLC =171, NRQSK3=172)
      INTEGER    NRQSK,      NRQVL,      NRQCH,      NRQPK
      PARAMETER (NRQSK =173, NRQVL =174, NRQCH =175, NRQPK =176)
      INTEGER    NRQST,      NSMLC3,     NSMLC,      NSMSK3
      PARAMETER (NRQST =177, NSMLC3=178, NSMLC =179, NSMSK3=180)
      INTEGER    NSMSK,      NSMVL,      NSMCH,      NSMPK
      PARAMETER (NSMSK =181, NSMVL =182, NSMCH =183, NSMPK =184)
      INTEGER    NSMST,      NWAIT,      NFLUSH,     NGTLC3
      PARAMETER (NSMST =185, NWAIT =186, NFLUSH=187, NGTLC3=188)
      INTEGER    NGTLC,      NGTSK3,     NGTSK,      NGTVL
      PARAMETER (NGTLC =189, NGTSK3=190, NGTSK =191, NGTVL =192)
      INTEGER    NGTCH,      NGTPK,      NGTST,      NWITM
      PARAMETER (NGTCH =193, NGTPK =194, NGTST =195, NWITM =196)
      INTEGER    NGTITM,     NRDITM,     NIITM,      NQSYS
      PARAMETER (NGTITM=197, NRDITM=198, NIITM =199, NQSYS =200)
      INTEGER    NQWKST,     NQSTRS,     NQARS,      NQEWK
      PARAMETER (NQWKST=201, NQSTRS=202, NQARS =203, NQEWK =204)
      INTEGER    NQPHF,      NQGSEF,     NQMCLF,     NQEDM
      PARAMETER (NQPHF =205, NQGSEF=206, NQMCLF=207, NQEDM =208)
      INTEGER    NQOPWK,     NQSID,      NQARF,      NQCNRS
      PARAMETER (NQOPWK=209, NQSID =210, NQARF =211, NQCNRS=212)
      INTEGER    NQCST,      NQCSTN,     NQSIM,      NQWKC
      PARAMETER (NQCST =213, NQCSTN=214, NQSIM =215, NQWKC =216)
      INTEGER    NQEVWI,     NQVWR,      NQHRM,      NQPOST
      PARAMETER (NQEVWI=217, NQVWR =218, NQHRM =219, NQPOST=220)
      INTEGER    NQDUS,      NQEPLI,     NQPLR,      NQEPMI
      PARAMETER (NQDUS =221, NQEPLI=222, NQPLR =223, NQEPMI=224)
      INTEGER    NQPMR,      NQETXI,     NQTXR,      NQEII
      PARAMETER (NQPMR =225, NQETXI=226, NQTXR =227, NQEII =228)
      INTEGER    NQIR,       NQEEDI,     NQEDR,      NQEPAI
      PARAMETER (NQIR  =229, NQEEDI=230, NQEDR =231, NQEPAI=232)
      INTEGER    NQPAR,      NQCMD,      NQECI,      NQCR
      PARAMETER (NQPAR =233, NQCMD =234, NQECI =235, NQCR  =236)
      INTEGER    NQHLFT,     NQIVFT,     NQWKT3,     NQWKT
      PARAMETER (NQHLFT=237, NQIVFT=238, NQWKT3=239, NQWKT =240)
      INTEGER    NQLCS3,     NQLCS,      NQSKS3,     NQSKS
      PARAMETER (NQLCS3=241, NQLCS =242, NQSKS3=243, NQSKS =244)
      INTEGER    NQVLS3,     NQVLS,      NQCHS3,     NQCHS
      PARAMETER (NQVLS3=245, NQVLS =246, NQCHS3=247, NQCHS =248)
      INTEGER    NQPKS3,     NQPKS,      NQSTS3,     NQSTS
      PARAMETER (NQPKS3=249, NQPKS =250, NQSTS3=251, NQSTS =252)
      INTEGER    NQWKCA,     NQDSP3,     NQDSP,      NQHRIF
      PARAMETER (NQWKCA=253, NQDSP3=254, NQDSP =255, NQHRIF=256)
      INTEGER    NQHRMF,     NQVWF,      NQPVWR,     NQWKCL
      PARAMETER (NQHRMF=256, NQVWF =257, NQPVWR=258, NQWKCL=259)
      INTEGER    NQDSWA,     NQDDUS,     NQPLF,      NQPPLR
      PARAMETER (NQDSWA=260, NQDDUS=261, NQPLF =262, NQPPLR=263)
      INTEGER    NQPMF,      NQPPMR,     NQTXF,      NQPTXR
      PARAMETER (NQPMF =264, NQPPMR=265, NQTXF =266, NQPTXR=267)
      INTEGER    NQANF,      NQTXX,      NQIF,       NQPIR
      PARAMETER (NQANF =268, NQTXX =269, NQIF  =270, NQPIR =271)
      INTEGER    NQEDF,      NQPEDR,     NQPAF,      NQPPAR
      PARAMETER (NQEDF =272, NQPEDR=273, NQPAF =274, NQPPAR=275)
      INTEGER    NQCMDF,     NQCF,       NQPCR,      NQEGD3
      PARAMETER (NQCMDF=276, NQCF  =277, NQPCR =278, NQEGD3=279)
      INTEGER    NQEGDP,     NQGDP3,     NQGDP,      NQEGSE
      PARAMETER (NQEGDP=280, NQGDP3=281, NQGDP =282, NQEGSE=283)
      INTEGER    NQDP,       NQWKSL,     NQDSTR,     NQLI
      PARAMETER (NQDP  =284, NQWKSL=285, NQDSTR=286, NQLI  =287)
      INTEGER    NQDLC3,     NQDLC,      NQDSK3,     NQDSK
      PARAMETER (NQDLC3=288, NQDLC =289, NQDSK3=290, NQDSK =291)
      INTEGER    NQDVL3,     NQDVL,      NQDCH3,     NQDCH
      PARAMETER (NQDVL3=292, NQDVL =293, NQDCH3=294, NQDCH =295)
      INTEGER    NQDPK3,     NQDPK,      NQDST3,     NQDST
      PARAMETER (NQDPK3=296, NQDPK =297, NQDST3=298, NQDST =299)
      INTEGER    NQWKPO,     NQOPST,     NQEP,       NQCETS
      PARAMETER (NQWKPO=300, NQOPST=301, NQEP  =302, NQCETS=303)
      INTEGER    NQCECO,     NQETS,      NQECO,      NQSTST
      PARAMETER (NQCECO=304, NQETS =305, NQECO =306, NQSTST=307)
      INTEGER    NQPAN,      NQPDE,      NELS,       NISS3
      PARAMETER (NQPAN =308, NQPDE =309, NELS  =310, NISS3 =311)
      INTEGER    NISS,       NQIQOV,     NQERHM,     NECLPH
      PARAMETER (NISS  =312, NQIQOV=313, NQERHM=314, NECLPH=315)
      INTEGER    NERHND,     NERLOG,     NSERHM,     NESC
      PARAMETER (NERHND=316, NERLOG=317, NSERHM=318, NESC  =319)
      INTEGER    NPREC,      NUREC,      NCRSTO,     NDLSTO
      PARAMETER (NPREC =320, NUREC =321, NCRSTO=322, NDLSTO=323)
      INTEGER    NSEHND
      PARAMETER (NSEHND=324)

      INTEGER  WKID, ERRIND, I1,I2,I3,I4,I5,I6,I7,I8,I9,I10,I11,I12
      INTEGER  I13, IA(*),IB(*)
      INTEGER  IA2(2,*),IB2(2,*),IC(*),ID(*),IE(*),IF(*),IG(*),IH(*)
      REAL     R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,R12
      REAL     RA(*),RB(*),RC(*), VCLIP(*),RD(*)
      REAL     XFA(3,3), XFB(3,3), XFC(3,3), XGA(4,4), XGB(4,4)
      REAL     XGC(4,4)

      CHARACTER  CHARS*(*), CHARSA(*)*(*), CHARSB(*)*(*)

C *** *** *** Transformation/Utility functions to support medelling

      ENTRY       RTR3 (R1, R2, R3, ERRIND, XGA)
      CALL        PTR3 (R1, R2, R3, ERRIND, XGA)
      CALL ICHKZ (ERRIND, NTR3)
      RETURN

      ENTRY       RTR (R1, R2, ERRIND, XFA)
      CALL        PTR (R1, R2, ERRIND, XFA)
      CALL ICHKZ (ERRIND, NTR)
      RETURN

      ENTRY       RSC3 (R1, R2, R3, ERRIND, XGA)
      CALL        PSC3 (R1, R2, R3, ERRIND, XGA)
      CALL ICHKZ (ERRIND, NSC3)
      RETURN

      ENTRY       RSC (R1, R2, ERRIND, XFA)
      CALL        PSC (R1, R2, ERRIND, XFA)
      CALL ICHKZ (ERRIND, NSC)
      RETURN

      ENTRY       RROX (R1, ERRIND, XGA)
      CALL        PROX (R1, ERRIND, XGA)
      CALL ICHKZ (ERRIND, NROX)
      RETURN

      ENTRY       RROY (R1, ERRIND, XGA)
      CALL        PROY (R1, ERRIND, XGA)
      CALL ICHKZ (ERRIND, NROX)
      RETURN

      ENTRY       RROZ (R1, ERRIND, XGA)
      CALL        PROZ (R1, ERRIND, XGA)
      CALL ICHKZ (ERRIND, NROZ)
      RETURN

      ENTRY       RRO (R1, ERRIND, XFA)
      CALL        PRO (R1, ERRIND, XFA)
      CALL ICHKZ (ERRIND, NRO)
      RETURN

      ENTRY       RCOM3 (XGA, XGB, ERRIND, XGC)
      CALL        PCOM3 (XGA, XGB, ERRIND, XGC)
      CALL ICHKZ (ERRIND, NCOM3)
      RETURN

      ENTRY       RCOM (XFA, XFB, ERRIND, XFC)
      CALL        PCOM (XFA, XFB, ERRIND, XFC)
      CALL ICHKZ (ERRIND, NCOM)
      RETURN

      ENTRY       RTP3 (R1, R2, R3, XGA, ERRIND, R4, R5, R6)
      CALL        PTP3 (R1, R2, R3, XGA, ERRIND, R4, R5, R6)
      CALL ICHKZ (ERRIND, NTP3)
      RETURN

      ENTRY       RTP (R1, R2, XFA, ERRIND, R3, R4)
      CALL        PTP (R1, R2, XFA, ERRIND, R3, R4)
      CALL ICHKZ (ERRIND, NTP)
      RETURN

      ENTRY       RBLTM3 (R1, R2, R3, R4, R5, R6, R7, R8, R9,
     1                    R10, R11, R12, ERRIND, XGA)
      CALL        PBLTM3 (R1, R2, R3, R4, R5, R6, R7, R8, R9,
     1                    R10, R11, R12, ERRIND, XGA)
      CALL ICHKZ (ERRIND, NBLTM3)
      RETURN

      ENTRY       RBLTM (R1, R2, R3, R4, R5, R6, R7, ERRIND, XFA)
      CALL        PBLTM (R1, R2, R3, R4, R5, R6, R7, ERRIND, XFA)
      CALL ICHKZ (ERRIND, NBLTM)
      RETURN

      ENTRY       RCOTM3 (XGA, R1, R2, R3, R4, R5, R6, R7, R8, R9,
     1                    R10, R11, R12, ERRIND, XGB)
      CALL        PCOTM3 (XGA, R1, R2, R3, R4, R5, R6, R7, R8, R9,
     1                    R10, R11, R12, ERRIND, XGB)
      CALL ICHKZ (ERRIND, NCOTM3)
      RETURN

      ENTRY       RCOTM (XFA, R1, R2, R3, R4, R5, R6, R7, ERRIND, XFB)
      CALL        PCOTM (XFA, R1, R2, R3, R4, R5, R6, R7, ERRIND, XFB)
      CALL ICHKZ (ERRIND, NCOTM)
      RETURN

C *** *** *** Transformation/Utility functions to support viewing

      ENTRY       REVOM3 (R1, R2, R3, R4, R5, R6, R7, R8, R9, ERRIND,
     1                    XGA)
      CALL        PEVOM3 (R1, R2, R3, R4, R5, R6, R7, R8, R9, ERRIND,
     1                    XGA)
      CALL ICHKZ (ERRIND, NEVOM3)
      RETURN

      ENTRY       REVOM (R1, R2, R3, R4, ERRIND, XFA)
      CALL        PEVOM (R1, R2, R3, R4, ERRIND, XFA)
      CALL ICHKZ (ERRIND, NEVOM)
      RETURN

      ENTRY       REVMM3 (RA, RB, I1, R1, R2, R3, R4, R5, R6, ERRIND,
     1                    XGA)
      CALL        PEVMM3 (RA, RB, I1, R1, R2, R3, R4, R5, R6, ERRIND,
     1                    XGA)
      CALL ICHKZ (ERRIND, NEVMM3)
      RETURN

      ENTRY       REVMM (RA, RB, ERRIND, XFA)
      CALL        PEVMM (RA, RB, ERRIND, XFA)
      CALL ICHKZ (ERRIND, NEVMM)
      RETURN

C *** *** *** Inquiry/PHIGS Description Table

      ENTRY       RQEWK (I1, ERRIND, I2, I3)
      CALL        PQEWK (I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQEWK)
      RETURN

      ENTRY       RQPHF (I1, ERRIND, I2, I3, I4, I5, I6, I7, I8)
      CALL        PQPHF (I1, ERRIND, I2, I3, I4, I5, I6, I7, I8)
      CALL ICHKZ (ERRIND, NQPHF)
      RETURN

      ENTRY       RQGSEF (I1, ERRIND, I2, I3, I4)
      CALL        PQGSEF (I1, ERRIND, I2, I3, I4)
      CALL ICHKZ (ERRIND, NQGSEF)
      RETURN

      ENTRY       RQMCLF (I1, ERRIND, I2, I3, I4)
      CALL        PQMCLF (I1, ERRIND, I2, I3, I4)
      CALL ICHKZ (ERRIND, NQMCLF)
      RETURN

C *** *** *** Inquiry/PHIGS State List

      ENTRY       RQEDM (ERRIND, I1)
      CALL        PQEDM (ERRIND, I1)
      CALL ICHKZ (ERRIND, NQEDM)
      RETURN

      ENTRY       RQOPWK (I1, ERRIND, I2, I3)
      CALL        PQOPWK (I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQOPWK)
      RETURN

      ENTRY       RQSID (I1, ERRIND, I2, I3)
      CALL        PQSID (I2, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQSID)
      RETURN

      ENTRY       RQARF (I1, ERRIND, I2, I3, I4)
      CALL        PQARF (I1, ERRIND, I2, I3, I4)
      CALL ICHKZ (ERRIND, NQARF)
      RETURN

      ENTRY       RQCNRS (ERRIND, I1, I2)
      CALL        PQCNRS (ERRIND, I1, I2)
      CALL ICHKZ (ERRIND, NQCNRS)
      RETURN

      ENTRY       RQCST (I1, I2, ERRIND, I3, I4)
      CALL        PQCST (I1, I2, ERRIND, I3, I4)
      CALL ICHKZ (ERRIND, NQCST)
      RETURN

      ENTRY       RQCSTN (I1, I2, I3, I4, ERRIND, I5, I6)
      CALL        PQCSTN (I1, I2, I3, I4, ERRIND, I5, I6)
      CALL ICHKZ (ERRIND, NQCSTN)
      RETURN

      ENTRY       RQSIM (ERRIND, I1)
      CALL        PQSIM (ERRIND, I1)
      CALL ICHKZ (ERRIND, NQSIM)
      RETURN

C *** *** *** Inquiry/workstation state list

      ENTRY       RQWKC (WKID, ERRIND, I2, I3)
      CALL        PQWKC (WKID, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQWKC)
      RETURN

      ENTRY       RQEVWI (WKID, I1, ERRIND, I2, I3)
      CALL        PQEVWI (WKID, I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQEVWI)
      RETURN

      ENTRY       RQVWR (WKID, I1, I2, ERRIND, I3, XGA, XGB, VCLIP,
     1                   I4, I5, I6)
      CALL        PQVWR (WKID, I1, I2, ERRIND, I3, XGA, XGB, VCLIP,
     1                   I4, I5, I6)
      CALL ICHKZ (ERRIND, NQVWR)
      RETURN

      ENTRY       RQHRM (WKID, ERRIND, I1, I2, I3)
      CALL        PQHRM (WKID, ERRIND, I1, I2, I3)
      CALL ICHKZ (ERRIND, NQHRM)
      RETURN

      ENTRY       RQPOST (WKID, I1, ERRIND, I2, I3, R1)
      CALL        PQPOST (WKID, I1, ERRIND, I2, I3, R1)
      CALL ICHKZ (ERRIND, NQPOST)
      RETURN

      ENTRY       RQDUS (WKID, ERRIND, I1, I2, I3, I4)
      CALL        PQDUS (WKID, ERRIND, I1, I2, I3, I4)
      CALL ICHKZ (ERRIND, NQDUS)
      RETURN

      ENTRY       RQEPLI (WKID, I1, ERRIND, I2, I3)
      CALL        PQEPLI (WKID, I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQEPLI)
      RETURN

      ENTRY       RQPLR (WKID, I1, I2, ERRIND, I3, R1, I4)
      CALL        PQPLR (WKID, I1, I2, ERRIND, I3, R1, I4)
      CALL ICHKZ (ERRIND, NQPLR)
      RETURN

      ENTRY       RQEPMI (WKID, I1, ERRIND, I2, I3)
      CALL        PQEPMI (WKID, I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQEPMI)
      RETURN

      ENTRY       RQPMR (WKID, I1, I2, ERRIND, I3, R1, I4)
      CALL        PQPMR (WKID, I1, I2, ERRIND, I3, R1, I4)
      CALL ICHKZ (ERRIND, NQPMR)
      RETURN

      ENTRY       RQETXI (WKID, I1, ERRIND, I2, I3)
      CALL        PQETXI (WKID, I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQETXI)
      RETURN

      ENTRY       RQTXR (WKID, I1, I2, ERRIND, I3, I4, R1, R2, I5)
      CALL        PQTXR (WKID, I1, I2, ERRIND, I3, I4, R1, R2, I5)
      CALL ICHKZ (ERRIND, NQTXR)
      RETURN

      ENTRY       RQEII (WKID, I1, ERRIND, I2, I3)
      CALL        PQEII (WKID, I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQEII)
      RETURN

      ENTRY       RQIR (WKID, I1, I2, ERRIND, I3, I4, I5)
      CALL        PQIR (WKID, I1, I2, ERRIND, I3, I4, I5)
      CALL ICHKZ (ERRIND, NQIR)
      RETURN

      ENTRY       RQEEDI (WKID, I1, ERRIND, I2, I3)
      CALL        PQEEDI (WKID, I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQEEDI)
      RETURN

      ENTRY       RQEDR (WKID, I1, I2, ERRIND, I3, I4, R1, I5)
      CALL        PQEDR (WKID, I1, I2, ERRIND, I3, I4, R1, I5)
      CALL ICHKZ (ERRIND, NQEDR)
      RETURN

      ENTRY       RQEPAI (WKID, I1, ERRIND, I2, I3)
      CALL        PQEPAI (WKID, I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQEPAI)
      RETURN

      ENTRY       RQPAR (WKID, I1, I2, I3, I4, ERRIND, I5, I6, IA)
      CALL        PQPAR (WKID, I1, I2, I3, I4, ERRIND, I5, I6, IA)
      CALL ICHKZ (ERRIND, NQPAR)
      RETURN

      ENTRY       RQCMD (WKID, ERRIND, I1)
      CALL        PQCMD (WKID, ERRIND, I1)
      CALL ICHKZ (ERRIND, NQCMD)
      RETURN

      ENTRY       RQECI (WKID, I1, ERRIND, I2, I3)
      CALL        PQECI (WKID, I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQECI)
      RETURN

      ENTRY       RQCR (WKID, I1, I2, I3, ERRIND, I4, RA)
      CALL        PQCR (WKID, I1, I2, I3, ERRIND, I4, RA)
      CALL ICHKZ (ERRIND, NQCR)
      RETURN

      ENTRY       RQHLFT (WKID, I1, I2, ERRIND, I3, IA, I4, IB)
      CALL        PQHLFT (WKID, I1, I2, ERRIND, I3, IA, I4, IB)
      CALL ICHKZ (ERRIND, NQHLFT)
      RETURN

      ENTRY       RQIVFT (WKID, I1, I2, ERRIND, I3, IA, I4, IB)
      CALL        PQIVFT (WKID, I1, I2, ERRIND, I3, IA, I4, IB)
      CALL ICHKZ (ERRIND, NQIVFT)
      RETURN

      ENTRY       RQWKT3 (WKID, ERRIND, I1, RA, RB, RC, RD)
      CALL        PQWKT3 (WKID, ERRIND, I1, RA, RB, RC, RD)
      CALL ICHKZ (ERRIND, NQWKT3)
      RETURN

      ENTRY       RQWKT (WKID, ERRIND, I1, RA, RB, RC, RD)
      CALL        PQWKT (WKID, ERRIND, I1, RA, RB, RC, RD)
      CALL ICHKZ (ERRIND, NQWKT)
      RETURN

C *** *** *** Inquiry/WSL/Input Devices

C *** *** *** Inquiry/Workstation Description Table

      ENTRY       RQWKCA (I1, ERRIND, I2)
      CALL        PQWKCA (I1, ERRIND, I2)
      CALL ICHKZ (ERRIND, NQWKCA)
      RETURN

      ENTRY       RQDSP3 (I1, ERRIND, I2, R1, R2, R3, I3, I4, I5)
      CALL        PQDSP3 (I1, ERRIND, I2, R1, R2, R3, I3, I4, I5)
      CALL ICHKZ (ERRIND, NQDSP3)
      RETURN

      ENTRY       RQDSP (I1, ERRIND, I2, R1, R2, I4, I5)
      CALL        PQDSP (I1, ERRIND, I2, R1, R2, I4, I5)
      CALL ICHKZ (ERRIND, NQDSP)
      RETURN

      ENTRY       RQHRIF (I1, I2, ERRIND, I3, I4)
      CALL        PQHRIF (I1, I2, ERRIND, I3, I4)
      CALL ICHKZ (ERRIND, NQHRIF)
      RETURN

      ENTRY       RQHRMF (I1, I2, ERRIND, I3, I4)
      CALL        PQHRMF (I1, I2, ERRIND, I3, I4)
      CALL ICHKZ (ERRIND, NQHRMF)
      RETURN

      ENTRY       RQVWF (I1, ERRIND, I2)
      CALL        PQVWF (I1, ERRIND, I2)
      CALL ICHKZ (ERRIND, NQVWF)
      RETURN

      ENTRY       RQPVWR (I1, I2, ERRIND, XGA, XGB, VCLIP, I3, I4, I5)
      CALL        PQPVWR (I1, I2, ERRIND, XGA, XGB, VCLIP, I3, I4, I5)
      CALL ICHKZ (ERRIND, NQPVWR)
      RETURN

      ENTRY       RQWKCL (I1, ERRIND, I2)
      CALL        PQWKCL (I1, ERRIND, I2)
      CALL ICHKZ (ERRIND, NQWKCL)
      RETURN

      ENTRY       RQDSWA (I1, ERRIND, I2, I3, I4, I5, I6, I7, I8,
     1                    I9, I10, I11, I12, I13)
      CALL        PQDSWA (I1, ERRIND, I2, I3, I4, I5, I6, I7, I8,
     1                    I9, I10, I11, I12, I13)
      CALL ICHKZ (ERRIND, NQDSWA)
      RETURN

      ENTRY       RQDDUS (I1, ERRIND, I2, I3)
      CALL        PQDDUS (I1, ERRIND, I2, I3)
      CALL ICHKZ (ERRIND, NQDDUS)
      RETURN
C *** *** *** Inquiry/WDT/Output Primitives and Attributes
      ENTRY       RQPLF (I1, I2, ERRIND, I3, I4, I5, R1, R2, R3, I6)
      CALL        PQPLF (I1, I2, ERRIND, I3, I4, I5, R1, R2, R3, I6)
      CALL ICHKZ (ERRIND, NQPLF)
      RETURN

      ENTRY       RQPPLR (I1, I2, ERRIND, I3, R1, I4)
      CALL        PQPPLR (I1, I2, ERRIND, I3, R1, I4)
      CALL ICHKZ (ERRIND, NQPPLR)
      RETURN

      ENTRY       RQPMF (I1, I2, ERRIND, I3, I4, I5, R1, R2, R3, I6)
      CALL        PQPMF (I1, I2, ERRIND, I3, I4, I5, R1, R2, R3, I6)
      CALL ICHKZ (ERRIND, NQPMF)
      RETURN

      ENTRY       RQPPMR (I1, I2, ERRIND, I3, R1, I4)
      CALL        PQPPMR (I2, I3, ERRIND, I3, R1, I4)
      CALL ICHKZ (ERRIND, NQPPMR)
      RETURN

      ENTRY       RQTXF (I1, I2, ERRIND, I3, I4, I5, I6, R1, R2, I7,
     1                   R3, R4, I8)
      CALL        PQTXF (I1, I2, ERRIND, I3, I4, I5, I6, R1, R2, I7,
     1                   R3, R4, I8)
      CALL ICHKZ (ERRIND, NQTXF)
      RETURN

      ENTRY       RQPTXR (I1, I2, ERRIND, I3, I4, R1, R2, I5)
      CALL        PQPTXR (I1, I2, ERRIND, I3, I4, R1, R2, I5)
      CALL ICHKZ (ERRIND, NQPTXR)
      RETURN

      ENTRY       RQANF (I1, I2, ERRIND, I3, I4, I5, R1, R2)
      CALL        PQANF (I1, I2, ERRIND, I3, I4, I5, R1, R2)
      CALL ICHKZ (ERRIND, NQANF)
      RETURN

      ENTRY       RQTXX (I1, I2, R1, R2, R3, I3, I4, I5, CHARS,
     1                   ERRIND, RA, RB, R4, R5)
      CALL        PQTXX (I1, I2, R1, R2, R3, I3, I4, I5, CHARS,
     1                   ERRIND, RA, RB, R4, R5)
      CALL ICHKZ (ERRIND, NQTXX)
      RETURN

      ENTRY       RQIF (I1, I2, I3, ERRIND, I4, I5, I6, I7, I8)
      CALL        PQIF (I1, I2, I3, ERRIND, I4, I5, I6, I7, I8)
      CALL ICHKZ (ERRIND, NQIF)
      RETURN

      ENTRY       RQPIR (I1, I2, ERRIND, I3, I4, I5)
      CALL        PQPIR (I1, I2, ERRIND, I3, I4, I5)
      CALL ICHKZ (ERRIND, NQPIR)
      RETURN

      ENTRY       RQEDF (I1, I2, ERRIND, I3, I4, I5, R1, R2, R3, I6)
      CALL        PQEDF (I1, I2, ERRIND, I3, I4, I5, R1, R2, R3, I6)
      CALL ICHKZ (ERRIND, NQEDF)
      RETURN

      ENTRY       RQPEDR (I1, I2, ERRIND, I3, I4, R1, I5)
      CALL        PQPEDR (I1, I2, ERRIND, I3, I4, R1, I5)
      CALL ICHKZ (ERRIND, NQPEDR)
      RETURN

      ENTRY       RQPAF (I1, ERRIND, I2)
      CALL        PQPAF (I1, ERRIND, I2)
      CALL ICHKZ (ERRIND, NQPAF)
      RETURN

      ENTRY       RQPPAR (I1, I2, I3, I4, ERRIND, I5, I6, IA)
      CALL        PQPPAR (I1, I2, I3, I4, ERRIND, I5, I6, IA)
      CALL ICHKZ (ERRIND, NQPPAR)
      RETURN

      ENTRY       RQCMDF (I1, I2, ERRIND, I3, I4, I5)
      CALL        PQCMDF (I1, I2, ERRIND, I3, I4, I5)
      CALL ICHKZ (ERRIND, NQCMDF)
      RETURN

      ENTRY       RQCF (I1, ERRIND, I2, I3, I4, RA)
      CALL        PQCF (I1, ERRIND, I2, I3, I4, RA)
      CALL ICHKZ (ERRIND, NQCF)
      RETURN

      ENTRY       RQPCR (I1, I2, I3, ERRIND, I4, RA)
      CALL        PQPCR (I1, I2, I3, ERRIND, I4, RA)
      CALL ICHKZ (ERRIND, NQPCR)
      RETURN

      ENTRY       RQEGD3 (I1, I2, ERRIND, I3, I4)
      CALL        PQEGD3 (I1, I2, ERRIND, I3, I4)
      CALL ICHKZ (ERRIND, NQEGD3)
      RETURN

      ENTRY       RQEGDP (I1, I2, ERRIND, I3, I4)
      CALL        PQEGDP (I1, I2, ERRIND, I3, I4)
      CALL ICHKZ (ERRIND, NQEGDP)
      RETURN

      ENTRY       RQGDP3 (I1, I2, ERRIND, I3, IA)
      CALL        PQGDP3 (I1, I2, ERRIND, I3, IA)
      CALL ICHKZ (ERRIND, NQGDP3)
      RETURN

      ENTRY       RQGDP (I1, I2, ERRIND, I3, IA)
      CALL        PQGDP (I1, I2, ERRIND, I3, IA)
      CALL ICHKZ (ERRIND, NQGDP)
      RETURN

      ENTRY       RQEGSE (I1, I2, ERRIND, I3, I4)
      CALL        PQEGSE (I1, I2, ERRIND, I3, I4)
      CALL ICHKZ (ERRIND, NQEGSE)
      RETURN

C *** *** *** Inquiry/WDL/Rendering Features

      ENTRY       RQDP (I1, ERRIND, I2)
      CALL        PQDP (I1, ERRIND, I2)
      CALL ICHKZ (ERRIND, NQDP)
      RETURN

      ENTRY       RQWKSL (I1, ERRIND, I2, I3, I4, I5, I6, I7, I8, I9)
      CALL        PQWKSL (I1, ERRIND, I2, I3, I4, I5, I6, I7, I8, I9)
      CALL ICHKZ (ERRIND, NQWKSL)
      RETURN

      ENTRY       RQDSTR (I1, ERRIND, I2, I3, I4, I5, I6)
      CALL        PQDSTR (I1, ERRIND, I2, I3, I4, I5, I6)
      CALL ICHKZ (ERRIND, NQDSTR)
      RETURN

C *** *** *** Inquiry/Structure State List

      ENTRY       RQWKPO (I1, I2, ERRIND, I3, I4)
      CALL        PQWKPO (I1, I2, ERRIND, I3, I4)
      CALL ICHKZ (ERRIND, NQWKPO)
      RETURN

C *** *** *** Inquiry/Structure Content

      ENTRY       RQOPST (ERRIND, I1, I2)
      CALL        PQOPST (ERRIND, I1, I2)
      CALL ICHKZ (ERRIND, NQOPST)
      RETURN

      ENTRY       RQEP (ERRIND, I1)
      CALL        PQEP (ERRIND, I1)
      CALL ICHKZ (ERRIND, NQEP)
      RETURN

      ENTRY       RQCETS (ERRIND, I1, I2, I3, I4)
      CALL        PQCETS (ERRIND, I1, I2, I3, I4)
      CALL ICHKZ (ERRIND, NQCETS)
      RETURN

      ENTRY       RQCECO (I1, I2, I3, ERRIND, I4, IA, I5, RA, I6,
     1                    IB, CHARSA)
      CALL        PQCECO (I1, I2, I3, ERRIND, I4, IA, I5, RA, I6,
     1                    IB, CHARSA)
      CALL ICHKZ (ERRIND, NQCECO)
      RETURN

      ENTRY       RQETS (I1, I2, ERRIND, I3, I4, I5, I6)
      CALL        PQETS (I1, I2, ERRIND, I3, I4, I5, I6)
      CALL ICHKZ (ERRIND, NQETS)
      RETURN

      ENTRY       RQECO (I1, I2, I3, I4, I5, ERRIND, I6, IA, I7, RA,
     1                   I8, IB, CHARSA)
      CALL        PQECO (I1, I2, I3, I4, I5, ERRIND, I6, IA, I7, RA,
     1                   I8, IB, CHARSA)
      CALL ICHKZ (ERRIND, NQECO)
      RETURN

      ENTRY       RQSTST (I1, ERRIND, I2)
      CALL        PQSTST (I1, ERRIND, I2)
      CALL ICHKZ (ERRIND, NQSTST)
      RETURN

      ENTRY       RQPAN (I1, I2, I3, I4, I5, ERRIND, I6, I7, IA2)
      CALL        PQPAN (I1, I2, I3, I4, I5, ERRIND, I6, I7, IA2)
      CALL ICHKZ (ERRIND, NQPAN)
      RETURN

      ENTRY       RQPDE (I1, I2, I3, I4, I5, ERRIND, I6, I7, IA2)
      CALL        PQPDE (I1, I2, I3, I4, I5, ERRIND, I6, I7, IA2)
      CALL ICHKZ (ERRIND, NQPDE)
      RETURN

      ENTRY       RELS (I1, I2, I3, I4, IA, I5, IB, ERRIND, I6, I7)
      CALL        PELS (I1, I2, I3, I4, IA, I5, IB, ERRIND, I6, I7)
      CALL ICHKZ (ERRIND, NELS)
      RETURN

      ENTRY       RISS3 (R1, R2, R3, R4, I1, IA2, I2, I3, I4, IA, IB,
     1                   IC, ID, I5, IE,IF,IG,IH,I6,ERRIND,I7,IB2)
      CALL        PISS3 (R1, R2, R3, R4, I1, IA2, I2, I3, I4, IA, IB,
     1                   IC, ID, I5, IE,IF,IG,IH,I6,ERRIND,I7,IB2)
      CALL ICHKZ (ERRIND, NISS3)
      RETURN

      ENTRY       RISS (R1, R2, R3, I1, IA2, I2, I3, I4, IA, IB, IC,
     1                  ID, I5, IE, IF, IG, IH, I6, ERRIND, I7, IB2)
      CALL        PISS (R1, R2, R3, I1, IA2, I2, I3, I4, IA, IB, IC,
     1                  ID, I5, IE, IF, IG, IH, I6, ERRIND, I7, IB2)
      CALL ICHKZ (ERRIND, NISS)
      RETURN

C *** *** *** Inquiry/Error State List

      ENTRY       RQIQOV (ERRIND, WKID, I1, I2)
      CALL        PQIQOV (ERRIND, WKID, I1, I2)
      CALL ICHKZ (ERRIND, NQIQOV)
      RETURN

      ENTRY       RQERHM (ERRIND, I1)
      CALL        PQERHM (ERRIND, I1)
      CALL ICHKZ (ERRIND, NQERHM)
      RETURN

C *** *** *** Utility functions

      ENTRY       RPREC (I1,IA,I2,RA,I3,IB,CHARSA,I4,ERRIND,I5,CHARSB)
      CALL        PPREC (I1,IA,I2,RA,I3,IB,CHARSA,I4,ERRIND,I5,CHARSB)
      CALL ICHKZ (ERRIND, NPREC)
      RETURN

      ENTRY       RUREC (I1,CHARSA,I2,I3,I4,ERRIND,I5,IA,I6,RA,I7,IB,
     1                   CHARSB)
      CALL        PUREC (I1,CHARSA,I2,I3,I4,ERRIND,I5,IA,I6,RA,I7,IB,
     1                   CHARSB)
      CALL ICHKZ (ERRIND, NUREC)
      RETURN

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.02/ichkz                             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ICHKZ (CERIND, FUNCID)

C  ICHKZ does post-processing after an error-indicator function has
C  been called.

C  Input parameters:
C    CERIND: actual error indicator returned by function
C    FUNCID: numeric identifier of function that returned error indicator

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150

      INTEGER     IX, FUNCID, ITRIM, CERIND
      CHARACTER   FUNNAM*80, TMSG*500, MSG*160, ACODE*4
      INTEGER     IARFND

      IF (EXPSIZ.LT.1) THEN
         CALL UNMSG ('ICHKZ is called with invalid EXPSIZ.')
      ENDIF

C  set up test message
      CALL NFUNM (FUNCID, FUNNAM)
      TMSG = 'If ' // FUNNAM
      TMSG(ITRIM(TMSG)+2:) = 'is called and ' // CURCON
      TMSG(ITRIM(TMSG)+1:) = ', it should return error indicator = '

C  may be several valid error code possibilities
      DO 50 IX = 1, EXPSIZ-1
         WRITE (ACODE, '(I4.3)') EXPERR(IX)
         TMSG(ITRIM(TMSG)+2:) = ACODE // ','
50    CONTINUE
      IF (EXPSIZ.GE.2) TMSG(ITRIM(TMSG):) = ' or '
      WRITE(ACODE, '(I4.3)') EXPERR(EXPSIZ)
      TMSG(ITRIM(TMSG)+2:) = ACODE // '.'
      CALL SETMSG (ERRSRS, TMSG)

      IF (IARFND(CERIND, EXPSIZ, EXPERR) .GT. 0) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I6.3,A)') 'Reported error indicator ',
     1          CERIND, ' is not one of the expected values.'
         CALL INMSG (MSG)
      ENDIF

      END
