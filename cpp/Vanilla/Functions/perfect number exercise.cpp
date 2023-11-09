#include <iostream>
#include <locale>
using namespace std;
void perfect(int a, int b)
{
	int z = 0;
	
	for (int q = a; q < b; q++)
	{
		int sum_divider = 0;

		for (int d = 1;d < q; d++)
			{
			if (q % d == 0)
				
				sum_divider += d;
		
			}


		if (sum_divider == q)
		{
			cout << q << ' ';
		}
	}	
	
}
int main()

{
	setlocale(0, "");
	int i, j;
	cout << "¬ведите начало диапазона\n";
	cin >> i;
	cout << "¬ведите конец диапазона\n";
	cin >> j;
	perfect(i, j);
	
}