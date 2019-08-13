CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS) #$(PROFFLAG) //Commenting this out so that valgrind runs succesfully as valgrind and -pg flag do not run together.   
OBJ = stack.o pa08.o calc.o
SRC = pa08.c 
SRC_H = stack.h calc.h
testdir = PA08_inputs
memflags = --tool=memcheck --leak-check=full 
VAL = valgrind $(memflags)

all: pa08

pa08: $(OBJ) $(SRC_H)
		$(GCC) $(OBJ) -o pa08  

.c.o:
	$(GCC) -c $*.c 

test: pa08 
	- ./pa08 $(testdir)/in0
	- ./pa08 $(testdir)/in1
	- ./pa08 $(testdir)/in2
	- ./pa08 $(testdir)/in3
	- ./pa08 $(testdir)/in4	  
	- ./pa08 $(testdir)/in5
	- ./pa08 $(testdir)/in6
	- ./pa08 $(testdir)/in7
	- ./pa08 $(testdir)/in8
	- ./pa08 $(testdir)/in9
	- ./pa08 $(testdir)/in10
	- ./pa08 $(testdir)/in11
	- ./pa08 $(testdir)/in12
	- ./pa08 $(testdir)/in13
	- ./pa08 $(testdir)/in14
	- ./pa08 $(testdir)/in15
	- ./pa08 $(testdir)/in16
	- ./pa08 $(testdir)/in17
	- ./pa08 $(testdir)/in18
	- ./pa08 $(testdir)/test1
	- ./pa08 $(testdir)/test2
	- ./pa08 $(testdir)/test3
	- ./pa08 $(testdir)/test4
	- ./pa08 $(testdir)/test5



memory: pa08
	  $(VAL) ./pa08 $(testdir)/test1
	  $(VAL) ./pa08 $(testdir)/test2
	  $(VAL) ./pa08 $(testdir)/test3
	  $(VAL) ./pa08 $(testdir)/test4
	  $(VAL) ./pa08 $(testdir)/test5

	
clean:
	/bin/rm -f *.o 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa08 pa08.prof

