#include <iostream>
#include <locale.h>
using namespace std;
int main () {
	 setlocale(LC_ALL, "Russian");
	int s, k1;
	double t, v, k2;
	
	
	
	

	cout << "���������� �������� ����." << endl;


	cout << "������� ����� ��������� (������) = ";
	cin >> s;


	cout <<"������� ����� (���.���) = ";
	cin >> t;
		 k1 = t;
	k2 = 100*(t-k1);	

	cout << "���������: " << s << endl;

	cout << "�����: " << k1 << " ��� " << k2 << " ��� = " << k1*60 + k2 << endl;

	cout << "�� ������ �� ���������: " << s/(k1*60 + k2)*3.6 << endl;
	return 0;
}




