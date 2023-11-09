/*
1. Определения приблизительного объема (ширина*д-
лина*максимальная глубина);
2. Определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному
типу (море-море; бассейн-пруд);
4. Для сравнения площади водной поверхности водоемов
одного типа;
5. Для копирования объектов;
6. Остальные методы на усмотрение разработчика (ме-
тоды set и get).
*/

#include <iostream>
using namespace std;
class Reservoir
{
	char* name;
	double depth;
	double width;
	double length;
	//конструкторы
public:
	explicit Reservoir(const char* name, double depth, double width, double length)
		:
		name{ (name) ? new char[strlen(name) + 1] : nullptr },
		depth(depth),
		width(width),
		length(length)
	{
		if (name)
			strcpy_s(this->name, strlen(name) + 1, name);
	}
	explicit Reservoir() : name{ nullptr }, depth(0), width(0), length(0) {}
	explicit Reservoir(const Reservoir& temp)
	{
		if (temp.name)
		{
			name = new char[strlen(temp.name) + 1];
			strcpy_s(name, strlen(temp.name) + 1, temp.name);
		}
		else
		{
			name = nullptr;
		}
		this->depth = temp.depth;
		this->width = temp.width;
		this->length = temp.length;
	}
	//геттеры и сеттеры
	const char* getName() const { return name; }
	double getDepth() const { return depth; }
	double getWidth() const { return width; }
	double getLength() const { return length; }
	void setName(const char* name)
	{
		if (name)
		{
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
	}
	void setDepth(double x) { depth = x; }
	void setWidth(double x) { width = x; }
	void setLength(double x) { length = x; }


	//методы 
	double getCapacity() const { return length * width * depth; }
	double getSquare() const { return length * width; }
	void CheckType()
	{
		if (length* width* depth < 10000)
			cout << "pool" << endl;
		else
			cout << "sea" << endl;
	}
	bool Compare(double x)
	{
		double a = getCapacity();
		if ((a < 1000 && x < 1000) || (a > 1000 && x > 1000))
			return a > x;
		else
		{
			cout << "error";
			return 0;
		}
	}

	void copy(const Reservoir& temp)
	{
		delete[] name;
		if (temp.name)
		{
			name = new char[strlen(temp.name) + 1];
			strcpy_s(name, strlen(temp.name) + 1, temp.name);
		}
		else
			name = nullptr;
		depth = temp.depth;
		width = temp.width;
		length = temp.length;
	}

	~Reservoir()
	{
		delete[] name;
	}
};

void newReservoir(Reservoir*& a, int& n)
{
	cout << "Enter the number of new Reservoirs\n";
	int n2;
	cin >> n2;
	Reservoir* b = new Reservoir[n + n2];
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	delete[] a;
	a = b;
	n = n + n2;


}
void deleteReservoir(Reservoir*& a, int& n)
{
	cout << "Enter number of Reservoir which you want to delete(1->n)\n";
	int n3;
	cin >> n3;
	n3--;
	Reservoir* b = new Reservoir[n - 1];
	Reservoir* c = b;
	for (int i = 0; i < n3; i++)
	{
		*b++ = a[i];
	}
	for (int i = n3 + 1; i < n; i++)
	{
		*b++ = a[i];
	}
	delete[] a;
	a = c;
	n--;
}


int main()
{
	int n;
	cin >> n;
	Reservoir* a = new Reservoir[n];
	delete[] a;
	return 0;
}








