#include <iostream>
#include "Mystring.h"
using namespace std;
#define max 100

int Mystring::stoi(const Mystring& str, size_t* idx, int base)
{
    //将字符串转为数字
    size_t point = 0;
    size_t index = 0;

    if (base == 0)
    {
        int i = 0;
        while (i < str.size() && str.Str[i] != '0')
            i++;
        if (i + 2 < str.size() && str.Str[i + 1] == 'x')
            base = 16;
        else
            base = 10;
    }
    while (!base_judge(*(str.Str + point), base))
    {
        point++;
    }
    //判断0x的情况
    if (base == 0 || base == 16)
    {
        if (*(str.Str + point) == '0')
        {
            if (*(str.Str + point + 1) == 'x' && point + 3 < str.size())
            {
                point = point + 2;
                if (base == 0)
                {
                    base = 16;
                }
            }
        }
    }

    int point_tem = point;

    while (base_judge(*(str.Str + point_tem), base))
    {
        point_tem++;
        index = point_tem;
        if (*(str.Str + point_tem) == '\0')
            break;

    }

    if (idx != NULL)
    {
        *idx = index;
    }
    int res = 0;
    int k = 0;
    for (size_t i = index - 1;i != point - 1;i--)
        res += char_change(str.Str[i]) * pow(base, k++);
    if (point > 0)
    {
        if (*(str.Str + point - 1) == '-')
        {
            res = (-1 * res);
        }
    }

    return res;
}

int char_change(char a)
{
    //将36个合法字符转换成数字
    if (a >= '0' && a <= '9')
        return a - '0';
    if (a >= 'a' && a <= 'z')
        return a - 'a' + 10;
    if (a >= 'A' && a <= 'Z')
        return a - 'A' + 10;
}

bool base_judge(char a, int base)
{
    //判断是否为合法字符
    if (char_change(a) < base)
        return true;
    else
        return false;
}

long Mystring::stol(const Mystring& str, size_t* idx, int base)
{
    int res=stoi(str, idx, base);
    return (long)res;
}


unsigned long Mystring::stoul(const Mystring& str, size_t* idx, int base)
{
    int res = stoi(str, idx, base);
    return (unsigned long)res;
}

long long Mystring::stoll(const Mystring& str, size_t* idx, int base)
{
    int res = stoi(str, idx, base);
    return (long long)res;
}

unsigned long long Mystring::stoull(const Mystring& str, size_t* idx, int base)
{
    int res = stoi(str, idx, base);
    return (unsigned long long)res;
}

float Mystring::stof(const Mystring& str, size_t* idx)
{
    size_t point = 0;
    size_t index = 0;
    while (!decimal_judge(*(str.Str + point)))
    {
        point++;
    }
    size_t point_tem = point;
    size_t point_tem_1 = point;
    while (decimal_judge(*(str.Str + point_tem)))
    {
        point_tem++;
        index = point_tem;
        if (*(str.Str + point_tem) == '\0')
            break;

    }
    size_t dot = 0;
    while (*(str.Str + point_tem_1) != '.')
    {
        point_tem_1++;
        dot = point_tem_1;
    }

    if (idx != NULL)
    {
        *idx = index;
    }
    float res=0.0;
    size_t k = 0;
    for (size_t i = dot - 1;i != point - 1;i--)
        res += str.Str[i] * pow(10, k++);
    size_t m = 0;
    for (size_t j = dot+1;j != index;j++)
        res += str.Str[j] * pow(0.1, m++);

    if (point > 0)
    {
        if (*(str.Str + point - 1) == '-')
        {
            res = (-1 * res);
        }
    }

    return res;
}

bool decimal_judge(char a)
{
    if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9' || a == '.')
        return true;
    else
        return false;
}

double Mystring::stod(const Mystring& str, size_t* idx)
{
    size_t point = 0;
    size_t index = 0;
    while (!decimal_judge(*(str.Str + point)))
    {
        point++;
    }
    size_t point_tem = point;
    size_t point_tem_1 = point;
    while (decimal_judge(*(str.Str + point_tem)))
    {
        point_tem++;
        index = point_tem;
        if (*(str.Str + point_tem) == '\0')
            break;

    }
    size_t dot = 0;
    while (*(str.Str + point_tem_1) != '.')
    {
        point_tem_1++;
        dot = point_tem_1;
    }

    if (idx != NULL)
    {
        *idx = index;
    }
    double res = 0.0;
    size_t k = 0;
    for (size_t i = dot - 1;i != point - 1;i--)
        res += str.Str[i] * pow(10, k++);
    size_t m = 0;
    for (size_t j = dot + 1;j != index;j++)
        res += str.Str[j] * pow(0.1, m++);

    if (point > 0)
    {
        if (*(str.Str + point - 1) == '-')
        {
            res = (-1 * res);
        }
    }

    return res;
}

long double Mystring::stold(const Mystring& str, size_t* idx)
{
    size_t point = 0;
    size_t index = 0;
    while (!decimal_judge(*(str.Str + point)))
    {
        point++;
    }
    size_t point_tem = point;
    size_t point_tem_1 = point;
    while (decimal_judge(*(str.Str + point_tem)))
    {
        point_tem++;
        index = point_tem;
        if (*(str.Str + point_tem) == '\0')
            break;

    }
    size_t dot = 0;
    while (*(str.Str + point_tem_1) != '.')
    {
        point_tem_1++;
        dot = point_tem_1;
    }

    if (idx != NULL)
    {
        *idx = index;
    }
    long double res = 0.0;
    size_t k = 0;
    for (size_t i = dot - 1;i != point - 1;i--)
        res += str.Str[i] * pow(10, k++);
    size_t m = 0;
    for (size_t j = dot + 1;j != index;j++)
        res += str.Str[j] * pow(0.1, m++);

    if (point > 0)
    {
        if (*(str.Str + point - 1) == '-')
        {
            res = (-1 * res);
        }
    }

    return res;
}

Mystring Mystring::to_string(int val)
{
    long long val_func=(long long)val;
    Mystring res=to_string(val_func);
    return res;
}

Mystring Mystring::to_string(long val)
{
    long long val_func = (long long)val;
    Mystring res = to_string(val_func);
    return res;
}

Mystring Mystring::to_string(long long val)
{
    bool ispositive = (val >= 0) ? true : false;
    val *= (val >= 0) ? 1 : -1;
    Mystring res;
    while (val != 0) {
        int num = val % 10;
        val = val / 10;
        res = ('0' + num) + res;
    }
    if (!ispositive) {
        res = '-' + res;
    }
    return res;
}

Mystring Mystring::to_string(unsigned val)
{
    unsigned long long val_func = (unsigned long long)val;
    Mystring res = to_string(val_func);
    return res;
}

Mystring Mystring::to_string(unsigned long val)
{
    unsigned long long val_func = (unsigned long long)val;
    Mystring res = to_string(val_func);
    return res;
}

Mystring Mystring::to_string(unsigned long long val)
{
    Mystring res;
    if (val == 0) {
        res = "0";
        return res;
    }
    while (val != 0) {
        int num = val % 10;
        val = val / 10;
        res = ('0' + num) + res;
    }

    return res;
}


Mystring Mystring::to_string(float val)
{
    long double val_func = (long double)val;
    Mystring res = to_string(val_func);
    return res;
}

Mystring Mystring::to_string(double val)
{
    long double val_func = (long double)val;
    Mystring res = to_string(val_func);
    return res;
}

Mystring Mystring::to_string(long double val)
{
    Mystring res;
    bool ispositive = (val >= 0) ? true : false;
    val *= (val >= 0) ? 1 : -1;
    unsigned long long integerPart = val;
    res = Mystring::to_string(integerPart);

    res += '.';
    unsigned long long decimalPart = (val - integerPart) * pow(10, 10);
    res += Mystring::to_string(decimalPart);

    if (!ispositive) {
        res = '-' + res;
    }
    return res;
}