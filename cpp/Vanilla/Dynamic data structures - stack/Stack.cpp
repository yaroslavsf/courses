#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
	enum { empty = 0 };
	char* mas;
	size_t top, size;
public:
	//конструкторы
	Stack(const char* mas, size_t size)
		:
		mas{ mas ? new char[size] : nullptr },
		top{ mas ? size : empty },
		size{ size }
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
		mas{ new char[20] },
		top{ 20 },
		size{ 20 }
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
	void Push(char param)
	{
		if (mas)
		{
			if (top >= size)
			{
				char* pointer = new char[size + 20];

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
	char Pop()
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


	bool check1(const char* pp,  char bracket)
	{
		while (*pp++)
		{
			if (*pp == bracket)
				return 1;
		}
		return 0;
	}
	bool check2(const char* pp, char bracket,  char bracket2)
	{
		if (*pp == bracket)
		{
			if (!check1(pp, bracket2))
				return 0;
		}
		return 1;
	}

	bool check()
	{
		char* p = mas;
		while (*p++)
		{
			if (!(check2(p, '(', ')') && check2(p, '{', '}') && check2(p, '[', ']')))
			{
				cout << "error";
				return 1;
			}
		}
		return 0;
	}


	~Stack()
	{
		delete[] mas;
	}
};






int main()
{
	Stack arr;
	arr.Push('{');
	arr.Push('(');
	arr.Push(')');
	arr.Push('}');
	arr.Push('[');
	arr.Push('{');
	arr.check();
	return 0;
}