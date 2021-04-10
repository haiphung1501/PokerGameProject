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
	
	for (int i = 0; i < MAX_CARDS ; i++) {
		arr[i] = i;
    }
	for (int i = 0; i < MAX_CARDS; i++) {
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
    for (int i = 0; i < SUITS; i++) {
		for (int j = 0; j < FACES; j++) {
			cout << faces[deck[i][j] / 4] << suits[deck[i][j] % 4] << "\n";
			//cout << deck[i][j] << " ";
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
	for (int i = 0; i < 5; i++)
		result[i] = new int[2];

	for (int i = 0; i < SUITS; i++) {
		for (int j = 0; j < FACES; j++) {
			temp[t] = deck[i][j];
			t++;
		}
	}
	t = 0;
	for (int i = 0; i < 5; i++) {
			result[i][1] = temp[t] / 4;
			t++;
	}
	t = 0;
	for (int i = 0; i < 5; i++) {
		result[i][0] = temp[t] % 4;
		t++;
	}
	//Sorting Cards
	for (int i = 0;  i < 4 ; i++){
		for (int j = i + 1; j < 5; j++) {
			if (result[i][1] > result[j][1]) {
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
    int max = hand[0][1];
    for (int i = 0; i < 5; i++) {
        if (hand[i][1] == 0)
            return 13;
        if (hand[i][1] > max)
            max = hand[i][1];
    }
    return max;
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
    for (int i = 0; i < SUITS; i++) {
		for (int j = 0; j < FACES; j++) {
			temp[t] = deck[i][j];
			t++;
		}
	}
	t = 0;
    for (int i = 0; i < 5; i++) {
        for (int p = 0; p < n; p++) {
                results[p][i][1] = temp[t] / 4;
                t++;
        }
    }
	t = 0;
    for (int i = 0; i < 5; i++) {
        for (int p = 0; p < n; p++) {
            results[p][i][0] = temp[t] % 4;
            t++;
        }
    }
	//Sorting Cards
    for (int p = 0; p < n; p++) {
        for (int i = 0;  i < 4 ; i++){
            for (int j = i + 1; j < 5; j++) {
                if (results[p][i][1] > results[p][j][1]) {
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
    cout << endl << "bai cua moi nguoi:\n";
    for (int p = 0; p < n; p++) {
        cout << "nguoi choi thu " << p + 1 << ":" << endl; 
        for (int i = 0; i < 5; i++) {
            cout << faces[hand[p][i][1]] << suits[hand[p][i][0]] << "\t" << endl;
        }
        cout << "-------------------------------------------" << endl;
    }
}

int getStatusOfHand(int** hand) {
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

int** convertHands(int***hand, int pos) {
    int** result = new int*[5];
    for (int i = 0; i < 5; i++) {
        result[i] = new int[2];
    }
    for (int i = 0; i < 5; i++) {
        result[i][0] = hand[pos][i][0];
        result[i][1] = hand[pos][i][1];
    }
    return result;
}

int* rankingHands(int*** hand, int n) {
    //Khoi tao mang 2 chieu [gia tri cua rank][vi tri]
    int** rank = new int *[n];
    for (int i = 0; i < n; i++) {
        rank[i] = new int[2];
    }
    int* pos = new int [n];
    
    for (int i = 0; i < n; i++) {
        rank[i][0] = getStatusOfHand(convertHands(hand,i));
        rank[i][1] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rank[j][0] > rank[i][0]) {
                swap(rank[j][0], rank[i][0]);
                swap(rank[j][1], rank[i][1]);           
            }
        }
    }   
    for (int i = 0; i < n; i++) {
        pos[i] = rank[i][1] + 1;
    } 
    return pos;
}

void evaluateHands(int deck[SUITS][FACES], int***hand, int people, int rounds, char* suits[], char* faces[] ) {
    int** score = new int *[people];
    int temp_max = 0;
    for (int i = 0; i < people; i++) {
        score[i] = new int[2];
    }
    for (int i = 0; i < people; i++) {
        for (int j = 0; j < 2; j++) {
            score[i][j] = 0;
        }
    }
    int curRound = 0;
    while (curRound != rounds) {
        shuffleCards(deck);
        dealingForHands(deck, people); 
        for (int i = 0; i < people; i++) {
            score[i][0] = score[i][0] + getStatusOfHand(convertHands(dealingForHands(deck, people),i));
            score[i][1] = i;
            //cout << score[i][0];
        }
        cout << "--------Round " << curRound + 1 <<"----------------" << endl;
        printHandsAll(dealingForHands(deck,people), suits, faces, people);
        curRound++;
    }
    //Print total Score of each player
    for (int i = 0; i < people; i++) {
            cout << "Total score of Player " << i + 1 << " is: " << score[i][0] << endl;
            if (score[i][0] > temp_max) {
                temp_max = score[i][0];
            }
        }
    //Print all Highest score player
    for (int i = 0; i < people; i++) {
        if (score[i][0] == temp_max)
            cout << "Player " << score[i][1] + 1 << " has the highest score : " << temp_max << endl;
    }
}

void printHandsAllDealer(int*** hand, char* suits[], char* faces[], int n) {
    cout << endl << "bai cua moi nguoi:\n";
    for (int p = 0; p < n; p++) {
        if (p == 0) {
            cout << "Dealer:" << endl; 
        }
        else {
            cout << "nguoi choi thu " << p << ":" << endl; 
        }
        for (int i = 0; i < 5; i++) {
            cout << faces[hand[p][i][1]] << suits[hand[p][i][0]] << "\t" << endl;
        }
        cout << "-------------------------------------------" << endl;
    }
}

void PlayWithDealer() {
    srand(time(NULL));
    int deck[SUITS][FACES] = {0};
    shuffleCards(deck);
    int n, rounds;
    cout << "nhap vao so nguoi choi(khong tinh Dealer): ";
    cin >> n;
    n = n + 1;
    // cout << "nhap vao so vong choi: ";
    // cin >> rounds;
    int*** results = dealingForHands(deck, n);
    //luu cac gia tri cua deck vao mang 1 chieu
    int temp[MAX_CARDS] = {0};
	int k = 0;
    for (int i = 0; i < SUITS; i++) {
		for (int j = 0; j < FACES; j++) {
			temp[k] = deck[i][j];
			k++;
		}
	}
    //in ra cac la bai tren tay nguoi choi
    printHandsAllDealer(results, suits, faces, n);

    cout << "-------------------------------------------" << endl;
    
    int t = n * 5, ok = 0; //t la so la bai duoc chia, ok la so lan dealer changes
    if (52 - t < 3) { //xet xem con du 3 la cho dealer changes khong
        cout << "Dealer chi co the doi " << 52 - t << " quan bai!!!" << endl;
        ok = 52 - t;
    }
    else {
        cout << "Dealer co the doi 3 quan bai!!!" << endl;
        ok = 3;
    }
    //dealer changes cards    
    char yesOrNo;
    for (int i = 0; i < 5; i++) {
        cout << "(Dealer) Change card " << (i + 1) << "? (y/n): ";
        cin.ignore(256, '\n');
        cin >> yesOrNo;

        if (yesOrNo == 'y') {
            results[0][i][0] = temp[t] % 4;
            results[0][i][1] = temp[t] / 4;
            t++;
            ok--;
        } 
        if (ok == 0) {
            cout << "***************************************" << endl;
            cout << "Dealer changed!!!";
            break;
        }
    }
    //in ra cac la bai cua nguoi choi sau khi dealer doi bai
    printHandsAllDealer(results, suits, faces, n);
}

void PlayerAndDealer() {
    srand(time(NULL));
    int deck[SUITS][FACES] = {0};
    shuffleCards(deck);
    int n, rounds;
    cout << "nhap vao so nguoi choi(khong tinh Dealer): ";
    cin >> n;

    n = n + 1; // dam bao co 2 nguoi choi la 1player va 1dealer

    if (n > 6) {
        cout << "khong the choi che do nay!!!!!:(((";
        return;
    }
    // cout << "nhap vao so vong choi: ";
    // cin >> rounds;
    int*** results = dealingForHands(deck, n);
    //luu cac gia tri cua deck vao mang 1 chieu
    int temp[MAX_CARDS] = {0};
	int k = 0;
    for (int i = 0; i < SUITS; i++) {
		for (int j = 0; j < FACES; j++) {
			temp[k] = deck[i][j];
			k++;
		}
	}
    //in ra cac la bai tren tay nguoi choi
    printHandsAllDealer(results, suits, faces, n);

    cout << "-------------------------------------------" << endl;

    cout << "Players change cards";
    cout << "Moi nguoi choi duoc phep doi toi da doi 3 la bai" << endl;

    char yesOrNo;
    int t = n * 5, ok = 3; //t la so bai da chia, ok la so lan nguoi choi co the doi bai
    
    for (int p = 1; p < n; p++) {
        cout << "Player " << p << " changes cards!" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "(Player) Change card " << (i + 1) << "? (y/n): ";
            cin.ignore(256, '\n');
            cin >> yesOrNo;

            if (yesOrNo == 'y') {
                results[p][i][0] = temp[t] % 4;
                results[p][i][1] = temp[t] / 4;
                t++;
                ok--;
            } 
            if (ok == 0) {
                cout << "***************************************" << endl;
                cout << "Player changed!!!";
                break;
            }
        }
        ok = 3;
    }

    cout << "***************************************" << endl;
    cout << "Dealer changes cards!!!" << endl;
    
    if (52 - t < 3) { //xet xem con du 3 la cho dealer changes khong
        cout << "Dealer chi co the doi " << 52 - t << " quan bai!!!" << endl;
        ok = 52 - t;
    }
    else {
        cout << "Dealer co the doi 3 quan bai!!!" << endl;
        ok = 3;
    }
    //dealer changes cards    
    for (int i = 0; i < 5; i++) {
        cout << "(Dealer) Change card " << (i + 1) << "? (y/n): ";
        cin.ignore(256, '\n');
        cin >> yesOrNo;

        if (yesOrNo == 'y') {
            results[0][i][0] = temp[t] % 4;
            results[0][i][1] = temp[t] / 4;
            t++;
            ok--;
        } 
        if (ok == 0) {
            cout << "***************************************" << endl;
            cout << "Dealer changed!!!";
            break;
        }
    }

    //in ra cac la bai cua nguoi choi sau khi dealer doi bai
    printHandsAllDealer(results, suits, faces, n);
}

int main() {
    // srand(time(NULL));
    // int deck[SUITS][FACES] = {0};
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

    // int n, rounds;
    // cout << "nhap vao so nguoi choi: ";
    // cin >> n;
    // cout << "nhap vao so vong choi: ";
    // cin >> rounds;
    // int***results = dealingForHands(deck, n);
    // printHands(results, suits, faces);
    // cout << "-------------------------------------------" << endl;
    // printHandsAll(results, suits, faces, n);
    // int* check = rankingHands(results, n);
    // for (int i = 0; i < n; i++) {
    //     cout << check[i] << " ";
    // }
    // evaluateHands(deck, results, n, rounds, suits, faces);

    // PlayWithDealer();

    // PlayerAndDealer();
    
    return 0;
}
