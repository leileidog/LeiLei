#include "grep.h"

int nex[100];
string info[1000];//存储文件每行的字符串
int a[1000];//存储该行是否有指定子串，1为有，0为无

//求子串的next值
void GetNext(string a) {

    int len = a.size();//子串长度
    int i = 0, j = -1;
    nex[0] = -1;
    while (i < len) {
    
        if (j == -1 || a[i] == a[j])
            nex[++i] = ++j;
        else
            j = nex[j];
    }
}

//KMP算法，从主串中查找子串并返回子串位置，若不存在则返回-1
int KMP(string a, string b) {

    GetNext(b);
    int lena = a.size();
    int lenb = b.size();
    int i = 0, j = 0;
    while (i < lena && j < lenb) {
    
        if (j == -1 || a[i] == b[j]) {
            i++; j++;
        }
        else
            j = nex[j];
    }
    if (j == lenb)
        return i - j;
    else
        return -1;
}

//grep str filename
//用KMP算法查找指定子串，并输出文本文件中对应行数及整行内容
void FindWord(string sub) {
    
    int i = 0;
    while (info[i] != "") {
        if (KMP(info[i], sub) != -1)
            a[i] = 1;
        else
            a[i] = 0;
        i++;
    }
    i = 0;
    while (info[i] != "") {

        if (a[i] == 1)
            cout << i + 1 << ":" << info[i] << endl;
        i++;
    }
}

//grep ^str filename
//查找行首出现子串的行，并输出对应行数及整行内容
void FirstWord(string sub) {
    int i = 0;
    while(info[i]!="") {

        for (int j = 0; j < sub.size()-1; j++) {        
            if (info[i][j] == sub[j + 1])
                a[i] = 1;
            else {         
                a[i] = 0;
                break;
            }                
        }
        i++;
    }
    i = 0;
    while (info[i] != "") {

        if (a[i] == 1)
            cout <<i+1<<":"<< info[i] << endl;
        i++;
    }
}

//grep str$ filename
// 查找行尾出现子串的行，并输出对应行数及整行内容
void EndWord(string sub) {
    int i = 0;
    while (info[i]!= "") {
        int m = info[i].size() - 1;
        for (int j = sub.size() - 1; j > 0; j--) {
            if (info[i][m] == sub[j-1]) {
                a[i] = 1;
                m--;
            }             
            else {
                a[i] = 0;
                break;
            }
        }
        i++;
    }
    i = 0;
    while (info[i] != "") {

        if (a[i] == 1)
            cout <<  i + 1 <<":" << info[i] << endl;
        i++;
    }
}

// egrep str1|str2 filename
//查找str1或str2出现的行，并输出对应行数及整行内容
void AndWord(string sub) {
    string s1, s2;
    int i = 0;
    while (sub[i] != '|') {
        s1 += sub[i];//s1为‘|’前的字符串
        i++;
    }
    i++;
    while (i < sub.size()) {
        s2 += sub[i]; //s1为‘ | ’后的字符串
        i++;
    }

    i = 0;
    while (info[i] != "") {
        if (KMP(info[i], s1) != -1 || KMP(info[i], s2) != -1)
            a[i] = 1;
        else
            a[i] = 0;
        i++;
    }
    i = 0;
    while (info[i] != "") {

        if (a[i] == 1)
            cout << i + 1 << ":" << info[i] << endl;
        i++;
    }  
}
