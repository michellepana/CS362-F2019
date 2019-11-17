/*
 * randomtestcard2.c
 *
 * minon actions:
 * +1 Action 
 *
 * Choose one: +2 coins
 * or +4 cards and other player with 5+ cards
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#define TESTCARD "MINION CARD"
#include <unistd.h>

int asserttrue (int gameTest, int gameControl)

{	if (gameTest == gameControl){
	printf("passed!\n");
	return 1;
	}
	else{
	printf("failed!\n");
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

int k[10] = {adventurer, council_room, feast, tribute, minion, remodel, smithy, village, baron, great_hall};
int coinsBefore;
int coinsAfter;
//initialized with 2 players instead of a random set.

initializeGame(2, k, seed, &gameControl);
endTurn (&gameControl);
endTurn (&gameControl);


int failedTests = 0;
int testScore;
memcpy(&gameTest, &gameControl, sizeof(struct gameState));

begin = clock();

printf("----------Testing Card: %s ----------\n", TESTCARD);

printf("Function name: minion()\n");
printf("Parameters: currentPlayer, choice1, choice2, state, handPos\n");


for (int index = 0; index < 1000; index++)
{
// either 1 or 0
int choice1Random = (rand() % (1-0 +1)) +0;
int choice2Random;
//game does not support choice1 = 1 & choice2 =1

//if choice1Random = 1, then player gets 2 coins.  and choice2Random
//needs to be 0.  vice versa.  but if choice2Random == 1,
//then coins unaffected.  instead card number affected
if (choice1Random == 1)
{
choice2Random = 0;
}

else 
choice2Random = 1;



printf("Iteration: %d\n", index);


coinsBefore= gameTest.coins;

minionCard(&gameTest, 0, playerA, choice1Random, choice2Random);
coinsAfter = gameTest.coins;

if (choice1Random == 1)
printf("Player chooses +2 coins.\n");

if (choice1Random ==0)
printf("Player chooses discard their cards and draw +4 cards.  If other player has 5 or more cards they discards and draw +4.\n");

//printf("Player turn: %d\n", whoseTurn(&gameTest));

printf( "Hand count: %d\n",  gameTest.handCount[playerA]);
if (choice1Random ==2){

testScore =asserttrue(gameTest.handCount[playerA], gameControl.handCount[playerA]-4);
if (testScore == -1)
{
failedTests = -1;
}
}
if (choice1Random ==1)
testScore =asserttrue(gameTest.handCount [playerA], gameControl.handCount[playerA]);
if (testScore == -1)
{
failedTests = -1;
}

printf("Action count: %d\n", gameTest.numActions);
testScore=asserttrue(gameTest.numActions, gameControl.numActions+ 1);
if (testScore == -1)
{
failedTests = -1;
}

printf("Coin count: %d\n", gameTest.coins);
if (choice1Random == 1)
testScore=asserttrue(gameTest.coins, (gameControl.coins) + 2);
if (testScore == -1)
{
failedTests = -1;
}

if (choice2Random == 1)
testScore=asserttrue(gameTest.coins, (gameControl.coins));
if (testScore == -1)
failedTests = -1;


printf("Discard countr: %d\n", gameTest.discardCount[playerA]);
if (choice2Random ==1 )
testScore = asserttrue (gameTest.handCount[playerA], 4);
if (testScore == -1)
failedTests =-1;



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
//sleep(4);
finish = clock();
printf("----------Summary for Minion Function: ----------\n");
//printf("Please see below for statement and branch coverage: \n");
//printf("begin time: %f\n", begin);
//printf("done time: %f\n", finish);
timeUsed = ((double) (finish-begin))/CLOCKS_PER_SEC;
//printf("Time for execution of this test in seconds: %f\n", timeUsed);
//printf("TOTAL ITERATIONS: 1000 \n");
printf("TESTS COMPLETED: \n");
if (failedTests == -1)
printf("not all test successful\n");
printf("statements and branch coverage: \n");
printf("---------------------------------------------------------\n");

return 0;
}