#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	int a, b=1;
	cin >> a;
	for (b; b <= a; b++)
	{
	
			if (a%(b*b*b) != 0)
			{
				cout <<"����� "<< a << " �� ������� �� " <<b<<"*"<<b<<"*"<<b << " ��� �������\n";
			}
				if (a % (b * b) == 0)
		{
			cout << "����� " << a << "  ������� �� "<<b<<"*"<<b<< " ��� �������\n";

		}
		
	}

	return 0;
}
