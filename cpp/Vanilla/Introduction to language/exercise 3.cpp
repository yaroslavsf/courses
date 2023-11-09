#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color F0");
	cout << "\t\t\tMy love is as a fever longing still,\n"
			"\t\t\tFor that which longer nurseth the disease,\n"
			"\t\t\tFeeding on that which doth preserve the ill,\n"
			"\t\t\tTh\' uncertain sickly appetite to please:\n"
			"\t\t\tMy reason the physician to my love,\n"
			"\t\t\tAngry that his prescriptions are not kept\n"
			"\t\t\tHath left me, and I desperate now approve,\n"
			"\t\t\tDesire is death, which physic did except.\n"
			"\t\t\tPast cure I am, now reason is past care,\n"
			"\t\t\tAnd frantic - mad with evermore unrest,\n"
			"\t\t\tMy thoughtsand my discourse as mad men's are,\n"
			"\t\t\tAt random from the truth vainly expressed.\n"
			"\t\t\tFor I have sworn thee fair, and thought thee bright,\n"
			"\t\t\tWho art as black as hell, as dark as night.\n";
	
	return 0;
}