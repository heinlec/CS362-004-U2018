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

#define TESTCARD "Steward"

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
	choice1 = 1;
	cardEffect(steward, choice1, choice2, choice3, &state, handpos, &bonus);
	
	printf("Testing option 1: player gains two cards\n");
	printf("Player 1 should gain two cards...\n");
	myAssertFunction(state.handCount[thisPlayer], originalState.handCount[thisPlayer]+2-discarded);
	
	printf("Player 1 should gain two cards from their own pile...\n");
	myAssertFunction(state.deckCount[thisPlayer], originalState.deckCount[thisPlayer]-2);

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

	printf("Testing option 2: player gains two coins\n");
	// copy the game state to a test case
	memcpy(&originalState, &state, sizeof(struct gameState));
        choice1 = 2;
        cardEffect(steward, choice1, choice2, choice3, &state, handpos, &bonus);

        printf("Player 1 hand count should not be modified...\n");
        myAssertFunction(state.handCount[thisPlayer], originalState.handCount[thisPlayer]-discarded);

        printf("Player 1 deck count should not be modified...\n");
        myAssertFunction(state.deckCount[thisPlayer], originalState.deckCount[thisPlayer]);

	printf("Player 1 should gain two coins...\n");
	myAssertFunction(state.coins, originalState.coins+2);

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

	printf("Testing option 3: player trashes two cards\n");
	// copy the game state to a test case
	memcpy(&originalState, &state, sizeof(struct gameState));
        choice1 = 3;
        cardEffect(steward, choice1, choice2, choice3, &state, handpos, &bonus);

        printf("Player 1 should trash two cards...\n");
        myAssertFunction(state.handCount[thisPlayer], originalState.handCount[thisPlayer]-3);

        printf("Player 1 deck count should not be modified...\n");
        myAssertFunction(state.deckCount[thisPlayer], originalState.deckCount[thisPlayer]);

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


	return 0;
}


