#include <iostream>
using namespace std;
int main () {
	int a, h, m, s;  
	cin >> a;// ��� � �����, ��������� ������ ���������� ������ � �������� ����� � ����,������,�������
	h = a/3600;
	m = a%3600/60;
	s = a-(h*3600 + m*60);
		cout << "hours: "<< h << " minutes: " << m << " seconds: " << s;
	return 0;
}
/*
�������, � �������� ����� � ������ ������, �� ���-��.
��� ��� ������ ��� ������ ����������� ����� � �������� �������� � �����, �������, ��������


#include <iostream>
using namespace std;
int main () {
int a;
cin >> a;
cout << " hours: " << a/3600 <<endl;
cout << " minutes: " << a/60 << endl;
cout << " seconds: "<<  a <<endl;
	return 0;
}
*/