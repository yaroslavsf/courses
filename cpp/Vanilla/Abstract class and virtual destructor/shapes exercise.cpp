#include <iostream>
#include <fstream>

using namespace std;



class Shape
{
protected:
    int x, y;
    double a;
public:
    Shape(double a = 0, int x = 0, int y = 0) : a{ a }, x{ x }, y{ y } {}

    virtual ~Shape() = 0 {};
    virtual void show() = 0;
    virtual void save(const char*) = 0;
    virtual bool load(ifstream& file) = 0;

};

class Square : public Shape
{
   
public:
    Square(double a = 0, int xc = 0, int yc = 0)
        :
        Shape(a,xc,yc)
    { };

    void show() override
    {
        cout << "Shape is Square " << "with " << a << "cm edge"  << endl;
    }

    void save(const char* filename) override
    {
        ofstream fout;
        fout.open(filename, std::ofstream::out | std::ofstream::app);
        fout << 1 << ' ' << x << ' ' << y << ' ' <<a << '\n';
        fout.close();
    }

    bool load(ifstream& file) override
    {
        file >> x  >> y  >> a;
        return file.good();
    }
};
class Rectangle : public Shape
{
    double b;
public:
    Rectangle(double a = 0, double b = 0,int xc= 0, int yc= 0)
        :
        Shape(a,xc,yc),
        b{b}
    {  };

    void show() override
    {
        cout << "Shape is Rectangle " << "with " << a << "cm one side"<<"\t"<<b<<"cm another side" << endl;
    }

    void save(const char* filename) override
    {

        ofstream fout;
        fout.open(filename, std::ofstream::out | std::ofstream::app);

        fout << 2 << ' ' << x << ' ' << y << ' ' << a << ' ' << b << '\n';
        fout.close();
    }

    bool load(ifstream& file) override
    {
        file >> x >> y >> a >> b;
        return file.good();

    }
};
class Circle : public Shape
{
    const double pi;
public:
    Circle(double a = 0, int xc = 0, int yc = 0)
        :
        Shape(a,xc,yc),
        pi{3.14}
    {   };

    void show() override
    {
        cout << "Shape is Circle " << "with " << a << "radius" << endl;
    }

    void save(const char* filename) override
    {

        ofstream fout;
        fout.open(filename, std::ofstream::out | std::ofstream::app);

        fout << 3 << ' ' << x << ' ' << y << ' ' << a << '\n';
        fout.close();
    }

    bool load(ifstream& file) override
    {
        file >> x >> y >> a;
        return file.good();

    }
};

class Ellipse : public Shape
{

    const double pi;
    double b;
public:
    Ellipse(double a = 0, double b = 0, int xc = 0, int yc = 0)
        :
        pi{3.14},
        Shape(a,xc,yc),
        b{b}
    {   }

    void show() override
    {
        cout << "Shape is Ellipse " << "with " << a << "ont radius" << "\t" << b << " another radius"<< endl;
    }

    void save(const char* filename) override
    {

        ofstream fout;
        fout.open(filename, std::ofstream::out | std::ofstream::app);

        fout << 4 << ' ' << x << ' ' << y << ' ' << a << ' ' << b <<'\n';
        fout.close();
    }

    bool load(ifstream& file) override
    {
        file >> x >> y >> a >> b;
        return file.good();

    }
};
void shape_load(Shape* mas[], int n, const char* filename)
{
    ifstream file;
    int id = -1;
    file.open(filename, ifstream::in);
    for (int index = 0; index < n; index++)
    {
        file >> id;
        if (id == -1)
            break;
        switch (id)
        {
        case 1:
            mas[index] = new Square();
            break;
        case 2:
            mas[index] = new Rectangle();
            break;
        case 3:
            mas[index] = new Circle();
            break;
        case 4:
            mas[index] = new Ellipse();
            break;
        default:
            return;
        }
        if (!mas[index]->load(file))
        {
            delete mas[index];
            mas[index] = nullptr;
            break;
        }
    }
}

int main()
{
    Shape* mas[] = { new Square(5,6,9), new Rectangle(1,2,3,4), new Circle(1,2,3), new Ellipse(1,2,3,4) };
    for (int i = 0; i < (sizeof(mas) / sizeof(*mas)); i++)
    {
        mas[i]->save("file.txt");
    }

    for (int i = 0; i < (sizeof(mas) / sizeof(*mas)); i++)
    {
        delete mas[i];
    }


    const int n = 4;
    Shape* mas2[n];
    shape_load(mas2, n, "file.txt");

    for (int i = 0; i < 4; i++)
        if (mas2[i] != nullptr)
            mas2[i]->show();

    for (int i = 0; i < 2; i++)
        delete mas2[i];


    return 0;
}

