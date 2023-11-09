#include <iostream>
#include <locale>
using namespace std;
int main()
{
	setlocale(0, "");
	const int j = 4;
	const int i = 2;
	int a[j][i];
	int b;
	cout << "¬ведите число\n";
	cin >> b;
	for (int y = 0; y < j; y++)
	{
		for (int x = 0; x < i; x++)
		{
			a[y][x] = b;
			b = a[y][x] + 1;
			cout << b << ' ';
		}
		cout << endl;
	}
	return 0;
}
