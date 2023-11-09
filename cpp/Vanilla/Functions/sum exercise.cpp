#include <iostream>
#include <ctime>
#include <locale>
#include <cstdlib>
using namespace std;
int sum(int value1, int value2)
{
    int r = value1;
    int sum_sum = 0;
    for (; value1 < value2; value1++)
    {

        sum_sum += value1;

    }
    return sum_sum - r;
}

int main()
{
    setlocale(0, "");
    int i, j;
    cout << "¬ведите 1 число\n";
    cin >> i;
    cout << "¬ведите 2 число\n";
    cin >> j;
    cout << sum(i, j);


    return 0;


}