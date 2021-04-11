
#include "Game.cpp"
#include "Display.cpp"

int main()
{
    srand(time(NULL));
	int deck[4][13] = {0};
    int n = 4;
    int rounds = 5;
	//printCardsShuffling(deck,suits,faces);
    //dealingForHand(deck);
	//printHand(dealingForHand(deck),suits,faces);
    //getHighestCard(result);
	//dealingForHandsS(deck,n);
	//printHandS(dealingForHandsS(deck,n),suits,faces,n);
    //rankingHands(dealingForHandsS(deck,n), n);
    //evaluateHands(deck,dealingForHandsS(deck,n), n, rounds, suits, faces);

    printPokerText();
    	//cout << getHighestCard(result);
	return 0;	

}

