#include <iostream>
#include "Mystring.h"
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
    str.Str = new char[str.length + 1];
    Mystring::strcpy(str.Str, tmp);
    return is;

}

Mystring& Mystring::operator= (char c)
{
    this->length = 1;
    Str = new char[2];
    Str[0] = c;
    this->Str[1] = '\0';
    return *this;
}

Mystring& Mystring::operator= (const Mystring& str)
{
    this->length = str.length;
    Str = new char[str.length+1];
    int i = 0;
    int j = 0;
    while ((this->Str[j] =str.Str[i])!='\0')
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
    Str = new char[length+1];
    Mystring::strcpy(Str, s);
    //int j = 0;
    //while ((this->Str[j] = *s) != '\0')
    //{
    //    s++;
    //    j++;
    //}
    //Str[j] = '\0';
    return *this;
}

Mystring Mystring::operator+ (const Mystring& rhs)
{
    Mystring str1;
    str1.Str = new char[this->length + rhs.length + 1];
    str1.length = this->length + rhs.length;
    str1[0] = '\0';//骗strcat函数
    Mystring::strcat(str1.Str, this->Str);
    Mystring::strcat(str1.Str, rhs.Str);
    return str1;
}

size_t Mystring::size() const
{
    size_t len = (size_t)length;
    return len;
}

//size_t Mystring::length() const
//{
//    size_t len = (size_t)length;
//    return len;
//}