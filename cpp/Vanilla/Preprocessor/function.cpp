#include <iostream>
#include <cstdlib>
#include <ctime>
#include "function.h"
#ifdef INTEGER
using namespace std;
template <typename T>
T action(T*& a, T n)
{
	setlocale(0, "");
	cout << "¬ведите:\na - дл€ заполнени€ массива случайными числами\n"
		<< "b - дл€ вывода значений в консоль\n"
		<< "c - дл€ поиска мимнимального элемента\n"
		<< "d - дл€ поиска маскимального элемента\n"
		<< "e - дл€ сортировки массива\n"
		<< "f - дл€ редактировани€ значений массива\n";
	char b;
	cin >> b;
	switch (b)
	{
	case 97:
#ifdef INTEGER
		IntArrayFill(a, n);
#endif // INTEGER
#ifdef FLOAT
		FloatArrayFill(a, n);
#endif // FLOAT
#ifdef CHAR
		CharArrayFill(a, n);
#endif // CHAR
		break;

	case 98:
#ifdef INTEGER
		IntArrayPrint(a, n);
#endif // INTEGER
#ifdef FLOAT
		FloatArrayPrint(a, n);
#endif // FLOAT
#ifdef CHAR
		CharArrayPrint(a, n);
#endif // CHAR

		break;

	case 99:
#ifdef INTEGER
		IntSearchMin(a, n);
#endif // INTEGER
#ifdef FLOAT
		FloatSearchMin(a, n);
#endif // FLOAT
#ifdef CHAR
		CharSearchMin(a, n);
#endif // CHAR	
		break;

	case 100:
#ifdef INTEGER
		IntSearchMax(a, n);
#endif // INTEGER
#ifdef FLOAT
		FloatSearchMax(a, n);
#endif // FLOAT
#ifdef CHAR
		CharSearchMax(a, n);
#endif // CHAR

		break;

	case 101:
#ifdef INTEGER
		IntArraySort(a, n);
#endif // INTEGER
#ifdef FLOAT
		FloatArraySort(a, n);
#endif // FLOAT
#ifdef CHAR
		CharArraySort(a, n);
#endif // CHAR

		break;

	case 102:
#ifdef INTEGER
		IntArrayEdit(a, n);
#endif // INTEGER
#ifdef FLOAT
		FloatArrayEdit(a, n);
#endif // FLOAT
#ifdef CHAR
		CharArrayEdit(a, n);
#endif // CHAR


		break;
	}
	return 1;
}

void IntArrayFill(int* &a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 9;
	}
}

void IntArrayPrint(const int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void IntSearchMin(const int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	cout <<  min;
}

void IntSearchMax(const int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	cout << max;
}

void IntArraySort(int* &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void IntArrayEdit(int*& a, int n)
{
	cout << "¬ведите номер эелемента дл€ редактировани€\n";
	int x1;
	cin >> x1;
	cout << "¬ведите значение элелмента\n";
	int x2;
	cin >> x2;
	a[x1] = x2;
}
#endif // INTEGER

#ifdef FLOAT
void FloatArrayFill(float*& a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 9.0;
	}
}

void FloatArrayPrint(const float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void FloatSearchMin(const float a[], int n)
{
	float min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	cout << min;
}

void FloatSearchMax(const float a[], int n)
{
	float max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	cout << max;
}

void FloatArraySort(float*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void FloatArrayEdit(float*& a, int n)
{
	cout << "¬ведите номер эелемента дл€ редактировани€\n";
	int x1;
	cin >> x1;
	cout << "¬ведите значение элелмента\n";
	float x2;
	cin >> x2;
	a[x1] = x2;
}
#endif // FLOAT

#ifdef CHAR
void CharArrayFill(char*& a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 9;
	}
}

void CharArrayPrint(const char a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void CharSearchMin(const char a[], int n)
{
	char min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	cout << min;
}

void CharSearchMax(const char a[], int n)
{
	char max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	cout << max;
}

void CharArraySort(char*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void CharArrayEdit(char*& a, int n)
{
	cout << "¬ведите номер эелемента дл€ редактировани€\n";
	int x1;
	cin >> x1;
	cout << "¬ведите значение элелмента\n";
	int x2;
	cin >> x2;
	a[x1] = x2;
}
#endif // CHAR
