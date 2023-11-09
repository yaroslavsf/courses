#include <iostream>
#include <locale>
using namespace std;
int suit(int a)
{
	const char bubna_suit = 4; const char pika_suit = 6; const char cherva_suit = 3; const char kresta_suit = 5;
	switch (a)
	{
	case 1:
		return pika_suit;
	case 2:
		return bubna_suit;
	case 3:
		return cherva_suit;
	case 4:
		return kresta_suit;
	}
}
int return_number(int a)
{
	const char jack = 74; const char queen = 81; const char king = 75; const char ace = 65;
	switch (a)
	{
	case 1:
		return 6;
	case 2:
		return 7;
	case 3:
		return 8;
	case 4:
		return 9;
	case 5:
		return 10;
	case 6:
		return (char)jack;
	case 7:
		return (char)queen;
	case 8:
		return (char)king;
	case 9:
		return (char)ace;
	}
}
void print_between1(int a)
{
	if (return_number(a) == 10)
	{
		cout << " |\n";
	}
	else
	{
		cout << "  |\n";
	}
}
void print_between2(int a)
{
	if (return_number(a) == 10)
	{
		cout << "|_";
	}
	else
	{
		cout << "|__";
	}
}
void gap()
{
	cout << "|   |\n";
}
void compare_return_numbers_and_print(int j)
{
	if (return_number(j) > 10)
	{
		cout << (char)return_number(j);
	}
	else
	{
		cout << return_number(j);
	}
	
}
void return_cards(int i, int j)
{
	cout << "_____\n";
	cout << "|";
	compare_return_numbers_and_print(j);
	print_between1(j);
	gap();
	cout << "| " << (char)suit(i) << " |\n";
	gap();
	print_between2(j);
	compare_return_numbers_and_print(j);
	cout << "|\n";
}
int main()
{
	setlocale(0, "");
	int i, d;
	cout << "¬ведите масть:\n"
		<< "1 - пика\n"
		<< "2 - бубна\n"
		<< "3 - черва\n"
		<< "4 - креста\n";
	cin >> i;
	cout << "¬ведите номер карты\n"
		<< "1 - 6\n"
		<< "2 - 7\n"
		<< "3 - 8\n"
		<< "4 - 9\n"
		<< "5 - 10\n"
		<< "6 - валет\n"
		<< "7 - дама\n"
		<< "8 - король\n"
		<< "9 - туз\n";
	cin >> d;
	return_cards(i, d);
}