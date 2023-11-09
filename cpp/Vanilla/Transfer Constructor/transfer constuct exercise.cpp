#include <iostream>
#include <clocale>
#include <cstring>
using namespace std;
char* memory(const char* string)
{
return (string) ? new char[strlen(string) + 1] : nullptr;
}
void string_cpy(const char* param, char* dest)
{
if (param)
strcpy(dest, param);    //в онлайн компиляторе не работает strcpy_s
}
class Student
{

private:
char* name;
char* date;
char* phone;
char* education_place;
char* city;
char* country;
int group_number;

public:
//конструкторы
Student()
:
name{nullptr}, date{nullptr}, phone{nullptr}, education_place{nullptr},
city{nullptr}, country{nullptr}, group_number{0}
{}
Student(const char *name, const char* date, const char* phone, const char* education_place, const char* city, const char* country, int group_number)
:
name{memory(name)}, //return (string) ? new char[strlen(string) + 1] : nullptr;
date{ memory(date)},
phone{ memory(phone)},
education_place{ memory(education_place)},
city{ memory(city)},
country{memory(country)},
group_number(group_number)
{
string_cpy(name, this->name); //strcpy_s(dest, strlen(param + 1), param);
string_cpy(date, this->date);
string_cpy(phone, this->phone);
string_cpy(education_place, this->education_place);
string_cpy(city, this->city);
string_cpy(country, this->country);
}
Student(const Student& source)
:
name{memory(source.name)},
date{ memory(source.date) },
phone{ memory(source.phone) },
education_place{ memory(source.education_place) },
city{ memory(source.city) },
country{ memory(source.country) },
group_number(source.group_number)
{
string_cpy(source.name, this->name);
string_cpy(source.date, this->date);
string_cpy(source.phone, this->phone);
string_cpy(source.education_place, this->education_place);
string_cpy(source.city, this->city);
string_cpy(source.country, this->country);
}

Student& operator=(Student&& source) 
{
  
      delete[] name;
      delete[] date;
      delete[] phone;
      delete[] education_place;
      delete[] city;
      delete[] country;

      name = source.name;
    date = source.date;
    phone = source.phone;
    education_place = source.education_place;
    city = source.city;
    country = source.country;
    group_number = source.group_number;

      source.name = nullptr;
    source.date = nullptr;
    source.phone = nullptr;
    source.education_place = nullptr;
    source.city = nullptr;
    source.country = nullptr;
    source.group_number = 0;
   
   return *this;
}

Student(Student && source)
:
name{nullptr},
date{nullptr},
phone{nullptr},
education_place{nullptr},
city{nullptr},
country{nullptr},
group_number{0}
{
    name = source.name;
    date = source.date;
    phone = source.phone;
    education_place = source.education_place;
    city = source.city;
    country = source.country;
    group_number = source.group_number;
    
    
    source.name = nullptr;
    source.date = nullptr;
    source.phone = nullptr;
    source.education_place = nullptr;
    source.city = nullptr;
    source.country = nullptr;
    source.group_number = 0;
}

~Student()
{
delete[] name;
delete[] date;
delete[] phone;
delete[] education_place;
delete[] city;
delete[] country;
}
};

int main()
{
setlocale(0, "");
Student student;

return 0;
}