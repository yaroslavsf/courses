#include <iostream>
#include <locale.h>
using namespace std;
int main () {
	 setlocale(LC_ALL, "Russian");
	int s, k1;
	double t, v, k2;
	
	
	
	

	cout << "Вычисление скорости бега." << endl;


	cout << "Введите длину дистанции (метров) = ";
	cin >> s;


	cout <<"Введите время (мин.сек) = ";
	cin >> t;
		 k1 = t;
	k2 = 100*(t-k1);	

	cout << "Дистанция: " << s << endl;

	cout << "Время: " << k1 << " мин " << k2 << " сек = " << k1*60 + k2 << endl;

	cout << "Вы бежали со скоростью: " << s/(k1*60 + k2)*3.6 << endl;
	return 0;
}




