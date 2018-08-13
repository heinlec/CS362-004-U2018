#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

#define TESTCARD "Adventurer"

int main() {
	
	srand(time(NULL));

    	int newCards = 0;
   	int discarded = 1;
   	int xtraCoins = 0;
   	int shuffledCards = 0;


	int numOfPasses;
	int numOfFailures;
	int currTreasure = 0;
	int origTreasure = 0;
	int card;   
	int i, j, m;
   	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  	int remove1, remove2;
   	int seed = 1000;
	//the game can have 2-10 players
	int numPlayers = (rand() % 9) + 2;
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

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	for (j = 0; j < 2000; j++) {

	// initialize a game state and player cards
	initializeGame(numPlayers, kingdom, seed, &state);

	// copy the game state to a test case
	memcpy(&originalState, &state, sizeof(struct gameState));

	//make sure that the adventurer card is actually in the player's hand
	state.hand[thisPlayer][0] = kingdom[0];

	//randomize the player's hand position
	handpos = rand() % (state.handCount[thisPlayer] + 1); //bounded by the player's hand count
		
	cardEffect(adventurer, choice1, choice2, choice3, &state, handpos, &bonus);
	
	
	//printf("Player 1 should gain two treasure cards...\n");
	for (i = 0; i < state.handCount[thisPlayer]; i++) {
		card = state.hand[thisPlayer][i];
		if (card == copper || card == silver || card == gold) {
			currTreasure++;
		}
	}
	
	if (currTreasure == 2) {
		numOfPasses++;
	//	printf("Passed\n");
	}
	else {
		numOfFailures++;
	//	printf("Failed\n");
	}
}

	printf("Total number of passes: %d out of %d\n", numOfPasses, 2000);
	printf("Total number of failures: %d out of %d\n", numOfFailures, 2000);
	return 0;
}


