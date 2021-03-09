###############################################################################
#   cc statement: add -I../F2C             for F2C includes                   #
###############################################################################

###############################################################################
#                                                                             #
#  Use one of the following:                                                  #
#                                                                             #
#                                                                             #
# for no proto-typing:                                                        #
# CC  =  cc -I../F2C -DKR_headers -DNO_PROTO                                  #
#                                                                             #
# for    proto-typing:                                                        #
# CC =   cc -I../F2C                                                          #
#                                                                             #
###############################################################################

## CC  =  cc  -I. -I../F2C -I$(OPENWINHOME)/include -I$(PHIGSHOME)/include/phigs         -L$(XGLHOME)/lib 

 CC  =  cc  -I../F2C -I$(PHIGSHOME)/include/phigs -I$(OPENWINHOME)/include 

###############################################################################
#  List of all "Object" files that compromise the layer code library          #
###############################################################################

OBJS = \
      nqli.o   nads.o   nap.o    narast.o narsn.o  narst.o  natr.o     \
      natr3.o  nbltm.o  nbltm3.o nca.o    nca3.o   ncelst.o nclarf.o   \
      nclph.o  nclst.o  nclwk.o  ncom.o   ncom3.o  ncotm.o  ncotm3.o   \
      ncstid.o ncstir.o ncstrf.o ndas.o   ndasar.o ndel.o   ndellb.o   \
      ndelra.o ndsn.o   ndsnar.o ndst.o   ndstar.o neclph.o nels.o     \
      nemst.o  nerlog.o nerhnd.o nevmm.o  nevmm3.o nevom.o  nevom3.o   \
      nexst.o  nfa.o    nfa3.o   nfas.o   nfas3.o  ngdp.o   ngdp3.o    \
      ngse.o   ngtitm.o niitm.o  ninst.o  niss.o   niss3.o  nlb.o      \
      nmsg.o   noparf.o nopph.o  nopst.o  nopwk.o  nosep.o  npl.o      \
      npl3.o   npm.o    npm3.o   npost.o  nprec.o  nqanf.o  nqarf.o    \
      nqars.o  nqceco.o nqcets.o nqcf.o   nqcmd.o  nqcmdf.o nqcnrs.o   \
      nqcr.o   nqcst.o  nqcstn.o nqddus.o nqdp.o   nqdsp.o  nqdsp3.o   \
      nqdstr.o nqdswa.o nqdus.o  nqeci.o  nqeco.o  nqedf.o  nqedm.o    \
      nqedr.o  nqeedi.o nqegd3.o nqegdp.o nqegse.o nqeii.o  nqep.o     \
      nqepai.o nqepli.o nqepmi.o nqerhm.o nqets.o  nqetxi.o nqevwi.o   \
      nqewk.o  nqgdp.o  nqgdp3.o nqgsef.o nqhlft.o nqhrif.o nqhrm.o    \
      nqhrmf.o nqif.o   nqiqov.o nqir.o   nqivft.o nqmclf.o nqopst.o   \
      nqopwk.o nqpaf.o  nqpan.o  nqpar.o  nqpcr.o  nqpde.o  nqpedr.o   \
      nqphf.o  nqpir.o  nqplf.o  nqplr.o  nqpmf.o  nqpmr.o  nqpost.o   \
      nqppar.o nqpplr.o nqppmr.o nqptxr.o nqpvwr.o nqsid.o  nqsim.o    \
      nqstrs.o nqstst.o nqsys.o  nqtxf.o  nqtxr.o  nqtxx.o  nqvwf.o    \
      nqvwr.o  nqwkc.o  nqwkca.o nqwkcl.o nqwkpo.o nqwksl.o nqwkst.o   \
      nqwkt.o  nqwkt3.o nrast.o  nrepan.o nrepde.o nres.o   nresn.o    \
      nrest.o  nrmcv.o  nro.o    nrox.o   nroy.o   nroz.o   nrqch.o    \
      nrqlc.o  nrqlc3.o nrqsk.o  nrqsk3.o nrqst.o  nrqvl.o  nrsid.o    \
      nsans.o  nsatal.o nsatch.o nsatcu.o nsatp.o  nsc.o    nsc3.o     \
      nschh.o  nschm.o  nschsp.o nschup.o nschxp.o nscmd.o  nscnrs.o   \
      nscr.o   nsdus.o  nsedci.o nsedfg.o nsedi.o  nsedm.o  nsedr.o    \
      nsedt.o  nsep.o   nseplb.o nserhm.o nsewsc.o nsgmt.o  nsgmt3.o   \
      nshlft.o nshrid.o nshrm.o  nsiasf.o nsici.o  nsii.o   nsir.o     \
      nsis.o   nsisi.o  nsivft.o nslcm.o  nslmt.o  nslmt3.o nsln.o     \
      nslwsc.o nsmcli.o nsmcv.o  nsmcv3.o nsmk.o   nsmksc.o nsmlc.o    \
      nsmlc3.o nspa.o   nspar.o  nsparf.o nspkft.o nspkid.o nspkm.o    \
      nsplci.o nspli.o  nsplr.o  nspmci.o nspmi.o  nspmr.o  nsprpv.o   \
      nsskm.o  nsstm.o  nstxal.o nstxci.o nstxfn.o nstxi.o  nstxp.o    \
      nstxpr.o nstxr.o  nsvlm.o  nsvtip.o nsvwi.o  nsvwr.o  nsvwr3.o   \
      nswkv.o  nswkv3.o nswkw.o  nswkw3.o ntp.o    ntp3.o   ntr.o      \
      ntr3.o   ntx.o    ntx3.o   nupast.o nupost.o nurec.o  nuwk.o     \
      nrst.o   name_file.o

all: liblayer.a 

liblayer.a: $(OBJS)
		rm -f   liblayer.a
		ar rvu  liblayer.a $(OBJS)

$(OBJS):  $$(@F:%.o=%.c)
		$(CC) -c $(@F:%.o=%.c)
		ld -r    $(@F:%.o=%.o)
		mv a.out $(@F)

clean:
	rm -f *.o
