//
// Created by 张虾ang on 16/10/26.
//
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

void change1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
//    cout <<"after change"<< " a:" << a << " b:" << b << endl;
}

void change2(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

void change3(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 1, b = 10;
    change1(a, b);//只是值传递  没有影响到实际的交换
    cout << "after change1" << " a:" << a << " b:" << b << endl;

    change2(&a, &b);//地址传递
    cout << "after change2" << " a:" << a << " b:" << b << endl;

    change3(a, b);//引用传递
    cout << "after change3" << " a:" << a << " b:" << b << endl;
    return 1;
}
