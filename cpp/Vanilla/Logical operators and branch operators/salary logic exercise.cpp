#include <iostream>
using namespace std;
int main() {
int day, day1, month, month1, year, year1, diffye, diffmon, diffmon1; 
    cout << "Enter the first date: ";
    cin >> day >> month >> year;
    cout << "Enter the second date: ";
    cin >> day1 >> month1 >> year1;
    if (day <= 31 && day1 <= 31 && month <= 12 && month1 <= 12) {
        diffye = (year1 - year) * 365;
        if (month > 8) diffmon = ((month - 1) * 30) + ((month - 1) / 2) + ((month - 1) % 2) - 1 + day;
        else if (month  > 2) diffmon  = ((month  - 1) * 30) + ((month  - 1) / 2) + ((month  - 1) % 2) - 2 + day ;
        else diffmon = ((month - 1) * 30) + ((month - 1) / 2) + ((month - 1) % 2) + day;
        if (month1 > 8) diffmon1= ((month1 - 1) * 30) + ((month1 - 1) / 2) + ((month1 - 1) % 2) - 1 + day1;
        else if (month1 > 2) diffmon1 = ((month1 - 1) * 30) + ((month1 - 1) / 2) + ((month1 - 1) % 2) - 2 + day1;
        else diffmon1 = ((month1 - 1) * 30) + ((month1 - 1) / 2) + ((month1 - 1) % 2) + day1;
        if (diffye > 0) {
            (diffye -=diffmon)+=diffmon1;
        }
        else {
            diffye = diffmon1 - diffmon;
        }
        if (((year1 - year) / 2) > 1 && month1 >  2) diffye += ((year1 - year) / 4) + 1; 
        cout << "amount of days between dates" << diffye;
    }
}