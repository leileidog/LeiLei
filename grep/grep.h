#ifndef CIRCLE_H
#define CIRCLE_H

#include<string>
#include <iostream>
#include<fstream>
using namespace std;



//���Ӵ���nextֵ
void GetNext(string a);

//KMP�㷨���������в����Ӵ��������Ӵ�λ�ã����������򷵻�-1
int KMP(string a, string b);

//grep str filename
//��KMP�㷨����ָ���Ӵ���������ı��ļ��ж�Ӧ��������������
void FindWord(string sub);

//grep ^str filename
//�������׳����Ӵ����У��������Ӧ��������������
void FirstWord(string sub);

//grep str$ filename
// ������β�����Ӵ����У��������Ӧ��������������
void EndWord(string sub);

// egrep str1|str2 filename
//����str1��str2���ֵ��У��������Ӧ��������������
void AndWord(string sub);




#endif