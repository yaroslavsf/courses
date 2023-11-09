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
				cout <<"число "<< a << " не делится на " <<b<<"*"<<b<<"*"<<b << " без остатка\n";
			}
				if (a % (b * b) == 0)
		{
			cout << "число " << a << "  делится на "<<b<<"*"<<b<< " без остатка\n";

		}
		
	}

	return 0;
}
