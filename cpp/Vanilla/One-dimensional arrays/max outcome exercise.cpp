#include <iostream>
using namespace std;
int main()
{	
	setlocale(0, "");
	int a[12];
	int d, b;
	int max,min;
	cout << "������� ������� �� ������ �����(12)"<< endl;
	for (int i = 0; i < 12; i++)
	{
		cin >> a[i];
	}
	cout << "������� ������ ���������"<< endl;
	
	cin >> d;
	cout << "������� ����� ���������" << endl;
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
	cout << "����������� �����" << min << endl;
	cout << "����������� �����" << max;
	return 0;
}