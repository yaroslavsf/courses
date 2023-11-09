#include <iostream>
#include <ctime>
#include <locale>
#include <cstdlib>
using namespace std;
int check_years(int year)
{
	if (year % 4 == 0 || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int count_month(int month, int day, int year)
{
	int a = 0;
	switch (month)
	{
	case 12:
		a += 30;
	case 11:
		a += 31;
	case 10:
		a += 30;
	case 9:
		a += 31;
	case 8:
		a += 31;
	case 7:
		a += 30;
	case 6:
		a += 31;
	case 5:
		a += 30;
	case 4:
		a += 31;
	case 3:
		if (check_years(year) == 1)
		{
			a += 29;
		}
		else
		{
			a += 28;
		}
	case 2:
		a += 31;
	case 1:
		a += 0;
	}
		a = a + day;
		return a;
}
int convert_years_in_days(int year1, int year2)
{
	int a = 0;
	for (; year1 < year2; year1++)
	{
		if (check_years(year1) == 1) 
		{
			a += 366;
		}
		else
		{
			a += 365;
		}
	}
	
	return a;
}

int count_days(int year1, int year2, int month1, int month2, int day1, int day2)
{
	int result;
	result = convert_years_in_days(year1, year2) + count_month(month2, day2, year2) - count_month(month1, day1, year1);
		return result;
}
int main()
{
	setlocale(0, "");
	int year1, year2, month1, month2, day1, day2;
	cout << "\n";
	cout << "¬ведите 1 мес€ц\n";
	cin >> month1;
	cout << "¬ведите 1 день\n";
	cin >> day1;
	cout << "¬ведите 1 год\n";
	cin >> year1;
	cout << "\n";
	cout << "¬ведите 2 мес€ц\n";
	cin >> month2;
	cout << "¬ведите 2 день\n";
	cin >> day2; 
	cout << "¬ведите 2 год\n";
	cin >> year2;
	cout <<endl << count_days(year1, year2, month1, month2, day1, day2);
	return 0;
}
		