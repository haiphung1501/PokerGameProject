#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>

#define MAX 9
#define MAX_CARDS 52
#define FACES 13
#define SUITS 4
#define COLS 3

using namespace std;

char* suits[SUITS] = {"\3", "\4", "\5", "\6"};
char* faces[FACES] = {"A", "2", "3", "4", "5",
"6", "7", "8", "9", "10", "J", "Q", "K"};

//ham shuffle Cards
void shuffleCards(int deck[SUITS][FACES]) {
    int arr[MAX_CARDS] = {0};
	int swapper = 0;
	int temp = 0;
	srand(time(NULL));
	for ( int i = 0; i < MAX_CARDS ; i++) {
		arr[i] = i;
    }
	for ( int i = 0; i < MAX_CARDS; i++) {
		swapper = rand() % MAX_CARDS ;
		temp = arr[i];
		arr[i] = arr[swapper];
		arr[swapper] = temp;
	}

	int t = 0; 
    for (int i = 0; i < SUITS; i++) {
        for (int j = 0; j < FACES; j++) {
            deck[i][j] = arr[t];
            t++;
		}
	}
}
//in ra Cards Shuffling
void printCardsShuffling(int deck[SUITS][FACES], char *suits[], char *faces[]) {
	//print deck
    for ( int i = 0; i < SUITS; i++) {
		for ( int j = 0; j < FACES; j++) {
			//cout << faces[deck[i][j] / 4] << suits[deck[i][j] % 4] << "\t";
			cout << deck[i][j] << " ";
		}
		cout << endl;
	}
}
//luu gia tri cac quan bai cua nguoi choi
int** dealingForHand(int deck[SUITS][FACES]) {
    //tao mang 2 chieu = array
	int temp[MAX_CARDS] = {0};
	int t = 0;
	int **result = new int *[5];
	for ( int i = 0; i < 5; i++)
		result[i] = new int[2];

	for ( int i = 0; i < SUITS; i++) {
		for ( int j = 0; j < FACES; j++) {
			temp[t] = deck[i][j];
			t++;
		}
	}
	t = 0;
	for ( int i = 0; i < 5; i++) {
			result[i][1] = temp[t] / 4;
			t++;
	}
	t = 0;
	for ( int i = 0; i < 5; i++) {
		result[i][0] = temp[t] % 4;
		t++;
	}
	//Sorting Cards
	for ( int i = 0;  i < 4 ; i++){
		for ( int j = i + 1; j < 5; j++) {
			if ( result[i][1] > result[j][1]) {
				swap(result[i][1], result[j][1]);
                swap(result[i][0], result[j][0]);
			}
		}
	}
	return result;
}
//in ra cac la bai tren tay nguoi choi
void printHand(int** hand, char* suits[], char* faces[]) {
    for (int i = 0; i < 5; i++) {
        cout << faces[hand[i][1]] << suits[hand[i][0]] << "\t" << endl;
    }
}
//check four of a kind
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
//check three of a kind
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
// check 2 pairs
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
//int** createHandTest(int deck[SUITS][FACES]), int a[]) {}
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
//chia bai cho n nguoi choi
int***dealingForHands(int deck[SUITS][FACES], int n) {
    int*** results = new int**[n];
    for (int i = 0; i < n; i++) {
        results[i] = new int*[5];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            results[i][j] = new int[2];
        }
    }

    int temp[MAX_CARDS] = {0};
	int t = 0;
    for ( int i = 0; i < SUITS; i++) {
		for ( int j = 0; j < FACES; j++) {
			temp[t] = deck[i][j];
			t++;
		}
	}
	t = 0;
    for (int p = 0; p < n; p++) {
        for ( int i = 0; i < 5; i++) {
                results[p][i][1] = temp[t] / 4;
                t++;
        }
    }
	t = 0;
    for (int p = 0; p < n; p++) {
        for ( int i = 0; i < 5; i++) {
            results[p][i][0] = temp[t] % 4;
            t++;
        }
    }
	//Sorting Cards
    for (int p = 0; p < n; p++) {
        for ( int i = 0;  i < 4 ; i++){
            for ( int j = i + 1; j < 5; j++) {
                if ( results[p][i][1] > results[p][j][1]) {
                    swap(results[p][i][1], results[p][j][1]);
                    swap(results[p][i][0], results[p][j][0]);
                }
            }
        }
    }
    return results;
}
//in ra bai tren tay nguoi choi mong muon
void printHands(int*** hand, char* suits[], char* faces[]) {
    int x;
    cout << "nhap vao nguoi choi muon xem bai: ";
    cin >> x;
    for (int i = 0; i < 5; i++) {
        cout << faces[hand[x - 1][i][1]] << suits[hand[x - 1][i][0]] << "\t" << endl;
    }
}
//in ra bai cua tat ca moi nguoi
void printHandsAll(int*** hand, char* suits[], char* faces[], int n) {
    cout << endl << "bai cua moi nguoi";
    for (int p = 0; p < n; p++) {
        cout << "nguoi choi thu " << p + 1 << ":" << endl; 
        for (int i = 0; i < 5; i++) {
            cout << faces[hand[p][i][1]] << suits[hand[p][i][0]] << "\t" << endl;
        }
        cout << "-------------------------------------------" << endl;
    }
}

int main() {

    int deck[SUITS][FACES] = {0};
    shuffleCards(deck);
    // printCardsShuffling(deck, suits, faces);
    // int** result = dealingForHand(deck);

    // check truc tiep
    // int** result = new int*[5];
    // for (int i = 0; i < 5; i++) {
    //     result[i] = new int[2];
    // }
    // result[0][0] = 0; result[0][1] = 2;
    // result[1][0] = 3; result[1][1] = 0;
    // result[2][0] = 2; result[2][1] = 0;
    // result[3][0] = 1; result[3][1] = 1;
    // result[4][0] = 1; result[4][1] = 0;

    // printHand(result, suits, faces);

    // cout << getHighestCard(result);

    int n;
    cout << "nhap vao so nguoi choi: ";
    cin >> n;
    int***results = dealingForHands(deck, n);
    printHands(results, suits, faces);
    cout << "-------------------------------------------" << endl;
    printHandsAll(results, suits, faces, n);
    return 0;
}
