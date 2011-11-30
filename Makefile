#!/bin/bash
#---------------------------------------------------------------------------------------------------------------
# FILE:    Makefile
# DESCR:   Make file for the K1 assembler.
# AUTHORS: Kevin R. Burger (burgerk@asu.edu)
#---------------------------------------------------------------------------------------------------------------

# -c         : Compile a .c file only to produce the .o file.
# -D_32_BIT_ : 32-bit system.
# _DDEUG     : Enable debugging information output.
# -g         : Put debugging information in the .o file. Used by the GDB debugger.
# -O0        : Turn off all optimization. Necessary if you are going to debug using GDB.
# -Wall      : Turn on all warnings. Your code should compile with no errors or warnings.
CPPFLAGS  = -c -D_32_BIT_ -DDEBUG -g -O0 -Wall

SOURCES = ArgException.cpp   \
          Args.cpp           \
          Assembler.cpp      \
          Binary.cpp         \
          DataSegment.cpp    \
          Dictionary.cpp     \
          DictionaryIter.cpp \
          Instr.cpp          \
          InstrTypeB.cpp     \
          InstrTypeR.cpp     \
          InstrTypeRI.cpp    \
          InstrTypeRV.cpp    \
          Integer.cpp        \
          Label.cpp          \
          Lex.cpp            \
          Main.cpp           \
          Operand.cpp        \
          Register.cpp       \
          Segment.cpp        \
          TextSegment.cpp    \
          Tuple.cpp          \
          Variable.cpp       \
          Vector.cpp         \
          VectorIter.cpp

OBJECTS = $(SOURCES:.cpp=.o)

TARGET  = k1as

$(TARGET): $(OBJECTS) 
	g++ $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	g++ $(CPPFLAGS) $< -o $@

%.d: %.cpp
	rm -f $@; gcc -MM $< > $@

include $(SOURCES:.cpp=.d)

.PHONY: clean
clean:
	rm -f $(OBJECTS)
	rm -f *.d
	rm -f $(TARGET)
