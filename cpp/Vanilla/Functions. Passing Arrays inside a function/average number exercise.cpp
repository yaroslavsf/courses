#include <iostream>
#include <locale>
#include <cstdlib>
using namespace std;
int arithmetic_mean(int a[], int i)
{
	int sum = 0;
	for (int j = 0; j < i; j++)
	{
		a[j] = rand() % 9;
		cout << a[j] << ' ';
		sum += a[j];
	}
	return sum;
}
int main ()
{
	setlocale(0, "");
	int i;
	do
	{ 
		cout << "¬ведите кол-во елементов массива, не больше 1000 эелементов\n";
		
		cin >> i;
		

	}while(i > 100);
	int a[100];
	cout << endl << arithmetic_mean(a, i);
	return 0;
}