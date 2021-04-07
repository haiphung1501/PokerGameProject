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
	int **result = new int *[5];
	for ( int i = 0; i < 5; i++)
		result[i] = new int[2];

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
			result[i][1] = temp[t] / 4;
			t++;
	}
	t = 0;
	for ( int i = 0; i < 5; i++)
	{
		result[i][0] = temp[t] % 4;
		t++;
	}
	//Sorting Cards
	int test = 0;
	int test_1 = 0;
	for ( int i = 0;  i < 4 ; i++){
		for ( int j = i + 1; j < 5; j++)
		{
			if ( result[i][1] > result[j][1])
			{
				test = result[i][1];
				result[i][1] = result[j][1];
				result[j][1] = test;

				test_1 = result[i][0];
				result[i][0] = result[j][0];
				result[j][0] = test_1;
			}
		}
	}
	return result;
}
void printHand(int** hand, char* suits[], char* faces[])
{
	for ( int i = 0; i < 5; i++)
		cout << faces[hand[i][1]] << suits[hand[i][0]] << "\n";
}	

int isFourOfAKind(int** hand) {
    int count = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5;j++) {
            if (hand[i][1] == hand[j][1]) {
                count++;
            }
        }
        if (count == 4) {
            return 1;
        }
        else {
            count = 1;
        }
    }
    return 0;
}
int isFlush(int** hand) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5;j++) {
            if (hand[i][0] != hand[j][0]) {
                return 0;
            }
        }
    }
    return 1;
}
int isThreeOfAKind(int** hand) {
    int count = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5;j++) {
            if (hand[i][1] == hand[j][1]) {
                count++;
            }
        }
        if (count == 3) {
            return 1;
        }
        else {
            count = 1;
        }
    }
    return 0;
}
int isStraight(int** hand) {
	if ( hand[0][1] == 0 && hand[1][1] == 9)
	{
		for ( int i = 0; i < 4; i++)
		{
			if (hand[i][1] != hand[i+1][1] - 1)
				return 0;
		}
		return 1;
	}
	else 
	{
		for ( int i = 0; i < 4; i++	)
		{
			if ( hand[i][1] != hand[i+1][1] - 1)
				return 0;
		}
	}
	return 1;
}
int isPair(int** hand)
{
    int count = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5;j++) {
            if (hand[i][1] == hand[j][1]) {
                count++;
            }
        }
        if (count == 2) {
            return 1;
        }
        else {
            count = 1;
        }
    }
	return 0;
}
int isTwoPairs(int** hand){
	int count = 1;
	for ( int i = 0; i < 4; i++)
	{
		for ( int j = i + 1; j < 5; j++)
		{
			if (hand[i][1] == hand[j][1])
				count++;
		}
	}
	if ( count == 3)
		return 1;
	return 0;
}
int isFullHouse(int** hand)
{
	if (isThreeOfAKind(hand) == 0)
		return 0;
	int ThreeOfAKind = 0;
	//code three of a kind to find a temporary variable
	int count = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5;j++) {
            if (hand[i][1] == hand[j][1]) {
                count++;
            }
        }
        if (count == 3)
            ThreeOfAKind = hand[i][1];
		else
			count == 1;
    }

	count = 1;
    for (int i = 0; i < 4; i++) {
		count = 1;
        for (int j = i + 1; j < 5;j++) 
		{
            if (hand[i][1] == hand[j][1]) 
                count++;
        }
        if (count == 2 && hand[i][1] != ThreeOfAKind) 
			return 1;
    }
	return 0;
	
}
int main()
{
	int deck[4][13] = {0};
	int** result = new int*[5];
    for (int i = 0; i < 5; i++) {
        result[i] = new int[2];
    }
    result[0][0] = 1; result[0][1] = 3;
    result[1][0] = 2; result[1][1] = 3;
    result[2][0] = 3; result[2][1] = 3;
    result[3][0] = 0; result[3][1] = 1;
    result[4][0] = 1; result[4][1] = 1;
	//shuffleCards(deck);
	//printCardsShuffling(deck,suits,faces);
	//dealingForHand(deck);
	printHand(result,suits,faces);
	cout << " " << isFullHouse(result);
	return 0;	

}

