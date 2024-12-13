CC=g++ #Name of compiler
FLAGS=-std=c++20 -w #Compiler flags (the s makes it silent)
TARGET=Test #Executable name
OBJECTS=Test.o FiniteFunctions.o CustomFunction.o ReadMysteryData.o
LIBS=-I ../../GNUplot/ -lboost_iostreams

#First target in Makefile is default
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} ${LIBS} -o ${TARGET}
	@make clean

Test.o : Test.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c Test.cxx

FiniteFunctions.o : FiniteFunctions.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c FiniteFunctions.cxx

ReadMysteryData.o : ReadMysteryData.cpp ReadMysteryData.h #added target for readmystery.o
	${CC} ${FLAGS} ${LIBS} -c ReadMysteryData.cpp 

CustomFunction.o : CustomFunction.cxx CustomFunction.h FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c CustomFunction.cxx

clean: #No targets just run shell command to rm object files and emacs backups
	@rm -f *.o *~

cleantarget: #Delete the exectuable
	@rm -f ${TARGET}
