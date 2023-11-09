#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

void Show_array(int** a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int** Fill_array(int r, int c)
{
    int** array = new int* [r];
    for (int i = 0; i < r; i++)
    {
        array[i] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            array[i][j] = rand() % 20 - 10;
        }
    }
    return array;
}



int main()
{

    srand(time(NULL));

    int rows_A;
    cin >> rows_A;
    int cols_A;
    cin >> cols_A;

    int rows_B;
    cin >> rows_B;
    int cols_B;
    cin >> cols_B;

    int rows_C;
    cin >> rows_C;
    int cols_C;
    cin >> cols_C;

    int** array_A = new int* [rows_A];
    int** array_B = new int* [rows_B];
    int** array_C = new int* [rows_C];

    cout << "Введите количество строк для массива А: " << endl;;
    cin >> rows_A;
    cout << "Введите количество столбцов для массива А: " << endl;
    cin >> cols_A;

    array_A = Fill_array(rows_A, cols_A);
    cout << "Массив А: " << endl << endl;
    Show_array(array_A, rows_A, cols_A);

    cout << endl;
    cout << "Введите количество строк для массива B: " << endl;
    cin >> rows_B;
    cout << "Введите количество столбцов для массива B: " << endl;
    cin >> cols_B;

    array_B = Fill_array(rows_B, cols_B);
    cout << "Массив B: " << endl << endl;
    Show_array(array_B, rows_B, cols_B);

    cout << endl;
    cout << "Введите количество строк для массива C: " << endl;
    cin >> rows_C;
    cout << "Введите количество столбцов для массива C: " << endl;
    cin >> cols_C;

    array_C = Fill_array(rows_C, cols_C);
    cout << "Массив C: " << endl << endl;
    Show_array(array_C, rows_C, cols_C);

    cout << endl;



    for (int i = 0; i < rows_A; i++)
    {
        delete[]array_A[i];
    }
    delete[]array_A;

    for (int i = 0; i < rows_B; i++)
    {
        delete[]array_B[i];
    }
    delete[]array_B;

    for (int i = 0; i < rows_C; i++)
    {
        delete[]array_C[i];
    }
    delete[]array_C;


    cout << endl;
    return 0;
}
