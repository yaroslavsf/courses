#include <iostream>
using namespace std;
int main()
{
	int a;
	int sum = 0;
	cin >> a;
	for (int i = a; i > 0; i = i / 10)
	{
		int d = i % 10;
		sum += d;
	}
	if (sum * sum * sum == a * a)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}