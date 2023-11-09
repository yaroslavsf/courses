#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int n,a,b;
	cout << "¬ведите длину линии\n";
	cin >> n;
	cout << "¬ведите цифру, в зависимости от того, на какой скорости вы хотите вывести линию\n"
		<< "1 - мдленно\n"
		<< "2 - среднье\n"
		<< "3 - быстро\n";
	cin >> a;
	cout << "¬ведите цифру, в зависимости от того, какую линию вы ххотите вывести\n"
		<<"1 - горизонтальна€ \n"
		<<"2 - вертикальна€ \n";
	cin >> b;
	for (int i = 0; i < n; i++)
	{
			switch (b)
			{
			case 1:
				cout << "*";
				switch (a)
				{
				case 1:
					for (int i = 0; i < 1000; i++)
					{
						cout << '\a';
					}
					break;
				case 2:
					for (int i = 0; i < 500; i++)
					{
						cout << '\a';
					}
					break;
				case 3:
					for (int i = 0; i < 50; i++)
					{
						cout << '\a';
					}
					break;
				}
				break;
			case 2:
				cout << "*" << endl;
				switch (a)
				{
				case 1:
					for (int i = 0; i < 1000; i++)
					{
						cout << '\a';
					}
					break;
				case 2:
					for (int i = 0; i < 500; i++)
					{
						cout << '\a';
					}
					break;
				case 3:
					for (int i = 0; i < 50; i++)
					{
						cout << '\a';
					}
					break;
				}
				break;
			}
	}
		return 0;
}