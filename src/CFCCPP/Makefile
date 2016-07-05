


CXX=g++
CXXFLAGS=-std=c++11
CXXFLAGS+=-DSTDCALL
CXXFLAGS+=-DASTYLE_LIB
TARGET=libCFCPP.so

all:
	$(CXX) $(CXXFLAGS) -I../include/ CFBaseTidy.h CFBaseTidy.cpp CFCppTidy.h CFCppTidy.cpp \
		-L../lib/  -lAStyleMain -fPIC -shared -o libCFCCPP.so
	mv libCFCCPP.so ../lib/
clean:
	rm ../lib/libCFCCPP.so


