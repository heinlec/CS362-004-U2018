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
	int trashFlag = 0;
	int handPos = 5;
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

	printf("Testing the function discardCard()\n\n");
	printf("Initializing the number of cards in the player's hand to 5...\n");
	state.handCount[currPlayer] = 5;
	//printf("%d", state.handCount[currPlayer]);	//debugging, was the hand count set to 5
	
	printf("Discarding one card, new hand count should be 4...\n");
	discardCard(handPos, currPlayer, &state, trashFlag);
	myAssertFunction(state.handCount[currPlayer], 4);

	printf("Discarding one card, new hand count should be 3...\n");
        discardCard(handPos, currPlayer, &state, trashFlag);
        myAssertFunction(state.handCount[currPlayer], 3);

	printf("Resetting hand count to 1 to test edge case...\n");
	state.handCount[currPlayer] = 1;
	discardCard(handPos, currPlayer, &state, trashFlag);
	myAssertFunction(state.handCount[currPlayer], 0);
	if (numOfFailures == 0) {
		printf("-------TESTING discardCard() COMPLETED--------\n\n");
	}
	else
		printf("-------THE FUNCTION NEEDS TO BE REVIEWED-----\n\n");
	return 0;
}
