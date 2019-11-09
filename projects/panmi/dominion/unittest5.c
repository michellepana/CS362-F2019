/*
 * unittest5.c
 *
 * Mine actions:
 * Trash a copper for a silver
 * Or trash a silver for a gold
 * 
 * unittest5: unittest5.c dominion.o rngs.o
 * 	gcc -o unittest5 -g unittest5.c dominion.o rngs.o $(CFLAGS)
 * 
 * Note: Much of the below code uses parts of cardtest4.c example from Week 3 module
 * * */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "mine"
void asserttrue (int gameTest, int gameControl)
{
if (gameTest == gameControl)
{
printf("passed\n");
}

else
{
printf("failed\n");
}
}

int main (){

int handpos = 0;
int choice1=0;
int choice2=0;
int choice3=0;
int bonus=0;
int coins=0;

int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;

struct gameState gameControl;
struct gameState gameTest; 

int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);
//printf("----------TEST 1: choice1=1.  -1 estate & +4 coins----------");
printf("TEST 1: choice1=1.  -1 copper treasure & +silver coins\n");

//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
gameTest.hand[thisPlayer][0] = mine;
choice1 = 2;
choice2 = 5;
//mineCard(struct gameState *state, int currentPlayer, int choice1, int choice2, int handPos)
mineCard(&gameTest, thisPlayer,   choice1, choice2, handpos);
printf("TEST 1: \n");

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-1);


asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-1);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins));

asserttrue(gameTest.coins, gameControl.coins);

printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys);

asserttrue(gameTest.numBuys, gameControl.numBuys);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));

asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");

printf("Supply Count of Estates = %d, expected = %d\n", gameTest.supplyCount[estate], gameControl.supplyCount[estate]);

asserttrue(gameTest.supplyCount[estate], gameControl.supplyCount[estate]);
printf("----------\n");

//////////////////////////////////////TEST1





//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
gameTest.hand[thisPlayer][0] = mine;
choice1 = 2;
choice2 = -1;
gameTest.hand[thisPlayer][2] = province;
//cardEffect(baron, choice1, choice2, choice3, &gameTest, handpos, &bonus);
mineCard(&gameTest, thisPlayer,   choice1, choice2, handpos);
printf("TEST 2: \n");


printf("testing of choice one is a treasure card:");
asserttrue(gameTest.hand[thisPlayer][choice1] < copper, 0);

asserttrue(mineCard(&gameTest, thisPlayer,   choice1, choice2, handpos), -1);


printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-1);


asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-1);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins));

asserttrue(gameTest.coins, gameControl.coins);

printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys);

asserttrue(gameTest.numBuys, gameControl.numBuys);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));

asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");

printf("Supply Count of Estates = %d, expected = %d\n", gameTest.supplyCount[estate], gameControl.supplyCount[estate]);

asserttrue(gameTest.supplyCount[estate], gameControl.supplyCount[estate]);
printf("----------\n");



//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
choice1 = 1;
choice2 = 6;
//cardEffect(baron, choice1, choice2, choice3, &gameTest, handpos, &bonus);
mineCard(&gameTest, thisPlayer,   choice1, choice2, handpos);

printf("TEST 2: \n");

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);

asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins));

asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");

printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys);

asserttrue(gameTest.numBuys, gameControl.numBuys);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));

asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");





return 0;
}
