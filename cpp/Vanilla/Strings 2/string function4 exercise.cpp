#include <iostream>
using namespace std;
char* Lowercase(char* str1)
{
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] > 64 && str1[i] < 91)
		{
			str1[i] = (int)str1[i] + 32;
		}
	}
	return str1;
}

int main()
{
	char str[] = "ZX C 123 %";
	cout <<  str;
	cout << endl <<Lowercase(str);
	return 0;
}