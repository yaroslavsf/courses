#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
int main() {	
	setlocale(0, "");
	int a,d=0,s,n=0,sum = 0;
	cout << "������� �����\n";
	cin >> a;
	for (int i = a; i > 0; i /= 10)
	{
		sum += i % 10;//����
		d++; // ���������� ����
		s = sum / d;//����.�������
		if (i % 10 == 0)
		{
			n++; //���������� �����
		}
	}
	cout << "�������\n1-���� ����\n2-���������� ����\n3-������� ��������������\n4-���������� �����\n";
	cout << "________________________________________________________________________\n";
	int q;
	cin >> q;
	switch (q)
	{
	case 1:
		system("cls");
		cout << "���� ����:\n";
		cout << sum;
		break;
	case 2:
		system("cls");
		cout << "���������� ����:\n";
		cout << d;
		break;
	case 3:
		system("cls");
		cout << "������� ��������������:\n";
		cout << s;
		break;
	case 4:
		system("cls");
		cout << "���������� �����:\n";
		cout << n;
		break;
	}
	return 0;
}