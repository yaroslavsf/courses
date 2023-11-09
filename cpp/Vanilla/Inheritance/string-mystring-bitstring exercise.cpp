#include<iostream>
#include<cstring>
using namespace std;

class MyString
{
protected:
    char* str;
    size_t length;

public:
    MyString(const char* string = 0)
        :
        str{ (string) ? new char[strlen(string) + 1] : nullptr }
    {
        if (string)
            strcpy_s(str, strlen(string)+1, string);
    }

    ~MyString()
    {
        delete[] str;
    }

    MyString(const MyString& other)
    {
        if (other.str)
        {
            length = strlen(other.str);
            this->str = new char[length + 1];

            for (size_t i = 0; i <= length; i++)
            {
                this->str[i] = other.str[i];
            }
        }
        else
        {
            str = nullptr;
            length = 0;
        }
    }


    MyString& operator =(const MyString& other)
    {

        if (this == &other)
            return *this;

        delete[] str;
        if (other.str)
        {
            length = strlen(other.str);
            str = new char[length + 1];
            strcpy_s(str, strlen(other.str)+1,other.str);
        }
        else
        {
            str = nullptr;
            length = 0;
        }

        return *this;

    }

    MyString operator+(const MyString& other)
    {
        if (str == nullptr && other.str == nullptr)
        {
            return MyString(nullptr);
        }
        else if (str == nullptr)
        {
            return MyString(other);
        }
        else if (other.str == nullptr)
        {
            return MyString(*this);
        }
        else
        {
            int  thisLength = strlen(this->str);
            int  otherLength = strlen(other.str);

            MyString newStr;
            newStr.length = thisLength + otherLength;
            newStr.str = new char[thisLength + otherLength + 1];

            int i = 0;
            for (; i < thisLength; i++)
            {
                newStr.str[i] = this->str[i];
            }

            for (int j = 0; j <= otherLength; j++, i++)
            {
                newStr.str[i] = other.str[j];
            }

            return newStr;
        }
    }

    void Print()
    {
        if (this->str)
            cout << this->str;
        else
            cout << "nullptr";
    }

    size_t Length() const
    {
        return length;
    }

    bool operator ==(const MyString& other)
    {
        if (this->length != other.length)
        {
            return false;
        }

        for (size_t i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator !=(const MyString& other)
    {
        return !(this->operator==(other));
    }

    char& operator [](int index)
    {
        return this->str[index];
    }

    MyString(MyString&& other)
    {
        this->length = other.length;
        this->str = other.str;
        other.str = nullptr;
        other.length = 0;
    }


};


class BitString : public MyString
{
public:
    BitString()
    {
        MyString(nullptr);
    }

    BitString(const char* str)
    {
        if (str)
            length = strlen(str);
        else
            length = 0;
        this->str = new char[length + 1];
        for (size_t i = 0; i < length; i++)
        {

            if ((str[i] != '0') && (str[i] != '1'))
            {
                this->str[0] = '\0';
                this->length = 0;
                break;
            }
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }

    BitString(const BitString& other)
        :
        MyString(other.str)
    {
    }


    BitString operator +(const BitString& other)
    {

        if (str == nullptr && other.str == nullptr)
        {
            return BitString();
        }
        if (str == nullptr)
        {
            return BitString(other);
        }
        else if (other.str == nullptr)
        {
            return BitString(*this);
        }
        else
        {
            size_t size_this = this->length;
            size_t size_other = other.length;

            size_t base_size = max(size_this, size_other) + 1;

            long int temp = 0;
            BitString res;
            res.str = new char[base_size];
            res.length = base_size - 1;
            res.str[length] = '\0';

            size_t i = base_size - 1;
            while (i > 0)
            {
                size_this--;
                size_other--;

                temp += ((size_this >= 0) ? this->str[size_this] - '0' : this->str[0] - '0');
                temp += ((size_other >= 0) ? other.str[size_other] - '0' : other.str[0] - '0');
                res.str[--i] = '0' + temp % 2;

                temp /= 2;
            }

            return res;
        }
    }
    BitString& operator +=(const BitString& other)
    {
        *this = *this + other;
        return *this;
    }

    bool operator ==(const BitString& other)
    {

        if (this->length != other.length)
        {
            return false;
        }

        for (size_t i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator !=(const BitString& other)
    {
        return !(this->operator==(other));
    }

};


int main()
{
    BitString str_1("1111111");
    str_1.Print();
    cout << endl;
    BitString str_2(str_1);
    cout << (str_1 == str_2) << endl;
    BitString s3(str_1 + str_2);
    cout << "1111111 + 1111111" << endl;
    s3.Print();

    return 0;
}

