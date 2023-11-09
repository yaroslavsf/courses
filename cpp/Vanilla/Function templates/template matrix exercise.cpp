#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
template <class T>
T min(T q1, T q2)
{
	T min;
	if (q1 > q2)
		min = q2;
	else
		min = q1;
	return min;
}

template <class T>
class Matrix
{
	T* matrix;
	size_t a;
public:
	//конструкторы
	Matrix() : matrix{ nullptr }, a{ 0 } {}
	Matrix(const size_t a) : matrix{ new T[a * a] }, a{ a }
	{
		for (int i = 0; i < a * a; i++)
		{
			matrix[i] = rand() % 9;
		}
	}
	Matrix(const T& source)
	{
		a = source.a;
		matrix = new T[a * a];
		for (int i = 0; i < a * a; i++)
		{
			matrix[i] = source.matrix[i];
		}
	}
	//функции
	const T* getMatrix() const
	{
		return matrix;
	}
	size_t getSize()
	{
		return a;
	}
	void displayMatrix()
	{
		for (int i = 0; i < a * a; i++)
		{
			std::cout << matrix[i] << ' ';

		}
	}
	void setMatrix()
	{
		std::cout << "set " << a * a << "elements\n";
		for (int i = 0; i < a * a; i++)
		{
			std::cin >> matrix[i];
		}
	}


	T max()
	{
		if (!matrix)
			return 0;
		T max = matrix[0];
		for (int i = 1; i < a * a; i++)
		{
			if (matrix[i] > max)
				max = matrix[i];
		}
		return max;
	}

	T min()
	{
		if (!matrix)
			return 0;
		T min = matrix[0];
		for (int i = 1; i < a * a; i++)
		{
			if (matrix[i] < min)
				min = matrix[i];
		}
		return min;
	}


	//+
	T& operator+=(const Matrix<T>& source)
	{
		if (source.matrix && matrix && (source.a == a))
		{
			T* pointer = matrix;
			for (int i = 0; i < a * a; i++)
			{
				*pointer++ += *source.matrix++;
			}

		}
		return *this;
	}

	T& operator+=(const T& source)
	{
		if (source.matrix && matrix && (source.a == a))
		{
			T* pointer = matrix;
			for (int i = 0; i < a * a; i++)
			{
				*pointer++ += source;
			}

		}
		return *this;
	}

	//-
	T& operator-=(const Matrix<T>& source)
	{
		if (source.matrix && matrix && (source.a == a))
		{
			T* pointer = matrix;
			for (int i = 0; i < a * a; i++)
			{
				*pointer++ -= *source.matrix++;
			}

		}
		return *this;
	}

	T& operator-=(const T& source)
	{
		if (source.matrix && matrix && (source.a == a))
		{
			T* pointer = matrix;
			for (int i = 0; i < a * a; i++)
			{
				*pointer++ -= source;
			}

		}
		return *this;
	}

	// /
	T& operator/=(const Matrix<T>& source)
	{
		if (source.matrix && matrix && (source.a == a))
		{
			T* pointer = matrix;
			for (int i = 0; i < a * a; i++)
			{
				*pointer++ /= *source.matrix++;
			}

		}
		return *this;
	}

	T& operator/=(const T& source)
	{
		if (source.matrix && matrix && (source.a == a))
		{
			T* pointer = matrix;
			for (int i = 0; i < a * a; i++)
			{
				*pointer++ /= source;
			}

		}
		return *this;
	}

	//*
	T& operator*=(const Matrix<T>& source)
	{
		if (source.matrix && matrix && (source.a == a))
		{
			T* pointer = matrix;
			for (int i = 0; i < a * a; i++)
			{
				*pointer++ *= *source.matrix++;
			}

		}
		return *this;
	}

	T& operator*=(const T& source)
	{
		if (source.matrix && matrix && (source.a == a))
		{
			T* pointer = matrix;
			for (int i = 0; i < a * a; i++)
			{
				*pointer++ *= source;
			}

		}
		return *this;
	}

	

	//деструктор
	~Matrix()
	{
		delete[] matrix;
	}
};
int main()
{
	Matrix <int> ex1(5);
	ex1.displayMatrix();
	Matrix <int> ex2(4);
	ex2.displayMatrix();
	Matrix <int> ex3(ex1 += ex2);

	return 0;
}