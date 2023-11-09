#include <ctime>
#include <locale>
#include <cstdlib>
#include <iostream>
using namespace std;
void fun(int mas[], const int z)
{
	int positive = 0, negative = 0, zero = 0;
	for (int i = 0; i < z; i++)
	{
		if (mas[i] == 0)
		{
			zero++;
		}
		else
		{
			if (mas[i] > 0)
			{
				positive++;
			}
			else
			{
				negative++;
			}
		}
	}
	int* mas1 = new int[zero];
	int* mas2 = new int[positive];
	int* mas3 = new int[negative];
	int* q1 = mas1;
	int* q2 = mas2;
	int* q3 = mas3;
	for (int i = 0; i < z; i++)
	{
		if (mas[i] == 0)
		{
			*mas1++ = mas[i];
		}
		else
		{
			if (mas[i] > 0)
			{
				*mas2++ = mas[i];
			}
			else
			{
				*mas3++ = mas[i];
			}
		}
	}
	cout << "нулевые елементы:\n";
	for (int i = 0; i < zero; i++)
	{
		cout << *q1++ << ' ';
	}
	cout << endl << "позитвные елементы:\n";
	for (int i = 0; i < positive; i++)
	{
		cout << *q2++ << ' ';
	}
	cout << endl << "негативные елементы:\n";
	for (int i = 0; i < negative; i++)
	{
		cout << *q3++ << ' ';
	}
	cout << endl;
}
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	const int j = 40;
	int a[j];
	for (int i = 0; i < j; i++)
	{
		a[i] = -9 + rand() % (-9 - 9 + 1);
		cout << a[i] << ' ';
	}
	cout << endl;
	fun(a, j);
	srand(time(NULL));
}