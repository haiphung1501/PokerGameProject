#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

const int SUITS = 4;
const int FACES = 13;

char* suits[SUITS] = {"\3", "\4", "\5", "\6"};
char* faces[FACES] = {"Ace", "2", "3", "4", "5",
"6", "7", "8", "9", "10", "Jack", "Queen", "King"};

//ham shuffle Cards
void shuffleCards(int deck[SUITS][FACES]) {
    int temp[51];

    //tao mang temp co gia tri tu 1 - 52
    for (int i = 0; i < 52; i++) {
        temp[i] = i + 1;
    }

    //xao tron cac phan tu trong mang temp
    srand(time(NULL)); 
    random_shuffle(temp, temp + 52);
    
    //gan deck bang cac phan tu trong temp
    int t = 0; 
    for (int i = 0; i < SUITS; i++) {
        for (int j = 0; j < FACES; j++) {
            deck[i][j] = temp[t];
            t++;
        }
    }

/*    //print deck[][]
    int count = 1;
    for (int i = 0; i < SUITS; i++) {
        for (int j = 0; j < FACES; j++) {
            cout << deck[i][j] << "\t";
            if (count % 4 == 0) {
                cout << endl;
            }
            count++;
        }
    }
    cout << endl << endl;*/
}
//in ra Cards Shuffling
void printCardsShuffling(int deck[SUITS][FACES], char *suits[], char *faces[]) {
	//print deck
    for (int num = 1; num <= 52; num++) {
        for (int i = 0; i < SUITS; i++) {
            for (int j = 0; j < FACES; j++) {
                if (deck[i][j] == num) {
                    cout << faces[j]<< suits[i] << "\t" << num << endl;
                }
            }
        }
    }
}
//luu gia tri cac quan bai cua nguoi choi
int** dealingForHand(int deck[SUITS][FACES]) {

    //khoi tao con tro result
    int** result = new int*[5];
    for (int i = 0; i < 5; i++) {
        result[i] = new int[2];
    }

    int t = 0; //t1 la bieu thi cho quan bai trong result

    //duyet gia tri tim 5 la bai dau tien
    int num = 1;
    int ok = 0;
    while (num <= 5) {
        for (int i = 0; i < SUITS; i++) {
            for (int j = 0; j < FACES; j++) {
                if (deck[i][j] == num) {
                    result[t][0] = i;
                    result[t][1] = j;
                    t++;
                    ok = 1;
                    break;
                }
            }
            if (ok == 1) {
                break;
            }
        }
        ok = 0;
        num++;
    }
    return result;
}
//in ra cac la bai tren tay nguoi choi
void printHand(int** hand, char* suits[], char* faces[]) {
    //check
    /*for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            cout << hand[i][j] << "\t";
        }
        cout << endl;
    }*/
    //check
    // for (int i = 0; i < 5; i++) {
    //     cout << faces[hand[i][1]] << suits[hand[i][0]] << "\t" << endl;
    // }

    // cout << endl << endl;
    
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (hand[i][1] > hand[j][1]) {
                swap(hand[i][1], hand[j][1]);
                swap(hand[i][0], hand[i][0]);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << faces[hand[i][1]] << suits[hand[i][0]] << "\t" << endl;
    }

}
//check fourofakind
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

int***dealingForHands(int deck[SUITS][FACES], int n) {
    int*** results = new int**[n];
    for (int i = 0; i < n; i++) {
        results[i] = new int*[5];
        for (int j = 0; j < 5; i++) {
            results[i][j] = new int[2];
        }
    }

    int t = 0; //t1 la bieu thi cho quan bai trong result

    //duyet gia tri tim 5 la bai dau tien
    int num = 1;
    int ok = 0;
    for (int p = 0; p < n; p++) {
        while (num <= 5) {
            for (int i = 0; i < SUITS; i++) {
                for (int j = 0; j < FACES; j++) {
                    if (deck[i][j] == num) {
                        results[p][t][0] = i;
                        results[p][t][1] = j;
                        t++;
                        ok = 1;
                        break;
                    }
                }
                if (ok == 1) {
                    break;
                }
            }
            ok = 0;
            num++;
        }
    }
    return results;
}

void printHands(int*** hand, char* suits[], char* faces[]) {
    int x;
    cout << "nhap vao nguoi choi muon xem bai: ";
    cin >> x;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (hand[i][1] > hand[j][1]) {
                swap(hand[x - 1][i][1], hand[x - 1][j][1]);
                swap(hand[x - 1][i][0], hand[x - 1][i][0]);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << faces[hand[x - 1][i][1]] << suits[hand[x - 1][i][0]] << "\t" << endl;
    }
}

int main() {

    int deck[SUITS][FACES] = {0};
    // shuffleCards(deck);
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

    return 0;
}
