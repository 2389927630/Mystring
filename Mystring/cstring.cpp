#include<iostream>
#include "Mystring.h"
#include <errno.h>
using namespace std;


void* Mystring::memcpy(void* destin, const void* source, size_t n)
{
    //复制内存块 memcpy实现
	void* ret = destin;
	while (n--)
	{
		*(char*)destin = *(char*)source;
		destin = ((char*)destin) + 1;
		source = ((char*)source) + 1;
	}
	return ret;
}


void* Mystring::memmove(void* destin, const void* source, size_t n)
{
    //复制内存块 memmove实现
    char* dest_func = (char*)destin;
    char* src_func = (char*)source;

    //参数判断
    if (NULL == dest_func || NULL == src_func || 0 > n) {
        cout<<"error\n";
        return destin;
    }

    //先判断是否存在重叠内存
    if (dest_func <= src_func || dest_func >= (src_func + n)) {
        while (n--) {
            *dest_func++ = *src_func++;//从头往后拷贝
        }
    }
    else {
        dest_func = dest_func + n - 1;
        src_func = src_func + n - 1;
        while (n--) {
            *dest_func-- = *src_func--;//从后往前拷贝(因为此时对dest的赋值，会覆盖掉src在内的n个空间的内容)
        }
    }

    return destin;
}

char* Mystring::strcpy(char* destin, const char* source)
{
    //字符串复制
    char* dest_func = destin;
    while ((*dest_func = *source) != 0)
    {
        source++;
        dest_func++;
    }
    return destin;
}


char* Mystring::strncpy(char* destination, const char* source, size_t num)
{
    //复制指定长度字符串
    char* dest_func = destination;
    while (num && (*dest_func++ = *source++))
        num--;
    if (num)
        while (--num)
        {
            *dest_func++ = '\0';
        }
    //else
    //    *(dest_func) = '\0';

    return destination;
}


char* Mystring::strcat(char* destination, const char* source)
{
    //在尾部拼接字符串
    char* dest_func = destination;
    while (*dest_func)
    {
        dest_func++;
    }

    while (*source)
    {
        *dest_func = *source;
        source++;
        dest_func++;
    }
    *(dest_func) = '\0';

    return destination;
}

char* Mystring::strncat(char* destination, const char* source, size_t num)
{
    char* dest_func = destination;
    while (*dest_func)
    {
        dest_func++;
    }

    while (num && (*dest_func++ = *source++))
        num--;
    if (num)
        while (--num)
        {
            *dest_func++ = '\0';
        }
    else
        *(dest_func + 1) = '\0';

    return destination;
}

int Mystring::memcmp(const void* ptr1, const void* ptr2, size_t num)
{
    int ret = 0;
    const char* ptm1 = (char*)ptr1;
    const char* ptm2 = (char*)ptr2;

    while (num)
    {
        if (*ptm1 > *ptm2)
        {
            ret = 1;
            break;
        }
        if (*ptm1 < *ptm2)
        {
            ret = -1;
            break;
        }
        ptm1++;
        ptm2++;
    }
    return ret;

}

int Mystring::strcmp(const char* str1, const char* str2)
{
    //比较字符串
    while (*str1 == *str2 && *str1 && *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;

}

int Mystring::strcoll(const char* str1, const char* str2)
{
    int i = 1;
    while (*str1 == *str2 && *str1 && *str2)
    {
        str1++;
        str2++;
        i++;
    }
    if (*str1 == *str2)
        return 0;
    else if (*str1 > *str2)
        return i;
    else if (*str1 < *str2)
        return -i;
}

int  Mystring::strncmp(const char* str1, const char* str2, size_t num)
{
    int j = 0;
    for (int i = 0;i < num;i++)
    {
        if (*str1 == *str2)
        {
            str1++;
            str2++;
            continue;
        }
        else if (*str1 > *str2)
        {
            j = 1;
            break;
        }
        else if (*str1 < *str2)
        {
            j = -1;
            break;
        }
        
    }
    return j;
}

size_t Mystring::strxfrm(char* destination, const char* source, size_t num)
{
    strncpy(destination, source, num);
    return strlen(source);
}

void* Mystring::memchr(const void* ptr, int value, size_t num)
{
    while (num && (*(unsigned char*)ptr != (unsigned char)value))
    {
        ptr = (unsigned char*)ptr + 1;
        num--;
    }
    return (num ? (void*)ptr : NULL);

}

char* Mystring::strchr(char* str, int character)
{
    while (*str && (*str != (char)character))
    {
        str++;
    }
    if (*str == (char)character)  return (char*)str;
    return NULL;

}

size_t Mystring::strcspn(const char* str1, const char* str2)
{
    //找到任意一个str2字符在str1中的第一个位置
    int i = 0;
    int j = 0;
    while (*(str1 + i) != '\0')
    {
        while (*(str2 + j) != '\0' && (*(str1 + i) != *(str2 + j)))
        {
            j++;
        }
        if (*(str1 + i) == *(str2 + j))
            break;
        i++;
        j = 0;
    }
    return i;
}

const char* Mystring::strpbrk(const char* str1, const char* str2)
{
    //依次找str1中含有str2中的字符
    int j = 0;
    while (*str1 != '\0')
    {
        while (*(str2 + j) != '\0' && (*(str1 ) != *(str2 + j)))
        {
            j++;
        }
        if (*(str1 ) == *(str2 + j))
            break;
        str1++;
        j = 0;
    }
    if (*str1 == '\0')
        return NULL;
    return str1;
}

char* Mystring::strpbrk(char* str1, const char* str2)
{
    //依次找str1中含有str2中的字符
    int j = 0;
    while (*str1 != '\0')
    {
        while (*(str2 + j) != '\0' && (*(str1) != *(str2 + j)))
        {
            j++;
        }
        if (*(str1) == *(str2 + j))
            break;
        str1++;
        j = 0;
    }
    if (*str1 == '\0')
        return NULL;
    return str1;
}


char* Mystring::strrchr(char* str, int character)
{
    //找最后一个指定的字符
    char* str_func= str;
    while (*str != '\0')
    {
        if (*str == (char)character)
            str_func = str;
        str++;
    }
    return str_func;
}

size_t Mystring::strspn(const char* str1, const char* str2)
{
    //找在str1中满足str2的第一个字符的位置
    size_t i = 0;
    int j = 0;
    while (*str1 != '\0')
    {
        while (*(str2+j) != '\0')
        {
            if (*str1 == *(str2+j))
            {
                i++;
                break;
            }
            j++;
        }
        str1++;
        j = 0;
    }
    return i;
}

int Mystring::debugSumNum = 0;

char* Mystring::strstr(char* str1, const char* str2)
{
    //找到str2在str1的地址
    int len = 0;
    while (*(str2+len) != 0)
    {
        len++;
    }
    int j = 0;
    int i = 0;
    while ( *(str1+i)!='\0')
    {
        i++;
        if (*(str2) == *(str1 + i)&&(Mystring::strncmp(str2, (str1 + i), len) == 0))
        {
                j = i;
                break;
        }
    }
    if (j!= 0)
        return str1 + j;
    else
        return NULL;
}

//该程序的关键点在于定义了一个静态的字符指针,该指针用来记录分割后的字符串的首地址
//传入NULL,则表示继续处理静态指针指向的余下字符串
char* Mystring::strtok(char* str, const char* delimiters)
{
    static char* src = NULL;                                         //记下上一次非分隔字符串字符的位置,详见图示
    const char* indelim = delimiters;                                  //对delim做一个备份
    int flag = 1, index = 0;
    //每一次调用strtok,flag标记都会使得程序只记录下第一个非分隔符的位置,以后出现非分隔符不再处理

    char* temp = NULL;                                       //程序的返回值

    if (str == NULL)
    {
        str = src;                                               //若str为NULL则表示该程序继续处理上一次余下的字符串
    }
    for (;*str;str++)
    {
        delimiters = indelim;
        for (;*delimiters;delimiters++)
        {
            if (*str == *delimiters)
            {
                *str = NULL;                    //若找到delim中感兴趣的字符,将该字符置为NULL
                index = 1;                         //用来标记已出现感兴趣字符
                break;
            }
        }
        if (*str != NULL && flag == 1)
        {
            temp = str;                              //只记录下当前第一个非感兴趣字符的位置
            flag = 0;
        }
        if (*str != NULL && flag == 0 && index == 1)
        {
            src = str;                                   //第二次出现非感兴趣字符的位置(之前一定出现过感兴趣字符)
            return temp;
        }
    }
    src = str; //执行该句表明一直未出现过感兴趣字符,或者说在出现了感兴趣的字符后,就没再出现过非感兴趣字符

    return temp;
}

void* Mystring::memset(void* ptr, int value, size_t num)
{
    char* ptr_func = (char*)ptr;
    for (int i = 0;i < num;i++)
    {
        *ptr_func = (char)value;
        ptr_func++;
    }
    return ptr;
}

char* Mystring::strerror(int errnum)
{
    char array[] = "\0";
    if (errnum == 0)
    {
        char* array = new char[Mystring::strlen("No error")];
        Mystring::strcpy(array, "No error");
        return array;
    }
    if (errnum == 2)
    {
        char* array = new char[Mystring::strlen("No such file or director")];
        Mystring::strcpy(array, "No such file or directory");
        return array;
    }
    
}

size_t Mystring::strlen(const char* str) 
{
    size_t i = 0;
    while (*str++)
    {
        i++;
    }
    return i;
}
