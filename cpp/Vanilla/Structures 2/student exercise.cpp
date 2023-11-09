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
    cout << "¬ведите количество студентов в группе: ";
    cin >> number_of_student;
    cin.get();
    cout << endl;
    Student* group = new Student[number_of_student];
    for (int i = 0; i < number_of_student; i++)
    {
        cout << "введите фамилию " << i+1  <<"студента "<< endl;
        cin.getline(group[i].surname, 20);
        cout << "¬ведите номер группы: " << endl;
        cin >> group[i].grup_number;
        cout << "введите успеваемость студента: " << endl;
        for (int j = 0; j < 5; j++)
            cin >> group[i].points_by_student[j];
        cin.get();
        cout << endl;
    }
    double good_mark;
    int count = 0;
    cout << "студенты, у которых средний балл больше 4.7:" << endl;
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += group[i].points_by_student[j];

        good_mark = sum / 5;
        if (good_mark >= 4.7)
        {
            cout << "номер группы: " << group[i].grup_number << endl;
            cout << "фамили€: " << group[i].surname << endl;
        }
        else
        {
            count++;
            if (count == 5)
                cout << "таки нет!" << endl;
        }

    }
   
    return 0;
}
