#include <iostream>
#include <locale>
using namespace std;
void lucky(int a)
{
	if ((a%10 + a/10%10 + a/100%10) == (a/100000 + a/10000%10 + a/1000%10))
	{
		cout << "����������";
	}
	else
	{
		cout << "�������";
	}
}
int main()

{
	setlocale(0, "");
	int d;
	cout << "������� �����\n";
	cin >> d;
	lucky(d);

}