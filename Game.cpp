#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

const int SUITS = 4;
const int FACES = 13;

char *suits[SUITS] = {"\3", "\4", "\5", "\6"};
char *faces[FACES] = {"Ace", "2", "3", "4", "5",
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
    for (int num = 1; num <= 5; num++) {
        for (int i = 0; i < SUITS; i++) {
            for (int j = 0; j < FACES; j++) {
                if (deck[i][j] == num) {
                    result[t][0] = i;
                    result[t][1] = j;
                    t++;
                }
            }
        }
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
    for (int i = 0; i < 5; i++) {
        cout << faces[hand[i][1]] << suits[hand[i][0]] << "\t" << endl;
    }

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

int main() {

    int deck[SUITS][FACES] = {0};
    //shuffleCards(deck);
    //printCardsShuffling(deck, suits, faces);
    //int** result = dealingForHand(deck);
    //printHand(result, suits, faces);
    int check = isFourOfAKind(result);
    cout << check;
    return 0;
}
