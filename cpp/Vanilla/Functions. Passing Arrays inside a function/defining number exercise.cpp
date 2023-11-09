#include <iostream>
#include <ctime>
#include <locale>
#include <cstdlib>
using namespace std;
void info(int a[], int z)
{
	int t1 = 0, t2 = 0, t3 = 0;
	srand(time(NULL));
	setlocale(0, "");
	for (int i = 0; i < z; i++)
	{
		a[i] = -9 + rand() % (9 - (-9) + 1);
		cout << a[i] << ' ';
		if (a[i] > 0)
		{
			t1++;
		}
		else
		{
			if (a[i] < 0)
			{
				t2++;
			}
			else
			{
				t3++;
			}
		}
	}
	cout << endl << "кол-во + елементов=" << t1 << endl;
	cout << "кол-во - елементов="<<t2<< endl;
	cout << "кол-во 0 елементов="<< t3<<endl;
}
int main ()
{
	const int z = 10;
	int a[z];
	info(a, z);
	return 0;
}
