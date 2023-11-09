#include <iostream>
#include <fstream>
using namespace std;
class Base
{
protected:
	ifstream input;
	char a[1000];
	int count;
public:	
	Base(const char* path)
		:
		input(path)
	{ 
		if (path) {
			count = 0;
			while (!input.eof())
			{
				input >> a[count];
				count++;
			}
		}
	}

	virtual void Display(const char* path)
	{
		
		for (int i = 0; i < count; i++)
		{
			if (a[i] <= '9' && a[i] >= '1')
			{
			char temp = (int)a[i] - 48;
			cout << temp;
			}
			else
			cout << a[i];
		}
	}
};

class Binary : public Base
{
public:
	Binary(const char* path)
		:
		Base(path)
	{ }

	void Display(const char* path) override
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = 7; j >= 0; --j)
			{
				cout << ((a[i] & (1 << j)) ? '1' : '0');
			}
			cout << ' ';
		}
	}
};

int main()
{
	// в файле "qweasd123546"
	Base* mas[2];
	Base ex1("output.txt");
	Binary ex2("output.txt");
	mas[1] = &ex2;
	mas[0] = &ex1;
	for (int i = 0; i < 2; i++)
	{
		mas[i]->Display("output.txt");
		cout << endl;
	}
	return 0;
}