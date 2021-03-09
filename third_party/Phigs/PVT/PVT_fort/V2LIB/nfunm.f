      SUBROUTINE NFUNM (FUNCCD, FUNNAM)

C  NFUNM accepts an integer identifying a function and returns the generic
C  name of the function.  These are the codes used by the PVT system, as
C  documented in sys-dict.prt and used in the #F entries of DOC.PRT.

C  Input parameter:
C    FUNCCD : integer code for function
C  Output parameter:
C    FUNNAM : generic name of function

      INTEGER    FUNCCD
      CHARACTER  FUNNAM*(*)

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

      IF (FUNCCD.LT.1 .OR. FUNCCD.GT.324) THEN
         CALL UNMSG ('NFUNM called with invalid value.')
      ENDIF

      IF (FUNCCD .LE. 100) GOTO 9000
      IF (FUNCCD .LE. 200) GOTO 9100
      IF (FUNCCD .LE. 300) GOTO 9200
      GOTO 9300

9000  CONTINUE
      GOTO ( 001,002,003,004,005,006,007,008,009,010,
     1       011,012,013,014,015,016,017,018,019,020,
     2       021,022,023,024,025,026,027,028,029,030,
     3       031,032,033,034,035,036,037,038,039,040,
     4       041,042,043,044,045,046,047,048,049,050,
     5       051,052,053,054,055,056,057,058,059,060,
     6       061,062,063,064,065,066,067,068,069,070,
     7       071,072,073,074,075,076,077,078,079,080,
     8       081,082,083,084,085,086,087,088,089,090,
     9       091,092,093,094,095,096,097,098,099,100 ), FUNCCD

9100  CONTINUE
      GOTO ( 101,102,103,104,105,106,107,108,109,110,
     1       111,112,113,114,115,116,117,118,119,120,
     2       121,122,123,124,125,126,127,128,129,130,
     3       131,132,133,134,135,136,137,138,139,140,
     4       141,142,143,144,145,146,147,148,149,150,
     5       151,152,153,154,155,156,157,158,159,160,
     6       161,162,163,164,165,166,167,168,169,170,
     7       171,172,173,174,175,176,177,178,179,180,
     8       181,182,183,184,185,186,187,188,189,190,
     9       191,192,193,194,195,196,197,198,199,200 ), FUNCCD-100

9200  CONTINUE
      GOTO ( 201,202,203,204,205,206,207,208,209,210,
     1       211,212,213,214,215,216,217,218,219,220,
     2       221,222,223,224,225,226,227,228,229,230,
     3       231,232,233,234,235,236,237,238,239,240,
     4       241,242,243,244,245,246,247,248,249,250,
     5       251,252,253,254,255,256,257,258,259,260,
     6       261,262,263,264,265,266,267,268,269,270,
     7       271,272,273,274,275,276,277,278,279,280,
     8       281,282,283,284,285,286,287,288,289,290,
     9       291,292,293,294,295,296,297,298,299,300 ), FUNCCD-200

9300  CONTINUE
      GOTO ( 301,302,303,304,305,306,307,308,309,310,
     1       311,312,313,314,315,316,317,318,319,320,
     2       321,322,323,324 ), FUNCCD-300

001   FUNNAM = '<open phigs>'
      RETURN
002   FUNNAM = '<close phigs>'
      RETURN
003   FUNNAM = '<open workstation>'
      RETURN
004   FUNNAM = '<close workstation>'
      RETURN
005   FUNNAM = '<redraw all structures>'
      RETURN
006   FUNNAM = '<update workstation>'
      RETURN
007   FUNNAM = '<set display update state>'
      RETURN
008   FUNNAM = '<message>'
      RETURN
009   FUNNAM = '<polyline 3>'
      RETURN
010   FUNNAM = '<polyline>'
      RETURN
011   FUNNAM = '<polymarker 3>'
      RETURN
012   FUNNAM = '<polymarker>'
      RETURN
013   FUNNAM = '<text 3>'
      RETURN
014   FUNNAM = '<text>'
      RETURN
015   FUNNAM = '<annotation text relative 3>'
      RETURN
016   FUNNAM = '<annotation text relative>'
      RETURN
017   FUNNAM = '<fill area 3>'
      RETURN
018   FUNNAM = '<fill area>'
      RETURN
019   FUNNAM = '<fill area set 3>'
      RETURN
020   FUNNAM = '<fill area set>'
      RETURN
021   FUNNAM = '<cell array 3>'
      RETURN
022   FUNNAM = '<cell array>'
      RETURN
023   FUNNAM = '<generalized drawing primitive 3>'
      RETURN
024   FUNNAM = '<generalized drawing primitive>'
      RETURN
025   FUNNAM = '<set polyline index>'
      RETURN
026   FUNNAM = '<set polymarker index>'
      RETURN
027   FUNNAM = '<set text index>'
      RETURN
028   FUNNAM = '<set interior index>'
      RETURN
029   FUNNAM = '<set edge index>'
      RETURN
030   FUNNAM = '<set linetype>'
      RETURN
031   FUNNAM = '<set linewidth scale factor>'
      RETURN
032   FUNNAM = '<set polyline colour index>'
      RETURN
033   FUNNAM = '<set marker type>'
      RETURN
034   FUNNAM = '<set marker size scale factor>'
      RETURN
035   FUNNAM = '<set polymarker colour index>'
      RETURN
036   FUNNAM = '<set text font>'
      RETURN
037   FUNNAM = '<set text precision>'
      RETURN
038   FUNNAM = '<set character expansion factor>'
      RETURN
039   FUNNAM = '<set character spacing>'
      RETURN
040   FUNNAM = '<set text colour index>'
      RETURN
041   FUNNAM = '<set character height>'
      RETURN
042   FUNNAM = '<set character up vector>'
      RETURN
043   FUNNAM = '<set text path>'
      RETURN
044   FUNNAM = '<set text alignment>'
      RETURN
045   FUNNAM = '<set annotation text character height>'
      RETURN
046   FUNNAM = '<set annotation text character up vector>'
      RETURN
047   FUNNAM = '<set annotation text path>'
      RETURN
048   FUNNAM = '<set annotation text alignment>'
      RETURN
049   FUNNAM = '<set annotation style>'
      RETURN
050   FUNNAM = '<set interior style>'
      RETURN
051   FUNNAM = '<set interior style index>'
      RETURN
052   FUNNAM = '<set interior colour index>'
      RETURN
053   FUNNAM = '<set edge flag>'
      RETURN
054   FUNNAM = '<set edgetype>'
      RETURN
055   FUNNAM = '<set edgewidth scale factor>'
      RETURN
056   FUNNAM = '<set edge colour index>'
      RETURN
057   FUNNAM = '<set pattern size>'
      RETURN
058   FUNNAM = '<set pattern reference point and vectors>'
      RETURN
059   FUNNAM = '<set pattern reference point>'
      RETURN
060   FUNNAM = '<add names to set>'
      RETURN
061   FUNNAM = '<remove names from set>'
      RETURN
062   FUNNAM = '<set individual asf>'
      RETURN
063   FUNNAM = '<set polyline representation>'
      RETURN
064   FUNNAM = '<set polymarker representation>'
      RETURN
065   FUNNAM = '<set text representation>'
      RETURN
066   FUNNAM = '<set interior representation>'
      RETURN
067   FUNNAM = '<set edge representation>'
      RETURN
068   FUNNAM = '<set pattern representation>'
      RETURN
069   FUNNAM = '<set colour representation>'
      RETURN
070   FUNNAM = '<set highlighting filter>'
      RETURN
071   FUNNAM = '<set invisibility filter>'
      RETURN
072   FUNNAM = '<set colour model>'
      RETURN
073   FUNNAM = '<set hlhsr identifier>'
      RETURN
074   FUNNAM = '<set hlhsr mode>'
      RETURN
075   FUNNAM = '<set local transformation 3>'
      RETURN
076   FUNNAM = '<set local transformation>'
      RETURN
077   FUNNAM = '<set global transformation 3>'
      RETURN
078   FUNNAM = '<set global transformation>'
      RETURN
079   FUNNAM = '<set modelling clipping volume 3>'
      RETURN
080   FUNNAM = '<set modelling clipping volume>'
      RETURN
081   FUNNAM = '<set modelling clipping indicator>'
      RETURN
082   FUNNAM = '<restore modelling clipping volume>'
      RETURN
083   FUNNAM = '<set view index>'
      RETURN
084   FUNNAM = '<set view representation 3>'
      RETURN
085   FUNNAM = '<set view representation>'
      RETURN
086   FUNNAM = '<set view transformation input priority>'
      RETURN
087   FUNNAM = '<set workstation window 3>'
      RETURN
088   FUNNAM = '<set workstation window>'
      RETURN
089   FUNNAM = '<set workstation viewport 3>'
      RETURN
090   FUNNAM = '<set workstation viewport>'
      RETURN
091   FUNNAM = '<translate 3>'
      RETURN
092   FUNNAM = '<translate>'
      RETURN
093   FUNNAM = '<scale 3>'
      RETURN
094   FUNNAM = '<scale>'
      RETURN
095   FUNNAM = '<rotate x>'
      RETURN
096   FUNNAM = '<rotate y>'
      RETURN
097   FUNNAM = '<rotate z>'
      RETURN
098   FUNNAM = '<rotate>'
      RETURN
099   FUNNAM = '<compose matrix 3>'
      RETURN
100   FUNNAM = '<compose matrix>'
      RETURN
101   FUNNAM = '<transform point 3>'
      RETURN
102   FUNNAM = '<transform point>'
      RETURN
103   FUNNAM = '<build transformation matrix 3>'
      RETURN
104   FUNNAM = '<build transformation matrix>'
      RETURN
105   FUNNAM = '<compose transformation matrix 3>'
      RETURN
106   FUNNAM = '<compose transformation matrix>'
      RETURN
107   FUNNAM = '<evaluate view orientation matrix 3>'
      RETURN
108   FUNNAM = '<evaluate view orientation matrix>'
      RETURN
109   FUNNAM = '<evaluate view mapping matrix 3>'
      RETURN
110   FUNNAM = '<evaluate view mapping matrix>'
      RETURN
111   FUNNAM = '<open structure>'
      RETURN
112   FUNNAM = '<close structure>'
      RETURN
113   FUNNAM = '<execute structure>'
      RETURN
114   FUNNAM = '<label>'
      RETURN
115   FUNNAM = '<application data>'
      RETURN
116   FUNNAM = '<generalized structure element>'
      RETURN
117   FUNNAM = '<set edit mode>'
      RETURN
118   FUNNAM = '<copy all elements from structure>'
      RETURN
119   FUNNAM = '<set element pointer>'
      RETURN
120   FUNNAM = '<offset element pointer>'
      RETURN
121   FUNNAM = '<set element pointer at label>'
      RETURN
122   FUNNAM = '<delete element>'
      RETURN
123   FUNNAM = '<delete element range>'
      RETURN
124   FUNNAM = '<delete elements between labels>'
      RETURN
125   FUNNAM = '<empty structure>'
      RETURN
126   FUNNAM = '<delete structure>'
      RETURN
127   FUNNAM = '<delete structure network>'
      RETURN
128   FUNNAM = '<delete all structures>'
      RETURN
129   FUNNAM = '<change structure identifier>'
      RETURN
130   FUNNAM = '<change structure references>'
      RETURN
131   FUNNAM = '<change structure identifier and references>'
      RETURN
132   FUNNAM = '<post structure>'
      RETURN
133   FUNNAM = '<unpost structure>'
      RETURN
134   FUNNAM = '<unpost all structures>'
      RETURN
135   FUNNAM = '<open archive file>'
      RETURN
136   FUNNAM = '<close archive file>'
      RETURN
137   FUNNAM = '<archive structures>'
      RETURN
138   FUNNAM = '<archive structure networks>'
      RETURN
139   FUNNAM = '<archive all structures>'
      RETURN
140   FUNNAM = '<set conflict resolution>'
      RETURN
141   FUNNAM = '<retrieve structure identifiers>'
      RETURN
142   FUNNAM = '<retrieve structures>'
      RETURN
143   FUNNAM = '<retrieve structure networks>'
      RETURN
144   FUNNAM = '<retrieve all structures>'
      RETURN
145   FUNNAM = '<retrieve paths to ancestors>'
      RETURN
146   FUNNAM = '<retrieve paths to descendants>'
      RETURN
147   FUNNAM = '<delete structures from archive>'
      RETURN
148   FUNNAM = '<delete structure networks from archive>'
      RETURN
149   FUNNAM = '<delete all structures from archive>'
      RETURN
150   FUNNAM = '<set pick identifier>'
      RETURN
151   FUNNAM = '<set pick filter>'
      RETURN
152   FUNNAM = '<initialize locator 3>'
      RETURN
153   FUNNAM = '<initialize locator>'
      RETURN
154   FUNNAM = '<initialize stroke 3>'
      RETURN
155   FUNNAM = '<initialize stroke>'
      RETURN
156   FUNNAM = '<initialize valuator 3>'
      RETURN
157   FUNNAM = '<initialize valuator>'
      RETURN
158   FUNNAM = '<initialize choice 3>'
      RETURN
159   FUNNAM = '<initialize choice>'
      RETURN
160   FUNNAM = '<initialize pick 3>'
      RETURN
161   FUNNAM = '<initialize pick>'
      RETURN
162   FUNNAM = '<initialize string 3>'
      RETURN
163   FUNNAM = '<initialize string>'
      RETURN
164   FUNNAM = '<set locator mode>'
      RETURN
165   FUNNAM = '<set stroke mode>'
      RETURN
166   FUNNAM = '<set valuator mode>'
      RETURN
167   FUNNAM = '<set choice mode>'
      RETURN
168   FUNNAM = '<set pick mode>'
      RETURN
169   FUNNAM = '<set string mode>'
      RETURN
170   FUNNAM = '<request locator 3>'
      RETURN
171   FUNNAM = '<request locator>'
      RETURN
172   FUNNAM = '<request stroke 3>'
      RETURN
173   FUNNAM = '<request stroke>'
      RETURN
174   FUNNAM = '<request valuator>'
      RETURN
175   FUNNAM = '<request choice>'
      RETURN
176   FUNNAM = '<request pick>'
      RETURN
177   FUNNAM = '<request string>'
      RETURN
178   FUNNAM = '<sample locator 3>'
      RETURN
179   FUNNAM = '<sample locator>'
      RETURN
180   FUNNAM = '<sample stroke 3>'
      RETURN
181   FUNNAM = '<sample stroke>'
      RETURN
182   FUNNAM = '<sample valuator>'
      RETURN
183   FUNNAM = '<sample choice>'
      RETURN
184   FUNNAM = '<sample pick>'
      RETURN
185   FUNNAM = '<sample string>'
      RETURN
186   FUNNAM = '<await event>'
      RETURN
187   FUNNAM = '<flush device events>'
      RETURN
188   FUNNAM = '<get locator 3>'
      RETURN
189   FUNNAM = '<get locator>'
      RETURN
190   FUNNAM = '<get stroke 3>'
      RETURN
191   FUNNAM = '<get stroke>'
      RETURN
192   FUNNAM = '<get valuator>'
      RETURN
193   FUNNAM = '<get choice>'
      RETURN
194   FUNNAM = '<get pick>'
      RETURN
195   FUNNAM = '<get string>'
      RETURN
196   FUNNAM = '<write item to metafile>'
      RETURN
197   FUNNAM = '<get item type from metafile>'
      RETURN
198   FUNNAM = '<read item from metafile>'
      RETURN
199   FUNNAM = '<interpret item>'
      RETURN
200   FUNNAM = '<inquire system state value>'
      RETURN
201   FUNNAM = '<inquire workstation state value>'
      RETURN
202   FUNNAM = '<inquire structure state value>'
      RETURN
203   FUNNAM = '<inquire archive state value>'
      RETURN
204   FUNNAM = '<inquire list of available workstation types>'
      RETURN
205   FUNNAM = '<inquire phigs facilities>'
      RETURN
206   FUNNAM = '<inquire generalized structure element facilities>'
      RETURN
207   FUNNAM = '<inquire modelling clipping facilities>'
      RETURN
208   FUNNAM = '<inquire edit mode>'
      RETURN
209   FUNNAM = '<inquire set of open workstations>'
      RETURN
210   FUNNAM = '<inquire structure identifiers>'
      RETURN
211   FUNNAM = '<inquire archive files>'
      RETURN
212   FUNNAM = '<inquire conflict resolution>'
      RETURN
213   FUNNAM = '<inquire all conflicting structures>'
      RETURN
214   FUNNAM = '<inquire conflicting structures in network>'
      RETURN
215   FUNNAM = '<inquire more simultaneous events>'
      RETURN
216   FUNNAM = '<inquire workstation connection and type>'
      RETURN
217   FUNNAM = '<inquire list of view indices>'
      RETURN
218   FUNNAM = '<inquire view representation>'
      RETURN
219   FUNNAM = '<inquire hlhsr mode>'
      RETURN
220   FUNNAM = '<inquire posted structures>'
      RETURN
221   FUNNAM = '<inquire display update state>'
      RETURN
222   FUNNAM = '<inquire list of polyline indices>'
      RETURN
223   FUNNAM = '<inquire polyline representation>'
      RETURN
224   FUNNAM = '<inquire list of polymarker indices>'
      RETURN
225   FUNNAM = '<inquire polymarker representation>'
      RETURN
226   FUNNAM = '<inquire list of text indices>'
      RETURN
227   FUNNAM = '<inquire text representation>'
      RETURN
228   FUNNAM = '<inquire list of interior indices>'
      RETURN
229   FUNNAM = '<inquire interior representation>'
      RETURN
230   FUNNAM = '<inquire list of edge indices>'
      RETURN
231   FUNNAM = '<inquire edge representation>'
      RETURN
232   FUNNAM = '<inquire list of pattern indices>'
      RETURN
233   FUNNAM = '<inquire pattern representation>'
      RETURN
234   FUNNAM = '<inquire colour model>'
      RETURN
235   FUNNAM = '<inquire list of colour indices>'
      RETURN
236   FUNNAM = '<inquire colour representation>'
      RETURN
237   FUNNAM = '<inquire highlighting filter>'
      RETURN
238   FUNNAM = '<inquire invisibility filter>'
      RETURN
239   FUNNAM = '<inquire workstation transformation 3>'
      RETURN
240   FUNNAM = '<inquire workstation transformation>'
      RETURN
241   FUNNAM = '<inquire locator device state 3>'
      RETURN
242   FUNNAM = '<inquire locator device state>'
      RETURN
243   FUNNAM = '<inquire stroke device state 3>'
      RETURN
244   FUNNAM = '<inquire stroke device state>'
      RETURN
245   FUNNAM = '<inquire valuator device state 3>'
      RETURN
246   FUNNAM = '<inquire valuator device state>'
      RETURN
247   FUNNAM = '<inquire choice device state 3>'
      RETURN
248   FUNNAM = '<inquire choice device state>'
      RETURN
249   FUNNAM = '<inquire pick device state 3>'
      RETURN
250   FUNNAM = '<inquire pick device state>'
      RETURN
251   FUNNAM = '<inquire string device state 3>'
      RETURN
252   FUNNAM = '<inquire string device state>'
      RETURN
253   FUNNAM = '<inquire workstation category>'
      RETURN
254   FUNNAM = '<inquire display space size 3>'
      RETURN
255   FUNNAM = '<inquire display space size>'
      RETURN
256   FUNNAM = '<inquire hlhsr facilities>'
      RETURN
257   FUNNAM = '<inquire view facilities>'
      RETURN
258   FUNNAM = '<inquire predefined view representation>'
      RETURN
259   FUNNAM = '<inquire workstation classification>'
      RETURN
260   FUNNAM = '<inquire dynamics of workstation attributes>'
      RETURN
261   FUNNAM = '<inquire default display update state>'
      RETURN
262   FUNNAM = '<inquire polyline facilities>'
      RETURN
263   FUNNAM = '<inquire predefined polyline representation>'
      RETURN
264   FUNNAM = '<inquire polymarker facilities>'
      RETURN
265   FUNNAM = '<inquire predefined polymarker representation>'
      RETURN
266   FUNNAM = '<inquire text facilities>'
      RETURN
267   FUNNAM = '<inquire predefined text representation>'
      RETURN
268   FUNNAM = '<inquire annotation facilities>'
      RETURN
269   FUNNAM = '<inquire text extent>'
      RETURN
270   FUNNAM = '<inquire interior facilities>'
      RETURN
271   FUNNAM = '<inquire predefined interior representation>'
      RETURN
272   FUNNAM = '<inquire edge facilities>'
      RETURN
273   FUNNAM = '<inquire predefined edge representation>'
      RETURN
274   FUNNAM = '<inquire pattern facilities>'
      RETURN
275   FUNNAM = '<inquire predefined pattern representation>'
      RETURN
276   FUNNAM = '<inquire colour model facilities>'
      RETURN
277   FUNNAM = '<inquire colour facilities>'
      RETURN
278   FUNNAM = '<inquire predefined colour representation>'
      RETURN
279   FUNNAM = '<inquire list of available generalized drawing ' //
     1         'primitives 3>'
      RETURN
280   FUNNAM = '<inquire list of available generalized drawing ' //
     1         'primitives>'
      RETURN
281   FUNNAM = '<inquire generalized drawing primitive 3>'
      RETURN
282   FUNNAM = '<inquire generalized drawing primitive>'
      RETURN
283   FUNNAM = '<inquire list of available generalized structure ' //
     1         'elements>'
      RETURN
284   FUNNAM = '<inquire number of display priorities supported>'
      RETURN
285   FUNNAM = '<inquire workstation state table lengths>'
      RETURN
286   FUNNAM = '<inquire dynamics of structures>'
      RETURN
287   FUNNAM = '<inquire number of available logical input devices>'
      RETURN
288   FUNNAM = '<inquire default locator device data 3>'
      RETURN
289   FUNNAM = '<inquire default locator device data>'
      RETURN
290   FUNNAM = '<inquire default stroke device data 3>'
      RETURN
291   FUNNAM = '<inquire default stroke device data>'
      RETURN
292   FUNNAM = '<inquire default valuator device data 3>'
      RETURN
293   FUNNAM = '<inquire default valuator device data>'
      RETURN
294   FUNNAM = '<inquire default choice device data 3>'
      RETURN
295   FUNNAM = '<inquire default choice device data>'
      RETURN
296   FUNNAM = '<inquire default pick device data 3>'
      RETURN
297   FUNNAM = '<inquire default pick device data>'
      RETURN
298   FUNNAM = '<inquire default string device data 3>'
      RETURN
299   FUNNAM = '<inquire default string device data>'
      RETURN
300   FUNNAM = '<inquire set of workstations to which posted>'
      RETURN
301   FUNNAM = '<inquire open structure>'
      RETURN
302   FUNNAM = '<inquire element pointer>'
      RETURN
303   FUNNAM = '<inquire current element type and size>'
      RETURN
304   FUNNAM = '<inquire current element content>'
      RETURN
305   FUNNAM = '<inquire element type and size>'
      RETURN
306   FUNNAM = '<inquire element content>'
      RETURN
307   FUNNAM = '<inquire structure status>'
      RETURN
308   FUNNAM = '<inquire paths to ancestors>'
      RETURN
309   FUNNAM = '<inquire paths to descendants>'
      RETURN
310   FUNNAM = '<element search>'
      RETURN
311   FUNNAM = '<incremental spatial search 3>'
      RETURN
312   FUNNAM = '<incremental spatial search>'
      RETURN
313   FUNNAM = '<inquire input queue overflow>'
      RETURN
314   FUNNAM = '<inquire error handling mode>'
      RETURN
315   FUNNAM = '<emergency close phigs>'
      RETURN
316   FUNNAM = '<error handling>'
      RETURN
317   FUNNAM = '<error logging>'
      RETURN
318   FUNNAM = '<set error handling mode>'
      RETURN
319   FUNNAM = '<escape>'
      RETURN
320   FUNNAM = '<pack data record>'
      RETURN
321   FUNNAM = '<unpack data record>'
      RETURN
322   FUNNAM = '<create store>'
      RETURN
323   FUNNAM = '<delete store>'
      RETURN
324   FUNNAM = '<set error handler>'
      RETURN

      END
