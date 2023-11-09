#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int sum1 = 0, sum2 = 0;
	srand(time(NULL));
	int a[3];
	int d[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = rand() % (1 - 7) + 1;
		sum1 += a[i];
		d[i] = rand() % (1 - 7) + 1;
		sum2 += d[i];
		cout << "Вы бросили: \n";
		switch (a[i])
		{
		case 1:

			cout <<

				" _______ \n"
				"|       |\n"
				"|       |\n"
				"|   *   |\n"
				"|       |\n"
				"|_______|\n";

			break;

		case 2:

			cout <<

				" _______ \n"
				"|       |\n"
				"|    *  |\n"
				"|       |\n"
				"|  *    |\n"
				"|_______|\n";

			break;

		case 3:

			cout <<

				" _______ \n"
				"|       |\n"
				"|   *   |\n"
				"|       |\n"
				"|  *  * |\n"
				"|_______|\n";

			break;

		case 4:

			cout <<

				" _______ \n"
				"|       |\n"
				"|  *  * |\n"
				"|       |\n"
				"|  *  * |\n"
				"|_______|\n";

			break;

		case 5:

			cout <<

				" _______ \n"
				"|       |\n"
				"| *   * |\n"
				"|   *   |\n"
				"| *   * |\n"
				"|_______|\n";

			break;

		case 6:
			cout <<

				" _______ \n"
				"|       |\n"
				"| *   * |\n"
				"| *   * |\n"
				"| *   * |\n"
				"|_______|\n";

			break;

		}
		cout << "Компьютер бросил: \n";
		switch (d[i])
		{
		case 1:

			cout <<

				" _______ \n"
				"|       |\n"
				"|       |\n"
				"|   *   |\n"
				"|       |\n"
				"|_______|\n";

			break;

		case 2:

			cout <<

				" _______ \n"
				"|       |\n"
				"|    *  |\n"
				"|       |\n"
				"|  *    |\n"
				"|_______|\n";

			break;

		case 3:

			cout <<

				" _______ \n"
				"|       |\n"
				"|   *   |\n"
				"|       |\n"
				"|  *  * |\n"
				"|_______|\n";

			break;

		case 4:

			cout <<

				" _______ \n"
				"|       |\n"
				"|  *  * |\n"
				"|       |\n"
				"|  *  * |\n"
				"|_______|\n";

			break;

		case 5:

			cout <<

				" _______ \n"
				"|       |\n"
				"| *   * |\n"
				"|   *   |\n"
				"| *   * |\n"
				"|_______|\n";

			break;

		case 6:

			cout <<

				" _______ \n"
				"|       |\n"
				"| *   * |\n"
				"| *   * |\n"
				"| *   * |\n"
				"|_______|\n";

			break;

		}

	}

	cout << endl;

	cout << "У вас: " << sum1 << endl;
	cout << "У компьютера: " << sum2 << endl;
	if (sum1 == sum2)
	{
		cout << "Ничья";
	}
	else
	{
		if (sum1 > sum2)
		{
			cout << "Вы выиграли";
		}
		else
		{
			cout << "Выиграл компьютер";
		}
	}

	return 0;
}