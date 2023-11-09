#include <iostream>
using namespace std;
char* Uppercase(char* str1)
{
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] > 96 && str1[i] < 123)
		{
			str1[i] = (int)str1[i] - 32;
		}
	}
	return str1;
}

int main()
{
	char str[] = "zx C 123 %";
	cout <<  str;
	cout << endl << Uppercase(str);
	return 0;
}