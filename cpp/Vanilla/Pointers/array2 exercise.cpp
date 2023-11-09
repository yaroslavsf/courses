#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale>
using namespace std;
void reverse(int* n1, int* n2)
{
	while (n1 < n2)
	{
		int temp = *n1;
		*n1 = *n2;
		*n2 = temp;
		n1++;
		n2--;
	}
}
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	const int n = 5;
	int a[n];
	cout << "Массив до:\n";
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 9;
		cout << a[i] << ' ';
	}
	reverse(&a[0], &a[n-1]);
	cout << endl << "Массив после:\n";;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}