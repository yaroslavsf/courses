#include <iostream>
using namespace std;
int main () {
	int a, k1; // a - ���� ����� ������ ������
	double b, c, k2; // b - ������������ ����� � ������; c - �������� �����
	
	
	
	
	
	
	cin >> a >> b;
	k1 = b; //������
	k2 = 100*(b-k1); //�������
	
	
	
	c = ((k1*60+k2) * a/60); 
	cout << c;
	return 0;
}




