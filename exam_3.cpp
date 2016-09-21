//
// Created by 张虾ang on 16/9/21.
//
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void exam_3_6() {
    string fighting("Fighting Aaron");
    for (auto &c:fighting) {
        c = 'X';
    }
    cout << fighting << endl;
}

void exam_3_7() {
    string fighting("Fighting Aaron");
    for (char &c:fighting) {
        c = 'X';
    }
    cout << fighting << endl;
}

void exam_3_8() {
    string fighting("Fighting Aaron");
    for (int i = 0; i < fighting.size(); i++) {
        fighting[i] = 'X';
    }
    cout << fighting << endl;

    string temp;//可见在声明一个string的时候就已经初始化出一个size 0 的数组了
    cout << temp.size() << endl;
}

void exam_3_9(string str) {
    for (auto &c:str) {
        if (ispunct(c)) {
            c = '\0';//直接赋值一个null或者是一个\0终止符也可以的
        }
    }
    cout << str << endl;
}

int main() {
    string params("Wu,Qing!I Miss...You~");
    exam_3_6();
    exam_3_7();
    exam_3_8();
    exam_3_9(params);
    return 0;
}

