/*
 * unittest3.c
 *
 * Ambassador actions:
 * Return 1 or 2 cards to the Supply.
 * Then each other player gains a copy of it.
 *
 
 *Bug 1: The player may return up to 2 cards from hand to supply. Introducing a
bug that will not check on this. Bug will surface when there is a count for how
many cards the player is supposed to hold

 Bug 2: Each other player will gain a copy of the revealed card of the current
player, and the current player will also gain a copy of the revealed card. Bug will surface when there is a check of how many cards each player is supposed to have.
 
 * unittest3: unittest3.c dominion.o rngs.o
 * 	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
 * 
 * * */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "ambassador"

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
int choice1 = 0;
int choice2=0;
int choice3=0;
int bonus=0;
int coins=0;


int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;
int otherPlayer=1;

struct gameState gameControl;
struct gameState gameTest; 

int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, ambassador, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);



//****************************TEST1**************************
//return 2 cards.  1st card
//
printf("TEST 1: choice1 = 1 choice2=2. -2 handCount for currentPlayer & +1 handCount for OtherPlayer\n");

//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
int handpos = 0;
choice1 = 1;
choice2 = 2;
//cardEffect(ambassador, choice1, choice2, choice3, &gameTest, handpos, &bonus);
//printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], 100);

ambassadorCard(choice1, choice2, thisPlayer, handpos, &gameTest);
int returnedCard = 2;

printf("----------\n");
//this should check that player didn't also get a card
printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-returnedCard);

asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-returnedCard);

printf("----------\n");
printf("Hand count for other player = %d, Expected = %d\n", gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer] + returnedCard);
asserttrue(gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer]+returnedCard);
printf("----------\n");
printf("Total supply count = %d, Expected = %d\n", gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);

asserttrue( gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);
  

printf("----------\n");


printf("\n");


printf("----------\n");

//****************************TEST2**************************
//return 2 cards.  1st card
//
printf("TEST 2: choice1 = 0 choice2=3. -2 handCount for currentPlayer & +1 handCount for OtherPlayer\n");
//will return -1 as handpos==choice1
//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
handpos = 2;
choice1 = 1;
choice2 = 3;
//cardEffect(ambassador, choice1, choice2, choice3, &gameTest, handpos, &bonus);
//ambassadorRefactor(thisPlayer, choice1, choice2, &gameTest, handpos);
;
returnedCard = 1;
int result = -1;
printf("----------\n");
//Initated the game as to player choose to discard 3 cards. This should not be allowed. as player is only allowed to discard up to 2 cards.
//function should exit and return -1.
//Since we're not checking for this, the function will not return -1. This should assert to false.
printf("function should return -1\n");
asserttrue(ambassadorCard(choice1, choice2, thisPlayer, handpos, &gameTest), result);

//printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer] -returnedCard);
//printf("Using Assert True Function...\n");
//asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-returnedCard);


printf("----------\n");



return 0;

}

