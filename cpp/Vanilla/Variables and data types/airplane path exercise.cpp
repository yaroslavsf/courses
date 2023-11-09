#include <iostream>
using namespace std;
int main () {
	
int b1, b2, b3;
double c1, c2, c3, o, s;


	cout << "Enter cost per litre for 3 types of fuel\n";
	cin >> b1 >> b2 >> b3;
	cout << "Enter the distance; fuel consumtion, expressed in litres per 100 km\n";
	cin >> s >> o;
	
	
	
	c1 = (100/s)*b1*o;
	c2 = (100/s)*b2*o;
	c3 = (100/s)*b3*o;
	

			cout << c1 << endl;
		
				cout << c2<< endl;
		
					cout <<c3<<endl;
	
	return 0;
}