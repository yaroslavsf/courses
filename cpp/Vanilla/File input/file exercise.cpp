#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	FILE* p;
	fopen("txt.txt", "w");
	fputs("string", p);
	fclose(p);
	return 0;
}