/*
 * unittest4.c
 *
 * Tribute actions:
 * Player to the left reveals then discards top 2 cards of deck.
 * If card is action +2 actions
 * If treasure card: +2 coins
 * If victory card: +2 cards
 * 
 * unittest1: unittest4.c dominion.o rngs.o
 * 	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
 * 
 * 
 * * */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "tribute"
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

int extraCoins = 2;
int extraActions =2;
int extraCards =2;

int bonus=0;

int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;
int otherPlayer=1;

struct gameState gameControl;
struct gameState gameTest; 

//0 = treasure

//int tributeRevealedCards[2] = {1,1};
int tributeRevealedCards[2] = {copper, province};
int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, tribute, great_hall};
//gameTest.deck[thisPlayer][gameTest.deckCount[thisPlayer]++] = copper;
//gameTest.deck[thisPlayer][gameTest.deckCount[thisPlayer]++] = province;

gameTest.deck[otherPlayer][gameTest.deckCount[otherPlayer]++] = copper;
gameTest.deck[otherPlayer][gameTest.deckCount[otherPlayer]++] = province;

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);

memcpy (&gameTest, &gameControl, sizeof(struct gameState));

tributeCard(&gameTest, otherPlayer, thisPlayer, tributeRevealedCards);
//****************************TEST1**************************
printf("TEST 1: tributeRevealedCards[2] = one copper one province\n");
printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);

asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);
printf("----------\n");
printf("testing if the top revealed card is copper\n");
asserttrue(gameTest.deck[otherPlayer][gameTest.deckCount[otherPlayer]], copper);

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins)+extraCoins);

asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");

printf("Action Number = %d, expected = %d\n", gameTest.numActions, gameControl.numActions);

asserttrue(gameTest.numActions, gameControl.numActions);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));

asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");



//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);

memcpy (&gameTest, &gameControl, sizeof(struct gameState));
int tributeRevealedCards2[2] = {copper, copper};
gameTest.deck[otherPlayer][gameTest.deckCount[otherPlayer]++] = copper;
gameTest.deck[otherPlayer][gameTest.deckCount[otherPlayer]++] = copper;

//state->deck[nextPlayer][state->deckCount[nextPlayer]-1]

tributeCard(&gameTest, otherPlayer, thisPlayer, tributeRevealedCards2);
//****************************TEST1**************************
printf("TEST 2: reveal 2 cards of the same type\n");
printf("test");

printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins)+extraCoins);

asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");

printf("Action Number = %d, expected = %d\n", gameTest.numActions, gameControl.numActions);


asserttrue(gameTest.numActions, gameControl.numActions);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));


asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");






//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);

memcpy (&gameTest, &gameControl, sizeof(struct gameState));
int tributeRevealedCards3[2] = {copper, baron};
gameTest.deck[otherPlayer][gameTest.deckCount[otherPlayer]++] = copper;
gameTest.deck[otherPlayer][gameTest.deckCount[otherPlayer]++] = baron;

//state->deck[nextPlayer][state->deckCount[nextPlayer]-1]

tributeCard(&gameTest, otherPlayer, thisPlayer, tributeRevealedCards3);
//****************************TEST1**************************

printf("test");

printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins)+extraCoins);

asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");

printf("Action Number = %d, expected = %d\n", gameTest.numActions, gameControl.numActions);


asserttrue(gameTest.numActions, gameControl.numActions);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));






return 0;
}