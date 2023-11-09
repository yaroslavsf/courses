#include <iostream>
using namespace std;
int main () {
	int a, h, m, s;  
	cin >> a;// как € пон€л, программа должна переводить данное в секнудах врем€ в часы,минуты,секнуды
	h = a/3600;
	m = a%3600/60;
	s = a-(h*3600 + m*60);
		cout << "hours: "<< h << " minutes: " << m << " seconds: " << s;
	return 0;
}
/*
Ќадеюсь, € правльно пон€л и сделал задачу, но все-же.
¬от код задачи где просто переводитс€ врем€ в секундах отдельно в часах, минутах, секундах


#include <iostream>
using namespace std;
int main () {
int a;
cin >> a;
cout << " hours: " << a/3600 <<endl;
cout << " minutes: " << a/60 << endl;
cout << " seconds: "<<  a <<endl;
	return 0;
}
*/