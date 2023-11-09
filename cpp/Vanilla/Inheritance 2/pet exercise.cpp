#include <iostream>
#include <cstring>
using namespace std;
class Pet
{
protected:
    char* name;
    int paws;
    int age;
    char* sound;
public:
    Pet(const char* name = nullptr, const int paws = 0, const int age = 0, const char* sound = nullptr)
        :
        name{ (name) ? new char[strlen(name) + 1] : nullptr },
        paws{ paws },
        age{ age },
        sound{ (sound) ? new char[strlen(sound) + 1] : nullptr }

    {
        if (name)
            strcpy_s(this->name, strlen(name) + 1, name);
        if (sound)
            strcpy_s(this->sound, strlen(sound) + 1, sound);

    }

    virtual void f_sound()
    {
        if (this->sound)
            cout << sound;
        else
            cout << "nullptr";
    }

    ~Pet()
    {
        delete[] name;
        delete[] sound;
    }
};
class Dog : public Pet
{
protected:
    char* profession;
public:
    Dog(const char* name = nullptr, const int paws = 0, const int age = 0, const char* sound = nullptr, const char* prof = nullptr)
        :
        Pet(name, paws, age, sound),
        profession{ (prof) ? new char[strlen(prof) + 1] : nullptr }
    {
        if (prof)
            strcpy_s(this->profession, strlen(prof) + 1, prof);
    }

    void f_sound() override
    {
        if (this->sound)
            cout << sound;
        else
            cout << "nullptr";
    }

};
class Cat : public Pet
{
protected:
    int amount_of_lives;
public:
    Cat(const char* name = nullptr, const int paws = 0, const int age = 0, const char* sound = nullptr, const int am_of_lives = 0)
        :
        Pet(name, paws, age, sound),
        amount_of_lives(am_of_lives)
    { }

    void f_sound() override
    {
        if (this->sound)
            cout << sound;
        else
            cout << "nullptr";
    }
};
class Parrot : public Pet
{
protected:
    int wings;
public:
    Parrot(const char* name = nullptr, const int paws = 0, const int age = 0, const char* sound = nullptr, const int wings = 0)
        :
        Pet(name, paws, age, sound),
        wings(wings)
    {}
    void f_sound() override
    {
        if (this->sound)
            cout << sound;
        else
            cout << "nullptr";
    }
};
int main()
{
    Dog d("dog_name", 4, 2, "dog_sound", "dog_prof");
    Cat c("cat_name", 4, 3, "cat_sound", 9);
    Parrot p("parrot_name", 2, 1, "parrot_sound", 2);
    Pet* arr[3];
    arr[0] = &d;
    arr[1] = &c;
    arr[2] = &p;
    for (int i = 0; i < 3; i++)
    {
        arr[i]->f_sound();
        cout << endl;
    }
    return 0;
}

