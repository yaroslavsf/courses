#include <iostream>
#include <ctime>
#include <locale>
#include <cstdlib>
using namespace std;
int pow(int a, int b)
{
    if (b == 0)
    {
        a = 1;
        return a;
    }
    for (int z = 1; z < b; z++)
    {
        a *= a;
    }
    return a;
}

int main()
{
    setlocale(0, "");
    int i, j;
    cout << "������� �����\n";
    cin >> i;
    cout << "������� �������\n";
    cin >> j;
    cout << pow(i, j);


    return 0;


}