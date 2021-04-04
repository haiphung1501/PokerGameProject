#include <Game.h>
int main()
{
	int deck[4][13] = {0};
	shuffleCards(deck);
	printCardsShuffling(deck,suits,faces);
	return 0;	
}

