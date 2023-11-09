#include <iostream>
using namespace std;
int main()
{
	int a;
	int d;
	int z = 0;
	int f = 0;
	cin >> a;
	for (int i = a; i > 0; i = i / 10)
	{

		d = i % 10;
		if ((d != 3) && (d != 6))
		{
			z = d + z * 10;	
			
		}

	}
	for (int i = z; i > 0; i /= 10)
	{
		f = f*10 + i % 10;
	}
	cout << f;
	return 0;
}
