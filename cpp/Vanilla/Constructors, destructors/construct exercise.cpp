#include <iostream>
#include <cstring>
using namespace std;
// функции для сокращения кода
void just_cpy(char*& string, const char* string2)
{
	if (string)
		strcpy_s(string, strlen(string2) + 1, string2);
}

void cpy_and_distribute(char*& string, const char* string2)
{
	if (string2)
	{
		string = new char[strlen(string2) + 1];
		strcpy_s(string, strlen(string2) + 1, string2);
	}
	else
	{
		string = nullptr;
	}
}

void check_for_nullptr_and_output(const char* temp)
{
	if (temp)
	{
		cout << temp << endl;
	}
	else
	{
		cout << "nullptr\n";
	}
}

class Book
{
	char* FIO;
	char* hphone;
	char* wphone;
	char* info;
public:
	
	//конструкторы
	Book():FIO(nullptr), hphone(nullptr), wphone(nullptr), info(nullptr) {}
	Book(const char* FIO, const char* hphone, const char* wphone, const char* info)
		:
		FIO{(FIO) ? new char[strlen(FIO)+1] : nullptr},
		hphone{ (hphone) ? new char[strlen(hphone) + 1] : nullptr },
		wphone{ (wphone) ? new char[strlen(wphone) + 1] : nullptr },
		info{ (info) ? new char[strlen(info) + 1] : nullptr }
	{
		just_cpy(this->FIO, FIO);
		just_cpy(this->hphone, hphone);
		just_cpy(this->wphone, wphone);
		just_cpy(this->info, info);
	}
	// конструктор копирования
	Book(const Book& temp)
	{
		cpy_and_distribute(FIO, temp.FIO);
		cpy_and_distribute(hphone, temp.hphone);
		cpy_and_distribute(wphone, temp.wphone);
		cpy_and_distribute(info, temp.info);
	}

	//сеттеры и геттеры
	const char* getFIO() const	{return FIO;}
	const char* getHphone() const { return hphone; }
	const char* getWphone() const { return wphone; }
	const char* getInfo() const { return info; }

	void setFIO(const char* temp)
	{
		delete[] FIO;
		cpy_and_distribute(FIO, temp);
	}
	void setHphone(const char* temp)
	{
		delete[] hphone;
		cpy_and_distribute(hphone, temp);
	}
	void setWphone(const char* temp)
	{
		delete[] wphone;
		cpy_and_distribute(wphone, temp);
	}

	void setInfo(const char* temp)
	{
		delete[] info;
		cpy_and_distribute(info, temp);
	}
	//отдельная функция вывода
	void display()
	{
		check_for_nullptr_and_output(getFIO());
		check_for_nullptr_and_output(getHphone());
		check_for_nullptr_and_output(getWphone());
		check_for_nullptr_and_output(getInfo());
	}

	//деструктор
	~Book()
	{
		delete[] FIO;
		delete[] hphone;
		delete[] wphone;
		delete[] info;
	}
};
#define help [i]
int main()
{
	const int n = 3;
	Book a[n] = {
		{"andrey", "+380667895233", "+380669724988", "doctor" },
		{"dimitriy", "+9658945214", "+946875215", "pizza courier"},
		{NULL, NULL, NULL, NULL}};
	char buf[BUFSIZ];
	cin.getline(buf, BUFSIZ);	
	//поиск по автору
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].getFIO(), buf) == 0)
		{
			cout << "this is what you are looking for: \n";
			a[i].display();
			cout << endl;
		}
	}
	
	return 0;
}