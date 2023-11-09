#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale>
using namespace std;
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int* a;
	int* a1;
	int m;
	cin >> m;
	a = new int[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = rand() % 9;
		cout << a[i] << ' ';
	}
	cout << "Выберите\n1 - чтобы удалить чётные\n2 - чтобы удалить нечётные\n";
	int z;
	cin >> z;
	int counter = 0;
	switch (z)
	{
	case 1:
		for (int i = 0; i < m; i++)
		{
			if (a[i] % 2 == 0)
			{
				counter++;  
			}
		}
		break;
	case 2:
		for (int i = 0; i < m; i++)
		{
			if (a[i] % 2 != 0)
			{
				counter++;  
			}
		}
		break;
	}
	a1 = new int[counter];
	int* start = a1;
	if (z == 1)
	{
		for (int i = 0; i < m; i++)
		{
			if (a[i] % 2 != 0)
			{
				*start++ = a[i];
			}
		}	
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (a[i] % 2 == 0)
			{
				*start++ = a[i];
			}
		}
	}
	cout << endl;
	for (int i = 0; i < m-counter; i++)
	{
		cout << a1[i] << ' ';
	}
	delete[] a;
	return 0;
}