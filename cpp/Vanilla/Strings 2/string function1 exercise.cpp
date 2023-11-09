#include <iostream>
using namespace std;
int StringToNumber(const char* str)
{
	int result = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] < '9')
		{
			result = 10 * result + (str[i] - '0');
		}
		else
		{
			break;
		}
	}
	return result;
}

int main()
{
	char str1[] = "123";
	cout << str1;
	cout << endl << StringToNumber(str1);
	return 0;
}