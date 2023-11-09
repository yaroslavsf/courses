#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "every hunter wants to know:\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 4));
		cout << "\t\tred\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 4));
		cout << "\t\t\torange\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 14));
		cout << "\t\t\t\tyellow\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 2));
		cout << "\t\t\t\t\tgreen\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 11));
		cout << "\t\t\t\t\t\tnavy\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 1));
		cout << "\t\t\t\t\t\t\tblue\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 13));
		cout << "\t\t\t\t\t\t\t\tmagenta\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 0));
		return 0;
}