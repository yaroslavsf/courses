#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale>
using namespace std;
int* memory_distributor(int n)
{
	return new int[n];
}
void init_array(int* begin_of_array, int n)
{
	int* end_of_array = begin_of_array + n;
	while (begin_of_array < end_of_array)
	{
		*begin_of_array++ = rand() % 9;
	}
}
void print_array(int* begin_of_array, int n)
{
	int* end_of_array = begin_of_array + n;
	cout << "��� ������:\n";
	while (begin_of_array < end_of_array)
	{
		cout << *begin_of_array++ << ' ';
	}
	cout << endl;
}
void add_to_end(int** mas, int* n, int x)
{
	int* b = new int[*n + 1];
	for (int i = 0; i < *n; i++)
	{
		b[i] = mas[0][i];
	}
	b[*n] = x;
	delete[] mas[0];
	*mas = b;
	(*n)++;

}
void insert_in_array(int** mas, int* n, int insert_number, int insert_index)
{
	int* b = new int[*n + 1];
	for (int i = 0; i < *n; i++)
	{
		b[i] = mas[0][i];
	}
	while (1)
	{
		if (insert_index <= *n && insert_index >= 0)
		{
			for (int i = *n; i > insert_index; i--)
			{
				b[i] = b[i-1];
			}
			b[insert_index] = insert_number;
			delete[] * mas;
			*mas = b;
			(*n)++;
			break;
		}
		else
		{
			cout << "������ ������, ��� ���-�� ��������� � ������� ��� ������ ����\n";
		}
		cin >> insert_index;
	}
}
void delete_in_array(int*& mas, int& n, int delete_index)
{
	int* b = new int[n - 1];
	while (1)
	{
		int* q = b;
		if (delete_index <= n && delete_index >= 0)
		{
			for (int i = 0; i < delete_index; i++)
			{
				*q++ = mas[i];
			}
			for (int i = delete_index + 1; i < n; i++)
			{
				*q++ = mas[i];
			}
			delete[]  mas;
			mas = b;
			n--;
			break;
		}
		else
		{
			cout << "������ ������, ��� ���-�� ��������� � ������� ��� ������ ����\n������� ��� ���\n";
		}
		cin >> delete_index;
	}
}
void delete_array(int** mas)
{
	delete[] * mas;
}
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int n, x; // x - ����� ��� ���������� � ����� �������; n - ���-�� �������� �������
	int index1, x1; //index1 - ������ ��� �������; x1 - ����� ��� �������
	int index2; //index2 - ������ ��� ��������
	cout << "������� ���-�� ������� �������\n";
	cin >> n; // ���� ���-�� ��. �������
	int* a = memory_distributor(n); //������������� ������������ ������(fun)
	init_array(a, n); // ������������� �������(fun)
	print_array(a, n); // ����� �������(fun)
	cout << "������� ����� ��� ���������� � ����� �������\n";
	cin >> x; // ���� ����� ��� ����������
	add_to_end(&a, &n, x); //���������� �����(fun)
	print_array(a, n);
	cout << "������� �������, ������� �� ������ ��������\n";
	cin >> x1; //���� ����� ��� �������
	cout << "������� ������\n";
	cin >> index1; //���� ������� ��� �������
	insert_in_array(&a, &n, x1, index1); //������� �� �������(fun)
	print_array(a, n);
	cout << "������� ������, ������� ������ �������\n";
	cin >> index2;
	delete_in_array(a, n, index2);
	print_array(a, n);
	delete_array(&a);
	return 0;
}