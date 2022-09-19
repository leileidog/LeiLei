#ifndef CIRCLE_H
#define CIRCLE_H

#include<string>
#include <iostream>
#include<fstream>
using namespace std;



//求子串的next值
void GetNext(string a);

//KMP算法，从主串中查找子串并返回子串位置，若不存在则返回-1
int KMP(string a, string b);

//grep str filename
//用KMP算法查找指定子串，并输出文本文件中对应行数及整行内容
void FindWord(string sub);

//grep ^str filename
//查找行首出现子串的行，并输出对应行数及整行内容
void FirstWord(string sub);

//grep str$ filename
// 查找行尾出现子串的行，并输出对应行数及整行内容
void EndWord(string sub);

// egrep str1|str2 filename
//查找str1或str2出现的行，并输出对应行数及整行内容
void AndWord(string sub);




#endif