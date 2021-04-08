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
			//cout << faces[deck[i][j] / 4] << suits[deck[i][j] % 4] << " ";
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
    int* temp = new int[13]; //tao mot mang chua so lan xuat hien cua cac la bai
    for (int i = 0; i < 13; i++) { //khoi tao gia tri = 0
        temp[i] = 0;
    }
    for (int i = 0; i < 5; i++) {//dem so lan xuat hien cua cac quan bai
        temp[hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {//xet tu quy
        if (temp[i] == 4) {
            return 1;
        }
    }

    return 0;
}
//check flush
int isFlush(int** hand) {
    int* temp = new int[4]; //tao mot mang chua so lan xuat hien cua 4 chat
    for (int i = 0; i < 4; i++) { //khoi tao gia tri = 0
        temp[i] = 0;
    }
    for (int i = 0; i < 5; i++) { //dem so lan xuat hien cua cac chat
        temp[hand[i][0]]++;
    }
    for (int i = 0; i < 4; i++) { //xet thung
        if (temp[i] == 5) {
            return 1;
        }
    }
    return 0;
}
//check threeofakind
int isThreeOfAKind(int** hand) {
    int* temp = new int[13]; //tao mot mang chua so lan xuat hien cua cac la bai
    for (int i = 0; i < 13; i++) { //khoi tao gia tri = 0
        temp[i] = 0;
    }
    for (int i = 0; i < 5; i++) { //dem so lan xuat hien cua cac la bai
        temp[hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) { //xet 3 la
        if (temp[i] == 3) {
            return 1;
        }
    }
    return 0;
}
//check straight
int isStraight(int** hand) {
    int* temp = new int[5];
    for (int i = 0; i < 5; i++) {
        temp[i] = hand[i][1];
    }

    //check temp
    // for (int i = 0; i < 5; i++) {
    //     cout << temp[i] << " ";
    // }

    if (temp[0] == 0 && temp[1] == 9) { //xet truong hop 10 J Q K A
        for (int i = 1; i < 4; i++) {
            if (temp[i] != temp[i+1] - 1) {
                return 0;
            }
        }
        return 1;
    }
    else { //truong hop binh thuong
        for (int i = 0; i < 4; i++) {
            if (temp[i] != temp[i+1] - 1) {
                return 0;
            }
        }
    }
    return 1;
}
//check straightflush
int isStraightFlush(int** hand) {
    if (isStraight(hand) && isFlush(hand)) {
        return 1;
    }
    return 0; 
}
//check 1 pair
int isPair(int** hand) {
    int* temp = new int[13]; //tao mot mang chua so lan xuat hien cua 13 la bai
    for (int i = 0; i < 13; i++) { //khoi tao gia tri = 0
        temp[i] = 0;
    }
    for (int i = 0; i < 5; i++) {//dem so lan xuat hien cua cac quan bai
        temp[hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {//xet 1 doi
        if (temp[i] == 2) {
            return 1;
        }
    }

    return 0;
}
// chech 2 pairs
int isTwoPairs(int** hand) {
    int* temp = new int[13]; //tao mot mang chua so lan xuat hien cua 13 la bai
    for (int i = 0; i < 13; i++) { //khoi tao gia tri = 0
        temp[i] = 0;
    }
    for (int i = 0; i < 5; i++) {//dem so lan xuat hien cua cac quan bai
        temp[hand[i][1]]++;
    }
    int count = 0;
    for (int i = 0; i < 13; i++) {//dem so doi
        if (temp[i] == 2) {
            count++;
        }
    }
    if (count == 2) { //xet 2 doi
        return 1;
    }
    return 0;
}
// check fullhouse
int isFullHouse(int** hand) {
    if (isPair(hand) && isThreeOfAKind(hand)) { //xet cu lu
        return 1;
    }
    return 0;
}
//test
//int** createHandTest(int deck[SUITS][FACES], int a[])
//lay gia tri cao nhat
int getHighestCard(int** hand) {
    if (isStraightFlush(hand)) {
        return 8;
    }
    if (isFourOfAKind(hand)) {
        return 7;
    }
    if (isFullHouse(hand)) {
        return 6;
    }
    if (isFlush(hand)) {
        return 5;
    }
    if (isStraight(hand)) {
        return 4;
    }
    if (isThreeOfAKind(hand)) {
        return 3;
    }
    if (isTwoPairs(hand)) {
        return 2;
    }
    if (isPair(hand)) {
        return 1;
    }
    return 0;
}
int*** n_dealingForHands(int deck[SUITS][FACES], int n)
{
	int pos = 0;
	int t = 0;
	//Mang 1 chieu de luu tu 1 -> 52
	int cards[MAX_CARDS];
    //Mang 2 chieu [so thu tu nguoi choi][so thu tu la bai]
    int** temp = new int*[n];
    for ( int i = 0; i < n; i++)
        temp[i] = new int[5];
    //mang 3 chieu [so thu tu nguoi choi][suits][faces]
    int*** result = new int**[n];
    for ( int i = 0; i < n; i++)
        result[i] = new int* [5];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            result[i][j] = new int[2];
        }
    }
    //Gan gia tri cua deck vao mang 1 chieu cards de xet cho de
	for ( int i = 0; i < SUITS; i++)
	{
		for ( int j = 0; j < FACES; j++)
		{
			cards[t] = deck[i][j];
			t++;
		}
	}
	t = 0;
    //Gan gia tri cua mang 1 chieu lan luot vao mang 2 chieu ( chia lan luot)
	for ( int i = 0; i < 5 * n; i++)
	{
		temp[pos][t] = cards[i];
		pos++;
		if ( pos == n) 
		{
			pos = 0;
			t++;
		}
	}
    //Gan vao mang 3 chieu
    while (pos != n )
	{
		for ( int i = 0; i < 5; i++)
        {
            result[pos][i][0] = temp[pos][i] % 4;
            result[pos][i][1] = temp[pos][i] / 4;
        }
		pos++;
	}
    return result;
}
void n_printHand(int*** hand, char* suits[], char* faces[], int n)
{
	int pos = 0;
	while (pos != n )
	{
		for ( int i = 0; i < 5; i++)
			cout << faces[hand[pos][i][1]] << suits[hand[pos][i][0]] << " ";
        cout << endl;
		pos++;
	}
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
    result[2][0] = 3; result[2][1] = 0;
    result[3][0] = 0; result[3][1] = 1;
    result[4][0] = 1; result[4][1] = 1;
	shuffleCards(deck);
	printCardsShuffling(deck,suits,faces);
	n_dealingForHands(deck,3);
	n_printHand(n_dealingForHands(deck,3),suits,faces,3);
	//dealingForHand(deck);
	//printHand(dealingForHand(deck),suits,faces);
	//cout << getHighestCard(result);
	return 0;	

}

