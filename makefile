CC = gcc 
CXX = g++ 
CFLAGS  = -O2

BINDIR = ./bin
LIBDIR = ./lib

ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)
ROOTGLIBS = $(shell root-config --glibs)
CXXFLAGS = -Wall -O2 $(ROOTFLAGS) 
CXXLIBS = $(ROOTLIBS)

CLHEPLIB	= -L/usr/local/cern/geant4.9.6.p04/lib64 -lG4clhep
CLHEPINC	= -I/usr/local/cern/geant4.9.6.p04/include/Geant4

TARGET1=     main
OBJS1=       main.o Analysis.o NKS2SimEvent.o NKS2SimTrack.o NKS2SimEvent_Dict.o NKS2SimTrack_Dict.o
all: $(TARGET1) \

$(LIBDIR)/%.o : %.cc
	$(CXX) $(CFLAGS) $(CLHEPINC) -c -o $@ $< $(CXXFLAGS)

$(LIBDIR)/%.o : %.cpp %.h
	$(CXX) $(CFLAGS) -c -o $@ $< $(CXXFLAGS)

$(TARGET1): $(patsubst %,$(LIBDIR)/%,$(OBJS1))
	$(CXX) $(CFLAGS) -o $(BINDIR)/$@ $^ $(CXXLIBS) $(CXXFLAGS)

.PHONY: clean
clean:
	rm -f $(LIBDIR)/*.o core $(BINDIR)/* *Dict*

