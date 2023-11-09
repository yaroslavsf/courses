#include <iostream>
using namespace std;
int main () {
	setlocale (0, "");
	char a;
	cin >> a;
	int b = a;
	if (b>= 48 && b<=57)
	{
		cout << "it's a numeral";
		return 0;
	}
	else 
	{
	if ((b>=65 && b<=90) || (b>=97 && b<=122))
	{
		cout << "it's a letter";
	return 0;	
	}
	else	
	{
		cout << "it's a sign";
	return 0;
	}
	
}
	
	return 0;
}