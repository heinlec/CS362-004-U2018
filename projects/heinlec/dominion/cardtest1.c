/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Ambassador"

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
	
   	int discarded = 1;
	int currTreasure = 0;
	int origTreasure = 0;
	int card;   
	int i, j, m;
   	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
   	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int player2 = 1;
	struct gameState state, originalState;
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

	// initialize a game state and player cards
	initializeGame(numPlayers, kingdom, seed, &state);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&originalState, &state, sizeof(struct gameState));
	cardEffect(ambassador, choice1, choice2, choice3, &state, handpos, &bonus);
	
	printf("The supply count for the chosen card should be increased by the amount being discarded...\n");
	myAssertFunction(state.supplyCount[thisPlayer], originalState.supplyCount[thisPlayer]);
	
	printf("Player 1 should not gain a card and should discard the played card...\n");
	myAssertFunction(state.handCount[thisPlayer], originalState.handCount[thisPlayer]-1);

	printf("Player 2 should gain a card...\n");
        myAssertFunction(state.handCount[player2], originalState.handCount[player2]+1);

	printf("The Victory card piles should not have been modified\n");
	printf("Checking the Province pile...\n");
	myAssertFunction(state.supplyCount[province], originalState.supplyCount[province]);
	printf("Checking the Duchy pile...\n");
        myAssertFunction(state.supplyCount[duchy], originalState.supplyCount[duchy]);	
	printf("Checking the Estate pile...\n");
        myAssertFunction(state.supplyCount[estate], originalState.supplyCount[estate]);

	printf("The Kingdom card piles should not have been modified. Checking each pile...\n");
	for (i = 0; i < 10; i++) {
		myAssertFunction(state.supplyCount[kingdom[i]], originalState.supplyCount[kingdom[i]]);
	}

	if (numOfFailures == 0) {
                printf("-------TESTING card %s COMPLETED--------\n\n", TESTCARD);
        }
        else
                printf("-------THE FUNCTION NEEDS TO BE REVIEWED-----\n\n");

	return 0;
}


