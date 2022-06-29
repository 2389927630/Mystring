#include <iostream>
using namespace std;


//全局函数
int char_change(char a);
bool base_judge(char a, int base);
bool decimal_judge(char a);

class Mystring
{
	friend ostream& operator<<(ostream& o, Mystring& str);
	friend istream& operator>> (istream& is, Mystring& str);
	friend Mystring operator+ (const char* lhs, const Mystring& rhs);
	friend Mystring operator+ (char lhs, const Mystring& rhs);
	friend istream& getline(istream& is, Mystring& str, char delim);
	friend istream& getline(istream& is, Mystring& str);
	friend bool operator== (const Mystring& lhs, const Mystring& rhs);
	friend bool operator== (const char* lhs, const Mystring& rhs);
	friend bool operator== (const Mystring& lhs, const char* rhs);
	friend bool operator!= (const Mystring& lhs, const Mystring& rhs);
	friend bool operator!= (const char* lhs, const Mystring& rhs);
	friend bool operator!= (const Mystring& lhs, const char* rhs);
	friend bool operator<  (const Mystring& lhs, const Mystring& rhs);
	friend bool operator<  (const char* lhs, const Mystring& rhs);
	friend bool operator<  (const Mystring& lhs, const char* rhs);
	friend bool operator<= (const Mystring& lhs, const Mystring& rhs);
	friend bool operator<= (const char* lhs, const Mystring& rhs);
	friend bool operator<= (const Mystring& lhs, const char* rhs);
	friend bool operator>  (const Mystring& lhs, const Mystring& rhs);
	friend bool operator>  (const char* lhs, const Mystring& rhs);
	friend bool operator>  (const Mystring& lhs, const char* rhs);
	friend bool operator>= (const Mystring& lhs, const Mystring& rhs);
	friend bool operator>= (const char* lhs, const Mystring& rhs);
	friend bool operator>= (const Mystring& lhs, const char* rhs);
	
public:
	Mystring();
	Mystring(const Mystring& str);
	Mystring(const Mystring& str, size_t pos, size_t len);
	Mystring(const char* s);
	Mystring(const char* s, size_t n);
	Mystring(size_t n, char c);
	~Mystring();


	Mystring& operator= (char c);
	Mystring& operator= (const Mystring& str);
	Mystring& operator= (const char* s);
    Mystring operator+ (const Mystring& rhs);
	Mystring operator+ (const char* rhs);
	Mystring operator+ (char rhs);
	
	Mystring& operator+= (char c);
	Mystring& operator+= (const Mystring& str);
	Mystring& operator+= (const char* s);

	
	size_t size() const;
    size_t length_func() const;
	size_t max_size() const;
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t capacity() const;
	void reserve(size_t n = 0);
	void clear();
	bool empty() const;
	void shrink_to_fit();

	char& operator[](size_t pos);
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;

	Mystring& append(const Mystring& str);
	Mystring& append(const Mystring& str, size_t subpos, size_t sublen);
	Mystring& append(const char* s);
	Mystring& append(const char* s, size_t n);
	Mystring& append(size_t n, char c);
	void push_back(char c);
	Mystring& assign(const Mystring& str);
	Mystring& assign(const Mystring& str, size_t subpos, size_t sublen);
	Mystring& assign(const char* s);
	Mystring& assign(const char* s, size_t n);
	Mystring& assign(size_t n, char c);
	Mystring& insert(size_t pos, const Mystring& str);
	Mystring& insert(size_t pos, const Mystring& str, size_t subpos, size_t sublen);
	Mystring& insert(size_t pos, const char* s);
	Mystring& insert(size_t pos, const char* s, size_t n);
	Mystring& insert(size_t pos, size_t n, char c);
	Mystring& erase(size_t pos = 0, size_t len = npos);
	Mystring& replace(size_t pos, size_t len, const Mystring& str);
	Mystring& replace(size_t pos, size_t len, const Mystring& str,size_t subpos, size_t sublen);
	Mystring& replace(size_t pos, size_t len, const char* s);
	Mystring& replace(size_t pos, size_t len, const char* s, size_t n);
	Mystring& replace(size_t pos, size_t len, size_t n, char c);
	static void swap(Mystring& x, Mystring& y);
	void pop_back();

	const char* data() const;
	size_t copy(char* s, size_t len, size_t pos = 0) const;
	size_t find(const Mystring& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;
	size_t rfind(const Mystring& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos=npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;
	size_t find_first_of(const Mystring& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	size_t find_last_of(const Mystring& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;
	size_t find_first_not_of(const Mystring& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;
	size_t find_last_not_of(const Mystring& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;


	Mystring substr(size_t pos = 0, size_t len=npos) const;
	int compare(const Mystring& str) const;
	int compare(size_t pos, size_t len, const Mystring& str) const;
	int compare(size_t pos, size_t len, const Mystring& str,size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;


	static int stoi(const Mystring& str, size_t* idx = 0, int base = 10);
	static long stol(const Mystring& str, size_t* idx = 0, int base = 10);
	static unsigned long stoul(const Mystring& str, size_t* idx = 0, int base = 10);
	static long long stoll(const Mystring& str, size_t* idx = 0, int base = 10);
	static unsigned long long stoull(const Mystring& str, size_t* idx = 0, int base = 10);
	static float stof(const Mystring& str, size_t* idx = 0);
	static double stod(const Mystring& str, size_t* idx = 0);
	static long double stold(const Mystring& str, size_t* idx = 0);
	Mystring to_string(int val);
	Mystring to_string(long val);
	Mystring to_string(long long val);
	Mystring to_string(unsigned val);
	Mystring to_string(unsigned long val);
	Mystring to_string(unsigned long long val);
	Mystring to_string(float val);
	Mystring to_string(double val);
	Mystring to_string(long double val);


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
	static size_t strlen(const char* str);


	static const size_t npos;
private:
	static int debugSumNum;
	int length;
	int debugNum;
	char* Str; //实际字符串内容
};

