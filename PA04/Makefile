CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS) $(PROFFLAG)  
OBJ = func1.o func2.o func3.o func4.o func5.o answer04.o pa04.o
SRC = pa04.c 
SRC_H = pa04.h 
out = output_

pa04: $(OBJ) $(SRC_H)
		$(GCC) $(OBJ) -o pa04 -lm 
.c.o:
		$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE -c $*.c

testall: pa04
	./pa04 testdir/test1 $(out)test1  
	./pa04 testdir/test2 $(out)test2 
	./pa04 testdir/test3 $(out)test3 
	./pa04 testdir/test4 $(out)test4 
	./pa04 testdir/test5 $(out)test5
	

clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa04 pa04.prof
	/bin/rm -f output_*


