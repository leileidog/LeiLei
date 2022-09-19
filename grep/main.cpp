#include "grep.h"

extern int nex[100];
extern string info[1000];//�洢�ļ�ÿ�е��ַ���
extern int a[1000];//�洢�����Ƿ���ָ���Ӵ���1Ϊ�У�0Ϊ��

int main(int argc, char* argv[]) {

    ifstream fin;
    string pre, mid;
    char file_name[100];
    string str;

    while (1) {
        cout << "Please enter the command:" << endl;
        cin >> pre >> mid >> file_name;
        if (pre == "0")
            break;
        fin.open(file_name);
        if (!fin) {
            cout << "File not found!" << endl;
            continue;
        }

        int i = 0;
        while (getline(fin, str)) {//���ж�ȡ�ı��ļ��������ַ�������

            info[i] = str;
            if (fin.eof())
                break;
            i++;
        }

        if (pre == "grep") {

            if (mid[0] == '^')
                FirstWord(mid);
            else if (mid[mid.size() - 1] == '$')
                EndWord(mid);
            else
                FindWord(mid);
        }
        else if (pre == "egrep") {
            AndWord(mid);
        }
        else
            cout << "Invalid instruction!" << endl;
        fin.close();
    }
    return 0;

}

