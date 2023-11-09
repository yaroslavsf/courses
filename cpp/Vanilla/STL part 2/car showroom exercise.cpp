/*
 Создайте приложение для работы автосалона.
 Необходимо хранить информацию о продаваемых автомобилях (название, год выпуска, объем двигателя, цену).
 Реализуйте интерфейс для добавления данных, удаления данных, отображения данных, сортировке данных по различным параметрам, поиску данных по различным параметрам.
 При реализации используйте контейнеры, функторы и алгоритмы.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Car
{
    string name;
    size_t year;
    double engine;//need to be double 
    double price;
    
public:
     Car(const string& name ,const size_t year ,const double engine ,const double price)
    :
    name{name},
    year{year},
    engine{engine},
    price{price}
    { }
    
    void setName(string & name)
    {
        this->name = name;
    }
    void setYear(size_t year)
    {
        this->year = year;
    }
    void setEngine(double engine)
    {
        this->engine = engine;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    const string& getName()
    {
        return name;
    }
    const size_t getYear()
    {
        return year;
    }
    const double getEngine()
    {
        return engine;
    }
    const double getPrice()
    {
        return price;
    }
    
    friend class dataBase;
    
    struct compareByYear
    {
        bool operator()(const Car& a, const Car& b)
        {
            return a.year < b.year;
        }
    };
    
    struct compareByName
    {
        bool operator()(const Car& a, const Car& b)
        {
            return a.name < b.name;
        }
    };
    
};




class dataBase
{
    vector<Car>item;

public:
    
    void addCar(const Car& car)
    {
        item.push_back(car);
    }
    
    void deleteCar(int number)
    {
        item.erase(item.begin() + number -1);
    }
    
    void showItem()
    {
        int number = 1;
        for (auto i = item.begin(); i != item.end(); ++i)
        {
            cout << number++<<" "<<i->name<<" " << i->year << " "
            << i->engine << " "<< i->price <<  endl;
        
        }
    }
    
    void sortByName()
    {
        cout<<" sorting by name: "<<endl;
        
        Car::compareByName name;
        sort(item.begin(),item.end(),name);
        showItem();
       
        cout<<endl;
        
    }
    
    void sortByYear()
    {
        cout<<" sorting by year: "<<endl;
        
        Car::compareByYear year;
        sort(item.begin(),item.end(),year);
        showItem();
       
        cout<<endl;
    }
    void searchByName(const string& search)
    {
        for (auto i = item.begin(); i != item.end(); ++i)
        {
            if (i->name == search)
            {
                cout <<" "<<i->name<<" " << i->year << " "
            << i->engine << " "<< i->price <<  endl;
            }
           
        }
    }
    
    void searchByYear(size_t y)
    {
        for (auto i = item.begin(); i != item.end(); ++i)
        {
            if (i->year == y)
            {
                cout <<" "<<i->name<<" " << i->year << " "
            << i->engine << " "<< i->price <<  endl;
            }
        
        }
    }
    
    
};

int main()
{
    Car car_1("Car1",1990,19,123.340);
    Car car_2("Car2",2010,18,423.340);
    Car car_3("Car3",2012,17,42.340);
    Car car_4("Car4",2018,18,421.340);
    Car car_5("Car5",2020,19,592.340);
    
    dataBase db;
    db.addCar(car_1);
    db.addCar(car_2);
    db.addCar(car_3);
    db.addCar(car_4);
    db.addCar(car_5);
    
    db.showItem();
    db.sortByName();
    db.sortByYear();
    
    cout<<"Name for serching ny name: "<<endl;
    string str ="Car1";

    db.searchByName(str);
    
    cout<<"Year for serching by year: "<<endl;
    size_t y =2018;

    db.searchByYear(y);
    
    
    
    db.deleteCar(3);
    db.showItem();
   
    return 0;
}