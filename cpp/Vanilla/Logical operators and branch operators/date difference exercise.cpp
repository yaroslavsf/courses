#include <iostream>
using namespace std;
int main () {
int distance1, distance2, m, x;
cout << "enter the distance between A-B:\n";
cin >> distance1;
cout << "enter the distance between B-C:\n";
cin >> distance2;
cout << "enter the cargo weight\n";
cin >> m;
if (m <= 500) 
{
	x = (distance1+distance2) / 1;
	if (x > 300) 
{
	cout << x-300;
}
else 
{
	cout << "We have enough fuel";
}
}
if (m > 500 && m <=1000) 
{
	x = (distance1+distance2) / 4;
	if (x > 300) 
{
	cout << x-300;
}
else 
{
	cout << "We have enough fuel";
}
}
if (m > 1000 && m <=1500) 
{
	x = (distance1+distance2) / 7;
	if (x > 300) 
{
		cout << x-300;
}
else 
{
	cout << "We have enough fuel";
}
}
if (m > 1500 && m <= 2000)
{
	x = (distance1+distance2) / 9;
	if (x > 300)
{
		cout << x-300;
}
else 
{
	cout << "We have enough fuel";
}
}
if ( m > 2000) 
{
	cout << "Error";
}
	return 0;
}