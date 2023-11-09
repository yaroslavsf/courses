#include <iostream>
using namespace std;
char * mystrrev(char* str)
{
	char* begin = str;
	int k = 0;
	while (*str++ != '\0')
	{
		k++;
	}
	char* end = begin + k;



	while (begin < end);
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end++;
	} 



	return str-k;
}

int main()
{
	char str[] = "ZX C 123 %";
	cout << str;
	cout << endl << mystrrev(str);
	return 0;
}