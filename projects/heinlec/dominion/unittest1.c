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
	//int currPlayer = 0;
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

	printf("Testing the function isGameOver()\n\n");
	
	printf("Game is over if the Province Supply Pile is empty\n");
	printf("Setting the Supply Pile to empty...\n");
	state.supplyCount[province] = 0;
	myAssertFunction(isGameOver(&state), 1);
	printf("Resetting the Supply Pile so it is no longer empty...\n");
	state.supplyCount[province] = 1;
	myAssertFunction(isGameOver(&state), 0);

	printf("Game is over if any three Supply Piles are empty\n");
        printf("Setting the Supply Piles to empty...\n");
        state.supplyCount[0] = 0;
	state.supplyCount[1] = 0;
	state.supplyCount[2] = 0;
        myAssertFunction(isGameOver(&state), 1);
	printf("Resetting the Supply Piles so they are no longer empty...\n");
        state.supplyCount[0] = 1;
        state.supplyCount[1] = 1;
        state.supplyCount[2] = 1;
        myAssertFunction(isGameOver(&state), 0);

	if (numOfFailures == 0) {
		printf("-------TESTING isGameOver() COMPLETED--------\n\n");
	}
	else
		printf("-------THE FUNCTION NEEDS TO BE REVIEWED-----\n\n");
	return 0;
}
