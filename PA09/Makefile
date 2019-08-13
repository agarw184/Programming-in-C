CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -Wunreachable-code
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS) #$(PROFFLAG) //Commenting this out so that valgrind runs succesfully as valgrind and -pg flag do not run together.   
OBJ = tree.o pa09.o expressionTree.o scanner.o
SRC = pa09.c 
SRC_H = tree.h expressionTree.h scanner.h
testdir = inputs
memflags = --tool=memcheck --leak-check=full 
VAL = valgrind $(memflags)

all: pa09

pa09: $(OBJ) $(SRC_H)
		$(GCC) $(OBJ) -o pa09  

.c.o:
	$(GCC) -c $*.c 

test: pa09 
	./pa09 $(testdir)/test1 output1
	./pa09 $(testdir)/test2 output2
	./pa09 $(testdir)/test3 output3
	./pa09 $(testdir)/test4 output4
	./pa09 $(testdir)/test5 output5
	./pa09 $(testdir)/test6 output6
	./pa09 $(testdir)/test7 output7

memory: pa09
	$(VAL) ./pa09 $(testdir)/test1 output1
	$(VAL) ./pa09 $(testdir)/test2 output2
	$(VAL) ./pa09 $(testdir)/test3 output3
	$(VAL) ./pa09 $(testdir)/test4 output4
	
clean:
	/bin/rm -f *.o 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa09 pa09.prof
	/bin/rm -f output*
