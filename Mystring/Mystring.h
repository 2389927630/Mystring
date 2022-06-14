#include <iostream>
using namespace std;

class Mystring
{
	friend ostream& operator<<(std::ostream& o, Mystring& str);
	friend istream& operator>> (istream& is, Mystring& str);
	
public:
	Mystring();
	Mystring(const Mystring& str);
	Mystring(const Mystring& str, size_t pos, size_t len);
	Mystring(const char* s);
	Mystring(const char* s, size_t n);
	Mystring(size_t n, char c);

	char& operator[](size_t pos);
	Mystring& operator= (char c);
	Mystring& operator= (const Mystring& str);
	Mystring& operator= (const char* s);
    Mystring operator+ (const Mystring& rhs);


	size_t size() const;
   // size_t length() const;
	


	~Mystring();
	static void* memcpy(void* destin, const void* source, size_t n);
	static void* memmove(void* destin, const void* source, size_t n);
	static char* strcpy(char* destin, const char* source);
	static char* strncpy(char* destination, const char* source, size_t num);
	static char* strcat(char* destination, const char* source);
	static char* strncat(char* destination, const char* source, size_t num);
	static int memcmp(const void* ptr1, const void* ptr2, size_t num);
	static int strcmp(const char* str1, const char* str2);
	static int strcoll(const char* str1, const char* str2);
	static int strncmp(const char* str1, const char* str2, size_t num);
	static size_t strxfrm(char* destination, const char* source, size_t num);
	static size_t strlen(const char* str);
	static void* memchr (const void* ptr , int value, size_t num);
	static char* strchr(char* str, int character);
	static size_t strcspn(const char* str1, const char* str2);
	static const char* strpbrk(const char* str1, const char* str2);
	static char* strpbrk(char* str1, const char* str2);
	static char* strrchr(char* str, int character);
	static size_t strspn(const char* str1, const char* str2);
	static char* strstr(char* str1, const char* str2);
	static char* strtok(char* str, const char* delimiters);
	static void* memset(void* ptr, int value, size_t num);
	static char* strerror(int errnum);





private:
	static int debugSumNum;
	int length;
	int debugNum;
	char* Str; //Êµ¼Ê×Ö·û´®ÄÚÈÝ
};

