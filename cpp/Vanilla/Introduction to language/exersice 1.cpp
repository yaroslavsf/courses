#include <iostream>
#include <locale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "\t\t\t������ ������.\n"
			"\t\t\t������: ���������.\n"
			"\t\t\t...\n"
			"\t\t\t���. : 222 - 22 - 22\n"
			"\t\t\t222 | 222 |\n"
			"\t\t\t22  | 22 |\n"
			"\t\t\t22  | 22 |\n"
			"\t\t\t� �.�.\n";
	
	return 0;
}