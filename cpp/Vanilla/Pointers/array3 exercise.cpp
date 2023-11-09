#include <iostream>
#include <ctime>
#include <locale>
#include <cstdlib>
using namespace std;
void copy_and_reverse(int* n1, int* n2, int b[])
{
	for (int i = 0; n2 >= n1; n2--, i++)
	{
		b[i] = *n2;
	}
}
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	const int n = 5;
	int a[n];
	int b[n];
	cout << "Массив a[]:\n";
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 9;
		cout << a[i] << ' ';
	}
	copy_and_reverse(&a[0], &a[n - 1], b);
	cout << endl << "Массив b[]:\n"; 
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << ' ';
	}
	return 0;
}



