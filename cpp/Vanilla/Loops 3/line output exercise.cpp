#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int n,a,b;
	cout << "������� ����� �����\n";
	cin >> n;
	cout << "������� �����, � ����������� �� ����, �� ����� �������� �� ������ ������� �����\n"
		<< "1 - �������\n"
		<< "2 - �������\n"
		<< "3 - ������\n";
	cin >> a;
	cout << "������� �����, � ����������� �� ����, ����� ����� �� ������� �������\n"
		<<"1 - �������������� \n"
		<<"2 - ������������ \n";
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