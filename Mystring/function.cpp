#include <iostream>
#include "Mystring.h"
#pragma warning(disable : 4996)
#include <windows.h>
using namespace std;

size_t Mystring::size() const
{
    size_t len = (size_t)length;
    return len;
}

size_t Mystring::length_func() const
{
    size_t len = (size_t)length;
    return len;
}

size_t Mystring::max_size() const
{
    MEMORYSTATUSEX l_oStatex;
    l_oStatex.dwLength = sizeof(l_oStatex);
    GlobalMemoryStatusEx(&l_oStatex);
    unsigned long long l_llAvailPhys = l_oStatex.ullAvailPhys;
    return l_llAvailPhys / sizeof(char);
}

void Mystring::resize(size_t n)
{
    char* Str_func = new char[n+1];
    if (n <= length)
    {
        Mystring::strncpy(Str_func, Str, n);
        delete[] Str;
        Str = new char[n + 1];
        Mystring::strcpy(Str, Str_func);
        *(Str + n) = '\0';
    }
    else
    {
        Mystring::strncpy(Str_func, Str, length);
        delete[] Str;
        Str = new char[n + 1];
        Mystring::strcpy(Str, Str_func);
        for (int i = length;i <= n;i++)
        {
            *(Str + i) = '\0';
        }
        *(Str + n) = '\0';
        
    }
    length = n;
    delete[] Str_func;
}

void Mystring::resize(size_t n, char c)
{
    char* Str_func = new char[n+1];
    if (n <= length)
    {
        Mystring::strncpy(Str_func,Str,n);
        *(Str_func+n) = '\0';
        delete[] Str;
        Str = new char[n + 1];
        Mystring::strcpy(Str,Str_func);
        *(Str + n) = '\0';
        
    }
    else
    {
        Mystring::strncpy(Str_func, Str, length);
        *(Str_func + length) = '\0';
        delete[] Str;
        Str = new char[n + 1];
        Mystring::strcpy(Str, Str_func);
        for (int i = length;i < n;i++)
        {
            *(Str+i) = c;
        }
        *(Str + n) = '\0';
    }
    delete[] Str_func;
}

size_t Mystring::capacity() const
{
    return sizeof(Mystring) + length * sizeof(char);
}

void Mystring::reserve(size_t n)
{
    if (n > this->Mystring::capacity())
    {
        Mystring::resize(n);
    }
}

void Mystring::clear()
{
    //Çå¿Õ×Ö·û´®
    length = 0;
    delete[] Str;
    Str = new char[1];
    *Str = '\0';
}

char& Mystring::at(size_t pos)
{
    return Str[pos];
}

const char& Mystring::at(size_t pos) const
{
    return Str[pos];
}

bool Mystring::empty() const
{
    if (*Str != '\0')
        return true;
    else
        return false;
}

void  Mystring::shrink_to_fit()
{
    length = strlen(this->Str);
    char* str = this->Str;
    Str = new char[length + 1];
    strncpy(this->Str, str, length-1);
    Str[length] = '\0';

}

size_t Mystring::rfind(const char* s, size_t pos) const
{
    size_t a = npos;
    while (Str[pos] != '\0')
    {
        if (strncmp(Str + pos, s, strlen(s))==0)
            a = pos;
        pos++;
    }

    return a;
}

size_t Mystring::rfind(const Mystring& str, size_t pos ) const
{
    size_t a=rfind(str.Str, pos);
    return a;
}

size_t Mystring::rfind(const char* s, size_t pos, size_t n) const
{
    size_t a = npos;
    while (Str[pos] != '\0')
    {
        if (strncmp(Str + pos, s, n)==0)
            a = pos;
        pos++;
    }

    return a;
}

size_t Mystring::rfind(char c, size_t pos) const
{
    size_t a = npos;
    while (Str[pos] != '\0')
    {
        if (Str[pos]==c)
            a = pos;
        pos++;
    }

    return a;
}

size_t Mystring::find_first_of(const Mystring& str, size_t pos) const
{
    size_t i = strcspn(this->Str+pos,str.Str);
    return i;
}

size_t Mystring::find_first_of(const char* s, size_t pos) const
{
    size_t i = strcspn(this->Str + pos, s);
    i += pos;
    if (i == this->size())
        return npos;
    
    return i;
}

size_t Mystring::find_first_of(const char* s, size_t pos, size_t n) const
{
    size_t count = pos;
    size_t num = 0;
    for(;count <pos+n;count++)
    {
        while (*(s + num) != '\0' && (this->Str[count] != *(s + num)))
        {
            num++;
        }
        if (this->Str[count] == *(s + num))
            break;
        count++;
        num = 0;
    }
    return count;
}

size_t Mystring::find_first_of(char c, size_t pos) const
{
    size_t count = 0;
    while (Str[pos] != '\0')
    {
        if (Str[pos] == c)
        {
            count = pos;
            break;
        }
            
        pos++;
    }
    return count;
}


size_t Mystring::find_last_of(const Mystring& str, size_t pos ) const
{
    size_t count = pos;
    size_t j = 0;
    size_t res = 0;
    while(Str[count]!='\0')
    {
        while (str.Str[j] != '\0' && (this->Str[count] != str.Str[j]))
        {
            j++;
        }
        if (this->Str[count] == str.Str[j])
            res = count;
        count++;
        j = 0;
    }
    return res;
}

size_t Mystring::find_last_of(const char* s, size_t pos) const
{
    size_t count = pos;
    size_t j = 0;
    size_t res = 0;
    while (Str[count] != '\0')
    {
        while (*(s+j) != '\0' && (this->Str[count] != *(s + j)))
        {
            j++;
        }
        if (this->Str[count] == *(s + j))
            res = count;
        count++;
        j = 0;
    }
    return res;
}

size_t Mystring::find_last_of(const char* s, size_t pos, size_t n) const
{
    size_t count = pos;
    size_t j = 0;
    size_t res = npos;
    while (Str[count] != '\0'&& count <=pos+n)
    {
        while (*(s + j) != '\0' && (this->Str[count] != *(s + j)))
        {
            j++;
        }
        if (this->Str[count] == *(s + j))
            res = count;
        count++;
        j = 0;
    }
    return res;
}

size_t Mystring::find_last_of(char c, size_t pos) const
{
    size_t i = pos;
    size_t res = npos;
    while (Str[i] != '\0')
    {
 
        if (this->Str[i] == c)
            res = i;
        i++;
    }
    return res;
}

size_t Mystring::find_first_not_of(const Mystring& str, size_t pos) const
{
    int j = 0;
    size_t count = pos;
    while (Str[count] != '\0')
    {
        while (str.Str[j] != '\0' && (Str[count] == str.Str[j]))
        {
            j++;
        }
        if (Str[count] != str.Str[j])
            break;
        count++;
        j = 0;
    }
    if (Str[count] == '\0')
        return npos;
    return count;
}

size_t Mystring::find_first_not_of(const char* s, size_t pos) const
{
    Mystring str1(s);
    size_t res=this->find_first_not_of(str1, pos);
    return res;
}

size_t Mystring::find_first_not_of(const char* s, size_t pos, size_t n) const
{
    char* str1 = new char[n + 1];
    strncpy(str1, s, n);
    *(str1 + n) = '\0';
    size_t res = this->find_first_not_of(s, pos);
    return res;
}

size_t Mystring::find_first_not_of(char c, size_t pos) const
{
    size_t num = pos;
    while (Str[num] != '\0')
    {
        if (Str[num] != c)
            break;
        num++;
    }
    if (Str[num] == '\0')
        return npos;
    return num;
}

size_t Mystring::find_last_not_of(const char* s, size_t pos, size_t n) const
{
    Mystring str1(s, n);
    size_t res=find_last_not_of(str1, pos);
    return res;
}

size_t Mystring::find_last_not_of(const Mystring& str, size_t pos) const
{
    size_t res = this->find_last_not_of(str.Str, pos);
    return res;
}

size_t Mystring::find_last_not_of(const char* s, size_t pos) const
{
    int j = 0;
    size_t res = 0;
    if (pos == npos) {
        pos = this->size();
    }
    for (int i = 0;i < pos;i++)
    {

        bool success = true;
        for (size_t k = 0; k < Mystring::strlen(s); k++)
        {
            if (this->at(i) == s[k]) {
                success = false;
                break;
            }
        }
        if (success) {
            res = i;
        }
    }
    return res;
}

size_t Mystring::find_last_not_of(char c, size_t pos) const
{
    size_t res = npos;
    while(Str[pos]!='\0')
    {

        if (Str[pos] == c)
            res = pos;
        pos++;

    }
    return res;
}

Mystring  Mystring::substr(size_t pos, size_t len) const
{
    Mystring str1;
    if (len == npos) {
        len = strlen(this->Str + pos);
    }
    if (pos == this->size())
        return str1;
    else if (pos < this->size())
    {
        delete[] str1.Str;
        str1.Str = new char[len + 1];
        str1.length = len;
        for (int count = 0;count < len;count++)
        {
            
            str1.Str[count] = this->Str[pos];
            pos++;
         
        }
        str1.Str[len] = '\0';
    }

    return str1;
}

int Mystring::compare(const Mystring& str) const
{
    int a = strcmp(this->Str, str.Str);
    return a;
}

int Mystring::compare(size_t pos, size_t len, const Mystring& str) const
{
    int a = strncmp(Str + pos, str.Str, len);
    return a;
}

int Mystring::compare(size_t pos, size_t len, const Mystring& str, size_t subpos, size_t sublen) const
{
    Mystring str_func=str.substr(subpos, sublen);
    if (sublen > len)
        len = sublen;
    int a = strncmp(Str + pos, str_func.Str, len);
    return a;
}

int Mystring::compare(const char* s) const
{
    int a = strcmp(this->Str, s);
    return a;
}

int Mystring::compare(size_t pos, size_t len, const char* s) const
{
    int a = strncmp(Str + pos, s, len);
    return a;
}

int Mystring::compare(size_t pos, size_t len, const char* s, size_t n) const
{
    char* s_func=new char [n+1];
    strncpy(s_func, s, n);
    if (n > len)
        len = n;
    int a = strncmp(Str + pos, s, len);
    return a;
}
char& Mystring::back()
{
    int i = 0;
    while (Str[i] != '\0')
        i++;
    return Str[i - 1];
}

const char& Mystring::back() const
{
    int i = 0;
    while (Str[i] != '\0')
        i++;
    return Str[i - 1];
}

char& Mystring::front()
{
    return Str[0];
}

const char& Mystring::front() const
{
    return Str[0];
}

//×·¼Ó×Ö·û´®
Mystring& Mystring::append(const Mystring& str)
{  
     *this+=str;
     return *this;
      
}

Mystring& Mystring::append(const Mystring& str, size_t subpos, size_t sublen)
{
    Mystring str1(str, subpos, sublen);
    *this += str1;
    return *this;
}

Mystring& Mystring::append(const char* s)
{
    *this += s;
    return *this;
}

Mystring& Mystring::append(const char* s, size_t n)
{
    char* str1 = new char[n + 1];
    strncpy(str1, s, n);
    str1[n] = '\0';
    *this += str1;
    delete[] str1;
    return *this;
}

Mystring& Mystring::append(size_t n, char c)
{
    Mystring str1(n, c);

    *this += str1;
    return *this;
}

void Mystring::push_back(char c)
{
    append(1, c);
}

//ÌáÈ¡×Ö·û´®
Mystring& Mystring::assign(const Mystring& str)
{
    Mystring str1(str);
    *this = str1;
    return *this;
}

Mystring& Mystring::assign(const Mystring& str, size_t subpos, size_t sublen)
{
    Mystring str1(str,subpos,sublen);
    *this = str1;
    return *this;
}

Mystring& Mystring::assign(const char* s)
{
    Mystring str1(s);
    *this = str1;
    return *this;
}

Mystring& Mystring::assign(const char* s, size_t n)
{
    Mystring str1(s,n);
    *this = str1;
    return *this;
}

Mystring& Mystring::assign(size_t n, char c)
{
    Mystring str1(n,c);
    *this = str1;
    return *this;
}

Mystring& Mystring::insert(size_t pos, const Mystring& str)
{
    char* str_tem=new char [strlen(Str)-pos+1];
    strcpy(str_tem, Str + pos);
    *(str_tem + strlen(Str) - pos) = '\0';
    Mystring str1(this->Str,pos);
    str1.append(str);
    str1.append(str_tem);
    delete[] str_tem;
    *this = str1;
    return *this;
}

Mystring& Mystring::insert(size_t pos, const Mystring& str, size_t subpos, size_t sublen)
{
    Mystring str_func(str, subpos, sublen);
    char* str_tem = new char[strlen(Str) - pos + 1];
    strcpy(str_tem, Str + pos);
    *(str_tem+strlen(Str) - pos)= '\0';
    Mystring str1(this->Str, pos);
    str1.append(str_func);
    str1.append(str_tem);
    delete[] str_tem;
    *this = str1;
    return *this;
}

Mystring& Mystring::insert(size_t pos, const char* s)
{
    char* str_tem = new char[strlen(Str) - pos + 1];
    strcpy(str_tem, Str + pos);
    *(str_tem + strlen(Str) - pos) = '\0';
    Mystring str1(this->Str, pos);
    str1.append(s);
    str1.append(str_tem);
    delete[] str_tem;
    *this = str1;
    return *this;
}

Mystring& Mystring::insert(size_t pos, const char* s, size_t n)
{
    char* s_func = new char[n + 1];
    strncpy(s_func, s, n);
    *(s_func + n) = '\0';
    char* str_tem = new char[strlen(Str) - pos + 1];
    strcpy(str_tem, Str + pos);
    *(str_tem + strlen(Str) - pos) = '\0';
    Mystring str1(this->Str, pos);
    str1.append(s_func);
    str1.append(str_tem);
    delete[] str_tem;
    delete[] s_func;
    *this = str1;
    return *this;
}

Mystring& Mystring::insert(size_t pos, size_t n, char c)
{
    char* str_tem = new char[strlen(Str) - pos + 1];
    strcpy(str_tem, Str + pos);
    *(str_tem + strlen(Str) - pos) = '\0';
    Mystring str1(this->Str, pos);
    str1.append(n,c);
    str1.append(str_tem);
    delete[] str_tem;
    *this = str1;
    return *this;
}

Mystring& Mystring::erase(size_t pos, size_t len)
{
    if (len == npos)
    {
        len = this->size() - pos;
    }
    char* str_tem = new char[strlen(Str) - pos - len + 1];
    strcpy(str_tem, Str + pos+len);
    *(str_tem + strlen(Str) - pos - len) = '\0';
    Mystring str1(this->Str, pos);
    str1.append(str_tem);
    delete[] str_tem;
    *this = str1;
    return *this;
}

Mystring& Mystring::replace(size_t pos, size_t len, const Mystring& str)
{
    this->erase(pos, len);
    this->insert(pos,str);
    return *this;
}

Mystring& Mystring::replace(size_t pos, size_t len, const Mystring& str, size_t subpos, size_t sublen)
{
    this->erase(pos, len);
    this->insert(pos, str, subpos, sublen);
    return *this;
}

Mystring& Mystring::replace(size_t pos, size_t len, const char* s)
{
    this->erase(pos, len);
    this->insert(pos, s);
    return *this;
}

Mystring& Mystring::replace(size_t pos, size_t len, const char* s, size_t n)
{
    this->erase(pos, len);
    this->insert(pos, s,n);
    return *this;
}

Mystring& Mystring::replace(size_t pos, size_t len, size_t n, char c)
{
    this->erase(pos, len);
    this->insert(pos,n,c);
    return *this;
}

const char* Mystring::data() const
{
    return Str;
}

size_t Mystring::copy(char* s, size_t len, size_t pos) const
{
    size_t i = pos;
    if (pos + len > this->size())
        return this->size() - pos;
    else
    {
        for (;i < pos + len;i++)
        {
            *s = Str[i];
            s++;
        }
        return len;
    }
    
}

size_t Mystring::find(const Mystring& str, size_t pos) const
{
    size_t num = pos;
    while ( this->Str[num] != '\0')
    {
        
        if (strncmp(this->Str + num, str.Str, str.size() ) == 0)
        {
            break;
        }
        num++;
    } 
    return num;
}

size_t Mystring::find(const char* s, size_t pos) const
{
    size_t num = pos;
    while (this->Str[num] != '\0')
    {

        if (strncmp(this->Str+num, s, strlen(s)) == 0)
        {
            return num;
        }
        num++;
    }
}

size_t Mystring::find(const char* s, size_t pos, size_t n) const
{
    size_t num = pos;
    while ( this->Str[num] != '\0')
    {
        
        if (strncmp(this->Str, s, n) == 0)
        {
            return num;
        }
        num++;
    }
}

size_t Mystring::find(char c, size_t pos) const
{
    size_t num = pos;
    while (this->Str[num] != c && this->Str[num] != '\0')
    {
        num++;
 
    }
    if (this->Str[num] = c)
    {
        return num;
      
    }
}


void Mystring::swap(Mystring& x, Mystring& y)
{
    Mystring str1(y);
    y = x;
    x = str1;
}

void Mystring::pop_back()
{
    this->Str[length] = '\0';
    length = length - 1;

}