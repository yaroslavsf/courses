#include <iostream>
#include <ctime>
#include <locale>
#include <cstdlib>
using namespace std;
int main ()
{
	int	*a, *b, *c;
	int m, n;
	cin >> m >> n;
	int k = m + n;
	a = new int[m];
	b = new int[n];
	c = new int[k];
	for (int i = 0; i < m; i++)
	{
		a[i] = rand() % 9;
		cout << a[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		b[i] = rand() % 9;
		cout << b[i] << ' ';
	}

	int* q = c;
	for (int i =0; i < m; i++)
	{
		*q++ = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		*q++ = b[i];
	}
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		cout << c[i] << ' ';
	}
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}

