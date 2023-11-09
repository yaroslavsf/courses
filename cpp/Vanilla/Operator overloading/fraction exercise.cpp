#include <iostream>
using namespace std;
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
int NOK(int x, int y) 
{
	int count = (x < y) ? x : y; 													
	for (int i = 2; i <= count; i++) 
		if (!(x % i) && !(y % i)) return i; 
	return 1; 
}
class Drob
{

private:
	int x;
	int y;

public:
	Drob() : x(1), y(1) {}
	Drob(int a, int b) : x(a), y(b) {}
	int getX() const { return x; }
	int getY() const { return y; }

	Drob operator+(const Drob& temp2)
	{
		int same;
		same = (this->y * temp2.y) / NOD(this->y, temp2.y);
		int new_cheslitel = this->x * (same / this->y) + temp2.x * (same / temp2.y);
		int new_znamenatel = same;
		int nod_for_drob = NOD(new_cheslitel, new_znamenatel);
		return Drob(new_cheslitel/ nod_for_drob, new_znamenatel/ nod_for_drob);
	}

	Drob operator-(const Drob& temp2)
	{
		int same;
		same = (this->y * temp2.y) / NOD(this->y, temp2.y);
		int new_cheslitel = this->x * (same / this->y) - temp2.x * (same / temp2.y);
		int new_znamenatel = same;
		int nod_for_drob = NOD(new_cheslitel, new_znamenatel);
		return Drob(new_cheslitel / nod_for_drob, new_znamenatel / nod_for_drob);
	}
	
	Drob operator*(const Drob& temp2)
	{
		int new_cheslitel = this->x * temp2.x;
		int new_znamenatel = this->y * temp2.y;
		int nod_for_drob = NOD(new_cheslitel, new_znamenatel);
		return Drob(new_cheslitel / nod_for_drob, new_znamenatel / nod_for_drob);
	}

	Drob operator/(const Drob& temp2)
	{
		int new_cheslitel = this->x * temp2.y;
		int new_znamenatel = this->y * temp2.x;
		int nod_for_drob = NOD(new_cheslitel, new_znamenatel);
		return Drob(new_cheslitel / nod_for_drob, new_znamenatel / nod_for_drob);
	}

};
int main ()
{
	Drob ex1(24, 12), ex2(5, 28);
	Drob ex3(ex1 - ex2), ex4(ex1 + ex2), ex5(ex1 * ex2), ex6(ex1 / ex2);

	cout << ex1.getX() << "/" << ex1.getY() << "  -  " << ex2.getX() << "/" << ex2.getY() << "  =  " << ex3.getX() << '/' << ex3.getY() << endl;
	cout << ex1.getX() << "/" << ex1.getY() << "  +  " << ex2.getX() << "/" << ex2.getY() << "  =  " << ex4.getX() << '/' << ex4.getY() << endl;
	cout << ex1.getX() << "/" << ex1.getY() << "  *  " << ex2.getX() << "/" << ex2.getY() << "  =  " << ex5.getX() << '/' << ex5.getY() << endl;
	cout << ex1.getX() << "/" << ex1.getY() << "  /  " << ex2.getX() << "/" << ex2.getY() << "  =  " << ex6.getX() << '/' << ex6.getY() << endl;
	return 0;
}
