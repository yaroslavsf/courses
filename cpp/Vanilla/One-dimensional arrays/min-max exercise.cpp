#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	setlocale(0, "");
	int n;
	int min, max;
	cout << "������� ���-�� ��������� �������\n";
	cin >> n;
	int* a = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
		cout << a[i] << " \n";
		
	}
	max = a[0];
	min = a[0];
	for (int i = 0; i < n; i++)
	{
		
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		
		if (a[i] > max)
		{
			max = a[i];

		}
	}

	cout << "������������ �����:" << max << endl;
	cout << "����������� �����:" << min << endl;
	return 0;
}