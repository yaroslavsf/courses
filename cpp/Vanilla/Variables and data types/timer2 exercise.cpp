#include <iostream>
using namespace std;
int main () {
	int a;
	cin >> a;
	if (a <= 8*3600) 
	{
	
	cout << (8*3600 - a) / 3600;
}
else
{
	cout << " it's time to go home";
}
}