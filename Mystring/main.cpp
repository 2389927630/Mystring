#include <iostream>
#include "Mystring.h"
#pragma warning(disable : 4996)
#include<cmath>
#include<fstream>
using namespace std;

int main()
{
    //stringÀà²âÊÔº¯Êý
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

    //operator=²âÊÔº¯Êý
    Mystring str1_, str2_, str3_;
    str1_ = "Test string: ";   // c-string
    str2_ = 'x';               // single character
    str3_ = str1_ + str2_;       // string
    cout << str3_ << '\n';

    //memcpy²âÊÔ³ÌÐò
    char str[] = "I'm Fan Jiahao";
    char str2[] = "who is studying C++";
    cout << str<<"\n"<< str2<<endl;
    Mystring::memcpy(&str2, &str, sizeof(str2));
    cout << str << "\n" << str2<<endl;

    //memmove²âÊÔ³ÌÐò
    char str4[] = "1234567890";
    cout<<str4<<endl;//1234567890
    Mystring::memmove(str4 , str4 + 7, 3); // ´Ó [8,9,0] ¸´ÖÆµ½ [1,2,3]
    cout << str4 << endl;//8904567890

    //strcpy²âÊÔ³ÌÐò
    char str5[] = "abcdefgh";
    char str6[] = "ijklmn";
    cout << str5 << "\t" << str6 << endl;
    Mystring::strcpy(str5, str6);//stdÓÐÍ¬Ãûstrcpyº¯Êý£¬Í¨¹ýÀàÃû·ÃÎÊ¶¨ÒåµÄ³ÉÔ±º¯Êý
    cout << str5 << "\t" << str6 << endl;

    
    //strncpy²âÊÔ³ÌÐò
    char str7[] = "To be or not to be";
    char str8[40];
    char str9[40];
    Mystring::strncpy(str8, str7, sizeof(str8));
    Mystring::strncpy(str9, str8, 5);
    str9[5] = '\0';
    cout << str7 << "\t" << str8 << "\t" << str9 << endl;

    //strcat²âÊÔ³ÌÐò
    char str10[80];
    Mystring::strcpy(str10, "these ");
    Mystring::strcat(str10, "strings ");
    Mystring::strcat(str10, "are ");
    Mystring::strcat(str10, "concatenated.");
    cout << str10<<endl;

    //strncat²âÊÔ³ÌÐò
    char str11[20];
    char str12[20];
    Mystring::strcpy(str11, "To be ");
    Mystring::strcpy(str12, "or not to be");
    Mystring::strncat(str11, str12, 6);
    cout<<str11<<endl;

    //memcmp²âÊÔ³ÌÐò
    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";
    int n;
    n = Mystring::memcmp(buffer1, buffer2, sizeof(buffer1));
    if (n > 0) cout << "buffer1 is greater than buffer2" << endl;
    else if (n < 0) cout << "buffer2 is greater than buffer1" << endl;
    else cout << "buffer1 is the same as buffer2" << endl;

    //strcmp²âÊÔ³ÌÐò
    char key[] = "apple";
    char buffer3[80];
    do {
        cout<<"Guess my favorite fruit? ";
        cin>> buffer3;
    } while (Mystring::strcmp(key, buffer3) != 0);
    cout<<"Correct answer!"<<endl;

    //strcoll²âÊÔ³ÌÐò
    char buffer4[] = "DWgaOtP12df0";
    char buffer5[] = "DWGAOTP12DF0";
    cout<< Mystring::strcoll(buffer4, buffer5)<<endl;

    //strncmp²âÊÔ³ÌÐò
    char str13[][5] = { "R2D2" , "C3PO" , "R2A6" };
    int n_1;
    cout<<"Looking for R2 astromech droids..."<<endl;
    for (n_1 = 0; n_1 < 3; n_1++)
        if ((unsigned)Mystring::strncmp(str13[n_1], "R2xx", 2) == 0)
        {
            cout<<"found "<< str13[n_1]<<endl;
        }

    //strxfrm²âÊÔ³ÌÐò
    char str14[] = "1234567890 abc";
    char str15[100];
    size_t len = Mystring::strxfrm(str15, str14, 50);
    std::cout << "len: " << len << std::endl;
    std::cout << "des: " << str15 << std::endl;

    
    //memchr²âÊÔ³ÌÐò
    char* pch1;
    char str16[] = "Example string";
    pch1 = (char*)Mystring::memchr(str16, 'p', strlen(str16));
    if (pch1 != NULL)
        cout<<"'p' found at position "<< pch1 - str16 + 1<<endl;
    else
        cout<<"'p' not found.\n";

    //strchr²âÊÔ³ÌÐò
    char str17[] = "This is a sample string";
    char* pch2;
    cout<<"Looking for the 's' character in "<<str17<<endl;
    pch2 = Mystring::strchr(str17, 's');
    while (pch2 != NULL)
    {
        cout<<"found at "<< pch2 - str17 + 1<<endl;
        pch2 = Mystring::strchr(pch2 + 1, 's');
    }

    //strchr²âÊÔ³ÌÐò
    char str18[] = "fcba73";
    char keys[] = "1234567890";
    int i;
    i = Mystring::strcspn(str18, keys);
    cout<<"The first number in str is at position "<< i + 1<<endl;

    //strpbrk²âÊÔ³ÌÐò
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

    //strrchr²âÊÔ³ÌÐò
    char str20[] = "This is a sample string";
    char* pch4;
    pch4 = Mystring::strrchr(str20, 's');
    cout<<"Last occurence of 's' found at "<< pch4 - str20 + 1<<endl;

    //strspn²âÊÔ³ÌÐò
    int i_1;
    char strtext[] = "129th";
    char cset[] = "1234567890";
    i_1 = Mystring::strspn(strtext, cset);
    cout << "The initial number has digits." << i_1 << endl;

    //strstr²âÊÔ³ÌÐò
    char str21[] = "This is a simple string";
    char* pch5;
    pch5 = Mystring::strstr(str21, "simple");
    if (pch5 != NULL)
        Mystring::strncpy(pch5, "sample", 6);
    cout<<str21<<endl;

    //strtok²âÊÔ³ÌÐò
    char str22[] = "- This, a sample string.";
    char* pch6;
    cout<<"Splitting string  "<< str22<<" into tokens:\n";
    pch6 = Mystring::strtok(str22, " ,.-");
    while (pch6 != NULL)
    {
        cout<< pch6<<endl;
        pch6= Mystring::strtok(NULL, " ,.-");
    }

    //memset²âÊÔ³ÌÐò
    char str23[] = "almost every programmer should know memset!";
    Mystring::memset(str23, '-', 6);
    cout<<str23<<endl;

    //strerror²âÊÔ³ÌÐò
    FILE* pFile;
    pFile = fopen("unexist.ent", "r");
    if (pFile == NULL)
        cout<<"Error opening file unexist.ent: "<< Mystring::strerror(errno)<<endl;

    //strlen²âÊÔ³ÌÐò
    char szInput[256];
    cout << "Enter a sentence: ";
    cin >> szInput;
    cout << "The sentence entered is  " << (unsigned)Mystring::strlen(szInput) << " characters long." << endl;

    //size length capacity max_sizeµÄ²âÊÔº¯Êý
    Mystring str24("Test string");
    cout << "size: " << str24.size() << "\n";
    cout << "length: " << str24.length_func() << "\n";
    cout << "capacity: " << str24.capacity() << "\n";
    cout << "max_size: " << str24.max_size() << "\n";

    //stoiµÄ²âÊÔº¯Êý
    Mystring str_dec = "2001, A Space Odyssey";
    Mystring str_hex = "40c3";
    Mystring str_bin = "-10010110001";
    Mystring str_auto = "0x7f";

    size_t sz;   //  size_t µÄ±ðÃû

    int i_dec = Mystring::stoi(str_dec, &sz);
    int i_hex = Mystring::stoi(str_hex, nullptr, 16);
    int i_bin = Mystring::stoi(str_bin, nullptr, 2);
    int i_auto = Mystring::stoi(str_auto, nullptr, 0);

    cout << str_dec << ": " << i_dec <<  "\n";
    cout << str_hex << ": " << i_hex << '\n';
    cout << str_bin << ": " << i_bin << '\n';
    cout << str_auto << ": " << i_auto << '\n';

    //stol²âÊÔº¯Êý
    Mystring str_dec_1 = "1987520";
    Mystring str_hex_1 = "2f04e009";
    Mystring str_bin_1 = "-11101001100100111010";
    Mystring str_auto_1 = "0x7fffff";

    size_t sz_1;   // alias of size_t

    long li_dec_1 = Mystring::stol(str_dec_1, &sz_1);
    long li_hex_1 = Mystring::stol(str_hex_1, nullptr, 16);
    long li_bin_1 = Mystring::stol(str_bin_1, nullptr, 2);
    long li_auto_1 = Mystring::stol(str_auto_1, nullptr, 0);

    cout << str_dec_1 << ": " << li_dec_1 << '\n';
    cout << str_hex_1 << ": " << li_hex_1 << '\n';
    cout << str_bin_1 << ": " << li_bin_1 << '\n';
    cout << str_auto_1 << ": " << li_auto_1 << '\n';


    ////stoul²âÊÔº¯Êý
    Mystring str24_;
    cout << "Enter an unsigned number: ";
    getline(std::cin, str24_);
    unsigned long ul = Mystring::stoul(str24_, nullptr, 0);
    cout << "You entered: " << ul << '\n';

    //resize²âÊÔº¯Êý
    Mystring str25("I like to code in C");
    cout << str25 << '\n';
    unsigned sz_= str25.size();

    str25.resize(sz_ + 2, '+');
    cout << str25 << '\n';

    str25.resize(14);
    cout << str25 << '\n';


    //reserveµÄ²âÊÔº¯Êý
    str25.reserve(20);


    //operator+=µÄ²âÊÔº¯Êý
    Mystring name("John");
    Mystring family("Smith");
    name += " K. ";         // c-string
    name += family;         // string
    name += '\n';           // character

    cout << name<<endl;

    //+ÔËËã·û²âÊÔº¯Êý
    Mystring firstlevel("com");
    Mystring secondlevel("cplusplus");
    Mystring scheme("http://");
    Mystring hostname;
    Mystring url;

    hostname = "www." + secondlevel + '.' + firstlevel;
    url = scheme + hostname;

    cout << url << '\n';

    //clear²âÊÔº¯Êý
    //char c;
    //Mystring str27;
    //cout << "Please type some lines of text. Enter a dot (.) to finish:\n";
    //do {
    //    c = cin.get();
    //    str27 += c;
    //    if (c == '\n')
    //    {
    //        cout << str27;
    //        str27.clear();
    //    }
    //} while (c != '.');

    //empty²âÊÔº¯Êý 
    Mystring content;
    Mystring line;
    cout << "Please introduce a text. Enter an empty line to finish:\n";
    do {
        getline(cin, line);
        content += line + '\n';
    } while (!line.empty());
    cout << "The text you introduced was:\n" << content;


    //at²âÊÔº¯Êý
    Mystring str28("Test string");
    for (unsigned i = 0; i < str28.length_func(); ++i)
    {
        cout << str28.at(i);
    }
    cout << endl;

    //substr²âÊÔº¯Êý
    Mystring str29 = "We think in generalities, but we live in details.";
  

    Mystring str30 = str29.substr(3, 5);     // "think"

    size_t pos = str29.find("live");      // position of "live" in str

    Mystring str31 = str29.substr(pos);     // get from "live" to the end

    cout << str30 << ' ' << str31<< '\n';

    //shrink_to_fit²âÊÔº¯Êý
   /* Mystring str32(100, 'x');
    cout << "1. capacity of str: " << str32.capacity() << '\n';

    str32.resize(10);
    str32.shrink_to_fit();
    cout << "3. capacity of str: " << str32.capacity() << '\n';*/

    //backµÄ²âÊÔº¯Êý
    Mystring str33("hello world.");
    str33.back() = '!';
    std::cout << str33 << '\n';

    //frontµÄ²âÊÔº¯Êý
    Mystring str34("test string");
    str34.front() = 'T';
    cout << str34 << '\n';

    //appendºÍpush_backµÄ²âÊÔº¯Êý
    //Mystring str35;
    //Mystring str36 = "Writing ";
    //Mystring str37 = "print 10 and then 5 more";

    //str35.append(str36);                       // "Writing "
    //str35.append(str37, 6, 3);                   // "10 "
    //str35.append("dots are cool", 5);          // "dots "
    //str35.append("here: ");                   // "here: "
    //str35.append(10u, '.');                    // ".........."
    //str35.push_back('!');
    //cout << str35 << '\n';

    //assignµÄ²âÊÔº¯Êý
    Mystring str38;
    Mystring base = "The quick brown fox jumps over a lazy dog.";

    // used in the same order as described above:

    str38.assign(base);
    cout << str38 << '\n';

    str38.assign(base, 10, 9);
    cout << str38 << '\n';         // "brown fox"

    str38.assign("pangrams are cool", 7);
    cout << str38 << '\n';         // "pangram"

    str38.assign("c-string");
    cout << str38 << '\n';         // "c-string"

    str38.assign(10, '*');
    cout << str38 << '\n';         // "**********"


    //data²âÊÔº¯Êý
    Mystring str40 = "Test string";
    const char* cstr_1 = "Test string";

    if (str40.size() == Mystring::strlen(cstr_1))
    {
        cout << "str and cstr have the same length.\n";

        if (Mystring::memcmp(cstr_1, str40.data(), str40.size()) == 0)
            cout << "str and cstr have the same content.\n";
    }

    //copyµÄ²âÊÔº¯Êý
    char buffer[20];
    Mystring str41("Test string...");
    size_t length = str41.copy(buffer, 6, 5);
    buffer[length] = '\0';
    cout << "buffer contains: " << buffer << '\n';

    //[]²âÊÔº¯Êý
    Mystring str42("Test string");
    for (int i = 0; i < str42.size(); ++i)
    {
        cout << str42[i];
    }
    cout << endl;


    //getline²âÊÔº¯Êý
    Mystring name_1;
    cout << "Please, enter your full name_1: ";
    getline(cin, name_1);
    cout << "Hello, " << name_1 << "!\n";

    //swap²âÊÔº¯Êý  
    /*Mystring buyer("money");
    Mystring seller("goods");

    cout << "Before the swap, buyer has " << buyer;
    cout << " and seller has " << seller << '\n';

    Mystring::swap(buyer, seller);
    cout << " After the swap, buyer has " << buyer;
    cout << " and seller has " << seller << '\n';*/

    //stof²âÊÔº¯Êý
    Mystring orbits("686.97 365.24");
    string::size_type sz_2;     // alias of size_t

    float mars = Mystring::stof(orbits, &sz_2);
    float earth = Mystring::stof(orbits.substr(sz_2));
    cout << "One martian year takes " << (mars / earth) << " Earth years.\n";

    //stod²âÊÔº¯Êý

    /*Mystring orbits_1("365.24 29.53");


    double Earth = Mystring::stod(orbits_1, &sz);
    double moon = Mystring::stod(orbits_1.substr(sz));
    cout << "The moon completes " << (Earth / moon) << " orbits per Earth year.\n";*/

    //pop_back²âÊÔº¯Êý
    Mystring str43("hello world!");
    str43.pop_back();
    std::cout << str43<< '\n';

    //insert²âÊÔº¯Êý
    Mystring str44 = "to be question";
    Mystring str45 = "the ";
    Mystring str46 = "or not to be";

    str44.insert(6, str45);                 // to be (the )question
    cout << str44 << '\n';

    //compare²âÊÔ´úÂë
    Mystring str47("green apple");
    Mystring str48("red apple");

    if (str47.compare(str48) != 0)
        cout << str47 << " is not " << str48 << '\n';

    if (str47.compare(6, 5, "apple") == 0)
        cout << "still, " << str48 << " is an apple\n";

    if (str47.compare(str48.size() - 5, 5, "apple") == 0)
        cout << "and " << str48 << " is also an apple\n";

    if (str47.compare(6, 5, str48, 4, 5) == 0)
        cout << "therefore, both are apples\n";

    //find_first_of²âÊÔº¯Êý
    Mystring str49("Please, replace the vowels in this sentence by asterisks.");
    size_t found = str49.find_first_of("aeiou");
    while (found != Mystring::npos)
    {
        str49[found] = '*';
        found = str49.find_first_of("aeiou", found + 1);
    }

    cout << str49 << '\n';

    //find_last_not_of²âÊÔº¯Êý
    Mystring str50("Please, erase trailing white-spaces   \n");
    Mystring whitespaces(" \t\f\v\n\r");

    size_t found_1 = str50.find_last_not_of(whitespaces);
    if (found_1 != Mystring::npos)
        str50.erase(found_1 + 1);
    else
        str50.clear();            // str is all whitespace

    cout << '[' << str50 << "]";

    //== != < > <= >=µÄ²âÊÔº¯Êý
    Mystring foo = "alpha";
    Mystring bar = "beta";

    if (foo == bar) cout << "foo and bar are equal\n";
    if (foo != bar) cout << "foo and bar are not equal\n";
    if (foo < bar) cout << "foo is less than bar\n";
    if (foo > bar) cout << "foo is greater than bar\n";
    if (foo <= bar) cout << "foo is less than or equal to bar\n";
    if (foo >= bar) cout << "foo is greater than or equal to bar\n";

   system("pause");
   return 0;

}

