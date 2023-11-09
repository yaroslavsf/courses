#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int x, y;
	int q;
	cout >> "¬ведите x и y\n";
	cin >> x >> y; // заданые стороны
	cout << "¬ведите символ\n";
	char c;
	cin >> c;
	cout << endl;
	cout << "¬ведите 1-а,2-б,3-в,4-г,5-д,6-е,7-ж,8-з,9-и,10-к\n";
	cin >> q;
	switch (q)
	{
	case 1://a
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (i <= j)
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;


	case 2://б
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (i >= j)
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}													// a) i <= j
		break;												// б) i >= j
															// г) 
	case 3: //в												// в)
		for (int i = 0; i < x; i++)							// д)
		{													// и) i + j < y	
			for (int j = 0; j < y; j++)						// к) i + j >= y-1
			{												// з) (i + j >= (x + y) / 2 - 1) && i <= j
															// ж)	(i + j <= (x + y) / 2 - 1) && i >= j
				if (i <= j && (i + j < y))					// е) ((i + j >= (x + y) / 2 - 1) && i <= j) || ((i+j <= (x+y)/2 - 1) && i >= j)
				{	
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;

	case 4://г
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (i >= j && i + j >= y - 1)
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;


	case 5: //д
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if ((i <= j && (i + j < y)) || (i >= j && i + j >= y - 1))
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;

	case 6: // е
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (((i + j >= (x + y) / 2 - 1) && i <= j) || ((i+j <= (x+y)/2 - 1) && i >= j)) 
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;
	case 7://ж
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if ((i + j <= (x + y) / 2 - 1) && i >= j)
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;
	case 8: //з
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if ((i + j >= (x + y) / 2 - 1) && i <= j)
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;
		
	case 9://и
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (i + j < y)
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;
	case 10://к
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (i + j >= y-1)
				{
					cout << c;
				}
				else
				{
					cout << " ";
				}

			}

			cout << endl;
		}
		break;
	}
	return 0;
}