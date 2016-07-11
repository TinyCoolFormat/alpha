CXX=g++
CXXFLAGS=-std=c++11
CXXFLAGS+=-DSTDCALL
CXXFLAGS+=-DASTYLE_LIB
TARGET=TinyFormat.exe





all:
	(export LD_LIBRARY_PATH=./lib/)
	(cd AStyleMain;$(MAKE))
	(cd CFCCPP;$(MAKE))
	(cd Option;$(MAKE))
	$(CXX) $(CXXFLAGS) -I./include/ TinyFormat.cpp  -L./lib -lCFCCPP -lOptionUtil -o TinyShared.exe
	./TinyShared.exe
