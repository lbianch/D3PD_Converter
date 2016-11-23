INCLUDES = -Iinclude -I$(shell root-config --incdir)
LIBS     = -Llib -lD3PD 

CXX      = g++
CXXFLAGS = -O3 -std=c++14 -pthread -m64 -fPIC

LD       = g++
LDLIBS   = $(shell root-config --libs)
LDFLAGS  = -fPIC -shared $(shell root-config --ldflags)

CXXLIST  = D3PD D3PD/branches utils
CXXLIST := $(patsubst %,src/%/*.cxx,$(CXXLIST))
CXXLIST := $(wildcard $(CXXLIST))
OBJLIST  = $(patsubst %.cxx,%.o,$(CXXLIST))

LIB = lib/libD3PD.so
SRC = convert.cxx
EXE = $(patsubst %.cxx,%,$(SRC))

DICT          = dict/DictOut.cxx
DICTOBJ       = $(patsubst %.cxx,%.o,$(DICT))
DICTPCM       = $(patsubst %.cxx,%_rdict.pcm,$(DICT))
LIBPCM        = $(patsubst dict/%,lib/%,$(DICTPCM))
DICTSRC       = $(wildcard dict/*.h)
ROOTCINT      = rootcint
ROOTCINTFLAGS = -Iinclude

all: $(EXE)

$(EXE): $(SRC) $(LIB)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LDLIBS) $(LIBS) -o $@ $<

$(LIB): $(OBJLIST) $(DICTOBJ)
	@rm -f $(LIB)
	$(LD) $(LDFLAGS) $(LDLIBS) -o $@ $^
	@rm $(OBJLIST)
	@rm $(DICTOBJ)

$(DICT): $(DICTSRC)
	$(ROOTCINT) -f $(DICT) $(ROOTCINTFLAGS) $^
	ln -s ../$(DICTPCM) $(LIBPCM)

#Implicit rule to convert a .cxx to an .o
%.o : %.cxx
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $*.o 

clean:                                              
	@rm -f $(EXE)
	@rm -f $(OBJS)
	@rm -f $(TARGET)
	@rm -f $(OBJLIST)
	@rm -f $(DICT)
	@rm -f $(DICTOBJ)
