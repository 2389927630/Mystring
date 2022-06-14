#include <iostream>
#include "Mystring.h"
#pragma warning(disable : 4996)
using namespace std;


int main()
{
    //string¿‡≤‚ ‘∫Ø ˝
    Mystring s0("Initial string");
    Mystring s1;
    Mystring s2(s0);
    Mystring s3(s0, 8, 3);
    Mystring s4("A character sequence");
    Mystring s5("Another character sequence", 12);
    Mystring s6a(10, 'x');
    Mystring s6b(10, 42);      // 42 is the ASCII code for '*'


    cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
    cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a << "\ns6b: " << s6b << endl;

    //operator=≤‚ ‘∫Ø ˝
    Mystring str1_, str2_, str3_;
    str1_ = "Test string: ";   // c-string
    str2_ = 'x';               // single character
    str3_ = str1_ + str2_;       // string
    cout << str3_ << '\n';

    //memcpy≤‚ ‘≥Ã–Ú
    char str[] = "I'm Fan Jiahao";
    char str2[] = "who is studying C++";
    cout << str<<"\n"<< str2<<endl;
    Mystring::memcpy(&str2, &str, sizeof(str2));
    cout << str << "\n" << str2<<endl;

    //memmove≤‚ ‘≥Ã–Ú
    char str4[] = "1234567890";
    cout<<str4<<endl;//1234567890
    Mystring::memmove(str4 , str4 + 7, 3); // ¥” [8,9,0] ∏¥÷∆µΩ [1,2,3]
    cout << str4 << endl;//8904567890

    //strcpy≤‚ ‘≥Ã–Ú
    char str5[] = "abcdefgh";
    char str6[] = "ijklmn";
    cout << str5 << "\t" << str6 << endl;
    Mystring::strcpy(str5, str6);//std”–Õ¨√˚strcpy∫Ø ˝£¨Õ®π˝¿‡√˚∑√Œ ∂®“Âµƒ≥…‘±∫Ø ˝
    cout << str5 << "\t" << str6 << endl;

    
    //strncpy≤‚ ‘≥Ã–Ú
    char str7[] = "To be or not to be";
    char str8[40];
    char str9[40];
    Mystring::strncpy(str8, str7, sizeof(str8));
    Mystring::strncpy(str9, str8, 5);
    cout << str7 << "\t" << str8 << "\t" << str9 << endl;

    //strcat≤‚ ‘≥Ã–Ú
    char str10[80];
    Mystring::strcpy(str10, "these ");
    Mystring::strcat(str10, "strings ");
    Mystring::strcat(str10, "are ");
    Mystring::strcat(str10, "concatenated.");
    cout << str10<<endl;

    //strncat≤‚ ‘≥Ã–Ú
    char str11[20];
    char str12[20];
    Mystring::strcpy(str11, "To be ");
    Mystring::strcpy(str12, "or not to be");
    Mystring::strncat(str11, str12, 6);
    cout<<str11<<endl;

    //memcmp≤‚ ‘≥Ã–Ú
    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";
    int n;
    n = Mystring::memcmp(buffer1, buffer2, sizeof(buffer1));
    if (n > 0) cout << "buffer1 is greater than buffer2" << endl;
    else if (n < 0) cout << "buffer2 is greater than buffer1" << endl;
    else cout << "buffer1 is the same as buffer2" << endl;

    //strcmp≤‚ ‘≥Ã–Ú
    char key[] = "apple";
    char buffer3[80];
    do {
        cout<<"Guess my favorite fruit? ";
        cin>> buffer3;
    } while (Mystring::strcmp(key, buffer3) != 0);
    cout<<"Correct answer!"<<endl;

    //strcoll≤‚ ‘≥Ã–Ú
    char buffer4[] = "DWgaOtP12df0";
    char buffer5[] = "DWGAOTP12DF0";
    cout<< Mystring::strcoll(buffer4, buffer5)<<endl;

    //strncmp≤‚ ‘≥Ã–Ú
    char str13[][5] = { "R2D2" , "C3PO" , "R2A6" };
    int n_1;
    cout<<"Looking for R2 astromech droids..."<<endl;
    for (n_1 = 0; n_1 < 3; n_1++)
        if ((unsigned)Mystring::strncmp(str13[n_1], "R2xx", 2) == 0)
        {
            cout<<"found "<< str13[n_1]<<endl;
        }

    //strxfrm≤‚ ‘≥Ã–Ú
    char str14[] = "1234567890 abc";
    char str15[100];
    size_t len = Mystring::strxfrm(str15, str14, 50);
    std::cout << "len: " << len << std::endl;
    std::cout << "des: " << str15 << std::endl;

    
    //memchr≤‚ ‘≥Ã–Ú
    char* pch1;
    char str16[] = "Example string";
    pch1 = (char*)Mystring::memchr(str16, 'p', strlen(str16));
    if (pch1 != NULL)
        cout<<"'p' found at position "<< pch1 - str16 + 1<<endl;
    else
        cout<<"'p' not found.\n";

    //strchr≤‚ ‘≥Ã–Ú
    char str17[] = "This is a sample string";
    char* pch2;
    cout<<"Looking for the 's' character in "<<str17<<endl;
    pch2 = Mystring::strchr(str17, 's');
    while (pch2 != NULL)
    {
        cout<<"found at "<< pch2 - str17 + 1<<endl;
        pch2 = Mystring::strchr(pch2 + 1, 's');
    }

    //strchr≤‚ ‘≥Ã–Ú
    char str18[] = "fcba73";
    char keys[] = "1234567890";
    int i;
    i = Mystring::strcspn(str18, keys);
    cout<<"The first number in str is at position "<< i + 1<<endl;

    //strpbrk≤‚ ‘≥Ã–Ú
    char str19[] = "'This is a sample string'";
    char key1[] = "aeiou";
    const char* pch3;
    cout<<"Vowels in "<< str19<<"\t";
    pch3 = Mystring::strpbrk(str19, key1);
    while (pch3 != NULL)
    {
        cout<< *pch3;
        pch3 = Mystring::strpbrk(pch3 + 1, key1);
    }
    cout << endl;

    //strrchr≤‚ ‘≥Ã–Ú
    char str20[] = "This is a sample string";
    char* pch4;
    pch4 = Mystring::strrchr(str20, 's');
    cout<<"Last occurence of 's' found at "<< pch4 - str20 + 1<<endl;

    //strspn≤‚ ‘≥Ã–Ú
    int i_1;
    char strtext[] = "129th";
    char cset[] = "1234567890";
    i_1 = Mystring::strspn(strtext, cset);
    cout << "The initial number has digits." << i_1 << endl;

    //strncpy≤‚ ‘≥Ã–Ú
    char str21[] = "This is a simple string";
    char* pch5;
    pch5 = Mystring::strstr(str21, "simple");
    if (pch5 != NULL)
        Mystring::strncpy(pch5, "sample", 6);
    cout<<str21<<endl;

    //strtok≤‚ ‘≥Ã–Ú
    char str22[] = "- This, a sample string.";
    char* pch6;
    cout<<"Splitting string  "<< str22<<" into tokens:\n";
    pch6 = Mystring::strtok(str22, " ,.-");
    while (pch6 != NULL)
    {
        cout<< pch6<<endl;
        pch6= Mystring::strtok(NULL, " ,.-");
    }

    //memset≤‚ ‘≥Ã–Ú
    char str23[] = "almost every programmer should know memset!";
    Mystring::memset(str23, '-', 6);
    cout<<str23<<endl;

    ////strerror≤‚ ‘≥Ã–Ú
    //FILE* pFile;
    //pFile = fopen("unexist.ent", "r");
    //if (pFile == NULL)
    //    cout<<"Error opening file unexist.ent: "<< Mystring::strerror(errno)<<endl;

    //strlen≤‚ ‘≥Ã–Ú
    char szInput[256];
    cout << "Enter a sentence: ";
    cin >> szInput;
    cout << "The sentence entered is  " << (unsigned)Mystring::strlen(szInput) << " characters long." << endl;

    //string str24("Test string");
    //cout << "The size of str is " << str24.length() << " bytes.\n";

	system("pause");
	return 0;
}