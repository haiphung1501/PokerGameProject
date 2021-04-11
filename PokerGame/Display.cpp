#include "Display.h"

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
