#include <iostream>
using namespace std;
int main () {


	int a, b, c; // initial time
	int a1, b1, c1; // endtime
	int k; // price of call
	int v; // talk time
	int s1, s2; 
 
	cout << "write down start time\n";
	cin >> a >> b >> c;
	cout << "wtite down endtime\n";
	cin >> a1 >> b1 >> c1;
	s1 =(a*3600)+(b*60)+(c); // initial time in seconds 
	s2 =(a1*3600)+(b1*60)+(c1); // endtime in seconds
	if (s1 > s2) {
		 
		v = (24*3600-s1+s2); 
	}else{
		v = (s2-s1); 
	}
	
	k = v/2;
	
	
	cout <<k;
	return 0;
}


