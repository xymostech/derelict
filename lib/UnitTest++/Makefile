CXX = g++
CXXFLAGS ?= -g -Wall -W -Winline -ansi 
LDFLAGS ?= 
SED = sed
MV = mv
RM = rm

.SUFFIXES: .o .cpp

lib = libUnitTest++.a

src = src/AssertException.cpp \
	src/Test.cpp \
	src/Checks.cpp \
	src/TestRunner.cpp \
	src/TestResults.cpp \
	src/TestReporter.cpp \
	src/TestReporterStdout.cpp \
	src/ReportAssert.cpp \
	src/TestList.cpp \
	src/TimeConstraint.cpp \
	src/TestDetails.cpp \
	src/MemoryOutStream.cpp \
	src/DeferredTestReporter.cpp \
	src/DeferredTestResult.cpp \
	src/XmlTestReporter.cpp \
	src/CurrentTest.cpp
	
ifeq ($(MSYSTEM), MINGW32)
  src += src/Win32/TimeHelpers.cpp
else
  src += src/Posix/SignalTranslator.cpp \
	src/Posix/TimeHelpers.cpp
endif

objects = $(patsubst %.cpp, %.o, $(src))

all: $(lib)


$(lib): $(objects) 
	@ar cr $(lib) $(objects)

clean:
	-@$(RM) $(objects) $(lib) 2>/dev/null

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $(patsubst %.cpp, %.o, $<)
