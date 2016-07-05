CXX=g++
CXXFLAGS=-std=c++11
CXXFLAGS+=-DSTDCALL
CXXFLAGS+=-DASTYLE_LIB
TARGET=TinyFormat.exe





all:
	(cd AStyleMain;$(MAKE))
	(cd CFCCPP;$(MAKE))
	$(CXX) $(CXXFLAGS) -I./include/ TinyFormat.cpp  -L./lib -lCFCCPP -o TinyShared.exe
	export LD_SHARE_LIB=./lib/
	./TinyShared.exe
