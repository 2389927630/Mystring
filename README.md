# Mystring

C++程序开发实训 (共5周)/14-18周

A方式、B方式二选一



A方式【自主学习与创新方式】：

自己设定C++程序开发实训。

评分标准：

依据项目的难度，挑战性，工作量，完成情况等各方面综合评价，评定综合成绩，并在C++学习微信班级群里公示。

示例：

2021级软件工程4班姚祉圻同学，https://gitee.com/rankrev/loxpp?_from=gitee_search  秩启 / Lox++ 

该项目可以直接提交为C++程序开发实训项目，     综合成绩初步评定为接近满分。



B方式【正常学习方式】：

一、设计mystring类，要求实现以下功能：

1、http://www.cplusplus.com/reference/cstring/   中右边后涉及的所有功能。（共24个）



2、实现以下功能。（共9个）。功能描述与使用见：http://www.cplusplus.com/reference/string/

stoi  Convert string to integer

stol  Convert string to long int

stoul  Convert string to unsigned integer 

stoll  Convert string to long long

stoull Convert string to unsigned long long

stof  Convert string to float

stod Convert string to double

stold  Convert string to long double

to_string  Convert numerical value to string



3、Construct string object。（共6个）。功能描述与使用见：http://www.cplusplus.com/reference/string/string/string/

Constructs a string object, initializing its value depending on the constructor version used:

(1) empty string constructor (default constructor)

Constructs an empty string, with a length of zero characters.

(2) copy constructor

Constructs a copy of str.

(3) substring constructor

Copies the portion of str that begins at the character position pos and spans len characters (or until the end of str, if either str is too short or if len is string::npos).

(4) from c-string

Copies the null-terminated character sequence (C-string) pointed by s.

(5) from buffer

Copies the first n characters from the array of characters pointed by s.

(6) fill constructor

Fills the string with n consecutive copies of character c.



4、实现以下功能。（共40个）功能描述与使用见：http://www.cplusplus.com/reference/string/string/

(destructor)  String destructor 

operator=   String assignment 

size  Return length of string 

length  Return length of string



Capacity:

size

Return length of string (public member function )

length

Return length of string (public member function )

max_size

Return maximum size of string (public member function )

resize

Resize string (public member function )

capacity

Return size of allocated storage (public member function )

reserve

Request a change in capacity (public member function )

clear

Clear string (public member function )

empty

Test if string is empty (public member function )

shrink_to_fit 

Shrink to fit (public member function )



Element access:

operator[]

Get character of string (public member function )

at

Get character in string (public member function )

back 

Access last character (public member function )

front 

Access first character (public member function )



Modifiers:

operator+=

Append to string (public member function )

append

Append to string (public member function )

push_back

Append character to string (public member function )

assign

Assign content to string (public member function )

insert

Insert into string (public member function )

erase

Erase characters from string (public member function )

replace

Replace portion of string (public member function )

swap

Swap string values (public member function )

pop_back 

Delete last character (public member function )



String operations:



data

Get string data (public member function )

copy

Copy sequence of characters from string (public member function )

find

Find content in string (public member function )

rfind

Find last occurrence of content in string (public member function )

find_first_of

Find character in string (public member function )

find_last_of

Find character in string from the end (public member function )

find_first_not_of

Find absence of character in string (public member function )

find_last_not_of

Find non-matching character in string from the end (public member function )

substr

Generate substring (public member function )

compare

Compare strings (public member function )



Non-member function overloads

operator+

Concatenate strings (function )

relational operators

Relational operators for string (function )

swap

Exchanges the values of two strings (function )

operator>>

Extract string from stream (function )

operator<<

Insert string into stream (function )

getline

Get line from stream into string (function )



5、测试

测试以上功能是否正确实现



二（选做，仅供有兴趣的同学练习，不参与评分）、封装mystring类，供Python调用。



三、评分标准：

功能实现占60%，程序可读性占40%。 做方式B的同学学生成绩不在微信群里公示，老师根据同学们的功能实现和程序可读性直接给出成绩。





友情提示：不懂的地方可以请教同学，但必须自己独立完成。自己做好的C++实践作业，做好保密工作，自己在教学在线上面提交，不要让别的同学COPY过去了。

DDL为2022年6月24日晚9点。

在此之后提交的同学，总评成绩乘以0.9的系数。



如果存在完全相同的两份作业，这两位同学均需要参加答辩，以确实哪一份是原创，哪一份是COPY件。COPY件的同学成绩计0分。
