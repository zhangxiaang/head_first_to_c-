//
// Created by 张虾ang on 16/11/21.
//
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
//    char c;
//    cin >> c;
//    cout << c << endl;
    string china = "a翔";//->"翔\0" 1+3
    string eng = "zz";//->"z\0" 1+1
    char cc = 'a';
//    char ce = '额';
    //字节数组和字符数组的关系   在不同的语言中 一个字符的内存可能是两个字节的长度
    //例如中文,一个u8中文可能是2-4个字节长度
    //所以之前纠结的问题: 为何中文字符
    cout << china.length() << endl;
    cout << sizeof(cc) << endl;//因为中文utf-8中是占据了三个字节的  而c中char是一个字符的 所以说无法用char来表示中文
    cout << eng.length() << endl;
//    cout << sizeof(ce) << endl;
//
//    try {
//        exception
//    }catch (I)


    return 1;
}
