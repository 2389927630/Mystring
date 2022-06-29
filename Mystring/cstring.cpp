#include<iostream>
#include "Mystring.h"
#include <errno.h>
using namespace std;


void* Mystring::memcpy(void* destin, const void* source, size_t n)
{
    //�����ڴ�� memcpyʵ��
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
    //�����ڴ�� memmoveʵ��
    char* dest_func = (char*)destin;
    char* src_func = (char*)source;

    //�����ж�
    if (NULL == dest_func || NULL == src_func || 0 > n) {
        cout<<"error\n";
        return destin;
    }

    //���ж��Ƿ�����ص��ڴ�
    if (dest_func <= src_func || dest_func >= (src_func + n)) {
        while (n--) {
            *dest_func++ = *src_func++;//��ͷ���󿽱�
        }
    }
    else {
        dest_func = dest_func + n - 1;
        src_func = src_func + n - 1;
        while (n--) {
            *dest_func-- = *src_func--;//�Ӻ���ǰ����(��Ϊ��ʱ��dest�ĸ�ֵ���Ḳ�ǵ�src���ڵ�n���ռ������)
        }
    }

    return destin;
}

char* Mystring::strcpy(char* destin, const char* source)
{
    //�ַ�������
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
    //����ָ�������ַ���
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
    //��β��ƴ���ַ���
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
    //�Ƚ��ַ���
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
    //�ҵ�����һ��str2�ַ���str1�еĵ�һ��λ��
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
    //������str1�к���str2�е��ַ�
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
    //������str1�к���str2�е��ַ�
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
    //�����һ��ָ�����ַ�
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
    //����str1������str2�ĵ�һ���ַ���λ��
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
    //�ҵ�str2��str1�ĵ�ַ
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

//�ó���Ĺؼ������ڶ�����һ����̬���ַ�ָ��,��ָ��������¼�ָ����ַ������׵�ַ
//����NULL,���ʾ��������ָ̬��ָ��������ַ���
char* Mystring::strtok(char* str, const char* delimiters)
{
    static char* src = NULL;                                         //������һ�ηǷָ��ַ����ַ���λ��,���ͼʾ
    const char* indelim = delimiters;                                  //��delim��һ������
    int flag = 1, index = 0;
    //ÿһ�ε���strtok,flag��Ƕ���ʹ�ó���ֻ��¼�µ�һ���Ƿָ�����λ��,�Ժ���ַǷָ������ٴ���

    char* temp = NULL;                                       //����ķ���ֵ

    if (str == NULL)
    {
        str = src;                                               //��strΪNULL���ʾ�ó������������һ�����µ��ַ���
    }
    for (;*str;str++)
    {
        delimiters = indelim;
        for (;*delimiters;delimiters++)
        {
            if (*str == *delimiters)
            {
                *str = NULL;                    //���ҵ�delim�и���Ȥ���ַ�,�����ַ���ΪNULL
                index = 1;                         //��������ѳ��ָ���Ȥ�ַ�
                break;
            }
        }
        if (*str != NULL && flag == 1)
        {
            temp = str;                              //ֻ��¼�µ�ǰ��һ���Ǹ���Ȥ�ַ���λ��
            flag = 0;
        }
        if (*str != NULL && flag == 0 && index == 1)
        {
            src = str;                                   //�ڶ��γ��ַǸ���Ȥ�ַ���λ��(֮ǰһ�����ֹ�����Ȥ�ַ�)
            return temp;
        }
    }
    src = str; //ִ�иþ����һֱδ���ֹ�����Ȥ�ַ�,����˵�ڳ����˸���Ȥ���ַ���,��û�ٳ��ֹ��Ǹ���Ȥ�ַ�

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
