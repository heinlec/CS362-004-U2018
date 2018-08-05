#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

#define TESTCARD "Salvager"

int main() {
	
	//srand(time(NULL));

    	int newCards = 0;
   	int discarded = 1;
   	int xtraCoins = 0;
   	int shuffledCards = 0;
	int choice1Failures = 0;
	int choice1Passes = 0;
	int numOfPasses = 0;
	int numOfFailures= 0;
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
                salvager,
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

	//make sure that the salvager card is actually in the player's hand
	state.hand[thisPlayer][0] = kingdom[2];

	//randomize the player's hand position
	handpos = rand() % (state.handCount[thisPlayer] + 1); //bounded by the player's hand count
	//randomize choice 1 to either gain coins (1) or discard card (0)
	choice1 = rand() % 2;	
	//printf("choice 1 = %d\n", choice1);
	cardEffect(salvager, choice1, choice2, choice3, &state, handpos, &bonus);
	
	if (choice1 == 1) {
		if (state.coins == state.coins + getCost(handCard(choice1, &state)) ) {
			choice1Passes++;
		//	printf("Passed\n");
		}
		else {
			choice1Failures++;
			//printf("Failed\n");
		}
	}
	else if (choice1 == 0) {
		if (state.hand[thisPlayer] == originalState.hand[thisPlayer] - 1 ) {
			numOfPasses++;
		}
		else {
			numOfFailures++;
		}
	}
}
	printf("Total number of passes when choosing to gain coins: %d\n", choice1Passes);
        printf("Total number of  failures when choosing to gain coins: %d\n", choice1Failures);
	printf("Total number of passes when choosing to discard a card: %d\n", numOfPasses);
	printf("Total number of failures when choosing to discard a card: %d\n", numOfFailures);
	return 0;
}


