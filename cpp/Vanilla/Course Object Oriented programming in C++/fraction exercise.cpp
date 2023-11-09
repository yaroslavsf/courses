#include <iostream>
using namespace std;
class Drob
{
	int cheslitel;
	int znamenatel;

public:
	//конструкторы
	Drob():cheslitel(1), znamenatel(1)	{}
	Drob(int x, int y): cheslitel(x), znamenatel(y) {}
	//функция для сокращения 
	int NOD(long a, long b) {

		if (a == b) {
			return a;
		}
		if (a > b) {
			long tmp = a;
			a = b;
			b = tmp;
		}
		return NOD(a, b - a);
	}
	//геттеры
	int getCheslitel() const
	{
		return cheslitel;
	}
	int getZnamenatel() const
	{
		return znamenatel;
	}
	int getDrob() const
	{
		return cheslitel / znamenatel;
	}
	//сеттеры
	void setDrob(int x, int y)
	{
		cheslitel = x;
		znamenatel = y;
	}
	//методы 
	void contraction()
	{
		cheslitel /= NOD(cheslitel, znamenatel);
		znamenatel /= NOD(cheslitel, znamenatel);
	}
	void sup(const Drob& temp)
	{
		int same;
		same = (this->znamenatel * temp.znamenatel) / NOD(this->znamenatel, temp.znamenatel);
		int new_cheslitel = this->cheslitel * (same / this->znamenatel) + temp.cheslitel * (same / temp.znamenatel);
		int new_znamenatel = same;
		cheslitel = new_cheslitel;
		znamenatel = new_znamenatel;
	}
	void substr(const Drob& temp)
	{
		int same;
		same = (this->znamenatel * temp.znamenatel) / NOD(this->znamenatel, temp.znamenatel);
		int new_cheslitel = this->cheslitel * (same / this->znamenatel) - temp.cheslitel * (same / temp.znamenatel);
		int new_znamenatel = same;
		cheslitel = new_cheslitel;
		znamenatel = new_znamenatel;
	}
	void mult(const Drob& temp)
	{
		int new_cheslitel = this->cheslitel * temp.cheslitel;
		int new_znamenatel = this->znamenatel * temp.znamenatel;
		cheslitel = new_cheslitel;
		znamenatel = new_znamenatel;
	}

	void div(const Drob& temp)
	{
		int new_cheslitel = this->cheslitel * temp.znamenatel;
		int new_znamenatel = this->znamenatel * temp.cheslitel;
		cheslitel = new_cheslitel;
		znamenatel = new_znamenatel;

	}
};

int main()
{
	return 0;
}