#include <iostream>
using namespace std;
int main () {
	int a, z,x,c, b;
	cin >> a;
	z = a/3600;
	x = a%3600/60;
	c = a - (z*3600 + x*60);
	cout << "current time: " << z << ":" << x << ":" << c <<endl;
		b = 24*3600 - a;
	cout << "time until midnight: " << (24*3600 - a)/3600 << ":" << (24*3600 - a)%3600/60 << ":" 
	<< (24*3600 - a) - (((24*3600 - a)/3600)*3600 + ((24*3600 - a)%3600/60)*60) <<endl; 
	
	

	return 0;
}           