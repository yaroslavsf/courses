#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
using namespace std;
int mod(int a, int b)
{
	if (a < b)
	{
		b = b - a;

	}
	else
	{
		a = a - b;

	}
	if (a != b)
	{
		return mod(a, b);
	}
	return a;
}


int main()
{
	setlocale(0, "");
	cout << "";
	int i, j;
	cin >> i >> j;
	cout << "";
	cout << mod(i, j);
}