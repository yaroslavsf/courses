#include <iostream>
using namespace std;
int main () {
	int a, b, c, m1, max;	
	int i = 1;
	cin >> a;
	cin >> b;
	max = a;
	m1:
		i++;
		
	
	if (b > max)
		{
			max = b;
		}
			
	if (i < 7) 
	{
		cin >> b;
		goto m1;
	} 
	else
	{
		cout << max;
	}
	return 0;
}