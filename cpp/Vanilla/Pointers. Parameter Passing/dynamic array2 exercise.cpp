#include <ctime>
#include <locale>
#include <cstdlib>
#include <iostream>
using namespace std;
int* delete_simple(int** a, int& n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[0][i] == 0 || a[0][i] == 1)
		{
			continue;
		}
		int count = 0;
		for (int j = 1; j <= a[0][i]; j++)
		{
			if (a[0][i] % j == 0)
			{
				count++;
			}
		}
		if (count == 2)
		{
			k++;
		}
	}
	cout << endl << "кол-во простых чисел= "<<k << endl;	
	int* b = new int[n-k];
	int* q = b;

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 1; j <= a[0][i]; j++)
		{
			if (a[i] == 0)
			{
				continue;
			}
			if (a[0][i] % j == 0)
			{
				count++;
			}
		}
		if (count != 2)
		{
			*b++ = a[0][i];

		}
	}

	delete[] a[0];
	*a = b;
	n = n - k;
	return q;
}
int main()
{
	srand(time(NULL));
	setlocale(0, "");
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 9;
		cout << a[i] << ' ';
	}
	cout << delete_simple(&a, n);
	return 0;
}