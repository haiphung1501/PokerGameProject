#include "Display.h"
#include "Game.cpp"
#include <conio.h>
#include <fstream>
#include <Windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}

void printPokerText()
{
	Textcolor(10);
		system("cls");
		gotoxy(2, 5);  cout << "PPPPPPPPPPPPPPPP";
		gotoxy(2, 6);  cout << "PPPP          PPPP";
		gotoxy(2, 7);  cout << "PPPP           PPPP";
		gotoxy(2, 8);  cout << "PPPP          PPPPP";
		gotoxy(2, 9);  cout << "PPPPPPPPPPPPPPPPPP";
		gotoxy(2, 10); cout << "PPPPPPPPPPPPPPPP";
		gotoxy(2, 11); cout << "PPPP";
		gotoxy(2, 12); cout << "PPPP";
		gotoxy(2, 13); cout << "PPPP";
		gotoxy(2, 14); cout << "PPPP";
	Textcolor(11);
		gotoxy(25, 5);  cout << "   OOOOOOOOOOOO   ";
		gotoxy(25, 6);  cout << "  OO          OO";
		gotoxy(25, 7);  cout << " OO            OO";
		gotoxy(25, 8);  cout << "OO              OO";
		gotoxy(25, 9);  cout << "OO              OO";
		gotoxy(25, 10); cout << "OO              OO";
		gotoxy(25, 11); cout << "OO              OO";
		gotoxy(25, 12); cout << " OO            OO";
		gotoxy(25, 13); cout << "  OO          OO";
		gotoxy(25, 14); cout << "   OOOOOOOOOOOO";
	Textcolor(12);
		gotoxy(46, 5);  cout << "KKKK            KKKK";
		gotoxy(46, 6);  cout << "KKKK          KKKK";
		gotoxy(46, 7);  cout << "KKKK        KKKK";
		gotoxy(46, 8);  cout << "KKKK      KKKK";
		gotoxy(46, 9);  cout << "KKKK    KKKK  ";
		gotoxy(46, 10); cout << "KKKKKKKKKK     ";
		gotoxy(46, 11); cout << "KKKK   KKKK";
		gotoxy(46, 12); cout << "KKKK     KKKK";
		gotoxy(46, 13); cout << "KKKK       KKKK";
		gotoxy(46, 14); cout << "KKKK         KKKK";
	Textcolor(13);
		gotoxy(71, 5);  cout << " EEEEEEEEEEEEEEE";
		gotoxy(71, 6);  cout << " EEEEEEEEEEEEEEE";
		gotoxy(71, 7);  cout << " EEEE";
		gotoxy(71, 8);  cout << " EEEE";
		gotoxy(71, 9);  cout << " EEEEEEEEEEEEEEE";
		gotoxy(71, 10); cout << " EEEEEEEEEEEEEEE";
		gotoxy(71, 11); cout << " EEEE";
		gotoxy(71, 12); cout << " EEEE";
		gotoxy(71, 13); cout << " EEEEEEEEEEEEEEE";
		gotoxy(71, 14); cout << " EEEEEEEEEEEEEEE";
	Textcolor(14);
		gotoxy(94, 5);  cout << "RRRRRRRRRRRRRRRRR";
		gotoxy(94, 6);  cout << "RRRR         RRRRR";
		gotoxy(94, 7);  cout << "RRRR           RRRR";
		gotoxy(94, 8);  cout << "RRRR         RRRRR";
		gotoxy(94, 9);  cout << "RRRRRRRRRRRRRRRRR";
		gotoxy(94, 10); cout << "RRRR      RRRR";
		gotoxy(94, 11); cout << "RRRR        RRRR";
		gotoxy(94, 12); cout << "RRRR          RRRR";
		gotoxy(94, 13); cout << "RRRR           RRRR";
		gotoxy(94, 14); cout << "RRRR             RRRR";
		Textcolor(7);
}

void aboutus()
{
	system("cls");
	printPokerText();
	gotoxy(50, 18); cout << "          ABOUT US       ";
	gotoxy(50, 19); cout << "------------------------------";
	gotoxy(50, 20); cout << " 20127018 - PHUNG DUC HAI";
	gotoxy(50, 21); cout << " 20127504 - MAI VU HUY HOANG";
	gotoxy(50, 22); cout << "------------------------------";

	_getch();
}

void Instruction()
{
	gotoxy(50,18);
	cout << "-------INSTRUCTION-------"; 
	cout << "99%...";
	_getch();
}

void printTable()
{
	Textcolor(160);
	gotoxy(30,5); cout << "                                                     ";
	gotoxy(28,6); cout << "                                                         ";
	gotoxy(26,7); cout << "                                                             ";
	gotoxy(24,8); cout << "                                                                  ";
	gotoxy(22,9); cout << "                                                                      "; 
	gotoxy(22,10); cout << "                                                                     ";
	gotoxy(22,11); cout << "                                                                     ";
	gotoxy(24,12); cout << "                                                                 ";
	gotoxy(26,13); cout << "                                                            ";
	gotoxy(28,14); cout << "                                                        ";
	gotoxy(30,15); cout << "                                                    ";
	Textcolor(15);
}
void EasyMediumHard()
{
	int x = 50, y = 20;
	int i;
	char s[30] = " ";
	int n = 1;
	int check = 1;


	printPokerText();

	gotoxy(50, 18); cout << "----CHOOSE MODES-----";
	Textcolor(9);
	gotoxy(50, 20); cout << "EASY";
	Textcolor(7);
	gotoxy(50, 21); cout << "MEDIUM";
	gotoxy(50, 22); cout << "HARD";
	gotoxy(50, 26); cout << "W-S to move, Enter to select";

	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				if (y > 20)
				{
					y--;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					Textcolor(9);
					gotoxy(50, 20); cout << "EASY";
					Textcolor(7);
					gotoxy(50, 21); cout << "MEDIUM";
					gotoxy(50, 22); cout << "HARD";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 21)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "EASY";
					Textcolor(9);
					gotoxy(50, 21); cout << "MEDIUM";
					Textcolor(7);
					gotoxy(50, 22); cout << "HARD";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 22)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "EASY";
					gotoxy(50, 21); cout << "MEDIUM";
					Textcolor(9);
					gotoxy(50, 22); cout << "HARD";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}

				break;
			case 's':
				if (y < 22)
				{
					y++;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					Textcolor(9);
					gotoxy(50, 20); cout << "EASY";
					Textcolor(7);
					gotoxy(50, 21); cout << "MEDIUM";
					gotoxy(50, 22); cout << "HARD";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				if (y == 21)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "EASY";
					Textcolor(9);
					gotoxy(50, 21); cout << "MEDIUM";
					Textcolor(7);
					gotoxy(50, 22); cout << "HARD";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				if (y == 22)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "EASY";
					gotoxy(50, 21); cout << "MEDIUM";
					Textcolor(9);
					gotoxy(50, 22); cout << "HARD";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}

				break;
			case 13:
				if (y == 20)
				{
					Easy();
				}
				if (y == 21)
				{
					Medium();
				}
				if (y == 22)
				{
					Hard();	
				}

				break;
			}
		}
	}
}
void chooseOptions()
{
	int x = 50, y = 20;
	int i;
	char s[30] = " ";
	int n = 1;
	int check = 1;


	printPokerText();

	gotoxy(50, 18); cout << "----CHOOSE MODES-----";
	Textcolor(9);
	gotoxy(50, 20); cout << "SINGLE PLAYER";
	Textcolor(7);
	gotoxy(50, 21); cout << "PLAYER VS PLAYER";
	gotoxy(50, 22); cout << "PLAYER VS DEALER";
	gotoxy(50, 26); cout << "W-S to move, Enter to select";

	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				if (y > 20)
				{
					y--;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					Textcolor(9);
					gotoxy(50, 20); cout << "SINGLE PLAYER";
					Textcolor(7);
					gotoxy(50, 21); cout << "PLAYER VS PLAYER";
					gotoxy(50, 22); cout << "PLAYER VS DEALER";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 21)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "SINGLE PLAYER";
					Textcolor(9);
					gotoxy(50, 21); cout << "PLAYER VS PLAYER";
					Textcolor(7);
					gotoxy(50, 22); cout << "PLAYER VS DEALER";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 22)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "SINGLE PLAYER";
					gotoxy(50, 21); cout << "PLAYER VS PLAYER";
					Textcolor(9);
					gotoxy(50, 22); cout << "PLAYER VS DEALER";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}

				break;
			case 's':
				if (y < 22)
				{
					y++;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					Textcolor(9);
					gotoxy(50, 20); cout << "SINGLE PLAYER";
					Textcolor(7);
					gotoxy(50, 21); cout << "PLAYER VS PLAYER";
					gotoxy(50, 22); cout << "PLAYER VS DEALER";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				if (y == 21)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "SINGLE PLAYER";
					Textcolor(9);
					gotoxy(50, 21); cout << "PLAYER VS PLAYER";
					Textcolor(7);
					gotoxy(50, 22); cout << "PLAYER VS DEALER";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				if (y == 22)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "SINGLE PLAYER";
					gotoxy(50, 21); cout << "PLAYER VS PLAYER";
					Textcolor(9);
					gotoxy(50, 22); cout << "PLAYER VS DEALER";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}

				break;
			case 13:
				if (y == 20)
				{
					SinglePlayer();
				}
				if (y == 21)
				{
					PlayervsPlayer();
				}
				if (y == 22)
				{
					EasyMediumHard();	
				}
				break;
			}
		}
	}
}

void start(int n)
{
	int x = 50, y = 20;
	int i;
	char s[30] = " ";
	int check = 1;

	printPokerText();
	gotoxy(50, 18); cout << "-------------------";
	Textcolor(9);
	gotoxy(50, 20); cout << "1. Start Game";
	Textcolor(7);
	gotoxy(50, 21); cout << "2. Instruction";
	gotoxy(50, 22); cout << "3. About us";
	gotoxy(50, 23); cout << "4. Exit Game";
	gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				if (y > 20)
				{
					y--;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					gotoxy(50, 18); cout << "-------------------";
					Textcolor(9);
					gotoxy(50, 20); cout << "1. Start Game";
					Textcolor(7);
					gotoxy(50, 21); cout << "2. Instruction";
					gotoxy(50, 22); cout << "3. About us";
					gotoxy(50, 23); cout << "4. Exit Game";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 21)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "1. Start Game";
					Textcolor(9);
					gotoxy(50, 21); cout << "2. Instruction";
					Textcolor(7);
					gotoxy(50, 22); cout << "3. About us";
					gotoxy(50, 23); cout << "4. Exit Game";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 22)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "1. Start Game";
					gotoxy(50, 21); cout << "2. Instruction";
					Textcolor(9);
					gotoxy(50, 22); cout << "3. About us";
					Textcolor(7);
					gotoxy(50, 23); cout << "4. Exit Game";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 23)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "1. Start Game";
					gotoxy(50, 21); cout << "2. Instruction";
					gotoxy(50, 22); cout << "3. About us";
					Textcolor(9);
					gotoxy(50, 23); cout << "4. Exit Game";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				break;
			case 's':
			if (y < 23)
			{
				y++;
				gotoxy(x, y);
			}
			if (y == 20)
			{
				gotoxy(50, 18); cout << "-------------------";
				Textcolor(9);
				gotoxy(50, 20); cout << "1. Start Game";
				Textcolor(7);
				gotoxy(50, 21); cout << "2. Instruction";
				gotoxy(50, 22); cout << "3. About us";
				gotoxy(50, 23); cout << "4. Exit Game";
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
			}
			if (y == 21)
			{
				Textcolor(7);
				gotoxy(50, 18); cout << "-------------------";
				gotoxy(50, 20); cout << "1. Start Game";
				Textcolor(9);
				gotoxy(50, 21); cout << "2. Instruction";
				Textcolor(7);
				gotoxy(50, 22); cout << "3. About us";
				gotoxy(50, 23); cout << "4. Exit Game";
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
			}
			if (y == 22)
			{
				Textcolor(7);
				gotoxy(50, 18); cout << "-------------------";
				gotoxy(50, 20); cout << "1. Start Game";
				gotoxy(50, 21); cout << "2. Instruction";
				Textcolor(9);
				gotoxy(50, 22); cout << "3. About us";
				Textcolor(7);
				gotoxy(50, 23); cout << "4. Exit Game";
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

			}
			if (y == 23)
			{
				Textcolor(7);
				gotoxy(50, 18); cout << "-------------------";
				gotoxy(50, 20); cout << "1. Start Game";
				gotoxy(50, 21); cout << "2. Instruction";
				gotoxy(50, 22); cout << "3. About us";
				Textcolor(9);
				gotoxy(50, 23); cout << "4. Exit Game";
				Textcolor(7);
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
			}
			break;
			case 13:
				if (y == 20)
				{
					chooseOptions();
				}
				if (y == 21)
				{
					Instruction();
					system("cls");
					start(99);
				}
				if (y == 22)
				{
					//printduaxe();
					aboutus();
					system("cls");
					start(99);
				}
				if (y == 23)
				{
					exit(0);
				}
				break;
			}
		}
	}

	}
}
