#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int x, y;
	int q;
	cout >> "������� x � y\n";
	cin >> x >> y; // ������� �������
	cout << "������� ������\n";
	char c;
	cin >> c;
	cout << endl;
	cout << "������� 1-�,2-�,3-�,4-�,5-�,6-�,7-�,8-�,9-�,10-�\n";
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


	case 2://�
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
		break;												// �) i >= j
															// �) 
	case 3: //�												// �)
		for (int i = 0; i < x; i++)							// �)
		{													// �) i + j < y	
			for (int j = 0; j < y; j++)						// �) i + j >= y-1
			{												// �) (i + j >= (x + y) / 2 - 1) && i <= j
															// �)	(i + j <= (x + y) / 2 - 1) && i >= j
				if (i <= j && (i + j < y))					// �) ((i + j >= (x + y) / 2 - 1) && i <= j) || ((i+j <= (x+y)/2 - 1) && i >= j)
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

	case 4://�
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


	case 5: //�
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

	case 6: // �
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
	case 7://�
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
	case 8: //�
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
		
	case 9://�
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
	case 10://�
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