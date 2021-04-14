
#include "Game.h"
#include "Display.h"
#include <Windows.h>
#include <conio.h>
int deck[4][13] = {0};
void shuffleCards(int deck[4][13])
{
	int arr[MAX_CARDS] = {0};
	int swapper = 0;
	int temp = 0;
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
            if (  deck[i][j] % 4  == 0 || deck[i][j] % 4 == 1 )
            {
                Textcolor(252);
                cout << faces[deck[i][j] / 4] << suits[deck[i][j] % 4];
                Textcolor(15);
                cout << " ";
            }
            else
            {
                Textcolor(240);
                cout << faces[deck[i][j] / 4] << suits[deck[i][j] % 4];
                Textcolor(15);
                cout << " ";
            }
		}
		cout << "\n";
	};
}
int** dealingForHands(int deck[SUITS][FACES])
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
    int pos_x[6] = {50, 70, 70, 50, 28, 28};
    int pos_y[6] = {15, 12, 8, 5, 8, 12};
	for ( int i = 0; i < 5; i++)
    {
        gotoxy(pos_x[0],pos_y[0]);
        if (  hand[i][0]  == 0 || hand[i][0] == 1 )
        {
            Textcolor(252);
            cout << faces[hand[i][1]] << suits[hand[i][0]] ;
            Textcolor(160);
            //cout << " ";
        }
        else
        {
            Textcolor(240);
		    cout << faces[hand[i][1]] << suits[hand[i][0]] ;
            Textcolor(160);
            //cout << " ";
        }
        pos_x[0] = pos_x[0] + 4;  
    }
		//cout << faces[hand[i][1]] << suits[hand[i][0]] << "\n";
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

    int test = 0;
    for ( int i = 0; i < 4; i++)
    {
        for ( int j = 0 ; j < 5; j++)
        {
            if (temp[j] > temp[i])
            {
                test = temp[i];
                temp[i] = temp[j];
                temp[j] = test;
            }
        }
    }

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
    int max = hand[0][1];
    for ( int i = 0; i < 5; i++)
    {
        if ( hand[i][1] == 0)
            return 13;
        if ( hand[i][1] > max)
            max = hand[i][1];
    }
    return max;
}
int*** dealingForHandsS(int deck[SUITS][FACES], int n)
{
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
    for ( int i = 0; i < 5; i++) {
        for (int p = 0; p < n; p++) {
                results[p][i][1] = temp[t] / 4;
                t++;
        }
    }
	t = 0;
    for ( int i = 0; i < 5; i++) {
        for (int p = 0; p < n; p++) {
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
int** convertHands(int***hand, int pos)
{
    int** result = new int*[5];
    for ( int i = 0; i < 5; i++)
        result[i] = new int[2];

    for ( int i = 0; i < 5; i++)
    {
        result[i][0] = hand[pos][i][0];
        result[i][1] = hand[pos][i][1];
    }
    return result;
}
int* rankingHands(int*** hand, int n)
{
    //Khoi tao mang 2 chieu [gia tri cua rank][vi tri]
    int** rank = new int *[n];
    for ( int i = 0; i < n; i++)
        rank[i] = new int[2];
    int* pos = new int [n];
    for ( int i = 0; i < n; i++)
    {
        rank[i][0] = getStatusOfHand(convertHands(hand,i));
        rank[i][1] = i;
    }
    for ( int i = 0; i < n - 1; i++)
    {
        for ( int j = i + 1; j < n; j++)
        {
            if (rank[j][0] > rank[i][0])
            {
                swap(rank[j][0], rank[i][0]);
                swap(rank[j][1], rank[i][1]);           
            }
        }
    }   
    for ( int i = 0; i < n; i++)
    {
        pos[i] = rank[i][1] + 1;
    } 
    return pos;
}
void printHandS(int*** hand, char* suits[], char* faces[], int n)
{
	int pos = 0;
	while (pos != n )
	{
        //system ("CLS");
        int pos_x[6] = {50, 70, 70, 50, 28, 28};
        int pos_y[6] = {15, 12, 8, 5, 8, 12};
        Textcolor(164);
        gotoxy(pos_x[pos], pos_y[pos] + 1);
            cout << "Player " << pos + 1 << " ";
		for ( int i = 0; i < 5; i++)
		{
            Sleep(50);
            gotoxy(pos_x[pos],pos_y[pos]);
            if (  hand[pos][i][0]  == 0 || hand[pos][i][0] == 1 )
            {
                Textcolor(252);
                cout << faces[hand[pos][i][1]] << suits[hand[pos][i][0]] ;
                Textcolor(15);
               //cout << " ";
            }
        else
            {
                Textcolor(240);
                cout << faces[hand[pos][i][1]] << suits[hand[pos][i][0]] ;
                Textcolor(15);
                //cout << " ";
            }
            pos_x[pos]+= 4;
        }
		pos++;
	}
    //cout << "Ranking: ";
    //for (int i = 0; i < n; i++)
        //cout << rankingHands(hand, n)[i] << " ";
}
void evaluateHands(int deck[SUITS][FACES], int***hand, int people, int rounds, char* suits[], char* faces[] )
{
    int** score = new int *[people];
    int temp_max = 0;
    for ( int i = 0; i < people; i++)
        score[i] = new int[2];
    for ( int i = 0; i < people; i++)
    {
        for ( int j = 0; j < 2; j++)
            score[i][j] = 0;
    }
    int curRound = 0;
    while ( curRound != rounds)
    {
        printTable();
        shuffleCards(deck);
        dealingForHandsS(deck, people); 
        for ( int i = 0; i < people; i++)
        {
            score[i][0] = score [i][0] + getStatusOfHand(convertHands(dealingForHandsS(deck, people),i));
            score[i][1] = i;
            //cout << score[i][0];
        }
        gotoxy(40,3);
        cout << "--------Round " << curRound + 1 <<"-----------" << endl;
        printHandS(dealingForHandsS(deck,people), suits, faces, people);
        gotoxy(45,19);
        cout << "Press any Key to go to next rounds";
        getch();
        curRound++;
    }
    //Print total Score of each player
    Textcolor(12);
    gotoxy(0,17);
    cout << "------------RESULT-------------" << endl;
    for ( int i = 0; i < people; i++)
        {
            cout << "Total score of Player " << i + 1 << " is: " << score[i][0] << endl;
            if ( score[i][0] > temp_max)
                temp_max = score[i][0];
        }
    //Print all Highest score player
    for ( int i = 0; i < people; i++)
    {
        if (score[i][0] == temp_max)
            cout << "Player " << score[i][1] + 1 << " has the highest score : " << temp_max << endl;
    }
}

void printHandsAllDealer(int*** hand, char* suits[], char* faces[], int n) {
    for (int pos = 0; pos < n; pos++) 
    {
        int pos_x[6] = {50, 70, 70, 50, 28, 28};
        int pos_y[6] = {15, 12, 8, 5, 8, 12};
        if (pos == 0) 
        {   
            Textcolor(164);
            gotoxy(pos_x[pos],pos_y[pos]+1);
            cout << "Dealer " << endl; 
        }
        else
        {
          Textcolor(164);
          gotoxy(pos_x[pos],pos_y[pos]+1);
            cout << "Player " << pos << ":" << endl; 
        }
        for (int i = 0; i < 5; i++) 
        {
            Sleep(50);
            gotoxy(pos_x[pos],pos_y[pos]);
            if (  hand[pos][i][0]  == 0 || hand[pos][i][0] == 1 )
            {
                Textcolor(252);
                cout << faces[hand[pos][i][1]] << suits[hand[pos][i][0]] ;
                Textcolor(15);
               //cout << " ";
            }
        else
            {
                Textcolor(240);
                cout << faces[hand[pos][i][1]] << suits[hand[pos][i][0]] ;
                Textcolor(15);
                //cout << " ";
            }
            pos_x[pos]+= 4;
        }
        //cout << "-------------------------------------------" << endl;
    }
}

void PlayWithDealer() {
    system("cls");
    srand(time(NULL));
    int deck[SUITS][FACES] = {0};
    int n, rounds;
    cout << "nhap vao so nguoi choi(khong tinh Dealer): ";
    cin >> n;
    n = n + 1;
    cout << "nhap vao so vong choi: ";
    cin >> rounds;

    int** score = new int *[n];
    int temp_max = 0;
    for (int i = 0; i < n; i++) {
        score[i] = new int[2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            score[i][j] = 0;
        }
    }

    int curRound = 0;
    while (curRound != rounds) 
    {
        system("CLS");
        printTable();
        shuffleCards(deck);
        int*** results = dealingForHandsS(deck, n);
        //luu cac gia tri cua deck vao mang 1 chieu
        int temp[MAX_CARDS] = {0};
        int k = 0;
        for (int i = 0; i < SUITS; i++) {
            for (int j = 0; j < FACES; j++) {
                temp[k] = deck[i][j];
                k++;
            }
        }
        gotoxy(40,3);
        cout << "--------Round " << curRound + 1 <<"-----------" << endl;
        //in ra cac la bai tren tay nguoi choi
        printHandsAllDealer(results, suits, faces, n);

        //cout << "-------------------------------------------" << endl;
        gotoxy(0,17);
        int t = n * 5, ok = 0; //t la so la bai duoc chia, ok la so lan dealer changes
        if (52 - t < 3) { //xet xem con du 3 la cho dealer changes khong
            cout << "Dealer can only changed " << 52 - t << " cards!!!" << endl;
            ok = 52 - t;
        }
        else {
            cout << "Dealer can change 3 cards!!!" << endl;
            ok = 3;
        }
        //dealer changes cards    
        char yesOrNo;
        for (int i = 0; i < 5; i++) {
            cout << "Change card " << (i + 1) << "? (y/n): ";
            cin.ignore(256, '\n');
            cin >> yesOrNo;

            if (yesOrNo == 'y') {
                results[0][i][0] = temp[t] % 4;
                results[0][i][1] = temp[t] / 4;
                t++;
                ok--;
            } 
            if (ok == 0 || i == 4) {
                cout << "\nDealer changed!!!";
                break;
            }
        }
        //in ra cac la bai cua nguoi choi sau khi dealer doi bai
        printHandsAllDealer(results, suits, faces, n);

        for (int i = 0; i < n; i++) {
            score[i][0] = score [i][0] + getStatusOfHand(convertHands(dealingForHandsS(deck, n),i));
            score[i][1] = i;
            //cout << score[i][0];
        }
        getch();
        curRound++;
    }
        gotoxy(0,17);
        Textcolor(12);
        cout << "----------RESULT---------" << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == 0) {
                cout << "Total score of Dealer " << " is: " << score[i][0] << endl;
            }
            else {
                cout << "Total score of Player " << i << " is: " << score[i][0] << endl;
            }
            if (score[i][0] > temp_max) 
            {
                temp_max = score[i][0];
            }
        }
        //Print all Highest score player
        for (int i = 0; i < n; i++) 
        {
            if (score[i][0] == temp_max)
                if (i == 0) {
                    cout << "Dealer " << " has the highest score : " << temp_max << endl;
                }
                else {
                    cout << "Player " << score[i][1] << " has the highest score : " << temp_max << endl;
                }        
        }
}


void PlayerAndDealer() {
    system("cls");
    srand(time(NULL));
    int deck[SUITS][FACES] = {0};
    int n, rounds;
    cout << "Input the number of players ( dealer doesn't count, less than 6 player): ";
    cin >> n;

    n = n + 1; // dam bao co 2 nguoi choi la 1player va 1dealer

    if (n > 6) {
        cout << "khong the choi che do nay!!!!!:(((";
        return;
    }
    cout << "Input the number of rounds: ";
    cin >> rounds;

    int** score = new int *[n];
    int temp_max = 0;
    for (int i = 0; i < n; i++) {
        score[i] = new int[2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            score[i][j] = 0;
        }
    }

    int curRound = 0;
    while (curRound != rounds) 
    {
        system("CLS");
        printTable();
        shuffleCards(deck);
        int*** results = dealingForHandsS(deck, n);
        //luu cac gia tri cua deck vao mang 1 chieu
        int temp[MAX_CARDS] = {0};
        int k = 0;
        for (int i = 0; i < SUITS; i++) {
            for (int j = 0; j < FACES; j++) {
                temp[k] = deck[i][j];
                k++;
            }
        }
        gotoxy(40,3);
        cout << "--------Round " << curRound + 1 <<"------------" << endl;
        //in ra cac la bai tren tay nguoi choi
        printHandsAllDealer(results, suits, faces, n);
        gotoxy(0,17);
        cout << "-------------------------------------------" << endl;

        cout << "Players change cards" << endl;
        cout << "Maxium = 3 cards" << endl;

        //gotoxy(0,17);
        char yesOrNo;
        int t = n * 5, ok = 3; //t la so bai da chia, ok la so lan nguoi choi co the doi bai
        
        for (int p = 1; p < n; p++) {
            cout << "Player " << p << " changes cards!" << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Change card " << (i + 1) << "? (y/n): ";
                cin.ignore(256, '\n');
                cin >> yesOrNo;

                if (yesOrNo == 'y') {
                    results[p][i][0] = temp[t] % 4;
                    results[p][i][1] = temp[t] / 4;
                    t++;
                    ok--;
                } 
                if (ok == 0) {
                    cout << "Player changed!!!";
                    break;
                }
            }
            ok = 3;
        }
        cout << "Dealer changes cards!!!" << endl;
        
        if (52 - t < 3) { //xet xem con du 3 la cho dealer changes khong
            cout << "Dealer can only change " << 52 - t << " cards!!!" << endl;
            ok = 52 - t;
        }
        else {
            cout << "Dealer can change 3 cards!!!" << endl;
            ok = 3;
        }
        //dealer changes cards    
        for (int i = 0; i < 5; i++) {
            cout << "Change card " << (i + 1) << "? (y/n): ";
            cin.ignore(256, '\n');
            cin >> yesOrNo;

            if (yesOrNo == 'y') {
                results[0][i][0] = temp[t] % 4;
                results[0][i][1] = temp[t] / 4;
                t++;
                ok--;
            } 
            if (ok == 0) {
                cout << "Dealer changed!!!";
                break;
            }
        }

        //in ra cac la bai cua nguoi choi sau khi dealer doi bai
        printHandsAllDealer(results, suits, faces, n);

        for (int i = 0; i < n; i++) {
            score[i][0] = score[i][0] + getStatusOfHand(convertHands(results, i));
            score[i][1] = i;
            //cout << score[i][0];
        }
        getch();
        curRound++;
    }
        gotoxy(0,17);
        Textcolor(12);
        cout << "-------------RESULT-----------" << endl;;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cout << "Total score of Dealer " << " is: " << score[i][0] << endl;
            }
            else {
                cout << "Total score of Player " << i << " is: " << score[i][0] << endl;
            }
            if (score[i][0] > temp_max) {
                temp_max = score[i][0];
            }
        }
        //Print all Highest score player
        for (int i = 0; i < n; i++) {
            if (score[i][0] == temp_max)
                if (i == 0) {
                    cout << "Dealer " << " has the highest score : " << temp_max << endl;
                }
                else {
                    cout << "Player " << score[i][1] << " has the highest score : " << temp_max << endl;
                }        
        }
        cout << "---------------------------";
    Textcolor(15);
}

void Easy() {
    PlayerAndDealer();
    getch();
    start(100);
}

void Medium() {
    PlayWithDealer();
    getch();
    start(100);
}

void Hard() {
        system("cls");
    srand(time(NULL));
    int deck[SUITS][FACES] = {0};
    int n, rounds;
    cout << "Input the number of players ( Dealer doesn't count ): ";
    cin >> n;
    n = n + 1;
    cout << "Input the number of rounds: ";
    cin >> rounds;

    int** score = new int *[n];
    int temp_max = 0;
    for (int i = 0; i < n; i++) {
        score[i] = new int[2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            score[i][j] = 0;
        }
    }

    int curRound = 0;
    while (curRound != rounds)
    {
        system("CLS");
        printTable();        
        shuffleCards(deck);
        int*** results = dealingForHandsS(deck, n);
        //luu cac gia tri cua deck vao mang 1 chieu
        int temp[MAX_CARDS] = {0};
        int k = 0;
        for (int i = 0; i < SUITS; i++) {
            for (int j = 0; j < FACES; j++) {
                temp[k] = deck[i][j];
                k++;
            }
        }
        gotoxy(40,3);        
        cout << "--------Round " << curRound + 1 <<"----------------" << endl;
        //in ra cac la bai tren tay nguoi choi
        printHandsAllDealer(results, suits, faces, n);
        gotoxy(0,17);   
        cout << "Dealer can change 5 cards!!!" << endl;
        int t = n * 5; //t la so la bai duoc chia, ok la so lan dealer changes
        //dealer changes cards    
        char yesOrNo;
        for (int i = 0; i < 5; i++) {
            cout << "Change card " << (i + 1) << "? (y/n): ";
            cin.ignore(256, '\n');
            cin >> yesOrNo;

            if (yesOrNo == 'y') {
                results[0][i][0] = temp[t] % 4;
                results[0][i][1] = temp[t] / 4;
                t++;
            } 
            if (i == 4) {
                cout << "Dealer changed!!!";
                break;
            }
        }
        //in ra cac la bai cua nguoi choi sau khi dealer doi bai
        printHandsAllDealer(results, suits, faces, n);

        for (int i = 0; i < n; i++) {
            score[i][0] = score[i][0] + getStatusOfHand(convertHands(results, i));
            score[i][1] = i;
            //cout << score[i][0];
        }

        curRound++;
    }   
    gotoxy(0,17);
    Textcolor(12); 
    for (int i = 0; i < n; i++) 
    {

            if (i == 0) {
                cout << "Total score of Dealer " << " is: " << score[i][0] << endl;
            }
            else {
                cout << "Total score of Player " << i << " is: " << score[i][0] << endl;
            }
            if (score[i][0] > temp_max) {
                temp_max = score[i][0];
            }
        }
        //Print all Highest score player
        for (int i = 0; i < n; i++) {
            if (score[i][0] == temp_max)
                if (i == 0) {
                    cout << "Dealer " << " has the highest score : " << temp_max << endl;
                }
                else {
                    cout << "Player " << score[i][1] << " has the highest score : " << temp_max << endl;
                }        
        }  
        cout << "---------------------------";
    Textcolor(15);  
    getch();
    start(100);
}

void SinglePlayer()
{
    system("cls");
    int player = 1;
    int rounds;
    cout << "Input the number of rounds: ";
    cin >> rounds;
    system("cls");

    printTable();
    evaluateHands(deck,dealingForHandsS(deck, player), player, rounds, suits, faces);
    getch();
    start(100);
}

void PlayervsPlayer()
{
    system("cls"); 
    int people, rounds;
    cout << "Input the number of Player: ";
    cin >> people;
    cout << "Input the number of Rounds: ";
    cin >> rounds;
    system("cls");

    evaluateHands(deck,dealingForHandsS(deck, people), people, rounds, suits, faces);
    getch();
    start(100);
}
