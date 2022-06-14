#include <iostream>
#include "Mystring.h"
using namespace std;

//¹¹Ôì¿Õ×Ö·û´®
Mystring::Mystring()
{
	this->debugNum = debugSumNum++;
	Str = new char[1];
	Str[0] = '\0' ;
	length = 0;
}

Mystring::Mystring(const Mystring& str)
{
	this->debugNum = debugSumNum++;
	Str = new char[str.length+1];
	this->length = str.length;
	Mystring::strcpy(this->Str, str.Str);

}

Mystring::Mystring(const Mystring& str, size_t pos, size_t len )
{
	this->debugNum = debugSumNum++;
	Str = new char[pos - len + 1];
	this->length = len;
	//this->Str = str.Str;
	//char* str = newStr;
	size_t j = 0;
	for (int i = pos; i < pos+len; i++)
	{
		this->Str[j] = str.Str[i];
		j++;
	}
	Str[j] = '\0';
	
}

Mystring::Mystring(const char* s)
{
	this->debugNum = debugSumNum++;
	Str = new char[strlen(s)];
	if (s)
	{
		length = Mystring::strlen(s);
		this->Str = new char[length + 1];
		Mystring::strcpy(Str, s);
	}
	else
		Mystring();

}

Mystring::Mystring(const char* s, size_t n)
{
	this->debugNum = debugSumNum++;
	length = n;
	this->Str = new char[n + 1];
	Mystring::strncpy(Str, s, n);
	//int j = 0;
	
	/*while (n)
	{
		*Str = *s;
		Str++;
		s++;
		n--;
	}
	while (--n)
	{
		*(this->Str++) = '\0';
	}
	*(this->Str+1) = '\0';*/
}

Mystring::Mystring(size_t n, char c)
{
	this->debugNum = debugSumNum++;
	Str = new char[n + 1];
	length = n;
	this->Str = new char[n + 1];
	int j = 0;
	for (int i = 0;i < n;i++)
	{
		Str[j] = c;
		j++;
	}
	Str[j] = '\0';
}

Mystring::~Mystring()
{
	if (Str) {
		delete[] Str;
		Str = NULL;
		length = 0;
	}
}

