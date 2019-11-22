/*
 * unittest5.c
 *
 * Mine actions:
 * allows you to trash your Coppers to gain Silvers and trash your Silvers to gain Golds
 * 
 * unittest5: unittest5.c dominion.o rngs.o
 * 	gcc -o unittest5 -g unittest5.c dominion.o rngs.o $(CFLAGS)
 * 
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
//mineCard(&gameTest, thisPlayer,   choice1, choice2, handpos);
mineEffect(choice1, choice2, &gameTest, handpos);
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
//mineCard(&gameTest, thisPlayer,   choice1, choice2, handpos);
mineEffect(choice1, choice2, &gameTest, handpos);
printf("TEST 2: \n");


printf("testing of choice one is a treasure card:");
asserttrue(gameTest.hand[thisPlayer][choice1] < copper, 0);

//asserttrue(mineCard(&gameTest, thisPlayer,   choice1, choice2, handpos), -1);


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

gameTest.handCount[0] = 3;
gameTest.hand[0][0] = mine;
gameTest.hand[0][1] = copper;
gameTest.hand[0][2] = copper;
//cardEffect(baron, choice1, choice2, choice3, &gameTest, handpos, &bonus);
//mineCard(&gameTest, thisPlayer,   choice1, choice2, handpos);
mineEffect(choice1, choice2, &gameTest, handpos);
printf("TEST 4: \n");

printf("----------\n");

printf("testing of choice1 = one is a treasure card. \n" );
asserttrue(gameTest.hand[thisPlayer][choice1] < copper, 0);
printf("there should be one copper left in hand. Hand count = %d, Expected = 1\n", gameTest.discardCount[0]);
asserttrue(gameTest.discardCount[0], 1);
asserttrue(gameTest.discard[0][0], copper);

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
