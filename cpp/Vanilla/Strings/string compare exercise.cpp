#include <iostream>
using namespace std;
int mystrcmp(const char* str1, const char* str2)
{
	while (*str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return 0;
	}
	else
	{
		if (*str1>*str2)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}
int main()
{
	char str1[] = "str1";
	char str2[] = "str2";
	cout << str1;
	cout << endl << str2;
	cout << endl << mystrcmp(str1, str2);
	return 0;
}