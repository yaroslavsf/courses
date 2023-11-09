#include <iostream>
using namespace std;
class Overcoat
{
	char* name;
	char* type;
	double price;


public:
	//конструкторы
	Overcoat(const char* name1, const char* type1, double price1)
		:
		name{ name1 ? new char[strlen(name1) + 1] : nullptr },
		type{ type1 ? new char[strlen(type1) + 1] : nullptr },
		price{ price1 }
	{
		strcpy_s(name, strlen(name1) + 1, name1);
		strcpy_s(type, strlen(type1) + 1, type1);
	}
	Overcoat() : name{ nullptr }, type{ nullptr }, price{ 0 } { }
	Overcoat(const Overcoat& temp)
		:
		price(temp.price), name{(temp.name) ? new char[strlen(temp.name) + 1] : nullptr }, type{(temp.type) ? new char[strlen(temp.type) + 1] : nullptr}
	{
		if (temp.name)
		strcpy_s(name, strlen(temp.name) + 1, temp.name);
		if (temp.type)	
		strcpy_s(type, strlen(temp.type) + 1, temp.type);
	}
	//геттеры и сеттеры
	const char* getName() const
	{
		return name;
	}
	const char* getType() const
	{
		return type;
	}
	const double getPrice() const
	{
		return price;
	}
	//операторы
	Overcoat& operator=(const Overcoat& temp)
	{
		delete[] name;
		name = new char[strlen(temp.name) + 1];
		strcpy_s(name, strlen(temp.name) + 1, temp.name);

		delete[] type;
		type = new char[strlen(temp.type) + 1];
		strcpy_s(type, strlen(temp.type) + 1, temp.type);

		price = temp.price;
		return *this;
	}


	
	int operator==(const Overcoat& temp)
	{
		int i = 0;
		while (type[i] != '\0' || temp.type[i] != '\0')
		{
			if (type[i] > temp.type[i])
				return 1;
			else
				if (type[i] < temp.type[i])
					return -1;
			i++;
		}
		return 0;
	}


	int operator> (const Overcoat& temp)
	{
		return this->price > temp.price;
	}
};
int main()
{
	setlocale(0, "");
	Overcoat ex1("name1", "type1", 1000), ex2("name2", "style2", 2000);
	Overcoat ex3(ex1);
	Overcoat ex4;
	ex4 = ex3;

	cout << "Проверка конструктора копирования: " << ex3.getName() << endl;
	cout << "Проверка перегрузки оператора = : " << ex4.getName() << endl;
	cout << "Проверка перегрузки оператора > : "<<(ex1 > ex2) << endl;
	cout << "Проверка перегрузки оператора == : " << (ex1 == ex4);
	

	return 0;
}