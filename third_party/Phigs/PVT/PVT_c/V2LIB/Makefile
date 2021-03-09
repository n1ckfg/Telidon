
###############################################################################
#                                                                             #
#				 NOTICE                                       #
#                                                                             #
#    Acquisition, use, and distribution of this module and related            #
#    materials are subject to the restrictions of a license agreement.        #
#    Consult the Preface in the User's Manual for the full terms of           #
#    this agreement.                                                          #
#                                                                             #
###############################################################################

###############################################################################
#   Set PVTHOME to the location of the pvt directory                          #
###############################################################################

  PVTHOME     = /home/cugini/pvt/work/v2.1
  PHIGSINCDIR = $(PHIGSHOME)/include/phigs
  XINCDIR     = /usr/openwin/include

###############################################################################
#                                                                             #
#  Use one of the following:                                                  #
#                                                                             #
#                                                                             #
# for no proto-typing(non-ansi):                                              #
# CC  =  cc -I$(XINCDIR) -I../F2C -DKR_headers -DNO_PROTO -I$(PHIGSINCDIR)    #
#                                                                             #
# for    proto-typing(ansi):                                                  #
# CC = gcc -I$(XINCDIR) -I../F2C -I$(PHIGSINCDIR)                             #
#                                                                             #
#  The -I parameter includes the directory that follows in the search path    #
#  for include files. The following are required:                             #
#                                                                             #
#     -I$(XINCDIR)       For X11 includes ( may not be needed )               #
#     -I/F2C             The directory where the f2c includes reside          #
#     -I$(PHIGSINCDIR)   for PHIGS includes                                   #
###############################################################################

 CC  =  cc -I../F2C -I$(PHIGSINCDIR) -I$(XINCDIR) 

###############################################################################
#                                                                             #
# The following arguments are Specific to the SUN compiler, but are           #
# explained here to allow the similar argument on your machine to be          #
# determined.                                                                 #
#                                                                             #
#    -Nn5000 increases static table size                                      #
#    -Nx5000 increases external symbol size                                   #
###############################################################################

  F77             = f77  -Nn5000 -Nx5000

###############################################################################
#   List each of the routines in the V2LIB, these are all the routines        #
#   fom all the sublibs.                                                      #
###############################################################################

  OBJS =   \
        delcss.o  tstcid.o  tcscid.o  tstcir.o  tcscir.o   elstr.o   actst.o \
        pthseq.o  tstels.o  sphdis.o   isspf.o  issgeo.o  tx2dex.o  fltran.o \
        issflt.o  setfil.o    zval.o  cssids.o  retopn.o  arcpth.o  setdif.o \
        filrec.o  plattr.o    ndlw.o  showlw.o  ranlst.o  expppl.o   rlzlw.o \
        displb.o  drwplb.o  shplbw.o  pmattr.o    ndmw.o  showmw.o  ranmkt.o \
        expppm.o   rlzms.o  dispmb.o  drwpmb.o  shpmbw.o  loctx1.o  loctx2.o \
        drwtxt.o  chtxrc.o  chmono.o  txcomp.o  tschup.o  inoutl.o  geotxt.o \
        locat2.o  locans.o  tsanup.o  dsanst.o  drwatx.o  showew.o   parpt.o \
        parlin.o  cldiag.o  disinb.o  drwint.o   rlzew.o  disedb.o  drwedb.o \
        drbued.o  shedbw.o  lbedty.o  patavl.o   arreq.o  locrec.o  patrec.o \
        altsiz.o  hlfbox.o  simark.o  basbot.o  tstasc.o   fpavl.o  prpfnt.o \
        varfnt.o  subfnt.o  chkfnt.o   unrep.o  ngtxat.o  txpcup.o  distxb.o \
        asfset.o  asfint.o  intinh.o  colnam.o  sqgrmk.o  hueang.o  modsep.o \
        undcmd.o  colpch.o  coltrn.o  sethue.o  tsthue.o  coleql.o  curnms.o \
        tsthlf.o  tstivf.o  nmscol.o  elgprm.o  nmsprm.o   ypos8.o  arcpts.o \
        discol.o   xfinh.o  locppl.o  loctxt.o  locatx.o  locint.o  loctri.o \
        setpcl.o  setsvr.o  surfok.o   svrok.o  picenv.o  picchg.o  exsvrs.o \
        doimod.o  setpst.o  chkpst.o  tranhs.o  comtok.o  chkmcv.o  modtrn.o \
        ranary.o  clpgon.o  clpmk5.o  clpair.o  locnpm.o  faclip.o   exedv.o \
        tstcor.o  tstprj.o  tstvip.o  e01001.o  c01002.o  e01003.o  c01003.o \
        e01004.o  c01004.o  e01005.o  c01005.o  e01006.o  c01006.o  e01007.o \
        c01007.o  ifphcl.o  e02052.o  e02053.o  e02054.o  e02056.o  e02057.o \
        e02058.o  e02059.o  e02060.o  e02061.o  e02063.o  e03100.o  e03101.o \
        e03103.o  e03104.o  e03105.o  e03106.o  e03107.o  e03108.o  e03110.o \
        e03111.o  e03112.o  e03113.o  e03114.o  e03115.o  e03116.o  e03117.o \
        e03118.o  e04150.o  e04151.o  e04152.o  e04153.o  e04154.o  e04156.o \
        e04157.o     ds3.o  e05200.o  e05201.o  e05205.o  e05206.o  e05207.o \
        e05208.o  e09401.o  e09402.o  e09404.o  e09405.o  e09407.o  e09408.o \
        e12202.o  esetup.o  enderr.o  tsterr.o \
        gterrm.o  ermsgh.o  scherr.o  tstign.o   streq.o  rfuncs.o   echkz.o \
        tstwan.o   crest.o  ifuncs.o   ichkz.o    etr3.o     etr.o    esc3.o \
           esc.o    erox.o    eroy.o    eroz.o     ero.o   ecom3.o    ecom.o \
          etp3.o     etp.o  ebltm3.o   ebltm.o  ecotm3.o   ecotm.o  eevom3.o \
         eevom.o   eevmm.o  matmul.o   idmat.o  arrtp3.o   red43.o   exp34.o \
        trnseq.o  satan2.o   vecl2.o    vecl.o    vec1.o  dotprd.o  vecang.o \
        crossp.o   prpv1.o  pervec.o  ptplds.o  lnplpt.o   pt3pl.o   ptspl.o \
         pl2pl.o   pl2ln.o  abest3.o  ptlnds.o  lintpt.o  pt2cof.o  parcof.o \
        ptregd.o  ceilng.o    mod1.o   invol.o  inarea.o  issdis.o   issab.o \
        ispths.o  initgl.o  xpopph.o  multws.o  setmsg.o    ifpf.o    pass.o \
          fail.o      pf.o  chkinq.o  windup.o   set2d.o   setis.o   seteq.o \
        setval.o   setvs.o  iniari.o  setrvs.o   iareq.o  iareql.o   rareq.o \
         appeq.o  iarfnd.o  cpyiar.o  srtiar.o  srtrar.o  prsint.o  prsuin.o \
         prsrl.o   ncmsg.o   unmsg.o   inmsg.o   abend.o  brdmsg.o   opmsg.o \
          opyn.o   opint.o   oplin.o  deblnk.o  leadnb.o   itrim.o  errctl.o \
        sigtst.o  sigmsg.o  erfucd.o  erfunm.o   nfunm.o  stdcss.o  csspth.o \
         csseq.o  strcon.o  setstr.o  newstr.o  gtroot.o  chkelp.o  avarnm.o \
        setdlg.o   endit.o    win6.o   wcnpc.o  locppm.o  drwrec.o  txexal.o \
        intsty.o  denhat.o  numlab.o  vislab.o   dynpf.o     dyn.o   dchpf.o \
        dchpfv.o   dchfl.o  dchflv.o  dchoic.o  dlstpf.o  dilist.o  drlval.o \
         dline.o  opfail.o  opcofl.o  opcomt.o    opco.o  dstrng.o  opmsgw.o \
        iacmsg.o  iacans.o  setasf.o  pstctl.o  fitpar.o  linbrk.o  scapar.o \
        ylocel.o  rn1shf.o  rnperm.o   rnset.o  rnbset.o  rndint.o   rndrl.o \
        rnd01.o   pvt_err_hand.o

##############################################################################
#                                                                            #
# List two different object directories, this will allow a C version and     #
# FORTRAN version to exist at the same time. The objects for each            #
# library will be gathered from the correct sub-directory                    #
#                                                                            #
##############################################################################

  COBJECTS = $(OBJS:%=%)

all:		libcpvt.a
	        @echo "Done"

libcpvt.a:	$(COBJECTS)
	        @echo "cpvt"
		@rm -f libcpvt.a
		ar lrcvu libcpvt.a ./*.o

%.o:		%.c
		$(CC) -c $(@F:.o=.c) -o $(@F)
		ld -r $(@F)
		mv a.out $(@F)

clean:
		rm -f *.o

