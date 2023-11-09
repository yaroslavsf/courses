1)
#include <iostream>
using namespace std;
class String
{
private:
    char* str;
    int size;
public:
    String() : str(new char[size]), size(80) { }
    String(const char* str1) : str(new char[strlen(str1)+1])
    {
        strcpy_s(str ,strlen(str1) + 1, str1);
    }
    String(unsigned int size) : str(new char[size]), size(size) 
    {
        str[0] = '\0';
    }
    String(const String& source)  
    {
        this->size = source.size;
        strcpy_s(this->str, strlen(str) + 1, source.str);
    }

    void print() const
    {
        cout << str;
    }
    void input()
    {
        char buf[BUFSIZ];
        cin.getline(buf, BUFSIZ);
    }
    ~String()
    {
        delete[] str;
    }
    
};

int main()
{



	return 0;
}

2)
#include <iostream>
using namespace std;
class Array
{
private:
    int* a;
    int size;
public:

    explicit Array(int* buf, int n) 
        :
        a{ buf ? new int[n] : nullptr },
        size{ n } 
    {   }

    explicit Array(int n) : Array(nullptr, n) { }
    
    explicit Array(const Array& source)
    {
        this->size = source.size;
        this->a = new int[source.size];
        for (int i = 0; i < size; i++)
        {
            a[i] = source.a[i];
         }
    }
    void sort_mas(int* &a)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }

    void print() const
    {
        cout << a;
    }

    ~Array()
    {
        delete[] a;
    }
};

int main()
{
	return 0;
}


