# You need to write this file so that
#
# "make" will create an executable called pa06
# 
# "make test" will run the three input files 
# 
# input: inputs/testinput1; output: id1, first1, last1
# input: inputs/testinput2; output: id2, first2, last2
# input: inputs/testinput3; output: id3, first3, last3
# 
# compare your program's output with the expected ouputs by
# using the "diff" command in Linux
#
# "make memory" calls valgrind to check memory errors
#
# "make clean" remove .o and all output files
###################################################################
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS) #$(PROFFLAG) //Commenting this out so that valgrind runs succesfully as valgrind and -pg flag do not run together.   
OBJ = student.o pa06.o msort.o
SRC = pa06.c 
SRC_H = student.h constant.h msort.h
out = output_
testdir = inputs
memflags = --tool=memcheck --leak-check=full 
FLAGS = -DTEST_READ -DTEST_WRITE -DTEST_SORTID -DTEST_SORTFIRSTNAME -DTEST_SORTLASTNAME 
VAL = valgrind $(memflags)

all : pa06

pa06: $(OBJ) $(SRC_H)
		$(GCC)  $(OBJ) $(FLAGS) -o pa06  

.c.o :
	$(GCC) $(FLAGS) -c $*.c 

test: pa06
	./pa06 inputs/testinput1 id1 first1 last1
	./pa06 inputs/testinput2 id2 first2 last2
	./pa06 inputs/testinput3 id3 first3 last3 
#	diff id1 expected/id1
#	diff first1 expected/first1
#	diff last1 expected/last1
# 	diff id2 expected/id2
# 	diff first2 expected/first2
# 	diff last2 expected/last2
# 	diff id3 expected/id3
# 	diff first3 expected/first3
# 	diff last3 expected/last3

memory: pa06
	$(VAL) ./pa06 inputs/testinput1 id1 first1 last1
	$(VAL) ./pa06 inputs/testinput2 id2 first2 last2
	$(VAL) ./pa06 inputs/testinput3 id3 first3 last3

clean:
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa06 pa06.prof
	/bin/rm -f first*
	/bin/rm -f last*
	/bin/rm -f id*
	/bin/rm -f msort.o
