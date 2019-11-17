CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 



randomtest1: randomtest1.c dominion.o rngs.o
	gcc -o randomtest1 -g randomtest1.c dominion.o rngs.o $(CFLAGS)

randomtest2: randomtest2.c dominion.o rngs.o
	gcc -o randomtest2 -g randomtest2.c dominion.o rngs.o $(CFLAGS)

randomtest3: randomtest3.c dominion.o rngs.o
	gcc -o randomtest3 -g randomtest3.c dominion.o rngs.o $(CFLAGS)

randomtestresults: randomtest1 randomtest2 randomtest3
	gcc -o randomtest1 dominion.c rngs.c randomtest1.c $(CFLAGS)
	randomtest1 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out
	#
	gcc -o randomtest2 dominion.c rngs.c randomtest2.c $(CFLAGS)
	randomtest2 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out
	#
	gcc -o randomtest3 dominion.c rngs.c randomtest3.c $(CFLAGS)
	randomtest3 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out
	
	

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtest1 randomtest2 randomtest3 randomtestresults.out 
