#include <iostream>
#include "Mystring.h"
#pragma warning(disable : 4996)
using namespace std;

char& Mystring::operator[] (size_t pos)
{
    if (pos < 0 || pos >= length) {  //异常处理过程
        return Str[0];
    }
    if (Str) {
        return Str[pos];
    }
}

ostream& operator<<(ostream& o, Mystring& str)
{
    o << str.Str;
    return o;
}

istream& operator>> (istream& is, Mystring& str)
{
    //is>>str.Str ;
    //return is;
    //因为不能确定str.data和输入的字符串的大小
    char tmp[1000] = { 0 };
    is >> tmp;
    str.length = Mystring::strlen(tmp);
    delete[] str.Str;
    str.Str = new char[str.length + 1];
    Mystring::strcpy(str.Str, tmp);
    return is;
}

Mystring& Mystring::operator= (char c)
{
    this->length = 1;
    delete[] Str;
    Str = new char[2];
    Str[0] = c;
    this->Str[1] = '\0';
    return *this;
}

Mystring& Mystring::operator= (const Mystring& str)
{
    this->length = str.length;
    delete[] Str;
    Str = new char[str.length + 1];
    int i = 0;
    int j = 0;
    while ((this->Str[j] = str.Str[i]) != '\0')
    {
        j++;
        i++;
    }
    this->Str[j] = '\0';
    return *this;
}

Mystring& Mystring::operator= (const char* s)
{
    length = Mystring::strlen(s);
    delete[] Str;
    Str = new char[length + 1];
    Mystring::strcpy(Str, s);
    return *this;
}

Mystring& Mystring::operator+= (char c)
{
    *this = *this + c;
    return *this;
}

Mystring& Mystring::operator+= (const Mystring& str)
{
    *this = *this + str;
    return *this;
}

Mystring& Mystring::operator+= (const char* s)
{
    *this = *this + s;
    return *this;
}

Mystring Mystring::operator+ (const Mystring& rhs)
{
    Mystring str1;
    //delete[] str1.Str;
    str1.Str = new char[this->length + rhs.length + 1];
    str1.length = this->length + rhs.length;

    Mystring::strcpy(str1.Str, this->Str);
    Mystring::strcat(str1.Str, rhs.Str);
    return str1;
}

Mystring Mystring::operator+ (const char* rhs)
{
    Mystring str1;
    //delete[] str1.Str;
    str1.Str = new char[this->length + strlen(rhs) + 1];
    str1.length = this->length + strlen(rhs);
    str1[0] = '\0';//骗strcat函数
    Mystring::strcpy(str1.Str, this->Str);
    Mystring::strcat(str1.Str, rhs);
    return str1;
}

Mystring operator+ (const char* lhs, const Mystring& rhs)
{
    //Mystring类和字符串指针相加的全局函数
    Mystring str1;
    //delete[] str1.Str;
    str1.Str = new char[rhs.size() + strlen(lhs) + 1];
    str1.length = rhs.size() + strlen(lhs);
    str1[0] = '\0';//骗strcat函数
    Mystring::strcat(str1.Str, lhs);
    Mystring::strcat(str1.Str, rhs.Str);
    return str1;
}

Mystring Mystring::operator+ (char rhs)
{
    Mystring str1(1, rhs);

    return *this + str1;
}

Mystring operator+ (char lhs, const Mystring& rhs)
{
    Mystring str1;
    //delete[] str1.Str;
    str1.Str = new char[rhs.size() + 2];
    str1.length = rhs.size() + 1;
    str1[0] = '\0';//骗strcat函数
    Mystring::strcat(str1.Str, &lhs);
    Mystring::strcat(str1.Str, rhs.Str);
    return str1;
}

bool operator==(const Mystring& lhs, const Mystring& rhs)
{
    return (lhs.compare(rhs) == 0) ? true : false;
}

bool operator==(const char* lhs, const Mystring& rhs)
{
    return (rhs.compare(lhs) == 0) ? true : false;
}

bool operator==(const Mystring& lhs, const char* rhs)
{
    return (lhs.compare(rhs) == 0) ? true : false;
}

bool operator!=(const Mystring& lhs, const Mystring& rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const char* lhs, const Mystring& rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const Mystring& lhs, const char* rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Mystring& lhs, const Mystring& rhs)
{
    return (lhs.compare(rhs) < 0) ? true : false;
}

bool operator<(const char* lhs, const Mystring& rhs)
{
    return (rhs.compare(lhs) > 0) ? true : false;
}

bool operator<(const Mystring& lhs, const char* rhs)
{
    return (lhs.compare(rhs) < 0) ? true : false;
}

bool operator<=(const Mystring& lhs, const Mystring& rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator<=(const char* lhs, const Mystring& rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator<=(const Mystring& lhs, const char* rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>(const Mystring& lhs, const Mystring& rhs)
{
    return rhs < lhs;
}

bool operator>(const char* lhs, const Mystring& rhs)
{
    return rhs < lhs;
}

bool operator>(const Mystring& lhs, const char* rhs)
{
    return rhs < lhs;
}

bool operator>=(const Mystring& lhs, const Mystring& rhs)
{
    return rhs <= lhs;
}

bool operator>=(const char* lhs, const Mystring& rhs)
{
    return rhs <= lhs;
}

bool operator>=(const Mystring& lhs, const char* rhs)
{
    return rhs <= lhs;
}

istream& getline(istream& is, Mystring& str, char delim)
{
    char c;
    is.ignore();
    while (true) {

        c = is.get();
        if (c == delim)
            return is;
        str.append(1, c);
    }
    return is;
}

istream& getline(istream& is, Mystring& str)
{
    return getline(is, str, '\n');
}
