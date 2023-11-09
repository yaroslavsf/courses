#include <iostream>
using namespace std;
int main () {
	int a, k1; // a - цена одной минуты звонка
	double b, c, k2; // b - длительность минут и секунд; c - денюжная сумма
	
	
	
	
	
	
	cin >> a >> b;
	k1 = b; //минуты
	k2 = 100*(b-k1); //секунды
	
	
	
	c = ((k1*60+k2) * a/60); 
	cout << c;
	return 0;
}




