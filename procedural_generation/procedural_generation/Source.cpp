/*
ѕроцедурна€ генераци€2. «аполните случайные €чейки двумерного массива размером N на N единицами.
ѕри этом единицы не должны соприкасатьс€ друг с другом ни по горизонтали, ни по вертикали, ни по диагонали.
¬ массив нужно поставить максимально возможное число единиц. (см рис)

*/

#include <iostream>

using namespace std;

void procedural_generation2(char mas[20][20], int N)
{
	int m, n;
	int counter = 0;

	while (counter <= 10000)
	{
		m = rand() % (N + 1) + 0;
		n = rand() % (N + 1) + 0;
		if ((m != 0) && (n != 0) && (m != N - 1) && (n != N - 1))
		{
			if ((mas[m][n] == '*') && (mas[m - 1][n] == '*') && (mas[m + 1][n] == '*')
				&& (mas[m][n - 1] == '*') && (mas[m][n + 1] == '*')
				&& (mas[m + 1][n - 1] == '*') && (mas[m - 1][n + 1] == '*')
				&& (mas[m - 1][n - 1] == '*') && (mas[m + 1][n + 1] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}
		else if ((m == 0) && (n == 0))
		{
			if ((mas[m + 1][n] == '*') && (mas[m][n + 1] == '*') && (mas[m + 1][n + 1] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}
		else if ((m == N - 1) && (n == 0))
		{
			if ((mas[m - 1][n] == '*') && (mas[m][n + 1] == '*') && (mas[m - 1][n + 1] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}
		else if ((m == N - 1) && (n == N - 1))
		{
			if ((mas[m][n - 1] == '*') && (mas[m - 1][n] == '*') && (mas[m - 1][n - 1] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}
		else if ((m == 0) && (n == N - 1))
		{
			if ((mas[m][n - 1] == '*') && (mas[m + 1][n] == '*') && (mas[m + 1][n - 1] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}
		else if ((m > 0) && (m < N - 1) && (n == 0))
		{
			if ((mas[m][n + 1] == '*') && (mas[m - 1][n + 1] == '*') && (mas[m + 1][n + 1] == '*') &&
				(mas[m + 1][n] == '*') && (mas[m - 1][n] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}
		else if ((m = 0) && (n < N - 1) && (n > 0))
		{
			if ((mas[m + 1][n] == '*') && (mas[m + 1][n - 1] == '*') && (mas[m + 1][n + 1] == '*') &&
				(mas[m][n + 1] == '*') && (mas[m][n - 1] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}
		else if ((m < N - 1) && (m > 0) && (n = N - 1))
		{
			if ((mas[m][n - 1] == '*') && (mas[m - 1][n - 1] == '*') && (mas[m + 1][n - 1] == '*') &&
				(mas[m + 1][n] == '*') && (mas[m - 1][n] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}
		else if ((m = N - 1) && (n > 0) && (n < N - 1))
		{
			if ((mas[m - 1][n] == '*') && (mas[m - 1][n - 1] == '*') && (mas[m - 1][n + 1] == '*') &&
				(mas[m][n + 1] == '*') && (mas[m][n - 1] == '*'))
			{
				mas[m][n] = (char)(1 + 48);
				counter++;
			}
		}

	}

}

void main()
{
	setlocale(LC_ALL, "Rus");
	int N, x;
	char mas[20][20];
	cout << "¬ведите размер квадратной матрицы: ";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			mas[i][j] = '*';
		}
	}

	procedural_generation2(mas, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << mas[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;


	cout << endl;
	cout << endl;

	system("pause");

}