#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

bool find_repeat_nums(vector<int> &secret_nums, int m)
{
	for (int j = 0; j < secret_nums.size(); j++)
	{
		if (m == secret_nums[j])
		{
			return false;
		}
	}
	return true;

}

vector<int> secret_num()
{
	vector<int> secret_nums;
	int n = 4;
	while (n != 0)
	{
		int m = rand() % 9 + 0;
		if (find_repeat_nums(secret_nums, m) != false)
		{
			secret_nums.push_back(m);
			n--;
		}
	}
	return secret_nums;
}

vector<int> strr_to_vec(string str)
{
	vector<int> enter_nums;
	for (int i = 0; i < str.size(); i++)
	{
		enter_nums.push_back(str[i] - (int)'0');
	}
	return enter_nums;
}

bool check_count_digits(string str_num)
{
	if (str_num.size() == 4)
		return true;
	else
		return false;
}

bool check_repeat_digits(string str_num)
{
	for (int i = 0; i < str_num.size() - 1; i++)
	{
		for (int j = i + 1; j < str_num.size(); j++)
		{
			if (str_num[i] == str_num[j])
				return false;
		}
	}
	return true;
}

vector<int> enter_num()
{
	int num;
	string str_num;

	cout << "enter a four-digit number (digits not repeat): ";
	cin >> str_num;

	if ((check_count_digits(str_num) == false) || (check_repeat_digits(str_num) == false))
	{
		while ((check_count_digits(str_num) == false) || (check_repeat_digits(str_num) == false))
		{
			cout << "enter a four-digit number (digits not repeat): ";
			cin >> str_num;
		}
	}
	return strr_to_vec(str_num);

}

int numbers_of_cows(vector<int> secret_nums, vector<int> enter_nums)
{
	int sum_cows = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((secret_nums[i] == enter_nums[j]) && (i != j))
			{
				sum_cows++;
			}
		}
	}
	return sum_cows;
}

int numbers_of_buils(vector<int> secret_nums, vector<int> enter_nums)
{
	int sum_builts = 0;

	for (int i = 0; i < 4; i++)
	{
		if (secret_nums[i] == enter_nums[i])
		{
			sum_builts++;
		}
	}
	return sum_builts;
}

bool check_two_numbers(vector<int> secret_nums, vector<int> enter_nums)
{
	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		if (secret_nums[i] != enter_nums[i])
		{
			flag = true;
			break;
		}
	}
	return flag;
}

string num_to_words_cows(int sum_cows)
{
	string str;
	switch (sum_cows)
	{
	case 1:
		str = "One cow";
		break;
	case 2:
		str = "Two cows";
		break;
	case 3:
		str = "Three cows";
		break;
	case 4:
		str = "Four cows";
		break;

	}
	return str;
}

string num_to_words_builts(int sum_builts)
{
	string str;
	switch (sum_builts)
	{
	case 1:
		str = "One bull";
		break;
	case 2:
		str = "Two bulls";
		break;
	case 3:
		str = "Three bulls";
		break;
	case 4:
		str = "Four bulls";
		break;
	}
	return str;

}

int main()
{
	setlocale(LC_ALL, "Rus");

	vector<int> secret_nums = secret_num();

	bool flag = true;

	do
	{
		vector<int> enter_nums = enter_num();

		cout << num_to_words_cows(numbers_of_cows(secret_nums, enter_nums)) << endl;
		cout << num_to_words_builts(numbers_of_buils(secret_nums, enter_nums)) << endl;

		flag = check_two_numbers(secret_nums, enter_nums);

	} while (flag == true);

	system("pause");
}