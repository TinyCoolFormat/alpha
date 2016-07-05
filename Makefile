CXX=g++
CXXFLAGS=-std=c++11
CXXFLAGS+=-DSTDCALL
CXXFLAGS+=-DASTYLE_LIB
TARGET=TinyFormat.exe


all:
	$(CXX) $(CXXFLAGS) astyle.h astyle_main.h ASLocalizer.h CFBaseTidy.h CFCppTidy.h \
		ASBeautifier.cpp ASEnhancer.cpp ASFormatter.cpp ASLocalizer.cpp ASResource.cpp \
		astyle_main.cpp CFBaseTidy.cpp CFCppTidy.cpp -fPIC -shared -o libCFCCPP.so
	$(CXX) $(CXXFLAGS) TinyFormat.cpp  -L. -lCFCCPP -o TinyShared.exe
clean:
	rm -rf $(TARGET)

