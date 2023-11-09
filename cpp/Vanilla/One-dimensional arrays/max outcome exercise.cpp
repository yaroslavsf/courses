#include <iostream>
using namespace std;
int main()
{	
	setlocale(0, "");
	int a[12];
	int d, b;
	int max,min;
	cout << "Введите прибыль за каждый месяц(12)"<< endl;
	for (int i = 0; i < 12; i++)
	{
		cin >> a[i];
	}
	cout << "Введите начала диапазона"<< endl;
	
	cin >> d;
	cout << "Введите конец диапазона" << endl;
	cin >> b;
	d = d - 1;
	min = a[d];
	max = a[d];
	for (int i = d;i<b;i++)
	{
	
		if (min > a[i])
		{
			min = a[i];
		}
		
	}

	for (int i = d; i < b; i++)
	{
	
		if (a[i] > max)
		{
			max = a[i];
		}

	}
	cout << "Минимальное число" << min << endl;
	cout << "Макимальное число" << max;
	return 0;
}