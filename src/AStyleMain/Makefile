
CXX=g++
CXXFLAGS=-std=c++11
CXXFLAGS+=-DSTDCALL
CXXFLAGS+=-DASTYLE_LIB

all:
	$(CXX) $(CXXFLAGS) astyle.h astyle_main.h ASLocalizer.h  \
		ASBeautifier.cpp ASEnhancer.cpp ASFormatter.cpp ASLocalizer.cpp ASResource.cpp \
		astyle_main.cpp  -fPIC -shared -o libAStyleMain.so
	mv libAStyleMain.so ../lib/
clean:
	rm ../lib/libAStyleMain.so
	
