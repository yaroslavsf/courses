#include <iostream>
using namespace std;

struct Student
{
    int grup_number;
    int points_by_student[5];
    char surname[20];
};


int main()
{
    int number_of_student;
    cout << "������� ���������� ��������� � ������: ";
    cin >> number_of_student;
    cin.get();
    cout << endl;
    Student* group = new Student[number_of_student];
    for (int i = 0; i < number_of_student; i++)
    {
        cout << "������� ������� " << i+1  <<"�������� "<< endl;
        cin.getline(group[i].surname, 20);
        cout << "������� ����� ������: " << endl;
        cin >> group[i].grup_number;
        cout << "������� ������������ ��������: " << endl;
        for (int j = 0; j < 5; j++)
            cin >> group[i].points_by_student[j];
        cin.get();
        cout << endl;
    }
    double good_mark;
    int count = 0;
    cout << "��������, � ������� ������� ���� ������ 4.7:" << endl;
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += group[i].points_by_student[j];

        good_mark = sum / 5;
        if (good_mark >= 4.7)
        {
            cout << "����� ������: " << group[i].grup_number << endl;
            cout << "�������: " << group[i].surname << endl;
        }
        else
        {
            count++;
            if (count == 5)
                cout << "���� ���!" << endl;
        }

    }
   
    return 0;
}
