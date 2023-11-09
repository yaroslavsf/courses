#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int main()
{
	setlocale(0, "");
	char buf[512];
	char** mas;


	cout << "enter name\n";
	cin.getline(buf, 512);
	mas[0] = new char[strlen(buf)+1];
	strcpy_s(mas[0], strlen(buf)+1, buf);

	cout << "enter phone\n";
	cin.getline(buf, 512);
	mas[1] = new char[strlen(buf) + 1];
	strcpy_s(mas[1], strlen(buf) + 1, buf);
	return 0;
}
