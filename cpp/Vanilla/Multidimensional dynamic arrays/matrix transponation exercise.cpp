#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	setlocale(0, "");
	int a, b;
	//	cout << "¬ведите кол-во строк\n";
	cin >> a;
	//	cout << "¬ведите кол-во столбцов\n";
	cin >> b;
	int* c = new int[a * b];
	int* c1 = new int[a * b];
	for (int i = 0; i < a * b; i++)
	{
		c[i] = rand() % 9;
		*c1++ = c[i];
	}
	

	for (int y = 0; y < a; y++)
	{
		for (int x = 0; x < b; x++)
		{
			c[x*a+y] = c1[y*b+x];
		}
	}
	return 0;
}
