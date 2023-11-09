#include <iostream>
#include <clocale>
#include <cstring>
#include <stdio.h>
struct Book
{
    char* pname;
    char* pauthor;
    char* ppublishing;
    char* pgenre;
};
using namespace std;
void sort_name(struct Book* &f)
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            
            if (strcmp(f[i].pname, f[i + 1].pname) < 0)
            {
                swap(f[i].pname, f[i+1].pname);
                swap(f[i].pauthor, f[i + 1].pauthor);
                swap(f[i].ppublishing, f[i + 1].ppublishing);
                swap(f[i].pgenre, f[i + 1].pgenre);
                
            }
        }
    }
}
void print(struct Book* &mas)
{
    cout << endl << "____________________________________________________";
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        cout << "�������� " << i + 1 << " �����: " << mas[i].pname << endl;
        cout << "����� " << i + 1 << " �����: " << mas[i].pauthor << endl;
        cout << "������������ " << i + 1 << " �����: " << mas[i].ppublishing << endl;
        cout << "���� " << i + 1 << " �����: " << mas[i].pgenre << endl;
    }

}
int main()
{
    setlocale(0, "");
    Book* mas = new Book[10];
    char* pbuf = new char[100];
    for (int i = 0; i < 10; i++)
    {

        cout << "������� ��� " << i + 1 << " �����\n";
        cin.getline(pbuf, 100);
        mas[i].pname = new char[strlen(pbuf) + 1];
        strcpy_s(mas[i].pname, strlen(pbuf) + 1, pbuf);



        cout << "������� ������ " << i + 1 << " �����\n";
        cin.getline(pbuf, 100);
        mas[i].pauthor = new char[strlen(pbuf) + 1];
        strcpy_s(mas[i].pauthor, strlen(pbuf) + 1, pbuf);



        cout << "������� ������������ " << i + 1 << " �����\n";
        cin.getline(pbuf, 100);
        mas[i].ppublishing = new char[strlen(pbuf) + 1];
        strcpy_s(mas[i].ppublishing, strlen(pbuf) + 1, pbuf);



        cout << "������� ���� " << i + 1 << " �����\n";
        cin.getline(pbuf, 100);
        mas[i].pgenre = new char[strlen(pbuf) + 1];
        strcpy_s(mas[i].pgenre, strlen(pbuf) + 1, pbuf);

    }
    delete[] pbuf;

    print(mas);
    sort_name(mas);
    print(mas);
    return 0;

}
