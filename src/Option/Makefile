

CXX=g++
CXXFLAGS=-std=c++11
TARGET=libOptionUtil.so

all:
	$(CXX) $(CXXFLAGS) tinystr.h tinystr.cpp tinyxml.h tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp \
		OptionUtil.cpp -L../lib/   -fPIC -shared -o $(TARGET)
	mv $(TARGET) ../lib/
clean:
	rm ../lib/$(TARGET)

test:
	g++ tinystr.h tinystr.cpp tinyxml.h tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp \
		OptionUtil.cpp -o OptionUtil.exe



