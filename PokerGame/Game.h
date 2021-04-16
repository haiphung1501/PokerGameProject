
#include <stdio.h>
#include <time.h> //time function
#include <stdlib.h> //random number generator functions
#include <string.h>
#include <iostream>
using namespace std;

//Define 
#define MAX 9
#define MAX_CARDS 52
#define FACES 13
#define SUITS 4
#define COLS 3

char* suits[SUITS] = {"\3", "\4", "\5", "\6"};
char* faces[FACES] = {"A", "2", "3", "4", "5",
"6", "7", "8", "9", "10", "J", "Q", "K"};


void shuffleCards(int deck[4][13]);
void printCardsShuffling(int deck[4][13], char *suits[], char *faces[]);
int** dealingForHand(int deck[SUITS][FACES]);
void printHand(int** hand, char* suits[], char* faces[]);
int isFourOfAKind(int** hand);
int isFlush(int** hand);
int isThreeOfAKind(int** hand);
int isStraight(int** hand);
int isStraightFlush(int** hand);
int isPair(int** hand);
int isTwoPairs(int** hand);
int isFullHouse(int** hand);
int getHighestCard(int** hand);
int*** dealingForHandsS(int deck[SUITS][FACES], int n);
int getStatusOfHand(int** hand);
int** convertHands(int***hand, int pos);
int* rankingHands(int*** hand, int n);
void printHandS(int*** hand, char* suits[], char* faces[], int n);
void evaluateHands(int deck[SUITS][FACES], int***hand,
int people, int rounds, char* suits[], char* faces[]);
void printHandsAllDealer(int*** hand, char* suits[], char* faces[], int n);
void PlayWithDealer();
void PlayerAndDealer();
void Easy();
void Medium();
void Hard();
void SinglePlayer();
void PlayerVsPlayer();
















