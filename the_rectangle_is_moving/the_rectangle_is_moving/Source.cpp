/*
Прямоугольник, который перемещается при нажатии на кнопки w - вверх, a - влево, s - вниз, d - вправо.
Также прямоугольник меняет размеры при нажатии на 1,3 - увеличивается размер, 2,4 - уменьшается размер.
При перемещении и изменении размеров прямоугольник не должен выходить за пределы экрана
консольного приложения.

*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbInfo;
void GetBufferChars(COORD *Chars)
{
	GetConsoleScreenBufferInfo(hCon, &csbInfo);
	Chars->X = csbInfo.srWindow.Right - csbInfo.srWindow.Left + 1;
	Chars->Y = csbInfo.srWindow.Bottom - csbInfo.srWindow.Top + 1;
}

struct Rect
{
	int left;
	int top;
	int height;
	int width;
};

void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void setPositionRect(Rect &rect, int ch)
{
	COORD Chars;
	GetBufferChars(&Chars);
	int widht = Chars.X;
	int height = Chars.Y;

	switch (ch)
	{
	case 'd':
	{
		if ((rect.width + rect.left) < (widht - 5))
		{
			rect.left = rect.left + 5;
		}
		break;
	}
	case 's':
	{
		if (((rect.height + rect.top) < height - 5))
		{
			rect.top = rect.top + 5;
		}
		break;
	}
	case 'a':
	{
		if ((rect.left - 5 > 0))
		{
			rect.left = rect.left - 5;
		}
		break;
	}
	case 'w':
	{
		if ((rect.top - 5 > 0))
		{
			rect.top = rect.top - 5;
		}
		break;
	}
	}

}

void resizeRect(Rect &rect, int ch)
{
	COORD Chars;
	GetBufferChars(&Chars);
	int widht = Chars.X;
	int height = Chars.Y;

	switch (ch)
	{
	case '1':
	{
		if (((rect.left + rect.width) < (widht - 5)) && ((rect.left + 5 > 0)))
		{
			rect.width = rect.width + 5;
		}
		break;
	}
	case '2':
	{
		rect.width = rect.width - 5;
		break;
	}
	case '3':
	{
		if ((((rect.top + rect.height) < height - 5)) && ((rect.top + 5 > 0)))
		{
			rect.height = rect.height + 5;
		}
		break;
	}
	case '4':
	{
		rect.height = rect.height - 5;
		break;
	}
	}
}

void showRect(Rect &rect)
{
	for (int i = rect.left; i < (rect.left + rect.width); i++)
	{
		gotoxy(i, rect.top);
		cout << "*";
	}
	for (int i = rect.top; i < (rect.top + rect.height); i++)
	{
		gotoxy(rect.width + rect.left, i);
		cout << "*";
	}
	for (int i = rect.top; i < (rect.top + rect.height); i++)
	{
		gotoxy(rect.left, i);
		cout << "*";
	}
	for (int i = rect.left; i < (rect.left + rect.width + 1); i++)

	{
		gotoxy(i, rect.height + rect.top);
		cout << "*";
	}

}

void hideRect(Rect &rect)
{
	for (int i = rect.left; i < (rect.left + rect.width); i++)
	{
		gotoxy(i, rect.top);
		cout << " ";
	}
	for (int i = rect.top; i < (rect.top + rect.height); i++)
	{
		gotoxy(rect.width + rect.left, i);
		cout << " ";
	}
	for (int i = rect.top; i < (rect.top + rect.height); i++)
	{
		gotoxy(rect.left, i);
		cout << " ";
	}
	for (int i = rect.left; i < (rect.left + rect.width + 1); i++)
	{
		gotoxy(i, rect.height + rect.top);
		cout << " ";
	}

}


void main()
{
	Rect rect;
	rect.left = 1;
	rect.top = 1;
	rect.height = 10;
	rect.width = 25;
	showRect(rect);
	Sleep(1000);

	for (int p = 0; p < 15; p++)
	{
		int ch = 0;
		ch = _getch();
		hideRect(rect);
		setPositionRect(rect, ch);
		resizeRect(rect, ch);
		showRect(rect);
		Sleep(1000);
	}

	cout << endl;
	system("pause");
}
