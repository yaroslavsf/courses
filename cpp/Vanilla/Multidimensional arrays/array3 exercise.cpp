#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <locale>
using namespace std;
int main()
{
	setlocale(0, "");
	//int* a = new int[n];
	const int i = 5;
	const int j = 3;
	int a[j][i];
	srand(time(NULL));

	for (int y = 0; y < j; y++)
	{
		for (int x = 0; x < i; x++)
		{
			a[y][x] = rand() % 10;
			cout << a[y][x] << ' ';
		}

		cout << endl;
	}
	cout << "выберите кол-во сдвигов:\n ";
	int z;
	cin >> z;
	cout << "выберите стороны сдвигов\n: 1-влево\n2-вправо\n3-вверх\n4-вниз\n";
	int q;
	cin >> q;
	switch (q)
	{
	case 2:
		for (int p = 0; p < z; p++)
		{

			for (int y = 0; y < j; y++)
			{
				int temp = a[y][0];

				for (int x = 0; x < i - 1; x++)
				{
					a[y][x] = a[y][x + 1];

				}
				a[y][i - 1] = temp;

				cout << endl;
			}
		}
			break;
	case 1:
		for (int p = 0; p < z; p++)
		{
			for (int y = 0; y < j; y++)
			{
				int temp = a[y][i - 1];
				for (int x = i - 2; x >= 0; x--)
				{
					a[y][x + 1] = a[y][x];
				}
				a[y][0] = temp;
				cout << endl;
			}
		}
		break;
	case 3:
		for (int p = 0; p < z; p++)
		{
			for (int x = 0; x < i; x++)
			{
				int temp = a[0][x];
				for (int y = 0; y < j - 1; y++)
				{
					a[y][x] = a[y + 1][x];

				}
				a[j - 1][x] = temp;
			}
		}
		break;
	case 4:
		for (int p = 0; p < z; p++)
		{
			for (int x = 0; x < i; x++)
			{
				int temp = a[j - 1][x];
				for (int y = j - 2; y >= 0; y--)
				{
					a[y + 1][x] = a[y][x];

				}
				a[0][x] = temp;
			}
		}

		break;

	}
	
		for (int y = 0; y < j; y++)
		{
			for (int x = 0; x < i; x++)
			{
				
				cout << a[y][x] << ' ';
			}

			cout << endl;
		}
	
	return 0;
}