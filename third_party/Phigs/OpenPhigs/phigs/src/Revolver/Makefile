CXX=g++
RM=rm
DFLAGS=
CXXFLAGS= -Wall
INCFLAGS=-I../../include -I/usr/X11R6/include
LDFLAGS=-L../../lib -L/usr/X11R6/lib
LIBS= -lGL -lGLU -lGLw -lXm -lXaw -lXt -lX11 -lXmu -lm -lphigs -lvk
OUTPATH=../../bin

.SUFFIXES: .o .c

.C.o:
	$(CXX) $(DFLAGS) $(CXXFLAGS) $(INCFLAGS) -c $*.C

OBJS = Workstation.o Main.o

all: Revolver

Revolver: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(OUTPATH)/Revolver $(OBJS) $(LIBS)

cleanup:
	$(RM) -rf *.o

clean:
	$(RM) -rf *.o
	$(RM) -rf $(OUTPATH)/Revolver

