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

	printf("Testing the function getCost()\n\n");
	
	printf("Verifying the cost of the first five kingdom cards from the hand...\n");

	printf("Adventurer cost should be 6: \n");
	myAssertFunction(getCost(adventurer), 6);
	printf("Smithy cost should be 4: \n");
        myAssertFunction(getCost(smithy), 4);
	printf("Gardens cost should be 4: \n");
        myAssertFunction(getCost(gardens), 4);
	printf("Embargo cost should be 2: \n");
        myAssertFunction(getCost(embargo), 2);
	printf("Minion cost should be 5: \n");
        myAssertFunction(getCost(minion), 5);

	if (numOfFailures == 0) {
		printf("-------TESTING getCost() COMPLETED--------\n\n");
	}
	else
		printf("-------THE FUNCTION NEEDS TO BE REVIEWED-----\n\n");
	return 0;
}
