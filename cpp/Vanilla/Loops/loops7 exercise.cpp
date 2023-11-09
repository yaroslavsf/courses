#include <iostream>
using namespace std;
int main() {
	int a, b, max;
	cin >> a >> b;
	if (a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	for (int i = 1;i <= max; i++)
	{
		if ((a%i == 0) && (b%i == 0))
		{
			cout << i << ' ';
		}
	}
	return 0;
}