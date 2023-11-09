#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int generate(int b)
{	
	while (1)
	{ 
	b = 1000 + rand() % (9999 - 1000 + 1);
		if ((b % 10 != b / 10 % 10) && (b / 10 % 10 != b / 100 % 10) && (b / 100 % 10 != b / 1000) && (b / 10 % 10 != b / 1000) && (b % 10 != b / 1000))
		{
			return b;
		}
	}

	
}
int bulls(int a, int b)
{
	if (a == 0 && b == 0)
		return 0;
	return bulls(a / 10, b / 10) + (a % 10 == b % 10); 
}

int cows(int a, int b)
{
	if (a == 0)
		return 0;
	return cows(a / 10, b) + (a % 10 == b % 10) + (a%10 == b/10%10) + (a%10==b/100%10) + (a% 10 == b/1000);
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int b = 0, a;
	cout << "Введите число (4 знака)\n";
	cin >> a;
	b = generate(b);
	cout << "Ваше число: " << a << "\nЧисло оппонента: " << b << endl;
	cout << "Быков= " << bulls(a, b);
	cout << "Коров=";
	if (bulls(a, b) > 0)
	{
	cout << cows(a, b) - bulls(a, b);
	}
	else
	{
	cout << cows(a, b);	
	}
	return 0;
}