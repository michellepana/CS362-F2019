  
CFLAGS = -Wall -fpic -coverage -lm
GCOVFLAGS = -fprofile-arcs -ftest-coverage
testme:
	gcc -o testme -g testme.c $(CFLAGS) $(GCOVFLAGS)
	./testme
clean:
	rm -f testme *.gcov *.gcda *.gcno *.o