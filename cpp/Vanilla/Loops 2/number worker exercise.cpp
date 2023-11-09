#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
int main() {	
	setlocale(0, "");
	int a,d=0,s,n=0,sum = 0;
	cout << "Введите число\n";
	cin >> a;
	for (int i = a; i > 0; i /= 10)
	{
		sum += i % 10;//сума
		d++; // колчиесвто цифр
		s = sum / d;//сред.арифмет
		if (i % 10 == 0)
		{
			n++; //количество нулей
		}
	}
	cout << "Введите\n1-сума цифр\n2-количество цифр\n3-среднее арифметическое\n4-количество нулей\n";
	cout << "________________________________________________________________________\n";
	int q;
	cin >> q;
	switch (q)
	{
	case 1:
		system("cls");
		cout << "сума цифр:\n";
		cout << sum;
		break;
	case 2:
		system("cls");
		cout << "количество цифр:\n";
		cout << d;
		break;
	case 3:
		system("cls");
		cout << "среднее арифметическое:\n";
		cout << s;
		break;
	case 4:
		system("cls");
		cout << "количество нулей:\n";
		cout << n;
		break;
	}
	return 0;
}