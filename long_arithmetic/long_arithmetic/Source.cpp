#include <iostream>
#include <string>

using namespace std;

string to_str(int n)
{
	char buf[40];
	sprintf_s(buf, "%d", n);
	return buf;
}


string summ_str(string str1, string str2)
{
	int str_length1 = str1.length();
	int str_length2 = str2.length();

	int l = 0;

	if (str_length1 > str_length2)
	{
		l = str_length1 - str_length2;
		int n = l;
		while (n != 0)
		{
			str2.insert(0, "0");
			n--;
		}
	}
	else
	{
		l = str_length2 - str_length1;
		int n = l;
		while (n != 0)
		{
			str1.insert(0, "0");
			n--;
		}
	}

	bool flag = 0;
	string sum_str = "";
	int sum = 0, _sum = 0;
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (flag == 0)
		{
			sum = ((str1[i] - '0') + (str2[i] - '0'));
			if ((sum>9) && (i != 0))
				_sum = ((str1[i] - '0') + (str2[i] - '0')) % 10;
		}
		else
		{
			sum = (str1[i] - '0') + (str2[i] - '0') + 1;
			if (sum > 9)
				_sum = ((str1[i] - '0') + (str2[i] - '0') + 1) % 10;

			flag = 0;
		}

		if ((sum > 9) && (i != 0))
		{
			flag = 1;
			sum_str = sum_str + char(_sum + 48);
		}
		else if ((sum > 9) && (i == 0))
		{
			string ss = to_str(sum);
			std::reverse(ss.begin(), ss.end());
			sum_str = sum_str + ss;

		}
		else
			sum_str = sum_str + char(sum + 48);

	}

	std::reverse(sum_str.begin(), sum_str.end());
	return sum_str;

}

void main()
{
	string str1, str2;
	setlocale(LC_ALL, "Rus");
	cout << "the first line: ";
	getline(cin, str1);

	cout << "the second line: ";
	getline(cin, str2);

	cout << summ_str(str1, str2);

	cout << endl;

	system("pause");

}