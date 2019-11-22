/*
 * randomtestcard1.c
 *
 * Baron actions:
 * +1 Buy
 * You may discard an Estate for +4 coins
 * If you don't, gain an Estate
 *
 *
 * randomtestcard1: randomtestcard1.c dominion.o rngs.o
 * 	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#define TESTCARD "BARON CARD"
#include <unistd.h>

int asserttrue (int gameTest, int gameControl)

{	if (gameTest == gameControl){
//	printf("passed!\n");
	return 1;
	}
	else{
//	printf("failed!\n");
	return -1;
	}		
}

int main (){
srand(time(0));
clock_t begin;
clock_t finish;
double timeUsed;
int seed = 1000;


int playerNumberRandom = (rand() % (4 - 1 +1)) + 1;
int currentPlayerRandom = (rand() % (3-0 +1)) +0;
int playerA = 0;
int playerB = 1;
int playerC = 2;
int playerD = 3;
int estateTally = 0;

struct gameState gameControl;
struct gameState gameTest; 

int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
int coinsBefore;
int coinsAfter;
initializeGame(2, k, seed, &gameControl);
int failedTests = 0;
int testScore;
memcpy(&gameTest, &gameControl, sizeof(struct gameState));

begin = clock();
//set to 100

printf("----------Testing Card: %s ----------\n", TESTCARD);

printf("Function name: baron()\n");
printf("Dependencies: currentPlayer, choice1, &state\n");


for (int index = 0; index < 3000; index++)
{
int choice1Random = (rand() % (1-0 +1)) +0;

printf("Iteration: %d\n", index);

coinsBefore= gameTest.coins;

//baronCard(&gameTest, choice1Random, playerA, 2);
baronEffect(choice1Random, &gameTest, playerA);
coinsAfter = gameTest.coins;

if (choice1Random == 1)
printf("Player discards Estate and gets +4 coins (if they have estates).\n");

if (choice1Random ==0)
printf("Player receives +1 Estate\n");

printf("Player turn: %d\n", whoseTurn(&gameTest));
testScore = asserttrue(whoseTurn(&gameTest), 0);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}


printf("Random choice: %d\n", choice1Random);

printf( "Hand count: %d\n",  gameTest.handCount[playerA]);
if (choice1Random ==1)
testScore =asserttrue(gameTest.handCount[playerA], gameControl.handCount[playerA]);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

if (choice1Random ==1)
testScore =asserttrue(gameTest.handCount [playerA], gameControl.handCount[playerA]-1);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

printf("Action count: %d\n", gameTest.numActions);
testScore=asserttrue(gameTest.numActions, gameControl.numActions--);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

printf("Coin count: %d\n", gameTest.coins);
if (coinsBefore != coinsAfter)
testScore=asserttrue (gameTest.coins, (gameControl.coins) + 4);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

if (coinsBefore == coinsAfter)
testScore=asserttrue (gameTest.coins, gameControl.coins);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

printf("Buy count: %d\n", gameTest.numBuys);
testScore=asserttrue(gameTest.numBuys, (gameControl.numBuys)+1);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

printf("Scorer: %d\n", scoreFor(playerA,&gameTest));

printf("Discard count: %d\n", gameTest.discardCount[playerA]);

//printf("Supply Count of Estate: %d\n", gameTest.supplyCount[estate]);
if (scoreFor(playerA, &gameTest) == 10)
testScore=asserttrue(gameTest.supplyCount[estate],0);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}


printf("\n");
coinsBefore = 0;
coinsAfter = 0;

if (playerNumberRandom == 2)
{
//switches to player b
endTurn(&gameTest);
//switches back to player a
endTurn(&gameTest);
}

if (playerNumberRandom ==3)
{
//switches to player b
endTurn(&gameTest);
//switches to player c
endTurn(&gameTest);
//switches back to plaeyr a
endTurn(&gameTest);
}
if (playerNumberRandom ==4)
{
//switches to player b
endTurn(&gameTest);
//switches to player c
endTurn(&gameTest);
//switches to player d
endTurn(&gameTest);

//switches back to plaeyr a
endTurn(&gameTest);
}

}

//printf("Sleeping for 1 second.\n");
   //sleep(8);
finish = clock();
printf("----------Summary for Baron Function: ----------\n");
printf("statements and branch coverage: \n");
//timeUsed = ((double) (finish-begin));
//printf("begin time: %f\n", begin);
//printf("done time: %f\n", finish);
printf("Time for execution of this test in seconds: %f\n", timeUsed);

//printf("TOTAL ITERATIONS: 1000 \n");
printf("TESTS COMPLETED: \n");
if (failedTests == -1)
printf("not all test successful\n");
printf("statements and branch coverage: \n");
printf("---------------------------------------------------------\n");

return 0;
}