#include <iostream>
using namespace std;
int main () {
	int a;
	cin >> a;
	if (a <= 9999 && a >= 1000)
	{
		cout << a%1000/100 <<a/1000 << a%10<< a%1000/10%10 <<endl;
	}
	else
	{
		cout << "Error";
	}
	return 0;
}


