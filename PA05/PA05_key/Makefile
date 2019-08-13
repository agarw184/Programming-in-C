CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_READ -DTEST_WRITE -DTEST_SORTID -DTEST_SORTFIRSTNAME -DTEST_SORTLASTNAME
GCC = gcc $(CFLAGS) $(TESTS)
OBJS =  pa05.o student.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

# This Makefile can be shortened by using loop. 
# It shows all steps to explain what it does

# test integrate1 using five different functions
# each function is tested using three sets of input data
pa05: $(OBJS) student.h
	$(GCC) $(OBJS) -o pa05

.c.o: 
	$(GCC) -c $*.c 

test: pa05
	./pa05 inputs/testinput1 id1 first1 last1
	./pa05 inputs/testinput2 id2 first2 last2
	./pa05 inputs/testinput3 id3 first3 last3

memory: pa05
	$(VALGRIND) --log-file=log1 ./pa05 inputs/testinput1 id1 first1 last1
	$(VALGRIND) --log-file=log2 ./pa05 inputs/testinput2 id2 first2 last2
	$(VALGRIND) --log-file=log3 ./pa05 inputs/testinput3 id3 first3 last3

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa05 pa05.prof
	/bin/rm -f id? first? last? log?


