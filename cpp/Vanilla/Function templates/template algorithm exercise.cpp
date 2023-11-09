#include <iostream>
#include <cstring>
using namespace std;
template <class T>
T max(T a, T b)
{
	return ((a > b) ? a : b);
}

template <class T>
T min(T a, T b)
{
	return ((a < b) ? a : b);
}



template <class T, int a>
void sort(T(&mas)[a])
{
	for (int i = 0; i < a; i++)
	{
		for (int i = 0; i < a - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
			T temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
			}
		}
	}
}

template <class T>
void sort(T *mas, int a)
{
for (int i = 0; i < a; i++)
{
for (int i = 0; i < a - 1; i++)
{
if (a[i] > a[i + 1])
{
T temp = a[i];
a[i] = a[i+1];
a[i + 1] = temp;
}
}
}
}


template <class T, size_t a>
T binary(const T (&mas)[a], T key, size_t left, size_t right)
{
	size_t midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < a[midd])
			right = midd - 1;
		else if (key > a[midd])
			left = midd + 1;
		else
			return a[midd];
		if (left > right)
			return -1;
	}
}



template <class T>
T binary(const T *mas, T key, size_t left, size_t right)
{
	midd = (left + right) / 2;

	if (key < a[midd])
		right = midd - 1;
	else if (key > a[midd])
		left = midd + 1;
	else
		return a[midd];
	if (left > right)
		return -1;
}



int main()
{
	return 0;
}
