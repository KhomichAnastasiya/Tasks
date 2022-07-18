#include <iostream>
#include <Windows.h>

using namespace std;

enum ConsoleColor
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARKGRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbInfo;

void GetBufferChars(COORD *Chars)
{
	GetConsoleScreenBufferInfo(hCon, &csbInfo);
	Chars->X = csbInfo.srWindow.Right - csbInfo.srWindow.Left + 1;
	Chars->Y = csbInfo.srWindow.Bottom - csbInfo.srWindow.Top + 1;
}

void setColor(int background, int text)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

struct Point
{
	int x[100];
	int y[100];
	int color;
};

void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void showPoint(Point pt, int N)
{
	pt.color = 0;
	for (int i = 0; i < N; i++)
	{
		setColor(0, pt.color);
		gotoxy(pt.x[i], pt.y[i]);
		cout << "*";
		pt.color++;
		if (pt.color == 15)
			pt.color = 0;
	}

}

void hidePoint(Point pt, int N)
{
	for (int i = 0; i < N; i++)
	{
		gotoxy(pt.x[i], pt.y[i]);
		cout << " ";
	}

}

void movePoint(Point pt[100], int N)
{
	getchar();
	COORD Chars;
	GetBufferChars(&Chars);
	int widht = Chars.X;
	int height = Chars.Y;

	for (int p = 0; p < 10; p++)
	{
		for (int i = 0; i < N; i++)
		{
			pt[p].x[i] = rand() % widht + 0;
			pt[p].y[i] = rand() % height + 0;
		}
	}

}

void main()
{
	int N;
	setlocale(LC_ALL, "Rus");
	cout << "enter the number of points: ";
	cin >> N;

	Point pt[100];
	movePoint(pt, N);

	for (int k = 0; k < 10; k++)
	{
		showPoint(pt[k], N);
		Sleep(500);
		hidePoint(pt[k], N);
	}

	setColor(0, 7);
	cout << endl;
	system("pause");
}