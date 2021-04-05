#include <stdio.h>
#include <time.h> //time function
#include <stdlib.h> //random number generator functions
#include <string.h>
#include <iostream>
#define MAX 9
#define MAX_CARDS 52
#define FACES 13
#define SUITS 4
#define COLS 3
using namespace std;

char *suits[SUITS] = {"\3", "\4", "\5", "\6"};
char *faces[FACES] = {"Ace", "2", "3", "4", "5",
"6", "7", "8", "9", "10", "Jack", "Queen", "King"};

void shuffleCards(int deck[4][13])
{
	int arr[MAX_CARDS] = {0};
	int swapper = 0;
	int temp = 0;
	srand(time(NULL));
	for ( int i = 0; i < MAX_CARDS ; i++)
		arr[i] = i;
	for ( int i = 0; i < MAX_CARDS; i++)
	{
		swapper = rand() % MAX_CARDS ;
		temp = arr[i];
		arr[i] = arr[swapper];
		arr[swapper] = temp;
	}

	int t = 0; 
    for (int i = 0; i < SUITS; i++) 
	{
        for (int j = 0; j < FACES; j++) 
		{
            deck[i][j] = arr[t];
            t++;
		}
	}
}
void printCardsShuffling(int deck[4][13], char *suits[], char *faces[])
{
	for ( int i = 0; i < SUITS; i++) 
	{
		for ( int j = 0; j < FACES; j++)
		{
			//cout << faces[deck[i][j] / 4] << suits[deck[i][j] % 4] << "\t";
			cout << deck[i][j] << " ";
		}
		cout << "\n";
	};
}

int** dealingForHand(int deck[SUITS][FACES])
{
	//Tạo mảng 2 chiều = array
	int temp[MAX_CARDS] = {0};
	int t = 0;
	int **arr = new int *[5];
	for ( int i = 0; i < 5; i++)
		arr[i] = new int[2];

	for ( int i = 0; i < SUITS; i++)
	{
		for ( int j = 0; j < FACES; j++)
		{
			temp[t] = deck[i][j];
			t++;
		}
	}
	t = 0;
	for ( int i = 0; i < 5; i++)
	{
			arr[i][0] = temp[t] / 4;
			t++;
	}
	t = 0;
	for ( int i = 0; i < 5; i++)
	{
		arr[i][1] = temp[t] % 4;
		t++;
	}
	return arr;
}
void printHand(int** hand, char* suits[], char* faces[])
{
	for ( int i = 0; i < 5; i++)
	{
		cout << faces[hand[i][0]];
		cout << suits[hand[i][1]];
		cout << "\n";
	}
}	
//int isFourOfAKind(int **hand)


int main()
{
	int deck[4][13] = {0};
	shuffleCards(deck);
	printCardsShuffling(deck,suits,faces);
	//dealingForHand(deck);
	//printHand(dealingForHand(deck),suits,faces);
	return 0;	
}

