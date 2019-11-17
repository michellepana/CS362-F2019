/*
 * randomtestcard3.c
 *
 * tribute actions:
 * player to the left reveals then discards top 2 cards of deck
 * if card is action: +2 actions for player of the card
 * if treasure card: +2 coins for player of the card
 * if victory card: +2 cards
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#define TESTCARD "TRIBUTE CARD"
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

initializeGame(2, k, seed, &gameControl);

endTurn (&gameControl);
endTurn (&gameControl);



int failedTests = 0;
int testScore;
memcpy(&gameTest, &gameControl, sizeof(struct gameState));

begin = clock();
//***********************start*****************************************
printf("----------Testing Card: %s ----------\n", TESTCARD);

printf("Function name: tribute()\n");
printf("Parameters: currentPlayer, nextPlayer, tributeRevealedCards, &state)\n");

for (int index = 0; index < 1000; index++)
{
// either 1 or 0
int currentPlayer = (rand() % (1-0 +1)) +0;
int nextPlayer;
//
int randomcard1 = (rand() % (2-0 +1)) + 0;
int randomcard2 = (rand() % (2-0 +1)) + 0;
int tributeRevealedCards[2] = {randomcard1, randomcard2};

//if currentPlayer = 0, then nextPlayer has to be 1.  
//if currentPlayer = 1, then nextPlayer has to be 0.
if (currentPlayer == 1)
{
nextPlayer = 0;
}

else 
nextPlayer = 1;


printf("Iteration: %d\n", index);

coinsBefore= gameTest.coins;
tributeCard(&gameTest, nextPlayer, currentPlayer, tributeRevealedCards);
coinsAfter = gameTest.coins;

printf("Player turn: %d\n", whoseTurn(&gameTest));

printf("Current player determined by random function: %d\n", currentPlayer);
printf("Next player determined by current player value: %d\n", nextPlayer);

//printf( "Hand count of current player: %d\n",  gameTest.handCount[currentPlayer]);

//printf( "Hand count of next player: %d\n", gameTest.handCount[nextPlayer]);
testScore = asserttrue(gameTest.handCount[currentPlayer], gameControl.handCount[currentPlayer]-2);
if(testScore == -1)
{
failedTests = -1;
}

printf("Action countr: %d\n", gameTest.numActions);
if (randomcard1 == 0 && randomcard2 == 0)
{
testScore=asserttrue(gameTest.numActions, gameControl.numActions+ 4);
}

if (randomcard1 == 0 || randomcard2 == 0)
{
testScore = asserttrue(gameTest.numActions, gameControl.numActions + 2);
}
if (testScore == -1)
{
failedTests = -1;
}

printf("Coin count: %d\n", gameTest.coins);
if (randomcard1 == 1 && randomcard2 == 1)
{
testScore=asserttrue (gameTest.coins, (gameControl.coins) + 4);
}

if (randomcard1 == 1 || randomcard2 == 1)
{ 
testScore = asserttrue (gameTest.coins, (gameControl.coins+ 2));
}
if (testScore == -1)
failedTests =-1;



//("Card count of player: %d\n", gameTest.handCount[currentPlayer]);
if (randomcard1 == 2 && randomcard2 == 2)
{
testScore = asserttrue (gameTest.handCount[currentPlayer], gameControl.handCount[currentPlayer]+4);
}

if (randomcard1 == 2 || randomcard2 == 2)
testScore = asserttrue (gameTest.handCount[currentPlayer], gameControl.handCount[currentPlayer]+2);

if (testScore == -1)
failedTests = -1;


printf("Discard count: %d\n", gameTest.discardCount[playerA]);
testScore = asserttrue (gameTest.discardCount[nextPlayer], gameControl.discardCount[nextPlayer] + 2);
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
//sleep(4);
finish = clock();
printf("----------Summary for TributeFunction: ----------\n");
//printf("begin time: %d\n", begin);
//printf("done time: %d\n", finish);
timeUsed = ((double) (finish-begin))/CLOCKS_PER_SEC;
//printf("Time for execution of testing in seconds: %f\n", timeUsed);
//printf("iterations 1000 \n");
printf("completed \n");
if (failedTests == -1)
printf("not all test successful\n");
printf("statements and branch coverage: \n");
printf("---------------------------------------------------------\n");

return 0;
}