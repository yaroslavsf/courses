#include <iostream>
#include <cstdlib>
#include <locale>
#include <ctime>
using namespace std;
double max(const int a[], const int b[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] > max)
		{
			max = b[i];
		}
	}
	return max;

}
double min(const int a[], const int b[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] < min)
		{
			min = b[i];
		}
	}
	return min;
}
double avg(const int a[], const int b[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		sum += b[i];
	}
	return (double)sum / n * 2;
}
double action(double (*p)(const int a[], const int b[], int n), const int a[], const int b[], int n)
{
	return p(a,b,n);
}
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int* a, * b;
	int n;
	cin >> n;
	a = new int[n];
	b = new int[n];
	for (int i = 0; i < n; i++)
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
	cout << endl;
	double (*p[3])(const int a[], const int b[], int n) = { max, min, avg };
	int x;
	cout << "¬ведите 1 - макс\n2- мин\n3 - среднее\n";
	do
	{
		
		cin >> x;
	}while (x < 1 || x > 3);
	cout << action(p[x-1], a, b, n);
	return 0;
}