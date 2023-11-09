#include <iostream>
#include <cstring>
using namespace std;
template <class T>
class Stack
{
	enum { empty = 0};
	T* mas;
	size_t top, size;
public:
	//конструкторы
	Stack(T* mas, size_t size)
		: 
		mas{ mas ? new T[size] : nullptr },
		top{mas ? size : empty},
		size{size}
	{
		if (mas)
		for (int i = 0; i < size; i++)
		{
			this->mas[i] = mas[i];
		}
		top = empty;
	}
	Stack()
		:
		mas{ new T[20] },
		top{20},
		size{20}
	{}
	//ф-ии
	void Clear()
	{
		top = empty;
		delete[] mas;
	}
	bool IsFull()
	{
		return (top == size);
	}
	bool IsEmpty()
	{
		return (top == empty);
	}
	int GetCount()
	{
		return (top);
	}
	void Push(T param)
	{
		if (mas)
		{
			if (top >= size)
			{
				T* pointer = new T[size + 20];

				for (int i = 0; i < size; i++) //size???
				{
					pointer[i] = mas[i];
				}
				delete[] mas;
				mas = pointer;
				size += 20;
			}
			if (!IsFull())
			{
				mas[top++] = param;
			}
		}
	}
	T Pop()
	{
		if (IsEmpty())
			return 0;
		if (!IsFull())
		{
			return mas[top--];
		}
		else
		{
			return 0;
		}
	}

	~Stack()
	{
		delete[] mas;
	}
};

int main()
{
	Stack<char> arr;
	Stack<int> arr2;
	return 0;
}
