#include <iostream>
#include <locale.h>
#include <cstdlib>
using namespace std;
int main()
{
	setlocale(0, "");
	int n;
	double sum_negative = 0, min, max, mult_mm = 1, sum_even = 0, negative1, negative2, sum_negative1and2 = 0;
	int minn, maxn; 
	int negative1n, negative2n;
	cout << "Введите кол-во елементов массива: \n";
	cin >> n;
	double* a = new double[n];
	cout << "Введите сам массив: \n";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	min = a[0];
	max = a[0];
	minn = 0;
	maxn = 0;
	negative1n = 0;
	negative2n = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			sum_negative += a[i];
		}
		if ((i % 2) != 0)
		{
			sum_even += a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
			maxn = i;
		}
		if (a[i] < min)
		{
			min = a[i];
			minn = i;
		}
		if (a[i] < 0)
		{
			negative2 = a[i];
			negative2n = i;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			negative1 = a[i];
			negative1n = i;
			break;
		}
	}
	//cout << sum_negative;
	if (maxn >= minn)
	{
		for (; minn <= maxn; minn++)
		{
			mult_mm *= a[minn];
		}
	}
	else
	{
		for (; maxn <= minn; maxn++)
		{
			mult_mm *= a[maxn];
		}

	}
	// cout << mult_mm;
	// cout << sum_even;
	for (; negative1n <= negative2n; negative1n++)
	{
		sum_negative1and2 += a[negative1n];
	}
	//cout << sum_negative1and2;
	system("cls");
	cout << "Ваш массив:\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	cout << "Введите: \n"
		<< "1 - Сумму отрицательных элементов.\n"
		<< "2 - Произведение элементов, находящихся между min и max элементами\n"
		<< "3 - Произведение элементов с четными номерами.\n"
		<< "4 - Сумма элементов, находящихся между первым и последним отрицательными элементами.\n";
	int d;
	cin >> d;
	system("cls");
	cout << "Ваш массив:\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	switch (d)
	{
	case 1:
		cout << "Сумма отрицательных елемнтов: \n" << sum_negative;
		break;
	case 2:
		cout << "Произведение элементов, находящихся между min и max элементами:\n" << mult_mm;
		break;
	case 3:
		cout << "Произведение элементов с четными номерами:\n" << sum_even;
		break;
	case 4:
		cout << "Сумма элементов, находящихся между первым и последним отрицательными элементами:\n" << sum_negative1and2;
		break;


	}
	return 0;
}
