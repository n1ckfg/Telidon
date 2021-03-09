CC=gcc
AR=ar
RANLIB=ranlib
RM=rm
DFLAGS=
CFLAGS= -Wall
INCFLAGS=-I../../include -I/usr/X11R6/include
OUTPATH=../../lib

.SUFFIXES: .o .c

.c.o:
	$(CC) $(DFLAGS) $(CFLAGS) $(INCFLAGS) -c $*.c

OBJS=ut.o ut_mat.o ut_list.o ut_htab.o ut_nset.o ut_stk.o ut_conv.o            \
     css_ini.o css_stb.o css_set.o css_str.o css_el.o css_inq.o css_pr.o       \
     css_ws.o phg.o phg_str.o phg_el.o phg_attr.o phg_ws.o phg_hdl.o phg_psl.o \
     phg_err.o phg_errnum.o phg_col.o phg_inq.o phg_tr.o phg_inp.o phg_wst.o   \
     phg_ut.o wsb.o wsb_lut.o ws_inp.o wsgl.o wsgl_attr.o wsgl_draw.o          \
     wsgl_hatch.o wsgl_light.o wsx.o wsx_util.o wstx_ini.o wsx_inp.o sin.o     \
     sinq.o sin_evt.o sin_ws.o sin_cvs.o sin_val.o sin_cho.o sin_str.o         \
     sin_dev.o phg_mroman.o phg_roman.o ar.o ar_conv.o ar_ops.o                \
     wsgl_extfill.o

all: libphigs

libphigs: $(OBJS)
	$(AR) cr $(OUTPATH)/libphigs.a $(OBJS)
	$(RANLIB) $(OUTPATH)/libphigs.a

cleanup:
	$(RM) -rf *.o

clean:
	$(RM) -rf *.o
	$(RM) -rf $(OUTPATH)/libphigs.a

