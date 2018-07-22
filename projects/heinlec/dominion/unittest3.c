#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// counter that holds the number of test failures 
int numOfFailures = 0;

// template for the assert function pulled from here: https://piazza.com/class/jino9xi6ivg1h3?cid=46
// if the two ints are equal print PASSED, otherwise print FAILED
void myAssertFunction(int a, int b) {
	if (a == b) {
		printf("Test: PASSED\n");
	}
	else {
		printf("Test: FAILED\n");
		numOfFailures++;
	}
}

int main() {

	//start a new game and initialize the starting values
	int numPlayers = 2;
	int currPlayer = 0;
	int seed = 100;
	int kingdom[10] = {
		adventurer,
		smithy,
		gardens,
		embargo,
		minion, 
		village,
		mine, 
		sea_hag,
		cutpurse,
		tribute, };
	struct gameState state;
	initializeGame(numPlayers, kingdom, seed, &state);

	printf("Testing the function drawCard())\n\n");

	printf("Initializing the player's hand to have 3 cards...\n");
	int cardsInHand = 3;
	state.handCount[currPlayer] = cardsInHand;
	//printf("%d", state.handCount[currPlayer]);	//debugging, do we have 3 cards in hand
	
	printf("Drawing one card, player should now have four cards in hand...\n");
	drawCard(currPlayer, &state);
	//does the player now have 4 cards in hand
	myAssertFunction(state.handCount[currPlayer], 4);
	
	printf("Drawing one card, player should now have five cards in hand...\n");
        drawCard(currPlayer, &state);
        //does the player now have 5 cards in hand
        myAssertFunction(state.handCount[currPlayer], 5);	

	if (numOfFailures == 0) {
		printf("-------TESTING drawCard() COMPLETED--------\n\n");
	}
	else
		printf("-------THE FUNCTION NEEDS TO BE REVIEWED-----\n\n");
	return 0;
}
