#include <iostream>
#include "function.h"
#define INTEGER
using namespace std;
int main()
{	
	cout << "¬ведите размер массива:\n";
	int n;
#ifdef INTEGER
	cin >> n;
	int* a = new int[n];
#endif

#ifdef FLOAT
	cin >> n;
	int* a = new float[n];
#endif

#ifdef CHAR
	cin >> n;
	int* a = new char[n];
#endif
	action(a,n);
	return 0;
}