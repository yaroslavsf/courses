#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <iomanip>
#include <typeinfo>
using namespace std;
const int i = 3, j = 3;
double factor = 1.2473309;
template <typename T>
T fun_main(T a[j][i])
{
	char c;
	srand(time(NULL));
	for (int y = 0; y < j; y++)
	{
		for (int x = 0; x < i; x++)
		{
			a[y][x] = (double)(rand()) / RAND_MAX * 9;
			if (typeid(T) == typeid(c))
			{
				cout << setprecision(2) << a[y][x] <<'('<<(int)a[y][x] << ") ";
			}
			else
			{
				cout << setprecision(2) << a[y][x] << ' ';
			}
		}
		cout << endl;
	}
	T max = a[0][0], min = max;

	for (int y = 0; y < j; y++)
	{
		for (int x = 0; x < i; x++)
		{
			if (y == x)
			{
				if (min > a[y][x])
				{
					min = a[y][x];
				}
				if (max < a[y][x])
				{
					max = a[y][x];
				}
			}
		}
	}
	cout << "(гл. диагональ): \n" << "min = ";
	if (typeid(T) == typeid(c))
	{
		cout << setprecision(2) << min << '(' << (int)min << ") ";
		cout << " max = " << setprecision(2) << max << '(' << (int)max << ") " << endl;
	}
	else
	{
		cout << setprecision(2) << min << " max = " << setprecision(2) << max << endl;
	}
	
	int step = i;
	while (step >= 1)
	{
		for (int x = 0; x < i; x++)
		{
			for (int z = 0; z + step < i; z++)
			{
				if (a[x][z] > a[x][z + step])
				{
					T temp = a[x][z];
					a[x][z] = a[x][z + step];
					a[x][z + step] = temp;
				}
			}
		}
		step /= factor;
	}
	cout << "Отсортированый массив в каждой строке: \n";
	for (int y = 0; y < j; y++)
	{
		for (int x = 0; x < i; x++)
		{
			if (typeid(T) == typeid(c))
			{
				cout << setprecision(2) << a[y][x] << '(' << (int)a[y][x] << ") ";
			}
			else
			{
				cout << setprecision(2) << a[y][x] << ' ';
			}
			
		}
		cout << endl;
	}
	cout << endl;
	return 1;
}

int fun(int a[j][i])
{
	cout << "Массив целых: \n";
	fun_main(a);
	return 1;
}
double fun(double b[j][i])
{
	cout << "Массив дробных: \n";
	fun_main(b);
	return 1;
}
char fun(char c[j][i])
{
	cout << "Массив символьных: \n";
	fun_main(c);
	return 1;
}
int main()
{
	setlocale(0, "");
	int a[j][i];
	double b[j][i];
	char c[j][i];
	fun(a);
	fun(b);
	fun(c);
	srand(time(0));
	return 0;
}
