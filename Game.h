#include<stdio.h>
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

void shuffleCards();
void printCardsShuffling();