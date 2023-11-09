#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void copy(int* n1, int* n2, int b[])
{
	for (int i = 0; n1 <= n2; n1++, i++)
	{
		b[i] = *n1;
	}	
}
int main()
{
	srand(time(NULL));
	const int n = 5;
	int a[n];
	int b[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 9;
		cout << a[i] << ' ';
	}
	copy(&a[0], &a[n-1], b);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << ' ';
	}
	return 0;
}


